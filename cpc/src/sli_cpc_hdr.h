/**
 * @file
 * @brief CPC data link header definitions and utilities.
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
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
 */
#ifndef SLI_CPC_HDR_H
#define SLI_CPC_HDR_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "sl_cpc_ep.h"
#include "sli_cpc_assert.h"
#include "sli_cpc_endianness.h"
#include "sli_cpc_types.h"
#include "sli_cpc_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                                  Defines                                   */
/******************************************************************************/
static_assert(SL_CPC_EP_MAX_PAYLOAD_SIZE <= UINT16_MAX,
              "Protocol limits the MTU to two bytes, max payload size is too big");

#define SLI_CPC_HEADER_SIZE (sizeof(sli_cpc_hdr_t))
#define SLI_CPC_HEADER_RX_BUFFER_WINDOW_MAX 255

#define SLI_CPC_FIELD_POS(field) field##_Pos
#define SLI_CPC_FIELD_MSK(field) field##_Msk

#define SLI_CPC_FIELD_PREP(field, val) (((uint8_t)(val) << SLI_CPC_FIELD_POS(field)) & SLI_CPC_FIELD_MSK(field))

#define SLI_CPC_FIELD_GET(field, reg) (((reg) & SLI_CPC_FIELD_MSK(field)) >> SLI_CPC_FIELD_POS(field))

/******************************************************************************/
/*                   Control Byte Field Positions and Masks                   */
/******************************************************************************/
#define SLI_CPC_CONTROL_REQUEST_ACK_Pos 6U
#define SLI_CPC_CONTROL_REQUEST_ACK_Msk 0x40UL

#define SLI_CPC_CONTROL_RESET_Pos 5U
#define SLI_CPC_CONTROL_RESET_Msk 0x20UL

#define SLI_CPC_CONTROL_SYN_Pos 4U
#define SLI_CPC_CONTROL_SYN_Msk 0x10UL

#define SLI_CPC_CONTROL_RFU_Pos 0U
#define SLI_CPC_CONTROL_RFU_Msk \
  (~(SLI_CPC_CONTROL_REQUEST_ACK_Msk | SLI_CPC_CONTROL_RESET_Msk | SLI_CPC_CONTROL_SYN_Msk))

/******************************************************************************/
/*                                   Types                                    */
/******************************************************************************/

SLI_CPC_STATIC_ASSERT_PACKED_SIZE(sli_cpc_hdr_t, 8);

static inline bool sli_cpc_header_is_syn(const sli_cpc_hdr_t *hdr);

/**
 * @brief Check if CPC header size field is within maximum payload size
 * @param hdr Pointer to CPC header structure
 * @return true if size_le decodes to a value not exceeding SL_CPC_EP_MAX_PAYLOAD_SIZE, false otherwise
 */
static inline bool sli_cpc_header_is_size_valid(const sli_cpc_hdr_t *hdr)
{
  return sli_cpc_u16_from_le(hdr->size_le) <= SL_CPC_EP_MAX_PAYLOAD_SIZE;
}

/**
 * @brief Get payload size from CPC header size field
 * @param hdr Pointer to CPC header structure
 * @return Payload length in bytes
 */
static inline uint16_t sli_cpc_header_get_payload_size(const sli_cpc_hdr_t *hdr)
{
  if (sli_cpc_header_is_syn(hdr))
    return 0;

  return sli_cpc_u16_from_le(hdr->size_le);
}

/**
 * @brief Set payload size in CPC header size field
 * @param hdr Pointer to CPC header structure
 * @param payload_size Payload length in bytes (host order)
 */
static inline void sli_cpc_header_set_payload_size(sli_cpc_hdr_t *hdr, uint16_t payload_size)
{
  sli_cpc_u16_to_le(payload_size, hdr->size_le);
}

/**
 * @brief Get destination address (endpoint ID) from CPC header addr field
 * @param hdr Pointer to CPC header structure
 * @return Endpoint ID in native byte order
 */
static inline uint16_t sli_cpc_header_get_address(const sli_cpc_hdr_t *hdr)
{
  return sli_cpc_u16_from_le(hdr->addr_le);
}

/**
 * @brief Set destination address (endpoint ID) in CPC header addr field
 * @param hdr Pointer to CPC header structure
 * @param address Endpoint ID (native byte order)
 */
static inline void sli_cpc_header_set_address(sli_cpc_hdr_t *hdr, uint16_t address)
{
  sli_cpc_u16_to_le(address, hdr->addr_le);
}

/******************************************************************************/
/*                           Function Declarations                            */
/******************************************************************************/

/**
 * @brief Get sequence number from header
 * @param hdr Pointer to CPC header structure
 * @return 8-bit sequence number (0-255)
 */
static inline uint8_t sli_cpc_header_get_seq(const sli_cpc_hdr_t *hdr)
{
  return hdr->seq;
}

/**
 * @brief Get acknowledgment number from header
 * @param hdr Pointer to CPC header structure
 * @return 8-bit acknowledgment number (0-255)
 */
static inline uint8_t sli_cpc_header_get_ack(const sli_cpc_hdr_t *hdr)
{
  return hdr->ack;
}

/**
 * @brief Get control byte from header
 * @param hdr Pointer to CPC header structure
 * @return 8-bit control byte
 */
static inline uint8_t sli_cpc_header_get_control(const sli_cpc_hdr_t *hdr)
{
  return hdr->ctrl;
}

/**
 * @brief Set control byte in header
 * @param hdr Pointer to CPC header structure
 * @param control 8-bit control byte value
 */
static inline void sli_cpc_header_set_control(sli_cpc_hdr_t *hdr, uint8_t control)
{
  hdr->ctrl = control;
}

/**
 * @brief Get RX window from header
 * @param hdr Pointer to CPC header structure
 * @return 8-bit RX window value
 */
static inline uint8_t sli_cpc_header_get_rx_wnd(const sli_cpc_hdr_t *hdr)
{
  return hdr->rx_wnd;
}

/**
 * @brief Set RX window in header
 * @param hdr Pointer to CPC header structure
 * @param rx_wnd 8-bit RX window value
 */
static inline void sli_cpc_header_set_rx_wnd(sli_cpc_hdr_t *hdr, uint8_t rx_wnd)
{
  hdr->rx_wnd = rx_wnd;
}

/**
 * @brief Set sequence number in header
 * @param hdr Pointer to CPC header structure
 * @param seq 8-bit sequence number (0-255)
 */
static inline void sli_cpc_header_set_seq(sli_cpc_hdr_t *hdr, uint8_t seq)
{
  hdr->seq = seq;
}

/**
 * @brief Set acknowledgment number in header
 * @param hdr Pointer to CPC header structure
 * @param ack 8-bit acknowledgment number (0-255)
 */
static inline void sli_cpc_header_set_ack(sli_cpc_hdr_t *hdr, uint8_t ack)
{
  hdr->ack = ack;
}

/**
 * @brief Check if acknowledgment is requested
 * @param hdr Pointer to CPC header structure
 * @return true if ACK requested
 */
static inline bool sli_cpc_header_is_ack_requested(const sli_cpc_hdr_t *hdr)
{
  return SLI_CPC_FIELD_GET(SLI_CPC_CONTROL_REQUEST_ACK, hdr->ctrl) != 0;
}

static inline bool sli_cpc_header_is_reset(const sli_cpc_hdr_t *hdr)
{
  return SLI_CPC_FIELD_GET(SLI_CPC_CONTROL_RESET, hdr->ctrl) != 0;
}

static inline bool sli_cpc_header_is_syn(const sli_cpc_hdr_t *hdr)
{
  return SLI_CPC_FIELD_GET(SLI_CPC_CONTROL_SYN, hdr->ctrl) != 0;
}

/**
 * @brief Set ACK request bit
 * @param hdr Pointer to CPC header structure
 * @param request_ack true to request ACK, false otherwise
 */
static inline void sli_cpc_header_set_ack_request(sli_cpc_hdr_t *hdr, bool request_ack)
{
  if (request_ack) {
    hdr->ctrl |= SLI_CPC_FIELD_PREP(SLI_CPC_CONTROL_REQUEST_ACK, 1);
  } else {
    hdr->ctrl &= ~SLI_CPC_FIELD_PREP(SLI_CPC_CONTROL_REQUEST_ACK, 1);
  }
}

/**
 * @brief Set reset bit
 * @param hdr Pointer to CPC header structure
 * @param reset true to signal a reset, false otherwise
 */
static inline void sli_cpc_header_set_reset(sli_cpc_hdr_t *hdr, bool reset)
{
  if (reset) {
    hdr->ctrl |= SLI_CPC_FIELD_PREP(SLI_CPC_CONTROL_RESET, 1);
  } else {
    hdr->ctrl &= ~SLI_CPC_FIELD_PREP(SLI_CPC_CONTROL_RESET, 1);
  }
}

/**
 * @brief Set SYN bit
 * @param hdr Pointer to CPC header structure
 * @param syn true to signal a syn, false otherwise
 */
static inline void sli_cpc_header_set_syn(sli_cpc_hdr_t *hdr, bool syn)
{
  if (syn) {
    hdr->ctrl |= SLI_CPC_FIELD_PREP(SLI_CPC_CONTROL_SYN, 1);
  } else {
    hdr->ctrl &= ~SLI_CPC_FIELD_PREP(SLI_CPC_CONTROL_SYN, 1);
  }
}

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_HDR_H
