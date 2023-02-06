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

#ifndef __SI32_IDAC_A_REGISTERS_H__
#define __SI32_IDAC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_IDAC_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Output Update Trigger
         volatile uint32_t OUPDT: 3;
         // Edge Trigger Source Select
         volatile uint32_t ETRIG: 3;
         // Output Mode
         volatile uint32_t OUTMD: 2;
         // Data Input Format
         volatile uint32_t INFMT: 2;
         // DMA Run
         volatile uint32_t DMARUN: 1;
         // Data Justification Select
         volatile uint32_t JSEL: 1;
         // Data Buffer Reset
         volatile uint32_t BUFRESET: 1;
         // Trigger Source Inhibit
         volatile uint32_t TRIGINH: 1;
                  uint32_t reserved0: 2;
         // Wrap Mode Enable
         volatile uint32_t WRAPEN: 1;
                  uint32_t reserved1: 3;
         // FIFO Overrun Interrupt Enable
         volatile uint32_t ORIEN: 1;
         // FIFO Underrun Interrupt Enable
         volatile uint32_t URIEN: 1;
         // FIFO Went Empty Interrupt Enable
         volatile uint32_t WEIEN: 1;
                  uint32_t reserved2: 6;
         // IDAC Debug Mode
         volatile uint32_t DBGMD: 1;
         // Load Resistor Enable
         volatile uint32_t LOADEN: 1;
         // IDAC Enable
         volatile uint32_t IDACEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_IDAC_A_CONTROL_OUPDT_MASK  0x00000007
#define SI32_IDAC_A_CONTROL_OUPDT_SHIFT  0
// The IDAC output updates using the DACnT8 trigger source.
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT8_VALUE  0
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT8_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT8_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)
// The IDAC output updates using the DACnT9 trigger source.
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT9_VALUE  1
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT9_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT9_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)
// The IDAC output updates using the DACnT10 trigger source.
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT10_VALUE  2
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT10_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT10_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)
// The IDAC output updates using the DACnT11 trigger source.
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT11_VALUE  3
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT11_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT11_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)
// The IDAC output updates on the rising edge of the trigger source selected by
// ETRIG.
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT12_VALUE  4
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT12_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT12_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)
// The IDAC output updates on the falling edge of the trigger source selected by
// ETRIG.
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT13_VALUE  5
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT13_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT13_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)
// The IDAC output updates on any edge of the trigger source selected by ETRIG.
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT14_VALUE  6
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT14_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT14_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)
// The IDAC output updates on write to DATA register (On Demand).
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT15_VALUE  7
#define SI32_IDAC_A_CONTROL_OUPDT_DACNT15_U32 \
   (SI32_IDAC_A_CONTROL_OUPDT_DACNT15_VALUE << SI32_IDAC_A_CONTROL_OUPDT_SHIFT)

#define SI32_IDAC_A_CONTROL_ETRIG_MASK  0x00000038
#define SI32_IDAC_A_CONTROL_ETRIG_SHIFT  3
// Select DACnT0 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT0_VALUE  0
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT0_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT0_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)
// Select DACnT1 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT1_VALUE  1
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT1_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT1_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)
// Select DACnT2 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT2_VALUE  2
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT2_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT2_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)
// Select DACnT3 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT3_VALUE  3
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT3_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT3_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)
// Select DACnT4 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT4_VALUE  4
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT4_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT4_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)
// Select DACnT5 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT5_VALUE  5
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT5_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT5_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)
// Select DACnT6 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT6_VALUE  6
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT6_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT6_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)
// Select DACnT7 as the IDAC external trigger source.
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT7_VALUE  7
#define SI32_IDAC_A_CONTROL_ETRIG_DACNT7_U32 \
   (SI32_IDAC_A_CONTROL_ETRIG_DACNT7_VALUE << SI32_IDAC_A_CONTROL_ETRIG_SHIFT)

#define SI32_IDAC_A_CONTROL_OUTMD_MASK  0x000000C0
#define SI32_IDAC_A_CONTROL_OUTMD_SHIFT  6
// The full-scale output current is 0.5 mA.
#define SI32_IDAC_A_CONTROL_OUTMD_0P5_MA_VALUE  0
#define SI32_IDAC_A_CONTROL_OUTMD_0P5_MA_U32 \
   (SI32_IDAC_A_CONTROL_OUTMD_0P5_MA_VALUE << SI32_IDAC_A_CONTROL_OUTMD_SHIFT)
// The full-scale output current is 1 mA.
#define SI32_IDAC_A_CONTROL_OUTMD_1_MA_VALUE  1
#define SI32_IDAC_A_CONTROL_OUTMD_1_MA_U32 \
   (SI32_IDAC_A_CONTROL_OUTMD_1_MA_VALUE << SI32_IDAC_A_CONTROL_OUTMD_SHIFT)
// The full-scale output current is 2 mA.
#define SI32_IDAC_A_CONTROL_OUTMD_2_MA_VALUE  2
#define SI32_IDAC_A_CONTROL_OUTMD_2_MA_U32 \
   (SI32_IDAC_A_CONTROL_OUTMD_2_MA_VALUE << SI32_IDAC_A_CONTROL_OUTMD_SHIFT)

#define SI32_IDAC_A_CONTROL_INFMT_MASK  0x00000300
#define SI32_IDAC_A_CONTROL_INFMT_SHIFT  8
// Writes are interpreted as one 10-bit sample.
#define SI32_IDAC_A_CONTROL_INFMT_1_10_BIT_VALUE  0
#define SI32_IDAC_A_CONTROL_INFMT_1_10_BIT_U32 \
   (SI32_IDAC_A_CONTROL_INFMT_1_10_BIT_VALUE << SI32_IDAC_A_CONTROL_INFMT_SHIFT)
// Writes are interpreted as two 10-bit samples.
#define SI32_IDAC_A_CONTROL_INFMT_2_10_BIT_VALUE  1
#define SI32_IDAC_A_CONTROL_INFMT_2_10_BIT_U32 \
   (SI32_IDAC_A_CONTROL_INFMT_2_10_BIT_VALUE << SI32_IDAC_A_CONTROL_INFMT_SHIFT)
// Writes are interpreted as four 8-bit samples.
#define SI32_IDAC_A_CONTROL_INFMT_4_8_BIT_VALUE  2
#define SI32_IDAC_A_CONTROL_INFMT_4_8_BIT_U32 \
   (SI32_IDAC_A_CONTROL_INFMT_4_8_BIT_VALUE << SI32_IDAC_A_CONTROL_INFMT_SHIFT)

#define SI32_IDAC_A_CONTROL_DMARUN_MASK  0x00000400
#define SI32_IDAC_A_CONTROL_DMARUN_SHIFT  10
// Read: No DMA operations are occurring or the DMA is done. Write: No effect.
#define SI32_IDAC_A_CONTROL_DMARUN_DISABLED_VALUE  0
#define SI32_IDAC_A_CONTROL_DMARUN_DISABLED_U32 \
   (SI32_IDAC_A_CONTROL_DMARUN_DISABLED_VALUE << SI32_IDAC_A_CONTROL_DMARUN_SHIFT)
// Read: A DMA operation is currently in progress. Write: Start a DMA operation.
#define SI32_IDAC_A_CONTROL_DMARUN_ENABLED_VALUE  1
#define SI32_IDAC_A_CONTROL_DMARUN_ENABLED_U32 \
   (SI32_IDAC_A_CONTROL_DMARUN_ENABLED_VALUE << SI32_IDAC_A_CONTROL_DMARUN_SHIFT)

#define SI32_IDAC_A_CONTROL_JSEL_MASK  0x00000800
#define SI32_IDAC_A_CONTROL_JSEL_SHIFT  11
// Data is right-justified.
#define SI32_IDAC_A_CONTROL_JSEL_RIGHT_VALUE  0
#define SI32_IDAC_A_CONTROL_JSEL_RIGHT_U32 \
   (SI32_IDAC_A_CONTROL_JSEL_RIGHT_VALUE << SI32_IDAC_A_CONTROL_JSEL_SHIFT)
// Data is left-justified.
#define SI32_IDAC_A_CONTROL_JSEL_LEFT_VALUE  1
#define SI32_IDAC_A_CONTROL_JSEL_LEFT_U32 \
   (SI32_IDAC_A_CONTROL_JSEL_LEFT_VALUE << SI32_IDAC_A_CONTROL_JSEL_SHIFT)

#define SI32_IDAC_A_CONTROL_BUFRESET_MASK  0x00001000
#define SI32_IDAC_A_CONTROL_BUFRESET_SHIFT  12
// Initiate a data buffer reset.
#define SI32_IDAC_A_CONTROL_BUFRESET_RESET_VALUE  1
#define SI32_IDAC_A_CONTROL_BUFRESET_RESET_U32 \
   (SI32_IDAC_A_CONTROL_BUFRESET_RESET_VALUE << SI32_IDAC_A_CONTROL_BUFRESET_SHIFT)

#define SI32_IDAC_A_CONTROL_TRIGINH_MASK  0x00002000
#define SI32_IDAC_A_CONTROL_TRIGINH_SHIFT  13
// The selected trigger source will cause the IDAC output to update.
#define SI32_IDAC_A_CONTROL_TRIGINH_INACTIVE_VALUE  0
#define SI32_IDAC_A_CONTROL_TRIGINH_INACTIVE_U32 \
   (SI32_IDAC_A_CONTROL_TRIGINH_INACTIVE_VALUE << SI32_IDAC_A_CONTROL_TRIGINH_SHIFT)
// The selected trigger source will not update the IDAC output, except for On-
// Demand DATA writes.
#define SI32_IDAC_A_CONTROL_TRIGINH_ACTIVE_VALUE  1
#define SI32_IDAC_A_CONTROL_TRIGINH_ACTIVE_U32 \
   (SI32_IDAC_A_CONTROL_TRIGINH_ACTIVE_VALUE << SI32_IDAC_A_CONTROL_TRIGINH_SHIFT)

#define SI32_IDAC_A_CONTROL_WRAPEN_MASK  0x00010000
#define SI32_IDAC_A_CONTROL_WRAPEN_SHIFT  16
// The IDAC will not wrap when it reaches the end of the data buffer.
#define SI32_IDAC_A_CONTROL_WRAPEN_DISABLED_VALUE  0
#define SI32_IDAC_A_CONTROL_WRAPEN_DISABLED_U32 \
   (SI32_IDAC_A_CONTROL_WRAPEN_DISABLED_VALUE << SI32_IDAC_A_CONTROL_WRAPEN_SHIFT)
// The IDAC will cycle through the data buffer contents.
#define SI32_IDAC_A_CONTROL_WRAPEN_ENABLED_VALUE  1
#define SI32_IDAC_A_CONTROL_WRAPEN_ENABLED_U32 \
   (SI32_IDAC_A_CONTROL_WRAPEN_ENABLED_VALUE << SI32_IDAC_A_CONTROL_WRAPEN_SHIFT)

#define SI32_IDAC_A_CONTROL_ORIEN_MASK  0x00100000
#define SI32_IDAC_A_CONTROL_ORIEN_SHIFT  20
// Disable the FIFO overrun interrupt (ORI).
#define SI32_IDAC_A_CONTROL_ORIEN_DISABLED_VALUE  0
#define SI32_IDAC_A_CONTROL_ORIEN_DISABLED_U32 \
   (SI32_IDAC_A_CONTROL_ORIEN_DISABLED_VALUE << SI32_IDAC_A_CONTROL_ORIEN_SHIFT)
// Enable the FIFO overrun interrupt (ORI).
#define SI32_IDAC_A_CONTROL_ORIEN_ENABLED_VALUE  1
#define SI32_IDAC_A_CONTROL_ORIEN_ENABLED_U32 \
   (SI32_IDAC_A_CONTROL_ORIEN_ENABLED_VALUE << SI32_IDAC_A_CONTROL_ORIEN_SHIFT)

#define SI32_IDAC_A_CONTROL_URIEN_MASK  0x00200000
#define SI32_IDAC_A_CONTROL_URIEN_SHIFT  21
// Disable the FIFO underrun interrupt (URI).
#define SI32_IDAC_A_CONTROL_URIEN_DISABLED_VALUE  0
#define SI32_IDAC_A_CONTROL_URIEN_DISABLED_U32 \
   (SI32_IDAC_A_CONTROL_URIEN_DISABLED_VALUE << SI32_IDAC_A_CONTROL_URIEN_SHIFT)
// Enable the FIFO underrun interrupt (URI).
#define SI32_IDAC_A_CONTROL_URIEN_ENABLED_VALUE  1
#define SI32_IDAC_A_CONTROL_URIEN_ENABLED_U32 \
   (SI32_IDAC_A_CONTROL_URIEN_ENABLED_VALUE << SI32_IDAC_A_CONTROL_URIEN_SHIFT)

#define SI32_IDAC_A_CONTROL_WEIEN_MASK  0x00400000
#define SI32_IDAC_A_CONTROL_WEIEN_SHIFT  22
// Disable the FIFO went empty interrupt (WEI).
#define SI32_IDAC_A_CONTROL_WEIEN_DISABLED_VALUE  0
#define SI32_IDAC_A_CONTROL_WEIEN_DISABLED_U32 \
   (SI32_IDAC_A_CONTROL_WEIEN_DISABLED_VALUE << SI32_IDAC_A_CONTROL_WEIEN_SHIFT)
// Enable the FIFO went empty interrupt (WEI).
#define SI32_IDAC_A_CONTROL_WEIEN_ENABLED_VALUE  1
#define SI32_IDAC_A_CONTROL_WEIEN_ENABLED_U32 \
   (SI32_IDAC_A_CONTROL_WEIEN_ENABLED_VALUE << SI32_IDAC_A_CONTROL_WEIEN_SHIFT)

#define SI32_IDAC_A_CONTROL_DBGMD_MASK  0x20000000
#define SI32_IDAC_A_CONTROL_DBGMD_SHIFT  29
// The IDAC module will continue to operate while the core is halted in debug mode.
#define SI32_IDAC_A_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_IDAC_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_IDAC_A_CONTROL_DBGMD_RUN_VALUE << SI32_IDAC_A_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the IDAC module to halt (ignore update triggers).
#define SI32_IDAC_A_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_IDAC_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_IDAC_A_CONTROL_DBGMD_HALT_VALUE << SI32_IDAC_A_CONTROL_DBGMD_SHIFT)

#define SI32_IDAC_A_CONTROL_LOADEN_MASK  0x40000000
#define SI32_IDAC_A_CONTROL_LOADEN_SHIFT  30
// Disable the internal load resistor.
#define SI32_IDAC_A_CONTROL_LOADEN_DISABLED_VALUE  0
#define SI32_IDAC_A_CONTROL_LOADEN_DISABLED_U32 \
   (SI32_IDAC_A_CONTROL_LOADEN_DISABLED_VALUE << SI32_IDAC_A_CONTROL_LOADEN_SHIFT)
// Enable the internal load resistor.
#define SI32_IDAC_A_CONTROL_LOADEN_ENABLED_VALUE  1
#define SI32_IDAC_A_CONTROL_LOADEN_ENABLED_U32 \
   (SI32_IDAC_A_CONTROL_LOADEN_ENABLED_VALUE << SI32_IDAC_A_CONTROL_LOADEN_SHIFT)

#define SI32_IDAC_A_CONTROL_IDACEN_MASK  0x80000000
#define SI32_IDAC_A_CONTROL_IDACEN_SHIFT  31
// Disable the IDAC.
#define SI32_IDAC_A_CONTROL_IDACEN_DISABLED_VALUE  0U
#define SI32_IDAC_A_CONTROL_IDACEN_DISABLED_U32 \
   (SI32_IDAC_A_CONTROL_IDACEN_DISABLED_VALUE << SI32_IDAC_A_CONTROL_IDACEN_SHIFT)
// Enable the IDAC.
#define SI32_IDAC_A_CONTROL_IDACEN_ENABLED_VALUE  1U
#define SI32_IDAC_A_CONTROL_IDACEN_ENABLED_U32 \
   (SI32_IDAC_A_CONTROL_IDACEN_ENABLED_VALUE << SI32_IDAC_A_CONTROL_IDACEN_SHIFT)



struct SI32_IDAC_A_DATA_Struct
{
   union
   {
      struct
      {
         // Output Data
         volatile uint32_t DATA_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_IDAC_A_DATA_DATA_MASK  0xFFFFFFFF
#define SI32_IDAC_A_DATA_DATA_SHIFT  0



struct SI32_IDAC_A_BUFSTATUS_Struct
{
   union
   {
      struct
      {
         // FIFO Level
         volatile uint32_t LEVEL: 3;
                  uint32_t reserved0: 1;
         // FIFO Overrun Interrupt Flag
         volatile uint32_t ORI: 1;
         // FIFO Underrun Interrupt Flag
         volatile uint32_t URI: 1;
         // FIFO Went Empty Interrupt Flag
         volatile uint32_t WEI: 1;
                  uint32_t reserved1: 25;
      };
      volatile uint32_t U32;
   };
};

#define SI32_IDAC_A_BUFSTATUS_LEVEL_MASK  0x00000007
#define SI32_IDAC_A_BUFSTATUS_LEVEL_SHIFT  0
// The data FIFO is empty.
#define SI32_IDAC_A_BUFSTATUS_LEVEL_EMPTY_VALUE  0
#define SI32_IDAC_A_BUFSTATUS_LEVEL_EMPTY_U32 \
   (SI32_IDAC_A_BUFSTATUS_LEVEL_EMPTY_VALUE << SI32_IDAC_A_BUFSTATUS_LEVEL_SHIFT)
// The data FIFO contains one word.
#define SI32_IDAC_A_BUFSTATUS_LEVEL_1WORD_VALUE  1
#define SI32_IDAC_A_BUFSTATUS_LEVEL_1WORD_U32 \
   (SI32_IDAC_A_BUFSTATUS_LEVEL_1WORD_VALUE << SI32_IDAC_A_BUFSTATUS_LEVEL_SHIFT)
// The data FIFO contains two words.
#define SI32_IDAC_A_BUFSTATUS_LEVEL_2WORDS_VALUE  2
#define SI32_IDAC_A_BUFSTATUS_LEVEL_2WORDS_U32 \
   (SI32_IDAC_A_BUFSTATUS_LEVEL_2WORDS_VALUE << SI32_IDAC_A_BUFSTATUS_LEVEL_SHIFT)
// The data FIFO contains three words.
#define SI32_IDAC_A_BUFSTATUS_LEVEL_3WORDS_VALUE  3
#define SI32_IDAC_A_BUFSTATUS_LEVEL_3WORDS_U32 \
   (SI32_IDAC_A_BUFSTATUS_LEVEL_3WORDS_VALUE << SI32_IDAC_A_BUFSTATUS_LEVEL_SHIFT)
// The data FIFO is full and contains four words.
#define SI32_IDAC_A_BUFSTATUS_LEVEL_4WORDS_VALUE  4
#define SI32_IDAC_A_BUFSTATUS_LEVEL_4WORDS_U32 \
   (SI32_IDAC_A_BUFSTATUS_LEVEL_4WORDS_VALUE << SI32_IDAC_A_BUFSTATUS_LEVEL_SHIFT)

#define SI32_IDAC_A_BUFSTATUS_ORI_MASK  0x00000010
#define SI32_IDAC_A_BUFSTATUS_ORI_SHIFT  4
// Read: A FIFO overrun has not occurred. Write: Clear the interrupt.
#define SI32_IDAC_A_BUFSTATUS_ORI_NOT_SET_VALUE  0
#define SI32_IDAC_A_BUFSTATUS_ORI_NOT_SET_U32 \
   (SI32_IDAC_A_BUFSTATUS_ORI_NOT_SET_VALUE << SI32_IDAC_A_BUFSTATUS_ORI_SHIFT)
// Read: A FIFO overrun occurred. Write: Force a FIFO overrun interrupt.
#define SI32_IDAC_A_BUFSTATUS_ORI_SET_VALUE  1
#define SI32_IDAC_A_BUFSTATUS_ORI_SET_U32 \
   (SI32_IDAC_A_BUFSTATUS_ORI_SET_VALUE << SI32_IDAC_A_BUFSTATUS_ORI_SHIFT)

#define SI32_IDAC_A_BUFSTATUS_URI_MASK  0x00000020
#define SI32_IDAC_A_BUFSTATUS_URI_SHIFT  5
// Read: A FIFO underrun has not occurred. Write: Clear the interrupt.
#define SI32_IDAC_A_BUFSTATUS_URI_NOT_SET_VALUE  0
#define SI32_IDAC_A_BUFSTATUS_URI_NOT_SET_U32 \
   (SI32_IDAC_A_BUFSTATUS_URI_NOT_SET_VALUE << SI32_IDAC_A_BUFSTATUS_URI_SHIFT)
// Read: A FIFO underrun occurred. Write: Force a FIFO underrun interrupt.
#define SI32_IDAC_A_BUFSTATUS_URI_SET_VALUE  1
#define SI32_IDAC_A_BUFSTATUS_URI_SET_U32 \
   (SI32_IDAC_A_BUFSTATUS_URI_SET_VALUE << SI32_IDAC_A_BUFSTATUS_URI_SHIFT)

#define SI32_IDAC_A_BUFSTATUS_WEI_MASK  0x00000040
#define SI32_IDAC_A_BUFSTATUS_WEI_SHIFT  6
// Read: A FIFO went empty condition has not occurred. Write: Clear the interrupt.
#define SI32_IDAC_A_BUFSTATUS_WEI_NOT_SET_VALUE  0
#define SI32_IDAC_A_BUFSTATUS_WEI_NOT_SET_U32 \
   (SI32_IDAC_A_BUFSTATUS_WEI_NOT_SET_VALUE << SI32_IDAC_A_BUFSTATUS_WEI_SHIFT)
// Read: The FIFO is empty. Write: Force a FIFO went empty interrupt.
#define SI32_IDAC_A_BUFSTATUS_WEI_SET_VALUE  1
#define SI32_IDAC_A_BUFSTATUS_WEI_SET_U32 \
   (SI32_IDAC_A_BUFSTATUS_WEI_SET_VALUE << SI32_IDAC_A_BUFSTATUS_WEI_SHIFT)



struct SI32_IDAC_A_BUFFER10_Struct
{
   union
   {
      struct
      {
         // FIFO Buffer Entry 0
         volatile uint16_t BUFFER0;
         // FIFO Buffer Entry 1
         volatile uint16_t BUFFER1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_IDAC_A_BUFFER10_BUFFER0_MASK  0x0000FFFF
#define SI32_IDAC_A_BUFFER10_BUFFER0_SHIFT  0

#define SI32_IDAC_A_BUFFER10_BUFFER1_MASK  0xFFFF0000
#define SI32_IDAC_A_BUFFER10_BUFFER1_SHIFT  16



struct SI32_IDAC_A_BUFFER32_Struct
{
   union
   {
      struct
      {
         // FIFO Buffer Entry 2
         volatile uint16_t BUFFER2;
         // FIFO Buffer Entry 3
         volatile uint16_t BUFFER3;
      };
      volatile uint32_t U32;
   };
};

#define SI32_IDAC_A_BUFFER32_BUFFER2_MASK  0x0000FFFF
#define SI32_IDAC_A_BUFFER32_BUFFER2_SHIFT  0

#define SI32_IDAC_A_BUFFER32_BUFFER3_MASK  0xFFFF0000
#define SI32_IDAC_A_BUFFER32_BUFFER3_SHIFT  16



struct SI32_IDAC_A_GAINADJ_Struct
{
   union
   {
      struct
      {
         // Output Current Gain Adjust
         volatile uint32_t GAINADJ_BITS: 5;
                  uint32_t reserved0: 27;
      };
      volatile uint32_t U32;
   };
};

#define SI32_IDAC_A_GAINADJ_GAINADJ_MASK  0x0000001F
#define SI32_IDAC_A_GAINADJ_GAINADJ_SHIFT  0



typedef struct SI32_IDAC_A_Struct
{
   struct SI32_IDAC_A_CONTROL_Struct               CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_IDAC_A_DATA_Struct                  DATA           ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_IDAC_A_BUFSTATUS_Struct             BUFSTATUS      ; // Base Address + 0x20
   volatile uint32_t                               BUFSTATUS_SET;
   volatile uint32_t                               BUFSTATUS_CLR;
   uint32_t                                        reserved4;
   struct SI32_IDAC_A_BUFFER10_Struct              BUFFER10       ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_IDAC_A_BUFFER32_Struct              BUFFER32       ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   struct SI32_IDAC_A_GAINADJ_Struct               GAINADJ        ; // Base Address + 0x50
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
} SI32_IDAC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_IDAC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

