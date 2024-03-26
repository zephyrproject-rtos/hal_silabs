/*******************************************************************************
* @file  rsi_firmware_upgradation.h
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

#ifndef RSI_FWUP_H
#define RSI_FWUP_H
/******************************************************
 * *                      Macros
 * ******************************************************/
// Firmware upgrade packet types
#define RSI_FWUP_RPS_HEADER  1
#define RSI_FWUP_RPS_CONTENT 0

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
int32_t rsi_fwup_start(uint8_t *rps_header);
int32_t rsi_fwup_load(uint8_t *content, uint16_t length);
int32_t rsi_ota_firmware_upgradation(uint8_t flags,
                                     uint8_t *server_ip,
                                     uint32_t server_port,
                                     uint16_t chunk_number,
                                     uint16_t timeout,
                                     uint16_t tcp_retry_count,
                                     void (*ota_fw_up_response_handler)(uint16_t status, uint16_t chunk_number));
#endif
