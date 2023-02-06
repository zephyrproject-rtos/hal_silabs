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

#ifndef __SI32_CAPSENSE_A_SUPPORT_H__
#define __SI32_CAPSENSE_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Conversion Rate Enum type

typedef enum SI32_CAPSENSE_A_CONVERSION_RATE_Enum
{
   SI32_CAPSENSE_A_CONVERSION_RATE_12_CLOCKS_12_BITS = 0,
   SI32_CAPSENSE_A_CONVERSION_RATE_13_CLOCKS_13_BITS = 1,
   SI32_CAPSENSE_A_CONVERSION_RATE_14_CLOCKS_14_BITS = 2,
   SI32_CAPSENSE_A_CONVERSION_RATE_16_CLOCKS_16_BITS = 3
} SI32_CAPSENSE_A_CONVERSION_RATE_Enum_Type;

//-----------------------------------------------------------------------------
// Define Accumulator Mode Enum type

typedef enum SI32_CAPSENSE_A_ACCUMULATOR_MODE_Enum
{
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_1_SAMPLE   = 0,
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_4_SAMPLES  = 1,
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_8_SAMPLES  = 2,
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_16_SAMPLES = 3,
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_32_SAMPLES = 4,
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_64_SAMPLES = 5
} SI32_CAPSENSE_A_ACCUMULATOR_MODE_Enum_Type;

//-----------------------------------------------------------------------------
// Define Pin Monitor Mode Enum type

typedef enum SI32_CAPSENSE_A_PIN_MONITOR_MODE_Enum
{
   SI32_CAPSENSE_A_PIN_MONITOR_MODE_RETRY_ON_PIN_STATE_CHANGE = 0,
   SI32_CAPSENSE_A_PIN_MONITOR_MODE_RETRY_UP_TO_TWICE         = 1,
   SI32_CAPSENSE_A_PIN_MONITOR_MODE_RETRY_UP_TO_4_TIMES       = 2,
   SI32_CAPSENSE_A_PIN_MONITOR_MODE_IGNORE_STATE_CHANGE       = 3
} SI32_CAPSENSE_A_PIN_MONITOR_MODE_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_CAPSENSE_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
