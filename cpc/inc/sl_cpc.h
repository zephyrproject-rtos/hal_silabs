/***************************************************************************/ /**
 * @file
 * @brief CPC public API.
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

#ifndef SL_CPC_H
#define SL_CPC_H

#include <stdbool.h>

#include "sl_component_catalog.h"
#include "sl_status.h"

#include "sl_cpc_buf.h"
#include "sl_cpc_bus.h"
#include "sl_cpc_ep.h"
#include "sl_cpc_frame.h"
#include "sl_cpc_msgq.h"
#include "sl_cpc_version.h"

#if defined(SL_CATALOG_POWER_MANAGER_PRESENT) || defined(DOXYGEN)
#include "sl_power_manager.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/ /**
 * @addtogroup cpc CPC
 * @{
 ******************************************************************************/

/***************************************************************************/ /**
 * Check if the system is ok to sleep.
 ******************************************************************************/
#if (!defined(SL_CATALOG_KERNEL_PRESENT) && defined(SL_CATALOG_POWER_MANAGER_PRESENT)) || defined(DOXYGEN)
bool sl_cpc_is_ok_to_sleep(void);
#endif

/***************************************************************************/ /**
 * Sleep on ISR exit.
 ******************************************************************************/
#if (!defined(SL_CATALOG_KERNEL_PRESENT) && defined(SL_CATALOG_POWER_MANAGER_PRESENT)) || defined(DOXYGEN)
sl_power_manager_on_isr_exit_t sl_cpc_sleep_on_isr_exit(void);
#endif

/** @} (end addtogroup cpc) */

#ifdef __cplusplus
}
#endif

#endif // SL_CPC_H
