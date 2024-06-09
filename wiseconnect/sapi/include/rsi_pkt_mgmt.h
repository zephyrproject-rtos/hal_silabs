/*******************************************************************************
* @file  rsi_pkt_mgmt.h
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

#ifndef RSI_PKT_MGMT_H
#define RSI_PKT_MGMT_H

#include <stdint.h>
#include <rsi_os.h>
#if ((defined RSI_SDIO_INTERFACE) && (defined CHIP_9117))
#define SIZE_OF_HEADROOM 216
#else
#define SIZE_OF_HEADROOM 0
#endif
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
// driver TX/RX packet structure
typedef struct rsi_pkt_s {
  // next packet pointer
  struct rsi_pkt_s *next;

#if ((defined RSI_SDIO_INTERFACE) && (defined CHIP_9117))
  uint8_t headroom[SIZE_OF_HEADROOM];
#endif

  // host descriptor
  uint8_t desc[16];

  // payload
  uint8_t data[1];
} rsi_pkt_t;

// packet pool structure
typedef struct rsi_pkt_pool_s {
  // Pool total packets count
  uint16_t size;

  // Pool avaialble packets count
  uint16_t avail;

  // Pool pointer
  void **pool;

  rsi_semaphore_handle_t pkt_sem;

} rsi_pkt_pool_t;

/******************************************************
 * *                    Structures
 * ******************************************************/
/******************************************************
 * *                 Global Variables
 * ******************************************************/
/******************************************************
 * *               Function Declarations
 * ******************************************************/
int32_t rsi_pkt_pool_init(rsi_pkt_pool_t *pool_cb, uint8_t *buffer, uint32_t total_size, uint32_t pkt_size);
rsi_pkt_t *rsi_pkt_alloc(rsi_pkt_pool_t *pool_cb);
int32_t rsi_pkt_free(rsi_pkt_pool_t *pool_cb, rsi_pkt_t *pkt);
uint32_t rsi_is_pkt_available(rsi_pkt_pool_t *pool_cb);
#endif
