/***************************************************************************/ /**
 * @file
 * @brief CPC endpoint helpers
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

#ifndef SLI_CPC_EP_H
#define SLI_CPC_EP_H

#include "sl_bit.h"
#include "sl_status.h"

#include "sl_cpc_bus.h"
#include "sl_cpc_ep.h"

#ifdef __cplusplus
extern "C" {
#endif

/// has pending ACK
#define SLI_CPC_EP_FLAG_PEND_ACK (SL_DEF_BIT(1))
/// has pending RX window probe
#define SLI_CPC_EP_FLAG_PEND_WND_PROBE (SL_DEF_BIT(2))
/// window probe send is scheduled pending timer expiry
#define SLI_CPC_EP_FLAG_WND_PROBE_SCHEDULED (SL_DEF_BIT(3))
/// Endpoint is opened (connect or listen)
#define SLI_CPC_EP_FLAG_OPENED (SL_DEF_BIT(4))
/// Deferred/immediate open is connect (0 = listen)
#define SLI_CPC_EP_FLAG_CONNECT (SL_DEF_BIT(5))
/// Control endpoint; skipped by deferred listen/connect completion
#define SLI_CPC_EP_FLAG_CONTROL (SL_DEF_BIT(6))

/**
 * @brief Take a reference on an endpoint so it cannot reach CLOSED while held.
 *
 * @p ep may be NULL; in that case this is a no-op and NULL is returned, so
 * callers can write @c frame->ep = sli_cpc_ep_get_ref(ep) unconditionally.
 *
 * @param[in] ep Endpoint to reference, or NULL.
 *
 * @return @p ep unchanged.
 */
sl_cpc_ep_t *sli_cpc_ep_get_ref(sl_cpc_ep_t *ep);

/**
 * @brief Drop a reference previously taken with @ref sli_cpc_ep_get_ref.
 *
 * When the last reference is dropped and the endpoint is closing, it is moved
 * to the closed list and @ref SL_CPC_EP_EVENT_CLOSED is delivered.
 *
 * @param[in] ep Endpoint whose reference to drop; must be non-NULL with
 *               @c ref_cnt > 0.
 */
void sli_cpc_ep_put_ref(sl_cpc_ep_t *ep);

/**
 * @brief Attach an initialized endpoint to a bus without opening it.
 *
 * Used by control-endpoint bring-up and by the public listen/connect path.
 * Does not require the bus to be initialized.
 *
 * @param[in] ep  Endpoint to attach.
 * @param[in] bus Bus that will own this endpoint.
 *
 * @retval SL_STATUS_OK                  Endpoint attached successfully, or @p ep
 *                                       is already on @p bus (e.g. deferred listen).
 * @retval SL_STATUS_NULL_POINTER        @p bus is NULL.
 * @retval SL_STATUS_INVALID_STATE       Endpoint is already attached to another
 *                                       bus, or is attached and not @c CLOSED.
 * @retval SL_STATUS_ALREADY_INITIALIZED Another endpoint with the same ID is on
 *                                       @p bus.
 */
sl_status_t sli_cpc_ep_attach(sl_cpc_ep_t *ep, sl_cpc_bus_t *bus);

/**
 * @brief Detach an endpoint from its bus.
 *
 * @param[in] ep Endpoint to detach.
 */
void sli_cpc_ep_detach(sl_cpc_ep_t *ep);

/**
 * @brief Start listening on an already-attached endpoint.
 *
 * Used once the bus is initialized, or by control-endpoint bring-up before that.
 */
sl_status_t sli_cpc_ep_listen(sl_cpc_ep_t *ep);

/**
 * @brief Start connecting an already-attached endpoint.
 *
 * Used once the bus is initialized, or by control-endpoint bring-up before that.
 */
sl_status_t sli_cpc_ep_connect(sl_cpc_ep_t *ep);

#ifdef __cplusplus
}
#endif

#endif
