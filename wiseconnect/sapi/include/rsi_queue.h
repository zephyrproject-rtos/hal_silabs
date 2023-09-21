/*******************************************************************************
* @file  rsi_queue.h
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

#ifndef RSI_QUEUE_H
#define RSI_QUEUE_H
/******************************************************
 * *                      Macros
 * ******************************************************/

/******************************************************
 * *                    Constants
 * ******************************************************/
/******************************************************
 * *                   Enumerations
 * ******************************************************/
/******************************************************
 * *                 Type Definitions
 * ******************************************************/
/******************************************************
 * *                    Structures
 * ******************************************************/

// queue structure
typedef struct rsi_queue_cb_s {
  // queue head
  rsi_pkt_t *head;

  // queue tail
  rsi_pkt_t *tail;

  // number of packets pending in queue
  volatile uint16_t pending_pkt_count;

  // mask status of the queue
  uint16_t queue_mask;

  // Mutex handle to queues
  rsi_mutex_handle_t queue_mutex;

} rsi_queue_cb_t;

/******************************************************
 * *                 Global Variables
 * ******************************************************/
/******************************************************
 * *               Function Declarations
 * ******************************************************/
extern void rsi_queues_init(rsi_queue_cb_t *queue);
extern void rsi_enqueue_pkt(rsi_queue_cb_t *queue, rsi_pkt_t *pkt);
extern rsi_pkt_t *rsi_dequeue_pkt(rsi_queue_cb_t *queue);
extern uint32_t rsi_check_queue_status(rsi_queue_cb_t *queue);
extern void rsi_block_queue(rsi_queue_cb_t *queue);
extern void rsi_unblock_queue(rsi_queue_cb_t *queue);
#endif
