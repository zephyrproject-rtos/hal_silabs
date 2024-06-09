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

#ifndef __SI32_CAPSENSE_A_REGISTERS_H__
#define __SI32_CAPSENSE_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_CAPSENSE_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Start and Busy Flag
         volatile uint32_t BUSYF: 1;
         // Module Enable
         volatile uint32_t CSEN: 1;
         // Bias Enable
         volatile uint32_t BIASEN: 1;
         // Digital Comparator Polarity Select
         volatile uint32_t CMPPOL: 1;
         // Conversion Mode Select
         volatile uint32_t CMD: 2;
         // Conversion Rate
         volatile uint32_t CNVR: 2;
         // Accumulator Mode Select
         volatile uint32_t ACCMD: 3;
         // Multiple Channel Enable
         volatile uint32_t MCEN: 1;
         // Start of Conversion Mode Select
         volatile uint32_t CSCM: 4;
         // Pin Monitor Mode
         volatile uint32_t PMMD: 2;
         // Pin Monitor Event Flag
         volatile uint32_t PMEF: 1;
                  uint32_t reserved0: 1;
         // Threshold Comparator Enable
         volatile uint32_t CMPEN: 1;
         // Conversion Done Interrupt Enable
         volatile uint32_t CDIEN: 1;
         // End-of-Scan Interrupt Enable
         volatile uint32_t EOSIEN: 1;
                  uint32_t reserved1: 1;
         // Threshold Comparator Interrupt Flag
         volatile uint32_t CMPI: 1;
         // Conversion Done Interrupt Flag
         volatile uint32_t CDI: 1;
         // End-of-Scan Interrupt Flag
         volatile uint32_t EOSI: 1;
                  uint32_t reserved2: 5;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CAPSENSE_A_CONTROL_BUSYF_MASK  0x00000001
#define SI32_CAPSENSE_A_CONTROL_BUSYF_SHIFT  0
// Read: A capacitive sensing conversion is complete or a conversion is not
// currently in progress. Write: No effect.
#define SI32_CAPSENSE_A_CONTROL_BUSYF_IDLE_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_BUSYF_IDLE_U32 \
   (SI32_CAPSENSE_A_CONTROL_BUSYF_IDLE_VALUE << SI32_CAPSENSE_A_CONTROL_BUSYF_SHIFT)
// Read: A capacitive sensing conversion is in progress. Write: Initiate a
// capacitive sensing conversion if BUSYF is selected as the start of conversion
// source.
#define SI32_CAPSENSE_A_CONTROL_BUSYF_BUSY_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_BUSYF_BUSY_U32 \
   (SI32_CAPSENSE_A_CONTROL_BUSYF_BUSY_VALUE << SI32_CAPSENSE_A_CONTROL_BUSYF_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CSEN_MASK  0x00000002
#define SI32_CAPSENSE_A_CONTROL_CSEN_SHIFT  1
// Disable the capacitive sensing module.
#define SI32_CAPSENSE_A_CONTROL_CSEN_DISABLED_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CSEN_DISABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSEN_DISABLED_VALUE << SI32_CAPSENSE_A_CONTROL_CSEN_SHIFT)
// Enable the capacitive sensing module.
#define SI32_CAPSENSE_A_CONTROL_CSEN_ENABLED_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CSEN_ENABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSEN_ENABLED_VALUE << SI32_CAPSENSE_A_CONTROL_CSEN_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_BIASEN_MASK  0x00000004
#define SI32_CAPSENSE_A_CONTROL_BIASEN_SHIFT  2
// Disable the bias.
#define SI32_CAPSENSE_A_CONTROL_BIASEN_DISABLED_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_BIASEN_DISABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_BIASEN_DISABLED_VALUE << SI32_CAPSENSE_A_CONTROL_BIASEN_SHIFT)
// Enable the bias.
#define SI32_CAPSENSE_A_CONTROL_BIASEN_ENABLED_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_BIASEN_ENABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_BIASEN_ENABLED_VALUE << SI32_CAPSENSE_A_CONTROL_BIASEN_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CMPPOL_MASK  0x00000008
#define SI32_CAPSENSE_A_CONTROL_CMPPOL_SHIFT  3
// The digital comparator generates an interrupt if the conversion is greater than
// the CSTH threshold.
#define SI32_CAPSENSE_A_CONTROL_CMPPOL_GT_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CMPPOL_GT_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMPPOL_GT_VALUE << SI32_CAPSENSE_A_CONTROL_CMPPOL_SHIFT)
// The digital comparator generates an interrupt if the conversion is less than or
// equal to the CSTH threshold.
#define SI32_CAPSENSE_A_CONTROL_CMPPOL_LTE_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CMPPOL_LTE_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMPPOL_LTE_VALUE << SI32_CAPSENSE_A_CONTROL_CMPPOL_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CMD_MASK  0x00000030
#define SI32_CAPSENSE_A_CONTROL_CMD_SHIFT  4
// Single Conversion Mode: One conversion occurs on a single channel.
#define SI32_CAPSENSE_A_CONTROL_CMD_SINGLE_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CMD_SINGLE_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMD_SINGLE_VALUE << SI32_CAPSENSE_A_CONTROL_CMD_SHIFT)
// Single Scan Mode: One conversion on each channel selected by SCANEN occurs. An
// end-of-scan interrupt indicates all channels have been measured.
#define SI32_CAPSENSE_A_CONTROL_CMD_SCAN_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CMD_SCAN_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMD_SCAN_VALUE << SI32_CAPSENSE_A_CONTROL_CMD_SHIFT)
// Continuous Single Conversion Mode: Continuously converts on a single channel.
// This operation ends only if the module is disabled (CSEN = 0) or if a compare
// threshold event occurs (CMPI = 1).
#define SI32_CAPSENSE_A_CONTROL_CMD_CONT_SINGLE_VALUE  2
#define SI32_CAPSENSE_A_CONTROL_CMD_CONT_SINGLE_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMD_CONT_SINGLE_VALUE << SI32_CAPSENSE_A_CONTROL_CMD_SHIFT)
// Continuous Scan Mode: Continuously loops through and converts on all the
// channels selected by SCANEN. This operation ends only if the module is disabled
// (CSEN = 0) or if a compare threshold event occurs (CMPI = 1).
#define SI32_CAPSENSE_A_CONTROL_CMD_CONT_SCAN_VALUE  3
#define SI32_CAPSENSE_A_CONTROL_CMD_CONT_SCAN_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMD_CONT_SCAN_VALUE << SI32_CAPSENSE_A_CONTROL_CMD_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CNVR_MASK  0x000000C0
#define SI32_CAPSENSE_A_CONTROL_CNVR_SHIFT  6
// Conversions last 12 internal CAPSENSE clocks and results are 12 bits in length.
#define SI32_CAPSENSE_A_CONTROL_CNVR_12BIT_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CNVR_12BIT_U32 \
   (SI32_CAPSENSE_A_CONTROL_CNVR_12BIT_VALUE << SI32_CAPSENSE_A_CONTROL_CNVR_SHIFT)
// Conversions last 13 internal CAPSENSE clocks and results are 13 bits in length.
#define SI32_CAPSENSE_A_CONTROL_CNVR_13BIT_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CNVR_13BIT_U32 \
   (SI32_CAPSENSE_A_CONTROL_CNVR_13BIT_VALUE << SI32_CAPSENSE_A_CONTROL_CNVR_SHIFT)
// Conversions last 14 internal CAPSENSE clocks and results are 14 bits in length.
#define SI32_CAPSENSE_A_CONTROL_CNVR_14BIT_VALUE  2
#define SI32_CAPSENSE_A_CONTROL_CNVR_14BIT_U32 \
   (SI32_CAPSENSE_A_CONTROL_CNVR_14BIT_VALUE << SI32_CAPSENSE_A_CONTROL_CNVR_SHIFT)
// Conversions last 16 internal CAPSENSE clocks and results are 16 bits in length.
#define SI32_CAPSENSE_A_CONTROL_CNVR_16BIT_VALUE  3
#define SI32_CAPSENSE_A_CONTROL_CNVR_16BIT_U32 \
   (SI32_CAPSENSE_A_CONTROL_CNVR_16BIT_VALUE << SI32_CAPSENSE_A_CONTROL_CNVR_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_ACCMD_MASK  0x00000700
#define SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT  8
// Accumulate 1 sample.
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_1_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_1_U32 \
   (SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_1_VALUE << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT)
// Accumulate 4 samples.
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_4_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_4_U32 \
   (SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_4_VALUE << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT)
// Accumulate 8 samples.
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_8_VALUE  2
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_8_U32 \
   (SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_8_VALUE << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT)
// Accumulate 16 samples.
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_16_VALUE  3
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_16_U32 \
   (SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_16_VALUE << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT)
// Accumulate 32 samples.
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_32_VALUE  4
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_32_U32 \
   (SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_32_VALUE << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT)
// Accumulate 64 samples.
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_64_VALUE  5
#define SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_64_U32 \
   (SI32_CAPSENSE_A_CONTROL_ACCMD_ACC_64_VALUE << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_MCEN_MASK  0x00000800
#define SI32_CAPSENSE_A_CONTROL_MCEN_SHIFT  11
// Disable the multiple channel measurement feature.
#define SI32_CAPSENSE_A_CONTROL_MCEN_DISABLED_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_MCEN_DISABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_MCEN_DISABLED_VALUE << SI32_CAPSENSE_A_CONTROL_MCEN_SHIFT)
// Enable the multiple channel measurement feature.
#define SI32_CAPSENSE_A_CONTROL_MCEN_ENABLED_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_MCEN_ENABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_MCEN_ENABLED_VALUE << SI32_CAPSENSE_A_CONTROL_MCEN_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CSCM_MASK  0x0000F000
#define SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT  12
// The CSnT0 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT0_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT0_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT0_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT1 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT1_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT1_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT1_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT2 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT2_VALUE  2
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT2_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT2_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT3 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT3_VALUE  3
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT3_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT3_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT4 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT4_VALUE  4
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT4_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT4_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT5 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT5_VALUE  5
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT5_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT5_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT6 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT6_VALUE  6
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT6_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT6_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT7 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT7_VALUE  7
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT7_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT7_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT8 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT8_VALUE  8
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT8_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT8_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT9 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT9_VALUE  9
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT9_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT9_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT10 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT10_VALUE  10
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT10_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT10_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT11 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT11_VALUE  11
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT11_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT11_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT12 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT12_VALUE  12
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT12_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT12_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT13 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT13_VALUE  13
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT13_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT13_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT14 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT14_VALUE  14
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT14_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT14_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)
// The CSnT15 trigger source starts conversions.
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT15_VALUE  15
#define SI32_CAPSENSE_A_CONTROL_CSCM_CSNT15_U32 \
   (SI32_CAPSENSE_A_CONTROL_CSCM_CSNT15_VALUE << SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_PMMD_MASK  0x00030000
#define SI32_CAPSENSE_A_CONTROL_PMMD_SHIFT  16
// Always retry on a pin state change.
#define SI32_CAPSENSE_A_CONTROL_PMMD_ALWAYS_RETRY_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_PMMD_ALWAYS_RETRY_U32 \
   (SI32_CAPSENSE_A_CONTROL_PMMD_ALWAYS_RETRY_VALUE << SI32_CAPSENSE_A_CONTROL_PMMD_SHIFT)
// Retry up to twice on consecutive bit cycles.
#define SI32_CAPSENSE_A_CONTROL_PMMD_RETRY_TWICE_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_PMMD_RETRY_TWICE_U32 \
   (SI32_CAPSENSE_A_CONTROL_PMMD_RETRY_TWICE_VALUE << SI32_CAPSENSE_A_CONTROL_PMMD_SHIFT)
// Retry up to four times on consecutive bit cycles.
#define SI32_CAPSENSE_A_CONTROL_PMMD_RETRY_FOUR_TIMES_VALUE  2
#define SI32_CAPSENSE_A_CONTROL_PMMD_RETRY_FOUR_TIMES_U32 \
   (SI32_CAPSENSE_A_CONTROL_PMMD_RETRY_FOUR_TIMES_VALUE << SI32_CAPSENSE_A_CONTROL_PMMD_SHIFT)
// Ignore monitored signal state change.
#define SI32_CAPSENSE_A_CONTROL_PMMD_DO_NOT_RETRY_VALUE  3
#define SI32_CAPSENSE_A_CONTROL_PMMD_DO_NOT_RETRY_U32 \
   (SI32_CAPSENSE_A_CONTROL_PMMD_DO_NOT_RETRY_VALUE << SI32_CAPSENSE_A_CONTROL_PMMD_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_PMEF_MASK  0x00040000
#define SI32_CAPSENSE_A_CONTROL_PMEF_SHIFT  18
// A retry did not occur due to a pin monitor event during the last conversion.
#define SI32_CAPSENSE_A_CONTROL_PMEF_NOT_SET_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_PMEF_NOT_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_PMEF_NOT_SET_VALUE << SI32_CAPSENSE_A_CONTROL_PMEF_SHIFT)
// A retry occurred due to a pin monitor event during the last conversion.
#define SI32_CAPSENSE_A_CONTROL_PMEF_SET_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_PMEF_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_PMEF_SET_VALUE << SI32_CAPSENSE_A_CONTROL_PMEF_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CMPEN_MASK  0x00100000
#define SI32_CAPSENSE_A_CONTROL_CMPEN_SHIFT  20
// Disable the threshold comparator.
#define SI32_CAPSENSE_A_CONTROL_CMPEN_DISABLED_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CMPEN_DISABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMPEN_DISABLED_VALUE << SI32_CAPSENSE_A_CONTROL_CMPEN_SHIFT)
// Enable the threshold comparator.
#define SI32_CAPSENSE_A_CONTROL_CMPEN_ENABLED_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CMPEN_ENABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMPEN_ENABLED_VALUE << SI32_CAPSENSE_A_CONTROL_CMPEN_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CDIEN_MASK  0x00200000
#define SI32_CAPSENSE_A_CONTROL_CDIEN_SHIFT  21
// Disable the single conversion done interrupt.
#define SI32_CAPSENSE_A_CONTROL_CDIEN_DISABLED_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CDIEN_DISABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_CDIEN_DISABLED_VALUE << SI32_CAPSENSE_A_CONTROL_CDIEN_SHIFT)
// Enable the single conversion done interrupt.
#define SI32_CAPSENSE_A_CONTROL_CDIEN_ENABLED_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CDIEN_ENABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_CDIEN_ENABLED_VALUE << SI32_CAPSENSE_A_CONTROL_CDIEN_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_EOSIEN_MASK  0x00400000
#define SI32_CAPSENSE_A_CONTROL_EOSIEN_SHIFT  22
// Disable the single scan end-of-scan interrupt.
#define SI32_CAPSENSE_A_CONTROL_EOSIEN_DISABLED_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_EOSIEN_DISABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_EOSIEN_DISABLED_VALUE << SI32_CAPSENSE_A_CONTROL_EOSIEN_SHIFT)
// Enable the single scan end-of-scan interrupt.
#define SI32_CAPSENSE_A_CONTROL_EOSIEN_ENABLED_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_EOSIEN_ENABLED_U32 \
   (SI32_CAPSENSE_A_CONTROL_EOSIEN_ENABLED_VALUE << SI32_CAPSENSE_A_CONTROL_EOSIEN_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CMPI_MASK  0x01000000
#define SI32_CAPSENSE_A_CONTROL_CMPI_SHIFT  24
// The capacitive sensing result did not cause a compare threshold interrupt.
#define SI32_CAPSENSE_A_CONTROL_CMPI_NOT_SET_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CMPI_NOT_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMPI_NOT_SET_VALUE << SI32_CAPSENSE_A_CONTROL_CMPI_SHIFT)
// The capacitive sensing result caused a compare threshold interrupt.
#define SI32_CAPSENSE_A_CONTROL_CMPI_SET_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CMPI_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_CMPI_SET_VALUE << SI32_CAPSENSE_A_CONTROL_CMPI_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_CDI_MASK  0x02000000
#define SI32_CAPSENSE_A_CONTROL_CDI_SHIFT  25
// Read: The CAPSENSEn module has not completed a data conversion since the last
// time CDI was cleared. Write: Clear the interrupt.
#define SI32_CAPSENSE_A_CONTROL_CDI_NOT_SET_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_CDI_NOT_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_CDI_NOT_SET_VALUE << SI32_CAPSENSE_A_CONTROL_CDI_SHIFT)
// Read: The CAPSENSEn module completed a data conversion. Write: Force a
// conversion complete interrupt.
#define SI32_CAPSENSE_A_CONTROL_CDI_SET_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_CDI_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_CDI_SET_VALUE << SI32_CAPSENSE_A_CONTROL_CDI_SHIFT)

#define SI32_CAPSENSE_A_CONTROL_EOSI_MASK  0x04000000
#define SI32_CAPSENSE_A_CONTROL_EOSI_SHIFT  26
// The CAPSENSEn module has not completed a scan since the last time EOSI was
// cleared.
#define SI32_CAPSENSE_A_CONTROL_EOSI_NOT_SET_VALUE  0
#define SI32_CAPSENSE_A_CONTROL_EOSI_NOT_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_EOSI_NOT_SET_VALUE << SI32_CAPSENSE_A_CONTROL_EOSI_SHIFT)
// The CAPSENSEn module completed a scan.
#define SI32_CAPSENSE_A_CONTROL_EOSI_SET_VALUE  1
#define SI32_CAPSENSE_A_CONTROL_EOSI_SET_U32 \
   (SI32_CAPSENSE_A_CONTROL_EOSI_SET_VALUE << SI32_CAPSENSE_A_CONTROL_EOSI_SHIFT)



struct SI32_CAPSENSE_A_MODE_Struct
{
   union
   {
      struct
      {
         // Capacitance Gain Select
         volatile uint32_t CGSEL: 3;
                  uint32_t reserved0: 3;
         // Ramp Selection
         volatile uint32_t RAMPSEL: 2;
         // Output Current Select
         volatile uint32_t IASEL: 3;
                  uint32_t reserved1: 1;
         // Discharge Time Select
         volatile uint32_t DTSEL: 3;
                  uint32_t reserved2: 17;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CAPSENSE_A_MODE_CGSEL_MASK  0x00000007
#define SI32_CAPSENSE_A_MODE_CGSEL_SHIFT  0

#define SI32_CAPSENSE_A_MODE_RAMPSEL_MASK  0x000000C0
#define SI32_CAPSENSE_A_MODE_RAMPSEL_SHIFT  6

#define SI32_CAPSENSE_A_MODE_IASEL_MASK  0x00000700
#define SI32_CAPSENSE_A_MODE_IASEL_SHIFT  8

#define SI32_CAPSENSE_A_MODE_DTSEL_MASK  0x00007000
#define SI32_CAPSENSE_A_MODE_DTSEL_SHIFT  12



struct SI32_CAPSENSE_A_DATA_Struct
{
   union
   {
      struct
      {
         // Capacitive Sensing Data
         volatile uint16_t DATA_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CAPSENSE_A_DATA_DATA_MASK  0x0000FFFF
#define SI32_CAPSENSE_A_DATA_DATA_SHIFT  0



struct SI32_CAPSENSE_A_SCAN_Struct
{
   union
   {
      struct
      {
         // Channel Scan Enable
         volatile uint16_t SCANEN;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CAPSENSE_A_SCAN_SCANEN_MASK  0x0000FFFF
#define SI32_CAPSENSE_A_SCAN_SCANEN_SHIFT  0



struct SI32_CAPSENSE_A_CSTH_Struct
{
   union
   {
      struct
      {
         // Compare Threshold
         volatile uint16_t CSTH_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CAPSENSE_A_CSTH_CSTH_MASK  0x0000FFFF
#define SI32_CAPSENSE_A_CSTH_CSTH_SHIFT  0



struct SI32_CAPSENSE_A_MUX_Struct
{
   union
   {
      struct
      {
         // Mux Channel Select
         volatile uint32_t CSMX: 4;
                  uint32_t reserved0: 3;
         // Channel Disconnect
         volatile uint32_t CSDISC: 1;
                  uint32_t reserved1: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CAPSENSE_A_MUX_CSMX_MASK  0x0000000F
#define SI32_CAPSENSE_A_MUX_CSMX_SHIFT  0
// Select CSn.0.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN0_VALUE  0
#define SI32_CAPSENSE_A_MUX_CSMX_CSN0_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN0_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.1.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN1_VALUE  1
#define SI32_CAPSENSE_A_MUX_CSMX_CSN1_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN1_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.2.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN2_VALUE  2
#define SI32_CAPSENSE_A_MUX_CSMX_CSN2_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN2_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.3.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN3_VALUE  3
#define SI32_CAPSENSE_A_MUX_CSMX_CSN3_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN3_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.4.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN4_VALUE  4
#define SI32_CAPSENSE_A_MUX_CSMX_CSN4_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN4_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.5.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN5_VALUE  5
#define SI32_CAPSENSE_A_MUX_CSMX_CSN5_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN5_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.6.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN6_VALUE  6
#define SI32_CAPSENSE_A_MUX_CSMX_CSN6_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN6_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.7.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN7_VALUE  7
#define SI32_CAPSENSE_A_MUX_CSMX_CSN7_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN7_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.8.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN8_VALUE  8
#define SI32_CAPSENSE_A_MUX_CSMX_CSN8_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN8_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.9.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN9_VALUE  9
#define SI32_CAPSENSE_A_MUX_CSMX_CSN9_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN9_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.10.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN10_VALUE  10
#define SI32_CAPSENSE_A_MUX_CSMX_CSN10_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN10_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.11.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN11_VALUE  11
#define SI32_CAPSENSE_A_MUX_CSMX_CSN11_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN11_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.12.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN12_VALUE  12
#define SI32_CAPSENSE_A_MUX_CSMX_CSN12_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN12_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.13.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN13_VALUE  13
#define SI32_CAPSENSE_A_MUX_CSMX_CSN13_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN13_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.14.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN14_VALUE  14
#define SI32_CAPSENSE_A_MUX_CSMX_CSN14_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN14_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)
// Select CSn.15.
#define SI32_CAPSENSE_A_MUX_CSMX_CSN15_VALUE  15
#define SI32_CAPSENSE_A_MUX_CSMX_CSN15_U32 \
   (SI32_CAPSENSE_A_MUX_CSMX_CSN15_VALUE << SI32_CAPSENSE_A_MUX_CSMX_SHIFT)

#define SI32_CAPSENSE_A_MUX_CSDISC_MASK  0x00000080
#define SI32_CAPSENSE_A_MUX_CSDISC_SHIFT  7
// Connect the capacitive sensing circuit to the selected channel.
#define SI32_CAPSENSE_A_MUX_CSDISC_CONNECT_VALUE  0
#define SI32_CAPSENSE_A_MUX_CSDISC_CONNECT_U32 \
   (SI32_CAPSENSE_A_MUX_CSDISC_CONNECT_VALUE << SI32_CAPSENSE_A_MUX_CSDISC_SHIFT)
// Disconnect the capacitive sensing input channel.
#define SI32_CAPSENSE_A_MUX_CSDISC_DISCONNECT_VALUE  1
#define SI32_CAPSENSE_A_MUX_CSDISC_DISCONNECT_U32 \
   (SI32_CAPSENSE_A_MUX_CSDISC_DISCONNECT_VALUE << SI32_CAPSENSE_A_MUX_CSDISC_SHIFT)



typedef struct SI32_CAPSENSE_A_Struct
{
   struct SI32_CAPSENSE_A_CONTROL_Struct           CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_CAPSENSE_A_MODE_Struct              MODE           ; // Base Address + 0x10
   volatile uint32_t                               MODE_SET;
   volatile uint32_t                               MODE_CLR;
   uint32_t                                        reserved1;
   struct SI32_CAPSENSE_A_DATA_Struct              DATA           ; // Base Address + 0x20
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   struct SI32_CAPSENSE_A_SCAN_Struct              SCAN           ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_CAPSENSE_A_CSTH_Struct              CSTH           ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   struct SI32_CAPSENSE_A_MUX_Struct               MUX            ; // Base Address + 0x50
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   uint32_t                                        reserved14[4];
   uint32_t                                        reserved15[4];
} SI32_CAPSENSE_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_CAPSENSE_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

