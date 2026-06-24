/***************************************************************************//**
 * @file
 * @brief PA power conversion curves used by Silicon Labs PA power conversion
 *   functions.
 * @details This file contains the curves needed convert PA power levels to
 *   dBm powers.
 *******************************************************************************
 * # License
 * <b>Copyright 2026 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef __PA_DBM_POWERSETTING_MAPPING_EFR32XG28_H_
#define __PA_DBM_POWERSETTING_MAPPING_EFR32XG28_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SL_RAIL_PA_TABLE_1_MIN_POWER_DDBM -450
#define SL_RAIL_PA_TABLE_1_MAX_POWER_DDBM  200
#define SL_RAIL_PA_TABLE_1_STEP_DDBM        10
#define SL_RAIL_PA_TABLE_1_NUM_VALUES       66U

#define SL_RAIL_PA_TABLE_1                            \
  {                               /* round:lowest */  \
    /* LLP from min to -11 dBm */                     \
    0xc000 /* est_deci-dBm:-450 act_deci-dBm:-443 */, \
    0xc000 /* est_deci-dBm:-440 act_deci-dBm:-443 */, \
    0xc000 /* est_deci-dBm:-430 act_deci-dBm:-443 */, \
    0xc002 /* est_deci-dBm:-420 act_deci-dBm:-429 */, \
    0xc003 /* est_deci-dBm:-410 act_deci-dBm:-419 */, \
    0xc003 /* est_deci-dBm:-400 act_deci-dBm:-419 */, \
    0xc005 /* est_deci-dBm:-390 act_deci-dBm:-390 */, \
    0xc005 /* est_deci-dBm:-380 act_deci-dBm:-390 */, \
    0xc007 /* est_deci-dBm:-370 act_deci-dBm:-371 */, \
    0xc007 /* est_deci-dBm:-360 act_deci-dBm:-371 */, \
    0xc008 /* est_deci-dBm:-350 act_deci-dBm:-353 */, \
    0xc00a /* est_deci-dBm:-340 act_deci-dBm:-340 */, \
    0xc00b /* est_deci-dBm:-330 act_deci-dBm:-335 */, \
    0xc00d /* est_deci-dBm:-320 act_deci-dBm:-322 */, \
    0xc00f /* est_deci-dBm:-310 act_deci-dBm:-312 */, \
    0xc00f /* est_deci-dBm:-300 act_deci-dBm:-312 */, \
    0xc012 /* est_deci-dBm:-290 act_deci-dBm:-292 */, \
    0xc015 /* est_deci-dBm:-280 act_deci-dBm:-281 */, \
    0xc017 /* est_deci-dBm:-270 act_deci-dBm:-275 */, \
    0xc01b /* est_deci-dBm:-260 act_deci-dBm:-260 */, \
    0xc01e /* est_deci-dBm:-250 act_deci-dBm:-251 */, \
    0xc022 /* est_deci-dBm:-240 act_deci-dBm:-240 */, \
    0xc027 /* est_deci-dBm:-230 act_deci-dBm:-230 */, \
    0xc02c /* est_deci-dBm:-220 act_deci-dBm:-220 */, \
    0xc031 /* est_deci-dBm:-210 act_deci-dBm:-210 */, \
    0xc037 /* est_deci-dBm:-200 act_deci-dBm:-202 */, \
    0xc03f /* est_deci-dBm:-190 act_deci-dBm:-190 */, \
    0xc047 /* est_deci-dBm:-180 act_deci-dBm:-180 */, \
    0xc04e /* est_deci-dBm:-170 act_deci-dBm:-171 */, \
    0xc058 /* est_deci-dBm:-160 act_deci-dBm:-160 */, \
    0xc064 /* est_deci-dBm:-150 act_deci-dBm:-150 */, \
    0xc070 /* est_deci-dBm:-140 act_deci-dBm:-140 */, \
    0xc07e /* est_deci-dBm:-130 act_deci-dBm:-130 */, \
    0xc08d /* est_deci-dBm:-120 act_deci-dBm:-120 */, \
    0xc09d /* est_deci-dBm:-110 act_deci-dBm:-110 */, \
    /* LP from -10 to -1 dBm */                       \
    0x803e /* est_deci-dBm:-100 act_deci-dBm:-100 */, \
    0x8047 /* est_deci-dBm: -90 act_deci-dBm: -90 */, \
    0x804e /* est_deci-dBm: -80 act_deci-dBm: -81 */, \
    0x8057 /* est_deci-dBm: -70 act_deci-dBm: -71 */, \
    0x8063 /* est_deci-dBm: -60 act_deci-dBm: -60 */, \
    0x806f /* est_deci-dBm: -50 act_deci-dBm: -50 */, \
    0x807c /* est_deci-dBm: -40 act_deci-dBm: -40 */, \
    0x808b /* est_deci-dBm: -30 act_deci-dBm: -30 */, \
    0x809c /* est_deci-dBm: -20 act_deci-dBm: -20 */, \
    0x80af /* est_deci-dBm: -10 act_deci-dBm: -10 */, \
    /* HP from 0 dBm to max */                        \
    0x000a /* est_deci-dBm:   0 act_deci-dBm:  -6 */, \
    0x000c /* est_deci-dBm:  10 act_deci-dBm:   7 */, \
    0x000e /* est_deci-dBm:  20 act_deci-dBm:  18 */, \
    0x0010 /* est_deci-dBm:  30 act_deci-dBm:  28 */, \
    0x0012 /* est_deci-dBm:  40 act_deci-dBm:  37 */, \
    0x0015 /* est_deci-dBm:  50 act_deci-dBm:  49 */, \
    0x0018 /* est_deci-dBm:  60 act_deci-dBm:  59 */, \
    0x001c /* est_deci-dBm:  70 act_deci-dBm:  70 */, \
    0x001f /* est_deci-dBm:  80 act_deci-dBm:  77 */, \
    0x0024 /* est_deci-dBm:  90 act_deci-dBm:  90 */, \
    0x0028 /* est_deci-dBm: 100 act_deci-dBm:  99 */, \
    0x002e /* est_deci-dBm: 110 act_deci-dBm: 109 */, \
    0x0035 /* est_deci-dBm: 120 act_deci-dBm: 120 */, \
    0x003e /* est_deci-dBm: 130 act_deci-dBm: 130 */, \
    0x0047 /* est_deci-dBm: 140 act_deci-dBm: 140 */, \
    0x0053 /* est_deci-dBm: 150 act_deci-dBm: 150 */, \
    0x0062 /* est_deci-dBm: 160 act_deci-dBm: 160 */, \
    0x0075 /* est_deci-dBm: 170 act_deci-dBm: 170 */, \
    0x0090 /* est_deci-dBm: 180 act_deci-dBm: 180 */, \
    0x00b8 /* est_deci-dBm: 190 act_deci-dBm: 190 */, \
    0x00ec /* est_deci-dBm: 200 act_deci-dBm: 200 */, \
  }

#if (_SILICON_LABS_EFR32_RADIO_TYPE == _SILICON_LABS_EFR32_RADIO_DUALBAND)
#define SL_RAIL_PA_TABLE_0_MIN_POWER_DDBM -200
#define SL_RAIL_PA_TABLE_0_MAX_POWER_DDBM  120
#define SL_RAIL_PA_TABLE_0_STEP_DDBM        10
#define SL_RAIL_PA_TABLE_0_NUM_VALUES       33U

#define SL_RAIL_PA_TABLE_0                            \
  {                               /* round:lowest */  \
    0x0000 /* est_deci-dBm:-200 act_deci-dBm:-199 */, \
    0x0000 /* est_deci-dBm:-190 act_deci-dBm:-199 */, \
    0x0000 /* est_deci-dBm:-180 act_deci-dBm:-199 */, \
    0x0000 /* est_deci-dBm:-170 act_deci-dBm:-199 */, \
    0x0002 /* est_deci-dBm:-160 act_deci-dBm:-164 */, \
    0x0002 /* est_deci-dBm:-150 act_deci-dBm:-164 */, \
    0x0003 /* est_deci-dBm:-140 act_deci-dBm:-141 */, \
    0x0003 /* est_deci-dBm:-130 act_deci-dBm:-141 */, \
    0x0004 /* est_deci-dBm:-120 act_deci-dBm:-123 */, \
    0x0004 /* est_deci-dBm:-110 act_deci-dBm:-123 */, \
    0x0005 /* est_deci-dBm:-100 act_deci-dBm:-107 */, \
    0x0006 /* est_deci-dBm: -90 act_deci-dBm: -94 */, \
    0x0007 /* est_deci-dBm: -80 act_deci-dBm: -84 */, \
    0x0008 /* est_deci-dBm: -70 act_deci-dBm: -75 */, \
    0x000a /* est_deci-dBm: -60 act_deci-dBm: -60 */, \
    0x000b /* est_deci-dBm: -50 act_deci-dBm: -53 */, \
    0x000d /* est_deci-dBm: -40 act_deci-dBm: -41 */, \
    0x000f /* est_deci-dBm: -30 act_deci-dBm: -31 */, \
    0x0011 /* est_deci-dBm: -20 act_deci-dBm: -22 */, \
    0x0014 /* est_deci-dBm: -10 act_deci-dBm: -11 */, \
    0x0017 /* est_deci-dBm:   0 act_deci-dBm:  -2 */, \
    0x001b /* est_deci-dBm:  10 act_deci-dBm:   8 */, \
    0x001f /* est_deci-dBm:  20 act_deci-dBm:  18 */, \
    0x0023 /* est_deci-dBm:  30 act_deci-dBm:  30 */, \
    0x002a /* est_deci-dBm:  40 act_deci-dBm:  40 */, \
    0x0031 /* est_deci-dBm:  50 act_deci-dBm:  50 */, \
    0x0039 /* est_deci-dBm:  60 act_deci-dBm:  60 */, \
    0x0043 /* est_deci-dBm:  70 act_deci-dBm:  70 */, \
    0x0052 /* est_deci-dBm:  80 act_deci-dBm:  80 */, \
    0x0064 /* est_deci-dBm:  90 act_deci-dBm:  90 */, \
    0x0084 /* est_deci-dBm: 100 act_deci-dBm: 100 */, \
    0x00b8 /* est_deci-dBm: 110 act_deci-dBm: 110 */, \
    0x00ed /* est_deci-dBm: 120 act_deci-dBm: 117 */, \
  }
#endif // (_SILICON_LABS_EFR32_RADIO_TYPE == _SILICON_LABS_EFR32_RADIO_DUALBAND)

#ifdef __cplusplus
}
#endif

#endif
