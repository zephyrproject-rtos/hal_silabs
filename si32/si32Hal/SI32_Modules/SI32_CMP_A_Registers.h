//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
//
// Script: 0.61
// Version: 1

#ifndef __SI32_CMP_A_REGISTERS_H__
#define __SI32_CMP_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_CMP_A_CONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 13;
         // Falling Edge Interrupt Flag
         volatile uint32_t CMPFI: 1;
         // Rising Edge Interrupt Flag
         volatile uint32_t CMPRI: 1;
                  uint32_t reserved1: 15;
         // Output State
         volatile uint32_t CMPOUT: 1;
         // Comparator Enable
         volatile uint32_t CMPEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CMP_A_CONTROL_CMPFI_MASK  0x00002000
#define SI32_CMP_A_CONTROL_CMPFI_SHIFT  13
// No comparator falling edge has occurred since this flag was last cleared.
#define SI32_CMP_A_CONTROL_CMPFI_NOT_SET_VALUE  0
#define SI32_CMP_A_CONTROL_CMPFI_NOT_SET_U32 \
   (SI32_CMP_A_CONTROL_CMPFI_NOT_SET_VALUE << SI32_CMP_A_CONTROL_CMPFI_SHIFT)
// A comparator falling edge occurred since last flag was cleared.
#define SI32_CMP_A_CONTROL_CMPFI_SET_VALUE  1
#define SI32_CMP_A_CONTROL_CMPFI_SET_U32 \
   (SI32_CMP_A_CONTROL_CMPFI_SET_VALUE << SI32_CMP_A_CONTROL_CMPFI_SHIFT)

#define SI32_CMP_A_CONTROL_CMPRI_MASK  0x00004000
#define SI32_CMP_A_CONTROL_CMPRI_SHIFT  14
// No comparator rising edge has occurred since this flag was last cleared.
#define SI32_CMP_A_CONTROL_CMPRI_NOT_SET_VALUE  0
#define SI32_CMP_A_CONTROL_CMPRI_NOT_SET_U32 \
   (SI32_CMP_A_CONTROL_CMPRI_NOT_SET_VALUE << SI32_CMP_A_CONTROL_CMPRI_SHIFT)
// A comparator rising edge occurred since last flag was cleared.
#define SI32_CMP_A_CONTROL_CMPRI_SET_VALUE  1
#define SI32_CMP_A_CONTROL_CMPRI_SET_U32 \
   (SI32_CMP_A_CONTROL_CMPRI_SET_VALUE << SI32_CMP_A_CONTROL_CMPRI_SHIFT)

#define SI32_CMP_A_CONTROL_CMPOUT_MASK  0x40000000
#define SI32_CMP_A_CONTROL_CMPOUT_SHIFT  30
// Voltage on CMP+ < CMP- (INVEN = 0).
#define SI32_CMP_A_CONTROL_CMPOUT_POS_LT_NEG_VALUE  0
#define SI32_CMP_A_CONTROL_CMPOUT_POS_LT_NEG_U32 \
   (SI32_CMP_A_CONTROL_CMPOUT_POS_LT_NEG_VALUE << SI32_CMP_A_CONTROL_CMPOUT_SHIFT)
// Voltage on CMP+ > CMP- (INVEN = 0).
#define SI32_CMP_A_CONTROL_CMPOUT_POS_GT_NEG_VALUE  1
#define SI32_CMP_A_CONTROL_CMPOUT_POS_GT_NEG_U32 \
   (SI32_CMP_A_CONTROL_CMPOUT_POS_GT_NEG_VALUE << SI32_CMP_A_CONTROL_CMPOUT_SHIFT)

#define SI32_CMP_A_CONTROL_CMPEN_MASK  0x80000000
#define SI32_CMP_A_CONTROL_CMPEN_SHIFT  31
// Disable the comparator.
#define SI32_CMP_A_CONTROL_CMPEN_DISABLED_VALUE  0U
#define SI32_CMP_A_CONTROL_CMPEN_DISABLED_U32 \
   (SI32_CMP_A_CONTROL_CMPEN_DISABLED_VALUE << SI32_CMP_A_CONTROL_CMPEN_SHIFT)
// Enable the comparator.
#define SI32_CMP_A_CONTROL_CMPEN_ENABLED_VALUE  1U
#define SI32_CMP_A_CONTROL_CMPEN_ENABLED_U32 \
   (SI32_CMP_A_CONTROL_CMPEN_ENABLED_VALUE << SI32_CMP_A_CONTROL_CMPEN_SHIFT)



struct SI32_CMP_A_MODE_Struct
{
   union
   {
      struct
      {
         // Negative Input Select
         volatile uint32_t NMUX: 4;
         // Positive Input Select
         volatile uint32_t PMUX: 4;
         // Input MUX Select
         volatile uint32_t INMUX: 2;
         // Comparator Mode
         volatile uint32_t CMPMD: 2;
                  uint32_t reserved0: 1;
         // Falling Edge Interrupt Enable
         volatile uint32_t FIEN: 1;
         // Rising Edge Interrupt Enable
         volatile uint32_t RIEN: 1;
                  uint32_t reserved1: 1;
         // Comparator DAC Output Level
         volatile uint32_t DACLVL: 6;
         // Negative Input Weak Pullup Enable
         volatile uint32_t NWPUEN: 1;
         // Positive Input Weak Pullup Enable
         volatile uint32_t PWPUEN: 1;
         // Negative Hysteresis Control
         volatile uint32_t CMPHYN: 2;
         // Positive Hysteresis Control
         volatile uint32_t CMPHYP: 2;
                  uint32_t reserved2: 2;
         // Invert Comparator Output Enable
         volatile uint32_t INVEN: 1;
                  uint32_t reserved3: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CMP_A_MODE_NMUX_MASK  0x0000000F
#define SI32_CMP_A_MODE_NMUX_SHIFT  0
// Select CMPnN.0.
#define SI32_CMP_A_MODE_NMUX_CMPNN0_VALUE  0
#define SI32_CMP_A_MODE_NMUX_CMPNN0_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN0_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.1.
#define SI32_CMP_A_MODE_NMUX_CMPNN1_VALUE  1
#define SI32_CMP_A_MODE_NMUX_CMPNN1_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN1_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.2.
#define SI32_CMP_A_MODE_NMUX_CMPNN2_VALUE  2
#define SI32_CMP_A_MODE_NMUX_CMPNN2_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN2_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.3.
#define SI32_CMP_A_MODE_NMUX_CMPNN3_VALUE  3
#define SI32_CMP_A_MODE_NMUX_CMPNN3_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN3_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.4.
#define SI32_CMP_A_MODE_NMUX_CMPNN4_VALUE  4
#define SI32_CMP_A_MODE_NMUX_CMPNN4_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN4_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.5.
#define SI32_CMP_A_MODE_NMUX_CMPNN5_VALUE  5
#define SI32_CMP_A_MODE_NMUX_CMPNN5_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN5_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.6.
#define SI32_CMP_A_MODE_NMUX_CMPNN6_VALUE  6
#define SI32_CMP_A_MODE_NMUX_CMPNN6_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN6_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.7.
#define SI32_CMP_A_MODE_NMUX_CMPNN7_VALUE  7
#define SI32_CMP_A_MODE_NMUX_CMPNN7_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN7_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.8.
#define SI32_CMP_A_MODE_NMUX_CMPNN8_VALUE  8
#define SI32_CMP_A_MODE_NMUX_CMPNN8_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN8_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.9.
#define SI32_CMP_A_MODE_NMUX_CMPNN9_VALUE  9
#define SI32_CMP_A_MODE_NMUX_CMPNN9_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN9_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.10.
#define SI32_CMP_A_MODE_NMUX_CMPNN10_VALUE  10
#define SI32_CMP_A_MODE_NMUX_CMPNN10_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN10_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.11.
#define SI32_CMP_A_MODE_NMUX_CMPNN11_VALUE  11
#define SI32_CMP_A_MODE_NMUX_CMPNN11_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN11_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.12.
#define SI32_CMP_A_MODE_NMUX_CMPNN12_VALUE  12
#define SI32_CMP_A_MODE_NMUX_CMPNN12_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN12_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.13.
#define SI32_CMP_A_MODE_NMUX_CMPNN13_VALUE  13
#define SI32_CMP_A_MODE_NMUX_CMPNN13_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN13_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.14.
#define SI32_CMP_A_MODE_NMUX_CMPNN14_VALUE  14
#define SI32_CMP_A_MODE_NMUX_CMPNN14_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN14_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)
// Select CMPnN.15.
#define SI32_CMP_A_MODE_NMUX_CMPNN15_VALUE  15
#define SI32_CMP_A_MODE_NMUX_CMPNN15_U32 \
   (SI32_CMP_A_MODE_NMUX_CMPNN15_VALUE << SI32_CMP_A_MODE_NMUX_SHIFT)

#define SI32_CMP_A_MODE_PMUX_MASK  0x000000F0
#define SI32_CMP_A_MODE_PMUX_SHIFT  4
// Select CMPnP.0.
#define SI32_CMP_A_MODE_PMUX_CMPNP0_VALUE  0
#define SI32_CMP_A_MODE_PMUX_CMPNP0_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP0_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.1.
#define SI32_CMP_A_MODE_PMUX_CMPNP1_VALUE  1
#define SI32_CMP_A_MODE_PMUX_CMPNP1_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP1_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.2.
#define SI32_CMP_A_MODE_PMUX_CMPNP2_VALUE  2
#define SI32_CMP_A_MODE_PMUX_CMPNP2_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP2_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.3.
#define SI32_CMP_A_MODE_PMUX_CMPNP3_VALUE  3
#define SI32_CMP_A_MODE_PMUX_CMPNP3_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP3_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.4.
#define SI32_CMP_A_MODE_PMUX_CMPNP4_VALUE  4
#define SI32_CMP_A_MODE_PMUX_CMPNP4_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP4_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.5.
#define SI32_CMP_A_MODE_PMUX_CMPNP5_VALUE  5
#define SI32_CMP_A_MODE_PMUX_CMPNP5_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP5_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.6.
#define SI32_CMP_A_MODE_PMUX_CMPNP6_VALUE  6
#define SI32_CMP_A_MODE_PMUX_CMPNP6_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP6_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.7.
#define SI32_CMP_A_MODE_PMUX_CMPNP7_VALUE  7
#define SI32_CMP_A_MODE_PMUX_CMPNP7_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP7_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.8.
#define SI32_CMP_A_MODE_PMUX_CMPNP8_VALUE  8
#define SI32_CMP_A_MODE_PMUX_CMPNP8_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP8_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.9.
#define SI32_CMP_A_MODE_PMUX_CMPNP9_VALUE  9
#define SI32_CMP_A_MODE_PMUX_CMPNP9_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP9_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.10.
#define SI32_CMP_A_MODE_PMUX_CMPNP10_VALUE  10
#define SI32_CMP_A_MODE_PMUX_CMPNP10_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP10_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.11.
#define SI32_CMP_A_MODE_PMUX_CMPNP11_VALUE  11
#define SI32_CMP_A_MODE_PMUX_CMPNP11_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP11_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.12.
#define SI32_CMP_A_MODE_PMUX_CMPNP12_VALUE  12
#define SI32_CMP_A_MODE_PMUX_CMPNP12_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP12_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.13.
#define SI32_CMP_A_MODE_PMUX_CMPNP13_VALUE  13
#define SI32_CMP_A_MODE_PMUX_CMPNP13_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP13_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.14.
#define SI32_CMP_A_MODE_PMUX_CMPNP14_VALUE  14
#define SI32_CMP_A_MODE_PMUX_CMPNP14_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP14_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)
// Select CMPnP.15.
#define SI32_CMP_A_MODE_PMUX_CMPNP15_VALUE  15
#define SI32_CMP_A_MODE_PMUX_CMPNP15_U32 \
   (SI32_CMP_A_MODE_PMUX_CMPNP15_VALUE << SI32_CMP_A_MODE_PMUX_SHIFT)

#define SI32_CMP_A_MODE_INMUX_MASK  0x00000300
#define SI32_CMP_A_MODE_INMUX_SHIFT  8
// Connects the NMUX signal to CMP- and the PMUX signal to CMP+.
#define SI32_CMP_A_MODE_INMUX_DIRECT_VALUE  0
#define SI32_CMP_A_MODE_INMUX_DIRECT_U32 \
   (SI32_CMP_A_MODE_INMUX_DIRECT_VALUE << SI32_CMP_A_MODE_INMUX_SHIFT)
// Connects VSS to CMP- and the PMUX signal to CMP+.
#define SI32_CMP_A_MODE_INMUX_CMPP_VSS_VALUE  1
#define SI32_CMP_A_MODE_INMUX_CMPP_VSS_U32 \
   (SI32_CMP_A_MODE_INMUX_CMPP_VSS_VALUE << SI32_CMP_A_MODE_INMUX_SHIFT)
// Connects the NMUX signal to CMP-, the PMUX signal to the Comparator DAC voltage
// reference, and the DAC output to CMP+.
#define SI32_CMP_A_MODE_INMUX_CMPP_DAC_VALUE  2
#define SI32_CMP_A_MODE_INMUX_CMPP_DAC_U32 \
   (SI32_CMP_A_MODE_INMUX_CMPP_DAC_VALUE << SI32_CMP_A_MODE_INMUX_SHIFT)
// Connects the PMUX signal to CMP+, the NMUX signal to the Comparator DAC voltage
// reference, and the DAC output to CMP-.
#define SI32_CMP_A_MODE_INMUX_CMPN_DAC_VALUE  3
#define SI32_CMP_A_MODE_INMUX_CMPN_DAC_U32 \
   (SI32_CMP_A_MODE_INMUX_CMPN_DAC_VALUE << SI32_CMP_A_MODE_INMUX_SHIFT)

#define SI32_CMP_A_MODE_CMPMD_MASK  0x00000C00
#define SI32_CMP_A_MODE_CMPMD_SHIFT  10
// Mode 0 (fastest response time, highest power consumption).
#define SI32_CMP_A_MODE_CMPMD_MODE0_VALUE  0
#define SI32_CMP_A_MODE_CMPMD_MODE0_U32 \
   (SI32_CMP_A_MODE_CMPMD_MODE0_VALUE << SI32_CMP_A_MODE_CMPMD_SHIFT)
// Mode 1.
#define SI32_CMP_A_MODE_CMPMD_MODE1_VALUE  1
#define SI32_CMP_A_MODE_CMPMD_MODE1_U32 \
   (SI32_CMP_A_MODE_CMPMD_MODE1_VALUE << SI32_CMP_A_MODE_CMPMD_SHIFT)
// Mode 2.
#define SI32_CMP_A_MODE_CMPMD_MODE2_VALUE  2
#define SI32_CMP_A_MODE_CMPMD_MODE2_U32 \
   (SI32_CMP_A_MODE_CMPMD_MODE2_VALUE << SI32_CMP_A_MODE_CMPMD_SHIFT)
// Mode 3 (slowest response time, lowest power consumption).
#define SI32_CMP_A_MODE_CMPMD_MODE3_VALUE  3
#define SI32_CMP_A_MODE_CMPMD_MODE3_U32 \
   (SI32_CMP_A_MODE_CMPMD_MODE3_VALUE << SI32_CMP_A_MODE_CMPMD_SHIFT)

#define SI32_CMP_A_MODE_FIEN_MASK  0x00002000
#define SI32_CMP_A_MODE_FIEN_SHIFT  13
// Disable the comparator falling edge interrupt.
#define SI32_CMP_A_MODE_FIEN_DISABLED_VALUE  0
#define SI32_CMP_A_MODE_FIEN_DISABLED_U32 \
   (SI32_CMP_A_MODE_FIEN_DISABLED_VALUE << SI32_CMP_A_MODE_FIEN_SHIFT)
// Enable the comparator falling edge interrupt.
#define SI32_CMP_A_MODE_FIEN_ENABLED_VALUE  1
#define SI32_CMP_A_MODE_FIEN_ENABLED_U32 \
   (SI32_CMP_A_MODE_FIEN_ENABLED_VALUE << SI32_CMP_A_MODE_FIEN_SHIFT)

#define SI32_CMP_A_MODE_RIEN_MASK  0x00004000
#define SI32_CMP_A_MODE_RIEN_SHIFT  14
// Disable the comparator rising edge interrupt.
#define SI32_CMP_A_MODE_RIEN_DISABLED_VALUE  0
#define SI32_CMP_A_MODE_RIEN_DISABLED_U32 \
   (SI32_CMP_A_MODE_RIEN_DISABLED_VALUE << SI32_CMP_A_MODE_RIEN_SHIFT)
// Enable the comparator rising edge interrupt.
#define SI32_CMP_A_MODE_RIEN_ENABLED_VALUE  1
#define SI32_CMP_A_MODE_RIEN_ENABLED_U32 \
   (SI32_CMP_A_MODE_RIEN_ENABLED_VALUE << SI32_CMP_A_MODE_RIEN_SHIFT)

#define SI32_CMP_A_MODE_DACLVL_MASK  0x003F0000
#define SI32_CMP_A_MODE_DACLVL_SHIFT  16

#define SI32_CMP_A_MODE_NWPUEN_MASK  0x00400000
#define SI32_CMP_A_MODE_NWPUEN_SHIFT  22
// Disable the negative input weak pull up.
#define SI32_CMP_A_MODE_NWPUEN_DISABLED_VALUE  0
#define SI32_CMP_A_MODE_NWPUEN_DISABLED_U32 \
   (SI32_CMP_A_MODE_NWPUEN_DISABLED_VALUE << SI32_CMP_A_MODE_NWPUEN_SHIFT)
// Enable the negative input weak pull up.
#define SI32_CMP_A_MODE_NWPUEN_ENABLED_VALUE  1
#define SI32_CMP_A_MODE_NWPUEN_ENABLED_U32 \
   (SI32_CMP_A_MODE_NWPUEN_ENABLED_VALUE << SI32_CMP_A_MODE_NWPUEN_SHIFT)

#define SI32_CMP_A_MODE_PWPUEN_MASK  0x00800000
#define SI32_CMP_A_MODE_PWPUEN_SHIFT  23
// Disable the positive input weak pull up.
#define SI32_CMP_A_MODE_PWPUEN_DISABLED_VALUE  0
#define SI32_CMP_A_MODE_PWPUEN_DISABLED_U32 \
   (SI32_CMP_A_MODE_PWPUEN_DISABLED_VALUE << SI32_CMP_A_MODE_PWPUEN_SHIFT)
// Enable the positive input weak pull up.
#define SI32_CMP_A_MODE_PWPUEN_ENABLED_VALUE  1
#define SI32_CMP_A_MODE_PWPUEN_ENABLED_U32 \
   (SI32_CMP_A_MODE_PWPUEN_ENABLED_VALUE << SI32_CMP_A_MODE_PWPUEN_SHIFT)

#define SI32_CMP_A_MODE_CMPHYN_MASK  0x03000000
#define SI32_CMP_A_MODE_CMPHYN_SHIFT  24
// Disable negative hysteresis.
#define SI32_CMP_A_MODE_CMPHYN_DISABLED_VALUE  0
#define SI32_CMP_A_MODE_CMPHYN_DISABLED_U32 \
   (SI32_CMP_A_MODE_CMPHYN_DISABLED_VALUE << SI32_CMP_A_MODE_CMPHYN_SHIFT)
// Set negative hysteresis to 5 mV.
#define SI32_CMP_A_MODE_CMPHYN_NEG_5_MV_VALUE  1
#define SI32_CMP_A_MODE_CMPHYN_NEG_5_MV_U32 \
   (SI32_CMP_A_MODE_CMPHYN_NEG_5_MV_VALUE << SI32_CMP_A_MODE_CMPHYN_SHIFT)
// Set negative hysteresis to 10 mV.
#define SI32_CMP_A_MODE_CMPHYN_NEG_10_MV_VALUE  2
#define SI32_CMP_A_MODE_CMPHYN_NEG_10_MV_U32 \
   (SI32_CMP_A_MODE_CMPHYN_NEG_10_MV_VALUE << SI32_CMP_A_MODE_CMPHYN_SHIFT)
// Set negative hysteresis to 20 mV.
#define SI32_CMP_A_MODE_CMPHYN_NEG_20_MV_VALUE  3
#define SI32_CMP_A_MODE_CMPHYN_NEG_20_MV_U32 \
   (SI32_CMP_A_MODE_CMPHYN_NEG_20_MV_VALUE << SI32_CMP_A_MODE_CMPHYN_SHIFT)

#define SI32_CMP_A_MODE_CMPHYP_MASK  0x0C000000
#define SI32_CMP_A_MODE_CMPHYP_SHIFT  26
// Disable positive hysteresis.
#define SI32_CMP_A_MODE_CMPHYP_DISABLED_VALUE  0
#define SI32_CMP_A_MODE_CMPHYP_DISABLED_U32 \
   (SI32_CMP_A_MODE_CMPHYP_DISABLED_VALUE << SI32_CMP_A_MODE_CMPHYP_SHIFT)
// Set positive hysteresis to 5 mV.
#define SI32_CMP_A_MODE_CMPHYP_POS_5_MV_VALUE  1
#define SI32_CMP_A_MODE_CMPHYP_POS_5_MV_U32 \
   (SI32_CMP_A_MODE_CMPHYP_POS_5_MV_VALUE << SI32_CMP_A_MODE_CMPHYP_SHIFT)
// Set positive hysteresis to 10 mV.
#define SI32_CMP_A_MODE_CMPHYP_POS_10_MV_VALUE  2
#define SI32_CMP_A_MODE_CMPHYP_POS_10_MV_U32 \
   (SI32_CMP_A_MODE_CMPHYP_POS_10_MV_VALUE << SI32_CMP_A_MODE_CMPHYP_SHIFT)
// Set positive hysteresis to 20 mV.
#define SI32_CMP_A_MODE_CMPHYP_POS_20_MV_VALUE  3
#define SI32_CMP_A_MODE_CMPHYP_POS_20_MV_U32 \
   (SI32_CMP_A_MODE_CMPHYP_POS_20_MV_VALUE << SI32_CMP_A_MODE_CMPHYP_SHIFT)

#define SI32_CMP_A_MODE_INVEN_MASK  0x40000000
#define SI32_CMP_A_MODE_INVEN_SHIFT  30
// Do not invert the comparator output.
#define SI32_CMP_A_MODE_INVEN_DISABLED_VALUE  0
#define SI32_CMP_A_MODE_INVEN_DISABLED_U32 \
   (SI32_CMP_A_MODE_INVEN_DISABLED_VALUE << SI32_CMP_A_MODE_INVEN_SHIFT)
// Invert the comparator output.
#define SI32_CMP_A_MODE_INVEN_ENABLED_VALUE  1
#define SI32_CMP_A_MODE_INVEN_ENABLED_U32 \
   (SI32_CMP_A_MODE_INVEN_ENABLED_VALUE << SI32_CMP_A_MODE_INVEN_SHIFT)



typedef struct SI32_CMP_A_Struct
{
   struct SI32_CMP_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_CMP_A_MODE_Struct                   MODE           ; // Base Address + 0x10
   volatile uint32_t                               MODE_SET;
   volatile uint32_t                               MODE_CLR;
   uint32_t                                        reserved1;
} SI32_CMP_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_CMP_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

