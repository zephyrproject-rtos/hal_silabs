/***************************************************************************/ /**
 * @file
 * @brief CPC Internal Memory Functions
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SLI_CPC_MEMORY_H
#define SLI_CPC_MEMORY_H

#include "sl_status.h"

#include "sl_cpc_msgq.h"
#include "sli_cpc_bus.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/ /**
 * @brief Get a CPC command frame.
 *
 * @param[in] bus       Pointer to bus to operate on.
 * @param[out] frame_ptr   Pointer to store the retrieved frame.
 *
 * @return Status code indicating operation result
 ******************************************************************************/
sl_status_t sli_cpc_get_write_command_frame(sl_cpc_bus_t *bus, sl_cpc_frame_t **frame_ptr);

/***************************************************************************/ /**
 * Allocate a reception payload for the specified frame.
 *
 * @note Caller must ensure that a valid header was decoded to the frame by
 * calling `sli_cpc_header_decode`.
 *
 * @param[in] bus  Pointer to bus to operate on.
 * @param[in] frame   Pointer to the frame.
 *
 * @return Status code.
 ******************************************************************************/
sl_status_t sli_cpc_alloc_rx_payload(const sl_cpc_bus_t *bus, sl_cpc_frame_t *frame);

/***************************************************************************/ /**
 * Build a buffer chain from a message queue of same-size buffers.
 *
 * Pop buffer from the message queue and chain them together to create a buffer
 * chain with a total length of @p total_len. All buffers in the chain have an
 * underlying buffer length that is a multiple of @ref SL_CPC_BUF_MIN_ALIGNMENT,
 * so the returned buffer chain is guaranteed to have allocated at least
 * `ROUND_UP(buf->tot_len, SL_CPC_BUF_MIN_ALIGNMENT)` bytes. Drivers can use
 * these extra bytes for trailing padding.
 *
 * @param[in] msgq       Pointer to the message queue.
 * @param[in] total_len  Total length of the chain to build.
 *
 * @return Head of the buffer chain.
 ******************************************************************************/
sl_cpc_buf_t *sli_cpc_buffer_chain_alloc(sl_cpc_msgq_t *msgq, uint16_t total_len);

/***************************************************************************/ /**
 * Release a buffer chain back to a message queue.
 *
 * Unlinks each segment of @p buf and pushes it to the back of @p msgq. Each segment's
 * @c len and @c tot_len are restored to @p reset_len before it is pushed.
 *
 * @param[in] msgq       Pointer to the message queue.
 * @param[in] buf        Head of the buffer chain to release.
 * @param[in] reset_len  Segment length to restore, or 0 to leave lengths unchanged.
 ******************************************************************************/
void sli_cpc_buffer_chain_release(sl_cpc_msgq_t *msgq, sl_cpc_buf_t *buf, uint16_t reset_len);

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_MEMORY_H
