/*******************************************************************************
* @file  rsi_scheduler.h
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

#ifndef RSI_SCHEDULER_H
#define RSI_SCHEDULER_H
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

// scheduler control block structure
typedef struct rsi_scheduler_cb_s {
  // This bitmap is used to set and clear events
  volatile uint32_t event_map;

  // This bitmap is used to mask and unmask events
  volatile uint32_t mask_map;

  // scheduler semaphore
  rsi_semaphore_handle_t scheduler_sem;
} rsi_scheduler_cb_t;

/******************************************************
 * *                    Structures
 * ******************************************************/
/******************************************************
 * *                 Global Variables
 * ******************************************************/
/******************************************************
 * *               Function Declarations
 * ******************************************************/
void rsi_scheduler_init(rsi_scheduler_cb_t *scheduler_cb);
uint32_t rsi_get_event(rsi_scheduler_cb_t *scheduler_cb);
void rsi_scheduler(rsi_scheduler_cb_t *scheduler_cb);
uint32_t rsi_get_event_non_rom(rsi_scheduler_cb_t *scheduler_cb);

#endif
