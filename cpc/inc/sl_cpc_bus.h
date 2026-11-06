/***************************************************************************/ /**
 * @file
 * @brief CPC public bus API.
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

#ifndef SL_CPC_BUS_H
#define SL_CPC_BUS_H

#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>

#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"
#endif
#include "sl_cpc_config.h"
#include "sl_memory_manager.h"
#include "sl_slist.h"
#include "sl_status.h"

#if defined(SL_CPC_KERNEL_PRESENT)
#include "cmsis_os2.h"
#include "sl_cpc_kernel_config.h"
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
#include "sl_cmsis_os2_common.h"
#endif
#endif

#if defined(SL_CATALOG_CPC_NG_WAKE_PRESENT)
#include "sl_gpio.h"
#endif

#include "sl_cpc_ep.h"
#include "sli_cpc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/ /**
 * @addtogroup cpc CPC
 * @{
 ******************************************************************************/

/******************************************************************************/
/*                                   Types                                    */
/******************************************************************************/

typedef struct sli_cpc_drv_ops sli_cpc_drv_ops_t;
typedef struct sli_cpc_control_ops sli_cpc_control_ops_t;

/** @brief Bus control endpoint. */
typedef struct sli_cpc_control {
  sl_cpc_ep_t ep;
  const sli_cpc_control_ops_t *ops;
  uint16_t next_request_op_id;
  bool deinitializing;
  bool initialized;
  sl_cpc_buf_t rx_buf;
  alignas(SL_CPC_BUF_MIN_ALIGNMENT) uint8_t rx_data[64];
#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
  sli_cpc_control_primary_t primary;
#endif
} sli_cpc_control_t;

/** @brief Bus configuration. */
typedef struct sl_cpc_bus_config {
  bool is_secondary;
  uint16_t rx_frame_pool_count;
  uint16_t tx_frame_pool_count;
} sl_cpc_bus_config_t;

/**
 * @brief CPC bus.
 *
 * An instance for one physical link between a primary and secondary.
 */
typedef struct sl_cpc_bus {
  sl_memory_pool_t rx_frame_pool;
  sl_memory_pool_t tx_frame_pool;

  sl_slist_node_t *eps;
  sl_slist_node_t *closed_eps;

  uint32_t tx_inflight_frame_count;
  sli_cpc_frame_list_t transmit_queue;
  sli_cpc_frame_list_t transmit_completed_list;
  sli_cpc_frame_list_t write_complete_callback_list;
  sli_cpc_frame_list_t expired_retransmit_list;

  sli_cpc_dispatcher_handle_t callback_dispatcher_handle;
  sli_cpc_dispatcher_handle_t retransmit_dispatcher_handle;

  sli_cpc_dispatcher_context_t dispatcher;

#if defined(SL_CATALOG_CPC_NG_WAKE_PRESENT)
  sli_cpc_dispatcher_handle_t wake_dispatcher_handle;
  sl_gpio_t wake;
  int32_t wake_int_no;
  bool wake_active;
#endif

#if defined(SL_CPC_KERNEL_PRESENT)
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
  alignas(4) uint8_t transmit_queue_mutex_cb[osMutexCbSize];
  alignas(4) uint8_t eps_list_mutex_cb[osMutexCbSize];
  alignas(4) uint8_t event_signal_semaphore_cb[osSemaphoreCbSize];
  alignas(4) uint8_t thread_cb[osThreadCbSize];
  alignas(8) uint8_t thread_stack[(SL_CPC_TASK_STACK_SIZE * sizeof(void *)) & 0xFFFFFFF8u];
#endif

  osMutexId_t ep_list_lock;        ///< endpoints list lock
  osMutexId_t transmit_queue_lock; ///< transmit queue lock
  osSemaphoreId_t event_signal;    ///< event signal
  osThreadId_t thread_id;          ///< CPC thread
#else
  uint32_t rx_process_flag; ///< Pending RX process signals (bare-metal)
#endif

  const sli_cpc_drv_ops_t *drv_ops;

  sli_cpc_control_t ctrl;

#if (SL_CPC_DEBUG_CORE_EVENT_COUNTERS == 1)
  sli_cpc_bus_debug_t debug;
#endif

  bool initialized;

#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
  bool secondary_capabilities_mismatch;
  bool secondary_application_version_mismatch;
#endif // SL_CATALOG_CPC_NG_PRIMARY_PRESENT
} sl_cpc_bus_t;

/******************************************************************************/
/*                                    APIs                                    */
/******************************************************************************/

/***************************************************************************/ /**
 * Start a bus.
 *
 * Creates the control endpoint. Secondary buses wait for a peer connection;
 * primary buses connect and begin startup sequencing.
 *
 * @param[in] bus  Bus to start.
 *
 * @retval SL_STATUS_OK Bus started successfully.
 * @retval Other        An error occurred.
 ******************************************************************************/
sl_status_t sl_cpc_bus_start(sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Stop a bus.
 *
 * Tears down the control endpoint created by @ref sl_cpc_bus_start.
 *
 * @param[in] bus  Bus to stop.
 ******************************************************************************/
void sl_cpc_bus_stop(sl_cpc_bus_t *bus);

/** @} (end addtogroup cpc) */

#ifdef __cplusplus
}
#endif

#endif // SL_CPC_BUS_H
