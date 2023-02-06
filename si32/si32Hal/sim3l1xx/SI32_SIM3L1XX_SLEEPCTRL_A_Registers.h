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
// This file applies to the SIM3L1XX_SLEEPCTRL_A module
//
// Script: 0.56
// Version: 1

#ifndef __SI32_SLEEPCTRL_A_REGISTERS_H__
#define __SI32_SLEEPCTRL_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_SLEEPCTRL_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // CLKDIV
         volatile uint32_t CLKDIV: 2;
         // CPMD
         volatile uint32_t CPMD: 2;
                  uint32_t reserved0: 28;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_MASK  0x00000003
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_SHIFT  0
// Undivided RTC clock
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV1_VALUE  0
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV1_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV1_VALUE << SI32_SLEEPCTRL_A_CONTROL_CLKDIV_SHIFT)
// RTC clock divided by 2
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV2_VALUE  1
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV2_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV2_VALUE << SI32_SLEEPCTRL_A_CONTROL_CLKDIV_SHIFT)
// RTC clock divided by 4
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV4_VALUE  2
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV4_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV4_VALUE << SI32_SLEEPCTRL_A_CONTROL_CLKDIV_SHIFT)
// RTC clock divided by 8
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV8_VALUE  3
#define SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV8_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CLKDIV_DIV8_VALUE << SI32_SLEEPCTRL_A_CONTROL_CLKDIV_SHIFT)

#define SI32_SLEEPCTRL_A_CONTROL_CPMD_MASK  0x0000000C
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_SHIFT  2
// VBAT is passed directly to VCP
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_VBAT_VALUE  0
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_VBAT_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CPMD_VBAT_VALUE << SI32_SLEEPCTRL_A_CONTROL_CPMD_SHIFT)
// VCP equals VBAT / 2
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_VBATDIV2_VALUE  1
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_VBATDIV2_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CPMD_VBATDIV2_VALUE << SI32_SLEEPCTRL_A_CONTROL_CPMD_SHIFT)
// VCP is tri-stated
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_TRISTATE_VALUE  2
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_TRISTATE_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CPMD_TRISTATE_VALUE << SI32_SLEEPCTRL_A_CONTROL_CPMD_SHIFT)
// VCP is connected to ground
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_GROUND_VALUE  3
#define SI32_SLEEPCTRL_A_CONTROL_CPMD_GROUND_U32 \
   (SI32_SLEEPCTRL_A_CONTROL_CPMD_GROUND_VALUE << SI32_SLEEPCTRL_A_CONTROL_CPMD_SHIFT)



typedef struct SI32_SLEEPCTRL_A_Struct
{
   uint32_t                                        reserved0[4];
   struct SI32_SLEEPCTRL_A_CONTROL_Struct          CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved1;
} SI32_SLEEPCTRL_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_SLEEPCTRL_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

