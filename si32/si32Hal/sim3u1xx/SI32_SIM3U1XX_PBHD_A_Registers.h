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
// This file applies to the SIM3U1XX_PBHD_A module
//
// Script: 0.56
// Version: 1

#ifndef __SI32_PBHD_A_REGISTERS_H__
#define __SI32_PBHD_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_PBHD_A_PB_Struct
{
   union
   {
      struct
      {
         // Output Latch
         volatile uint32_t PB_BITS: 6;
                  uint32_t reserved0: 26;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PB_PB_MASK  0x0000003F
#define SI32_PBHD_A_PB_PB_SHIFT  0



struct SI32_PBHD_A_PBPIN_Struct
{
   union
   {
      struct
      {
         // Pin Value
         volatile uint32_t PBPIN_BITS: 6;
                  uint32_t reserved0: 26;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBPIN_PBPIN_MASK  0x0000003F
#define SI32_PBHD_A_PBPIN_PBPIN_SHIFT  0



struct SI32_PBHD_A_PBMDSEL_Struct
{
   union
   {
      struct
      {
         // Mode Select
         volatile uint32_t PBMDSEL_BITS: 6;
                  uint32_t reserved0: 26;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBMDSEL_PBMDSEL_MASK  0x0000003F
#define SI32_PBHD_A_PBMDSEL_PBMDSEL_SHIFT  0



struct SI32_PBHD_A_PBDEN_Struct
{
   union
   {
      struct
      {
         // Port Bank N-Channel Driver Enable
         volatile uint32_t PBNDEN: 6;
                  uint32_t reserved0: 10;
         // Port Bank P-Channel Driver Enable
         volatile uint32_t PBPDEN: 6;
                  uint32_t reserved1: 10;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBDEN_PBNDEN_MASK  0x0000003F
#define SI32_PBHD_A_PBDEN_PBNDEN_SHIFT  0

#define SI32_PBHD_A_PBDEN_PBPDEN_MASK  0x003F0000
#define SI32_PBHD_A_PBDEN_PBPDEN_SHIFT  16



struct SI32_PBHD_A_PBDRV_Struct
{
   union
   {
      struct
      {
         // Drive Strength
         volatile uint32_t PBDRV_BITS: 6;
                  uint32_t reserved0: 10;
         // Port Bank Weak Pull-up Enable
         volatile uint32_t PBPUEN: 1;
         // Port Low Voltage Mode
         volatile uint32_t PBLVMD: 1;
         // Port Slew Control
         volatile uint32_t PBSLEW: 2;
                  uint32_t reserved1: 1;
         // Port Bias Enable
         volatile uint32_t PBBIASEN: 1;
         // Port Drive Enable
         volatile uint32_t PBDRVEN: 1;
         // Port Voltage Supply Tracking Enable
         volatile uint32_t PBVTRKEN: 1;
                  uint32_t reserved2: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBDRV_PBDRV_MASK  0x0000003F
#define SI32_PBHD_A_PBDRV_PBDRV_SHIFT  0

#define SI32_PBHD_A_PBDRV_PBPUEN_MASK  0x00010000
#define SI32_PBHD_A_PBDRV_PBPUEN_SHIFT  16
// Disable weak pull-ups for this port.
#define SI32_PBHD_A_PBDRV_PBPUEN_DISABLED_VALUE  0
#define SI32_PBHD_A_PBDRV_PBPUEN_DISABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBPUEN_DISABLED_VALUE << SI32_PBHD_A_PBDRV_PBPUEN_SHIFT)
// Enable weak pull-ups for this port.
#define SI32_PBHD_A_PBDRV_PBPUEN_ENABLED_VALUE  1
#define SI32_PBHD_A_PBDRV_PBPUEN_ENABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBPUEN_ENABLED_VALUE << SI32_PBHD_A_PBDRV_PBPUEN_SHIFT)

#define SI32_PBHD_A_PBDRV_PBLVMD_MASK  0x00020000
#define SI32_PBHD_A_PBDRV_PBLVMD_SHIFT  17
// Port configured for normal mode.
#define SI32_PBHD_A_PBDRV_PBLVMD_NORMAL_VALUE  0
#define SI32_PBHD_A_PBDRV_PBLVMD_NORMAL_U32 \
   (SI32_PBHD_A_PBDRV_PBLVMD_NORMAL_VALUE << SI32_PBHD_A_PBDRV_PBLVMD_SHIFT)
// Port configured for low power mode.
#define SI32_PBHD_A_PBDRV_PBLVMD_LOW_VALUE  1
#define SI32_PBHD_A_PBDRV_PBLVMD_LOW_U32 \
   (SI32_PBHD_A_PBDRV_PBLVMD_LOW_VALUE << SI32_PBHD_A_PBDRV_PBLVMD_SHIFT)

#define SI32_PBHD_A_PBDRV_PBSLEW_MASK  0x000C0000
#define SI32_PBHD_A_PBDRV_PBSLEW_SHIFT  18
// Select the fastest transition speed for this port bank.
#define SI32_PBHD_A_PBDRV_PBSLEW_FASTEST_VALUE  0
#define SI32_PBHD_A_PBDRV_PBSLEW_FASTEST_U32 \
   (SI32_PBHD_A_PBDRV_PBSLEW_FASTEST_VALUE << SI32_PBHD_A_PBDRV_PBSLEW_SHIFT)
// Select the faster transition speed for this port bank.
#define SI32_PBHD_A_PBDRV_PBSLEW_FASTER_VALUE  1
#define SI32_PBHD_A_PBDRV_PBSLEW_FASTER_U32 \
   (SI32_PBHD_A_PBDRV_PBSLEW_FASTER_VALUE << SI32_PBHD_A_PBDRV_PBSLEW_SHIFT)
// Select the slower transition speed for this port bank.
#define SI32_PBHD_A_PBDRV_PBSLEW_SLOWER_VALUE  2
#define SI32_PBHD_A_PBDRV_PBSLEW_SLOWER_U32 \
   (SI32_PBHD_A_PBDRV_PBSLEW_SLOWER_VALUE << SI32_PBHD_A_PBDRV_PBSLEW_SHIFT)
// Select the slowest transition speed for this port bank.
#define SI32_PBHD_A_PBDRV_PBSLEW_SLOWEST_VALUE  3
#define SI32_PBHD_A_PBDRV_PBSLEW_SLOWEST_U32 \
   (SI32_PBHD_A_PBDRV_PBSLEW_SLOWEST_VALUE << SI32_PBHD_A_PBDRV_PBSLEW_SHIFT)

#define SI32_PBHD_A_PBDRV_PBBIASEN_MASK  0x00200000
#define SI32_PBHD_A_PBDRV_PBBIASEN_SHIFT  21
// Disable the biasing to the port pins.
#define SI32_PBHD_A_PBDRV_PBBIASEN_DISABLED_VALUE  0
#define SI32_PBHD_A_PBDRV_PBBIASEN_DISABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBBIASEN_DISABLED_VALUE << SI32_PBHD_A_PBDRV_PBBIASEN_SHIFT)
// Enable the biasing to the port pins.
#define SI32_PBHD_A_PBDRV_PBBIASEN_ENABLED_VALUE  1
#define SI32_PBHD_A_PBDRV_PBBIASEN_ENABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBBIASEN_ENABLED_VALUE << SI32_PBHD_A_PBDRV_PBBIASEN_SHIFT)

#define SI32_PBHD_A_PBDRV_PBDRVEN_MASK  0x00400000
#define SI32_PBHD_A_PBDRV_PBDRVEN_SHIFT  22
// Disable the port drivers.
#define SI32_PBHD_A_PBDRV_PBDRVEN_DISABLED_VALUE  0
#define SI32_PBHD_A_PBDRV_PBDRVEN_DISABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBDRVEN_DISABLED_VALUE << SI32_PBHD_A_PBDRV_PBDRVEN_SHIFT)
// Enable the port drivers.
#define SI32_PBHD_A_PBDRV_PBDRVEN_ENABLED_VALUE  1
#define SI32_PBHD_A_PBDRV_PBDRVEN_ENABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBDRVEN_ENABLED_VALUE << SI32_PBHD_A_PBDRV_PBDRVEN_SHIFT)

#define SI32_PBHD_A_PBDRV_PBVTRKEN_MASK  0x00800000
#define SI32_PBHD_A_PBDRV_PBVTRKEN_SHIFT  23
// Disable VIOHD tracking.
#define SI32_PBHD_A_PBDRV_PBVTRKEN_DISABLED_VALUE  0
#define SI32_PBHD_A_PBDRV_PBVTRKEN_DISABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBVTRKEN_DISABLED_VALUE << SI32_PBHD_A_PBDRV_PBVTRKEN_SHIFT)
// Enable VIOHD tracking.
#define SI32_PBHD_A_PBDRV_PBVTRKEN_ENABLED_VALUE  1
#define SI32_PBHD_A_PBDRV_PBVTRKEN_ENABLED_U32 \
   (SI32_PBHD_A_PBDRV_PBVTRKEN_ENABLED_VALUE << SI32_PBHD_A_PBDRV_PBVTRKEN_SHIFT)



struct SI32_PBHD_A_PBILIMIT_Struct
{
   union
   {
      struct
      {
         // Current Limit Enable
         volatile uint32_t PBILEN: 6;
                  uint32_t reserved0: 10;
         // N-Channel Current Limit
         volatile uint32_t NILIMIT: 4;
         // P-Channel Current Limit
         volatile uint32_t PILIMIT: 4;
                  uint32_t reserved1: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBILIMIT_PBILEN_MASK  0x0000003F
#define SI32_PBHD_A_PBILIMIT_PBILEN_SHIFT  0

#define SI32_PBHD_A_PBILIMIT_NILIMIT_MASK  0x000F0000
#define SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT  16
// Set sink limit to mode 0.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE0_VALUE  0
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE0_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE0_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 1.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE1_VALUE  1
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE1_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE1_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 2.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE2_VALUE  2
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE2_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE2_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 3.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE3_VALUE  3
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE3_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE3_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 4.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE4_VALUE  4
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE4_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE4_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 5.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE5_VALUE  5
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE5_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE5_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 6.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE6_VALUE  6
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE6_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE6_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 7.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE7_VALUE  7
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE7_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE7_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 8.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE8_VALUE  8
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE8_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE8_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 9.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE9_VALUE  9
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE9_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE9_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 10.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE10_VALUE  10
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE10_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE10_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 11.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE11_VALUE  11
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE11_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE11_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 12.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE12_VALUE  12
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE12_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE12_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 13.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE13_VALUE  13
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE13_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE13_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 14.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE14_VALUE  14
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE14_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE14_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)
// Set sink limit to mode 15.
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE15_VALUE  15
#define SI32_PBHD_A_PBILIMIT_NILIMIT_MODE15_U32 \
   (SI32_PBHD_A_PBILIMIT_NILIMIT_MODE15_VALUE << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT)

#define SI32_PBHD_A_PBILIMIT_PILIMIT_MASK  0x00F00000
#define SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT  20
// Set source limit to mode 0.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE0_VALUE  0
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE0_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE0_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 1.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE1_VALUE  1
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE1_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE1_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 2.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE2_VALUE  2
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE2_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE2_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 3.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE3_VALUE  3
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE3_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE3_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 4.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE4_VALUE  4
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE4_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE4_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 5.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE5_VALUE  5
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE5_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE5_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 6.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE6_VALUE  6
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE6_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE6_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 7.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE7_VALUE  7
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE7_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE7_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 8.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE8_VALUE  8
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE8_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE8_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 9.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE9_VALUE  9
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE9_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE9_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 10.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE10_VALUE  10
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE10_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE10_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 11.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE11_VALUE  11
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE11_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE11_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 12.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE12_VALUE  12
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE12_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE12_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 13.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE13_VALUE  13
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE13_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE13_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 14.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE14_VALUE  14
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE14_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE14_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)
// Set source limit to mode 15.
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE15_VALUE  15
#define SI32_PBHD_A_PBILIMIT_PILIMIT_MODE15_U32 \
   (SI32_PBHD_A_PBILIMIT_PILIMIT_MODE15_VALUE << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT)



struct SI32_PBHD_A_PBFSEL_Struct
{
   union
   {
      struct
      {
         // Port Bank n.0 Function Select
         volatile uint32_t PB0SEL: 2;
         // Port Bank n.1 Function Select
         volatile uint32_t PB1SEL: 2;
         // Port Bank n.2 Function Select
         volatile uint32_t PB2SEL: 2;
         // Port Bank n.3 Function Select
         volatile uint32_t PB3SEL: 2;
         // Port Bank n.4 Function Select
         volatile uint32_t PB4SEL: 2;
         // Port Bank n.5 Function Select
         volatile uint32_t PB5SEL: 3;
                  uint32_t reserved0: 19;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBFSEL_PB0SEL_MASK  0x00000003
#define SI32_PBHD_A_PBFSEL_PB0SEL_SHIFT  0
// Pin configured for GPIO.
#define SI32_PBHD_A_PBFSEL_PB0SEL_GPIO_VALUE  0
#define SI32_PBHD_A_PBFSEL_PB0SEL_GPIO_U32 \
   (SI32_PBHD_A_PBFSEL_PB0SEL_GPIO_VALUE << SI32_PBHD_A_PBFSEL_PB0SEL_SHIFT)
// Pin configured for Port Mapped Level Shift.
#define SI32_PBHD_A_PBFSEL_PB0SEL_PMLS_VALUE  1
#define SI32_PBHD_A_PBFSEL_PB0SEL_PMLS_U32 \
   (SI32_PBHD_A_PBFSEL_PB0SEL_PMLS_VALUE << SI32_PBHD_A_PBFSEL_PB0SEL_SHIFT)
// Pin configured for EPCA0 output.
#define SI32_PBHD_A_PBFSEL_PB0SEL_EPCA0_VALUE  2
#define SI32_PBHD_A_PBFSEL_PB0SEL_EPCA0_U32 \
   (SI32_PBHD_A_PBFSEL_PB0SEL_EPCA0_VALUE << SI32_PBHD_A_PBFSEL_PB0SEL_SHIFT)

#define SI32_PBHD_A_PBFSEL_PB1SEL_MASK  0x0000000C
#define SI32_PBHD_A_PBFSEL_PB1SEL_SHIFT  2
// Pin configured for GPIO.
#define SI32_PBHD_A_PBFSEL_PB1SEL_GPIO_VALUE  0
#define SI32_PBHD_A_PBFSEL_PB1SEL_GPIO_U32 \
   (SI32_PBHD_A_PBFSEL_PB1SEL_GPIO_VALUE << SI32_PBHD_A_PBFSEL_PB1SEL_SHIFT)
// Pin configured for Port Mapped Level Shift.
#define SI32_PBHD_A_PBFSEL_PB1SEL_PMLS_VALUE  1
#define SI32_PBHD_A_PBFSEL_PB1SEL_PMLS_U32 \
   (SI32_PBHD_A_PBFSEL_PB1SEL_PMLS_VALUE << SI32_PBHD_A_PBFSEL_PB1SEL_SHIFT)
// Pin configured for EPCA0 output.
#define SI32_PBHD_A_PBFSEL_PB1SEL_EPCA0_VALUE  2
#define SI32_PBHD_A_PBFSEL_PB1SEL_EPCA0_U32 \
   (SI32_PBHD_A_PBFSEL_PB1SEL_EPCA0_VALUE << SI32_PBHD_A_PBFSEL_PB1SEL_SHIFT)

#define SI32_PBHD_A_PBFSEL_PB2SEL_MASK  0x00000030
#define SI32_PBHD_A_PBFSEL_PB2SEL_SHIFT  4
// Pin configured for GPIO.
#define SI32_PBHD_A_PBFSEL_PB2SEL_GPIO_VALUE  0
#define SI32_PBHD_A_PBFSEL_PB2SEL_GPIO_U32 \
   (SI32_PBHD_A_PBFSEL_PB2SEL_GPIO_VALUE << SI32_PBHD_A_PBFSEL_PB2SEL_SHIFT)
// Pin configured for Port Mapped Level Shift.
#define SI32_PBHD_A_PBFSEL_PB2SEL_PMLS_VALUE  1
#define SI32_PBHD_A_PBFSEL_PB2SEL_PMLS_U32 \
   (SI32_PBHD_A_PBFSEL_PB2SEL_PMLS_VALUE << SI32_PBHD_A_PBFSEL_PB2SEL_SHIFT)
// Pin configured for EPCA0 output.
#define SI32_PBHD_A_PBFSEL_PB2SEL_EPCA0_VALUE  2
#define SI32_PBHD_A_PBFSEL_PB2SEL_EPCA0_U32 \
   (SI32_PBHD_A_PBFSEL_PB2SEL_EPCA0_VALUE << SI32_PBHD_A_PBFSEL_PB2SEL_SHIFT)
// Pin configured for UART1 TX.
#define SI32_PBHD_A_PBFSEL_PB2SEL_UART1_VALUE  3
#define SI32_PBHD_A_PBFSEL_PB2SEL_UART1_U32 \
   (SI32_PBHD_A_PBFSEL_PB2SEL_UART1_VALUE << SI32_PBHD_A_PBFSEL_PB2SEL_SHIFT)

#define SI32_PBHD_A_PBFSEL_PB3SEL_MASK  0x000000C0
#define SI32_PBHD_A_PBFSEL_PB3SEL_SHIFT  6
// Pin configured for GPIO.
#define SI32_PBHD_A_PBFSEL_PB3SEL_GPIO_VALUE  0
#define SI32_PBHD_A_PBFSEL_PB3SEL_GPIO_U32 \
   (SI32_PBHD_A_PBFSEL_PB3SEL_GPIO_VALUE << SI32_PBHD_A_PBFSEL_PB3SEL_SHIFT)
// Pin configured for Port Mapped Level Shift.
#define SI32_PBHD_A_PBFSEL_PB3SEL_PMLS_VALUE  1
#define SI32_PBHD_A_PBFSEL_PB3SEL_PMLS_U32 \
   (SI32_PBHD_A_PBFSEL_PB3SEL_PMLS_VALUE << SI32_PBHD_A_PBFSEL_PB3SEL_SHIFT)
// Pin configured for EPCA0 output.
#define SI32_PBHD_A_PBFSEL_PB3SEL_EPCA0_VALUE  2
#define SI32_PBHD_A_PBFSEL_PB3SEL_EPCA0_U32 \
   (SI32_PBHD_A_PBFSEL_PB3SEL_EPCA0_VALUE << SI32_PBHD_A_PBFSEL_PB3SEL_SHIFT)
// Pin configured for UART1 RX.
#define SI32_PBHD_A_PBFSEL_PB3SEL_UART1_VALUE  3
#define SI32_PBHD_A_PBFSEL_PB3SEL_UART1_U32 \
   (SI32_PBHD_A_PBFSEL_PB3SEL_UART1_VALUE << SI32_PBHD_A_PBFSEL_PB3SEL_SHIFT)

#define SI32_PBHD_A_PBFSEL_PB4SEL_MASK  0x00000300
#define SI32_PBHD_A_PBFSEL_PB4SEL_SHIFT  8
// Pin configured for GPIO.
#define SI32_PBHD_A_PBFSEL_PB4SEL_GPIO_VALUE  0
#define SI32_PBHD_A_PBFSEL_PB4SEL_GPIO_U32 \
   (SI32_PBHD_A_PBFSEL_PB4SEL_GPIO_VALUE << SI32_PBHD_A_PBFSEL_PB4SEL_SHIFT)
// Pin configured for Port Mapped Level Shift.
#define SI32_PBHD_A_PBFSEL_PB4SEL_PMLS_VALUE  1
#define SI32_PBHD_A_PBFSEL_PB4SEL_PMLS_U32 \
   (SI32_PBHD_A_PBFSEL_PB4SEL_PMLS_VALUE << SI32_PBHD_A_PBFSEL_PB4SEL_SHIFT)
// Pin configured for EPCA0 output.
#define SI32_PBHD_A_PBFSEL_PB4SEL_EPCA0_VALUE  2
#define SI32_PBHD_A_PBFSEL_PB4SEL_EPCA0_U32 \
   (SI32_PBHD_A_PBFSEL_PB4SEL_EPCA0_VALUE << SI32_PBHD_A_PBFSEL_PB4SEL_SHIFT)
// Pin configured for UART1 RTS.
#define SI32_PBHD_A_PBFSEL_PB4SEL_UART1_VALUE  3
#define SI32_PBHD_A_PBFSEL_PB4SEL_UART1_U32 \
   (SI32_PBHD_A_PBFSEL_PB4SEL_UART1_VALUE << SI32_PBHD_A_PBFSEL_PB4SEL_SHIFT)

#define SI32_PBHD_A_PBFSEL_PB5SEL_MASK  0x00001C00
#define SI32_PBHD_A_PBFSEL_PB5SEL_SHIFT  10
// Pin configured for GPIO.
#define SI32_PBHD_A_PBFSEL_PB5SEL_GPIO_VALUE  0
#define SI32_PBHD_A_PBFSEL_PB5SEL_GPIO_U32 \
   (SI32_PBHD_A_PBFSEL_PB5SEL_GPIO_VALUE << SI32_PBHD_A_PBFSEL_PB5SEL_SHIFT)
// Pin configured for Port Mapped Level Shift.
#define SI32_PBHD_A_PBFSEL_PB5SEL_PMLS_VALUE  1
#define SI32_PBHD_A_PBFSEL_PB5SEL_PMLS_U32 \
   (SI32_PBHD_A_PBFSEL_PB5SEL_PMLS_VALUE << SI32_PBHD_A_PBFSEL_PB5SEL_SHIFT)
// Pin configured for EPCA0 output.
#define SI32_PBHD_A_PBFSEL_PB5SEL_EPCA0_VALUE  2
#define SI32_PBHD_A_PBFSEL_PB5SEL_EPCA0_U32 \
   (SI32_PBHD_A_PBFSEL_PB5SEL_EPCA0_VALUE << SI32_PBHD_A_PBFSEL_PB5SEL_SHIFT)
// Pin configured for UART1 CTS.
#define SI32_PBHD_A_PBFSEL_PB5SEL_UART1_VALUE  3
#define SI32_PBHD_A_PBFSEL_PB5SEL_UART1_U32 \
   (SI32_PBHD_A_PBFSEL_PB5SEL_UART1_VALUE << SI32_PBHD_A_PBFSEL_PB5SEL_SHIFT)
// Pin configured for LPTIMER0 toggle output.
#define SI32_PBHD_A_PBFSEL_PB5SEL_LPTIMER0_VALUE  4
#define SI32_PBHD_A_PBFSEL_PB5SEL_LPTIMER0_U32 \
   (SI32_PBHD_A_PBFSEL_PB5SEL_LPTIMER0_VALUE << SI32_PBHD_A_PBFSEL_PB5SEL_SHIFT)



struct SI32_PBHD_A_PBSS_Struct
{
   union
   {
      struct
      {
         // Port Bank n.0 Safe State Select
         volatile uint32_t PB0SSSEL: 2;
         // Port Bank n.1 Safe State Select
         volatile uint32_t PB1SSSEL: 2;
         // Port Bank n.2 Safe State Select
         volatile uint32_t PB2SSSEL: 2;
         // Port Bank n.3 Safe State Select
         volatile uint32_t PB3SSSEL: 2;
         // Port Bank n.4 Safe State Select
         volatile uint32_t PB4SSSEL: 2;
         // Port Bank n.5 Safe State Select
         volatile uint32_t PB5SSSEL: 2;
                  uint32_t reserved0: 4;
         // Enter Safe State Mode
         volatile uint32_t SSMDEN: 1;
         // Safe State Signal Mode
         volatile uint32_t PBSSSMD: 1;
                  uint32_t reserved1: 14;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBSS_PB0SSSEL_MASK  0x00000003
#define SI32_PBHD_A_PBSS_PB0SSSEL_SHIFT  0
// Place PBn.0 in a High Impedance state.
#define SI32_PBHD_A_PBSS_PB0SSSEL_HIZ_VALUE  0
#define SI32_PBHD_A_PBSS_PB0SSSEL_HIZ_U32 \
   (SI32_PBHD_A_PBSS_PB0SSSEL_HIZ_VALUE << SI32_PBHD_A_PBSS_PB0SSSEL_SHIFT)
// Drive PBn.0 High.
#define SI32_PBHD_A_PBSS_PB0SSSEL_HIGH_VALUE  1
#define SI32_PBHD_A_PBSS_PB0SSSEL_HIGH_U32 \
   (SI32_PBHD_A_PBSS_PB0SSSEL_HIGH_VALUE << SI32_PBHD_A_PBSS_PB0SSSEL_SHIFT)
// Drive PBn.0 Low.
#define SI32_PBHD_A_PBSS_PB0SSSEL_LOW_VALUE  2
#define SI32_PBHD_A_PBSS_PB0SSSEL_LOW_U32 \
   (SI32_PBHD_A_PBSS_PB0SSSEL_LOW_VALUE << SI32_PBHD_A_PBSS_PB0SSSEL_SHIFT)
// Ignore the safe state signal (weak pull-ups disabled).
#define SI32_PBHD_A_PBSS_PB0SSSEL_DISABLED_VALUE  3
#define SI32_PBHD_A_PBSS_PB0SSSEL_DISABLED_U32 \
   (SI32_PBHD_A_PBSS_PB0SSSEL_DISABLED_VALUE << SI32_PBHD_A_PBSS_PB0SSSEL_SHIFT)

#define SI32_PBHD_A_PBSS_PB1SSSEL_MASK  0x0000000C
#define SI32_PBHD_A_PBSS_PB1SSSEL_SHIFT  2
// Place PBn.1 in a High Impedance state.
#define SI32_PBHD_A_PBSS_PB1SSSEL_HIZ_VALUE  0
#define SI32_PBHD_A_PBSS_PB1SSSEL_HIZ_U32 \
   (SI32_PBHD_A_PBSS_PB1SSSEL_HIZ_VALUE << SI32_PBHD_A_PBSS_PB1SSSEL_SHIFT)
// Drive PBn.1 High.
#define SI32_PBHD_A_PBSS_PB1SSSEL_HIGH_VALUE  1
#define SI32_PBHD_A_PBSS_PB1SSSEL_HIGH_U32 \
   (SI32_PBHD_A_PBSS_PB1SSSEL_HIGH_VALUE << SI32_PBHD_A_PBSS_PB1SSSEL_SHIFT)
// Drive PBn.1 Low.
#define SI32_PBHD_A_PBSS_PB1SSSEL_LOW_VALUE  2
#define SI32_PBHD_A_PBSS_PB1SSSEL_LOW_U32 \
   (SI32_PBHD_A_PBSS_PB1SSSEL_LOW_VALUE << SI32_PBHD_A_PBSS_PB1SSSEL_SHIFT)
// Ignore the safe state signal (weak pull-ups disabled).
#define SI32_PBHD_A_PBSS_PB1SSSEL_DISABLED_VALUE  3
#define SI32_PBHD_A_PBSS_PB1SSSEL_DISABLED_U32 \
   (SI32_PBHD_A_PBSS_PB1SSSEL_DISABLED_VALUE << SI32_PBHD_A_PBSS_PB1SSSEL_SHIFT)

#define SI32_PBHD_A_PBSS_PB2SSSEL_MASK  0x00000030
#define SI32_PBHD_A_PBSS_PB2SSSEL_SHIFT  4
// Place PBn.2 in a High Impedance state.
#define SI32_PBHD_A_PBSS_PB2SSSEL_HIZ_VALUE  0
#define SI32_PBHD_A_PBSS_PB2SSSEL_HIZ_U32 \
   (SI32_PBHD_A_PBSS_PB2SSSEL_HIZ_VALUE << SI32_PBHD_A_PBSS_PB2SSSEL_SHIFT)
// Drive PBn.2 High.
#define SI32_PBHD_A_PBSS_PB2SSSEL_HIGH_VALUE  1
#define SI32_PBHD_A_PBSS_PB2SSSEL_HIGH_U32 \
   (SI32_PBHD_A_PBSS_PB2SSSEL_HIGH_VALUE << SI32_PBHD_A_PBSS_PB2SSSEL_SHIFT)
// Drive PBn.2 Low.
#define SI32_PBHD_A_PBSS_PB2SSSEL_LOW_VALUE  2
#define SI32_PBHD_A_PBSS_PB2SSSEL_LOW_U32 \
   (SI32_PBHD_A_PBSS_PB2SSSEL_LOW_VALUE << SI32_PBHD_A_PBSS_PB2SSSEL_SHIFT)
// Ignore the safe state signal (weak pull-ups disabled).
#define SI32_PBHD_A_PBSS_PB2SSSEL_DISABLED_VALUE  3
#define SI32_PBHD_A_PBSS_PB2SSSEL_DISABLED_U32 \
   (SI32_PBHD_A_PBSS_PB2SSSEL_DISABLED_VALUE << SI32_PBHD_A_PBSS_PB2SSSEL_SHIFT)

#define SI32_PBHD_A_PBSS_PB3SSSEL_MASK  0x000000C0
#define SI32_PBHD_A_PBSS_PB3SSSEL_SHIFT  6
// Place PBn.3 in a High Impedance state.
#define SI32_PBHD_A_PBSS_PB3SSSEL_HIZ_VALUE  0
#define SI32_PBHD_A_PBSS_PB3SSSEL_HIZ_U32 \
   (SI32_PBHD_A_PBSS_PB3SSSEL_HIZ_VALUE << SI32_PBHD_A_PBSS_PB3SSSEL_SHIFT)
// Drive PBn.3 High.
#define SI32_PBHD_A_PBSS_PB3SSSEL_HIGH_VALUE  1
#define SI32_PBHD_A_PBSS_PB3SSSEL_HIGH_U32 \
   (SI32_PBHD_A_PBSS_PB3SSSEL_HIGH_VALUE << SI32_PBHD_A_PBSS_PB3SSSEL_SHIFT)
// Drive PBn.3 Low.
#define SI32_PBHD_A_PBSS_PB3SSSEL_LOW_VALUE  2
#define SI32_PBHD_A_PBSS_PB3SSSEL_LOW_U32 \
   (SI32_PBHD_A_PBSS_PB3SSSEL_LOW_VALUE << SI32_PBHD_A_PBSS_PB3SSSEL_SHIFT)
// Ignore the safe state signal (weak pull-ups disabled).
#define SI32_PBHD_A_PBSS_PB3SSSEL_DISABLED_VALUE  3
#define SI32_PBHD_A_PBSS_PB3SSSEL_DISABLED_U32 \
   (SI32_PBHD_A_PBSS_PB3SSSEL_DISABLED_VALUE << SI32_PBHD_A_PBSS_PB3SSSEL_SHIFT)

#define SI32_PBHD_A_PBSS_PB4SSSEL_MASK  0x00000300
#define SI32_PBHD_A_PBSS_PB4SSSEL_SHIFT  8
// Place PBn.4 in a High Impedance state.
#define SI32_PBHD_A_PBSS_PB4SSSEL_HIZ_VALUE  0
#define SI32_PBHD_A_PBSS_PB4SSSEL_HIZ_U32 \
   (SI32_PBHD_A_PBSS_PB4SSSEL_HIZ_VALUE << SI32_PBHD_A_PBSS_PB4SSSEL_SHIFT)
// Drive PBn.4 High.
#define SI32_PBHD_A_PBSS_PB4SSSEL_HIGH_VALUE  1
#define SI32_PBHD_A_PBSS_PB4SSSEL_HIGH_U32 \
   (SI32_PBHD_A_PBSS_PB4SSSEL_HIGH_VALUE << SI32_PBHD_A_PBSS_PB4SSSEL_SHIFT)
// Drive PBn.4 Low.
#define SI32_PBHD_A_PBSS_PB4SSSEL_LOW_VALUE  2
#define SI32_PBHD_A_PBSS_PB4SSSEL_LOW_U32 \
   (SI32_PBHD_A_PBSS_PB4SSSEL_LOW_VALUE << SI32_PBHD_A_PBSS_PB4SSSEL_SHIFT)
// Ignore the safe state signal (weak pull-ups disabled).
#define SI32_PBHD_A_PBSS_PB4SSSEL_DISABLED_VALUE  3
#define SI32_PBHD_A_PBSS_PB4SSSEL_DISABLED_U32 \
   (SI32_PBHD_A_PBSS_PB4SSSEL_DISABLED_VALUE << SI32_PBHD_A_PBSS_PB4SSSEL_SHIFT)

#define SI32_PBHD_A_PBSS_PB5SSSEL_MASK  0x00000C00
#define SI32_PBHD_A_PBSS_PB5SSSEL_SHIFT  10
// Place PBn.5 in a High Impedance state.
#define SI32_PBHD_A_PBSS_PB5SSSEL_HIZ_VALUE  0
#define SI32_PBHD_A_PBSS_PB5SSSEL_HIZ_U32 \
   (SI32_PBHD_A_PBSS_PB5SSSEL_HIZ_VALUE << SI32_PBHD_A_PBSS_PB5SSSEL_SHIFT)
// Drive PBn.5 High.
#define SI32_PBHD_A_PBSS_PB5SSSEL_HIGH_VALUE  1
#define SI32_PBHD_A_PBSS_PB5SSSEL_HIGH_U32 \
   (SI32_PBHD_A_PBSS_PB5SSSEL_HIGH_VALUE << SI32_PBHD_A_PBSS_PB5SSSEL_SHIFT)
// Drive PBn.5 Low.
#define SI32_PBHD_A_PBSS_PB5SSSEL_LOW_VALUE  2
#define SI32_PBHD_A_PBSS_PB5SSSEL_LOW_U32 \
   (SI32_PBHD_A_PBSS_PB5SSSEL_LOW_VALUE << SI32_PBHD_A_PBSS_PB5SSSEL_SHIFT)
// Ignore the safe state signal (weak pull-ups disabled).
#define SI32_PBHD_A_PBSS_PB5SSSEL_DISABLED_VALUE  3
#define SI32_PBHD_A_PBSS_PB5SSSEL_DISABLED_U32 \
   (SI32_PBHD_A_PBSS_PB5SSSEL_DISABLED_VALUE << SI32_PBHD_A_PBSS_PB5SSSEL_SHIFT)

#define SI32_PBHD_A_PBSS_SSMDEN_MASK  0x00010000
#define SI32_PBHD_A_PBSS_SSMDEN_SHIFT  16
// Disable Safe State.
#define SI32_PBHD_A_PBSS_SSMDEN_DISABLED_VALUE  0
#define SI32_PBHD_A_PBSS_SSMDEN_DISABLED_U32 \
   (SI32_PBHD_A_PBSS_SSMDEN_DISABLED_VALUE << SI32_PBHD_A_PBSS_SSMDEN_SHIFT)
// Enter Safe State.  Each PBn.x pin will enter the states defined by PBxSSSEL.
#define SI32_PBHD_A_PBSS_SSMDEN_ENABLED_VALUE  1
#define SI32_PBHD_A_PBSS_SSMDEN_ENABLED_U32 \
   (SI32_PBHD_A_PBSS_SSMDEN_ENABLED_VALUE << SI32_PBHD_A_PBSS_SSMDEN_SHIFT)

#define SI32_PBHD_A_PBSS_PBSSSMD_MASK  0x00020000
#define SI32_PBHD_A_PBSS_PBSSSMD_SHIFT  17
// Enable deglitching on the kill signal input. The kill signal must be asserted
// for two APB clocks to be recognized.
#define SI32_PBHD_A_PBSS_PBSSSMD_DEGLITCH_VALUE  0
#define SI32_PBHD_A_PBSS_PBSSSMD_DEGLITCH_U32 \
   (SI32_PBHD_A_PBSS_PBSSSMD_DEGLITCH_VALUE << SI32_PBHD_A_PBSS_PBSSSMD_SHIFT)
// Disable deglitching on the kill signal input.  The kill signal will take
// immediate effect.
#define SI32_PBHD_A_PBSS_PBSSSMD_IMMEDIATE_VALUE  1
#define SI32_PBHD_A_PBSS_PBSSSMD_IMMEDIATE_U32 \
   (SI32_PBHD_A_PBSS_PBSSSMD_IMMEDIATE_VALUE << SI32_PBHD_A_PBSS_PBSSSMD_SHIFT)



struct SI32_PBHD_A_PBLOCK_Struct
{
   union
   {
      struct
      {
         // Port Bank Lock
         volatile uint32_t PBLOCK_BITS: 6;
                  uint32_t reserved0: 26;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBHD_A_PBLOCK_PBLOCK_MASK  0x0000003F
#define SI32_PBHD_A_PBLOCK_PBLOCK_SHIFT  0



typedef struct SI32_PBHD_A_Struct
{
   struct SI32_PBHD_A_PB_Struct                    PB             ; // Base Address + 0x0
   volatile uint32_t                               PB_SET;
   volatile uint32_t                               PB_CLR;
   volatile uint32_t                               PB_MSK;
   struct SI32_PBHD_A_PBPIN_Struct                 PBPIN          ; // Base Address + 0x10
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_PBHD_A_PBMDSEL_Struct               PBMDSEL        ; // Base Address + 0x20
   volatile uint32_t                               PBMDSEL_SET;
   volatile uint32_t                               PBMDSEL_CLR;
   uint32_t                                        reserved3;
   struct SI32_PBHD_A_PBDEN_Struct                 PBDEN          ; // Base Address + 0x30
   volatile uint32_t                               PBDEN_SET;
   volatile uint32_t                               PBDEN_CLR;
   uint32_t                                        reserved4;
   struct SI32_PBHD_A_PBDRV_Struct                 PBDRV          ; // Base Address + 0x40
   volatile uint32_t                               PBDRV_SET;
   volatile uint32_t                               PBDRV_CLR;
   uint32_t                                        reserved5;
   struct SI32_PBHD_A_PBILIMIT_Struct              PBILIMIT       ; // Base Address + 0x50
   volatile uint32_t                               PBILIMIT_SET;
   volatile uint32_t                               PBILIMIT_CLR;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7[4];
   struct SI32_PBHD_A_PBFSEL_Struct                PBFSEL         ; // Base Address + 0x70
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   struct SI32_PBHD_A_PBSS_Struct                  PBSS           ; // Base Address + 0x80
   volatile uint32_t                               PBSS_SET;
   volatile uint32_t                               PBSS_CLR;
   uint32_t                                        reserved11;
   struct SI32_PBHD_A_PBLOCK_Struct                PBLOCK         ; // Base Address + 0x90
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   uint32_t                                        reserved14;
} SI32_PBHD_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PBHD_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

