/***************************************************************************/ /**
 * @file
 * @brief CPC frame allocation and pool management.
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

#include <assert.h> /* static_assert() */
#include <stddef.h> /* offsetof() */
#include <stdlib.h>
#include <string.h>

#include "sl_component_catalog.h"
#include "sl_memory_manager.h"
#include "sl_status.h"

#include "sli_cpc_assert.h"
#include "sli_cpc_bus.h"
#include "sli_cpc_ep.h"
#include "sli_cpc_frame.h"
#include "sli_cpc_log.h"

static_assert((offsetof(sl_cpc_frame_t, hdr) % SL_CPC_BUF_MIN_ALIGNMENT) == 0U,
              "CPC frame header must be aligned for ADMA");

sl_status_t sli_cpc_frame_mempool_init(sl_cpc_bus_t *bus, uint16_t rx_frame_pool_count, uint16_t tx_frame_pool_count)
{
  sl_status_t status;

  if (rx_frame_pool_count == 0 || tx_frame_pool_count == 0) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  status = sl_memory_create_pool(sizeof(sl_cpc_frame_t), rx_frame_pool_count, &bus->rx_frame_pool);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("RX frame pool create failed, status=0x%lx", (unsigned long)status);
    return status;
  }

  status = sl_memory_create_pool(sizeof(sl_cpc_frame_t), tx_frame_pool_count, &bus->tx_frame_pool);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("TX frame pool create failed, status=0x%lx", (unsigned long)status);
    goto cleanup_rx_pool;
  }

  return SL_STATUS_OK;

cleanup_rx_pool:
  (void)sl_memory_delete_pool(&bus->rx_frame_pool);
  return status;
}

void sli_cpc_frame_mempool_deinit(sl_cpc_bus_t *bus)
{
  sl_status_t status;

  status = sl_memory_delete_pool(&bus->rx_frame_pool);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("RX frame pool delete failed, status=0x%lx", (unsigned long)status);
  }

  status = sl_memory_delete_pool(&bus->tx_frame_pool);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("TX frame pool delete failed, status=0x%lx", (unsigned long)status);
  }
}

static void endpoint_owned_frame_destructor(sl_cpc_frame_t *frame)
{
  sl_cpc_ep_t *ep = frame->ep;

  sli_cpc_frame_free(frame);

  if (ep) {
    sli_cpc_ep_put_ref(ep);
  }
}

sl_cpc_frame_t *sli_cpc_frame_new(sl_cpc_bus_t *bus, bool is_rx)
{
  sl_memory_pool_t *pool;
  sl_cpc_frame_t *frame;
  sl_status_t status;

  pool = is_rx ? &bus->rx_frame_pool : &bus->tx_frame_pool;

  status = sl_memory_pool_alloc(pool, (void **)&frame);
  if (status != SL_STATUS_OK || !frame) {
    return NULL;
  }

  sli_cpc_frame_init(frame);

  frame->bus = bus;
  frame->is_rx = is_rx;
  frame->destructor = endpoint_owned_frame_destructor;

  return frame;
}

void sli_cpc_frame_free(sl_cpc_frame_t *frame)
{
  sl_cpc_bus_t *bus;
  sl_memory_pool_t *pool;
  sl_status_t status;
  bool is_rx;

  if (!frame) {
    return;
  }

  SLI_CPC_ASSERT(frame->bus_node.node == NULL);
  SLI_CPC_ASSERT(frame->ep_node.node == NULL);

  bus = frame->bus;
  is_rx = frame->is_rx;

  pool = is_rx ? &bus->rx_frame_pool : &bus->tx_frame_pool;

  status = sl_memory_pool_free(pool, frame);
  if (status != SL_STATUS_OK) {
    SLI_CPC_PANIC("Failed to free frame back to pool, status=0x%lx", (unsigned long)status);
  }

  if (is_rx && bus->drv_ops->on_rx_frame_free != NULL) {
    bus->drv_ops->on_rx_frame_free(bus);
  }
}
