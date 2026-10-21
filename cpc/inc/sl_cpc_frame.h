/***************************************************************************/ /**
 * @file
 * @brief CPC frame structure.
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

#ifndef SL_CPC_FRAME_H
#define SL_CPC_FRAME_H

#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>

#include "sl_component_catalog.h"
#include "sl_slist.h"
#include "sl_status.h"

#include "sl_cpc_buf.h"
#include "sli_cpc_types.h"

#if defined(SL_CATALOG_CPC_SECURITY_PRESENT)
#include "sl_cpc_security_config.h"
#endif

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

typedef struct sl_cpc_ep sl_cpc_ep_t;

typedef struct sl_cpc_bus sl_cpc_bus_t;

/**
 * @brief CPC frame.
 *
 * A single frame structure used internally by CPC for both RX and TX flows.
 */
typedef struct sl_cpc_frame {
  /// Node in bus-level lists (TX queue, RX list, etc.).
  sl_slist_node_t bus_node;

  /// Node in endpoint-level lists (re_transmit_list, holding_list).
  sl_slist_node_t ep_node;

  /// Owning CPC bus (used for pool routing).
  sl_cpc_bus_t *bus;

  /// User payload buffer.
  sl_cpc_buf_t *payload;

  /// Whether this frame is an RX frame.
  bool is_rx;

  /// Header (must be ADMA-aligned; SDIO DMAs this buffer directly).
  alignas(SL_CPC_BUF_MIN_ALIGNMENT) sli_cpc_hdr_t hdr;

#if defined(SL_CATALOG_CPC_SECURITY_PRESENT)
  void *security_tag;
#endif

  /// Payload checksum.
  uint16_t payload_csum;

  /// RX validity / TX cached-state for payload checksum.
  bool payload_csum_is_valid;

  /// Reference counter.
  uint8_t ref_count;

  /// Associated endpoint, if any.
  sl_cpc_ep_t *ep;

  /// Per-send opaque user context from @ref sl_cpc_ep_send.
  void *arg;

  /// Number of times pushed to driver for TX.
  uint8_t tx_count;

  /// Completion status.
  sl_status_t status;

  /// Called when @ref ref_count drops to zero.
  void (*destructor)(struct sl_cpc_frame *frame);
} sl_cpc_frame_t;

/** @} (end addtogroup cpc) */

#ifdef __cplusplus
}
#endif

#endif // SL_CPC_FRAME_H
