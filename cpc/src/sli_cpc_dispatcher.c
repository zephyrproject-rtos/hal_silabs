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

#include "sli_cpc_dispatcher.h"
#include "sli_cpc_assert.h"
#include "sli_cpc_atomic.h"
#include "sli_cpc_bus.h"

static sl_slist_node_t **handle_queue(sli_cpc_dispatcher_handle_t *handle)
{
  return handle->pre ? &handle->bus->dispatcher.pre_process_queue : &handle->bus->dispatcher.process_queue;
}

static uint8_t *handle_counter(sli_cpc_dispatcher_handle_t *handle)
{
  return handle->pre ? &handle->bus->dispatcher.pre_process_event_counter
                     : &handle->bus->dispatcher.post_process_event_counter;
}

/***************************************************************************/ /**
 * Initialize the dispatcher handle.
 ******************************************************************************/
void sli_cpc_dispatcher_init_handle(sli_cpc_dispatcher_handle_t *handle, sl_cpc_bus_t *bus)
{
  SLI_CPC_ASSERT(handle != NULL);

  handle->submitted = false;
  handle->fnct = NULL;
  handle->data = NULL;
  handle->bus = bus;
  handle->pre = false;
}

/***************************************************************************/ /**
 * Bind the dispatcher handle to the pre-dispatch phase.
 ******************************************************************************/
void sli_cpc_dispatcher_set_pre(sli_cpc_dispatcher_handle_t *handle)
{
  SLI_CPC_ASSERT(handle != NULL);
  handle->pre = true;
}

/***************************************************************************/ /**
 * Push function in dispatch queue along with the data to be passed when
 * dispatched.
 ******************************************************************************/
sl_status_t sli_cpc_dispatcher_push(sli_cpc_dispatcher_handle_t *handle, sli_cpc_dispatcher_fnct_t fnct, void *data)
{
  uint8_t *counter = handle_counter(handle);

  MCU_DECLARE_IRQ_STATE;
  MCU_ENTER_ATOMIC();

  if (handle->submitted) {
    MCU_EXIT_ATOMIC();
    return SL_STATUS_BUSY; // Already dispatched
  }

  handle->fnct = fnct;
  handle->data = data;
  sl_slist_push_back(handle_queue(handle), &handle->node);

  SLI_CPC_ASSERT(*counter < 255);
  ++*counter;

  handle->submitted = true;

  MCU_EXIT_ATOMIC();

  sli_cpc_bus_signal_event(handle->bus, SLI_CPC_SIGNAL_SYSTEM);

  return SL_STATUS_OK;
}

/***************************************************************************/ /**
 * Remove function from dispatch queue.
 ******************************************************************************/
void sli_cpc_dispatcher_cancel(sli_cpc_dispatcher_handle_t *handle)
{
  uint8_t *counter = handle_counter(handle);

  MCU_DECLARE_IRQ_STATE;

  MCU_ENTER_ATOMIC();
  if (handle->submitted) {
    sl_slist_remove(handle_queue(handle), &handle->node);

    SLI_CPC_ASSERT(*counter > 0);
    --*counter;

    handle->submitted = false;
  }
  MCU_EXIT_ATOMIC();
}

static void drain_queue(const sl_cpc_bus_t *bus, sl_slist_node_t **queue, uint8_t *counter)
{
  sl_slist_node_t *node;
  sli_cpc_dispatcher_handle_t *handle;
  uint8_t event_count_processed;
  uint8_t event_count_to_process;

  MCU_DECLARE_IRQ_STATE;

  MCU_ATOMIC_LOAD(event_count_processed, *counter);
  event_count_to_process = event_count_processed;

  do {
    // Pop and clear handle->submitted atomically so a concurrent push()/cancel()
    // cannot observe a popped-but-still-submitted handle.
    MCU_ENTER_ATOMIC();
    node = sl_slist_pop(queue);
    if (node != NULL) {
      handle = SL_SLIST_ENTRY(node, sli_cpc_dispatcher_handle_t, node);
      handle->submitted = false;
    }
    MCU_EXIT_ATOMIC();

    if (node != NULL) {
      SLI_CPC_ASSERT(handle->bus == bus);
      handle->fnct(handle->data);
    }
    if (event_count_to_process > 0) {
      --event_count_to_process;
    }
  } while (node != NULL && event_count_to_process > 0);

  // Sync the phase event counter after draining
  MCU_ENTER_ATOMIC();
  if (*counter >= event_count_processed) {
    *counter -= event_count_processed;
  } else {
    // If we are here, an event was cancelled when processing the queue
    *counter = 0;
  }
  MCU_EXIT_ATOMIC();
}

/***************************************************************************/ /**
 * Process the dispatch queue.
 ******************************************************************************/
void sli_cpc_dispatcher_process(sl_cpc_bus_t *bus)
{
  drain_queue(bus, &bus->dispatcher.process_queue, &bus->dispatcher.post_process_event_counter);
}

/***************************************************************************/ /**
 * Process the pre-dispatch queue.
 ******************************************************************************/
void sli_cpc_dispatcher_pre_process(sl_cpc_bus_t *bus)
{
  drain_queue(bus, &bus->dispatcher.pre_process_queue, &bus->dispatcher.pre_process_event_counter);
}
