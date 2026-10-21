/***************************************************************************/ /**
 * @file
 * @brief CPC Message Queue Implementation.
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

#include <stdint.h>

#include "sl_slist.h"

#include "sl_cpc_buf.h"
#include "sl_cpc_msgq.h"

#include "sli_cpc_assert.h"
#include "sli_cpc_atomic.h"

static sl_cpc_buf_t *chain_tail(sl_cpc_buf_t *buf)
{
  while (buf->tot_len != buf->len) {
    SLI_CPC_ASSERT(buf->node.node);
    buf = SL_SLIST_ENTRY(buf->node.node, sl_cpc_buf_t, node);
  }

  return buf;
}

void sl_cpc_msgq_init(sl_cpc_msgq_t *msgq)
{
  msgq->head = NULL;
  msgq->tail = NULL;
  msgq->len = 0;
}

void sl_cpc_msgq_push(sl_cpc_msgq_t *msgq, sl_cpc_buf_t *buf)
{
  sl_cpc_buf_t *c_end;
  MCU_DECLARE_IRQ_STATE;

  SLI_CPC_ASSERT(msgq != NULL);

  if (buf == NULL) {
    return;
  }

  c_end = chain_tail(buf);
  c_end->node.node = NULL;

  MCU_ENTER_ATOMIC();
  if (msgq->tail == NULL) {
    msgq->head = &buf->node;
  } else {
    msgq->tail->node = &buf->node;
  }

  msgq->tail = &c_end->node;
  msgq->len++;
  MCU_EXIT_ATOMIC();
}

bool sl_cpc_msgq_pop(sl_cpc_msgq_t *msgq, sl_cpc_buf_t **out_buf)
{
  sl_cpc_buf_t *c_head;
  sl_cpc_buf_t *c_tail;
  sl_slist_node_t *n;
  MCU_DECLARE_IRQ_STATE;

  if (out_buf == NULL)
    return false;

  MCU_ENTER_ATOMIC();
  if (!msgq->head) {
    SLI_CPC_ASSERT(msgq->len == 0);
    MCU_EXIT_ATOMIC();

    return false;
  }

  n = msgq->head;
  c_head = SL_SLIST_ENTRY(n, sl_cpc_buf_t, node);
  c_tail = chain_tail(c_head);

  msgq->head = c_tail->node.node;
  if (msgq->head == NULL) {
    msgq->tail = NULL;
  }
  msgq->len--;
  MCU_EXIT_ATOMIC();

  c_tail->node.node = NULL;
  *out_buf = c_head;
  return true;
}
