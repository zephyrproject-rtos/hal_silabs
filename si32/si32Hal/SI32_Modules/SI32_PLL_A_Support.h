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

#ifndef __SI32_PLL_A_SUPPORT_H__
#define __SI32_PLL_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Spectrum Spreading Amplitude Enum type

typedef enum SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_Enum
{
	SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_0P1_PERCENT = 0,
	SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_0P2_PERCENT = 1,
	SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_0P4_PERCENT = 2,
	SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_0P8_PERCENT = 3,
	SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_1P6_PERCENT = 4
} SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_Enum_Type;

//-----------------------------------------------------------------------------
// Define Output Frequency Range Enum type

typedef enum SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_Enum
{
	SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_23_TO_32_MHZ = 0,
	SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_33_TO_54_MHZ = 1,
	SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_45_TO_71_MHZ = 2,
	SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_53_TO_80_MHZ = 3,
	SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_73_TO_80_MHZ = 4
} SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PLL_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
