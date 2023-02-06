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
// This file applies to the SIM3L1XX_RSTSRC_A module
//
// Script: 0.61
// Version: 1

#ifndef __SI32_RSTSRC_A_REGISTERS_H__
#define __SI32_RSTSRC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_RSTSRC_A_RESETEN_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 2;
         // Voltage Supply Monitor VBAT Reset Enable
         volatile uint32_t VMONREN: 1;
                  uint32_t reserved1: 1;
         // Missing Clock Detector Reset Enable
         volatile uint32_t MCDREN: 1;
         // Watchdog Timer Reset Enable
         volatile uint32_t WDTREN: 1;
         // Software Reset
         volatile uint32_t SWREN: 1;
         // Comparator 0 Reset Enable
         volatile uint32_t CMP0REN: 1;
         // Comparator 1 Reset Enable
         volatile uint32_t CMP1REN: 1;
         // Low Power Mode Charge Pump Supply Fail Reset Enable
         volatile uint32_t CPFREN: 1;
         // RTC0 Reset Enable
         volatile uint32_t RTC0REN: 1;
                  uint32_t reserved2: 16;
         // Low Power Mode Charge Pump Module Reset Enable
         volatile uint32_t CPMREN: 1;
         // UART0 Module Reset Enable
         volatile uint32_t UART0MREN: 1;
         // LCD0 Module Reset Enable
         volatile uint32_t LCD0MREN: 1;
         // ACCTR0 Module Reset Enable
         volatile uint32_t ACC0MREN: 1;
         // RTC0 Module Reset Enable
         volatile uint32_t RTC0MREN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RSTSRC_A_RESETEN_VMONREN_MASK  0x00000004
#define SI32_RSTSRC_A_RESETEN_VMONREN_SHIFT  2
// Disable the Voltage Supply Monitor VBAT event as a reset source.
#define SI32_RSTSRC_A_RESETEN_VMONREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_VMONREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_VMONREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_VMONREN_SHIFT)
// Enable the Voltage Supply Monitor VBAT event as a reset source.
#define SI32_RSTSRC_A_RESETEN_VMONREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_VMONREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_VMONREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_VMONREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_MCDREN_MASK  0x00000010
#define SI32_RSTSRC_A_RESETEN_MCDREN_SHIFT  4
// Disable the Missing Clock Detector event as a reset source.
#define SI32_RSTSRC_A_RESETEN_MCDREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_MCDREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_MCDREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_MCDREN_SHIFT)
// Enable the Missing Clock Detector event as a reset source.
#define SI32_RSTSRC_A_RESETEN_MCDREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_MCDREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_MCDREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_MCDREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_WDTREN_MASK  0x00000020
#define SI32_RSTSRC_A_RESETEN_WDTREN_SHIFT  5
// Disable the Watchdog Timer event as a reset source.
#define SI32_RSTSRC_A_RESETEN_WDTREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_WDTREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_WDTREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_WDTREN_SHIFT)
// Enable the Watchdog Timer event as a reset source.
#define SI32_RSTSRC_A_RESETEN_WDTREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_WDTREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_WDTREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_WDTREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_SWREN_MASK  0x00000040
#define SI32_RSTSRC_A_RESETEN_SWREN_SHIFT  6
// Do not generate a Software Reset.
#define SI32_RSTSRC_A_RESETEN_SWREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_SWREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_SWREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_SWREN_SHIFT)
// Generate a Software Reset.
#define SI32_RSTSRC_A_RESETEN_SWREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_SWREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_SWREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_SWREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_CMP0REN_MASK  0x00000080
#define SI32_RSTSRC_A_RESETEN_CMP0REN_SHIFT  7
// Disable the Comparator 0 event as a reset source.
#define SI32_RSTSRC_A_RESETEN_CMP0REN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_CMP0REN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CMP0REN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_CMP0REN_SHIFT)
// Enable the Comparator 0 event as a reset source.
#define SI32_RSTSRC_A_RESETEN_CMP0REN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_CMP0REN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CMP0REN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_CMP0REN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_CMP1REN_MASK  0x00000100
#define SI32_RSTSRC_A_RESETEN_CMP1REN_SHIFT  8
// Disable the Comparator 1 event as a reset source.
#define SI32_RSTSRC_A_RESETEN_CMP1REN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_CMP1REN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CMP1REN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_CMP1REN_SHIFT)
// Enable the Comparator 1 event as a reset source.
#define SI32_RSTSRC_A_RESETEN_CMP1REN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_CMP1REN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CMP1REN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_CMP1REN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_CPFREN_MASK  0x00000200
#define SI32_RSTSRC_A_RESETEN_CPFREN_SHIFT  9
// Disable the low power mode charge pump supply fail event as a reset source.
#define SI32_RSTSRC_A_RESETEN_CPFREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_CPFREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CPFREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_CPFREN_SHIFT)
// Enable the low power mode charge pump supply fail event as a reset source.
#define SI32_RSTSRC_A_RESETEN_CPFREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_CPFREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CPFREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_CPFREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_RTC0REN_MASK  0x00000400
#define SI32_RSTSRC_A_RESETEN_RTC0REN_SHIFT  10
// Disable the RTC0 event as a reset source.
#define SI32_RSTSRC_A_RESETEN_RTC0REN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_RTC0REN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_RTC0REN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_RTC0REN_SHIFT)
// Enable the RTC0 event as a reset source.
#define SI32_RSTSRC_A_RESETEN_RTC0REN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_RTC0REN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_RTC0REN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_RTC0REN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_CPMREN_MASK  0x08000000
#define SI32_RSTSRC_A_RESETEN_CPMREN_SHIFT  27
// Disable low power mode charge pump module resets.
#define SI32_RSTSRC_A_RESETEN_CPMREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_CPMREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CPMREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_CPMREN_SHIFT)
// Enable low power mode charge pump module resets.
#define SI32_RSTSRC_A_RESETEN_CPMREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_CPMREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_CPMREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_CPMREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_UART0MREN_MASK  0x10000000
#define SI32_RSTSRC_A_RESETEN_UART0MREN_SHIFT  28
// Disable UART0 module resets.
#define SI32_RSTSRC_A_RESETEN_UART0MREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_UART0MREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_UART0MREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_UART0MREN_SHIFT)
// Enable UART0 module resets.
#define SI32_RSTSRC_A_RESETEN_UART0MREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_UART0MREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_UART0MREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_UART0MREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_LCD0MREN_MASK  0x20000000
#define SI32_RSTSRC_A_RESETEN_LCD0MREN_SHIFT  29
// Disable LCD0 module resets.
#define SI32_RSTSRC_A_RESETEN_LCD0MREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_LCD0MREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_LCD0MREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_LCD0MREN_SHIFT)
// Enable LCD0 module resets.
#define SI32_RSTSRC_A_RESETEN_LCD0MREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_LCD0MREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_LCD0MREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_LCD0MREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_ACC0MREN_MASK  0x40000000
#define SI32_RSTSRC_A_RESETEN_ACC0MREN_SHIFT  30
// Disable ACCTR0 module resets.
#define SI32_RSTSRC_A_RESETEN_ACC0MREN_DISABLED_VALUE  0
#define SI32_RSTSRC_A_RESETEN_ACC0MREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_ACC0MREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_ACC0MREN_SHIFT)
// Enable ACCTR0 module resets.
#define SI32_RSTSRC_A_RESETEN_ACC0MREN_ENABLED_VALUE  1
#define SI32_RSTSRC_A_RESETEN_ACC0MREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_ACC0MREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_ACC0MREN_SHIFT)

#define SI32_RSTSRC_A_RESETEN_RTC0MREN_MASK  0x80000000
#define SI32_RSTSRC_A_RESETEN_RTC0MREN_SHIFT  31
// Disable RTC0 module resets.
#define SI32_RSTSRC_A_RESETEN_RTC0MREN_DISABLED_VALUE  0U
#define SI32_RSTSRC_A_RESETEN_RTC0MREN_DISABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_RTC0MREN_DISABLED_VALUE << SI32_RSTSRC_A_RESETEN_RTC0MREN_SHIFT)
// Enable RTC0 module resets.
#define SI32_RSTSRC_A_RESETEN_RTC0MREN_ENABLED_VALUE  1U
#define SI32_RSTSRC_A_RESETEN_RTC0MREN_ENABLED_U32 \
   (SI32_RSTSRC_A_RESETEN_RTC0MREN_ENABLED_VALUE << SI32_RSTSRC_A_RESETEN_RTC0MREN_SHIFT)



struct SI32_RSTSRC_A_RESETFLAG_Struct
{
   union
   {
      struct
      {
         // Pin Reset Flag
         volatile uint32_t PINRF: 1;
         // Power-On Reset Flag
         volatile uint32_t PORRF: 1;
         // Voltage Supply Monitor VBAT Reset Flag
         volatile uint32_t VMONRF: 1;
         // Core Reset Flag
         volatile uint32_t CORERF: 1;
         // Missing Clock Detector Reset Flag
         volatile uint32_t MCDRF: 1;
         // Watchdog Timer Reset Flag
         volatile uint32_t WDTRF: 1;
         // Software Reset Flag
         volatile uint32_t SWRF: 1;
         // Comparator 0 Reset Flag
         volatile uint32_t CMP0RF: 1;
         // Comparator 1 Reset Flag
         volatile uint32_t CMP1RF: 1;
         // Low Power Mode Charge Pump Supply Fail Reset Flag
         volatile uint32_t CPFRF: 1;
         // RTC0 Reset Flag
         volatile uint32_t RTC0RF: 1;
         // PMU Wakeup Reset Flag
         volatile uint32_t WAKERF: 1;
                  uint32_t reserved0: 20;
      };
      volatile uint32_t U32;
   };
};

#define SI32_RSTSRC_A_RESETFLAG_PINRF_MASK  0x00000001
#define SI32_RSTSRC_A_RESETFLAG_PINRF_SHIFT  0
// A /RESET pin event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_PINRF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_PINRF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_PINRF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_PINRF_SHIFT)
// A /RESET pin event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_PINRF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_PINRF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_PINRF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_PINRF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_PORRF_MASK  0x00000002
#define SI32_RSTSRC_A_RESETFLAG_PORRF_SHIFT  1
// A Power-On Reset event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_PORRF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_PORRF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_PORRF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_PORRF_SHIFT)
// A Power-On Reset event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_PORRF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_PORRF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_PORRF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_PORRF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_VMONRF_MASK  0x00000004
#define SI32_RSTSRC_A_RESETFLAG_VMONRF_SHIFT  2
// A Voltage Supply Monitor VBAT Reset event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_VMONRF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_VMONRF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_VMONRF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_VMONRF_SHIFT)
// A Voltage Supply Monitor VBAT Reset event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_VMONRF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_VMONRF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_VMONRF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_VMONRF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_CORERF_MASK  0x00000008
#define SI32_RSTSRC_A_RESETFLAG_CORERF_SHIFT  3
// A Core Reset event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_CORERF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_CORERF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CORERF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CORERF_SHIFT)
// A Core Reset event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_CORERF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_CORERF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CORERF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CORERF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_MCDRF_MASK  0x00000010
#define SI32_RSTSRC_A_RESETFLAG_MCDRF_SHIFT  4
// A Missing Clock Detector event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_MCDRF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_MCDRF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_MCDRF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_MCDRF_SHIFT)
// A Missing Clock Detector event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_MCDRF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_MCDRF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_MCDRF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_MCDRF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_WDTRF_MASK  0x00000020
#define SI32_RSTSRC_A_RESETFLAG_WDTRF_SHIFT  5
// A Watchdog Timer event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_WDTRF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_WDTRF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_WDTRF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_WDTRF_SHIFT)
// A Watchdog Timer event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_WDTRF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_WDTRF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_WDTRF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_WDTRF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_SWRF_MASK  0x00000040
#define SI32_RSTSRC_A_RESETFLAG_SWRF_SHIFT  6
// A Software Reset event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_SWRF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_SWRF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_SWRF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_SWRF_SHIFT)
// A Software Reset event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_SWRF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_SWRF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_SWRF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_SWRF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_CMP0RF_MASK  0x00000080
#define SI32_RSTSRC_A_RESETFLAG_CMP0RF_SHIFT  7
// A Comparator 0 event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_CMP0RF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_CMP0RF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CMP0RF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CMP0RF_SHIFT)
// A Comparator 0 event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_CMP0RF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_CMP0RF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CMP0RF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CMP0RF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_CMP1RF_MASK  0x00000100
#define SI32_RSTSRC_A_RESETFLAG_CMP1RF_SHIFT  8
// A Comparator 1 event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_CMP1RF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_CMP1RF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CMP1RF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CMP1RF_SHIFT)
// A Comparator 1 event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_CMP1RF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_CMP1RF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CMP1RF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CMP1RF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_CPFRF_MASK  0x00000200
#define SI32_RSTSRC_A_RESETFLAG_CPFRF_SHIFT  9
// A low power mode charge pump supply fail event did not cause the last system
// reset.
#define SI32_RSTSRC_A_RESETFLAG_CPFRF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_CPFRF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CPFRF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CPFRF_SHIFT)
// A low power mode charge pump supply fail event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_CPFRF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_CPFRF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_CPFRF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_CPFRF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_RTC0RF_MASK  0x00000400
#define SI32_RSTSRC_A_RESETFLAG_RTC0RF_SHIFT  10
// An RTC0 event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_RTC0RF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_RTC0RF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_RTC0RF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_RTC0RF_SHIFT)
// An RTC0 event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_RTC0RF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_RTC0RF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_RTC0RF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_RTC0RF_SHIFT)

#define SI32_RSTSRC_A_RESETFLAG_WAKERF_MASK  0x00000800
#define SI32_RSTSRC_A_RESETFLAG_WAKERF_SHIFT  11
// A PMU Wakeup event did not cause the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_WAKERF_NOT_SET_VALUE  0
#define SI32_RSTSRC_A_RESETFLAG_WAKERF_NOT_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_WAKERF_NOT_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_WAKERF_SHIFT)
// A PMU Wakeup event caused the last system reset.
#define SI32_RSTSRC_A_RESETFLAG_WAKERF_SET_VALUE  1
#define SI32_RSTSRC_A_RESETFLAG_WAKERF_SET_U32 \
   (SI32_RSTSRC_A_RESETFLAG_WAKERF_SET_VALUE << SI32_RSTSRC_A_RESETFLAG_WAKERF_SHIFT)



typedef struct SI32_RSTSRC_A_Struct
{
   struct SI32_RSTSRC_A_RESETEN_Struct             RESETEN        ; // Base Address + 0x0
   volatile uint32_t                               RESETEN_SET;
   volatile uint32_t                               RESETEN_CLR;
   uint32_t                                        reserved0;
   struct SI32_RSTSRC_A_RESETFLAG_Struct           RESETFLAG      ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
} SI32_RSTSRC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_RSTSRC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

