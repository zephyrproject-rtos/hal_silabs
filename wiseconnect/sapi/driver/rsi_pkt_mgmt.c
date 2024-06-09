/*******************************************************************************
* @file  rsi_pkt_mgmt.c
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

/*
  Include files
  */
#include "rsi_driver.h"
/** @addtogroup DRIVER5
* @{
*/
/*==============================================*/
/**
 * @fn         int32_t rsi_pkt_pool_init(rsi_pkt_pool_t *pool_cb, uint8_t *buffer, uint32_t total_size, uint32_t pkt_size)
 * @brief      Initialize/create packet pool from the provided buffer
 * @param[in]  pool_cb    - packet pool pointer which needs to be initialized  \n 
 * @param[in]  buffer     - buffer pointer to create pool \n 
 * @param[in]  total_size - size of pool to create \n 
 * @param[in]  pkt_size   - size of each packet in pool \n 
 * @return     0              - Success \n
 * @return     Non-Zero Value - Failure
 *
 */
///@private
int32_t rsi_pkt_pool_init(rsi_pkt_pool_t *pool_cb, uint8_t *buffer, uint32_t total_size, uint32_t pkt_size)
{
#ifdef ROM_WIRELESS
  return ROMAPI_WL->rsi_pkt_pool_init(global_cb_p, pool_cb, buffer, total_size, pkt_size);
#else
  return api_wl->rsi_pkt_pool_init(global_cb_p, pool_cb, buffer, total_size, pkt_size);
#endif
}

/*==============================================*/
/**
 * @fn          rsi_pkt_t *rsi_pkt_alloc(rsi_pkt_pool_t *pool_cb)
 * @brief       Allocate packet from a given packet pool 
 * @param[in]   pool_cb - packet pool pointer from which packet needs to be allocated  
 * @return      0              - Success \n
 * @return      Non-Zero Value - Failure
 *
 */
///@private
rsi_pkt_t *rsi_pkt_alloc(rsi_pkt_pool_t *pool_cb)
{
#ifdef ROM_WIRELESS
  return ROMAPI_WL->rsi_pkt_alloc(global_cb_p, pool_cb);
#else
  return api_wl->rsi_pkt_alloc(global_cb_p, pool_cb);
#endif
}

/*==============================================*/
/**
 * @fn         int32_t rsi_pkt_free(rsi_pkt_pool_t *pool_cb, rsi_pkt_t *pkt)
 * @brief      Free the packet
 * @param[in]  pool_cb - packet pool to which packet needs to be freed  
 * @param[in]  pkt     - packet pointer which needs to be freed 
 * @return     0              - Success \n
 * @return     Non-Zero Value - Failure
 *
 */
///@private
int32_t rsi_pkt_free(rsi_pkt_pool_t *pool_cb, rsi_pkt_t *pkt)
{
#ifdef ROM_WIRELESS
  return ROMAPI_WL->rsi_pkt_free(global_cb_p, pool_cb, pkt);
#else
  return api_wl->rsi_pkt_free(global_cb_p, pool_cb, pkt);
#endif
}

/*==============================================*/
/**
 * @fn         uint32_t rsi_is_pkt_available(rsi_pkt_pool_t *pool_cb)
 * @brief      Number of available packets in pool
 * @param[in]  pool_cb - pool pointer to check available packet count 
 * @return     Number of packets in pool (>=0)
 *
 */
///@private
uint32_t rsi_is_pkt_available(rsi_pkt_pool_t *pool_cb)
{
#ifdef ROM_WIRELESS
  return ROMAPI_WL->rsi_is_pkt_available(global_cb_p, pool_cb);
#else
  return api_wl->rsi_is_pkt_available(global_cb_p, pool_cb);
#endif
}
/** @} */
