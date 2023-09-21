/*******************************************************************************
* @file  rsi_queue_rom.c
* @brief 
*******************************************************************************
* # License
* Copyright 2020 Silicon Laboratories Inc. http://www.silabs.com/
*******************************************************************************
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************/

/*==============================================*/
/*
  Include files
  */
#include "rsi_driver.h"
#ifndef ROM_WIRELESS

/** @addtogroup DRIVER16
* @{
*/
/*==============================================*/
/**
 *
 * @fn         void ROM_WL_rsi_queues_init(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
 * @brief      Initialize queue
 * @param[in]  queue       - pointer to queue 
 * @param[in]  global_cb_p - pointer to the global control block
 * @return     void
 *
 */
/// @private
void ROM_WL_rsi_queues_init(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
{
  //This statement is added only to resolve compilation warning, value is unchanged
  UNUSED_PARAMETER(global_cb_p);
  //! Initialize head pointer to NULL
  queue->head = NULL;

  // Initialize tail pointer to NULL
  queue->tail = NULL;

  // Initialize pending packet count to zero
  queue->pending_pkt_count = 0;

  // Initialize queue mask to zero
  queue->queue_mask = 0;

  // Mutex for  queues
  RSI_MUTEX_CREATE(&queue->queue_mutex);
}

/*==============================================*/
/**
 * @fn          void ROM_WL_rsi_enqueue_pkt(global_cb_t *global_cb_p, rsi_queue_cb_t *queue,rsi_pkt_t *pkt)
 * @brief       Enqueue packet into queue
 * @param[in]   global_cb_p - pointer to the global control block
 * @param[in]   queue       - pointer to queue cb 
 * @param[in]   pkt         - packet pointer which needs to be queued 
 * @return      void
 */

void ROM_WL_rsi_enqueue_pkt(global_cb_t *global_cb_p, rsi_queue_cb_t *queue, rsi_pkt_t *pkt)
{
  //This statement is added only to resolve compilation warning, value is unchanged
  UNUSED_PARAMETER(global_cb_p);
  //! take lock on queue
  RSI_MUTEX_LOCK(&queue->queue_mutex);

  // check queue is empty
  if (!queue->pending_pkt_count) {
    // if empty then add packet as first packet (head & tail point to first packet)
    queue->head = queue->tail = pkt;
  } else {
    // if not empty append the packet to list at tail
    queue->tail->next = pkt;

    // Make packet as tail
    queue->tail = pkt;
  }

  // increment packet pending count
  queue->pending_pkt_count++;

  // Unlock the queue
  RSI_MUTEX_UNLOCK(&queue->queue_mutex);
}
/*==============================================*/
/**
 * @fn          rsi_pkt_t *ROM_WL_rsi_dequeue_pkt(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
 * @brief       Dequeue packet from queue
 * @param[in]   global_cb_p - pointer to the global control block
 * @param[in]   queue       - queue pointer from which packet needs to be dequeued 
 * @return      Allocated packet pointer - Success \n
 * @return      NULL                     - Failure
 */
/// @private
rsi_pkt_t *ROM_WL_rsi_dequeue_pkt(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
{
  //This statement is added only to resolve compilation warning, value is unchanged
  UNUSED_PARAMETER(global_cb_p);
  rsi_pkt_t *pkt;

  // lock the mutex
  RSI_MUTEX_LOCK(&queue->queue_mutex);

  // check queue is empty
  if (!queue->pending_pkt_count) {

    RSI_MUTEX_UNLOCK(&queue->queue_mutex);
    // return NULL if queue is empty
    return NULL;
  }

  // dequeue the packet from queue
  pkt = queue->head;

  // update the queue head and decrement pending count
  queue->head = queue->head->next;

  // Decrease pending packet count
  queue->pending_pkt_count--;

  // if pending count is zero, then reset head and tail
  if (!queue->pending_pkt_count) {
    queue->head = NULL;
    queue->tail = NULL;
  }

  // Unlock the mutex
  RSI_MUTEX_UNLOCK(&queue->queue_mutex);

  // return the packet
  return pkt;
}
/*==============================================*/
/**
 * @fn          uint32_t ROM_WL_rsi_check_queue_status(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
 * @brief       Return packet pending count in queue
 * @param[in]   global_cb_p - pointer to the global control block
 * @param[in]   queue       - pointer to queue  
 * @return      0                         - If queue masked \n
 * @return      Number of packets pending - If queue is not masked
 */
/// @private
uint32_t ROM_WL_rsi_check_queue_status(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
{
  //This statement is added only to resolve compilation warning, value is unchanged
  UNUSED_PARAMETER(global_cb_p);
  uint32_t pkt_count = 0;

  // lock the mutex
  RSI_MUTEX_LOCK(&queue->queue_mutex);

  // check whether queue is masked or not
  if (queue->queue_mask) {

    // Unlock the mutex
    RSI_MUTEX_UNLOCK(&queue->queue_mutex);

    // if queue masked return 0
    return 0;
  } else {
    pkt_count = queue->pending_pkt_count;

    // Unlock the mutex
    RSI_MUTEX_UNLOCK(&queue->queue_mutex);

    // if queue is not masked return number of packets pending
    return pkt_count;
  }
}

/*====================================================*/
/**
 * @fn          void ROM_WL_rsi_block_queue(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
 * @brief       Block the queue.
 * @param[in]   global_cb_p - pointer to the global control block
 * @param[in]   queue -  pointer to queue
 * @return      void 
 */
/// @private
void ROM_WL_rsi_block_queue(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
{
  //This statement is added only to resolve compilation warning, value is unchanged
  UNUSED_PARAMETER(global_cb_p);
  // lock the mutex
  RSI_MUTEX_LOCK(&queue->queue_mutex);

  // Mask the queue
  queue->queue_mask = 1;

  // Unlock the mutex
  RSI_MUTEX_UNLOCK(&queue->queue_mutex);
}

/*====================================================*/
/**
 * @fn          void ROM_WL_rsi_unblock_queue(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
 * @brief       Unblock the queue.
 * @param[in]   global_cb_p - pointer to the global control block
 * @param[in]   queue 		- pointer to queue
 * @return      void
 */
/// @private
void ROM_WL_rsi_unblock_queue(global_cb_t *global_cb_p, rsi_queue_cb_t *queue)
{
  //This statement is added only to resolve compilation warning, value is unchanged
  UNUSED_PARAMETER(global_cb_p);
  // lock the mutex
  RSI_MUTEX_LOCK(&queue->queue_mutex);

  // Unmask the queue
  queue->queue_mask = 0;

  // Unlock the mutex
  RSI_MUTEX_UNLOCK(&queue->queue_mutex);
}
#endif

/*==============================================*/
/**
 * @fn          void ROM_WL_rsi_enqueue_pkt_from_isr(global_cb_t *global_cb_p, rsi_queue_cb_t *queue,rsi_pkt_t *pkt)
 * @brief       Enqueue packet from ISR into queue
 * @param[in]   global_cb_p - pointer to the global control block
 * @param[in]   queue 		- pointer to queue cb
 * @param[in]   pkt 		- packet pointer which needs to be queued
 * @return      void
 */
/// @private
void ROM_WL_rsi_enqueue_pkt_from_isr(global_cb_t *global_cb_p, rsi_queue_cb_t *queue, rsi_pkt_t *pkt)
{
  UNUSED_PARAMETER(global_cb_p); //This statement is added only to resolve compilation warning, value is unchanged
  // check queue is empty
  if (!queue->pending_pkt_count) {
    // if empty then add packet as first packet (head & tail point to first packet)
    queue->head = queue->tail = pkt;
  } else {
    // if not empty append the packet to list at tail
    queue->tail->next = pkt;

    // Make packet as tail
    queue->tail = pkt;
  }

  // increment packet pending count
  queue->pending_pkt_count++;
}
/** @} */
