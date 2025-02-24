/***************************************************************************//**
 * @file
 * @brief ECC J-PAKE accelerated implementation
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

/**
 * This file includes an alternative implementation of the standard
 * mbedtls/libary/ecjpake.c using the secure engine incorporated in Series-2
 * devices with Secure Engine from Silicon Laboratories.
 */

#include <mbedtls/build_info.h>

#if defined(MBEDTLS_ECJPAKE_ALT) && defined(MBEDTLS_ECJPAKE_C)

#include "em_device.h"

#if defined(SEMAILBOX_PRESENT)
#include "sli_se_manager_mailbox.h"
#include "se_management.h"
#include "mbedtls/ecjpake.h"
#include "mbedtls/platform_util.h"
#include "mbedtls/error.h"
#include <string.h>

static const char * const ecjpake_id[] = {
  "client",
  "server"
};

static int parse_tls_point(const uint8_t **ibuf, size_t *ilen, size_t *rlen,
                           uint8_t **obuf, size_t *olen)
{
  if (ilen == NULL || ibuf == NULL || obuf == NULL || olen == NULL) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  if (*ilen == 0 || *ibuf == NULL || *obuf == NULL) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // consume first byte, length of what follows
  size_t field_length = **ibuf;
  *ibuf += 1;
  *ilen -= 1;
  if (rlen != NULL) {
    *rlen += 1;
  }

  if (field_length > *ilen) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // consume second byte, point type
  uint8_t point_type = **ibuf;
  size_t point_length = field_length - 1;
  *ibuf += 1;
  *ilen -= 1;

  switch (point_type) {
    case 0x0:
      // Why would we ever get a zero-point?
      return MBEDTLS_ERR_ECP_INVALID_KEY;
    case 0x04:
      break;
    case 0x05:
      // We don't support compressed points...
      return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    default:
      return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // copy out binary point
  if (point_length > *olen) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  memcpy(*obuf, *ibuf, point_length);
  *ibuf += point_length;
  *ilen -= point_length;
  *obuf += point_length;
  *olen -= point_length;
  if (rlen != NULL) {
    *rlen += field_length;
  }

  return 0;
}

static int parse_tls_zkp(const uint8_t **ibuf, size_t *ilen, size_t *rlen,
                         uint8_t **obuf, size_t *olen)
{
  if (ilen == NULL || ibuf == NULL || obuf == NULL || olen == NULL) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  if (*ilen == 0 || *ibuf == NULL || *obuf == NULL || *olen < 96) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  int ret = parse_tls_point(ibuf, ilen, rlen, obuf, olen);
  if (ret != 0) {
    return ret;
  }

  if (*ilen < 1) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // consume first byte, length of what follows
  size_t field_length = **ibuf;
  *ibuf += 1;
  *ilen -= 1;
  if (rlen != NULL) {
    *rlen += 1;
  }

  if (field_length > *ilen || field_length > *olen) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  if (field_length == 0) {
    // scalar cannot be zero
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // right-adjust
  size_t adjust_length = 32 - field_length;
  memset(*obuf, 0, adjust_length);
  *obuf += adjust_length;
  *olen -= adjust_length;

  // Consume field
  memcpy(*obuf, *ibuf, field_length);
  *obuf += field_length;
  *olen -= field_length;
  *ibuf += field_length;
  *ilen -= field_length;

  if (rlen != NULL) {
    *rlen += field_length;
  }

  return 0;
}

static int write_tls_point(uint8_t **obuf, size_t *olen, size_t *wlen,
                           const uint8_t **ibuf, size_t *ilen, size_t point_length)
{
  if (ibuf == NULL || obuf == NULL || olen == NULL || ilen == NULL) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  if (*obuf == NULL || *ibuf == NULL) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // We can only output uncompressed points here
  if (*olen < point_length + 2) {
    return MBEDTLS_ERR_ECP_BUFFER_TOO_SMALL;
  }

  if (*ilen < point_length) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  **obuf = point_length + 1;
  *obuf += 1;
  *olen -= 1;

  **obuf = 0x04;
  *obuf += 1;
  *olen -= 1;

  memcpy(*obuf, *ibuf, point_length);

  *obuf += point_length;
  *olen -= point_length;
  *ibuf += point_length;
  *ilen -= point_length;

  if (wlen != NULL) {
    *wlen += point_length + 2;
  }

  return 0;
}

static int write_tls_zkp(uint8_t **obuf, size_t *olen, size_t *wlen,
                         const uint8_t **ibuf, size_t *ilen, size_t point_length)
{
  int ret = 0;

  if (ibuf == NULL || obuf == NULL || olen == NULL || ilen == NULL) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  if (*obuf == NULL || *ibuf == NULL) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  ret = write_tls_point(obuf, olen, wlen, ibuf, ilen, point_length);

  if (ret != 0) {
    return ret;
  }

  size_t zkp_length = 32;

  if (*olen < zkp_length + 1 || *ilen < zkp_length) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  **obuf = zkp_length;
  *obuf += 1;
  *olen -= 1;

  memcpy(*obuf, *ibuf, zkp_length);

  *obuf += zkp_length;
  *olen -= zkp_length;
  *ibuf += zkp_length;
  *ilen -= zkp_length;

  if (wlen != NULL) {
    *wlen += zkp_length + 1;
  }

  return 0;
}

void mbedtls_ecjpake_init(mbedtls_ecjpake_context *ctx)
{
  memset(ctx, 0, sizeof(*ctx));
}

int mbedtls_ecjpake_setup(mbedtls_ecjpake_context *ctx,
                          mbedtls_ecjpake_role role,
                          mbedtls_md_type_t hash,
                          mbedtls_ecp_group_id curve,
                          const unsigned char *secret,
                          size_t len)
{
  if ( role != MBEDTLS_ECJPAKE_CLIENT && role != MBEDTLS_ECJPAKE_SERVER ) {
    return(MBEDTLS_ERR_ECP_BAD_INPUT_DATA);
  }

  // SE only supports passphrases of maximum 32 bytes
  if (len > 32) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // SE currently only supports SHA256 as JPAKE hashing mechanism
  if (hash != MBEDTLS_MD_SHA256) {
    return MBEDTLS_ERR_PLATFORM_FEATURE_UNSUPPORTED;
  }

  // SE currently only supports ECDSA secp256r1 as curve
  if (curve != MBEDTLS_ECP_DP_SECP256R1) {
    return MBEDTLS_ERR_PLATFORM_FEATURE_UNSUPPORTED;
  }

  ctx->curve_flags = 0x8000001FUL;
  ctx->role = role;
  ctx->pwd_len = len;
  memcpy(ctx->pwd, secret, len);

  return 0;
}

int mbedtls_ecjpake_check(const mbedtls_ecjpake_context *ctx)
{
  if (ctx->curve_flags == 0) {
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  return 0;
}

int mbedtls_ecjpake_set_point_format(mbedtls_ecjpake_context *ctx,
                                     int point_format)
{
  switch (point_format) {
    case MBEDTLS_ECP_PF_UNCOMPRESSED:
      ctx->point_format = point_format;
      return 0;
    case MBEDTLS_ECP_PF_COMPRESSED:
      return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
    default:
      return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }
}

int mbedtls_ecjpake_write_round_one(mbedtls_ecjpake_context *ctx,
                                    unsigned char *buf, size_t len, size_t *olen,
                                    int (*f_rng)(void *, unsigned char *, size_t),
                                    void *p_rng)
{
  // SE has internal RNG
  (void)f_rng;
  (void)p_rng;

  int ret = 0;

  // local storage for ZKPs
  uint8_t zkp1[32 + 64];
  uint8_t zkp2[32 + 64];

  *olen = 0;

  // SE command structures
  sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT(SLI_SE_COMMAND_JPAKE_R1_GENERATE);
  sli_se_datatransfer_t domain_in = SLI_SE_DATATRANSFER_DEFAULT(NULL, 0);
  sli_se_datatransfer_t userid = SLI_SE_DATATRANSFER_DEFAULT((void*)ecjpake_id[ctx->role], strlen(ecjpake_id[ctx->role]));
  sli_se_datatransfer_t r_out = SLI_SE_DATATRANSFER_DEFAULT(ctx->r, 32);
  sli_se_datatransfer_t Xm1_out = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xm1, 64);
  sli_se_datatransfer_t zkp1_out = SLI_SE_DATATRANSFER_DEFAULT(zkp1, sizeof(zkp1));
  sli_se_datatransfer_t Xm2_out = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xm2, 64);
  sli_se_datatransfer_t zkp2_out = SLI_SE_DATATRANSFER_DEFAULT(zkp2, sizeof(zkp2));

  sli_se_mailbox_command_add_input(&command, &domain_in);
  sli_se_mailbox_command_add_input(&command, &userid);
  sli_se_mailbox_command_add_output(&command, &r_out);
  sli_se_mailbox_command_add_output(&command, &Xm1_out);
  sli_se_mailbox_command_add_output(&command, &zkp1_out);
  sli_se_mailbox_command_add_output(&command, &Xm2_out);
  sli_se_mailbox_command_add_output(&command, &zkp2_out);

  sli_se_mailbox_command_add_parameter(&command, ctx->curve_flags);
  sli_se_mailbox_command_add_parameter(&command, strlen(ecjpake_id[ctx->role]));

  int status = se_management_acquire();
  if (status != 0) {
    return status;
  }

  sli_se_mailbox_execute_command(&command);
  sli_se_mailbox_response_t res = sli_se_handle_mailbox_response();

  se_management_release();

  if ( res == SLI_SE_RESPONSE_OK ) {
    // To write TLS structures of ECJ-PAKE, we need to write:
    // * Xm1
    // * zkp1
    // * Xm2
    // * zkp2
    uint8_t *obuf = buf;
    const uint8_t *ibuf = ctx->Xm1;
    size_t ilen = 64;

    ret = write_tls_point(&obuf, &len, olen, &ibuf, &ilen, 64);
    if (ret != 0) {
      return ret;
    }

    ibuf = zkp1;
    ilen = 96;
    ret = write_tls_zkp(&obuf, &len, olen, &ibuf, &ilen, 64);
    if (ret != 0) {
      return ret;
    }

    ibuf = ctx->Xm2;
    ilen = 64;
    ret = write_tls_point(&obuf, &len, olen, &ibuf, &ilen, 64);
    if (ret != 0) {
      return ret;
    }

    ibuf = zkp2;
    ilen = 96;
    ret = write_tls_zkp(&obuf, &len, olen, &ibuf, &ilen, 64);
    if (ret != 0) {
      return ret;
    }

    return 0;
  } else {
    return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
  }
}

int mbedtls_ecjpake_read_round_one(mbedtls_ecjpake_context *ctx,
                                   const unsigned char *buf,
                                   size_t len)
{
  int ret = 0;

  // Should receive 2 binary points and 2 ZKPs

  // local storage for ZKPs
  uint8_t zkp1[32 + 64] = { 0 };
  uint8_t zkp2[32 + 64] = { 0 };

  uint8_t *obuf = ctx->Xp1;
  size_t olen = 64;

  // Parse structures
  ret = parse_tls_point(&buf, &len, NULL, &obuf, &olen);
  if (ret != 0) {
    return ret;
  }

  obuf = zkp1;
  olen = 96;
  ret = parse_tls_zkp(&buf, &len, NULL, &obuf, &olen);
  if (ret != 0) {
    return ret;
  }

  obuf = ctx->Xp2;
  olen = 64;
  ret = parse_tls_point(&buf, &len, NULL, &obuf, &olen);
  if (ret != 0) {
    return ret;
  }

  obuf = zkp2;
  olen = 96;
  ret = parse_tls_zkp(&buf, &len, NULL, &obuf, &olen);
  if (ret != 0) {
    return ret;
  }

  if (len > 0) {
    // Too much input
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // SE command structures
  sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT(SLI_SE_COMMAND_JPAKE_R1_VERIFY);
  sli_se_datatransfer_t domain_in = SLI_SE_DATATRANSFER_DEFAULT(NULL, 0);
  sli_se_datatransfer_t userid_mine = SLI_SE_DATATRANSFER_DEFAULT((void*)ecjpake_id[ctx->role], strlen(ecjpake_id[ctx->role]));
  sli_se_datatransfer_t userid_peer = SLI_SE_DATATRANSFER_DEFAULT((void*)ecjpake_id[1 - ctx->role], strlen(ecjpake_id[1 - ctx->role]));

  sli_se_datatransfer_t Xp1_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp1, 64);
  sli_se_datatransfer_t zkp1_in = SLI_SE_DATATRANSFER_DEFAULT(zkp1, sizeof(zkp1));
  sli_se_datatransfer_t Xp2_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp2, 64);
  sli_se_datatransfer_t zkp2_in = SLI_SE_DATATRANSFER_DEFAULT(zkp2, sizeof(zkp2));

  sli_se_mailbox_command_add_input(&command, &domain_in);
  sli_se_mailbox_command_add_input(&command, &userid_mine);
  sli_se_mailbox_command_add_input(&command, &userid_peer);

  sli_se_mailbox_command_add_input(&command, &Xp1_in);
  sli_se_mailbox_command_add_input(&command, &zkp1_in);
  sli_se_mailbox_command_add_input(&command, &Xp2_in);
  sli_se_mailbox_command_add_input(&command, &zkp2_in);

  sli_se_mailbox_command_add_parameter(&command, ctx->curve_flags);
  sli_se_mailbox_command_add_parameter(&command, strlen(ecjpake_id[ctx->role]));
  sli_se_mailbox_command_add_parameter(&command, strlen(ecjpake_id[1 - ctx->role]));

  int status = se_management_acquire();
  if (status != 0) {
    return status;
  }

  sli_se_mailbox_execute_command(&command);
  sli_se_mailbox_response_t res = sli_se_handle_mailbox_response();

  se_management_release();

  if ( res == SLI_SE_RESPONSE_OK ) {
    return 0;
  } else {
    return MBEDTLS_ERR_ECP_VERIFY_FAILED;
  }
}

int mbedtls_ecjpake_write_round_two(mbedtls_ecjpake_context *ctx,
                                    unsigned char *buf, size_t len, size_t *olen,
                                    int (*f_rng)(void *, unsigned char *, size_t),
                                    void *p_rng)
{
  // SE has internal RNG
  (void)f_rng;
  (void)p_rng;

  int ret = 0;

  *olen = 0;

  uint8_t zkpA[32 + 64];
  uint8_t xA[64];

  // SE command structures
  sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT(SLI_SE_COMMAND_JPAKE_R2_GENERATE);
  sli_se_datatransfer_t domain_in = SLI_SE_DATATRANSFER_DEFAULT(NULL, 0);
  sli_se_datatransfer_t pwd_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->pwd, ctx->pwd_len);
  sli_se_datatransfer_t userid = SLI_SE_DATATRANSFER_DEFAULT((void*)ecjpake_id[ctx->role], strlen(ecjpake_id[ctx->role]));
  sli_se_datatransfer_t r_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->r, 32);
  sli_se_datatransfer_t Xm1_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xm1, 64);
  sli_se_datatransfer_t Xp1_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp1, 64);
  sli_se_datatransfer_t Xp2_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp2, 64);

  sli_se_datatransfer_t xA_out = SLI_SE_DATATRANSFER_DEFAULT(xA, sizeof(xA));
  sli_se_datatransfer_t zkpA_out = SLI_SE_DATATRANSFER_DEFAULT(zkpA, sizeof(zkpA));

  sli_se_mailbox_command_add_input(&command, &domain_in);
  sli_se_mailbox_command_add_input(&command, &pwd_in);
  sli_se_mailbox_command_add_input(&command, &userid);
  sli_se_mailbox_command_add_input(&command, &r_in);
  sli_se_mailbox_command_add_input(&command, &Xm1_in);
  sli_se_mailbox_command_add_input(&command, &Xp1_in);
  sli_se_mailbox_command_add_input(&command, &Xp2_in);

  sli_se_mailbox_command_add_output(&command, &xA_out);
  sli_se_mailbox_command_add_output(&command, &zkpA_out);

  sli_se_mailbox_command_add_parameter(&command, ctx->curve_flags);
  sli_se_mailbox_command_add_parameter(&command, ctx->pwd_len);
  sli_se_mailbox_command_add_parameter(&command, strlen(ecjpake_id[ctx->role]));

  int status = se_management_acquire();
  if (status != 0) {
    return status;
  }

  sli_se_mailbox_execute_command(&command);
  sli_se_mailbox_response_t res = sli_se_handle_mailbox_response();

  se_management_release();

  if ( res == SLI_SE_RESPONSE_OK ) {
    // If we are the server, we need to write out the ECParams
    if ( ctx->role == MBEDTLS_ECJPAKE_SERVER ) {
      if ( len < 3 + 66 + 66 + 33) {
        return MBEDTLS_ERR_ECP_BUFFER_TOO_SMALL;
      }
      const mbedtls_ecp_curve_info *curve_info;

      if ( (curve_info = mbedtls_ecp_curve_info_from_grp_id(MBEDTLS_ECP_DP_SECP256R1) ) == NULL ) {
        return(MBEDTLS_ERR_ECP_BAD_INPUT_DATA);
      }

      // First byte is curve_type, always named_curve
      *(buf++) = MBEDTLS_ECP_TLS_NAMED_CURVE;

      // Next two bytes are the namedcurve value
      *(buf++) = curve_info->tls_id >> 8;
      *(buf++) = curve_info->tls_id & 0xFF;

      *olen += 3;
      len -= 3;
    }

    // To write TLS structures of ECJ-PAKE, we need to write:
    // * XA in uncompressed form
    // * zkpA in uncompressed form
    uint8_t *obuf = buf;
    const uint8_t *ibuf = xA;
    size_t ilen = 64;

    ret = write_tls_point(&obuf, &len, olen, &ibuf, &ilen, 64);
    if (ret != 0) {
      return ret;
    }

    ibuf = zkpA;
    ilen = 96;
    ret = write_tls_zkp(&obuf, &len, olen, &ibuf, &ilen, 64);
    if (ret != 0) {
      return ret;
    }

    return 0;
  } else {
    return MBEDTLS_ERR_PLATFORM_HW_ACCEL_FAILED;
  }
}

int mbedtls_ecjpake_read_round_two(mbedtls_ecjpake_context *ctx,
                                   const unsigned char *buf,
                                   size_t len)
{
  int ret = 0;

  // local storage for ZKP
  uint8_t zkpB[32 + 64];

  if ( ctx->role == MBEDTLS_ECJPAKE_CLIENT ) {
    const mbedtls_ecp_curve_info *curve_info;
    uint16_t tls_id;

    if ( len < 3 ) {
      return(MBEDTLS_ERR_ECP_BAD_INPUT_DATA);
    }

    // First byte is curve_type; only named_curve is handled
    if ( *(buf++) != MBEDTLS_ECP_TLS_NAMED_CURVE ) {
      return(MBEDTLS_ERR_ECP_BAD_INPUT_DATA);
    }

    // Next two bytes are the namedcurve value
    tls_id = *(buf++);
    tls_id <<= 8;
    tls_id |= *(buf++);

    if ( (curve_info = mbedtls_ecp_curve_info_from_tls_id(tls_id) ) == NULL ) {
      return(MBEDTLS_ERR_PLATFORM_FEATURE_UNSUPPORTED);
    }

    if (curve_info->grp_id != MBEDTLS_ECP_DP_SECP256R1) {
      return MBEDTLS_ERR_PLATFORM_FEATURE_UNSUPPORTED;
    }

    len -= 3;
  }

  // Should receive 1 binary point and 1 ZKP
  uint8_t *obuf = ctx->Xp;
  size_t olen = 64;

  // Parse structures
  ret = parse_tls_point(&buf, &len, NULL, &obuf, &olen);
  if (ret != 0) {
    return ret;
  }

  obuf = zkpB;
  olen = sizeof(zkpB);
  ret = parse_tls_zkp(&buf, &len, NULL, &obuf, &olen);
  if (ret != 0) {
    return ret;
  }

  if (len > 0) {
    // Too much input
    return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
  }

  // SE command structures
  sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT(SLI_SE_COMMAND_JPAKE_R2_VERIFY);
  sli_se_datatransfer_t domain_in = SLI_SE_DATATRANSFER_DEFAULT(NULL, 0);
  sli_se_datatransfer_t userid_peer = SLI_SE_DATATRANSFER_DEFAULT((void*)ecjpake_id[1 - ctx->role], strlen(ecjpake_id[1 - ctx->role]));

  sli_se_datatransfer_t Xm1_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xm1, 64);
  sli_se_datatransfer_t Xm2_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xm2, 64);
  sli_se_datatransfer_t Xp1_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp1, 64);
  sli_se_datatransfer_t Xp_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp, 64);
  sli_se_datatransfer_t zkpB_in = SLI_SE_DATATRANSFER_DEFAULT(zkpB, sizeof(zkpB));

  sli_se_mailbox_command_add_input(&command, &domain_in);
  sli_se_mailbox_command_add_input(&command, &userid_peer);

  sli_se_mailbox_command_add_input(&command, &Xm1_in);
  sli_se_mailbox_command_add_input(&command, &Xm2_in);
  sli_se_mailbox_command_add_input(&command, &Xp1_in);
  sli_se_mailbox_command_add_input(&command, &Xp_in);
  sli_se_mailbox_command_add_input(&command, &zkpB_in);

  sli_se_mailbox_command_add_parameter(&command, ctx->curve_flags);
  sli_se_mailbox_command_add_parameter(&command, strlen(ecjpake_id[1 - ctx->role]));

  int status = se_management_acquire();
  if (status != 0) {
    return status;
  }

  sli_se_mailbox_execute_command(&command);
  sli_se_mailbox_response_t res = sli_se_handle_mailbox_response();

  se_management_release();

  if ( res == SLI_SE_RESPONSE_OK ) {
    return 0;
  } else {
    return MBEDTLS_ERR_ECP_VERIFY_FAILED;
  }
}

int mbedtls_ecjpake_derive_secret(mbedtls_ecjpake_context *ctx,
                                  unsigned char *buf, size_t len, size_t *olen,
                                  int (*f_rng)(void *, unsigned char *, size_t),
                                  void *p_rng)
{
  // SE has internal RNG
  (void)f_rng;
  (void)p_rng;

  if (len < 32) {
    return MBEDTLS_ERR_ECP_BUFFER_TOO_SMALL;
  }

  // Generated session key needs to come out unprotected
  uint32_t gen_key_flags = 32;

  // SE command structures
  sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT(SLI_SE_COMMAND_JPAKE_GEN_SESSIONKEY | SLI_SE_COMMAND_OPTION_HASH_SHA256);
  sli_se_datatransfer_t domain_in = SLI_SE_DATATRANSFER_DEFAULT(NULL, 0);
  sli_se_datatransfer_t pwd_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->pwd, ctx->pwd_len);

  sli_se_datatransfer_t r_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->r, 32);
  sli_se_datatransfer_t Xp2_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp2, 64);
  sli_se_datatransfer_t Xp_in = SLI_SE_DATATRANSFER_DEFAULT(ctx->Xp, 64);
  sli_se_datatransfer_t key_out = SLI_SE_DATATRANSFER_DEFAULT(buf, 32);

  sli_se_mailbox_command_add_input(&command, &domain_in);
  sli_se_mailbox_command_add_input(&command, &pwd_in);

  sli_se_mailbox_command_add_input(&command, &r_in);
  sli_se_mailbox_command_add_input(&command, &Xp2_in);
  sli_se_mailbox_command_add_input(&command, &Xp_in);

  sli_se_mailbox_command_add_output(&command, &key_out);

  sli_se_mailbox_command_add_parameter(&command, ctx->curve_flags);
  sli_se_mailbox_command_add_parameter(&command, ctx->pwd_len);
  sli_se_mailbox_command_add_parameter(&command, gen_key_flags);

  int status = se_management_acquire();
  if (status != 0) {
    return status;
  }

  sli_se_mailbox_execute_command(&command);
  sli_se_mailbox_response_t res = sli_se_handle_mailbox_response();

  se_management_release();

  if ( res == SLI_SE_RESPONSE_OK ) {
    *olen = 32;
    return 0;
  } else {
    *olen = 0;
    return MBEDTLS_ERR_ECP_VERIFY_FAILED;
  }
}

int mbedtls_ecjpake_write_shared_key(mbedtls_ecjpake_context *ctx,
                                     unsigned char *buf, size_t len, size_t *olen,
                                     int (*f_rng)(void *, unsigned char *, size_t),
                                     void *p_rng)
{
  (void)ctx;
  (void)buf;
  (void)len;
  (void)olen;
  (void)f_rng;
  (void)p_rng;

  return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
}

void mbedtls_ecjpake_free(mbedtls_ecjpake_context *ctx)
{
  if (ctx == NULL) {
    return;
  }

  memset(ctx, 0, sizeof(*ctx));
}

#endif /* #if defined(SEMAILBOX_PRESENT) */

#endif /* #if defined(MBEDTLS_ECJPAKE_ALT) && defined(MBEDTLS_ECJPAKE_C) */
