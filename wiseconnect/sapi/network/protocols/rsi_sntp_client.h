/*******************************************************************************
* @file  rsi_sntp_client.h
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

#ifndef RSI_SNTP_CLIENT_H
#define RSI_SNTP_CLIENT_H
/******************************************************
 * *                      Macros
 * ******************************************************/
#ifndef RSI_IPV6
#define RSI_IPV6 1
#endif

//SNTP Method to USe
#define RSI_SNTP_BROADCAST_MODE 1

//SNTP Method to USe
#define RSI_SNTP_UNICAST_MODE 2

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
int32_t rsi_sntp_client_create_async(uint8_t flags,
                                     uint8_t *server_ip,
                                     uint8_t sntp_method,
                                     uint16_t sntp_timeout,
                                     void (*rsi_sntp_client_create_response_handler)(uint16_t status,
                                                                                     const uint8_t cmd_type,
                                                                                     const uint8_t *buffer));
int32_t rsi_sntp_client_gettime(uint16_t length, uint8_t *sntp_time_rsp);
int32_t rsi_sntp_client_gettime_date(uint16_t length, uint8_t *sntp_time_date_rsp);
int32_t rsi_sntp_client_server_info(uint16_t length, uint8_t *sntp_server_response);
int32_t rsi_sntp_client_delete_async(void);
#endif
