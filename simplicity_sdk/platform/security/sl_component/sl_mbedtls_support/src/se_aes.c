/***************************************************************************//**
 * @file
 * @brief AES abstraction based on Secure Engine
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

/*
 * This file includes alternative plugin implementations of various
 * functions in aes.c using the Secure Engine accelerator incorporated
 * in Series-2 devices with Secure Engine from Silicon Laboratories.
 */

/**
 *  The AES block cipher was designed by Vincent Rijmen and Joan Daemen.
 *
 *  http://csrc.nist.gov/encryption/aes/rijndael/Rijndael.pdf
 *  http://csrc.nist.gov/publications/fips/fips197/fips-197.pdf
 */

#include <mbedtls/build_info.h>

#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_AES_ALT)

#include "em_device.h"

#if defined(SEMAILBOX_PRESENT)

#include "sli_se_manager_mailbox.h"
#include "sli_se_manager_internal.h"
#include "se_management.h"
#include "mbedtls/aes.h"
#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
#include "mbedtls/error.h"
#include <string.h>

/*
 * Initialize AES context
 */
void mbedtls_aes_init(mbedtls_aes_context *ctx)
{
  memset(ctx, 0, sizeof(mbedtls_aes_context) );
}

/*
 * Clear AES context
 */
void mbedtls_aes_free(mbedtls_aes_context *ctx)
{
  if ( ctx == NULL ) {
    return;
  }

  memset(ctx, 0, sizeof(mbedtls_aes_context) );
}

#if defined(MBEDTLS_CIPHER_MODE_XTS)
void mbedtls_aes_xts_init(mbedtls_aes_xts_context *ctx)
{
  mbedtls_aes_init(&ctx->crypt);
  mbedtls_aes_init(&ctx->tweak);
}

void mbedtls_aes_xts_free(mbedtls_aes_xts_context *ctx)
{
  if ( ctx == NULL ) {
    return;
  }

  mbedtls_aes_free(&ctx->crypt);
  mbedtls_aes_free(&ctx->tweak);
}

static int mbedtls_aes_xts_decode_keys(const unsigned char *key,
                                       unsigned int keybits,
                                       const unsigned char **key1,
                                       unsigned int *key1bits,
                                       const unsigned char **key2,
                                       unsigned int *key2bits)
{
  const unsigned int half_keybits = keybits / 2;
  const unsigned int half_keybytes = half_keybits / 8;

  switch ( keybits ) {
    case 256: break;
    case 512: break;
    default: return(MBEDTLS_ERR_AES_INVALID_KEY_LENGTH);
  }

  *key1bits = half_keybits;
  *key2bits = half_keybits;
  *key1 = &key[0];
  *key2 = &key[half_keybytes];

  return 0;
}

int mbedtls_aes_xts_setkey_enc(mbedtls_aes_xts_context *ctx,
                               const unsigned char *key,
                               unsigned int keybits)
{
  int ret;
  const unsigned char *key1 = NULL;
  const unsigned char *key2 = NULL;
  unsigned int key1bits = 0;
  unsigned int key2bits = 0;

  ret = mbedtls_aes_xts_decode_keys(key, keybits, &key1, &key1bits,
                                    &key2, &key2bits);
  if ( ret != 0 ) {
    return(ret);
  }

  /* Set the tweak key. Always set tweak key for the encryption mode. */
  ret = mbedtls_aes_setkey_enc(&ctx->tweak, key2, key2bits);
  if ( ret != 0 ) {
    return(ret);
  }

  /* Set crypt key for encryption. */
  return mbedtls_aes_setkey_enc(&ctx->crypt, key1, key1bits);
}

int mbedtls_aes_xts_setkey_dec(mbedtls_aes_xts_context *ctx,
                               const unsigned char *key,
                               unsigned int keybits)
{
  int ret;
  const unsigned char *key1 = NULL;
  const unsigned char *key2 = NULL;
  unsigned int key1bits = 0;
  unsigned int key2bits = 0;

  if (ctx == NULL || key == NULL) {
    return MBEDTLS_ERR_AES_BAD_INPUT_DATA;
  }

  ret = mbedtls_aes_xts_decode_keys(key, keybits, &key1, &key1bits,
                                    &key2, &key2bits);
  if ( ret != 0 ) {
    return(ret);
  }

  /* Set the tweak key. Always set tweak key for encryption. */
  ret = mbedtls_aes_setkey_enc(&ctx->tweak, key2, key2bits);
  if ( ret != 0 ) {
    return(ret);
  }

  /* Set crypt key for decryption. */
  return mbedtls_aes_setkey_dec(&ctx->crypt, key1, key1bits);
}

/* Endianess with 64 bits values */
#ifndef GET_UINT64_LE
#define GET_UINT64_LE(n, b, i)               \
  {                                          \
    (n) = ( (uint64_t) (b)[(i) + 7] << 56)   \
          | ( (uint64_t) (b)[(i) + 6] << 48) \
          | ( (uint64_t) (b)[(i) + 5] << 40) \
          | ( (uint64_t) (b)[(i) + 4] << 32) \
          | ( (uint64_t) (b)[(i) + 3] << 24) \
          | ( (uint64_t) (b)[(i) + 2] << 16) \
          | ( (uint64_t) (b)[(i) + 1] <<  8) \
          | ( (uint64_t) (b)[(i)]);          \
  }
#endif

#ifndef PUT_UINT64_LE
#define PUT_UINT64_LE(n, b, i)                   \
  {                                              \
    (b)[(i) + 7] = (unsigned char) ( (n) >> 56); \
    (b)[(i) + 6] = (unsigned char) ( (n) >> 48); \
    (b)[(i) + 5] = (unsigned char) ( (n) >> 40); \
    (b)[(i) + 4] = (unsigned char) ( (n) >> 32); \
    (b)[(i) + 3] = (unsigned char) ( (n) >> 24); \
    (b)[(i) + 2] = (unsigned char) ( (n) >> 16); \
    (b)[(i) + 1] = (unsigned char) ( (n) >>  8); \
    (b)[(i)] = (unsigned char) ( (n)       );    \
  }
#endif

/*
 * GF(2^128) multiplication function
 *
 * This function multiplies a field element by x in the polynomial field
 * representation. It uses 64-bit word operations to gain speed but compensates
 * for machine endianess and hence works correctly on both big and little
 * endian machines.
 */
static void mbedtls_gf128mul_x_ble(unsigned char r[16],
                                   const unsigned char x[16])
{
  uint64_t a, b, ra, rb;

  GET_UINT64_LE(a, x, 0);
  GET_UINT64_LE(b, x, 8);

  ra = (a << 1)  ^ 0x0087 >> (8 - ( (b >> 63) << 3) );
  rb = (a >> 63) | (b << 1);

  PUT_UINT64_LE(ra, r, 0);
  PUT_UINT64_LE(rb, r, 8);
}

/*
 * AES-XTS buffer encryption/decryption
 */
int mbedtls_aes_crypt_xts(mbedtls_aes_xts_context *ctx,
                          int mode,
                          size_t length,
                          const unsigned char data_unit[16],
                          const unsigned char *input,
                          unsigned char *output)
{
  int ret;
  size_t blocks = length / 16;
  size_t leftover = length % 16;
  unsigned char tweak[16];
  unsigned char prev_tweak[16];
  unsigned char tmp[16];

  if ((mode != MBEDTLS_AES_ENCRYPT) && (mode != MBEDTLS_AES_DECRYPT)) {
    return MBEDTLS_ERR_AES_BAD_INPUT_DATA;
  }

  /* Data units must be at least 16 bytes long. */
  if ( length < 16 ) {
    return MBEDTLS_ERR_AES_INVALID_INPUT_LENGTH;
  }

  /* NIST SP 800-38E disallows data units larger than 2**20 blocks. */
  if ( length > (1 << 20) * 16 ) {
    return MBEDTLS_ERR_AES_INVALID_INPUT_LENGTH;
  }

  /* Compute the tweak. */
  ret = mbedtls_aes_crypt_ecb(&ctx->tweak, MBEDTLS_AES_ENCRYPT,
                              data_unit, tweak);
  if ( ret != 0 ) {
    return(ret);
  }

  while ( blocks-- ) {
    size_t i;

    if ( leftover && (mode == MBEDTLS_AES_DECRYPT) && blocks == 0 ) {
      /* We are on the last block in a decrypt operation that has
       * leftover bytes, so we need to use the next tweak for this block,
       * and this tweak for the lefover bytes. Save the current tweak for
       * the leftovers and then update the current tweak for use on this,
       * the last full block. */
      memcpy(prev_tweak, tweak, sizeof(tweak) );
      mbedtls_gf128mul_x_ble(tweak, tweak);
    }

    for ( i = 0; i < 16; i++ ) {
      tmp[i] = input[i] ^ tweak[i];
    }

    ret = mbedtls_aes_crypt_ecb(&ctx->crypt, mode, tmp, tmp);
    if ( ret != 0 ) {
      return(ret);
    }

    for ( i = 0; i < 16; i++ ) {
      output[i] = tmp[i] ^ tweak[i];
    }

    /* Update the tweak for the next block. */
    mbedtls_gf128mul_x_ble(tweak, tweak);

    output += 16;
    input += 16;
  }

  if ( leftover ) {
    /* If we are on the leftover bytes in a decrypt operation, we need to
    * use the previous tweak for these bytes (as saved in prev_tweak). */
    unsigned char *t = mode == MBEDTLS_AES_DECRYPT ? prev_tweak : tweak;

    /* We are now on the final part of the data unit, which doesn't divide
     * evenly by 16. It's time for ciphertext stealing. */
    size_t i;
    unsigned char *prev_output = output - 16;

    /* Copy ciphertext bytes from the previous block to our output for each
     * byte of cyphertext we won't steal. At the same time, copy the
     * remainder of the input for this final round (since the loop bounds
     * are the same). */
    for ( i = 0; i < leftover; i++ ) {
      output[i] = prev_output[i];
      tmp[i] = input[i] ^ t[i];
    }

    /* Copy ciphertext bytes from the previous block for input in this
     * round. */
    for (; i < 16; i++ ) {
      tmp[i] = prev_output[i] ^ t[i];
    }

    ret = mbedtls_aes_crypt_ecb(&ctx->crypt, mode, tmp, tmp);
    if ( ret != 0 ) {
      return ret;
    }

    /* Write the result back to the previous block, overriding the previous
     * output we copied. */
    for ( i = 0; i < 16; i++ ) {
      prev_output[i] = tmp[i] ^ t[i];
    }
  }

  return(0);
}

#endif /* MBEDTLS_CIPHER_MODE_XTS */

/*
 * AES key schedule (encryption)
 */
int mbedtls_aes_setkey_enc(mbedtls_aes_context *ctx,
                           const unsigned char *key,
                           unsigned int keybits)
{
  memset(ctx, 0, sizeof(mbedtls_aes_context) );

  if ( (128UL != keybits) && (192UL != keybits) && (256UL != keybits) ) {
    // Unsupported key size
    return MBEDTLS_ERR_AES_INVALID_KEY_LENGTH;
  }

  ctx->keybits = keybits;
  memcpy(ctx->key, key, keybits / 8);

  return 0;
}

/*
 * AES key schedule (decryption)
 */
int mbedtls_aes_setkey_dec(mbedtls_aes_context *ctx,
                           const unsigned char *key,
                           unsigned int keybits)
{
  return mbedtls_aes_setkey_enc(ctx, key, keybits);
}

/*
 * AES-ECB block encryption/decryption
 */
int mbedtls_aes_crypt_ecb(mbedtls_aes_context *ctx,
                          int mode,
                          const unsigned char input[16],
                          unsigned char output[16])
{
  sli_se_mailbox_response_t command_status;

  if ((mode != MBEDTLS_AES_ENCRYPT) && (mode != MBEDTLS_AES_DECRYPT)) {
    return MBEDTLS_ERR_AES_BAD_INPUT_DATA;
  }

  if ( ctx->keybits != 128UL && ctx->keybits != 192UL && ctx->keybits != 256UL) {
    return MBEDTLS_ERR_PLATFORM_FEATURE_UNSUPPORTED;
  }

  sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT((mode == MBEDTLS_AES_ENCRYPT ? SLI_SE_COMMAND_AES_ENCRYPT : SLI_SE_COMMAND_AES_DECRYPT) | SLI_SE_COMMAND_OPTION_MODE_ECB | SLI_SE_COMMAND_OPTION_CONTEXT_WHOLE);
  sli_se_datatransfer_t key = SLI_SE_DATATRANSFER_DEFAULT(ctx->key, (ctx->keybits / 8));
  sli_se_datatransfer_t in = SLI_SE_DATATRANSFER_DEFAULT((void*)input, 16);
  sli_se_datatransfer_t out = SLI_SE_DATATRANSFER_DEFAULT(output, 16);

  sli_se_mailbox_command_add_input(&command, &key);
  sli_se_mailbox_command_add_input(&command, &in);
  sli_se_mailbox_command_add_output(&command, &out);
  sli_se_mailbox_command_add_parameter(&command, (ctx->keybits / 8));
  sli_se_mailbox_command_add_parameter(&command, 16);

  int status = se_management_acquire();
  if (status != 0) {
    return status;
  }

  sli_se_mailbox_execute_command(&command);
  command_status = sli_se_handle_mailbox_response();

  se_management_release();

  if ( command_status == SLI_SE_RESPONSE_OK ) {
    return 0;
  } else {
    return (int)command_status;
  }
}

#if defined(MBEDTLS_CIPHER_MODE_CBC)

/*
 * AES-CBC buffer encryption/decryption
 */
int mbedtls_aes_crypt_cbc(mbedtls_aes_context *ctx,
                          int mode,
                          size_t length,
                          unsigned char iv[16],
                          const unsigned char *input,
                          unsigned char *output)
{
  sli_se_mailbox_response_t command_status;

  if ((mode != MBEDTLS_AES_ENCRYPT) && (mode != MBEDTLS_AES_DECRYPT)) {
    return MBEDTLS_ERR_AES_BAD_INPUT_DATA;
  }

  // Input length must be a multiple of 16 bytes which is the AES block
  // length.
  if ( length & 0xf ) {
    return MBEDTLS_ERR_AES_INVALID_INPUT_LENGTH;
  }

  if ( ctx->keybits != 128UL && ctx->keybits != 192UL && ctx->keybits != 256UL) {
    return MBEDTLS_ERR_AES_INVALID_KEY_LENGTH;
  }

  sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT((mode == MBEDTLS_AES_ENCRYPT ? SLI_SE_COMMAND_AES_ENCRYPT : SLI_SE_COMMAND_AES_DECRYPT) | SLI_SE_COMMAND_OPTION_MODE_CBC | SLI_SE_COMMAND_OPTION_CONTEXT_ADD);
  sli_se_datatransfer_t key = SLI_SE_DATATRANSFER_DEFAULT(ctx->key, (ctx->keybits / 8));
  sli_se_datatransfer_t iv_in = SLI_SE_DATATRANSFER_DEFAULT(iv, 16);
  sli_se_datatransfer_t iv_out = SLI_SE_DATATRANSFER_DEFAULT(iv, 16);
  sli_se_datatransfer_t in = SLI_SE_DATATRANSFER_DEFAULT((void*)input, length);
  sli_se_datatransfer_t out = SLI_SE_DATATRANSFER_DEFAULT(output, length);

  sli_se_mailbox_command_add_input(&command, &key);
  sli_se_mailbox_command_add_input(&command, &iv_in);
  sli_se_mailbox_command_add_input(&command, &in);
  sli_se_mailbox_command_add_output(&command, &out);
  sli_se_mailbox_command_add_output(&command, &iv_out);
  sli_se_mailbox_command_add_parameter(&command, (ctx->keybits / 8));
  sli_se_mailbox_command_add_parameter(&command, length);

  int status = se_management_acquire();
  if (status != 0) {
    return status;
  }

  sli_se_mailbox_execute_command(&command);
  command_status = sli_se_handle_mailbox_response();

  se_management_release();

  if ( command_status == SLI_SE_RESPONSE_OK ) {
    return 0;
  } else {
    return (int)command_status;
  }
}
#endif /* MBEDTLS_CIPHER_MODE_CBC */

#if defined(MBEDTLS_CIPHER_MODE_CFB)
/*
 * AES-CFB128 buffer encryption/decryption
 */
int mbedtls_aes_crypt_cfb128(mbedtls_aes_context *ctx,
                             int mode,
                             size_t length,
                             size_t *iv_off,
                             unsigned char iv[16],
                             const unsigned char *input,
                             unsigned char *output)
{
  size_t n = iv_off ? *iv_off : 0;
  size_t processed = 0;
  sli_se_mailbox_response_t command_status = SLI_SE_RESPONSE_OK;

  if ((mode != MBEDTLS_AES_ENCRYPT) && (mode != MBEDTLS_AES_DECRYPT)) {
    return MBEDTLS_ERR_AES_BAD_INPUT_DATA;
  }

  if ( n > 15 ) {
    return MBEDTLS_ERR_AES_BAD_INPUT_DATA;
  }

  if ( ctx->keybits != 128UL && ctx->keybits != 192UL && ctx->keybits != 256UL) {
    return MBEDTLS_ERR_AES_INVALID_KEY_LENGTH;
  }

  while ( processed < length ) {
    if ( n > 0 ) {
      /* start by filling up the IV */
      if ( mode == MBEDTLS_AES_ENCRYPT ) {
        iv[n] = output[processed] = (unsigned char)(iv[n] ^ input[processed]);
      } else {
        int c = input[processed];
        output[processed] = (unsigned char)(c ^ iv[n]);
        iv[n] = (unsigned char) c;
      }
      n = (n + 1) & 0x0F;
      processed++;
    } else {
      /* process one ore more blocks of data */
      size_t iterations = (length - processed) / 16;

      if ( iterations > 0 ) {
        sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT((mode == MBEDTLS_AES_ENCRYPT ? SLI_SE_COMMAND_AES_ENCRYPT : SLI_SE_COMMAND_AES_DECRYPT) | SLI_SE_COMMAND_OPTION_MODE_CFB | SLI_SE_COMMAND_OPTION_CONTEXT_ADD);
        sli_se_datatransfer_t key = SLI_SE_DATATRANSFER_DEFAULT(ctx->key, (ctx->keybits / 8));
        sli_se_datatransfer_t iv_in = SLI_SE_DATATRANSFER_DEFAULT(iv, 16);
        sli_se_datatransfer_t iv_out = SLI_SE_DATATRANSFER_DEFAULT(iv, 16);
        sli_se_datatransfer_t in = SLI_SE_DATATRANSFER_DEFAULT((void*)&input[processed], iterations * 16);
        sli_se_datatransfer_t out = SLI_SE_DATATRANSFER_DEFAULT(&output[processed], iterations * 16);

        sli_se_mailbox_command_add_input(&command, &key);
        sli_se_mailbox_command_add_input(&command, &iv_in);
        sli_se_mailbox_command_add_input(&command, &in);
        sli_se_mailbox_command_add_output(&command, &out);
        sli_se_mailbox_command_add_output(&command, &iv_out);
        sli_se_mailbox_command_add_parameter(&command, (ctx->keybits / 8));
        sli_se_mailbox_command_add_parameter(&command, iterations * 16);

        int status = se_management_acquire();
        if (status != 0) {
          return status;
        }

        sli_se_mailbox_execute_command(&command);
        command_status = sli_se_handle_mailbox_response();

        se_management_release();
        processed += iterations * 16;
      }

      if ( command_status != SLI_SE_RESPONSE_OK ) {
        goto exit;
      }

      while ( length - processed > 0 ) {
        if ( n == 0 ) {
          // Need to update the IV but don't have a full block of input to pass to the SE
          int status = mbedtls_aes_crypt_ecb(ctx, MBEDTLS_AES_ENCRYPT, iv, iv);
          if (status != 0) {
            return status;
          }
        }
        /* Save remainder to iv */
        if ( mode == MBEDTLS_AES_ENCRYPT ) {
          iv[n] = output[processed] = (unsigned char)(iv[n] ^ input[processed]);
        } else {
          int c = input[processed];
          output[processed] = (unsigned char)(c ^ iv[n]);
          iv[n] = (unsigned char) c;
        }
        n = (n + 1) & 0x0F;
        processed++;
      }
    }
  }

  if ( iv_off ) {
    *iv_off = n;
  }

  exit:
  if ( command_status == SLI_SE_RESPONSE_OK ) {
    return 0;
  } else {
    return (int)command_status;
  }
}

/*
 * AES-CFB8 buffer encryption/decryption
 */
int mbedtls_aes_crypt_cfb8(mbedtls_aes_context *ctx,
                           int mode,
                           size_t length,
                           unsigned char iv[16],
                           const unsigned char *input,
                           unsigned char *output)
{
  unsigned char c;
  unsigned char ov[17];
  int ret = 0;

  if ((mode != MBEDTLS_AES_ENCRYPT) && (mode != MBEDTLS_AES_DECRYPT)) {
    return MBEDTLS_ERR_AES_BAD_INPUT_DATA;
  }

  if ( ctx->keybits != 128UL && ctx->keybits != 192UL && ctx->keybits != 256UL) {
    return MBEDTLS_ERR_AES_INVALID_KEY_LENGTH;
  }

  while ( length-- ) {
    memcpy(ov, iv, 16);
    if ( (ret = mbedtls_aes_crypt_ecb(ctx, MBEDTLS_AES_ENCRYPT, iv, iv) ) != 0 ) {
      return ret;
    }

    if ( mode == MBEDTLS_AES_DECRYPT ) {
      ov[16] = *input;
    }

    c = *output++ = (unsigned char)(iv[0] ^ *input++);

    if ( mode == MBEDTLS_AES_ENCRYPT ) {
      ov[16] = c;
    }

    memcpy(iv, ov + 1, 16);
  }

  return ret;
}
#endif /*MBEDTLS_CIPHER_MODE_CFB */

#if defined(MBEDTLS_CIPHER_MODE_CTR)
/*
 * AES-CTR buffer encryption/decryption
 */
int mbedtls_aes_crypt_ctr(mbedtls_aes_context *ctx,
                          size_t length,
                          size_t *nc_off,
                          unsigned char nonce_counter[16],
                          unsigned char stream_block[16],
                          const unsigned char *input,
                          unsigned char *output)
{
  size_t n = nc_off ? *nc_off : 0;
  size_t processed = 0;
  sli_se_mailbox_response_t command_status = SLI_SE_RESPONSE_OK;

  if ( ctx->keybits != 128UL && ctx->keybits != 192UL && ctx->keybits != 256UL) {
    return MBEDTLS_ERR_AES_INVALID_KEY_LENGTH;
  }

  while ( processed < length ) {
    if ( n > 0 ) {
      /* start by filling up the IV */
      output[processed] = (unsigned char)(input[processed] ^ stream_block[n]);
      n = (n + 1) & 0x0F;
      processed++;
    } else {
      /* process one or more blocks of data */
      size_t iterations = (length - processed) / 16;

      if ( iterations > 0 ) {
        sli_se_mailbox_command_t command = SLI_SE_MAILBOX_COMMAND_DEFAULT(SLI_SE_COMMAND_AES_ENCRYPT | SLI_SE_COMMAND_OPTION_MODE_CTR | SLI_SE_COMMAND_OPTION_CONTEXT_ADD);
        sli_se_datatransfer_t key = SLI_SE_DATATRANSFER_DEFAULT(ctx->key, (ctx->keybits / 8));
        sli_se_datatransfer_t iv_in = SLI_SE_DATATRANSFER_DEFAULT(nonce_counter, 16);
        sli_se_datatransfer_t iv_out = SLI_SE_DATATRANSFER_DEFAULT(nonce_counter, 16);
        sli_se_datatransfer_t in = SLI_SE_DATATRANSFER_DEFAULT((void*)&input[processed], iterations * 16);
        sli_se_datatransfer_t out = SLI_SE_DATATRANSFER_DEFAULT(&output[processed], iterations * 16);

        sli_se_mailbox_command_add_input(&command, &key);
        sli_se_mailbox_command_add_input(&command, &iv_in);
        sli_se_mailbox_command_add_input(&command, &in);
        sli_se_mailbox_command_add_output(&command, &out);
        sli_se_mailbox_command_add_output(&command, &iv_out);
        sli_se_mailbox_command_add_parameter(&command, (ctx->keybits / 8));
        sli_se_mailbox_command_add_parameter(&command, iterations * 16);

        int status = se_management_acquire();
        if (status != 0) {
          return status;
        }

        sli_se_mailbox_execute_command(&command);
        command_status = sli_se_handle_mailbox_response();

        se_management_release();
        processed += iterations * 16;
      }

      if ( command_status != SLI_SE_RESPONSE_OK ) {
        goto exit;
      }

      while ( length - processed > 0 ) {
        if ( n == 0 ) {
          // Get a new stream block
          int status = mbedtls_aes_crypt_ecb(ctx,
                                             MBEDTLS_AES_ENCRYPT,
                                             nonce_counter,
                                             stream_block);
          if (status != 0) {
            return status;
          }
          // increment nonce counter...
          for (size_t i = 0; i < 16; i++) {
            nonce_counter[15 - i] = nonce_counter[15 - i] + 1;
            if ( nonce_counter[15 - i] != 0 ) {
              break;
            }
          }
        }
        /* Save remainder to iv */
        output[processed] = (unsigned char)(input[processed] ^ stream_block[n]);
        n = (n + 1) & 0x0F;
        processed++;
      }
    }
  }

  if ( nc_off ) {
    *nc_off = n;
  }

  exit:
  if ( command_status == SLI_SE_RESPONSE_OK ) {
    return 0;
  } else {
    return (int)command_status;
  }
}
#endif /* MBEDTLS_CIPHER_MODE_CTR */

#if defined(MBEDTLS_CIPHER_MODE_OFB)
/*
 * AES-OFB (Output Feedback Mode) buffer encryption/decryption
 */
int mbedtls_aes_crypt_ofb(mbedtls_aes_context *ctx,
                          size_t length,
                          size_t *iv_off,
                          unsigned char iv[16],
                          const unsigned char *input,
                          unsigned char *output)
{
  int ret = 0;
  size_t n;

  n = *iv_off;

  if ( n > 15 ) {
    return(MBEDTLS_ERR_AES_BAD_INPUT_DATA);
  }

  while ( length-- ) {
    if ( n == 0 ) {
      ret = mbedtls_aes_crypt_ecb(ctx, MBEDTLS_AES_ENCRYPT, iv, iv);
      if ( ret != 0 ) {
        goto exit;
      }
    }
    *output++ =  *input++ ^ iv[n];

    n = (n + 1) & 0x0F;
  }

  *iv_off = n;

  exit:
  return(ret);
}
#endif /* MBEDTLS_CIPHER_MODE_OFB */

#endif /* SEMAILBOX_PRESENT */

#endif /* MBEDTLS_AES_ALT */

#endif /* MBEDTLS_AES_C */
