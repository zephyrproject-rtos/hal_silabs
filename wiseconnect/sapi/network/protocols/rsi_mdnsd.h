/*******************************************************************************
* @file  rsi_mdnsd.h
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

#ifndef RSI_MDNSD_H
#define RSI_MDNSD_H

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
int32_t rsi_mdnsd_init(uint8_t ip_version, uint16_t ttl, uint8_t *host_name);
#ifndef CHIP_9117
int32_t rsi_mdnsd_register_service(uint16_t port,
                                   uint16_t ttl,
                                   uint8_t more,
                                   uint8_t *service_ptr_name,
                                   uint8_t *service_name,
                                   uint8_t *service_text);
#else
int32_t rsi_mdnsd_register_service(uint16_t port,
                                   uint16_t ttl,
                                   uint8_t *type,
                                   uint8_t *sub_type,
                                   uint8_t *service_name,
                                   uint8_t *service_text);
#endif
int32_t rsi_mdnsd_deinit(void);
#endif
