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

#ifndef __SI32_RTC_B_REGISTERS_H__
#define __SI32_RTC_B_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_RTC_B_CONFIG_Struct
{
   union
   {
      struct
      {
         // Alarm 0 Automatic Reset Enable
         volatile uint32_t ALM0AREN: 1;
         // RTC Timer Run Control
         volatile uint32_t RUN: 1;
         // Missing Clock Detector Enable
         volatile uint32_t MCLKEN: 1;
         // Automatic Crystal Load Capacitance Stepping Enable
         volatile uint32_t ASEN: 1;
         // Load Capacitance Value
         volatile uint32_t RTCLC: 4;
                  uint32_t reserved0: 8;
         // Bias Doubler Enable
         volatile uint32_t BDEN: 1;
         // Crystal Oscillator Enable
         volatile uint32_t CRYSEN: 1;
         // Automatic Gain Control Enable
         volatile uint32_t AGCEN: 1;
                  uint32_t reserved1: 5;
         // Alarm 0 Enable
         volatile uint32_t ALM0EN: 1;
         // Alarm 1 Enable
         volatile uint32_t ALM1EN: 1;
         // Alarm 2 Enable
         volatile uint32_t ALM2EN: 1;
                  uint32_t reserved2: 1;
         // RTC Clock Output Enable
         volatile uint32_t CLKOEN: 1;
         // RTC External Output Enable
         volatile uint32_t RTCOEN: 1;
         // RTC Timer Clock Select
         volatile uint32_t CLKSEL: 1;
         // RTC Timer Enable
         volatile uint32_t RTCEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RTC_B_CONFIG_ALM0AREN_MASK  0x00000001
#define SI32_RTC_B_CONFIG_ALM0AREN_SHIFT  0
// Disable the Alarm 0 automatic reset.
#define SI32_RTC_B_CONFIG_ALM0AREN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_ALM0AREN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM0AREN_DISABLED_VALUE << SI32_RTC_B_CONFIG_ALM0AREN_SHIFT)
// Enable the Alarm 0 automatic reset.
#define SI32_RTC_B_CONFIG_ALM0AREN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_ALM0AREN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM0AREN_ENABLED_VALUE << SI32_RTC_B_CONFIG_ALM0AREN_SHIFT)

#define SI32_RTC_B_CONFIG_RUN_MASK  0x00000002
#define SI32_RTC_B_CONFIG_RUN_SHIFT  1
// Stop the RTC timer.
#define SI32_RTC_B_CONFIG_RUN_STOP_VALUE  0
#define SI32_RTC_B_CONFIG_RUN_STOP_U32 \
   (SI32_RTC_B_CONFIG_RUN_STOP_VALUE << SI32_RTC_B_CONFIG_RUN_SHIFT)
// Run the RTC timer.
#define SI32_RTC_B_CONFIG_RUN_START_VALUE  1
#define SI32_RTC_B_CONFIG_RUN_START_U32 \
   (SI32_RTC_B_CONFIG_RUN_START_VALUE << SI32_RTC_B_CONFIG_RUN_SHIFT)

#define SI32_RTC_B_CONFIG_MCLKEN_MASK  0x00000004
#define SI32_RTC_B_CONFIG_MCLKEN_SHIFT  2
// Disable the missing clock detector.
#define SI32_RTC_B_CONFIG_MCLKEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_MCLKEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_MCLKEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_MCLKEN_SHIFT)
// Enable the missing clock detector. If the missing clock detector triggers, it
// will generate an RTC Fail event.
#define SI32_RTC_B_CONFIG_MCLKEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_MCLKEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_MCLKEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_MCLKEN_SHIFT)

#define SI32_RTC_B_CONFIG_ASEN_MASK  0x00000008
#define SI32_RTC_B_CONFIG_ASEN_SHIFT  3
// Disable automatic load capacitance stepping.
#define SI32_RTC_B_CONFIG_ASEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_ASEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_ASEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_ASEN_SHIFT)
// Enable automatic load capacitance stepping.
#define SI32_RTC_B_CONFIG_ASEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_ASEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_ASEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_ASEN_SHIFT)

#define SI32_RTC_B_CONFIG_RTCLC_MASK  0x000000F0
#define SI32_RTC_B_CONFIG_RTCLC_SHIFT  4

#define SI32_RTC_B_CONFIG_BDEN_MASK  0x00010000
#define SI32_RTC_B_CONFIG_BDEN_SHIFT  16
// Disable the bias doubler, saving power.
#define SI32_RTC_B_CONFIG_BDEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_BDEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_BDEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_BDEN_SHIFT)
// Enable the bias doubler.
#define SI32_RTC_B_CONFIG_BDEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_BDEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_BDEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_BDEN_SHIFT)

#define SI32_RTC_B_CONFIG_CRYSEN_MASK  0x00020000
#define SI32_RTC_B_CONFIG_CRYSEN_SHIFT  17
// Disable the crystal oscillator circuitry.
#define SI32_RTC_B_CONFIG_CRYSEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_CRYSEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_CRYSEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_CRYSEN_SHIFT)
// Enable the crystal oscillator circuitry.
#define SI32_RTC_B_CONFIG_CRYSEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_CRYSEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_CRYSEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_CRYSEN_SHIFT)

#define SI32_RTC_B_CONFIG_AGCEN_MASK  0x00040000
#define SI32_RTC_B_CONFIG_AGCEN_SHIFT  18
// Disable automatic gain control.
#define SI32_RTC_B_CONFIG_AGCEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_AGCEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_AGCEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_AGCEN_SHIFT)
// Enable automatic gain control, saving power.
#define SI32_RTC_B_CONFIG_AGCEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_AGCEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_AGCEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_AGCEN_SHIFT)

#define SI32_RTC_B_CONFIG_ALM0EN_MASK  0x01000000
#define SI32_RTC_B_CONFIG_ALM0EN_SHIFT  24
// Disable RTC Alarm 0.
#define SI32_RTC_B_CONFIG_ALM0EN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_ALM0EN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM0EN_DISABLED_VALUE << SI32_RTC_B_CONFIG_ALM0EN_SHIFT)
// Enable RTC Alarm 0.
#define SI32_RTC_B_CONFIG_ALM0EN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_ALM0EN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM0EN_ENABLED_VALUE << SI32_RTC_B_CONFIG_ALM0EN_SHIFT)

#define SI32_RTC_B_CONFIG_ALM1EN_MASK  0x02000000
#define SI32_RTC_B_CONFIG_ALM1EN_SHIFT  25
// Disable RTC Alarm 1.
#define SI32_RTC_B_CONFIG_ALM1EN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_ALM1EN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM1EN_DISABLED_VALUE << SI32_RTC_B_CONFIG_ALM1EN_SHIFT)
// Enable RTC Alarm 1.
#define SI32_RTC_B_CONFIG_ALM1EN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_ALM1EN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM1EN_ENABLED_VALUE << SI32_RTC_B_CONFIG_ALM1EN_SHIFT)

#define SI32_RTC_B_CONFIG_ALM2EN_MASK  0x04000000
#define SI32_RTC_B_CONFIG_ALM2EN_SHIFT  26
// Disable RTC Alarm 2.
#define SI32_RTC_B_CONFIG_ALM2EN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_ALM2EN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM2EN_DISABLED_VALUE << SI32_RTC_B_CONFIG_ALM2EN_SHIFT)
// Enable RTC Alarm 2.
#define SI32_RTC_B_CONFIG_ALM2EN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_ALM2EN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_ALM2EN_ENABLED_VALUE << SI32_RTC_B_CONFIG_ALM2EN_SHIFT)

#define SI32_RTC_B_CONFIG_CLKOEN_MASK  0x10000000
#define SI32_RTC_B_CONFIG_CLKOEN_SHIFT  28
// Disable the RTCnTCLK output to the timer and other internal modules.
#define SI32_RTC_B_CONFIG_CLKOEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_CLKOEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_CLKOEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_CLKOEN_SHIFT)
// Enable the RTCnTCLK output to the timer and other internal modules.
#define SI32_RTC_B_CONFIG_CLKOEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_CLKOEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_CLKOEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_CLKOEN_SHIFT)

#define SI32_RTC_B_CONFIG_RTCOEN_MASK  0x20000000
#define SI32_RTC_B_CONFIG_RTCOEN_SHIFT  29
// Disable the external RTCnTCLK_OUT output.
#define SI32_RTC_B_CONFIG_RTCOEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONFIG_RTCOEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_RTCOEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_RTCOEN_SHIFT)
// Enable the external RTCnTCLK_OUT output.
#define SI32_RTC_B_CONFIG_RTCOEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONFIG_RTCOEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_RTCOEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_RTCOEN_SHIFT)

#define SI32_RTC_B_CONFIG_CLKSEL_MASK  0x40000000
#define SI32_RTC_B_CONFIG_CLKSEL_SHIFT  30
// Select the External Crystal or External CMOS Clock as the RTC Timer clock
// (RTCnTCLK) source.
#define SI32_RTC_B_CONFIG_CLKSEL_RTCNOSC_VALUE  0
#define SI32_RTC_B_CONFIG_CLKSEL_RTCNOSC_U32 \
   (SI32_RTC_B_CONFIG_CLKSEL_RTCNOSC_VALUE << SI32_RTC_B_CONFIG_CLKSEL_SHIFT)
// Select the Low Frequency Oscillator as the RTC Timer clock (RTCnTCLK) source.
#define SI32_RTC_B_CONFIG_CLKSEL_LFOSCN_VALUE  1
#define SI32_RTC_B_CONFIG_CLKSEL_LFOSCN_U32 \
   (SI32_RTC_B_CONFIG_CLKSEL_LFOSCN_VALUE << SI32_RTC_B_CONFIG_CLKSEL_SHIFT)

#define SI32_RTC_B_CONFIG_RTCEN_MASK  0x80000000
#define SI32_RTC_B_CONFIG_RTCEN_SHIFT  31
// Disable the RTC timer.
#define SI32_RTC_B_CONFIG_RTCEN_DISABLED_VALUE  0U
#define SI32_RTC_B_CONFIG_RTCEN_DISABLED_U32 \
   (SI32_RTC_B_CONFIG_RTCEN_DISABLED_VALUE << SI32_RTC_B_CONFIG_RTCEN_SHIFT)
// Enable the RTC timer.
#define SI32_RTC_B_CONFIG_RTCEN_ENABLED_VALUE  1U
#define SI32_RTC_B_CONFIG_RTCEN_ENABLED_U32 \
   (SI32_RTC_B_CONFIG_RTCEN_ENABLED_VALUE << SI32_RTC_B_CONFIG_RTCEN_SHIFT)



struct SI32_RTC_B_CONTROL_Struct
{
   union
   {
      struct
      {
         // Alarm 0 Interrupt Flag
         volatile uint32_t ALM0I: 1;
         // Alarm 1 Interrupt Flag
         volatile uint32_t ALM1I: 1;
         // Alarm 2 Interrupt Flag
         volatile uint32_t ALM2I: 1;
         // RTC Timer Capture
         volatile uint32_t TMRCAP: 1;
         // RTC Timer Set
         volatile uint32_t TMRSET: 1;
         // RTC External Oscillator Valid Flag
         volatile uint32_t CLKVF: 1;
         // RTC Oscillator Fail Interrupt Flag
         volatile uint32_t OSCFI: 1;
         // RTC High Speed Mode Enable
         volatile uint32_t HSMDEN: 1;
         // RTC Load Capacitance Ready Flag
         volatile uint32_t LRDYF: 1;
                  uint32_t reserved0: 23;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RTC_B_CONTROL_ALM0I_MASK  0x00000001
#define SI32_RTC_B_CONTROL_ALM0I_SHIFT  0
// Alarm 0 event has not occurred.
#define SI32_RTC_B_CONTROL_ALM0I_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_ALM0I_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_ALM0I_NOT_SET_VALUE << SI32_RTC_B_CONTROL_ALM0I_SHIFT)
// Alarm 0 event occurred.
#define SI32_RTC_B_CONTROL_ALM0I_SET_VALUE  1
#define SI32_RTC_B_CONTROL_ALM0I_SET_U32 \
   (SI32_RTC_B_CONTROL_ALM0I_SET_VALUE << SI32_RTC_B_CONTROL_ALM0I_SHIFT)

#define SI32_RTC_B_CONTROL_ALM1I_MASK  0x00000002
#define SI32_RTC_B_CONTROL_ALM1I_SHIFT  1
// Alarm 1 event has not occurred.
#define SI32_RTC_B_CONTROL_ALM1I_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_ALM1I_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_ALM1I_NOT_SET_VALUE << SI32_RTC_B_CONTROL_ALM1I_SHIFT)
// Alarm 1 event occurred.
#define SI32_RTC_B_CONTROL_ALM1I_SET_VALUE  1
#define SI32_RTC_B_CONTROL_ALM1I_SET_U32 \
   (SI32_RTC_B_CONTROL_ALM1I_SET_VALUE << SI32_RTC_B_CONTROL_ALM1I_SHIFT)

#define SI32_RTC_B_CONTROL_ALM2I_MASK  0x00000004
#define SI32_RTC_B_CONTROL_ALM2I_SHIFT  2
// Alarm 2 event has not occurred.
#define SI32_RTC_B_CONTROL_ALM2I_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_ALM2I_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_ALM2I_NOT_SET_VALUE << SI32_RTC_B_CONTROL_ALM2I_SHIFT)
// Alarm 2 event occurred.
#define SI32_RTC_B_CONTROL_ALM2I_SET_VALUE  1
#define SI32_RTC_B_CONTROL_ALM2I_SET_U32 \
   (SI32_RTC_B_CONTROL_ALM2I_SET_VALUE << SI32_RTC_B_CONTROL_ALM2I_SHIFT)

#define SI32_RTC_B_CONTROL_TMRCAP_MASK  0x00000008
#define SI32_RTC_B_CONTROL_TMRCAP_SHIFT  3
// RTC timer capture operation is complete.
#define SI32_RTC_B_CONTROL_TMRCAP_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_TMRCAP_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_TMRCAP_NOT_SET_VALUE << SI32_RTC_B_CONTROL_TMRCAP_SHIFT)
// Start the RTC timer capture.
#define SI32_RTC_B_CONTROL_TMRCAP_SET_VALUE  1
#define SI32_RTC_B_CONTROL_TMRCAP_SET_U32 \
   (SI32_RTC_B_CONTROL_TMRCAP_SET_VALUE << SI32_RTC_B_CONTROL_TMRCAP_SHIFT)

#define SI32_RTC_B_CONTROL_TMRSET_MASK  0x00000010
#define SI32_RTC_B_CONTROL_TMRSET_SHIFT  4
// RTC timer set operation is complete.
#define SI32_RTC_B_CONTROL_TMRSET_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_TMRSET_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_TMRSET_NOT_SET_VALUE << SI32_RTC_B_CONTROL_TMRSET_SHIFT)
// Start the RTC timer set.
#define SI32_RTC_B_CONTROL_TMRSET_SET_VALUE  1
#define SI32_RTC_B_CONTROL_TMRSET_SET_U32 \
   (SI32_RTC_B_CONTROL_TMRSET_SET_VALUE << SI32_RTC_B_CONTROL_TMRSET_SHIFT)

#define SI32_RTC_B_CONTROL_CLKVF_MASK  0x00000020
#define SI32_RTC_B_CONTROL_CLKVF_SHIFT  5
// External oscillator is not valid.
#define SI32_RTC_B_CONTROL_CLKVF_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_CLKVF_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_CLKVF_NOT_SET_VALUE << SI32_RTC_B_CONTROL_CLKVF_SHIFT)
// External oscillator is valid.
#define SI32_RTC_B_CONTROL_CLKVF_SET_VALUE  1
#define SI32_RTC_B_CONTROL_CLKVF_SET_U32 \
   (SI32_RTC_B_CONTROL_CLKVF_SET_VALUE << SI32_RTC_B_CONTROL_CLKVF_SHIFT)

#define SI32_RTC_B_CONTROL_OSCFI_MASK  0x00000040
#define SI32_RTC_B_CONTROL_OSCFI_SHIFT  6
// Oscillator is running.
#define SI32_RTC_B_CONTROL_OSCFI_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_OSCFI_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_OSCFI_NOT_SET_VALUE << SI32_RTC_B_CONTROL_OSCFI_SHIFT)
// Oscillator has failed.
#define SI32_RTC_B_CONTROL_OSCFI_SET_VALUE  1
#define SI32_RTC_B_CONTROL_OSCFI_SET_U32 \
   (SI32_RTC_B_CONTROL_OSCFI_SET_VALUE << SI32_RTC_B_CONTROL_OSCFI_SHIFT)

#define SI32_RTC_B_CONTROL_HSMDEN_MASK  0x00000080
#define SI32_RTC_B_CONTROL_HSMDEN_SHIFT  7
// Disable high speed mode. (AHBCLK < 4x RTCnTCLK)
#define SI32_RTC_B_CONTROL_HSMDEN_DISABLED_VALUE  0
#define SI32_RTC_B_CONTROL_HSMDEN_DISABLED_U32 \
   (SI32_RTC_B_CONTROL_HSMDEN_DISABLED_VALUE << SI32_RTC_B_CONTROL_HSMDEN_SHIFT)
// Enable high speed mode. (AHBCLK >= 4x RTCnTCLK)
#define SI32_RTC_B_CONTROL_HSMDEN_ENABLED_VALUE  1
#define SI32_RTC_B_CONTROL_HSMDEN_ENABLED_U32 \
   (SI32_RTC_B_CONTROL_HSMDEN_ENABLED_VALUE << SI32_RTC_B_CONTROL_HSMDEN_SHIFT)

#define SI32_RTC_B_CONTROL_LRDYF_MASK  0x00000100
#define SI32_RTC_B_CONTROL_LRDYF_SHIFT  8
// The load capacitance is currently stepping.
#define SI32_RTC_B_CONTROL_LRDYF_NOT_SET_VALUE  0
#define SI32_RTC_B_CONTROL_LRDYF_NOT_SET_U32 \
   (SI32_RTC_B_CONTROL_LRDYF_NOT_SET_VALUE << SI32_RTC_B_CONTROL_LRDYF_SHIFT)
// The load capacitance has reached its programmed value.
#define SI32_RTC_B_CONTROL_LRDYF_SET_VALUE  1
#define SI32_RTC_B_CONTROL_LRDYF_SET_U32 \
   (SI32_RTC_B_CONTROL_LRDYF_SET_VALUE << SI32_RTC_B_CONTROL_LRDYF_SHIFT)



struct SI32_RTC_B_ALARM0_Struct
{
   union
   {
      struct
      {
         // RTC Alarm 0
         volatile uint32_t ALARM0_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RTC_B_ALARM0_ALARM0_MASK  0xFFFFFFFF
#define SI32_RTC_B_ALARM0_ALARM0_SHIFT  0



struct SI32_RTC_B_ALARM1_Struct
{
   union
   {
      struct
      {
         // RTC Alarm 1
         volatile uint32_t ALARM1_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RTC_B_ALARM1_ALARM1_MASK  0xFFFFFFFF
#define SI32_RTC_B_ALARM1_ALARM1_SHIFT  0



struct SI32_RTC_B_ALARM2_Struct
{
   union
   {
      struct
      {
         // RTC Alarm 2
         volatile uint32_t ALARM2_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RTC_B_ALARM2_ALARM2_MASK  0xFFFFFFFF
#define SI32_RTC_B_ALARM2_ALARM2_SHIFT  0



struct SI32_RTC_B_SETCAP_Struct
{
   union
   {
      struct
      {
         // RTC Timer Set/Capture Value
         volatile uint32_t SETCAP_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RTC_B_SETCAP_SETCAP_MASK  0xFFFFFFFF
#define SI32_RTC_B_SETCAP_SETCAP_SHIFT  0



struct SI32_RTC_B_LFOCONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 30;
         // Low Frequency Oscillator Output Enable
         volatile uint32_t LFOOEN: 1;
         // Low Frequency Oscillator Enable
         volatile uint32_t LFOSCEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RTC_B_LFOCONTROL_LFOOEN_MASK  0x40000000
#define SI32_RTC_B_LFOCONTROL_LFOOEN_SHIFT  30
// Disable the Low Frequency Oscillator output to internal modules.
#define SI32_RTC_B_LFOCONTROL_LFOOEN_DISABLED_VALUE  0
#define SI32_RTC_B_LFOCONTROL_LFOOEN_DISABLED_U32 \
   (SI32_RTC_B_LFOCONTROL_LFOOEN_DISABLED_VALUE << SI32_RTC_B_LFOCONTROL_LFOOEN_SHIFT)
// Enable the Low Frequency Oscillator output to internal module.
#define SI32_RTC_B_LFOCONTROL_LFOOEN_ENABLED_VALUE  1
#define SI32_RTC_B_LFOCONTROL_LFOOEN_ENABLED_U32 \
   (SI32_RTC_B_LFOCONTROL_LFOOEN_ENABLED_VALUE << SI32_RTC_B_LFOCONTROL_LFOOEN_SHIFT)

#define SI32_RTC_B_LFOCONTROL_LFOSCEN_MASK  0x80000000
#define SI32_RTC_B_LFOCONTROL_LFOSCEN_SHIFT  31
// Disable the Low Frequency Oscillator (LFOSCn).
#define SI32_RTC_B_LFOCONTROL_LFOSCEN_DISABLED_VALUE  0U
#define SI32_RTC_B_LFOCONTROL_LFOSCEN_DISABLED_U32 \
   (SI32_RTC_B_LFOCONTROL_LFOSCEN_DISABLED_VALUE << SI32_RTC_B_LFOCONTROL_LFOSCEN_SHIFT)
// Enable the Low Frequency Oscillator (LFOSCn).
#define SI32_RTC_B_LFOCONTROL_LFOSCEN_ENABLED_VALUE  1U
#define SI32_RTC_B_LFOCONTROL_LFOSCEN_ENABLED_U32 \
   (SI32_RTC_B_LFOCONTROL_LFOSCEN_ENABLED_VALUE << SI32_RTC_B_LFOCONTROL_LFOSCEN_SHIFT)



typedef struct SI32_RTC_B_Struct
{
   struct SI32_RTC_B_CONFIG_Struct                 CONFIG         ; // Base Address + 0x0
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved0;
   struct SI32_RTC_B_CONTROL_Struct                CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved1;
   struct SI32_RTC_B_ALARM0_Struct                 ALARM0         ; // Base Address + 0x20
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   struct SI32_RTC_B_ALARM1_Struct                 ALARM1         ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_RTC_B_ALARM2_Struct                 ALARM2         ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   struct SI32_RTC_B_SETCAP_Struct                 SETCAP         ; // Base Address + 0x50
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   struct SI32_RTC_B_LFOCONTROL_Struct             LFOCONTROL     ; // Base Address + 0x60
   uint32_t                                        reserved14;
   uint32_t                                        reserved15;
   uint32_t                                        reserved16;
   uint32_t                                        reserved17[4];
   uint32_t                                        reserved18[4];
} SI32_RTC_B_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_RTC_B_REGISTERS_H__

//-eof--------------------------------------------------------------------------

