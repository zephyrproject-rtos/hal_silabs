/***************************************************************************/ /**
 * @file
 * @brief CPC shared types
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

#ifndef SLI_CPC_TYPES_H
#define SLI_CPC_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#include "sl_component_catalog.h"
#include "sl_cpc_config.h"
#include "sl_slist.h"
#include "sl_status.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                                    Bus                                     */
/******************************************************************************/

/**
 * @brief CPC bus debug counters.
 */
typedef struct sli_cpc_bus_debug_counters {
  uint32_t ep_opened; ///< Number of endpoint opened (listen/connect)
  uint32_t ep_freed;  ///< Number of endpoint freed

  uint32_t rxd_frame;                  ///< Total number of frames received
  uint32_t rxd_valid_reliable_frame;   ///< Total number of reliable frames received
  uint32_t rxd_valid_unreliable_frame; ///< Total number of unreliable frames received
  uint32_t rxd_data_frame_dropped;     ///< Total number of frame dropped

  uint32_t txd_reset;     ///< Total number of reset frames transmitted
  uint32_t txd_completed; ///< Total number of frame confirmed sent by the driver
  uint32_t retxd_frame;   ///< Total number of frame retransmission

  uint32_t driver_error;          ///< Total number of error reported by the driver
  uint32_t driver_packet_dropped; ///< Total number of frame dropped by the driver

  uint32_t invalid_header_checksum;    ///< Total number of frame received with invalid header checksum
  uint32_t invalid_payload_checksum;   ///< Total number of frame received with invalid frame checksum
  uint32_t txd_reset_frame_fault;      ///< Number of failed attempt to transmit a reject frame
  uint32_t txd_syn_fault;              ///< Total number of failed attempt to transmit a syn frame
  uint32_t txd_rx_window_update_fault; ///< Total number of failed attempt to transmit a rx window update.
} sli_cpc_bus_debug_counters_t;

/**
 * @brief CPC bus debug state.
 */
#if (SL_CPC_DEBUG_CORE_EVENT_COUNTERS == 1)
typedef struct sli_cpc_bus_debug {
  sli_cpc_bus_debug_counters_t counters; ///< Bus debug counters
} sli_cpc_bus_debug_t;
#endif

/******************************************************************************/
/*                                 Dispatcher                                 */
/******************************************************************************/

/**
 * @brief Per-bus dispatcher state: one queue + counter per phase.
 */
typedef struct sli_cpc_dispatcher_context {
  sl_slist_node_t *process_queue;
  sl_slist_node_t *pre_process_queue;
  uint8_t post_process_event_counter;
  uint8_t pre_process_event_counter;
} sli_cpc_dispatcher_context_t;

/**
 * @brief Dispatcher callback.
 */
typedef void (*sli_cpc_dispatcher_fnct_t)(void *data);

/**
 * @brief CPC dispatcher handle.
 */
typedef struct sli_cpc_dispatcher_handle {
  sl_slist_node_t node;           ///< node
  sli_cpc_dispatcher_fnct_t fnct; ///< fnct
  struct sl_cpc_bus *bus;         ///< Owning bus.
  void *data;                     ///< Opaque user context passed to @ref sli_cpc_dispatcher_fnct_t.
  bool submitted;                 ///< submitted
  bool pre;                       ///< true: drained before process_action; false: after process_action
} sli_cpc_dispatcher_handle_t;

/******************************************************************************/
/*                                  Endpoint                                  */
/******************************************************************************/

/**
 * @brief CPC endpoint debug counters.
 */
typedef struct sli_cpc_ep_debug_counters {
  uint32_t rxd_packet;             ///< Number of packet received
  uint32_t rxd_data_frame;         ///< Number of frame with payload (data frame);
  uint32_t rxd_data_frame_dropped; ///< Number of dataframe with data dropped

  uint32_t rxd_ack;           ///< Number of frames with an ACK field received
  uint32_t rxd_ack_processed; ///< Number of ack frame processed
  uint32_t rxd_ack_dropped;   ///< Number of ack frame ignored

  uint32_t rxd_out_of_sequence; ///< Number of frames out of sequence received
  uint32_t rxd_reset;           ///< Number of reset frame received

  uint32_t txd_ack;               ///< Number of ACK supervisory-frame transmitted
  uint32_t txd_re_transmit_frame; ///< Number of data frame retransmitted

  uint32_t txd_submitted; ///< Number of frame submitted to the driver
  uint32_t txd_completed; ///< Number of frame confirmed sent by the driver
} sli_cpc_ep_debug_counters_t;

/**
 * @brief Enumeration representing the possible endpoint state.
 */
typedef enum sli_cpc_ep_state {
  /// Endpoint is closed. In this state, the endpoint is ready to be connected
  /// with sl_cpc_ep_listen() or sl_cpc_ep_connect().
  SLI_CPC_STATE_CLOSED,

  /// Endpoint is in the process of closing. This can be initiated by the user
  /// with sl_cpc_ep_close() or upon receiving a reset frame from the
  /// peer. Once all resources associated with the endpoint are returned,
  /// either to the user for RX/TX buffer handles and TX frames, or to the
  /// bus for RX frames, the endpoint returns to the CLOSED state.
  SLI_CPC_STATE_CLOSING,

  /// Transition to this state when sl_cpc_ep_listen() is called.
  /// Endpoint now waits for a SYN+ACK frame from the peer.
  SLI_CPC_STATE_OPEN,

  /// Transition to this state when endpoint was in @p SLI_CPC_STATE_OPEN
  /// state nd a SYN+ACK frame is received. Endpoint must now responds with
  /// a SYN+ACK of its own.
  SLI_CPC_STATE_SYN_RCVD,

  /// Transition to this state when sl_cpc_ep_connect() is called.
  /// A SYN frame has been sent and the endpoint now waits for a SYN+ACK
  /// frame from the peer.
  SLI_CPC_STATE_SYN_SENT,

  /// Transition to this state from @p SLI_CPC_STATE_SYN_RCVD when an valid ACK
  /// is received; or from @p SLI_CPC_STATE_SYN_SENT when a valid SYN+ACK frame
  /// is received. Endpoint is now connected and can use receive/transmit
  /// functions.
  SLI_CPC_STATE_CONNECTED,
} sli_cpc_ep_state_t;

/******************************************************************************/
/*                                   Header                                   */
/******************************************************************************/

/**
 * @brief CPC data link header structure
 *
 * Fixed-size 8-byte packed structure.
 *
 * Header Layout:
 *     +---------+---------+------+--------+-----+-----+
 *     | size_le | addr_le | ctrl | rx_wnd | seq | ack |
 *     |  u8[2]  |  u8[2]  |  u8  |   u8   | u8  | u8  |
 *     +---------+---------+------+--------+-----+-----+
 *
 * Control byte (bits):
 *     +---+---+---+---+---+---+---+---+
 *     | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 *     +---+---+---+---+---+---+---+---+
 *     |rsv|rst|ack|syn|   reserved    |
 *     +---+---+-----------------------+
 *     - Bit 7: Reserved
 *     - Bit 6: Reset
 *     - Bit 5: Request ACK
 *     - Bit 4: SYN
 *     - Bits [3..0]: Reserved for future use
 */
typedef struct sli_cpc_hdr {
  uint8_t size_le[2];
  uint8_t addr_le[2];
  uint8_t ctrl;
  uint8_t rx_wnd;
  uint8_t seq;
  uint8_t ack;
} sli_cpc_hdr_t;

/******************************************************************************/
/*                                    List                                    */
/******************************************************************************/

/**
 * @brief Singly-linked list structure.
 */
struct sli_cpc_list {
  /// List head.
  sl_slist_node_t *head;
  /// List tail.
  sl_slist_node_t *tail;
  /// List length.
  uint32_t len;
};

/**
 * @brief Endpoint frame list (uses @ref sli_cpc_frame::ep_node).
 *
 * Endpoint-level lists (re_transmit_list, holding_list) use a dedicated node
 * so that a frame can simultaneously sit on a bus-level list (via bus_node)
 * and an endpoint list (via ep_node).
 */
typedef struct sli_cpc_list sli_cpc_ep_frame_list_t;

/**
 * @brief CPC frame list (uses @ref sli_cpc_frame::bus_node).
 *
 * Frames can be on exactly one such list at a time via their
 * @ref sli_cpc_frame::bus_node.
 */
typedef struct sli_cpc_list sli_cpc_frame_list_t;

/******************************************************************************/
/*                                  Control                                   */
/******************************************************************************/

#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
typedef enum sli_cpc_control_primary_state {
  SLI_CPC_CONTROL_PRIMARY_STATE_IDLE = 0,
  SLI_CPC_CONTROL_PRIMARY_STATE_PROTOCOL_VERSION,
  SLI_CPC_CONTROL_PRIMARY_STATE_RESET_REASON,
  SLI_CPC_CONTROL_PRIMARY_STATE_PHY_CAPABILITIES,
  SLI_CPC_CONTROL_PRIMARY_STATE_BUS_ENABLE,
  SLI_CPC_CONTROL_PRIMARY_STATE_INITIALIZED,
} sli_cpc_control_primary_state_t;

/** @brief Primary control endpoint context. */
typedef struct sli_cpc_control_primary {
  sli_cpc_control_primary_state_t state;
  uint16_t expected_response_op_id;
} sli_cpc_control_primary_t;
#endif

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_TYPES_H
