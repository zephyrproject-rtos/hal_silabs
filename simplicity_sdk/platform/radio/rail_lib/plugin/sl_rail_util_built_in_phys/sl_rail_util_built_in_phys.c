/***************************************************************************//**
 * @file sl_rail_util_built_in_phys.c
 * @brief Brings in built-in (Standards based) PHYs. Also applies PHY overrides
 *  based on a device's HFXO frequency.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#include "sl_rail_features.h"
#if !defined(_SILICON_LABS_32B_SERIES_3)
#include "em_common.h"
#endif

#if ((_SILICON_LABS_32B_SERIES_2_CONFIG == 4) \
  || (_SILICON_LABS_32B_SERIES_2_CONFIG == 6) \
  || (_SILICON_LABS_32B_SERIES_3_CONFIG == 301))
#define SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS 1
#else
#define SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS 0
#endif

#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS
#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif // SL_COMPONENT_CATALOG_PRESENT

#if defined(SL_CATALOG_CLOCK_MANAGER_PRESENT)
#include "sl_clock_manager_oscillator_config.h"
#define SL_RAIL_PHY_INIT_HFXO_FREQ   SL_CLOCK_MANAGER_HFXO_FREQ
#else // !defined(SL_CATALOG_CLOCK_MANAGER_PRESENT)
#include "sl_device_init_hfxo_config.h"
#define SL_RAIL_PHY_INIT_HFXO_FREQ   SL_DEVICE_INIT_HFXO_FREQ
#endif // defined(SL_CATALOG_CLOCK_MANAGER_PRESENT)

#include "sl_rail_ble_config_38M4Hz.h"
#include "sl_rail_ble_config_39MHz.h"
#include "sl_rail_ble_config_40MHz.h"

#include "sl_rail_ieee802154_config_38M4Hz.h"
#include "sl_rail_ieee802154_config_39MHz.h"
#include "sl_rail_ieee802154_config_40MHz.h"

#if SL_RAIL_SUPPORTS_RF_SENSE_OOK_PHY
#include "sl_rail_rfsense_ook_config_38M4Hz.h"
#include "sl_rail_rfsense_ook_config_39MHz.h"
#include "sl_rail_rfsense_ook_config_40MHz.h"
#endif

#else // !SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS

#if SL_RAIL_SUPPORTS_PROTOCOL_BLE
#include "sl_rail_ble_config.h"
#endif // SL_RAIL_SUPPORTS_PROTOCOL_BLE

#if SL_RAIL_SUPPORTS_RF_SENSE_OOK_PHY
#include "sl_rail_rfsense_ook_config.h"
#endif // SL_RAIL_SUPPORTS_RF_SENSE_OOK_PHY

#if SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154
#include "sl_rail_ieee802154_config.h"
#endif // SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154

#if SL_RAIL_SUPPORTS_PROTOCOL_ZWAVE
#include "sl_rail_zwave_config.h"
#endif // SL_RAIL_SUPPORTS_PROTOCOL_ZWAVE

#if SL_RAIL_SUPPORTS_PROTOCOL_SIDEWALK
#include "sl_rail_sidewalk_config.h"
#endif // SL_RAIL_SUPPORTS_PROTOCOL_SIDEWALK
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS

#if SL_RAIL_BLE_SUPPORTS_1_MBPS
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy1MbpsViterbi =
  &sl_rail_ble_phy_1Mbps_viterbi_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy1MbpsViterbi =
  &sl_rail_ble_phy_1Mbps_viterbi_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy1MbpsViterbi =
  &sl_rail_ble_phy_1Mbps_viterbi_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy1MbpsViterbi =
  &ble_viterbi1M_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_BLE_SUPPORTS_1_MBPS

#if SL_RAIL_BLE_SUPPORTS_2_MBPS
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsViterbi =
  &sl_rail_ble_phy_2Mbps_viterbi_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsViterbi =
  &sl_rail_ble_phy_2Mbps_viterbi_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsViterbi =
  &sl_rail_ble_phy_2Mbps_viterbi_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsViterbi =
  &ble_viterbi2M_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_BLE_SUPPORTS_2_MBPS

#if SL_RAIL_BLE_SUPPORTS_2_MBPS && SL_RAIL_BLE_SUPPORTS_AOX && (_SILICON_LABS_32B_SERIES_3_CONFIG != 301)
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &sl_rail_ble_phy_2Mbps_aox_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &sl_rail_ble_phy_2Mbps_aox_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &sl_rail_ble_phy_2Mbps_aox_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &ble_viterbi2M_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_BLE_SUPPORTS_2_MBPS && SL_RAIL_BLE_SUPPORTS_AOX && (_SILICON_LABS_32B_SERIES_3_CONFIG != 301)

// Use Standard 2mbps PHY for AOX on SIXG301 devices
#if SL_RAIL_BLE_SUPPORTS_2_MBPS && SL_RAIL_BLE_SUPPORTS_AOX && (_SILICON_LABS_32B_SERIES_3_CONFIG == 301)
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &sl_rail_ble_phy_2Mbps_viterbi_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &sl_rail_ble_phy_2Mbps_viterbi_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &sl_rail_ble_phy_2Mbps_viterbi_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsAox =
  &ble_viterbi2M_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif

#if SL_RAIL_BLE_SUPPORTS_CS && SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy1MbpsViterbiCs =
  &sl_rail_ble_phy_1Mbps_viterbi_cs_40MHz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy2MbpsViterbiCs =
  &sl_rail_ble_phy_2Mbps_viterbi_cs_40MHz_channelConfig;
#endif // SL_RAIL_BLE_SUPPORTS_CS && SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000

#if SL_RAIL_BLE_SUPPORTS_CODED_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy125kbps =
  &sl_rail_ble_phy_125kbps_38M4Hz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy500kbps =
  &sl_rail_ble_phy_500kbps_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy125kbps =
  &sl_rail_ble_phy_125kbps_39MHz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy500kbps =
  &sl_rail_ble_phy_500kbps_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy125kbps =
  &sl_rail_ble_phy_125kbps_40MHz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy500kbps =
  &sl_rail_ble_phy_500kbps_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy125kbps =
  &ble_LR_DSA_125kb_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_BLE_Phy500kbps =
  &ble_LR_DSA_500kb_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_BLE_SUPPORTS_CODED_PHY

#if SL_RAIL_BLE_SUPPORTS_SIMULSCAN_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_BLE_PhySimulscan =
  &sl_rail_ble_phy_simulscan_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_BLE_PhySimulscan =
  &sl_rail_ble_phy_simulscan_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_PhySimulscan =
  &sl_rail_ble_phy_simulscan_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_BLE_PhySimulscan =
  &ble_LR_DSA_1Mb_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_BLE_SUPPORTS_SIMULSCAN_PHY

#if SL_RAIL_BLE_SUPPORTS_QUUPPA
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_BLE_PhyQuuppa =
  &sl_rail_ble_phy_quuppa_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_BLE_PhyQuuppa =
  &sl_rail_ble_phy_quuppa_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_BLE_PhyQuuppa =
  &sl_rail_ble_phy_quuppa_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_BLE_PhyQuuppa =
  &quuppa_viterbi1M_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_BLE_SUPPORTS_QUUPPA

#if SL_RAIL_IEEE802154_SUPPORTS_2P4_GHZ_BAND && SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154 && (_SILICON_LABS_32B_SERIES_3_CONFIG != 301)
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &sl_rail_ieee802154_phy_2G4Hz_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &sl_rail_ieee802154_phy_2G4Hz_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &sl_rail_ieee802154_phy_2G4Hz_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &ieee802154_2p4_coherent_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_2P4_GHZ_BAND && SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154 && (_SILICON_LABS_32B_SERIES_3_CONFIG != 301)

#if SL_RAIL_IEEE802154_SUPPORTS_2P4_GHZ_BAND && SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154 && (_SILICON_LABS_32B_SERIES_3_CONFIG == 301)
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &sl_rail_ieee802154_phy_2G4Hz_coherent_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &sl_rail_ieee802154_phy_2G4Hz_coherent_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &sl_rail_ieee802154_phy_2G4Hz_coherent_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz =
  &ieee802154_2p4_coherent_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_2P4_GHZ_BAND && SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154 && (_SILICON_LABS_32B_SERIES_3_CONFIG == 301)

#if SL_RAIL_IEEE802154_SUPPORTS_2_MBPS_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz1MbpsFec =
  &sl_rail_ieee802154_phy_2G4Hz_1Mbps_fec_38M4Hz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz2Mbps =
  &sl_rail_ieee802154_phy_2G4Hz_2Mbps_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz1MbpsFec =
  &sl_rail_ieee802154_phy_2G4Hz_1Mbps_fec_39MHz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz2Mbps =
  &sl_rail_ieee802154_phy_2G4Hz_2Mbps_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz1MbpsFec =
  &sl_rail_ieee802154_phy_2G4Hz_1Mbps_fec_40MHz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz2Mbps =
  &sl_rail_ieee802154_phy_2G4Hz_2Mbps_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz1MbpsFec =
  &ieee802154_2p4_1mbps_fec_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHz2Mbps =
  &ieee802154_2p4_2mbps_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_2_MBPS_PHY

#if SL_RAIL_IEEE802154_SUPPORTS_FCS_2_MBPS_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs1MbpsFec =
  &sl_rail_ieee802154_phy_2G4Hz_fcs_1Mbps_fec_38M4Hz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs2Mbps =
  &sl_rail_ieee802154_phy_2G4Hz_fcs_2Mbps_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs1MbpsFec =
  &sl_rail_ieee802154_phy_2G4Hz_fcs_1Mbps_fec_39MHz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs2Mbps =
  &sl_rail_ieee802154_phy_2G4Hz_fcs_2Mbps_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs1MbpsFec =
  &sl_rail_ieee802154_phy_2G4Hz_fcs_1Mbps_fec_40MHz_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs2Mbps =
  &sl_rail_ieee802154_phy_2G4Hz_fcs_2Mbps_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs1MbpsFec =
  &ieee802154_2p4_fcs_1mbps_fec_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFcs2Mbps =
  &ieee802154_2p4_fcs_2mbps_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_FCS_2_MBPS_PHY

#if SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY && SL_RAIL_SUPPORTS_2P4_GHZ_BAND \
  && SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154                               \
  && (_SILICON_LABS_32B_SERIES_2_CONFIG != 8)
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDiv =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDiv =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDiv =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDiv =
  &ieee802154_2p4_antdiv_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY && SL_RAIL_SUPPORTS_2P4_GHZ_BAND && SL_RAIL_SUPPORTS_PROTOCOL_IEEE802154

#if SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoex =
  &sl_rail_ieee802154_phy_2G4Hz_coex_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoex =
  &sl_rail_ieee802154_phy_2G4Hz_coex_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoex =
  &sl_rail_ieee802154_phy_2G4Hz_coex_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoex =
  &ieee802154_2p4_coex_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY

#if SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY && SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoex =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_coex_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoex =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_coex_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoex =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_coex_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoex =
  &ieee802154_2p4_antdiv_coex_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY && SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY

#if SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFem =
  &sl_rail_ieee802154_phy_2G4Hz_fem_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFem =
  &sl_rail_ieee802154_phy_2G4Hz_fem_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFem =
  &sl_rail_ieee802154_phy_2G4Hz_fem_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzFem =
  &ieee802154_2p4_coherent_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY

#if SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY && SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivFem =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_fem_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivFem =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_fem_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivFem =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_fem_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivFem =
  &ieee802154_2p4_antdiv_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY && SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY

#if SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY && SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoexFem =
  &sl_rail_ieee802154_phy_2G4Hz_coex_fem_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoexFem =
  &sl_rail_ieee802154_phy_2G4Hz_coex_fem_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoexFem =
  &sl_rail_ieee802154_phy_2G4Hz_coex_fem_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzCoexFem =
  &ieee802154_2p4_coex_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY && SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY

#if SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY && SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY \
  && SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoexFem =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_coex_fem_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoexFem =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_coex_fem_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoexFem =
  &sl_rail_ieee802154_phy_2G4Hz_antdiv_coex_fem_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzAntDivCoexFem =
  &ieee802154_2p4_antdiv_coex_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_FEM_PHY && SL_RAIL_IEEE802154_SUPPORTS_COEX_PHY && SL_RAIL_SUPPORTS_ANTENNA_DIVERSITY

#if SL_RAIL_IEEE802154_SUPPORTS_G_SUBSET_GB868
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_PhyGB863MHz =
  &ieee802154_gb868_863_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_PhyGB915MHz =
  &ieee802154_gb868_915_channelConfig;
#endif // SL_RAIL_IEEE802154_SUPPORTS_G_SUBSET_GB868

#if SL_RAIL_IEEE802154_SUPPORTS_RX_CHANNEL_SWITCHING && !defined(_SILICON_LABS_32B_SERIES_3)
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzRxChSwitching =
  &sl_rail_ieee802154_phy_2G4Hz_fast_switch_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzRxChSwitching =
  &sl_rail_ieee802154_phy_2G4Hz_fast_switch_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzRxChSwitching =
  &sl_rail_ieee802154_phy_2G4Hz_fast_switch_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_IEEE802154_Phy2p4GHzRxChSwitching =
  &ieee802154_2p4_rx_channel_switching_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_IEEE802154_SUPPORTS_RX_CHANNEL_SWITCHING && !defined(_SILICON_LABS_32B_SERIES_3)

#if SL_RAIL_SUPPORTS_RF_SENSE_OOK_PHY
#if SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
const RAIL_ChannelConfig_t *const RAIL_RFSENSE_OOK_Phy1kbps =
  &sl_rfsense_ook_1kbps_38M4Hz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 39000000
const RAIL_ChannelConfig_t *const RAIL_RFSENSE_OOK_Phy1kbps =
  &sl_rfsense_ook_1kbps_39MHz_channelConfig;
#elif SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 40000000
const RAIL_ChannelConfig_t *const RAIL_RFSENSE_OOK_Phy1kbps =
  &sl_rfsense_ook_1kbps_40MHz_channelConfig;
#else
const RAIL_ChannelConfig_t *const RAIL_RFSENSE_OOK_Phy1kbps =
  &rfsense_ook_1kbps_channelConfig;
#endif // SL_RAIL_SUPPORTS_MULTIPLE_XTAL_PHYS && SL_RAIL_PHY_INIT_HFXO_FREQ == 38400000
#endif // SL_RAIL_SUPPORTS_RF_SENSE_OOK_PHY

#if SL_RAIL_SUPPORTS_PROTOCOL_SIDEWALK
const RAIL_ChannelConfig_t *const RAIL_Sidewalk_Phy2GFSK50kbps =
  &sidewalk_2gfsk_50kbps_channelConfig;
#endif // SL_RAIL_SUPPORTS_PROTOCOL_SIDEWALK

#if SL_RAIL_SUPPORTS_PROTOCOL_ZWAVE
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy9p6kbps =
  &zwave_9p6kb_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy9p6kbpsConcurrent =
  &zwave_9p6kb_conc_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy40kbps =
  &zwave_40kb_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy40kbpsBeam =
  &zwave_40kb_beam_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy100kbps =
  &zwave_100kb_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy100kbpsLowside =
  &zwave_100kb_lowside_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy100kbpsBeam =
  &zwave_100kb_beam_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_Phy100kbpsLowsideBeam =
  &zwave_100kb_beam_lowside_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_PhyLongRange =
  &zwave_lr_channelConfig;
const RAIL_ChannelConfig_t *const RAIL_ZWAVE_PhyLongRangeBeam =
  &zwave_lr_beam_channelConfig;
#endif // SL_RAIL_SUPPORTS_PROTOCOL_ZWAVE
