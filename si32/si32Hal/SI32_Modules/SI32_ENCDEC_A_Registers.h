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

#ifndef __SI32_ENCDEC_A_REGISTERS_H__
#define __SI32_ENCDEC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_ENCDEC_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Input Ready Interrupt Enable
         volatile uint32_t INRDYIEN: 1;
         // Output Ready Interrupt Enable
         volatile uint32_t ORDYIEN: 1;
         // Error Interrupt Enable
         volatile uint32_t ERRIEN: 1;
         // Module Reset
         volatile uint32_t RESET: 1;
         // Manchester Output Size
         volatile uint32_t MOSIZE: 1;
         // Encode Decode Mode
         volatile uint32_t EDMD: 1;
         // Operation Mode
         volatile uint32_t OPMD: 1;
                  uint32_t reserved0: 1;
         // Bypass Encoder/Decoder Operation Enable
         volatile uint32_t BEN: 1;
         // DMA Mode Enable
         volatile uint32_t DMAEN: 1;
         // Debug Mode
         volatile uint32_t DBGMD: 1;
                  uint32_t reserved1: 1;
         // Output Order Mode
         volatile uint32_t OORDER: 2;
         // Input Order Mode
         volatile uint32_t IORDER: 2;
                  uint32_t reserved2: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ENCDEC_A_CONTROL_INRDYIEN_MASK  0x00000001
#define SI32_ENCDEC_A_CONTROL_INRDYIEN_SHIFT  0
// Disable the input ready interrupt.
#define SI32_ENCDEC_A_CONTROL_INRDYIEN_DISABLED_VALUE  0
#define SI32_ENCDEC_A_CONTROL_INRDYIEN_DISABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_INRDYIEN_DISABLED_VALUE << SI32_ENCDEC_A_CONTROL_INRDYIEN_SHIFT)
// Enable the input ready interrupt.
#define SI32_ENCDEC_A_CONTROL_INRDYIEN_ENABLED_VALUE  1
#define SI32_ENCDEC_A_CONTROL_INRDYIEN_ENABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_INRDYIEN_ENABLED_VALUE << SI32_ENCDEC_A_CONTROL_INRDYIEN_SHIFT)

#define SI32_ENCDEC_A_CONTROL_ORDYIEN_MASK  0x00000002
#define SI32_ENCDEC_A_CONTROL_ORDYIEN_SHIFT  1
// Disable the output ready interrupt.
#define SI32_ENCDEC_A_CONTROL_ORDYIEN_DISABLED_VALUE  0
#define SI32_ENCDEC_A_CONTROL_ORDYIEN_DISABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_ORDYIEN_DISABLED_VALUE << SI32_ENCDEC_A_CONTROL_ORDYIEN_SHIFT)
// Enable the output ready interrupt.
#define SI32_ENCDEC_A_CONTROL_ORDYIEN_ENABLED_VALUE  1
#define SI32_ENCDEC_A_CONTROL_ORDYIEN_ENABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_ORDYIEN_ENABLED_VALUE << SI32_ENCDEC_A_CONTROL_ORDYIEN_SHIFT)

#define SI32_ENCDEC_A_CONTROL_ERRIEN_MASK  0x00000004
#define SI32_ENCDEC_A_CONTROL_ERRIEN_SHIFT  2
// Disable the error interrupt.
#define SI32_ENCDEC_A_CONTROL_ERRIEN_DISABLED_VALUE  0
#define SI32_ENCDEC_A_CONTROL_ERRIEN_DISABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_ERRIEN_DISABLED_VALUE << SI32_ENCDEC_A_CONTROL_ERRIEN_SHIFT)
// Enable the error interrupt.
#define SI32_ENCDEC_A_CONTROL_ERRIEN_ENABLED_VALUE  1
#define SI32_ENCDEC_A_CONTROL_ERRIEN_ENABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_ERRIEN_ENABLED_VALUE << SI32_ENCDEC_A_CONTROL_ERRIEN_SHIFT)

#define SI32_ENCDEC_A_CONTROL_RESET_MASK  0x00000008
#define SI32_ENCDEC_A_CONTROL_RESET_SHIFT  3
// Reset the module.
#define SI32_ENCDEC_A_CONTROL_RESET_ACTIVE_VALUE  1
#define SI32_ENCDEC_A_CONTROL_RESET_ACTIVE_U32 \
   (SI32_ENCDEC_A_CONTROL_RESET_ACTIVE_VALUE << SI32_ENCDEC_A_CONTROL_RESET_SHIFT)

#define SI32_ENCDEC_A_CONTROL_MOSIZE_MASK  0x00000010
#define SI32_ENCDEC_A_CONTROL_MOSIZE_SHIFT  4
// Manchester encode operations generate a half-word output, and decode operations
// generate a byte output.
#define SI32_ENCDEC_A_CONTROL_MOSIZE_SMALL_VALUE  0
#define SI32_ENCDEC_A_CONTROL_MOSIZE_SMALL_U32 \
   (SI32_ENCDEC_A_CONTROL_MOSIZE_SMALL_VALUE << SI32_ENCDEC_A_CONTROL_MOSIZE_SHIFT)
// Manchester encode operations generate a word output, and decode operations
// generate a half-word output.
#define SI32_ENCDEC_A_CONTROL_MOSIZE_LARGE_VALUE  1
#define SI32_ENCDEC_A_CONTROL_MOSIZE_LARGE_U32 \
   (SI32_ENCDEC_A_CONTROL_MOSIZE_LARGE_VALUE << SI32_ENCDEC_A_CONTROL_MOSIZE_SHIFT)

#define SI32_ENCDEC_A_CONTROL_EDMD_MASK  0x00000020
#define SI32_ENCDEC_A_CONTROL_EDMD_SHIFT  5
// Decode data written to DATAIN.
#define SI32_ENCDEC_A_CONTROL_EDMD_DECODE_VALUE  0
#define SI32_ENCDEC_A_CONTROL_EDMD_DECODE_U32 \
   (SI32_ENCDEC_A_CONTROL_EDMD_DECODE_VALUE << SI32_ENCDEC_A_CONTROL_EDMD_SHIFT)
// Encode data written to DATAIN.
#define SI32_ENCDEC_A_CONTROL_EDMD_ENCODE_VALUE  1
#define SI32_ENCDEC_A_CONTROL_EDMD_ENCODE_U32 \
   (SI32_ENCDEC_A_CONTROL_EDMD_ENCODE_VALUE << SI32_ENCDEC_A_CONTROL_EDMD_SHIFT)

#define SI32_ENCDEC_A_CONTROL_OPMD_MASK  0x00000040
#define SI32_ENCDEC_A_CONTROL_OPMD_SHIFT  6
// The operation selected by EDMD uses Manchester mode.
#define SI32_ENCDEC_A_CONTROL_OPMD_MANCHESTER_VALUE  0
#define SI32_ENCDEC_A_CONTROL_OPMD_MANCHESTER_U32 \
   (SI32_ENCDEC_A_CONTROL_OPMD_MANCHESTER_VALUE << SI32_ENCDEC_A_CONTROL_OPMD_SHIFT)
// The operation selected by EDMD uses Three-out-of-Six mode.
#define SI32_ENCDEC_A_CONTROL_OPMD_3OUTOF6_VALUE  1
#define SI32_ENCDEC_A_CONTROL_OPMD_3OUTOF6_U32 \
   (SI32_ENCDEC_A_CONTROL_OPMD_3OUTOF6_VALUE << SI32_ENCDEC_A_CONTROL_OPMD_SHIFT)

#define SI32_ENCDEC_A_CONTROL_BEN_MASK  0x00000100
#define SI32_ENCDEC_A_CONTROL_BEN_SHIFT  8
// Do not bypass ENCDEC operations.
#define SI32_ENCDEC_A_CONTROL_BEN_DISABLED_VALUE  0
#define SI32_ENCDEC_A_CONTROL_BEN_DISABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_BEN_DISABLED_VALUE << SI32_ENCDEC_A_CONTROL_BEN_SHIFT)
// Bypass ENCDEC operations.
#define SI32_ENCDEC_A_CONTROL_BEN_ENABLED_VALUE  1
#define SI32_ENCDEC_A_CONTROL_BEN_ENABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_BEN_ENABLED_VALUE << SI32_ENCDEC_A_CONTROL_BEN_SHIFT)

#define SI32_ENCDEC_A_CONTROL_DMAEN_MASK  0x00000200
#define SI32_ENCDEC_A_CONTROL_DMAEN_SHIFT  9
// Disable DMA mode.
#define SI32_ENCDEC_A_CONTROL_DMAEN_DISABLED_VALUE  0
#define SI32_ENCDEC_A_CONTROL_DMAEN_DISABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_DMAEN_DISABLED_VALUE << SI32_ENCDEC_A_CONTROL_DMAEN_SHIFT)
// Enable DMA mode.
#define SI32_ENCDEC_A_CONTROL_DMAEN_ENABLED_VALUE  1
#define SI32_ENCDEC_A_CONTROL_DMAEN_ENABLED_U32 \
   (SI32_ENCDEC_A_CONTROL_DMAEN_ENABLED_VALUE << SI32_ENCDEC_A_CONTROL_DMAEN_SHIFT)

#define SI32_ENCDEC_A_CONTROL_DBGMD_MASK  0x00000400
#define SI32_ENCDEC_A_CONTROL_DBGMD_SHIFT  10
// The ENCDEC module will continue to operate while the core is halted in debug
// mode.
#define SI32_ENCDEC_A_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_ENCDEC_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_ENCDEC_A_CONTROL_DBGMD_RUN_VALUE << SI32_ENCDEC_A_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the ENCDEC module to halt.
#define SI32_ENCDEC_A_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_ENCDEC_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_ENCDEC_A_CONTROL_DBGMD_HALT_VALUE << SI32_ENCDEC_A_CONTROL_DBGMD_SHIFT)

#define SI32_ENCDEC_A_CONTROL_OORDER_MASK  0x00003000
#define SI32_ENCDEC_A_CONTROL_OORDER_SHIFT  12
// The module outputs data to DATAOUT in the same order as it was processed (input:
// B3 B2 B1 B0, output: B3 B2 B1 B0).
#define SI32_ENCDEC_A_CONTROL_OORDER_NO_CHANGE_VALUE  0
#define SI32_ENCDEC_A_CONTROL_OORDER_NO_CHANGE_U32 \
   (SI32_ENCDEC_A_CONTROL_OORDER_NO_CHANGE_VALUE << SI32_ENCDEC_A_CONTROL_OORDER_SHIFT)
// The module flips the data in half-words before outputting to DATAOUT (input: B3
// B2 B1 B0, output: B2 B3 B0 B1).
#define SI32_ENCDEC_A_CONTROL_OORDER_HALF_WORD_VALUE  1
#define SI32_ENCDEC_A_CONTROL_OORDER_HALF_WORD_U32 \
   (SI32_ENCDEC_A_CONTROL_OORDER_HALF_WORD_VALUE << SI32_ENCDEC_A_CONTROL_OORDER_SHIFT)
// The module flips the data in words before outputting to DATAOUT (input: B3 B2 B1
// B0, output: B0 B1 B2 B3).
#define SI32_ENCDEC_A_CONTROL_OORDER_WORD_VALUE  2
#define SI32_ENCDEC_A_CONTROL_OORDER_WORD_U32 \
   (SI32_ENCDEC_A_CONTROL_OORDER_WORD_VALUE << SI32_ENCDEC_A_CONTROL_OORDER_SHIFT)
// The module flips the lower three bytes before outputting to DATAOUT (input: B3
// B2 B1 B0, output: B3 B0 B1 B2).
#define SI32_ENCDEC_A_CONTROL_OORDER_LOWER_THREE_BYTES_VALUE  3
#define SI32_ENCDEC_A_CONTROL_OORDER_LOWER_THREE_BYTES_U32 \
   (SI32_ENCDEC_A_CONTROL_OORDER_LOWER_THREE_BYTES_VALUE << SI32_ENCDEC_A_CONTROL_OORDER_SHIFT)

#define SI32_ENCDEC_A_CONTROL_IORDER_MASK  0x0000C000
#define SI32_ENCDEC_A_CONTROL_IORDER_SHIFT  14
// Data written to DATAIN is processed in the order written (input: B3 B2 B1 B0,
// output: B3 B2 B1 B0).
#define SI32_ENCDEC_A_CONTROL_IORDER_NO_CHANGE_VALUE  0
#define SI32_ENCDEC_A_CONTROL_IORDER_NO_CHANGE_U32 \
   (SI32_ENCDEC_A_CONTROL_IORDER_NO_CHANGE_VALUE << SI32_ENCDEC_A_CONTROL_IORDER_SHIFT)
// The module flips the DATAIN input data in half-words (input: B2 B3 B0 B1,
// output: B3 B2 B1 B0).
#define SI32_ENCDEC_A_CONTROL_IORDER_HALF_WORD_VALUE  1
#define SI32_ENCDEC_A_CONTROL_IORDER_HALF_WORD_U32 \
   (SI32_ENCDEC_A_CONTROL_IORDER_HALF_WORD_VALUE << SI32_ENCDEC_A_CONTROL_IORDER_SHIFT)
// The module flips the DATAIN input data in words (input: B0 B1 B2 B3, output: B3
// B2 B1 B0).
#define SI32_ENCDEC_A_CONTROL_IORDER_WORD_VALUE  2
#define SI32_ENCDEC_A_CONTROL_IORDER_WORD_U32 \
   (SI32_ENCDEC_A_CONTROL_IORDER_WORD_VALUE << SI32_ENCDEC_A_CONTROL_IORDER_SHIFT)
// The module flips the lower three bytes of the DATAIN input data (input: B3 B0 B1
// B2, output: B3 B2 B1 B0).
#define SI32_ENCDEC_A_CONTROL_IORDER_LOWER_THREE_BYTES_VALUE  3
#define SI32_ENCDEC_A_CONTROL_IORDER_LOWER_THREE_BYTES_U32 \
   (SI32_ENCDEC_A_CONTROL_IORDER_LOWER_THREE_BYTES_VALUE << SI32_ENCDEC_A_CONTROL_IORDER_SHIFT)



struct SI32_ENCDEC_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Input Ready Interrupt Flag
         volatile uint32_t INRDYI: 1;
         // Output Ready Interrupt Flag
         volatile uint32_t ORDYI: 1;
         // Data Error Interrupt Flag
         volatile uint32_t DERRI: 1;
         // Data Underrun Interrupt Flag
         volatile uint32_t DURI: 1;
         // Data Overrun Interrupt Flag
         volatile uint32_t DORI: 1;
                  uint32_t reserved0: 27;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ENCDEC_A_STATUS_INRDYI_MASK  0x00000001
#define SI32_ENCDEC_A_STATUS_INRDYI_SHIFT  0
// The input FIFO is not ready for new data.
#define SI32_ENCDEC_A_STATUS_INRDYI_NOT_SET_VALUE  0
#define SI32_ENCDEC_A_STATUS_INRDYI_NOT_SET_U32 \
   (SI32_ENCDEC_A_STATUS_INRDYI_NOT_SET_VALUE << SI32_ENCDEC_A_STATUS_INRDYI_SHIFT)
// Firmware can write new input data to DATAIN.
#define SI32_ENCDEC_A_STATUS_INRDYI_SET_VALUE  1
#define SI32_ENCDEC_A_STATUS_INRDYI_SET_U32 \
   (SI32_ENCDEC_A_STATUS_INRDYI_SET_VALUE << SI32_ENCDEC_A_STATUS_INRDYI_SHIFT)

#define SI32_ENCDEC_A_STATUS_ORDYI_MASK  0x00000002
#define SI32_ENCDEC_A_STATUS_ORDYI_SHIFT  1
// The output data is not ready.
#define SI32_ENCDEC_A_STATUS_ORDYI_NOT_SET_VALUE  0
#define SI32_ENCDEC_A_STATUS_ORDYI_NOT_SET_U32 \
   (SI32_ENCDEC_A_STATUS_ORDYI_NOT_SET_VALUE << SI32_ENCDEC_A_STATUS_ORDYI_SHIFT)
// The output data is ready to be read by firmware.
#define SI32_ENCDEC_A_STATUS_ORDYI_SET_VALUE  1
#define SI32_ENCDEC_A_STATUS_ORDYI_SET_U32 \
   (SI32_ENCDEC_A_STATUS_ORDYI_SET_VALUE << SI32_ENCDEC_A_STATUS_ORDYI_SHIFT)

#define SI32_ENCDEC_A_STATUS_DERRI_MASK  0x00000004
#define SI32_ENCDEC_A_STATUS_DERRI_SHIFT  2
#define SI32_ENCDEC_A_STATUS_DERRI_NOT_SET_VALUE  0
#define SI32_ENCDEC_A_STATUS_DERRI_NOT_SET_U32 \
   (SI32_ENCDEC_A_STATUS_DERRI_NOT_SET_VALUE << SI32_ENCDEC_A_STATUS_DERRI_SHIFT)
#define SI32_ENCDEC_A_STATUS_DERRI_SET_VALUE  1
#define SI32_ENCDEC_A_STATUS_DERRI_SET_U32 \
   (SI32_ENCDEC_A_STATUS_DERRI_SET_VALUE << SI32_ENCDEC_A_STATUS_DERRI_SHIFT)

#define SI32_ENCDEC_A_STATUS_DURI_MASK  0x00000008
#define SI32_ENCDEC_A_STATUS_DURI_SHIFT  3
// No output data FIFO underrun.
#define SI32_ENCDEC_A_STATUS_DURI_NOT_SET_VALUE  0
#define SI32_ENCDEC_A_STATUS_DURI_NOT_SET_U32 \
   (SI32_ENCDEC_A_STATUS_DURI_NOT_SET_VALUE << SI32_ENCDEC_A_STATUS_DURI_SHIFT)
// An output data FIFO underrun has occurred.
#define SI32_ENCDEC_A_STATUS_DURI_SET_VALUE  1
#define SI32_ENCDEC_A_STATUS_DURI_SET_U32 \
   (SI32_ENCDEC_A_STATUS_DURI_SET_VALUE << SI32_ENCDEC_A_STATUS_DURI_SHIFT)

#define SI32_ENCDEC_A_STATUS_DORI_MASK  0x00000010
#define SI32_ENCDEC_A_STATUS_DORI_SHIFT  4
// No input data FIFO overrun.
#define SI32_ENCDEC_A_STATUS_DORI_NOT_SET_VALUE  0
#define SI32_ENCDEC_A_STATUS_DORI_NOT_SET_U32 \
   (SI32_ENCDEC_A_STATUS_DORI_NOT_SET_VALUE << SI32_ENCDEC_A_STATUS_DORI_SHIFT)
// An input data FIFO overrun has occurred.
#define SI32_ENCDEC_A_STATUS_DORI_SET_VALUE  1
#define SI32_ENCDEC_A_STATUS_DORI_SET_U32 \
   (SI32_ENCDEC_A_STATUS_DORI_SET_VALUE << SI32_ENCDEC_A_STATUS_DORI_SHIFT)



struct SI32_ENCDEC_A_DATAIN_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_ENCDEC_A_DATAIN_DATAIN_MASK  0xFFFFFFFF
#define SI32_ENCDEC_A_DATAIN_DATAIN_SHIFT  0



struct SI32_ENCDEC_A_DATAOUT_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_ENCDEC_A_DATAOUT_DATAOUT_MASK  0xFFFFFFFF
#define SI32_ENCDEC_A_DATAOUT_DATAOUT_SHIFT  0



struct SI32_ENCDEC_A_DATAOUTC_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_ENCDEC_A_DATAOUTC_DATAOUTC_MASK  0xFFFFFFFF
#define SI32_ENCDEC_A_DATAOUTC_DATAOUTC_SHIFT  0



typedef struct SI32_ENCDEC_A_Struct
{
   struct SI32_ENCDEC_A_CONTROL_Struct             CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_ENCDEC_A_STATUS_Struct              STATUS         ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_ENCDEC_A_DATAIN_Struct              DATAIN         ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_ENCDEC_A_DATAOUT_Struct             DATAOUT        ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   struct SI32_ENCDEC_A_DATAOUTC_Struct            DATAOUTC       ; // Base Address + 0x40
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
} SI32_ENCDEC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_ENCDEC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

