/***************************************************************************/ /**
 * @file
 * @brief CPC Internal Definitions
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

#ifndef SLI_CPC_H
#define SLI_CPC_H

#include <stdarg.h>
#include <stddef.h>

#include "sl_common.h"
#include "sl_compiler.h"
#include "sl_component_catalog.h"
#include "sl_cpc_config.h"
#include "sl_slist.h"
#include "sl_status.h"

#include "sl_cpc.h"
#include "sli_cpc_frame_list.h"
#include "sli_cpc_hdr.h"
#include "sli_cpc_timer.h"

#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "cmsis_os2.h"
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
#include "sl_cmsis_os2_common.h"
#endif
#endif

#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
#include "sl_power_manager.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/ /**
 * @addtogroup cpc CPC
 * @{
 ******************************************************************************/

/******************************************************************************/
/*                                  Defines                                   */
/******************************************************************************/

#define SLI_CPC_INIT_WINDOW_PROBE_TIMEOUT_MS 100
#define SLI_CPC_RE_TRANSMIT 10
#define SLI_CPC_WINDOW_PROBE_MAX 10

/******************************************************************************/
/*                                   Enums                                    */
/******************************************************************************/

typedef enum sli_cpc_signal_type {
  SLI_CPC_SIGNAL_RX,
  SLI_CPC_SIGNAL_TX,
  SLI_CPC_SIGNAL_CLOSED,
  SLI_CPC_SIGNAL_SYSTEM,
} sli_cpc_signal_type_t;

/******************************************************************************/
/*                                    APIs                                    */
/******************************************************************************/

/***************************************************************************/ /**
 * Send a standalone ACK on an endpoint (no payload, no ACK request).
 *
 * @param[in] ep  Endpoint that sends the ACK.
 *
 * @retval SL_STATUS_OK  ACK queued for transmission.
 * @retval Other         Allocation or internal error.
 ******************************************************************************/
sl_status_t sli_cpc_ep_send_ack(sl_cpc_ep_t *ep);

/***************************************************************************/ /**
 * Run the process loop for the specified bus.
 *
 * @param[in] bus  Bus to process.
 ******************************************************************************/
void sli_cpc_bus_process_action(sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Transmit a RESET frame for the given endpoint address.
 *
 * @param[in] bus     Bus that transmits the RESET frame.
 * @param[in] address Endpoint address to reset.
 ******************************************************************************/
void sli_cpc_send_reset_frame(sl_cpc_bus_t *bus, uint16_t address);

/** @} (end addtogroup cpc) */

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_H
