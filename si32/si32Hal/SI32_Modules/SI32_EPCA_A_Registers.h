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

#ifndef __SI32_EPCA_A_REGISTERS_H__
#define __SI32_EPCA_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_EPCA_A_MODE_Struct
{
   union
   {
      struct
      {
         // Input Clock Divider
         volatile uint32_t CLKDIV: 10;
         // Input Clock (F<subscript>CLKIN</subscript>) Select
         volatile uint32_t CLKSEL: 3;
                  uint32_t reserved0: 1;
         // High Drive Port Bank Output Select
         volatile uint32_t HDOSEL: 2;
         // DMA Write End Index
         volatile uint32_t DEND: 3;
         // DMA Write Transfer Pointer
         volatile uint32_t DPTR: 3;
         // DMA Target Start Index
         volatile uint32_t DSTART: 3;
         // DMA Busy Flag
         volatile uint32_t DBUSYF: 1;
                  uint32_t reserved1: 1;
         // Standard Port Bank Output Select
         volatile uint32_t STDOSEL: 2;
                  uint32_t reserved2: 3;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_MODE_CLKDIV_MASK  0x000003FF
#define SI32_EPCA_A_MODE_CLKDIV_SHIFT  0

#define SI32_EPCA_A_MODE_CLKSEL_MASK  0x00001C00
#define SI32_EPCA_A_MODE_CLKSEL_SHIFT  10
// Set the APB as the input clock (FCLKIN).
#define SI32_EPCA_A_MODE_CLKSEL_APB_VALUE  0
#define SI32_EPCA_A_MODE_CLKSEL_APB_U32 \
   (SI32_EPCA_A_MODE_CLKSEL_APB_VALUE << SI32_EPCA_A_MODE_CLKSEL_SHIFT)
// Set Timer 0 low overflows divided by 2 as the input clock (FCLKIN).
#define SI32_EPCA_A_MODE_CLKSEL_TIMER0_VALUE  1
#define SI32_EPCA_A_MODE_CLKSEL_TIMER0_U32 \
   (SI32_EPCA_A_MODE_CLKSEL_TIMER0_VALUE << SI32_EPCA_A_MODE_CLKSEL_SHIFT)
// Set high-to-low transitions on ECI divided by 2 as the input clock (FCLKIN).
#define SI32_EPCA_A_MODE_CLKSEL_HL_ECI_VALUE  2
#define SI32_EPCA_A_MODE_CLKSEL_HL_ECI_U32 \
   (SI32_EPCA_A_MODE_CLKSEL_HL_ECI_VALUE << SI32_EPCA_A_MODE_CLKSEL_SHIFT)
// Set the external oscillator module output (EXTOSCn) divided by 2 as the input
// clock (FCLKIN).
#define SI32_EPCA_A_MODE_CLKSEL_EXTOSCN_VALUE  3
#define SI32_EPCA_A_MODE_CLKSEL_EXTOSCN_U32 \
   (SI32_EPCA_A_MODE_CLKSEL_EXTOSCN_VALUE << SI32_EPCA_A_MODE_CLKSEL_SHIFT)
// Set ECI transitions divided by 2 as the input clock (FCLKIN).
#define SI32_EPCA_A_MODE_CLKSEL_ECI_VALUE  4
#define SI32_EPCA_A_MODE_CLKSEL_ECI_U32 \
   (SI32_EPCA_A_MODE_CLKSEL_ECI_VALUE << SI32_EPCA_A_MODE_CLKSEL_SHIFT)

#define SI32_EPCA_A_MODE_HDOSEL_MASK  0x0000C000
#define SI32_EPCA_A_MODE_HDOSEL_SHIFT  14
// Select three differential outputs from Channels 3, 4, and 5 for the High Drive
// pins.
#define SI32_EPCA_A_MODE_HDOSEL_THREE_DIFF_VALUE  0
#define SI32_EPCA_A_MODE_HDOSEL_THREE_DIFF_U32 \
   (SI32_EPCA_A_MODE_HDOSEL_THREE_DIFF_VALUE << SI32_EPCA_A_MODE_HDOSEL_SHIFT)
// Select the differential outputs from Channels 4 and 5 and non-differential
// outputs from Channels 2 and 3 for the High Drive pins.
#define SI32_EPCA_A_MODE_HDOSEL_TWO_DIFF_VALUE  1
#define SI32_EPCA_A_MODE_HDOSEL_TWO_DIFF_U32 \
   (SI32_EPCA_A_MODE_HDOSEL_TWO_DIFF_VALUE << SI32_EPCA_A_MODE_HDOSEL_SHIFT)
// Select the differential output from Channel 5 and non-differential outputs from
// Channels 1-4 for the High Drive pins.
#define SI32_EPCA_A_MODE_HDOSEL_ONE_DIFF_VALUE  2
#define SI32_EPCA_A_MODE_HDOSEL_ONE_DIFF_U32 \
   (SI32_EPCA_A_MODE_HDOSEL_ONE_DIFF_VALUE << SI32_EPCA_A_MODE_HDOSEL_SHIFT)
// Select the non-differential channel outputs (Channels 0-5) for the High Drive
// pins.
#define SI32_EPCA_A_MODE_HDOSEL_NO_DIFF_VALUE  3
#define SI32_EPCA_A_MODE_HDOSEL_NO_DIFF_U32 \
   (SI32_EPCA_A_MODE_HDOSEL_NO_DIFF_VALUE << SI32_EPCA_A_MODE_HDOSEL_SHIFT)

#define SI32_EPCA_A_MODE_DEND_MASK  0x00070000
#define SI32_EPCA_A_MODE_DEND_SHIFT  16
// Set the last register in a DMA write transfer to LIMITUPD.
#define SI32_EPCA_A_MODE_DEND_LIMIT_VALUE  0
#define SI32_EPCA_A_MODE_DEND_LIMIT_U32 \
   (SI32_EPCA_A_MODE_DEND_LIMIT_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)
// Set the last register in a DMA write transfer to Channel 0 CCAPVUPD.
#define SI32_EPCA_A_MODE_DEND_CH0_VALUE  1
#define SI32_EPCA_A_MODE_DEND_CH0_U32 \
   (SI32_EPCA_A_MODE_DEND_CH0_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)
// Set the last register in a DMA write transfer to Channel 1 CCAPVUPD.
#define SI32_EPCA_A_MODE_DEND_CH1_VALUE  2
#define SI32_EPCA_A_MODE_DEND_CH1_U32 \
   (SI32_EPCA_A_MODE_DEND_CH1_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)
// Set the last register in a DMA write transfer to Channel 2 CCAPVUPD.
#define SI32_EPCA_A_MODE_DEND_CH2_VALUE  3
#define SI32_EPCA_A_MODE_DEND_CH2_U32 \
   (SI32_EPCA_A_MODE_DEND_CH2_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)
// Set the last register in a DMA write transfer to Channel 3 CCAPVUPD.
#define SI32_EPCA_A_MODE_DEND_CH3_VALUE  4
#define SI32_EPCA_A_MODE_DEND_CH3_U32 \
   (SI32_EPCA_A_MODE_DEND_CH3_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)
// Set the last register in a DMA write transfer to Channel 4 CCAPVUPD.
#define SI32_EPCA_A_MODE_DEND_CH4_VALUE  5
#define SI32_EPCA_A_MODE_DEND_CH4_U32 \
   (SI32_EPCA_A_MODE_DEND_CH4_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)
// Set the last register in a DMA write transfer to Channel 5 CCAPVUPD.
#define SI32_EPCA_A_MODE_DEND_CH5_VALUE  6
#define SI32_EPCA_A_MODE_DEND_CH5_U32 \
   (SI32_EPCA_A_MODE_DEND_CH5_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)
// Empty slot.
#define SI32_EPCA_A_MODE_DEND_EMPTY_VALUE  7
#define SI32_EPCA_A_MODE_DEND_EMPTY_U32 \
   (SI32_EPCA_A_MODE_DEND_EMPTY_VALUE << SI32_EPCA_A_MODE_DEND_SHIFT)

#define SI32_EPCA_A_MODE_DPTR_MASK  0x00380000
#define SI32_EPCA_A_MODE_DPTR_SHIFT  19
// The DMA channel will write to LIMITUPD next.
#define SI32_EPCA_A_MODE_DPTR_LIMIT_VALUE  0
#define SI32_EPCA_A_MODE_DPTR_LIMIT_U32 \
   (SI32_EPCA_A_MODE_DPTR_LIMIT_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)
// The DMA channel will write to Channel 0 CCAPVUPD next.
#define SI32_EPCA_A_MODE_DPTR_CH0_VALUE  1
#define SI32_EPCA_A_MODE_DPTR_CH0_U32 \
   (SI32_EPCA_A_MODE_DPTR_CH0_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)
// The DMA channel will write to Channel 1 CCAPVUPD next.
#define SI32_EPCA_A_MODE_DPTR_CH1_VALUE  2
#define SI32_EPCA_A_MODE_DPTR_CH1_U32 \
   (SI32_EPCA_A_MODE_DPTR_CH1_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)
// The DMA channel will write to Channel 2 CCAPVUPD next.
#define SI32_EPCA_A_MODE_DPTR_CH2_VALUE  3
#define SI32_EPCA_A_MODE_DPTR_CH2_U32 \
   (SI32_EPCA_A_MODE_DPTR_CH2_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)
// The DMA channel will write to Channel 3 CCAPVUPD next.
#define SI32_EPCA_A_MODE_DPTR_CH3_VALUE  4
#define SI32_EPCA_A_MODE_DPTR_CH3_U32 \
   (SI32_EPCA_A_MODE_DPTR_CH3_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)
// The DMA channel will write to Channel 4 CCAPVUPD next.
#define SI32_EPCA_A_MODE_DPTR_CH4_VALUE  5
#define SI32_EPCA_A_MODE_DPTR_CH4_U32 \
   (SI32_EPCA_A_MODE_DPTR_CH4_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)
// The DMA channel will write to Channel 5 CCAPVUPD next.
#define SI32_EPCA_A_MODE_DPTR_CH5_VALUE  6
#define SI32_EPCA_A_MODE_DPTR_CH5_U32 \
   (SI32_EPCA_A_MODE_DPTR_CH5_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)
// Empty slot.
#define SI32_EPCA_A_MODE_DPTR_EMPTY_VALUE  7
#define SI32_EPCA_A_MODE_DPTR_EMPTY_U32 \
   (SI32_EPCA_A_MODE_DPTR_EMPTY_VALUE << SI32_EPCA_A_MODE_DPTR_SHIFT)

#define SI32_EPCA_A_MODE_DSTART_MASK  0x01C00000
#define SI32_EPCA_A_MODE_DSTART_SHIFT  22
// Set the first register in a DMA write transfer to LIMITUPD.
#define SI32_EPCA_A_MODE_DSTART_LIMIT_VALUE  0
#define SI32_EPCA_A_MODE_DSTART_LIMIT_U32 \
   (SI32_EPCA_A_MODE_DSTART_LIMIT_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)
// Set the first register in a DMA write transfer to Channel 0 CCAPVUPD.
#define SI32_EPCA_A_MODE_DSTART_CH0_VALUE  1
#define SI32_EPCA_A_MODE_DSTART_CH0_U32 \
   (SI32_EPCA_A_MODE_DSTART_CH0_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)
// Set the first register in a DMA write transfer to Channel 1 CCAPVUPD.
#define SI32_EPCA_A_MODE_DSTART_CH1_VALUE  2
#define SI32_EPCA_A_MODE_DSTART_CH1_U32 \
   (SI32_EPCA_A_MODE_DSTART_CH1_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)
// Set the first register in a DMA write transfer to Channel 2 CCAPVUPD.
#define SI32_EPCA_A_MODE_DSTART_CH2_VALUE  3
#define SI32_EPCA_A_MODE_DSTART_CH2_U32 \
   (SI32_EPCA_A_MODE_DSTART_CH2_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)
// Set the first register in a DMA write transfer to Channel 3 CCAPVUPD.
#define SI32_EPCA_A_MODE_DSTART_CH3_VALUE  4
#define SI32_EPCA_A_MODE_DSTART_CH3_U32 \
   (SI32_EPCA_A_MODE_DSTART_CH3_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)
// Set the first register in a DMA write transfer to Channel 4 CCAPVUPD.
#define SI32_EPCA_A_MODE_DSTART_CH4_VALUE  5
#define SI32_EPCA_A_MODE_DSTART_CH4_U32 \
   (SI32_EPCA_A_MODE_DSTART_CH4_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)
// Set the first register in a DMA write transfer to Channel 5 CCAPVUPD.
#define SI32_EPCA_A_MODE_DSTART_CH5_VALUE  6
#define SI32_EPCA_A_MODE_DSTART_CH5_U32 \
   (SI32_EPCA_A_MODE_DSTART_CH5_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)
// Empty slot.
#define SI32_EPCA_A_MODE_DSTART_EMPTY_VALUE  7
#define SI32_EPCA_A_MODE_DSTART_EMPTY_U32 \
   (SI32_EPCA_A_MODE_DSTART_EMPTY_VALUE << SI32_EPCA_A_MODE_DSTART_SHIFT)

#define SI32_EPCA_A_MODE_DBUSYF_MASK  0x02000000
#define SI32_EPCA_A_MODE_DBUSYF_SHIFT  25
// The DMA channel is not servicing an EPCA control transfer.
#define SI32_EPCA_A_MODE_DBUSYF_IDLE_VALUE  0
#define SI32_EPCA_A_MODE_DBUSYF_IDLE_U32 \
   (SI32_EPCA_A_MODE_DBUSYF_IDLE_VALUE << SI32_EPCA_A_MODE_DBUSYF_SHIFT)
// The DMA channel is busy servicing an EPCA control transfer.
#define SI32_EPCA_A_MODE_DBUSYF_BUSY_VALUE  1
#define SI32_EPCA_A_MODE_DBUSYF_BUSY_U32 \
   (SI32_EPCA_A_MODE_DBUSYF_BUSY_VALUE << SI32_EPCA_A_MODE_DBUSYF_SHIFT)

#define SI32_EPCA_A_MODE_STDOSEL_MASK  0x18000000
#define SI32_EPCA_A_MODE_STDOSEL_SHIFT  27
// Select the non-differential channel outputs (Channels 0-5) for the standard PB
// pins.
#define SI32_EPCA_A_MODE_STDOSEL_NO_DIFF_VALUE  0
#define SI32_EPCA_A_MODE_STDOSEL_NO_DIFF_U32 \
   (SI32_EPCA_A_MODE_STDOSEL_NO_DIFF_VALUE << SI32_EPCA_A_MODE_STDOSEL_SHIFT)
// Select the differential output from Channel 2 and non-differential outputs from
// Channels 0, 1, 3, and 4 for the standard PB pins.
#define SI32_EPCA_A_MODE_STDOSEL_ONE_DIFF_VALUE  1
#define SI32_EPCA_A_MODE_STDOSEL_ONE_DIFF_U32 \
   (SI32_EPCA_A_MODE_STDOSEL_ONE_DIFF_VALUE << SI32_EPCA_A_MODE_STDOSEL_SHIFT)
// Select the differential outputs from Channels 1 and 2 and non-differential
// outputs from Channels 0 and 3 for the standard PB pins.
#define SI32_EPCA_A_MODE_STDOSEL_TWO_DIFF_VALUE  2
#define SI32_EPCA_A_MODE_STDOSEL_TWO_DIFF_U32 \
   (SI32_EPCA_A_MODE_STDOSEL_TWO_DIFF_VALUE << SI32_EPCA_A_MODE_STDOSEL_SHIFT)
// Select three differential outputs from Channels 0, 1, and 2 for the standard PB
// pins.
#define SI32_EPCA_A_MODE_STDOSEL_THREE_DIFF_VALUE  3
#define SI32_EPCA_A_MODE_STDOSEL_THREE_DIFF_U32 \
   (SI32_EPCA_A_MODE_STDOSEL_THREE_DIFF_VALUE << SI32_EPCA_A_MODE_STDOSEL_SHIFT)



struct SI32_EPCA_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // EPCA Counter Overflow/Limit Interrupt Enable
         volatile uint32_t OVFIEN: 1;
         // EPCA Counter Overflow/Limit DMA Request Enable
         volatile uint32_t OVFDEN: 1;
         // EPCA Counter Overflow/Limit Synchronization Signal Enable
         volatile uint32_t OVFSEN: 1;
         // EPCA Halt Input Interrupt Enable
         volatile uint32_t HALTIEN: 1;
         // Internal Register Update Inhibit
         volatile uint32_t NOUPD: 1;
                  uint32_t reserved0: 1;
         // EPCA Debug Mode
         volatile uint32_t DBGMD: 1;
                  uint32_t reserved1: 2;
         // Halt Input Enable
         volatile uint32_t HALTEN: 1;
                  uint32_t reserved2: 1;
         // Synchronous Input Trigger Select
         volatile uint32_t STSEL: 2;
         // Synchronous Input Trigger Edge Select
         volatile uint32_t STESEL: 1;
         // Synchronous Input Trigger Enable
         volatile uint32_t STEN: 1;
                  uint32_t reserved3: 6;
         // Clock Divider Output State
         volatile uint32_t DIVST: 1;
         // Current Clock Divider Count
         volatile uint32_t DIV: 10;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_CONTROL_OVFIEN_MASK  0x00000001
#define SI32_EPCA_A_CONTROL_OVFIEN_SHIFT  0
// Disable the EPCA counter overflow/limit event interrupt.
#define SI32_EPCA_A_CONTROL_OVFIEN_DISABLED_VALUE  0
#define SI32_EPCA_A_CONTROL_OVFIEN_DISABLED_U32 \
   (SI32_EPCA_A_CONTROL_OVFIEN_DISABLED_VALUE << SI32_EPCA_A_CONTROL_OVFIEN_SHIFT)
// Enable the EPCA counter overflow/limit event interrupt.
#define SI32_EPCA_A_CONTROL_OVFIEN_ENABLED_VALUE  1
#define SI32_EPCA_A_CONTROL_OVFIEN_ENABLED_U32 \
   (SI32_EPCA_A_CONTROL_OVFIEN_ENABLED_VALUE << SI32_EPCA_A_CONTROL_OVFIEN_SHIFT)

#define SI32_EPCA_A_CONTROL_OVFDEN_MASK  0x00000002
#define SI32_EPCA_A_CONTROL_OVFDEN_SHIFT  1
// Do not request DMA data when a EPCA counter overflow/limit event occurs.
#define SI32_EPCA_A_CONTROL_OVFDEN_DISABLED_VALUE  0
#define SI32_EPCA_A_CONTROL_OVFDEN_DISABLED_U32 \
   (SI32_EPCA_A_CONTROL_OVFDEN_DISABLED_VALUE << SI32_EPCA_A_CONTROL_OVFDEN_SHIFT)
// Request DMA data when a EPCA counter overflow/limit event occurs.
#define SI32_EPCA_A_CONTROL_OVFDEN_ENABLED_VALUE  1
#define SI32_EPCA_A_CONTROL_OVFDEN_ENABLED_U32 \
   (SI32_EPCA_A_CONTROL_OVFDEN_ENABLED_VALUE << SI32_EPCA_A_CONTROL_OVFDEN_SHIFT)

#define SI32_EPCA_A_CONTROL_OVFSEN_MASK  0x00000004
#define SI32_EPCA_A_CONTROL_OVFSEN_SHIFT  2
// Do not send a synchronization signal when a EPCA counter overflow/limit event
// occurs.
#define SI32_EPCA_A_CONTROL_OVFSEN_DISABLED_VALUE  0
#define SI32_EPCA_A_CONTROL_OVFSEN_DISABLED_U32 \
   (SI32_EPCA_A_CONTROL_OVFSEN_DISABLED_VALUE << SI32_EPCA_A_CONTROL_OVFSEN_SHIFT)
// Send a synchronization signal when a EPCA counter overflow/limit event occurs.
#define SI32_EPCA_A_CONTROL_OVFSEN_ENABLED_VALUE  1
#define SI32_EPCA_A_CONTROL_OVFSEN_ENABLED_U32 \
   (SI32_EPCA_A_CONTROL_OVFSEN_ENABLED_VALUE << SI32_EPCA_A_CONTROL_OVFSEN_SHIFT)

#define SI32_EPCA_A_CONTROL_HALTIEN_MASK  0x00000008
#define SI32_EPCA_A_CONTROL_HALTIEN_SHIFT  3
// Do not generate an interrupt if the EPCA halt input is high.
#define SI32_EPCA_A_CONTROL_HALTIEN_DISABLED_VALUE  0
#define SI32_EPCA_A_CONTROL_HALTIEN_DISABLED_U32 \
   (SI32_EPCA_A_CONTROL_HALTIEN_DISABLED_VALUE << SI32_EPCA_A_CONTROL_HALTIEN_SHIFT)
// Generate an interrupt if the EPCA halt input is high.
#define SI32_EPCA_A_CONTROL_HALTIEN_ENABLED_VALUE  1
#define SI32_EPCA_A_CONTROL_HALTIEN_ENABLED_U32 \
   (SI32_EPCA_A_CONTROL_HALTIEN_ENABLED_VALUE << SI32_EPCA_A_CONTROL_HALTIEN_SHIFT)

#define SI32_EPCA_A_CONTROL_NOUPD_MASK  0x00000010
#define SI32_EPCA_A_CONTROL_NOUPD_SHIFT  4
// The EPCA registers will automatically load any new update values after an
// overflow/limit event occurs.
#define SI32_EPCA_A_CONTROL_NOUPD_INACTIVE_VALUE  0
#define SI32_EPCA_A_CONTROL_NOUPD_INACTIVE_U32 \
   (SI32_EPCA_A_CONTROL_NOUPD_INACTIVE_VALUE << SI32_EPCA_A_CONTROL_NOUPD_SHIFT)
// The EPCA registers will not load any new update values after an overflow/limit
// event occurs.
#define SI32_EPCA_A_CONTROL_NOUPD_ACTIVE_VALUE  1
#define SI32_EPCA_A_CONTROL_NOUPD_ACTIVE_U32 \
   (SI32_EPCA_A_CONTROL_NOUPD_ACTIVE_VALUE << SI32_EPCA_A_CONTROL_NOUPD_SHIFT)

#define SI32_EPCA_A_CONTROL_DBGMD_MASK  0x00000040
#define SI32_EPCA_A_CONTROL_DBGMD_SHIFT  6
// A debug breakpoint will stop the EPCA counter/timer.
#define SI32_EPCA_A_CONTROL_DBGMD_HALT_VALUE  0
#define SI32_EPCA_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_EPCA_A_CONTROL_DBGMD_HALT_VALUE << SI32_EPCA_A_CONTROL_DBGMD_SHIFT)
// The EPCA will continue to operate while the core is halted in debug mode.
#define SI32_EPCA_A_CONTROL_DBGMD_RUN_VALUE  1
#define SI32_EPCA_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_EPCA_A_CONTROL_DBGMD_RUN_VALUE << SI32_EPCA_A_CONTROL_DBGMD_SHIFT)

#define SI32_EPCA_A_CONTROL_HALTEN_MASK  0x00000200
#define SI32_EPCA_A_CONTROL_HALTEN_SHIFT  9
// The Halt input (PB_HDKill) does not affect the EPCA counter/timer.
#define SI32_EPCA_A_CONTROL_HALTEN_DISABLED_VALUE  0
#define SI32_EPCA_A_CONTROL_HALTEN_DISABLED_U32 \
   (SI32_EPCA_A_CONTROL_HALTEN_DISABLED_VALUE << SI32_EPCA_A_CONTROL_HALTEN_SHIFT)
// An assertion of the Halt input (PB_HDKill) will stop the EPCA counter/timer.
#define SI32_EPCA_A_CONTROL_HALTEN_ENABLED_VALUE  1
#define SI32_EPCA_A_CONTROL_HALTEN_ENABLED_U32 \
   (SI32_EPCA_A_CONTROL_HALTEN_ENABLED_VALUE << SI32_EPCA_A_CONTROL_HALTEN_SHIFT)

#define SI32_EPCA_A_CONTROL_STSEL_MASK  0x00001800
#define SI32_EPCA_A_CONTROL_STSEL_SHIFT  11
// Select input trigger 0, Comparator0 output.
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT0_VALUE  0
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT0_U32 \
   (SI32_EPCA_A_CONTROL_STSEL_EPCANT0_VALUE << SI32_EPCA_A_CONTROL_STSEL_SHIFT)
// Select input trigger 1, Comparator1 output.
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT1_VALUE  1
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT1_U32 \
   (SI32_EPCA_A_CONTROL_STSEL_EPCANT1_VALUE << SI32_EPCA_A_CONTROL_STSEL_SHIFT)
// Select input trigger 2, Timer 0 high overflow.
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT2_VALUE  2
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT2_U32 \
   (SI32_EPCA_A_CONTROL_STSEL_EPCANT2_VALUE << SI32_EPCA_A_CONTROL_STSEL_SHIFT)
// Select input trigger 3, Timer 1 high overflow.
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT3_VALUE  3
#define SI32_EPCA_A_CONTROL_STSEL_EPCANT3_U32 \
   (SI32_EPCA_A_CONTROL_STSEL_EPCANT3_VALUE << SI32_EPCA_A_CONTROL_STSEL_SHIFT)

#define SI32_EPCA_A_CONTROL_STESEL_MASK  0x00002000
#define SI32_EPCA_A_CONTROL_STESEL_SHIFT  13
// A high-to-low transition (falling edge) on EPCAnTx will start the counter/timer.
#define SI32_EPCA_A_CONTROL_STESEL_FALLING_VALUE  0
#define SI32_EPCA_A_CONTROL_STESEL_FALLING_U32 \
   (SI32_EPCA_A_CONTROL_STESEL_FALLING_VALUE << SI32_EPCA_A_CONTROL_STESEL_SHIFT)
// A low-to-high transition (rising edge) on EPCAnTx will start the counter/timer.
#define SI32_EPCA_A_CONTROL_STESEL_RISING_VALUE  1
#define SI32_EPCA_A_CONTROL_STESEL_RISING_U32 \
   (SI32_EPCA_A_CONTROL_STESEL_RISING_VALUE << SI32_EPCA_A_CONTROL_STESEL_SHIFT)

#define SI32_EPCA_A_CONTROL_STEN_MASK  0x00004000
#define SI32_EPCA_A_CONTROL_STEN_SHIFT  14
// Disable the input trigger (EPCAnTx). The EPCA counter/timer will continue to run
// if the RUN bit is set regardless of the value on the input trigger.
#define SI32_EPCA_A_CONTROL_STEN_DISABLED_VALUE  0
#define SI32_EPCA_A_CONTROL_STEN_DISABLED_U32 \
   (SI32_EPCA_A_CONTROL_STEN_DISABLED_VALUE << SI32_EPCA_A_CONTROL_STEN_SHIFT)
// Enable the input trigger (EPCAnTx). If RUN is set to 1, the EPCA counter/timer
// will start running when the selected input trigger (STSEL) meets the criteria
// set by STESEL. It will not stop running if the criteria is no longer met.
#define SI32_EPCA_A_CONTROL_STEN_ENABLED_VALUE  1
#define SI32_EPCA_A_CONTROL_STEN_ENABLED_U32 \
   (SI32_EPCA_A_CONTROL_STEN_ENABLED_VALUE << SI32_EPCA_A_CONTROL_STEN_SHIFT)

#define SI32_EPCA_A_CONTROL_DIVST_MASK  0x00200000
#define SI32_EPCA_A_CONTROL_DIVST_SHIFT  21
// The clock divider is currently in the first half-cycle.
#define SI32_EPCA_A_CONTROL_DIVST_OUTPUT_HIGH_VALUE  0
#define SI32_EPCA_A_CONTROL_DIVST_OUTPUT_HIGH_U32 \
   (SI32_EPCA_A_CONTROL_DIVST_OUTPUT_HIGH_VALUE << SI32_EPCA_A_CONTROL_DIVST_SHIFT)
// The clock divider is currently in the second half-cycle.
#define SI32_EPCA_A_CONTROL_DIVST_OUTPUT_LOW_VALUE  1
#define SI32_EPCA_A_CONTROL_DIVST_OUTPUT_LOW_U32 \
   (SI32_EPCA_A_CONTROL_DIVST_OUTPUT_LOW_VALUE << SI32_EPCA_A_CONTROL_DIVST_SHIFT)

#define SI32_EPCA_A_CONTROL_DIV_MASK  0xFFC00000
#define SI32_EPCA_A_CONTROL_DIV_SHIFT  22



struct SI32_EPCA_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Channel 0 Capture/Compare Interrupt Flag
         volatile uint32_t C0CCI: 1;
         // Channel 1 Capture/Compare Interrupt Flag
         volatile uint32_t C1CCI: 1;
         // Channel 2 Capture/Compare Interrupt Flag
         volatile uint32_t C2CCI: 1;
         // Channel 3 Capture/Compare Interrupt Flag
         volatile uint32_t C3CCI: 1;
         // Channel 4 Capture/Compare Interrupt Flag
         volatile uint32_t C4CCI: 1;
         // Channel 5 Capture/Compare Interrupt Flag
         volatile uint32_t C5CCI: 1;
         // Counter/Timer Run
         volatile uint32_t RUN: 1;
         // Counter/Timer Overflow/Limit Interrupt Flag
         volatile uint32_t OVFI: 1;
         // Register Update Complete Flag
         volatile uint32_t UPDCF: 1;
         // Halt Input Interrupt Flag
         volatile uint32_t HALTI: 1;
         // Channel 0 Intermediate Overflow Interrupt Flag
         volatile uint32_t C0IOVFI: 1;
         // Channel 1 Intermediate Overflow Interrupt Flag
         volatile uint32_t C1IOVFI: 1;
         // Channel 2 Intermediate Overflow Interrupt Flag
         volatile uint32_t C2IOVFI: 1;
         // Channel 3 Intermediate Overflow Interrupt Flag
         volatile uint32_t C3IOVFI: 1;
         // Channel 4 Intermediate Overflow Interrupt Flag
         volatile uint32_t C4IOVFI: 1;
         // Channel 5 Intermediate Overflow Interrupt Flag
         volatile uint32_t C5IOVFI: 1;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_STATUS_C0CCI_MASK  0x00000001
#define SI32_EPCA_A_STATUS_C0CCI_SHIFT  0
// A Channel 0 match or capture event did not occur.
#define SI32_EPCA_A_STATUS_C0CCI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C0CCI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C0CCI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C0CCI_SHIFT)
// A Channel 0 match or capture event occurred.
#define SI32_EPCA_A_STATUS_C0CCI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C0CCI_SET_U32 \
   (SI32_EPCA_A_STATUS_C0CCI_SET_VALUE << SI32_EPCA_A_STATUS_C0CCI_SHIFT)

#define SI32_EPCA_A_STATUS_C1CCI_MASK  0x00000002
#define SI32_EPCA_A_STATUS_C1CCI_SHIFT  1
// A Channel 1 match or capture event did not occur.
#define SI32_EPCA_A_STATUS_C1CCI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C1CCI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C1CCI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C1CCI_SHIFT)
// A Channel 1 match or capture event occurred.
#define SI32_EPCA_A_STATUS_C1CCI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C1CCI_SET_U32 \
   (SI32_EPCA_A_STATUS_C1CCI_SET_VALUE << SI32_EPCA_A_STATUS_C1CCI_SHIFT)

#define SI32_EPCA_A_STATUS_C2CCI_MASK  0x00000004
#define SI32_EPCA_A_STATUS_C2CCI_SHIFT  2
// A Channel 2 match or capture event did not occur.
#define SI32_EPCA_A_STATUS_C2CCI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C2CCI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C2CCI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C2CCI_SHIFT)
// A Channel 2 match or capture event occurred.
#define SI32_EPCA_A_STATUS_C2CCI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C2CCI_SET_U32 \
   (SI32_EPCA_A_STATUS_C2CCI_SET_VALUE << SI32_EPCA_A_STATUS_C2CCI_SHIFT)

#define SI32_EPCA_A_STATUS_C3CCI_MASK  0x00000008
#define SI32_EPCA_A_STATUS_C3CCI_SHIFT  3
// A Channel 3 match or capture event did not occur.
#define SI32_EPCA_A_STATUS_C3CCI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C3CCI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C3CCI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C3CCI_SHIFT)
// A Channel 3 match or capture event occurred.
#define SI32_EPCA_A_STATUS_C3CCI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C3CCI_SET_U32 \
   (SI32_EPCA_A_STATUS_C3CCI_SET_VALUE << SI32_EPCA_A_STATUS_C3CCI_SHIFT)

#define SI32_EPCA_A_STATUS_C4CCI_MASK  0x00000010
#define SI32_EPCA_A_STATUS_C4CCI_SHIFT  4
// A Channel 4 match or capture event did not occur.
#define SI32_EPCA_A_STATUS_C4CCI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C4CCI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C4CCI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C4CCI_SHIFT)
// A Channel 4 match or capture event occurred.
#define SI32_EPCA_A_STATUS_C4CCI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C4CCI_SET_U32 \
   (SI32_EPCA_A_STATUS_C4CCI_SET_VALUE << SI32_EPCA_A_STATUS_C4CCI_SHIFT)

#define SI32_EPCA_A_STATUS_C5CCI_MASK  0x00000020
#define SI32_EPCA_A_STATUS_C5CCI_SHIFT  5
// A Channel 5 match or capture event did not occur.
#define SI32_EPCA_A_STATUS_C5CCI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C5CCI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C5CCI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C5CCI_SHIFT)
// A Channel 5 match or capture event occurred.
#define SI32_EPCA_A_STATUS_C5CCI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C5CCI_SET_U32 \
   (SI32_EPCA_A_STATUS_C5CCI_SET_VALUE << SI32_EPCA_A_STATUS_C5CCI_SHIFT)

#define SI32_EPCA_A_STATUS_RUN_MASK  0x00000040
#define SI32_EPCA_A_STATUS_RUN_SHIFT  6
// Stop the EPCA Counter/Timer.
#define SI32_EPCA_A_STATUS_RUN_STOP_VALUE  0
#define SI32_EPCA_A_STATUS_RUN_STOP_U32 \
   (SI32_EPCA_A_STATUS_RUN_STOP_VALUE << SI32_EPCA_A_STATUS_RUN_SHIFT)
// Start the EPCA Counter/Timer.
#define SI32_EPCA_A_STATUS_RUN_START_VALUE  1
#define SI32_EPCA_A_STATUS_RUN_START_U32 \
   (SI32_EPCA_A_STATUS_RUN_START_VALUE << SI32_EPCA_A_STATUS_RUN_SHIFT)

#define SI32_EPCA_A_STATUS_OVFI_MASK  0x00000080
#define SI32_EPCA_A_STATUS_OVFI_SHIFT  7
// An EPCA Counter/Timer overflow/limit event did not occur.
#define SI32_EPCA_A_STATUS_OVFI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_OVFI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_OVFI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_OVFI_SHIFT)
// An EPCA Counter/Timer overflow/limit event occurred.
#define SI32_EPCA_A_STATUS_OVFI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_OVFI_SET_U32 \
   (SI32_EPCA_A_STATUS_OVFI_SET_VALUE << SI32_EPCA_A_STATUS_OVFI_SHIFT)

#define SI32_EPCA_A_STATUS_UPDCF_MASK  0x00000100
#define SI32_EPCA_A_STATUS_UPDCF_SHIFT  8
// An EPCA register update completed or is not pending.
#define SI32_EPCA_A_STATUS_UPDCF_EMPTY_VALUE  0
#define SI32_EPCA_A_STATUS_UPDCF_EMPTY_U32 \
   (SI32_EPCA_A_STATUS_UPDCF_EMPTY_VALUE << SI32_EPCA_A_STATUS_UPDCF_SHIFT)
// An EPCA register update has not completed and is still pending.
#define SI32_EPCA_A_STATUS_UPDCF_FULL_VALUE  1
#define SI32_EPCA_A_STATUS_UPDCF_FULL_U32 \
   (SI32_EPCA_A_STATUS_UPDCF_FULL_VALUE << SI32_EPCA_A_STATUS_UPDCF_SHIFT)

#define SI32_EPCA_A_STATUS_HALTI_MASK  0x00000200
#define SI32_EPCA_A_STATUS_HALTI_SHIFT  9
// The Halt input (PB_HDKill) was not asserted.
#define SI32_EPCA_A_STATUS_HALTI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_HALTI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_HALTI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_HALTI_SHIFT)
// The Halt input (PB_HDKill) was asserted.
#define SI32_EPCA_A_STATUS_HALTI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_HALTI_SET_U32 \
   (SI32_EPCA_A_STATUS_HALTI_SET_VALUE << SI32_EPCA_A_STATUS_HALTI_SHIFT)

#define SI32_EPCA_A_STATUS_C0IOVFI_MASK  0x00000400
#define SI32_EPCA_A_STATUS_C0IOVFI_SHIFT  10
// Channel 0 did not count past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C0IOVFI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C0IOVFI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C0IOVFI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C0IOVFI_SHIFT)
// Channel 0 counted past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C0IOVFI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C0IOVFI_SET_U32 \
   (SI32_EPCA_A_STATUS_C0IOVFI_SET_VALUE << SI32_EPCA_A_STATUS_C0IOVFI_SHIFT)

#define SI32_EPCA_A_STATUS_C1IOVFI_MASK  0x00000800
#define SI32_EPCA_A_STATUS_C1IOVFI_SHIFT  11
// Channel 1 did not count past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C1IOVFI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C1IOVFI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C1IOVFI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C1IOVFI_SHIFT)
// Channel 1 counted past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C1IOVFI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C1IOVFI_SET_U32 \
   (SI32_EPCA_A_STATUS_C1IOVFI_SET_VALUE << SI32_EPCA_A_STATUS_C1IOVFI_SHIFT)

#define SI32_EPCA_A_STATUS_C2IOVFI_MASK  0x00001000
#define SI32_EPCA_A_STATUS_C2IOVFI_SHIFT  12
// Channel 2 did not count past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C2IOVFI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C2IOVFI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C2IOVFI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C2IOVFI_SHIFT)
// Channel 2 counted past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C2IOVFI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C2IOVFI_SET_U32 \
   (SI32_EPCA_A_STATUS_C2IOVFI_SET_VALUE << SI32_EPCA_A_STATUS_C2IOVFI_SHIFT)

#define SI32_EPCA_A_STATUS_C3IOVFI_MASK  0x00002000
#define SI32_EPCA_A_STATUS_C3IOVFI_SHIFT  13
// Channel 3 did not count past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C3IOVFI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C3IOVFI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C3IOVFI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C3IOVFI_SHIFT)
// Channel 3 counted past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C3IOVFI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C3IOVFI_SET_U32 \
   (SI32_EPCA_A_STATUS_C3IOVFI_SET_VALUE << SI32_EPCA_A_STATUS_C3IOVFI_SHIFT)

#define SI32_EPCA_A_STATUS_C4IOVFI_MASK  0x00004000
#define SI32_EPCA_A_STATUS_C4IOVFI_SHIFT  14
// Channel 4 did not count past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C4IOVFI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C4IOVFI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C4IOVFI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C4IOVFI_SHIFT)
// Channel 4 counted past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C4IOVFI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C4IOVFI_SET_U32 \
   (SI32_EPCA_A_STATUS_C4IOVFI_SET_VALUE << SI32_EPCA_A_STATUS_C4IOVFI_SHIFT)

#define SI32_EPCA_A_STATUS_C5IOVFI_MASK  0x00008000
#define SI32_EPCA_A_STATUS_C5IOVFI_SHIFT  15
// Channel 5 did not count past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C5IOVFI_NOT_SET_VALUE  0
#define SI32_EPCA_A_STATUS_C5IOVFI_NOT_SET_U32 \
   (SI32_EPCA_A_STATUS_C5IOVFI_NOT_SET_VALUE << SI32_EPCA_A_STATUS_C5IOVFI_SHIFT)
// Channel 5 counted past the channel n-bit mode limit.
#define SI32_EPCA_A_STATUS_C5IOVFI_SET_VALUE  1
#define SI32_EPCA_A_STATUS_C5IOVFI_SET_U32 \
   (SI32_EPCA_A_STATUS_C5IOVFI_SET_VALUE << SI32_EPCA_A_STATUS_C5IOVFI_SHIFT)



struct SI32_EPCA_A_COUNTER_Struct
{
   union
   {
      struct
      {
         // Counter/Timer
         volatile uint16_t COUNTER_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_COUNTER_COUNTER_MASK  0x0000FFFF
#define SI32_EPCA_A_COUNTER_COUNTER_SHIFT  0



struct SI32_EPCA_A_LIMIT_Struct
{
   union
   {
      struct
      {
         // Upper Limit
         volatile uint16_t LIMIT_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_LIMIT_LIMIT_MASK  0x0000FFFF
#define SI32_EPCA_A_LIMIT_LIMIT_SHIFT  0



struct SI32_EPCA_A_LIMITUPD_Struct
{
   union
   {
      struct
      {
         // Module Upper Limit Update Value
         volatile uint16_t LIMITUPD_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_LIMITUPD_LIMITUPD_MASK  0x0000FFFF
#define SI32_EPCA_A_LIMITUPD_LIMITUPD_SHIFT  0



struct SI32_EPCA_A_DTIME_Struct
{
   union
   {
      struct
      {
         // X Phase Delay Time
         volatile uint8_t DTIMEX;
         // Y Phase Delay Time
         volatile uint8_t DTIMEY;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_DTIME_DTIMEX_MASK  0x000000FF
#define SI32_EPCA_A_DTIME_DTIMEX_SHIFT  0

#define SI32_EPCA_A_DTIME_DTIMEY_MASK  0x0000FF00
#define SI32_EPCA_A_DTIME_DTIMEY_SHIFT  8



struct SI32_EPCA_A_DTARGET_Struct
{
   union
   {
      struct
      {
         // DMA Transfer Target
         volatile uint32_t DTARGET_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCA_A_DTARGET_DTARGET_MASK  0xFFFFFFFF
#define SI32_EPCA_A_DTARGET_DTARGET_SHIFT  0



typedef struct SI32_EPCA_A_Struct
{
   struct SI32_EPCA_A_MODE_Struct                  MODE           ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_EPCA_A_CONTROL_Struct               CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
   struct SI32_EPCA_A_STATUS_Struct                STATUS         ; // Base Address + 0x20
   volatile uint32_t                               STATUS_SET;
   volatile uint32_t                               STATUS_CLR;
   uint32_t                                        reserved4;
   struct SI32_EPCA_A_COUNTER_Struct               COUNTER        ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_EPCA_A_LIMIT_Struct                 LIMIT          ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   struct SI32_EPCA_A_LIMITUPD_Struct              LIMITUPD       ; // Base Address + 0x50
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   struct SI32_EPCA_A_DTIME_Struct                 DTIME          ; // Base Address + 0x60
   uint32_t                                        reserved14;
   uint32_t                                        reserved15;
   uint32_t                                        reserved16;
   uint32_t                                        reserved17[4];
   struct SI32_EPCA_A_DTARGET_Struct               DTARGET        ; // Base Address + 0x80
   uint32_t                                        reserved18;
   uint32_t                                        reserved19;
   uint32_t                                        reserved20;
} SI32_EPCA_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_EPCA_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

