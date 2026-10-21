/***************************************************************************/ /**
 * @file
 * @brief CPC API implementation.
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

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "sl_common.h"
#include "sl_component_catalog.h"
#include "sl_slist.h"
#include "sl_status.h"

#include "sl_cpc_config.h"

#include "sli_cpc.h"
#include "sli_cpc_assert.h"
#include "sli_cpc_atomic.h"
#include "sli_cpc_debug.h"
#include "sli_cpc_drv.h"
#include "sli_cpc_ep.h"
#include "sli_cpc_frame.h"
#include "sli_cpc_hdr.h"
#include "sli_cpc_memory.h"

#include "sl_cpc_buf.h"
#include "sl_cpc_msgq.h"

#include "sl_memory_manager.h"

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************/ /**
 * Get a CPC command frame. Command frames don't have a CPC frame passed by
 * the core, so we need to allocate a new one to be able to send over the bus.
 ******************************************************************************/
sl_status_t sli_cpc_get_write_command_frame(sl_cpc_bus_t *bus, sl_cpc_frame_t **frame_ptr)
{
  *frame_ptr = sli_cpc_frame_new(bus, false);
  if (*frame_ptr == NULL) {
    return SL_STATUS_NO_MORE_RESOURCE;
  }

  return SL_STATUS_OK;
}

/***************************************************************************/ /**
 * Create a buffer chain of `total_len` using buffers from `msgq`.
 ******************************************************************************/
sl_cpc_buf_t *sli_cpc_buffer_chain_alloc(sl_cpc_msgq_t *msgq, uint16_t total_len)
{
  sl_cpc_buf_t *head = NULL;
  sl_cpc_buf_t *tail = NULL;
  uint16_t buf_len = 0;
  bool popped;

  SLI_CPC_ASSERT(msgq);

  if (total_len == 0)
    return NULL;

  do {
    popped = sl_cpc_msgq_pop(msgq, &tail);
    if (!popped) {
      goto cancel;
    }

    // Implementation assumes pop returns a single buffer, not a buffer chain.
    // Validate that to prevent false assumption from returning an invalid chain.
    SLI_CPC_ASSERT(tail->node.node == NULL);

    // First iteration, save the head and the size of each buffer
    if (!head) {
      head = tail;
      buf_len = head->tot_len;
    }

    // Trim the tail length if it's the last element
    if (total_len < buf_len) {
      tail->len = total_len;

      // single buffer chain, need to update head's tot_len as well
      if (head == tail) {
        head->tot_len = total_len;
      }
    }

    // Chain the new tail, it's important to update tail->len first so that
    // head->tot_len (and its following nodes) have the correct value
    if (head != tail) {
      sl_cpc_buf_chain(head, tail);
    }

    total_len -= tail->len;
  } while (total_len);

  return head;

cancel:
  sli_cpc_buffer_chain_release(msgq, head, buf_len);

  return NULL;
}

/***************************************************************************/ /**
 * Release a buffer chain back to a message queue.
 ******************************************************************************/
void sli_cpc_buffer_chain_release(sl_cpc_msgq_t *msgq, sl_cpc_buf_t *buf, uint16_t reset_len)
{
  sl_cpc_buf_t *next;

  SLI_CPC_ASSERT(msgq);

  while (buf != NULL) {
    next = buf->node.node ? SL_SLIST_ENTRY(buf->node.node, sl_cpc_buf_t, node) : NULL;

    buf->node.node = NULL;
    buf->len = reset_len;
    buf->tot_len = reset_len;

    sl_cpc_msgq_push(msgq, buf);
    buf = next;
  }
}

/***************************************************************************/ /**
 * Allocate a reception payload based on the header received from the bus.
 ******************************************************************************/
sl_status_t sli_cpc_alloc_rx_payload(const sl_cpc_bus_t *bus, sl_cpc_frame_t *frame)
{
  const sli_cpc_hdr_t *hdr = sli_cpc_frame_get_header(frame);
  const uint16_t addr = sli_cpc_header_get_address(hdr);
  const uint16_t payload_length = sli_cpc_header_get_payload_size(hdr);
  sl_status_t status = SL_STATUS_OK;
  sl_cpc_buf_t *buf;

  frame->ep = sli_cpc_ep_get_ref(sli_cpc_bus_find_ep_from_id(bus, addr));

  if (!frame->ep) {
    SLI_CPC_LOG_DEBUG("Received frame for an unallocated endpoint. Endpoint ID: %d", addr);
    status = SL_STATUS_NOT_INITIALIZED;
    goto exit;
  }

  if (payload_length == 0) {
    // Command frame (e.g. RST, ACK), no payload to allocate.
    goto exit;
  }

  buf = sli_cpc_buffer_chain_alloc(&frame->ep->rx_buffer_queue, payload_length);
  if (!buf) {
    // Endpoint is out of RX buffers. Driver will drop the payload and return the
    // empty context to the core for handling.
    SLI_CPC_DEBUG_TRACE_EP_RXD_DATA_FRAME_DROPPED(frame->ep);
    SLI_CPC_LOG_ERROR("Received frame for an endpoint that is out of memory. Endpoint ID: %d", addr);

    status = SL_STATUS_NO_MORE_RESOURCE;
    goto exit;
  }

  frame->payload = buf;

exit:
  return status;
}
