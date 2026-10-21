/***************************************************************************/ /**
 * @file
 * @brief CPC Bus implementation.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#include "sl_component_catalog.h"
#include "sl_status.h"

#include "sli_cpc_bus.h"
#include "sli_cpc_control.h"
#include "sli_cpc_debug.h"
#include "sli_cpc_frame_list.h"

#if defined(SL_CATALOG_CPC_NG_WAKE_PRESENT)
#include "sli_cpc_wake.h"
#endif

#if defined(SL_CATALOG_KERNEL_PRESENT)
static void cpc_task(void *arg)
{
  sl_cpc_bus_t *bus = (sl_cpc_bus_t *)arg;

  while (true) {
    osSemaphoreAcquire(bus->event_signal, osWaitForever);
    sli_cpc_bus_process_action(bus);
  }
}
#endif

/***************************************************************************/ /**
 * Allocate kernel-related resources for a CPC bus.
 *
 * @retval  SL_STATUS_OK    Resources allocated successfully.
 * @retval  Other sl_status_t if error occurred.
 ******************************************************************************/
static sl_status_t init_kernel(sl_cpc_bus_t *bus)
{
#if defined(SL_CATALOG_KERNEL_PRESENT)
  sl_status_t status = SL_STATUS_OK;

  const osMutexAttr_t ep_list_mutex_attr = {
    .attr_bits = osMutexRecursive,
    .name = "CPC Endpoints List Lock",
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
    .cb_mem = &bus->eps_list_mutex_cb[0],
    .cb_size = sizeof(bus->eps_list_mutex_cb),
#else
    .cb_mem = NULL,
    .cb_size = 0U,
#endif // SL_CATALOG_CMSIS_OS_COMMON_PRESENT
  };

  const osMutexAttr_t transmit_queue_mutex_attr = {
    .attr_bits = osMutexRecursive,
    .name = "CPC Transmit Queue Lock",
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
    .cb_mem = &bus->transmit_queue_mutex_cb[0],
    .cb_size = sizeof(bus->transmit_queue_mutex_cb),
#else
    .cb_mem = NULL,
    .cb_size = 0U,
#endif // SL_CATALOG_CMSIS_OS_COMMON_PRESENT
  };

  const osSemaphoreAttr_t event_signal_semaphore_attr = {
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
    .cb_mem = &bus->event_signal_semaphore_cb[0],
    .cb_size = sizeof(bus->event_signal_semaphore_cb),
#else
    .cb_mem = NULL,
    .cb_size = 0U,
#endif // SL_CATALOG_CMSIS_OS_COMMON_PRESENT
  };

  const osThreadAttr_t task_attr = {
    .name = "CPC Bus",
    .priority = SL_CPC_TASK_PRIORITY,
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
    .stack_mem = &bus->thread_stack[0],
    .stack_size = sizeof(bus->thread_stack),
    .cb_mem = &bus->thread_cb[0],
    .cb_size = sizeof(bus->thread_cb),
#else
    .stack_mem = NULL,
    .stack_size = 0U,
    .cb_mem = NULL,
    .cb_size = 0U,
#endif // SL_CATALOG_CMSIS_OS_COMMON_PRESENT
  };

  bus->ep_list_lock = osMutexNew(&ep_list_mutex_attr);
  if (bus->ep_list_lock == 0) {
    status = SL_STATUS_ALLOCATION_FAILED;
    goto exit;
  }

  bus->transmit_queue_lock = osMutexNew(&transmit_queue_mutex_attr);
  if (bus->transmit_queue_lock == 0) {
    status = SL_STATUS_ALLOCATION_FAILED;
    goto free_list_lock;
  }

  bus->event_signal = osSemaphoreNew(1, 0u, &event_signal_semaphore_attr);
  if (bus->event_signal == 0) {
    status = SL_STATUS_ALLOCATION_FAILED;
    goto free_transmit_queue_lock;
  }

  bus->thread_id = osThreadNew(&cpc_task, (void *)bus, &task_attr);
  if (bus->thread_id == NULL) {
    status = SL_STATUS_ALLOCATION_FAILED;
    goto free_event_signal;
  }

  goto exit;

free_event_signal:
  osSemaphoreDelete(bus->event_signal);

free_transmit_queue_lock:
  osMutexDelete(bus->transmit_queue_lock);

free_list_lock:
  osMutexDelete(bus->ep_list_lock);

exit:
  return status;
#else
  (void)bus;

  return SL_STATUS_OK;
#endif // SL_CATALOG_KERNEL_PRESENT
}

/***************************************************************************/ /**
 * Free kernel-related resources for a CPC bus.
 ******************************************************************************/
static void deinit_kernel(const sl_cpc_bus_t *bus)
{
#if defined(SL_CATALOG_KERNEL_PRESENT)
  osThreadTerminate(bus->thread_id);
  osSemaphoreDelete(bus->event_signal);
  osMutexDelete(bus->transmit_queue_lock);
  osMutexDelete(bus->ep_list_lock);
#else
  (void)bus;
#endif // SL_CATALOG_KERNEL_PRESENT
}

/***************************************************************************/ /**
 * Acquire / release the wake source the bus needs to receive bus traffic.
 * When the CPC wake component is present we hand off to it; otherwise we hold
 * an EM1 requirement so the device doesn't drop into deep sleep.
 ******************************************************************************/
#if defined(SL_CATALOG_CPC_NG_WAKE_PRESENT)
static sl_status_t init_wake(sl_cpc_bus_t *bus)
{
  return sli_cpc_wake_init(bus);
}

static void deinit_wake(sl_cpc_bus_t *bus)
{
  sli_cpc_wake_deinit(bus);
}
#else
static sl_status_t init_wake(const sl_cpc_bus_t *bus)
{
  (void)bus;

  sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

  return SL_STATUS_OK;
}

static void deinit_wake(const sl_cpc_bus_t *bus)
{
  (void)bus;

  sl_power_manager_remove_em_requirement(SL_POWER_MANAGER_EM1);
}
#endif

/***************************************************************************/ /**
 * Early init allocation, set up software variables and enable driver's hardware.
 ******************************************************************************/
static sl_status_t init_early(sl_cpc_bus_t *bus, const sl_cpc_bus_config_t *cfg)
{
  sl_status_t status;

  SLI_CPC_DEBUG_CORE_INIT(bus);

  // Initialize per-bus frame memory pools
  status = sli_cpc_frame_mempool_init(bus, cfg->rx_frame_pool_count, cfg->tx_frame_pool_count);
  if (status != SL_STATUS_OK) {
    return status;
  }

  // Prepare endpoint lists
  sl_slist_init(&bus->eps);
  sl_slist_init(&bus->closed_eps);

  // Prepare dispatcher list
  sl_slist_init(&bus->dispatcher.process_queue);
  sl_slist_init(&bus->dispatcher.pre_process_queue);

  // Prepare frame lists
  bus->tx_inflight_frame_count = 0;
  sli_cpc_frame_list_init(&bus->transmit_queue);
  sli_cpc_frame_list_init(&bus->transmit_completed_list);
  sli_cpc_frame_list_init(&bus->write_complete_callback_list);
  sli_cpc_frame_list_init(&bus->expired_retransmit_list);

  bus->dispatcher.post_process_event_counter = 0;
  bus->dispatcher.pre_process_event_counter = 0;

  sli_cpc_dispatcher_init_handle(&bus->callback_dispatcher_handle, bus);
  sli_cpc_dispatcher_init_handle(&bus->retransmit_dispatcher_handle, bus);

  status = init_wake(bus);
  if (status != SL_STATUS_OK) {
    goto deinit_mempool;
  }

  return SL_STATUS_OK;

deinit_mempool:
  sli_cpc_frame_mempool_deinit(bus);

  return status;
}

/***************************************************************************/ /**
 * Free resource reserved in init_early().
 ******************************************************************************/
static void deinit_early(sl_cpc_bus_t *bus)
{
  // drivers don't implement a hw_deinit operation, so skip that.

  sli_cpc_dispatcher_cancel(&bus->callback_dispatcher_handle);
  sli_cpc_dispatcher_cancel(&bus->retransmit_dispatcher_handle);

  deinit_wake(bus);

  // lists don't have a deinit function

  sli_cpc_frame_mempool_deinit(bus);
}

/***************************************************************************/ /**
 * Late initialization, finish initializing the driver and the system EP.
 ******************************************************************************/
static sl_status_t init_late(sl_cpc_bus_t *bus)
{
  return bus->drv_ops->init(bus);
}

/***************************************************************************/ /**
 * Free resource reserved in init_late().
 ******************************************************************************/
static void deinit_late(sl_cpc_bus_t *bus)
{
  // system endpoint doesn't have a deinit function
#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
  if (bus->drv_ops->deinit) {
    bus->drv_ops->deinit(bus);
  }
#else
  (void)bus;
#endif
}

/***************************************************************************/ /**
 * Initialize an bus.
 ******************************************************************************/
sl_status_t sli_cpc_bus_init(sl_cpc_bus_t *bus, const sl_cpc_bus_config_t *cfg, const sli_cpc_drv_ops_t *drv_ops)
{
  sl_status_t status;

  SLI_CPC_ASSERT(bus != NULL);
  SLI_CPC_ASSERT(cfg != NULL);
  SLI_CPC_ASSERT(drv_ops != NULL);

  memset(bus, 0, sizeof(*bus));

  if (cfg->is_secondary) {
#if defined(SL_CATALOG_CPC_NG_SECONDARY_PRESENT)
    bus->ctrl.ops = &sli_cpc_control_secondary_ops;
#else
    return SL_STATUS_NOT_SUPPORTED;
#endif
  } else {
#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
    bus->ctrl.ops = &sli_cpc_control_primary_ops;
#else
    return SL_STATUS_NOT_SUPPORTED;
#endif
  }

  bus->drv_ops = drv_ops;

  status = init_kernel(bus);
  if (status != SL_STATUS_OK) {
    goto exit;
  }

  status = init_early(bus, cfg);
  if (status != SL_STATUS_OK) {
    goto kernel_deinit;
  }

  status = init_late(bus);
  if (status != SL_STATUS_OK) {
    goto early_deinit;
  }

  return SL_STATUS_OK;

early_deinit:
  deinit_early(bus);
kernel_deinit:
  deinit_kernel(bus);

exit:
  return status;
}

/***************************************************************************/ /**
 * Deinitialize an bus.
 ******************************************************************************/
void sli_cpc_bus_deinit(sl_cpc_bus_t *bus)
{
  deinit_late(bus);
  deinit_early(bus);
  deinit_kernel(bus);
}

/***************************************************************************/ /**
 * Start bus.
 ******************************************************************************/
sl_status_t sl_cpc_bus_start(sl_cpc_bus_t *bus)
{
  sl_status_t status;

  SLI_CPC_ASSERT(bus);
  SLI_CPC_ASSERT(bus->ctrl.ops);

  status = bus->drv_ops->start_rx(bus);
  if (status != SL_STATUS_OK) {
    return status;
  }

  return bus->ctrl.ops->init(&bus->ctrl, bus);
}

/***************************************************************************/ /**
 * Endpoint list sorting function
 ******************************************************************************/
static bool sort_eps(sl_slist_node_t *item_l, sl_slist_node_t *item_r)
{
  const sl_cpc_ep_t *ep_left = SL_SLIST_ENTRY(item_l, sl_cpc_ep_t, node);
  const sl_cpc_ep_t *ep_right = SL_SLIST_ENTRY(item_r, sl_cpc_ep_t, node);

  return ep_left->id < ep_right->id;
}

/***************************************************************************/ /**
 * Check if endpoint ID is already in use for specified bus.
 ******************************************************************************/
sl_cpc_ep_t *sli_cpc_bus_find_ep_from_id(const sl_cpc_bus_t *bus, uint16_t id)
{
  sl_cpc_ep_t *ep;

  SL_SLIST_FOR_EACH_ENTRY(bus->eps, ep, sl_cpc_ep_t, node)
  {
    if (ep->id == id) {
      return ep;
    }
  }

  return NULL;
}

/***************************************************************************/ /**
 * Add endpoint to active endpoints list
 ******************************************************************************/
void sli_cpc_bus_add_ep(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep)
{
  sl_slist_push(&bus->eps, &ep->node);
  sl_slist_sort(&bus->eps, sort_eps);
}

/***************************************************************************/ /**
 * Remove endpoint from active endpoints list
 ******************************************************************************/
void sli_cpc_bus_remove_ep(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep)
{
  sl_slist_remove(&bus->eps, &ep->node);
}
