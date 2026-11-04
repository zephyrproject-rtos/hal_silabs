/**
 * @file sli_cpc_atomic.h
 * @brief CPC Atomic Primitives
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SLI_CPC_ATOMIC_H
#define SLI_CPC_ATOMIC_H

#include "cpc_atomic.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Ports are expected to provide a "cpc_atomic.h"
 * header that defines following primitives:
 *
 * Storage Primitives:
 *   - MCU_ATOMIC_STORE
 *   - MCU_ATOMIC_LOAD
 *
 * Critical Section Primitives:
 *   - MCU_DECLARE_IRQ_STATE
 *   - MCU_ENTER_CRITICAL
 *   - MCU_EXIT_CRITICAL
 *
 * Atomic Section Primitives:
 *   - MCU_ENTER_ATOMIC
 *   - MCU_EXIT_ATOMIC
 */

#ifndef MCU_CRITICAL_SECTION
#define MCU_CRITICAL_SECTION(yourcode) \
  {                                    \
    MCU_DECLARE_IRQ_STATE;             \
    MCU_ENTER_CRITICAL();              \
    {yourcode} MCU_EXIT_CRITICAL();    \
  }
#endif

#ifndef MCU_ATOMIC_SECTION
#define MCU_ATOMIC_SECTION(yourcode) \
  {                                  \
    MCU_DECLARE_IRQ_STATE;           \
    MCU_ENTER_ATOMIC();              \
    {yourcode} MCU_EXIT_ATOMIC();    \
  }
#endif

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_ATOMIC_H
