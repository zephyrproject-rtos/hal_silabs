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
// Script: 0.62
// Version: 1

#ifndef __SI32_ACCTR_A_REGISTERS_H__
#define __SI32_ACCTR_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_ACCTR_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Write Update Status Flag
         volatile uint32_t UPDSTSF: 1;
                  uint32_t reserved0: 4;
         // Debug Signal Select
         volatile uint32_t DBGSEL: 3;
                  uint32_t reserved1: 16;
         // Flutter Quadrature-to-Dual Switch Enable
         volatile uint32_t FLQDEN: 1;
         // Flutter Stop Enable
         volatile uint32_t FLSTPEN: 1;
                  uint32_t reserved2: 3;
         // Topology Mode
         volatile uint32_t TOPMD: 1;
         // Pulse Counter Mode
         volatile uint32_t PCMD: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_CONFIG_UPDSTSF_MASK  0x00000001
#define SI32_ACCTR_A_CONFIG_UPDSTSF_SHIFT  0
// An internal pulse counter register update is not in progress.
#define SI32_ACCTR_A_CONFIG_UPDSTSF_NOT_SET_VALUE  0
#define SI32_ACCTR_A_CONFIG_UPDSTSF_NOT_SET_U32 \
   (SI32_ACCTR_A_CONFIG_UPDSTSF_NOT_SET_VALUE << SI32_ACCTR_A_CONFIG_UPDSTSF_SHIFT)
// An internal pulse counter register update is in progress.
#define SI32_ACCTR_A_CONFIG_UPDSTSF_SET_VALUE  1
#define SI32_ACCTR_A_CONFIG_UPDSTSF_SET_U32 \
   (SI32_ACCTR_A_CONFIG_UPDSTSF_SET_VALUE << SI32_ACCTR_A_CONFIG_UPDSTSF_SHIFT)

#define SI32_ACCTR_A_CONFIG_DBGSEL_MASK  0x000000E0
#define SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT  5
// No debug signals output.
#define SI32_ACCTR_A_CONFIG_DBGSEL_NONE_VALUE  0
#define SI32_ACCTR_A_CONFIG_DBGSEL_NONE_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_NONE_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)
// (LC Mode) DBG0 = CMP0OUT,  DBG1 = CMP1OUT.
#define SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_LCC1_VALUE  1
#define SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_LCC1_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_LCC1_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)
// (LC Mode) DBG0 = CMP0OUT,  DBG1 = INTEG0.
#define SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_INT0_VALUE  2
#define SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_INT0_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_INT0_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)
// (LC Mode) DBG0 = CMP1OUT,  DBG1 = INTEG1.
#define SI32_ACCTR_A_CONFIG_DBGSEL_LCC1_INT1_VALUE  3
#define SI32_ACCTR_A_CONFIG_DBGSEL_LCC1_INT1_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_LCC1_INT1_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)
// (Any Mode) DBG0 = INTEG0  DBG1 = INTEG1.
#define SI32_ACCTR_A_CONFIG_DBGSEL_INT0_INT1_VALUE  4
#define SI32_ACCTR_A_CONFIG_DBGSEL_INT0_INT1_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_INT0_INT1_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)
// (Switch Mode) DBG0 = CMP0OUT,  DBG1 = CMP1OUT.
#define SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_CMP1_VALUE  5
#define SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_CMP1_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_CMP1_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)
// (Switch Mode) DBG0 = CMP0OUT,  DBG1 = INTEG0.
#define SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_INT0_VALUE  6
#define SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_INT0_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_INT0_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)
// (Switch Mode) DBG0= CMP1OUT,  DBG1 = INTEG1.
#define SI32_ACCTR_A_CONFIG_DBGSEL_CMP1_INT1_VALUE  7
#define SI32_ACCTR_A_CONFIG_DBGSEL_CMP1_INT1_U32 \
   (SI32_ACCTR_A_CONFIG_DBGSEL_CMP1_INT1_VALUE << SI32_ACCTR_A_CONFIG_DBGSEL_SHIFT)

#define SI32_ACCTR_A_CONFIG_FLQDEN_MASK  0x01000000
#define SI32_ACCTR_A_CONFIG_FLQDEN_SHIFT  24
// The pulse counter remains in quadrature mode during a flutter event.
#define SI32_ACCTR_A_CONFIG_FLQDEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_CONFIG_FLQDEN_DISABLED_U32 \
   (SI32_ACCTR_A_CONFIG_FLQDEN_DISABLED_VALUE << SI32_ACCTR_A_CONFIG_FLQDEN_SHIFT)
// The pulse counter switches from quadrature mode to dual mode during a flutter
// event.
#define SI32_ACCTR_A_CONFIG_FLQDEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_CONFIG_FLQDEN_ENABLED_U32 \
   (SI32_ACCTR_A_CONFIG_FLQDEN_ENABLED_VALUE << SI32_ACCTR_A_CONFIG_FLQDEN_SHIFT)

#define SI32_ACCTR_A_CONFIG_FLSTPEN_MASK  0x02000000
#define SI32_ACCTR_A_CONFIG_FLSTPEN_SHIFT  25
// The pulse counter continues operating during a flutter event.
#define SI32_ACCTR_A_CONFIG_FLSTPEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_CONFIG_FLSTPEN_DISABLED_U32 \
   (SI32_ACCTR_A_CONFIG_FLSTPEN_DISABLED_VALUE << SI32_ACCTR_A_CONFIG_FLSTPEN_SHIFT)
// The 24-bit counters stop counting during a flutter event.
#define SI32_ACCTR_A_CONFIG_FLSTPEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_CONFIG_FLSTPEN_ENABLED_U32 \
   (SI32_ACCTR_A_CONFIG_FLSTPEN_ENABLED_VALUE << SI32_ACCTR_A_CONFIG_FLSTPEN_SHIFT)

#define SI32_ACCTR_A_CONFIG_TOPMD_MASK  0x20000000
#define SI32_ACCTR_A_CONFIG_TOPMD_SHIFT  29
// Select the switch closure topology.
#define SI32_ACCTR_A_CONFIG_TOPMD_SWITCH_VALUE  0
#define SI32_ACCTR_A_CONFIG_TOPMD_SWITCH_U32 \
   (SI32_ACCTR_A_CONFIG_TOPMD_SWITCH_VALUE << SI32_ACCTR_A_CONFIG_TOPMD_SHIFT)
// Select the LC resonant topology.
#define SI32_ACCTR_A_CONFIG_TOPMD_LC_VALUE  1
#define SI32_ACCTR_A_CONFIG_TOPMD_LC_U32 \
   (SI32_ACCTR_A_CONFIG_TOPMD_LC_VALUE << SI32_ACCTR_A_CONFIG_TOPMD_SHIFT)

#define SI32_ACCTR_A_CONFIG_PCMD_MASK  0xC0000000
#define SI32_ACCTR_A_CONFIG_PCMD_SHIFT  30
// Disable the pulse counter.
#define SI32_ACCTR_A_CONFIG_PCMD_DISABLED_VALUE  0U
#define SI32_ACCTR_A_CONFIG_PCMD_DISABLED_U32 \
   (SI32_ACCTR_A_CONFIG_PCMD_DISABLED_VALUE << SI32_ACCTR_A_CONFIG_PCMD_SHIFT)
// Select single channel mode.
#define SI32_ACCTR_A_CONFIG_PCMD_SINGLE_VALUE  1U
#define SI32_ACCTR_A_CONFIG_PCMD_SINGLE_U32 \
   (SI32_ACCTR_A_CONFIG_PCMD_SINGLE_VALUE << SI32_ACCTR_A_CONFIG_PCMD_SHIFT)
// Select dual channel mode.
#define SI32_ACCTR_A_CONFIG_PCMD_DUAL_VALUE  2U
#define SI32_ACCTR_A_CONFIG_PCMD_DUAL_U32 \
   (SI32_ACCTR_A_CONFIG_PCMD_DUAL_VALUE << SI32_ACCTR_A_CONFIG_PCMD_SHIFT)
// Select quadrature mode.
#define SI32_ACCTR_A_CONFIG_PCMD_QUADRATURE_VALUE  3U
#define SI32_ACCTR_A_CONFIG_PCMD_QUADRATURE_U32 \
   (SI32_ACCTR_A_CONFIG_PCMD_QUADRATURE_VALUE << SI32_ACCTR_A_CONFIG_PCMD_SHIFT)



struct SI32_ACCTR_A_CONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 15;
         // Comparator Low Threshold
         volatile uint32_t CMPLTH: 2;
         // Comparator High Threshold
         volatile uint32_t CMPHTH: 2;
         // Automatic Calibration Mode
         volatile uint32_t CALMD: 1;
         // Automatic Calibration Pull-up Mode
         volatile uint32_t CALPUMD: 2;
         // Force Continuous Pull-up Enable
         volatile uint32_t FPUPEN: 1;
         // Force Ground Input Enable
         volatile uint32_t FPDNEN: 1;
         // Pull-up Value
         volatile uint32_t PUVAL: 5;
         // Automatic Calibration Input Select
         volatile uint32_t CALSEL: 1;
         // Calibration Result Flag
         volatile uint32_t CALRF: 1;
         // Calibration Busy Flag
         volatile uint32_t CALBUSYF: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_CONTROL_CMPLTH_MASK  0x00018000
#define SI32_ACCTR_A_CONTROL_CMPLTH_SHIFT  15
// Set the digital comparator low threshold to 32% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPLTH_32_PERCENT_VALUE  0
#define SI32_ACCTR_A_CONTROL_CMPLTH_32_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPLTH_32_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPLTH_SHIFT)
// Set the digital comparator low threshold to 36% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPLTH_36_PERCENT_VALUE  1
#define SI32_ACCTR_A_CONTROL_CMPLTH_36_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPLTH_36_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPLTH_SHIFT)
// Set the digital comparator low threshold to 40% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPLTH_40_PERCENT_VALUE  2
#define SI32_ACCTR_A_CONTROL_CMPLTH_40_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPLTH_40_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPLTH_SHIFT)
// Set the digital comparator low threshold to 44% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPLTH_44_PERCENT_VALUE  3
#define SI32_ACCTR_A_CONTROL_CMPLTH_44_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPLTH_44_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPLTH_SHIFT)

#define SI32_ACCTR_A_CONTROL_CMPHTH_MASK  0x00060000
#define SI32_ACCTR_A_CONTROL_CMPHTH_SHIFT  17
// Set the digital comparator high threshold to 48% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPHTH_48_PERCENT_VALUE  0
#define SI32_ACCTR_A_CONTROL_CMPHTH_48_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPHTH_48_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPHTH_SHIFT)
// Set the digital comparator high threshold to 52% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPHTH_52_PERCENT_VALUE  1
#define SI32_ACCTR_A_CONTROL_CMPHTH_52_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPHTH_52_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPHTH_SHIFT)
// Set the digital comparator high threshold to 56% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPHTH_56_PERCENT_VALUE  2
#define SI32_ACCTR_A_CONTROL_CMPHTH_56_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPHTH_56_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPHTH_SHIFT)
// Set the digital comparator high threshold to 60% of VIO.
#define SI32_ACCTR_A_CONTROL_CMPHTH_60_PERCENT_VALUE  3
#define SI32_ACCTR_A_CONTROL_CMPHTH_60_PERCENT_U32 \
   (SI32_ACCTR_A_CONTROL_CMPHTH_60_PERCENT_VALUE << SI32_ACCTR_A_CONTROL_CMPHTH_SHIFT)

#define SI32_ACCTR_A_CONTROL_CALMD_MASK  0x00080000
#define SI32_ACCTR_A_CONTROL_CALMD_SHIFT  19
// Continue to calibrate until a passing condition occurs.
#define SI32_ACCTR_A_CONTROL_CALMD_UNTIL_PASS_VALUE  0
#define SI32_ACCTR_A_CONTROL_CALMD_UNTIL_PASS_U32 \
   (SI32_ACCTR_A_CONTROL_CALMD_UNTIL_PASS_VALUE << SI32_ACCTR_A_CONTROL_CALMD_SHIFT)
// Continue to calibrate until a failing condition occurs.
#define SI32_ACCTR_A_CONTROL_CALMD_UNTIL_FAIL_VALUE  1
#define SI32_ACCTR_A_CONTROL_CALMD_UNTIL_FAIL_U32 \
   (SI32_ACCTR_A_CONTROL_CALMD_UNTIL_FAIL_VALUE << SI32_ACCTR_A_CONTROL_CALMD_SHIFT)

#define SI32_ACCTR_A_CONTROL_CALPUMD_MASK  0x00300000
#define SI32_ACCTR_A_CONTROL_CALPUMD_SHIFT  20
// Use full pull-up mode.
#define SI32_ACCTR_A_CONTROL_CALPUMD_FULL_VALUE  0
#define SI32_ACCTR_A_CONTROL_CALPUMD_FULL_U32 \
   (SI32_ACCTR_A_CONTROL_CALPUMD_FULL_VALUE << SI32_ACCTR_A_CONTROL_CALPUMD_SHIFT)
// Use small pull-up mode.
#define SI32_ACCTR_A_CONTROL_CALPUMD_SMALL_VALUE  1
#define SI32_ACCTR_A_CONTROL_CALPUMD_SMALL_U32 \
   (SI32_ACCTR_A_CONTROL_CALPUMD_SMALL_VALUE << SI32_ACCTR_A_CONTROL_CALPUMD_SHIFT)
// Use medium pull-up mode.
#define SI32_ACCTR_A_CONTROL_CALPUMD_MEDIUM_VALUE  2
#define SI32_ACCTR_A_CONTROL_CALPUMD_MEDIUM_U32 \
   (SI32_ACCTR_A_CONTROL_CALPUMD_MEDIUM_VALUE << SI32_ACCTR_A_CONTROL_CALPUMD_SHIFT)
// Use large pull-up mode.
#define SI32_ACCTR_A_CONTROL_CALPUMD_LARGE_VALUE  3
#define SI32_ACCTR_A_CONTROL_CALPUMD_LARGE_U32 \
   (SI32_ACCTR_A_CONTROL_CALPUMD_LARGE_VALUE << SI32_ACCTR_A_CONTROL_CALPUMD_SHIFT)

#define SI32_ACCTR_A_CONTROL_FPUPEN_MASK  0x00400000
#define SI32_ACCTR_A_CONTROL_FPUPEN_SHIFT  22
// Pull-ups are enabled automatically by hardware.
#define SI32_ACCTR_A_CONTROL_FPUPEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_CONTROL_FPUPEN_DISABLED_U32 \
   (SI32_ACCTR_A_CONTROL_FPUPEN_DISABLED_VALUE << SI32_ACCTR_A_CONTROL_FPUPEN_SHIFT)
// Always enable the pull-ups.
#define SI32_ACCTR_A_CONTROL_FPUPEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_CONTROL_FPUPEN_ENABLED_U32 \
   (SI32_ACCTR_A_CONTROL_FPUPEN_ENABLED_VALUE << SI32_ACCTR_A_CONTROL_FPUPEN_SHIFT)

#define SI32_ACCTR_A_CONTROL_FPDNEN_MASK  0x00800000
#define SI32_ACCTR_A_CONTROL_FPDNEN_SHIFT  23
// Disable input grounding.
#define SI32_ACCTR_A_CONTROL_FPDNEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_CONTROL_FPDNEN_DISABLED_U32 \
   (SI32_ACCTR_A_CONTROL_FPDNEN_DISABLED_VALUE << SI32_ACCTR_A_CONTROL_FPDNEN_SHIFT)
// Enable input grounding. The IN0 and IN1 inputs are grounded.
#define SI32_ACCTR_A_CONTROL_FPDNEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_CONTROL_FPDNEN_ENABLED_U32 \
   (SI32_ACCTR_A_CONTROL_FPDNEN_ENABLED_VALUE << SI32_ACCTR_A_CONTROL_FPDNEN_SHIFT)

#define SI32_ACCTR_A_CONTROL_PUVAL_MASK  0x1F000000
#define SI32_ACCTR_A_CONTROL_PUVAL_SHIFT  24

#define SI32_ACCTR_A_CONTROL_CALSEL_MASK  0x20000000
#define SI32_ACCTR_A_CONTROL_CALSEL_SHIFT  29
// Calibrate the IN0 input.
#define SI32_ACCTR_A_CONTROL_CALSEL_IN0_VALUE  0
#define SI32_ACCTR_A_CONTROL_CALSEL_IN0_U32 \
   (SI32_ACCTR_A_CONTROL_CALSEL_IN0_VALUE << SI32_ACCTR_A_CONTROL_CALSEL_SHIFT)
// Calibrate the IN1 input.
#define SI32_ACCTR_A_CONTROL_CALSEL_IN1_VALUE  1
#define SI32_ACCTR_A_CONTROL_CALSEL_IN1_U32 \
   (SI32_ACCTR_A_CONTROL_CALSEL_IN1_VALUE << SI32_ACCTR_A_CONTROL_CALSEL_SHIFT)

#define SI32_ACCTR_A_CONTROL_CALRF_MASK  0x40000000
#define SI32_ACCTR_A_CONTROL_CALRF_SHIFT  30
// The automatic calibration operation did not succeed.
#define SI32_ACCTR_A_CONTROL_CALRF_NOT_SET_VALUE  0
#define SI32_ACCTR_A_CONTROL_CALRF_NOT_SET_U32 \
   (SI32_ACCTR_A_CONTROL_CALRF_NOT_SET_VALUE << SI32_ACCTR_A_CONTROL_CALRF_SHIFT)
// The automatic calibration operation succeeded.
#define SI32_ACCTR_A_CONTROL_CALRF_SET_VALUE  1
#define SI32_ACCTR_A_CONTROL_CALRF_SET_U32 \
   (SI32_ACCTR_A_CONTROL_CALRF_SET_VALUE << SI32_ACCTR_A_CONTROL_CALRF_SHIFT)

#define SI32_ACCTR_A_CONTROL_CALBUSYF_MASK  0x80000000
#define SI32_ACCTR_A_CONTROL_CALBUSYF_SHIFT  31
// A calibration operation is not in progress.
#define SI32_ACCTR_A_CONTROL_CALBUSYF_NOT_SET_VALUE  0U
#define SI32_ACCTR_A_CONTROL_CALBUSYF_NOT_SET_U32 \
   (SI32_ACCTR_A_CONTROL_CALBUSYF_NOT_SET_VALUE << SI32_ACCTR_A_CONTROL_CALBUSYF_SHIFT)
// A calibration operation is in progress. Hardware will clear this flag when the
// operation completes.
#define SI32_ACCTR_A_CONTROL_CALBUSYF_SET_VALUE  1U
#define SI32_ACCTR_A_CONTROL_CALBUSYF_SET_U32 \
   (SI32_ACCTR_A_CONTROL_CALBUSYF_SET_VALUE << SI32_ACCTR_A_CONTROL_CALBUSYF_SHIFT)



struct SI32_ACCTR_A_LCCONFIG_Struct
{
   union
   {
      struct
      {
         // LC Pulse Extension Mode
         volatile uint32_t PEMD: 2;
         // LC Comparator 0 Fine Threshold
         volatile uint32_t CMP0FTH: 3;
         // LC Comparator 0 Coarse Threshold
         volatile uint32_t CMP0CTH: 6;
         // LC Comparator 0 Threshold Range
         volatile uint32_t CMP0THR: 1;
         // LC Comparator 1 Fine Threshold
         volatile uint32_t CMP1FTH: 3;
         // LC Comparator 1 Coarse Threshold
         volatile uint32_t CMP1CTH: 6;
         // LC Comparator 1 Threshold Range
         volatile uint32_t CMP1THR: 1;
         // LC Comparator Low-side Hysteresis
         volatile uint32_t CMPLHYS: 2;
         // LC Comparator High-side Hysteresis
         volatile uint32_t CMPHHYS: 2;
         // LC Comparator Mode
         volatile uint32_t CMPMD: 2;
         // LC Comparator 0 to Count 1 Enable
         volatile uint32_t CMP0CNT1EN: 1;
         // Force LC Comparator 0 On Enable
         volatile uint32_t FCMP0EN: 1;
         // Force LC Comparator 1 On Enable
         volatile uint32_t FCMP1EN: 1;
                  uint32_t reserved0: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_LCCONFIG_PEMD_MASK  0x00000003
#define SI32_ACCTR_A_LCCONFIG_PEMD_SHIFT  0
// Stretch the LC comparator output low pulses by approximately 20 ns.
#define SI32_ACCTR_A_LCCONFIG_PEMD_LOW_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_PEMD_LOW_U32 \
   (SI32_ACCTR_A_LCCONFIG_PEMD_LOW_VALUE << SI32_ACCTR_A_LCCONFIG_PEMD_SHIFT)
// Stretch the LC comparator output high pulses by approximately 20 ns.
#define SI32_ACCTR_A_LCCONFIG_PEMD_HIGH_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_PEMD_HIGH_U32 \
   (SI32_ACCTR_A_LCCONFIG_PEMD_HIGH_VALUE << SI32_ACCTR_A_LCCONFIG_PEMD_SHIFT)
// No pulse extension.
#define SI32_ACCTR_A_LCCONFIG_PEMD_NONE_VALUE  2
#define SI32_ACCTR_A_LCCONFIG_PEMD_NONE_U32 \
   (SI32_ACCTR_A_LCCONFIG_PEMD_NONE_VALUE << SI32_ACCTR_A_LCCONFIG_PEMD_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_CMP0FTH_MASK  0x0000001C
#define SI32_ACCTR_A_LCCONFIG_CMP0FTH_SHIFT  2

#define SI32_ACCTR_A_LCCONFIG_CMP0CTH_MASK  0x000007E0
#define SI32_ACCTR_A_LCCONFIG_CMP0CTH_SHIFT  5

#define SI32_ACCTR_A_LCCONFIG_CMP0THR_MASK  0x00000800
#define SI32_ACCTR_A_LCCONFIG_CMP0THR_SHIFT  11
// Set the comparator 0 threshold to the low range (0 V to VIO/8 in 48 steps).
#define SI32_ACCTR_A_LCCONFIG_CMP0THR_LOW_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_CMP0THR_LOW_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMP0THR_LOW_VALUE << SI32_ACCTR_A_LCCONFIG_CMP0THR_SHIFT)
// Set the comparator 0 threshold to a full range (0 V to VIO in 64 steps).
#define SI32_ACCTR_A_LCCONFIG_CMP0THR_FULL_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_CMP0THR_FULL_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMP0THR_FULL_VALUE << SI32_ACCTR_A_LCCONFIG_CMP0THR_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_CMP1FTH_MASK  0x00007000
#define SI32_ACCTR_A_LCCONFIG_CMP1FTH_SHIFT  12

#define SI32_ACCTR_A_LCCONFIG_CMP1CTH_MASK  0x001F8000
#define SI32_ACCTR_A_LCCONFIG_CMP1CTH_SHIFT  15

#define SI32_ACCTR_A_LCCONFIG_CMP1THR_MASK  0x00200000
#define SI32_ACCTR_A_LCCONFIG_CMP1THR_SHIFT  21
// Set the comparator 1 threshold to the low range (0 V to VIO/8 in 48 steps).
#define SI32_ACCTR_A_LCCONFIG_CMP1THR_LOW_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_CMP1THR_LOW_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMP1THR_LOW_VALUE << SI32_ACCTR_A_LCCONFIG_CMP1THR_SHIFT)
// Set the comparator 1 threshold to a full range (0 V to VIO in 64 steps).
#define SI32_ACCTR_A_LCCONFIG_CMP1THR_FULL_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_CMP1THR_FULL_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMP1THR_FULL_VALUE << SI32_ACCTR_A_LCCONFIG_CMP1THR_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_MASK  0x00C00000
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_SHIFT  22
// Set both LC comparators to use 0 mV low-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_0_MV_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_0_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPLHYS_0_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPLHYS_SHIFT)
// Set both LC comparators to use 5 mV low-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_5_MV_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_5_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPLHYS_5_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPLHYS_SHIFT)
// Set both LC comparators to use 10 mV low-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_10_MV_VALUE  2
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_10_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPLHYS_10_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPLHYS_SHIFT)
// Set both LC comparators to use 20 mV low-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_20_MV_VALUE  3
#define SI32_ACCTR_A_LCCONFIG_CMPLHYS_20_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPLHYS_20_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPLHYS_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_MASK  0x03000000
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_SHIFT  24
// Set both LC comparators to use 0 mV high-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_0_MV_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_0_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPHHYS_0_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPHHYS_SHIFT)
// Set both LC comparators to use 5 mV high-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_5_MV_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_5_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPHHYS_5_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPHHYS_SHIFT)
// Set both LC comparators to use 10 mV high-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_10_MV_VALUE  2
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_10_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPHHYS_10_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPHHYS_SHIFT)
// Set both LC comparators to use 20 mV high-side hysteresis.
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_20_MV_VALUE  3
#define SI32_ACCTR_A_LCCONFIG_CMPHHYS_20_MV_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPHHYS_20_MV_VALUE << SI32_ACCTR_A_LCCONFIG_CMPHHYS_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_CMPMD_MASK  0x0C000000
#define SI32_ACCTR_A_LCCONFIG_CMPMD_SHIFT  26
// Mode 0 (slowest response time, lowest power consumption).
#define SI32_ACCTR_A_LCCONFIG_CMPMD_5_US_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_CMPMD_5_US_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPMD_5_US_VALUE << SI32_ACCTR_A_LCCONFIG_CMPMD_SHIFT)
// Mode 1.
#define SI32_ACCTR_A_LCCONFIG_CMPMD_1_US_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_CMPMD_1_US_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPMD_1_US_VALUE << SI32_ACCTR_A_LCCONFIG_CMPMD_SHIFT)
// Mode 2.
#define SI32_ACCTR_A_LCCONFIG_CMPMD_400_NS_VALUE  2
#define SI32_ACCTR_A_LCCONFIG_CMPMD_400_NS_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPMD_400_NS_VALUE << SI32_ACCTR_A_LCCONFIG_CMPMD_SHIFT)
// Mode 3 (fastest response time, highest power consumption).
#define SI32_ACCTR_A_LCCONFIG_CMPMD_200_NS_VALUE  3
#define SI32_ACCTR_A_LCCONFIG_CMPMD_200_NS_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMPMD_200_NS_VALUE << SI32_ACCTR_A_LCCONFIG_CMPMD_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_MASK  0x10000000
#define SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_SHIFT  28
// Use LC comparator 0 as an input to counter 0 and LC comparator 1 as an input to
// counter 1.
#define SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_DISABLED_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_DISABLED_VALUE << SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_SHIFT)
// Use LC comparator 0 as an input to both counter 0 and counter 1.
#define SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_ENABLED_U32 \
   (SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_ENABLED_VALUE << SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_FCMP0EN_MASK  0x20000000
#define SI32_ACCTR_A_LCCONFIG_FCMP0EN_SHIFT  29
// Hardware automatically turns LC comparator 0 on and off.
#define SI32_ACCTR_A_LCCONFIG_FCMP0EN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_FCMP0EN_DISABLED_U32 \
   (SI32_ACCTR_A_LCCONFIG_FCMP0EN_DISABLED_VALUE << SI32_ACCTR_A_LCCONFIG_FCMP0EN_SHIFT)
// Force LC comparator 0 always on.
#define SI32_ACCTR_A_LCCONFIG_FCMP0EN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_FCMP0EN_ENABLED_U32 \
   (SI32_ACCTR_A_LCCONFIG_FCMP0EN_ENABLED_VALUE << SI32_ACCTR_A_LCCONFIG_FCMP0EN_SHIFT)

#define SI32_ACCTR_A_LCCONFIG_FCMP1EN_MASK  0x40000000
#define SI32_ACCTR_A_LCCONFIG_FCMP1EN_SHIFT  30
// Hardware automatically turns LC comparator 1 on and off.
#define SI32_ACCTR_A_LCCONFIG_FCMP1EN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCCONFIG_FCMP1EN_DISABLED_U32 \
   (SI32_ACCTR_A_LCCONFIG_FCMP1EN_DISABLED_VALUE << SI32_ACCTR_A_LCCONFIG_FCMP1EN_SHIFT)
// Force LC comparator 1 always on.
#define SI32_ACCTR_A_LCCONFIG_FCMP1EN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCCONFIG_FCMP1EN_ENABLED_U32 \
   (SI32_ACCTR_A_LCCONFIG_FCMP1EN_ENABLED_VALUE << SI32_ACCTR_A_LCCONFIG_FCMP1EN_SHIFT)



struct SI32_ACCTR_A_TIMING_Struct
{
   union
   {
      struct
      {
         // Timing State
         volatile uint32_t STATE: 3;
         // Bias 0 Offset Enable
         volatile uint32_t B0OEN: 1;
         // Bias 1 Offset Enable
         volatile uint32_t B1OEN: 1;
                  uint32_t reserved0: 4;
         // Zone D Count
         volatile uint32_t ZONED: 3;
         // Zone C Count
         volatile uint32_t ZONEC: 3;
         // Zone B Count
         volatile uint32_t ZONEB: 3;
         // Zone A Count
         volatile uint32_t ZONEA: 3;
         // Zone P Count
         volatile uint32_t ZONEP: 3;
         // LC Wake Mode
         volatile uint32_t WAKEMD: 3;
         // Sequencer Start
         volatile uint32_t START: 1;
         // Pulse Counter Period
         volatile uint32_t PERIOD: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_TIMING_STATE_MASK  0x00000007
#define SI32_ACCTR_A_TIMING_STATE_SHIFT  0

#define SI32_ACCTR_A_TIMING_B0OEN_MASK  0x00000008
#define SI32_ACCTR_A_TIMING_B0OEN_SHIFT  3
// The bias 0 pulse is a full width (minimum 2 RTC cycles).
#define SI32_ACCTR_A_TIMING_B0OEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_TIMING_B0OEN_DISABLED_U32 \
   (SI32_ACCTR_A_TIMING_B0OEN_DISABLED_VALUE << SI32_ACCTR_A_TIMING_B0OEN_SHIFT)
// The bias 0 pulse is delayed 1/2 an RTC cycle and de-asserts 1/2 an RTC cycle
// early (minimum 3 RTC cycles).
#define SI32_ACCTR_A_TIMING_B0OEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_TIMING_B0OEN_ENABLED_U32 \
   (SI32_ACCTR_A_TIMING_B0OEN_ENABLED_VALUE << SI32_ACCTR_A_TIMING_B0OEN_SHIFT)

#define SI32_ACCTR_A_TIMING_B1OEN_MASK  0x00000010
#define SI32_ACCTR_A_TIMING_B1OEN_SHIFT  4
// The bias 1 pulse is a full width (minimum 2 RTC cycles).
#define SI32_ACCTR_A_TIMING_B1OEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_TIMING_B1OEN_DISABLED_U32 \
   (SI32_ACCTR_A_TIMING_B1OEN_DISABLED_VALUE << SI32_ACCTR_A_TIMING_B1OEN_SHIFT)
// The bias 1 pulse is delayed 1/2 an RTC cycle and de-asserts 1/2 an RTC cycle
// early (minimum 3 RTC cycles).
#define SI32_ACCTR_A_TIMING_B1OEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_TIMING_B1OEN_ENABLED_U32 \
   (SI32_ACCTR_A_TIMING_B1OEN_ENABLED_VALUE << SI32_ACCTR_A_TIMING_B1OEN_SHIFT)

#define SI32_ACCTR_A_TIMING_ZONED_MASK  0x00000E00
#define SI32_ACCTR_A_TIMING_ZONED_SHIFT  9

#define SI32_ACCTR_A_TIMING_ZONEC_MASK  0x00007000
#define SI32_ACCTR_A_TIMING_ZONEC_SHIFT  12

#define SI32_ACCTR_A_TIMING_ZONEB_MASK  0x00038000
#define SI32_ACCTR_A_TIMING_ZONEB_SHIFT  15

#define SI32_ACCTR_A_TIMING_ZONEA_MASK  0x001C0000
#define SI32_ACCTR_A_TIMING_ZONEA_SHIFT  18

#define SI32_ACCTR_A_TIMING_ZONEP_MASK  0x00E00000
#define SI32_ACCTR_A_TIMING_ZONEP_SHIFT  21

#define SI32_ACCTR_A_TIMING_WAKEMD_MASK  0x07000000
#define SI32_ACCTR_A_TIMING_WAKEMD_SHIFT  24
// Disable wake up events.
#define SI32_ACCTR_A_TIMING_WAKEMD_DISABLED_VALUE  0
#define SI32_ACCTR_A_TIMING_WAKEMD_DISABLED_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_DISABLED_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)
// Wake or interrupt at the start of zone P.
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEP_VALUE  1
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEP_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_WZONEP_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)
// Wake or interrupt at the start of zone A.
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEA_VALUE  2
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEA_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_WZONEA_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)
// Wake or interrupt at the start of zone B.
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEB_VALUE  3
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEB_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_WZONEB_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)
// Wake or interrupt at the start of zone C.
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEC_VALUE  4
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONEC_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_WZONEC_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)
// Wake or interrupt at the start of zone D.
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONED_VALUE  5
#define SI32_ACCTR_A_TIMING_WAKEMD_WZONED_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_WZONED_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)
// Wake or interrupt at the end of the LC sequence.
#define SI32_ACCTR_A_TIMING_WAKEMD_WEND_VALUE  6
#define SI32_ACCTR_A_TIMING_WAKEMD_WEND_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_WEND_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)
// Wake or interrupt at the end of the LC sequence and stop the sequencer when this
// event occurs.
#define SI32_ACCTR_A_TIMING_WAKEMD_WKSTOP_VALUE  7
#define SI32_ACCTR_A_TIMING_WAKEMD_WKSTOP_U32 \
   (SI32_ACCTR_A_TIMING_WAKEMD_WKSTOP_VALUE << SI32_ACCTR_A_TIMING_WAKEMD_SHIFT)

#define SI32_ACCTR_A_TIMING_START_MASK  0x08000000
#define SI32_ACCTR_A_TIMING_START_SHIFT  27
// Do not start the sequencer.
#define SI32_ACCTR_A_TIMING_START_DISABLED_VALUE  0
#define SI32_ACCTR_A_TIMING_START_DISABLED_U32 \
   (SI32_ACCTR_A_TIMING_START_DISABLED_VALUE << SI32_ACCTR_A_TIMING_START_SHIFT)
// Start the sequencer.
#define SI32_ACCTR_A_TIMING_START_ENABLED_VALUE  1
#define SI32_ACCTR_A_TIMING_START_ENABLED_U32 \
   (SI32_ACCTR_A_TIMING_START_ENABLED_VALUE << SI32_ACCTR_A_TIMING_START_SHIFT)

#define SI32_ACCTR_A_TIMING_PERIOD_MASK  0xF0000000
#define SI32_ACCTR_A_TIMING_PERIOD_SHIFT  28
// Set the period to 4 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_4_CYCLES_VALUE  0U
#define SI32_ACCTR_A_TIMING_PERIOD_4_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_4_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 8 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_8_CYCLES_VALUE  1U
#define SI32_ACCTR_A_TIMING_PERIOD_8_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_8_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 16 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_16_CYCLES_VALUE  2U
#define SI32_ACCTR_A_TIMING_PERIOD_16_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_16_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 32 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_32_CYCLES_VALUE  3U
#define SI32_ACCTR_A_TIMING_PERIOD_32_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_32_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 64 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_64_CYCLES_VALUE  4U
#define SI32_ACCTR_A_TIMING_PERIOD_64_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_64_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 128 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_128_CYCLES_VALUE  5U
#define SI32_ACCTR_A_TIMING_PERIOD_128_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_128_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 256 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_256_CYCLES_VALUE  6U
#define SI32_ACCTR_A_TIMING_PERIOD_256_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_256_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 512 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_512_CYCLES_VALUE  7U
#define SI32_ACCTR_A_TIMING_PERIOD_512_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_512_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 1024 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_1024_CYCLES_VALUE  8U
#define SI32_ACCTR_A_TIMING_PERIOD_1024_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_1024_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 2048 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_2048_CYCLES_VALUE  9U
#define SI32_ACCTR_A_TIMING_PERIOD_2048_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_2048_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the period to 4096 RTC cycles.
#define SI32_ACCTR_A_TIMING_PERIOD_4096_CYCLES_VALUE  10U
#define SI32_ACCTR_A_TIMING_PERIOD_4096_CYCLES_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_4096_CYCLES_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the module to single sample mode and disable the period counter after the
// next completion of the sequencer.  In this mode, firmware must start each sample
// by setting FLCSEN to 1.
#define SI32_ACCTR_A_TIMING_PERIOD_SINGLE_SAMPLE_VALUE  14U
#define SI32_ACCTR_A_TIMING_PERIOD_SINGLE_SAMPLE_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_SINGLE_SAMPLE_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)
// Set the module to consecutive sample mode and disable the period counter. After
// completing zone D, the timing engine will jump directly to zone A, skipping both
// the W and P zones.
#define SI32_ACCTR_A_TIMING_PERIOD_CONSECUTIVE_SAMPLE_VALUE  15U
#define SI32_ACCTR_A_TIMING_PERIOD_CONSECUTIVE_SAMPLE_U32 \
   (SI32_ACCTR_A_TIMING_PERIOD_CONSECUTIVE_SAMPLE_VALUE << SI32_ACCTR_A_TIMING_PERIOD_SHIFT)



struct SI32_ACCTR_A_LCMODE_Struct
{
   union
   {
      struct
      {
         // Automatic Tracking Enable
         volatile uint32_t ATRKEN: 1;
         // Automatic Center Discriminator Enable
         volatile uint32_t ACDEN: 1;
         // LC Discriminator 0 Digital Hysterisis
         volatile uint32_t LCD0HYS: 2;
         // LC Discriminator 1 Digital Hysterisis
         volatile uint32_t LCD1HYS: 2;
         // Counter 0 Active Zone Select
         volatile uint32_t C0ZONE: 2;
         // Counter 1 Active Zone Select
         volatile uint32_t C1ZONE: 2;
         // Pulse 0 Active Zone Select
         volatile uint32_t P0ZONE: 2;
         // Pulse 1 Active Zone Select
         volatile uint32_t P1ZONE: 2;
         // LC Pulse Mode
         volatile uint32_t PMD: 2;
         // Bias 0 Zone C Enable
         volatile uint32_t B0ZONECEN: 1;
         // Bias 0 Zone B Enable
         volatile uint32_t B0ZONEBEN: 1;
         // Bias 0 Zone A Enable
         volatile uint32_t B0ZONEAEN: 1;
         // Bias 0 Zone P Enable
         volatile uint32_t B0ZONEPEN: 1;
         // Bias 0 Polarity
         volatile uint32_t B0POL: 1;
         // Bias 1 Zone C Enable
         volatile uint32_t B1ZONECEN: 1;
         // Bias 1 Zone B Enable
         volatile uint32_t B1ZONEBEN: 1;
         // Bias 1 Zone A Enable
         volatile uint32_t B1ZONEAEN: 1;
         // Bias 1 Zone P Enable
         volatile uint32_t B1ZONEPEN: 1;
         // Bias 1 Polarity
         volatile uint32_t B1POL: 1;
         // Bias Mode
         volatile uint32_t BMD: 2;
         // LC Mode
         volatile uint32_t LCMD: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_LCMODE_ATRKEN_MASK  0x00000001
#define SI32_ACCTR_A_LCMODE_ATRKEN_SHIFT  0
// Disable automatic tracking.
#define SI32_ACCTR_A_LCMODE_ATRKEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_ATRKEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_ATRKEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_ATRKEN_SHIFT)
// Enable automatic tracking. A new MAX value of any size will increase both the
// MAX and MIN by 1, and a new MIN value of any size will decrease both the MAX and
// MIN by 1.
#define SI32_ACCTR_A_LCMODE_ATRKEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_ATRKEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_ATRKEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_ATRKEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_ACDEN_MASK  0x00000002
#define SI32_ACCTR_A_LCMODE_ACDEN_SHIFT  1
// Disable automatic center discriminator mode. Firmware must set the CD0 and CD1
// fields.
#define SI32_ACCTR_A_LCMODE_ACDEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_ACDEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_ACDEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_ACDEN_SHIFT)
// Enable automatic center discriminator mode. Hardware will keep the CD0 and CD1
// fields centered between MAX and MIN.
#define SI32_ACCTR_A_LCMODE_ACDEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_ACDEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_ACDEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_ACDEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_LCD0HYS_MASK  0x0000000C
#define SI32_ACCTR_A_LCMODE_LCD0HYS_SHIFT  2
// A high-to-low transition occurs if LCCOUNT0 is less than CD0.
#define SI32_ACCTR_A_LCMODE_LCD0HYS_ZERO_VALUE  0
#define SI32_ACCTR_A_LCMODE_LCD0HYS_ZERO_U32 \
   (SI32_ACCTR_A_LCMODE_LCD0HYS_ZERO_VALUE << SI32_ACCTR_A_LCMODE_LCD0HYS_SHIFT)
// A high-to-low transition occurs if LCCOUNT0 is less than CD0 - 1.
#define SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS1_VALUE  1
#define SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS1_U32 \
   (SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS1_VALUE << SI32_ACCTR_A_LCMODE_LCD0HYS_SHIFT)
// A high-to-low transition occurs if LCCOUNT0 is less than CD0 - 2.
#define SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS2_VALUE  2
#define SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS2_U32 \
   (SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS2_VALUE << SI32_ACCTR_A_LCMODE_LCD0HYS_SHIFT)
// A high-to-low transition occurs if LCCOUNT0 is less than CD0 - 3.
#define SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS3_VALUE  3
#define SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS3_U32 \
   (SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS3_VALUE << SI32_ACCTR_A_LCMODE_LCD0HYS_SHIFT)

#define SI32_ACCTR_A_LCMODE_LCD1HYS_MASK  0x00000030
#define SI32_ACCTR_A_LCMODE_LCD1HYS_SHIFT  4
// A high-to-low transition occurs if LCCOUNT1 is less than CD1.
#define SI32_ACCTR_A_LCMODE_LCD1HYS_ZERO_VALUE  0
#define SI32_ACCTR_A_LCMODE_LCD1HYS_ZERO_U32 \
   (SI32_ACCTR_A_LCMODE_LCD1HYS_ZERO_VALUE << SI32_ACCTR_A_LCMODE_LCD1HYS_SHIFT)
// A high-to-low transition occurs if LCCOUNT1 is less than CD1 - 1.
#define SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS1_VALUE  1
#define SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS1_U32 \
   (SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS1_VALUE << SI32_ACCTR_A_LCMODE_LCD1HYS_SHIFT)
// A high-to-low transition occurs if LCCOUNT1 is less than CD1 - 2.
#define SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS2_VALUE  2
#define SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS2_U32 \
   (SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS2_VALUE << SI32_ACCTR_A_LCMODE_LCD1HYS_SHIFT)
// A high-to-low transition occurs if LCCOUNT1 is less than CD1 - 3.
#define SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS3_VALUE  3
#define SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS3_U32 \
   (SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS3_VALUE << SI32_ACCTR_A_LCMODE_LCD1HYS_SHIFT)

#define SI32_ACCTR_A_LCMODE_C0ZONE_MASK  0x000000C0
#define SI32_ACCTR_A_LCMODE_C0ZONE_SHIFT  6
// Select zone A as the active zone for counter 0 (LCIN0 input).
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONEA_VALUE  0
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONEA_U32 \
   (SI32_ACCTR_A_LCMODE_C0ZONE_ZONEA_VALUE << SI32_ACCTR_A_LCMODE_C0ZONE_SHIFT)
// Select zone B as the active zone for counter 0 (LCIN0 input).
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONEB_VALUE  1
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONEB_U32 \
   (SI32_ACCTR_A_LCMODE_C0ZONE_ZONEB_VALUE << SI32_ACCTR_A_LCMODE_C0ZONE_SHIFT)
// Select zone C as the active zone for counter 0 (LCIN0 input).
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONEC_VALUE  2
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONEC_U32 \
   (SI32_ACCTR_A_LCMODE_C0ZONE_ZONEC_VALUE << SI32_ACCTR_A_LCMODE_C0ZONE_SHIFT)
// Select zone D as the active zone for counter 0 (LCIN0 input).
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONED_VALUE  3
#define SI32_ACCTR_A_LCMODE_C0ZONE_ZONED_U32 \
   (SI32_ACCTR_A_LCMODE_C0ZONE_ZONED_VALUE << SI32_ACCTR_A_LCMODE_C0ZONE_SHIFT)

#define SI32_ACCTR_A_LCMODE_C1ZONE_MASK  0x00000300
#define SI32_ACCTR_A_LCMODE_C1ZONE_SHIFT  8
// Select zone A as the active zone for counter 1 (LCIN1 input).
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONEA_VALUE  0
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONEA_U32 \
   (SI32_ACCTR_A_LCMODE_C1ZONE_ZONEA_VALUE << SI32_ACCTR_A_LCMODE_C1ZONE_SHIFT)
// Select zone B as the active zone for counter 1 (LCIN1 input).
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONEB_VALUE  1
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONEB_U32 \
   (SI32_ACCTR_A_LCMODE_C1ZONE_ZONEB_VALUE << SI32_ACCTR_A_LCMODE_C1ZONE_SHIFT)
// Select zone C as the active zone for counter 1 (LCIN1 input).
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONEC_VALUE  2
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONEC_U32 \
   (SI32_ACCTR_A_LCMODE_C1ZONE_ZONEC_VALUE << SI32_ACCTR_A_LCMODE_C1ZONE_SHIFT)
// Select zone D as the active zone for counter 1 (LCIN1 input).
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONED_VALUE  3
#define SI32_ACCTR_A_LCMODE_C1ZONE_ZONED_U32 \
   (SI32_ACCTR_A_LCMODE_C1ZONE_ZONED_VALUE << SI32_ACCTR_A_LCMODE_C1ZONE_SHIFT)

#define SI32_ACCTR_A_LCMODE_P0ZONE_MASK  0x00000C00
#define SI32_ACCTR_A_LCMODE_P0ZONE_SHIFT  10
// Disable the pulse 0 output (LCPUL0).
#define SI32_ACCTR_A_LCMODE_P0ZONE_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_P0ZONE_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_P0ZONE_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_P0ZONE_SHIFT)
// Select zone C only as the active zone for the pulse 0 output (LCPUL0).
#define SI32_ACCTR_A_LCMODE_P0ZONE_C_ONLY_VALUE  1
#define SI32_ACCTR_A_LCMODE_P0ZONE_C_ONLY_U32 \
   (SI32_ACCTR_A_LCMODE_P0ZONE_C_ONLY_VALUE << SI32_ACCTR_A_LCMODE_P0ZONE_SHIFT)
// Select zone A only as the active zone for the pulse 0 output (LCPUL0).
#define SI32_ACCTR_A_LCMODE_P0ZONE_A_ONLY_VALUE  2
#define SI32_ACCTR_A_LCMODE_P0ZONE_A_ONLY_U32 \
   (SI32_ACCTR_A_LCMODE_P0ZONE_A_ONLY_VALUE << SI32_ACCTR_A_LCMODE_P0ZONE_SHIFT)
// Select zones A and C as the active zones for the pulse 0 output (LCPUL0).
#define SI32_ACCTR_A_LCMODE_P0ZONE_A_AND_C_VALUE  3
#define SI32_ACCTR_A_LCMODE_P0ZONE_A_AND_C_U32 \
   (SI32_ACCTR_A_LCMODE_P0ZONE_A_AND_C_VALUE << SI32_ACCTR_A_LCMODE_P0ZONE_SHIFT)

#define SI32_ACCTR_A_LCMODE_P1ZONE_MASK  0x00003000
#define SI32_ACCTR_A_LCMODE_P1ZONE_SHIFT  12
// Disable the pulse 1 output (LCPUL1).
#define SI32_ACCTR_A_LCMODE_P1ZONE_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_P1ZONE_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_P1ZONE_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_P1ZONE_SHIFT)
// Select zone C only as the active zone for the pulse 1 output (LCPUL1).
#define SI32_ACCTR_A_LCMODE_P1ZONE_C_ONLY_VALUE  1
#define SI32_ACCTR_A_LCMODE_P1ZONE_C_ONLY_U32 \
   (SI32_ACCTR_A_LCMODE_P1ZONE_C_ONLY_VALUE << SI32_ACCTR_A_LCMODE_P1ZONE_SHIFT)
// Select zone A only as the active zone for the pulse 1 output (LCPUL1).
#define SI32_ACCTR_A_LCMODE_P1ZONE_A_ONLY_VALUE  2
#define SI32_ACCTR_A_LCMODE_P1ZONE_A_ONLY_U32 \
   (SI32_ACCTR_A_LCMODE_P1ZONE_A_ONLY_VALUE << SI32_ACCTR_A_LCMODE_P1ZONE_SHIFT)
// Select zones A and C as the active zones for the pulse 1 output (LCPUL1).
#define SI32_ACCTR_A_LCMODE_P1ZONE_A_AND_C_VALUE  3
#define SI32_ACCTR_A_LCMODE_P1ZONE_A_AND_C_U32 \
   (SI32_ACCTR_A_LCMODE_P1ZONE_A_AND_C_VALUE << SI32_ACCTR_A_LCMODE_P1ZONE_SHIFT)

#define SI32_ACCTR_A_LCMODE_PMD_MASK  0x0000C000
#define SI32_ACCTR_A_LCMODE_PMD_SHIFT  14
// Disable pulse mode.
#define SI32_ACCTR_A_LCMODE_PMD_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_PMD_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_PMD_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_PMD_SHIFT)
// Toggle at the start of zone A or zone C.
#define SI32_ACCTR_A_LCMODE_PMD_TOGGLE_VALUE  1
#define SI32_ACCTR_A_LCMODE_PMD_TOGGLE_U32 \
   (SI32_ACCTR_A_LCMODE_PMD_TOGGLE_VALUE << SI32_ACCTR_A_LCMODE_PMD_SHIFT)
// Set the pulse mode to idle high, pulse low.
#define SI32_ACCTR_A_LCMODE_PMD_PULSE_LOW_VALUE  2
#define SI32_ACCTR_A_LCMODE_PMD_PULSE_LOW_U32 \
   (SI32_ACCTR_A_LCMODE_PMD_PULSE_LOW_VALUE << SI32_ACCTR_A_LCMODE_PMD_SHIFT)
// Set the pulse mode to idle low, pulse high.
#define SI32_ACCTR_A_LCMODE_PMD_PULSE_HIGH_VALUE  3
#define SI32_ACCTR_A_LCMODE_PMD_PULSE_HIGH_U32 \
   (SI32_ACCTR_A_LCMODE_PMD_PULSE_HIGH_VALUE << SI32_ACCTR_A_LCMODE_PMD_SHIFT)

#define SI32_ACCTR_A_LCMODE_B0ZONECEN_MASK  0x00010000
#define SI32_ACCTR_A_LCMODE_B0ZONECEN_SHIFT  16
// Disable bias 0 during zone C.
#define SI32_ACCTR_A_LCMODE_B0ZONECEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B0ZONECEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONECEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONECEN_SHIFT)
// Enable bias 0 during zone C.
#define SI32_ACCTR_A_LCMODE_B0ZONECEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B0ZONECEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONECEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONECEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B0ZONEBEN_MASK  0x00020000
#define SI32_ACCTR_A_LCMODE_B0ZONEBEN_SHIFT  17
// Disable bias 0 during zone B.
#define SI32_ACCTR_A_LCMODE_B0ZONEBEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B0ZONEBEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONEBEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONEBEN_SHIFT)
// Enable bias 0 during zone B.
#define SI32_ACCTR_A_LCMODE_B0ZONEBEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B0ZONEBEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONEBEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONEBEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B0ZONEAEN_MASK  0x00040000
#define SI32_ACCTR_A_LCMODE_B0ZONEAEN_SHIFT  18
// Disable bias 0 during zone A.
#define SI32_ACCTR_A_LCMODE_B0ZONEAEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B0ZONEAEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONEAEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONEAEN_SHIFT)
// Enable bias 0 during zone A.
#define SI32_ACCTR_A_LCMODE_B0ZONEAEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B0ZONEAEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONEAEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONEAEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B0ZONEPEN_MASK  0x00080000
#define SI32_ACCTR_A_LCMODE_B0ZONEPEN_SHIFT  19
// Disable bias 0 during zone P.
#define SI32_ACCTR_A_LCMODE_B0ZONEPEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B0ZONEPEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONEPEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONEPEN_SHIFT)
// Enable bias 0 during zone P.
#define SI32_ACCTR_A_LCMODE_B0ZONEPEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B0ZONEPEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B0ZONEPEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B0ZONEPEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B0POL_MASK  0x00100000
#define SI32_ACCTR_A_LCMODE_B0POL_SHIFT  20
// Set bias 0 to idle high, pulse low.
#define SI32_ACCTR_A_LCMODE_B0POL_PULSE_LOW_VALUE  0
#define SI32_ACCTR_A_LCMODE_B0POL_PULSE_LOW_U32 \
   (SI32_ACCTR_A_LCMODE_B0POL_PULSE_LOW_VALUE << SI32_ACCTR_A_LCMODE_B0POL_SHIFT)
// Set bias 0 to idle low, pulse high.
#define SI32_ACCTR_A_LCMODE_B0POL_PULSE_HIGH_VALUE  1
#define SI32_ACCTR_A_LCMODE_B0POL_PULSE_HIGH_U32 \
   (SI32_ACCTR_A_LCMODE_B0POL_PULSE_HIGH_VALUE << SI32_ACCTR_A_LCMODE_B0POL_SHIFT)

#define SI32_ACCTR_A_LCMODE_B1ZONECEN_MASK  0x00200000
#define SI32_ACCTR_A_LCMODE_B1ZONECEN_SHIFT  21
// Disable bias 1 during zone C.
#define SI32_ACCTR_A_LCMODE_B1ZONECEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B1ZONECEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONECEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONECEN_SHIFT)
// Enable bias 1 during zone C.
#define SI32_ACCTR_A_LCMODE_B1ZONECEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B1ZONECEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONECEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONECEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B1ZONEBEN_MASK  0x00400000
#define SI32_ACCTR_A_LCMODE_B1ZONEBEN_SHIFT  22
// Disable bias 1 during zone B.
#define SI32_ACCTR_A_LCMODE_B1ZONEBEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B1ZONEBEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONEBEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONEBEN_SHIFT)
// Enable bias 1 during zone B.
#define SI32_ACCTR_A_LCMODE_B1ZONEBEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B1ZONEBEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONEBEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONEBEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B1ZONEAEN_MASK  0x00800000
#define SI32_ACCTR_A_LCMODE_B1ZONEAEN_SHIFT  23
// Disable bias 1 during zone A.
#define SI32_ACCTR_A_LCMODE_B1ZONEAEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B1ZONEAEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONEAEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONEAEN_SHIFT)
// Enable bias 1 during zone A.
#define SI32_ACCTR_A_LCMODE_B1ZONEAEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B1ZONEAEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONEAEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONEAEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B1ZONEPEN_MASK  0x01000000
#define SI32_ACCTR_A_LCMODE_B1ZONEPEN_SHIFT  24
// Disable bias 1 during zone P.
#define SI32_ACCTR_A_LCMODE_B1ZONEPEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_LCMODE_B1ZONEPEN_DISABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONEPEN_DISABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONEPEN_SHIFT)
// Enable bias 1 during zone P.
#define SI32_ACCTR_A_LCMODE_B1ZONEPEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_LCMODE_B1ZONEPEN_ENABLED_U32 \
   (SI32_ACCTR_A_LCMODE_B1ZONEPEN_ENABLED_VALUE << SI32_ACCTR_A_LCMODE_B1ZONEPEN_SHIFT)

#define SI32_ACCTR_A_LCMODE_B1POL_MASK  0x02000000
#define SI32_ACCTR_A_LCMODE_B1POL_SHIFT  25
// Set bias 1 to idle high, pulse low.
#define SI32_ACCTR_A_LCMODE_B1POL_PULSE_LOW_VALUE  0
#define SI32_ACCTR_A_LCMODE_B1POL_PULSE_LOW_U32 \
   (SI32_ACCTR_A_LCMODE_B1POL_PULSE_LOW_VALUE << SI32_ACCTR_A_LCMODE_B1POL_SHIFT)
// Set bias 1 to idle low, pulse high.
#define SI32_ACCTR_A_LCMODE_B1POL_PULSE_HIGH_VALUE  1
#define SI32_ACCTR_A_LCMODE_B1POL_PULSE_HIGH_U32 \
   (SI32_ACCTR_A_LCMODE_B1POL_PULSE_HIGH_VALUE << SI32_ACCTR_A_LCMODE_B1POL_SHIFT)

#define SI32_ACCTR_A_LCMODE_BMD_MASK  0x0C000000
#define SI32_ACCTR_A_LCMODE_BMD_SHIFT  26
// Disable the bias signals.
#define SI32_ACCTR_A_LCMODE_BMD_MODE0_VALUE  0
#define SI32_ACCTR_A_LCMODE_BMD_MODE0_U32 \
   (SI32_ACCTR_A_LCMODE_BMD_MODE0_VALUE << SI32_ACCTR_A_LCMODE_BMD_SHIFT)
// Use the bias signals externally only (LCBIAS0 and LCBIAS1 outputs).
#define SI32_ACCTR_A_LCMODE_BMD_MODE1_VALUE  1
#define SI32_ACCTR_A_LCMODE_BMD_MODE1_U32 \
   (SI32_ACCTR_A_LCMODE_BMD_MODE1_VALUE << SI32_ACCTR_A_LCMODE_BMD_SHIFT)
// Use the bias signals internally only.
#define SI32_ACCTR_A_LCMODE_BMD_MODE2_VALUE  2
#define SI32_ACCTR_A_LCMODE_BMD_MODE2_U32 \
   (SI32_ACCTR_A_LCMODE_BMD_MODE2_VALUE << SI32_ACCTR_A_LCMODE_BMD_SHIFT)
// Use the bias signals externally (LCBIAS0 and LCBIAS1 outputs) and internally.
#define SI32_ACCTR_A_LCMODE_BMD_MODE3_VALUE  3
#define SI32_ACCTR_A_LCMODE_BMD_MODE3_U32 \
   (SI32_ACCTR_A_LCMODE_BMD_MODE3_VALUE << SI32_ACCTR_A_LCMODE_BMD_SHIFT)

#define SI32_ACCTR_A_LCMODE_LCMD_MASK  0xF0000000
#define SI32_ACCTR_A_LCMODE_LCMD_SHIFT  28
// The LC pulse asserts throughout zone A or zone C with a single-ended comparator
// using the counter and discriminator.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE0_VALUE  0U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE0_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE0_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse asserts throughout zone A or zone C with differential comparators
// using the counter and discriminator.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE1_VALUE  1U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE1_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE1_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse asserts throughout zone A or zone C with a single-ended comparator
// sampling and holding at the end of the LC pulse.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE2_VALUE  2U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE2_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE2_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse asserts throughout zone A or zone C with differential comparators
// sampling and holding at the end of the LC pulse.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE3_VALUE  3U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE3_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE3_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at the beginning of zone A or C and stops with the timer
// with a single-ended comparator using the counter and discriminator.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE4_VALUE  4U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE4_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE4_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at the beginning of zone A or C and stops with the timer
// with differential comparators using the counter and discriminator.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE5_VALUE  5U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE5_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE5_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at the beginning of zone A or C and stops with the timer
// with a single-ended comparator sampling and holding at the end of the LC pulse.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE6_VALUE  6U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE6_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE6_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at the beginning of zone A or C and stops with the timer
// with differential comparators sampling and holding at the end of the LC pulse.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE7_VALUE  7U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE7_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE7_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at beginning of zone A or C and stops with the rising edge
// of the external stop input (STOPx) with a single-ended comparator using the
// counter and discriminator.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE8_VALUE  8U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE8_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE8_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at beginning of zone A or C and stops with the falling edge
// of the external stop input (STOPx) with single-ended comparators using the
// counter and discriminator.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE9_VALUE  9U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE9_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE9_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at beginning of zone A or C and stops with the rising edge
// of the external stop input (STOPx) with a single-ended comparator sampling and
// holding at the end of the LC pulse.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE10_VALUE  10U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE10_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE10_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// The LC pulse starts at beginning of zone A or C and stops with the falling edge
// of the external stop input (STOPx) with single-ended comparators sampling and
// holding at the end of the LC pulse.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE11_VALUE  11U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE11_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE11_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// Do not generate a pulse with a single-ended comparator using the timer and
// discrimintor.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE12_VALUE  12U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE12_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE12_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// Do not generate a pulse with differential comparators using the timer and
// discrimintor.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE13_VALUE  13U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE13_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE13_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// Do not generate a pulse with a single-ended comparator sampling and holding at
// the end of the zone.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE14_VALUE  14U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE14_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE14_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)
// Do not genreate a pulse with differential comparators sampling and holding at
// the end of the zone.
#define SI32_ACCTR_A_LCMODE_LCMD_MODE15_VALUE  15U
#define SI32_ACCTR_A_LCMODE_LCMD_MODE15_U32 \
   (SI32_ACCTR_A_LCMODE_LCMD_MODE15_VALUE << SI32_ACCTR_A_LCMODE_LCMD_SHIFT)



struct SI32_ACCTR_A_LCCLKCONTROL_Struct
{
   union
   {
      struct
      {
         // LC Oscillator Clock Cycles
         volatile uint32_t CLKCYCLES: 12;
         // LC Oscillator Calibration Start
         volatile uint32_t CLKCAL: 1;
                  uint32_t reserved0: 3;
         // LC Oscillator Reload Value
         volatile uint32_t RELOAD: 12;
                  uint32_t reserved1: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_LCCLKCONTROL_CLKCYCLES_MASK  0x00000FFF
#define SI32_ACCTR_A_LCCLKCONTROL_CLKCYCLES_SHIFT  0

#define SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_MASK  0x00001000
#define SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_SHIFT  12
// A calibration operation is not in progress.
#define SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_NOT_IN_PROGRESS_VALUE  0
#define SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_NOT_IN_PROGRESS_U32 \
   (SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_NOT_IN_PROGRESS_VALUE << SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_SHIFT)
// Start an oscillator calibration or a calibration operation is in progress.
#define SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_START_VALUE  1
#define SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_START_U32 \
   (SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_START_VALUE << SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_SHIFT)

#define SI32_ACCTR_A_LCCLKCONTROL_RELOAD_MASK  0x0FFF0000
#define SI32_ACCTR_A_LCCLKCONTROL_RELOAD_SHIFT  16



struct SI32_ACCTR_A_LCLIMITS_Struct
{
   union
   {
      struct
      {
         // LC Counter 0 Minimum Value
         volatile uint8_t MIN0;
         // LC Counter 0 Maximum Value
         volatile uint8_t MAX0;
         // LC Counter 1 Minimum Value
         volatile uint8_t MIN1;
         // LC Counter 1 Maximum Value
         volatile uint8_t MAX1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_LCLIMITS_MIN0_MASK  0x000000FF
#define SI32_ACCTR_A_LCLIMITS_MIN0_SHIFT  0

#define SI32_ACCTR_A_LCLIMITS_MAX0_MASK  0x0000FF00
#define SI32_ACCTR_A_LCLIMITS_MAX0_SHIFT  8

#define SI32_ACCTR_A_LCLIMITS_MIN1_MASK  0x00FF0000
#define SI32_ACCTR_A_LCLIMITS_MIN1_SHIFT  16

#define SI32_ACCTR_A_LCLIMITS_MAX1_MASK  0xFF000000
#define SI32_ACCTR_A_LCLIMITS_MAX1_SHIFT  24



struct SI32_ACCTR_A_LCCOUNT_Struct
{
   union
   {
      struct
      {
         // LC Counter 0
         volatile uint8_t LCCOUNT0;
         // LC Counter 0 Discriminator
         volatile uint8_t CD0;
         // LC Counter 1
         volatile uint8_t LCCOUNT1;
         // LC Counter 1 Discriminator
         volatile uint8_t CD1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_LCCOUNT_LCCOUNT0_MASK  0x000000FF
#define SI32_ACCTR_A_LCCOUNT_LCCOUNT0_SHIFT  0

#define SI32_ACCTR_A_LCCOUNT_CD0_MASK  0x0000FF00
#define SI32_ACCTR_A_LCCOUNT_CD0_SHIFT  8

#define SI32_ACCTR_A_LCCOUNT_LCCOUNT1_MASK  0x00FF0000
#define SI32_ACCTR_A_LCCOUNT_LCCOUNT1_SHIFT  16

#define SI32_ACCTR_A_LCCOUNT_CD1_MASK  0xFF000000
#define SI32_ACCTR_A_LCCOUNT_CD1_SHIFT  24



struct SI32_ACCTR_A_DBCONFIG_Struct
{
   union
   {
      struct
      {
         // Integrator Low Debounce
         volatile uint8_t LDBTH;
         // Integrator High Debounce
         volatile uint8_t HDBTH;
         // PC Integrator Disconnect Enable
         volatile uint32_t INTEGDCEN: 1;
         // PC Integrator 0 Output
         volatile uint32_t INTEG0: 1;
         // PC Integrator 1 Output
         volatile uint32_t INTEG1: 1;
                  uint32_t reserved0: 13;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_DBCONFIG_LDBTH_MASK  0x000000FF
#define SI32_ACCTR_A_DBCONFIG_LDBTH_SHIFT  0

#define SI32_ACCTR_A_DBCONFIG_HDBTH_MASK  0x0000FF00
#define SI32_ACCTR_A_DBCONFIG_HDBTH_SHIFT  8

#define SI32_ACCTR_A_DBCONFIG_INTEGDCEN_MASK  0x00010000
#define SI32_ACCTR_A_DBCONFIG_INTEGDCEN_SHIFT  16
// Connect integrator to 24 bit counter state machine logic.
#define SI32_ACCTR_A_DBCONFIG_INTEGDCEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_DBCONFIG_INTEGDCEN_DISABLED_U32 \
   (SI32_ACCTR_A_DBCONFIG_INTEGDCEN_DISABLED_VALUE << SI32_ACCTR_A_DBCONFIG_INTEGDCEN_SHIFT)
// Disconnect the integrators from the IN0 and IN1 inputs.
#define SI32_ACCTR_A_DBCONFIG_INTEGDCEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_DBCONFIG_INTEGDCEN_ENABLED_U32 \
   (SI32_ACCTR_A_DBCONFIG_INTEGDCEN_ENABLED_VALUE << SI32_ACCTR_A_DBCONFIG_INTEGDCEN_SHIFT)

#define SI32_ACCTR_A_DBCONFIG_INTEG0_MASK  0x00020000
#define SI32_ACCTR_A_DBCONFIG_INTEG0_SHIFT  17
// The integrator 0 output is low.
#define SI32_ACCTR_A_DBCONFIG_INTEG0_LOW_VALUE  0
#define SI32_ACCTR_A_DBCONFIG_INTEG0_LOW_U32 \
   (SI32_ACCTR_A_DBCONFIG_INTEG0_LOW_VALUE << SI32_ACCTR_A_DBCONFIG_INTEG0_SHIFT)
// The integrator 0 output is high.
#define SI32_ACCTR_A_DBCONFIG_INTEG0_HIGH_VALUE  1
#define SI32_ACCTR_A_DBCONFIG_INTEG0_HIGH_U32 \
   (SI32_ACCTR_A_DBCONFIG_INTEG0_HIGH_VALUE << SI32_ACCTR_A_DBCONFIG_INTEG0_SHIFT)

#define SI32_ACCTR_A_DBCONFIG_INTEG1_MASK  0x00040000
#define SI32_ACCTR_A_DBCONFIG_INTEG1_SHIFT  18
// The integrator 1 output is low.
#define SI32_ACCTR_A_DBCONFIG_INTEG1_LOW_VALUE  0
#define SI32_ACCTR_A_DBCONFIG_INTEG1_LOW_U32 \
   (SI32_ACCTR_A_DBCONFIG_INTEG1_LOW_VALUE << SI32_ACCTR_A_DBCONFIG_INTEG1_SHIFT)
// The integrator 1 output is high.
#define SI32_ACCTR_A_DBCONFIG_INTEG1_HIGH_VALUE  1
#define SI32_ACCTR_A_DBCONFIG_INTEG1_HIGH_U32 \
   (SI32_ACCTR_A_DBCONFIG_INTEG1_HIGH_VALUE << SI32_ACCTR_A_DBCONFIG_INTEG1_SHIFT)



struct SI32_ACCTR_A_COUNT0_Struct
{
   union
   {
      struct
      {
         // Pulse Counter 0
         volatile uint32_t COUNT0_BITS: 24;
                  uint32_t reserved0: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_COUNT0_COUNT0_MASK  0x00FFFFFF
#define SI32_ACCTR_A_COUNT0_COUNT0_SHIFT  0



struct SI32_ACCTR_A_COUNT1_Struct
{
   union
   {
      struct
      {
         // Pulse Counter 1
         volatile uint32_t COUNT1_BITS: 24;
                  uint32_t reserved0: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_COUNT1_COUNT1_MASK  0x00FFFFFF
#define SI32_ACCTR_A_COUNT1_COUNT1_SHIFT  0



struct SI32_ACCTR_A_COMP0_Struct
{
   union
   {
      struct
      {
         // Pulse Counter Comparator 0 Threshold
         volatile uint32_t COMP0_BITS: 24;
                  uint32_t reserved0: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_COMP0_COMP0_MASK  0x00FFFFFF
#define SI32_ACCTR_A_COMP0_COMP0_SHIFT  0



struct SI32_ACCTR_A_COMP1_Struct
{
   union
   {
      struct
      {
         // Pulse Counter Comparator 1 Threshold
         volatile uint32_t COMP1_BITS: 24;
                  uint32_t reserved0: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_COMP1_COMP1_MASK  0x00FFFFFF
#define SI32_ACCTR_A_COMP1_COMP1_SHIFT  0



struct SI32_ACCTR_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Direction Change Interrupt Flag
         volatile uint32_t DIRCHGI: 1;
         // Counter Overflow Interrupt Flag
         volatile uint32_t OVFI: 1;
         // Digital Comparator 0 Interrupt Flag
         volatile uint32_t CMP0I: 1;
         // Digital Comparator 1 Interrupt Flag
         volatile uint32_t CMP1I: 1;
         // Integrator Transition Interrupt Flag
         volatile uint32_t TRANSI: 1;
         // Quadrature Error Interrupt Flag
         volatile uint32_t QERRI: 1;
         // Flutter Stop Interrupt Flag
         volatile uint32_t FLSTOPI: 1;
         // Flutter Start Interrupt Flag
         volatile uint32_t FLSTARTI: 1;
         // Direction Change Interrupt Enable
         volatile uint32_t DIRCHGIEN: 1;
         // Counter Overflow Interrupt Enable
         volatile uint32_t OVFIEN: 1;
         // Digital Comparator 0 Interrupt Enable
         volatile uint32_t CMP0IEN: 1;
         // Digital Comparator 1 Interrupt Enable
         volatile uint32_t CMP1IEN: 1;
         // Integrator Transition Interrupt Enable
         volatile uint32_t TRANSIEN: 1;
         // Quadrature Error Interrupt Enable
         volatile uint32_t QERRIEN: 1;
         // Flutter Stop Interrupt Enable
         volatile uint32_t FLSTOPIEN: 1;
         // Flutter Start Interrupt Enable
         volatile uint32_t FLSTARTIEN: 1;
         // Integrator 0 Output
         volatile uint32_t IN0: 1;
         // Integrator 1 Output
         volatile uint32_t IN1: 1;
         // Previous Integrator 0 Output
         volatile uint32_t IN0PREV: 1;
         // Previous Integrator 1 Output
         volatile uint32_t IN1PREV: 1;
         // Pulse Counter State
         volatile uint32_t STATE: 2;
         // Direction Flag
         volatile uint32_t DIRF: 1;
         // Flutter Detected Flag
         volatile uint32_t FLF: 1;
         // Direction History
         volatile uint32_t DIRHIST: 4;
         // Comparator 0 Output
         volatile uint32_t CMP0OUT: 1;
         // Comparator 1 Output
         volatile uint32_t CMP1OUT: 1;
                  uint32_t reserved0: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_STATUS_DIRCHGI_MASK  0x00000001
#define SI32_ACCTR_A_STATUS_DIRCHGI_SHIFT  0
// A direction change did not occur.
#define SI32_ACCTR_A_STATUS_DIRCHGI_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_DIRCHGI_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_DIRCHGI_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_DIRCHGI_SHIFT)
// A direction change occurred.
#define SI32_ACCTR_A_STATUS_DIRCHGI_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_DIRCHGI_SET_U32 \
   (SI32_ACCTR_A_STATUS_DIRCHGI_SET_VALUE << SI32_ACCTR_A_STATUS_DIRCHGI_SHIFT)

#define SI32_ACCTR_A_STATUS_OVFI_MASK  0x00000002
#define SI32_ACCTR_A_STATUS_OVFI_SHIFT  1
// Neither of the counters overflowed.
#define SI32_ACCTR_A_STATUS_OVFI_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_OVFI_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_OVFI_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_OVFI_SHIFT)
// One of the counters overflowed.
#define SI32_ACCTR_A_STATUS_OVFI_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_OVFI_SET_U32 \
   (SI32_ACCTR_A_STATUS_OVFI_SET_VALUE << SI32_ACCTR_A_STATUS_OVFI_SHIFT)

#define SI32_ACCTR_A_STATUS_CMP0I_MASK  0x00000004
#define SI32_ACCTR_A_STATUS_CMP0I_SHIFT  2
// A digital comparator 0 and counter 0 match did not occur.
#define SI32_ACCTR_A_STATUS_CMP0I_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_CMP0I_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_CMP0I_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_CMP0I_SHIFT)
// A digital comparator 0 and counter 0 match occurred.
#define SI32_ACCTR_A_STATUS_CMP0I_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_CMP0I_SET_U32 \
   (SI32_ACCTR_A_STATUS_CMP0I_SET_VALUE << SI32_ACCTR_A_STATUS_CMP0I_SHIFT)

#define SI32_ACCTR_A_STATUS_CMP1I_MASK  0x00000008
#define SI32_ACCTR_A_STATUS_CMP1I_SHIFT  3
// A digital comparator 1 and counter 1 match did not occur.
#define SI32_ACCTR_A_STATUS_CMP1I_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_CMP1I_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_CMP1I_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_CMP1I_SHIFT)
// A digital comparator 1 and counter 1 match occurred.
#define SI32_ACCTR_A_STATUS_CMP1I_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_CMP1I_SET_U32 \
   (SI32_ACCTR_A_STATUS_CMP1I_SET_VALUE << SI32_ACCTR_A_STATUS_CMP1I_SHIFT)

#define SI32_ACCTR_A_STATUS_TRANSI_MASK  0x00000010
#define SI32_ACCTR_A_STATUS_TRANSI_SHIFT  4
// An integrator output transition did not occur.
#define SI32_ACCTR_A_STATUS_TRANSI_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_TRANSI_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_TRANSI_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_TRANSI_SHIFT)
// An integrator output transition occurred.
#define SI32_ACCTR_A_STATUS_TRANSI_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_TRANSI_SET_U32 \
   (SI32_ACCTR_A_STATUS_TRANSI_SET_VALUE << SI32_ACCTR_A_STATUS_TRANSI_SHIFT)

#define SI32_ACCTR_A_STATUS_QERRI_MASK  0x00000020
#define SI32_ACCTR_A_STATUS_QERRI_SHIFT  5
// A quadrature error did not occur.
#define SI32_ACCTR_A_STATUS_QERRI_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_QERRI_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_QERRI_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_QERRI_SHIFT)
// A quadrature error occurred.
#define SI32_ACCTR_A_STATUS_QERRI_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_QERRI_SET_U32 \
   (SI32_ACCTR_A_STATUS_QERRI_SET_VALUE << SI32_ACCTR_A_STATUS_QERRI_SHIFT)

#define SI32_ACCTR_A_STATUS_FLSTOPI_MASK  0x00000040
#define SI32_ACCTR_A_STATUS_FLSTOPI_SHIFT  6
// A flutter detection end event did not occur.
#define SI32_ACCTR_A_STATUS_FLSTOPI_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_FLSTOPI_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_FLSTOPI_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_FLSTOPI_SHIFT)
// A flutter detection end event occurred.
#define SI32_ACCTR_A_STATUS_FLSTOPI_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_FLSTOPI_SET_U32 \
   (SI32_ACCTR_A_STATUS_FLSTOPI_SET_VALUE << SI32_ACCTR_A_STATUS_FLSTOPI_SHIFT)

#define SI32_ACCTR_A_STATUS_FLSTARTI_MASK  0x00000080
#define SI32_ACCTR_A_STATUS_FLSTARTI_SHIFT  7
// A flutter detection start event did not occur.
#define SI32_ACCTR_A_STATUS_FLSTARTI_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_FLSTARTI_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_FLSTARTI_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_FLSTARTI_SHIFT)
// A flutter detection start event occurred.
#define SI32_ACCTR_A_STATUS_FLSTARTI_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_FLSTARTI_SET_U32 \
   (SI32_ACCTR_A_STATUS_FLSTARTI_SET_VALUE << SI32_ACCTR_A_STATUS_FLSTARTI_SHIFT)

#define SI32_ACCTR_A_STATUS_DIRCHGIEN_MASK  0x00000100
#define SI32_ACCTR_A_STATUS_DIRCHGIEN_SHIFT  8
// Disable direction change as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_DIRCHGIEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_DIRCHGIEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_DIRCHGIEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_DIRCHGIEN_SHIFT)
// Enable direction change as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_DIRCHGIEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_DIRCHGIEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_DIRCHGIEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_DIRCHGIEN_SHIFT)

#define SI32_ACCTR_A_STATUS_OVFIEN_MASK  0x00000200
#define SI32_ACCTR_A_STATUS_OVFIEN_SHIFT  9
// Disable counter overflows as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_OVFIEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_OVFIEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_OVFIEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_OVFIEN_SHIFT)
// Enable counter overflows as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_OVFIEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_OVFIEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_OVFIEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_OVFIEN_SHIFT)

#define SI32_ACCTR_A_STATUS_CMP0IEN_MASK  0x00000400
#define SI32_ACCTR_A_STATUS_CMP0IEN_SHIFT  10
// Disable comparator 0 as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_CMP0IEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_CMP0IEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_CMP0IEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_CMP0IEN_SHIFT)
// Enable comparator 0 as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_CMP0IEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_CMP0IEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_CMP0IEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_CMP0IEN_SHIFT)

#define SI32_ACCTR_A_STATUS_CMP1IEN_MASK  0x00000800
#define SI32_ACCTR_A_STATUS_CMP1IEN_SHIFT  11
// Disable comparator 1 as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_CMP1IEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_CMP1IEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_CMP1IEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_CMP1IEN_SHIFT)
// Enable comparator 1 as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_CMP1IEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_CMP1IEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_CMP1IEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_CMP1IEN_SHIFT)

#define SI32_ACCTR_A_STATUS_TRANSIEN_MASK  0x00001000
#define SI32_ACCTR_A_STATUS_TRANSIEN_SHIFT  12
// Disable integrator transitions as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_TRANSIEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_TRANSIEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_TRANSIEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_TRANSIEN_SHIFT)
// Enable integrator transitions as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_TRANSIEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_TRANSIEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_TRANSIEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_TRANSIEN_SHIFT)

#define SI32_ACCTR_A_STATUS_QERRIEN_MASK  0x00002000
#define SI32_ACCTR_A_STATUS_QERRIEN_SHIFT  13
// Disable quadrature error as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_QERRIEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_QERRIEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_QERRIEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_QERRIEN_SHIFT)
// Enable quadrature error as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_QERRIEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_QERRIEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_QERRIEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_QERRIEN_SHIFT)

#define SI32_ACCTR_A_STATUS_FLSTOPIEN_MASK  0x00004000
#define SI32_ACCTR_A_STATUS_FLSTOPIEN_SHIFT  14
// Disable flutter detection end events as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_FLSTOPIEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_FLSTOPIEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_FLSTOPIEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_FLSTOPIEN_SHIFT)
// Enable flutter detection end events as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_FLSTOPIEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_FLSTOPIEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_FLSTOPIEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_FLSTOPIEN_SHIFT)

#define SI32_ACCTR_A_STATUS_FLSTARTIEN_MASK  0x00008000
#define SI32_ACCTR_A_STATUS_FLSTARTIEN_SHIFT  15
// Disable flutter detection start events as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_FLSTARTIEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_STATUS_FLSTARTIEN_DISABLED_U32 \
   (SI32_ACCTR_A_STATUS_FLSTARTIEN_DISABLED_VALUE << SI32_ACCTR_A_STATUS_FLSTARTIEN_SHIFT)
// Enable flutter detection start events as an interrupt or wake up source.
#define SI32_ACCTR_A_STATUS_FLSTARTIEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_STATUS_FLSTARTIEN_ENABLED_U32 \
   (SI32_ACCTR_A_STATUS_FLSTARTIEN_ENABLED_VALUE << SI32_ACCTR_A_STATUS_FLSTARTIEN_SHIFT)

#define SI32_ACCTR_A_STATUS_IN0_MASK  0x00010000
#define SI32_ACCTR_A_STATUS_IN0_SHIFT  16
// The integrator 0 output is low.
#define SI32_ACCTR_A_STATUS_IN0_LOW_VALUE  0
#define SI32_ACCTR_A_STATUS_IN0_LOW_U32 \
   (SI32_ACCTR_A_STATUS_IN0_LOW_VALUE << SI32_ACCTR_A_STATUS_IN0_SHIFT)
// The integrator 0 output is high.
#define SI32_ACCTR_A_STATUS_IN0_HIGH_VALUE  1
#define SI32_ACCTR_A_STATUS_IN0_HIGH_U32 \
   (SI32_ACCTR_A_STATUS_IN0_HIGH_VALUE << SI32_ACCTR_A_STATUS_IN0_SHIFT)

#define SI32_ACCTR_A_STATUS_IN1_MASK  0x00020000
#define SI32_ACCTR_A_STATUS_IN1_SHIFT  17
// The integrator 1 output is low.
#define SI32_ACCTR_A_STATUS_IN1_LOW_VALUE  0
#define SI32_ACCTR_A_STATUS_IN1_LOW_U32 \
   (SI32_ACCTR_A_STATUS_IN1_LOW_VALUE << SI32_ACCTR_A_STATUS_IN1_SHIFT)
// The integrator 1 output is high.
#define SI32_ACCTR_A_STATUS_IN1_HIGH_VALUE  1
#define SI32_ACCTR_A_STATUS_IN1_HIGH_U32 \
   (SI32_ACCTR_A_STATUS_IN1_HIGH_VALUE << SI32_ACCTR_A_STATUS_IN1_SHIFT)

#define SI32_ACCTR_A_STATUS_IN0PREV_MASK  0x00040000
#define SI32_ACCTR_A_STATUS_IN0PREV_SHIFT  18
// The previous integrator 0 output was low.
#define SI32_ACCTR_A_STATUS_IN0PREV_LOW_VALUE  0
#define SI32_ACCTR_A_STATUS_IN0PREV_LOW_U32 \
   (SI32_ACCTR_A_STATUS_IN0PREV_LOW_VALUE << SI32_ACCTR_A_STATUS_IN0PREV_SHIFT)
// The previous integrator 0 output was high.
#define SI32_ACCTR_A_STATUS_IN0PREV_HIGH_VALUE  1
#define SI32_ACCTR_A_STATUS_IN0PREV_HIGH_U32 \
   (SI32_ACCTR_A_STATUS_IN0PREV_HIGH_VALUE << SI32_ACCTR_A_STATUS_IN0PREV_SHIFT)

#define SI32_ACCTR_A_STATUS_IN1PREV_MASK  0x00080000
#define SI32_ACCTR_A_STATUS_IN1PREV_SHIFT  19
// The previous integrator 1 output was low.
#define SI32_ACCTR_A_STATUS_IN1PREV_LOW_VALUE  0
#define SI32_ACCTR_A_STATUS_IN1PREV_LOW_U32 \
   (SI32_ACCTR_A_STATUS_IN1PREV_LOW_VALUE << SI32_ACCTR_A_STATUS_IN1PREV_SHIFT)
// The previous integrator 1 output was high.
#define SI32_ACCTR_A_STATUS_IN1PREV_HIGH_VALUE  1
#define SI32_ACCTR_A_STATUS_IN1PREV_HIGH_U32 \
   (SI32_ACCTR_A_STATUS_IN1PREV_HIGH_VALUE << SI32_ACCTR_A_STATUS_IN1PREV_SHIFT)

#define SI32_ACCTR_A_STATUS_STATE_MASK  0x00300000
#define SI32_ACCTR_A_STATUS_STATE_SHIFT  20
// The pulse counter is in state 0.
#define SI32_ACCTR_A_STATUS_STATE_ST0_VALUE  0
#define SI32_ACCTR_A_STATUS_STATE_ST0_U32 \
   (SI32_ACCTR_A_STATUS_STATE_ST0_VALUE << SI32_ACCTR_A_STATUS_STATE_SHIFT)
// The pulse counter is in state 1.
#define SI32_ACCTR_A_STATUS_STATE_ST1_VALUE  1
#define SI32_ACCTR_A_STATUS_STATE_ST1_U32 \
   (SI32_ACCTR_A_STATUS_STATE_ST1_VALUE << SI32_ACCTR_A_STATUS_STATE_SHIFT)
// The pulse counter is in state 2.
#define SI32_ACCTR_A_STATUS_STATE_ST2_VALUE  2
#define SI32_ACCTR_A_STATUS_STATE_ST2_U32 \
   (SI32_ACCTR_A_STATUS_STATE_ST2_VALUE << SI32_ACCTR_A_STATUS_STATE_SHIFT)
// The pulse counter is in state 3.
#define SI32_ACCTR_A_STATUS_STATE_ST3_VALUE  3
#define SI32_ACCTR_A_STATUS_STATE_ST3_U32 \
   (SI32_ACCTR_A_STATUS_STATE_ST3_VALUE << SI32_ACCTR_A_STATUS_STATE_SHIFT)

#define SI32_ACCTR_A_STATUS_DIRF_MASK  0x00400000
#define SI32_ACCTR_A_STATUS_DIRF_SHIFT  22
// The current direction is counter-clockwise.
#define SI32_ACCTR_A_STATUS_DIRF_COUNTER_CLOCKWISE_VALUE  0
#define SI32_ACCTR_A_STATUS_DIRF_COUNTER_CLOCKWISE_U32 \
   (SI32_ACCTR_A_STATUS_DIRF_COUNTER_CLOCKWISE_VALUE << SI32_ACCTR_A_STATUS_DIRF_SHIFT)
// The current direction is clockwise.
#define SI32_ACCTR_A_STATUS_DIRF_CLOCKWISE_VALUE  1
#define SI32_ACCTR_A_STATUS_DIRF_CLOCKWISE_U32 \
   (SI32_ACCTR_A_STATUS_DIRF_CLOCKWISE_VALUE << SI32_ACCTR_A_STATUS_DIRF_SHIFT)

#define SI32_ACCTR_A_STATUS_FLF_MASK  0x00800000
#define SI32_ACCTR_A_STATUS_FLF_SHIFT  23
// The switch operates normally.
#define SI32_ACCTR_A_STATUS_FLF_NOT_SET_VALUE  0
#define SI32_ACCTR_A_STATUS_FLF_NOT_SET_U32 \
   (SI32_ACCTR_A_STATUS_FLF_NOT_SET_VALUE << SI32_ACCTR_A_STATUS_FLF_SHIFT)
// A flutter event was detected.
#define SI32_ACCTR_A_STATUS_FLF_SET_VALUE  1
#define SI32_ACCTR_A_STATUS_FLF_SET_U32 \
   (SI32_ACCTR_A_STATUS_FLF_SET_VALUE << SI32_ACCTR_A_STATUS_FLF_SHIFT)

#define SI32_ACCTR_A_STATUS_DIRHIST_MASK  0x0F000000
#define SI32_ACCTR_A_STATUS_DIRHIST_SHIFT  24

#define SI32_ACCTR_A_STATUS_CMP0OUT_MASK  0x10000000
#define SI32_ACCTR_A_STATUS_CMP0OUT_SHIFT  28
// The output of comparator 0 is low.
#define SI32_ACCTR_A_STATUS_CMP0OUT_LOW_VALUE  0
#define SI32_ACCTR_A_STATUS_CMP0OUT_LOW_U32 \
   (SI32_ACCTR_A_STATUS_CMP0OUT_LOW_VALUE << SI32_ACCTR_A_STATUS_CMP0OUT_SHIFT)
// The output of comparator 0 is high.
#define SI32_ACCTR_A_STATUS_CMP0OUT_HIGH_VALUE  1
#define SI32_ACCTR_A_STATUS_CMP0OUT_HIGH_U32 \
   (SI32_ACCTR_A_STATUS_CMP0OUT_HIGH_VALUE << SI32_ACCTR_A_STATUS_CMP0OUT_SHIFT)

#define SI32_ACCTR_A_STATUS_CMP1OUT_MASK  0x20000000
#define SI32_ACCTR_A_STATUS_CMP1OUT_SHIFT  29
// The output of comparator 1 is low.
#define SI32_ACCTR_A_STATUS_CMP1OUT_LOW_VALUE  0
#define SI32_ACCTR_A_STATUS_CMP1OUT_LOW_U32 \
   (SI32_ACCTR_A_STATUS_CMP1OUT_LOW_VALUE << SI32_ACCTR_A_STATUS_CMP1OUT_SHIFT)
// The output of comparator1 is high.
#define SI32_ACCTR_A_STATUS_CMP1OUT_HIGH_VALUE  1
#define SI32_ACCTR_A_STATUS_CMP1OUT_HIGH_U32 \
   (SI32_ACCTR_A_STATUS_CMP1OUT_HIGH_VALUE << SI32_ACCTR_A_STATUS_CMP1OUT_SHIFT)



struct SI32_ACCTR_A_DEBUGEN_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 14;
         // Debug Output Enable
         volatile uint32_t DBGOEN: 1;
                  uint32_t reserved1: 17;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ACCTR_A_DEBUGEN_DBGOEN_MASK  0x00004000
#define SI32_ACCTR_A_DEBUGEN_DBGOEN_SHIFT  14
#define SI32_ACCTR_A_DEBUGEN_DBGOEN_DISABLED_VALUE  0
#define SI32_ACCTR_A_DEBUGEN_DBGOEN_DISABLED_U32 \
   (SI32_ACCTR_A_DEBUGEN_DBGOEN_DISABLED_VALUE << SI32_ACCTR_A_DEBUGEN_DBGOEN_SHIFT)
#define SI32_ACCTR_A_DEBUGEN_DBGOEN_ENABLED_VALUE  1
#define SI32_ACCTR_A_DEBUGEN_DBGOEN_ENABLED_U32 \
   (SI32_ACCTR_A_DEBUGEN_DBGOEN_ENABLED_VALUE << SI32_ACCTR_A_DEBUGEN_DBGOEN_SHIFT)



typedef struct SI32_ACCTR_A_Struct
{
   struct SI32_ACCTR_A_CONFIG_Struct               CONFIG         ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_ACCTR_A_CONTROL_Struct              CONTROL        ; // Base Address + 0x10
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   struct SI32_ACCTR_A_LCCONFIG_Struct             LCCONFIG       ; // Base Address + 0x20
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   struct SI32_ACCTR_A_TIMING_Struct               TIMING         ; // Base Address + 0x30
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
   struct SI32_ACCTR_A_LCMODE_Struct               LCMODE         ; // Base Address + 0x40
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   uint32_t                                        reserved14;
   struct SI32_ACCTR_A_LCCLKCONTROL_Struct         LCCLKCONTROL   ; // Base Address + 0x50
   uint32_t                                        reserved15;
   uint32_t                                        reserved16;
   uint32_t                                        reserved17;
   struct SI32_ACCTR_A_LCLIMITS_Struct             LCLIMITS       ; // Base Address + 0x60
   uint32_t                                        reserved18;
   uint32_t                                        reserved19;
   uint32_t                                        reserved20;
   struct SI32_ACCTR_A_LCCOUNT_Struct              LCCOUNT        ; // Base Address + 0x70
   uint32_t                                        reserved21;
   uint32_t                                        reserved22;
   uint32_t                                        reserved23;
   struct SI32_ACCTR_A_DBCONFIG_Struct             DBCONFIG       ; // Base Address + 0x80
   uint32_t                                        reserved24;
   uint32_t                                        reserved25;
   uint32_t                                        reserved26;
   struct SI32_ACCTR_A_COUNT0_Struct               COUNT0         ; // Base Address + 0x90
   uint32_t                                        reserved27;
   uint32_t                                        reserved28;
   uint32_t                                        reserved29;
   struct SI32_ACCTR_A_COUNT1_Struct               COUNT1         ; // Base Address + 0xa0
   uint32_t                                        reserved30;
   uint32_t                                        reserved31;
   uint32_t                                        reserved32;
   struct SI32_ACCTR_A_COMP0_Struct                COMP0          ; // Base Address + 0xb0
   uint32_t                                        reserved33;
   uint32_t                                        reserved34;
   uint32_t                                        reserved35;
   struct SI32_ACCTR_A_COMP1_Struct                COMP1          ; // Base Address + 0xc0
   uint32_t                                        reserved36;
   uint32_t                                        reserved37;
   uint32_t                                        reserved38;
   struct SI32_ACCTR_A_STATUS_Struct               STATUS         ; // Base Address + 0xd0
   uint32_t                                        reserved39;
   uint32_t                                        reserved40;
   uint32_t                                        reserved41;
   struct SI32_ACCTR_A_DEBUGEN_Struct              DEBUGEN        ; // Base Address + 0xe0
   uint32_t                                        reserved42;
   uint32_t                                        reserved43;
   uint32_t                                        reserved44;
} SI32_ACCTR_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_ACCTR_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

