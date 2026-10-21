/***************************************************************************/ /**
 * @file
 * @brief CPC public endpoint API.
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

#ifndef SL_CPC_EP_H
#define SL_CPC_EP_H

#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>

#include "sl_component_catalog.h"
#include "sl_cpc_config.h"
#include "sl_slist.h"
#include "sl_status.h"

#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "cmsis_os2.h"
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
#include "sl_cmsis_os2_common.h"
#endif
#endif

#include "sl_cpc_frame.h"
#include "sl_cpc_msgq.h"

#include "sli_cpc_timer_types.h"
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

typedef struct sl_cpc_bus sl_cpc_bus_t;

typedef struct sl_cpc_ep sl_cpc_ep_t;

/// Maximum CPC application payload size, in bytes.
#define SL_CPC_EP_MAX_PAYLOAD_SIZE 4096U

/// Endpoint ID reserved for the CPC control endpoint.
#define SL_CPC_EP_ID_CONTROL 0U

/// Endpoint events delivered to @ref sl_cpc_ep_event_cb_t.
typedef enum sl_cpc_ep_event_type {
  SL_CPC_EP_EVENT_RECV,      ///< Data received.
  SL_CPC_EP_EVENT_SEND_DONE, ///< Transmission completed (acknowledged or aborted).
  SL_CPC_EP_EVENT_CONNECTED, ///< Endpoint connected.
  SL_CPC_EP_EVENT_CLOSED,    ///< Endpoint closed; resources have been returned.
  SL_CPC_EP_EVENT_ERROR,     ///< Fatal error on the endpoint.
} sl_cpc_ep_event_type_t;

/**
 * @brief Error payload for @ref SL_CPC_EP_EVENT_ERROR.
 */
typedef struct sl_cpc_ep_event_error {
  sl_status_t status; ///< Error status.
} sl_cpc_ep_event_error_t;

/**
 * @brief Receive payload for @ref SL_CPC_EP_EVENT_RECV.
 */
typedef struct sl_cpc_ep_event_recv {
  sl_cpc_buf_t *buf; ///< Buffer with the received payload.
} sl_cpc_ep_event_recv_t;

/**
 * @brief Send-done payload for @ref SL_CPC_EP_EVENT_SEND_DONE.
 */
typedef struct sl_cpc_ep_event_send_done {
  sl_cpc_buf_t *buf;     ///< Buffer that finished transmission.
  sl_cpc_frame_t *frame; ///< Send context from @ref sl_cpc_ep_send.
  sl_status_t status;    ///< Transmission status.
  void *arg;             ///< @p arg passed to @ref sl_cpc_ep_send.
} sl_cpc_ep_event_send_done_t;

/**
 * @brief Event-specific data for @ref sl_cpc_ep_event_cb_t.
 */
typedef union sl_cpc_ep_event {
  sl_cpc_ep_event_error_t error;
  sl_cpc_ep_event_recv_t recv;
  sl_cpc_ep_event_send_done_t send_done;
} sl_cpc_ep_event_t;

/***************************************************************************/ /**
 * Endpoint event callback.
 *
 * All endpoint events are delivered here. Use @p event_type to select which
 * fields of @p event are valid. Runs in CPC's execution context: do minimal
 * work, do not block, and hand the event off to the application if needed.
 *
 * @param ep         Endpoint that produced the event.
 * @param event_type Event that occurred.
 * @param event      Event-specific data; valid only for this call.
 * @param arg        User argument from @ref sl_cpc_ep_init.
 ******************************************************************************/
typedef void(sl_cpc_ep_event_cb_t)(sl_cpc_ep_t *ep, sl_cpc_ep_event_type_t event_type, const sl_cpc_ep_event_t *event,
                                   void *arg);

/**
 * @brief CPC endpoint.
 *
 * Bidirectional communication channel on a bus.
 */
typedef struct sl_cpc_ep {
  sl_slist_node_t node; ///< node
  uint8_t id;           ///< id
  uint8_t flags;        ///< flags

  /// Send next, the next sequence number that will be used for transmission
  /// Used to keep track of unacknowledged frames and frame sequence allowed
  /// for transmission
  uint8_t send_nxt;

  /// Send Unacknowledged, the oldest unacknowledged sequence number
  uint8_t send_una;

  /// Send window, maximum number of frames that the remote can accept
  /// TX frames should have a sequence in the range [send_una; send_una + send_wnd)
  uint8_t send_wnd;

  /// In order to avoid bloating frames with a uint64_t, the RTT is measured
  /// only once "per window" and variables used for this measurement are kept
  /// in the endpoint. To keep track of the frame used for RTT, the endpoint
  /// keeps the sequence number of the frame as well as the timestamp at which
  /// it was sent.
  uint8_t rtt_frame_seq;

  /// Timestamp at which the frame with sequence `rtt_frame_seq` was sent.
  uint64_t rtt_sent_ticks;

  /// Max payload length this endpoint is able to receive.
  uint16_t mtu;

  /// Maximum payload length the remote endpoint is able to receive.
  uint16_t remote_mtu;

  uint8_t ack;                       ///< ack
  uint8_t packet_re_transmit_count;  ///< packet re transmit count
  uint32_t re_transmit_timeout;      ///< re transmit timeout
  uint64_t smoothed_rtt;             ///< smoothed rtt
  uint64_t rtt_variation;            ///< rtt variation
  sli_cpc_timer_t re_transmit_timer; ///< re transmit timer
  sli_cpc_ep_state_t state;          ///< state

  struct {
    uint32_t timeout; ///< window probe schedule timeout
    uint8_t count;    ///< window probes sent while still blocked
  } wnd_probe;

  /// Usage counter of the endpoint. This is used to guarantee that the
  /// endpoint is not going away while some objects have a reference to it.
  ///   - TX frames take a reference to the endpoint when transmitted
  ///     (no matter if they come from the application or from CPC itself).
  ///     This reference is dropped when the transmission completes, or
  ///     when the TX frame and buffer are passed back to the application.
  ///     This ensures that the ep->event_cb refers to a valid endpoint
  ///     pointer.
  ///   - RX frames take a reference in the drivers. frame->ep either points
  ///     to NULL or to a valid endpoint pointer. This ensures that when the
  ///     RX frame is processed in CPC's loop, the endpoint is still valid.
  ///     This reference is dropped when CPC is done with the frame if
  ///     the frame doesn't have a payload, or when the application gets
  ///     the frame if it has a payload. Note that the endpoint's state can
  ///     still change between the reception by the driver and the processing
  ///     of that frame by CPC's loop.
  ///   - @ref sl_cpc_ep_listen / @ref sl_cpc_ep_connect take a reference when
  ///     the endpoint is added to the bus list so drivers always see list
  ///     members with ref_cnt >= 1. That reference is dropped in
  ///     @ref sl_cpc_ep_close, or in @ref sl_cpc_ep_deinit if open never
  ///     succeeded.
  ///   - public open APIs also set @c SLI_CPC_EP_FLAG_OPENED (immediately, or
  ///     when a deferred open is pending); closing then drops the list
  ///     reference taken above.
  ///
  /// When all references are dropped, the endpoint is considered closed and
  /// the event callback is called to notify the application. After that, the
  /// endpoint can be freed or reused for another connection.
  uint16_t ref_cnt;

  sl_cpc_ep_event_cb_t *event_cb;           ///< unified endpoint event callback
  void *event_cb_arg;                       ///< Opaque user context passed to @ref event_cb.
  sli_cpc_ep_frame_list_t re_transmit_list; ///< re-transmit list
  sli_cpc_ep_frame_list_t holding_list;     ///< holding list
  sl_cpc_msgq_t rx_buffer_queue;            ///< reception buffer queue
#if (SL_CPC_DEBUG_EP_EVENT_COUNTERS == 1)
  sli_cpc_ep_debug_counters_t debug_counters;
#endif
#if defined(SL_CATALOG_KERNEL_PRESENT)
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
  alignas(4) uint8_t lock_cb[osMutexCbSize]; ///< lock cb
#endif
  osMutexId_t lock;                   ///< lock
  osSemaphoreId_t state_event_signal; ///< endpoint state has changed
#endif
#if defined(SL_CATALOG_CPC_SECURITY_PRESENT)
  uint32_t frame_counter_rx;
  uint32_t frame_counter_tx;
  bool encrypted;
  bool packets_held_for_security;
#endif

  sl_cpc_bus_t *bus;
} sl_cpc_ep_t;

/******************************************************************************/
/*                                    APIs                                    */
/******************************************************************************/

/***************************************************************************/ /**
 * Initialize an endpoint.
 *
 * After this returns, receive buffers may be queued with
 * @ref sl_cpc_ep_push_recv_buf. @p rx_size is the largest payload this endpoint
 * can receive; buffers pushed for RX must be at least that size. If buffers are
 * larger than that size, that extra space will be wasted as CPC won't be able to
 * use it.
 *
 * Re-initializing an already initialized endpoint is undefined behavior.
 *
 * @param[in] ep      Endpoint to initialize.
 * @param[in] id      Endpoint ID shared with the remote side.
 * @param[in] rx_size Maximum receive payload size; must be a multiple of
 *                    @ref SL_CPC_BUF_MIN_ALIGNMENT.
 * @param[in] cb      Event callback.
 * @param[in] cb_arg  User argument passed to @p cb. May be @c NULL.
 *
 * @retval SL_STATUS_OK           Endpoint initialized successfully.
 * @retval SL_STATUS_NULL_POINTER @p cb is NULL.
 * @retval Other                  An error occurred.
 ******************************************************************************/
sl_status_t sl_cpc_ep_init(sl_cpc_ep_t *ep, uint8_t id, uint16_t rx_size, sl_cpc_ep_event_cb_t *cb, void *cb_arg);

/***************************************************************************/ /**
 * Deinitialize an endpoint.
 *
 * The endpoint must have been closed with @ref sl_cpc_ep_close, or never have
 * successfully called @ref sl_cpc_ep_listen / @ref sl_cpc_ep_connect.
 *
 * @param[in] ep Endpoint to deinitialize.
 ******************************************************************************/
void sl_cpc_ep_deinit(sl_cpc_ep_t *ep);

/***************************************************************************/ /**
 * Get an endpoint's ID.
 *
 * @param[in] ep Endpoint to query.
 *
 * @return Endpoint ID.
 ******************************************************************************/
uint8_t sl_cpc_ep_get_id(const sl_cpc_ep_t *ep);

/***************************************************************************/ /**
 * Add a buffer (or buffer chain) to the endpoint's receive pool.
 *
 * @p buf can be a single buffer or a buffer chain. All elements in the chain
 * must have pointers aligned on @ref SL_CPC_BUF_MIN_ALIGNMENT. This function
 * sets the length of each buffer in the chain to the `rx_size` value that was
 * configured by @ref sl_cpc_ep_init. The caller is responsible for not passing
 * buffers smaller than this value. Buffers can have a larger underlying
 * storage than `rx_size` but this extra space will never be used by CPC.
 *
 * @param[in] ep   Endpoint that will receive into @p buf.
 * @param[in] buf  Buffer, or chain of buffers, available for reception.
 *
 * @retval SL_STATUS_OK                Buffer queued successfully.
 * @retval SL_STATUS_NULL_POINTER      @p buf or @p buf->ptr is NULL.
 * @retval SL_STATUS_INVALID_PARAMETER Buffer is not correctly aligned.
 * @retval SL_STATUS_NOT_AVAILABLE     Endpoint has no configured MTU.
 ******************************************************************************/
sl_status_t sl_cpc_ep_push_recv_buf(sl_cpc_ep_t *ep, sl_cpc_buf_t *buf);

/***************************************************************************/ /**
 * Pop a single reception buffer from endpoint's receive pool.
 *
 * If a buffer chain was pushed with @ref sl_cpc_ep_push_recv_buf, this
 * function must be called once for each element that was part of the chain to
 * pop all buffers.
 *
 * Can only be called when the endpoint is closed.
 *
 * @param[in]  ep      Endpoint whose RX pool to pop from.
 * @param[out] out_buf Set to the popped buffer on success.
 *
 * @retval SL_STATUS_OK               Buffer popped successfully.
 * @retval SL_STATUS_NO_MORE_RESOURCE Endpoint has no available RX buffer.
 * @retval SL_STATUS_INVALID_STATE    Endpoint is not closed.
 ******************************************************************************/
sl_status_t sl_cpc_ep_pop_recv_buf(sl_cpc_ep_t *ep, sl_cpc_buf_t **out_buf);

/***************************************************************************/ /**
 * Listen for an incoming connection on an endpoint.
 *
 * @param[in] ep  Endpoint that will accept the connection.
 * @param[in] bus Bus the endpoint belongs to.
 *
 * @retval SL_STATUS_OK                    Listen started successfully.
 * @retval SL_STATUS_NULL_POINTER          @p bus is NULL.
 * @retval SL_STATUS_INVALID_STATE         Endpoint is not in a valid state to listen.
 * @retval SL_STATUS_ALREADY_INITIALIZED   Another endpoint with the same ID is open.
 * @retval SL_STATUS_INVALID_CONFIGURATION Endpoint is not properly configured.
 ******************************************************************************/
sl_status_t sl_cpc_ep_listen(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Connect an endpoint.
 *
 * @param[in] ep  Endpoint that initiates the connection.
 * @param[in] bus Bus the endpoint belongs to.
 *
 * @retval SL_STATUS_OK                    Connect started successfully.
 * @retval SL_STATUS_NULL_POINTER          @p bus is NULL.
 * @retval SL_STATUS_INVALID_STATE         Endpoint is not in a valid state to connect.
 * @retval SL_STATUS_ALREADY_INITIALIZED   Another endpoint with the same ID is open.
 * @retval SL_STATUS_INVALID_CONFIGURATION Endpoint is not properly configured.
 ******************************************************************************/
sl_status_t sl_cpc_ep_connect(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Close an endpoint.
 *
 * Asynchronous; @ref SL_CPC_EP_EVENT_CLOSED is delivered when the endpoint can
 * be reused.
 *
 * @param[in] ep Endpoint to close.
 ******************************************************************************/
void sl_cpc_ep_close(sl_cpc_ep_t *ep);

/***************************************************************************/ /**
 * Queue a buffer or buffer chain for transmission to the endpoint.
 *
 * @p buf and @p frame must remain valid until @ref SL_CPC_EP_EVENT_SEND_DONE.
 * All buffers in the buffer chain must have data pointer aligned on
 * @ref SL_CPC_BUF_MIN_ALIGNMENT. The chain can be constructed with
 * @ref sl_cpc_buf_chain.
 *
 * @param[in] ep    Endpoint to send on.
 * @param[in] buf   Buffer, or chain of buffers, to transmit.
 * @param[in] frame Per-send context used while processing @p buf.
 * @param[in] arg   Returned in @ref SL_CPC_EP_EVENT_SEND_DONE.
 *
 * @retval SL_STATUS_OK Buffer queued successfully.
 * @retval Other        An error occurred.
 ******************************************************************************/
sl_status_t sl_cpc_ep_send(sl_cpc_ep_t *ep, sl_cpc_buf_t *buf, sl_cpc_frame_t *frame, void *arg);

/** @} (end addtogroup cpc) */

#ifdef __cplusplus
}
#endif

#endif // SL_CPC_EP_H
