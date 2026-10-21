/**
 * @file
 * @brief CPC list definitions.
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
 */

#ifndef SLI_CPC_LIST_H
#define SLI_CPC_LIST_H

#include "sli_cpc_assert.h"
#include "sli_cpc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                                List Macros                                 */
/******************************************************************************/

/**
 * @brief Convert a list node to its containing object.
 *
 * @param[in] node         Pointer to the node (may be NULL).
 * @param[in] type         Type of the containing object.
 * @param[in] node_field   Field name of the node in the object.
 * @return Pointer to the object containing the node, or NULL if @p node is NULL.
 */
#define SLI_CPC_OBJ_FROM_ENTRY(node, type, node_field) ((node) ? SL_SLIST_ENTRY((node), type, node_field) : NULL)

/**
 * @brief Iterate over a list of objects.
 *
 * @note It is NOT safe to manipulate the list when iterating over it.
 *
 * @param[in] list         Pointer to the list to iterate over.
 * @param[in] cur          Variable to hold the current object.
 * @param[in] type         Type of the objects on the list.
 * @param[in] node_field   Field name of the @ref sl_slist_node_t in @p type.
 */
#define SLI_CPC_LIST_FOR_EACH(list, cur, type, node_field)                            \
  for ((cur) = SLI_CPC_OBJ_FROM_ENTRY((list)->head, type, node_field); (cur) != NULL; \
       (cur) = SLI_CPC_OBJ_FROM_ENTRY((cur)->node_field.node, type, node_field))

/**
 * @brief Iterate over a list of objects safely.
 *
 * This macro allows safe removal of the current element during iteration.
 * The next element is cached before the loop body executes, so modifications
 * to the current element don't affect iteration.
 *
 * @param[in] list         Pointer to the list to iterate over.
 * @param[in] cur          Variable to hold the current object.
 * @param[in] tmp          Variable to hold the next object.
 * @param[in] type         Type of the objects on the list.
 * @param[in] node_field   Field name of the @ref sl_slist_node_t in @p type.
 */
#define SLI_CPC_LIST_FOR_EACH_SAFE(list, cur, tmp, type, node_field)                                       \
  for ((cur) = SLI_CPC_OBJ_FROM_ENTRY((list)->head, type, node_field);                                     \
       ((cur) != NULL) && (((tmp) = SLI_CPC_OBJ_FROM_ENTRY((cur)->node_field.node, type, node_field)), 1); \
       (cur) = (tmp))

/**
 * @brief Iterate over a raw @ref sl_slist_node_t head safely.
 *
 * Caches the next object before the loop body so the current element can be
 * removed without breaking iteration.
 *
 * @param[in] head         Head pointer (@c sl_slist_node_t *).
 * @param[in] cur          Variable to hold the current object.
 * @param[in] tmp          Variable to hold the next object.
 * @param[in] type         Type of the objects on the list.
 * @param[in] node_field   Field name of the @ref sl_slist_node_t in @p type.
 */
#define SLI_CPC_SLIST_FOR_EACH_ENTRY_SAFE(head, cur, tmp, type, node_field)                                \
  for ((cur) = SLI_CPC_OBJ_FROM_ENTRY((head), type, node_field);                                           \
       ((cur) != NULL) && (((tmp) = SLI_CPC_OBJ_FROM_ENTRY((cur)->node_field.node, type, node_field)), 1); \
       (cur) = (tmp))

/******************************************************************************/
/*                               List Functions                               */
/******************************************************************************/

/**
 * @brief Initialize a list.
 *
 * @param[in] list Pointer to a list.
 */
static inline void sli_cpc_list_init(struct sli_cpc_list *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

/**
 * @brief Returns whether a list is empty.
 *
 * @param[in] list Pointer to a list.
 * @return true if the list is empty, false otherwise.
 */
static inline bool sli_cpc_list_empty(const struct sli_cpc_list *list)
{
  return list->len == 0;
}

/**
 * @brief Returns the length of a list.
 *
 * @param[in] list Pointer to a list.
 * @return The length of the list.
 */
static inline uint32_t sli_cpc_list_get_len(const struct sli_cpc_list *list)
{
  return list->len;
}

/******************************************************************************
 * Node API
 *
 * These operate on the raw sl_slist_node_t. Typed wrappers (see e.g.
 * sli_cpc_frame.h) should be preferred at call sites so the right per-object
 * node field is plumbed through consistently.
 *
 ******************************************************************************/

/**
 * @brief Push a node to the back of a list.
 *
 * @param[in] list Pointer to a list.
 * @param[in] node Pointer to the node to push.
 */
static inline void sli_cpc_list_push_back(struct sli_cpc_list *list, sl_slist_node_t *node)
{
  SLI_CPC_ASSERT(node != NULL);

  node->node = NULL;

  if (list->tail == NULL) {
    list->head = node;
  } else {
    list->tail->node = node;
  }
  list->tail = node;
  list->len++;
}

/**
 * @brief Push a node to the front of a list.
 *
 * @param[in] list Pointer to a list.
 * @param[in] node Pointer to the node to push.
 */
static inline void sli_cpc_list_push_front(struct sli_cpc_list *list, sl_slist_node_t *node)
{
  SLI_CPC_ASSERT(node != NULL);

  node->node = list->head;

  if (list->tail == NULL) {
    list->tail = node;
  }
  list->head = node;
  list->len++;
}

/**
 * @brief Pop a node from the front of a list.
 *
 * @param[in] list Pointer to a list.
 * @return Pointer to the popped node, or NULL if the list is empty.
 */
static inline sl_slist_node_t *sli_cpc_list_pop(struct sli_cpc_list *list)
{
  sl_slist_node_t *node;

  if (list->head == NULL) {
    return NULL;
  }

  node = list->head;
  list->head = node->node;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  list->len--;

  node->node = NULL;

  return node;
}

/**
 * @brief Peek at the front node of a list without removing it.
 *
 * @param[in] list Pointer to a list.
 * @return Pointer to the front node, or NULL if the list is empty.
 */
static inline sl_slist_node_t *sli_cpc_list_peek(const struct sli_cpc_list *list)
{
  return list->head;
}

/**
 * @brief Extend a list with another list.
 *
 * @note On return, list1 will hold both lists and list2 will be empty.
 *
 * @param[in] list1 Pointer to the first list to be extended.
 * @param[in] list2 Pointer to the second list to be added to the first.
 */
static inline void sli_cpc_list_extend(struct sli_cpc_list *list1, struct sli_cpc_list *list2)
{
  if (sli_cpc_list_empty(list2)) {
    return;
  }

  if (sli_cpc_list_empty(list1)) {
    list1->head = list2->head;
    list1->tail = list2->tail;
    list1->len = list2->len;
  } else {
    list1->tail->node = list2->head;
    list1->tail = list2->tail;
    list1->len += list2->len;
  }

  list2->head = NULL;
  list2->tail = NULL;
  list2->len = 0;
}

/**
 * @brief Remove a specific node from a list.
 *
 * @param[in] list Pointer to a list.
 * @param[in] node Pointer to the node to remove.
 */
static inline void sli_cpc_list_remove(struct sli_cpc_list *list, sl_slist_node_t *node)
{
  sl_slist_node_t *prev = NULL;
  sl_slist_node_t *cur = list->head;

  while (cur != NULL) {
    if (cur == node) {
      if (prev == NULL) {
        // Removing head
        list->head = cur->node;
      } else {
        prev->node = cur->node;
      }

      if (cur == list->tail) {
        // Removing tail
        list->tail = prev;
      }

      cur->node = NULL;
      list->len--;
      return;
    }
    prev = cur;
    cur = cur->node;
  }
}

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_LIST_H
