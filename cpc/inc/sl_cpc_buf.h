/***************************************************************************/ /**
 * @file
 * @brief CPC buffer.
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
 * @addtogroup cpc_buf CPC Buffer
 * @brief CPC API for scatter-gather operations
 * @details
 * ## Overview
 *
 * This header defines the public buffer type used to describe CPC frame payloads,
 * helpers to allocate and link buffers, and a small FIFO queue for handing buffer
 * chains between contexts.
 *
 * A @ref sl_cpc_buf_t is a lightweight descriptor for a contiguous span of
 * memory. It does not allocate nor copy the memory at @c ptr. @ref sl_cpc_buf_t
 * can be chained together to represent a single frame. CPC transfers all the
 * buffers of a frame in a single transaction.
 *
 * ## Usage
 *
 * Use @ref sl_cpc_buf_init() to initialize static buffers or when reusing buffers,
 * @ref sl_cpc_buf_alloc() / @ref sl_cpc_buf_free() for heap-backed descriptors.
 *
 * Buffers can be chained together in a single frame with
 * @ref sl_cpc_buf_chain(). The first argument is the head of the buffer chain.
 *
 * @code{.c}
 * sl_cpc_buf_t *chunk1 = sl_cpc_buf_alloc(chunk1_len);
 * sl_cpc_buf_t *chunk2 = sl_cpc_buf_alloc(chunk2_len);
 * sl_cpc_buf_t *chunk3 = sl_cpc_buf_alloc(chunk3_len);
 *
 * sl_cpc_buf_chain(chunk1, chunk2); // chunk1 -> chunk2
 * sl_cpc_buf_chain(chunk1, chunk3); // chunk1 -> chunk2 -> chunk3
 *
 * sl_cpc_frame_t *frame = malloc(sizeof(*frame));
 * // check frame allocation
 *
 * // chunks and their payloads must remain valid until
 * // @c SL_CPC_EP_EVENT_SEND_DONE.
 * sl_status_t status = sl_cpc_ep_send(ep, chunk1, frame, NULL);
 *
 * @endcode
 ******************************************************************************/

#ifndef SL_CPC_BUF_H
#define SL_CPC_BUF_H

#include <stdalign.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "sl_common.h"
#include "sl_slist.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                                  Defines                                   */
/******************************************************************************/

/** @addtogroup cpc_buf
 * @{
 */

/// Required alignment, in bytes, of user-provided buffers handed to CPC.
#define SL_CPC_BUF_MIN_ALIGNMENT 4U

/** @} (end addtogroup cpc_buf) */

/******************************************************************************/
/*                                   Types                                    */
/******************************************************************************/

/** @addtogroup cpc_buf
 * @{
 */

/**
 * @brief CPC buffer.
 *
 * Descriptor for a contiguous payload span; buffers may be chained for scatter-gather.
 */
typedef struct sl_cpc_buf {
  /// Pointer to the next CPC buffer. This next element can be part of the
  /// same buffer chain or be the head of a new buffer chain.
  sl_slist_node_t node;

  /// Data pointer.
  void *ptr;

  /// Total length of the buffer chain. This buffer is the last element
  /// in the chain if @c len == @c tot_len.
  uint16_t tot_len;

  /// Length of the data pointed to by @c ptr.
  uint16_t len;
} sl_cpc_buf_t;

/***************************************************************************/ /**
 * @brief Initialize a CPC buffer.
 *
 * @param buf  Buffer to initialize.
 * @param ptr  Address of the data.
 * @param len  Length of the data pointed by @p ptr.
 ******************************************************************************/
static inline void sl_cpc_buf_init(sl_cpc_buf_t *buf, void *ptr, uint16_t len)
{
  buf->ptr = ptr;
  buf->len = len;
  buf->tot_len = len;
  buf->node.node = NULL;
}

/***************************************************************************/ /**
 * @brief Allocate a CPC buffer.
 *
 * @param len  Length of the buffer to allocate.
 *
 * @return Pointer to the allocated buffer, with all fields initialized; or
 *         NULL if allocation failed.
 ******************************************************************************/
static inline sl_cpc_buf_t *sl_cpc_buf_alloc(uint16_t len)
{
  size_t off;
  void *ptr;
  off = SL_DIV_ROUND_UP(sizeof(sl_cpc_buf_t), alignof(max_align_t)) * alignof(max_align_t);
  ptr = malloc(off + len);
  if (ptr != NULL) {
    sl_cpc_buf_init((sl_cpc_buf_t *)ptr, &((unsigned char *)ptr)[off], len);
  }
  return (sl_cpc_buf_t *)ptr;
}

/***************************************************************************/ /**
 * @brief Free a CPC buffer.
 *
 * @param buf Address of the buffer to free.
 ******************************************************************************/
static inline void sl_cpc_buf_free(sl_cpc_buf_t *buf)
{
  free(buf);
}

/***************************************************************************/ /**
 * @brief Append a buffer segment to a buffer chain.
 *
 * @p tail must not already be part of a chain. Repeated calls with the same
 * @p head build longer chains.
 *
 * @param[in] head First segment of the chain; must not be @c NULL.
 * @param[in] tail Segment to append; must not be @c NULL.
 ******************************************************************************/
void sl_cpc_buf_chain(sl_cpc_buf_t *head, sl_cpc_buf_t *tail);

/** @} (end addtogroup cpc_buf) */

#ifdef __cplusplus
}
#endif

#endif // SL_CPC_BUF_H
