/***************************************************************************/ /**
 * @file
 * @brief CPC frame accessors and pool API.
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

#ifndef SLI_CPC_FRAME_H
#define SLI_CPC_FRAME_H

#include <stdint.h>
#include <string.h>

#include "sl_cpc.h"
#include "sl_cpc_frame.h"
#include "sli_cpc_assert.h"
#include "sli_cpc_crc.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                               Inline helpers                               */
/******************************************************************************/

/**
 * @brief Initialise a CPC frame's CPC-internal fields to a clean state.
 *
 * @param[in] frame  Frame to initialize.
 */
static inline void sli_cpc_frame_init(sl_cpc_frame_t *frame)
{
  memset(frame, 0, sizeof(*frame));

  frame->ref_count = 1;
}

/**
 * @brief Get a pointer to the CPC header inside a frame.
 */
static inline sli_cpc_hdr_t *sli_cpc_frame_get_header(sl_cpc_frame_t *frame)
{
  return &frame->hdr;
}

/**
 * @brief Compute payload checksum in software.
 *
 * @param[in] buf Buffer.
 * @return The computed checksum.
 */
static inline uint16_t sli_cpc_get_csum_payload(const sl_cpc_buf_t *buf)
{
  return sli_cpc_get_crc_sw(buf->ptr, buf->len);
}

/**
 * @brief Increment the frame reference counter.
 */
static inline sl_cpc_frame_t *sli_cpc_frame_get_ref(sl_cpc_frame_t *frame)
{
  if (frame) {
    SLI_CPC_ASSERT(frame->ref_count > 0);
    frame->ref_count++;
  }

  return frame;
}

/**
 * @brief Decrement the frame reference counter.
 *
 * Calls the destructor and clears the caller's pointer when the count hits 0.
 */
static inline void sli_cpc_frame_put_ref(sl_cpc_frame_t **frame_ptr)
{
  if (*frame_ptr) {
    SLI_CPC_ASSERT((*frame_ptr)->ref_count > 0);

    (*frame_ptr)->ref_count--;

    if ((*frame_ptr)->ref_count == 0) {
      if ((*frame_ptr)->destructor) {
        (*frame_ptr)->destructor(*frame_ptr);
      }

      *frame_ptr = NULL;
    }
  }
}

/**
 * @brief Get the endpoint associated with a frame, or NULL.
 */
static inline sl_cpc_ep_t *sli_cpc_frame_get_ep(const sl_cpc_frame_t *frame)
{
  return frame->ep;
}

/******************************************************************************/
/*                 Private API (defined in sli_cpc_frame.c)                  */
/******************************************************************************/

/**
 * @brief Initialize the per-bus CPC frame memory pools.
 *
 * @param[in] bus                   CPC bus.
 * @param[in] rx_frame_pool_count   Number of RX frames in the pool.
 * @param[in] tx_frame_pool_count   Number of TX frames in the pool.
 *
 * @return SL_STATUS_OK on success, error code otherwise.
 */
sl_status_t sli_cpc_frame_mempool_init(sl_cpc_bus_t *bus, uint16_t rx_frame_pool_count, uint16_t tx_frame_pool_count);

/**
 * @brief Tear down the per-bus CPC frame memory pools.
 *
 * @param[in] bus CPC bus.
 */
void sli_cpc_frame_mempool_deinit(sl_cpc_bus_t *bus);

/**
 * @brief Allocate a new CPC frame from the per-bus pool.
 *
 * @param[in] bus       CPC bus.
 * @param[in] is_rx      Whether this frame is an RX frame.
 *
 * @return Pointer to the allocated frame, or NULL on failure.
 */
sl_cpc_frame_t *sli_cpc_frame_new(sl_cpc_bus_t *bus, bool is_rx);

/**
 * @brief Free a CPC frame back to its pool.
 *
 * @param[in] frame Address of the pointer to free.
 */
void sli_cpc_frame_free(sl_cpc_frame_t *frame);

#ifdef __cplusplus
}
#endif

#endif /* SLI_CPC_FRAME_H */
