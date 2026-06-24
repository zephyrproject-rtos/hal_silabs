/***************************************************************************//**
 * @file
 * @brief Silicon Labs PSA Crypto Opaque Driver Key Derivation functions.
 *******************************************************************************
 * # License
 * <b>Copyright 2023 Silicon Laboratories Inc. www.silabs.com</b>
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

#include "em_device.h"
#include "psa/crypto.h"
#include "sli_mbedtls_omnipresent.h"
#include "sli_cryptoacc_opaque_types.h"
#include "sli_psa_driver_features.h"
#include "sli_psa_driver_common.h"
#include "cryptoacc_management.h"
#include "cryptolib_def.h"
#include "sx_errors.h"
#include "sx_aes.h"

#if defined(SLI_PSA_DRIVER_FEATURE_PBKDF2) || defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)

#include <string.h>
#include "sl_psa_values.h"

// -----------------------------------------------------------------------------
// Defines

#if defined(SLI_PSA_DRIVER_FEATURE_PBKDF2)
#define PBKDF2_COUNTER_ENCODING_SIZE  (4u)
#endif

// -----------------------------------------------------------------------------
// Static helper functions

/// @brief
///   Converting a value to a big endian octet string.
static void uint32_to_octet_string(uint32_t value, uint8_t buffer[4])
{
  for (uint8_t i = 0; i < 4; i++) {
    buffer[i] = (uint8_t)((value >> (8 * (3 - i))) & 0xFF);
  }
}

#if defined(SLI_PSA_DRIVER_FEATURE_PBKDF2)

/// @brief
///   XOR the data pointed to by the two input blocks (of len 16 B). Result is
///   stored in dk.
///
/// @note
///   This function assumes that both block_t:s point to word-aligned addresses.
static void xorbuf(block_t dk, block_t u)
{
  for (uint32_t i = 0; i < u.len; i += 4) {
    *(uint32_t*)((uint32_t)dk.addr + i) ^= *(uint32_t*)((uint32_t)u.addr + i);
  }
}

// -----------------------------------------------------------------------------
// Custom implementation of PBKDF2 using AES-CMAC-128-PRF

/// @brief
///   Perform the PBKDF2 algorithm with AES-CMAC-128-PRF.
static psa_status_t derive_key_pbkdf2_aes_cmac_128_prf(
  block_t  *password,
  block_t  *salt,
  uint32_t iterations,
  uint32_t derived_key_length,
  block_t  *derived_key)
{
  psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
  // Buffers for storing temporary/partial results of the operation.
  uint8_t temp_buf_1[AES_MAC_SIZE];
  block_t temp_blk_1 = block_t_convert(temp_buf_1, AES_MAC_SIZE);
  uint8_t temp_buf_2[AES_MAC_SIZE];
  block_t temp_blk_2 = block_t_convert(temp_buf_2, AES_MAC_SIZE);

  // Make sure that we can handle the length of the salt input.
  if (salt->len > DERIV_MAX_SALT_SIZE) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  // Make sure that the output key length is sufficient.
  if (derived_key->len < derived_key_length) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  // Buffer for appending the iteration counter to the input salt before
  // applying the PRF.
  uint8_t internal_data_buf[DERIV_MAX_SALT_SIZE + PBKDF2_COUNTER_ENCODING_SIZE]
    = { 0 };
  block_t internal_data_blk =
    block_t_convert(internal_data_buf,
                    salt->len + PBKDF2_COUNTER_ENCODING_SIZE);

  uint8_t *counter_encoding = &internal_data_buf[salt->len];

  // Read the user provided salt into our internal buffer.
  memcpy(internal_data_buf, salt->addr, salt->len);

  // It is possible that the password provided is not of the expected size for
  // AES-128. In those cases, we will have to expand the password to 16 bytes;
  // this is done as described in RFC4615.
  uint8_t internal_password_buf[AES_KEYSIZE_128] = { 0 };
  if (password->len != AES_KEYSIZE_128) {
    block_t internal_password_blk =
      block_t_convert(internal_password_buf, sizeof(internal_password_buf));
    uint32_t sx_ret;
    if (password->addr == &aes_hw_key1 || password->addr == &aes_hw_key2) {
      // Hardware keys cannot be read as data by DMA.
      return PSA_ERROR_NOT_SUPPORTED;
    } else {
      // Acquire hardware lock and execute CMAC operation
      status = cryptoacc_management_acquire();
      if (status != PSA_SUCCESS) {
        return status;
      }
      // Standard RFC 4615: CMAC(zero_key, password_data) → 128-bit key
      sx_ret = sx_aes_cmac_generate(&internal_password_blk,
                                     password,
                                     &internal_password_blk);
      status = cryptoacc_management_release();
    }

    if (status != PSA_SUCCESS) {
      return status;
    }
    if (sx_ret != CRYPTOLIB_SUCCESS) {
      return PSA_ERROR_HARDWARE_FAILURE;
    }
    *password = internal_password_blk;
  }

  uint32_t output_key_length = 0;
  uint32_t i = 1;
  while (output_key_length < derived_key_length) {
    // Encode counter value.
    uint32_to_octet_string(i, counter_encoding);

    // First Block (U_1).
    // Acquire hardware lock and execute CMAC operation
    status = cryptoacc_management_acquire();
    if (status != PSA_SUCCESS) {
      return status;
    }
    uint32_t sx_ret = sx_aes_cmac_generate(password,
                                           &internal_data_blk,
                                           &temp_blk_1);
    status = cryptoacc_management_release();
    if (status != PSA_SUCCESS) {
      return status;
    }
    if (sx_ret != CRYPTOLIB_SUCCESS) {
      return PSA_ERROR_HARDWARE_FAILURE;
    }
    memcpy(temp_blk_2.addr, temp_blk_1.addr, AES_MAC_SIZE);

    // Remaining blocks (U_j).
    for (uint32_t j = 1; j < iterations; j++) {
      status = cryptoacc_management_acquire();
      if (status != PSA_SUCCESS) {
        return status;
      }
      sx_ret = sx_aes_cmac_generate(password, &temp_blk_1, &temp_blk_1);
      status = cryptoacc_management_release();
      if (status != PSA_SUCCESS) {
        return status;
      }
      if (sx_ret != CRYPTOLIB_SUCCESS) {
        return PSA_ERROR_HARDWARE_FAILURE;
      }
      xorbuf(temp_blk_2, temp_blk_1);
    }

    uint32_t partial_output_length =
      (derived_key_length - output_key_length >= AES_MAC_SIZE)
      ? (AES_MAC_SIZE) : (derived_key_length - output_key_length);

    output_key_length += partial_output_length;

    memcpy(derived_key->addr, temp_blk_2.addr, partial_output_length);
    derived_key->len -= partial_output_length;
    if (!(derived_key->flags & BLOCK_S_CONST_ADDR)) {
      derived_key->addr += partial_output_length;
    }

    i += 1;
  }

  return PSA_SUCCESS;
}

#endif // defined(SLI_PSA_DRIVER_FEATURE_PBKDF2)

// -----------------------------------------------------------------------------
// NIST SP 800-108r1 KDF in Counter Mode using AES-CMAC as the PRF.
//
// K_IN may be a PUF hardware key or a transparent software key.  The key is
// always in the KEY position for AES-CMAC and never exposed as data.  A
// domain-separation label is chosen automatically based on the key type to
// ensure PUF-derived and software-derived keys never collide.
//
//   K(i) = AES-CMAC(K_IN, [i]_2 || Label || 0x00 || Context || [L]_2)
//
// Reference: NIST SP 800-108r1 Section 4.1

#if defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)

// Fixed labels for key separation (NIST SP 800-108r1 Section 6.5).
// Versioned so that future changes produce distinct derived keys.
// PUF and non-PUF keys use different labels to ensure domain separation.
static const char sp800_108r1_label_puf[] = "kdf:sp800-108r1:cmac:puf:v1";
static const char sp800_108r1_label_key[] = "kdf:sp800-108r1:cmac:key:v1";

// Longest label determines the stack buffer size.
#define SP800_108R1_MAX_LABEL_SIZE  (sizeof(sp800_108r1_label_key) - 1)

// Maximum Context length (user secret + salt).
#define SP800_108_MAX_CONTEXT_SIZE  (DERIV_MAX_SALT_SIZE)

// Maximum derived material output in bytes.
//
// NIST SP 800-108r1 Section 4.1: the security strength of derived keying
// material is bounded by the PRF output length h.  Our PRF is AES-CMAC
// (h = 128 bits).  Deriving significantly more than h bits from a single
// KDF invocation weakens single-key security because output blocks share 
// the same PRF key.
//
// 128 bytes (1024 bits) likely covers all practical symmetric key derivation
// needs (ie. 8 h-bit subkeys, 2 128-bit AES keys + IV material)- be aware 
// using derived material in excess of h-bits as a single key may reduce 
// security margin. If more derived material is needed, invoke the KDF 
// multiple times with different context values instead.
#define SP800_108R1_MAX_DERIVED_KEY_SIZE  (128u)

/// @brief
///   Derive key material using NIST SP 800-108r1 KDF in Counter Mode with
///   AES-CMAC as the PRF.
///
/// @param[in]  kdk                 Key-Derivation Key (PUF hardware key or
///                                 transparent key block).
/// @param[in]  context             Caller-supplied context (user secret || salt).
///                                 Must be non-NULL and non-empty.
/// @param[in]  context_length      Length of context in bytes.
/// @param[in]  derived_key_length  Desired output length in bytes (must be > 0).
/// @param[out] derived_key         Output buffer (must be >= derived_key_length).
///
/// @return PSA_SUCCESS on success.
static psa_status_t derive_key_sp_800_108_r1_prf(
  block_t  *kdk,
  const uint8_t *context,
  size_t   context_length,
  uint32_t derived_key_length,
  block_t  *derived_key)
{
  // Key-derivation key must be a valid, non-empty block.
  if (kdk == NULL || kdk->addr == NULL || kdk->len == 0 || kdk->addr == &aes_hw_key2) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  // require user context for key separation
  if (context == NULL || context_length == 0) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  // Bound context length to prevent stack buffer overflow.
  if (context_length > SP800_108_MAX_CONTEXT_SIZE) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  // An output buffer of sufficient size is required 
  if (derived_key == NULL || derived_key->addr == NULL
      || derived_key->len == 0 || derived_key_length == 0) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (derived_key->len < derived_key_length) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  // Enforce a safe ceiling on derived key length to prevent buffer overflows
  // or DoS via locking the cryptoacc for GB-level derivations.
  if (derived_key_length > SP800_108R1_MAX_DERIVED_KEY_SIZE) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  const char *label;
  if (kdk->addr == &aes_hw_key1) {
    // Use a separate label to prevent context overlap with PUF key and user key.
    label     = sp800_108r1_label_puf;
  } else {
    // user key case
    label     = sp800_108r1_label_key;
  }
  // Ignore trailing null
  const size_t label_len = (strlen(label));

  psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

  // Build the fixed portion of the input:
  //   Label || 0x00 || Context || [L]_2
  // The counter [i]_2 is prepended per iteration.
  // Total fixed size: 4 (counter) + label + 1 (separator) + context + 4 (L encoding)
  const size_t input_len = sizeof(uint32_t) + label_len + sizeof(uint8_t) + context_length + sizeof(uint32_t);

  // Stack-allocate input buffer (counter + max_label + 0x00 + context + L)
  uint8_t input_buf[sizeof(uint32_t) + SP800_108R1_MAX_LABEL_SIZE + sizeof(uint8_t) + SP800_108_MAX_CONTEXT_SIZE + sizeof(uint32_t)];
  if (input_len > sizeof(input_buf)) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  // Fill the fixed portion (after the 4-byte counter slot)
  uint8_t *p = input_buf + sizeof(uint32_t);
  memcpy(p, label, label_len);
  p += label_len;
  *p++ = 0x00; // separator
  memcpy(p, context, context_length);
  p += context_length;
  // [L]_2: output length in bits, 32-bit big-endian
  uint32_to_octet_string(derived_key_length * 8, p);

  block_t input_blk = block_t_convert(input_buf, input_len);
  uint8_t mac_buf[AES_MAC_SIZE] = {0};
  block_t mac_blk = block_t_convert(mac_buf, AES_MAC_SIZE);

  uint32_t output_offset = 0;
  // Number of CMAC iterations required: n = ceil(L / 128)
  const uint32_t n = (derived_key_length + AES_MAC_SIZE - 1) / AES_MAC_SIZE;
  for (uint32_t i = 1; i <= n; i++) {
    // [i]_2: counter as 32-bit big-endian in the first 4 bytes
    uint32_to_octet_string(i, input_buf);

    status = cryptoacc_management_acquire();
    if (status != PSA_SUCCESS) {
      goto exit;
    }

    // Key is always in the KEY position (1st arg); input data in 2nd arg.
    uint32_t sx_ret = sx_aes_cmac_generate(kdk, &input_blk, &mac_blk);
    status = cryptoacc_management_release();

    if (status != PSA_SUCCESS) {
      goto exit;
    }
    if (sx_ret != CRYPTOLIB_SUCCESS) {
      status = PSA_ERROR_HARDWARE_FAILURE;
      goto exit;
    }

    // Copy output (last block may be partial)
    uint32_t chunk = (derived_key_length - output_offset >= AES_MAC_SIZE)
                     ? AES_MAC_SIZE
                     : (derived_key_length - output_offset);
    memcpy(derived_key->addr + output_offset, mac_buf, chunk);
    output_offset += chunk;
  }

  status = PSA_SUCCESS;

exit:
  // Destroy intermediate secrets: input buffer contains the caller's context,
  // mac_buf may contain intermediate derived key material.
  sli_psa_zeroize(input_buf, sizeof(input_buf));
  sli_psa_zeroize(mac_buf, sizeof(mac_buf));

  // On failure, wipe any partial output to prevent leaking derived key material.
  if (status != PSA_SUCCESS) {
    sli_psa_zeroize(derived_key->addr, derived_key->len);
  }

  return status;
}

#endif // defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)

// -----------------------------------------------------------------------------
// Public dispatch function for single-shot key derivation

psa_status_t sli_cryptoacc_driver_single_shot_key_derivation(
  psa_algorithm_t alg,
  const psa_key_attributes_t *key_in_attributes,
  const uint8_t *key_in_buffer,
  size_t key_in_buffer_size,
  const uint8_t* salt,
  size_t salt_length,
  const psa_key_attributes_t *key_out_attributes,
  uint32_t iterations,
  uint8_t *key_out_buffer,
  size_t key_out_buffer_size)
{
  if (key_in_buffer == NULL
      || key_in_attributes == NULL
      || salt == NULL
      || key_out_attributes == NULL
      || key_out_buffer == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  size_t key_out_size = PSA_BITS_TO_BYTES(psa_get_key_bits(key_out_attributes));
  psa_status_t psa_status = PSA_ERROR_NOT_SUPPORTED;

  if (key_out_buffer_size < key_out_size) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  if (iterations == 0 && !PSA_ALG_IS_SP800_108R1_CMAC(alg)) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  psa_key_lifetime_t lifetime = psa_get_key_lifetime(key_in_attributes);
  psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(lifetime);
  block_t key_block = NULL_blk;

  switch (location) {
    case PSA_KEY_LOCATION_LOCAL_STORAGE:
    {
#if defined(SLI_PSA_DRIVER_FEATURE_ECC)
      if (PSA_KEY_TYPE_IS_ECC(psa_get_key_type(key_in_attributes))) {
        return PSA_ERROR_NOT_SUPPORTED;
      }

#endif // SLI_PSA_DRIVER_FEATURE_ECC

      key_block = block_t_convert(key_in_buffer, key_in_buffer_size);
      break;
    }

#if defined(SLI_PSA_DRIVER_FEATURE_OPAQUE_KEYS)
    case PSA_KEY_LOCATION_SL_CRYPTOACC_OPAQUE:
    {
      if (key_in_buffer_size < sizeof(sli_cryptoacc_opaque_key_context_t)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
      }

      // The only opaque key that is currently supported is the PUF key
      sli_cryptoacc_opaque_key_context_t *key_context =
        (sli_cryptoacc_opaque_key_context_t *)key_in_buffer;
      if (key_context->builtin_key_id != 0) {
        switch (key_context->builtin_key_id) {
          case SLI_CRYPTOACC_BUILTIN_KEY_PUF_SLOT:
            // Using this key block as input will make the AES engine use the PUF-
            // derived key for the operation.
            // Make sure that the attributes and so on match our expectations
            if (psa_get_key_bits(key_in_attributes) != 256) {
              return PSA_ERROR_INVALID_ARGUMENT;
            }
            key_block = AES_KEY1_256;
            break;
          default:
            return PSA_ERROR_INVALID_ARGUMENT;
        }
      } else {
        return PSA_ERROR_NOT_SUPPORTED;
      }

      break;
    }
#endif // SLI_PSA_DRIVER_FEATURE_OPAQUE_KEYS

    default:
      return PSA_ERROR_DOES_NOT_EXIST;
  }

  switch (alg) {
#if defined(SLI_PSA_DRIVER_FEATURE_PBKDF2)
    case PSA_ALG_PBKDF2_AES_CMAC_PRF_128:
    {
      #define AES_CMAC_PRF_128_BLOCK_SIZE 128
      // The out key length can atmost be 128 bits long.
      if ( !key_out_size || (key_out_size > PSA_BITS_TO_BYTES(AES_CMAC_PRF_128_BLOCK_SIZE)) ) {
        return PSA_ERROR_INVALID_ARGUMENT;
      }

      block_t salt_block = block_t_convert(salt, salt_length);
      block_t key_out_block = block_t_convert(key_out_buffer, key_out_buffer_size);
      psa_status = derive_key_pbkdf2_aes_cmac_128_prf(&key_block, &salt_block, iterations, key_out_size, &key_out_block);
      break;
    }
#endif // SLI_PSA_DRIVER_FEATURE_PBKDF2

#if defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)
    case PSA_ALG_SP800_108R1_CMAC:
    {
      if (!key_out_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
      }

      // The salt parameter carries the Context (user secret || salt).
      // The label is selected automatically based on whether kdk is a PUF key.
      block_t key_out_block = block_t_convert(key_out_buffer, key_out_buffer_size);
      psa_status = derive_key_sp_800_108_r1_prf(&key_block,
                                                 salt, salt_length,
                                                 key_out_size,
                                                 &key_out_block);
      break;
    }
#endif // SLI_PSA_DRIVER_FEATURE_SP800_108R1

    default:
      psa_status = PSA_ERROR_NOT_SUPPORTED;
  }
  return psa_status;
}

#endif // defined(SLI_PSA_DRIVER_FEATURE_PBKDF2) || defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)
