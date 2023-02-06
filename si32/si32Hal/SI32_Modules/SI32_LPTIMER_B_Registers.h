//-----------------------------------------------------------------------------
// Copyright 2013 (c) Silicon Laboratories Inc.
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

#ifndef __SI32_LPTIMER_B_REGISTERS_H__
#define __SI32_LPTIMER_B_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_LPTIMER_B_CONTROL_Struct
{
   union
   {
      struct
      {
         // Count Mode
         volatile uint32_t CMD: 2;
                  uint32_t reserved0: 2;
         // External Trigger Source Select
         volatile uint32_t EXTSEL: 4;
         // Timer Set
         volatile uint32_t TMRSET: 1;
         // Timer Capture
         volatile uint32_t TMRCAP: 1;
         // High Speed Timer Access Mode Enable
         volatile uint32_t HSMDEN: 1;
         // Timer Compare 0 Threshold Enable
         volatile uint32_t CMP0EN: 1;
         // Timer Compare 1 Threshold Enable
         volatile uint32_t CMP1EN: 1;
         // Output Enable
         volatile uint32_t OUTEN: 1;
                  uint32_t reserved1: 2;
         // Timer Overflow Interrupt Enable
         volatile uint32_t OVFIEN: 1;
         // Timer Compare 0 Event Interrupt Enable
         volatile uint32_t CMP0IEN: 1;
         // Timer Overflow Output Enable
         volatile uint32_t OVFOEN: 1;
         // Timer Compare 0 Event Output Enable
         volatile uint32_t CMP0OEN: 1;
         // Timer Compare 1 Event Interrupt Enable
         volatile uint32_t CMP1IEN: 1;
         // Timer Compare 1 Event Output Enable
         volatile uint32_t CMP1OEN: 1;
         // Output Inversion Enable
         volatile uint32_t OUTINVEN: 1;
                  uint32_t reserved2: 1;
         // Timer Compare 0 Event Reset Enable
         volatile uint32_t CMP0RSTEN: 1;
         // Timer Compare 1 Event Reset Enable
         volatile uint32_t CMP1RSTEN: 1;
                  uint32_t reserved3: 3;
         // Low Power Timer Module Clock Enable
         volatile uint32_t MCLKEN: 1;
         // Low Power Timer Debug Mode
         volatile uint32_t DBGMD: 1;
         // Timer Run Control and Compare Threshold Enable
         volatile uint32_t RUN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LPTIMER_B_CONTROL_CMD_MASK  0x00000003
#define SI32_LPTIMER_B_CONTROL_CMD_SHIFT  0
// The timer is free running mode on the RTC timer clock (RTC0TCLK).
#define SI32_LPTIMER_B_CONTROL_CMD_FREE_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMD_FREE_U32 \
   (SI32_LPTIMER_B_CONTROL_CMD_FREE_VALUE << SI32_LPTIMER_B_CONTROL_CMD_SHIFT)
// The timer is incremented on the rising edges of the selected external trigger
// (LPTnTx).
#define SI32_LPTIMER_B_CONTROL_CMD_RISING_EDGE_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMD_RISING_EDGE_U32 \
   (SI32_LPTIMER_B_CONTROL_CMD_RISING_EDGE_VALUE << SI32_LPTIMER_B_CONTROL_CMD_SHIFT)
// The timer is incremented on the falling edges of the selected external trigger
// (LPTnTx).
#define SI32_LPTIMER_B_CONTROL_CMD_FALLING_EDGE_VALUE  2
#define SI32_LPTIMER_B_CONTROL_CMD_FALLING_EDGE_U32 \
   (SI32_LPTIMER_B_CONTROL_CMD_FALLING_EDGE_VALUE << SI32_LPTIMER_B_CONTROL_CMD_SHIFT)
// The timer is incremented on both edges of the selected external trigger
// (LPTnTx).
#define SI32_LPTIMER_B_CONTROL_CMD_ANY_EDGE_VALUE  3
#define SI32_LPTIMER_B_CONTROL_CMD_ANY_EDGE_U32 \
   (SI32_LPTIMER_B_CONTROL_CMD_ANY_EDGE_VALUE << SI32_LPTIMER_B_CONTROL_CMD_SHIFT)

#define SI32_LPTIMER_B_CONTROL_EXTSEL_MASK  0x000000F0
#define SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT  4
// Select external trigger LPTnT0.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT0_VALUE  0
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT0_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT0_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT1.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT1_VALUE  1
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT1_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT1_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT2.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT2_VALUE  2
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT2_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT2_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT3.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT3_VALUE  3
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT3_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT3_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT4.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT4_VALUE  4
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT4_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT4_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT5.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT5_VALUE  5
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT5_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT5_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT6.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT6_VALUE  6
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT6_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT6_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT7.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT7_VALUE  7
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT7_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT7_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT8.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT8_VALUE  8
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT8_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT8_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT9.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT9_VALUE  9
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT9_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT9_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT10.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT10_VALUE  10
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT10_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT10_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT11.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT11_VALUE  11
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT11_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT11_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT12.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT12_VALUE  12
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT12_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT12_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT13.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT13_VALUE  13
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT13_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT13_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT14.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT14_VALUE  14
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT14_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT14_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT15.
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT15_VALUE  15
#define SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT15_U32 \
   (SI32_LPTIMER_B_CONTROL_EXTSEL_LPTNT15_VALUE << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT)

#define SI32_LPTIMER_B_CONTROL_TMRSET_MASK  0x00000100
#define SI32_LPTIMER_B_CONTROL_TMRSET_SHIFT  8
// Writing a 1 to TMRSET initiates a copy of the value from the COUNT register into
// the internal timer register. This field is automatically cleared by hardware
// when the copy is complete and does not need to be cleared by software.
#define SI32_LPTIMER_B_CONTROL_TMRSET_SET_VALUE  1
#define SI32_LPTIMER_B_CONTROL_TMRSET_SET_U32 \
   (SI32_LPTIMER_B_CONTROL_TMRSET_SET_VALUE << SI32_LPTIMER_B_CONTROL_TMRSET_SHIFT)

#define SI32_LPTIMER_B_CONTROL_TMRCAP_MASK  0x00000200
#define SI32_LPTIMER_B_CONTROL_TMRCAP_SHIFT  9
// Writing a 1 to TMRCAP initiates a read of internal timer register into the COUNT
// register. This field is automatically cleared by hardware when the operation
// completes and does not need to be cleared by software.
#define SI32_LPTIMER_B_CONTROL_TMRCAP_SET_VALUE  1
#define SI32_LPTIMER_B_CONTROL_TMRCAP_SET_U32 \
   (SI32_LPTIMER_B_CONTROL_TMRCAP_SET_VALUE << SI32_LPTIMER_B_CONTROL_TMRCAP_SHIFT)

#define SI32_LPTIMER_B_CONTROL_HSMDEN_MASK  0x00000400
#define SI32_LPTIMER_B_CONTROL_HSMDEN_SHIFT  10
// Disable high speed timer access mode.
#define SI32_LPTIMER_B_CONTROL_HSMDEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_HSMDEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_HSMDEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_HSMDEN_SHIFT)
// Enable high speed timer access mode.
#define SI32_LPTIMER_B_CONTROL_HSMDEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_HSMDEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_HSMDEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_HSMDEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP0EN_MASK  0x00000800
#define SI32_LPTIMER_B_CONTROL_CMP0EN_SHIFT  11
#define SI32_LPTIMER_B_CONTROL_CMP0EN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP0EN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0EN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0EN_SHIFT)
#define SI32_LPTIMER_B_CONTROL_CMP0EN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP0EN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0EN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0EN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP1EN_MASK  0x00001000
#define SI32_LPTIMER_B_CONTROL_CMP1EN_SHIFT  12
#define SI32_LPTIMER_B_CONTROL_CMP1EN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP1EN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1EN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1EN_SHIFT)
#define SI32_LPTIMER_B_CONTROL_CMP1EN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP1EN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1EN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1EN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_OUTEN_MASK  0x00002000
#define SI32_LPTIMER_B_CONTROL_OUTEN_SHIFT  13
// Disable the LPTIMER0 output.
#define SI32_LPTIMER_B_CONTROL_OUTEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_OUTEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OUTEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_OUTEN_SHIFT)
// Enable the LPTIMER0 output.
#define SI32_LPTIMER_B_CONTROL_OUTEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_OUTEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OUTEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_OUTEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_OVFIEN_MASK  0x00010000
#define SI32_LPTIMER_B_CONTROL_OVFIEN_SHIFT  16
// Disable the timer overflow interrupt.
#define SI32_LPTIMER_B_CONTROL_OVFIEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_OVFIEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OVFIEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_OVFIEN_SHIFT)
// Enable the timer overflow interrupt.
#define SI32_LPTIMER_B_CONTROL_OVFIEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_OVFIEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OVFIEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_OVFIEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP0IEN_MASK  0x00020000
#define SI32_LPTIMER_B_CONTROL_CMP0IEN_SHIFT  17
// Disable the timer compare 0 event interrupt.
#define SI32_LPTIMER_B_CONTROL_CMP0IEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP0IEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0IEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0IEN_SHIFT)
// Enable the timer compare 0 event interrupt.
#define SI32_LPTIMER_B_CONTROL_CMP0IEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP0IEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0IEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0IEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_OVFOEN_MASK  0x00040000
#define SI32_LPTIMER_B_CONTROL_OVFOEN_SHIFT  18
// Timer overflows do not modify the Low Power Timer output.
#define SI32_LPTIMER_B_CONTROL_OVFOEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_OVFOEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OVFOEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_OVFOEN_SHIFT)
// Timer overflows set the Low Power Timer output to 1.
#define SI32_LPTIMER_B_CONTROL_OVFOEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_OVFOEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OVFOEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_OVFOEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP0OEN_MASK  0x00080000
#define SI32_LPTIMER_B_CONTROL_CMP0OEN_SHIFT  19
// Timer compare 0 events do not modify the Low Power Timer output.
#define SI32_LPTIMER_B_CONTROL_CMP0OEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP0OEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0OEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0OEN_SHIFT)
// Timer compare 0 events clear the Low Power Timer output to 0.
#define SI32_LPTIMER_B_CONTROL_CMP0OEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP0OEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0OEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0OEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP1IEN_MASK  0x00100000
#define SI32_LPTIMER_B_CONTROL_CMP1IEN_SHIFT  20
// Disable the timer compare 1 event interrupt.
#define SI32_LPTIMER_B_CONTROL_CMP1IEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP1IEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1IEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1IEN_SHIFT)
// Enable the timer compare 1 event interrupt.
#define SI32_LPTIMER_B_CONTROL_CMP1IEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP1IEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1IEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1IEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP1OEN_MASK  0x00200000
#define SI32_LPTIMER_B_CONTROL_CMP1OEN_SHIFT  21
// Timer compare 1 events do not modify the Low Power Timer output.
#define SI32_LPTIMER_B_CONTROL_CMP1OEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP1OEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1OEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1OEN_SHIFT)
// Timer compare 1 events set the Low Power Timer output to 1.
#define SI32_LPTIMER_B_CONTROL_CMP1OEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP1OEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1OEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1OEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_OUTINVEN_MASK  0x00400000
#define SI32_LPTIMER_B_CONTROL_OUTINVEN_SHIFT  22
// Do not invert the LPTIMER0 output.
#define SI32_LPTIMER_B_CONTROL_OUTINVEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_OUTINVEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OUTINVEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_OUTINVEN_SHIFT)
// Invert the LPTIMER0 output.
#define SI32_LPTIMER_B_CONTROL_OUTINVEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_OUTINVEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_OUTINVEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_OUTINVEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP0RSTEN_MASK  0x01000000
#define SI32_LPTIMER_B_CONTROL_CMP0RSTEN_SHIFT  24
// Timer compare 0 events do not reset the timer.
#define SI32_LPTIMER_B_CONTROL_CMP0RSTEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP0RSTEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0RSTEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0RSTEN_SHIFT)
// Timer compare 0 events reset the timer.
#define SI32_LPTIMER_B_CONTROL_CMP0RSTEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP0RSTEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP0RSTEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP0RSTEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_CMP1RSTEN_MASK  0x02000000
#define SI32_LPTIMER_B_CONTROL_CMP1RSTEN_SHIFT  25
// Timer compare 1 events do not reset the timer.
#define SI32_LPTIMER_B_CONTROL_CMP1RSTEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_CMP1RSTEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1RSTEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1RSTEN_SHIFT)
// Timer compare 1 events reset the timer.
#define SI32_LPTIMER_B_CONTROL_CMP1RSTEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_CMP1RSTEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_CMP1RSTEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_CMP1RSTEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_MCLKEN_MASK  0x20000000
#define SI32_LPTIMER_B_CONTROL_MCLKEN_SHIFT  29
// Disable the clock to the Low Power Timer module.
#define SI32_LPTIMER_B_CONTROL_MCLKEN_DISABLED_VALUE  0
#define SI32_LPTIMER_B_CONTROL_MCLKEN_DISABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_MCLKEN_DISABLED_VALUE << SI32_LPTIMER_B_CONTROL_MCLKEN_SHIFT)
// Enable the clock to the Low Power Timer module.
#define SI32_LPTIMER_B_CONTROL_MCLKEN_ENABLED_VALUE  1
#define SI32_LPTIMER_B_CONTROL_MCLKEN_ENABLED_U32 \
   (SI32_LPTIMER_B_CONTROL_MCLKEN_ENABLED_VALUE << SI32_LPTIMER_B_CONTROL_MCLKEN_SHIFT)

#define SI32_LPTIMER_B_CONTROL_DBGMD_MASK  0x40000000
#define SI32_LPTIMER_B_CONTROL_DBGMD_SHIFT  30
// The Low Power Timer module will continue to operate while the core is halted in
// debug mode.
#define SI32_LPTIMER_B_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_LPTIMER_B_CONTROL_DBGMD_RUN_U32 \
   (SI32_LPTIMER_B_CONTROL_DBGMD_RUN_VALUE << SI32_LPTIMER_B_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the Low Power Timer module to halt.
#define SI32_LPTIMER_B_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_LPTIMER_B_CONTROL_DBGMD_HALT_U32 \
   (SI32_LPTIMER_B_CONTROL_DBGMD_HALT_VALUE << SI32_LPTIMER_B_CONTROL_DBGMD_SHIFT)

#define SI32_LPTIMER_B_CONTROL_RUN_MASK  0x80000000
#define SI32_LPTIMER_B_CONTROL_RUN_SHIFT  31
// Stop the timer and disable the compare threshold.
#define SI32_LPTIMER_B_CONTROL_RUN_STOP_VALUE  0U
#define SI32_LPTIMER_B_CONTROL_RUN_STOP_U32 \
   (SI32_LPTIMER_B_CONTROL_RUN_STOP_VALUE << SI32_LPTIMER_B_CONTROL_RUN_SHIFT)
// Start the timer running and enable the compare threshold.
#define SI32_LPTIMER_B_CONTROL_RUN_START_VALUE  1U
#define SI32_LPTIMER_B_CONTROL_RUN_START_U32 \
   (SI32_LPTIMER_B_CONTROL_RUN_START_VALUE << SI32_LPTIMER_B_CONTROL_RUN_SHIFT)



struct SI32_LPTIMER_B_COUNT_Struct
{
   union
   {
      struct
      {
         // Timer Value
         volatile uint16_t TIMER;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LPTIMER_B_COUNT_TIMER_MASK  0x0000FFFF
#define SI32_LPTIMER_B_COUNT_TIMER_SHIFT  0



struct SI32_LPTIMER_B_THRESHOLD_Struct
{
   union
   {
      struct
      {
         // Timer Compare 0 Threshold Value
         volatile uint16_t COMPARE0;
         // Timer Compare 1 Threshold Value
         volatile uint16_t COMPARE1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LPTIMER_B_THRESHOLD_COMPARE0_MASK  0x0000FFFF
#define SI32_LPTIMER_B_THRESHOLD_COMPARE0_SHIFT  0

#define SI32_LPTIMER_B_THRESHOLD_COMPARE1_MASK  0xFFFF0000
#define SI32_LPTIMER_B_THRESHOLD_COMPARE1_SHIFT  16



struct SI32_LPTIMER_B_STATUS_Struct
{
   union
   {
      struct
      {
         // Timer Overflow Interrupt Flag
         volatile uint32_t OVFI: 1;
         // Timer Compare 0 Event Interrupt Flag
         volatile uint32_t CMP0I: 1;
         // Timer Compare 1 Event Interrupt Flag
         volatile uint32_t CMP1I: 1;
                  uint32_t reserved0: 29;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LPTIMER_B_STATUS_OVFI_MASK  0x00000001
#define SI32_LPTIMER_B_STATUS_OVFI_SHIFT  0
// A timer overflow has not occurred.
#define SI32_LPTIMER_B_STATUS_OVFI_NOT_SET_VALUE  0
#define SI32_LPTIMER_B_STATUS_OVFI_NOT_SET_U32 \
   (SI32_LPTIMER_B_STATUS_OVFI_NOT_SET_VALUE << SI32_LPTIMER_B_STATUS_OVFI_SHIFT)
// A timer overflow occurred.
#define SI32_LPTIMER_B_STATUS_OVFI_SET_VALUE  1
#define SI32_LPTIMER_B_STATUS_OVFI_SET_U32 \
   (SI32_LPTIMER_B_STATUS_OVFI_SET_VALUE << SI32_LPTIMER_B_STATUS_OVFI_SHIFT)

#define SI32_LPTIMER_B_STATUS_CMP0I_MASK  0x00000002
#define SI32_LPTIMER_B_STATUS_CMP0I_SHIFT  1
// A timer compare 0 event has not occurred.
#define SI32_LPTIMER_B_STATUS_CMP0I_NOT_SET_VALUE  0
#define SI32_LPTIMER_B_STATUS_CMP0I_NOT_SET_U32 \
   (SI32_LPTIMER_B_STATUS_CMP0I_NOT_SET_VALUE << SI32_LPTIMER_B_STATUS_CMP0I_SHIFT)
// A timer compare 0 event occurred.
#define SI32_LPTIMER_B_STATUS_CMP0I_SET_VALUE  1
#define SI32_LPTIMER_B_STATUS_CMP0I_SET_U32 \
   (SI32_LPTIMER_B_STATUS_CMP0I_SET_VALUE << SI32_LPTIMER_B_STATUS_CMP0I_SHIFT)

#define SI32_LPTIMER_B_STATUS_CMP1I_MASK  0x00000004
#define SI32_LPTIMER_B_STATUS_CMP1I_SHIFT  2
// A timer compare 1 event has not occurred.
#define SI32_LPTIMER_B_STATUS_CMP1I_NOT_SET_VALUE  0
#define SI32_LPTIMER_B_STATUS_CMP1I_NOT_SET_U32 \
   (SI32_LPTIMER_B_STATUS_CMP1I_NOT_SET_VALUE << SI32_LPTIMER_B_STATUS_CMP1I_SHIFT)
// A timer compare 1 event occurred.
#define SI32_LPTIMER_B_STATUS_CMP1I_SET_VALUE  1
#define SI32_LPTIMER_B_STATUS_CMP1I_SET_U32 \
   (SI32_LPTIMER_B_STATUS_CMP1I_SET_VALUE << SI32_LPTIMER_B_STATUS_CMP1I_SHIFT)



typedef struct SI32_LPTIMER_B_Struct
{
   struct SI32_LPTIMER_B_CONTROL_Struct            CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_LPTIMER_B_COUNT_Struct              COUNT          ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_LPTIMER_B_THRESHOLD_Struct          THRESHOLD      ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_LPTIMER_B_STATUS_Struct             STATUS         ; // Base Address + 0x30
   volatile uint32_t                               STATUS_SET;
   volatile uint32_t                               STATUS_CLR;
   uint32_t                                        reserved7;
} SI32_LPTIMER_B_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_LPTIMER_B_REGISTERS_H__

//-eof--------------------------------------------------------------------------

