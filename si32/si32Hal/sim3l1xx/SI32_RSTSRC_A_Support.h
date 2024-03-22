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
//
// This file applies to the SIM3L1XX_RSTSRC_A module
//
// Version: 1

#ifndef __SI32_RSTSRC_A_SUPPORT_H__
#define __SI32_RSTSRC_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the RSTSRC Enum type

typedef enum SI32_RSTSRC_Enum
{
  SI32_PIN_RESET         = 0,
  SI32_POWER_ON_RESET    = 1,
  SI32_VDD_MON_RESET     = 2,
  SI32_CORE_RESET        = 3,
  SI32_MCD_RESET         = 4,
  SI32_WDT_RESET         = 5,
  SI32_SW_RESET          = 6,
  SI32_CMP0_RESET        = 7,
  SI32_CMP1_RESET        = 8,
  SI32_LPCPFAIL_RESET    = 9,
  SI32_RTC0_RESET        = 10,
  SI32_PMU_WAKEUP_RESET  = 11,
  SI32_RESET_ERROR       = 12
} SI32_RSTSRC_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_RSTSRC_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
