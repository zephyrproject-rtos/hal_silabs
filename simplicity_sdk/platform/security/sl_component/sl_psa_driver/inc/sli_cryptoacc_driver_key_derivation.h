/***************************************************************************//**
 * @file
 * @brief Silicon Labs PSA Crypto key derivation functions for CRYPTOACC.
 *******************************************************************************
 * # License
 * <b>Copyright 2026 Silicon Laboratories Inc. www.silabs.com</b>
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
#ifndef SLI_CRYPTOACC_DRIVER_KEY_DERIVATION_H
#define SLI_CRYPTOACC_DRIVER_KEY_DERIVATION_H

/// @cond DO_NOT_INCLUDE_WITH_DOXYGEN

#include "sli_psa_driver_features.h"

#if defined(SLI_MBEDTLS_DEVICE_VSE)                              \
  && (defined(SLI_PSA_DRIVER_FEATURE_PBKDF2)                     \
      || defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1))

#include "psa/crypto_driver_common.h"

#ifdef __cplusplus
extern "C" {
#endif

psa_status_t sli_cryptoacc_driver_single_shot_key_derivation(
  psa_algorithm_t alg,
  const psa_key_attributes_t *key_in_attributes,
  const uint8_t *key_in_buffer,
  size_t key_in_buffer_size,
  const uint8_t *salt,
  size_t salt_length,
  const psa_key_attributes_t *key_out_attributes,
  uint32_t iterations,
  uint8_t *key_out_buffer,
  size_t key_out_buffer_size);

#ifdef __cplusplus
}
#endif

#endif // SLI_MBEDTLS_DEVICE_VSE && (SLI_PSA_DRIVER_FEATURE_PBKDF2 || SLI_PSA_DRIVER_FEATURE_SP800_108R1)

/// @endcond

#endif // SLI_CRYPTOACC_DRIVER_KEY_DERIVATION_H
