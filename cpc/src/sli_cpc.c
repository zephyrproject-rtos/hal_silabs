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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "cpc_atomic.h"
#include "sl_bit.h"
#include "sl_common.h"
#include "sl_component_catalog.h"
#include "sl_status.h"
#include "sl_string.h"

#include "sli_cpc.h"
#include "sli_cpc_assert.h"
#include "sli_cpc_atomic.h"
#include "sli_cpc_bus.h"
#include "sli_cpc_control.h"
#include "sli_cpc_debug.h"
#include "sli_cpc_drv.h"
#include "sli_cpc_ep.h"
#include "sli_cpc_frame_list.h"
#include "sli_cpc_hdr.h"
#include "sli_cpc_memory.h"
#include "sli_cpc_panic.h"

#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "cmsis_os2.h"
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
#include "sl_cmsis_os2_common.h"
#endif
#endif

/*******************************************************************************
 *********************************   DEFINES   *********************************
 ******************************************************************************/
#if defined(SL_CATALOG_KERNEL_PRESENT)
#define SLI_CPC_MUTEX_ACQUIRE(mutex, name)                \
  do {                                                    \
    if (osMutexAcquire((mutex), osWaitForever) != osOK) { \
      SLI_CPC_PANIC("Failed to acquire " name);           \
    }                                                     \
  } while (0)

#define SLI_CPC_MUTEX_RELEASE(mutex, name)      \
  do {                                          \
    if (osMutexRelease(mutex) != osOK) {        \
      SLI_CPC_PANIC("Failed to release " name); \
    }                                           \
  } while (0)

#define LOCK_EP_LIST(bus) SLI_CPC_MUTEX_ACQUIRE((bus)->ep_list_lock, "endpoint list lock")
#define RELEASE_EP_LIST(bus) SLI_CPC_MUTEX_RELEASE((bus)->ep_list_lock, "endpoint list lock")
#define LOCK_TRANSMIT_QUEUE(bus) SLI_CPC_MUTEX_ACQUIRE((bus)->transmit_queue_lock, "transmit queue lock")
#define RELEASE_TRANSMIT_QUEUE(bus) SLI_CPC_MUTEX_RELEASE((bus)->transmit_queue_lock, "transmit queue lock")
#define LOCK_EP(ep) SLI_CPC_MUTEX_ACQUIRE((ep)->lock, "endpoint lock")
#define RELEASE_EP(ep) SLI_CPC_MUTEX_RELEASE((ep)->lock, "endpoint lock")
#else
// silence warnings where bus is passed just for locking purpose
#define LOCK_EP_LIST(bus) ((void)bus)
#define RELEASE_EP_LIST(bus) ((void)bus)
#define LOCK_TRANSMIT_QUEUE(bus) ((void)bus)
#define RELEASE_TRANSMIT_QUEUE(bus) ((void)bus)
#define LOCK_EP(ep)
#define RELEASE_EP(ep)
#endif

#if !defined(SLI_CPC_SECURITY_NONCE_FRAME_COUNTER_RESET_VALUE)
#define SLI_CPC_SECURITY_NONCE_FRAME_COUNTER_RESET_VALUE 0
#endif

#define ABS(a) (unsigned)((a) < 0 ? -(a) : (a))

#define SLI_CPC_EP_MAX_TX_QUEUE_LENGTH_DEFAULT 127
#define SLI_CPC_INIT_RE_TRANSMIT_TIMEOUT_MS 100
#define SLI_CPC_MAX_RE_TRANSMIT_TIMEOUT_MS 500
#define SLI_CPC_MAX_WINDOW_PROBE_TIMEOUT_MS 1000
#define SLI_CPC_MIN_RE_TRANSMIT_TIMEOUT_MINIMUM_VARIATION_MS 5
#define SLI_CPC_MIN_RE_TRANSMIT_TIMEOUT_MS 100

/*******************************************************************************
 ***************************  GLOBAL VARIABLES   *******************************
 ******************************************************************************/

#if defined(SL_CATALOG_CPC_NG_PRIMARY_PRESENT)
bool secondary_protocol_version_mismatch = false;
bool secondary_capabilities_mismatch = false;
bool secondary_application_version_mismatch = false;
#endif

/*******************************************************************************
 **************************   LOCAL FUNCTIONS   ********************************
 ******************************************************************************/
// Initialization
static void initialize_ep_counters(sl_cpc_ep_t *ep);

// Endpoint state
static bool is_ep_open(const sl_cpc_ep_t *ep);
static bool is_ep_closed(const sl_cpc_ep_t *ep);
static bool has_ep_deferred_listen(const sl_cpc_ep_t *ep);
static bool is_ep_active(const sl_cpc_ep_t *ep);
static void ep_set_state(sl_cpc_ep_t *ep, sli_cpc_ep_state_t state, bool lock_ep);

// Endpoint lifecycle
static void terminate_ep(sl_cpc_ep_t *ep);
static void ep_set_error(sl_cpc_ep_t *ep, sl_status_t status);
static void process_closed_eps(sl_cpc_bus_t *bus);

// Endpoint notifications
static void move_ep_to_close_list(sl_cpc_ep_t *ep);
static void notify_error(sl_cpc_ep_t *ep, sl_status_t status);
static bool notify_state_change(const sl_cpc_ep_t *ep);
static sl_status_t ep_request_open(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus, bool connect);

// Endpoint queue management
static void clean_tx_queues(sl_cpc_ep_t *ep);
static uint8_t get_ep_rx_buffer_count(const sl_cpc_ep_t *ep);

// Frame validation
static bool frame_has_invalid_flags(sl_cpc_frame_t *frame);
static bool frame_in_send_window(const sl_cpc_ep_t *ep, const sl_cpc_buf_t *buf);

// Frame creation
static sl_cpc_frame_t *get_syn_frame(sl_cpc_ep_t *ep);

// Receive path
static void process_received_frames(sl_cpc_bus_t *bus);
static void receive_frame(sl_cpc_bus_t *bus, sl_cpc_frame_t *frame);
static void reject_invalid_received_frame(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep, uint16_t address);
static bool process_incoming_ack(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep, const sli_cpc_hdr_t *hdr);
static bool process_incoming_payload(sl_cpc_ep_t *ep, const sli_cpc_hdr_t *hdr, sl_cpc_frame_t *frame);
static void receive_syn(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep, sl_cpc_frame_t *frame);
static void receive_reset(sl_cpc_ep_t *ep);
static void receive_ack(sl_cpc_ep_t *ep, const sli_cpc_hdr_t *remote_hdr);
static sl_status_t process_received_data_frame(sl_cpc_frame_t *frame);

// Transmit path
static void transmit_frame(sl_cpc_bus_t *bus, sl_cpc_frame_t *frame, bool signal);
static void process_transmit_queue(sl_cpc_bus_t *bus);
static void process_transmit_complete(sl_cpc_bus_t *bus);
static void submit_write_completion(sl_cpc_frame_t *frame);
static void process_write_completions(sl_cpc_bus_t *bus);

// ACK and window management
static void ep_clear_pend_ack(sl_cpc_ep_t *ep);
static void ep_set_pend_ack(sl_cpc_ep_t *ep);
static void ep_flush_pend_ack(sl_cpc_ep_t *ep);
static void ep_clear_pend_wnd_probe(sl_cpc_ep_t *ep);
static void cancel_scheduled_wnd_probe(sl_cpc_ep_t *ep);
static void sli_compute_window_probe_timeout(sl_cpc_ep_t *ep);
static void schedule_wnd_probe(sl_cpc_ep_t *ep);
static bool ep_needs_wnd_probe(const sl_cpc_ep_t *ep);
static sl_status_t send_ack_frame(sl_cpc_ep_t *ep);
static sl_status_t send_wnd_probe_frame(sl_cpc_ep_t *ep);
static void process_pending_flags(sl_cpc_bus_t *bus);

// Retransmission
static sl_cpc_frame_t *on_frame_retx(sl_cpc_ep_t *ep);
static sl_status_t re_transmit_frame(sl_cpc_ep_t *ep, sl_cpc_frame_t *frame);
static void re_transmit_timeout_callback(sli_cpc_timer_t *timer, void *data);
static void scheduled_wnd_probe_timer_callback(sli_cpc_timer_t *timer, void *data);
static sl_status_t start_retx_timer(sl_cpc_ep_t *ep);
static void stop_retx_timer(sl_cpc_ep_t *ep);

#if defined(SL_CATALOG_CPC_SECURITY_PRESENT)
static void on_state_change(sl_cpc_security_state_t old, sl_cpc_security_state_t new_state);
#endif

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************/ /**
 * Stop bus.
 ******************************************************************************/
void sl_cpc_bus_stop(sl_cpc_bus_t *bus)
{
  SLI_CPC_ASSERT(bus);
  SLI_CPC_ASSERT(bus->ctrl.ops);

  bus->ctrl.ops->deinit(&bus->ctrl);
  bus->initialized = false;
}

/***************************************************************************/ /**
 * Get the ID of an endpoint.
 ******************************************************************************/
uint8_t sl_cpc_ep_get_id(const sl_cpc_ep_t *ep)
{
  SLI_CPC_ASSERT(ep);

  return ep->id;
}

/***************************************************************************/ /**
 * Get a reference to an endpoint. This ensures the endpoint cannot go the
 * CLOSED state while it's being referenced.
 ******************************************************************************/
sl_cpc_ep_t *sli_cpc_ep_get_ref(sl_cpc_ep_t *ep)
{
  // Allow NULL endpoint pointer to make construct like
  //     frame->ep = sli_cpc_ep_get_ref(ep);
  // always valid, no matter if `ep` is NULL or not.
  if (ep) {
    MCU_ATOMIC_SECTION(ep->ref_cnt++;);
  }

  return ep;
}

/***************************************************************************/ /**
 * Drop a reference to an endpoint. Endpoint will go to CLOSED state when all its
 * resources have been released.
 ******************************************************************************/
void sli_cpc_ep_put_ref(sl_cpc_ep_t *ep)
{
  MCU_DECLARE_IRQ_STATE;
  bool closed;

  MCU_ENTER_ATOMIC();

  SLI_CPC_ASSERT(ep->ref_cnt > 0);

  ep->ref_cnt--;
  closed = ep->ref_cnt == 0;

  MCU_EXIT_ATOMIC();

  if (closed) {
    SLI_CPC_ASSERT(ep->state == SLI_CPC_STATE_CLOSING);
    move_ep_to_close_list(ep);
  }
}

/***************************************************************************/ /**
 * Update an endpoint state and call the callback with the proper event
 * if necessary.
 ******************************************************************************/
static void ep_set_state(sl_cpc_ep_t *ep, sli_cpc_ep_state_t state, bool lock_ep)
{
  sli_cpc_ep_state_t prev_state;

  if (lock_ep) {
    LOCK_EP(ep);
  }

  prev_state = ep->state;
  ep->state = state;

  if (lock_ep) {
    RELEASE_EP(ep);
  }

  SLI_CPC_LOG_DEBUG("Endpoint state update: ep=%d, old=%d, new=%d", ep->id, prev_state, state);

  switch (state) {
    case SLI_CPC_STATE_CONNECTED:
      ep->event_cb(ep, SL_CPC_EP_EVENT_CONNECTED, NULL, ep->event_cb_arg);

      break;
    case SLI_CPC_STATE_CLOSED:
      SLI_CPC_ASSERT(prev_state == SLI_CPC_STATE_CLOSING);
      ep->event_cb(ep, SL_CPC_EP_EVENT_CLOSED, NULL, ep->event_cb_arg);

      break;
    default:
      break;
  }
}

/***************************************************************************/ /**
 * Terminate endpoint (This function must be called on a locked endpoint).
 ******************************************************************************/
static void terminate_ep(sl_cpc_ep_t *ep)
{
  sl_cpc_bus_t *bus = ep->bus;

  // The locking pattern is to always lock the endpoint's list first and then
  // endpoints. This pattern must be followed consistently to prevent deadlocks.
  // This function is entered with endpoint locked, so it must be unlocked first.
  RELEASE_EP(ep);

  // removing the endpoint from this list prevents it from further receiving
  // frames, it's essentially similar to disabling the RX path. Some resources
  // belonging to the endpoint might still be used.
  // See comment in sli_cpc_ep_listen() for
  // explanations about this atomic section.
  LOCK_EP_LIST(bus);
  MCU_ATOMIC_SECTION(sli_cpc_bus_remove_ep(bus, ep););
  RELEASE_EP_LIST(bus);

  // Lock back the endpoint.
  LOCK_EP(ep);

  // Endpoint is now in the process of cleaning its queues
  ep_set_state(ep, SLI_CPC_STATE_CLOSING, false);

  // Drop any pending TX frame
  clean_tx_queues(ep);

  // Flush any pending ACK before teardown completes so the peer does not wait
  // through retransmit attempts for an ACK that will never come.
  ep_flush_pend_ack(ep);
}

/***************************************************************************/ /**
 * Mark bus initialized and complete any deferred listen/connect requests.
 ******************************************************************************/
void sli_cpc_bus_notify_initialized(sl_cpc_bus_t *bus)
{
  sl_status_t status;
  sl_cpc_ep_t *next;
  sl_cpc_ep_t *ep;

  SLI_CPC_ASSERT(bus);

  LOCK_EP_LIST(bus);

  SLI_CPC_ASSERT(!bus->initialized);
  bus->initialized = true;

  SLI_CPC_SLIST_FOR_EACH_ENTRY_SAFE(bus->eps, ep, next, sl_cpc_ep_t, node)
  {
    LOCK_EP(ep);
    if (ep->flags & SLI_CPC_EP_FLAG_CONTROL) {
      RELEASE_EP(ep);
      continue;
    }
    if (!(ep->flags & SLI_CPC_EP_FLAG_OPENED)) {
      RELEASE_EP(ep);
      continue;
    }

    SLI_CPC_ASSERT(ep->state == SLI_CPC_STATE_CLOSED);

    if (ep->flags & SLI_CPC_EP_FLAG_CONNECT) {
      status = sli_cpc_ep_connect(ep);
    } else {
      status = sli_cpc_ep_listen(ep);
    }

    if (status != SL_STATUS_OK) {
      notify_error(ep, status);
    }
    RELEASE_EP(ep);
  }

  RELEASE_EP_LIST(bus);
}

/***************************************************************************/ /**
 * Terminate every endpoint on the bus.
 ******************************************************************************/
void sli_cpc_bus_terminate_endpoints(sl_cpc_bus_t *bus)
{
  sl_cpc_ep_t *next;
  sl_cpc_ep_t *ep;

  SLI_CPC_ASSERT(bus);

  LOCK_EP_LIST(bus);
  SLI_CPC_SLIST_FOR_EACH_ENTRY_SAFE(bus->eps, ep, next, sl_cpc_ep_t, node)
  {
    LOCK_EP(ep);
    ep_set_error(ep, SL_STATUS_ABORT);
    RELEASE_EP(ep);
  }
  RELEASE_EP_LIST(bus);
}

/***************************************************************************/ /**
 * Close an endpoint
 ******************************************************************************/
void sl_cpc_ep_close(sl_cpc_ep_t *ep)
{
  SLI_CPC_ASSERT(ep);

  LOCK_EP(ep);

  if (!(ep->flags & SLI_CPC_EP_FLAG_OPENED) || ep->ref_cnt == 0) {
    RELEASE_EP(ep);
    return;
  }

  ep->flags &= ~SLI_CPC_EP_FLAG_OPENED;

  // endpoint might already be closing from a RST frame, so terminate it
  // only if it's not already terminated. Deferred opens remain CLOSED while
  // still on the bus list.
  if (ep->state != SLI_CPC_STATE_CLOSING) {
    terminate_ep(ep);
  }

  RELEASE_EP(ep);
  sli_cpc_ep_put_ref(ep);
}

/***************************************************************************/ /**
 * Checks if an endpoint is open
 ******************************************************************************/
static inline bool is_ep_open(const sl_cpc_ep_t *ep)
{
  return ep->state == SLI_CPC_STATE_OPEN;
}

/***************************************************************************/ /**
 * Checks if an endpoint is in an activate state (connecting or connected)
 ******************************************************************************/
static inline bool is_ep_active(const sl_cpc_ep_t *ep)
{
  return ep->state == SLI_CPC_STATE_SYN_RCVD || ep->state == SLI_CPC_STATE_SYN_SENT
         || ep->state == SLI_CPC_STATE_CONNECTED;
}

/***************************************************************************/ /**
 * Set endpoint to error state. User will be notified by the on_error callback.
 *
 * @note Caller must hold the endpoint lock.
 ******************************************************************************/
static void ep_set_error(sl_cpc_ep_t *ep, sl_status_t status)
{
  if (is_ep_active(ep)) {
    notify_error(ep, status);
    terminate_ep(ep);
  }
}

/***************************************************************************/ /**
 * Calculate the re transmit timeout
 * Implemented using Karn's algorithm
 * Based off of RFC 2988 Computing TCP's Retransmission Timer
 ******************************************************************************/
static void sli_compute_re_transmit_timeout(sl_cpc_ep_t *ep)
{
  // Implemented using Karn's algorithm
  // Based off of RFC 2988 Computing TCP's Retransmission Timer
  bool first_rtt_measurement = ep->smoothed_rtt == 0 && ep->rtt_variation == 0;

  uint64_t round_trip_time = 0;
  uint64_t rto = 0;
  uint64_t delta = 0;

  const unsigned k = 4; // This value is recommended by the Karn's algorithm

  SLI_CPC_ASSERT(ep != NULL);

  round_trip_time = sli_cpc_timer_get_tick_count64() - ep->rtt_sent_ticks;

  if (first_rtt_measurement) {
    ep->smoothed_rtt = round_trip_time;
    ep->rtt_variation = round_trip_time / 2;
  } else {
    // RTTVAR <- (1 - beta) * RTTVAR + beta * |SRTT - R'| where beta is 0.25
    delta = ABS((int64_t)ep->smoothed_rtt - (int64_t)round_trip_time);
    ep->rtt_variation = 3 * (ep->rtt_variation / 4) + delta / 4;

    //SRTT <- (1 - alpha) * SRTT + alpha * R' where alpha is 0.125
    ep->smoothed_rtt = 7 * (ep->smoothed_rtt / 8) + round_trip_time / 8;
  }

  // Impose a lowerbound on the variation, we don't want the RTO to converge too close to the RTT
  if (ep->rtt_variation < sli_cpc_timer_ms_to_tick(SLI_CPC_MIN_RE_TRANSMIT_TIMEOUT_MINIMUM_VARIATION_MS)) {
    ep->rtt_variation = sli_cpc_timer_ms_to_tick(SLI_CPC_MIN_RE_TRANSMIT_TIMEOUT_MINIMUM_VARIATION_MS);
  }

  rto = ep->smoothed_rtt + k * ep->rtt_variation;

  if (rto > sli_cpc_timer_ms_to_tick(SLI_CPC_MAX_RE_TRANSMIT_TIMEOUT_MS)) {
    rto = sli_cpc_timer_ms_to_tick(SLI_CPC_MAX_RE_TRANSMIT_TIMEOUT_MS);
  } else if (rto < sli_cpc_timer_ms_to_tick(SLI_CPC_MIN_RE_TRANSMIT_TIMEOUT_MS)) {
    rto = sli_cpc_timer_ms_to_tick(SLI_CPC_MIN_RE_TRANSMIT_TIMEOUT_MS);
  }

  ep->re_transmit_timeout = (uint32_t)rto;
}

/***************************************************************************/ /**
 * Signal processing is required
 ******************************************************************************/
void sli_cpc_bus_signal_event(sl_cpc_bus_t *bus, sli_cpc_signal_type_t signal_type)
{
#if defined(SL_CATALOG_KERNEL_PRESENT)
  (void)signal_type;
  osStatus_t status = osSemaphoreRelease(bus->event_signal);
  if (status != osOK && status != osErrorResource) {
    SLI_CPC_PANIC("Failed to release bus event signal, status=%d", (int)status);
  }
#else
  if (signal_type == SLI_CPC_SIGNAL_RX) {
    MCU_ATOMIC_SECTION(bus->rx_process_flag++;);
  }
#endif
}

/***************************************************************************/ /**
 * Notify the core that an endpoint is terminated.
 ******************************************************************************/
static void move_ep_to_close_list(sl_cpc_ep_t *ep)
{
  MCU_ATOMIC_SECTION(sl_slist_push(&ep->bus->closed_eps, &ep->node););
  sli_cpc_bus_signal_event(ep->bus, SLI_CPC_SIGNAL_CLOSED);
}

/***************************************************************************/ /**
 * Handle frame write completion
 ******************************************************************************/
static void on_send_done(sl_cpc_frame_t *frame, void *arg, sl_status_t status)
{
  sl_cpc_ep_t *ep = sli_cpc_frame_get_ep(frame);
  sl_cpc_ep_event_t event = {
    .send_done = {
      .buf = frame->payload,
      .frame = frame,
      .status = status,
      .arg = arg,
    },
  };

  ep->event_cb(ep, SL_CPC_EP_EVENT_SEND_DONE, &event, ep->event_cb_arg);
}

/***************************************************************************/ /**
 * This function checks the frame type and notifies the appropriate callback.
 * After notification, it clears the data and releases the buffer.
 ******************************************************************************/
static void complete_tx_frame(sl_cpc_frame_t *frame)
{
  sl_cpc_ep_t *ep = sli_cpc_frame_get_ep(frame);

  LOCK_EP(ep);

  on_send_done(frame, frame->arg, frame->status);

  sli_cpc_ep_put_ref(ep);

  RELEASE_EP(ep);
}

/***************************************************************************/ /**
 * Process frames that have completed their entire transmission lifetime. For
 * example, a reliable frame will complete once it has received its ACK (or once
 * it has failed).
 *
 * @note This is not to be confused with a Transmit complete, where the frame has
 * only been sent to the remote. The frame's lifetime may not be over, as it may
 * be pending on an ACK.
 ******************************************************************************/
static void process_write_completions(sl_cpc_bus_t *bus)
{
  sl_cpc_frame_t *frame;

  MCU_DECLARE_IRQ_STATE;

  while (!sli_cpc_frame_list_empty(&bus->write_complete_callback_list)) {
    MCU_ENTER_ATOMIC();
    frame = sli_cpc_frame_list_pop(&bus->write_complete_callback_list);
    SLI_CPC_ASSERT(frame->ref_count == 0); // Make sure we own the context
    // before leaving the atomic section
    MCU_EXIT_ATOMIC();

    complete_tx_frame(frame);
  }
}

/***************************************************************************/ /**
 * This function is called upon the completion of a write operation. It sets
 * the write status of the buffer and dispatches a routine that will be executed
 * later to inform the endpoint user via the appropriate registered callback.
 ******************************************************************************/
static void submit_write_completion(sl_cpc_frame_t *frame)
{
  sl_cpc_ep_t *ep = sli_cpc_frame_get_ep(frame);

  // When submitting for write completion, the buffer should not be referenced
  SLI_CPC_ASSERT(frame->ref_count == 0);

  MCU_ATOMIC_SECTION(sli_cpc_frame_list_push_back(&ep->bus->write_complete_callback_list, frame););

  sli_cpc_bus_signal_event(ep->bus, SLI_CPC_SIGNAL_SYSTEM);
}

/***************************************************************************/ /**
 * Notify Packet has been received and it is ready to be processed
 ******************************************************************************/
void sli_cpc_bus_notify_rx_data_from_drv(sl_cpc_bus_t *bus)
{
  sli_cpc_bus_signal_event(bus, SLI_CPC_SIGNAL_RX);
}

/***************************************************************************/ /**
 * Determines if CPC is ok to enter sleep mode.
 ******************************************************************************/
#if !defined(SL_CATALOG_KERNEL_PRESENT) && defined(SL_CATALOG_POWER_MANAGER_PRESENT)
#include "sl_cpc_bus_instances.h"

bool sl_cpc_is_ok_to_sleep(void)
{
  bool ret;
  MCU_ATOMIC_SECTION(ret = ((g_bus->rx_process_flag == 0 && sli_cpc_frame_list_empty(&g_bus->transmit_queue))););
  return ret;
}
#endif

/***************************************************************************/ /**
 * Determines if CPC is ok to return to sleep mode on ISR exit.
 ******************************************************************************/
#if !defined(SL_CATALOG_KERNEL_PRESENT) && defined(SL_CATALOG_POWER_MANAGER_PRESENT)
sl_power_manager_on_isr_exit_t sl_cpc_sleep_on_isr_exit(void)
{
  return (sl_cpc_is_ok_to_sleep() ? SL_POWER_MANAGER_IGNORE : SL_POWER_MANAGER_WAKEUP);
}
#endif

/***************************************************************************/ /**
 * Initialize endpoint
 ******************************************************************************/
sl_status_t sl_cpc_ep_init(sl_cpc_ep_t *ep, uint8_t id, uint16_t rx_size, sl_cpc_ep_event_cb_t *cb, void *cb_arg)
{
  sl_status_t status;

  SLI_CPC_ASSERT(ep);

  // Limit the MTU according to the driver's capabilities and mandates that an
  // event callback is set
  if (cb == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  if (rx_size > SL_CPC_EP_MAX_PAYLOAD_SIZE || rx_size % SL_CPC_BUF_MIN_ALIGNMENT) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  memset(ep, 0, sizeof(*ep));

  SLI_CPC_DEBUG_EP_INIT(ep);

  // Initialize endpoint
  ep->flags = 0;
  ep->id = id;
  ep->mtu = rx_size;
  ep->event_cb = cb;
  ep->event_cb_arg = cb_arg;

#if defined(SL_CATALOG_KERNEL_PRESENT)
  osMutexAttr_t mutex_attr = {
    .attr_bits = osMutexRecursive | osMutexPrioInherit,
    .name = "CPC Endpoint Lock",
#if defined(SL_CATALOG_CMSIS_OS_COMMON_PRESENT)
    .cb_mem = ep->lock_cb,
    .cb_size = osMutexCbSize,
#else
    .cb_mem = NULL,
    .cb_size = 0U,
#endif
  };

  ep->lock = osMutexNew(&mutex_attr);
  if (ep->lock == 0) {
    return SL_STATUS_NO_MORE_RESOURCE;
  }
#endif

  // Initialize the re-transmit timer
  status = sli_cpc_timer_init(&ep->re_transmit_timer);
  if (status != SL_STATUS_OK) {
#if defined(SL_CATALOG_KERNEL_PRESENT)
    osMutexDelete(ep->lock);
#endif
    return status;
  }

  // Initialize endpoint frame lists
  sli_cpc_ep_frame_list_init(&ep->re_transmit_list);
  sli_cpc_ep_frame_list_init(&ep->holding_list);

  // Initialize endpoint buffer lists
  sl_cpc_msgq_init(&ep->rx_buffer_queue);

  return SL_STATUS_OK;
}

/***************************************************************************/ /**
 * Attach an initialized endpoint to a bus.
 ******************************************************************************/
sl_status_t sli_cpc_ep_attach(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus)
{
  const sl_cpc_ep_t *endpoint;
  MCU_DECLARE_IRQ_STATE;

  SLI_CPC_ASSERT(ep);

  if (bus == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  // Reject if already bound to another bus, or bound but not CLOSED.
  if (ep->bus != NULL && (ep->bus != bus || ep->state != SLI_CPC_STATE_CLOSED)) {
    return SL_STATUS_INVALID_STATE;
  }

  LOCK_EP_LIST(bus);

  endpoint = sli_cpc_bus_find_ep_from_id(bus, ep->id);
  if (endpoint) {
    RELEASE_EP_LIST(bus);
    if (endpoint == ep) {
      // This endpoint is already attached to the bus.
      return SL_STATUS_OK;
    }
    // Another endpoint with the same ID is already attached to the bus.
    return SL_STATUS_ALREADY_INITIALIZED;
  }

  ep->bus = bus;

  // Drivers look up endpoints by ID on this list and take a reference. Keep the
  // invariant that list membership implies ref_cnt >= 1.
  MCU_ENTER_ATOMIC();
  sli_cpc_ep_get_ref(ep);
  sli_cpc_bus_add_ep(bus, ep);
  MCU_EXIT_ATOMIC();

  RELEASE_EP_LIST(bus);

  return SL_STATUS_OK;
}

/***************************************************************************/ /**
 * Detach an endpoint from its bus (inverse of sli_cpc_ep_attach).
 ******************************************************************************/
void sli_cpc_ep_detach(sl_cpc_ep_t *ep)
{
  sl_cpc_bus_t *bus;
  MCU_DECLARE_IRQ_STATE;

  SLI_CPC_ASSERT(ep);

  bus = ep->bus;
  if (bus == NULL) {
    return;
  }

  LOCK_EP_LIST(bus);

  if (sli_cpc_bus_find_ep_from_id(bus, ep->id) != ep) {
    ep->bus = NULL;
    RELEASE_EP_LIST(bus);
    return;
  }

  MCU_ENTER_ATOMIC();
  sli_cpc_bus_remove_ep(bus, ep);
  SLI_CPC_ASSERT(ep->ref_cnt > 0);
  ep->ref_cnt--;
  MCU_EXIT_ATOMIC();

  ep->bus = NULL;
  RELEASE_EP_LIST(bus);
}

void sl_cpc_ep_deinit(sl_cpc_ep_t *ep)
{
  SLI_CPC_ASSERT(ep);
  SLI_CPC_ASSERT(!(ep->flags & SLI_CPC_EP_FLAG_OPENED));

  sli_cpc_ep_detach(ep);

  SLI_CPC_ASSERT(ep->ref_cnt == 0);

#if defined(SL_CATALOG_KERNEL_PRESENT)
  osMutexDelete(ep->lock);
  ep->lock = 0;
#endif
}

/***************************************************************************/ /**
 * Start listening on an attached endpoint.
 ******************************************************************************/
sl_status_t sli_cpc_ep_listen(sl_cpc_ep_t *ep)
{
  const sl_cpc_ep_t *ep_found;
  const sl_cpc_bus_t *bus;
  sl_status_t status = SL_STATUS_OK;

  SLI_CPC_ASSERT(ep);

  bus = ep->bus;
  if (!bus) {
    return SL_STATUS_INVALID_STATE;
  }

  LOCK_EP_LIST(bus);
  LOCK_EP(ep);

  // if the endpoint is not closed, the endpoint is not in a state where calling
  // listen is a valid operation, bail out early.
  if (ep->state != SLI_CPC_STATE_CLOSED) {
    status = SL_STATUS_INVALID_STATE;
    goto release_ep;
  }

  // Must already be on the bus from sli_cpc_ep_attach().
  ep_found = sli_cpc_bus_find_ep_from_id(bus, ep->id);
  if (ep_found == NULL) {
    status = SL_STATUS_INVALID_STATE;
    goto release_ep;
  }
  if (ep_found != ep) {
    status = SL_STATUS_ALREADY_INITIALIZED;
    goto release_ep;
  }

  ep->flags |= SLI_CPC_EP_FLAG_OPENED;
  ep_set_state(ep, SLI_CPC_STATE_OPEN, false);

  initialize_ep_counters(ep);

  SLI_CPC_DEBUG_TRACE_CORE_OPEN_EP(bus);

release_ep:
  RELEASE_EP(ep);
  RELEASE_EP_LIST(bus);

  return status;
}

/***************************************************************************/ /**
 * Register an open request; run now or defer until the bus is initialized.
 ******************************************************************************/
static sl_status_t ep_request_open(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus, bool connect)
{
  sl_status_t status;

  SLI_CPC_ASSERT(ep);

  if (bus == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  LOCK_EP_LIST(bus);
  LOCK_EP(ep);

  status = sli_cpc_ep_attach(ep, bus);
  if (status != SL_STATUS_OK) {
    goto exit;
  }

  if (connect) {
    ep->flags |= SLI_CPC_EP_FLAG_CONNECT;
  } else {
    ep->flags &= ~SLI_CPC_EP_FLAG_CONNECT;
  }

  ep->flags |= SLI_CPC_EP_FLAG_OPENED;

  if (!bus->initialized) {
    status = SL_STATUS_OK;
    goto exit;
  }

  status = connect ? sli_cpc_ep_connect(ep) : sli_cpc_ep_listen(ep);
  if (status != SL_STATUS_OK) {
    ep->flags &= ~SLI_CPC_EP_FLAG_OPENED;
    sli_cpc_ep_detach(ep);
  }

exit:
  RELEASE_EP(ep);
  RELEASE_EP_LIST(bus);

  return status;
}

/***************************************************************************/ /**
 * Listen for connection on an endpoint.
 ******************************************************************************/
sl_status_t sl_cpc_ep_listen(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus)
{
  return ep_request_open(ep, bus, false);
}

/***************************************************************************/ /**
 * Start connecting an attached endpoint.
 ******************************************************************************/
sl_status_t sli_cpc_ep_connect(sl_cpc_ep_t *ep)
{
  const sl_cpc_ep_t *ep_found;
  sl_cpc_bus_t *bus;
  sl_cpc_frame_t *frame;
  sl_status_t status = SL_STATUS_OK;

  SLI_CPC_ASSERT(ep);

  bus = ep->bus;
  if (!bus) {
    return SL_STATUS_INVALID_STATE;
  }

  LOCK_EP_LIST(bus);
  LOCK_EP(ep);

  // if the endpoint is not closed, the endpoint is not in a state where calling
  // connect is a valid operation, bail out early.
  if (ep->state != SLI_CPC_STATE_CLOSED) {
    status = SL_STATUS_INVALID_STATE;
    goto release_ep;
  }

  // Must already be on the bus from sli_cpc_ep_attach().
  ep_found = sli_cpc_bus_find_ep_from_id(bus, ep->id);
  if (ep_found == NULL) {
    status = SL_STATUS_INVALID_STATE;
    goto release_ep;
  }
  if (ep_found != ep) {
    status = SL_STATUS_ALREADY_INITIALIZED;
    goto release_ep;
  }

  initialize_ep_counters(ep);

  frame = get_syn_frame(ep);
  if (!frame) {
    status = SL_STATUS_NO_MORE_RESOURCE;
    goto release_ep;
  }

  ep->flags |= SLI_CPC_EP_FLAG_OPENED;
  ep_set_state(ep, SLI_CPC_STATE_SYN_SENT, false);

  transmit_frame(bus, frame, true);

  SLI_CPC_DEBUG_TRACE_CORE_OPEN_EP(bus);

release_ep:
  RELEASE_EP(ep);
  RELEASE_EP_LIST(bus);

  return status;
}

/***************************************************************************/ /**
 * Connect an endpoint.
 ******************************************************************************/
sl_status_t sl_cpc_ep_connect(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus)
{
  return ep_request_open(ep, bus, true);
}

/***************************************************************************/ /**
 * Wrapper function to signal the state_event_signal semaphore.
 * Returns if the state change was signaled or not.
 ******************************************************************************/
static inline bool notify_state_change(const sl_cpc_ep_t *ep)
{
  bool signaled = false;
#if defined(SL_CATALOG_KERNEL_PRESENT)
  if (ep->state_event_signal != NULL) {
    osStatus_t status = osSemaphoreRelease(ep->state_event_signal);
    if (status != osOK && status != osErrorResource) {
      SLI_CPC_PANIC("Failed to release state event signal for ep=%u, status=%d", (unsigned int)ep->id, (int)status);
    }
    signaled = true;
  }
#else
  (void)ep;
#endif
  return signaled;
}

/***************************************************************************/ /**
 * Test if a number is between start and end (included), taking into account
 * the modulo 256.
 *
 * @param start   Lowest limit
 * @param end     Highest limit
 * @param n       Number to be tested
 *
 * @return        True if start <= n <= end (modulo 256)
 ******************************************************************************/
static bool in_range(uint8_t start, uint8_t end, uint8_t n)
{
  if (end >= start) {
    if (n < start || n > end) {
      return false;
    }
  } else {
    if (n > end && n < start) {
      return false;
    }
  }

  return true;
}

/***************************************************************************/ /**
 * Compute by how much the sequence number would advance given the buffer total
 * length and a divider.
 *
 * @param[in] buf     Pointer to buffer, might be NULL.
 * @param[in] divider Divider.
 *
 * @return  1 if @p buf is NULL, or buf->tot_len / divider, rounded up.
 ******************************************************************************/
static uint8_t advance_seq_number(const sl_cpc_buf_t *buf, uint16_t divider)
{
  if (!buf) {
    return 1;
  }

  return (uint8_t)SL_DIV_ROUND_UP(buf->tot_len, divider);
}

/***************************************************************************/ /**
 * Tests if a frame is within the endpoint send window.
 *
 * @param[in] frame Pointer to the frame.
 *
 * @return  Whether the frame is within the endpoint send window.
 ******************************************************************************/
static bool frame_in_send_window(const sl_cpc_ep_t *ep, const sl_cpc_buf_t *buf)
{
  uint8_t rx_buffers_wanted = advance_seq_number(buf, ep->remote_mtu);
  uint8_t inflight = ep->send_nxt - ep->send_una;
  // Keep these two as integers. `need` might wrap around if using a uint8_t.
  int wnd = SL_MIN(ep->send_wnd, SLI_CPC_EP_MAX_TX_QUEUE_LENGTH_DEFAULT);
  int need = inflight + rx_buffers_wanted;

  if (wnd == 0) {
    return false;
  }

  return need <= wnd;
}

/***************************************************************************/ /**
 * Add a frame to the transmit queue. Frames will be submitted to the bus in
 * process_transmit_queue.
 *
 * @note Caller should hold endpoint lock associated with the frame prior to calling.
 *
 * @param bus   Pointer to the bus owning the transmit queue.
 * @param frame Pointer to the frame to transmit.
 * @param signal Whether the bus should be signaled of this event.
 ******************************************************************************/
static void transmit_frame(sl_cpc_bus_t *bus, sl_cpc_frame_t *frame, bool signal)
{
  sl_cpc_ep_t *ep = sli_cpc_frame_get_ep(frame);
  sli_cpc_hdr_t *hdr = sli_cpc_frame_get_header(frame);

  frame->tx_count++;

  if (sli_cpc_header_is_ack_requested(hdr)) {
    // Get additional ref to the context, as core now owns another reference to it. The frame
    // is considered in-flight from that point on.
    sli_cpc_frame_get_ref(frame);

    if (frame->tx_count == 1) {
      // First transmission on a reliable frame. Add it to the re-transmit frame list to handle re-tx.
      // Notice that the endpoint still holds a reference to the context, as it remains in one of its lists.
      SLI_CPC_ASSERT(ep != NULL);

      sli_cpc_ep_frame_list_push_back(&ep->re_transmit_list, frame);

      sli_cpc_header_set_seq(hdr, ep->send_nxt);

      // Increase the send_nxt sequence, this is used as the upper bound
      // of sequence number that can be acknowledged by the remote
      ep->send_nxt += advance_seq_number(frame->payload, ep->remote_mtu);
    }
  }

  LOCK_TRANSMIT_QUEUE(bus);
  sli_cpc_frame_list_push_back(&bus->transmit_queue, frame);
  RELEASE_TRANSMIT_QUEUE(bus);

  if (signal) {
    sli_cpc_bus_signal_event(bus, SLI_CPC_SIGNAL_TX);
  }
}

/***************************************************************************/ /**
 * Starts the retransmission timer for given endpoint. The timer will be started
 * only if it's not already running.
 ******************************************************************************/
static sl_status_t start_retx_timer(sl_cpc_ep_t *ep)
{
  sl_status_t status = SL_STATUS_OK;

  // send_una == send_nxt checks if there are no outstanding frames,
  // meaning that the endpoint is idle.
  if (ep->send_una == ep->send_nxt) {
    return status;
  }

  // Start the timer if it was idle, or allow to override a scheduled window probe
  if (!sli_cpc_timer_is_running(&ep->re_transmit_timer) || ep->flags & SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED) {
    ep->flags &= ~SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED;
    status = sli_cpc_timer_restart(&ep->re_transmit_timer, ep->re_transmit_timeout, re_transmit_timeout_callback, ep);
  }

  return status;
}

/***************************************************************************/ /**
 * Stop the retransmit timer and clear any flag associated with it.
 ******************************************************************************/
static void stop_retx_timer(sl_cpc_ep_t *ep)
{
  sli_cpc_timer_stop(&ep->re_transmit_timer);
  ep->flags &= ~SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED;
}

/***************************************************************************/ /**
 * Set the pending ACK flag on an endpoint.
 *
 * The pending ACK can be consumed by piggy-backing it on an outgoing data
 * frame, or by sending a standalone ACK control frame later.
 ******************************************************************************/
static void ep_set_pend_ack(sl_cpc_ep_t *ep)
{
  ep->flags |= SLI_CPC_EP_FLAG_PEND_ACK;
}

/***************************************************************************/ /**
 * Clear the pending ACK flag on an endpoint.
 *
 * This is called once a pending ACK has been consumed, either by piggy-backing
 * on an outgoing data frame or by successfully sending a standalone ACK
 * control frame.
 ******************************************************************************/
static void ep_clear_pend_ack(sl_cpc_ep_t *ep)
{
  ep->flags &= ~SLI_CPC_EP_FLAG_PEND_ACK;
}

/***************************************************************************/ /**
 * Clear the pending window probe flag on an endpoint.
 ******************************************************************************/
static void ep_clear_pend_wnd_probe(sl_cpc_ep_t *ep)
{
  ep->flags &= ~SLI_CPC_EP_FLAG_PEND_WND_PROBE;
}

/***************************************************************************/ /**
 * Calculate the window probe schedule timeout.
 *
 * Doubles the current timeout with an upper limit at SLI_CPC_MAX_WINDOW_PROBE_TIMEOUT_MS.
 ******************************************************************************/
static void sli_compute_window_probe_timeout(sl_cpc_ep_t *ep)
{
  ep->wnd_probe.timeout
    = SL_MIN(ep->wnd_probe.timeout * 2, sli_cpc_timer_ms_to_tick(SLI_CPC_MAX_WINDOW_PROBE_TIMEOUT_MS));
}

/***************************************************************************/ /**
 * Cancel a scheduled window probe and clear related endpoint flags.
 *
 * @note Caller must hold the endpoint lock prior to calling.
 ******************************************************************************/
static void cancel_scheduled_wnd_probe(sl_cpc_ep_t *ep)
{
  if (ep->flags & SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED) {
    sli_cpc_timer_stop(&ep->re_transmit_timer);
    ep->flags &= ~SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED;
  }

  ep_clear_pend_wnd_probe(ep);
  ep->wnd_probe.timeout = sli_cpc_timer_ms_to_tick(SLI_CPC_INIT_WINDOW_PROBE_TIMEOUT_MS);
  ep->wnd_probe.count = 0u;
}

/***************************************************************************/ /**
 * Request a window probe to be scheduled after a short delay.
 *
 * Loss retransmission and scheduled probes share ep->re_transmit_timer. They are
 * mutually exclusive: loss retx runs while send_una != send_nxt; probe schedule
 * runs only when send_una == send_nxt (see ep_needs_wnd_probe()).
 *
 * @note Caller must hold the endpoint lock prior to calling.
 *
 * @param ep  Pointer to the endpoint.
 ******************************************************************************/
static void schedule_wnd_probe(sl_cpc_ep_t *ep)
{
  if (!ep_needs_wnd_probe(ep)) {
    return;
  }

  if (ep->flags & SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED) {
    return;
  }

  // Loss retransmission owns the timer while frames are unacknowledged.
  if (sli_cpc_timer_is_running(&ep->re_transmit_timer)) {
    return;
  }

  ep->flags |= SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED;
  sli_cpc_bus_signal_event(ep->bus, SLI_CPC_SIGNAL_TX);
}

/***************************************************************************/ /**
 * Tests whether an endpoint should transmit an RX window probe.
 ******************************************************************************/
static bool ep_needs_wnd_probe(const sl_cpc_ep_t *ep)
{
  if (ep->state != SLI_CPC_STATE_CONNECTED) {
    return false;
  }

  if (sli_cpc_ep_frame_list_empty(&ep->holding_list)) {
    return false;
  }

  return ep->send_una == ep->send_nxt;
}

/***************************************************************************/ /**
 * Send a buffer on an endpoint.
 ******************************************************************************/
sl_status_t sl_cpc_ep_send(sl_cpc_ep_t *ep, sl_cpc_buf_t *buf, sl_cpc_frame_t *frame, void *arg)
{
  sl_status_t status = SL_STATUS_OK;
  sl_cpc_buf_t *current_buf;
  sli_cpc_hdr_t *hdr;

  SLI_CPC_ASSERT(ep);

  if (!frame || !buf) {
    return SL_STATUS_NULL_POINTER;
  }

  if (buf->tot_len == 0) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  SL_SLIST_FOR_EACH_ENTRY(&buf->node, current_buf, sl_cpc_buf_t, node)
  {
    if (current_buf->ptr == NULL) {
      return SL_STATUS_NULL_POINTER;
    }

    if ((uintptr_t)current_buf->ptr % SL_CPC_BUF_MIN_ALIGNMENT != 0) {
      return SL_STATUS_INVALID_PARAMETER;
    }

    if (current_buf->tot_len == current_buf->len && current_buf->node.node != NULL) {
      return SL_STATUS_INVALID_PARAMETER;
    }

    if (current_buf->tot_len != current_buf->len && current_buf->node.node == NULL) {
      return SL_STATUS_INVALID_PARAMETER;
    }
  }

  sli_cpc_frame_init(frame);
  frame->payload = buf;

  hdr = sli_cpc_frame_get_header(frame);

  sli_cpc_header_set_address(hdr, ep->id);
  sli_cpc_header_set_payload_size(hdr, frame->payload->tot_len);
  sli_cpc_header_set_ack_request(hdr, true);
  sli_cpc_header_set_reset(hdr, false);

  LOCK_EP(ep);

  if (ep->state != SLI_CPC_STATE_CONNECTED) {
    status = SL_STATUS_INVALID_STATE;
    goto exit;
  }

  if (ep->remote_mtu == 0) {
    status = SL_STATUS_NOT_AVAILABLE;
    goto exit;
  }

  if (advance_seq_number(frame->payload, ep->remote_mtu) > SLI_CPC_EP_MAX_TX_QUEUE_LENGTH_DEFAULT) {
    status = SL_STATUS_WOULD_OVERFLOW;
    goto exit;
  }

  frame->ep = sli_cpc_ep_get_ref(ep);
  frame->arg = arg;
  frame->destructor = submit_write_completion;

  if (!frame_in_send_window(ep, frame->payload)) {
    // Frame does not fit in the transmit window, add it to the holding list.
    // Once room is made available in the window, the frame will be sent.
    sli_cpc_ep_frame_list_push_back(&ep->holding_list, frame);

    schedule_wnd_probe(ep);

    goto exit;
  }

  transmit_frame(ep->bus, frame, true);

exit:
  RELEASE_EP(ep);

  return status;
}

sl_status_t sl_cpc_ep_push_recv_buf(sl_cpc_ep_t *ep, sl_cpc_buf_t *buf)
{
  sl_status_t status = SL_STATUS_OK;
  sl_cpc_buf_t *current_buf;

  SLI_CPC_ASSERT(ep);

  if (buf == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  SL_SLIST_FOR_EACH_ENTRY(&buf->node, current_buf, sl_cpc_buf_t, node)
  {
    // Must have a valid data pointer, obviously
    if (current_buf->ptr == NULL) {
      return SL_STATUS_NULL_POINTER;
    }

    // Must respect alignment
    if ((uintptr_t)current_buf->ptr % SL_CPC_BUF_MIN_ALIGNMENT != 0) {
      return SL_STATUS_INVALID_PARAMETER;
    }
  }

  LOCK_EP(ep);

  if (ep->mtu == 0) {
    status = SL_STATUS_NOT_AVAILABLE;
    goto release;
  }

  sli_cpc_buffer_chain_release(&ep->rx_buffer_queue, buf, ep->mtu);

release:
  RELEASE_EP(ep);
  return status;
}

sl_status_t sl_cpc_ep_pop_recv_buf(sl_cpc_ep_t *ep, sl_cpc_buf_t **out_buf)
{
  sl_status_t status = SL_STATUS_OK;

  SLI_CPC_ASSERT(ep);

  if (!out_buf) {
    return SL_STATUS_NULL_POINTER;
  }

  LOCK_EP(ep);
  if (ep->state != SLI_CPC_STATE_CLOSED) {
    status = SL_STATUS_INVALID_STATE;
    goto release;
  }

  if (!sl_cpc_msgq_pop(&ep->rx_buffer_queue, out_buf)) {
    status = SL_STATUS_NO_MORE_RESOURCE;
    goto release;
  }

release:
  RELEASE_EP(ep);

  return status;
}

static void process_received_frames(sl_cpc_bus_t *bus)
{
  sli_cpc_frame_list_t rxd_frames;
  sl_cpc_frame_t *frame;

  sli_cpc_frame_list_init(&rxd_frames);

  if (bus->drv_ops->read(bus, &rxd_frames) != SL_STATUS_OK) {
    return;
  }

  while ((frame = sli_cpc_frame_list_pop(&rxd_frames)) != NULL) {
    receive_frame(bus, frame);
  }
}

static void reject_invalid_received_frame(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep, uint16_t address)
{
  // Driver received a frame for an unallocated or closed endpoint.
  // Send a RST only if the incoming is not itself of type RST, that
  // prevents both sides going havoc and spamming RST to each other.
  SLI_CPC_LOG_ERROR("Rejected non-RST frame received on closed endpoint: %d", address);

  // Notify the remote that the endpoint has prematurely been closed.
  if (ep) {
    ep_set_error(ep, SL_STATUS_ABORT);
  }

  sli_cpc_send_reset_frame(bus, address);
}

static bool process_incoming_ack(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep, const sli_cpc_hdr_t *hdr)
{
  sl_cpc_frame_t *pending_frame;
  bool window_too_small = false;
  uint8_t seq;

  // Validate packet sequence numbers to ensure frames are processed in order.
  seq = sli_cpc_header_get_seq(hdr);
  if (sli_cpc_header_is_ack_requested(hdr) && ep->ack != seq) {
    ep_set_pend_ack(ep);

    SLI_CPC_DEBUG_TRACE_EP_RXD_OUT_OF_SEQ_FRAME(ep);
    return false;
  }

  receive_ack(ep, hdr);

  // ACK may have increased send_wnd try to send pending frames.
  while (!sli_cpc_ep_frame_list_empty(&ep->holding_list)) {
    pending_frame = sli_cpc_ep_frame_list_peek(&ep->holding_list);
    if (!frame_in_send_window(ep, pending_frame->payload)) {
      window_too_small = true;
      break;
    }

    sli_cpc_ep_frame_list_pop(&ep->holding_list);
    transmit_frame(bus, pending_frame, false);
  }

  if (window_too_small) {
    schedule_wnd_probe(ep);
  } else {
    cancel_scheduled_wnd_probe(ep);
  }

  return true;
}

/***************************************************************************/ /**
 * Process an incoming payload frame.
 *
 * @return true if the frame was processed and this function now owns it;
 *         false if the caller still owns the frame and is responsible for
 *         cleanup.
 ******************************************************************************/
static bool process_incoming_payload(sl_cpc_ep_t *ep, const sli_cpc_hdr_t *hdr, sl_cpc_frame_t *frame)
{
  sl_status_t status;
  size_t hdr_pl_size = sli_cpc_header_get_payload_size(hdr);
  size_t buf_pl_size = frame->payload ? frame->payload->tot_len : 0;

  SLI_CPC_DEBUG_TRACE_EP_RXD_FRAME(ep);

  // If the driver detected an invalid payload checksum, either the csum flag is invalid...
  if (frame->payload && !frame->payload_csum_is_valid) {
    SLI_CPC_LOG_WARN("Invalid payload checksum: Endpoint=%d, payload_len=%d", ep->id, hdr_pl_size);
    return false;
  }

  // ... or the buffer payload length doesn't match the header.
  if (hdr_pl_size != buf_pl_size) {
    SLI_CPC_LOG_WARN("Invalid payload length: Endpoint=%d, hdr_len=%d, buf_len=%d", ep->id, hdr_pl_size, buf_pl_size);
    return false;
  }

  if (sli_cpc_header_is_ack_requested(hdr)) {
    SLI_CPC_DEBUG_TRACE_CORE_RXD_VALID_RELIABLE_FRAME(ep->bus);

    ep->ack += advance_seq_number(frame->payload, ep->mtu);
    ep_set_pend_ack(ep);
  }

  if (hdr_pl_size == 0) {
    return false;
  }

  status = process_received_data_frame(frame);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("Failed to process data frame: 0x%lx", (unsigned long)status);
  }

  sli_cpc_frame_put_ref(&frame);

  return true;
}

/***************************************************************************/ /**
 * De-multiplex received frame and put it in right endpoint queue.
 * @param bus     Pointer to the bus.
 * @param frame  Pointer to the received frame.
 *
 * @warning The underlying context may be freed by this function.
 ******************************************************************************/
static void receive_frame(sl_cpc_bus_t *bus, sl_cpc_frame_t *frame)
{
  sl_cpc_ep_t *ep = NULL;
  const sli_cpc_hdr_t *hdr;
  uint16_t address;

  SLI_CPC_DEBUG_TRACE_CORE_RXD_FRAME(bus);

  hdr = sli_cpc_frame_get_header(frame);
  address = sli_cpc_header_get_address(hdr);

  if (sli_cpc_header_is_reset(hdr)) {
    sl_cpc_ep_t *rst_ep = sli_cpc_frame_get_ep(frame);

    if (rst_ep) {
      LOCK_EP(rst_ep);
      receive_reset(rst_ep);
      RELEASE_EP(rst_ep);
    }

    goto cleanup;
  }

  ep = sli_cpc_frame_get_ep(frame);

  if (ep) {
    LOCK_EP(ep);
  }

  if (!ep || frame_has_invalid_flags(frame)) {
    reject_invalid_received_frame(bus, ep, address);
    goto cleanup;
  }

  if (sli_cpc_header_is_syn(hdr)) {
    receive_syn(bus, ep, frame);
    sli_cpc_frame_put_ref(&frame);

    goto cleanup;
  }

  if (is_ep_closed(ep)) {
    reject_invalid_received_frame(bus, ep, address);
    goto cleanup;
  }

  // From here, all frames are DATA frames, with or without payload

  SLI_CPC_ASSERT(
    // CONNECTED is the nominal mode when connection is established
    ep->state == SLI_CPC_STATE_CONNECTED ||
    // SYN_RCVD expects a DATA frame to move to the next state
    ep->state == SLI_CPC_STATE_SYN_RCVD ||
    // SYN_SENT expects a SYN frame
    ep->state == SLI_CPC_STATE_SYN_SENT ||
    // In case a listening endpoint received a non-SYN frame
    ep->state == SLI_CPC_STATE_OPEN);

  // DATA is only valid in CONNECTED and SYN_RCVD
  switch (ep->state) {
    case SLI_CPC_STATE_CONNECTED:
    case SLI_CPC_STATE_SYN_RCVD:
      break;
    default:
      reject_invalid_received_frame(bus, ep, address);
      goto cleanup;
  }

  if (!process_incoming_ack(bus, ep, hdr)) {
    goto cleanup;
  }

  // This function returns true when it takes ownership of the frame. When it does,
  // it becomes responsible for releasing the frame when it's done with it.
  if (process_incoming_payload(ep, hdr, frame)) {
    frame = NULL;
  }

cleanup:
  if (frame) {
    if (ep && frame->payload) {
      sl_cpc_ep_push_recv_buf(ep, frame->payload);
      frame->payload = NULL;
    }
    sli_cpc_frame_put_ref(&frame);
  }
  if (ep) {
    RELEASE_EP(ep);
  }
}

/***************************************************************************/ /**
 * Process a received RST frame based on the current endpoint state.
 *
 * @note The caller must hold the endpoint lock prior to calling this API.
 ******************************************************************************/
static void receive_reset(sl_cpc_ep_t *ep)
{
  ep_set_error(ep, SL_STATUS_ABORT);
}

/***************************************************************************/ /**
 * Process a received SYN frame based on the current endpoint state.
 *
 * @note The caller must hold the endpoint lock prior to calling this API.
 *
 * Handles the incoming SYN while the caller retains ownership of the frame
 * and emits a reply where required by the matrix.
 ******************************************************************************/
static void receive_syn(sl_cpc_bus_t *bus, sl_cpc_ep_t *ep, sl_cpc_frame_t *frame)
{
  const sli_cpc_hdr_t *hdr = sli_cpc_frame_get_header(frame);
  uint16_t address = sli_cpc_header_get_address(hdr);
  sl_cpc_frame_t *reply;

  switch (ep->state) {
    case SLI_CPC_STATE_OPEN:
      ep->ack = sli_cpc_header_get_seq(hdr) + 1;
      ep->remote_mtu = sli_cpc_u16_from_le(hdr->size_le);

      reply = get_syn_frame(ep);
      if (reply == NULL) {
        // Couldn't get a TX frame; treat as a transient failure and let the
        // peer retransmit. Endpoint stays in OPEN.
        SLI_CPC_LOG_ERROR("OPEN+SYN: out of TX frames replying to ep=%u", (unsigned int)ep->id);
        break;
      }

      transmit_frame(bus, reply, false);

      ep_set_state(ep, SLI_CPC_STATE_SYN_RCVD, false);
      break;

    case SLI_CPC_STATE_SYN_SENT:
      ep->ack = sli_cpc_header_get_seq(hdr) + 1;
      ep->remote_mtu = sli_cpc_u16_from_le(hdr->size_le);

      receive_ack(ep, hdr);

      ep_set_pend_ack(ep);
      break;

    case SLI_CPC_STATE_SYN_RCVD:
      // Peer retransmitted SYN (or raced another SYN). Do not RST — stay in
      // SYN_RCVD and let the outstanding SYN-ACK retransmit path recover.
      break;

    case SLI_CPC_STATE_CONNECTED:
      // Peer retransmitted SYN+ACK. This should only be the case when actively connecting an
      // endpoint, when the final ack of the three-way handshake has been lost. The first SYN+ACK
      // changed the endpoint state to connected, the second one ends up here. The endpoint seq,
      // ack, and rx_wnd are already initialized based on the first SYN+ACK, the second one should
      // have the same values. If there's a mismatch, consider it an error.
      if ((ep->flags & SLI_CPC_EP_FLAG_CONNECT) != 0U && sli_cpc_header_get_seq(hdr) == (uint8_t)(ep->ack - 1U)
          && sli_cpc_header_get_ack(hdr) == ep->send_una && sli_cpc_header_get_rx_wnd(hdr) == ep->send_wnd) {
        ep_set_pend_ack(ep);
      } else {
        SLI_CPC_LOG_WARN("Unexpected SYN received in connected state on ep=%u", (unsigned int)ep->id);
        ep_set_error(ep, SL_STATUS_INVALID_STATE);
        sli_cpc_send_reset_frame(bus, address);
      }
      break;

    case SLI_CPC_STATE_CLOSED:
      if (has_ep_deferred_listen(ep)) {
        break;
      }

      sli_cpc_send_reset_frame(bus, address);
      break;

    default:
      sli_cpc_send_reset_frame(bus, address);
      break;
  }
}

/***************************************************************************/ /**
 * Process received ACK
 *
 * @note The caller must hold the endpoint lock prior to calling this API.
 ******************************************************************************/
static void receive_ack(sl_cpc_ep_t *ep, const sli_cpc_hdr_t *remote_hdr)
{
  uint8_t ack = sli_cpc_header_get_ack(remote_hdr);
  bool syn_acked = false;

  SLI_CPC_DEBUG_TRACE_EP_RXD_ACK(ep);

  if (sli_cpc_ep_frame_list_empty(&ep->re_transmit_list) || !in_range(ep->send_una + 1, ep->send_nxt, ack)) {
    // ignore this ack as either there are no frames waiting to be acked
    // or the ack number it carries is not valid in the current send window
    SLI_CPC_DEBUG_TRACE_EP_RXD_ACK_DROPPED(ep);

    goto update_window;
  }

  SLI_CPC_DEBUG_TRACE_EP_RXD_ACK_PROCESSED(ep);

  // Stop incoming re-transmit timeout. The timer is stopped even if the ack doesn't
  // fully ack the first frame. It's an okay trade-off to make sure the re_transmit_list
  // is not accessed concurrently from the timeout callback handler.
  stop_retx_timer(ep);

  // Remove all acknowledged frames in re-transmit queue
  while (ep->send_una != ack) {
    sl_cpc_frame_t *frame;

    frame = sli_cpc_ep_frame_list_peek(&ep->re_transmit_list);
    if (frame == NULL || frame->ref_count > 1) {
      if (frame == NULL) {
        // This should never happen as the ack number is checked at the beginning
        // of the function to be within [send_una; send_nxt).
        SLI_CPC_ASSERT(false);
      }
      // Frame is currently being (re)-transmitted, or invariant violated.
      break;
    }

    // send_una is incremented every time a frame is acked, so the sequence
    // number of popped frame should always match send_una.
    const sli_cpc_hdr_t *hdr = sli_cpc_frame_get_header(frame);
    uint8_t seq = sli_cpc_header_get_seq(hdr);
    SLI_CPC_ASSERT(seq == ep->send_una);

    // Partial frame acks are not allowed; the frame must be acked as a whole.
    // The best way to reliably detect that is to make sure that the incoming ack
    // falls in the range [send_una + 1, send_next] for single buffer frame. For
    // buffer chain, the start of the interval is send_una + n, where n is the
    // number of buffers in the chain.
    uint8_t advance_una = advance_seq_number(frame->payload, ep->remote_mtu);
    if (!in_range(ep->send_una + advance_una, ep->send_nxt, ack)) {
      break;
    }

    // Reset re-transmit counter
    ep->packet_re_transmit_count = 0u;

    frame = sli_cpc_ep_frame_list_pop(&ep->re_transmit_list);

    if (seq == ep->rtt_frame_seq && ep->rtt_sent_ticks != 0) {
      // Calculate re_transmit_timeout
      sli_compute_re_transmit_timeout(ep);

      // reset sent timestamp to be reused by next TX'd frame
      ep->rtt_sent_ticks = 0;
    }

    // Defer CONNECTED until after send_una/send_wnd update below.
    if (sli_cpc_header_is_syn(hdr) && (ep->state == SLI_CPC_STATE_SYN_SENT || ep->state == SLI_CPC_STATE_SYN_RCVD)) {
      syn_acked = true;
    }

    // mark the frame as transmitted successfully
    // and drop the reference to it.
    frame->status = SL_STATUS_OK;

    sli_cpc_frame_put_ref(&frame);

    // Update sequence of last unacknowledged frame
    ep->send_una += advance_una;
  }

  start_retx_timer(ep);

update_window:
  ep->send_wnd = sli_cpc_header_get_rx_wnd(remote_hdr);

  // Set connected state only after send_una/send_wnd has been
  // updated as the connected handler may write immediately (e.g.
  // the control endpoint sends a protocol version request).
  // Otherwise send_una still counts the SYN as unacknowledged,
  // therefore the send window has no room for another frame.
  if (syn_acked) {
    ep_set_state(ep, SLI_CPC_STATE_CONNECTED, false);
  }

  SLI_CPC_DEBUG_TRACE_EP_RXD_ACK(ep);
}

/***************************************************************************/ /**
 * Process received data frame
 ******************************************************************************/
static sl_status_t process_received_data_frame(sl_cpc_frame_t *frame)
{
  sl_cpc_ep_t *ep = sli_cpc_frame_get_ep(frame);
  const sli_cpc_hdr_t *hdr;

  SLI_CPC_DEBUG_TRACE_EP_RXD_DATA_FRAME(ep);

  // MTU must be respected.
  hdr = sli_cpc_frame_get_header(frame);
  SLI_CPC_ASSERT(sli_cpc_header_get_payload_size(hdr) <= SL_CPC_EP_MAX_PAYLOAD_SIZE);

  // Currently processing a reliable data frame. Should always be requesting an ACK.
  SLI_CPC_ASSERT(sli_cpc_header_is_ack_requested(hdr));

  sl_cpc_ep_event_t event = {.recv = {.buf = frame->payload}};
  ep->event_cb(ep, SL_CPC_EP_EVENT_RECV, &event, ep->event_cb_arg);

  return SL_STATUS_OK;
}

/***************************************************************************/ /**
 * Transmit ACK frame
 *
 * @note  Caller must hold lock to the endpoint prior to calling.
 *
 * @param ep  Pointer to the endpoint.
 * @return  SL_STATUS_OK on success, error code otherwise.
 ******************************************************************************/
static sl_status_t send_ack_frame(sl_cpc_ep_t *ep)
{
  sl_cpc_frame_t *frame;
  sli_cpc_hdr_t *hdr;
  sl_status_t status;

  status = sli_cpc_get_write_command_frame(ep->bus, &frame);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("Could not get ack frame (status 0x%lx) for ep: %u", (unsigned long)status, (unsigned int)ep->id);

    return status;
  }

  hdr = sli_cpc_frame_get_header(frame);

  sli_cpc_header_set_seq(hdr, 0);
  sli_cpc_header_set_address(hdr, ep->id);
  sli_cpc_header_set_payload_size(hdr, 0);

  frame->ep = sli_cpc_ep_get_ref(ep);

  transmit_frame(ep->bus, frame, true);

  return SL_STATUS_OK;
}

/***************************************************************************/ /**
 * Transmit RX window probe frame
 *
 * @note  Caller must hold lock to the endpoint prior to calling.
 *
 * @param ep  Pointer to the endpoint.
 * @return  SL_STATUS_OK on success, error code otherwise.
 ******************************************************************************/
static sl_status_t send_wnd_probe_frame(sl_cpc_ep_t *ep)
{
  sl_cpc_frame_t *frame;
  sli_cpc_hdr_t *hdr;
  sl_status_t status;

  if (ep->wnd_probe.count >= SLI_CPC_WINDOW_PROBE_MAX) {
    ep_set_error(ep, SL_STATUS_TIMEOUT);
    return SL_STATUS_OK;
  }

  status = sli_cpc_get_write_command_frame(ep->bus, &frame);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("Could not get window probe frame (status 0x%lx) for ep: %u", (unsigned long)status,
                      (unsigned int)ep->id);

    return status;
  }

  hdr = sli_cpc_frame_get_header(frame);

  sli_cpc_header_set_ack_request(hdr, true);
  sli_cpc_header_set_address(hdr, ep->id);
  sli_cpc_header_set_payload_size(hdr, 0);

  frame->ep = sli_cpc_ep_get_ref(ep);

  transmit_frame(ep->bus, frame, true);

  ep->wnd_probe.count++;
  sli_compute_window_probe_timeout(ep);

  return SL_STATUS_OK;
}

sl_status_t sli_cpc_ep_send_ack(sl_cpc_ep_t *ep)
{
  sl_status_t status;

  SLI_CPC_ASSERT(ep);

  LOCK_EP(ep);
  status = send_ack_frame(ep);
  RELEASE_EP(ep);

  return status;
}

/***************************************************************************/ /**
 * Transmit reset frame
 *
 * @param[in] bus    Pointer to the bus.
 * @param[in] address The address of the endpoint.
 ******************************************************************************/
void sli_cpc_send_reset_frame(sl_cpc_bus_t *bus, uint16_t address)
{
  sl_cpc_frame_t *frame;
  sli_cpc_hdr_t *hdr;
  sl_status_t status;

  status = sli_cpc_get_write_command_frame(bus, &frame);
  if (status != SL_STATUS_OK) {
    // CPC-3374: Defer the RST and retry when a TX frame is available instead of panicking.
    SLI_CPC_DEBUG_TRACE_CORE_TXD_RESET_FRAME_FAULT(bus);
    SLI_CPC_PANIC("Could not allocate reset frame (status 0x%lx) for ep: %u", (unsigned long)status,
                  (unsigned int)address);
  }

  SLI_CPC_DEBUG_TRACE_CORE_TXD_RESET(bus);

  hdr = sli_cpc_frame_get_header(frame);

  sli_cpc_header_set_reset(hdr, true);
  sli_cpc_header_set_ack_request(hdr, false);
  sli_cpc_header_set_seq(hdr, 0);
  sli_cpc_header_set_address(hdr, address);
  sli_cpc_header_set_payload_size(hdr, 0);
  sli_cpc_header_set_ack(hdr, 0);
  sli_cpc_header_set_rx_wnd(hdr, 0);

  frame->ep = NULL;

  transmit_frame(bus, frame, true);
}

/***************************************************************************/ /**
 * Re-transmit frame
 ******************************************************************************/
static sl_status_t re_transmit_frame(sl_cpc_ep_t *ep, sl_cpc_frame_t *frame)
{
  MCU_DECLARE_IRQ_STATE;

  SLI_CPC_ASSERT(ep != NULL);

  MCU_ENTER_ATOMIC();
  if (frame == NULL) {
    frame = on_frame_retx(ep);
  }
  MCU_EXIT_ATOMIC();

  if (frame == NULL) {
    return SL_STATUS_OK;
  }

  // Send out the frame once more
  ep->packet_re_transmit_count++;
  transmit_frame(ep->bus, frame, true);

  SLI_CPC_DEBUG_TRACE_EP_TXD_RE_TRANSMIT_FRAME(ep);
  SLI_CPC_DEBUG_TRACE_CORE_RE_TRANSMIT_FRAME(ep->bus);

  return SL_STATUS_OK;
}

/***************************************************************************/ /**
 * Get a SYN frame for the specified endpoint.
 *
 * @param[in] ep Pointer to the endpoint structure.
 * @return  Pointer to a valid frame on success, NULL on failure.
 ******************************************************************************/
static sl_cpc_frame_t *get_syn_frame(sl_cpc_ep_t *ep)
{
  sl_cpc_frame_t *frame;
  sli_cpc_hdr_t *hdr;
  sl_status_t status;

  status = sli_cpc_get_write_command_frame(ep->bus, &frame);
  if (status != SL_STATUS_OK) {
    SLI_CPC_LOG_ERROR("Could not get syn frame (status 0x%lx) for ep: %u", (unsigned long)status, (unsigned int)ep->id);
    SLI_CPC_DEBUG_TRACE_CORE_TXD_SYN_FAULT(ep->bus);

    return NULL;
  }

  hdr = sli_cpc_frame_get_header(frame);

  sli_cpc_header_set_syn(hdr, true);
  sli_cpc_header_set_ack_request(hdr, true);
  sli_cpc_header_set_address(hdr, ep->id);
  sli_cpc_header_set_payload_size(hdr, ep->mtu);

  frame->ep = sli_cpc_ep_get_ref(ep);

  return frame;
}

/***************************************************************************/ /**
 * Best-effort flush of a pending ACK during endpoint teardown.
 *
 * Unlike process_pend_ack_flag(), the flag is always cleared: the endpoint is
 * leaving the bus list, so there is no later retry opportunity.
 *
 * @note Caller must hold the endpoint lock.
 ******************************************************************************/
static void ep_flush_pend_ack(sl_cpc_ep_t *ep)
{
  if (ep->flags & SLI_CPC_EP_FLAG_PEND_ACK) {
    send_ack_frame(ep);
  }

  ep_clear_pend_ack(ep);
}

/***************************************************************************/ /**
 * Iterates through all endpoints and sends standalone ACKs for any endpoint
 * still pending after piggy-back opportunities have been processed.
 ******************************************************************************/
static void process_pend_ack_flag(sl_cpc_ep_t *ep)
{
  sl_status_t status;

  if (!(ep->flags & SLI_CPC_EP_FLAG_PEND_ACK)) {
    return;
  }

  // This could fail due to a lack of resources.
  // The pending ack flag remains set and we will retry later.
  status = send_ack_frame(ep);
  if (status == SL_STATUS_OK) {
    ep_clear_pend_ack(ep);
  }
}

/***************************************************************************/ /**
 * Arm the window probe schedule timer for a pending schedule request.
 *
 * @note Caller must hold the endpoint lock.
 ******************************************************************************/
static void process_pend_wnd_probe_schedule_flag(sl_cpc_ep_t *ep)
{
  if (!(ep->flags & SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED)) {
    return;
  }

  if (!ep_needs_wnd_probe(ep)) {
    ep->flags &= ~SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED;
    return;
  }

  // Loss retransmission owns the timer while frames are unacknowledged, or
  // a previous iteration of the loop already armed the timer.
  if (sli_cpc_timer_is_running(&ep->re_transmit_timer)) {
    return;
  }

  sli_cpc_timer_restart(&ep->re_transmit_timer, ep->wnd_probe.timeout, scheduled_wnd_probe_timer_callback, ep);
}

/***************************************************************************/ /**
 * Service a pending window probe flag on an endpoint.
 *
 * @note Caller must hold the endpoint lock.
 ******************************************************************************/
static void process_pend_wnd_probe_flag(sl_cpc_ep_t *ep)
{
  sl_status_t status;

  if (!(ep->flags & SLI_CPC_EP_FLAG_PEND_WND_PROBE)) {
    return;
  }

  ep_clear_pend_wnd_probe(ep);

  if (ep_needs_wnd_probe(ep)) {
    status = send_wnd_probe_frame(ep);
    if (status != SL_STATUS_OK) {
      ep->flags |= SLI_CPC_EP_FLAG_PEND_WND_PROBE;
    }
  }
}

/***************************************************************************/ /**
 * Iterates through all endpoints and services pending endpoint flags after
 * piggy-back opportunities have been processed.
 ******************************************************************************/
static void process_pending_flags(sl_cpc_bus_t *bus)
{
  sl_cpc_ep_t *ep;

  LOCK_EP_LIST(bus);

  SL_SLIST_FOR_EACH_ENTRY(bus->eps, ep, sl_cpc_ep_t, node)
  {
    LOCK_EP(ep);

    if (!(ep->flags
          & (SLI_CPC_EP_FLAG_PEND_ACK | SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED | SLI_CPC_EP_FLAG_PEND_WND_PROBE))) {
      RELEASE_EP(ep);
      continue;
    }

    process_pend_ack_flag(ep);
    process_pend_wnd_probe_schedule_flag(ep);
    process_pend_wnd_probe_flag(ep);

    RELEASE_EP(ep);
  }

  RELEASE_EP_LIST(bus);
}

/***************************************************************************/ /**
 * Process frames that have been sent by the driver.
 *
 * @note The frame may not have reached the end of its lifetime, as it may be
 * pending an ACK on the bus.
 ******************************************************************************/
static void process_transmit_complete(sl_cpc_bus_t *bus)
{
  sli_cpc_frame_list_t frames;
  sl_cpc_ep_t *ep;
  sl_cpc_frame_t *frame;
  MCU_DECLARE_IRQ_STATE;

  sli_cpc_frame_list_init(&frames);

  MCU_ENTER_ATOMIC();

  if (sli_cpc_frame_list_empty(&bus->transmit_completed_list)) {
    MCU_EXIT_ATOMIC();
    return;
  }

  sli_cpc_frame_list_extend(&frames, &bus->transmit_completed_list);

  MCU_EXIT_ATOMIC();

  while ((frame = sli_cpc_frame_list_pop(&frames)) != NULL) {
    ep = sli_cpc_frame_get_ep(frame);

    if (ep == NULL) {
      // Sanity check, context should always be linked to an endpoint.
      SLI_CPC_ASSERT(frame->ref_count == 1);

      goto drop_cpc_frame;
    }

    LOCK_EP(ep);

#if defined(CPC_DEBUG_TRACE)
    SLI_CPC_DEBUG_TRACE_EP_TXD_COMPLETED(ep);
    SLI_CPC_DEBUG_TRACE_CORE_TXD_TRANSMIT_COMPLETED(ep->bus);
#endif

    if (sli_cpc_header_is_ack_requested(sli_cpc_frame_get_header(frame))) {
      start_retx_timer(ep);
    }

    RELEASE_EP(ep);

drop_cpc_frame:
    sli_cpc_frame_put_ref(&frame);

    bus->tx_inflight_frame_count--;
  }

#if defined(SL_CATALOG_CPC_NG_WAKE_PRESENT)
  if (bus->tx_inflight_frame_count == 0) {
    // Finished sending all the frames, allow the core to enter sleep.
    sl_power_manager_remove_em_requirement(SL_POWER_MANAGER_EM1);
  }
#endif
}

/***************************************************************************/ /**
 * Get available RX buffer count for an endpoint
 ******************************************************************************/
static uint8_t get_ep_rx_buffer_count(const sl_cpc_ep_t *ep)
{
  return (uint8_t)SL_MIN(sl_cpc_msgq_len(&ep->rx_buffer_queue), (uint32_t)SLI_CPC_HEADER_RX_BUFFER_WINDOW_MAX);
}

/***************************************************************************/ /**
 * Iterates through all endpoints and send frames that are ready over the bus.
 ******************************************************************************/
static void process_transmit_queue(sl_cpc_bus_t *bus)
{
  sli_cpc_frame_list_t transmit_queue;
  sli_cpc_frame_list_t sent_frames;
  sl_cpc_frame_t *frame;
  sl_cpc_ep_t *ep;
  size_t avail_tx_frames;
  sli_cpc_hdr_t *hdr;

  avail_tx_frames = bus->drv_ops->get_available_write_frame_slots(bus);
  if (avail_tx_frames == 0) {
    // Driver is completely full, no more frames can be submitted. More will be sent out when
    // the core is notified of transmit completion.

    return;
  }

  // Grab the bus transmit queue and use it to iterate through the frames, so that endpoints
  // can be locked without holding the transmit queue lock. This is to prevent a potential deadlock, as
  // the endpoint will hold the endpoint and transmit queue lock when pushing a new frame. The unprocessed
  // frames will be added back to the front of the transmit queue at the end of the function.
  LOCK_TRANSMIT_QUEUE(bus);
  if (sli_cpc_frame_list_empty(&bus->transmit_queue)) {
    // No endpoint has anything to send.
    RELEASE_TRANSMIT_QUEUE(bus);

    return;
  }

  sli_cpc_frame_list_init(&transmit_queue);
  sli_cpc_frame_list_init(&sent_frames);

  sli_cpc_frame_list_extend(&transmit_queue, &bus->transmit_queue);
  RELEASE_TRANSMIT_QUEUE(bus);

  // Send as many frames as possible to the driver.
  while ((frame = sli_cpc_frame_list_pop(&transmit_queue)) != NULL) {
    hdr = sli_cpc_frame_get_header(frame);

    ep = sli_cpc_frame_get_ep(frame);
    if (ep) {
      // Update endpoint meta-data.
      LOCK_EP(ep);

      sli_cpc_header_set_ack(hdr, ep->ack);
      sli_cpc_header_set_rx_wnd(hdr, get_ep_rx_buffer_count(ep));

      ep_clear_pend_ack(ep);

      if (sli_cpc_header_is_ack_requested(hdr) && frame->tx_count == 1 && ep->rtt_sent_ticks == 0) {
        // The RTT is computed once per TX window, so we must keep track
        // of sequence number of the frame used for measurement. Also,
        // measurement must not be done on retransmitted frames as there might
        // be confusion as to which bus of the frame is being acked.
        ep->rtt_frame_seq = sli_cpc_header_get_seq(hdr);
        ep->rtt_sent_ticks = sli_cpc_timer_get_tick_count64();
      }

      RELEASE_EP(ep);
    }

#if defined(SL_CATALOG_CPC_NG_WAKE_PRESENT)
    if (bus->tx_inflight_frame_count == 0) {
      // Sending the first frame since we last idle. Prevent the device from sleeping until all
      // coming frames are sent.
      sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);
    }
#endif
    bus->tx_inflight_frame_count++;

    // CPC-2188: Don't get a ref before the frame is sent over the bus, i.e.: no ref in process re-tx
    // and move get_ref to transmit_frame.
    sli_cpc_frame_list_push_back(&sent_frames, frame);

    if (!--avail_tx_frames) {
      // Driver queue is completely full, submit to driver.
      break;
    }
  }

  if (!sli_cpc_frame_list_empty(&sent_frames)) {
    // Submit the list of frames to the driver
    bus->drv_ops->write(bus, &sent_frames);
  }

  LOCK_TRANSMIT_QUEUE(bus);
  // Extend the local transmit queue with any frames that have been queued while writing.
  sli_cpc_frame_list_extend(&transmit_queue, &bus->transmit_queue);

  // Add-back the un-sent frames to the bus transmit queue so they can be sent when more room
  // will be made available in the driver.
  sli_cpc_frame_list_extend(&bus->transmit_queue, &transmit_queue);
  RELEASE_TRANSMIT_QUEUE(bus);
}

/***************************************************************************/ /**
 * Process endpoint that are closed.
 ******************************************************************************/
static void process_closed_eps(sl_cpc_bus_t *bus)
{
  if (bus->closed_eps != NULL) {
    sl_slist_node_t *node;

    MCU_ATOMIC_SECTION(node = sl_slist_pop(&bus->closed_eps););
    do {
      sl_cpc_ep_t *ep = SL_SLIST_ENTRY(node, sl_cpc_ep_t, node);

      MCU_ATOMIC_SECTION(node = sl_slist_pop(&bus->closed_eps););

      ep_set_state(ep, SLI_CPC_STATE_CLOSED, true);

    } while (node != NULL);
  }
}

/***************************************************************************/ /**
 * Checks if an endpoint is in a state that doesn't allow receiving new frame
 ******************************************************************************/
static inline bool is_ep_closed(const sl_cpc_ep_t *ep)
{
  return ep->state == SLI_CPC_STATE_CLOSED || ep->state == SLI_CPC_STATE_CLOSING;
}

/***************************************************************************/ /**
 * Checks if an endpoint has a deferred listen pending bus initialization.
 ******************************************************************************/
static inline bool has_ep_deferred_listen(const sl_cpc_ep_t *ep)
{
  return (ep->flags & SLI_CPC_EP_FLAG_OPENED) != 0 && (ep->flags & SLI_CPC_EP_FLAG_CONNECT) == 0;
}

/***************************************************************************/ /**
 * Checks if a frame's header has unsupported flags
 ******************************************************************************/
static bool frame_has_invalid_flags(sl_cpc_frame_t *frame)
{
  const sli_cpc_hdr_t *hdr = sli_cpc_frame_get_header(frame);
  uint8_t control = sli_cpc_header_get_control(hdr);

  return control & SLI_CPC_CONTROL_RFU_Msk; // Check if reserved bits are set
}

/***************************************************************************/ /**
 * Abort frame transmission by removing it from the list.
 ******************************************************************************/
static void abort_frame_transmit(sl_cpc_frame_t *frame, sli_cpc_frame_list_t *list)
{
  if (list) {
    sli_cpc_frame_list_remove(list, frame);
  }

  frame->status = SL_STATUS_TRANSMIT_INCOMPLETE;
  sli_cpc_frame_put_ref(&frame);
}

/***************************************************************************/ /**
 * Function for freeing items in tx queues.
 * Endpoint must be locked before calling.
 ******************************************************************************/
static void clean_tx_queues(sl_cpc_ep_t *ep)
{
  sl_cpc_bus_t *bus = ep->bus;
  sl_cpc_frame_t *tmp_frame;
  sl_cpc_frame_t *frame;

  MCU_DECLARE_IRQ_STATE;

  LOCK_TRANSMIT_QUEUE(bus);

  // Enter atomic region for the following reasons:
  // - Re-transmit timer callback is an ISR and will access the expired_retransmit_list.
  SLI_CPC_FRAME_LIST_FOR_EACH_SAFE(&bus->transmit_queue, frame, tmp_frame)
  {
    if (frame->ep == ep) {
      abort_frame_transmit(frame, &bus->transmit_queue);
    }
  }

  sli_cpc_timer_stop(&ep->re_transmit_timer);

  // Cleanup expired re-transmit queues
  MCU_ENTER_ATOMIC();
  SLI_CPC_FRAME_LIST_FOR_EACH_SAFE(&bus->expired_retransmit_list, frame, tmp_frame)
  {
    if (frame->ep == ep) {
      abort_frame_transmit(frame, &bus->expired_retransmit_list);
    }
  }
  MCU_EXIT_ATOMIC();

  RELEASE_TRANSMIT_QUEUE(bus);

  // Cleanup re-transmit frame list
  while (!sli_cpc_ep_frame_list_empty(&ep->re_transmit_list)) {
    frame = sli_cpc_ep_frame_list_pop(&ep->re_transmit_list);

    abort_frame_transmit(frame, NULL);
  }

  ep->packet_re_transmit_count = 0u;
  MCU_EXIT_ATOMIC();

  // Clean holding frame list
  while (!sli_cpc_ep_frame_list_empty(&ep->holding_list)) {
    frame = sli_cpc_ep_frame_list_pop(&ep->holding_list);

    abort_frame_transmit(frame, NULL);
  }

  cancel_scheduled_wnd_probe(ep);
}

/***************************************************************************/ /**
 * CPC-2188: Handle in the CPC event loop:
 *  1) Set a flag on the endpoint to indicate it needs a re-tx & remove the expired_retransmit_list
 *  2) Lock the endpoint
 *  3) Call re_transmit_frame()
 ******************************************************************************/
static void process_expired_retransmit(void *data)
{
  sl_cpc_bus_t *bus = (sl_cpc_bus_t *)data;
  sl_cpc_frame_t *frame;
  sl_cpc_ep_t *ep;

  while (!sli_cpc_frame_list_empty(&bus->expired_retransmit_list)) {
    MCU_ATOMIC_SECTION(frame = sli_cpc_frame_list_pop(&bus->expired_retransmit_list););

    ep = sli_cpc_frame_get_ep(frame);

    LOCK_EP(ep);
    if (ep->packet_re_transmit_count >= SLI_CPC_RE_TRANSMIT) {
      // mark the endpoint as being in error
      ep_set_error(ep, SL_STATUS_TIMEOUT);
    } else {
      // RTO(new) = RTO(before retransmission) * 2
      // with an upper limit at SLI_CPC_MAX_RE_TRANSMIT_TIMEOUT_MS
      ep->re_transmit_timeout
        = SL_MIN(ep->re_transmit_timeout * 2, sli_cpc_timer_ms_to_tick(SLI_CPC_MAX_RE_TRANSMIT_TIMEOUT_MS));

      re_transmit_frame(ep, frame);
    }

    // CPC-2188: Need this hack because re_transmit_frame increments the ref_count, and we can't decrement
    // before the endpoint lock, because the ref_count could drop to 0 if a terminate would get scheduled-in.
    sli_cpc_frame_put_ref(&frame);

    RELEASE_EP(ep);
  }
}

/***************************************************************************/ /**
 * Common implementation when a retransmission occurs on an endpoint.
 ******************************************************************************/
static sl_cpc_frame_t *on_frame_retx(sl_cpc_ep_t *ep)
{
  sl_cpc_frame_t *frame;
  const sli_cpc_hdr_t *hdr;

  stop_retx_timer(ep);

  frame = sli_cpc_ep_frame_list_peek(&ep->re_transmit_list);
  if (frame == NULL) {
    return NULL;
  }

  hdr = sli_cpc_frame_get_header(frame);
  if (sli_cpc_header_get_seq(hdr) == ep->rtt_frame_seq) {
    // transmit timeout occured, invalidate the timestamp.
    // RTT should not be calculated with re-transmitted frames.
    ep->rtt_sent_ticks = 0;
  }

  // check the ref count. The frame was just peeked from endpoint's retx queue
  // so we know that the ref count is at least 1 because of that. If the ref
  // count is greater than that, it means the frame is already in use by the core
  // Abort the retransmission process in that case.
  if (frame->ref_count > 1) {
    return NULL;
  }

  return frame;
}

/***************************************************************************/ /**
 * Callback for a scheduled window probe timer expiry.
 *
 * Runs in interrupt context: update endpoint flags and signal the core.
 * Whether a probe is still required is decided later in process_pending_flags(),
 * which holds the endpoint lock.
 *
 * @Note: @p timer cannot be const as the declaration must match sleeptimer callback.
 ******************************************************************************/
static void scheduled_wnd_probe_timer_callback(sli_cpc_timer_t *timer, void *data)
{
  sl_cpc_ep_t *ep = (sl_cpc_ep_t *)data;

  (void)timer;

  ep->flags &= ~SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED;
  ep->flags |= SLI_CPC_EP_FLAG_PEND_WND_PROBE;

  sli_cpc_bus_signal_event(ep->bus, SLI_CPC_SIGNAL_TX);
}

/***************************************************************************/ /**
 * Callback for re-transmit frame
 *
 * Must match sli_cpc_timer_callback_t declaration.
 ******************************************************************************/
static void re_transmit_timeout_callback(sli_cpc_timer_t *timer, void *data)
{
  sl_cpc_ep_t *ep = data;
  sl_cpc_frame_t *frame;
  MCU_DECLARE_IRQ_STATE;

  (void)timer;

  if (ep->flags & SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED) {
    return;
  }

  MCU_ENTER_ATOMIC();
  frame = on_frame_retx(ep);
  if (frame == NULL) {
    // frame already being retransmitted
    MCU_EXIT_ATOMIC();
    return;
  }

  sli_cpc_frame_get_ref(frame);

  sli_cpc_frame_list_push_back(&ep->bus->expired_retransmit_list, frame);
  sli_cpc_dispatcher_push(&ep->bus->retransmit_dispatcher_handle, process_expired_retransmit,
                          ep->bus); //Use to push status

  MCU_EXIT_ATOMIC();
}

/***************************************************************************/ /**
 * Notify app about endpoint error. Endpoint must be locked by caller.
 ******************************************************************************/
static void notify_error(sl_cpc_ep_t *ep, sl_status_t status)
{
  sl_cpc_ep_event_t event = {.error = {.status = status}};

  ep->event_cb(ep, SL_CPC_EP_EVENT_ERROR, &event, ep->event_cb_arg);

  // Return state is irrelevant, simply want to unlock any blocking API.
  notify_state_change(ep);
}

/***************************************************************************/ /**
 * Initialize an endpoint's counters.
 ******************************************************************************/
static void initialize_ep_counters(sl_cpc_ep_t *ep)
{
  ep->ack = 0;

  ep->re_transmit_timeout = sli_cpc_timer_ms_to_tick(SLI_CPC_INIT_RE_TRANSMIT_TIMEOUT_MS);
  ep->wnd_probe.timeout = sli_cpc_timer_ms_to_tick(SLI_CPC_INIT_WINDOW_PROBE_TIMEOUT_MS);
  ep->wnd_probe.count = 0u;
  ep->rtt_sent_ticks = 0;
  ep->rtt_variation = 0;
  ep->rtt_frame_seq = 0;
  ep->smoothed_rtt = 0;

  ep->send_una = 0;
  ep->send_nxt = 0;
  ep->send_wnd = 1;

#if defined(SL_CATALOG_CPC_SECURITY_PRESENT)
  ep->frame_counter_rx = 0;
  ep->frame_counter_tx = 0;
#endif
}

/**
 * @brief Notify when all bus bring-up gates are satisfied.
 *
 * Additional gates besides control (e.g. security) can be added here.
 */
static void process_bus_initialized(sl_cpc_bus_t *bus)
{
  if (!bus->ctrl.initialized) {
    return;
  }

  if (bus->initialized) {
    return;
  }

  sli_cpc_bus_notify_initialized(bus);
}

void sli_cpc_bus_process_action(sl_cpc_bus_t *bus)
{
  sli_cpc_dispatcher_pre_process(bus);

  process_write_completions(bus);
  process_transmit_complete(bus);

#if !defined(SL_CATALOG_KERNEL_PRESENT)
  uint32_t processed;
  MCU_DECLARE_IRQ_STATE;

  MCU_ATOMIC_LOAD(processed, bus->rx_process_flag);
#endif

  process_bus_initialized(bus);

  process_received_frames(bus);

#if !defined(SL_CATALOG_KERNEL_PRESENT)
  MCU_ENTER_ATOMIC();
  bus->rx_process_flag -= processed;
  MCU_EXIT_ATOMIC();
#endif

  process_transmit_queue(bus);

  process_pending_flags(bus);

  process_closed_eps(bus);

  sli_cpc_dispatcher_process(bus);
}
