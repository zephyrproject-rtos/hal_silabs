/*******************************************************************************
* @file  rsi_timer.h
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

#ifndef RSI_TIMER_H
#define RSI_TIMER_H
/******************************************************
 * *                      Macros
 * ******************************************************/
#define RSI_TIMER_NODE_0 0
/******************************************************
 * *                    Constants
 * ******************************************************/
/******************************************************
 * *                   Enumerations
 * ******************************************************/
/******************************************************
 * *                 Type Definitions
 * ******************************************************/
typedef struct rsi_timer_instance_s {
  uint32_t start_time;
  uint32_t timeout;
} rsi_timer_instance_t;
/******************************************************
 * *                    Structures
 * ******************************************************/
/******************************************************
 * *                 Global Variables
 * ******************************************************/
/******************************************************
 * *               Function Declarations
 * ******************************************************/
void rsi_timer_expiry_interrupt_handler(void);
uint32_t rsi_timer_read_counter(void);
uint32_t rsi_hal_gettickcount(void);
void rsi_init_timer(rsi_timer_instance_t *rsi_timer, uint32_t duration);
int32_t rsi_timer_expired(rsi_timer_instance_t *timer);
uint32_t rsi_timer_left(rsi_timer_instance_t *timer);

#endif
