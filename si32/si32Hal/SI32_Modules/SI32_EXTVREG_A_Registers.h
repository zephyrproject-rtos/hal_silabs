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
// Script: 0.57
// Version: 1

#ifndef __SI32_EXTVREG_A_REGISTERS_H__
#define __SI32_EXTVREG_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_EXTVREG_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Stand-Alone Mode Enable
         volatile uint32_t SAEN: 1;
                  uint32_t reserved0: 23;
         // Weak Pull Up/Down Enable
         volatile uint32_t WPULLEN: 1;
         // Foldback Limiting Enable
         volatile uint32_t FBLEN: 1;
         // NPN/PNP Type Select
         volatile uint32_t PNSEL: 1;
         // Foldback Sensing Pin Select
         volatile uint32_t FBPINSEL: 1;
                  uint32_t reserved1: 3;
         // External Regulator Enable
         volatile uint32_t EVREGEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EXTVREG_A_CONTROL_SAEN_MASK  0x00000001
#define SI32_EXTVREG_A_CONTROL_SAEN_SHIFT  0
// Use the external regulator in normal mode.
#define SI32_EXTVREG_A_CONTROL_SAEN_DISABLED_VALUE  0
#define SI32_EXTVREG_A_CONTROL_SAEN_DISABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_SAEN_DISABLED_VALUE << SI32_EXTVREG_A_CONTROL_SAEN_SHIFT)
// Use the external regulator in stand-alone mode.
#define SI32_EXTVREG_A_CONTROL_SAEN_ENABLED_VALUE  1
#define SI32_EXTVREG_A_CONTROL_SAEN_ENABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_SAEN_ENABLED_VALUE << SI32_EXTVREG_A_CONTROL_SAEN_SHIFT)

#define SI32_EXTVREG_A_CONTROL_WPULLEN_MASK  0x01000000
#define SI32_EXTVREG_A_CONTROL_WPULLEN_SHIFT  24
// Disable the external regulator weak pull-up/down resistor on the EXREGBD pin and
// weak pull-down resistor on the EXREGOUT pin.
#define SI32_EXTVREG_A_CONTROL_WPULLEN_DISABLED_VALUE  0
#define SI32_EXTVREG_A_CONTROL_WPULLEN_DISABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_WPULLEN_DISABLED_VALUE << SI32_EXTVREG_A_CONTROL_WPULLEN_SHIFT)
// Enable the external regulator weak pull-up/down resistor on the EXREGBD pin and
// weak pull-down resistor on the EXREGOUT pin.
#define SI32_EXTVREG_A_CONTROL_WPULLEN_ENABLED_VALUE  1
#define SI32_EXTVREG_A_CONTROL_WPULLEN_ENABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_WPULLEN_ENABLED_VALUE << SI32_EXTVREG_A_CONTROL_WPULLEN_SHIFT)

#define SI32_EXTVREG_A_CONTROL_FBLEN_MASK  0x02000000
#define SI32_EXTVREG_A_CONTROL_FBLEN_SHIFT  25
// Disable foldback limiting.
#define SI32_EXTVREG_A_CONTROL_FBLEN_DISABLED_VALUE  0
#define SI32_EXTVREG_A_CONTROL_FBLEN_DISABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_FBLEN_DISABLED_VALUE << SI32_EXTVREG_A_CONTROL_FBLEN_SHIFT)
// Enable foldback limiting.
#define SI32_EXTVREG_A_CONTROL_FBLEN_ENABLED_VALUE  1
#define SI32_EXTVREG_A_CONTROL_FBLEN_ENABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_FBLEN_ENABLED_VALUE << SI32_EXTVREG_A_CONTROL_FBLEN_SHIFT)

#define SI32_EXTVREG_A_CONTROL_PNSEL_MASK  0x04000000
#define SI32_EXTVREG_A_CONTROL_PNSEL_SHIFT  26
// Select NPN Mode.
#define SI32_EXTVREG_A_CONTROL_PNSEL_NPN_VALUE  0
#define SI32_EXTVREG_A_CONTROL_PNSEL_NPN_U32 \
   (SI32_EXTVREG_A_CONTROL_PNSEL_NPN_VALUE << SI32_EXTVREG_A_CONTROL_PNSEL_SHIFT)
// Select PNP Mode.
#define SI32_EXTVREG_A_CONTROL_PNSEL_PNP_VALUE  1
#define SI32_EXTVREG_A_CONTROL_PNSEL_PNP_U32 \
   (SI32_EXTVREG_A_CONTROL_PNSEL_PNP_VALUE << SI32_EXTVREG_A_CONTROL_PNSEL_SHIFT)

#define SI32_EXTVREG_A_CONTROL_FBPINSEL_MASK  0x08000000
#define SI32_EXTVREG_A_CONTROL_FBPINSEL_SHIFT  27
// Use the input to the EXREGSN pin for foldback limiting.
#define SI32_EXTVREG_A_CONTROL_FBPINSEL_EXREGSN_VALUE  0
#define SI32_EXTVREG_A_CONTROL_FBPINSEL_EXREGSN_U32 \
   (SI32_EXTVREG_A_CONTROL_FBPINSEL_EXREGSN_VALUE << SI32_EXTVREG_A_CONTROL_FBPINSEL_SHIFT)
// Use the input to the VREGIN pin for foldback limiting.
#define SI32_EXTVREG_A_CONTROL_FBPINSEL_VREGIN_VALUE  1
#define SI32_EXTVREG_A_CONTROL_FBPINSEL_VREGIN_U32 \
   (SI32_EXTVREG_A_CONTROL_FBPINSEL_VREGIN_VALUE << SI32_EXTVREG_A_CONTROL_FBPINSEL_SHIFT)

#define SI32_EXTVREG_A_CONTROL_EVREGEN_MASK  0x80000000
#define SI32_EXTVREG_A_CONTROL_EVREGEN_SHIFT  31
// Disable the external regulator.
#define SI32_EXTVREG_A_CONTROL_EVREGEN_DISABLED_VALUE  0U
#define SI32_EXTVREG_A_CONTROL_EVREGEN_DISABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_EVREGEN_DISABLED_VALUE << SI32_EXTVREG_A_CONTROL_EVREGEN_SHIFT)
// Enable the external regulator.
#define SI32_EXTVREG_A_CONTROL_EVREGEN_ENABLED_VALUE  1U
#define SI32_EXTVREG_A_CONTROL_EVREGEN_ENABLED_U32 \
   (SI32_EXTVREG_A_CONTROL_EVREGEN_ENABLED_VALUE << SI32_EXTVREG_A_CONTROL_EVREGEN_SHIFT)



struct SI32_EXTVREG_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Minimum Current Fine Select
         volatile uint32_t IMINFINE: 2;
         // Minimum Current Select
         volatile uint32_t IMIN: 3;
                  uint32_t reserved0: 3;
         // Foldback Voltage Offset Select
         volatile uint32_t FBVOSEL: 3;
                  uint32_t reserved1: 1;
         // Voltage Sense Gain Multiplier
         volatile uint32_t FBRATE: 3;
                  uint32_t reserved2: 1;
         // Maximum Current Select
         volatile uint32_t IMAX: 3;
                  uint32_t reserved3: 5;
         // Regulator Output Voltage Select
         volatile uint32_t VOUTSEL: 6;
                  uint32_t reserved4: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EXTVREG_A_CONFIG_IMINFINE_MASK  0x00000003
#define SI32_EXTVREG_A_CONFIG_IMINFINE_SHIFT  0
// Minimum current limit is IMIN current + 0 uA.
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0_UA_VALUE  0
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMINFINE_0_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMINFINE_SHIFT)
// Minimum current limit is IMIN current + 0.25 uA.
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0P25_UA_VALUE  1
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0P25_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMINFINE_0P25_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMINFINE_SHIFT)
// Minimum current limit is IMIN current + 0.50 uA.
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0P5_UA_VALUE  2
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0P5_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMINFINE_0P5_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMINFINE_SHIFT)
// Minimum current limit is IMIN current + 0.75 uA.
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0P75_UA_VALUE  3
#define SI32_EXTVREG_A_CONFIG_IMINFINE_0P75_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMINFINE_0P75_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMINFINE_SHIFT)

#define SI32_EXTVREG_A_CONFIG_IMIN_MASK  0x0000001C
#define SI32_EXTVREG_A_CONFIG_IMIN_SHIFT  2
// Minimum current limit is 1 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_1_UA_VALUE  0
#define SI32_EXTVREG_A_CONFIG_IMIN_1_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_1_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)
// Minimum current limit is 2 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_2_UA_VALUE  1
#define SI32_EXTVREG_A_CONFIG_IMIN_2_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_2_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)
// Minimum current limit is 3 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_3_UA_VALUE  2
#define SI32_EXTVREG_A_CONFIG_IMIN_3_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_3_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)
// Minimum current limit is 4 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_4_UA_VALUE  3
#define SI32_EXTVREG_A_CONFIG_IMIN_4_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_4_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)
// Minimum current limit is 5 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_5_UA_VALUE  4
#define SI32_EXTVREG_A_CONFIG_IMIN_5_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_5_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)
// Minimum current limit is 6 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_6_UA_VALUE  5
#define SI32_EXTVREG_A_CONFIG_IMIN_6_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_6_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)
// Minimum current limit is 7 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_7_UA_VALUE  6
#define SI32_EXTVREG_A_CONFIG_IMIN_7_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_7_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)
// Minimum current limit is 8 uA + IMINFINE current.
#define SI32_EXTVREG_A_CONFIG_IMIN_8_UA_VALUE  7
#define SI32_EXTVREG_A_CONFIG_IMIN_8_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMIN_8_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMIN_SHIFT)

#define SI32_EXTVREG_A_CONFIG_FBVOSEL_MASK  0x00000700
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT  8
// Foldback voltage offset is 0 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_0_V_VALUE  0
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_0_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_0_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)
// Foldback voltage offset is 0.5 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_0P5_V_VALUE  1
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_0P5_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_0P5_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)
// Foldback voltage offset is 1 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_1_V_VALUE  2
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_1_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_1_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)
// Foldback voltage offset is 1.5 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_1P5_V_VALUE  3
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_1P5_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_1P5_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)
// Foldback voltage offset is 2 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_2_V_VALUE  4
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_2_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_2_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)
// Foldback voltage offset is 2.5 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_2P5_V_VALUE  5
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_2P5_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_2P5_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)
// Foldback voltage offset is 3 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_3_V_VALUE  6
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_3_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_3_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)
// Foldback voltage offset is 3.5 V.
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_3P5_V_VALUE  7
#define SI32_EXTVREG_A_CONFIG_FBVOSEL_3P5_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBVOSEL_3P5_V_VALUE << SI32_EXTVREG_A_CONFIG_FBVOSEL_SHIFT)

#define SI32_EXTVREG_A_CONFIG_FBRATE_MASK  0x00007000
#define SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT  12
// Set the foldback rate to 4 uA/V.
#define SI32_EXTVREG_A_CONFIG_FBRATE_4_UA_PER_V_VALUE  0
#define SI32_EXTVREG_A_CONFIG_FBRATE_4_UA_PER_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBRATE_4_UA_PER_V_VALUE << SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT)
// Set the foldback rate to 2 uA/V.
#define SI32_EXTVREG_A_CONFIG_FBRATE_2_UA_PER_V_VALUE  1
#define SI32_EXTVREG_A_CONFIG_FBRATE_2_UA_PER_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBRATE_2_UA_PER_V_VALUE << SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT)
// Set the foldback rate to 1 uA/V.
#define SI32_EXTVREG_A_CONFIG_FBRATE_1_UA_PER_V_VALUE  2
#define SI32_EXTVREG_A_CONFIG_FBRATE_1_UA_PER_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBRATE_1_UA_PER_V_VALUE << SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT)
// Set the foldback rate to 0.5 uA/V.
#define SI32_EXTVREG_A_CONFIG_FBRATE_0P5_UA_PER_V_VALUE  3
#define SI32_EXTVREG_A_CONFIG_FBRATE_0P5_UA_PER_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBRATE_0P5_UA_PER_V_VALUE << SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT)
// Set the foldback rate to 8 uA/V.
#define SI32_EXTVREG_A_CONFIG_FBRATE_8_UA_PER_V_VALUE  5
#define SI32_EXTVREG_A_CONFIG_FBRATE_8_UA_PER_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBRATE_8_UA_PER_V_VALUE << SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT)
// Set the foldback rate to 16 uA/V.
#define SI32_EXTVREG_A_CONFIG_FBRATE_16_UA_PER_V_VALUE  6
#define SI32_EXTVREG_A_CONFIG_FBRATE_16_UA_PER_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBRATE_16_UA_PER_V_VALUE << SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT)
// Set the foldback rate to 32 uA/V.
#define SI32_EXTVREG_A_CONFIG_FBRATE_32_UA_PER_V_VALUE  7
#define SI32_EXTVREG_A_CONFIG_FBRATE_32_UA_PER_V_U32 \
   (SI32_EXTVREG_A_CONFIG_FBRATE_32_UA_PER_V_VALUE << SI32_EXTVREG_A_CONFIG_FBRATE_SHIFT)

#define SI32_EXTVREG_A_CONFIG_IMAX_MASK  0x00070000
#define SI32_EXTVREG_A_CONFIG_IMAX_SHIFT  16
// Maximum current limit is 2 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_2_UA_VALUE  0
#define SI32_EXTVREG_A_CONFIG_IMAX_2_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_2_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)
// Maximum current limit is 3 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_3_UA_VALUE  1
#define SI32_EXTVREG_A_CONFIG_IMAX_3_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_3_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)
// Maximum current limit is 4 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_4_UA_VALUE  2
#define SI32_EXTVREG_A_CONFIG_IMAX_4_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_4_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)
// Maximum current limit is 5 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_5_UA_VALUE  3
#define SI32_EXTVREG_A_CONFIG_IMAX_5_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_5_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)
// Maximum current limit is 6 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_6_UA_VALUE  4
#define SI32_EXTVREG_A_CONFIG_IMAX_6_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_6_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)
// Maximum current limit is 7 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_7_UA_VALUE  5
#define SI32_EXTVREG_A_CONFIG_IMAX_7_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_7_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)
// Maximum current limit is 8 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_8_UA_VALUE  6
#define SI32_EXTVREG_A_CONFIG_IMAX_8_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_8_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)
// Maximum current limit is 9 uA.
#define SI32_EXTVREG_A_CONFIG_IMAX_9_UA_VALUE  7
#define SI32_EXTVREG_A_CONFIG_IMAX_9_UA_U32 \
   (SI32_EXTVREG_A_CONFIG_IMAX_9_UA_VALUE << SI32_EXTVREG_A_CONFIG_IMAX_SHIFT)

#define SI32_EXTVREG_A_CONFIG_VOUTSEL_MASK  0x3F000000
#define SI32_EXTVREG_A_CONFIG_VOUTSEL_SHIFT  24



struct SI32_EXTVREG_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Maximum Foldback Flag
         volatile uint32_t FBMAXF: 1;
                  uint32_t reserved0: 31;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EXTVREG_A_STATUS_FBMAXF_MASK  0x00000001
#define SI32_EXTVREG_A_STATUS_FBMAXF_SHIFT  0
// Maximum foldback has not been reached.
#define SI32_EXTVREG_A_STATUS_FBMAXF_NOT_SET_VALUE  0
#define SI32_EXTVREG_A_STATUS_FBMAXF_NOT_SET_U32 \
   (SI32_EXTVREG_A_STATUS_FBMAXF_NOT_SET_VALUE << SI32_EXTVREG_A_STATUS_FBMAXF_SHIFT)
// Maximum foldback has been reached.
#define SI32_EXTVREG_A_STATUS_FBMAXF_SET_VALUE  1
#define SI32_EXTVREG_A_STATUS_FBMAXF_SET_U32 \
   (SI32_EXTVREG_A_STATUS_FBMAXF_SET_VALUE << SI32_EXTVREG_A_STATUS_FBMAXF_SHIFT)



struct SI32_EXTVREG_A_CSCONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 30;
         // External Regulator Current Sense Enable
         volatile uint32_t ISNSEN: 1;
         // ADC Current Sense Enable
         volatile uint32_t ADCISNSEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EXTVREG_A_CSCONTROL_ISNSEN_MASK  0x40000000
#define SI32_EXTVREG_A_CSCONTROL_ISNSEN_SHIFT  30
// Disable external regulator current sensing.
#define SI32_EXTVREG_A_CSCONTROL_ISNSEN_DISABLED_VALUE  0
#define SI32_EXTVREG_A_CSCONTROL_ISNSEN_DISABLED_U32 \
   (SI32_EXTVREG_A_CSCONTROL_ISNSEN_DISABLED_VALUE << SI32_EXTVREG_A_CSCONTROL_ISNSEN_SHIFT)
// Enable external regulator current sensing.
#define SI32_EXTVREG_A_CSCONTROL_ISNSEN_ENABLED_VALUE  1
#define SI32_EXTVREG_A_CSCONTROL_ISNSEN_ENABLED_U32 \
   (SI32_EXTVREG_A_CSCONTROL_ISNSEN_ENABLED_VALUE << SI32_EXTVREG_A_CSCONTROL_ISNSEN_SHIFT)

#define SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_MASK  0x80000000
#define SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_SHIFT  31
// Disable ADC current sensing.
#define SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_DISABLED_VALUE  0U
#define SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_DISABLED_U32 \
   (SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_DISABLED_VALUE << SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_SHIFT)
// Enable ADC current sensing.
#define SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_ENABLED_VALUE  1U
#define SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_ENABLED_U32 \
   (SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_ENABLED_VALUE << SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_SHIFT)



struct SI32_EXTVREG_A_CSCONFIG_Struct
{
   union
   {
      struct
      {
         // ADC Current Sense Gain
         volatile uint32_t ISADCGAIN: 3;
         // External Regulator Current Sense Gain
         volatile uint32_t ISOGAIN: 3;
         // External Regulator Current Sense Input Select
         volatile uint32_t ISINSEL: 2;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_MASK  0x00000007
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_SHIFT  0
// ADC current sensing input gain is 16.
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_16X_VALUE  0
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_16X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_16X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_SHIFT)
// ADC current sensing input gain is 8.
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_8X_VALUE  1
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_8X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_8X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_SHIFT)
// ADC current sensing input gain is 4.
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_4X_VALUE  2
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_4X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_4X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_SHIFT)
// ADC current sensing input gain is 2.
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_2X_VALUE  3
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_2X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_2X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_SHIFT)
// ADC current sensing input gain is 1.
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_1X_VALUE  4
#define SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_1X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_1X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISADCGAIN_SHIFT)

#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_MASK  0x00000038
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_SHIFT  3
// External regulator current sensing gain is 16.
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_16X_VALUE  0
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_16X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISOGAIN_16X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISOGAIN_SHIFT)
// External regulator current sensing gain is 8.
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_8X_VALUE  1
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_8X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISOGAIN_8X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISOGAIN_SHIFT)
// External regulator current sensing gain is 4.
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_4X_VALUE  2
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_4X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISOGAIN_4X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISOGAIN_SHIFT)
// External regulator current sensing gain is 2.
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_2X_VALUE  3
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_2X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISOGAIN_2X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISOGAIN_SHIFT)
// External regulator current sensing gain is 1.
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_1X_VALUE  4
#define SI32_EXTVREG_A_CSCONFIG_ISOGAIN_1X_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISOGAIN_1X_VALUE << SI32_EXTVREG_A_CSCONFIG_ISOGAIN_SHIFT)

#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_MASK  0x000000C0
#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_SHIFT  6
// Select external regulator current sensing mode 0.
#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE0_VALUE  0
#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE0_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE0_VALUE << SI32_EXTVREG_A_CSCONFIG_ISINSEL_SHIFT)
// Select external regulator current sensing mode 1.
#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE1_VALUE  1
#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE1_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE1_VALUE << SI32_EXTVREG_A_CSCONFIG_ISINSEL_SHIFT)
// Select external regulator current sensing mode 2.
#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE2_VALUE  2
#define SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE2_U32 \
   (SI32_EXTVREG_A_CSCONFIG_ISINSEL_MODE2_VALUE << SI32_EXTVREG_A_CSCONFIG_ISINSEL_SHIFT)



typedef struct SI32_EXTVREG_A_Struct
{
   struct SI32_EXTVREG_A_CONTROL_Struct            CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_EXTVREG_A_CONFIG_Struct             CONFIG         ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_EXTVREG_A_STATUS_Struct             STATUS         ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7[4];
   struct SI32_EXTVREG_A_CSCONTROL_Struct          CSCONTROL      ; // Base Address + 0x40
   volatile uint32_t                               CSCONTROL_SET;
   volatile uint32_t                               CSCONTROL_CLR;
   uint32_t                                        reserved8;
   struct SI32_EXTVREG_A_CSCONFIG_Struct           CSCONFIG       ; // Base Address + 0x50
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
} SI32_EXTVREG_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_EXTVREG_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

