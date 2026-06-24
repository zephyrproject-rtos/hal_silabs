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
  50000, 9000, 500, 500
};

static const int32_t timingConfig_1[] = {
  50000, 5200, 250, 250
};

static const int32_t timingConfig_2[] = {
  187125, 10000, 600, 600
};

static const int32_t timingConfig_3[] = {
  49125, 10000, 450, 450
};

static const int32_t timingConfig_4[] = {
  50000, 11750, 2000, 2000
};

__ALIGNED(4) static const uint8_t hfxoRetimingConfigEntries[] = {
  2, 0, 0, 0, 0x00, 0xf0, 0x49, 0x02, 6, 20, 0, 0, 0x00, 0xe0, 0x93, 0x04, 5, 56, 0, 0, 0xa0, 0x08, 0, 0, 0, 0, 0x58, 0x09, 1, 4, 7, 6, 0x10, 0x0a, 1, 4, 7, 7, 0xc8, 0x0a, 0, 4, 8, 7, 0x80, 0x0b, 0, 4, 8, 8, 0x38, 0x0c, 0, 4, 9, 8, 0x61, 0x08, 0, 0, 0, 0, 0x68, 0x08, 0, 0, 0, 0, 0xc7, 0x09, 1, 4, 4, 3, 0x2c, 0x0b, 1, 4, 4, 4, 0x92, 0x0c, 1, 4, 5, 4
};

#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
__ALIGNED(4) static const uint8_t stackInfo_0[2] = { 0x03, 0x01 };
__ALIGNED(4) static const uint8_t stackInfo_1[2] = { 0x03, 0x02 };
__ALIGNED(4) static const uint8_t stackInfo_2[2] = { 0x03, 0x03 };
__ALIGNED(4) static const uint8_t stackInfo_3[2] = { 0x03, 0x04 };
__ALIGNED(4) static const uint8_t stackInfo_4[2] = { 0x03, 0x05 };
__ALIGNED(4) static const uint8_t stackInfo_5[2] = { 0x03, 0x09 };
#endif // RADIO_CONFIG_ENABLE_STACK_INFO

static RAIL_ChannelConfigEntryAttr_t channelConfigEntryAttr = {
#if RAIL_SUPPORTS_OFDM_PA
  {
    { 0xFFFFFFFFUL },
    { 0xFFFFFFFFUL, 0xFFFFFFFFUL }
  }
#else // RAIL_SUPPORTS_OFDM_PA
  { 0xFFFFFFFFUL },
#endif // RAIL_SUPPORTS_OFDM_PA
};

static const uint32_t phyInfo_0[] = {
  20UL,
  0x00800000UL, // 128.0
  (uint32_t) NULL,
  (uint32_t) irCalConfig,
  (uint32_t) timingConfig_0,
  0x00000000UL,
  4396932UL,
  16000000UL,
  1000000UL,
  0x00F40101UL,
  0x03502555UL,
  (uint32_t) NULL,
  (uint32_t) hfxoRetimingConfigEntries,
  (uint32_t) NULL,
  0UL,
  0UL,
  999992UL,
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
  0x00F40101UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) hfxoRetimingConfigEntries,
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
  0x00F40801UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) hfxoRetimingConfigEntries,
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
  0x00F40201UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) hfxoRetimingConfigEntries,
  (uint32_t) NULL,
  0UL,
  0UL,
  999998UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) 0UL,
};

static const uint32_t phyInfo_4[] = {
  20UL,
  0x00800000UL, // 128.0
  (uint32_t) NULL,
  (uint32_t) irCalConfig,
  (uint32_t) timingConfig_4,
  0x00000000UL,
  9840000UL,
  32000000UL,
  1000000UL,
  0x00F40801UL,
  0x02504911UL,
  (uint32_t) NULL,
  (uint32_t) hfxoRetimingConfigEntries,
  (uint32_t) NULL,
  0UL,
  0UL,
  999998UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) 0UL,
};

static const uint32_t phyInfo_5[] = {
  20UL,
  0x00800000UL, // 128.0
  (uint32_t) NULL,
  (uint32_t) irCalConfig,
  (uint32_t) timingConfig_0,
  0x00000000UL,
  4396932UL,
  16000000UL,
  1000000UL,
  0x00F40101UL,
  0x03502555UL,
  (uint32_t) NULL,
  (uint32_t) hfxoRetimingConfigEntries,
  (uint32_t) NULL,
  0UL,
  0UL,
  999986UL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) NULL,
  (uint32_t) 0UL,
};

const uint32_t ble_viterbi1M_modemConfigBase[] = {
  0x0001400CUL, 0x00018101UL,
  0x00024020UL, 0x00000000UL,
  /*    4024 */ 0x00000001UL,
  0x00034030UL, 0x00000000UL,
  /*    4034 */ 0x00000000UL,
  /*    4038 */ 0x00000000UL,
  0x00024040UL, 0x00000000UL,
  /*    4044 */ 0x00004000UL,
  0x00014060UL, 0x00000101UL,
  0x000140A8UL, 0x00000007UL,
  0x000440BCUL, 0x00000000UL,
  /*    40C0 */ 0x00000000UL,
  /*    40C4 */ 0x00000000UL,
  /*    40C8 */ 0x00000000UL,
  0x00034108UL, 0x00004CFFUL,
  /*    410C */ 0x00004DFFUL,
  /*    4110 */ 0x00004DFFUL,
  0x1001C020UL, 0x0007F800UL,
  0x3001C020UL, 0x000802F5UL,
  0x1001C024UL, 0x000000FFUL,
  0x3001C024UL, 0x00001300UL,
  0x0007C028UL, 0x83B380ECUL,
  /*    C02C */ 0x51407543UL,
  /*    C030 */ 0x48000FA0UL,
  /*    C034 */ 0x00004030UL,
  /*    C038 */ 0x00000000UL,
  /*    C03C */ 0x00000000UL,
  /*    C040 */ 0x0000022EUL,
  0x0004C050UL, 0x04301151UL,
  /*    C054 */ 0xE6092D0EUL,
  /*    C058 */ 0x08070654UL,
  /*    C05C */ 0x0002B6D1UL,
  0x000AC064UL, 0x1C003004UL,
  /*    C068 */ 0x09183040UL,
  /*    C06C */ 0x2079640DUL,
  /*    C070 */ 0x01FBFCEBUL,
  /*    C074 */ 0x03E8F67FUL,
  /*    C078 */ 0x15724BBDUL,
  /*    C07C */ 0x0518A311UL,
  /*    C080 */ 0x76543210UL,
  /*    C084 */ 0x00000A98UL,
  /*    C088 */ 0x00000000UL,
  0x01010008UL, 0x00000708UL,
  0x01010018UL, 0x00AAAAAAUL,
  0x01010020UL, 0x00DA6000UL,
  0x0101401CUL, 0x00000010UL,
  0x0103402CUL, 0x00008000UL,
  /*    4030 */ 0x03000000UL,
  /*    4034 */ 0x00000000UL,
  0x01024068UL, 0x71764129UL,
  /*    406C */ 0x00000000UL,
  0x010240BCUL, 0x00000000UL,
  /*    40C0 */ 0x00000000UL,
  0x010240E0UL, 0x00000033UL,
  /*    40E4 */ 0x00000000UL,
  0x010240F4UL, 0x07830464UL,
  /*    40F8 */ 0x3AC81388UL,
  0x01014124UL, 0x00000000UL,
  0x01014134UL, 0x0000010CUL,
  0x01014154UL, 0x00000101UL,
  0x01024168UL, 0x07830464UL,
  /*    416C */ 0x00821388UL,
  0x01014230UL, 0x00000000UL,
  0x01024238UL, 0x00000000UL,
  /*    423C */ 0x00000000UL,
  0x01014244UL, 0x00000000UL,
  0x01094254UL, 0x00000000UL,
  /*    4258 */ 0x003C0000UL,
  /*    425C */ 0x00000000UL,
  /*    4260 */ 0x00000000UL,
  /*    4264 */ 0x55555555UL,
  /*    4268 */ 0x00000017UL,
  /*    426C */ 0x00000000UL,
  /*    4270 */ 0x00000000UL,
  /*    4274 */ 0x0006AAAAUL,
  0x01018010UL, 0x00000003UL,
  0x0101803CUL, 0x00000001UL,
  0x010280B0UL, 0x02000300UL,
  /*    80B4 */ 0x01000037UL,
  0x02020098UL, 0x04000C00UL,
  /*    009C */ 0x0000004CUL,
  0x020100A4UL, 0x00000400UL,
  0x020200D0UL, 0x8A400005UL,
  /*    00D4 */ 0x00000188UL,
  0x020100F4UL, 0x00000000UL,
  0x120100F8UL, 0x000FCF00UL,
  0x320100F8UL, 0x1100203DUL,
  0x120100FCUL, 0x0000003FUL,
  0x320100FCUL, 0x00045400UL,
  0x02010130UL, 0x0251C060UL,
  0x02010168UL, 0x00000400UL,
  0xFFFFFFFFUL,
};

const uint32_t quuppa_viterbi1M_modemConfigBase[] = {
  0x0002400CUL, 0x00018101UL,
  /*    4010 */ 0x00004101UL,
  0x00024020UL, 0x00000000UL,
  /*    4024 */ 0x00000001UL,
  0x00024030UL, 0x00000000UL,
  /*    4034 */ 0x00000044UL,
  0x0004403CUL, 0x00000001UL,
  /*    4040 */ 0x00000000UL,
  /*    4044 */ 0x00004000UL,
  /*    4048 */ 0x030007A0UL,
  0x00014050UL, 0x00000000UL,
  0x0002405CUL, 0x00000000UL,
  /*    4060 */ 0x00000101UL,
  0x000140A8UL, 0x00000007UL,
  0x000440BCUL, 0x00000000UL,
  /*    40C0 */ 0x00000000UL,
  /*    40C4 */ 0x00000000UL,
  /*    40C8 */ 0x00000000UL,
  0x00044104UL, 0x00004CFFUL,
  /*    4108 */ 0x00004CFFUL,
  /*    410C */ 0x00004DFFUL,
  /*    4110 */ 0x00004DFFUL,
  0x1001C020UL, 0x0007F800UL,
  0x3001C020UL, 0x000802F5UL,
  0x1001C024UL, 0x000000FFUL,
  0x3001C024UL, 0x00001300UL,
  0x0007C028UL, 0x83B380ECUL,
  /*    C02C */ 0x51407543UL,
  /*    C030 */ 0x48000FA0UL,
  /*    C034 */ 0x00004030UL,
  /*    C038 */ 0x00000000UL,
  /*    C03C */ 0x00000000UL,
  /*    C040 */ 0x0000022EUL,
  0x0004C050UL, 0x04301151UL,
  /*    C054 */ 0xE6092D0EUL,
  /*    C058 */ 0x08070654UL,
  /*    C05C */ 0x0002B6D1UL,
  0x000AC064UL, 0x1C003004UL,
  /*    C068 */ 0x09183040UL,
  /*    C06C */ 0x2079640DUL,
  /*    C070 */ 0x01FBFCEBUL,
  /*    C074 */ 0x03E8F67FUL,
  /*    C078 */ 0x15724BBDUL,
  /*    C07C */ 0x0518A311UL,
  /*    C080 */ 0x76543210UL,
  /*    C084 */ 0x00000A98UL,
  /*    C088 */ 0x00000000UL,
  0x01010008UL, 0x00000708UL,
  0x01010018UL, 0x00AAAAAAUL,
  0x01010020UL, 0x00DA6000UL,
  0x0108401CUL, 0x00000010UL,
  /*    4020 */ 0x86000000UL,
  /*    4024 */ 0x0001C01FUL,
  /*    4028 */ 0x00006000UL,
  /*    402C */ 0x00008000UL,
  /*    4030 */ 0x03000000UL,
  /*    4034 */ 0x00000000UL,
  /*    4038 */ 0x40000000UL,
  0x01064058UL, 0x00FF04C8UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000001UL,
  /*    4064 */ 0x00040092UL,
  /*    4068 */ 0x8E89BED6UL,
  /*    406C */ 0x00000000UL,
  0x01114080UL, 0x020C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x002203B6UL,
  /*    408C */ 0x00000000UL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0E050200UL,
  /*    4098 */ 0x53432F1CUL,
  /*    409C */ 0x61686962UL,
  /*    40A0 */ 0x04324355UL,
  /*    40A4 */ 0x0E0E1016UL,
  /*    40A8 */ 0x080A0C0DUL,
  /*    40AC */ 0x04050607UL,
  /*    40B0 */ 0x02020303UL,
  /*    40B4 */ 0x01010102UL,
  /*    40B8 */ 0x00010101UL,
  /*    40BC */ 0x00000000UL,
  /*    40C0 */ 0x00000000UL,
  0x010240E0UL, 0x00000033UL,
  /*    40E4 */ 0x00000000UL,
  0x010540F4UL, 0x07830464UL,
  /*    40F8 */ 0x3AC81388UL,
  /*    40FC */ 0x000A2090UL,
  /*    4100 */ 0x80585B05UL,
  /*    4104 */ 0xB5BEC8B8UL,
  0x01024110UL, 0x2949192AUL,
  /*    4114 */ 0x40403B89UL,
  0x01024124UL, 0x00000000UL,
  /*    4128 */ 0x0000DDFFUL,
  0x01094134UL, 0x0000010CUL,
  /*    4138 */ 0x00FA53E8UL,
  /*    413C */ 0x00000000UL,
  /*    4140 */ 0x00000000UL,
  /*    4144 */ 0x00000000UL,
  /*    4148 */ 0x00000000UL,
  /*    414C */ 0x00000000UL,
  /*    4150 */ 0x00000000UL,
  /*    4154 */ 0x00000101UL,
  0x01034168UL, 0x07830464UL,
  /*    416C */ 0x00821388UL,
  /*    4170 */ 0x000003C1UL,
  0x01044230UL, 0x00000000UL,
  /*    4234 */ 0x0E000000UL,
  /*    4238 */ 0x00000000UL,
  /*    423C */ 0x00000000UL,
  0x01024244UL, 0x00000000UL,
  /*    4248 */ 0xC01EAA58UL,
  0x010C4254UL, 0x00000000UL,
  /*    4258 */ 0x003C0000UL,
  /*    425C */ 0x00000000UL,
  /*    4260 */ 0x00000000UL,
  /*    4264 */ 0x55555555UL,
  /*    4268 */ 0x00000017UL,
  /*    426C */ 0x00000000UL,
  /*    4270 */ 0x00000000UL,
  /*    4274 */ 0x0006AAAAUL,
  /*    4278 */ 0x00000000UL,
  /*    427C */ 0x00000000UL,
  /*    4280 */ 0x00000002UL,
  0x01018010UL, 0x00000003UL,
  0x01028038UL, 0x00102555UL,
  /*    803C */ 0x00000001UL,
  0x010280A0UL, 0x00037870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F6UL,
  0x310180A8UL, 0x01CB4201UL,
  0x110180ACUL, 0x000001F6UL,
  0x310180ACUL, 0x00FD3E01UL,
  0x010280B0UL, 0x02000300UL,
  /*    80B4 */ 0x01000037UL,
  0x02020098UL, 0x04000C00UL,
  /*    009C */ 0x0000004CUL,
  0x020100A4UL, 0x00000400UL,
  0x020200D0UL, 0x8A400005UL,
  /*    00D4 */ 0x00000188UL,
  0x020100E4UL, 0x13512F2EUL,
  0x020100F4UL, 0x00000000UL,
  0x120100F8UL, 0x000FCF00UL,
  0x320100F8UL, 0x1100203DUL,
  0x120100FCUL, 0x0000003FUL,
  0x320100FCUL, 0x00045400UL,
  0x02010130UL, 0x0251C060UL,
  0x02010154UL, 0x00023FC4UL,
  0x02010168UL, 0x00000400UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_viterbi1M_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_0,
  0x00014010UL, 0x00004101UL,
  0x0001403CUL, 0x00000000UL,
  0x00014048UL, 0x030007A0UL,
  0x00014050UL, 0x00000000UL,
  0x0001405CUL, 0x00000000UL,
  0x00014104UL, 0x00004CFFUL,
  0x01034020UL, 0x86000000UL,
  /*    4024 */ 0x0001C01FUL,
  /*    4028 */ 0x00006000UL,
  0x01014038UL, 0x40000000UL,
  0x01044058UL, 0x00FF04C8UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000001UL,
  /*    4064 */ 0x00040092UL,
  0x010F4080UL, 0x020C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x002203B6UL,
  /*    408C */ 0x00000000UL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0E050200UL,
  /*    4098 */ 0x53432F1CUL,
  /*    409C */ 0x61686962UL,
  /*    40A0 */ 0x04324355UL,
  /*    40A4 */ 0x0E0E1016UL,
  /*    40A8 */ 0x080A0C0DUL,
  /*    40AC */ 0x04050607UL,
  /*    40B0 */ 0x02020303UL,
  /*    40B4 */ 0x01010102UL,
  /*    40B8 */ 0x00010101UL,
  0x010140ECUL, 0x8C2BE890UL,
  0x010340FCUL, 0x000A2090UL,
  /*    4100 */ 0x80585B05UL,
  /*    4104 */ 0x4A413747UL,
  0x0103410CUL, 0x005262F5UL,
  /*    4110 */ 0x2949192AUL,
  /*    4114 */ 0x40403B89UL,
  0x01014128UL, 0x0000DDFFUL,
  0x01074138UL, 0x00FA53E8UL,
  /*    413C */ 0x00000000UL,
  /*    4140 */ 0x00000000UL,
  /*    4144 */ 0x00000000UL,
  /*    4148 */ 0x00000000UL,
  /*    414C */ 0x00000000UL,
  /*    4150 */ 0x00000000UL,
  0x01014170UL, 0x000003C1UL,
  0x01014234UL, 0x0E000000UL,
  0x01014248UL, 0xC01EAA58UL,
  0x01034278UL, 0x00000000UL,
  /*    427C */ 0x00000000UL,
  /*    4280 */ 0x00000002UL,
  0x01018038UL, 0x00102555UL,
  0x010280A0UL, 0x00037870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F6UL,
  0x310180A8UL, 0x01CB4201UL,
  0x110180ACUL, 0x000001F6UL,
  0x310180ACUL, 0x00FD3E01UL,
  0x020100E4UL, 0x13512F2EUL,
  0x02010154UL, 0x00023FC4UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_viterbi2M_0_34_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_1,
  0x00014010UL, 0x00004101UL,
  0x0001403CUL, 0x00000000UL,
  0x00014048UL, 0x030007A0UL,
  0x00014050UL, 0x00000000UL,
  0x0001405CUL, 0x00000000UL,
  0x00014104UL, 0x00004CFFUL,
  0x01034020UL, 0x86000000UL,
  /*    4024 */ 0x0001C01FUL,
  /*    4028 */ 0x00006000UL,
  0x01014038UL, 0x40000000UL,
  0x01044058UL, 0x00FF0264UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000001UL,
  /*    4064 */ 0x00080092UL,
  0x010F4080UL, 0x020C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x002203D7UL,
  /*    408C */ 0x00000000UL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0D050200UL,
  /*    4098 */ 0x503F2D1AUL,
  /*    409C */ 0x63696860UL,
  /*    40A0 */ 0x25354657UL,
  /*    40A4 */ 0x08090D15UL,
  /*    40A8 */ 0x05050607UL,
  /*    40AC */ 0x03040404UL,
  /*    40B0 */ 0x02030303UL,
  /*    40B4 */ 0x02020202UL,
  /*    40B8 */ 0x01010101UL,
  0x010140ECUL, 0x8C2C3890UL,
  0x010340FCUL, 0x000A209CUL,
  /*    4100 */ 0x80585B05UL,
  /*    4104 */ 0x4A413747UL,
  0x0103410CUL, 0x005255B8UL,
  /*    4110 */ 0x2949192AUL,
  /*    4114 */ 0x40403B89UL,
  0x01014128UL, 0x0000DDFFUL,
  0x01074138UL, 0x00FA53E8UL,
  /*    413C */ 0x00000000UL,
  /*    4140 */ 0x00000000UL,
  /*    4144 */ 0x00000000UL,
  /*    4148 */ 0x00000000UL,
  /*    414C */ 0x00000000UL,
  /*    4150 */ 0x00000000UL,
  0x01014170UL, 0x000003C1UL,
  0x01014234UL, 0x0E000000UL,
  0x01014248UL, 0xC01EAA58UL,
  0x01034278UL, 0x00000000UL,
  /*    427C */ 0x00000000UL,
  /*    4280 */ 0x00000002UL,
  0x01018038UL, 0x00104911UL,
  0x010280A0UL, 0x00037870UL,
  /*    80A4 */ 0x0002C0FFUL,
  0x110180A8UL, 0x000001F6UL,
  0x310180A8UL, 0x01CB4201UL,
  0x110180ACUL, 0x000001F6UL,
  0x310180ACUL, 0x000D0A01UL,
  0x020100E4UL, 0x11512F2CUL,
  0x02010154UL, 0x00003FC4UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_LR_DSA_125kb_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_2,
  0x00014010UL, 0x00004100UL,
  0x0001403CUL, 0x00000010UL,
  0x00014048UL, 0x03000720UL,
  0x00014050UL, 0x00000400UL,
  0x0001405CUL, 0x00000F0DUL,
  0x00014104UL, 0x0001C003UL,
  0x01034020UL, 0x46000030UL,
  /*    4024 */ 0x0001C81FUL,
  /*    4028 */ 0x10002000UL,
  0x01014038UL, 0x00000000UL,
  0x01044058UL, 0x00050018UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000009UL,
  /*    4064 */ 0x000A0092UL,
  0x010F4080UL, 0x022C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x00120012UL,
  /*    408C */ 0x1B8C805BUL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0E050200UL,
  /*    4098 */ 0x53432F1CUL,
  /*    409C */ 0x61686962UL,
  /*    40A0 */ 0x04324355UL,
  /*    40A4 */ 0x0E0E1016UL,
  /*    40A8 */ 0x080A0C0DUL,
  /*    40AC */ 0x04050607UL,
  /*    40B0 */ 0x02020303UL,
  /*    40B4 */ 0x01010102UL,
  /*    40B8 */ 0x00010101UL,
  0x010140ECUL, 0x8CB1B080UL,
  0x010340FCUL, 0x000A209CUL,
  /*    4100 */ 0x80206101UL,
  /*    4104 */ 0x123556B7UL,
  0x0103410CUL, 0x001255B8UL,
  /*    4110 */ 0x29041BA0UL,
  /*    4114 */ 0x40408808UL,
  0x01014128UL, 0x00000000UL,
  0x01074138UL, 0x3BE8D44CUL,
  /*    413C */ 0x306F1904UL,
  /*    4140 */ 0x1A140E08UL,
  /*    4144 */ 0x322C2620UL,
  /*    4148 */ 0x32103E38UL,
  /*    414C */ 0x0A987654UL,
  /*    4150 */ 0x00005F1DUL,
  0x01014170UL, 0x00000000UL,
  0x01014234UL, 0x0E000800UL,
  0x01014248UL, 0x001F81F4UL,
  0x01034278UL, 0x00000000UL,
  /*    427C */ 0x00000000UL,
  /*    4280 */ 0x00000012UL,
  0x01018038UL, 0x00104911UL,
  0x0103809CUL, 0x000240EBUL,
  /*    80A0 */ 0x00033870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F6UL,
  0x310180A8UL, 0x01FD5A01UL,
  0x110180ACUL, 0x000001F6UL,
  0x310180ACUL, 0x00FD3E01UL,
  0x020100E4UL, 0x11512F2CUL,
  0x02010154UL, 0x00003FC4UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_LR_DSA_500kb_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_3,
  0x00014010UL, 0x00004100UL,
  0x0001403CUL, 0x00000010UL,
  0x00014048UL, 0x03001720UL,
  0x00014050UL, 0x00000401UL,
  0x0001405CUL, 0x00000F0DUL,
  0x00014104UL, 0x0001C003UL,
  0x01034020UL, 0x46000030UL,
  /*    4024 */ 0x0001C81FUL,
  /*    4028 */ 0x10002000UL,
  0x01014038UL, 0x00000000UL,
  0x01044058UL, 0x00050018UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000009UL,
  /*    4064 */ 0x000A0092UL,
  0x010F4080UL, 0x022C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x00120012UL,
  /*    408C */ 0x1B8C805BUL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0E050200UL,
  /*    4098 */ 0x53432F1CUL,
  /*    409C */ 0x61686962UL,
  /*    40A0 */ 0x04324355UL,
  /*    40A4 */ 0x0E0E1016UL,
  /*    40A8 */ 0x080A0C0DUL,
  /*    40AC */ 0x04050607UL,
  /*    40B0 */ 0x02020303UL,
  /*    40B4 */ 0x01010102UL,
  /*    40B8 */ 0x00010101UL,
  0x010140ECUL, 0x8CB1B080UL,
  0x010340FCUL, 0x000A209CUL,
  /*    4100 */ 0x80206101UL,
  /*    4104 */ 0x123556B7UL,
  0x0103410CUL, 0x001255B8UL,
  /*    4110 */ 0x29041BA0UL,
  /*    4114 */ 0x40408808UL,
  0x01014128UL, 0x00000000UL,
  0x01074138UL, 0x3BE8D44CUL,
  /*    413C */ 0x306F1904UL,
  /*    4140 */ 0x1C16100AUL,
  /*    4144 */ 0x342E2822UL,
  /*    4148 */ 0x3210403AUL,
  /*    414C */ 0x0A987654UL,
  /*    4150 */ 0xA4805F1DUL,
  0x01014170UL, 0x00000000UL,
  0x01014234UL, 0x0E000800UL,
  0x01014248UL, 0x001F81F4UL,
  0x01034278UL, 0x00000000UL,
  /*    427C */ 0x00000000UL,
  /*    4280 */ 0x00000012UL,
  0x01018038UL, 0x00104911UL,
  0x0103809CUL, 0x000240EBUL,
  /*    80A0 */ 0x00033870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F6UL,
  0x310180A8UL, 0x01FD5A01UL,
  0x110180ACUL, 0x000001F6UL,
  0x310180ACUL, 0x00FD3E01UL,
  0x020100E4UL, 0x11512F2CUL,
  0x02010154UL, 0x00003FC4UL,
  0xFFFFFFFFUL,
};

const uint32_t ble_LR_DSA_1Mb_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_4,
  0x00014010UL, 0x00004100UL,
  0x0001403CUL, 0x00000000UL,
  0x00014048UL, 0x03000720UL,
  0x00014050UL, 0x00000000UL,
  0x0001405CUL, 0x00000F0DUL,
  0x00014104UL, 0x00004CFFUL,
  0x01034020UL, 0x86000000UL,
  /*    4024 */ 0x0001C01FUL,
  /*    4028 */ 0x00002000UL,
  0x01014038UL, 0x00000000UL,
  0x01044058UL, 0x00050018UL,
  /*    405C */ 0x00000840UL,
  /*    4060 */ 0x00000009UL,
  /*    4064 */ 0x00040092UL,
  0x010F4080UL, 0x022C008CUL,
  /*    4084 */ 0x00000000UL,
  /*    4088 */ 0x00120012UL,
  /*    408C */ 0x198C8000UL,
  /*    4090 */ 0x00000000UL,
  /*    4094 */ 0x0E050200UL,
  /*    4098 */ 0x53432F1CUL,
  /*    409C */ 0x61686962UL,
  /*    40A0 */ 0x04324355UL,
  /*    40A4 */ 0x0E0E1016UL,
  /*    40A8 */ 0x080A0C0DUL,
  /*    40AC */ 0x04050607UL,
  /*    40B0 */ 0x02020303UL,
  /*    40B4 */ 0x01010102UL,
  /*    40B8 */ 0x00010101UL,
  0x010140ECUL, 0x8CB1B080UL,
  0x010340FCUL, 0x000B209CUL,
  /*    4100 */ 0x80605B05UL,
  /*    4104 */ 0x4A413747UL,
  0x0103410CUL, 0x001255B8UL,
  /*    4110 */ 0x2949192AUL,
  /*    4114 */ 0x40400809UL,
  0x01014128UL, 0x0000DDFFUL,
  0x01074138UL, 0x3BE8D44CUL,
  /*    413C */ 0x106F1904UL,
  /*    4140 */ 0x1A140E08UL,
  /*    4144 */ 0x322C2620UL,
  /*    4148 */ 0x32103E38UL,
  /*    414C */ 0x0A987654UL,
  /*    4150 */ 0x0000001DUL,
  0x01014170UL, 0x000003C0UL,
  0x01014234UL, 0x0E000800UL,
  0x01014248UL, 0xC01EAA58UL,
  0x01034278UL, 0x80000000UL,
  /*    427C */ 0x00000000UL,
  /*    4280 */ 0x00000012UL,
  0x01018038UL, 0x00104911UL,
  0x0103809CUL, 0x000240EBUL,
  /*    80A0 */ 0x00033870UL,
  /*    80A4 */ 0x000000D0UL,
  0x110180A8UL, 0x000001F6UL,
  0x310180A8UL, 0x01FD5A01UL,
  0x110180ACUL, 0x000001F6UL,
  0x310180ACUL, 0x00FD3E01UL,
  0x020100E4UL, 0x11512F2CUL,
  0x02010154UL, 0x00003FC4UL,
  0xFFFFFFFFUL,
};

const uint32_t quuppa_viterbi1M_0_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_5,
  0x00014038UL, 0x00000056UL,
  0x010140ECUL, 0x8C2B7890UL,
  0x0101410CUL, 0x00526336UL,
  0xFFFFFFFFUL,
};

const uint32_t quuppa_viterbi1M_1_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_5,
  0x00014038UL, 0x00000065UL,
  0x010140ECUL, 0x8C2B7890UL,
  0x0101410CUL, 0x00526336UL,
  0xFFFFFFFFUL,
};

const uint32_t quuppa_viterbi1M_2_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_5,
  0x00014038UL, 0x00000058UL,
  0x010140ECUL, 0x8C2B7890UL,
  0x0101410CUL, 0x00526336UL,
  0xFFFFFFFFUL,
};

const uint32_t quuppa_viterbi1M_3_modemConfig[] = {
  0x03014FFCUL, (uint32_t) &phyInfo_5,
  0x00014038UL, 0x00000066UL,
  0x010140ECUL, 0x8C30C894UL,
  0x0101410CUL, 0x00524FBFUL,
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
    .maxPower = 300,
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
    .maxPower = 58,
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
    .maxPower = 300,
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

const RAIL_ChannelConfigEntry_t ble_LR_DSA_1Mb_channels[] = {
  {
    .phyConfigDeltaAdd = ble_LR_DSA_1Mb_modemConfig,
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
    .stackInfo = stackInfo_4,
#endif
    .alternatePhy = NULL,
  },
};

const RAIL_ChannelConfigEntry_t quuppa_viterbi1M_channels[] = {
  {
    .phyConfigDeltaAdd = quuppa_viterbi1M_0_modemConfig,
    .baseFrequency = 2401000000,
    .channelSpacing = 1000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 0,
    .channelNumberEnd = 0,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_5,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = quuppa_viterbi1M_1_modemConfig,
    .baseFrequency = 2401000000,
    .channelSpacing = 1000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 1,
    .channelNumberEnd = 1,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_5,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = quuppa_viterbi1M_2_modemConfig,
    .baseFrequency = 2401000000,
    .channelSpacing = 1000000,
    .physicalChannelOffset = 0,
    .channelNumberStart = 2,
    .channelNumberEnd = 2,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_5,
#endif
    .alternatePhy = NULL,
  },
  {
    .phyConfigDeltaAdd = quuppa_viterbi1M_3_modemConfig,
    .baseFrequency = 2480000000,
    .channelSpacing = 1000000,
    .physicalChannelOffset = 2,
    .channelNumberStart = 3,
    .channelNumberEnd = 3,
    .maxPower = RAIL_TX_POWER_MAX,
    .attr = &channelConfigEntryAttr,
#ifdef RADIO_CONFIG_ENABLE_CONC_PHY
    .entryType = 0,
#endif
#ifdef RADIO_CONFIG_ENABLE_STACK_INFO
    .stackInfo = stackInfo_5,
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

const RAIL_ChannelConfig_t ble_LR_DSA_1Mb_channelConfig = {
  .phyConfigBase = ble_viterbi1M_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = ble_LR_DSA_1Mb_channels,
  .length = 1U,
  .signature = 0UL,
  .xtalFrequencyHz = 38400000UL,
};

const RAIL_ChannelConfig_t quuppa_viterbi1M_channelConfig = {
  .phyConfigBase = quuppa_viterbi1M_modemConfigBase,
  .phyConfigDeltaSubtract = NULL,
  .configs = quuppa_viterbi1M_channels,
  .length = 4U,
  .signature = 0UL,
  .xtalFrequencyHz = 38400000UL,
};
