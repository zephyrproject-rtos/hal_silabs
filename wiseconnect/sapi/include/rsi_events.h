/*******************************************************************************
* @file  rsi_events.h
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

#ifndef RSI_EVENTS_H
#define RSI_EVENTS_H
/******************************************************
 * *                      Macros
 * ******************************************************/
#ifndef RSI_M4_INTERFACE
#ifdef RSI_ENABLE_DEMOS
// Max number events used in the driver
#define RSI_MAX_NUM_EVENTS 5

// RX event number used in the driver
#define RSI_RX_EVENT 1

// TX event number used in the driver
#define RSI_TX_EVENT 0

// Socket event number used in the driver
#define RSI_SOCKET_EVENT 2

// Application event1 number used in driver
#define RSI_APP_EVENT1 3

// Application event1 number used in driver
#define RSI_APP_EVENT2 4

#else

// Max number events used in the driver
#define RSI_MAX_NUM_EVENTS 3

// RX event number used in the driver
#define RSI_RX_EVENT       0

// TX event number used in the driver
#define RSI_TX_EVENT       1

// Socket event number used in the driver
#define RSI_SOCKET_EVENT   2

#endif
#else

// Max number events used in the driver
#define RSI_MAX_NUM_EVENTS 2

// RX event number used in the driver
#define RSI_RX_EVENT       1

// TX event number used in the driver
#define RSI_TX_EVENT       0

#endif

/******************************************************
 * *                    Constants
 * ******************************************************/
/******************************************************
 * *                   Enumerations
 * ******************************************************/
/******************************************************
 * *                 Type Definitions
 * ******************************************************/

// event handler structure
typedef struct rsi_event_cb_s {
  // event handler pointer
  void (*event_handler)(void);
} rsi_event_cb_t;

/******************************************************
 * *                    Structures
 * ******************************************************/
/******************************************************
 * *                 Global Variables
 * ******************************************************/
/******************************************************
 * *               Function Declarations
 * ******************************************************/

uint16_t rsi_register_event(uint32_t event_id, void (*event_handler_ptr)(void));
uint32_t rsi_find_event(uint32_t event_map);
void rsi_set_event(uint32_t event_num);
void rsi_clear_event(uint32_t event_num);
void rsi_mask_event(uint32_t event_num);
void rsi_unmask_event(uint32_t event_num);
void rsi_tx_event_handler(void);
void rsi_rx_event_handler(void);
void rsi_set_event_from_isr(uint32_t event_num);
void rsi_unmask_event_from_isr(uint32_t event_num);
rsi_error_t rsi_semaphore_post_from_isr(rsi_semaphore_handle_t *semaphore);
#ifndef RSI_M4_INTERFACE

#ifdef RSI_ENABLE_DEMOS

#if (BT_A2DP_SOURCE_WIFI_HTTP_S_RX || BLE_DUAL_MODE_BT_A2DP_SOURCE_WIFI_HTTP_S_RX \
     || BT_A2DP_SOURCE_WIFI_HTTP_S_RX_DYN_COEX)
void rsi_app_event1_handler(void);
void rsi_app_event2_handler(void);
#endif

#endif

void rsi_socket_event_handler(void);
#endif
void rsi_events_init(void);

#endif
