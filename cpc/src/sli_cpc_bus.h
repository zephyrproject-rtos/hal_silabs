/***************************************************************************/ /**
 * @file
 * @brief CPC Bus Internal Definitions
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

#ifndef SLI_CPC_BUS_H
#define SLI_CPC_BUS_H

#include "sl_component_catalog.h"
#include "sl_cpc_kernel_config.h"
#include "sl_memory_manager.h"
#include "sl_slist.h"
#include "sli_cpc.h"
#include "sli_cpc_atomic.h"
#include "sli_cpc_dispatcher.h"
#include "sli_cpc_drv.h"
#include "sli_cpc_frame_list.h"
#include "sli_cpc_memory.h"
#include "sli_cpc_types.h"

#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "cmsis_os2.h"
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
#include "sl_cmsis_os2_common.h"
#endif
#endif

#if defined(SL_CATALOG_CPC_NG_WAKE_PRESENT)
#include "sl_gpio.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT) && !defined(SL_CATALOG_CPC_NG_SECONDARY_PRESENT)
#error "CPC requires cpc_primary and/or cpc_secondary"
#endif

/***************************************************************************/ /**
 * Initialize a CPC bus.
 *
 * @param[in] bus      CPC bus pointer.
 * @param[in] cfg      Bus configuration. Must not be NULL.
 * @param[in] drv_ops  Driver operations for this bus. Must not be NULL.
 *
 * @retval  SL_STATUS_OK    Initialized endpoint successfully.
 * @retval  Other sl_status_t if error occurred.
 ******************************************************************************/
sl_status_t sli_cpc_bus_init(sl_cpc_bus_t *bus, const sl_cpc_bus_config_t *cfg, const sli_cpc_drv_ops_t *drv_ops);

/***************************************************************************/ /**
 * Deinitialize a CPC bus.
 *
 * @param[in] bus      CPC bus pointer.
 ******************************************************************************/
void sli_cpc_bus_deinit(sl_cpc_bus_t *bus);

/******************************************************************************/
/*                          Driver to core interface                          */
/******************************************************************************/

/***************************************************************************/ /**
 * Signal process needed.
 ******************************************************************************/
void sli_cpc_bus_signal_event(sl_cpc_bus_t *bus, sli_cpc_signal_type_t signal_type);

/***************************************************************************/ /**
 * Notifies core of rx completion.
 ******************************************************************************/
void sli_cpc_bus_notify_rx_data_from_drv(sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Returns an endpoint pointer from the specified id.
 *
 * @param[in] ep_id Endpoint ID number to return.
 * @param[in] bus CPC bus where to search.
 *
 * @retval Pointer to an endpoint, NULL if the endpoint is not allocated.
 ******************************************************************************/
sl_cpc_ep_t *sli_cpc_bus_find_ep_from_id(const sl_cpc_bus_t *bus, uint16_t ep_id);

/***************************************************************************/ /**
 * Add endpoint to active endpoint list. After this call, drivers might start
 * receiving frames from this endpoint.
 *
 * @param[in] bus CPC bus to operate on.
 * @param[in] ep   Endpoint to add.
 ******************************************************************************/
void sli_cpc_bus_add_ep(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep);

/***************************************************************************/ /**
 * Remove endpoint from active endpoint list. After this call, drivers will no
 * longer be able to receive payloads for this endpoint, but they will still
 * receive the header part of these frames. Note that might stil have frames
 * with payloads in their internal queues.
 *
 * @param[in] bus CPC bus to operate on.
 * @param[in] ep   Endpoint to remove.
 ******************************************************************************/
void sli_cpc_bus_remove_ep(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep);

/***************************************************************************/ /**
 * Mark the bus initialized and complete any deferred listen/connect requests.
 *
 * @param[in] bus Bus that is now initialized.
 ******************************************************************************/
void sli_cpc_bus_notify_initialized(sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Terminate every endpoint on the bus.
 *
 * @param[in] bus Bus whose user endpoints should be terminated.
 ******************************************************************************/
void sli_cpc_bus_terminate_endpoints(sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Notifies core of tx completion by the driver.
 *
 * @param bus     Pointer to the CPC bus to notify.
 * @param frames   Pointer to the list of frames that have been transmitted.
 ******************************************************************************/
static inline void sli_cpc_bus_notify_tx_data_by_drv(sl_cpc_bus_t *bus, sli_cpc_frame_list_t *frames)
{
  SLI_CPC_ASSERT(bus != NULL && frames != NULL);

  MCU_ATOMIC_SECTION(sli_cpc_frame_list_extend(&bus->transmit_completed_list, frames);)

  sli_cpc_bus_signal_event(bus, SLI_CPC_SIGNAL_TX);
}

#ifdef __cplusplus
}
#endif

#endif /* SLI_CPC_BUS_H */
