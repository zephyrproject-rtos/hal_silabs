/*******************************************************************************
* @file  rsi_bt_common_config.h
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
/**
 * @file         rsi_bt_common_config.h
 * @version      0.1
 * @date         15 Aug 2018
 *
 *
 *
 *  @brief : This file contains user configurable details to configure the device  
 *
 *  @section Description  This file contains user configurable details to configure the device 
 *
 *
 */
#ifndef RSI_BT_COMMON_CONFIG_H
#define RSI_BT_COMMON_CONFIG_H

#ifndef BD_ADDR_ARRAY_LEN
#define BD_ADDR_ARRAY_LEN 18
#endif

#ifndef RSI_LINKKEY_REPLY_SIZE
#define RSI_LINKKEY_REPLY_SIZE 16
#endif

// WLAN + BT Classic coex mode
#ifndef RSI_OPERMODE_WLAN_BT_CLASSIC
#define RSI_OPERMODE_WLAN_BT_CLASSIC 5
#endif

#ifndef RSI_BT_BLE_DUAL_MODE
#define RSI_BT_BLE_DUAL_MODE 9
#endif

#ifndef BT_GLOBAL_BUFF_LEN
#define BT_GLOBAL_BUFF_LEN 10000
#endif
/*=======================================================================*/
// Discovery command parameters
/*=======================================================================*/

// Discovery mode
// Start the discoverable mode
#ifndef START_DISCOVERY
#define START_DISCOVERY 0x01
#endif

// Start the limited discoverable mode
#ifndef START_LIMITED_DISCOVERY
#define START_LIMITED_DISCOVERY 0x02
#endif

// Stop the discoverable mode
#ifndef STOP_DISCOVERY
#define STOP_DISCOVERY 0x00
#endif
/*=======================================================================*/
// Connectability command parameters
/*=======================================================================*/

// Connectable mode
// Start the connectable mode
#ifndef CONNECTABLE
#define CONNECTABLE 0x01
#endif

// Stop the connectable mode
#ifndef NON_CONNECTABLE
#define NON_CONNECTABLE 0x00
#endif

/*=======================================================================*/
//  SSP Confirmation command parameters
/*=======================================================================*/
// Confimation type
// Accept confirmation
#ifndef ACCEPT
#define ACCEPT 0x01
#endif

// Reject confirmation
#ifndef REJECT
#define REJECT 0x00
#endif
/*=======================================================================*/
//  BT classic profile enable BITS
/*=======================================================================*/
#ifndef RSI_SPP_PROFILE_BIT
#define RSI_SPP_PROFILE_BIT BIT(0)
#endif

#ifndef RSI_A2DP_PROFILE_BIT
#define RSI_A2DP_PROFILE_BIT BIT(1)
#endif

#ifndef RSI_AVRCP_PROFILE_BIT
#define RSI_AVRCP_PROFILE_BIT BIT(2)
#endif

#ifndef RSI_HFP_PROFILE_BIT
#define RSI_HFP_PROFILE_BIT BIT(3)
#endif

#ifndef RSI_PBAP_PROFILE_BIT
#define RSI_PBAP_PROFILE_BIT BIT(4)
#endif
/*=======================================================================*/
//  A2DP Profile Related
/*=======================================================================*/

#ifndef A2DP_BURST_MODE
#define A2DP_BURST_MODE 1 //  0 - Disable, 1 - Enable
#endif

#ifndef A2DP_BURST_SIZE
#define A2DP_BURST_SIZE 1 //  Number of PCM/MP3 packets buffered
#endif

#ifndef PCM_AUDIO
#define PCM_AUDIO 1
#endif
#ifndef SBC_AUDIO
#define SBC_AUDIO 2
#endif
#ifndef MP3_AUDIO
#define MP3_AUDIO 3
#endif

#ifndef RSI_AUDIO_DATA_TYPE
#define RSI_AUDIO_DATA_TYPE SBC_AUDIO
#endif
#ifndef PCM_INPUT_BUFFER_SIZE
#define PCM_INPUT_BUFFER_SIZE 30 * 512
#endif

#ifndef MP3_INPUT_BUFFER_SIZE
#define MP3_INPUT_BUFFER_SIZE 10 * 512
#endif

#ifndef BIN_FILE
#define BIN_FILE 1
#endif
#ifndef BT_ARRAY
#define BT_ARRAY 2
#endif
#ifndef SD_BIN_FILE
#define SD_BIN_FILE 3
#endif

#ifndef RSI_AUDIO_DATA_SRC
#define RSI_AUDIO_DATA_SRC BIN_FILE
#endif

#ifndef PRE_ENC_BUF_LEN
#define PRE_ENC_BUF_LEN 8
#endif

//avdtp related defines
#ifndef ACCEPTOR_ROLE
#define ACCEPTOR_ROLE 1
#endif
#ifndef INITIATOR_ROLE
#define INITIATOR_ROLE 2
#endif
#ifndef ANY_ROLE
#define ANY_ROLE 3
#endif

#ifndef RSI_BT_MAX_PAYLOAD_SIZE
#define RSI_BT_MAX_PAYLOAD_SIZE \
  1040 // BT MTU size changes //310 /* Max supported is 200, but 190 gives optimum Tx throughput */
#endif

#ifndef BT_BDR_MODE
#define BT_BDR_MODE 0 // 1 - HP chain
#endif

#ifndef USE_REM_MTU_SIZE_ONLY
#define USE_REM_MTU_SIZE_ONLY 1
#endif

#ifndef TA_BASED_ENCODER
#define TA_BASED_ENCODER 0
#endif

#endif //RSI_BT_COMMON_CONFIG_H
