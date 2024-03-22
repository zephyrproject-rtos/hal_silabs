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

#ifndef __SI32_PCA_A_REGISTERS_H__
#define __SI32_PCA_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_PCA_A_MODE_Struct
{
   union
   {
      struct
      {
         // Input Clock Divisor
         volatile uint32_t CLKDIV: 10;
         // Input Clock (F<subscript>CLKIN</subscript>) Select
         volatile uint32_t CLKSEL: 3;
                  uint32_t reserved0: 19;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PCA_A_MODE_CLKDIV_MASK  0x000003FF
#define SI32_PCA_A_MODE_CLKDIV_SHIFT  0

#define SI32_PCA_A_MODE_CLKSEL_MASK  0x00001C00
#define SI32_PCA_A_MODE_CLKSEL_SHIFT  10
// Set the APB as the input clock (FCLKIN).
#define SI32_PCA_A_MODE_CLKSEL_APB_VALUE  0
#define SI32_PCA_A_MODE_CLKSEL_APB_U32 \
   (SI32_PCA_A_MODE_CLKSEL_APB_VALUE << SI32_PCA_A_MODE_CLKSEL_SHIFT)
// Set Timer 0 low overflows divided by 2 as the input clock (FCLKIN).
#define SI32_PCA_A_MODE_CLKSEL_TIMER0_VALUE  1
#define SI32_PCA_A_MODE_CLKSEL_TIMER0_U32 \
   (SI32_PCA_A_MODE_CLKSEL_TIMER0_VALUE << SI32_PCA_A_MODE_CLKSEL_SHIFT)
// Set high-to-low transitions on ECI divided by 2 as the input clock (FCLKIN).
#define SI32_PCA_A_MODE_CLKSEL_HL_ECI_VALUE  2
#define SI32_PCA_A_MODE_CLKSEL_HL_ECI_U32 \
   (SI32_PCA_A_MODE_CLKSEL_HL_ECI_VALUE << SI32_PCA_A_MODE_CLKSEL_SHIFT)
// Set the external oscillator module output (EXTOSCn) divided by 2 as the input
// clock (FCLKIN).
#define SI32_PCA_A_MODE_CLKSEL_EXTOSCN_VALUE  3
#define SI32_PCA_A_MODE_CLKSEL_EXTOSCN_U32 \
   (SI32_PCA_A_MODE_CLKSEL_EXTOSCN_VALUE << SI32_PCA_A_MODE_CLKSEL_SHIFT)
// Set ECI transitions divided by 2 as the input clock (FCLKIN).
#define SI32_PCA_A_MODE_CLKSEL_ECI_VALUE  4
#define SI32_PCA_A_MODE_CLKSEL_ECI_U32 \
   (SI32_PCA_A_MODE_CLKSEL_ECI_VALUE << SI32_PCA_A_MODE_CLKSEL_SHIFT)



struct SI32_PCA_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // PCA Counter Overflow/Limit Interrupt Enable
         volatile uint32_t OVFIEN: 1;
                  uint32_t reserved0: 5;
         // PCA Debug Mode
         volatile uint32_t DBGMD: 1;
                  uint32_t reserved1: 14;
         // Clock Divider Output State
         volatile uint32_t DIVST: 1;
         // Current Clock Divider Count
         volatile uint32_t DIV: 10;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PCA_A_CONTROL_OVFIEN_MASK  0x00000001
#define SI32_PCA_A_CONTROL_OVFIEN_SHIFT  0
// Disable the PCA counter overflow/limit event interrupt.
#define SI32_PCA_A_CONTROL_OVFIEN_DISABLED_VALUE  0
#define SI32_PCA_A_CONTROL_OVFIEN_DISABLED_U32 \
   (SI32_PCA_A_CONTROL_OVFIEN_DISABLED_VALUE << SI32_PCA_A_CONTROL_OVFIEN_SHIFT)
// Enable the PCA counter overflow/limit event interrupt.
#define SI32_PCA_A_CONTROL_OVFIEN_ENABLED_VALUE  1
#define SI32_PCA_A_CONTROL_OVFIEN_ENABLED_U32 \
   (SI32_PCA_A_CONTROL_OVFIEN_ENABLED_VALUE << SI32_PCA_A_CONTROL_OVFIEN_SHIFT)

#define SI32_PCA_A_CONTROL_DBGMD_MASK  0x00000040
#define SI32_PCA_A_CONTROL_DBGMD_SHIFT  6
// A debug breakpoint will cause the PCA to halt.
#define SI32_PCA_A_CONTROL_DBGMD_HALT_VALUE  0
#define SI32_PCA_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_PCA_A_CONTROL_DBGMD_HALT_VALUE << SI32_PCA_A_CONTROL_DBGMD_SHIFT)
// The PCA will continue to operate while the core is halted in debug mode.
#define SI32_PCA_A_CONTROL_DBGMD_RUN_VALUE  1
#define SI32_PCA_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_PCA_A_CONTROL_DBGMD_RUN_VALUE << SI32_PCA_A_CONTROL_DBGMD_SHIFT)

#define SI32_PCA_A_CONTROL_DIVST_MASK  0x00200000
#define SI32_PCA_A_CONTROL_DIVST_SHIFT  21
// The clock divider is currently in the first half-cycle.
#define SI32_PCA_A_CONTROL_DIVST_OUTPUT_HIGH_VALUE  0
#define SI32_PCA_A_CONTROL_DIVST_OUTPUT_HIGH_U32 \
   (SI32_PCA_A_CONTROL_DIVST_OUTPUT_HIGH_VALUE << SI32_PCA_A_CONTROL_DIVST_SHIFT)
// The clock divider is currently in the second half-cycle.
#define SI32_PCA_A_CONTROL_DIVST_OUTPUT_LOW_VALUE  1
#define SI32_PCA_A_CONTROL_DIVST_OUTPUT_LOW_U32 \
   (SI32_PCA_A_CONTROL_DIVST_OUTPUT_LOW_VALUE << SI32_PCA_A_CONTROL_DIVST_SHIFT)

#define SI32_PCA_A_CONTROL_DIV_MASK  0xFFC00000
#define SI32_PCA_A_CONTROL_DIV_SHIFT  22



struct SI32_PCA_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Channel 0 Capture/Compare Interrupt Flag
         volatile uint32_t C0CCI: 1;
         // Channel 1 Capture/Compare Interrupt Flag
         volatile uint32_t C1CCI: 1;
                  uint32_t reserved0: 4;
         // Counter/Timer Run
         volatile uint32_t RUN: 1;
         // Counter/Timer Overflow/Limit Interrupt Flag
         volatile uint32_t OVFI: 1;
                  uint32_t reserved1: 2;
         // Channel 0 Intermediate Overflow Interrupt Flag
         volatile uint32_t C0IOVFI: 1;
         // Channel 1 Intermediate Overflow Interrupt Flag
         volatile uint32_t C1IOVFI: 1;
                  uint32_t reserved2: 20;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PCA_A_STATUS_C0CCI_MASK  0x00000001
#define SI32_PCA_A_STATUS_C0CCI_SHIFT  0
// A Channel 0 match or capture event did not occur.
#define SI32_PCA_A_STATUS_C0CCI_NOT_SET_VALUE  0
#define SI32_PCA_A_STATUS_C0CCI_NOT_SET_U32 \
   (SI32_PCA_A_STATUS_C0CCI_NOT_SET_VALUE << SI32_PCA_A_STATUS_C0CCI_SHIFT)
// A Channel 0 match or capture event occurred.
#define SI32_PCA_A_STATUS_C0CCI_SET_VALUE  1
#define SI32_PCA_A_STATUS_C0CCI_SET_U32 \
   (SI32_PCA_A_STATUS_C0CCI_SET_VALUE << SI32_PCA_A_STATUS_C0CCI_SHIFT)

#define SI32_PCA_A_STATUS_C1CCI_MASK  0x00000002
#define SI32_PCA_A_STATUS_C1CCI_SHIFT  1
// A Channel 1 match or capture event did not occur.
#define SI32_PCA_A_STATUS_C1CCI_NOT_SET_VALUE  0
#define SI32_PCA_A_STATUS_C1CCI_NOT_SET_U32 \
   (SI32_PCA_A_STATUS_C1CCI_NOT_SET_VALUE << SI32_PCA_A_STATUS_C1CCI_SHIFT)
// A Channel 1 match or capture event occurred.
#define SI32_PCA_A_STATUS_C1CCI_SET_VALUE  1
#define SI32_PCA_A_STATUS_C1CCI_SET_U32 \
   (SI32_PCA_A_STATUS_C1CCI_SET_VALUE << SI32_PCA_A_STATUS_C1CCI_SHIFT)

#define SI32_PCA_A_STATUS_RUN_MASK  0x00000040
#define SI32_PCA_A_STATUS_RUN_SHIFT  6
// Stop the PCA Counter/Timer.
#define SI32_PCA_A_STATUS_RUN_STOP_VALUE  0
#define SI32_PCA_A_STATUS_RUN_STOP_U32 \
   (SI32_PCA_A_STATUS_RUN_STOP_VALUE << SI32_PCA_A_STATUS_RUN_SHIFT)
// Start the PCA Counter/Timer.
#define SI32_PCA_A_STATUS_RUN_START_VALUE  1
#define SI32_PCA_A_STATUS_RUN_START_U32 \
   (SI32_PCA_A_STATUS_RUN_START_VALUE << SI32_PCA_A_STATUS_RUN_SHIFT)

#define SI32_PCA_A_STATUS_OVFI_MASK  0x00000080
#define SI32_PCA_A_STATUS_OVFI_SHIFT  7
// A PCA Counter/Timer overflow/limit event did not occur.
#define SI32_PCA_A_STATUS_OVFI_NOT_SET_VALUE  0
#define SI32_PCA_A_STATUS_OVFI_NOT_SET_U32 \
   (SI32_PCA_A_STATUS_OVFI_NOT_SET_VALUE << SI32_PCA_A_STATUS_OVFI_SHIFT)
// A PCA Counter/Timer overflow/limit event occurred.
#define SI32_PCA_A_STATUS_OVFI_SET_VALUE  1
#define SI32_PCA_A_STATUS_OVFI_SET_U32 \
   (SI32_PCA_A_STATUS_OVFI_SET_VALUE << SI32_PCA_A_STATUS_OVFI_SHIFT)

#define SI32_PCA_A_STATUS_C0IOVFI_MASK  0x00000400
#define SI32_PCA_A_STATUS_C0IOVFI_SHIFT  10
// Channel 0 did not count past the channel n-bit mode limit.
#define SI32_PCA_A_STATUS_C0IOVFI_NOT_SET_VALUE  0
#define SI32_PCA_A_STATUS_C0IOVFI_NOT_SET_U32 \
   (SI32_PCA_A_STATUS_C0IOVFI_NOT_SET_VALUE << SI32_PCA_A_STATUS_C0IOVFI_SHIFT)
// Channel 0 counted past the channel n-bit mode limit.
#define SI32_PCA_A_STATUS_C0IOVFI_SET_VALUE  1
#define SI32_PCA_A_STATUS_C0IOVFI_SET_U32 \
   (SI32_PCA_A_STATUS_C0IOVFI_SET_VALUE << SI32_PCA_A_STATUS_C0IOVFI_SHIFT)

#define SI32_PCA_A_STATUS_C1IOVFI_MASK  0x00000800
#define SI32_PCA_A_STATUS_C1IOVFI_SHIFT  11
// Channel 1 did not count past the channel n-bit mode limit.
#define SI32_PCA_A_STATUS_C1IOVFI_NOT_SET_VALUE  0
#define SI32_PCA_A_STATUS_C1IOVFI_NOT_SET_U32 \
   (SI32_PCA_A_STATUS_C1IOVFI_NOT_SET_VALUE << SI32_PCA_A_STATUS_C1IOVFI_SHIFT)
// Channel 1 counted past the channel n-bit mode limit.
#define SI32_PCA_A_STATUS_C1IOVFI_SET_VALUE  1
#define SI32_PCA_A_STATUS_C1IOVFI_SET_U32 \
   (SI32_PCA_A_STATUS_C1IOVFI_SET_VALUE << SI32_PCA_A_STATUS_C1IOVFI_SHIFT)



struct SI32_PCA_A_COUNTER_Struct
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

#define SI32_PCA_A_COUNTER_COUNTER_MASK  0x0000FFFF
#define SI32_PCA_A_COUNTER_COUNTER_SHIFT  0



struct SI32_PCA_A_LIMIT_Struct
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

#define SI32_PCA_A_LIMIT_LIMIT_MASK  0x0000FFFF
#define SI32_PCA_A_LIMIT_LIMIT_SHIFT  0



typedef struct SI32_PCA_A_Struct
{
   struct SI32_PCA_A_MODE_Struct                   MODE           ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_PCA_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
   struct SI32_PCA_A_STATUS_Struct                 STATUS         ; // Base Address + 0x20
   volatile uint32_t                               STATUS_SET;
   volatile uint32_t                               STATUS_CLR;
   uint32_t                                        reserved4;
   struct SI32_PCA_A_COUNTER_Struct                COUNTER        ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_PCA_A_LIMIT_Struct                  LIMIT          ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
} SI32_PCA_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PCA_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

