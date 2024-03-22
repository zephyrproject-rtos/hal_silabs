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
// This file applies to the SIM3L1XX_LOCK_A module
//
// Version: 1

#ifndef __SI32_LOCK_A_SUPPORT_H__
#define __SI32_LOCK_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Lock/Unlock Values and Global Mask

#define SI32_LOCK_A_LOCK_VALUE      0x00
#define SI32_LOCK_A_UNLOCK_VALUE_1  0xA5
#define SI32_LOCK_A_UNLOCK_VALUE_2  0xF1

#define SI32_LOCK_A_PERIPHLOCK0_ALL_LOCKS_MASK  0x787FFFFF
#define SI32_LOCK_A_PERIPHLOCK1_ALL_LOCKS_MASK  0x00000001

//-----------------------------------------------------------------------------
// Define the LOCK Enum type

typedef enum SI32_LOCK_A_Enum
{
  SI32_LOCK_A_SELECT_USART_LOCK    = 0,
  SI32_LOCK_A_SELECT_SPI_LOCK      = 1,
  SI32_LOCK_A_SELECT_I2C_LOCK      = 2,
  SI32_LOCK_A_SELECT_PCA_LOCK      = 3,
  SI32_LOCK_A_SELECT_TIMER_LOCK    = 4,
  SI32_LOCK_A_SELECT_SARADC_LOCK   = 5,
  SI32_LOCK_A_SELECT_CMP_LOCK      = 6,
  SI32_LOCK_A_SELECT_AES_LOCK      = 7,
  SI32_LOCK_A_SELECT_CRC_LOCK      = 8,
  SI32_LOCK_A_SELECT_RTC_LOCK      = 9,
  SI32_LOCK_A_SELECT_RSTSRC_LOCK   = 10,
  SI32_LOCK_A_SELECT_CLKCTRL_LOCK  = 11,
  SI32_LOCK_A_SELECT_VMON_LOCK     = 12,
  SI32_LOCK_A_SELECT_IDAC_LOCK     = 13,
  SI32_LOCK_A_SELECT_DMACTRL_LOCK  = 14,
  SI32_LOCK_A_SELECT_DMAXBAR_LOCK  = 15,
  SI32_LOCK_A_SELECT_LPT_LOCK      = 16,
  SI32_LOCK_A_SELECT_LDO_LOCK      = 17,
  SI32_LOCK_A_SELECT_PLL_LOCK      = 18,
  SI32_LOCK_A_SELECT_EXTOSC_LOCK   = 19,
  SI32_LOCK_A_SELECT_PVT_LOCK      = 20,
  SI32_LOCK_A_SELECT_LPOSC_LOCK    = 21,
  SI32_LOCK_A_SELECT_ACCTR_LOCK    = 22,
  // Reserved 23-26
  SI32_LOCK_A_SELECT_PMU_LOCK      = 27,
  SI32_LOCK_A_SELECT_DTM_LOCK      = 28,
  SI32_LOCK_A_SELECT_LCD_LOCK      = 29,
  SI32_LOCK_A_SELECT_DCDC_LOCK     = 30,
  // Reserved 31
  SI32_LOCK_A_SELECT_ENCDEC_LOCK   = 32,
} SI32_LOCK_A_Enum_Type;

//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __SI32_LOCK_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
