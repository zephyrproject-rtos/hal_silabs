/*******************************************************************************
* @file  rsi_pop3_client.h
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

#ifndef RSI_POP3_CLIENT_H
#define RSI_POP3_CLIENT_H

#include <stdint.h>
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

// To create the POP3 session
int32_t rsi_pop3_session_create(uint8_t flags,
                                uint8_t *server_ip_address,
                                uint16_t server_port_number,
                                uint8_t auth_type,
                                uint8_t *username,
                                uint8_t *password,
                                void (*rsi_pop3_response_handler)(uint16_t status, uint8_t type, uint8_t *buffer));
int32_t rsi_pop3_session_create_async(uint8_t flags,
                                      uint8_t *server_ip_address,
                                      uint16_t server_port_number,
                                      uint8_t auth_type,
                                      uint8_t *username,
                                      uint8_t *password,
                                      void (*rsi_pop3_client_mail_response_handler)(uint16_t status,
                                                                                    uint8_t type,
                                                                                    const uint8_t *buffer));

// Delete the POP3 session
int32_t rsi_pop3_session_delete(void);

// Get the number of mails count and total size of the mails
int32_t rsi_pop3_get_mail_stats(void);

// Get the mail size of the passed mail index
int32_t rsi_pop3_get_mail_list(uint16_t mail_index);

// Get the mail header and mail body of the passed mail index
int32_t rsi_pop3_retrive_mail(uint16_t mail_index);

// Mail will be marked as deleted on the POP3 server for the passed mail index
int32_t rsi_pop3_mark_mail(uint16_t mail_index);

// Any messages/mails marked as deleted in the current session will be unmarked
int32_t rsi_pop3_unmark_mail(void); /* or rsi_pop3_reset(void);*/

// Get the connection status of the POP3 server
int32_t rsi_pop3_get_server_status(void);

#endif
