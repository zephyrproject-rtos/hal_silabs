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
// This file applies to the SIM3L1XX_PMU_A module
//
// Script: 0.61
// Version: 1

#ifndef __SI32_PMU_A_REGISTERS_H__
#define __SI32_PMU_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_PMU_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Wakeup Source Clear
         volatile uint32_t WAKECLR: 1;
                  uint32_t reserved0: 2;
         // Pin Wake Match Enable
         volatile uint32_t PWAKEEN: 1;
         // PMU Asleep Pin Enable
         volatile uint32_t PMUASLPEN: 1;
         // Low Power Charge Pump Voltage Monitor Enable
         volatile uint32_t CPMONEN: 1;
         // Low Power Charge Pump Voltage Monitor Interrupt Enable
         volatile uint32_t CPMONIEN: 1;
                  uint32_t reserved1: 9;
         // RAM 0 Retention Enable
         volatile uint32_t RAM0REN: 1;
         // RAM 1 Retention Enable
         volatile uint32_t RAM1REN: 1;
         // RAM 2 Retention Enable
         volatile uint32_t RAM2REN: 1;
         // RAM 3 Retention Enable
         volatile uint32_t RAM3REN: 1;
         // RAM 4 Retention Enable
         volatile uint32_t RAM4REN: 1;
         // RAM 5 Retention Enable
         volatile uint32_t RAM5REN: 1;
         // RAM 6 Retention Enable
         volatile uint32_t RAM6REN: 1;
         // RAM 7 Retention Enable
         volatile uint32_t RAM7REN: 1;
                  uint32_t reserved2: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_CONTROL_WAKECLR_MASK  0x00000001
#define SI32_PMU_A_CONTROL_WAKECLR_SHIFT  0
// Clear all wakeup sources.
#define SI32_PMU_A_CONTROL_WAKECLR_CLEAR_VALUE  0
#define SI32_PMU_A_CONTROL_WAKECLR_CLEAR_U32 \
   (SI32_PMU_A_CONTROL_WAKECLR_CLEAR_VALUE << SI32_PMU_A_CONTROL_WAKECLR_SHIFT)

#define SI32_PMU_A_CONTROL_PWAKEEN_MASK  0x00000008
#define SI32_PMU_A_CONTROL_PWAKEEN_SHIFT  3
// Disable Pin Wake.
#define SI32_PMU_A_CONTROL_PWAKEEN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_PWAKEEN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_PWAKEEN_DISABLED_VALUE << SI32_PMU_A_CONTROL_PWAKEEN_SHIFT)
// Enable Pin Wake.
#define SI32_PMU_A_CONTROL_PWAKEEN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_PWAKEEN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_PWAKEEN_ENABLED_VALUE << SI32_PMU_A_CONTROL_PWAKEEN_SHIFT)

#define SI32_PMU_A_CONTROL_PMUASLPEN_MASK  0x00000010
#define SI32_PMU_A_CONTROL_PMUASLPEN_SHIFT  4
// Disable the PMU Asleep pin.
#define SI32_PMU_A_CONTROL_PMUASLPEN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_PMUASLPEN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_PMUASLPEN_DISABLED_VALUE << SI32_PMU_A_CONTROL_PMUASLPEN_SHIFT)
// Enable the PMU Asleep pin.
#define SI32_PMU_A_CONTROL_PMUASLPEN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_PMUASLPEN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_PMUASLPEN_ENABLED_VALUE << SI32_PMU_A_CONTROL_PMUASLPEN_SHIFT)

#define SI32_PMU_A_CONTROL_CPMONEN_MASK  0x00000020
#define SI32_PMU_A_CONTROL_CPMONEN_SHIFT  5
// Disable the low power charge pump voltage monitor.
#define SI32_PMU_A_CONTROL_CPMONEN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_CPMONEN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_CPMONEN_DISABLED_VALUE << SI32_PMU_A_CONTROL_CPMONEN_SHIFT)
// Enable the low power charge pump voltage monitor.
#define SI32_PMU_A_CONTROL_CPMONEN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_CPMONEN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_CPMONEN_ENABLED_VALUE << SI32_PMU_A_CONTROL_CPMONEN_SHIFT)

#define SI32_PMU_A_CONTROL_CPMONIEN_MASK  0x00000040
#define SI32_PMU_A_CONTROL_CPMONIEN_SHIFT  6
// Disable the low power charge pump voltage monitor interrupt.
#define SI32_PMU_A_CONTROL_CPMONIEN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_CPMONIEN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_CPMONIEN_DISABLED_VALUE << SI32_PMU_A_CONTROL_CPMONIEN_SHIFT)
// Enable the low power charge pump voltage monitor interrupt.
#define SI32_PMU_A_CONTROL_CPMONIEN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_CPMONIEN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_CPMONIEN_ENABLED_VALUE << SI32_PMU_A_CONTROL_CPMONIEN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM0REN_MASK  0x00010000
#define SI32_PMU_A_CONTROL_RAM0REN_SHIFT  16
// Disable power to RAM 0 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM0REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM0REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM0REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM0REN_SHIFT)
// Enable power to RAM 0 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM0REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM0REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM0REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM0REN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM1REN_MASK  0x00020000
#define SI32_PMU_A_CONTROL_RAM1REN_SHIFT  17
// Disable power to RAM 1 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM1REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM1REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM1REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM1REN_SHIFT)
// Enable power to RAM 1 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM1REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM1REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM1REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM1REN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM2REN_MASK  0x00040000
#define SI32_PMU_A_CONTROL_RAM2REN_SHIFT  18
// Disable power to RAM 2 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM2REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM2REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM2REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM2REN_SHIFT)
// Enable power to RAM 2 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM2REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM2REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM2REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM2REN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM3REN_MASK  0x00080000
#define SI32_PMU_A_CONTROL_RAM3REN_SHIFT  19
// Disable power to RAM 3 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM3REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM3REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM3REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM3REN_SHIFT)
// Enable power to RAM 3 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM3REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM3REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM3REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM3REN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM4REN_MASK  0x00100000
#define SI32_PMU_A_CONTROL_RAM4REN_SHIFT  20
// Disable power to RAM 4 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM4REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM4REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM4REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM4REN_SHIFT)
// Enable power to RAM 4 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM4REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM4REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM4REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM4REN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM5REN_MASK  0x00200000
#define SI32_PMU_A_CONTROL_RAM5REN_SHIFT  21
// Disable power to RAM 5 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM5REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM5REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM5REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM5REN_SHIFT)
// Enable power to RAM 5 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM5REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM5REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM5REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM5REN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM6REN_MASK  0x00400000
#define SI32_PMU_A_CONTROL_RAM6REN_SHIFT  22
// Disable power to RAM 6 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM6REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM6REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM6REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM6REN_SHIFT)
// Enable power to RAM 6 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM6REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM6REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM6REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM6REN_SHIFT)

#define SI32_PMU_A_CONTROL_RAM7REN_MASK  0x00800000
#define SI32_PMU_A_CONTROL_RAM7REN_SHIFT  23
// Disable power to RAM 7 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM7REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_RAM7REN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM7REN_DISABLED_VALUE << SI32_PMU_A_CONTROL_RAM7REN_SHIFT)
// Enable power to RAM 7 during sleep (4 kB addresses from 0x20000000 to
// 0x20000FFF).
#define SI32_PMU_A_CONTROL_RAM7REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_RAM7REN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_RAM7REN_ENABLED_VALUE << SI32_PMU_A_CONTROL_RAM7REN_SHIFT)



struct SI32_PMU_A_CONFIG_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 5;
         // VDRV Switch Mode
         volatile uint32_t VDRVSMD: 2;
                  uint32_t reserved1: 1;
         // Low Power Charge Pump Enable
         volatile uint32_t CPEN: 1;
                  uint32_t reserved2: 1;
         // Charge Pump Load Setting
         volatile uint32_t CPLOAD: 2;
                  uint32_t reserved3: 20;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_CONFIG_VDRVSMD_MASK  0x00000060
#define SI32_PMU_A_CONFIG_VDRVSMD_SHIFT  5
// High-Z.
#define SI32_PMU_A_CONFIG_VDRVSMD_HIGHZ_VALUE  0
#define SI32_PMU_A_CONFIG_VDRVSMD_HIGHZ_U32 \
   (SI32_PMU_A_CONFIG_VDRVSMD_HIGHZ_VALUE << SI32_PMU_A_CONFIG_VDRVSMD_SHIFT)
// VBAT connected to VDRV.
#define SI32_PMU_A_CONFIG_VDRVSMD_VBAT_VALUE  2
#define SI32_PMU_A_CONFIG_VDRVSMD_VBAT_U32 \
   (SI32_PMU_A_CONFIG_VDRVSMD_VBAT_VALUE << SI32_PMU_A_CONFIG_VDRVSMD_SHIFT)
// DC-DC output connected to VDRV.
#define SI32_PMU_A_CONFIG_VDRVSMD_VDC_VALUE  3
#define SI32_PMU_A_CONFIG_VDRVSMD_VDC_U32 \
   (SI32_PMU_A_CONFIG_VDRVSMD_VDC_VALUE << SI32_PMU_A_CONFIG_VDRVSMD_SHIFT)

#define SI32_PMU_A_CONFIG_CPEN_MASK  0x00000100
#define SI32_PMU_A_CONFIG_CPEN_SHIFT  8
#define SI32_PMU_A_CONFIG_CPEN_DISABLED_VALUE  0
#define SI32_PMU_A_CONFIG_CPEN_DISABLED_U32 \
   (SI32_PMU_A_CONFIG_CPEN_DISABLED_VALUE << SI32_PMU_A_CONFIG_CPEN_SHIFT)
#define SI32_PMU_A_CONFIG_CPEN_ENABLED_VALUE  1
#define SI32_PMU_A_CONFIG_CPEN_ENABLED_U32 \
   (SI32_PMU_A_CONFIG_CPEN_ENABLED_VALUE << SI32_PMU_A_CONFIG_CPEN_SHIFT)

#define SI32_PMU_A_CONFIG_CPLOAD_MASK  0x00000C00
#define SI32_PMU_A_CONFIG_CPLOAD_SHIFT  10



struct SI32_PMU_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Power Mode 8 Exited Flag
         volatile uint32_t PM8EF: 1;
         // Pin Wake Status Flag
         volatile uint32_t PWAKEF: 1;
         // Power-On Reset Flag
         volatile uint32_t PORF: 1;
         // Low Power Charge Pump Voltage Monitor Status
         volatile uint32_t CPSTS: 1;
                  uint32_t reserved0: 28;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_STATUS_PM8EF_MASK  0x00000001
#define SI32_PMU_A_STATUS_PM8EF_SHIFT  0
// The device has not exited Power Mode 8.
#define SI32_PMU_A_STATUS_PM8EF_NOT_SET_VALUE  0
#define SI32_PMU_A_STATUS_PM8EF_NOT_SET_U32 \
   (SI32_PMU_A_STATUS_PM8EF_NOT_SET_VALUE << SI32_PMU_A_STATUS_PM8EF_SHIFT)
// The device has exited Power Mode 8. This bit must be cleared by firmware.
#define SI32_PMU_A_STATUS_PM8EF_SET_VALUE  1
#define SI32_PMU_A_STATUS_PM8EF_SET_U32 \
   (SI32_PMU_A_STATUS_PM8EF_SET_VALUE << SI32_PMU_A_STATUS_PM8EF_SHIFT)

#define SI32_PMU_A_STATUS_PWAKEF_MASK  0x00000002
#define SI32_PMU_A_STATUS_PWAKEF_SHIFT  1
// No Pin Wake condition is active.
#define SI32_PMU_A_STATUS_PWAKEF_NOT_SET_VALUE  0
#define SI32_PMU_A_STATUS_PWAKEF_NOT_SET_U32 \
   (SI32_PMU_A_STATUS_PWAKEF_NOT_SET_VALUE << SI32_PMU_A_STATUS_PWAKEF_SHIFT)
// A Pin Wake condition is active.
#define SI32_PMU_A_STATUS_PWAKEF_SET_VALUE  1
#define SI32_PMU_A_STATUS_PWAKEF_SET_U32 \
   (SI32_PMU_A_STATUS_PWAKEF_SET_VALUE << SI32_PMU_A_STATUS_PWAKEF_SHIFT)

#define SI32_PMU_A_STATUS_PORF_MASK  0x00000004
#define SI32_PMU_A_STATUS_PORF_SHIFT  2
// A power-on reset did not occur since the last time PORF was cleared.
#define SI32_PMU_A_STATUS_PORF_NOT_SET_VALUE  0
#define SI32_PMU_A_STATUS_PORF_NOT_SET_U32 \
   (SI32_PMU_A_STATUS_PORF_NOT_SET_VALUE << SI32_PMU_A_STATUS_PORF_SHIFT)
// A power-on reset occurred.
#define SI32_PMU_A_STATUS_PORF_SET_VALUE  1
#define SI32_PMU_A_STATUS_PORF_SET_U32 \
   (SI32_PMU_A_STATUS_PORF_SET_VALUE << SI32_PMU_A_STATUS_PORF_SHIFT)

#define SI32_PMU_A_STATUS_CPSTS_MASK  0x00000008
#define SI32_PMU_A_STATUS_CPSTS_SHIFT  3
// The low power charge pump supply voltage is below the threshold.
#define SI32_PMU_A_STATUS_CPSTS_NOT_SET_VALUE  0
#define SI32_PMU_A_STATUS_CPSTS_NOT_SET_U32 \
   (SI32_PMU_A_STATUS_CPSTS_NOT_SET_VALUE << SI32_PMU_A_STATUS_CPSTS_SHIFT)
// The low power charge pump supply voltage is greater than the threshold.
#define SI32_PMU_A_STATUS_CPSTS_SET_VALUE  1
#define SI32_PMU_A_STATUS_CPSTS_SET_U32 \
   (SI32_PMU_A_STATUS_CPSTS_SET_VALUE << SI32_PMU_A_STATUS_CPSTS_SHIFT)



struct SI32_PMU_A_WAKEEN_Struct
{
   union
   {
      struct
      {
         // RTC0 Fail Wake Enable
         volatile uint32_t RTC0FWEN: 1;
         // RTC0 Alarm Wake Enable
         volatile uint32_t RTC0A0WEN: 1;
         // Comparator 0 Wake Enable
         volatile uint32_t CMP0WEN: 1;
         // Advanced Capture Counter 0 Wake Enable
         volatile uint32_t ACC0WEN: 1;
         // LCD VBAT Voltage Monitor Wake Enable
         volatile uint32_t LCDMONWEN: 1;
         // Pin Wake Wake Enable
         volatile uint32_t PWAKEWEN: 1;
         // Low Power Timer Wake Enable
         volatile uint32_t LPT0WEN: 1;
         // UART0 Wake Enable
         volatile uint32_t UART0WEN: 1;
         // Low Power Charge Pump Supply Fail Wake Enable
         volatile uint32_t CPFWEN: 1;
                  uint32_t reserved0: 23;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_WAKEEN_RTC0FWEN_MASK  0x00000001
#define SI32_PMU_A_WAKEEN_RTC0FWEN_SHIFT  0
// An RTC0 Fail event does not wake the device.
#define SI32_PMU_A_WAKEEN_RTC0FWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_RTC0FWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0FWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0FWEN_SHIFT)
// An RTC0 Fail event awakens the device.
#define SI32_PMU_A_WAKEEN_RTC0FWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_RTC0FWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0FWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0FWEN_SHIFT)

#define SI32_PMU_A_WAKEEN_RTC0A0WEN_MASK  0x00000002
#define SI32_PMU_A_WAKEEN_RTC0A0WEN_SHIFT  1
// An RTC0 Alarm event does not wake the device.
#define SI32_PMU_A_WAKEEN_RTC0A0WEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_RTC0A0WEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0A0WEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0A0WEN_SHIFT)
// An RTC0 Alarm event awakens the device.
#define SI32_PMU_A_WAKEEN_RTC0A0WEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_RTC0A0WEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0A0WEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0A0WEN_SHIFT)

#define SI32_PMU_A_WAKEEN_CMP0WEN_MASK  0x00000004
#define SI32_PMU_A_WAKEEN_CMP0WEN_SHIFT  2
// A Comparator 0 event does not wake the device.
#define SI32_PMU_A_WAKEEN_CMP0WEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_CMP0WEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_CMP0WEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_CMP0WEN_SHIFT)
// A Comparator 0 event awakens the device.
#define SI32_PMU_A_WAKEEN_CMP0WEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_CMP0WEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_CMP0WEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_CMP0WEN_SHIFT)

#define SI32_PMU_A_WAKEEN_ACC0WEN_MASK  0x00000008
#define SI32_PMU_A_WAKEEN_ACC0WEN_SHIFT  3
// An Advanced Capture Counter (ACCTR0) event does not wake the device.
#define SI32_PMU_A_WAKEEN_ACC0WEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_ACC0WEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_ACC0WEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_ACC0WEN_SHIFT)
// An Advanced Capture Counter (ACCTR0) event awakens the device.
#define SI32_PMU_A_WAKEEN_ACC0WEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_ACC0WEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_ACC0WEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_ACC0WEN_SHIFT)

#define SI32_PMU_A_WAKEEN_LCDMONWEN_MASK  0x00000010
#define SI32_PMU_A_WAKEEN_LCDMONWEN_SHIFT  4
// An LCD VBAT voltage monitor event does not wake the device.
#define SI32_PMU_A_WAKEEN_LCDMONWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_LCDMONWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_LCDMONWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_LCDMONWEN_SHIFT)
// An LCD VBAT voltage monitor event awakens the device.
#define SI32_PMU_A_WAKEEN_LCDMONWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_LCDMONWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_LCDMONWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_LCDMONWEN_SHIFT)

#define SI32_PMU_A_WAKEEN_PWAKEWEN_MASK  0x00000020
#define SI32_PMU_A_WAKEEN_PWAKEWEN_SHIFT  5
// A Pin Wake event does not wake the device.
#define SI32_PMU_A_WAKEEN_PWAKEWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_PWAKEWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_PWAKEWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_PWAKEWEN_SHIFT)
// A Pin Wake event awakens the device.
#define SI32_PMU_A_WAKEEN_PWAKEWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_PWAKEWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_PWAKEWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_PWAKEWEN_SHIFT)

#define SI32_PMU_A_WAKEEN_LPT0WEN_MASK  0x00000040
#define SI32_PMU_A_WAKEEN_LPT0WEN_SHIFT  6
// An LPTIMER0 event does not wake the device.
#define SI32_PMU_A_WAKEEN_LPT0WEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_LPT0WEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_LPT0WEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_LPT0WEN_SHIFT)
// An LPTIMER0 event awakens the device.
#define SI32_PMU_A_WAKEEN_LPT0WEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_LPT0WEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_LPT0WEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_LPT0WEN_SHIFT)

#define SI32_PMU_A_WAKEEN_UART0WEN_MASK  0x00000080
#define SI32_PMU_A_WAKEEN_UART0WEN_SHIFT  7
// A UART0 event does not wake the device.
#define SI32_PMU_A_WAKEEN_UART0WEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_UART0WEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_UART0WEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_UART0WEN_SHIFT)
// A UART0 event awakens the device.
#define SI32_PMU_A_WAKEEN_UART0WEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_UART0WEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_UART0WEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_UART0WEN_SHIFT)

#define SI32_PMU_A_WAKEEN_CPFWEN_MASK  0x00000100
#define SI32_PMU_A_WAKEEN_CPFWEN_SHIFT  8
// A low power charge pump supply fail event does not wake the device.
#define SI32_PMU_A_WAKEEN_CPFWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_CPFWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_CPFWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_CPFWEN_SHIFT)
// A low power charge pump supply fail event awakens the device.
#define SI32_PMU_A_WAKEEN_CPFWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_CPFWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_CPFWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_CPFWEN_SHIFT)



struct SI32_PMU_A_WAKESTATUS_Struct
{
   union
   {
      struct
      {
         // RTC0 Fail Wake Flag
         volatile uint32_t RTC0FWF: 1;
         // RTC0 Alarm Wake Flag
         volatile uint32_t RTC0A0WF: 1;
         // Comparator 0 Wake Flag
         volatile uint32_t CMP0WF: 1;
         // Advanced Capture Counter 0 Wake Flag
         volatile uint32_t ACC0WF: 1;
         // LCD VBAT Voltage Monitor Wake Flag
         volatile uint32_t LCDMONWF: 1;
         // Pin Wake Wake Flag
         volatile uint32_t PWAKEWF: 1;
         // Low Power Timer Wake Flag
         volatile uint32_t LPT0WF: 1;
         // UART0 Wake Flag
         volatile uint32_t UART0WF: 1;
         // Low Power Charge Pump Supply Fail Wake Flag
         volatile uint32_t CPFWF: 1;
         // Reset Pin Wake Flag
         volatile uint32_t RSTWF: 1;
                  uint32_t reserved0: 22;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_WAKESTATUS_RTC0FWF_MASK  0x00000001
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_SHIFT  0
// An RTC0 Fail event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0FWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0FWF_SHIFT)
// An RTC0 Fail event woke the device.
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0FWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0FWF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_RTC0A0WF_MASK  0x00000002
#define SI32_PMU_A_WAKESTATUS_RTC0A0WF_SHIFT  1
// An RTC0 Alarm event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_RTC0A0WF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_RTC0A0WF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0A0WF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0A0WF_SHIFT)
// An RTC0 Alarm event woke the device.
#define SI32_PMU_A_WAKESTATUS_RTC0A0WF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_RTC0A0WF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0A0WF_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0A0WF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_CMP0WF_MASK  0x00000004
#define SI32_PMU_A_WAKESTATUS_CMP0WF_SHIFT  2
// A Comparator 0 event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_CMP0WF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_CMP0WF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_CMP0WF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_CMP0WF_SHIFT)
// A Comparator 0 event woke the device.
#define SI32_PMU_A_WAKESTATUS_CMP0WF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_CMP0WF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_CMP0WF_SET_VALUE << SI32_PMU_A_WAKESTATUS_CMP0WF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_ACC0WF_MASK  0x00000008
#define SI32_PMU_A_WAKESTATUS_ACC0WF_SHIFT  3
// An Advanced Capture Counter (ACCTR0) event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_ACC0WF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_ACC0WF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_ACC0WF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_ACC0WF_SHIFT)
// An Advanced Capture Counter (ACCTR0) event woke the device.
#define SI32_PMU_A_WAKESTATUS_ACC0WF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_ACC0WF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_ACC0WF_SET_VALUE << SI32_PMU_A_WAKESTATUS_ACC0WF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_LCDMONWF_MASK  0x00000010
#define SI32_PMU_A_WAKESTATUS_LCDMONWF_SHIFT  4
// A LCD VBAT voltage monitor event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_LCDMONWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_LCDMONWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_LCDMONWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_LCDMONWF_SHIFT)
// A LCD VBAT voltage monitor event woke the device.
#define SI32_PMU_A_WAKESTATUS_LCDMONWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_LCDMONWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_LCDMONWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_LCDMONWF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_PWAKEWF_MASK  0x00000020
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_SHIFT  5
// A Pin Wake event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_PWAKEWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_PWAKEWF_SHIFT)
// A Pin Wake event woke the device.
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_PWAKEWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_PWAKEWF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_LPT0WF_MASK  0x00000040
#define SI32_PMU_A_WAKESTATUS_LPT0WF_SHIFT  6
// An LPTIMER0 event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_LPT0WF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_LPT0WF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_LPT0WF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_LPT0WF_SHIFT)
// An LPTIMER0 event woke the device.
#define SI32_PMU_A_WAKESTATUS_LPT0WF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_LPT0WF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_LPT0WF_SET_VALUE << SI32_PMU_A_WAKESTATUS_LPT0WF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_UART0WF_MASK  0x00000080
#define SI32_PMU_A_WAKESTATUS_UART0WF_SHIFT  7
// A UART0 event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_UART0WF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_UART0WF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_UART0WF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_UART0WF_SHIFT)
// A UART0 event woke the device.
#define SI32_PMU_A_WAKESTATUS_UART0WF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_UART0WF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_UART0WF_SET_VALUE << SI32_PMU_A_WAKESTATUS_UART0WF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_CPFWF_MASK  0x00000100
#define SI32_PMU_A_WAKESTATUS_CPFWF_SHIFT  8
// A low power charge pump supply fail event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_CPFWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_CPFWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_CPFWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_CPFWF_SHIFT)
// A low power charge pump supply fail event woke the device.
#define SI32_PMU_A_WAKESTATUS_CPFWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_CPFWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_CPFWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_CPFWF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_RSTWF_MASK  0x00000200
#define SI32_PMU_A_WAKESTATUS_RSTWF_SHIFT  9
// A /RESET Pin event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_RSTWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_RSTWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RSTWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_RSTWF_SHIFT)
// A /RESET Pin event woke the device.
#define SI32_PMU_A_WAKESTATUS_RSTWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_RSTWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RSTWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_RSTWF_SHIFT)



struct SI32_PMU_A_PWEN_Struct
{
   union
   {
      struct
      {
         // WAKE.0 Enable
         volatile uint32_t PW0EN: 1;
         // WAKE.1 Enable
         volatile uint32_t PW1EN: 1;
         // WAKE.2 Enable
         volatile uint32_t PW2EN: 1;
         // WAKE.3 Enable
         volatile uint32_t PW3EN: 1;
         // WAKE.4 Enable
         volatile uint32_t PW4EN: 1;
         // WAKE.5 Enable
         volatile uint32_t PW5EN: 1;
         // WAKE.6 Enable
         volatile uint32_t PW6EN: 1;
         // WAKE.7 Enable
         volatile uint32_t PW7EN: 1;
         // WAKE.8 Enable
         volatile uint32_t PW8EN: 1;
         // WAKE.9 Enable
         volatile uint32_t PW9EN: 1;
         // WAKE.10 Enable
         volatile uint32_t PW10EN: 1;
         // WAKE.11 Enable
         volatile uint32_t PW11EN: 1;
         // WAKE.12 Enable
         volatile uint32_t PW12EN: 1;
         // WAKE.13 Enable
         volatile uint32_t PW13EN: 1;
         // WAKE.14 Enable
         volatile uint32_t PW14EN: 1;
         // WAKE.15 Enable
         volatile uint32_t PW15EN: 1;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_PWEN_PW0EN_MASK  0x00000001
#define SI32_PMU_A_PWEN_PW0EN_SHIFT  0
// WAKE.0 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW0EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW0EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW0EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW0EN_SHIFT)
// Enable WAKE.0 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW0EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW0EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW0EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW0EN_SHIFT)

#define SI32_PMU_A_PWEN_PW1EN_MASK  0x00000002
#define SI32_PMU_A_PWEN_PW1EN_SHIFT  1
// WAKE.1 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW1EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW1EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW1EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW1EN_SHIFT)
// Enable WAKE.1 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW1EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW1EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW1EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW1EN_SHIFT)

#define SI32_PMU_A_PWEN_PW2EN_MASK  0x00000004
#define SI32_PMU_A_PWEN_PW2EN_SHIFT  2
// WAKE.2 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW2EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW2EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW2EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW2EN_SHIFT)
// Enable WAKE.2 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW2EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW2EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW2EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW2EN_SHIFT)

#define SI32_PMU_A_PWEN_PW3EN_MASK  0x00000008
#define SI32_PMU_A_PWEN_PW3EN_SHIFT  3
// WAKE.3 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW3EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW3EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW3EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW3EN_SHIFT)
// Enable WAKE.3 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW3EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW3EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW3EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW3EN_SHIFT)

#define SI32_PMU_A_PWEN_PW4EN_MASK  0x00000010
#define SI32_PMU_A_PWEN_PW4EN_SHIFT  4
// WAKE.4 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW4EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW4EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW4EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW4EN_SHIFT)
// Enable WAKE.4 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW4EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW4EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW4EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW4EN_SHIFT)

#define SI32_PMU_A_PWEN_PW5EN_MASK  0x00000020
#define SI32_PMU_A_PWEN_PW5EN_SHIFT  5
// WAKE.5 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW5EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW5EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW5EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW5EN_SHIFT)
// Enable WAKE.5 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW5EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW5EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW5EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW5EN_SHIFT)

#define SI32_PMU_A_PWEN_PW6EN_MASK  0x00000040
#define SI32_PMU_A_PWEN_PW6EN_SHIFT  6
// WAKE.6 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW6EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW6EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW6EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW6EN_SHIFT)
// Enable WAKE.6 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW6EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW6EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW6EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW6EN_SHIFT)

#define SI32_PMU_A_PWEN_PW7EN_MASK  0x00000080
#define SI32_PMU_A_PWEN_PW7EN_SHIFT  7
// WAKE.7 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW7EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW7EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW7EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW7EN_SHIFT)
// Enable WAKE.7 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW7EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW7EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW7EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW7EN_SHIFT)

#define SI32_PMU_A_PWEN_PW8EN_MASK  0x00000100
#define SI32_PMU_A_PWEN_PW8EN_SHIFT  8
// WAKE.8 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW8EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW8EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW8EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW8EN_SHIFT)
// Enable WAKE.8 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW8EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW8EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW8EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW8EN_SHIFT)

#define SI32_PMU_A_PWEN_PW9EN_MASK  0x00000200
#define SI32_PMU_A_PWEN_PW9EN_SHIFT  9
// WAKE.9 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW9EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW9EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW9EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW9EN_SHIFT)
// Enable WAKE.9 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW9EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW9EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW9EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW9EN_SHIFT)

#define SI32_PMU_A_PWEN_PW10EN_MASK  0x00000400
#define SI32_PMU_A_PWEN_PW10EN_SHIFT  10
// WAKE.10 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW10EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW10EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW10EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW10EN_SHIFT)
// Enable WAKE.10 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW10EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW10EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW10EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW10EN_SHIFT)

#define SI32_PMU_A_PWEN_PW11EN_MASK  0x00000800
#define SI32_PMU_A_PWEN_PW11EN_SHIFT  11
// WAKE.11 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW11EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW11EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW11EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW11EN_SHIFT)
// Enable WAKE.11 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW11EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW11EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW11EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW11EN_SHIFT)

#define SI32_PMU_A_PWEN_PW12EN_MASK  0x00001000
#define SI32_PMU_A_PWEN_PW12EN_SHIFT  12
// WAKE.12 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW12EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW12EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW12EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW12EN_SHIFT)
// Enable WAKE.12 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW12EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW12EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW12EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW12EN_SHIFT)

#define SI32_PMU_A_PWEN_PW13EN_MASK  0x00002000
#define SI32_PMU_A_PWEN_PW13EN_SHIFT  13
// WAKE.13 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW13EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW13EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW13EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW13EN_SHIFT)
// Enable WAKE.13 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW13EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW13EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW13EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW13EN_SHIFT)

#define SI32_PMU_A_PWEN_PW14EN_MASK  0x00004000
#define SI32_PMU_A_PWEN_PW14EN_SHIFT  14
// WAKE.14 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW14EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW14EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW14EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW14EN_SHIFT)
// Enable WAKE.14 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW14EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW14EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW14EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW14EN_SHIFT)

#define SI32_PMU_A_PWEN_PW15EN_MASK  0x00008000
#define SI32_PMU_A_PWEN_PW15EN_SHIFT  15
// WAKE.15 does not cause a Pin Wake event.
#define SI32_PMU_A_PWEN_PW15EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW15EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW15EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW15EN_SHIFT)
// Enable WAKE.15 as a Pin Wake source.
#define SI32_PMU_A_PWEN_PW15EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW15EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW15EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW15EN_SHIFT)



struct SI32_PMU_A_PWPOL_Struct
{
   union
   {
      struct
      {
         // WAKE.0 Polarity Select
         volatile uint32_t PW0POL: 1;
         // WAKE.1 Polarity Select
         volatile uint32_t PW1POL: 1;
         // WAKE.2 Polarity Select
         volatile uint32_t PW2POL: 1;
         // WAKE.3 Polarity Select
         volatile uint32_t PW3POL: 1;
         // WAKE.4 Polarity Select
         volatile uint32_t PW4POL: 1;
         // WAKE.5 Polarity Select
         volatile uint32_t PW5POL: 1;
         // WAKE.6 Polarity Select
         volatile uint32_t PW6POL: 1;
         // WAKE.7 Polarity Select
         volatile uint32_t PW7POL: 1;
         // WAKE.8 Polarity Select
         volatile uint32_t PW8POL: 1;
         // WAKE.9 Polarity Select
         volatile uint32_t PW9POL: 1;
         // WAKE.10 Polarity Select
         volatile uint32_t PW10POL: 1;
         // WAKE.11 Polarity Select
         volatile uint32_t PW11POL: 1;
         // WAKE.12 Polarity Select
         volatile uint32_t PW12POL: 1;
         // WAKE.13 Polarity Select
         volatile uint32_t PW13POL: 1;
         // WAKE.14 Polarity Select
         volatile uint32_t PW14POL: 1;
         // WAKE.15 Polarity Select
         volatile uint32_t PW15POL: 1;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_PWPOL_PW0POL_MASK  0x00000001
#define SI32_PMU_A_PWPOL_PW0POL_SHIFT  0
// A logic low on WAKE.0 causes a Pin Wake event if PW0EN is set to 1.
#define SI32_PMU_A_PWPOL_PW0POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW0POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW0POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW0POL_SHIFT)
// A logic high on WAKE.0 causes a Pin Wake event if PW0EN is set to 1.
#define SI32_PMU_A_PWPOL_PW0POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW0POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW0POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW0POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW1POL_MASK  0x00000002
#define SI32_PMU_A_PWPOL_PW1POL_SHIFT  1
// A logic low on WAKE.1 causes a Pin Wake event if PW1EN is set to 1.
#define SI32_PMU_A_PWPOL_PW1POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW1POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW1POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW1POL_SHIFT)
// A logic high on WAKE.1 causes a Pin Wake event if PW1EN is set to 1.
#define SI32_PMU_A_PWPOL_PW1POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW1POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW1POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW1POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW2POL_MASK  0x00000004
#define SI32_PMU_A_PWPOL_PW2POL_SHIFT  2
// A logic low on WAKE.2 causes a Pin Wake event if PW2EN is set to 1.
#define SI32_PMU_A_PWPOL_PW2POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW2POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW2POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW2POL_SHIFT)
// A logic high on WAKE.2 causes a Pin Wake event if PW2EN is set to 1.
#define SI32_PMU_A_PWPOL_PW2POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW2POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW2POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW2POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW3POL_MASK  0x00000008
#define SI32_PMU_A_PWPOL_PW3POL_SHIFT  3
// A logic low on WAKE.3 causes a Pin Wake event if PW3EN is set to 1.
#define SI32_PMU_A_PWPOL_PW3POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW3POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW3POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW3POL_SHIFT)
// A logic high on WAKE.3 causes a Pin Wake event if PW3EN is set to 1.
#define SI32_PMU_A_PWPOL_PW3POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW3POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW3POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW3POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW4POL_MASK  0x00000010
#define SI32_PMU_A_PWPOL_PW4POL_SHIFT  4
// A logic low on WAKE.4 causes a Pin Wake event if PW4EN is set to 1.
#define SI32_PMU_A_PWPOL_PW4POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW4POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW4POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW4POL_SHIFT)
// A logic high on WAKE.4 causes a Pin Wake event if PW4EN is set to 1.
#define SI32_PMU_A_PWPOL_PW4POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW4POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW4POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW4POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW5POL_MASK  0x00000020
#define SI32_PMU_A_PWPOL_PW5POL_SHIFT  5
// A logic low on WAKE.5 causes a Pin Wake event if PW5EN is set to 1.
#define SI32_PMU_A_PWPOL_PW5POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW5POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW5POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW5POL_SHIFT)
// A logic high on WAKE.5 causes a Pin Wake event if PW5EN is set to 1.
#define SI32_PMU_A_PWPOL_PW5POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW5POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW5POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW5POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW6POL_MASK  0x00000040
#define SI32_PMU_A_PWPOL_PW6POL_SHIFT  6
// A logic low on WAKE.6 causes a Pin Wake event if PW6EN is set to 1.
#define SI32_PMU_A_PWPOL_PW6POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW6POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW6POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW6POL_SHIFT)
// A logic high on WAKE.6 causes a Pin Wake event if PW6EN is set to 1.
#define SI32_PMU_A_PWPOL_PW6POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW6POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW6POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW6POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW7POL_MASK  0x00000080
#define SI32_PMU_A_PWPOL_PW7POL_SHIFT  7
// A logic low on WAKE.7 causes a Pin Wake event if PW7EN is set to 1.
#define SI32_PMU_A_PWPOL_PW7POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW7POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW7POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW7POL_SHIFT)
// A logic high on WAKE.7 causes a Pin Wake event if PW7EN is set to 1.
#define SI32_PMU_A_PWPOL_PW7POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW7POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW7POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW7POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW8POL_MASK  0x00000100
#define SI32_PMU_A_PWPOL_PW8POL_SHIFT  8
// A logic low on WAKE.8 causes a Pin Wake event if PW8EN is set to 1.
#define SI32_PMU_A_PWPOL_PW8POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW8POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW8POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW8POL_SHIFT)
// A logic high on WAKE.8 causes a Pin Wake event if PW8EN is set to 1.
#define SI32_PMU_A_PWPOL_PW8POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW8POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW8POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW8POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW9POL_MASK  0x00000200
#define SI32_PMU_A_PWPOL_PW9POL_SHIFT  9
// A logic low on WAKE.9 causes a Pin Wake event if PW9EN is set to 1.
#define SI32_PMU_A_PWPOL_PW9POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW9POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW9POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW9POL_SHIFT)
// A logic high on WAKE.9 causes a Pin Wake event if PW9EN is set to 1.
#define SI32_PMU_A_PWPOL_PW9POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW9POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW9POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW9POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW10POL_MASK  0x00000400
#define SI32_PMU_A_PWPOL_PW10POL_SHIFT  10
// A logic low on WAKE.10 causes a Pin Wake event if PW10EN is set to 1.
#define SI32_PMU_A_PWPOL_PW10POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW10POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW10POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW10POL_SHIFT)
// A logic high on WAKE.10 causes a Pin Wake event if PW10EN is set to 1.
#define SI32_PMU_A_PWPOL_PW10POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW10POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW10POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW10POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW11POL_MASK  0x00000800
#define SI32_PMU_A_PWPOL_PW11POL_SHIFT  11
// A logic low on WAKE.11 causes a Pin Wake event if PW11EN is set to 1.
#define SI32_PMU_A_PWPOL_PW11POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW11POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW11POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW11POL_SHIFT)
// A logic high on WAKE.11 causes a Pin Wake event if PW11EN is set to 1.
#define SI32_PMU_A_PWPOL_PW11POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW11POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW11POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW11POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW12POL_MASK  0x00001000
#define SI32_PMU_A_PWPOL_PW12POL_SHIFT  12
// A logic low on WAKE.12 causes a Pin Wake event if PW12EN is set to 1.
#define SI32_PMU_A_PWPOL_PW12POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW12POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW12POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW12POL_SHIFT)
// A logic high on WAKE.12 causes a Pin Wake event if PW12EN is set to 1.
#define SI32_PMU_A_PWPOL_PW12POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW12POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW12POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW12POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW13POL_MASK  0x00002000
#define SI32_PMU_A_PWPOL_PW13POL_SHIFT  13
// A logic low on WAKE.13 causes a Pin Wake event if PW13EN is set to 1.
#define SI32_PMU_A_PWPOL_PW13POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW13POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW13POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW13POL_SHIFT)
// A logic high on WAKE.13 causes a Pin Wake event if PW13EN is set to 1.
#define SI32_PMU_A_PWPOL_PW13POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW13POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW13POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW13POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW14POL_MASK  0x00004000
#define SI32_PMU_A_PWPOL_PW14POL_SHIFT  14
// A logic low on WAKE.14 causes a Pin Wake event if PW14EN is set to 1.
#define SI32_PMU_A_PWPOL_PW14POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW14POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW14POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW14POL_SHIFT)
// A logic high on WAKE.14 causes a Pin Wake event if PW14EN is set to 1.
#define SI32_PMU_A_PWPOL_PW14POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW14POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW14POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW14POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW15POL_MASK  0x00008000
#define SI32_PMU_A_PWPOL_PW15POL_SHIFT  15
// A logic low on WAKE.15 causes a Pin Wake event if PW15EN is set to 1.
#define SI32_PMU_A_PWPOL_PW15POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW15POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW15POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW15POL_SHIFT)
// A logic high on WAKE.15 causes a Pin Wake event if PW15EN is set to 1.
#define SI32_PMU_A_PWPOL_PW15POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW15POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW15POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW15POL_SHIFT)



typedef struct SI32_PMU_A_Struct
{
   struct SI32_PMU_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_PMU_A_CONFIG_Struct                 CONFIG         ; // Base Address + 0x10
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved1;
   struct SI32_PMU_A_STATUS_Struct                 STATUS         ; // Base Address + 0x20
   volatile uint32_t                               STATUS_SET;
   volatile uint32_t                               STATUS_CLR;
   uint32_t                                        reserved2;
   struct SI32_PMU_A_WAKEEN_Struct                 WAKEEN         ; // Base Address + 0x30
   volatile uint32_t                               WAKEEN_SET;
   volatile uint32_t                               WAKEEN_CLR;
   uint32_t                                        reserved3;
   struct SI32_PMU_A_WAKESTATUS_Struct             WAKESTATUS     ; // Base Address + 0x40
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_PMU_A_PWEN_Struct                   PWEN           ; // Base Address + 0x50
   volatile uint32_t                               PWEN_SET;
   volatile uint32_t                               PWEN_CLR;
   uint32_t                                        reserved7;
   struct SI32_PMU_A_PWPOL_Struct                  PWPOL          ; // Base Address + 0x60
   volatile uint32_t                               PWPOL_SET;
   volatile uint32_t                               PWPOL_CLR;
   uint32_t                                        reserved8;
} SI32_PMU_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PMU_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

