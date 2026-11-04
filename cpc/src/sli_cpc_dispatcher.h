/***************************************************************************/ /**
 * @file
 * @brief CPC Dispatcher
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

#ifndef SLI_CPC_DISPATCHER_H
#define SLI_CPC_DISPATCHER_H

#include "sl_status.h"

#include "sli_cpc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sl_cpc_bus sl_cpc_bus_t;

/***************************************************************************/ /**
 * Initialize the dispatcher handle.
 *
 * @param[in] handle  Dispatch queue node.
 ******************************************************************************/
void sli_cpc_dispatcher_init_handle(sli_cpc_dispatcher_handle_t *handle, sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Bind the dispatcher handle to the pre-dispatch phase. Pushed work is drained
 * at the start of process_action so the dispatched function can feed the same
 * iteration's RX/TX/control processing (single-iteration latency).
 *
 * @param[in] handle  Dispatch queue node, previously initialized with
 *                    sli_cpc_dispatcher_init_handle.
 ******************************************************************************/
void sli_cpc_dispatcher_set_pre(sli_cpc_dispatcher_handle_t *handle);

/***************************************************************************/ /**
 * Push function in dispatch queue along with the data to be passed when
 * dispatched.
 *
 * @param[in] handle  Dispatch queue node.
 * @param[in] fnct    Function to be dispatched.
 * @param[in] data    Data to pass to the function.
 *
 * @return Status code.
 ******************************************************************************/
sl_status_t sli_cpc_dispatcher_push(sli_cpc_dispatcher_handle_t *handle, sli_cpc_dispatcher_fnct_t fnct, void *data);

/***************************************************************************/ /**
 * Remove function from dispatch queue along with the data to be passed when
 * dispatched.
 *
 * @param[in] handle  Dispatch queue node.
 ******************************************************************************/
void sli_cpc_dispatcher_cancel(sli_cpc_dispatcher_handle_t *handle);

/***************************************************************************/ /**
 * Process the dispatch queue.
 *
 * @brief
 *   This function empty the dispatch queue by calling all the functions
 *   registered.
 ******************************************************************************/
void sli_cpc_dispatcher_process(sl_cpc_bus_t *bus);

/***************************************************************************/ /**
 * Process the pre-dispatch queue.
 ******************************************************************************/
void sli_cpc_dispatcher_pre_process(sl_cpc_bus_t *bus);

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_DISPATCHER_H
