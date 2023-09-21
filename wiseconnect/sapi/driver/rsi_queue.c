/*******************************************************************************
* @file  rsi_queue.c
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
/** @addtogroup DRIVER16
* @{
*/
/*==============================================*/
/**
 *
 * @fn         void rsi_queues_init(rsi_queue_cb_t *queue)
 * @brief      Initialize queue
 * @param[in]  queue - pointer to queue 
 * @return     void   
 *
 */
// the below group is mentioned for hiding below internal API.
/// @private
void rsi_queues_init(rsi_queue_cb_t *queue)
{
#ifdef ROM_WIRELESS
  ROMAPI_WL->rsi_queues_init(global_cb_p, queue);
#else
  api_wl->rsi_queues_init(global_cb_p, queue);
#endif
}
/*==============================================*/
/**
 * @fn          void rsi_enqueue_pkt(rsi_queue_cb_t *queue, rsi_pkt_t *pkt)
 * @brief       Enqueue packet into queue
 * @param[in]   queue - pointer to queue cb 
 * @param[in]   pkt   - packet pointer which needs to be queued
 * @return      void  
 *
 */
/// @private
void rsi_enqueue_pkt(rsi_queue_cb_t *queue, rsi_pkt_t *pkt)
{
#ifdef ROM_WIRELESS
  ROMAPI_WL->rsi_enqueue_pkt(global_cb_p, queue, pkt);
#else
  api_wl->rsi_enqueue_pkt(global_cb_p, queue, pkt);
#endif
}
/*==============================================*/
/**
 * @fn          rsi_pkt_t *rsi_dequeue_pkt(rsi_queue_cb_t *queue)
 * @brief       Dequeue packet from queue
 * @param[in]   queue - queue pointer from which packet needs to be dequeued \n 
 * @return      Allocated pocket pointer - Success \n
 * @return      NULL                     - Failure
 *
 */
/// @private
rsi_pkt_t *rsi_dequeue_pkt(rsi_queue_cb_t *queue)
{
#ifdef ROM_WIRELESS
  return ROMAPI_WL->rsi_dequeue_pkt(global_cb_p, queue);
#else
  return api_wl->rsi_dequeue_pkt(global_cb_p, queue);
#endif
}
/*==============================================*/
/**
 * @fn          uint32_t rsi_check_queue_status(rsi_queue_cb_t *queue)
 * @brief       Return packet pending count in queue
 * @param[in]   queue - pointer to queue  
 * @return      0                         - If queue masked \n
 * @return      Number of packets pending - If queue is not masked 
 */
/// @private
uint32_t rsi_check_queue_status(rsi_queue_cb_t *queue)
{
#ifdef ROM_WIRELESS
  return ROMAPI_WL->rsi_check_queue_status(global_cb_p, queue);
#else
  return api_wl->rsi_check_queue_status(global_cb_p, queue);
#endif
}

/*====================================================*/
/**
 * @fn          void rsi_block_queue(rsi_queue_cb_t *queue)
 * @brief       Block the queue.
 * @param[in]   queue - pointer to queue  
 * @return      void  
 */
/// @private
void rsi_block_queue(rsi_queue_cb_t *queue)
{
#ifdef ROM_WIRELESS
  ROMAPI_WL->rsi_block_queue(global_cb_p, queue);
#else
  api_wl->rsi_block_queue(global_cb_p, queue);
#endif
}

/*====================================================*/
/**
 * @fn          void rsi_unblock_queue(rsi_queue_cb_t *queue)
 * @brief       Unblock the queue.
 * @param[in]   queue - pointer to queue 
 * @return      void  
 */
/// @private
void rsi_unblock_queue(rsi_queue_cb_t *queue)
{
#ifdef ROM_WIRELESS
  ROMAPI_WL->rsi_unblock_queue(global_cb_p, queue);
#else
  api_wl->rsi_unblock_queue(global_cb_p, queue);
#endif
}
/** @} */
