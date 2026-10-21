/***************************************************************************/ /**
 * @file
 * @brief CPC message queue.
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

/***************************************************************************/ /**
 * @addtogroup cpc_msgq CPC Message Queue
 * @brief FIFO queue of buffer chains.
 * @details
 * ## Overview
 *
 * An @ref sl_cpc_msgq_t is a thread-safe FIFO of buffer chains. Each
 * @ref sl_cpc_msgq_push() enqueues one chain (a single @ref sl_cpc_buf_t or a
 * head linked with @ref sl_cpc_buf_chain()). Each @ref sl_cpc_msgq_pop() removes
 * the oldest chain and returns its head; segment links inside that chain are
 * unchanged.
 *
 * Typical use is to defer handling of @c SL_CPC_EP_EVENT_RECV buffers
 * out of the CPC callback into a main loop or worker task.
 *
 * ## Usage
 *
 * Initialize with @ref sl_cpc_msgq_init() before use. A buffer must not be linked
 * into another chain or queue when it is pushed; the tail segment's @c next must
 * be @c NULL.
 *
 * Use @ref sl_cpc_msgq_is_empty() and @ref sl_cpc_msgq_len() to inspect the queue.
 * @ref sl_cpc_msgq_len() counts buffer chains (one per push), not segments within
 * a chain.
 *
 * @code{.c}
 * sl_cpc_msgq_t msgq;
 * sl_cpc_buf_t seg1;
 * sl_cpc_buf_t seg2;
 * sl_cpc_buf_t single;
 * sl_cpc_buf_t *out;
 *
 * sl_cpc_msgq_init(&msgq);
 *
 * sl_cpc_buf_init(&seg1, payload1, len1);
 * sl_cpc_buf_init(&seg2, payload2, len2);
 * sl_cpc_buf_chain(&seg1, &seg2);
 * sl_cpc_msgq_push(&msgq, &seg1); // one queue entry (two segments: seg1 -> seg2)
 *
 * sl_cpc_buf_init(&single, payload3, len3);
 * sl_cpc_msgq_push(&msgq, &single); // second entry; sl_cpc_msgq_len() is 2
 *
 * sl_cpc_msgq_pop(&msgq, &out);
 * // First pop: `out` points to `seg1` (head of the first push). `seg1` still
 * // links to `seg2`; the queue now holds only single buffer.
 *
 * sl_cpc_msgq_pop(&msgq, &out);
 * // Second pop: `out` points to `single`. The queue is empty.
 * @endcode
 ******************************************************************************/

#ifndef SL_CPC_MSGQ_H
#define SL_CPC_MSGQ_H

#include <stdbool.h>
#include <stddef.h>

#include "sl_slist.h"

#include "sl_cpc_buf.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                                   Types                                    */
/******************************************************************************/

/** @addtogroup cpc_msgq
 * @{
 */

/**
 * @brief Message queue for buffer chains.
 *
 * FIFO of buffer chains (one entry per @ref sl_cpc_msgq_push).
 */
typedef struct sl_cpc_msgq {
  /// List head, points to the node of the first sl_cpc_buf_t in the message queue
  sl_slist_node_t *head;

  /// List tail, points to the last element of the last buffer chain that was
  /// pushed to the message queue.
  sl_slist_node_t *tail;

  /// Number of buffer chains in the queue (one per @ref sl_cpc_msgq_push()).
  size_t len;
} sl_cpc_msgq_t;

/***************************************************************************/ /**
 * @brief Initialize message queue.
 *
 * @param[in] msgq Message queue.
 ******************************************************************************/
void sl_cpc_msgq_init(sl_cpc_msgq_t *msgq);

/***************************************************************************/ /**
 * @brief Push a buffer chain to the back of message queue.
 *
 * @param[in] msgq Message queue.
 * @param[in] buf  Head of the buffer chain.
 ******************************************************************************/
void sl_cpc_msgq_push(sl_cpc_msgq_t *msgq, sl_cpc_buf_t *buf);

/***************************************************************************/ /**
 * @brief Pop a buffer chain from message queue.
 *
 * @param[in] msgq Message queue.
 * @param[out] out_buf Address of a pointer to a buffer chain's head.
 *
 * @return True if a buffer chain is popped from the list.
 ******************************************************************************/
bool sl_cpc_msgq_pop(sl_cpc_msgq_t *msgq, sl_cpc_buf_t **out_buf);

/***************************************************************************/ /**
 * @brief Test whether a message queue has no entries.
 *
 * @param[in] msgq Message queue.
 *
 * @return True if the queue is empty.
 ******************************************************************************/
static inline bool sl_cpc_msgq_is_empty(const sl_cpc_msgq_t *msgq)
{
  return !msgq->head;
}

/***************************************************************************/ /**
 * @brief Get the number of buffer chains in a message queue.
 *
 * Each @ref sl_cpc_msgq_push() adds one entry (which may be a multi-segment
 * chain). This function does not count segments within a chain.
 *
 * @param[in] msgq Message queue.
 *
 * @return Number of queued buffer chains.
 ******************************************************************************/
static inline size_t sl_cpc_msgq_len(const sl_cpc_msgq_t *msgq)
{
  return msgq->len;
}

/** @} (end addtogroup cpc_msgq) */

#ifdef __cplusplus
}
#endif

#endif // SL_CPC_MSGQ_H
