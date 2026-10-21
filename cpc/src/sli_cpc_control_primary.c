/***************************************************************************/ /**
 * @file
 * @brief CPC control primary: bus init sequence initiator.
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
#include <string.h>

#include "sl_status.h"

#include "sli_cpc.h"
#include "sli_cpc_bus.h"
#include "sli_cpc_control.h"
#include "sli_cpc_endianness.h"
#include "sli_cpc_ep.h"
#include "sli_cpc_log.h"
#include "sli_cpc_panic.h"

static void primary_on_error(sli_cpc_control_t *ctrl, sl_status_t status)
{
  (void)status;

  SLI_CPC_LOG_DEBUG("on_error: status=0x%lx, closing to reconnect", (unsigned long)status);

  sl_cpc_ep_close(&ctrl->ep);
}

static void primary_on_closed(sli_cpc_control_t *ctrl)
{
  sli_cpc_control_primary_t *primary = &ctrl->primary;
  sl_cpc_ep_t *ep = &ctrl->ep;
  sl_status_t status;

  primary->state = SLI_CPC_CONTROL_PRIMARY_STATE_IDLE;
  primary->expected_response_op_id = 0;

  status = sli_cpc_ep_attach(ep, ep->bus);
  if (status != SL_STATUS_OK) {
    SLI_CPC_PANIC("on_closed: attach failed: 0x%lx", (unsigned long)status);
  }

  status = sli_cpc_ep_connect(ep);
  if (status != SL_STATUS_OK) {
    SLI_CPC_PANIC("on_closed: connect failed: 0x%lx", (unsigned long)status);
  }
}

static sl_status_t primary_init(sli_cpc_control_t *ctrl, sl_cpc_bus_t *bus)
{
  sl_status_t status;

  status = sli_cpc_control_init(ctrl);
  if (status != SL_STATUS_OK) {
    return status;
  }

  status = sli_cpc_ep_attach(&ctrl->ep, bus);
  if (status != SL_STATUS_OK) {
    sli_cpc_control_deinit(ctrl);
    return status;
  }

  status = sli_cpc_ep_connect(&ctrl->ep);
  if (status != SL_STATUS_OK) {
    sli_cpc_control_close(ctrl);
    sli_cpc_control_deinit(ctrl);
    return status;
  }

  return SL_STATUS_OK;
}

static void primary_deinit(sli_cpc_control_t *ctrl)
{
  sli_cpc_control_primary_t *primary = &ctrl->primary;

  primary->state = SLI_CPC_CONTROL_PRIMARY_STATE_IDLE;
  primary->expected_response_op_id = 0;
  ctrl->deinitializing = true;

  sli_cpc_control_close(ctrl);
  sli_cpc_control_deinit(ctrl);
}

static sl_status_t send_protocol_version_request(sli_cpc_control_t *ctrl)
{
  sli_cpc_control_primary_t *primary = &ctrl->primary;
  sli_cpc_protocol_version_request_t req = {
    .version_major = SL_CPC_VERSION_MAJOR,
    .version_minor = SL_CPC_VERSION_MINOR,
  };
  sl_status_t status;
  uint16_t request_op_id;

  status
    = sli_cpc_control_send_request(ctrl, SLI_CPC_CTRL_TYPE_PROTOCOL_VERSION, &req, sizeof(req), NULL, &request_op_id);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("failed to send protocol version request: %lx", (unsigned long)status);
    return status;
  }

  primary->state = SLI_CPC_CONTROL_PRIMARY_STATE_PROTOCOL_VERSION;
  primary->expected_response_op_id = request_op_id;
  SLI_CPC_LOG_DEBUG("sent protocol version request");

  return SL_STATUS_OK;
}

static sl_status_t send_reset_reason_request(sli_cpc_control_t *ctrl)
{
  sli_cpc_control_primary_t *primary = &ctrl->primary;
  sl_status_t status;
  uint16_t request_op_id;

  status = sli_cpc_control_send_request(ctrl, SLI_CPC_CTRL_TYPE_RESET_REASON, NULL, 0, NULL, &request_op_id);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("failed to send reset reason request: %lx", (unsigned long)status);
    return status;
  }

  primary->state = SLI_CPC_CONTROL_PRIMARY_STATE_RESET_REASON;
  primary->expected_response_op_id = request_op_id;
  SLI_CPC_LOG_DEBUG("sent reset reason request");

  return SL_STATUS_OK;
}

static sl_status_t send_phy_capabilities_request(sli_cpc_control_t *ctrl)
{
  sli_cpc_control_primary_t *primary = &ctrl->primary;
  sl_cpc_bus_t *bus = ctrl->ep.bus;
  const void *local_caps = NULL;
  uint16_t local_caps_len = 0;
  sl_status_t status;
  uint16_t request_op_id;

  if (bus->drv_ops->get_local_capabilities) {
    bus->drv_ops->get_local_capabilities(bus, &local_caps, &local_caps_len);
  }

  status = sli_cpc_control_send_request(ctrl, SLI_CPC_CTRL_TYPE_PHY_CAPABILITIES, local_caps, local_caps_len, NULL,
                                        &request_op_id);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("failed to send PHY capabilities request: %lx", (unsigned long)status);
    return status;
  }

  primary->state = SLI_CPC_CONTROL_PRIMARY_STATE_PHY_CAPABILITIES;
  primary->expected_response_op_id = request_op_id;
  SLI_CPC_LOG_DEBUG("sent PHY capabilities request");

  return SL_STATUS_OK;
}

static sl_status_t send_bus_enable_request(sli_cpc_control_t *ctrl)
{
  sli_cpc_control_primary_t *primary = &ctrl->primary;
  sl_status_t status;
  uint16_t request_op_id;

  status = sli_cpc_control_send_request(ctrl, SLI_CPC_CTRL_TYPE_BUS_ENABLE, NULL, 0, NULL, &request_op_id);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("failed to send bus enable request: %lx", (unsigned long)status);
    return status;
  }

  primary->state = SLI_CPC_CONTROL_PRIMARY_STATE_BUS_ENABLE;
  primary->expected_response_op_id = request_op_id;
  SLI_CPC_LOG_DEBUG("sent bus enable request");

  return SL_STATUS_OK;
}

static sl_status_t on_protocol_version_response(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf)
{
  const sli_cpc_control_header_t *hdr = sli_cpc_control_header_from_buf(buf);
  const sli_cpc_protocol_version_response_t *resp;
  const void *data;
  uint16_t len;

  if (sli_cpc_control_header_get_status(hdr) != SLI_CPC_CTRL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("protocol version negotiation failed: status=%u", sli_cpc_control_header_get_status(hdr));
    return SL_STATUS_FAIL;
  }

  sli_cpc_control_get_data_from_buf(buf, &data, &len);
  resp = data;

  if (resp == NULL || len != sizeof(*resp)) {
    SLI_CPC_LOG_WARN("invalid protocol version response length: %u", len);
    return SL_STATUS_INVALID_PARAMETER;
  }

  if (resp->version_major != SL_CPC_VERSION_MAJOR || resp->version_minor != SL_CPC_VERSION_MINOR) {
    SLI_CPC_LOG_ERROR("incompatible secondary protocol version: %u.%u", resp->version_major, resp->version_minor);
    return SL_STATUS_NOT_SUPPORTED;
  }

  return send_reset_reason_request(ctrl);
}

static sl_status_t on_reset_reason_response(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf)
{
  const sli_cpc_control_header_t *hdr = sli_cpc_control_header_from_buf(buf);
  const sli_cpc_reset_reason_response_t *resp;
  const void *data;
  uint16_t len;

  if (sli_cpc_control_header_get_status(hdr) != SLI_CPC_CTRL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("reset reason request failed: status=%u", sli_cpc_control_header_get_status(hdr));
    return SL_STATUS_FAIL;
  }

  sli_cpc_control_get_data_from_buf(buf, &data, &len);
  resp = data;

  if (resp == NULL || len != sizeof(*resp)) {
    SLI_CPC_LOG_WARN("invalid reset reason response length: %u", len);
    return SL_STATUS_INVALID_PARAMETER;
  }

  SLI_CPC_LOG_DEBUG("secondary reset reason: %lu", (unsigned long)sli_cpc_u32_from_le(resp->reset_reason_le));

  return send_phy_capabilities_request(ctrl);
}

static sl_status_t on_phy_capabilities_response(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf)
{
  const sli_cpc_control_header_t *hdr = sli_cpc_control_header_from_buf(buf);
  sl_cpc_bus_t *bus = ctrl->ep.bus;
  sl_status_t status;
  uint16_t caps_len;
  const void *caps;

  if (sli_cpc_control_header_get_status(hdr) != SLI_CPC_CTRL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("PHY capabilities negotiation failed: status=%u", sli_cpc_control_header_get_status(hdr));
    return SL_STATUS_FAIL;
  }

  sli_cpc_control_get_data_from_buf(buf, &caps, &caps_len);

  if (bus->drv_ops->set_remote_capabilities && caps_len != 0) {
    status = bus->drv_ops->set_remote_capabilities(bus, caps, caps_len);
    if (status != SL_STATUS_OK) {
      SLI_CPC_LOG_ERROR("failed to apply remote capabilities: %lx", (unsigned long)status);
      return status;
    }
  }

  return send_bus_enable_request(ctrl);
}

static sl_status_t on_bus_enable_response(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf)
{
  const sli_cpc_control_header_t *hdr = sli_cpc_control_header_from_buf(buf);
  sli_cpc_control_primary_t *primary = &ctrl->primary;

  if (sli_cpc_control_header_get_status(hdr) != SLI_CPC_CTRL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("bus enable failed: status=%u", sli_cpc_control_header_get_status(hdr));
    return SL_STATUS_FAIL;
  }

  if (sli_cpc_control_header_get_payload_size(hdr) != 0) {
    SLI_CPC_LOG_WARN("bus enable response with payload is not supported");
    return SL_STATUS_INVALID_PARAMETER;
  }

  primary->state = SLI_CPC_CONTROL_PRIMARY_STATE_INITIALIZED;
  primary->expected_response_op_id = 0;

  SLI_CPC_LOG_DEBUG("primary init sequence completed");
  ctrl->initialized = true;
  sli_cpc_bus_signal_event(ctrl->ep.bus, SLI_CPC_SIGNAL_SYSTEM);

  return SL_STATUS_OK;
}

static void primary_on_connected(sli_cpc_control_t *ctrl)
{
  const sli_cpc_control_primary_t *primary = &ctrl->primary;
  sl_status_t status;

  if (primary->state != SLI_CPC_CONTROL_PRIMARY_STATE_IDLE) {
    SLI_CPC_LOG_WARN("CONNECTED ignored, state=%d", (int)primary->state);
    return;
  }

  SLI_CPC_LOG_DEBUG("CONNECTED, starting init sequence");
  status = send_protocol_version_request(ctrl);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("failed to start init sequence: %lx", (unsigned long)status);
    sl_cpc_ep_close(&ctrl->ep);
  }
}

static sl_status_t primary_on_response(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf)
{
  const sli_cpc_control_header_t *hdr = sli_cpc_control_header_from_buf(buf);
  const sli_cpc_control_primary_t *primary = &ctrl->primary;
  uint16_t response_op_id = sli_cpc_control_header_get_op_id(hdr);
  uint8_t type = sli_cpc_control_header_get_type(hdr);

  if (response_op_id != primary->expected_response_op_id) {
    SLI_CPC_LOG_WARN("ignoring unmatched control response: type=0x%02X response_op_id=%u expected=%u", type,
                     response_op_id, primary->expected_response_op_id);
    return SL_STATUS_OK;
  }

  switch (primary->state) {
    case SLI_CPC_CONTROL_PRIMARY_STATE_PROTOCOL_VERSION:
      if (type != SLI_CPC_CTRL_TYPE_PROTOCOL_VERSION) {
        break;
      }
      return on_protocol_version_response(ctrl, buf);

    case SLI_CPC_CONTROL_PRIMARY_STATE_RESET_REASON:
      if (type != SLI_CPC_CTRL_TYPE_RESET_REASON) {
        break;
      }
      return on_reset_reason_response(ctrl, buf);

    case SLI_CPC_CONTROL_PRIMARY_STATE_PHY_CAPABILITIES:
      if (type != SLI_CPC_CTRL_TYPE_PHY_CAPABILITIES) {
        break;
      }
      return on_phy_capabilities_response(ctrl, buf);

    case SLI_CPC_CONTROL_PRIMARY_STATE_BUS_ENABLE:
      if (type != SLI_CPC_CTRL_TYPE_BUS_ENABLE) {
        break;
      }
      return on_bus_enable_response(ctrl, buf);

    default:
      SLI_CPC_LOG_WARN("ignoring control response outside init: type=0x%02X response_op_id=%u state=%u", type,
                       response_op_id, (unsigned int)primary->state);
      return SL_STATUS_OK;
  }

  SLI_CPC_LOG_WARN("unexpected control response type=0x%02X in init state %u", type, primary->state);

  return SL_STATUS_INVALID_STATE;
}

static sl_status_t primary_on_request(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf)
{
  return sli_cpc_control_on_unknown_request(ctrl, buf);
}

static void primary_on_send_done(sli_cpc_control_t *ctrl, const sl_cpc_ep_event_t *event)
{
  (void)ctrl;
  (void)event;
}

const sli_cpc_control_ops_t sli_cpc_control_primary_ops = {
  .init = primary_init,
  .deinit = primary_deinit,
  .on_connected = primary_on_connected,
  .on_error = primary_on_error,
  .on_closed = primary_on_closed,
  .on_request = primary_on_request,
  .on_response = primary_on_response,
  .on_send_done = primary_on_send_done,
};
