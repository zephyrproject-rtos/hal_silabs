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
// This file applies to the SIM3C1XX_PMU_A module
//
// Script: 0.57
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
         // Peripheral Low Power Enable
         volatile uint32_t PERILPEN: 1;
         // Pin Low Power Enable
         volatile uint32_t PINLPEN: 1;
         // Pin Wake Match Enable
         volatile uint32_t PWAKEEN: 1;
         // PMU Asleep Pin Enable
         volatile uint32_t PMUASLPEN: 1;
                  uint32_t reserved0: 27;
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

#define SI32_PMU_A_CONTROL_PERILPEN_MASK  0x00000002
#define SI32_PMU_A_CONTROL_PERILPEN_SHIFT  1
// Disable the peripheral low power state.
#define SI32_PMU_A_CONTROL_PERILPEN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_PERILPEN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_PERILPEN_DISABLED_VALUE << SI32_PMU_A_CONTROL_PERILPEN_SHIFT)
// Enable the peripheral low power state. The peripherals will not be accessible in
// this state.
#define SI32_PMU_A_CONTROL_PERILPEN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_PERILPEN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_PERILPEN_ENABLED_VALUE << SI32_PMU_A_CONTROL_PERILPEN_SHIFT)

#define SI32_PMU_A_CONTROL_PINLPEN_MASK  0x00000004
#define SI32_PMU_A_CONTROL_PINLPEN_SHIFT  2
// Disable the pin low power state.
#define SI32_PMU_A_CONTROL_PINLPEN_DISABLED_VALUE  0
#define SI32_PMU_A_CONTROL_PINLPEN_DISABLED_U32 \
   (SI32_PMU_A_CONTROL_PINLPEN_DISABLED_VALUE << SI32_PMU_A_CONTROL_PINLPEN_SHIFT)
// Enable the pin low power state. The pins will not be accessible in this state.
#define SI32_PMU_A_CONTROL_PINLPEN_ENABLED_VALUE  1
#define SI32_PMU_A_CONTROL_PINLPEN_ENABLED_U32 \
   (SI32_PMU_A_CONTROL_PINLPEN_ENABLED_VALUE << SI32_PMU_A_CONTROL_PINLPEN_SHIFT)

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



struct SI32_PMU_A_CONFIG_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 8;
         // RTC0 Fail RTC0/LPTIMER0 Reset Enable
         volatile uint32_t RTC0FREN: 1;
         // RTC0 Alarm RTC0/LPTIMER0 Reset Enable
         volatile uint32_t RTC0AREN: 1;
                  uint32_t reserved1: 3;
         // Comparator 0 RTC0/LPTIMER0 Reset Enable
         volatile uint32_t CMP0REN: 1;
         // Pin Wake RTC0/LPTIMER0 Reset Enable
         volatile uint32_t PWAKEREN: 1;
         // Low Power Timer RTC0/LPTIMER0 Reset Enable
         volatile uint32_t LPT0REN: 1;
                  uint32_t reserved2: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_CONFIG_RTC0FREN_MASK  0x00000100
#define SI32_PMU_A_CONFIG_RTC0FREN_SHIFT  8
// An RTC0 fail event does not cause the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_RTC0FREN_DISABLED_VALUE  0
#define SI32_PMU_A_CONFIG_RTC0FREN_DISABLED_U32 \
   (SI32_PMU_A_CONFIG_RTC0FREN_DISABLED_VALUE << SI32_PMU_A_CONFIG_RTC0FREN_SHIFT)
// An RTC0 fail event causes the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_RTC0FREN_ENABLED_VALUE  1
#define SI32_PMU_A_CONFIG_RTC0FREN_ENABLED_U32 \
   (SI32_PMU_A_CONFIG_RTC0FREN_ENABLED_VALUE << SI32_PMU_A_CONFIG_RTC0FREN_SHIFT)

#define SI32_PMU_A_CONFIG_RTC0AREN_MASK  0x00000200
#define SI32_PMU_A_CONFIG_RTC0AREN_SHIFT  9
// An RTC0 alarm event does not cause the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_RTC0AREN_DISABLED_VALUE  0
#define SI32_PMU_A_CONFIG_RTC0AREN_DISABLED_U32 \
   (SI32_PMU_A_CONFIG_RTC0AREN_DISABLED_VALUE << SI32_PMU_A_CONFIG_RTC0AREN_SHIFT)
// An RTC0 alarm event causes the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_RTC0AREN_ENABLED_VALUE  1
#define SI32_PMU_A_CONFIG_RTC0AREN_ENABLED_U32 \
   (SI32_PMU_A_CONFIG_RTC0AREN_ENABLED_VALUE << SI32_PMU_A_CONFIG_RTC0AREN_SHIFT)

#define SI32_PMU_A_CONFIG_CMP0REN_MASK  0x00002000
#define SI32_PMU_A_CONFIG_CMP0REN_SHIFT  13
// A Comparator 0 event does not cause the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_CMP0REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONFIG_CMP0REN_DISABLED_U32 \
   (SI32_PMU_A_CONFIG_CMP0REN_DISABLED_VALUE << SI32_PMU_A_CONFIG_CMP0REN_SHIFT)
// A Comparator 0 event causes the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_CMP0REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONFIG_CMP0REN_ENABLED_U32 \
   (SI32_PMU_A_CONFIG_CMP0REN_ENABLED_VALUE << SI32_PMU_A_CONFIG_CMP0REN_SHIFT)

#define SI32_PMU_A_CONFIG_PWAKEREN_MASK  0x00004000
#define SI32_PMU_A_CONFIG_PWAKEREN_SHIFT  14
// A Pin Wake event does not cause the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_PWAKEREN_DISABLED_VALUE  0
#define SI32_PMU_A_CONFIG_PWAKEREN_DISABLED_U32 \
   (SI32_PMU_A_CONFIG_PWAKEREN_DISABLED_VALUE << SI32_PMU_A_CONFIG_PWAKEREN_SHIFT)
// A Pin Wake event causes the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_PWAKEREN_ENABLED_VALUE  1
#define SI32_PMU_A_CONFIG_PWAKEREN_ENABLED_U32 \
   (SI32_PMU_A_CONFIG_PWAKEREN_ENABLED_VALUE << SI32_PMU_A_CONFIG_PWAKEREN_SHIFT)

#define SI32_PMU_A_CONFIG_LPT0REN_MASK  0x00008000
#define SI32_PMU_A_CONFIG_LPT0REN_SHIFT  15
// An LPTIMER0 event does not cause the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_LPT0REN_DISABLED_VALUE  0
#define SI32_PMU_A_CONFIG_LPT0REN_DISABLED_U32 \
   (SI32_PMU_A_CONFIG_LPT0REN_DISABLED_VALUE << SI32_PMU_A_CONFIG_LPT0REN_SHIFT)
// An LPTIMER0 event causes the RTC0 and LPTIMER0 modules to reset.
#define SI32_PMU_A_CONFIG_LPT0REN_ENABLED_VALUE  1
#define SI32_PMU_A_CONFIG_LPT0REN_ENABLED_U32 \
   (SI32_PMU_A_CONFIG_LPT0REN_ENABLED_VALUE << SI32_PMU_A_CONFIG_LPT0REN_SHIFT)



struct SI32_PMU_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Power Mode 9 Exited Flag
         volatile uint32_t PM9EF: 1;
         // Pin Wake Status Flag
         volatile uint32_t PWAKEF: 1;
         // Power-On Reset Flag
         volatile uint32_t PORF: 1;
                  uint32_t reserved0: 29;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_STATUS_PM9EF_MASK  0x00000001
#define SI32_PMU_A_STATUS_PM9EF_SHIFT  0
// The device has not exited Power Mode 9.
#define SI32_PMU_A_STATUS_PM9EF_NOT_SET_VALUE  0
#define SI32_PMU_A_STATUS_PM9EF_NOT_SET_U32 \
   (SI32_PMU_A_STATUS_PM9EF_NOT_SET_VALUE << SI32_PMU_A_STATUS_PM9EF_SHIFT)
// The device has exited Power Mode 9. This bit must be cleared by firmware.
#define SI32_PMU_A_STATUS_PM9EF_SET_VALUE  1
#define SI32_PMU_A_STATUS_PM9EF_SET_U32 \
   (SI32_PMU_A_STATUS_PM9EF_SET_VALUE << SI32_PMU_A_STATUS_PM9EF_SHIFT)

#define SI32_PMU_A_STATUS_PWAKEF_MASK  0x00000002
#define SI32_PMU_A_STATUS_PWAKEF_SHIFT  1
// A Pin Wake event has occurred.
#define SI32_PMU_A_STATUS_PWAKEF_SET_VALUE  0
#define SI32_PMU_A_STATUS_PWAKEF_SET_U32 \
   (SI32_PMU_A_STATUS_PWAKEF_SET_VALUE << SI32_PMU_A_STATUS_PWAKEF_SHIFT)
// A Pin Wake event has not occurred.
#define SI32_PMU_A_STATUS_PWAKEF_NOT_SET_VALUE  1
#define SI32_PMU_A_STATUS_PWAKEF_NOT_SET_U32 \
   (SI32_PMU_A_STATUS_PWAKEF_NOT_SET_VALUE << SI32_PMU_A_STATUS_PWAKEF_SHIFT)

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



struct SI32_PMU_A_WAKEEN_Struct
{
   union
   {
      struct
      {
         // RTC0 Fail Wake Enable
         volatile uint32_t RTC0FWEN: 1;
         // RTC0 Alarm Wake Enable
         volatile uint32_t RTC0AWEN: 1;
                  uint32_t reserved0: 3;
         // Comparator 0 Wake Enable
         volatile uint32_t CMP0WEN: 1;
         // Pin Wake Wake Enable
         volatile uint32_t PWAKEWEN: 1;
         // Low Power Timer Wake Enable
         volatile uint32_t LPT0WEN: 1;
         // Reset Pin Wake Enable
         volatile uint32_t RSTWEN: 1;
                  uint32_t reserved1: 23;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_WAKEEN_RTC0FWEN_MASK  0x00000001
#define SI32_PMU_A_WAKEEN_RTC0FWEN_SHIFT  0
// An RTC0 fail event does not wake the device.
#define SI32_PMU_A_WAKEEN_RTC0FWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_RTC0FWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0FWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0FWEN_SHIFT)
// An RTC0 fail event awakens the device.
#define SI32_PMU_A_WAKEEN_RTC0FWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_RTC0FWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0FWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0FWEN_SHIFT)

#define SI32_PMU_A_WAKEEN_RTC0AWEN_MASK  0x00000002
#define SI32_PMU_A_WAKEEN_RTC0AWEN_SHIFT  1
// An RTC0 alarm event does not wake the device.
#define SI32_PMU_A_WAKEEN_RTC0AWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_RTC0AWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0AWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0AWEN_SHIFT)
// An RTC0 alarm event awakens the device.
#define SI32_PMU_A_WAKEEN_RTC0AWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_RTC0AWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_RTC0AWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_RTC0AWEN_SHIFT)

#define SI32_PMU_A_WAKEEN_CMP0WEN_MASK  0x00000020
#define SI32_PMU_A_WAKEEN_CMP0WEN_SHIFT  5
// A Comparator 0 event does not wake the device.
#define SI32_PMU_A_WAKEEN_CMP0WEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_CMP0WEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_CMP0WEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_CMP0WEN_SHIFT)
// A Comparator 0 event awakens the device.
#define SI32_PMU_A_WAKEEN_CMP0WEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_CMP0WEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_CMP0WEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_CMP0WEN_SHIFT)

#define SI32_PMU_A_WAKEEN_PWAKEWEN_MASK  0x00000040
#define SI32_PMU_A_WAKEEN_PWAKEWEN_SHIFT  6
// A Pin Wake event does not wake the device.
#define SI32_PMU_A_WAKEEN_PWAKEWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_PWAKEWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_PWAKEWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_PWAKEWEN_SHIFT)
// A Pin Wake event awakens the device.
#define SI32_PMU_A_WAKEEN_PWAKEWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_PWAKEWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_PWAKEWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_PWAKEWEN_SHIFT)

#define SI32_PMU_A_WAKEEN_LPT0WEN_MASK  0x00000080
#define SI32_PMU_A_WAKEEN_LPT0WEN_SHIFT  7
// An LPTIMER0 event does not wake the device.
#define SI32_PMU_A_WAKEEN_LPT0WEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_LPT0WEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_LPT0WEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_LPT0WEN_SHIFT)
// An LPTIMER0 event awakens the device.
#define SI32_PMU_A_WAKEEN_LPT0WEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_LPT0WEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_LPT0WEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_LPT0WEN_SHIFT)

#define SI32_PMU_A_WAKEEN_RSTWEN_MASK  0x00000100
#define SI32_PMU_A_WAKEEN_RSTWEN_SHIFT  8
// A /RESET Pin event does not wake the device.
#define SI32_PMU_A_WAKEEN_RSTWEN_DISABLED_VALUE  0
#define SI32_PMU_A_WAKEEN_RSTWEN_DISABLED_U32 \
   (SI32_PMU_A_WAKEEN_RSTWEN_DISABLED_VALUE << SI32_PMU_A_WAKEEN_RSTWEN_SHIFT)
// A /RESET Pin event awakens the device.
#define SI32_PMU_A_WAKEEN_RSTWEN_ENABLED_VALUE  1
#define SI32_PMU_A_WAKEEN_RSTWEN_ENABLED_U32 \
   (SI32_PMU_A_WAKEEN_RSTWEN_ENABLED_VALUE << SI32_PMU_A_WAKEEN_RSTWEN_SHIFT)



struct SI32_PMU_A_WAKESTATUS_Struct
{
   union
   {
      struct
      {
         // RTC0 Fail Wake Flag
         volatile uint32_t RTC0FWF: 1;
         // RTC0 Alarm Wake Flag
         volatile uint32_t RTC0AWF: 1;
                  uint32_t reserved0: 3;
         // Comparator 0 Wake Flag
         volatile uint32_t CMP0WF: 1;
         // Pin Wake Wake Flag
         volatile uint32_t PWAKEWF: 1;
         // Low Power Timer Wake Flag
         volatile uint32_t LPT0WF: 1;
         // Reset Pin Wake Flag
         volatile uint32_t RSTWF: 1;
                  uint32_t reserved1: 23;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PMU_A_WAKESTATUS_RTC0FWF_MASK  0x00000001
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_SHIFT  0
// An RTC0 fail event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0FWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0FWF_SHIFT)
// An RTC0 fail event woke the device.
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_RTC0FWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0FWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0FWF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_RTC0AWF_MASK  0x00000002
#define SI32_PMU_A_WAKESTATUS_RTC0AWF_SHIFT  1
// An RTC0 alarm event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_RTC0AWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_RTC0AWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0AWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0AWF_SHIFT)
// An RTC0 alarm event woke the device.
#define SI32_PMU_A_WAKESTATUS_RTC0AWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_RTC0AWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_RTC0AWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_RTC0AWF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_CMP0WF_MASK  0x00000020
#define SI32_PMU_A_WAKESTATUS_CMP0WF_SHIFT  5
// A Comparator 0 event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_CMP0WF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_CMP0WF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_CMP0WF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_CMP0WF_SHIFT)
// A Comparator 0 event woke the device.
#define SI32_PMU_A_WAKESTATUS_CMP0WF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_CMP0WF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_CMP0WF_SET_VALUE << SI32_PMU_A_WAKESTATUS_CMP0WF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_PWAKEWF_MASK  0x00000040
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_SHIFT  6
// A Pin Wake event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_PWAKEWF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_PWAKEWF_SHIFT)
// A Pin Wake event woke the device.
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_PWAKEWF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_PWAKEWF_SET_VALUE << SI32_PMU_A_WAKESTATUS_PWAKEWF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_LPT0WF_MASK  0x00000080
#define SI32_PMU_A_WAKESTATUS_LPT0WF_SHIFT  7
// An LPTIMER0 event did not wake the device.
#define SI32_PMU_A_WAKESTATUS_LPT0WF_NOT_SET_VALUE  0
#define SI32_PMU_A_WAKESTATUS_LPT0WF_NOT_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_LPT0WF_NOT_SET_VALUE << SI32_PMU_A_WAKESTATUS_LPT0WF_SHIFT)
// An LPTIMER0 event woke the device.
#define SI32_PMU_A_WAKESTATUS_LPT0WF_SET_VALUE  1
#define SI32_PMU_A_WAKESTATUS_LPT0WF_SET_U32 \
   (SI32_PMU_A_WAKESTATUS_LPT0WF_SET_VALUE << SI32_PMU_A_WAKESTATUS_LPT0WF_SHIFT)

#define SI32_PMU_A_WAKESTATUS_RSTWF_MASK  0x00000100
#define SI32_PMU_A_WAKESTATUS_RSTWF_SHIFT  8
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
// WAKE.0 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW0EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW0EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW0EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW0EN_SHIFT)
// WAKE.0 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW0EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW0EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW0EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW0EN_SHIFT)

#define SI32_PMU_A_PWEN_PW1EN_MASK  0x00000002
#define SI32_PMU_A_PWEN_PW1EN_SHIFT  1
// WAKE.1 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW1EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW1EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW1EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW1EN_SHIFT)
// WAKE.1 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW1EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW1EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW1EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW1EN_SHIFT)

#define SI32_PMU_A_PWEN_PW2EN_MASK  0x00000004
#define SI32_PMU_A_PWEN_PW2EN_SHIFT  2
// WAKE.2 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW2EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW2EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW2EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW2EN_SHIFT)
// WAKE.2 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW2EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW2EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW2EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW2EN_SHIFT)

#define SI32_PMU_A_PWEN_PW3EN_MASK  0x00000008
#define SI32_PMU_A_PWEN_PW3EN_SHIFT  3
// WAKE.3 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW3EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW3EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW3EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW3EN_SHIFT)
// WAKE.3 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW3EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW3EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW3EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW3EN_SHIFT)

#define SI32_PMU_A_PWEN_PW4EN_MASK  0x00000010
#define SI32_PMU_A_PWEN_PW4EN_SHIFT  4
// WAKE.4 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW4EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW4EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW4EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW4EN_SHIFT)
// WAKE.4 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW4EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW4EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW4EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW4EN_SHIFT)

#define SI32_PMU_A_PWEN_PW5EN_MASK  0x00000020
#define SI32_PMU_A_PWEN_PW5EN_SHIFT  5
// WAKE.5 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW5EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW5EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW5EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW5EN_SHIFT)
// WAKE.5 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW5EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW5EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW5EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW5EN_SHIFT)

#define SI32_PMU_A_PWEN_PW6EN_MASK  0x00000040
#define SI32_PMU_A_PWEN_PW6EN_SHIFT  6
// WAKE.6 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW6EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW6EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW6EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW6EN_SHIFT)
// WAKE.6 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW6EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW6EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW6EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW6EN_SHIFT)

#define SI32_PMU_A_PWEN_PW7EN_MASK  0x00000080
#define SI32_PMU_A_PWEN_PW7EN_SHIFT  7
// WAKE.7 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW7EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW7EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW7EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW7EN_SHIFT)
// WAKE.7 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW7EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW7EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW7EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW7EN_SHIFT)

#define SI32_PMU_A_PWEN_PW8EN_MASK  0x00000100
#define SI32_PMU_A_PWEN_PW8EN_SHIFT  8
// WAKE.8 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW8EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW8EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW8EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW8EN_SHIFT)
// WAKE.8 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW8EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW8EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW8EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW8EN_SHIFT)

#define SI32_PMU_A_PWEN_PW9EN_MASK  0x00000200
#define SI32_PMU_A_PWEN_PW9EN_SHIFT  9
// WAKE.9 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW9EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW9EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW9EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW9EN_SHIFT)
// WAKE.9 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW9EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW9EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW9EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW9EN_SHIFT)

#define SI32_PMU_A_PWEN_PW10EN_MASK  0x00000400
#define SI32_PMU_A_PWEN_PW10EN_SHIFT  10
// WAKE.10 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW10EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW10EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW10EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW10EN_SHIFT)
// WAKE.10 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW10EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW10EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW10EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW10EN_SHIFT)

#define SI32_PMU_A_PWEN_PW11EN_MASK  0x00000800
#define SI32_PMU_A_PWEN_PW11EN_SHIFT  11
// WAKE.11 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW11EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW11EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW11EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW11EN_SHIFT)
// WAKE.11 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW11EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW11EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW11EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW11EN_SHIFT)

#define SI32_PMU_A_PWEN_PW12EN_MASK  0x00001000
#define SI32_PMU_A_PWEN_PW12EN_SHIFT  12
// WAKE.12 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW12EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW12EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW12EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW12EN_SHIFT)
// WAKE.12 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW12EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW12EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW12EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW12EN_SHIFT)

#define SI32_PMU_A_PWEN_PW13EN_MASK  0x00002000
#define SI32_PMU_A_PWEN_PW13EN_SHIFT  13
// WAKE.13 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW13EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW13EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW13EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW13EN_SHIFT)
// WAKE.13 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW13EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW13EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW13EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW13EN_SHIFT)

#define SI32_PMU_A_PWEN_PW14EN_MASK  0x00004000
#define SI32_PMU_A_PWEN_PW14EN_SHIFT  14
// WAKE.14 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW14EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW14EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW14EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW14EN_SHIFT)
// WAKE.14 is used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW14EN_ENABLED_VALUE  1
#define SI32_PMU_A_PWEN_PW14EN_ENABLED_U32 \
   (SI32_PMU_A_PWEN_PW14EN_ENABLED_VALUE << SI32_PMU_A_PWEN_PW14EN_SHIFT)

#define SI32_PMU_A_PWEN_PW15EN_MASK  0x00008000
#define SI32_PMU_A_PWEN_PW15EN_SHIFT  15
// WAKE.15 is not used in the Pin Wake comparison.
#define SI32_PMU_A_PWEN_PW15EN_DISABLED_VALUE  0
#define SI32_PMU_A_PWEN_PW15EN_DISABLED_U32 \
   (SI32_PMU_A_PWEN_PW15EN_DISABLED_VALUE << SI32_PMU_A_PWEN_PW15EN_SHIFT)
// WAKE.15 is used in the Pin Wake comparison.
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
// The WAKE.0 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW0POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW0POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW0POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW0POL_SHIFT)
// The WAKE.0 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW0POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW0POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW0POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW0POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW1POL_MASK  0x00000002
#define SI32_PMU_A_PWPOL_PW1POL_SHIFT  1
// The WAKE.1 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW1POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW1POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW1POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW1POL_SHIFT)
// The WAKE.1 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW1POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW1POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW1POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW1POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW2POL_MASK  0x00000004
#define SI32_PMU_A_PWPOL_PW2POL_SHIFT  2
// The WAKE.2 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW2POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW2POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW2POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW2POL_SHIFT)
// The WAKE.2 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW2POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW2POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW2POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW2POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW3POL_MASK  0x00000008
#define SI32_PMU_A_PWPOL_PW3POL_SHIFT  3
// The WAKE.3 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW3POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW3POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW3POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW3POL_SHIFT)
// The WAKE.3 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW3POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW3POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW3POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW3POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW4POL_MASK  0x00000010
#define SI32_PMU_A_PWPOL_PW4POL_SHIFT  4
// The WAKE.4 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW4POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW4POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW4POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW4POL_SHIFT)
// The WAKE.4 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW4POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW4POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW4POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW4POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW5POL_MASK  0x00000020
#define SI32_PMU_A_PWPOL_PW5POL_SHIFT  5
// The WAKE.5 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW5POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW5POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW5POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW5POL_SHIFT)
// The WAKE.5 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW5POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW5POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW5POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW5POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW6POL_MASK  0x00000040
#define SI32_PMU_A_PWPOL_PW6POL_SHIFT  6
// The WAKE.6 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW6POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW6POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW6POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW6POL_SHIFT)
// The WAKE.6 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW6POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW6POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW6POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW6POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW7POL_MASK  0x00000080
#define SI32_PMU_A_PWPOL_PW7POL_SHIFT  7
// The WAKE.7 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW7POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW7POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW7POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW7POL_SHIFT)
// The WAKE.7 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW7POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW7POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW7POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW7POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW8POL_MASK  0x00000100
#define SI32_PMU_A_PWPOL_PW8POL_SHIFT  8
// The WAKE.8 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW8POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW8POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW8POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW8POL_SHIFT)
// The WAKE.8 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW8POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW8POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW8POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW8POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW9POL_MASK  0x00000200
#define SI32_PMU_A_PWPOL_PW9POL_SHIFT  9
// The WAKE.9 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW9POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW9POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW9POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW9POL_SHIFT)
// The WAKE.9 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW9POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW9POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW9POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW9POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW10POL_MASK  0x00000400
#define SI32_PMU_A_PWPOL_PW10POL_SHIFT  10
// The WAKE.10 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW10POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW10POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW10POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW10POL_SHIFT)
// The WAKE.10 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW10POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW10POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW10POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW10POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW11POL_MASK  0x00000800
#define SI32_PMU_A_PWPOL_PW11POL_SHIFT  11
// The WAKE.11 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW11POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW11POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW11POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW11POL_SHIFT)
// The WAKE.11 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW11POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW11POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW11POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW11POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW12POL_MASK  0x00001000
#define SI32_PMU_A_PWPOL_PW12POL_SHIFT  12
// The WAKE.12 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW12POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW12POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW12POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW12POL_SHIFT)
// The WAKE.12 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW12POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW12POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW12POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW12POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW13POL_MASK  0x00002000
#define SI32_PMU_A_PWPOL_PW13POL_SHIFT  13
// The WAKE.13 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW13POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW13POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW13POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW13POL_SHIFT)
// The WAKE.13 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW13POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW13POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW13POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW13POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW14POL_MASK  0x00004000
#define SI32_PMU_A_PWPOL_PW14POL_SHIFT  14
// The WAKE.14 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW14POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW14POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW14POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW14POL_SHIFT)
// The WAKE.14 comparison value is logic high.
#define SI32_PMU_A_PWPOL_PW14POL_HIGH_VALUE  1
#define SI32_PMU_A_PWPOL_PW14POL_HIGH_U32 \
   (SI32_PMU_A_PWPOL_PW14POL_HIGH_VALUE << SI32_PMU_A_PWPOL_PW14POL_SHIFT)

#define SI32_PMU_A_PWPOL_PW15POL_MASK  0x00008000
#define SI32_PMU_A_PWPOL_PW15POL_SHIFT  15
// The WAKE.15 comparison value is logic low.
#define SI32_PMU_A_PWPOL_PW15POL_LOW_VALUE  0
#define SI32_PMU_A_PWPOL_PW15POL_LOW_U32 \
   (SI32_PMU_A_PWPOL_PW15POL_LOW_VALUE << SI32_PMU_A_PWPOL_PW15POL_SHIFT)
// The WAKE.15 comparison value is logic high.
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

