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
// This file applies to the SIM3C1XX_LOCK_A module
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

#define SI32_LOCK_A_PERIPHLOCK0_ALL_LOCKS_MASK  0x17FFFFFF

//-----------------------------------------------------------------------------
// Define the LOCK Enum type

typedef enum SI32_LOCK_A_Enum
{
  SI32_LOCK_A_SELECT_USART_LOCK    = 0,
  SI32_LOCK_A_SELECT_SPI_LOCK      = 1,
  SI32_LOCK_A_SELECT_I2C_LOCK      = 2,
  SI32_LOCK_A_SELECT_PCA_LOCK      = 3,
  SI32_LOCK_A_SELECT_TIMER_LOCK    = 4,
  // Reserved 5
  SI32_LOCK_A_SELECT_SARADC_LOCK   = 6,
  SI32_LOCK_A_SELECT_SSG0_LOCK     = 7,
  SI32_LOCK_A_SELECT_CMP_LOCK      = 8,
  SI32_LOCK_A_SELECT_CS0_LOCK      = 9,
  SI32_LOCK_A_SELECT_EMIF_LOCK     = 10,
  SI32_LOCK_A_SELECT_AES0_LOCK     = 11,
  SI32_LOCK_A_SELECT_CRC0_LOCK     = 12,
  SI32_LOCK_A_SELECT_RTC0_LOCK     = 13,
  SI32_LOCK_A_SELECT_CLKRST_LOCK   = 14,
  SI32_LOCK_A_SELECT_VDDMON_LOCK   = 15,
  SI32_LOCK_A_SELECT_IDAC_LOCK     = 16,
  SI32_LOCK_A_SELECT_DMACTRL_LOCK  = 17,
  SI32_LOCK_A_SELECT_DMAXBAR_LOCK  = 18,
  SI32_LOCK_A_SELECT_LPT0_LOCK     = 19,
  SI32_LOCK_A_SELECT_VREF_LOCK     = 20,
  SI32_LOCK_A_SELECT_I2S0_LOCK     = 21,
  SI32_LOCK_A_SELECT_PLL_LOCK      = 22,
  SI32_LOCK_A_SELECT_EXTOSC_LOCK   = 23,
  SI32_LOCK_A_SELECT_VREG5_LOCK    = 24,
  SI32_LOCK_A_SELECT_LPOSC_LOCK    = 25,
  SI32_LOCK_A_SELECT_EXTREG_LOCK   = 26,
  // Reserved 27
  SI32_LOCK_A_SELECT_IVC0_LOCK     = 28,
  // Reserved 29-31

  SI32_LOCK_A_SELECT_PMU_LOCK      = 32
} SI32_LOCK_A_Enum_Type;

//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __SI32_LOCK_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
