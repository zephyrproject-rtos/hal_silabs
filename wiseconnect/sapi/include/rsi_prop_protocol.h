/*******************************************************************************
* @file  rsi_prop_protocol.h
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

#ifndef RSI_PROP_PROTOCOL_H
#define RSI_PROP_PROTOCOL_H

#include <rsi_data_types.h>
#include <rsi_bt_common.h>
#include <rsi_ble_apis.h>

typedef void (*rsi_prop_protocol_resp_handler_t)(uint8_t *data);
typedef void (*rsi_prop_protocol_data_request_callback_t)(void);
// Driver PROP_PROTOCOL control block
typedef struct rsi_prop_protocol_cb_s {
  //PROP_PROTOCOL CBFC callbacks
  rsi_prop_protocol_resp_handler_t prop_protocol_async_resp_handler;
  rsi_prop_protocol_data_request_callback_t rsi_prop_protocol_data_request_callback;
} rsi_prop_protocol_cb_t;

void rsi_prop_protocol_common_tx_done(rsi_pkt_t *pkt);
void rsi_prop_protocol_callbacks_handler(rsi_bt_cb_t *, uint16_t rsp_type, uint8_t *payload, uint16_t payload_length);
int32_t rsi_driver_process_prop_protocol_resp(
  rsi_bt_cb_t *,
  rsi_pkt_t *pkt,
  void (*rsi_bt_async_callback_handler)(rsi_bt_cb_t *cb, uint16_t type, uint8_t *data, uint16_t length));
#define RSI_OPERMODE_PROP_PROTOCOL 0x109

#endif
