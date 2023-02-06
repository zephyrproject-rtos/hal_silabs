//------------------------------------------------------------------------------
// Copyright 2012 (c) Silicon Laboratories Inc.
//
// SPDX-License-Identifier: Zlib
//
// This siHAL software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//------------------------------------------------------------------------------

// Version: 1

#ifndef __SI32_EXTVREG_A_SUPPORT_H__
#define __SI32_EXTVREG_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Current Limit Minimum Coarse Enum type

typedef enum SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_Enum
{
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_1_UA = 1,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_2_UA = 2,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_3_UA = 3,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_4_UA = 4,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_5_UA = 5,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_6_UA = 6,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_7_UA = 7,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_8_UA = 8
} SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_Enum_Type;

//-----------------------------------------------------------------------------
// Define Current Limit Minimum Fine Enum type

typedef enum SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_Enum
{
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_P00_UA = 0,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_P25_UA = 1,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_P50_UA = 2,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_P75_UA = 3
} SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_Enum_Type;

//-----------------------------------------------------------------------------
// Define Foldback Voltage Offset Enum type

typedef enum SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_Enum
{
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_0P0_V = 0,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_0P5_V = 1,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_1P0_V = 2,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_1P5_V = 3,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_2P0_V = 4,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_2P5_V = 5,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_3P0_V = 6,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_3P5_V = 7
} SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_Enum_Type;

//-----------------------------------------------------------------------------
// Define Current Limit Maximum Enum type

typedef enum SI32_EXTVREG_A_CURRENT_LIMIT_MAX_Enum
{
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_2_UA = 0,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_3_UA = 1,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_4_UA = 2,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_5_UA = 3,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_6_UA = 4,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_7_UA = 5,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_8_UA = 6,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_9_UA = 7,
} SI32_EXTVREG_A_CURRENT_LIMIT_MAX_Enum_Type;

//-----------------------------------------------------------------------------
// Define ADC Current Sense Gain Enum type

typedef enum SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_Enum
{
   SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_16X  = 0,
   SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_8X  = 1,
   SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_4X  = 2,
   SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_2X  = 3,
   SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_11X = 4
} SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_Enum_Type;

//-----------------------------------------------------------------------------
// Define External Regulator Current Sense Gain Enum type

typedef enum SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_Enum
{
   SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_16X  = 0,
   SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_8X  = 1,
   SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_4X  = 2,
   SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_2X  = 3,
   SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_1X = 4
} SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_EXTVREG_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
