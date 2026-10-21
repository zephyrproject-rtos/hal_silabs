/***************************************************************************/ /**
 * @file
 * @brief CPC data-link control definition.
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

#ifndef SLI_CPC_CONTROL_H
#define SLI_CPC_CONTROL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "sl_slist.h"
#include "sl_status.h"

#include "sl_cpc_buf.h"
#include "sli_cpc.h"
#include "sli_cpc_endianness.h"
#include "sli_cpc_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                                Wire format                                 */
/******************************************************************************/

/// Bit 7 of the type field marks a command as a response to a previously sent
/// request.
#define SLI_CPC_CTRL_TYPE_RESPONSE_FLAG 0x80

/// CPC control command header (8 bytes, on-wire layout). All multi-byte fields are
/// little-endian.
typedef struct sli_cpc_control_header {
  uint8_t size_le[2];  ///< Total size of the control command, including this header.
  uint8_t op_id_le[2]; ///< Operation identifier for request/response matching.
  uint8_t type;        ///< Control type; bit 7 is the response flag, bits 6..0 are sli_cpc_ctrl_type_t.
  uint8_t status;      ///< sli_cpc_ctrl_status_t on responses; ignored on requests.
  uint8_t reserved[2]; ///< Must be zero on TX, ignored on RX.
} sli_cpc_control_header_t;
SLI_CPC_STATIC_ASSERT_PACKED_SIZE(sli_cpc_control_header_t, 8);

typedef struct sli_cpc_control_command {
  sli_cpc_control_header_t header;
  uint8_t data[];
} sli_cpc_control_command_t;

typedef enum {
  SLI_CPC_CTRL_TYPE_PROTOCOL_VERSION = 0x01,
  SLI_CPC_CTRL_TYPE_RESET_REASON = 0x02,
  SLI_CPC_CTRL_TYPE_PHY_CAPABILITIES = 0x03,
  SLI_CPC_CTRL_TYPE_BUS_ENABLE = 0x04,
} sli_cpc_ctrl_type_t;

typedef enum {
  SLI_CPC_CTRL_STATUS_OK = 0x00,
  SLI_CPC_CTRL_STATUS_NOT_SUPPORTED = 0x01,
  SLI_CPC_CTRL_STATUS_INVALID_PARAMETER = 0x02,
  SLI_CPC_CTRL_STATUS_INTERNAL_ERROR = 0x03,
} sli_cpc_ctrl_status_t;

typedef enum {
  SLI_CPC_RESET_REASON_CRASH,
  SLI_CPC_RESET_REASON_FAULT,
  SLI_CPC_RESET_REASON_WATCHDOG,
  SLI_CPC_RESET_REASON_SOFTWARE,
  SLI_CPC_RESET_REASON_EXTERNAL,
  SLI_CPC_RESET_REASON_UNKNOWN,
} sli_cpc_reset_reason_t;

typedef struct sli_cpc_reset_reason_response {
  uint8_t reset_reason_le[4];
} sli_cpc_reset_reason_response_t;
SLI_CPC_STATIC_ASSERT_PACKED_SIZE(sli_cpc_reset_reason_response_t, 4);

typedef struct sli_cpc_protocol_version_request {
  uint8_t version_major;
  uint8_t version_minor;
} sli_cpc_protocol_version_request_t;
SLI_CPC_STATIC_ASSERT_PACKED_SIZE(sli_cpc_protocol_version_request_t, 2);

typedef struct sli_cpc_protocol_version_request sli_cpc_protocol_version_response_t;

/******************************************************************************/
/*                          Control header accessors                          */
/******************************************************************************/

static inline const sli_cpc_control_command_t *sli_cpc_control_command_from_buf(const sl_cpc_buf_t *buf)
{
  return (const sli_cpc_control_command_t *)buf->ptr;
}

static inline const sli_cpc_control_header_t *sli_cpc_control_header_from_buf(const sl_cpc_buf_t *buf)
{
  return &sli_cpc_control_command_from_buf(buf)->header;
}

static inline uint16_t sli_cpc_control_header_get_payload_size(const sli_cpc_control_header_t *hdr)
{
  uint16_t total = sli_cpc_u16_from_le(hdr->size_le);
  return (total >= sizeof(*hdr)) ? (total - sizeof(*hdr)) : 0;
}

static inline void sli_cpc_control_header_set_payload_size(sli_cpc_control_header_t *hdr, uint16_t payload_size)
{
  sli_cpc_u16_to_le(payload_size + sizeof(*hdr), hdr->size_le);
}

static inline uint16_t sli_cpc_control_header_get_op_id(const sli_cpc_control_header_t *hdr)
{
  return sli_cpc_u16_from_le(hdr->op_id_le);
}

static inline void sli_cpc_control_header_set_op_id(sli_cpc_control_header_t *hdr, uint16_t op_id)
{
  sli_cpc_u16_to_le(op_id, hdr->op_id_le);
}

static inline uint8_t sli_cpc_control_header_get_type(const sli_cpc_control_header_t *hdr)
{
  return hdr->type & ~SLI_CPC_CTRL_TYPE_RESPONSE_FLAG;
}

static inline void sli_cpc_control_header_set_type(sli_cpc_control_header_t *hdr, uint8_t type)
{
  hdr->type = type;
}

static inline uint8_t sli_cpc_control_header_get_status(const sli_cpc_control_header_t *hdr)
{
  return hdr->status;
}

static inline void sli_cpc_control_header_set_status(sli_cpc_control_header_t *hdr, uint8_t status)
{
  hdr->status = status;
}

static inline bool sli_cpc_control_header_is_response(const sli_cpc_control_header_t *hdr)
{
  return (hdr->type & SLI_CPC_CTRL_TYPE_RESPONSE_FLAG) != 0;
}

/**
 * @brief Return the data slice of an incoming control frame.
 */
void sli_cpc_control_get_data_from_buf(const sl_cpc_buf_t *buf, const void **data, uint16_t *len);

/**
 * @brief Send a control request on the control endpoint.
 *
 * @param[out] request_op_id_out Optional; receives the allocated request operation ID when non-NULL.
 */
sl_status_t sli_cpc_control_send_request(sli_cpc_control_t *ctrl, sli_cpc_ctrl_type_t type, const void *tx_data,
                                         uint16_t tx_len, void *arg, uint16_t *request_op_id_out);

/**
 * @brief Respond to a received control request.
 */
sl_status_t sli_cpc_control_respond(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *rx_buf, const void *tx_data,
                                    uint16_t tx_len, sli_cpc_ctrl_status_t tx_status, void *arg);

/**
 * @brief Log an unsupported control type and respond with NOT_SUPPORTED.
 */
sl_status_t sli_cpc_control_on_unknown_request(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf);

/******************************************************************************/
/*                            Control operations                              */
/******************************************************************************/

/**
 * @brief Bus control operations.
 */
typedef struct sli_cpc_control_ops {
  sl_status_t (*init)(sli_cpc_control_t *ctrl, sl_cpc_bus_t *bus);
  void (*deinit)(sli_cpc_control_t *ctrl);
  void (*on_connected)(sli_cpc_control_t *ctrl);
  void (*on_error)(sli_cpc_control_t *ctrl, sl_status_t status);
  void (*on_closed)(sli_cpc_control_t *ctrl);
  sl_status_t (*on_request)(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf);
  sl_status_t (*on_response)(sli_cpc_control_t *ctrl, const sl_cpc_buf_t *buf);
  void (*on_send_done)(sli_cpc_control_t *ctrl, const sl_cpc_ep_event_t *event);
} sli_cpc_control_ops_t;

#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
extern const sli_cpc_control_ops_t sli_cpc_control_primary_ops;
#endif
#if defined(SL_CATALOG_CPC_NG_SECONDARY_PRESENT)
extern const sli_cpc_control_ops_t sli_cpc_control_secondary_ops;
#endif

/**
 * @brief Initialize a control endpoint with one RX buffer.
 *
 * @param[in] ctrl  Control endpoint to initialize (@ref sl_cpc_bus_t::ctrl); @c ops
 *                  must already be set.
 *
 * On failure, the endpoint is left uninitialized.
 * On success, deinitialize with @ref sli_cpc_control_deinit.
 */
sl_status_t sli_cpc_control_init(sli_cpc_control_t *ctrl);

/**
 * @brief Free RX buffers and deinitialize a control endpoint that is not on a bus.
 */
void sli_cpc_control_deinit(sli_cpc_control_t *ctrl);

/**
 * @brief Close the control endpoint that is attached to a bus.
 */
void sli_cpc_control_close(sli_cpc_control_t *ctrl);

#ifdef __cplusplus
}
#endif

#endif
