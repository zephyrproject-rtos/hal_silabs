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
// This file applies to the SIM3L1XX_CLKCTRL_A module
//
// Version: 1

#ifndef __SI32_CLKCTRL_A_SUPPORT_H__
#define __SI32_CLKCTRL_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Defines for APBCLKG0 and APBCLKG1 module masks

#define SI32_CLKCTRL_A_APBCLKG0_FLASHCTRL0   0x00000001
#define SI32_CLKCTRL_A_APBCLKG0_PB0          0x00000002
#define SI32_CLKCTRL_A_APBCLKG0_USART0       0x00000004
#define SI32_CLKCTRL_A_APBCLKG0_UART0        0x00000008
#define SI32_CLKCTRL_A_APBCLKG0_SPI0         0x00000010
#define SI32_CLKCTRL_A_APBCLKG0_SPI1         0x00000020
#define SI32_CLKCTRL_A_APBCLKG0_I2C0         0x00000040
#define SI32_CLKCTRL_A_APBCLKG0_EPCA0        0x00000080
#define SI32_CLKCTRL_A_APBCLKG0_TIMER0       0x00000100
#define SI32_CLKCTRL_A_APBCLKG0_TIMER1       0x00000200
#define SI32_CLKCTRL_A_APBCLKG0_TIMER2       0x00000400
#define SI32_CLKCTRL_A_APBCLKG0_SARADC0      0x00000800
#define SI32_CLKCTRL_A_APBCLKG0_CMP0         0x00001000
#define SI32_CLKCTRL_A_APBCLKG0_CMP1         0x00002000
#define SI32_CLKCTRL_A_APBCLKG0_AES0         0x00004000
#define SI32_CLKCTRL_A_APBCLKG0_CRC0         0x00008000
#define SI32_CLKCTRL_A_APBCLKG0_IDAC0        0x00010000
#define SI32_CLKCTRL_A_APBCLKG0_LPTIMER0     0x00020000
#define SI32_CLKCTRL_A_APBCLKG0_ACCTR0       0x00040000
#define SI32_CLKCTRL_A_APBCLKG0_DTM0         0x00080000
#define SI32_CLKCTRL_A_APBCLKG0_DTM1         0x00100000
#define SI32_CLKCTRL_A_APBCLKG0_DTM2         0x00200000
#define SI32_CLKCTRL_A_APBCLKG0_LCD0         0x00400000
#define SI32_CLKCTRL_A_APBCLKG0_DCDC0        0x00800000
#define SI32_CLKCTRL_A_APBCLKG0_ENCDEC0      0x01000000
#define SI32_CLKCTRL_A_APBCLKG0_PLL0         0x02000000

#define SI32_CLKCTRL_A_APBCLKG1_MISC0        0x00000001
#define SI32_CLKCTRL_A_APBCLKG1_MISC1        0x00000002

#ifdef __cplusplus
}
#endif

#endif // __SI32_CLKCTRL_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
