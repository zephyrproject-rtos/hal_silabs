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
// This file applies to the SIM3C1XX_PMU_A module
//
// Version: 1

#ifndef __SI32_PMU_A_SUPPORT_H__
#define __SI32_PMU_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the PMU Enum type

typedef enum SI32_PMU_Wakeup_Enum
{
   SI32_RESET_WAKEUP                      = 0,
   SI32_PIN_WAKEUP                        = 1,
   SI32_LPTIMER0_WAKEUP                   = 2,
   SI32_CMP0_WAKEUP                       = 3,
   SI32_RTC0_ALARM_WAKEUP                 = 4,
   SI32_RTC0_FAIL_WAKEUP                  = 5,
   SI32_ADVANCED_CAPTURE_COUNTER_WAKEUP   = 6,
   SI32_LCD_MONITOR_WAKEUP                = 7,
   SI32_UART0_WAKEUP                      = 8,
   SI32_NO_WAKEUP                         = 9,
   SI32_WAKEUP_ERROR                      = 10,
} SI32_PMU_Wakeup_Enum_Type;

#ifdef __cplusplus
}

#endif

#endif // __SI32_PMU_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
