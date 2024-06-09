/*******************************************************************************
* @file  rsi_http_client.h
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

#ifndef RSI_HTTP_CLIENT_H
#define RSI_HTTP_CLIENT_H
#include "rsi_driver.h"
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
#if RSI_HTTP_STATUS_INDICATION_EN
int32_t rsi_http_client_get_async(uint16_t flags,
                                  uint8_t *ip_address,
                                  uint16_t port,
                                  uint8_t *resource,
                                  uint8_t *host_name,
                                  uint8_t *extended_header,
                                  uint8_t *user_name,
                                  uint8_t *password,
                                  void (*http_client_get_response_handler)(uint16_t status,
                                                                           const uint8_t *buffer,
                                                                           const uint16_t length,
                                                                           const uint32_t moredata,
                                                                           uint16_t status_code));
int32_t rsi_http_client_post_async(uint16_t flags,
                                   uint8_t *ip_address,
                                   uint16_t port,
                                   uint8_t *resource,
                                   uint8_t *host_name,
                                   uint8_t *extended_header,
                                   uint8_t *user_name,
                                   uint8_t *password,
                                   uint8_t *post_data,
                                   uint32_t post_data_length,
                                   void (*http_client_post_response_handler)(uint16_t status,
                                                                             const uint8_t *buffer,
                                                                             const uint16_t length,
                                                                             const uint32_t moredata,
                                                                             uint16_t status_code));

int32_t rsi_http_client_post_data(uint8_t *file_content,
                                  uint16_t current_chunk_length,
                                  void (*http_client_post_response_handler)(uint16_t status,
                                                                            const uint8_t *buffer,
                                                                            const uint16_t length,
                                                                            const uint32_t moredata,
                                                                            uint16_t status_code));
#else
int32_t rsi_http_client_get_async(uint16_t flags,
                                  uint8_t *ip_address,
                                  uint16_t port,
                                  uint8_t *resource,
                                  uint8_t *host_name,
                                  uint8_t *extended_header,
                                  uint8_t *user_name,
                                  uint8_t *password,
                                  void (*http_client_get_response_handler)(uint16_t status,
                                                                           const uint8_t *buffer,
                                                                           const uint16_t length,
                                                                           const uint32_t moredata));
int32_t rsi_http_client_post_async(uint16_t flags,
                                   uint8_t *ip_address,
                                   uint16_t port,
                                   uint8_t *resource,
                                   uint8_t *host_name,
                                   uint8_t *extended_header,
                                   uint8_t *user_name,
                                   uint8_t *password,
                                   uint8_t *post_data,
                                   uint32_t post_data_length,
                                   void (*http_client_post_response_handler)(uint16_t status,
                                                                             const uint8_t *buffer,
                                                                             const uint16_t length,
                                                                             const uint32_t moredata));

int32_t rsi_http_client_post_data(uint8_t *file_content,
                                  uint16_t current_chunk_length,
                                  void (*http_client_post_response_handler)(uint16_t status,
                                                                            const uint8_t *buffer,
                                                                            const uint16_t length,
                                                                            const uint32_t moredata));
#endif
int32_t rsi_http_client_abort(void);

int32_t rsi_http_client_put_start(
  uint16_t flags,
  uint8_t *ip_address,
  uint32_t port_number,
  uint8_t *resource,
  uint8_t *host_name,
  uint8_t *extended_header,
  uint8_t *user_name,
  uint8_t *password,
  uint32_t content_length,
  void (*callback)(uint16_t status, uint8_t type, const uint8_t *buffer, uint16_t length, const uint8_t moredata));

int32_t rsi_http_client_put_delete(void);

int32_t rsi_http_client_put_pkt(uint8_t *file_content, uint16_t current_chunk_length);
int32_t rsi_http_client_put_create(void);
#endif
