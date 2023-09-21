/*******************************************************************************
* @file  rsi_timer.c
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
#include "rsi_timer.h"
#include "rsi_hal.h"

/** @addtogroup DRIVER11
* @{
*/
/*==============================================*/
/**
 * @fn          void rsi_timer_expiry_interrupt_handler(void) 
 * @brief       Called for every millisecond and increments the timer counter.
 * @param[in]   void   
 * @return      void 
 *
 */

void rsi_timer_expiry_interrupt_handler(void)
{
  rsi_driver_cb_non_rom->timer_counter++;
#ifdef RSI_SPI_INTERFACE
#ifdef RSI_HWTIMER
  rsi_driver_cb_non_rom->rsi_spiTimer2++;
  rsi_driver_cb_non_rom->rsi_spiTimer1++;
  rsi_driver_cb_non_rom->rsi_spiTimer3++;
#endif
#endif
}

/*==============================================*/
/**
 * @fn           uint32_t rsi_timer_read_counter()
 * @brief        Read the timer counter value 
 * @param[in]    void 
 * @return       Timer counter value in milliseconds 
 *
 */

uint32_t rsi_timer_read_counter(void)
{
  return rsi_hal_gettickcount();
}

/*==============================================*/
/**
 * @fn            void rsi_init_timer(rsi_timer_instance_t *rsi_timer, uint32_t duration)
 * @brief         Initialize the timer instance
 * @param[in]     rsi_timer - timer instance 
 * @param[in]     duration  - duration in milli seconds  
 * @return        Void 
 *
 */

void rsi_init_timer(rsi_timer_instance_t *rsi_timer, uint32_t duration)
{
  rsi_timer->start_time = rsi_timer_read_counter();
  rsi_timer->timeout    = duration;
}

/*==============================================*/
/**
 * @fn           int32_t rsi_timer_expired(rsi_timer_instance_t *timer)
 * @brief        Check if the timer instance is expired
 * @param[in]    rsi_timer - timer instance 
 * @return       1 - if timer is expired \n 
 * @return       0 - if timer is not expired 
 *              
 */

int32_t rsi_timer_expired(rsi_timer_instance_t *timer)
{
  if ((rsi_timer_read_counter() - (timer->start_time)) > (timer->timeout))
    return 1;
  else
    return 0;
}

/*==============================================*/
/**
 * @fn           uint32_t rsi_timer_left(rsi_timer_instance_t *timer)
 * @brief        Get the remaining time for timer expiry. 
 * @param[in]    rsi_timer - timer instance
 * @return       Positive value - Time left to expire \n 
 * @return       0              - Timer is expired 
 *
 */

uint32_t rsi_timer_left(rsi_timer_instance_t *timer)
{
  int32_t left = (timer->timeout) - (rsi_timer_read_counter() - (timer->start_time));
  return (left < 0) ? 0 : left;
}
/** @} */
