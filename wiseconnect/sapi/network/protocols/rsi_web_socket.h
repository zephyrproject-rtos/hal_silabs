/*******************************************************************************
* @file  rsi_web_socket.h
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

#ifndef RSI_WEB_SOCKET_H
#define RSI_WEB_SOCKET_H

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
/******************************************************
 * *                 Global Variables
 * ******************************************************/
/******************************************************
 * *               Function Declarations
 * ******************************************************/
int32_t rsi_web_socket_create(int8_t flags,
                              uint8_t *server_ip_addr,
                              uint16_t server_port,
                              uint16_t device_port,
                              uint8_t *webs_resource_name,
                              uint8_t *webs_host_name,
                              int32_t *socket_id,
                              void (*web_socket_data_receive_notify_callback)(uint32_t sock_no,
                                                                              uint8_t *buffer,
                                                                              uint32_t length));
int32_t rsi_web_socket_send_async(int32_t sockID, uint8_t opcode, int8_t *msg, int32_t msg_length);
int32_t rsi_web_socket_close(int32_t sockID);
#endif
