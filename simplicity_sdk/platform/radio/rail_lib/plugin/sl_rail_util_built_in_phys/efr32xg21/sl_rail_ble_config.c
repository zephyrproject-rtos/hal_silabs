/***************************************************************************//**
 * @brief RAIL Configuration
 * @details
 *   WARNING: Auto-Generated Radio Config  -  DO NOT EDIT
 *   Radio Configurator Version: 2504.4.3
 *   RAIL Adapter Version: 2.4.33
 *   RAIL Compatibility: 2.x
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
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
#include "em_device.h"
#include "sl_rail_ble_config.h"

static const uint8_t irCalConfig[] = {
  25, 63, 1, 6, 4, 16, 1, 0, 0, 1, 1, 6, 0, 16, 39, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0
};

static const int32_t timingConfig_0[] = {
  50000, 9500, 500, 500
};

static const int32_t timingConfig_1[] = {
  50000, 5500, 1500, 1500
};

static const int32_t timingConfig_2[] = {
  187125, 9500, 500, 500
};

static const int32_t timingConfig_3[] = {
  49125, 9500, 500, 500
};

#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
__ALIGNED(4) static const uint8_t stackInfo_0[2] = { 0x03, 0x01 };
__ALIGNED(4) static const uint8_t stackInfo_1[2] = { 0x03, 0x02 };
__ALIGNED(4) static const uint8_t stackInfo_2[2] = { 0x03, 0x03 };
__ALIGNED(4) static const uint8_t stackInfo_3[2] = { 0x03, 0x04 };
#endif // RADIO_CONFIG_ENABLE_STACK_INFO

static RAIL_ChannelConfigEntryAttr_t channelConfigEntryAttr = {
#if RAIL_SUPPORTS_OFDM_PA
  {
#ifdef RADIO_CONFIG_ENABLE_IRCAL_MULTIPLE_RF_PATHS
    { 0xFFFFFFFFUL, 0xFFFFFFFFUL, },
#else
    { 0xFFFFFFFFUL },
#endif // RADIO_CONFIG_ENABLE_IRCAL_MULTIPLE_RF_PATHS
    { 0xFFFFFFFFUL, 0xFFFFFFFFUL }
  }
#else // RAIL_SUPPORTS_OFDM_PA
#ifdef RADIO_CONFIG_ENABLE_IRCAL_MULTIPLE_RF_PATHS
  { 0xFFFFFFFFUL, 0xFFFFFFFFUL, },
#else
  { 0xFFFFFFFFUL },
#endif // RADIO_CONFIG_ENABLE_IRCAL_MULTIPLE_RF_PATHS
#endif // RAIL_SUPPORTS_OFDM_PA
};

static const uint32_t phyInfo_0[] = {
  20UL,
  0x00400000UL, // 64.0
  (uint32_t) NULL,
  (uint32_t) irCalConfig,
  (uint32_t) timingConfig_0,
  0x00000000UL,
  8793864UL,
  32000000UL,
  1000000UL,
  0x00000101UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  0UL,
  0UL,
  999978UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) 0UL,
};

static const uint32_t phyInfo_1[] = {
  20UL,
  0x00800000UL, // 128.0
  (uint32_t) NULL,
  (uint32_t) irCalConfig,
  (uint32_t) timingConfig_1,
  0x00000000UL,
  8800000UL,
  32000000UL,
  2000000UL,
  0x00000101UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  0UL,
  0UL,
  1999957UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) 0UL,
};

static const uint32_t phyInfo_2[] = {
  20UL,
  0x00800000UL, // 128.0
  (uint32_t) NULL,
  (uint32_t) irCalConfig,
  (uint32_t) timingConfig_2,
  0x00000000UL,
  9840000UL,
  32000000UL,
  1000000UL,
  0x00000801UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  0UL,
  0UL,
  999998UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) 0UL,
};

static const uint32_t phyInfo_3[] = {
  20UL,
  0x00800000UL, // 128.0
  (uint32_t) NULL,
  (uint32_t) irCalConfig,
  (uint32_t) timingConfig_3,
  0x00000000UL,
  9840000UL,
  32000000UL,
  1000000UL,
  0x00000201UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  0UL,
  0UL,
  999998UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) 0UL,
};

const uint32_t ble_viterbi1M_modemConfigBase[] = {
  0x0002400CUL, 0x00018101UL,
  /*    4010 */ 0x00004100UL,
  0x00024020UL, 0x00000000UL,
  /*    4024 */ 0x00000001UL,
  0x00034030UL, 0x00000000UL,
  /*    4034 */ 0x00000000UL,
  /*    4038 */ 0x00000000UL,
  0x00024040UL, 0x00000000UL,
  /*    4044 */ 0x00000000UL,
  0x000140A8UL, 0x00000007UL,
  0x000340B8UL, 0x00004CFFUL,
  /*    40BC */ 0x00004DFFUL,
  /*    40C0 */ 0x00004DFFUL,
  0x0001C008UL, 0x00000000UL,
  0x1001C01CUL, 0x0007F800UL,
  0x3001C01CUL, 0x000802F5UL,
  0x1001C020UL, 0x000000FFUL,
  0x3001C020UL, 0x00001300UL,
  0x0004C024UL, 0x03B380ECUL,
  /*    C028 */ 0x02A87543UL,
  /*    C02C */ 0x00000000UL,
  /*    C030 */ 0x0000022EUL,
  0x0001C050UL, 0x0C304187UL,
  0x0002C058UL, 0x08070654UL,
  /*    C05C */ 0x0002B6D1UL,
  0x0008C064UL, 0x00003004UL,
  /*    C068 */ 0x06102040UL,
  /*    C06C */ 0x1848F2C8UL,
  /*    C070 */ 0x00F6E81FUL,
  /*    C074 */ 0x15724BBDUL,
  /*    C078 */ 0x0518A311UL,
  /*    C07C */ 0x76543210UL,
  /*    C080 */ 0x00000A98UL,
  0x0001C088UL, 0x00000000UL,
  0x01010008UL, 0x00000708UL,
  0x01010018UL, 0x00AAAAAAUL,
  0x01010020UL, 0x00DA6000UL,
  0x0101401CUL, 0x00000010UL,
  0x01034030UL, 0x03000000UL,
  /*    4034 */ 0x00000000UL,
  /*    4038 */ 0x00000000UL,
  0x01024068UL, 0x71764129UL,
  /*    406C */ 0x00000000UL,
  0x010240E0UL, 0x00000033UL,
  /*    40E4 */ 0x00000000UL,
  0x0101410CUL, 0x001255B8UL,
  0x01014124UL, 0x00000000UL,
  0x01054154UL, 0x00000001UL,
  /*    4158 */ 0x00000000UL,
  /*    415C */ 0x00000000UL,
  /*    4160 */ 0x00000000UL,
  /*    4164 */ 0x00000000UL,
  0x01024238UL, 0x00000000UL,
  /*    423C */ 0x00000000UL,
  0x01014244UL, 0x00000000UL,
  0x01018010UL, 0x00000003UL,
  0x01028038UL, 0x00104911UL,
  /*    803C */ 0x00000001UL,
  0x0101809CUL, 0x000240EBUL,
  0x010280B0UL, 0x02000300UL,
  /*    80B4 */ 0x01000037UL,
  0x02020088UL, 0x04000C00UL,
  /*    008C */ 0x0000004CUL,
  0x02010094UL, 0x00000400UL,
  0x020100D4UL, 0x08960290UL,
  0x020100E4UL, 0x0442093DUL,
  0x02010118UL, 0x02510060UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_viterbi1M_modemConfig[] = {
  0x03011FFCUL, (uint32_t) &phyInfo_0,
  0x0001403CUL, 0x00000000UL,
  0x00014048UL, 0x000007A0UL,
  0x00014050UL, 0x00000000UL,
  0x0002405CUL, 0x00000000UL,
  /*    4060 */ 0x00000000UL,
  0x000140B4UL, 0x00004CFFUL,
  0x0001C054UL, 0xE6092D0EUL,
  0x01044020UL, 0x86000000UL,
  /*    4024 */ 0x0001C01FUL,
  /*    4028 */ 0x00006000UL,
  /*    402C */ 0x00008000UL,
  0x01044058UL, 0x00050018UL,
  /*    405C */ 0x00000880UL,
  /*    4060 */ 0x00000009UL,
  /*    4064 */ 0x00040091UL,
  0x010C4080UL, 0x000C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x00220013UL,
  /*    408C */ 0x00000000UL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0D050200UL,
  /*    4098 */ 0x53422F1CUL,
  /*    409C */ 0x60686962UL,
  /*    40A0 */ 0x1F2E4053UL,
  /*    40A4 */ 0x84208291UL,
  /*    40A8 */ 0x22334567UL,
  /*    40AC */ 0x00024912UL,
  0x010740ECUL, 0xAC2C3890UL,
  /*    40F0 */ 0x00000000UL,
  /*    40F4 */ 0x0A08105AUL,
  /*    40F8 */ 0x4ACA07D0UL,
  /*    40FC */ 0x00481051UL,
  /*    4100 */ 0x801E54F9UL,
  /*    4104 */ 0x4A413747UL,
  0x01024110UL, 0x054A1930UL,
  /*    4114 */ 0x0040BB89UL,
  0x01014128UL, 0x0000FFFFUL,
  0x01094130UL, 0x430450F1UL,
  /*    4134 */ 0x0000010CUL,
  /*    4138 */ 0x00FA53E8UL,
  /*    413C */ 0x00080000UL,
  /*    4140 */ 0x221C1610UL,
  /*    4144 */ 0x3A342E28UL,
  /*    4148 */ 0x43214640UL,
  /*    414C */ 0x0BA98765UL,
  /*    4150 */ 0xB4C00000UL,
  0x01034168UL, 0x0A08105AUL,
  /*    416C */ 0x044107D0UL,
  /*    4170 */ 0x000003C1UL,
  0x01024230UL, 0x0FA39389UL,
  /*    4234 */ 0x0E5DC25EUL,
  0x010280A0UL, 0x00037870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F0UL,
  0x310180A8UL, 0x01CB4205UL,
  0x110180ACUL, 0x000001F0UL,
  0x310180ACUL, 0x00FD3E05UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_viterbi2M_0_34_modemConfig[] = {
  0x03011FFCUL, (uint32_t) &phyInfo_1,
  0x0001403CUL, 0x00000000UL,
  0x00014048UL, 0x000007A0UL,
  0x00014050UL, 0x00000000UL,
  0x0002405CUL, 0x00000000UL,
  /*    4060 */ 0x00000000UL,
  0x000140B4UL, 0x00004CFFUL,
  0x0001C054UL, 0xE6092D0AUL,
  0x01044020UL, 0x06000000UL,
  /*    4024 */ 0x0000C01FUL,
  /*    4028 */ 0x00006000UL,
  /*    402C */ 0x0032D000UL,
  0x01044058UL, 0x00FF0264UL,
  /*    405C */ 0x00000880UL,
  /*    4060 */ 0x00000001UL,
  /*    4064 */ 0x00080011UL,
  0x010C4080UL, 0x00000408UL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x002203D9UL,
  /*    408C */ 0x00000000UL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x11070201UL,
  /*    4098 */ 0x5A4B3721UL,
  /*    409C */ 0x54626967UL,
  /*    40A0 */ 0x05152940UL,
  /*    40A4 */ 0x20800000UL,
  /*    40A8 */ 0x33334443UL,
  /*    40AC */ 0x24A49223UL,
  0x010740ECUL, 0xAC2C3890UL,
  /*    40F0 */ 0x00000000UL,
  /*    40F4 */ 0x07830464UL,
  /*    40F8 */ 0x3AC81388UL,
  /*    40FC */ 0x000A209DUL,
  /*    4100 */ 0x80206101UL,
  /*    4104 */ 0x4A413747UL,
  0x01024110UL, 0x024A142AUL,
  /*    4114 */ 0x0AC0BB89UL,
  0x01014128UL, 0x0000FFFFUL,
  0x01094130UL, 0x0C660664UL,
  /*    4134 */ 0x0000010CUL,
  /*    4138 */ 0x00FA53E8UL,
  /*    413C */ 0x00080000UL,
  /*    4140 */ 0x241E1812UL,
  /*    4144 */ 0x3C36302AUL,
  /*    4148 */ 0x43214842UL,
  /*    414C */ 0x0BA98765UL,
  /*    4150 */ 0xC4E00000UL,
  0x01034168UL, 0x07830464UL,
  /*    416C */ 0x00821388UL,
  /*    4170 */ 0x000008C1UL,
  0x01024230UL, 0x106B9645UL,
  /*    4234 */ 0x0E67225CUL,
  0x010280A0UL, 0x00037870UL,
  /*    80A4 */ 0x0000C0D5UL,
  0x110180A8UL, 0x000001F0UL,
  0x310180A8UL, 0x01CB4205UL,
  0x110180ACUL, 0x000001F0UL,
  0x310180ACUL, 0x008D2205UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_LR_DSA_125kb_modemConfig[] = {
  0x03011FFCUL, (uint32_t) &phyInfo_2,
  0x0001403CUL, 0x00000010UL,
  0x00014048UL, 0x00000720UL,
  0x00014050UL, 0x00000400UL,
  0x0002405CUL, 0x00000F0DUL,
  /*    4060 */ 0x00000101UL,
  0x000140B4UL, 0x0001C003UL,
  0x0001C054UL, 0xE6092D0EUL,
  0x01044020UL, 0x46000030UL,
  /*    4024 */ 0x0001C81FUL,
  /*    4028 */ 0x10002000UL,
  /*    402C */ 0x00008000UL,
  0x01044058UL, 0x00050018UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000009UL,
  /*    4064 */ 0x000A0092UL,
  0x010C4080UL, 0x022C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x00120012UL,
  /*    408C */ 0x1B8C805BUL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0E050200UL,
  /*    4098 */ 0x53432F1CUL,
  /*    409C */ 0x61686962UL,
  /*    40A0 */ 0x04324355UL,
  /*    40A4 */ 0xC6B8E416UL,
  /*    40A8 */ 0x3345678AUL,
  /*    40AC */ 0x04924A22UL,
  0x010740ECUL, 0x8CB1B080UL,
  /*    40F0 */ 0x00000000UL,
  /*    40F4 */ 0x07830464UL,
  /*    40F8 */ 0x3AC81388UL,
  /*    40FC */ 0x000A209CUL,
  /*    4100 */ 0x80206101UL,
  /*    4104 */ 0x123556B7UL,
  0x01024110UL, 0x29041BA0UL,
  /*    4114 */ 0x00408808UL,
  0x01014128UL, 0x00000000UL,
  0x01094130UL, 0x0C660664UL,
  /*    4134 */ 0x0000010CUL,
  /*    4138 */ 0x3BE8D44CUL,
  /*    413C */ 0x306F1904UL,
  /*    4140 */ 0x1A140E08UL,
  /*    4144 */ 0x322C2620UL,
  /*    4148 */ 0x32103E38UL,
  /*    414C */ 0x0A987654UL,
  /*    4150 */ 0x00005F1DUL,
  0x01034168UL, 0x07830464UL,
  /*    416C */ 0x00821388UL,
  /*    4170 */ 0x00000000UL,
  0x01024230UL, 0x00000000UL,
  /*    4234 */ 0x0E000800UL,
  0x010280A0UL, 0x00033870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F0UL,
  0x310180A8UL, 0x01FD5A05UL,
  0x110180ACUL, 0x000001F0UL,
  0x310180ACUL, 0x00FD3E05UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_LR_DSA_500kb_modemConfig[] = {
  0x03011FFCUL, (uint32_t) &phyInfo_3,
  0x0001403CUL, 0x00000010UL,
  0x00014048UL, 0x00001720UL,
  0x00014050UL, 0x00000401UL,
  0x0002405CUL, 0x00000F0DUL,
  /*    4060 */ 0x00000101UL,
  0x000140B4UL, 0x0001C003UL,
  0x0001C054UL, 0xE6092D0EUL,
  0x01044020UL, 0x46000030UL,
  /*    4024 */ 0x0001C81FUL,
  /*    4028 */ 0x10002000UL,
  /*    402C */ 0x00008000UL,
  0x01044058UL, 0x00050018UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000009UL,
  /*    4064 */ 0x000A0092UL,
  0x010C4080UL, 0x022C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x00120012UL,
  /*    408C */ 0x1B8C805BUL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0E050200UL,
  /*    4098 */ 0x53432F1CUL,
  /*    409C */ 0x61686962UL,
  /*    40A0 */ 0x04324355UL,
  /*    40A4 */ 0xC6B8E416UL,
  /*    40A8 */ 0x3345678AUL,
  /*    40AC */ 0x04924A22UL,
  0x010740ECUL, 0x8CB1B080UL,
  /*    40F0 */ 0x00000000UL,
  /*    40F4 */ 0x07830464UL,
  /*    40F8 */ 0x3AC81388UL,
  /*    40FC */ 0x000A209CUL,
  /*    4100 */ 0x80206101UL,
  /*    4104 */ 0x123556B7UL,
  0x01024110UL, 0x29041BA0UL,
  /*    4114 */ 0x00408808UL,
  0x01014128UL, 0x00000000UL,
  0x01094130UL, 0x0C660664UL,
  /*    4134 */ 0x0000010CUL,
  /*    4138 */ 0x3BE8D44CUL,
  /*    413C */ 0x306F1904UL,
  /*    4140 */ 0x1C16100AUL,
  /*    4144 */ 0x342E2822UL,
  /*    4148 */ 0x3210403AUL,
  /*    414C */ 0x0A987654UL,
  /*    4150 */ 0xA4805F1DUL,
  0x01034168UL, 0x07830464UL,
  /*    416C */ 0x00821388UL,
  /*    4170 */ 0x00000000UL,
  0x01024230UL, 0x00000000UL,
  /*    4234 */ 0x0E000800UL,
  0x010280A0UL, 0x00033870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F0UL,
  0x310180A8UL, 0x01FD5A05UL,
  0x110180ACUL, 0x000001F0UL,
  0x310180ACUL, 0x00FD3E05UL,
  0xFFFFFFFFUL,
};

const RAIL_ChannelConfigEntry_t ble_viterbi1M_channels[] = {
  {
    .phyConfigDeltaAdd = ble_viterbi1M_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 39,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_0,
#endif
    .alternatePhy = NULL,
  },
};

const RAIL_ChannelConfigEntry_t ble_viterbi2M_channels[] = {
  {
    .phyConfigDeltaAdd = ble_viterbi2M_0_34_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 34,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_1,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = ble_viterbi2M_0_34_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 35,
    .channelNumberEnd = 35,
    .maxPower = 182,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_1,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = ble_viterbi2M_0_34_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 36,
    .channelNumberEnd = 36,
    .maxPower = 157,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_1,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = ble_viterbi2M_0_34_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 37,
    .channelNumberEnd = 37,
    .maxPower = 125,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_1,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = ble_viterbi2M_0_34_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 38,
    .channelNumberEnd = 38,
    .maxPower = 83,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_1,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = ble_viterbi2M_0_34_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 39,
    .channelNumberEnd = 39,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_1,
#endif
    .alternatePhy = NULL,
  },
};

const RAIL_ChannelConfigEntry_t ble_LR_DSA_125kb_channels[] = {
  {
    .phyConfigDeltaAdd = ble_LR_DSA_125kb_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 39,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_2,
#endif
    .alternatePhy = NULL,
  },
};

const RAIL_ChannelConfigEntry_t ble_LR_DSA_500kb_channels[] = {
  {
    .phyConfigDeltaAdd = ble_LR_DSA_500kb_modemConfig,
    .baseFrequency = 2402000000,
    .channelSpacing = 2000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 39,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_3,
#endif
    .alternatePhy = NULL,
  },
};

const RAIL_ChannelConfig_t ble_viterbi1M_channelConfig = {
  .phyConfigBase = ble_viterbi1M_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = ble_viterbi1M_channels,
  .length = 1U,
  .signature = 0UL,
  .xtalFrequencyHz = 38400000UL,
};

const RAIL_ChannelConfig_t ble_viterbi2M_channelConfig = {
  .phyConfigBase = ble_viterbi1M_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = ble_viterbi2M_channels,
  .length = 6U,
  .signature = 0UL,
  .xtalFrequencyHz = 38400000UL,
};

const RAIL_ChannelConfig_t ble_LR_DSA_125kb_channelConfig = {
  .phyConfigBase = ble_viterbi1M_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = ble_LR_DSA_125kb_channels,
  .length = 1U,
  .signature = 0UL,
  .xtalFrequencyHz = 38400000UL,
};

const RAIL_ChannelConfig_t ble_LR_DSA_500kb_channelConfig = {
  .phyConfigBase = ble_viterbi1M_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = ble_LR_DSA_500kb_channels,
  .length = 1U,
  .signature = 0UL,
  .xtalFrequencyHz = 38400000UL,
};
