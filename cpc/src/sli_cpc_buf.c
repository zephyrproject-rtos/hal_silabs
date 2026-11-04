/***************************************************************************/ /**
 * @file
 * @brief CPC Buffer implementation.
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

#include "sl_slist.h"

#include "sl_cpc_buf.h"

#include "sli_cpc_assert.h"

static sl_cpc_buf_t *from_node(sl_slist_node_t *node)
{
  return node ? SL_SLIST_ENTRY(node, sl_cpc_buf_t, node) : NULL;
}

void sl_cpc_buf_chain(sl_cpc_buf_t *head, sl_cpc_buf_t *tail)
{
  sl_cpc_buf_t *prev;
  sl_cpc_buf_t *cur;

  if (tail == NULL || head == tail) {
    return;
  }

  SLI_CPC_ASSERT(head != NULL);
  SLI_CPC_ASSERT(tail->node.node == NULL);
  SLI_CPC_ASSERT(head->tot_len < UINT16_MAX - tail->len);

  for (cur = head, prev = head; cur != NULL; prev = cur, cur = from_node(cur->node.node)) {
    cur->tot_len += tail->len;
  }

  prev->node.node = &tail->node;
  tail->tot_len = tail->len;
}
