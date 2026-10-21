/***************************************************************************/ /**
 * @file sli_cpc_debug.h
 * @brief CPC SystemView header file
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

#ifndef SLI_CPC_DEBUG_H
#define SLI_CPC_DEBUG_H

#include <string.h>

#include "sl_component_catalog.h"
#include "sl_cpc_config.h"

#include "sli_cpc_types.h"

#if (SL_CPC_DEBUG_SYSTEM_VIEW_LOG_CORE_EVENT == 1) || (SL_CPC_DEBUG_SYSTEM_VIEW_LOG_EP_EVENT == 1)
#include "SEGGER_SYSVIEW.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if ((SL_CPC_DEBUG_SYSTEM_VIEW_LOG_CORE_EVENT == 1) || (SL_CPC_DEBUG_SYSTEM_VIEW_LOG_EP_EVENT == 1) \
     || (SL_CPC_DEBUG_CORE_EVENT_COUNTERS == 1) || (SL_CPC_DEBUG_EP_EVENT_COUNTERS == 1))
#define CPC_DEBUG_TRACE
#endif

/********************************************************************************
******************************* Core Trace Macros ******************************
********************************************************************************/

#define SLI_CPC_DEBUG_TRACE_CORE_OPEN_EP(bus)       \
  do {                                              \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, ep_opened); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(OPEN_EP);    \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_FREE_EP(bus)      \
  do {                                             \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, ep_freed); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(FREE_EP);   \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_RXD_FRAME(bus)     \
  do {                                              \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, rxd_frame); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(RX_FRAME);   \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_RXD_VALID_RELIABLE_FRAME(bus)     \
  do {                                                             \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, rxd_valid_reliable_frame); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(RXD_VALID_RELIABLE_FRAME);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_RXD_VALID_UNRELIABLE_FRAME(bus)     \
  do {                                                               \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, rxd_valid_unreliable_frame); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(RXD_VALID_UNRELIABLE_FRAME);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_RXD_VALID_SYN_FRAME(bus)     \
  do {                                                        \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, rxd_valid_syn_frame); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(RXD_VALID_SYN_FRAME);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_RXD_DATA_FRAME_DROPPED(bus)     \
  do {                                                           \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, rxd_data_frame_dropped); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(RXD_DATA_FRAME_DROPPED);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_TXD_RESET(bus)     \
  do {                                              \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, txd_reset); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(TXD_reset);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_TXD_TRANSMIT_COMPLETED(bus)    \
  do {                                                          \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, txd_completed);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(TXD_TRANSMIT_COMPLETED); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_RE_TRANSMIT_FRAME(bus) \
  do {                                                  \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, retxd_frame);   \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(RETRANSMIT);     \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_DRIVER_ERROR(bus)         \
  do {                                                     \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, driver_error);     \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(DRIVER_READ_ERROR); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_DRIVER_PACKET_DROPPED(bus)     \
  do {                                                          \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, driver_packet_dropped); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(DRIVER_PACKET_DROPPED);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_INVALID_HEADER_CHECKSUM(bus)     \
  do {                                                            \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, invalid_header_checksum); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(INVALID_HEADER_CHECKSUM);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_INVALID_PAYLOAD_CHECKSUM(bus)     \
  do {                                                             \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, invalid_payload_checksum); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(INVALID_PAYLOAD_CHECKSUM);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_TXD_RESET_FRAME_FAULT(bus)     \
  do {                                                          \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, txd_reset_frame_fault); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(TXD_RESET_FRAME_FAULT);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_TXD_SYN_FAULT(bus)     \
  do {                                                  \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, txd_syn_fault); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(TXD_SYN_FAULT);  \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_CORE_TXD_RX_WINDOW_UPDATE_FAULT(bus)     \
  do {                                                               \
    SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, txd_rx_window_update_fault); \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(TXD_RX_WINDOW_UPDATE_FAULT);  \
  } while (0)

/********************************************************************************
*************************** Endpoint Trace Macros ******************************
********************************************************************************/

#define SLI_CPC_DEBUG_TRACE_EP_RXD_FRAME(ep)             \
  do {                                                   \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_packet);        \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_FRAME, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_RXD_DATA_FRAME(ep)             \
  do {                                                        \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_data_frame);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_DATA_FRAME, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_RXD_DATA_FRAME_DROPPED(ep)             \
  do {                                                                \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_data_frame_dropped);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_DATA_FRAME_DROPPED, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_RXD_ACK(ep)             \
  do {                                                 \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_ack);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_ACK, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_RXD_ACK_PROCESSED(ep)             \
  do {                                                           \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_ack_processed);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_ACK_PROCESSED, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_RXD_ACK_DROPPED(ep)             \
  do {                                                         \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_ack_dropped);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_ACK_DROPPED, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_RXD_OUT_OF_SEQ_FRAME(ep)       \
  do {                                                        \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_out_of_sequence);    \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_OUT_OF_SEQ, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_RXD_RESET(ep)             \
  do {                                                   \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, rxd_reset);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(RXD_RESET, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_TXD_ACK(ep)             \
  do {                                                 \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, txd_ack);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(TXD_ACK, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_TXD_RE_TRANSMIT_FRAME(ep)             \
  do {                                                               \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, txd_re_transmit_frame);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(TXD_RE_TRANSMIT_FRAME, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_TXD_SUBMITTED(ep)             \
  do {                                                       \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, txd_submitted);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(TXD_SUBMITTED, ep->id); \
  } while (0)

#define SLI_CPC_DEBUG_TRACE_EP_TXD_COMPLETED(ep)             \
  do {                                                       \
    SLI_CPC_DEBUG_EP_COUNTER_INC(ep, txd_completed);         \
    SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(TXD_COMPLETED, ep->id); \
  } while (0)

// DEBUG EVENTS COUNTERS ON CORE
#if (SL_CPC_DEBUG_CORE_EVENT_COUNTERS == 1)
#define SLI_CPC_DEBUG_CORE_INIT(bus) (memset(&(bus)->debug.counters, 0, sizeof((bus)->debug.counters)))
#define SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, counter) (((bus)->debug.counters.counter)++)
#else // SL_CPC_DEBUG_CORE_EVENT_COUNTERS
#define SLI_CPC_DEBUG_CORE_INIT(bus)
#define SLI_CPC_DEBUG_CORE_COUNTER_INC(bus, counter)
#endif // SL_CPC_DEBUG_CORE_EVENT_COUNTERS

// DEBUG EVENTS COUNTERS ON ENDPOINT
#if (SL_CPC_DEBUG_EP_EVENT_COUNTERS == 1)
#define SLI_CPC_DEBUG_EP_INIT(ep) (memset(&ep->debug_counters, 0, sizeof(ep->debug_counters)))
#define SLI_CPC_DEBUG_EP_COUNTER_INC(ep, counter) ((ep->debug_counters.counter)++)
#else // SL_CPC_DEBUG_EP_EVENT_COUNTERS
#define SLI_CPC_DEBUG_EP_INIT(ep)
#define SLI_CPC_DEBUG_EP_COUNTER_INC(ep, counter)
#endif // SL_CPC_DEBUG_EP_EVENT_COUNTERS

// CORE EVENT ID
#if !defined(SLI_CPC_SYSVIEW_CORE_EVENT_ID)
#define SLI_CPC_SYSVIEW_CORE_EVENT_ID 9999
#endif

// ENDPOINT ID and MULTIPLICATOR
#if !defined(CPC_CORE_EVENT_ID_MULTIPLIER)
#define CPC_EP_EVENT_ID_OFFSET 10000
#endif
#if !defined(CPC_CORE_EVENT_ID_MULTIPLIER)
#define CPC_EP_EVENT_ID_MULTIPLIER 1000
#endif

// SYSTEMVIEW TRACE MACRO
#define SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(event)
#define SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(event, ep)
#if (SL_CPC_DEBUG_SYSTEM_VIEW_LOG_CORE_EVENT == 1)
#undef SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE
#define SLI_CPC_SYSVIEW_MARK_EVENT_ON_CORE(event) \
  SEGGER_SYSVIEW_NameMarker(SLI_CPC_SYSVIEW_CORE_EVENT_ID, SLI_CPC_SYSVIEW_ON_CORE_##event##_MESSAGE)
#endif

#if (SL_CPC_DEBUG_SYSTEM_VIEW_LOG_EP_EVENT == 1)
#undef SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP
#define SLI_CPC_SYSVIEW_MARK_EVENT_ON_EP(event, ep)                        \
  SEGGER_SYSVIEW_NameMarker(SLI_CPC_SYSVIEW_ON_EP_##event##_EVENT_ID + ep, \
                            SLI_CPC_SYSVIEW_ON_EP_##event##_EVENT_MESSAGE)
#endif

#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)

#define ON_EP_STR_MESSAGE(EVENT, NRB, MULTIPLER) \
  "CPC: " EVENT " [EP ID = MarkerID - (" STR(NRB) " * " STR(MULTIPLER) ")]"

// SYSTEMVIEW; CORE MESSAGE
#define SLI_CPC_SYSVIEW_ON_CORE_OPEN_EP_MESSAGE "CPC: Listen/Connect endpoint"
#define SLI_CPC_SYSVIEW_ON_CORE_FREE_EP_MESSAGE "CPC: Free endpoint"
#define SLI_CPC_SYSVIEW_ON_CORE_RX_FRAME_MESSAGE "CPC: Receive Frame"
#define SLI_CPC_SYSVIEW_ON_CORE_RXD_VALID_RELIABLE_FRAME_MESSAGE "CPC: Valid reliable frame received"
#define SLI_CPC_SYSVIEW_ON_CORE_RXD_VALID_UNRELIABLE_FRAME_MESSAGE "CPC: Valid unreliable frame received"
#define SLI_CPC_SYSVIEW_ON_CORE_RXD_VALID_SYN_FRAME_MESSAGE "CPC: Valid syn frame received"
#define SLI_CPC_SYSVIEW_ON_CORE_RXD_DATA_FRAME_DROPPED_MESSAGE "CPC: Data frame dropped"
#define SLI_CPC_SYSVIEW_ON_CORE_TXD_RESET "CPC: Transmit reset"
#define SLI_CPC_SYSVIEW_ON_CORE_TXD_TRANSMIT_COMPLETED_MESSAGE "CPC: Transmit completed"
#define SLI_CPC_SYSVIEW_ON_CORE_RETRANSMIT_MESSAGE "CPC: Frame re-transmitted"
#define SLI_CPC_SYSVIEW_ON_CORE_DRIVER_READ_ERROR_MESSAGE "CPC: Driver reported an error"
#define SLI_CPC_SYSVIEW_ON_CORE_DRIVER_PACKET_DROPPED_MESSAGE "CPC: Driver dropped a packet"
#define SLI_CPC_SYSVIEW_ON_CORE_INVALID_HEADER_CHECKSUM_MESSAGE "CPC: Invalid checksum in protocol header"
#define SLI_CPC_SYSVIEW_ON_CORE_INVALID_PAYLOAD_CHECKSUM_MESSAGE "CPC: Invalid checksum on payload"
#define SLI_CPC_SYSVIEW_ON_CORE_TXD_RESET_FRAME_FAULT_MESSAGE "CPC: Failed to send RST frame"
#define SLI_CPC_SYSVIEW_ON_CORE_TXD_SYN_FAULT_MESSAGE "CPC: Failed to send SYN frame"
#define SLI_CPC_SYSVIEW_ON_CORE_TXD_RX_WINDOW_UPDATE_FAULT_MESSAGE "CPC: Failed to send RX window update"

// SYSTEMVIEW; ENDPOINT EVENT IDs and MESSAGES
#define SLI_CPC_SYSVIEW_ON_EP_RXD_FRAME_EVENT_NBR 1
#define SLI_CPC_SYSVIEW_ON_EP_RXD_FRAME_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_FRAME_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_FRAME_EVENT_ID (SLI_CPC_SYSVIEW_ON_EP_RXD_FRAME_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_FRAME_EVENT_MESSAGE \
  ON_EP_STR_MESSAGE("Received frame", SLI_CPC_SYSVIEW_ON_EP_RXD_FRAME_EVENT_NBR, CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_EVENT_NBR 2
#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_EVENT_MESSAGE \
  ON_EP_STR_MESSAGE("Received Data frame", SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_EVENT_NBR, CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_DROPPED_EVENT_NBR 4
#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_DROPPED_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_DROPPED_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_DROPPED_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_DROPPED_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_DROPPED_EVENT_MESSAGE                                            \
  ON_EP_STR_MESSAGE("Received data has been dropped", SLI_CPC_SYSVIEW_ON_EP_RXD_DATA_FRAME_DROPPED_EVENT_NBR, \
                    CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_EVENT_NBR 5
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_EVENT_ID (SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_EVENT_MESSAGE \
  ON_EP_STR_MESSAGE("Received ack", SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_EVENT_NBR, CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_PROCESSED_EVENT_NBR 6
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_PROCESSED_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_PROCESSED_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_PROCESSED_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_PROCESSED_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_PROCESSED_EVENT_MESSAGE                                             \
  ON_EP_STR_MESSAGE("Received ack has been processed", SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_PROCESSED_EVENT_NBR, \
                    CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_DROPPED_EVENT_NBR 7
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_DROPPED_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_DROPPED_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_DROPPED_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_DROPPED_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_DROPPED_EVENT_MESSAGE                                           \
  ON_EP_STR_MESSAGE("Received ack has been dropped", SLI_CPC_SYSVIEW_ON_EP_RXD_ACK_DROPPED_EVENT_NBR, \
                    CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_RXD_OUT_OF_SEQ_EVENT_NBR 8
#define SLI_CPC_SYSVIEW_ON_EP_RXD_OUT_OF_SEQ_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_OUT_OF_SEQ_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_OUT_OF_SEQ_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_OUT_OF_SEQ_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_OUT_OF_SEQ_EVENT_MESSAGE                                            \
  ON_EP_STR_MESSAGE("Received out of sequence frame", SLI_CPC_SYSVIEW_ON_EP_RXD_OUT_OF_SEQ_EVENT_NBR, \
                    CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_RXD_RESET_EVENT_NBR 9
#define SLI_CPC_SYSVIEW_ON_EP_RXD_RESET_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_RXD_RESET_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_RESET_EVENT_ID (SLI_CPC_SYSVIEW_ON_EP_RXD_RESET_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_RXD_RESET_EVENT_MESSAGE \
  ON_EP_STR_MESSAGE("Received reset frame", SLI_CPC_SYSVIEW_ON_EP_RXD_RESET_EVENT_NBR, CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_TXD_ACK_EVENT_NBR 10
#define SLI_CPC_SYSVIEW_ON_EP_TXD_ACK_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_TXD_ACK_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_ACK_EVENT_ID (SLI_CPC_SYSVIEW_ON_EP_TXD_ACK_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_ACK_EVENT_MESSAGE \
  ON_EP_STR_MESSAGE("Transmitted ack", SLI_CPC_SYSVIEW_ON_EP_TXD_ACK_EVENT_NBR, CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_TXD_RE_TRANSMIT_FRAME_EVENT_NBR 11
#define SLI_CPC_SYSVIEW_ON_EP_TXD_RE_TRANSMIT_FRAME_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_TXD_RE_TRANSMIT_FRAME_EVENT_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_RE_TRANSMIT_FRAME_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_TXD_RE_TRANSMIT_FRAME_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_RE_TRANSMIT_FRAME_EVENT_MESSAGE                                      \
  ON_EP_STR_MESSAGE("Retransmitted data frame", SLI_CPC_SYSVIEW_ON_EP_TXD_RE_TRANSMIT_FRAME_EVENT_NBR, \
                    CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_TXD_SUBMITTED_NBR 12
#define SLI_CPC_SYSVIEW_ON_EP_TXD_SUBMITTED_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_TXD_SUBMITTED_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_SUBMITTED_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_TXD_SUBMITTED_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_SUBMITTED_EVENT_MESSAGE                                        \
  ON_EP_STR_MESSAGE("Frame submitted for transmission", SLI_CPC_SYSVIEW_ON_EP_TXD_SUBMITTED_NBR, \
                    CPC_EP_EVENT_ID_MULTIPLIER)

#define SLI_CPC_SYSVIEW_ON_EP_TXD_COMPLETED_NBR 13
#define SLI_CPC_SYSVIEW_ON_EP_TXD_COMPLETED_EVENT_MARKER \
  (SLI_CPC_SYSVIEW_ON_EP_TXD_COMPLETED_NBR * CPC_EP_EVENT_ID_MULTIPLIER)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_COMPLETED_EVENT_ID \
  (SLI_CPC_SYSVIEW_ON_EP_TXD_COMPLETED_EVENT_MARKER + CPC_EP_EVENT_ID_OFFSET)
#define SLI_CPC_SYSVIEW_ON_EP_TXD_COMPLETED_EVENT_MESSAGE \
  ON_EP_STR_MESSAGE("Transmit completed", SLI_CPC_SYSVIEW_ON_EP_TXD_COMPLETED_NBR, CPC_EP_EVENT_ID_MULTIPLIER)

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_DEBUG_H
