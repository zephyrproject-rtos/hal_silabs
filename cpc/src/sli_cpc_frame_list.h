/***************************************************************************/ /**
 * @file
 * @brief CPC frame list helpers.
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

#ifndef SLI_CPC_FRAME_LIST_H
#define SLI_CPC_FRAME_LIST_H

#include "sli_cpc_frame.h"
#include "sli_cpc_list.h"
#include "sli_cpc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Frame list type
 *
 * Built directly on the generic struct sli_cpc_list (see sli_cpc_lists.h);
 * the typed wrappers below just plumb the right node field through for each
 * flavor of list a frame can belong to.
 *
 ******************************************************************************/

/**
 * @brief Convert a node back to its containing frame (using bus_node).
 */
#define SLI_CPC_FRAME_FROM_BUS_ENTRY(entry) SLI_CPC_OBJ_FROM_ENTRY((entry), sl_cpc_frame_t, bus_node)

/**
 * @brief Iterate over a frame list.
 *
 * @note It is not safe to manipulate the list while iterating.
 */
#define SLI_CPC_FRAME_LIST_FOR_EACH(list, cur) SLI_CPC_LIST_FOR_EACH((list), (cur), sl_cpc_frame_t, bus_node)

/**
 * @brief Iterate over a frame list with safe removal of the current element.
 */
#define SLI_CPC_FRAME_LIST_FOR_EACH_SAFE(list, cur, tmp) \
  SLI_CPC_LIST_FOR_EACH_SAFE((list), (cur), (tmp), sl_cpc_frame_t, bus_node)

#define sli_cpc_frame_list_init(list) sli_cpc_list_init(list)
#define sli_cpc_frame_list_empty(list) sli_cpc_list_empty(list)
#define sli_cpc_frame_list_get_len(list) sli_cpc_list_get_len(list)
#define sli_cpc_frame_list_extend(list1, list2) sli_cpc_list_extend((list1), (list2))

#define sli_cpc_frame_list_push_back(list, frame) sli_cpc_list_push_back((list), &(frame)->bus_node)
#define sli_cpc_frame_list_push_front(list, frame) sli_cpc_list_push_front((list), &(frame)->bus_node)
#define sli_cpc_frame_list_remove(list, frame) sli_cpc_list_remove((list), &(frame)->bus_node)

static inline sl_cpc_frame_t *sli_cpc_frame_list_pop(sli_cpc_frame_list_t *list)
{
  sl_slist_node_t *node = sli_cpc_list_pop(list);
  return SLI_CPC_FRAME_FROM_BUS_ENTRY(node);
}

static inline sl_cpc_frame_t *sli_cpc_frame_list_peek(const sli_cpc_frame_list_t *list)
{
  sl_slist_node_t *node = sli_cpc_list_peek(list);
  return SLI_CPC_FRAME_FROM_BUS_ENTRY(node);
}

/******************************************************************************/
// Endpoint frame list (uses @ref sli_cpc_frame::ep_node)
//
// Endpoint-level lists (re_transmit_list, holding_list) use a dedicated node
// so that a frame can simultaneously sit on a bus-level list (via
// bus_node) and an endpoint list (via ep_node).
/******************************************************************************/

#define SLI_CPC_FRAME_FROM_EP_ENTRY(entry) SLI_CPC_OBJ_FROM_ENTRY((entry), sl_cpc_frame_t, ep_node)

#define sli_cpc_ep_frame_list_init(list) sli_cpc_list_init(list)
#define sli_cpc_ep_frame_list_empty(list) sli_cpc_list_empty(list)
#define sli_cpc_ep_frame_list_push_back(list, frame) sli_cpc_list_push_back((list), &(frame)->ep_node)
#define sli_cpc_ep_frame_list_remove(list, frame) sli_cpc_list_remove((list), &(frame)->ep_node)

static inline sl_cpc_frame_t *sli_cpc_ep_frame_list_pop(sli_cpc_ep_frame_list_t *list)
{
  sl_slist_node_t *node = sli_cpc_list_pop(list);
  return SLI_CPC_FRAME_FROM_EP_ENTRY(node);
}

static inline sl_cpc_frame_t *sli_cpc_ep_frame_list_peek(const sli_cpc_ep_frame_list_t *list)
{
  sl_slist_node_t *node = sli_cpc_list_peek(list);
  return SLI_CPC_FRAME_FROM_EP_ENTRY(node);
}

#ifdef __cplusplus
}
#endif

#endif /* SLI_CPC_FRAME_LIST_H */
