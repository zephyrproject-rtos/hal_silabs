/***************************************************************************/ /**
* @file  sli_nwp.h
* @brief This is for Host-NWP interface.
*        This contains all the user command IDs and response/event IDs,
*        payloads, status/error codes and the functions that can be used by
*        Host to interface with NWP.
 *******************************************************************************
 * # License
 * <b>Copyright 2024-2026 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef SLI_NWP_H
#define SLI_NWP_H

#include <stdint.h>
#include <stddef.h>

/******************************************************************************/
/* Section layout:
 * - Common definitions
 * - Host SDK frames - request/response IDs
 * - Host SDK frames - async indication IDs
 * - Host SDK frames - payloads
 * - Internal management frames - Tx request IDs
 * - Internal management frames - Rx response/indication IDs
 * - Internal management frames - payloads
 * - Global / per-command status codes
 ******************************************************************************/

/******************************************************************************/
/************************* Common definitions *********************************/
/******************************************************************************/
#ifndef BIT
#define BIT(x) ((uint32_t)1 << (x))
#endif

#define SLI_WIFI_SSID_LEN          34
#define SLI_WIFI_PSK_LEN           64
#define SL_WIFI_MAC_ADDRESS_LENGTH 6

#define SLI_WIFI_COUNTRY_CODE_LENGTH 3

/// Enumeration for Wi-Fi security types.
typedef enum {
  SL_WIFI_OPEN                       = 0,  ///< Wi-Fi Open security type
  SL_WIFI_WPA                        = 1,  ///< Wi-Fi WPA security type
  SL_WIFI_WPA2                       = 2,  ///< Wi-Fi WPA2 security type
  SL_WIFI_WEP                        = 3,  ///< Wi-Fi WEP security type
  SL_WIFI_WPA_ENTERPRISE             = 4,  ///< Wi-Fi WPA enterprise security type
  SL_WIFI_WPA2_ENTERPRISE            = 5,  ///< Wi-Fi WPA2 enterprise security type
  SL_WIFI_WPA_WPA2_MIXED             = 6,  ///< Wi-Fi WPA/WPA2 mixed security type that supports both WPA and WPA2
  SL_WIFI_WPA3                       = 7,  ///< Wi-Fi WPA3 security type
  SL_WIFI_WPA3_TRANSITION            = 8,  ///< Wi-Fi WPA3 Transition security type (not currently supported in AP mode)
  SL_WIFI_WPA3_ENTERPRISE            = 9,  ///< Wi-Fi WPA3 enterprise security type
  SL_WIFI_WPA3_TRANSITION_ENTERPRISE = 10, ///< Wi-Fi WPA3 Transition enterprise security type
} sl_wifi_security_t;

/// TX power related macros (signed deci-dBm for LMAC)
/// (e.g. 200 = +20.0 dBm, -50 = -5.0 dBm)
/// Minimum transmit power in decidBm (tenths of dBm).
#define SLI_WIFI_TX_POWER_DECIDBM_MIN (-150) ///< -15.0 dBm
/// Maximum transmit power in decidBm (tenths of dBm).
#define SLI_WIFI_TX_POWER_DECIDBM_MAX (310) ///< +31.0 dBm

/// Generic SL MAC address type
typedef struct {
  uint8_t octet[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< MAC address
} sl_mac_address_t;

/******************************************************************************/
/***************** Host SDK frames — command IDs ******************************/
/******************************************************************************/

#define SLI_WIFI_CMD_BOOTCONFIG                   0x10
#define SLI_WIFI_CMD_OPERMODE                     SLI_WIFI_CMD_BOOTCONFIG
#define SLI_WIFI_CMD_BAND                         0x11
#define SLI_WIFI_CMD_INIT                         0x12
#define SLI_WIFI_CMD_SCAN                         0x13
#define SLI_WIFI_CMD_JOIN                         0x14
#define SLI_WIFI_CMD_SET_MAC_ADDRESS              0x17
#define SLI_WIFI_CMD_QUERY_NETWORK_PARAMS         0x18
#define SLI_WIFI_CMD_DISCONNECT                   0x19
#define SLI_WIFI_CMD_ANTENNA_SELECT               0x1B
#define SLI_WIFI_CMD_SET_REGION                   0x1D
#define SLI_WIFI_CMD_AP_CONFIGURATION             0x24
#define SLI_WIFI_CMD_TWT_AUTO_CONFIG              0x2E
#define SLI_WIFI_CMD_TWT_PARAMS                   0x2F
#define SLI_WIFI_CMD_VENDOR_IE                    0x38
#define SLI_WIFI_CMD_WIFI_SIGNAL_QUALITY_STATS    0x3B
#define SLI_WIFI_CMD_RESCHEDULE_TWT               0x3F
#define SLI_WIFI_CMD_SET_MULTICAST_FILTER         0x40
#define SLI_WIFI_CMD_WMM_PARAMS                   0x45
#define SLI_WIFI_CMD_GAIN_TABLE                   0x47
#define SLI_WIFI_CMD_TSF                          0x65
#define SLI_WIFI_CMD_EXT_STATS                    0x68
#define SLI_WIFI_CMD_BG_SCAN                      0x6A
#define SLI_WIFI_CMD_HT_CAPABILITIES              0x6D
#define SLI_WIFI_CMD_REJOIN_PARAMS                0x6F
#define SLI_WIFI_CMD_WPS_METHOD                   0x72
#define SLI_WIFI_CMD_DMP_CONFIGURATION            0x78
#define SLI_WIFI_CMD_SET_TRANSCEIVER_CHANNEL      0x7A
#define SLI_WIFI_CMD_TX_TEST_MODE                 0x7C
#define SLI_WIFI_CMD_RATE                         0x87
#define SLI_WIFI_CMD_TRANSCEIVER_PEER_LIST_UPDATE 0x8B
#define SLI_WIFI_CMD_TRANSCEIVER_CONFIG_PARAMS    0x8C
#define SLI_WIFI_CMD_SET_TRANSCEIVER_MCAST_FILTER 0x8D
#define SLI_WIFI_CMD_TRANSCEIVER_FLUSH_DATA_Q     0x8E
#define SLI_WIFI_CMD_WIFI_RAIL                    0x99
#define SLI_WIFI_CMD_TX_TEST_STATS                0xA2
#define SLI_WIFI_CMD_AP_STOP                      0xAE
#define SLI_WIFI_CMD_SET_REGION_AP                0xBD
#define SLI_WIFI_CMD_CONFIG                       0xBE
#define SLI_WIFI_CMD_GET_CSI_DATA                 0xC4
#define SLI_WIFI_COMMON_CMD_FEATURE_FRAME         0xC8
#define SLI_WIFI_CMD_FILTER_BCAST_PACKETS         0xC9
#define SLI_WIFI_CMD_FULL_FW_VERSION              0xE0
#define SLI_WIFI_CMD_TIMEOUT                      0xEA
#define SLI_WIFI_CMD_GET_STATS                    0xF1
#define SLI_WIFI_CMD_FREQ_OFFSET                  0xF3
#define SLI_WIFI_CMD_11AX_PARAMS                  0xFF

/******************************************************************************/
/***************** Host SDK frames — async indication IDs *********************/
/******************************************************************************/

#define SLI_WIFI_IND_TRANSCEIVER_TX_DATA_STATUS 0x3D
#define SLI_WIFI_IND_TWT_ASYNC                  0x71
#define SLI_WIFI_IND_SCAN_RESULTS               0xAF

/******************************************************************************/
/**************************** Host SDK payloads *******************************/
/******************************************************************************/

/************ SLI_WIFI_CMD_BOOTCONFIG (0x10) **********************************/
/**
 * @brief Select the device operating mode and boot-time feature configuration.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific, Connection Manager) to
 * configure opermode, features and device capabilities.
 * Management interface validates and translates @c vif_type, stores
 * selected feature bitmaps, and may clear unsupported configuration bits before
 * forwarding the request.
 * In concurrent mode, UMAC creates both STA and AP VAPs and derives the AP MAC
 * address from the default device MAC address.
 * Opermodes supported: All
 *
 * - Request payload:
 *   @ref sl_wifi_system_boot_configuration_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SL_STATUS_FAIL - Concurrent AP MAC address cannot be derived.
 *   - Response payload:
 *     - None
 */

/// Macros related to @c vif_type
#define SLI_NWP_OP_ACCESS_POINT  0x0 ///< Wi-Fi access point mode
#define SLI_NWP_OP_STATION       0x1 ///< Wi-Fi station mode
#define SLI_NWP_OP_P2P_GO        0x2 ///< Wi-Fi P2P group owner mode
#define SLI_NWP_OP_P2P_CLIENT    0x3 ///< Wi-Fi P2P client mode
#define SLI_NWP_OP_TRANSCEIVER   0x7 ///< Wi-Fi transceiver mode
#define SLI_NWP_OP_TRANSMIT_TEST 0x8 ///< Wi-Fi transmit test mode
#define SLI_NWP_OP_CONCURRENT    0x9 ///< Wi-Fi concurrent mode

/************ Feature bitmaps *********/

/* Feature bitmap (feature_bit_map) */
#define SL_WIFI_FEAT_SECURITY_OPEN        BIT(0) ///< Used in management interface only; Reserved
#define SL_WIFI_FEAT_SECURITY_PSK         BIT(1) ///< Used in management interface only; Reserved
#define SL_WIFI_FEAT_AGGREGATION          BIT(2) ///< Supports AMPDU for both TX and RX
#define SL_WIFI_FEAT_WPS_DISABLE          BIT(7) ///< Used in management interface only
#define SL_WIFI_FEAT_EAP_LEAP_IN_COEX     BIT(8) ///< Used in management interface only
#define SL_WIFI_FEAT_HIDE_PSK_CREDENTIALS BIT(9) ///< Used in management interface only
#define SL_WIFI_FEAT_TRANSCEIVER_MAC_PEER_DS_SUPPORT \
  BIT(13) /* Enables support to store peer information in the MAC layer in Transceiver mode of operation */
#define SL_WIFI_FEAT_DISABLE_11AX_11AC_SUPPORT \
  BIT(15) /* Force DUT connection (in station mode) to use 11n, disabling 11ax connections */

/* TCP/IP feature bitmap (tcp_ip_feature_bit_map) */
#define SL_WIFI_TCP_IP_FEAT_EXTENSION_VALID BIT(31) /* This bit indicates the @c ext_tcp_ip_feature_bit_map is valid */

/* Custom feature bitmap (custom_feature_bit_map) */
/// When enabled, the AP is created in hidden mode (SSID is not broadcasted)
#define SL_WIFI_CUSTOM_FEAT_AP_IN_HIDDEN_MODE BIT(5)
/// Enables scanning of DFS channels in the 5 GHz band (STA only)
/// Used in management interface for validation only
#define SL_WIFI_CUSTOM_FEAT_DFS_CHANNEL_SUPPORT BIT(8)
/// Enables asynchronous WLAN connection status indication to the host (STA only)
/// Used in management interface only
#define SL_WIFI_CUSTOM_FEAT_ASYNC_CONNECTION_STATUS BIT(10)
/// Enables AP blacklisting in Station (STA) mode.
/// Used in management interface only
#define SL_WIFI_CUSTOM_FEAT_ENABLE_AP_BLACKLIST BIT(12)
/// Selects between de-authentication or null data (with power management bit set) for roaming
/// Used in management interface only
#define SL_WIFI_CUSTOM_FEAT_ROAM_WITH_NULL_DATA BIT(17)
/// Enables dual-band roaming and VCSAFD (Virtual Channel Scan and Frequency Avoidance Detection) feature
#define SL_WIFI_CUSTOM_FEAT_DUAL_BAND_ROAM_VCSAFD BIT(27)
/// This bit indicates the @c ext_custom_feature_bit_map is valid
#define SL_WIFI_SYSTEM_CUSTOM_FEAT_EXTENSION_VALID BIT(31)

/* Extended custom feature bitmap (ext_custom_feature_bit_map) */
#define SL_WIFI_EXT_FEAT_ANTENNA_DIVERSITY BIT(0)
/// Supports 4096 size RSA KEY certificate
/// Used in management interface only
#define SL_WIFI_EXT_FEAT_RSA_KEY_WITH_4096_SUPPORT BIT(1)
#define SL_WIFI_EXT_FEAT_PREAUTH_SUPPORT_ENABLE    BIT(5)
/// Activates support for 802.11R (Fast BSS Transition) Over The Air Roaming
/// Used in management interface only
#define SL_WIFI_EXT_FEAT_ENABLE_11R_OTA BIT(11)
///< Used in management interface only
#define SL_WIFI_EXT_FEAT_IEEE_80211J BIT(12)
/// Enable 802.11W protocol.
#define SL_WIFI_EXT_FEAT_IEEE_80211W BIT(13)
/// Enable 802.11R Over the Distribution System Roaming
/// Used in management interface only
#define SL_WIFI_EXT_FEAT_ENABLE_11R_ODS BIT(16)
/// Disable the WoWLAN (Wake-on-Wireless-LAN) feature.
#define SL_WIFI_EXT_FEAT_WOWLAN_DISABLE BIT(17)
/// Used in management interface only; Never set
#define SL_WIFI_EXT_FEAT_ENABLE_GTK_REKEY_DATA BIT(17)
/// Disable auto correction of XTAL (40 MHz crystal)
#define SL_WIFI_EXT_FEAT_DISABLE_XTAL_CORRECTION BIT(18)
#define SL_WIFI_EXT_FEAT_XTAL_CLK_ENABLE         (BIT(23) | BIT(22))
#define SL_WIFI_EXT_FEAT_BATTERY_VOLTAGE_0       BIT(25)
#define SL_WIFI_EXT_FEAT_BATTERY_VOLTAGE_1       BIT(26)
#define SL_WIFI_EXT_FEAT_PIN_SELECT_BIT_LOCATION 29

/* Extended TCP/IP feature bitmap (ext_tcp_ip_feature_bit_map) */
#define SL_WIFI_CONFIG_FEAT_EXTENSION_VALID BIT(31) ///< This bit indicates the @c config_feature_bit_map is valid

/* Config feature bitmap (config_feature_bit_map) */
/// Selects the GPIO for wakeup indication to the host
#define SL_WIFI_FEAT_SLEEP_GPIO_SEL_BITMAP BIT(0)
/// Enables TLS version 1.0 for enterprise security
/// Used in management interface only; Reserved
#define SL_WIFI_FEAT_EAP_TLS_V1P0 BIT(14)
/// Enables TLS version 1.2 for enterprise security
/// Used in management interface only; Reserved
#define SL_WIFI_FEAT_EAP_TLS_V1P2                            BIT(15)
#define SL_WIFI_FEAT_ENABLE_ACTIVE_HIGH_INTERRUPT_FOR_WOWLAN BIT(16)
#define SL_WIFI_FEAT_ENABLE_LMAC_MISC                        (BIT(24) | BIT(25) | BIT(26) | BIT(27) | BIT(28) | BIT(29) | BIT(30) | BIT(31))

/// Boot configuration structure
typedef struct {
  uint16_t vif_type;                   ///< VIF type
  uint16_t coex_mode;                  ///< Reserved
  uint32_t feature_bit_map;            ///< Feature bitmap
  uint32_t tcp_ip_feature_bit_map;     ///< TCP/IP feature bitmap; Qualifies @c ext_tcp_ip_feature_bit_map
  uint32_t custom_feature_bit_map;     ///< Custom feature bitmap
  uint32_t ext_custom_feature_bit_map; ///< Extended custom feature bitmap; Used when
                                       ///< @c SL_WIFI_SYSTEM_CUSTOM_FEAT_EXTENSION_VALID is set in
                                       ///< @c custom_feature_bit_map
  uint32_t bt_feature_bit_map;         ///< Reserved
  uint32_t ext_tcp_ip_feature_bit_map; ///< Extended TCP/IP feature bitmap; Qualifies @c config_feature_bit_map
  uint32_t ble_feature_bit_map;        ///< Reserved
  uint32_t ble_ext_feature_bit_map;    ///< Reserved
  uint32_t config_feature_bit_map;     ///< Config feature bitmap; Used when @c SL_WIFI_CONFIG_FEAT_EXTENSION_VALID is
                                       ///< set in @c ext_tcp_ip_feature_bit_map
} sl_wifi_system_boot_configuration_t;

/************ SLI_WIFI_CMD_BAND (0x11) ****************************************/
/**
 * @brief Set the device operating band.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific) to configure the
 * operating band, AP-channels, supported standard rate bitmap,
 * and max transmit-power per channel during device bring-up.
 * This configuration (except AP channels) will be applied across all
 * active VAPs (AP, STA). AP channels will be applied only to AP VAP.
 *
 * - Request payload:
 *   @ref sl_wifi_band_mode_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_INVALID_BAND - NWP received an unsupported band value.
 *   - Response payload:
 *     - None
 */
#define SL_WIFI_BAND_MODE_2_4GHZ 0 ///< 2.4 GHz Wi-Fi band
#define SL_WIFI_BAND_MODE_5GHZ   1 ///< 5 GHz Wi-Fi band
#define SL_WIFI_DUAL_BAND_MODE   2 ///< Both 2.4 GHz and 5 GHz Wi-Fi band

typedef uint8_t sl_wifi_band_mode_t; ///< Band mode

/************ SLI_WIFI_CMD_INIT (0x12) ****************************************/
/**
 * @brief Initialize Wi-Fi VAP after boot configuration.
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP/STA FSM) to initialize the VAP
 * and drive MAC bring-up through LMAC configuration frames.
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_ALREADY_IN_ASSOCIATED_STATE - VAP is already in connected state
 *   - Response payload (consumed only in management interface):
 *     - 6-byte MAC (single interface), or
 *     - 12-byte MACs (concurrent; STA MAC followed by AP MAC)
 */

/************ SLI_WIFI_CMD_SCAN (0x13) ****************************************/
/**
 * @brief Initiates a Wi-Fi scan operation.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to start an active/passive
 * scan on channels configured in the scan request
 *
 * - Request payload:
 *   @ref sli_wifi_request_scan_t; Sent from Host SDK to management interface.
 *   @ref sli_mgmtif_request_scan_t; Extended scan structure sent from
 *   management interface to NWP.
 *
 * - Response (to Host SDK):
 *   - Immediate failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_NO_AP_FOUND - No AP found, or no valid channel available to scan
 *     - @c SLI_STATUS_INVALID_CHANNEL - Channel or channel-bitmap validation failed
 *     - @c SLI_STATUS_ALREADY_IN_ASSOCIATED_STATE - VAP is already in connected state
 *   - Response payload:
 *     - None
 *
 * @note During scan, beacons and probe responses may be forwarded as
 *       @c SLI_WIFI_IND_ON_AIR_MGMT
 */

/* Scan feature bitmap (scan_feature_bitmap) */
/// Stop scan early on SSID match
#define SLI_WIFI_FEATURE_SELECT_QUICK_SCAN BIT(0)

/// Bypass supplicant scan handling; Used in management interface only.
#define SLI_WIFI_FEATURE_SCAN_SUPPLICANT_BYPASS BIT(1)

/// SDK-MGMTIF: When enabled, populates @c bssid (stored from an earlier JOIN request)
/// Host-NWP: Used to contruct a BSSID-directed probe request
#define SLI_WIFI_FEATURE_BSSID_BASED_SCAN BIT(2)

/* Passive scan bitmap (pscan_bitmap) */
#define SLI_WIFI_ENABLE_LP_CHAIN     BIT(14) ///< Select LP chain for scan
#define SLI_WIFI_ENABLE_PASSIVE_SCAN BIT(15) ///< Enable passive scans

/// Scan command request structure
typedef struct {
  uint8_t
    channel[4]; ///< Channel number to scan; Valid range: 1–14 for 2.4 GHz, 36–165 for 5 GHz or 0 to scan all channels
                ///< Selects the scan channel or all-channel scan (restricted by
                ///< @c channel_bit_map_2_4, @c channel_bit_map_5 bitmap, if configured).
                ///< Channel index 1, 2, 3 - Reserved
  uint8_t ssid[SLI_WIFI_SSID_LEN]; ///< SSID to scan; zero-length string = broadcast scan
                                   ///< SDK-MGMTIF: Stores directed scan SSID for downstream BG scan, result matching.
                                   ///< HOST-NWP: Selects directed vs broadcast probe requests.
  uint16_t pscan_bitmap;           ///< Passive scan bitmap
                                   ///< SDK-MGMTIF: Stores passive-scan bitmap for later NWP scan requests.
                                   ///< HOST-NWP: Enables passive scan and LP-chain selection.
  int16_t power_level;             ///< Scan TX power in deci-dBm (tenths of dBm).
                                   ///< Valid range: @c SLI_WIFI_TX_POWER_DECIDBM_MIN - @c SLI_WIFI_TX_POWER_DECIDBM_MAX
  uint8_t _reserved;               ///< Reserved
  uint8_t scan_feature_bitmap;     ///< Scan feature bitmap
                                   ///< SDK-MGMTIF: May clear quick-scan for broadcast scans; stores bitmap for
                                   ///< result handling.
                                   ///< HOST-NWP: Configures quick scan, BSSID filter, and scan TX power.
  uint8_t channel_bit_map_2_4[2];  ///< 2.4 GHz channel bitmap
                                   ///< SDK-MGMTIF: May fill defaults or host-selected masks before forwarding.
                                   ///< HOST-NWP: Restricts 2.4 GHz channels scanned.
  uint8_t channel_bit_map_5[4];    ///< 5 GHz channel bitmap
                                   ///< SDK-MGMTIF: May fill defaults or host-selected masks before forwarding.
                                   ///< HOST-NWP: Restricts 5 GHz channels scanned.
} __attribute__((packed)) sli_wifi_request_scan_t;

/// Extended scan command request structure
typedef struct {
  sli_wifi_request_scan_t scan_req;           ///< Scan request parameters from Host SDK
  uint8_t set_scan_channel_bitmask_from_user; ///< Reserved
  uint8_t bssid[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< Optional BSSID filter when @c SLI_WIFI_FEATURE_BSSID_BASED_SCAN is set
} sli_mgmtif_request_scan_t;

/************ SLI_WIFI_CMD_JOIN (0x14) ****************************************/
/**
 * @brief In STA mode, connect to the given Wi-Fi AP. In AP mode, start the
 * Wi-Fi access point (AP) interface.
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP/STA FSM). In STA mode,
 * drives the connect sequence (probe / auth / assoc, or quick-join /
 * reassociation). In AP mode, brings up the AP VAP for beacon emission and
 * per-STA admission.
 * Management interface builds the extended JOIN structure, and in STA mode
 * appends selected-AP scan-confirm data before forwarding to NWP.
 *
 * - Request payload:
 *   @ref sli_wifi_join_request_t; Sent from Host SDK to management interface.
 *   @ref sli_mgmtif_join_request_t; Extended join request sent from management
 *   interface to NWP. In STA mode, @c sta_ext_info appends
 *   @ref sli_wifi_sta_join_ap_info_t.
 *
 * - Response:
 *   - Immediate failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error/status codes:
 *     - @c SLI_STATUS_ALREADY_IN_ASSOCIATED_STATE - VAP is already in connected state
 *     - @c SLI_STATUS_ASSOCIATION_FAILED - Association failed
 *     - @c SLI_STATUS_ASSOCIATION_TIMEOUT - Association response timed out
 *     - @c SLI_STATUS_AUTHENTICATION_TIMEOUT - Authentication response timed out
 *     - @c SLI_STATUS_CONNECTED_AP_OR_STATION_CHANNEL_MISMATCH - STA join channel does not
 *       match the connected concurrent AP channel
 *     - @c SLI_STATUS_FOUR_WAY_HANDSHAKE_FAILED - EAPOL 4-way handshake failed during STA
 *       connect
 *     - @c SLI_STATUS_INVALID_FIXED_RATE - Requested fixed rate is not valid
 *     - @c SLI_STATUS_INVALID_PMKID - PMKID validation failed
 *     - @c SLI_STATUS_MEMORY_FAILED_FROM_MODULE - Memory allocation failed while processing JOIN
 *     - @c SLI_STATUS_JOIN_SAE_TRIGGER - SAE authentication must be completed by supplicant
 *     - @c SLI_STATUS_MISSED_SYNCHRONIZATION - Failed to receive response from the AP
 *
 *   - Async @c SLI_WIFI_CMD_JOIN error codes
 *     - @c SLI_STATUS_MAX_BEACON_MISCOUNT - Deauthenticated after missed beacons
 *     - @c SLI_STATUS_DEAUTH_DUE_TO_CHANNEL_CHANGE - Deauthenticated due to channel change
 *     - @c SLI_STATUS_DEAUTH_REQUEST_FROM_SUPPLICANT - Deauthenticated by the supplicant
 *     - @c SLI_STATUS_DEAUTH_REQUEST_FROM_FROM_AP - Deauth received after channel
 *       switch
 *     - @c SA_QUERY_TIMEOUT - SA Query triggered during deauth handling timed out
 *     - @c SLI_STATUS_DEAUTHENTICATION_RECEIVED_FROM_AP - Deauthentication received;
 *   - Response payload:
 *     - None, except @c SLI_STATUS_DEAUTHENTICATION_RECEIVED_FROM_AP which carries
 *       1-byte deauth reason code (aligned with IEEE 802.11 specification)
 *
 * @note STA success (@c 0) is deferred until after association (and related
 *       LMAC confirms). AP start does not emit a success @c SLI_WIFI_CMD_JOIN
 *       at JOIN time.
 * @note AP-mode async indications that may follow:
 *       - @c SLI_NWP_IND_STA_ADD, @c SLI_NWP_CMD_VALIDATE_PMKID_ASSOC_REQ
 *
 * @note - Use the rate command @c SLI_WIFI_CMD_RATE for fixed-rate selection.
 */

/// Join Feature Bitmap related macros
/// To enable b/g only mode in station mode (used in NWP only)
#define SL_WIFI_JOIN_FEAT_STA_BG_ONLY_MODE_ENABLE (1U << 0)
/// SDK-MGMTIF: Take listen interval from join command
/// HOST-NWP: Reserved
#define SL_WIFI_JOIN_FEAT_LISTEN_INTERVAL_VALID (1U << 1)
/// SDK-MGMTIF: Reserved
/// HOST-NWP: To enable quick join feature
#define SL_WIFI_JOIN_FEAT_QUICK_JOIN    (1U << 2)
#define SL_WIFI_JOIN_FEAT_CCXV2_FEATURE (1U << 3) ///< Reserved
/// SDK-MGMTIF: To connect to AP based on BSSID together with configured SSID
/// HOST-NWP: Reserved
#define SL_WIFI_JOIN_FEAT_BSSID_BASED (1U << 4)
/// SDK-MGMTIF: MFP Capable only bit (11w)
/// HOST-NWP: Reserved
#define SL_WIFI_JOIN_FEAT_MFP_CAPABLE_ONLY (1U << 5)
/// SDK-MGMTIF: MFP Capable required bit (11w)
/// HOST-NWP: Reserved
#define SL_WIFI_JOIN_FEAT_MFP_CAPABLE_REQUIRED         ((1U << 5) | (1U << 6))
#define SL_WIFI_JOIN_FEAT_PS_CMD_LISTEN_INTERVAL_VALID (1U << 7) ///< Reserved

/// Listen interval multiplier related macros
#define SLI_WIFI_LISTEN_INTERVAL_MULTIPLIER_DEFAULT 1
/// Recommended maximum value. Higher values may cause interoperability issues.
#define SLI_WIFI_LISTEN_INTERVAL_MULTIPLIER_MAX_RECOMMENDED 10

/// Used for security_type
#define SLI_WIFI_ENCRYPT_MODE_CCMP_ONLY 0x80 ///< Used in management interface for supplicant cipher configuration

/// Join command request structure
typedef struct {
  uint8_t reserved1;               ///< Reserved
  uint8_t security_type;           ///< Security mode; see @c sl_wifi_security_t
  int16_t power_level;             ///< Join TX power in deci-dBm (0.1 dBm units); stored and sent to LMAC as deci-dBm
                                   ///< Valid range: @c SLI_WIFI_TX_POWER_DECIDBM_MIN - @c SLI_WIFI_TX_POWER_DECIDBM_MAX
  uint8_t psk[SLI_WIFI_PSK_LEN];   ///< Pre-shared key, 63-byte string, last character is NULL
                                   ///< SDK-MGMTIF: Host SDK provided PSK material used for secured joins.
                                   ///< HOST-NWP: Stored in join configuration. Used only for sending to host in
                                   ///< subsequent query command for STA network params.
  uint8_t ssid[SLI_WIFI_SSID_LEN]; ///< SDK-MGMTIF: SSID of access point to join in STA mode, or SSID to start AP.
                                   ///< HOST-NWP: SSID used to start AP; SSID ignored in STA mode (SSID from
                                   ///< selected-AP context @c sta_ext_info used instead)
  uint8_t join_feature_bitmap;     ///< Join Feature Bitmap; @c SL_WIFI_JOIN_FEAT_*
  uint8_t reserved2[1];            ///< Reserved
  uint8_t listen_interval_multiplier; ///< Multiply the listen interval by this value in the association request.
                                      ///< Default: @c SLI_WIFI_LISTEN_INTERVAL_MULTIPLIER_DEFAULT;
                                      ///< Recommended max: @c SLI_WIFI_LISTEN_INTERVAL_MULTIPLIER_MAX_RECOMMENDED.
  uint8_t ssid_len;                   ///< SSID length
  uint32_t listen_interval;           ///< Listen interval in time units (1 TU = 1024 microseconds)
                                      ///< used when @c SL_WIFI_JOIN_FEAT_LISTEN_INTERVAL_VALID is set
  uint8_t vap_id;                     ///< VAP ID. Valid values: @c SLI_WIFI_STA_MODE, @c SLI_WIFI_AP_MODE
                                      ///< SDK-MGMTIF: Used for identifying interface in concurrent mode.
                                      ///< HOST-NWP: Reserved
  uint8_t join_bssid[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< SDK-MGMTIF: Join BSSID for MAC-based join when
                                                  ///< @c SL_WIFI_JOIN_FEAT_BSSID_BASED is set
                                                  ///< HOST-NWP: Reserved
} __attribute__((packed)) sli_wifi_join_request_t;

#define SLI_WIFI_RATES_LEN 16

/// Supported rates of scanned AP (carried on sta_ext_info)
typedef struct {
  uint8_t rates_len;                     ///< Supported Rates IE length
  uint8_t rates_eid;                     ///< Reserved
  uint8_t rates[SLI_WIFI_RATES_LEN];     ///< Supported Rates
  uint8_t ext_rates_len;                 ///< Extended Supported Rates IE length
  uint8_t ext_rates[SLI_WIFI_RATES_LEN]; ///< Extended Supported Rates
} sli_wifi_supported_rates_t;

#define SLI_WIFI_OUI_LEN          3
#define SLI_WIFI_GEN_IE_LEN       100
#define SLI_WIFI_WMM_AC_Q_MAX_IDX 4 ///< WMM AC queues max index

/// Per-AC WMM parameters of scanned AP (carried on sta_ext_info)
typedef struct {
  uint8_t aifsn : 4;   ///< Arbitration Inter-Frame Space Number (AIFSN).
  uint8_t acm : 1;     ///< Reserved
  uint8_t aci : 2;     ///< Reserved
  uint8_t res : 1;     ///< Reserved
  uint8_t ECW_min : 4; ///< Minimum contention window size exponent.
  uint8_t ECW_max : 4; ///< Maximum contention window size exponent.
  uint16_t txop;       ///< TXOP limit
} sli_wifi_wmm_info_t;

/// Vendor WMM information of scanned AP (carried on sta_ext_info)
typedef struct {
  uint8_t oui_subtype;                                     ///< WMM OUI subtype
  uint8_t version;                                         ///< WMM version
  uint8_t ac_info;                                         ///< QoS Info field
  uint8_t reserved;                                        ///< Reserved
  sli_wifi_wmm_info_t ac_param[SLI_WIFI_WMM_AC_Q_MAX_IDX]; ///< Per-AC WMM parameters
} sli_wifi_vendor_wmm_data_t;

/// Vendor HT information of scanned AP (carried on sta_ext_info)
typedef struct {
  uint8_t payload[SLI_WIFI_GEN_IE_LEN]; ///< Vendor HT IE body after OUI header
} sli_wifi_vendor_ht_data_t;

/// Vendor IE information from scanned AP (carried on sta_ext_info)
typedef struct {
  uint8_t eid;                   ///< Element ID
  uint8_t eid_len;               ///< Element length
  uint8_t oui[SLI_WIFI_OUI_LEN]; ///< Vendor OUI
  uint8_t oui_type;              ///< OUI type
  union {
    sli_wifi_vendor_wmm_data_t wmm; ///< WMM vendor IE body
    sli_wifi_vendor_ht_data_t ht;   ///< Vendor HT IE body
  };
} sli_wifi_vendor_ie_t;

#define SLI_WIFI_HT_IE_LEN      28
#define SLI_WIFI_TSF_WORD_COUNT 4

/// Selected-AP scan information (carried on sta_ext_info)
typedef struct {
  uint8_t channel_num;                       ///< Operating channel
  uint8_t sec_mode;                          ///< Derived security mode
  int16_t rssi;                              ///< Reserved
  uint8_t network_type;                      ///< Reserved
  uint8_t ssid[SLI_WIFI_SSID_LEN];           ///< SSID
  uint8_t bssid[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< BSSID
  uint8_t snr;                               ///< Reserved
  uint8_t reserved;                          ///< Reserved
  /// Do not interchange/move the above fields
  uint16_t timestamp[SLI_WIFI_TSF_WORD_COUNT]; ///< Reserved
  uint16_t beacon_interval;                    ///< Beacon interval (TUs)
  uint16_t capability_info;                    ///< Capability Information
  uint8_t ssid_len;                            ///< SSID length
  sli_wifi_supported_rates_t supported_rates;  ///< Supported / extended rates
  uint8_t atim_window;                         ///< Reserved
  uint8_t phy_param_len;                       ///< Reserved
  uint8_t phy_param[3];                        ///< Reserved
  uint8_t enc_mode;                            ///< Encryption mode
  uint8_t enc_mode_bkp;                        ///< Reserved
  sli_wifi_vendor_ie_t vendor_ie;              ///< Vendor / WMM / HT generic IE
  uint8_t ht_oper_ie[SLI_WIFI_HT_IE_LEN];      ///< Reserved
  uint8_t ht_cap_ie[SLI_WIFI_HT_IE_LEN];       ///< HT Capabilities IE
  uint8_t ht_oper_present;                     ///< Reserved
  uint8_t ht_cap_present;                      ///< HT Capabilities IE present
  uint8_t capable_11n;                         ///< 11n capable flag
  uint8_t qos_enable;                          ///< QoS / WMM associated
  uint8_t wmm_ps_enable;                       ///< Reserved
  uint16_t group_cipher;                       ///< Group cipher
  uint8_t vht_capable;                         ///< VHT capable flag
  uint8_t he_capable;                          ///< HE capable flag
  uint8_t mfpc;                                ///< Management Frame Protection Capable
} sli_wifi_scan_result_t;

#define SLI_WIFI_COUNTRY_TRIPLET_MAX 30

/// Mobility Domain IE of scanned AP (carried on sta_ext_info)
/// @note Aligned with IEEE 802.11-2024 Mobility Domain element (MDIE) format.
typedef struct {
  uint8_t eid;               ///< Element ID
  uint8_t len;               ///< Element length
  uint8_t mdid[2];           ///< Mobility Domain Identifier
  uint8_t ft_cap_and_policy; ///< FT capability and policy
} __attribute__((packed)) sli_wifi_mobility_domain_ie_t;

/// Country IE subband triplet information (carried on sta_ext_info)
typedef struct {
  uint8_t first_channel;  ///< First channel in subband
  uint8_t no_of_channels; ///< Number of channels
  int8_t max_tx_power;    ///< Max TX power (dBm)
} __attribute__((packed)) sli_wifi_country_subband_triplet_t;

/// Country IE information of scanned AP (carried on sta_ext_info)
/// @note Aligned with IEEE 802.11-2024 Country element format.
/// @note Reserved - not filled by management interface.
typedef struct {
  uint8_t country_ie_found;                           ///< Non-zero if Country IE is present
  uint8_t eid;                                        ///< Element ID (Country)
  uint8_t eid_len;                                    ///< Element length
  uint8_t country_code[SLI_WIFI_COUNTRY_CODE_LENGTH]; ///< Country string
  sli_wifi_country_subband_triplet_t chan_info[SLI_WIFI_COUNTRY_TRIPLET_MAX];
} __attribute__((packed)) sli_wifi_country_info_t;

/// MBSSID parameters of scanned AP (carried on sta_ext_info)
typedef struct {
  uint8_t tx_bssid_b5;             ///< BSSID octet 5 used for MBSSID TX
  uint8_t mbssid_index;            ///< MBSSID profile index
  uint8_t full_set_rx_periodicity; ///< Full-set RX periodicity
  uint8_t max_bssid_indicator;     ///< Max BSSID indicator from MBSSID IE
} __attribute__((packed)) sli_wifi_mbssid_info_t;

/**
 * @brief STA JOIN scanned AP information filled by management interface
 * @note Carried on trailing sta_ext_info field in STA mode
 */
typedef struct {
  sli_wifi_scan_result_t scan_result;   ///< Selected AP scan summary
  sli_wifi_mobility_domain_ie_t mdie;   ///< Reserved
  sli_wifi_country_info_t country_info; ///< Reserved
  sli_wifi_mbssid_info_t mbssid_params; ///< MBSSID parameters
  uint8_t ap_rrm_capable;               ///< AP RRM capable flag
} __attribute__((packed)) sli_wifi_sta_join_ap_info_t;

/// WPS session flag
#define SLI_WIFI_WPS_SESSION_DISABLE 0 ///< WPS session disabled
#define SLI_WIFI_WPS_SESSION_ENABLE  1 ///< WPS session enabled

/// SAE PMKSA caching flag.
#define SLI_WIFI_SAE_PMKSA_CACHING_DISABLE 0 ///< Disable SAE PMKSA caching
#define SLI_WIFI_SAE_PMKSA_CACHING_ENABLE  1 ///< Enable SAE PMKSA caching

/// Extended join information
typedef struct {
  uint8_t vif_type;   ///< VIF type for this JOIN (@c SLI_NWP_OP_STATION / @c SLI_NWP_OP_ACCESS_POINT)
  uint8_t ap_channel; ///< Channel for AP mode start
  uint8_t bssid[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< Reserved
  uint8_t wps_session;                       ///< WPS session flag
  uint8_t sae_pmksa_caching;                 ///< SAE PMKSA caching flag
} __attribute__((packed)) sli_mgmt_join_request_ext_t;

/// NWP join structure
typedef struct {
  sli_wifi_join_request_t join_req;          ///< Host-provided JOIN request parameters
  sli_mgmt_join_request_ext_t join_ext_info; ///< Management-provided extended JOIN parameters
  uint8_t sta_ext_info[0];                   ///< Optional trailing STA field; appends @ref sli_wifi_sta_join_ap_info_t
} __attribute__((packed)) sli_mgmtif_join_request_t;

/******************** SLI_WIFI_CMD_SET_MAC_ADDRESS (0x17) *********************/
/**
 * @brief Set the Wi-Fi interface MAC address.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific) during device bring-up
 * to program the Wi-Fi interface MAC address before VAP install.
 * In concurrent mode, all VAPs derive MAC address from the same input payload.
 * AP MAC address is derived by incrementing the last octet of the payload.
 *
 * - Request payload:
 *   @ref sl_mac_address_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_CONCURRENT_AP_IN_CONNECTED_STATE - Concurrent AP interface in
 *       connected state.
 *     - @c SLI_STATUS_COMMAND_GIVEN_IN_INVALID_STATE - AP or STA interface in wrong state.
 *   - Response payload: None
 */

/************ SLI_WIFI_CMD_QUERY_NETWORK_PARAMS (0x18) ************************/
/**
 * @brief Get wireless connection information for STA interface.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA Query). UMAC builds a response
 * from the STA connection context.
 *
 * - Request payload:
 *   - None
 *
 * - Response (to Host SDK):
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success
 *   - Response payload:
 *     @ref sli_mgmtif_network_params_nwp_t; Sent from NWP to management
 *     interface.
 *     @ref sli_mgmtif_network_params_host_t; Sent from management interface
 *     to Host SDK.
 */

/// Wi-Fi connection state
#define SLI_WIFI_STATE_DISCONNECTED 0
#define SLI_WIFI_STATE_CONNECTED    1

/// Wi-Fi connection type
#define SLI_WIFI_CONN_TYPE_INFRA 1 ///< Infrastructure mode

/// Station Wireless Modes
typedef enum {
  STA_WIRELESS_MODE_B = 1,
  //STA_WIRELESS_MODE_A = 2, ///< Reserved
  STA_WIRELESS_MODE_G = 3,
  STA_WIRELESS_MODE_N = 4,
  //STA_WIRELESS_MODE_AC = 5, ///< Reserved
  STA_WIRELESS_MODE_AX = 6,
} sli_wifi_sta_wireless_mode_t;

typedef struct {
  uint16_t wlan_connection_state;  ///< Wi-Fi connection state
  uint8_t ssid[SLI_WIFI_SSID_LEN]; ///< SSID of connected access point
  uint16_t connection_type;        ///< Wi-Fi connection type
  uint8_t security_type;           ///< Security mode used by the STA to connect to the AP. See @c sl_wifi_security_t
  uint8_t channel_no; ///< Channel number of connected AP; Valid channel range: 1–14 for 2.4 GHz and 36–165 for 5 GHz.
  uint8_t psk[SLI_WIFI_PSK_LEN];             ///< PSK
  uint8_t bssid[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< BSSID address of connected AP
  uint8_t sta_wireless_mode;                 ///< Station Wireless Mode
} sli_mgmtif_network_params_nwp_t;

typedef struct {
  uint8_t wlan_connection_state; ///< Wi-Fi connection state
  uint8_t channel_no; ///< Channel number of connected AP; Valid range is 1-14 for 2.4 GHz band, 36-165 for 5GHz band
  uint8_t psk[SLI_WIFI_PSK_LEN];                ///< PSK
  uint8_t mac_addr[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< Device MAC address; Filled in management interface
  uint8_t ssid[SLI_WIFI_SSID_LEN];              ///< SSID of connected access point
  uint16_t connection_type;                     ///< Wi-Fi connection type
  uint8_t security_type; ///< Security mode used by the STA to connect to the AP. See @c sl_wifi_security_t
  uint8_t reserved[290]; ///< Reserved
  uint8_t bssid[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< BSSID address of connected AP
  uint8_t sta_wireless_mode;                 ///< Station Wireless Mode
} __attribute__((packed)) sli_mgmtif_network_params_host_t;

/************ SLI_WIFI_CMD_DISCONNECT (0x19) **********************************/
/**
 * @brief Disconnect from AP when in Wi-Fi STA mode or disconnect a client
 * with the specified MAC address in Access Point (AP) mode.
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP/STA FSM). In STA mode,
 * UMAC tears down the connection to the AP if STA is in connected state. In AP
 * mode, UMAC triggers a disconnection if the client specified by
 * @c client_mac_address in the payload is connected to the AP.
 * Management interface extends the Host SDK request to
 * @ref sli_mgmtif_disconnect_req_t (adds origin flags) before forwarding to NWP.
 * NWP uses @c mode_flag to select STA vs AP handling.
 *
 * - Request payload:
 *   @ref sli_wifi_disassociation_request_t; Sent from Host SDK to management
 *   interface (first 8 bytes of the management-to-NWP payload).
 *   @ref sli_mgmtif_disconnect_req_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - Returns a response immediately when disconnect is host-initiated
 *     (@c host_initiated != 0).
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_INVALID_MAC_SUPPLIED - AP mode: client not found
 *     - @c SLI_STATUS_UNASSOCIATED - STA mode: not in a connected state
 *     - @c SLI_STATUS_MEMORY_FAILED_FROM_MODULE - Insufficient memory to construct deauthentication
 *       frame
 *   - Response payload:
 *     - None
 *
 * @note Async indications that may follow disconnection:
 *       @c SLI_NWP_IND_STA_REMOVE, @c SLI_WIFI_IND_TWT_ASYNC
 *
 * @note In future, when multiple concurrent AP interface support is added,
 * mode_flag (encoded with vap_id) along with client_mac_address can be
 * used/extended to support disconnection of one or more clients on the
 * specified interface.
 */

/// Definitions for mode flag
#define SLI_WIFI_STA_MODE 0
#define SLI_WIFI_AP_MODE  1

/// Values for @c host_initiated
#define SLI_WIFI_DISCONN_FROM_SUPP 0
#define SLI_WIFI_DISCONN_FROM_HOST 1

/// Values for @c supp_initiated_in_wps
#define SLI_WIFI_DISCONN_FROM_SUPP_WPS_FAIL_FALSE 0
#define SLI_WIFI_DISCONN_FROM_SUPP_WPS_FAIL_TRUE  1

/// Disconnect command request structure from Host SDK
typedef struct {
  uint16_t mode_flag;                  ///< Selects STA disconnect or AP client removal process.
  sl_mac_address_t client_mac_address; ///< Client MAC in AP mode; ignored in STA mode
} __attribute__((packed)) sli_wifi_disassociation_request_t;

/// Disconnect command request structure from management interface to NWP.
typedef struct {
  sli_wifi_disassociation_request_t disconn_req; ///< @ref sli_wifi_disassociation_request_t
  uint8_t host_initiated;                        ///< 1 = host-initiated disconnect; 0 = supplicant-initiated
  uint8_t supp_initiated_in_wps;                 ///< 1 = WPS failure (STA WPS path); 0 otherwise
} __attribute__((packed)) sli_mgmtif_disconnect_req_t;

/************ SLI_WIFI_CMD_ANTENNA_SELECT (0x1B) ******************************/
/**
 * @brief Select the RF antenna and configure per-band antenna gain.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific) to store the
 * antenna selection and gain values. UMAC programs LMAC immediately when the
 * VAP is initialized; otherwise, the values are retained for later use.
 *
 * - Request payload:
 *   @ref sli_wifi_antenna_select_t; Sent from Host SDK to NWP.
 *   @ref sli_mgmtif_antenna_select_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - No response is returned.
 *
 * @note Currently not supported in LMAC.
 */
/// Antenna select command request structure
typedef struct {
  uint8_t antenna_value; ///< Antenna value to set
  uint8_t gain_2g;       ///< Reserved
  uint8_t gain_5g;       ///< Reserved
} sli_wifi_antenna_select_t;

/// Extended antenna select command request structure
typedef struct {
  sli_wifi_antenna_select_t ant_sel_req; ///< Antenna select command request structure from Host SDK
  uint8_t antenna_path;                  ///< Reserved
  uint8_t antenna_type;                  ///< Reserved
} __attribute__((packed)) sli_mgmtif_antenna_select_t;

/************ SLI_WIFI_CMD_SET_REGION (0x1D) **********************************/
/**
 * @brief Configures region and corresponding regulatory domain settings.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific) to set the
 * regulatory domain from the supplied region or a scanned beacon. The
 * configured region applies to all active VAPs.
 * In from-beacon mode, UMAC performs passive scan processing and applies the
 * decoded country information asynchronously.
 * Opermodes supported: STA
 *
 * - Request payload:
 *   @ref sli_wifi_set_region_request_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_EXTRACTING_COUNTRY_REGION_FROM_BEACON_FAILED - Failed to derive a
 *       valid regulatory region from beacon country information.
 *     - @c SLI_STATUS_SET_REGION_ERROR - Invalid region-configuration source
 *       value.
 *     - @c SLI_STATUS_SELECTED_REGION_NOT_SUPPORTED - Selected region is not
 *       supported by the module.
 *   - Response payload:
 *     - 1-byte configured regulatory region; Sent from NWP to Host SDK.
 */

/// Enumeration of Wi-Fi region codes.
typedef enum {
  SL_WIFI_DEFAULT_REGION,      ///< Factory default region
  SL_WIFI_REGION_US,           ///< United States
  SL_WIFI_REGION_EU,           ///< European Union
  SL_WIFI_REGION_JP,           ///< Japan
  SL_WIFI_REGION_WORLD_DOMAIN, ///< Worldwide domain
  SL_WIFI_REGION_KR,           ///< Korea
  SL_WIFI_REGION_WORLD_SAFE,   ///< Worldwide safe
  SL_WIFI_REGION_CN,           ///< China
  SL_WIFI_REGION_MAX,
} sl_wifi_region_code_t;

/// Valid types for set_region_code_from_user_cmd
typedef enum {
  SET_REGION_CODE_FROM_BEACONS, ///< Take region from beacon country IE
  SET_REGION_CODE_FROM_USER     ///< Take region from user configuration
} sli_wifi_set_region_code_command_t;

/// Set region command request structure
typedef struct {
  uint8_t set_region_code_from_user_cmd; ///< @c SET_REGION_CODE_FROM_BEACONS to take the region from beacon country IE
                                         ///< @c SET_REGION_CODE_FROM_USER to take region from @c region_code
  uint8_t region_code;                   ///< Regulatory domain; valid values are @c sl_wifi_region_code_t
  uint16_t module_type;                  ///< Reserved
} sli_wifi_set_region_request_t;

/************ SLI_WIFI_CMD_AP_CONFIGURATION (0x24) ****************************/
/**
 * @brief Wi-Fi Access Point configuration
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP FSM) to configure Access Point
 * parameters, including triggering an ACS scan when @c channel is zero.
 * Note: This command only configures the AP parameters. The AP is brought up by
 * the subsequent SLI_WIFI_CMD_JOIN command.
 *
 * - Request payload:
 *   @ref sli_wifi_ap_config_request_t; Sent from Host SDK to NWP.
 *   @ref sli_mgmtif_ap_config_request_t; Sent from management interface to
 *   NWP.
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_INVALID_CHANNEL - Requested channel is not allowed in the current
 *       band or regulatory domain.
 *     - @c ACS_EXECUTION_IN_PROGRESS - ACS is already in progress for the AP
 *       VAP.
 *     - @c SLI_STATUS_ACS_EXECUTION_FAIL - ACS execution failed before completing channel
 *       selection.
 *   - Response payload:
 *     - None
 *
 */

/// Encryption mode
typedef enum { SLI_WIFI_NO_ENCRYPTION, SLI_WIFI_TKIP_ENCRYPTION, SLI_WIFI_CCMP_ENCRYPTION } sli_wifi_encryption_t;

/// Beacon interval (ms) in multiples of 100
#define SLI_WIFI_BEACON_INTERVAL_MS_MIN     100
#define SLI_WIFI_BEACON_INTERVAL_MS_MAX     1000
#define SLI_WIFI_BEACON_INTERVAL_MS_DEFAULT 200

/// DTIM period
#define SLI_WIFI_DTIM_PERIOD_MIN 1
#define SLI_WIFI_DTIM_PERIOD_MAX 255

/// Option values
#define SLI_WIFI_AP_OPT_KEEPALIVE_TYPE_MASK      (BIT(0) | BIT(1))
#define SLI_WIFI_AP_OPT_DYNAMIC_HIDDEN_SSID_CONF BIT(3)

/// Macros related to max_sta_support
#define SLI_WIFI_AP_SUPPORTED_STATIONS_DEFAULT 4

/// Access point configuration parameters
typedef struct {
  uint16_t channel;                ///< Channel number of the access point
                                   ///< Valid range: 0-ACS, 1-14 for 2.4 GHz band, 36-165 for 5GHz band
  uint8_t ssid[SLI_WIFI_SSID_LEN]; ///< SSID of the AP to be created
                                   ///< SDK-MGMTIF: Configures the AP SSID in management interface for downstream
                                   ///< processing of SLI_WIFI_CMD_JOIN.
                                   ///< HOST-NWP: Reserved
  uint8_t security_type;           ///< Security type of the Access point. See @c sl_wifi_security_t
                                   ///< SDK-MGMTIF: Configures security type in management interface for downstream
                                   ///< processing of SLI_WIFI_CMD_JOIN.
                                   ///< HOST-NWP: Reserved
  uint8_t encryption_mode;         ///< Encryption mode. See @c sli_wifi_encryption_t
                                   ///< SDK-MGMTIF: Stores encryption mode in management interface for downstream
                                   ///< operations.
                                   ///< HOST-NWP: Reserved
  uint8_t psk[SLI_WIFI_PSK_LEN];   ///< PSK in case of security mode
                                   ///< SDK-MGMTIF: Configures the AP credential in management interface for
                                   ///< downstream processing of SLI_WIFI_CMD_JOIN.
                                   ///< HOST-NWP: Reserved
  uint16_t beacon_interval;        ///< Beacon interval of the access point in time units (1 TU = 1024 microseconds).
  uint16_t dtim_period;            ///< DTIM period of the access point
  uint8_t options;                 ///< Bitmap controlling AP keep alive type, and Hidden SSID dynamic configurability.
  uint8_t ap_keepalive_period;     ///< Keep alive time after which AP will disconnect the station if there are no
                                   ///< wireless exchanges from station to AP.
  uint16_t max_sta_support;        ///< Number of stations supported. Default: @c SLI_WIFI_AP_SUPPORTED_STATIONS_DEFAULT
} __attribute__((packed)) sli_wifi_ap_config_request_t;

/// AP configuration request passed to NWP.
/// This contains a subset of the data received from the user in sli_wifi_ap_config_request_t.
typedef struct {
  uint16_t dtim_period;        ///< DTIM period of the access point
  uint16_t beacon_interval;    ///< Beacon interval of the access point in time units (1 TU = 1024 microseconds).
  uint16_t channel;            ///< Channel number of the access point; zero requests ACS.
  uint16_t max_sta_support;    ///< Number of clients supported. Default: @c SLI_WIFI_AP_SUPPORTED_STATIONS_DEFAULT
  uint16_t encryption_mode;    ///< Encryption mode
                               ///< SDK-MGMTIF: Stores encryption mode in management interface for downstream
                               ///< operations. See @sli_wifi_encryption_t.
                               ///< HOST-NWP: Reserved
  uint8_t options;             ///< Bitmap controlling AP keep alive type, and Hidden SSID dynamic configurability.
  uint8_t ap_keepalive_period; ///< Keep alive time after which AP will disconnect the station if there are no
                               ///< wireless exchanges from station to AP.
} __attribute__((packed)) sli_mgmtif_ap_config_request_t;

/************ SLI_WIFI_CMD_TWT_AUTO_CONFIG (0x2E) *****************************/
/**
 * @brief Derive TWT parameters from throughput/latency targets and
 * enable or disable the TWT session.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to auto-select TWT wake
 * parameters and accept a setup or teardown request. Actual TWT action-frame
 * exchange is deferred until the STA is authorized with AP TWT support.
 *
 * - Request payload:
 *   @ref sl_wifi_twt_selection_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c SLI_STATUS_TWT_COMMAND_SUCCESS on
 *     success, error code otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_TWT_SUPPORT_NOT_ENABLED_ERR - TWT support is not enabled
 *     - @c SLI_STATUS_TWT_SETUP_ERR_SESSION_ACTIVE - Active TWT session or setup already in
 *       progress
 *     - @c SLI_STATUS_TWT_TEARDOWN_ERR_NOACTIVE_SESS - Teardown requested with no active
 *       TWT session
 *     - @c SLI_STATUS_TWT_SESSION_NOT_FEASIBLE - Derived wake parameters are not feasible for the
 *       given targets
 *   - Response payload:
 *     - None
 *
 * @note Session outcomes may follow as @c SLI_WIFI_IND_TWT_ASYNC. When the STA
 *       is authorized but the AP does not support TWT responder mode, UMAC may
 *       also emit @c SLI_STATUS_TWT_INACTIVE_NO_AP_SUPPORT after the command confirm.
 */

/// TWT enable related macros
#define SLI_WIFI_TWT_DISABLE 0 ///< TWT session teardown
#define SLI_WIFI_TWT_ENABLE  1 ///< TWT session setup

/// TWT request structure to auto-select a session
typedef struct {
  uint8_t twt_enable;                 ///< TWT enable. Valid values: @c SLI_WIFI_TWT_ENABLE or @c SLI_WIFI_TWT_DISABLE
  uint16_t average_tx_throughput;     ///< Expected average Tx throughput in Kbps
  uint32_t tx_latency;                ///< Allowed Tx latency in milliseconds
  uint32_t rx_latency;                ///< Maximum latency in ms for receiving buffered packets from AP
  uint16_t device_average_throughput; ///< Average Tx throughput the device can achieve in Kbps
  uint8_t estimated_extra_wake_duration_percent; ///< Extra wake duration percent to compensate for BSS congestion
  uint8_t twt_tolerable_deviation;               ///< Allowed deviation percentage of wake duration TWT response
  uint32_t default_wake_interval_ms;             ///< Default minimum wake interval in milliseconds
  uint32_t default_minimum_wake_duration_ms;     ///< Default minimum wake duration in milliseconds
  uint8_t beacon_wake_up_count_after_sp;         ///< Beacons to listen after service period completion
} sl_wifi_twt_selection_t;

/************ SLI_WIFI_CMD_TWT_PARAMS (0x2F) **********************************/
/**
 * @brief Configure explicit TWT parameters and enable or disable the TWT
 * session.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to program manual TWT
 * configurations and accept a setup or teardown request. Actual TWT action-frame
 * exchange is deferred until the STA is authorized with AP TWT support.
 *
 * - Request payload:
 *   @ref sl_wifi_twt_request_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c SLI_STATUS_TWT_COMMAND_SUCCESS on
 *     success, error code otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_TWT_SUPPORT_NOT_ENABLED_ERR - TWT support is not enabled
 *     - @c SLI_STATUS_TWT_SETUP_ERR_SESSION_ACTIVE - Active TWT session or setup already in
 *       progress
 *     - @c SLI_STATUS_TWT_TEARDOWN_ERR_FLOWID_NOT_MATCHED - Teardown flow ID does not match
 *       the active session
 *     - @c SLI_STATUS_TWT_TEARDOWN_ERR_NOACTIVE_SESS - Teardown requested with no active
 *       TWT session
 *   - Response payload:
 *     - None
 *
 * @note Session outcomes may follow as @c SLI_WIFI_IND_TWT_ASYNC. When the STA
 *       is authorized but the AP does not support TWT responder mode, UMAC may
 *       also emit @c SLI_STATUS_TWT_INACTIVE_NO_AP_SUPPORT after the command confirm.
 */

/// Valid range for wake_duration (units as per wake_duration_unit)
#define SLI_WIFI_TWT_WAKE_DURATION_MIN 0
#define SLI_WIFI_TWT_WAKE_DURATION_MAX 255

/// Valid range for wake_duration_tol
#define SLI_WIFI_TWT_WAKE_DURATION_TOL_MIN 0
#define SLI_WIFI_TWT_WAKE_DURATION_TOL_MAX 255

/// Valid range for wake_int_exp
#define SLI_WIFI_TWT_WAKE_INT_EXP_MIN 0
#define SLI_WIFI_TWT_WAKE_INT_EXP_MAX 31

/// Valid range for wake_int_exp_tol
#define SLI_WIFI_TWT_WAKE_INT_EXP_TOL_MIN 0
#define SLI_WIFI_TWT_WAKE_INT_EXP_TOL_MAX 31

/// Valid range for wake_int_mantissa
#define SLI_WIFI_TWT_WAKE_INT_MANTISSA_MIN 0
#define SLI_WIFI_TWT_WAKE_INT_MANTISSA_MAX 65535

/// Valid range for wake_int_mantissa_tol
#define SLI_WIFI_TWT_WAKE_INT_MANTISSA_TOL_MIN 0
#define SLI_WIFI_TWT_WAKE_INT_MANTISSA_TOL_MAX 65535

/// Valid range for implicit_twt
#define SLI_WIFI_TWT_IMPLICIT_DISABLED 0
#define SLI_WIFI_TWT_IMPLICIT_ENABLED  1

/// Valid range for un_announced_twt
#define SLI_WIFI_TWT_UNANNOUNCED_TWT_DISABLED 0
#define SLI_WIFI_TWT_UNANNOUNCED_TWT_ENABLED  1

/// Valid range for triggered_twt
#define SLI_WIFI_TWT_TRIG_TWT_FRAME_IN_TSP_DISABLED 0
#define SLI_WIFI_TWT_TRIG_TWT_FRAME_IN_TSP_ENABLED  1

/// Negotiation type (negotiation_type)
#define SLI_WIFI_TWT_NEG_TYPE_INDIVIDUAL 0 ///< Individual TWT
#define SLI_WIFI_TWT_NEG_TYPE_BROADCAST  1 ///< Broadcast TWT

/// TWT session flow id
#define SLI_WIFI_TWT_FLOW_ID_MIN         0    ///< Minimum TWT session flow id
#define SLI_WIFI_TWT_FLOW_ID_MAX         7    ///< Maximum TWT session flow id
#define SLI_WIFI_TWT_FLOW_ID_DISABLE_ALL 0xFF ///< Disable all active TWT sessions

/// Valid range for restrict_tx_outside_tsp
#define SLI_WIFI_TWT_TX_OUTSIDE_TSP_ALLOWED    0 ///< Tx allowed outside TSP
#define SLI_WIFI_TWT_TX_OUTSIDE_TSP_RESTRICTED 1 ///< Tx outside TSP restricted

/// Valid range for twt_retry_limit
#define SLI_WIFI_TWT_RETRY_LIMIT_MIN     0
#define SLI_WIFI_TWT_RETRY_LIMIT_MAX     15
#define SLI_WIFI_TWT_RETRY_LIMIT_DEFAULT 3

/// Valid range for twt_retry_interval (seconds)
#define SLI_WIFI_TWT_RETRY_INT_MIN     5
#define SLI_WIFI_TWT_RETRY_INT_MAX     255
#define SLI_WIFI_TWT_RETRY_INT_DEFAULT 5

/// TWT Request Type (req_type)
#define SLI_WIFI_TWT_REQ_TYPE_REQUEST   0 ///< Request TWT
#define SLI_WIFI_TWT_REQ_TYPE_SUGGEST   1 ///< Suggest TWT
#define SLI_WIFI_TWT_REQ_TYPE_DEMAND    2 ///< Demand TWT
#define SLI_WIFI_TWT_REQ_TYPE_GROUPING  3 ///< Reserved
#define SLI_WIFI_TWT_REQ_TYPE_ACCEPT    4 ///< Reserved
#define SLI_WIFI_TWT_REQ_TYPE_ALTERNATE 5 ///< Reserved
#define SLI_WIFI_TWT_REQ_TYPE_DICTATE   6 ///< Reserved
#define SLI_WIFI_TWT_REQ_TYPE_REJECT    7 ///< Reserved

/// Wake duration unit (wake_duration_unit)
#define SLI_WIFI_TWT_WAKE_DURATION_UNIT_256US  0 ///< Wake duration unit of 256 microseconds
#define SLI_WIFI_TWT_WAKE_DURATION_UNIT_1024US 1 ///< Wake duration unit of 1024 microseconds

/// TWT (Target Wake Time) request structure to configure a session
typedef struct {
  uint8_t wake_duration;      ///< Nominal minimum wake duration.
  uint8_t wake_duration_tol;  ///< Tolerance allowed for wake duration for suggest TWT. Received TWT wake duration
                              ///< from AP validates against tolerance limits and decides if TWT config received is in
                              ///< acceptable range or not.
  uint8_t wake_int_exp;       ///< Wake interval exponent to the base 2.
  uint8_t wake_int_exp_tol;   ///< Tolerance allowed for wake_int_exp for suggest TWT. Received TWT wake duration from
                              ///< AP validates against tolerance limits and decides if TWT config received is in
                              ///< acceptable range or not.
  uint16_t wake_int_mantissa; ///< Wake interval mantissa.
  uint16_t wake_int_mantissa_tol; ///< Tolerance allowed for wake_int_mantissa for suggest TWT. Received TWT wake
                                  ///< interval mantissa from AP validates against tolerance limits and decides if
                                  ///< TWT config received is in acceptable range or not.
  uint8_t implicit_twt;     ///< If enabled (1), STA calculates next TWT by adding a fixed value to current TWT value
                            ///< Currently, explicit TWT is not allowed
  uint8_t un_announced_twt; ///< If enabled (1), STA does not announce wake-up via PS-POLL or UAPSD trigger frames
  uint8_t triggered_twt;    ///< If enabled (1), at least one trigger frame is included in the TWT Service Period(TSP)
  uint8_t negotiation_type; ///< Negotiation type
  uint8_t twt_channel;      ///< Reserved
  uint8_t twt_protection;   ///< Reserved
  uint8_t twt_flow_id;      ///< TWT session flow id.
  uint8_t restrict_tx_outside_tsp; ///< 1 - Tx outside TSP restricted; 0 - Tx allowed outside TSP
  uint8_t twt_retry_limit;         ///< TWT retry limit.
  uint8_t twt_retry_interval;      ///< TWT retry interval in seconds between two TWT requests. Range : 5 - 255
  uint8_t req_type;                ///< TWT request type. Valid values: @c SLI_WIFI_TWT_REQ_TYPE_REQUEST,
                                   ///< @c SLI_WIFI_TWT_REQ_TYPE_SUGGEST, or @c SLI_WIFI_TWT_REQ_TYPE_DEMAND
  uint8_t twt_enable;              ///< TWT enable. Valid values: @c SLI_WIFI_TWT_ENABLE or @c SLI_WIFI_TWT_DISABLE
  uint8_t wake_duration_unit;      ///< Wake duration unit
} sl_wifi_twt_request_t;

/***************** SLI_WIFI_CMD_VENDOR_IE (0x38) ******************************/
/**
 * @brief Add a vendor-specific IE to Wi-Fi management frames
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP/STA FSM) to add or remove
 * vendor IEs used in downstream management frame construction.
 *
 * - Request payload:
 *   @ref sli_wifi_manage_vendor_ie_packet_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_VENDOR_IE_RET_FAIL - Vendor IE validation or update failed.
 *     - @c SLI_STATUS_VENDOR_IE_INVALID_UNIQUE_ID - Slot ID is invalid for the
 *       requested action.
 *     - @c SLI_STATUS_VENDOR_IE_INVALID_IE_LENGTH - IE length is outside the valid
 *       range.
 *     - @c SLI_STATUS_VENDOR_IE_INVALID_PACKET_BITMAP - Management-frame bitmap is
 *       invalid.
 *     - @c SLI_STATUS_VENDOR_IE_NO_SLOTS_AVAILABLE - No free vendor-IE slot is
 *       available.
 *     - @c SLI_STATUS_VENDOR_IE_INVALID_ACTION - Action field is not supported.
 *   - Response payload:
 *     - 1-byte assigned or removed slot ID; Sent from NWP to Host SDK.
 */

/// Frame version for vendor-specific IE.
#define SLI_WIFI_VENDOR_IE_FRAME_VERSION 0

/// Enum to specify the action for vendor-specific IE management.
typedef enum {
  SLI_WIFI_VENDOR_IE_ACTION_ADD        = 0,   ///< Add a vendor-specific IE
  SLI_WIFI_VENDOR_IE_ACTION_REMOVE     = 1,   ///< Remove a vendor-specific IE
  SLI_WIFI_VENDOR_IE_ACTION_REMOVE_ALL = 0xFF ///< Remove all vendor-specific IEs
} sli_wifi_vendor_ie_action_t;

/// Defines the maximum number of Vendor Specific IEs that can be configured.
#define SLI_WIFI_MAX_VENDOR_IE 2

/// Bitmaps for management frames in which vendor IE is injected (mgmt_frame_bitmap)
#define SLI_WIFI_VENDOR_IE_BITMAP_BEACON    BIT(0) // Beacon frame
#define SLI_WIFI_VENDOR_IE_BITMAP_PROBE_RSP BIT(1) // Probe response frame
#define SLI_WIFI_VENDOR_IE_BITMAP_ASSOC_RSP BIT(2) // Association response frame
#define SLI_WIFI_VENDOR_IE_BITMAP_PROBE_REQ BIT(3) // Probe request frame
#define SLI_WIFI_VENDOR_IE_BITMAP_ASSOC_REQ BIT(4) // Association request frame

/// Minimum vendor IE length (element ID, length, and OUI)
#define SLI_WIFI_VENDOR_IE_MIN_IE_LENGTH 6

/// Defines the Header length in vendor-specific IE buffer.
#define SLI_WIFI_VENDOR_IE_HEADER_LENGTH 2

/// Defines the maximum length of the vendor-specific IE buffer 256 Bytes (254 bytes for data + 2 bytes for header).
#define SLI_WIFI_MAX_VENDOR_IE_BUFFER_LENGTH (254 + SLI_WIFI_VENDOR_IE_HEADER_LENGTH)

/// Packet structure for sending Vendor Specific IE to firmware.
typedef struct {
  uint16_t version;           ///< Reserved
  uint8_t action;             ///< Action to perform. See @c sli_wifi_vendor_ie_action_t
  uint8_t unique_id;          ///< Slot ID: 0 = auto-assign; 1..SLI_WIFI_MAX_VENDOR_IE (inclusive) = explicit slot
  uint16_t mgmt_frame_bitmap; ///< Bitmap indicating which management frames include the IE
  uint8_t reserved[4];        ///< Reserved
  uint16_t ie_buffer_length;  ///< Length of the IE buffer (must be <= SLI_WIFI_MAX_VENDOR_IE_BUFFER_LENGTH)
  uint8_t ie_buffer[SLI_WIFI_MAX_VENDOR_IE_BUFFER_LENGTH]; ///< Raw IE data from host
} __attribute__((packed)) sli_wifi_manage_vendor_ie_packet_t;

/************ SLI_WIFI_CMD_WIFI_SIGNAL_QUALITY_STATS (0x3B) *******************/
/**
 * @brief Query Wi-Fi SNR/RSSI statistics in STA mode
 *
 * @description
 * Consumed by UMAC (LMAC passthrough) to query RSSI or SNR statistics from
 * LMAC and forward the resulting response to Host SDK.
 * Opermodes supported: STA
 *
 * - Request payload:
 *   @ref sli_wifi_signal_quality_stats_req_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Response payload:
 *     @ref sli_wifi_signal_quality_stats_rsp_t; Sent from NWP to Host SDK.
 */

/// Statistics type
#define SLI_WIFI_STATS_TYPE_SNR  0 ///< SNR statistics
#define SLI_WIFI_STATS_TYPE_RSSI 1 ///< RSSI statistics

/// Statistics request structure
typedef struct {
  uint8_t interface;  ///< Interface selector from Host SDK; forwarded to LMAC unchanged
  uint8_t stats_type; ///< Statistics type
} sli_wifi_signal_quality_stats_req_t;

/// Statistics response structure
typedef struct {
  uint8_t stats_type;    ///< Statistics type returned by LMAC
  int16_t last_deci_dbm; ///< Most recent RSSI or SNR reading in deci-dBm
  int16_t avg_deci_dbm;  ///< Average RSSI or SNR reading in deci-dBm
} sli_wifi_signal_quality_stats_rsp_t;

/************ SLI_WIFI_CMD_RESCHEDULE_TWT (0x3F) ******************************/
/**
 * @brief Suspend or resume an active TWT flow.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to suspend the TWT
 * agreement for the given flow ID or resume it. On success, UMAC transmits a
 * TWT Information action frame to the connected AP.
 * The reschedule TWT actions are valid until the end of the current TWT
 * agreement; teardown or Wi-Fi disconnection does not retain them.
 *
 * - Request payload:
 *   @ref sl_wifi_reschedule_twt_config_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c SLI_STATUS_TWT_COMMAND_SUCCESS on
 *     success, error code otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_RESCHEDULE_TWT_ERR_NOACTIVE_SESS - No active TWT agreement for the
 *       given flow ID
 *     - @c SLI_STATUS_RESCHEDULE_TWT_NOT_SUPPORTED - AP does not support TWT Information
 *       frame reception
 *     - @c SLI_STATUS_TWT_RESCHEDULING_IN_PROGRESS - Suspend or resume action already in
 *       progress
 *     - @c SLI_STATUS_RESCHEDULE_TWT_PACKET_CREATION_FAILED - TWT Information frame
 *       creation failed
 *   - Response payload:
 *     - None
 *
 * @note Async outcomes may follow as @c SLI_WIFI_IND_TWT_ASYNC
 *       (@c SLI_STATUS_RESCHEDULE_TWT_SUCCESS or @c SLI_STATUS_TWT_INFO_FRAME_EXCHANGE_FAILED).
 */
/// Enumeration defining rescheduling actions(twt_action).
typedef enum {
  SL_WIFI_SUSPEND_INDEFINITELY, ///< Suspend TWT indefinitely, effectively disabling TWT functionality
                                ///< until explicitly resumed.
  SL_WIFI_SUSPEND_FOR_DURATION, ///< Suspend TWT for a specified duration, after which it can automatically resume.
  SL_WIFI_RESUME_IMMEDIATELY    ///< Resume TWT immediately, allowing devices to continue adhering to TWT schedules.
} sl_wifi_reschedule_twt_action_t;

/// TWT reschedule configuration structure
typedef struct {
  uint8_t flow_id;                            ///< TWT session flow ID; Range: @c SLI_WIFI_TWT_FLOW_ID_MIN -
                                              ///< @c SLI_WIFI_TWT_FLOW_ID_MAX
  sl_wifi_reschedule_twt_action_t twt_action; ///< Action for rescheduling the TWT session. This determines how and
                                              ///< when the TWT session would be suspended or adjusted.
  uint16_t reserved1;                         ///< Reserved
  uint8_t reserved2;                          ///< Reserved
  uint64_t suspend_duration;                  ///< Duration to suspend the respective TWT session, in microseconds
} sl_wifi_reschedule_twt_config_t;

/**************** SLI_WIFI_CMD_SET_MULTICAST_FILTER (0x40) ********************/
/**
 * @brief This frame is reserved.
 */

/**************** SLI_WIFI_CMD_WMM_PARAMS (0x45) ******************************/
/**
 * @brief Queries WMM Access Category(AC) parameters.
 *
 * @description
 * Consumed by UMAC (Connection Manager - Query) to return WMM AC parameters for
 * Best Effort (BE), Background (BK), Video (VI), and Voice (VO).
 * Opermodes supported: AP, STA.
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success.
 *   - Response payload:
 *     - @ref sli_wifi_wmm_info_t[SLI_WIFI_WMM_AC_Q_MAX_IDX] where index values are
 *       0 - Best Effort, 1 - Background, 2 - Video and 3 - Voice.
 *       Sent from NWP to Host SDK.
 *
 * @note Host SDK currently does not support this frame.
 */

/************ SLI_WIFI_CMD_GAIN_TABLE (0x47) **********************************/
/**
 * @brief This frame is reserved.
 */

// Region codes for Gain Table Command
#define REGION_FCC        0
#define REGION_ETSI       1
#define REGION_TELEC      2
#define REGION_WORLD_WIDE 3
#define REGION_KCC        4
#define REGION_WORLD_SAFE 5
#define REGION_SRRC       6

#define SLI_GAIN_TABLE_BAND_2P4_GHZ                       0x01
#define SLI_GAIN_TABLE_BAND_5GHZ                          0x02
#define SLI_MIN_GAIN_TABLE_PAYLOAD_LEN                    0
#define SLI_MAX_GAIN_TABLE_PAYLOAD_LEN                    160
#define SLI_MAX_BUMP_UP_OFFSET_52_TONE_RU_FOR_FCC         6
#define SLI_MAX_BUMP_UP_OFFSET_106_TONE_RU_FOR_FCC        6
#define SLI_MAX_BUMP_UP_OFFSET_52_TONE_RU_FOR_ETSI_TELEC  6
#define SLI_MAX_BUMP_UP_OFFSET_106_TONE_RU_FOR_ETSI_TELEC 10

//! user configurable gain table structure
typedef struct {
  uint8_t band;               ///< band value
  uint8_t bandwidth;          ///< bandwidth value
  uint16_t size;              ///< payload size
  uint8_t x_offset;           ///< X: bump up offset for 52 tone RU
  uint8_t y_offset;           ///< Y: bump up offset for 106 tone RU
  uint8_t gain_table_version; ///< 0: Old gain table, 1:New gain table
  uint8_t reserved;           ///< Reserved
  uint8_t gain_table[];       ///< payload
} sli_wifi_gain_table_info_t;

/************ SLI_WIFI_CMD_TSF (0x65) *****************************************/
/**
 * @brief Get the station Timing Synchronization Function (TSF) time which is
 * synchronised with connected AP beacon TSF.
 *
 * @description
 * Consumed by UMAC (UMAC/LMAC interface) to return the 64-bit TSF value
 * in microseconds. When STA is connected, UMAC queries LMAC; otherwise UMAC
 * returns a zeroed TSF payload.
 * Opermodes supported: STA
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error
 *     code otherwise.
 *   - Possible error codes:
 *     - @c SLI_STATUS_INVALID_STATION_TSF - TSF value is invalid or STA is not
 *       connected.
 *   - Response payload:
 *     @ref sl_wifi_tsf64_t; Sent from NWP to Host SDK.
 *
 * @note Management interface currently does not support this frame.
 */

/// Wi-Fi station TSF (Timing Synchronization Function) structure
typedef struct {
  uint32_t tsf_l; ///< Lower 32 bits of the TSF timer. Used to store the Least
                  ///< Significant Bits (LSB) of the TSF
  uint32_t tsf_m; ///< Upper 32 bits of the TSF timer. Used to store the Most
                  ///< Significant Bits (MSB) of the TSF.
} sl_wifi_tsf64_t;

/************ SLI_WIFI_CMD_EXT_STATS (0x68) ***********************************/
/**
 * @brief Return Wi-Fi operational statistics
 *
 * @description
 * Consumed by UMAC (UMAC/LMAC interface) to return Wi-Fi operational
 * statistics. When STA is connected, UMAC queries LMAC; otherwise UMAC
 * returns an empty statistics payload.
 * Opermodes supported: STA
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success.
 *   - Response payload:
 *     @ref sl_wifi_statistics_t; Sent from NWP to Host SDK.
 *
 * @note Currently not supported in LMAC.
 */

/// Wi-Fi interface statistics structure
typedef struct {
  uint32_t beacon_lost_count; ///< Number of missed beacons
  uint32_t beacon_rx_count;   ///< Number of received beacons
  uint32_t mcast_rx_count;    ///< Multicast packets received
  uint32_t mcast_tx_count;    ///< Multicast packets transmitted
  uint32_t ucast_rx_count;    ///< Unicast packets received
  uint32_t ucast_tx_count;    ///< Unicast packets transmitted
  uint32_t overrun_count;     ///< Packets dropped either at ingress or egress, due to lack of buffer memory
} sl_wifi_statistics_t;

/************ SLI_WIFI_CMD_BG_SCAN (0x6A) *************************************/
/**
 * @brief Initiates a Wi-Fi background scan operation
 *
 * @description
 * Consumed by UMAC (Operations manager) to configure background scan parameters
 * and program them to LMAC through internal configuration frames. The request
 * is processed only when the VAP is connected; otherwise it is ignored.
 * In AP mode, UMAC forces the active-scan dwell and applies a band-specific
 * passive-scan dwell before programming LMAC.
 * Opermodes supported: STA, AP
 *
 * - Request payload:
 *   @ref sli_wifi_request_bg_scan_t; Sent from Host SDK to NWP.
 *   @ref sli_mgmtif_request_bg_scan_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_BG_SCAN_NOT_ALLOWED
 *   - Response payload:
 *     - None
 *
 * @note Async scan results may follow as @c SLI_WIFI_IND_ON_AIR_MGMT.
 */

/// Valid range for @c bgscan_enable
#define SLI_WIFI_BG_SCAN_DISABLE 0 ///< Disable background scan
#define SLI_WIFI_BG_SCAN_ENABLE  1 ///< Enable background scan

/// Valid range for @c enable_instant_bgscan
#define SLI_WIFI_INSTANT_BG_SCAN_DISABLE 0 ///< Normal bgscan
#define SLI_WIFI_INSTANT_BG_SCAN_ENABLE  1 ///< Instant bgscan

#define MAX_BG_CHANNEL_SUPPORT (24 + 12)

/// Background scan command request structure
typedef struct {
  uint16_t bgscan_enable;            ///< Enable or disable BG scan
  uint16_t enable_instant_bgscan;    ///< Instant bgscan or normal bgscan
  uint16_t bgscan_threshold;         ///< RSSI threshold level to trigger background scan for roaming. When connected
                                     ///< to an AP, if the RSSI drops below this level, a background scan is
                                     ///< automatically triggered to find better APs for potential roaming.
  uint16_t rssi_tolerance_threshold; ///< RSSI delta change threshold to trigger background scan for roaming. If the
                                     ///< current RSSI value drops by this delta amount from the previous measurement,
                                     ///< a background scan is triggered to find better APs for potential roaming.
  uint16_t bgscan_periodicity;       ///< Duration between periodic scans (milliseconds)
  uint16_t active_scan_duration;     ///< Time spent on each channel during active scan (milliseconds)
  uint16_t passive_scan_duration;    ///< Time spent on each channel during passive scan (milliseconds)
  uint8_t multi_probe;               ///< Flag to send multiple probes to AP. If the value is set to 1, a probe
                                     ///< request is sent to all access points in addition to the connected SSID.
                                     ///< SDK-MGMTIF: Used in management iface in downstream processing of scan results
                                     ///< HOST-NWP: Enables additional probe requests when non-zero.
  uint8_t reserved;                  ///< Reserved
} sli_wifi_request_bg_scan_t;

typedef struct {
  sli_wifi_request_bg_scan_t bg_scan_req;         ///< Host SDK background-scan request
  uint8_t num_bg_channels;                        ///< SDK-MGMTIF: Reserved.
                                                  ///< HOST-NWP: Number of scan channels derived by UMAC from
                                                  ///< @c channel_bitmap or default channel lists.
  uint8_t reserved1;                              ///< Reserved
  uint16_t channels2scan[MAX_BG_CHANNEL_SUPPORT]; ///< SDK-MGMTIF: Reserved.
                                                  ///< HOST-NWP: Scan channel list derived by UMAC
  uint8_t ssid[SLI_WIFI_SSID_LEN];                ///< Scan SSID
  uint16_t ssid_len;                              ///< SSID length
  uint16_t reserved2;                             ///< Reserved
  uint32_t channel_bitmap; ///< Channel bitmap used by UMAC to derive @c channels2scan when present.
} sli_mgmtif_request_bg_scan_t;

/************ SLI_WIFI_CMD_HT_CAPABILITIES (0x6D) *****************************/
/**
 * @brief Enable/disable HT capabilities
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP FSM) to configure HT
 * capabilities used in AP management frames.
 *
 * - Request payload:
 *   @ref sli_wifi_request_ap_high_throughput_capability_t; Sent from Host SDK
 *   to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_HT_CAPABILITIES_NOT_SUPPORTED - HT capability is not
 *       supported or one or more HT capabilities specified in @c ht_caps_bitmap
 *       are not supported
 *   - Response payload:
 *     - None
 */
/// Field mode_11n_enable definitions
#define SLI_WIFI_11N_DISABLED 0
#define SLI_WIFI_11N_ENABLED  1

/// HT capability bitmap definitions aligned with IEEE 802.11-2024 (reference
/// 9.4.2.54.2 HT Capability Information field)
/// Support for Greenfield mode, which improves efficiency by eliminating legacy
/// preambles
#define SL_WIFI_HT_CAPS_GREENFIELD_EN BIT(4)
/// Support for Short Guard Interval (GI) in 20 MHz channels
#define SL_WIFI_HT_CAPS_SHORT_GI_20MHZ BIT(5)
/// Number of RX Space-Time Block Coding (STBC) streams supported.
/// Note: As per specification, RX STBC maps to bits 8-9. Current implementation
/// supports 1 spatial steam only.
#define SL_WIFI_HT_CAPS_NUM_RX_STBC BIT(8)

/// High throughput capability enable payload
typedef struct {
  uint16_t mode_11n_enable; ///< 11n mode enable
  uint16_t ht_caps_bitmap;  ///< HT capability bitmap; Aligned with IEEE 802.11-2024
} sli_wifi_request_ap_high_throughput_capability_t;

/************ SLI_WIFI_CMD_REJOIN_PARAMS (0x6F) *******************************/
/**
 * @brief Configure STA rejoin parameters
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to configure rejoin related
 * configurations in STA mode.
 * - Request payload:
 *   @ref sli_wifi_rejoin_params_t; Sent from Host SDK to management interface
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success
 *   - Response payload:
 *     - None
 */

/// max_retry_attempts limits
#define SLI_WIFI_REJOIN_MAX_RETRY_ATTEMPTS_MIN       1
#define SLI_WIFI_REJOIN_MAX_RETRY_ATTEMPTS_UNLIMITED 0  ///< 0 = unlimited retries
#define SLI_WIFI_REJOIN_RETRY_DEFAULT                20 ///< Default max_retry_attempts

/// scan_interval limits (seconds)
#define SLI_WIFI_REJOIN_SCAN_INTERVAL_MIN     1
#define SLI_WIFI_REJOIN_SCAN_INTERVAL_DEFAULT 4

/// beacon_missed_count limits
#define SLI_WIFI_MAX_BEACON_MISSED_COUNT 40 ///< Default beacon_missed_count

/// first_time_retry_enable values
#define SLI_WIFI_REJOIN_FIRST_TIME_RETRY_DISABLE 0
#define SLI_WIFI_REJOIN_FIRST_TIME_RETRY_ENABLE  1

/// Rejoin parameters
typedef struct {
  uint32_t max_retry_attempts;      ///< SDK-MGMTIF: Maximum number of rejoin retries before join failure.
                                    ///< HOST-NWP: Reserved.
  int32_t scan_interval;            ///< SDK-MGMTIF: Scan interval between rejoin retries(seconds).
                                    ///< HOST-NWP: Reserved.
  int32_t beacon_missed_count;      ///< SDK-MGMTIF: Forwarded to NWP.
                                    ///< HOST-NWP: Reserved.
                                    ///< default @c SLI_WIFI_MAX_BEACON_MISSED_COUNT.
  uint32_t first_time_retry_enable; ///< SDK-MGMTIF: Enables retry for the first join attempt.
                                    ///< HOST-NWP: Reserved.
} sli_wifi_rejoin_params_t;

/********************** SLI_WIFI_CMD_WPS_METHOD (0x72) ************************/
/**
 * @brief This frame is reserved.
 *
 */

/********************** SLI_WIFI_CMD_DMP_CONFIGURATION (0x78) *****************/
/**
 * @brief
 *
 * @description
 * This is a passthrough frame forwarded to LMAC by UMAC command decoder.
 *
 * - Request payload:
 *   @ref sli_si3xx_dmp_configuration_t; Sent from Host SDK to NWP
 *
 * - Response:
 *   - Deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Response payload:
 *     - None
 */

/************ SLI_WIFI_CMD_SET_TRANSCEIVER_CHANNEL (0x7A) *********************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_CMD_TX_TEST_MODE (0x7C) ********************************/
/**
 * @brief Programs PER TX test mode (continuous / burst).
 *
 * @description
 * Consumed by UMAC (Operations manager) to configure PER TX operations in LMAC.
 * Opermodes supported: PER.
 *
 * - Request payload:
 *   @ref sli_wifi_tx_test_base_info_wire_t followed by the mode-specific extension
 *   (@ref sli_wifi_11ax_per_params_wire_t, @ref sli_wifi_11ac_per_params_wire_t,
 *   @ref sli_wifi_11be_per_params_wire_t, or @ref sli_wifi_11bgn_per_params_wire_t);
 *   Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_MEMORY_FAILED_FROM_MODULE - Insufficient memory to construct
 *       an internal PER/LMAC frame
 *     - @c SLI_STATUS_INVALID_CONFIG_RANGE_PROVIDED - Input field value provided is
 *       outside the supported range
 *     - @c SLI_STATUS_INVALID_FIXED_RATE - Rate is invalid for the selected channel
 *       or band
 *     - @c SLI_STATUS_INVALID_CHANNEL - Channel is invalid for the configured band
 *   - Response payload:
 *     - None
 */
/// Wi-Fi rate protocols
typedef enum __attribute__((packed)) {
  SL_WIFI_RATE_PROTOCOL_B_ONLY,  ///< 802.11b rates only
  SL_WIFI_RATE_PROTOCOL_G_ONLY,  ///< 802.11g rates only
  SL_WIFI_RATE_PROTOCOL_N_ONLY,  ///< 802.11n rates only
  SL_WIFI_RATE_PROTOCOL_AC_ONLY, ///< 802.11ac rates only
  SL_WIFI_RATE_PROTOCOL_AX_ONLY, ///< 802.11ax rates only
  SL_WIFI_RATE_PROTOCOL_BE_ONLY, ///< 802.11be rates only
  SL_WIFI_RATE_PROTOCOL_AUTO,    ///< Reserved
} sl_wifi_rate_protocol_t;

/// Enable/disable TX test mode (@ enable)
#define SLI_WIFI_PER_TX_STOP  0
#define SLI_WIFI_PER_TX_START 1

/// PER continuous / burst mode (@c mode)
#define SLI_WIFI_PER_BURST_MODE 0
#define SLI_WIFI_PER_CONT_MODE  1

/// Valid range for @c channel (2.4 GHz)
#define SLI_WIFI_PER_CHANNEL_2_4GHZ_MIN 1
#define SLI_WIFI_PER_CHANNEL_2_4GHZ_MAX 14

/// Valid range for @c channel (5 GHz)
#define SLI_WIFI_PER_CHANNEL_5GHZ_MIN 36
#define SLI_WIFI_PER_CHANNEL_5GHZ_MAX 177

/**
  * @enum sl_wifi_mcs_rate_t
  * @brief Encoded Wi-Fi data rate / MCS index for PER descriptors and E2E fixed transmit rate
  *        command payloads. Numeric values match firmware encoding; interpret together with
  *        @ref sl_wifi_rate_protocol_t.
  */
typedef enum __attribute__((packed)) {
  SL_WIFI_RATE_1    = 0,                ///< Wi-Fi 1 Mbps transfer rate
  SL_WIFI_RATE_2    = 2,                ///< Wi-Fi 2 Mbps transfer rate
  SL_WIFI_RATE_5_5  = 4,                ///< Wi-Fi 5.5 Mbps transfer rate
  SL_WIFI_RATE_11   = 6,                ///< Wi-Fi 11 Mbps transfer rate
  SL_WIFI_RATE_6    = 11,               ///< Wi-Fi 6 Mbps transfer rate
  SL_WIFI_RATE_9    = 15,               ///< Wi-Fi 9 Mbps transfer rate
  SL_WIFI_RATE_12   = 10,               ///< Wi-Fi 12 Mbps transfer rate
  SL_WIFI_RATE_18   = 14,               ///< Wi-Fi 18 Mbps transfer rate
  SL_WIFI_RATE_24   = 9,                ///< Wi-Fi 24 Mbps transfer rate
  SL_WIFI_RATE_36   = 13,               ///< Wi-Fi 36 Mbps transfer rate
  SL_WIFI_RATE_48   = 8,                ///< Wi-Fi 48 Mbps transfer rate
  SL_WIFI_RATE_54   = 12,               ///< Wi-Fi 54 Mbps transfer rate
  SL_WIFI_RATE_MCS0 = SL_WIFI_RATE_1,   ///< Wi-Fi MCS index 0 transfer rate
  SL_WIFI_RATE_MCS1 = 1,                ///< Wi-Fi MCS index 1 transfer rate
  SL_WIFI_RATE_MCS2 = SL_WIFI_RATE_2,   ///< Wi-Fi MCS index 2 transfer rate
  SL_WIFI_RATE_MCS3 = 3,                ///< Wi-Fi MCS index 3 transfer rate
  SL_WIFI_RATE_MCS4 = SL_WIFI_RATE_5_5, ///< Wi-Fi MCS index 4 transfer rate
  SL_WIFI_RATE_MCS5 = 5,                ///< Wi-Fi MCS index 5 transfer rate
  SL_WIFI_RATE_MCS6 = SL_WIFI_RATE_11,  ///< Wi-Fi MCS index 6 transfer rate
  SL_WIFI_RATE_MCS7 = 7,                ///< Wi-Fi MCS index 7 transfer rate
  SL_WIFI_RATE_MCS8 = SL_WIFI_RATE_48,  ///< Wi-Fi MCS index 8 transfer rate
  SL_WIFI_RATE_MCS9 = SL_WIFI_RATE_24,  ///< Wi-Fi MCS index 9 transfer rate
  SL_WIFI_RATE_MCSF = SL_WIFI_RATE_9,   ///< Wi-Fi MCS index 15 (0xF) transfer rate
} sl_wifi_mcs_rate_t;

/// Valid range for @c rate; See @c sl_wifi_mcs_rate_t
#define SLI_WIFI_PER_RATE_IDX_11G_MIN      8    ///< 802.11g rate index min
#define SLI_WIFI_PER_RATE_IDX_11G_MAX      15   ///< 802.11g rate index max
#define SLI_WIFI_PER_RATE_IDX_11N_MAX      7    ///< 802.11n rate index max
#define SLI_WIFI_PER_RATE_IDX_11AC_MAX     8    ///< 802.11ac rate index max
#define SLI_WIFI_PER_RATE_IDX_11AX_MAX     9    ///< 802.11ax rate index max
#define SLI_WIFI_PER_RATE_IDX_11BE_MAX     9    ///< 802.11be MCS rate index max
#define SLI_WIFI_PER_RATE_IDX_11BE_SPECIAL 0xFu ///< 802.11be special rate index

/// Valid range for @c aggr_enable
#define SLI_WIFI_PER_AGGR_DISABLE 0
#define SLI_WIFI_PER_AGGR_ENABLE  1

/// PER flags (@c flags). BIT(1)–BIT(15) reserved
#define SLI_WIFI_PER_FLAGS_IMMEDIATE_TRANSFER BIT(0)

/**
 * @brief Common TX test (PER) base parameters.
 *
 * Mode-specific extension follows in the command buffer.
 */
typedef struct {
  uint16_t wifi_protocol; ///< PHY for TX test; values from @ref sl_wifi_rate_protocol_t
  uint16_t enable;        ///< Enable/disable TX test mode
  int16_t power;          ///< TX power in dBm
  uint32_t rate;          ///< Transmit data rate. Range: @ref sl_wifi_mcs_rate_t
  uint16_t length;        ///< TX packet length in bytes
  uint16_t mode;          ///< TX test mode
                          ///< Values 2-6 are remapped to continuous mode in UMAC
  uint16_t channel;       ///< Channel number in 2.4 GHz / 5 GHz
  uint16_t no_of_pkts;    ///< Number of packets to transmit. 0 for continuous transmission until stopped.
  uint32_t delay;         ///< Delay between packets in microseconds
  uint16_t channel_bw;    ///< Channel bandwidth
  uint16_t aggr_enable;   ///< Enable/disable aggregation
  uint16_t aggr_count;    ///< Aggregation count
  uint16_t flags;         ///< Flags. BIT(0) - immediate transfer; BIT(1)-BIT(15) reserved.
  uint16_t reserved;      ///< Reserved (padding)
} __attribute__((packed)) sli_wifi_tx_test_base_info_wire_t;

/// Valid range for short GI (@c short_gi_enable)
#define SLI_WIFI_PER_SHORT_GI_DISABLE 0
#define SLI_WIFI_PER_SHORT_GI_ENABLE  1

/// Valid range for greenfield mode (@c greenfield_mode_enable)
#define SLI_WIFI_PER_GREENFIELD_MODE_DISABLE 0
#define SLI_WIFI_PER_GREENFIELD_MODE_ENABLE  1

/// Valid range for short preamble (@c short_preamble_enable)
#define SLI_WIFI_PER_SHORT_PREAMBLE_DISABLE 0
#define SLI_WIFI_PER_SHORT_PREAMBLE_ENABLE  1

/**
 * @brief Wi-Fi 4 (802.11b/g/n) PER parameters
 * (@c wifi_protocol == @ref SL_WIFI_RATE_PROTOCOL_B_ONLY / G_ONLY / N_ONLY).
 */
typedef struct {
  uint8_t short_gi_enable;        ///< Short guard interval
  uint8_t greenfield_mode_enable; ///< Greenfield mode
  uint8_t short_preamble_enable;  ///< Short preamble
  uint16_t reserved[2];           ///< Reserved
} __attribute__((packed)) sli_wifi_11bgn_per_params_wire_t;

/**
 * @brief Wi-Fi 5 (802.11ac) PER parameters.
 * (@c wifi_protocol == @ref SL_WIFI_RATE_PROTOCOL_AC_ONLY).
 */
typedef struct {
  uint8_t short_gi_enable; ///< Short guard interval.
                           ///< Range: @c SLI_WIFI_PER_SHORT_GI_DISABLE/@c SLI_WIFI_PER_SHORT_GI_ENABLE
  uint16_t reserved[2];    ///< Reserved (padding)
} __attribute__((packed)) sli_wifi_11ac_per_params_wire_t;

/// Valid range for @c coding_type
#define SLI_WIFI_PER_CODING_TYPE_BCC  0
#define SLI_WIFI_PER_CODING_TYPE_LDPC 1

/// Valid range for @c nominal_pe (microseconds)
#define SLI_WIFI_PER_NOMINAL_PE_0US  0 ///< 0us
#define SLI_WIFI_PER_NOMINAL_PE_8US  1 ///< 8us
#define SLI_WIFI_PER_NOMINAL_PE_16US 2 ///< 16us

/// Valid range for @c ul_dl
#define SLI_WIFI_PER_DL 0 ///< AP to STA
#define SLI_WIFI_PER_UL 1 ///< STA to AP

/// Valid range for @c he_ppdu_type
typedef enum __attribute__((packed)) {
  SL_WIFI_HE_PPDU_TYPE_SU    = 0, ///< HE SU PPDU
  SL_WIFI_HE_PPDU_TYPE_ER_SU = 1, ///< HE ER SU PPDU
  SL_WIFI_HE_PPDU_TYPE_TB    = 2, ///< HE TB PPDU
  SL_WIFI_HE_PPDU_TYPE_MU    = 3, ///< HE MU PPDU
} sl_wifi_he_ppdu_type_t;

/// Valid range for @c beam_change
#define SLI_WIFI_PER_BEAM_CHANGE_SPATIAL_MAP_SAME 0 ///< pre-HE and HE fields are spatially mapped in the same way
#define SLI_WIFI_PER_BEAM_CHANGE_SPATIAL_MAP_DIFF 1 ///< pre-HE and HE fields are spatially mapped differently.

/// Valid range for AX @c bw
#define SLI_WIFI_PER_AX_BW_242_TONE_RU       0 ///< 242-tone RU
#define SLI_WIFI_PER_AX_BW_106_TONE_RU_UPPER 1 ///< upper 106-tone RU

/// Valid range for @c stbc
#define SLI_WIFI_PER_STBC_NONE    0 ///< No STBC
#define SLI_WIFI_PER_STBC_ENABLED 1 ///< STBC (only if DCM is 0)

/// Valid range for @c tx_bf
#define SLI_WIFI_PER_TX_BF_NONE    0
#define SLI_WIFI_PER_TX_BF_APPLIED 1

/// HE guard interval (GI) and LTF symbol length selection (@c gi_ltf)
typedef enum __attribute__((packed)) {
  SL_WIFI_1HE_LTF_800_NSEC_GI,  ///< 1x HE-LTF, 800 ns guard interval
  SL_WIFI_1HE_LTF_1600_NSEC_GI, ///< 1x HE-LTF, 1600 ns guard interval
  SL_WIFI_2HE_LTF_800_NSEC_GI,  ///< 2x HE-LTF, 800 ns guard interval
  SL_WIFI_2HE_LTF_1600_NSEC_GI, ///< 2x HE-LTF, 1600 ns guard interval
  SL_WIFI_4HE_LTF_800_NSEC_GI,  ///< 4x HE-LTF, 800 ns guard interval; Reserved
  SL_WIFI_4HE_LTF_3200_NSEC_GI, ///< 4x HE-LTF, 3200 ns guard interval; Reserved
} sl_wifi_gi_ltf_t;

/// Dual subcarrier modulation (DCM) enable for transmissions (@c dcm)
typedef enum __attribute__((packed)) {
  SL_WIFI_DCM_ENABLE_DISABLED = 0, ///< DCM disabled
  SL_WIFI_DCM_ENABLE_ENABLED  = 1, ///< DCM enabled
} sl_wifi_dcm_enable_t;

/// Valid range for @c nsts_midamble
#define SLI_WIFI_PER_NSTS_MIDAMBLE_MIN 0
#define SLI_WIFI_PER_NSTS_MIDAMBLE_MAX 7

/// Valid range for @c spatial_reuse
#define SLI_WIFI_PER_SPATIAL_REUSE_MIN 0
#define SLI_WIFI_PER_SPATIAL_REUSE_MAX 15

/// Valid range for @c bss_color
#define SLI_WIFI_PER_BSS_COLOR_MIN 0
#define SLI_WIFI_PER_BSS_COLOR_MAX 63

/// Valid range for @ru_allocation
#define SLI_WIFI_PER_RU_ALLOC_MIN 0
#define SLI_WIFI_PER_RU_ALLOC_MAX 255

/// Valid range for @c he_siga2_reserved
#define SLI_WIFI_PER_HE_SIGA2_RESERVED_MIN 0
#define SLI_WIFI_PER_HE_SIGA2_RESERVED_MAX 511

/// Valid range for @c n_heltf_tot
#define SLI_WIFI_PER_N_HELTF_TOT_MIN 0
#define SLI_WIFI_PER_N_HELTF_TOT_MAX 7

/// Valid range for @c sigb_dcm
#define SLI_WIFI_PER_SIGB_DCM_DISABLE 0
#define SLI_WIFI_PER_SIGB_DCM_ENABLE  1

/// Valid range for @c sigb_mcs
#define SLI_WIFI_PER_SIGB_MCS_MIN 0
#define SLI_WIFI_PER_SIGB_MCS_MAX 5

/// Valid range for @c user_idx
#define SLI_WIFI_PER_USER_IDX_MIN 0
#define SLI_WIFI_PER_USER_IDX_MAX 8

/// Valid range for @c user_sta_id
#define SLI_WIFI_PER_USER_STA_ID_MIN 0
#define SLI_WIFI_PER_USER_STA_ID_MAX 2047

/// Valid range for @c sigb_compression
#define SLI_WIFI_PER_SIGB_COMPRESSION_DISABLED 0
#define SLI_WIFI_PER_SIGB_COMPRESSION_ENABLED  1

/**
 * @brief Wi-Fi 6/6E (802.11ax) HE PER parameters.
 * (@c wifi_protocol == @ref SL_WIFI_RATE_PROTOCOL_AX_ONLY).
 */
typedef struct {
  uint8_t coding_type;        ///< Coding type.
  uint8_t nominal_pe;         ///< Nominal T-PE value
  uint8_t ul_dl;              ///< UL/DL indication
  uint8_t he_ppdu_type;       ///< HE PPDU type
  uint8_t beam_change;        ///< Spatial mapping of pre-HE and HE fields.
  uint8_t bw;                 ///< BW for PPDU.
  uint8_t stbc;               ///< STBC for PPDU transmission.
  uint8_t tx_bf;              ///< Beamforming matrix.
  uint8_t gi_ltf;             ///< HE GI and HE-LTF
                              ///< Valid range @ref sl_wifi_gi_ltf_t capped at SL_WIFI_2HE_LTF_1600_NSEC_GI.
  uint8_t dcm;                ///< DCM on data symbols; Valid range @ref sl_wifi_dcm_enable_t
  uint8_t nsts_midamble;      ///< NSTS and midamble periodicity
  uint8_t spatial_reuse;      ///< Spatial reuse. 4 indicates spatial reuse is allowed
  uint8_t bss_color;          ///< BSS color value
  uint8_t ru_allocation;      ///< RU allocation subfield for 20 MHz BW
  uint16_t he_siga2_reserved; ///< HE SIGA2 reserved field
  uint8_t n_heltf_tot;        ///< Number of HE-LTF to be transmitted
  uint8_t sigb_dcm;           ///< DCM applied to SIG-B symbols
  uint8_t sigb_mcs;           ///< MCS for SIG-B symbols
  uint8_t user_idx;           ///< User index
  uint16_t user_sta_id;       ///< Station ID of the intended user
  uint8_t sigb_compression;   ///< SIG-B compression field
  uint16_t reserved[2];       ///< Reserved (padding)
} __attribute__((packed)) sli_wifi_11ax_per_params_wire_t;

/// Valid range for @c be_ppdu_type
#define SLI_WIFI_PER_BE_PPDU_TYPE_MAX 3

/// Valid range for BE @c bw
#define SLI_WIFI_PER_BE_BW_MAX 3

/// Valid range for @c eht_sig_mcs
#define SLI_WIFI_PER_EHT_SIG_MCS_MAX 3

/// Valid range for @c disregard
#define SLI_WIFI_PER_DISREGARD_MAX 31

/**
 * @brief Wi-Fi 7 (802.11be) EHT PER parameters.
 * (@c wifi_protocol == @ref SL_WIFI_RATE_PROTOCOL_BE_ONLY).
 */
typedef struct {
  uint8_t coding_type;   ///< Coding type. @c SLI_WIFI_PER_CODING_TYPE_BCC, @c SLI_WIFI_PER_CODING_TYPE_LDPC
  uint8_t nominal_pe;    ///< Nominal T-PE value
                         ///< 0 - @c SLI_WIFI_PER_NOMINAL_PE_0US
                         ///< 1 - @c SLI_WIFI_PER_NOMINAL_PE_8US
                         ///< 2 - @c SLI_WIFI_PER_NOMINAL_PE_16US
  uint8_t ul_dl;         ///< UL/DL indication.
                         ///< 0 - @c SLI_WIFI_PER_DL (AP to STA)
                         ///< 1 - @c SLI_WIFI_PER_UL (STA to AP)
  uint8_t be_ppdu_type;  ///< BE PPDU type
  uint8_t bw;            ///< BW for PPDU
  uint8_t gi_ltf;        ///< HE GI and HE-LTF; Valid range @ref sl_wifi_gi_ltf_t
  uint8_t spatial_reuse; ///< Spatial reuse;
                         ///< Range: @c SLI_WIFI_PER_SPATIAL_REUSE_MIN - @c SLI_WIFI_PER_SPATIAL_REUSE_MAX
  uint8_t ru_allocation; ///< RU allocation subfield
  uint8_t n_heltf_tot;   ///< Number of HE-LTF to be transmitted
                         ///< Range: @c SLI_WIFI_PER_N_HELTF_TOT_MIN - @c SLI_WIFI_PER_N_HELTF_TOT_MAX
  uint8_t eht_sig_mcs;   ///< MCS for EHT SIG symbols
  uint8_t disregard;     ///< Disregard field
  uint16_t reserved[2];  ///< Reserved (padding)
} __attribute__((packed)) sli_wifi_11be_per_params_wire_t;

/************ SLI_WIFI_CMD_TRANSCEIVER_PEER_LIST_UPDATE (0x8B) ****************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_CMD_TRANSCEIVER_CONFIG_PARAMS (0x8C) *******************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_CMD_SET_TRANSCEIVER_MCAST_FILTER (0x8D) ****************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_CMD_TRANSCEIVER_FLUSH_DATA_Q (0x8E) ********************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_CMD_WIFI_RAIL (0x99) ***********************************/
/**
 * @brief
 *
 * @description
 * This is a passthrough frame forwarded to LMAC by UMAC command decoder.
 *
 */

/************ SLI_WIFI_CMD_TX_TEST_STATS (0xA2) ************************************/
/**
 * @brief Packet Error Rate (PER) statistics request configuration.
 *
 * @description
 * Consumed by UMAC (Operations manager) to start or stop PER RX-statistics
 * collection in LMAC.
 * Opermodes supported: PER
 *
 * - Request payload:
 *   @ref sli_wifi_request_rx_stats_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Response payload:
 *     - None when collection is stopped.
 *     - LMAC PER statistics; Sent from NWP to Host SDK when collection starts.
 *   - Async periodic statistics reports follow as @c SLI_WIFI_CMD_TX_TEST_STATS frames.
 *   - Async response payload (sent from LMAC to Host SDK via UMAC):
 *     - @ref sl_wifi_async_station_stats_t appended with @ref sl_wifi_async_station_stats_ext_t.
 */

/**
  * @enum sli_wifi_statistics_report_t
  * @brief Enumeration for Wi-Fi statistics report commands.
  *
  * This enumeration defines the commands to start or stop the collection of Wi-Fi statistics.
  */
typedef enum {
  SLI_WIFI_START_STATISTICS_REPORT = 0, ///< Start statistics report
  SLI_WIFI_STOP_STATISTICS_REPORT  = 1, ///< Stop statistics report
} sli_wifi_statistics_report_t;

/// PER stats command request structure
typedef struct {
  unsigned short start;   ///< Start or stop PER RX statistics collection
  unsigned short channel; ///< Channel number
} sli_wifi_request_rx_stats_t;

typedef struct {
  uint16_t tx_pkts;      ///< Number of Tx packets
  uint16_t rx_pkts;      ///< Number of Rx packets
  uint16_t tx_retries;   ///< Number of Tx retries
  uint16_t crc_pass;     ///< Number of packets that pass crc check
  uint16_t crc_fail;     ///< Number of packets failing crc check
  uint16_t cca_stk;      ///< Number of times cca got stuck
  uint16_t cca_not_stk;  ///< Number of times cca didn't get stuck
  uint16_t pkt_abort;    ///< Number of packet aborts
  uint16_t fls_rx_start; ///< Number of false Rx starts
  uint16_t cca_idle;     ///< CCA idle time
  struct {
    uint16_t gf_pkts; ///< Number of greenfield packets
    uint16_t ht_pkts; ///< Number of high throughput packets
    uint16_t leg_pkt; ///< Number of legacy packets
    uint16_t leg_prty_fails;
    uint16_t ht_crc_fails; ///< Number of ht packets failing crc check
    uint16_t sp_rejected;
    uint16_t lp_rejected;
  } __attribute__((packed));
  struct {
    uint16_t ch1_sig_pow;   ///< Channel 1 signal power
    uint16_t ch1_noise_pow; ///< channel 1 noise power
    uint16_t ch2_sig_pow;   ///< channel 2 signal power
    uint16_t ch2_noise_pow; ///< channel 2 noise power
    uint16_t ch3_sig_pow;   ///< channel 3 signal power
    uint16_t ch3_noise_pow; ///< channel 3 noise power
  } __attribute__((packed));
  struct {
    uint16_t rx_retries; ///< Number of Rx retries
    int16_t rssi;        ///< RSSI is 16 bit value in Q8.2 format with sign extension
    int16_t cal_rssi;    ///< Averaged RSSI converted to deci-dBm
    uint16_t reserved;
    uint16_t avg_val;               ///< Average value
    uint16_t xretries;              ///< xretries packets dropped
    uint16_t max_cons_pkts_dropped; ///< Consecutive packets dropped
    uint16_t false_under_sat;
    uint16_t bss_broadcast_pkts;            ///< BSS matched broadcast packets count
    uint16_t bss_multicast_pkts;            ///< BSS matched multicast packets count
    uint16_t bss_da_matched_multicast_pkts; ///< BSS and DA matched multicast packets count
    uint32_t eof_pkt_drop_count;
    uint32_t mask_pkt_drop_count;
  } __attribute__((packed));
} __attribute__((packed)) sl_wifi_async_station_stats_t;

typedef struct {
  uint32_t no_of_acks_sent;
  uint16_t pkt_rcvd_with_48M; ///< Number of packets received with 48M
  uint16_t pkt_rcvd_with_24M; ///< Number of packets received with 24M
  uint16_t pkt_rcvd_with_12M; ///< Number of packets received with 12M
  uint16_t pkt_rcvd_with_6M;  ///< Number of packets received with 6M
  uint16_t pkt_rcvd_with_54M; ///< Number of packets received with 54M
  uint16_t pkt_rcvd_with_36M; ///< Number of packets received with 36M
  uint16_t pkt_rcvd_with_18M; ///< Number of packets received with 18M
  uint16_t pkt_rcvd_with_9M;  ///< Number of packets received with 9M
  uint16_t pkt_rcvd_with_11M; ///< Number of packets received with 11M
  uint16_t pkt_rcvd_with_5M;  ///< Number of packets received with 5.5M
  uint16_t pkt_rcvd_with_2M;  ///< Number of packets received with 2M
  uint16_t pkt_rcvd_with_1M;  ///< Number of packets received with 1M
  struct {
    uint16_t pkt_rcvd_with_mcs0; ///< Number of packets received with mcs0
    uint16_t pkt_rcvd_with_mcs1; ///< Number of packets received with mcs1
    uint16_t pkt_rcvd_with_mcs2; ///< Number of packets received with mcs2
    uint16_t pkt_rcvd_with_mcs3; ///< Number of packets received with mcs3
    uint16_t pkt_rcvd_with_mcs4; ///< Number of packets received with mcs4
    uint16_t pkt_rcvd_with_mcs5; ///< Number of packets received with mcs5
    uint16_t pkt_rcvd_with_mcs6; ///< Number of packets received with mcs6
    uint16_t pkt_rcvd_with_mcs7; ///< Number of packets received with mcs7
    uint16_t pkt_rcvd_with_mcs8; ///< Number of packets received with mcs8
    uint16_t pkt_rcvd_with_mcs9; ///< Number of packets received with mcs9
  } __attribute__((packed));
  struct {
    uint16_t pkt_count_he_su_ppdu;    ///< Number of HE SU packets received
    uint16_t pkt_count_he_er_su_ppdu; ///< Number of HE ER SU packets received
    uint16_t pkt_count_he_trig_ppdu;  ///< Number of HE TB packets received
    uint16_t pkt_count_he_mu_ppdu;    ///< Number of HE MU packets received
    uint16_t pkt_count_11ac;          ///< Number of 11ac packets received
    uint16_t rate_non_6mbps;          ///< Non 6mbps packets
    uint16_t lsig_parity_pass_stat;
    uint16_t lsig_parity_fail_stat;
    uint16_t lsig_crc_pass_stat;
    uint16_t lsig_crc_fail_stat;
    uint16_t rate_11be_stat;
    uint16_t unsupported_rate_stat;  ///< Unsupported rate packets
    uint16_t no_of_tx_per_pkts_cnt;  ///< Total Tx per packets count
    uint16_t he_mu_mimo_pkt_cnt_ta;  ///< MU MIMO packets
    uint16_t he_mu_ofdma_pkt_cnt_ta; ///< MU OFDMA packets
    uint32_t rcpi;                   ///< RCPI from averaged receive RSSI
    int32_t rsni;                    ///< RSNI as signal_power - IFS noise in deci-dB (dB * 10)
    uint32_t pkt_rcvd_with_ta_match; ///< Number of packets received with TA match
    uint32_t mlo_switch_time;
  } __attribute__((packed));
} __attribute__((packed)) sl_wifi_async_station_stats_ext_t;

/************* SLI_WIFI_CMD_AP_STOP (0xAE) ************************************/
/**
 * @brief Stop Wi-Fi AP interface
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP FSM) to disconnect associated
 * stations and bring down the Wi-Fi AP interface.
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_MEMORY_FAILED_FROM_MODULE - Insufficient memory to construct the
 *       deauthentication frame
 *   - Response payload:
 *     - None
 *
 * @note Async indications that may follow AP stop:
 *       @c SLI_NWP_IND_STA_REMOVE
 */

/************ SLI_WIFI_CMD_SET_REGION_AP (0xBD) *******************************/
/**
 * @brief Configures region and corresponding regulatory domain settings.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific) to set AP-mode
 * regulatory domain and per-channel rules. The configured region applies to
 * all active VAPs.
 * Opermodes supported: AP
 *
 * - Request payload:
 *   @ref sli_wifi_set_region_ap_request_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_AP_SET_REGION_COMMAND_ERROR - Invalid region-configuration source
 *       value.
 *     - @c SLI_STATUS_AP_SET_REGION_COMMAND_PARAMETERS_ERROR - Invalid channel-rule parameters.
 *     - @c SLI_STATUS_REGION_CODE_NOT_SUPPORTED - Country code is not supported.
 *   - Response payload:
 *     - None
 *
 * @note Management interface currently does not support this frame.
 */

#define SLI_WIFI_MAX_POSSIBLE_CHANNEL 24

/// Valid range for @c no_of_rules (i.e @c channel_info entries)
#define SLI_WIFI_REG_CHAN_NUM_RULES_MIN 1
#define SLI_WIFI_REG_CHAN_NUM_RULES_MAX 24

/// Valid range for number of channels covered by a rule (@c no_of_channels)
#define SLI_WIFI_REG_CHAN_NUM_CHAN_MIN 1
#define SLI_WIFI_REG_CHAN_NUM_CHAN_MAX 14

/// Max Tx power(dBm) related macro
#define SLI_WIFI_REG_CHAN_MAX_TX_POWER 33

/// Set region in AP mode command request structure
typedef struct {
  /// Set region configuration from user
  /// 0 - Take from @c country_code
  /// @c SET_REGION_CODE_FROM_USER - Take from user configuration (@c country_code, @c channel_info)
  uint8_t set_region_code_from_user_cmd;
  uint8_t country_code
    [SLI_WIFI_COUNTRY_CODE_LENGTH]; ///< Country code string used to select the regulatory domain. Valid values: US, EU, JP, KR, CN.
  uint32_t no_of_rules;             ///< Number of @c channel_info entries; must be non-zero for host-driven mode
  struct {
    uint8_t first_channel;                       ///< First channel of the rule
    uint8_t no_of_channels;                      ///< Number of channels covered by the rule
    uint8_t max_tx_power;                        ///< Max Tx power for the rule in dBm
  } channel_info[SLI_WIFI_MAX_POSSIBLE_CHANNEL]; ///< Channel information
} sli_wifi_set_region_ap_request_t;

/************ SLI_WIFI_CMD_CONFIG (0xBE) **************************************/
/**
 * @brief Configures the Request-To-Send (RTS) threshold in bytes.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific) to configure the
 * RTS threshold and, for an initialized VAP, update LMAC through CMD_VAP_CAPS.
 * Opermodes supported: AP, STA
 *
 * - Request payload:
 *   @ref sli_wifi_config_request_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_INVALID_CONFIG_TYPE - Unsupported config type
 *     - @c SLI_STATUS_INVALID_CONFIG_RANGE_PROVIDED - Invalid value
 *   - Response payload:
 *     - None
 *
 * @note Management interface currently does not support forwarding this frame
 * to NWP.
 */
/// Configuration type values
#define SLI_WIFI_CONFIG_RTS_THRESHOLD 1

/// RTS threshold value in bytes for @c SLI_WIFI_CONFIG_RTS_THRESHOLD
#define SLI_WIFI_RTS_THRESHOLD_MIN     0
#define SLI_WIFI_RTS_THRESHOLD_MAX     2347
#define SLI_WIFI_RTS_THRESHOLD_DEFAULT 2346

/// Config command request structure
typedef struct {
  uint16_t config_type; ///< Configuration type
  uint16_t value; ///< Value to set; for RTS threshold, @c SLI_WIFI_RTS_THRESHOLD_MIN to @c SLI_WIFI_RTS_THRESHOLD_MAX
} sli_wifi_config_request_t;

/************ SLI_WIFI_CMD_GET_CSI_DATA (0xC4) ********************************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_COMMON_CMD_FEATURE_FRAME (0xC8) ************************/
/**
 * @brief Programs wireless-mode and feature enables bitmap.
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific, UMAC/LMAC interface) to
 * configure feature parameters to LMAC.
 * In STA mode, UMAC preserves only a subset of @c feature_enables bits before
 * programming LMAC.
 *
 * @note: @c wireless_mode, @c feature_enables is unused in UMAC.
 *
 * - Request payload:
 *   @ref sli_wifi_feature_frame_request_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success.
 *   - Response payload:
 *     - None
 */

/// Feature enables bitmap related macros
#define SLI_FEAT_FRAME_PERMIT_UNDESTINED_PACKETS BIT(1)
#define SLI_FEAT_FRAME_DPD_ENABLE                BIT(3)
#define SLI_FEAT_FRAME_POWER_SAVE_OPT_IN         (BIT(1) | BIT(7) | BIT(30))
#define SLI_FEAT_FRAME_DISABLE_WLAN_KEEP_ALIVE   BIT(27)
#define SLI_FEAT_FRAME_BACKWARD_AUTORATE_VALUES  (BIT(28) | BIT(29))

typedef struct {
  uint8_t pll_mode;            ///< Reserved
  uint8_t rf_type;             ///< Reserved
  uint8_t wireless_mode;       ///< Reserved
  uint8_t enable_ppp;          ///< Reserved
  uint8_t afe_type;            ///< Reserved
  uint8_t disable_programming; ///< Reserved
  uint16_t reserved;           ///< Reserved
  uint32_t feature_enables;    ///< Feature enables bitmap
} sli_wifi_feature_frame_request_t;

/************ SLI_WIFI_CMD_FILTER_BCAST_PACKETS (0xC9) ************************/
/**
 * @brief Configure broadcast filtering on the station interface.
 *
 * @description
 * Consumed by UMAC (UMAC/LMAC interface) to configure broadcast filtering
 * parameters in LMAC.
 *
 * - Request payload:
 *   @ref sli_wifi_request_wlan_filter_broadcast_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SL_STATUS_FAIL - Failed to program broadcast-filter configuration to
 *       LMAC.
 *   - Response payload:
 *     - None
 */

typedef struct {
  uint8_t beacon_drop_threshold[2];       ///< Beacon drop threshold
  uint8_t filter_bcast_in_tim;            ///< Filter broadcast in TIM
  uint8_t filter_bcast_tim_till_next_cmd; ///< Filter broadcast TIM till next command
} sli_wifi_request_wlan_filter_broadcast_t;

/**************** SLI_WIFI_CMD_FULL_FW_VERSION (0xE0) *************************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_CMD_TIMEOUT (0xEA) *************************************/
/**
 * @brief Configure Wi-Fi Timeouts
 *
 * @description
 * Consumed by UMAC (Command decoder - device-specific) to configure
 * active-scan, passive-scan, authentication, association, and keep-alive
 * timeouts used by later operations.
 * Opermodes supported: AP, STA
 *
 * - Request payload:
 *   @ref sli_wifi_request_timeout_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_WRONG_PARAMETERS - Invalid range for timeout_value
 *   - Response payload:
 *     - None
 */

/// Wi-Fi timeout type bitmap definitions
/// Used for setting association and authentication timeout request in milliseconds
#define SLI_WIFI_AUTH_ASSOC_TIMEOUT BIT(0)
/// Used for setting dwell time per channel in milliseconds during active scan
#define SLI_WIFI_CHANNEL_ACTIVE_SCAN_TIMEOUT BIT(1)
/// Used for setting WLAN keep alive time in seconds
#define SLI_WIFI_KEEP_ALIVE_TIMEOUT BIT(2)
/// Used for setting dwell time per channel in milliseconds during passive scan
#define SLI_WIFI_PASSIVE_SCAN_DWELL_TIME BIT(3)

/// Authentication and Association timeout values
#define SLI_WIFI_AUTH_ASSOC_TIMEOUT_MS_MIN     1
#define SLI_WIFI_AUTH_ASSOC_TIMEOUT_MS_DEFAULT 300

/// Active scan dwell time values
#define SLI_WIFI_ACTIVE_SCAN_DWELL_TIME_MS_MIN     1
#define SLI_WIFI_ACTIVE_SCAN_DWELL_TIME_MS_DEFAULT 100

/// Passive scan dwell time values
#define SLI_WIFI_PASSIVE_SCAN_DWELL_TIME_MS_MIN     5
#define SLI_WIFI_PASSIVE_SCAN_DWELL_TIME_MS_MAX     1000
#define SLI_WIFI_PASSIVE_SCAN_DWELL_TIME_MS_DEFAULT 400

/// Keep alive timeout values
#define SLI_WIFI_KEEP_ALIVE_TIMEOUT_SEC_DEFAULT 30

/// Request timeout structure
typedef struct {
  uint32_t timeout_bitmap; ///< Wi-Fi timeout type bitmap
  uint16_t timeout_value;  ///< Timeout value
} sli_wifi_request_timeout_t;

/************ SLI_WIFI_CMD_GET_STATS (0xF1) ***********************************/
/**
 * @brief Query beacon statistics.
 *
 * @description
 * Consumed by UMAC (UMAC/LMAC interface) to return beacon statistics.
 * When in connected state, UMAC queries LMAC; otherwise UMAC returns an empty
 * statistics payload.
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - Immediate success or failure / deferred success or failure response
 *   - Status is filled in host-descriptor; @c 0 on success.
 *   - Response payload:
 *     @ref sl_wifi_operational_statistics_t; Sent from NWP to Host SDK.
 *
 * @note Currently not supported in LMAC.
 */

/// Wi-Fi operational statistics structure
typedef struct {
  uint8_t operating_mode;       ///< Operating mode of the Wi-Fi interface
  uint8_t dtim_period;          ///< DTIM (Delivery Traffic Indication Message) period
  uint8_t ideal_beacon_info[2]; ///< Ideal beacon information
  uint8_t busy_beacon_info[2];  ///< Busy beacon information
  uint8_t beacon_interval[2];   ///< Beacon interval in Time Units (TUs)
} sl_wifi_operational_statistics_t;

/************ SLI_WIFI_CMD_FREQ_OFFSET (0xF3) *********************************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_CMD_11AX_PARAMS (0xFF) *********************************/
/**
 * @brief Configure 11ax parameters in STA mode.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to configure 11ax
 * settings and rate parameters used by subsequent association processing.
 *
 * - Request payload:
 *   @ref sli_wifi_11ax_config_params_t; Sent from Host SDK to NWP.
 *
 * - Response:
 *   - Returns a response immediately.
 *   - Status is filled in host-descriptor; @c 0 on success, error code
 *     otherwise
 *   - Possible error codes:
 *     - @c SLI_STATUS_NO_11AX_SUPPORT_IN_AP - Command is not supported in AP mode.
 *   - Response payload:
 *     - None
 */

/// 11AX parameter ranges

/// Valid range for guard_interval
#define SLI_WIFI_11AX_GUARD_INTERVAL_MIN 0
#define SLI_WIFI_11AX_GUARD_INTERVAL_MAX 3

/// Valid range for nominal_pe (microseconds)
#define SLI_WIFI_11AX_NOMINAL_PE_MIN 0
#define SLI_WIFI_11AX_NOMINAL_PE_MAX 2

/// Valid range for dcm_enable
#define SLI_WIFI_11AX_DCM_DISABLE 0
#define SLI_WIFI_11AX_DCM_ENABLE  1

/// Valid range for ldpc_enable
#define SLI_WIFI_11AX_LDPC_DISABLE 0
#define SLI_WIFI_11AX_LDPC_ENABLE  1

/// Valid range for ng_cb_enable
#define SLI_WIFI_11AX_NG_CB_DISABLE 0
#define SLI_WIFI_11AX_NG_CB_ENABLE  1

/// Valid range for ng_cb_values
#define SLI_WIFI_11AX_NG_CB_VALUES_MIN  0x00
#define SLI_WIFI_11AX_NG_CB_VALUES_MAX  0x11
#define SLI_WIFI_11AX_NG_CB_VALUES_MASK 0xEE

/// Bitmap for trigger_rsp_ind
#define SLI_WIFI_11AX_TRIG_RSP_IND_BE BIT(0)
#define SLI_WIFI_11AX_TRIG_RSP_IND_BK BIT(1)
#define SLI_WIFI_11AX_TRIG_RSP_IND_VI BIT(2)
#define SLI_WIFI_11AX_TRIG_RSP_IND_VO BIT(3)

/// Valid range for ipps_valid_value
#define SLI_WIFI_11AX_IPPS_DISABLE 0
#define SLI_WIFI_11AX_IPPS_ENABLE  1

/// Valid range for tx_only_on_ap_trig
#define SLI_WIFI_11AX_TX_ONLY_ON_AP_TRIG 2

/// Valid range for twt_support
#define SLI_WIFI_11AX_TWT_SUPPORT_DISABLE 0
#define SLI_WIFI_11AX_TWT_SUPPORT_ENABLE  1

/// Valid range for config_er_su
#define SLI_WIFI_11AX_ER_SU_DISABLE        0 ///< No ER_SU support
#define SLI_WIFI_11AX_ER_SU_WITH_NON_ER_SU 1 ///< Use ER_SU rates along with Non_ER_SU rates
#define SLI_WIFI_11AX_ER_SU_ONLY           2 ///< Use ER_SU rates only

/// Valid range for beamformee_support
#define SLI_WIFI_11AX_BFEE_SUPPORT_ENABLED    0x00
#define SLI_WIFI_11AX_DISABLE_SU_BFEE_SUPPORT 0x01
#define SLI_WIFI_11AX_DISABLE_MU_BFEE_SUPPORT 0x02

/// 11AX configuration parameters
typedef struct {
  uint8_t guard_interval;     ///< Period of time inserted between two packets in wireless transmission.
  uint8_t nominal_pe;         ///< Nominal Packet extension.
  uint8_t dcm_enable;         ///< Enable or disable dual carrier modulation (DCM).
  uint8_t ldpc_enable;        ///< Enable or disable low-density parity-check (LDPC)
  uint8_t ng_cb_enable;       ///< Enable/disable non-contiguous channel bonding (NG CB).
  uint8_t ng_cb_values;       ///< Values of non-contiguous channel bonding (NG CB).
  uint8_t uora_enable;        ///< Reserved.
  uint8_t trigger_rsp_ind;    ///< Trigger response indication.
  uint8_t ipps_valid_value;   ///< IPPS valid value.
  uint8_t tx_only_on_ap_trig; ///< Reserved
  uint8_t twt_support;        ///< Enable or Disable TWT.
  uint8_t config_er_su;       ///< Extended Range Single User.
  uint8_t beamformee_support; ///< Flag indicating Beamformee support.
} sli_wifi_11ax_config_params_t;

/************ SLI_WIFI_IND_TRANSCEIVER_TX_DATA_STATUS (0x3D) ****************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_WIFI_IND_TWT_ASYNC (0x71) ***********************************/
/**
 * @brief Asynchronous TWT session outcome indication.
 *
 * @description
 * Async indication from NWP (Connection Manager - STA FSM) to Host SDK
 * reporting TWT setup, teardown, inactivity, or reschedule outcomes.
 * Opermodes supported: STA
 *
 * - Payload:
 *   @ref sl_wifi_twt_response_t; Sent from NWP to Host SDK.
 *   - Full payload - for all TWT request or responses (TWT status < @c SLI_STATUS_TWT_TEARDOWN_SUCCESS)
 *   - Payload with @c twt_flow_id and @c negotiation_type only - for TWT tear down and
 *     TWT information frame response (TWT status >= @c SLI_STATUS_TWT_TEARDOWN_SUCCESS)
 *   - No payload: @c SLI_STATUS_TWT_INACTIVE_NO_AP_SUPPORT
 *
 * - TWT status encoded in host descriptor:
 *   - @c TWT_SESSION_SUCC - Solicited TWT setup succeeded
 *   - @c SLI_STATUS_TWT_UNSOL_SESSION_SUCCESS - Unsolicited TWT setup succeeded
 *   - @c SLI_STATUS_TWT_SETUP_AP_REJECTED - AP rejected TWT setup
 *   - @c SLI_STATUS_TWT_SETUP_RSP_OUTOF_TOL - AP TWT response outside tolerance
 *   - @c SLI_STATUS_TWT_SETUP_RSP_NOT_MATCHED - AP TWT response did not match request
 *   - @c SLI_STATUS_TWT_SETUP_UNSUPPORTED_RSP - Unsupported TWT setup response
 *   - @c SLI_STATUS_TWT_TEARDOWN_SUCCESS - Local TWT teardown succeeded
 *   - @c SLI_STATUS_TWT_AP_TEARDOWN_SUCCESS - AP-initiated TWT teardown succeeded
 *   - @c SLI_STATUS_TWT_SETUP_FAIL_MAX_RETRIES_REACHED - TWT setup failed after max retries
 *   - @c SLI_STATUS_TWT_INACTIVE_DUETO_ROAMING - Reserved
 *   - @c SLI_STATUS_TWT_INACTIVE_DUETO_DISCONNECT - TWT ended due to disconnect
 *   - @c SLI_STATUS_TWT_INACTIVE_NO_AP_SUPPORT - AP does not support TWT responder mode
 *   - @c SLI_STATUS_RESCHEDULE_TWT_SUCCESS - TWT Information / reschedule succeeded
 *   - @c SLI_STATUS_TWT_INFO_FRAME_EXCHANGE_FAILED - TWT Information frame exchange failed
 *   - @c SLI_STATUS_TWT_EVENTS_END - Reserved
 *
 * See @c SLI_WIFI_CMD_TWT_PARAMS for detailed description of fields.
 */

/// TWT response structure
typedef struct {
  uint8_t wake_duration;      ///< Wake duration
  uint8_t wake_duration_unit; ///< Wake duration unit
  uint8_t wake_int_exp;       ///< Wake interval exponent
  uint8_t negotiation_type;   ///< Negotiation type
  uint16_t wake_int_mantissa; ///< Wake interval mantissa
  uint8_t implicit_twt;       ///< Implicit TWT
  uint8_t un_announced_twt;   ///< Unannounced TWT
  uint8_t triggered_twt;      ///< Triggered TWT
  uint8_t twt_channel;        ///< TWT channel
  uint8_t twt_protection;     ///< TWT Protection
  uint8_t twt_flow_id;        ///< TWT flow ID
} sl_wifi_twt_response_t;

/*************** SLI_WIFI_IND_SCAN_RESULTS (0xAF) *****************************/
/**
 * @brief Per-BSS scan result indication to Host SDK.
 *
 * @description
 * Async indication from management interface to Host SDK. Management interface
 * forms this indication by retagging selected @c SLI_WIFI_IND_ON_AIR_MGMT
 * packets received from NWP during scan.
 * Opermodes: STA, AP
 *
 * - Packets forwarded from management interface to Host SDK:
 *   - Beacon frame
 *   - Probe response frame
 *
 * - Host-descriptor fields filled by management interface:
 *   - @c DW2.B0 / @c DW2.B1 - receive frequency
 *   - @c DW2.B2 - RSSI (low byte of signed deci-dBm)
 *   - @c DW2.B3 - receive channel
 *
 * - Payload:
 *   - IEEE 802.11 beacon or probe-response frame; Sent from management
 *     interface to Host SDK.
 *
 * @note Other @c SLI_WIFI_IND_ON_AIR_MGMT subtypes (for example probe request
 *       or action frames) are not converted to this indication.
 */

/******************************************************************************/
/**************** Internal management frames - Tx request IDs *****************/
/******************************************************************************/

#define SLI_WIFI_TX_DOT11_MGMT_FRAME               0x00
#define SLI_NWP_CMD_11W_BIP_VALIDATION             0x0F
#define SLI_MGMTIF_CMD_SET_KEYS                    0x30
#define SLI_MGMTIF_CMD_LOAD_IE_INFO                0x31
#define SLI_MGMTIF_CMD_TX_P2P_ACTION_FRAME         0x32
#define SLI_MGMTIF_CMD_LOAD_AP_CAPS                0x34
#define SLI_MGMTIF_CMD_SET_CHANNEL                 0x35
#define SLI_MGMTIF_CMD_SET_LISTEN_MODE             0x36
#define SLI_MGMTIF_CMD_REJOIN_FAIL                 0x37
#define SLI_MGMTIF_CMD_GTK_REKEY_DATA              0x39
#define SLI_NWP_CMD_VALIDATE_PMKID_SEND_ASSOC_RESP 0x56
#define SLI_MGMTIF_CMD_SWITCH_BAND                 0x69
#define SLI_MGMTIF_CMD_ROAM_IND                    0x6B
#define SLI_MGMTIF_CMD_NULL_AND_BLK_UNBLK          0x6C
#define SLI_MGMTIF_CMD_DEAUTH_FROM_ROAM            0x6E
#define SLI_MGMTIF_CMD_UPDATE_FT_IES_FROM_SUPP     0x7D ///< Reserved
#define SLI_MGMTIF_CMD_LOAD_FT_ACTION_IE           0x7F ///< Reserved
#define SLI_MGMTIF_CMD_SEND_TARGET_AP_INFO         0x80 ///< Reserved
#define SLI_MGMTIF_CMD_SAE_CONFIRM_SUCCESS         0xCA
#define SLI_MGMTIF_CMD_SAE_COMMIT_STATUS           0xCB
#define SLI_MGMTIF_CMD_SEND_DEVINFO_WIFI           0xCC ///< Host→NWP DEVINFO-WIFI (OTP Element 11) delivery

/*********** Internal management frames - Tx frame subtypes *******************/

#define NULL_DATA_CONFIRM            0xE0
#define EAPOL4_CONFIRM               0xEE
#define TWT_INFO_FRAME_CONFIRM       0xEF
#define SLI_PROBE_CONFIRM_INDICATION 0xFE

/******************************************************************************/
/*********** Internal management frames - Rx response/indication IDs **********/
/******************************************************************************/

#define SLI_WIFI_IND_CARD_READY              0x00
#define SLI_NWP_IND_ON_AIR_MGMT              0x02
#define SLI_NWP_IND_TX_STATUS                0x04
#define SLI_NWP_IND_DECRYPT_ERROR            0x07
#define SLI_NWP_IND_FAST_PSP_TIM             0x35
#define SLI_NWP_IND_CURR_OPER_CHAN_UPDATE    0x93
#define SLI_NWP_CMD_VALIDATE_PMKID_ASSOC_REQ 0xF3

#define SLI_NWP_IND_STA_ADD      0x00A8
#define SLI_NWP_IND_STA_REMOVE   0x00A9
#define SLI_WIFI_IND_ON_AIR_MGMT 0x00AA

/******************************************************************************/
/***************** Internal management frames - payloads **********************/
/******************************************************************************/

/************** SLI_WIFI_TX_DOT11_MGMT_FRAME (0x00) ***************************/
/**
 * @brief Queue an already-formed IEEE 802.11 management frame to LMAC.
 *
 * @description
 * Consumed by UMAC (Packet Handler path) to transmit an IEEE 802.11 management
 * frame formed by the management interface. For EAPOL, UMAC command decoder
 * validates Connection Manager context and updates the host descriptor before
 * queuing to LMAC; other frame types are queued to LMAC unchanged.
 *
 * - Request payload:
 *   - Peer MAC address in the first six bytes of the extended descriptor for
 *     EAPOL frames only.
 *   - IEEE 802.11 frame; Sent from management interface to NWP.
 *
 * - Response:
 *   - No response is returned.
 */

/************** SLI_NWP_CMD_11W_BIP_VALIDATION (0x0F) *************************/
/**
 * @brief Request BIP MIC validation for a broadcast deauth/disassoc, then
 * continue PMF disconnect processing with the host result.
 *
 * @description
 * Consumed by UMAC (Packet Handler - STA). When PMF (11w) is enabled and a
 * broadcast deauthentication or disassociation is received, Packet Handler
 * forwards the RX descriptor and frame to the management interface for BIP MIC
 * validation. The management interface returns the same frame type with a MIC
 * status byte; UMAC continues disconnect processing only on success.
 *
 * - Request payload (NWP to management interface):
 *   - RX host descriptor and IEEE 802.11 deauth/disassoc frame; Sent from NWP
 *     to management interface.
 *
 * - Response payload (management interface to NWP):
 *   - Byte 0: MIC status; @c 0 on success, non-zero on failure
 *   - Original RX host descriptor and IEEE 802.11 deauth/disassoc frame; Sent
 *     from management interface to NWP.
 *
 * @note On successful MIC validation, disconnect may follow as a deferred
 * @c SLI_WIFI_CMD_JOIN status @c SLI_STATUS_DEAUTHENTICATION_RECEIVED_FROM_AP
 * with a 1-byte reason code.
 */

/************ SLI_MGMTIF_CMD_SET_KEYS (0x30) **********************************/
/**
 * @brief Install PTK/GTK keys, or mark IGTK for PMF.
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP/STA FSM) to install
 * pairwise or group keys to LMAC, or to enable 11w when the high nibble selects
 * IGTK. On STA WPA/WPA2/enterprise paths with an outstanding EAPOL confirm, the
 * key install may be queued until EAPOL completes.
 *
 * - Host-descriptor:
 *   - @c DW1.B3 selects interface; 0 = STA, 1 = AP
 *
 * - Request payload:
 *   @ref sli_mgmtif_set_keys_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - No response is returned on success.
 *   - On failure, returns @c SLI_MGMTIF_CMD_SET_KEYS immediately.
 *   - Status is filled in host-descriptor; error code otherwise
 *   - Possible error codes:
 *     - @c SL_STATUS_FAIL - AP mode: no connected station matches
 *       @c mac_address
 *   - Response payload:
 *     - None
 */

/// Key type values (low nibble of @c type)
#define SLI_WIFI_KEY_TYPE_PTK 1 ///< Pairwise transient key
#define SLI_WIFI_KEY_TYPE_GTK 2 ///< Group temporal key

#define SLI_WIFI_INSTALL_KEY BIT(7)

/// Max key length
#define SLI_WIFI_MAX_KEY_LEN 32

/// WPA Algorithm values (high nibble of @c type)
/// Enum sli_wifi_wpa_alg_t is aligned with enum wpa_alg {} present in wpa_supplicant.

typedef struct {
  uint8_t type;                      ///< Low nibble: @c SLI_WIFI_KEY_TYPE_PTK or @c SLI_WIFI_KEY_TYPE_GTK;
                                     ///< High nibble: @c sli_wifi_wpa_alg_t
  uint8_t key_id;                    ///< Bits [1:0] = key ID; remaining bits reserved on the NWP path
  uint8_t key[SLI_WIFI_MAX_KEY_LEN]; ///< Key to be loaded
  uint8_t mac_address[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< STA MAC in AP mode; reserved in STA mode
  uint8_t key_len;                                 ///< Key length; must be <= @c SLI_WIFI_MAX_KEY_LEN
} sli_mgmtif_set_keys_t;

/************ SLI_MGMTIF_CMD_LOAD_IE_INFO (0x31) ******************************/
/**
 * @brief Load Information Element(s) into per-frame-type IE storage.
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP/STA FSM) to store host-
 * supplied IEs used when constructing beacon, probe, and association
 * management frames. In STA mode, UMAC replaces the per-frame-type IE cache;
 * in AP and other modes, UMAC merges IEs by element ID into the existing cache.
 *
 * - Request payload:
 *   @ref sli_mgmtif_load_ie_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - No response is returned.
 */
#define SLI_WIFI_MAX_IE_SIZE        300 ///< Max IE data length
#define SLI_WIFI_NUM_IE_FRAME_TYPES 5   ///< Max frame types supported

/// Management frame type for IE load
#define SLI_WIFI_IE_ASSOC_REQ 0x00
#define SLI_WIFI_IE_ASSOC_RES 0x01
#define SLI_WIFI_IE_PROBE_REQ 0x02
#define SLI_WIFI_IE_PROBE_RES 0x03
#define SLI_WIFI_IE_BEACON    0x04

typedef struct {
  uint16_t frame_type;                   ///< Management frame type
  uint16_t ie_length;                    ///< IE length; Valid range: 0 – @c SLI_WIFI_MAX_IE_SIZE
  uint8_t ie_data[SLI_WIFI_MAX_IE_SIZE]; ///< IE(s) to add into @c frame_type
} sli_mgmtif_load_ie_t;

/************ SLI_MGMTIF_CMD_TX_P2P_ACTION_FRAME (0x32) ***********************/
/**
 * @brief This frame is reserved (P2P only).
 */

/************ SLI_MGMTIF_CMD_LOAD_AP_CAPS (0x34) ******************************/
/**
 * @brief Load the AP capability bitmask into the VAP.
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP FSM) to store host-supplied AP
 * capability flags into the AP VAP.
 *
 * - Request payload:
 *   @ref sli_mgmtif_load_ap_caps_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - Returns @c SLI_MGMTIF_CMD_LOAD_AP_CAPS immediately.
 *   - Status is filled in host-descriptor; @c 0 on success.
 *   - Response payload:
 *     - None
 */

typedef struct {
  uint32_t ap_capabilities; ///< SDK-MGMTIF: AP capability bitmask derived from AP security type
                            ///< (privacy and WPA1/WPA2 bits as applicable).
                            ///< HOST-NWP: Enables short-slot, short-preamble bits and optionally
                            ///< hidden-SSID, WME bits which are stored into VAP capability flags
                            ///< along with host-supplied bits. Used downstream when building AP
                            ///< capability IEs and validating association.
} sli_mgmtif_load_ap_caps_t;

/************ SLI_MGMTIF_CMD_SET_CHANNEL (0x35) *******************************/
/**
 * @brief Set the operating channel (P2P only).
 *
 * @description
 * Consumed by UMAC (Connection Manager - device-specific) to set the
 * operating channel.
 *
 * - Request payload:
 *   @ref sli_mgmtif_set_channel_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - Returns @c SLI_MGMTIF_CMD_SET_CHANNEL immediately.
 *   - Status is filled in host-descriptor; @c 0 on success.
 *   - Response payload:
 *     - 2-byte operating channel; Sent from NWP to management interface.
 */

/// Set channel command payload information
typedef struct {
  uint16_t channel_number; ///< Operating channel
                           ///< Valid channel range: 0 for all channels, 1–14 for 2.4 GHz and 36–165 for 5 GHz.
} sli_mgmtif_set_channel_t;

/************ SLI_MGMTIF_CMD_SET_LISTEN_MODE (0x36) ***************************/
/**
 * @brief This frame is reserved (P2P only).
 */

typedef struct {
  uint16_t probe_report; ///< Listen mode for on-air probe request reporting.
} sli_mgmtif_listen_mode_t;

/****************** SLI_MGMTIF_CMD_REJOIN_FAIL (0x37) *************************/
/**
 * @brief Rejoin failure indication sent from management interface.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to clear the rejoin flag
 * and, when queues were previously blocked, unblock them after rejoin failure
 * or completion.
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - No response is returned.
 */

/************ SLI_MGMTIF_CMD_GTK_REKEY_DATA (0x39) ****************************/
/**
 * @brief This frame is reserved.
 */

#define SLI_WIFI_KEK_LENGTH            16
#define SLI_WIFI_KCK_LENGTH            16
#define SLI_WIFI_REPLAY_COUNTER_LENGTH 8

typedef struct {
  uint8_t kek[SLI_WIFI_KEK_LENGTH];                    // kek- Key encryption key
  uint8_t kck[SLI_WIFI_KCK_LENGTH];                    // kck -key confirmation key
  uint8_t replay_cntr[SLI_WIFI_REPLAY_COUNTER_LENGTH]; // Counter value
} sli_mgmtif_gtk_rekey_info_t;

/************ SLI_NWP_CMD_VALIDATE_PMKID_SEND_ASSOC_RESP (0x56) ***************/
/**
 * @brief Resume AP association after PMKID validation in management interface
 *
 * @description
 * Consumed by UMAC (Connection Manager - AP FSM) as the management-
 * interface response to @c SLI_NWP_CMD_VALIDATE_PMKID_ASSOC_REQ. On success,
 * UMAC sends the (re)association response and completes peer install; on
 * failure, UMAC removes the station.
 *
 * - Payload:
 *   @ref sli_nwp_sme_assoc_resp_t; Sent from management interface to NWP.
 *
 * @note Outcomes may follow as @c SLI_NWP_IND_STA_ADD on success or
 *       @c SLI_NWP_IND_STA_REMOVE on PMKID failure.
 */
#define SLI_WIFI_PMKID_STATUS_SUCCESS 0 ///< Proceed with (re)association response

typedef struct {
  uint16_t pmkid_status;                        ///< @c SLI_WIFI_PMKID_STATUS_SUCCESS or non-zero failure
  uint8_t assoc_reassoc_type;                   ///< Frame type (Association / Reassociation request)
  uint8_t is_legacy;                            ///< Reserved
  uint8_t mac_addr[SL_WIFI_MAC_ADDRESS_LENGTH]; ///< MAC address of associating STA
  size_t ies_len;                               ///< Length of IEs
  uint8_t ie[0];                                ///< Holds selected IEs from association request
} __attribute__((packed)) sli_nwp_sme_assoc_resp_t;

/******************** SLI_MGMTIF_CMD_SWITCH_BAND (0x69) **********************/
/**
 * @brief Switch operating band when dual-band mode is enabled.
 *
 * @description
 * Consumed by UMAC (Connection Manager - device-specific) to switch the
 * operating band and reprogram band-dependent rates, channel masks, and VAP
 * capabilities. The configured band is applied across active VAPs.
 * Opermodes supported: STA
 *
 * - Request payload:
 *   @ref sl_wifi_band_mode_t; Sent from management interface to NWP
 *   (@c SL_WIFI_BAND_MODE_2_4GHZ or @c SL_WIFI_BAND_MODE_5GHZ).
 *
 * - Response:
 *   - No response is returned.
 */

/******************** SLI_MGMTIF_CMD_ROAM_IND (0x6B) *************************/
/**
 * @brief Update roaming indication state.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to store the
 * roaming indication status used by later join, disconnect, and background-scan
 * handling.
 *
 * - Request payload:
 *   @ref sli_mgmtif_roam_ind_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - No response is returned.
 */
/// Roaming indication values
#define SLI_WIFI_ROAM_DISABLED 0
#define SLI_WIFI_ROAM_ENABLED  1

/// Roam indication status
typedef uint8_t sli_mgmtif_roam_ind_t;

/******************** SLI_MGMTIF_CMD_NULL_AND_BLK_UNBLK (0x6C) ***************/
/**
 * @brief Transmit a QoS NULL frame and optionally tear down the STA peer.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to send a QoS NULL data
 * frame to the connected AP. When the payload selects block, UMAC also clears
 * key/IE state and notifies LMAC of peer disconnect.
 *
 * - Request payload:
 *   @ref sli_mgmtif_blk_unblk_q_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - No response is returned.
 */

/// Block/Unblock queue values
#define SLI_WIFI_QUEUE_UNBLOCK 0 ///< Transmit NULL only; do not tear down peer
#define SLI_WIFI_QUEUE_BLOCK   1 ///< Transmit NULL and perform disconnect cleanup

/// Block/Unblock queues
typedef uint8_t sli_mgmtif_blk_unblk_q_t;

/************* SLI_MGMTIF_CMD_DEAUTH_FROM_ROAM (0x6E) *************************/
/**
 * @brief Deauthenticate from the connected AP during roaming.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to transmit a
 * deauthentication frame and notify LMAC of peer disconnect as part of roaming
 * transition. The request is ignored if rejoin is already in progress.
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - No response is returned for this frame type.
 *
 * @note Allocation failure may be reported as deferred @c SLI_WIFI_CMD_JOIN
 *       status @c SLI_STATUS_MEMORY_FAILED_FROM_MODULE.
 */

/************ SLI_MGMTIF_CMD_UPDATE_FT_IES_FROM_SUPP (0x7D) *******************/
/**
 * @brief This frame is reserved.
 */

/************ SLI_MGMTIF_CMD_LOAD_FT_ACTION_IE (0x7F) *************************/
/**
 * @brief This frame is reserved.
 */
typedef struct {
  uint8_t action_code;
  uint8_t ft_ies_len;
  uint8_t target_mac[6];
} sli_mgmtif_ft_action_req_frm_supp_t;

/************ SLI_MGMTIF_CMD_SEND_TARGET_AP_INFO (0x80) ***********************/
/**
 * @brief This frame is reserved.
 */

/************* SLI_MGMTIF_CMD_SAE_CONFIRM_SUCCESS (0xCA) **********************/
/**
 * @brief Resume STA association after successful WPA3 SAE authentication.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) after the management
 * interface completes the SAE exchange. UMAC installs the peer and continues
 * with association-request processing.
 *
 * - Request payload:
 *   - None
 *
 * - Response:
 *   - No response is returned for this frame type.
 *
 * @note Allocation or association-prep failure may be reported as
 *       @c SLI_WIFI_CMD_JOIN status @c SLI_STATUS_MEMORY_FAILED_FROM_MODULE.
 */

/************* SLI_MGMTIF_CMD_SAE_COMMIT_STATUS (0xCB) ************************/
/**
 * @brief Update the SAE Commit completion state.
 *
 * @description
 * Consumed by UMAC (Connection Manager - STA FSM) to store whether
 * SAE Commit has completed. The flag is used by later STA authentication
 * handling.
 *
 * - Request payload:
 *   @ref sli_mgmtif_sae_commit_t; Sent from management interface to NWP.
 *
 * - Response:
 *   - No response is returned.
 */

/// SAE commit state values
#define SLI_WIFI_SAE_COMMIT_STATE_FALSE 0
#define SLI_WIFI_SAE_COMMIT_STATE_TRUE  1

/// SAE commit state
typedef uint8_t sli_mgmtif_sae_commit_t;

/***************** SLI_WIFI_IND_CARD_READY (0x00) *****************************/
/**
 * @brief First indication after firmware load that the device is ready.
 *
 * @description
 * Async indication from LMAC to UMAC (Connection Manager path, device-init).
 * UMAC stores selected card-ready fields and forwards the indication to the
 * management interface. Management interface then sends
 * @c SLI_WIFI_RSP_CARDREADY to Host SDK to signal that commands may be accepted.
 *
 * - Payload:
 *   @ref wlan_card_ready; Reserved.
 */

/********************** SLI_NWP_IND_ON_AIR_MGMT (0x02) *************************/
/**
 * @brief Raw on-air IEEE 802.11 management frames from LMAC, forwarded to
 * management interface.
 *
 * @description
 * Async indication from LMAC to UMAC (Packet Handler path). UMAC forwards only
 * SAE auth frame to management interface for further processing in supplicant.
 *
 * @note: Other frames (scan, join, AP admission, action handling) are processed
 * internally and may be forwarded to the management interface, retagged
 * as @c SLI_WIFI_IND_ON_AIR_MGMT.
 *
 * Opermodes supported: STA, AP
 *
 * - Host-descriptor:
 *   - @c DW1.B3 - VAP ID
 *
 * - Payload:
 *   - SAE auth IEEE802.11 management frame
 */

/// Authentication frame fixed fields after the 802.11 MAC header (aligned with
/// IEEE 802.11-2024 Authentication frame format)
typedef struct {
  uint16_t auth_algorithm_num; ///< Authentication algorithm number
  uint16_t auth_seq_num;       ///< Authentication transaction sequence number
  uint16_t status_code;        ///< Status code
} sli_nwp_auth_frame_t;

/******************* SLI_NWP_IND_TX_STATUS (0x04) *****************************/
/**
 * @brief TX-completion / confirm indication to UMAC, forwarded to management
 * interface.
 *
 * @description
 * Async indication from LMAC to UMAC (Packet Handler path) to indicate
 * completion status for Tx packets. Currently only EAPOL4_CONFIRM notified to
 * host, other packets internally handled.
 *
 * - Host-descriptor:
 *   - @c DW3.sta_id - confirm subtype:
 *     - @c EAPOL4_CONFIRM - final EAPOL-4 TX confirm; Mid-connection failure
 *        emits async @c SLI_WIFI_CMD_JOIN with @c SLI_STATUS_FOUR_WAY_HANDSHAKE_FAILED.
 *   - @c DW3.token - status for @c EAPOL4_CONFIRM (1 - success, 0 - failure)
 *
 * - Payload:
 *   - RX packet - Reserved
 */

/******************* SLI_NWP_IND_DECRYPT_ERROR (0x07) *************************/
/**
 * @brief This frame is reserved.
 */

/******************* SLI_NWP_IND_FAST_PSP_TIM (0x35) **************************/
/**
 * @brief This frame is reserved.
 */

/******************* SLI_NWP_IND_CURR_OPER_CHAN_UPDATE (0x93) *****************/
/**
 * @brief STA operating-channel update after AP-driven channel switch (CSA).
 *
 * @description
 * Async indication from NWP (Connection Manager - STA FSM) to the management
 * interface after CSA-derived channel switch has been applied. Management
 * interface updates the connected STA channel and does not forward this
 * indication to Host SDK.
 * Opermodes supported: STA
 *
 * - Payload:
 *   - Operating channel (1 byte); Sent from NWP to management interface.
 */

/******************* SLI_NWP_CMD_VALIDATE_PMKID_ASSOC_REQ (0xF3) **************/
/**
 * @brief Request PMKID validation for a WPA3 association request (AP mode).
 *
 * @description
 * Async indication from NWP (Connection Manager - AP FSM) to the management
 * interface when an associating station presents a PMKID. Association-response
 * processing is paused until management interface returns
 * @c SLI_NWP_CMD_VALIDATE_PMKID_SEND_ASSOC_RESP.
 * Opermodes supported: AP
 *
 * - Payload:
 *   - [6 bytes] STA MAC address
 *   - [1 byte] Reserved (@c is_legacy_station)
 *   - [1 byte]  Frame type (Association / Reassociation request)
 *   - [N bytes] Selected IEs from the association request (RSN / RSNXE / WPA /
 *     WPS / P2P); Sent from NWP to management interface.
 *
 * - Response:
 *   - Immediate response sent in @c SLI_NWP_CMD_VALIDATE_PMKID_SEND_ASSOC_RESP
 *     frame.
 *   - Response payload:
 *     @ref sli_nwp_sme_assoc_resp_t; Sent from management interface to NWP.
 *
 * @note Success may follow as @c SLI_NWP_IND_STA_ADD; PMKID failure may follow
 *       as @c SLI_NWP_IND_STA_REMOVE.
 */

/******************* SLI_NWP_IND_STA_ADD (0x00A8) *****************************/
/**
 * @brief AP-mode indication that a station associated successfully.
 *
 * @description
 * Async indication from NWP (Connection Manager - AP FSM) to the management
 * interface after a station reaches the associated / run state.
 * Opermodes supported: AP
 *
 * - Host-descriptor:
 *   - @c DW1.B3 - VAP-id in concurrent mode
 *
 * - Payload:
 *   - [6 bytes] Station MAC address
 *   - [N bytes] Association IE blob; Sent from NWP to management interface.
 */

/******************* SLI_NWP_IND_STA_REMOVE (0x00A9) **************************/
/**
 * @brief AP-mode indication that a station was removed.
 *
 * @description
 * Async indication from NWP (Connection Manager - AP FSM) to the management
 * interface when a station is removed (for example deauth / disassoc, keep-alive
 * failure, or PMKID validation failure).
 * Opermodes supported: AP
 *
 * - Payload:
 *   - [6 bytes] Station MAC address
 *   - [1-2 bytes] Frame type (eg: IEEE 802.11 deauth/disassoc)
 *     Sent from NWP to management interface.
 */

/******************* SLI_WIFI_IND_ON_AIR_MGMT (0x00AA) ************************/
/**
 * @brief Selected on-air management frames forwarded to management interface.
 *
 * @description
 * Async indication from NWP (Packet Handler path) to the management interface /
 * Host SDK. Formed by retagging selected @c SLI_NWP_IND_ON_AIR_MGMT frames
 * after UMAC processing.
 * Opermodes supported: STA, AP
 *
 * - Host-descriptor:
 *   - @c DW2.B0 - channel index
 *
 * - Payload:
 *   - IEEE 802.11 management frame of type:
 *     - Beacon
 *     - Probe response
 *     - Probe request
 *     - WNM BSS Transition Management request action
 *     - Other action frames handled by the default action path
 *   - Sent from NWP to management interface / Host SDK.
 *
 * @note Association / reassociation requests are not forwarded on this path;
 *       they may instead emit @c SLI_NWP_CMD_VALIDATE_PMKID_ASSOC_REQ or
 *       @c SLI_NWP_IND_STA_ADD. Beacon / probe-response frames may be retagged
 *       by management interface to @c SLI_WIFI_IND_SCAN_RESULTS for Host SDK.
 */

/******************************************************************************/
/********************* Global / per-command status codes **********************/
/******************************************************************************/

/************ General WLAN status codes ***************************************/

#define SLI_STATUS_ALREADY_IN_ASSOCIATED_STATE       0x02 ///< Already in associated or connected state.
#define SLI_STATUS_NO_AP_FOUND                       0x03 ///< No access point found.
#define SLI_STATUS_INVALID_PSK                       0x04 ///< Invalid PSK provided. Reserved.
#define SLI_STATUS_INVALID_BAND                      0x05 ///< Invalid band specified.
#define SLI_STATUS_UNASSOCIATED                      0x06 ///< Device is not associated or is in an unassociated state.
#define SLI_STATUS_DEAUTHENTICATION_RECEIVED_FROM_AP 0x08 ///< De-authentication received from access point.
#define SLI_STATUS_ASSOCIATION_FAILED                0x09 ///< Failed to associate with the access point during "Join".
#define SLI_STATUS_INVALID_CHANNEL                   0x0A ///< Invalid channel specified.
#define SLI_STATUS_JOIN_AUTHENTICATION_FAILED \
  0x0E ///< Authentication failure during "Join". Unable to find access point during join which was found during scan. Reserved.
#define SLI_STATUS_INVALID_PMKID                  0x11 ///< Invalid PMKID provided.
#define SLI_STATUS_INVALID_MAC_SUPPLIED           0x13 ///< Non-existent MAC address supplied in "Disassociate" command.
#define SLI_STATUS_EAP_CONFIG_NOT_DONE            0x14 ///< EAP configuration is not completed. Reserved.
#define SLI_STATUS_MEMORY_FAILED_FROM_MODULE      0x15 ///< Memory allocation failed or store configuration checksum failed.
#define SLI_STATUS_COMMAND_GIVEN_IN_INVALID_STATE 0x21 ///< Command issued in an invalid state.
#define SLI_STATUS_WRONG_PARAMETERS               0x26 ///< Incorrect parameters provided for the command.
#define SLI_STATUS_INVALID_FIXED_RATE             0x33 ///< Invalid fixed rate specified.
#define SLI_STATUS_WEP_KEY_NOT_GIVEN              0x40 ///< WEP key not provided. Reserved.
#define SLI_STATUS_MAX_BEACON_MISCOUNT            0x44 ///< Maximum beacon miscount reached: De-authentication due to beacon miss.
#define SLI_STATUS_DEAUTH_REQUEST_FROM_SUPPLICANT 0x45 ///< De-authentication request received from supplicant.
#define SLI_STATUS_DEAUTH_REQUEST_FROM_FROM_AP \
  0x46                                         ///< De-authentication request received from AP after channel switching.
#define SLI_STATUS_MISSED_SYNCHRONIZATION 0x47 ///< Synchronization missed.
#define SLI_STATUS_AUTHENTICATION_TIMEOUT 0x48 ///< Authentication timeout occurred.
#define SLI_STATUS_ASSOCIATION_TIMEOUT    0x49 ///< Association timeout.
#define SLI_STATUS_BG_SCAN_NOT_ALLOWED    0x4A ///< BG scan in given channels is not allowed.
#define SLI_STATUS_SSID_MISMATCH          0x4B ///< Scanned SSID and SSID given in join are not matching. Reserved.
#define SLI_STATUS_CLIENT_MAX_SUPPORTED_EXCEEDED \
  0x4C ///< The number of clients exceeds the maximum number of supported stations.
#define SLI_STATUS_MGMT_PKT_DROPPED                         0x50 ///< Management packet dropped. Reserved.
#define SLI_STATUS_INVALID_RF_CURRENT_MODE                  0x51 ///< The current RF mode is invalid. Reserved.
#define SLI_STATUS_CONNECTED_AP_OR_STATION_CHANNEL_MISMATCH 0x54 ///< Channel mismatch between connected AP and station.
#define SLI_STATUS_WPS_NOT_SUPPORTED                        0x56 ///< WPS is not supported in the current operating mode. Reserved.
#define SLI_STATUS_ACS_EXECUTION_FAIL                       0x59 ///< ACS execution failed.
#define SLI_STATUS_FOUR_WAY_HANDSHAKE_FAILED                0x5A ///< The 4/4 confirmation of the four-way handshake failed.
#define SLI_STATUS_INVALID_CONFIG_RANGE_PROVIDED            0x63 ///< The provided configuration range is invalid.
#define SLI_STATUS_INVALID_CONFIG_TYPE \
  0x64                                   ///< The provided configuration type (for example, RTS threshold) is invalid.
#define SLI_STATUS_JOIN_SAE_TRIGGER 0x68 ///< SAE authentication trigger required for join.
#define SLI_STATUS_EC_GROUP_STATION_UNSUPPORTED_BY_AP \
  0x6A ///< The Access Point does not support the EC-group set by the station. Reserved.
#define SLI_STATUS_DEAUTH_DUE_TO_CHANNEL_CHANGE 0x70 ///< Deauthenticated due to channel change.

/************ SLI_WIFI_CMD_SET_MAC_ADDRESS (0x17) - status codes **************/

#define SLI_STATUS_CONCURRENT_AP_IN_CONNECTED_STATE 0x53 ///< Concurrent AP is in a connected state.

/************ SLI_WIFI_CMD_SET_REGION(0x1D) - status codes ********************/

#define SLI_STATUS_SET_REGION_ERROR 0xC7 ///< Error in set region command.
#define SLI_STATUS_EXTRACTING_COUNTRY_REGION_FROM_BEACON_FAILED \
  0xCD                                                ///< Error in extracting country region from beacon.
#define SLI_STATUS_SELECTED_REGION_NOT_SUPPORTED 0xCE ///< Device does not have selected region support. Reserved.

/************ SLI_WIFI_CMD_TWT_PARAMS (0x2F) - status codes *******************/

#define SLI_STATUS_TWT_COMMAND_SUCCESS         0x00 ///< TWT command completed successfully.
#define SLI_STATUS_TWT_SUPPORT_NOT_ENABLED_ERR 0x70 ///< TWT support not enabled.
#define SLI_STATUS_TWT_SETUP_ERR_SESSION_ACTIVE \
  0x71 ///< TWT config command issued while there is already an active TWT session.
#define SLI_STATUS_TWT_TEARDOWN_ERR_FLOWID_NOT_MATCHED \
  0x72 ///< TWT teardown command issued with a flow ID that does not match the existing session flow ID.
#define SLI_STATUS_TWT_TEARDOWN_ERR_NOACTIVE_SESS \
  0x73                                           ///< TWT teardown command issued while there is no active TWT session.
#define SLI_STATUS_TWT_SESSION_NOT_FEASIBLE 0x74 ///< TWT session is not feasible

/************ SLI_WIFI_CMD_VENDOR_IE (0x38) - status codes ********************/

#define SLI_STATUS_VENDOR_IE_RET_FAIL          -1 ///< Vendor IE operation failed.
#define SLI_STATUS_VENDOR_IE_INVALID_UNIQUE_ID -2 ///< Vendor IE unique ID is out of valid range or not found.
#define SLI_STATUS_VENDOR_IE_INVALID_IE_LENGTH \
  -3 ///< Vendor IE buffer length is invalid or exceeds maximum allowed size.
#define SLI_STATUS_VENDOR_IE_INVALID_PACKET_BITMAP \
  -4 ///< Vendor IE management frame bitmap contains invalid or unsupported frame types.
#define SLI_STATUS_VENDOR_IE_NO_SLOTS_AVAILABLE -5 ///< No firmware memory slots available for adding new vendor IE.
#define SLI_STATUS_VENDOR_IE_INVALID_ACTION     -6 ///< Vendor IE operation is not supported or invalid action specified.

/************ SLI_WIFI_CMD_RESCHEDULE_TWT (0x3F) - status codes ***************/

#define SLI_STATUS_RESCHEDULE_TWT_NOT_SUPPORTED 0x75 ///< AP does not support TWT information frame reception.
#define SLI_STATUS_RESCHEDULE_TWT_ERR_NOACTIVE_SESS \
  0x76                                               ///< No active TWT agreement corresponding to the given flow ID.
#define SLI_STATUS_TWT_RESCHEDULING_IN_PROGRESS 0x77 ///< Suspend or resume TWT action is currently in progress.
#define SLI_STATUS_RESCHEDULE_TWT_PACKET_CREATION_FAILED \
  0x78 ///< TWT information frame packet creation failed in firmware.

/************ SLI_WIFI_CMD_TSF (0x65) - status codes **************************/

#define SLI_STATUS_INVALID_STATION_TSF \
  0x79 ///< Station TSF is invalid (station is not connected or has not received at least one beacon)

/************ SLI_WIFI_CMD_HT_CAPABILITIES (0x6D) - status codes **************/

#define SLI_STATUS_HT_CAPABILITIES_NOT_SUPPORTED 0x4D ///< The specified HT capabilities are not supported.

/************ SLI_WIFI_CMD_SET_REGION_AP (0xBD) - status codes ****************/

#define SLI_STATUS_AP_SET_REGION_COMMAND_ERROR            0xCA ///< Error in AP set region command.
#define SLI_STATUS_AP_SET_REGION_COMMAND_PARAMETERS_ERROR 0xCB ///< Error in AP set region command parameters.
#define SLI_STATUS_REGION_CODE_NOT_SUPPORTED              0xCC ///< Region code not supported.

/************ SLI_WIFI_CMD_11AX_PARAMS (0xFF) - status codes ******************/

#define SLI_STATUS_NO_11AX_SUPPORT_IN_AP 0x6C ///< 802.11ax (Wi-Fi 6) is not supported in Access Point mode.

/************ SLI_WIFI_IND_TWT_ASYNC (0x71) - status codes ********************/

#define SLI_STATUS_TWT_SESSION_SUCCESS                0x00 ///< TWT session setup succeeded.
#define SLI_STATUS_TWT_UNSOL_SESSION_SUCCESS          0x01 ///< Unsolicited TWT session setup succeeded.
#define SLI_STATUS_TWT_SETUP_AP_REJECTED              0x04 ///< TWT setup rejected by the AP.
#define SLI_STATUS_TWT_SETUP_RSP_OUTOF_TOL            0x05 ///< TWT setup response outside tolerance.
#define SLI_STATUS_TWT_SETUP_RSP_NOT_MATCHED          0x06 ///< TWT setup response parameters did not match.
#define SLI_STATUS_TWT_SETUP_UNSUPPORTED_RSP          0x0A ///< Unsupported TWT setup response received.
#define SLI_STATUS_TWT_TEARDOWN_SUCCESS               0x0B ///< TWT teardown succeeded.
#define SLI_STATUS_TWT_AP_TEARDOWN_SUCCESS            0x0C ///< AP-initiated TWT teardown succeeded.
#define SLI_STATUS_TWT_SETUP_FAIL_MAX_RETRIES_REACHED 0x0F ///< TWT setup failed after max retries.
#define SLI_STATUS_TWT_INACTIVE_DUETO_ROAMING         0x10 ///< TWT session inactive due to roaming. Reserved.
#define SLI_STATUS_TWT_INACTIVE_DUETO_DISCONNECT      0x11 ///< TWT session inactive due to disconnect.
#define SLI_STATUS_TWT_INACTIVE_NO_AP_SUPPORT         0x12 ///< TWT session inactive; AP does not support TWT.
#define SLI_STATUS_RESCHEDULE_TWT_SUCCESS             0x13 ///< TWT reschedule completed successfully.
#define SLI_STATUS_TWT_INFO_FRAME_EXCHANGE_FAILED     0x14 ///< TWT Information frame exchange failed.
#define SLI_STATUS_TWT_EVENTS_END                     0x15 ///< End marker for TWT event subtypes. Reserved.

#endif /* SLI_NWP_H */
