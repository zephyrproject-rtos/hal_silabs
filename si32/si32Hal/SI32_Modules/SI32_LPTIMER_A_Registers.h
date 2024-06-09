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

#ifndef __SI32_LPTIMER_A_REGISTERS_H__
#define __SI32_LPTIMER_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_LPTIMER_A_CONTROL_Struct
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
         // Timer Comparator Set
         volatile uint32_t CMPSET: 1;
         // Timer Comparator Capture
         volatile uint32_t CMPCAP: 1;
                  uint32_t reserved1: 4;
         // Timer Overflow Interrupt Enable
         volatile uint32_t OVFIEN: 1;
         // Timer Compare Event Interrupt Enable
         volatile uint32_t CMPIEN: 1;
         // Timer Overflow Toggle Mode
         volatile uint32_t OVFTMD: 1;
         // Timer Compare Event Toggle Mode
         volatile uint32_t CMPTMD: 1;
                  uint32_t reserved2: 4;
         // Timer Compare Event Reset Enable
         volatile uint32_t CMPRSTEN: 1;
                  uint32_t reserved3: 5;
         // Low Power Timer Debug Mode
         volatile uint32_t DBGMD: 1;
         // Timer Run Control and Compare Threshold Enable
         volatile uint32_t RUN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LPTIMER_A_CONTROL_CMD_MASK  0x00000003
#define SI32_LPTIMER_A_CONTROL_CMD_SHIFT  0
// The timer is free running mode on the RTC0 timer clock (RTC0TCLK).
#define SI32_LPTIMER_A_CONTROL_CMD_FREE_VALUE  0
#define SI32_LPTIMER_A_CONTROL_CMD_FREE_U32 \
   (SI32_LPTIMER_A_CONTROL_CMD_FREE_VALUE << SI32_LPTIMER_A_CONTROL_CMD_SHIFT)
// The timer is incremented on the rising edges of the selected external trigger
// (LPTnTx).
#define SI32_LPTIMER_A_CONTROL_CMD_RISING_EDGE_VALUE  1
#define SI32_LPTIMER_A_CONTROL_CMD_RISING_EDGE_U32 \
   (SI32_LPTIMER_A_CONTROL_CMD_RISING_EDGE_VALUE << SI32_LPTIMER_A_CONTROL_CMD_SHIFT)
// The timer is incremented on the falling edges of the selected external trigger
// (LPTnTx).
#define SI32_LPTIMER_A_CONTROL_CMD_FALLING_EDGE_VALUE  2
#define SI32_LPTIMER_A_CONTROL_CMD_FALLING_EDGE_U32 \
   (SI32_LPTIMER_A_CONTROL_CMD_FALLING_EDGE_VALUE << SI32_LPTIMER_A_CONTROL_CMD_SHIFT)
// The timer is incremented on both edges of the selected external trigger
// (LPTnTx).
#define SI32_LPTIMER_A_CONTROL_CMD_ANY_EDGE_VALUE  3
#define SI32_LPTIMER_A_CONTROL_CMD_ANY_EDGE_U32 \
   (SI32_LPTIMER_A_CONTROL_CMD_ANY_EDGE_VALUE << SI32_LPTIMER_A_CONTROL_CMD_SHIFT)

#define SI32_LPTIMER_A_CONTROL_EXTSEL_MASK  0x000000F0
#define SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT  4
// Select external trigger LPTnT0.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT0_VALUE  0
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT0_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT0_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT1.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT1_VALUE  1
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT1_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT1_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT2.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT2_VALUE  2
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT2_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT2_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT3.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT3_VALUE  3
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT3_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT3_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT4.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT4_VALUE  4
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT4_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT4_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT5.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT5_VALUE  5
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT5_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT5_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT6.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT6_VALUE  6
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT6_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT6_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT7.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT7_VALUE  7
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT7_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT7_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT8.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT8_VALUE  8
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT8_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT8_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT9.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT9_VALUE  9
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT9_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT9_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT10.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT10_VALUE  10
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT10_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT10_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT11.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT11_VALUE  11
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT11_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT11_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT12.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT12_VALUE  12
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT12_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT12_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT13.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT13_VALUE  13
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT13_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT13_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT14.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT14_VALUE  14
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT14_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT14_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)
// Select external trigger LPTnT15.
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT15_VALUE  15
#define SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT15_U32 \
   (SI32_LPTIMER_A_CONTROL_EXTSEL_LPTNT15_VALUE << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT)

#define SI32_LPTIMER_A_CONTROL_TMRSET_MASK  0x00000100
#define SI32_LPTIMER_A_CONTROL_TMRSET_SHIFT  8
// Writing a 1 to TMRSET initiates a copy of the value from the DATA register into
// the internal timer register. This field is automatically cleared by hardware
// when the copy is complete and does not need to be cleared by software.
#define SI32_LPTIMER_A_CONTROL_TMRSET_SET_VALUE  1
#define SI32_LPTIMER_A_CONTROL_TMRSET_SET_U32 \
   (SI32_LPTIMER_A_CONTROL_TMRSET_SET_VALUE << SI32_LPTIMER_A_CONTROL_TMRSET_SHIFT)

#define SI32_LPTIMER_A_CONTROL_TMRCAP_MASK  0x00000200
#define SI32_LPTIMER_A_CONTROL_TMRCAP_SHIFT  9
// Writing a 1 to TMRCAP initiates a read of internal timer register into the DATA
// register. This field is automatically cleared by hardware when the operation
// completes and does not need to be cleared by software.
#define SI32_LPTIMER_A_CONTROL_TMRCAP_SET_VALUE  1
#define SI32_LPTIMER_A_CONTROL_TMRCAP_SET_U32 \
   (SI32_LPTIMER_A_CONTROL_TMRCAP_SET_VALUE << SI32_LPTIMER_A_CONTROL_TMRCAP_SHIFT)

#define SI32_LPTIMER_A_CONTROL_CMPSET_MASK  0x00000400
#define SI32_LPTIMER_A_CONTROL_CMPSET_SHIFT  10
// Writing a 1 to CMPSET initiates a copy of the value in DATA into the internal
// timer comparator register. This field is automatically cleared by hardware when
// the copy is complete and does not need to be cleared by software.
#define SI32_LPTIMER_A_CONTROL_CMPSET_SET_VALUE  1
#define SI32_LPTIMER_A_CONTROL_CMPSET_SET_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPSET_SET_VALUE << SI32_LPTIMER_A_CONTROL_CMPSET_SHIFT)

#define SI32_LPTIMER_A_CONTROL_CMPCAP_MASK  0x00000800
#define SI32_LPTIMER_A_CONTROL_CMPCAP_SHIFT  11
// Writing a 1 to CMPCAP initiates a read of the internal comparator register into
// the DATA register. This field is automatically cleared by hardware when the
// operation completes and does not need to be cleared by software.
#define SI32_LPTIMER_A_CONTROL_CMPCAP_SET_VALUE  1
#define SI32_LPTIMER_A_CONTROL_CMPCAP_SET_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPCAP_SET_VALUE << SI32_LPTIMER_A_CONTROL_CMPCAP_SHIFT)

#define SI32_LPTIMER_A_CONTROL_OVFIEN_MASK  0x00010000
#define SI32_LPTIMER_A_CONTROL_OVFIEN_SHIFT  16
// Disable the timer overflow interrupt.
#define SI32_LPTIMER_A_CONTROL_OVFIEN_DISABLED_VALUE  0
#define SI32_LPTIMER_A_CONTROL_OVFIEN_DISABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_OVFIEN_DISABLED_VALUE << SI32_LPTIMER_A_CONTROL_OVFIEN_SHIFT)
// Enable the timer overflow interrupt.
#define SI32_LPTIMER_A_CONTROL_OVFIEN_ENABLED_VALUE  1
#define SI32_LPTIMER_A_CONTROL_OVFIEN_ENABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_OVFIEN_ENABLED_VALUE << SI32_LPTIMER_A_CONTROL_OVFIEN_SHIFT)

#define SI32_LPTIMER_A_CONTROL_CMPIEN_MASK  0x00020000
#define SI32_LPTIMER_A_CONTROL_CMPIEN_SHIFT  17
// Disable the timer compare event interrupt.
#define SI32_LPTIMER_A_CONTROL_CMPIEN_DISABLED_VALUE  0
#define SI32_LPTIMER_A_CONTROL_CMPIEN_DISABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPIEN_DISABLED_VALUE << SI32_LPTIMER_A_CONTROL_CMPIEN_SHIFT)
// Enable the timer compare event interrupt.
#define SI32_LPTIMER_A_CONTROL_CMPIEN_ENABLED_VALUE  1
#define SI32_LPTIMER_A_CONTROL_CMPIEN_ENABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPIEN_ENABLED_VALUE << SI32_LPTIMER_A_CONTROL_CMPIEN_SHIFT)

#define SI32_LPTIMER_A_CONTROL_OVFTMD_MASK  0x00040000
#define SI32_LPTIMER_A_CONTROL_OVFTMD_SHIFT  18
// Timer overflows do not toggle the Low Power Timer output.
#define SI32_LPTIMER_A_CONTROL_OVFTMD_DISABLED_VALUE  0
#define SI32_LPTIMER_A_CONTROL_OVFTMD_DISABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_OVFTMD_DISABLED_VALUE << SI32_LPTIMER_A_CONTROL_OVFTMD_SHIFT)
// Timer overflows toggle the Low Power Timer output.
#define SI32_LPTIMER_A_CONTROL_OVFTMD_ENABLED_VALUE  1
#define SI32_LPTIMER_A_CONTROL_OVFTMD_ENABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_OVFTMD_ENABLED_VALUE << SI32_LPTIMER_A_CONTROL_OVFTMD_SHIFT)

#define SI32_LPTIMER_A_CONTROL_CMPTMD_MASK  0x00080000
#define SI32_LPTIMER_A_CONTROL_CMPTMD_SHIFT  19
// Timer compare events do not toggle the Low Power Timer output.
#define SI32_LPTIMER_A_CONTROL_CMPTMD_DISABLED_VALUE  0
#define SI32_LPTIMER_A_CONTROL_CMPTMD_DISABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPTMD_DISABLED_VALUE << SI32_LPTIMER_A_CONTROL_CMPTMD_SHIFT)
// Timer compare events toggle the Low Power Timer output.
#define SI32_LPTIMER_A_CONTROL_CMPTMD_ENABLED_VALUE  1
#define SI32_LPTIMER_A_CONTROL_CMPTMD_ENABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPTMD_ENABLED_VALUE << SI32_LPTIMER_A_CONTROL_CMPTMD_SHIFT)

#define SI32_LPTIMER_A_CONTROL_CMPRSTEN_MASK  0x01000000
#define SI32_LPTIMER_A_CONTROL_CMPRSTEN_SHIFT  24
// Timer compare events do not reset the timer.
#define SI32_LPTIMER_A_CONTROL_CMPRSTEN_DISABLED_VALUE  0
#define SI32_LPTIMER_A_CONTROL_CMPRSTEN_DISABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPRSTEN_DISABLED_VALUE << SI32_LPTIMER_A_CONTROL_CMPRSTEN_SHIFT)
// Timer compare events reset the timer.
#define SI32_LPTIMER_A_CONTROL_CMPRSTEN_ENABLED_VALUE  1
#define SI32_LPTIMER_A_CONTROL_CMPRSTEN_ENABLED_U32 \
   (SI32_LPTIMER_A_CONTROL_CMPRSTEN_ENABLED_VALUE << SI32_LPTIMER_A_CONTROL_CMPRSTEN_SHIFT)

#define SI32_LPTIMER_A_CONTROL_DBGMD_MASK  0x40000000
#define SI32_LPTIMER_A_CONTROL_DBGMD_SHIFT  30
// The Low Power Timer module will continue to operate while the core is halted in
// debug mode.
#define SI32_LPTIMER_A_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_LPTIMER_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_LPTIMER_A_CONTROL_DBGMD_RUN_VALUE << SI32_LPTIMER_A_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the Low Power Timer module to halt.
#define SI32_LPTIMER_A_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_LPTIMER_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_LPTIMER_A_CONTROL_DBGMD_HALT_VALUE << SI32_LPTIMER_A_CONTROL_DBGMD_SHIFT)

#define SI32_LPTIMER_A_CONTROL_RUN_MASK  0x80000000
#define SI32_LPTIMER_A_CONTROL_RUN_SHIFT  31
// Stop the timer and disable the compare threshold.
#define SI32_LPTIMER_A_CONTROL_RUN_STOP_VALUE  0U
#define SI32_LPTIMER_A_CONTROL_RUN_STOP_U32 \
   (SI32_LPTIMER_A_CONTROL_RUN_STOP_VALUE << SI32_LPTIMER_A_CONTROL_RUN_SHIFT)
// Start the timer running and enable the compare threshold.
#define SI32_LPTIMER_A_CONTROL_RUN_START_VALUE  1U
#define SI32_LPTIMER_A_CONTROL_RUN_START_U32 \
   (SI32_LPTIMER_A_CONTROL_RUN_START_VALUE << SI32_LPTIMER_A_CONTROL_RUN_SHIFT)



struct SI32_LPTIMER_A_DATA_Struct
{
   union
   {
      struct
      {
         // Timer and Comparator Data
         volatile uint16_t DATA_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LPTIMER_A_DATA_DATA_MASK  0x0000FFFF
#define SI32_LPTIMER_A_DATA_DATA_SHIFT  0



struct SI32_LPTIMER_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Timer Overflow Interrupt Flag
         volatile uint32_t OVFI: 1;
         // Timer Compare Event Interrupt Flag
         volatile uint32_t CMPI: 1;
                  uint32_t reserved0: 30;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LPTIMER_A_STATUS_OVFI_MASK  0x00000001
#define SI32_LPTIMER_A_STATUS_OVFI_SHIFT  0
// A timer overflow has not occurred.
#define SI32_LPTIMER_A_STATUS_OVFI_NOT_SET_VALUE  0
#define SI32_LPTIMER_A_STATUS_OVFI_NOT_SET_U32 \
   (SI32_LPTIMER_A_STATUS_OVFI_NOT_SET_VALUE << SI32_LPTIMER_A_STATUS_OVFI_SHIFT)
// A timer overflow occurred.
#define SI32_LPTIMER_A_STATUS_OVFI_SET_VALUE  1
#define SI32_LPTIMER_A_STATUS_OVFI_SET_U32 \
   (SI32_LPTIMER_A_STATUS_OVFI_SET_VALUE << SI32_LPTIMER_A_STATUS_OVFI_SHIFT)

#define SI32_LPTIMER_A_STATUS_CMPI_MASK  0x00000002
#define SI32_LPTIMER_A_STATUS_CMPI_SHIFT  1
// A timer compare event has not occurred.
#define SI32_LPTIMER_A_STATUS_CMPI_NOT_SET_VALUE  0
#define SI32_LPTIMER_A_STATUS_CMPI_NOT_SET_U32 \
   (SI32_LPTIMER_A_STATUS_CMPI_NOT_SET_VALUE << SI32_LPTIMER_A_STATUS_CMPI_SHIFT)
// A timer compare event occurred.
#define SI32_LPTIMER_A_STATUS_CMPI_SET_VALUE  1
#define SI32_LPTIMER_A_STATUS_CMPI_SET_U32 \
   (SI32_LPTIMER_A_STATUS_CMPI_SET_VALUE << SI32_LPTIMER_A_STATUS_CMPI_SHIFT)



typedef struct SI32_LPTIMER_A_Struct
{
   struct SI32_LPTIMER_A_CONTROL_Struct            CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_LPTIMER_A_DATA_Struct               DATA           ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_LPTIMER_A_STATUS_Struct             STATUS         ; // Base Address + 0x20
   volatile uint32_t                               STATUS_SET;
   volatile uint32_t                               STATUS_CLR;
   uint32_t                                        reserved4;
} SI32_LPTIMER_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_LPTIMER_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

