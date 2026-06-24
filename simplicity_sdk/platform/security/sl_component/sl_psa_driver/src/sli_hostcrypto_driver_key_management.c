/***************************************************************************/ /**
 * @file
 * @brief PSA Driver common utility functions
 *******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
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

#include "sli_psa_driver_features.h"
#include "psa/crypto.h"
#if defined(SLI_MBEDTLS_DEVICE_HC)
#include "sli_hostcrypto_transparent_functions.h"
#include "sxsymcrypt/keyref.h"
#include "sl_psa_values.h"

psa_status_t sli_hostcrypto_load_key(struct sxkeyref *sx_key_ref,
                                     const psa_key_attributes_t *attributes,
                                     const uint8_t *key_buffer)
{
  if ((sx_key_ref == NULL) || (key_buffer == NULL)) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  psa_key_location_t location =
    PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

  if (location == PSA_KEY_LOCATION_LOCAL_STORAGE) {
    size_t key_bits = psa_get_key_bits(attributes);
    *sx_key_ref = sx_keyref_load_material(PSA_BITS_TO_BYTES(key_bits),
                                          (const char *)key_buffer);
    return PSA_SUCCESS;
#if defined(SLI_PSA_DRIVER_FEATURE_KSU)
  } else if (location == SL_PSA_KEY_LOCATION_KSU_0) {
    size_t key_index = (size_t) *key_buffer;
    *sx_key_ref = sx_keyref_load_by_id(key_index);
    return PSA_SUCCESS;
#endif // SLI_PSA_DRIVER_FEATURE_KSU
  } else {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
}
#endif