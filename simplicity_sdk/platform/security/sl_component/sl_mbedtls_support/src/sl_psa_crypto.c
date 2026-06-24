/***************************************************************************//**
 * @file
 * @brief Silicon Labs PSA Crypto utility functions.
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

#include "sl_psa_crypto.h"

#include "sli_psa_driver_features.h"

// -----------------------------------------------------------------------------
// Global functions

void sl_psa_set_key_lifetime_with_location_preference(
  psa_key_attributes_t *attributes,
  psa_key_persistence_t persistence,
  psa_key_location_t preferred_location)
{
  psa_key_location_t selected_location = PSA_KEY_LOCATION_LOCAL_STORAGE;

  switch (preferred_location) {
    // The underlying values for wrapped and built-in keys are the same. In
    // order to avoid compiler errors, we therefore use #elif in order to make
    // sure that we do not get identical switch labels.
    #if defined(SLI_PSA_DRIVER_FEATURE_WRAPPED_KEYS)
    case SL_PSA_KEY_LOCATION_WRAPPED:
      selected_location = SL_PSA_KEY_LOCATION_WRAPPED;
      break;
    #elif defined(SLI_PSA_DRIVER_FEATURE_BUILTIN_KEYS)
    case SL_PSA_KEY_LOCATION_BUILTIN:
      selected_location = SL_PSA_KEY_LOCATION_BUILTIN;
      break;
    #elif defined(SLI_PSA_DRIVER_FEATURE_KSU)
    case SL_PSA_KEY_LOCATION_KSU_0:
      selected_location = SL_PSA_KEY_LOCATION_KSU_0;
      break;
    #endif

    default:
      // Use the already set PSA_KEY_LOCATION_LOCAL_STORAGE.
      break;
  }

  psa_key_lifetime_t lifetime =
    PSA_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(persistence,
                                                   selected_location);
  psa_set_key_lifetime(attributes, lifetime);
}

psa_key_location_t sl_psa_get_most_secure_key_location(void)
{
  #if defined(SLI_PSA_DRIVER_FEATURE_WRAPPED_KEYS)
  return SL_PSA_KEY_LOCATION_WRAPPED;
  #else
  return PSA_KEY_LOCATION_LOCAL_STORAGE;
  #endif
}

// -----------------------------------------------------------------------------
// Single-shot key derivation (migrated from psa_crypto.c)
//
// The full implementation is compiled only when PSA crypto drivers are present
// and this is not a TrustZone non-secure build.  NS builds get this function
// body from the TFM NS interface (tfm_crypto_func_api.c), which marshals the
// call through the NSC veneer to the secure side.

#if defined(MBEDTLS_PSA_CRYPTO_DRIVERS) && !defined(SL_TRUSTZONE_NONSECURE)

#include "sl_psa_values.h"
#include "psa_crypto_core.h"
#include "psa_crypto_slot_management.h"
#include "psa_crypto_driver_wrappers_no_static.h"

#if defined(SLI_MBEDTLS_DEVICE_HSE)
#include "sli_se_driver_key_derivation.h"
#endif

#if defined(SLI_MBEDTLS_DEVICE_VSE)                              \
  && (defined(SLI_PSA_DRIVER_FEATURE_PBKDF2)                     \
      || defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1))
#include "sli_cryptoacc_driver_key_derivation.h"
#endif

psa_status_t sl_psa_key_derivation_single_shot(
  psa_algorithm_t alg,
  mbedtls_svc_key_id_t key_in,
  const uint8_t *info,
  size_t info_length,
  const uint8_t *salt,
  size_t salt_length,
  size_t iterations,
  const psa_key_attributes_t *key_out_attributes,
  mbedtls_svc_key_id_t *key_out)
{
  psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
  psa_status_t unlock_status = PSA_ERROR_CORRUPTION_DETECTED;
  psa_key_slot_t *input_key_slot = NULL;
  psa_key_slot_t *output_key_slot = NULL;
  psa_se_drv_table_entry_t *driver = NULL;
  *key_out = MBEDTLS_SVC_KEY_ID_INIT;
  size_t storage_size = 0;

  if (psa_get_key_bits(key_out_attributes) == 0) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  status = psa_get_and_lock_key_slot_with_policy(
    key_in, &input_key_slot, PSA_KEY_USAGE_DERIVE, alg);
  if (status != PSA_SUCCESS) {
    return status;
  }

  status = psa_start_key_creation(PSA_KEY_CREATION_DERIVE, key_out_attributes,
                                  &output_key_slot, &driver);
  if (status != PSA_SUCCESS) {
    goto exit;
  }

  status = psa_driver_wrapper_get_key_buffer_size(key_out_attributes, &storage_size);
  if (status != PSA_SUCCESS) {
    goto exit;
  }

  if (output_key_slot->key.data == NULL) {
    status = psa_allocate_buffer_to_slot(output_key_slot, storage_size);
    if (status != PSA_SUCCESS) {
      goto exit;
    }
  }

  {
    if (PSA_ALG_IS_HKDF(alg))
#if defined(SLI_PSA_DRIVER_FEATURE_HKDF)
    {
      status = sli_se_driver_single_shot_hkdf(
        alg, &input_key_slot->attr, input_key_slot->key.data,
        input_key_slot->key.bytes, info, info_length, salt, salt_length,
        &output_key_slot->attr, output_key_slot->key.data,
        output_key_slot->key.bytes);
    }
#else /* SLI_PSA_DRIVER_FEATURE_HKDF */
    {
      (void)info;
      (void)info_length;
      (void)salt;
      (void)salt_length;

      status = PSA_ERROR_NOT_SUPPORTED;
    }
#endif /* SLI_PSA_DRIVER_FEATURE_HKDF */
    else if (PSA_ALG_IS_PBKDF2_HMAC(alg)
             || (alg == PSA_ALG_PBKDF2_AES_CMAC_PRF_128)
#if defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)
             || (alg == PSA_ALG_SP800_108R1_CMAC)
#endif
             )
#if defined(SLI_PSA_DRIVER_FEATURE_PBKDF2) || defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)
#if defined(SLI_MBEDTLS_DEVICE_VSE)
    {
      if ((alg == PSA_ALG_PBKDF2_AES_CMAC_PRF_128)
#if defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)
          || (alg == PSA_ALG_SP800_108R1_CMAC)
#endif
          ) {
        status = sli_cryptoacc_driver_single_shot_key_derivation(
          alg, &input_key_slot->attr, input_key_slot->key.data,
          input_key_slot->key.bytes, salt, salt_length,
          &output_key_slot->attr, iterations, output_key_slot->key.data,
          output_key_slot->key.bytes);
      } else {
        (void)salt;
        (void)salt_length;
        (void)iterations;

        status = PSA_ERROR_NOT_SUPPORTED;
      }
    }
#else /* !SLI_MBEDTLS_DEVICE_VSE */
    {
#if defined(SLI_PSA_DRIVER_FEATURE_SP800_108R1)
      if (PSA_ALG_IS_SP800_108R1_CMAC(alg)) {
        status = PSA_ERROR_NOT_SUPPORTED;
      } else
#endif
      {
        status = sli_se_driver_single_shot_pbkdf2(
          alg, &input_key_slot->attr, input_key_slot->key.data,
          input_key_slot->key.bytes, salt, salt_length,
          &output_key_slot->attr, iterations, output_key_slot->key.data,
          output_key_slot->key.bytes);
      }
    }
#endif /* SLI_MBEDTLS_DEVICE_VSE */
#else /* !SLI_PSA_DRIVER_FEATURE_PBKDF2 && !SLI_PSA_DRIVER_FEATURE_SP800_108R1 */
    {
      (void)salt;
      (void)salt_length;
      (void)iterations;

      status = PSA_ERROR_NOT_SUPPORTED;
    }
#endif /* !SLI_PSA_DRIVER_FEATURE_PBKDF2 && !SLI_PSA_DRIVER_FEATURE_SP800_108R1 */
    else {
      status = PSA_ERROR_NOT_SUPPORTED;
    }
  }

  exit:

  if (status == PSA_SUCCESS) {
    status = psa_finish_key_creation(output_key_slot, driver, key_out);
  }
  if (status != PSA_SUCCESS) {
    psa_fail_key_creation(output_key_slot, driver);
  }

  unlock_status = psa_unregister_read(input_key_slot);

  return (status == PSA_SUCCESS) ? unlock_status : status;
}

#endif /* MBEDTLS_PSA_CRYPTO_DRIVERS && !SL_TRUSTZONE_NONSECURE */
