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

#ifndef __SI32_SARADC_A_SUPPORT_H__
#define __SI32_SARADC_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Bias Power Enum type

typedef enum SI32_SARADC_A_BIAS_POWER_Enum
{
	SI32_SARADC_A_BIAS_POWER_MAXIMUM = 0,
	SI32_SARADC_A_BIAS_POWER_HIGH    = 1,
	SI32_SARADC_A_BIAS_POWER_LOW     = 2,
	SI32_SARADC_A_BIAS_POWER_MINIMUM = 3
} SI32_SARADC_A_BIAS_POWER_Enum_Type;

//-----------------------------------------------------------------------------
// Define Burst Mode Repeat Count Enum type

typedef enum SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum
{
	SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_SAMPLE_ONCE     = 0,
	SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_SAMPLE_4_TIMES  = 1,
	SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_SAMPLE_8_TIMES  = 2,
	SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_SAMPLE_16_TIMES = 3,
	SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_SAMPLE_32_TIMES = 4,
	SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_SAMPLE_64_TIMES = 5
} SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_SARADC_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
