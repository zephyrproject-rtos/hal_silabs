/***************************************************************************//**
 * @file
 * @brief Clock Manager Private API definition.
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

#ifndef SLI_CLOCK_MANAGER_H
#define SLI_CLOCK_MANAGER_H

#include "sl_clock_manager.h"
#include "sl_status.h"
#include "sl_compiler.h"
#include "sl_code_classification.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * When this callback function is called, it means that HFXO is ready.
 ******************************************************************************/
__WEAK void sli_clock_manager_notify_hfxo_ready(void);

/***************************************************************************//**
 * Gets the HFXO's average startup time.
 *
 * @param[out] val  The HFXO's AVGSTUP value.
 *
 * @return  Status code.
 *          SL_STATUS_OK if successful.
 *          SL_STATUS_NOT_READY if measure is not done yet.
 *          SL_STATUS_NOT_SUPPORTED if not supported.
 *
 ******************************************************************************/
sl_status_t sli_clock_manager_get_hfxo_average_startup_time(uint32_t *val);

#ifdef __cplusplus
}
#endif

#endif // SLI_CLOCK_MANAGER_H
