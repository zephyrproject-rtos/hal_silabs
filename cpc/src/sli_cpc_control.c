/***************************************************************************/ /**
 * @file
 * @brief CPC data-link control shared implementation.
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

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "sl_status.h"

#include "sl_cpc_buf.h"
#include "sli_cpc.h"
#include "sli_cpc_assert.h"
#include "sli_cpc_bus.h"
#include "sli_cpc_control.h"
#include "sli_cpc_endianness.h"
#include "sli_cpc_ep.h"
#include "sli_cpc_frame.h"
#include "sli_cpc_log.h"
#include "sli_cpc_panic.h"
#include "sli_cpc_types.h"
#include "sli_cpc_utils.h"

/******************************************************************************/
/*                              Shared helpers                                */
/******************************************************************************/

static bool sli_cpc_control_command_buf_is_valid(const sl_cpc_buf_t *buf)
{
  const sli_cpc_control_header_t *hdr;
  uint16_t required;

  if (buf->len < sizeof(*hdr)) {
    return false;
  }

  hdr = sli_cpc_control_header_from_buf(buf);
  required = sizeof(*hdr) + sli_cpc_control_header_get_payload_size(hdr);

  return buf->len >= required;
}

void sli_cpc_control_get_data_from_buf(const sl_cpc_buf_t *buf, const void **data, uint16_t *len)
{
  const sli_cpc_control_command_t *command = sli_cpc_control_command_from_buf(buf);

  *len = sli_cpc_control_header_get_payload_size(&command->header);
  *data = (*len > 0) ? command->data : NULL;
}

static inline sl_status_t validate_tx_payload_size(uint16_t payload_size)
{
  return (payload_size > SL_CPC_EP_MAX_PAYLOAD_SIZE) ? SL_STATUS_INVALID_PARAMETER : SL_STATUS_OK;
}

static sl_status_t send_control_command(sli_cpc_control_t *ctrl, uint8_t type, uint16_t message_id, uint8_t status,
                                        const void *tx_data, uint16_t tx_len, void *arg)
{
  sli_cpc_control_command_t *control_command;
  sl_cpc_frame_t *frame;
  sl_cpc_buf_t *tx_buf;
  uint16_t total_size;
  sl_status_t ret;

  ret = validate_tx_payload_size(tx_len);
  if (ret != SL_STATUS_OK) {
    return ret;
  }

  total_size = sizeof(*control_command) + tx_len;
  tx_buf = sl_cpc_buf_alloc(total_size);
  if (!tx_buf) {
    return SL_STATUS_ALLOCATION_FAILED;
  }

  control_command = tx_buf->ptr;
  memset(&control_command->header, 0, sizeof(control_command->header));
  sli_cpc_control_header_set_payload_size(&control_command->header, tx_len);
  sli_cpc_control_header_set_op_id(&control_command->header, message_id);
  sli_cpc_control_header_set_type(&control_command->header, type);
  sli_cpc_control_header_set_status(&control_command->header, status);

  if (tx_len > 0) {
    memcpy(control_command->data, tx_data, tx_len);
  }

  frame = malloc(sizeof(*frame));
  if (!frame) {
    sl_cpc_buf_free(tx_buf);
    return SL_STATUS_ALLOCATION_FAILED;
  }

  ret = sl_cpc_ep_send(&ctrl->ep, tx_buf, frame, arg);
  if (ret != SL_STATUS_OK) {
    sl_cpc_buf_free(tx_buf);
    free(frame);
  }

  return ret;
}

sl_status_t sli_cpc_control_respond(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *rx_buf, const void *tx_data,
                                    uint16_t tx_len, sli_cpc_ctrl_status_t tx_status, void *arg)
{
  const sli_cpc_control_header_t *ctrl_hdr = sli_cpc_control_header_from_buf(rx_buf);
  uint16_t response_op_id;
  sl_status_t status;
  uint8_t resp_type;

  resp_type = sli_cpc_control_header_get_type(ctrl_hdr) | SLI_CPC_CTRL_TYPE_RESPONSE_FLAG;
  response_op_id = sli_cpc_control_header_get_op_id(ctrl_hdr);

  status = send_control_command(ctrl, resp_type, response_op_id, (uint8_t)tx_status, tx_data, tx_len, arg);
  if (status != SL_STATUS_OK) {
    // CPC-3374: The init sequence will hang until internal TX allocations are solved.
    SLI_CPC_PANIC("control respond failed: 0x%lx (type=0x%02X response_op_id=%u)", (unsigned long)status,
                  (unsigned int)sli_cpc_control_header_get_type(ctrl_hdr), (unsigned int)response_op_id);
  }

  return status;
}

sl_status_t sli_cpc_control_send_request(sli_cpc_control_t *ctrl, sli_cpc_ctrl_type_t type, const void *tx_data,
                                         uint16_t tx_len, void *arg, uint16_t *request_op_id_out)
{
  uint16_t request_op_id;

  if ((type & SLI_CPC_CTRL_TYPE_RESPONSE_FLAG) != 0) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  if (tx_len > 0 && !tx_data) {
    return SL_STATUS_NULL_POINTER;
  }

  request_op_id = ctrl->next_request_op_id++;

  if (request_op_id_out) {
    *request_op_id_out = request_op_id;
  }

  return send_control_command(ctrl, (uint8_t)type, request_op_id, SLI_CPC_CTRL_STATUS_OK, tx_data, tx_len, arg);
}

sl_status_t sli_cpc_control_on_unknown_request(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf)
{
  SLI_CPC_LOG_WARN("received unknown request type 0x%02X (request_op_id=%d)",
                   sli_cpc_control_header_get_type(sli_cpc_control_header_from_buf(buf)),
                   sli_cpc_control_header_get_op_id(sli_cpc_control_header_from_buf(buf)));

  return sli_cpc_control_respond(ctrl, buf, NULL, 0, SLI_CPC_CTRL_STATUS_NOT_SUPPORTED, NULL);
}

static sl_status_t on_control_request(sli_cpc_control_t *ctrl, sl_cpc_buf_t *buf)
{
  sl_status_t status;

  status = ctrl->ops->on_request(ctrl, buf);

  sl_cpc_ep_push_recv_buf(&ctrl->ep, buf);

  return status;
}

static sl_status_t on_control_response(sli_cpc_control_t *ctrl, sl_cpc_buf_t *buf)
{
  sl_status_t status;

  status = ctrl->ops->on_response(ctrl, buf);

  sl_cpc_ep_push_recv_buf(&ctrl->ep, buf);

  return status;
}

static void on_recv(sli_cpc_control_t *ctrl, const sl_cpc_ep_event_t *event)
{
  sl_cpc_buf_t *buf = event->recv.buf;
  const sli_cpc_control_header_t *hdr;
  sl_cpc_ep_t *ep = &ctrl->ep;
  sl_status_t status;

  if (!sli_cpc_control_command_buf_is_valid(buf)) {
    SLI_CPC_LOG_ERROR("dropped invalid control command on ep %u", (unsigned int)ep->id);
    sl_cpc_ep_push_recv_buf(ep, buf);
    sl_cpc_ep_close(ep);
    return;
  }

  hdr = sli_cpc_control_header_from_buf(buf);
  if (sli_cpc_control_header_is_response(hdr)) {
    status = on_control_response(ctrl, buf);
  } else {
    status = on_control_request(ctrl, buf);
  }

  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("handling failed on ep %u: 0x%lx", (unsigned int)ep->id, (unsigned long)status);
    sl_cpc_ep_close(ep);
  }
}

static void on_send_done(sli_cpc_control_t *ctrl, const sl_cpc_ep_event_t *event)
{
  sl_cpc_frame_t *frame = event->send_done.frame;
  sl_status_t status = event->send_done.status;

  if (status != SL_STATUS_OK) {
    if (status == SL_STATUS_TRANSMIT_INCOMPLETE) {
      SLI_CPC_LOG_WARN("control command transmit aborted: 0x%lx", (unsigned long)status);
    } else {
      SLI_CPC_LOG_ERROR("failed to write control command: 0x%lx", (unsigned long)status);
    }
    goto cleanup;
  }

  ctrl->ops->on_send_done(ctrl, event);

cleanup:
  if (frame->payload) {
    sl_cpc_buf_free(frame->payload);
    frame->payload = NULL;
  }

  free(frame);
}

static void on_connected(sli_cpc_control_t *ctrl)
{
  ctrl->ops->on_connected(ctrl);
}

static void on_error(sli_cpc_control_t *ctrl, sl_status_t status)
{
  ctrl->ops->on_error(ctrl, status);
}

static void on_closed(sli_cpc_control_t *ctrl)
{
  sl_cpc_ep_t *ep = &ctrl->ep;

  ctrl->initialized = false;
  ctrl->next_request_op_id = 0;
  ep->bus->initialized = false;

  sli_cpc_bus_terminate_endpoints(ep->bus);

  if (ctrl->deinitializing) {
    return;
  }

  ctrl->ops->on_closed(ctrl);
}

void sli_cpc_control_deinit(sli_cpc_control_t *ctrl)
{
  sl_cpc_buf_t *buf;

  SLI_CPC_ASSERT(ctrl);

  while (sl_cpc_ep_pop_recv_buf(&ctrl->ep, &buf) == SL_STATUS_OK) {
    SLI_CPC_ASSERT(buf == &ctrl->rx_buf);
  }

  sl_cpc_ep_deinit(&ctrl->ep);
  ctrl->next_request_op_id = 0;
  ctrl->deinitializing = false;
  ctrl->initialized = false;
}

static void control_event_callback(sl_cpc_ep_t *ep, sl_cpc_ep_event_type_t type, const sl_cpc_ep_event_t *event,
                                   void *arg)
{
  sli_cpc_control_t *ctrl = container_of(ep, sli_cpc_control_t, ep);

  (void)arg;

  switch (type) {
    case SL_CPC_EP_EVENT_SEND_DONE:
      on_send_done(ctrl, event);
      break;
    case SL_CPC_EP_EVENT_RECV:
      on_recv(ctrl, event);
      break;
    case SL_CPC_EP_EVENT_CONNECTED:
      on_connected(ctrl);
      break;
    case SL_CPC_EP_EVENT_ERROR:
      on_error(ctrl, event->error.status);
      break;
    case SL_CPC_EP_EVENT_CLOSED:
      on_closed(ctrl);
      break;
    default:
      break;
  }
}

sl_status_t sli_cpc_control_init(sli_cpc_control_t *ctrl)
{
  sl_status_t status;

  SLI_CPC_ASSERT(ctrl);

  if (!ctrl->ops) {
    return SL_STATUS_NULL_POINTER;
  }

  ctrl->deinitializing = false;

  status = sl_cpc_ep_init(&ctrl->ep, SL_CPC_EP_ID_CONTROL, sizeof(ctrl->rx_data), control_event_callback, NULL);
  if (status != SL_STATUS_OK) {
    return status;
  }

  ctrl->ep.flags |= SLI_CPC_EP_FLAG_CONTROL;
  ctrl->next_request_op_id = 0;

  sl_cpc_buf_init(&ctrl->rx_buf, ctrl->rx_data, sizeof(ctrl->rx_data));

  status = sl_cpc_ep_push_recv_buf(&ctrl->ep, &ctrl->rx_buf);
  if (status != SL_STATUS_OK) {
    sl_cpc_ep_deinit(&ctrl->ep);
    return status;
  }

  return SL_STATUS_OK;
}

void sli_cpc_control_close(sli_cpc_control_t *ctrl)
{
  sl_cpc_bus_t *bus = ctrl->ep.bus;

  sl_cpc_ep_close(&ctrl->ep);
  sli_cpc_bus_process_action(bus);
}
