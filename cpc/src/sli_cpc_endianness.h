/**
 * @file
 * @brief CPC endianness helpers.
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
 */

#ifndef SLI_CPC_ENDIANNESS_H
#define SLI_CPC_ENDIANNESS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Read a little-endian @c uint16_t from a byte buffer.
 */
static inline uint16_t sli_cpc_u16_from_le(const uint8_t *p)
{
  return (uint16_t)(((uint16_t)p[0]) | ((uint16_t)p[1] << 8));
}

/**
 * @brief Write a @c uint16_t in little-endian into a byte buffer.
 */
static inline void sli_cpc_u16_to_le(uint16_t x, uint8_t *p)
{
  p[0] = (uint8_t)(x >> 0);
  p[1] = (uint8_t)(x >> 8);
}

/**
 * @brief Read a little-endian @c uint32_t from a byte buffer.
 */
static inline uint32_t sli_cpc_u32_from_le(const uint8_t *p)
{
  return ((uint32_t)p[0]) | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

/**
 * @brief Write a @c uint32_t in little-endian into a byte buffer.
 */
static inline void sli_cpc_u32_to_le(uint32_t x, uint8_t *p)
{
  p[0] = (uint8_t)(x >> 0);
  p[1] = (uint8_t)(x >> 8);
  p[2] = (uint8_t)(x >> 16);
  p[3] = (uint8_t)(x >> 24);
}

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_ENDIANNESS_H
