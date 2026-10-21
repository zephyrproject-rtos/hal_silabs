/**
 * @file
 * @brief CPC utility macros.
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

#ifndef SLI_CPC_UTILS_H
#define SLI_CPC_UTILS_H

#include <assert.h>
#include <stdalign.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                                   Macros                                   */
/******************************************************************************/

/**
 * @brief Compile-time assert that a packed wire-format type is 1-byte aligned
 *        and exactly @p size bytes wide.
 */
#define SLI_CPC_STATIC_ASSERT_PACKED_SIZE(type, size)                                                  \
  static_assert(alignof(type) == 1 && sizeof(type) == size, #type " must be 1 byte aligned and " #size \
                                                                  " bytes in "                         \
                                                                  "size")

/**
 * @brief Poison a freshly freed buffer to catch use-after-free.
 *
 * Enabled when @c SLI_CPC_POISON_MEMORY_ENABLED is set to 1.
 */
#if defined(SLI_CPC_POISON_MEMORY_ENABLED) && SLI_CPC_POISON_MEMORY_ENABLED == 1
#define SLI_CPC_POISON_MEMORY(data, size) data ? memset(data, 0xA5, size) : (void)0;
#else
#define SLI_CPC_POISON_MEMORY(data, size) (void)0;
#endif

/**
 * @brief Poison, free and NULL-out a buffer of the given size.
 */
#define SLI_CPC_FREE_SIZE(data, size)  \
  do {                                 \
    SLI_CPC_POISON_MEMORY(data, size); \
    free(data);                        \
    data = NULL;                       \
  } while (0)

/**
 * @brief Poison, free and NULL-out a typed pointer (uses sizeof(*data)).
 */
#define SLI_CPC_FREE(data) SLI_CPC_FREE_SIZE(data, sizeof(*data))

/**
 * @brief Free a void * (or otherwise size-unknown) allocation; only poisons
 *        the first byte.
 */
#define SLI_CPC_FREE_VOID(data) SLI_CPC_FREE_SIZE(data, 1)

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_UTILS_H
