/*******************************************************************************
* @file  rsi_error.h
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

#ifndef RSI_ERROR_H
#define RSI_ERROR_H
/******************************************************
 * *                      Macros
 * ******************************************************/
#define RSI_ERROR_REMOTE_TERNIMATE   0xFF62
#define RSI_ERROR_SOCKET_RCV_TIMEOUT 0xFF6A
#define RSI_ERROR_MQTT_PING_TIMEOUT  0xBBF1

/******************************************************
 * *                    Constants
 * ******************************************************/
/******************************************************
 * *                   Enumerations
 * ******************************************************/
// enumeration for error codes used in driver
typedef enum rsi_error_e {
  RSI_ERROR_NONE                            = 0,
  RSI_ERROR_TIMEOUT                         = -1, // Time out error
  RSI_ERROR_INVALID_PARAM                   = -2, // Invalid param error
  RSI_ERROR_COMMAND_GIVEN_IN_WRONG_STATE    = -3,
  RSI_ERROR_PKT_ALLOCATION_FAILURE          = -4,
  RSI_ERROR_COMMAND_NOT_SUPPORTED           = -5,
  RSI_ERROR_INSUFFICIENT_BUFFER             = -6,
  RSI_ERROR_IN_OS_OPERATION                 = -7,
  RSI_ERROR_INVALID_MEMORY                  = -8,
  RSI_ERROR_BOOTUP_OPTIONS_NOT_SAVED        = -9,
  RSI_ERROR_BOOTUP_OPTIONS_CHECKSUM_FAIL    = -10,
  RSI_ERROR_BOOTLOADER_VERSION_NOT_MATCHING = -11,
  RSI_ERROR_WAITING_FOR_BOARD_READY         = -12,
  RSI_ERROR_INVALID_ADDRESS                 = -13,
  RSI_ERROR_VALID_FIRMWARE_NOT_PRESENT      = -14,
  RSI_ERROR_INVALID_OPTION                  = -15,
  RSI_ERROR_EXCEEDS_MAX_CALLBACKS           = -16,
  RSI_ERROR_SET_ITIMER                      = -17,
  RSI_ERROR_SIG_ACTION                      = -18,
  RSI_ERROR_NOT_IN_CONNECTED_STATE          = -19,
  RSI_ERROR_NOT_IN_IPCONFIG_STATE           = -20,
  RSI_ERROR_SPI_BUSY                        = -21,
  RSI_ERROR_SPI_FAIL                        = -22,
  RSI_ERROR_SPI_TIMEOUT                     = -23,
  RSI_ERROR_CARD_READY_TIMEOUT              = -24,
  RSI_ERROR_BOARD_READY_TIMEOUT             = -25,
  RSI_ERROR_INVALID_PACKET                  = -26,
  RSI_ERROR_FW_UPGRADE_TIMEOUT              = -27,
  RSI_ERROR_FW_LOAD_OR_UPGRADE_TIMEOUT      = -28,
  RSI_ERROR_GPIO_WAKEUP_TIMEOUT             = -29,
  RSI_ERROR_RESPONSE_TIMEOUT                = -30,
  RSI_ERROR_BLE_DEV_BUF_FULL                = -31,
  RSI_ERROR_NWK_CMD_IN_PROGRESS             = -32,
  RSI_ERROR_SOCKET_CMD_IN_PROGRESS          = -33,
  RSI_ERROR_WLAN_CMD_IN_PROGRESS            = -34,
  RSI_ERROR_COMMON_CMD_IN_PROGRESS          = -35,
  RSI_ERROR_PROP_PROTOCOL_DEV_BUF_FULL      = -36,
  RSI_ERROR_BT_BLE_CMD_IN_PROGRESS          = -37,
  RSI_ERROR_PROP_PROTOCOL_CMD_IN_PROGRESS   = -38,
  RSI_ERROR_BLE_ATT_CMD_IN_PROGRESS         = -39,
  RSI_ERROR_MEMORY_NOT_ALIGNED              = -40,
  RSI_ERROR_SEMAPHORE_CREATE_FAILED         = -41,
  RSI_ERROR_SEMAPHORE_DESTROY_FAILED        = -42,
  RSI_ERROR_IN_WLAN_CMD                     = -43,
  RSI_ERROR_RX_BUFFER_CHECK                 = -44,
  RSI_ERROR_PARAMTER_LENGTH_EXCEEDS_MAX_VAL = -45,
  RSI_ERROR_IN_COMMON_CMD                   = -46,
  RSI_ERROR_TX_BUFFER_FULL                  = -47,
  RSI_ERROR_SDIO_TIMEOUT                    = -48,
  RSI_ERROR_SDIO_WRITE_FAIL                 = -49,
  RSI_ERROR_INVALID_SET_CONFIG_FLAG         = -50,
  RSI_ERROR_BLE_DEV_BUF_IS_IN_PROGRESS      = -51,
  RSI_ERROR_SET_REGION_NOT_ENABLED          = -52,
  RSI_ERROR_BLE_INVALID_CALLBACK_CNT        = -53,
  RSI_ERROR_BLE_ADV_EXT_COMMAND_NOT_ALLOWED = -54,
  RSI_ERROR_BLE_LEGACY_COMMAND_NOT_ALLOWED  = -55,
} rsi_error_t;

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

#endif
