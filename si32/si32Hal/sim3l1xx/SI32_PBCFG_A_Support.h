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
// This file applies to the SIM3L1XX_PBCFG_A module
//
// Version: 1

#ifndef __SI32_PBCFG_A_SUPPORT_H__
#define __SI32_PBCFG_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define crossbar0 masks

#define SI32_PBCFG_A_XBAR0_USART0EN            0x00000001
#define SI32_PBCFG_A_XBAR0_USART0FCEN          0x00000002
#define SI32_PBCFG_A_XBAR0_USART0CEN           0x00000004
#define SI32_PBCFG_A_XBAR0_DMATRIG0EN          0x00000008
#define SI32_PBCFG_A_XBAR0_DMATRIG1EN          0x00000010
#define SI32_PBCFG_A_XBAR0_IDAC0TRIGEN         0x00000020
#define SI32_PBCFG_A_XBAR0_SPI0EN              0x00000040
#define SI32_PBCFG_A_XBAR0_SPI0NSSEN           0x00000080
#define SI32_PBCFG_A_XBAR0_EECI0EN             0x00000800
#define SI32_PBCFG_A_XBAR0_I2C0EN              0x00001000
#define SI32_PBCFG_A_XBAR0_CMP0SEN             0x00002000
#define SI32_PBCFG_A_XBAR0_CMP0AEN             0x00004000
#define SI32_PBCFG_A_XBAR0_CMP1SEN             0x00008000
#define SI32_PBCFG_A_XBAR0_CMP1AEN             0x00010000
#define SI32_PBCFG_A_XBAR0_TMR0CTEN            0x00020000
#define SI32_PBCFG_A_XBAR0_TMR0EXEN            0x00040000
#define SI32_PBCFG_A_XBAR0_TMR1CTEN            0x00080000
#define SI32_PBCFG_A_XBAR0_TMR1EXEN            0x00100000
#define SI32_PBCFG_A_XBAR0_CNVSTREN            0x00200000
#define SI32_PBCFG_A_XBAR0_AHBEN               0x00400000
#define SI32_PBCFG_A_XBAR0_XBAR0EN             0x80000000

//-----------------------------------------------------------------------------
// Define crossbar0 signal parameter values

typedef enum SI32_PBCFG_A_XBAR0_Enum
{
    SI32_XBAR0_USART0       = 0x00,
    SI32_XBAR0_USART0FC     = 0x01,
    SI32_XBAR0_USART0C      = 0x02,
    SI32_XBAR0_DMATRIG0     = 0x03,
    SI32_XBAR0_DMATRIG1     = 0x04,
    SI32_XBAR0_IDAC0TRIG    = 0x05,
    SI32_XBAR0_SPI0         = 0x06,
    SI32_XBAR0_SPI0NSS      = 0x07,
    SI32_XBAR0_EECI0        = 0x0B,
    SI32_XBAR0_I2C0         = 0x0C,
    SI32_XBAR0_CMP0S        = 0x0D,
    SI32_XBAR0_CMP0A        = 0x0E,
    SI32_XBAR0_CMP1S        = 0x0F,
    SI32_XBAR0_CMP1A        = 0x10,
    SI32_XBAR0_TMR0CT       = 0x11,
    SI32_XBAR0_TMR0EX       = 0x12,
    SI32_XBAR0_TMR1CT       = 0x13,
    SI32_XBAR0_TMR1EX       = 0x14,
    SI32_XBAR0_CNVSTR       = 0x15,
    SI32_XBAR0_AHB          = 0x16,

    SI32_XBAR0_EPCA0_CEX0   = 0x81,
    SI32_XBAR0_EPCA0_CEX0_1 = 0x82,
    SI32_XBAR0_EPCA0_CEX0_2 = 0x83,
    SI32_XBAR0_EPCA0_CEX0_3 = 0x84,
    SI32_XBAR0_EPCA0_CEX0_4 = 0x85,
    SI32_XBAR0_EPCA0_CEX0_5 = 0x86
} 
SI32_PBCFG_A_XBAR0_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PBCFG_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
