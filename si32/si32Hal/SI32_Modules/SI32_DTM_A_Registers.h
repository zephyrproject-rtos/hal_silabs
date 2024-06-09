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

#ifndef __SI32_DTM_A_REGISTERS_H__
#define __SI32_DTM_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_DTM_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Active State Counter
         volatile uint8_t STCOUNT;
         // Active State
         volatile uint32_t ST: 4;
         // Last State
         volatile uint32_t LASTST: 4;
         // Inhibit Signal Select
         volatile uint32_t INHSSEL: 4;
                  uint32_t reserved0: 3;
         // Debug Mode
         volatile uint32_t DBGMD: 1;
         // Inhibit Status Flag
         volatile uint32_t INHF: 1;
         // Destination Peripheral DMA Request Status Flag
         volatile uint32_t DSTREQF: 1;
         // Source Peripheral DMA Request Status Flag
         volatile uint32_t SRCREQF: 1;
         // DTM Module Inhibit
         volatile uint32_t DTMINH: 1;
         // Timeout Error Interrupt Flag
         volatile uint32_t TOERRI: 1;
         // DMA Error Interrupt Flag
         volatile uint32_t DMAERRI: 1;
         // Module Interrupt Flag
         volatile uint32_t DTMI: 1;
         // Module Enable
         volatile uint32_t DTMEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DTM_A_CONTROL_STCOUNT_MASK  0x000000FF
#define SI32_DTM_A_CONTROL_STCOUNT_SHIFT  0

#define SI32_DTM_A_CONTROL_ST_MASK  0x00000F00
#define SI32_DTM_A_CONTROL_ST_SHIFT  8

#define SI32_DTM_A_CONTROL_LASTST_MASK  0x0000F000
#define SI32_DTM_A_CONTROL_LASTST_SHIFT  12

#define SI32_DTM_A_CONTROL_INHSSEL_MASK  0x000F0000
#define SI32_DTM_A_CONTROL_INHSSEL_SHIFT  16
// Select inhibit signal source DTMnINH.0.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH0_VALUE  0
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH0_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH0_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.1.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH1_VALUE  1
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH1_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH1_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.2.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH2_VALUE  2
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH2_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH2_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.3.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH3_VALUE  3
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH3_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH3_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.4.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH4_VALUE  4
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH4_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH4_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.5.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH5_VALUE  5
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH5_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH5_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.6.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH6_VALUE  6
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH6_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH6_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.7.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH7_VALUE  7
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH7_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH7_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.8.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH8_VALUE  8
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH8_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH8_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.9.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH9_VALUE  9
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH9_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH9_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.10.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH10_VALUE  10
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH10_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH10_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.11.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH11_VALUE  11
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH11_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH11_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.12.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH12_VALUE  12
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH12_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH12_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.13.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH13_VALUE  13
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH13_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH13_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.14.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH14_VALUE  14
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH14_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH14_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)
// Select inhibit signal source DTMnINH.15.
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH15_VALUE  15
#define SI32_DTM_A_CONTROL_INHSSEL_DTMNINH15_U32 \
   (SI32_DTM_A_CONTROL_INHSSEL_DTMNINH15_VALUE << SI32_DTM_A_CONTROL_INHSSEL_SHIFT)

#define SI32_DTM_A_CONTROL_DBGMD_MASK  0x00800000
#define SI32_DTM_A_CONTROL_DBGMD_SHIFT  23
// The DTM module will continue to operate while the core is halted in debug mode.
#define SI32_DTM_A_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_DTM_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_DTM_A_CONTROL_DBGMD_RUN_VALUE << SI32_DTM_A_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the DTM module to halt.
#define SI32_DTM_A_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_DTM_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_DTM_A_CONTROL_DBGMD_HALT_VALUE << SI32_DTM_A_CONTROL_DBGMD_SHIFT)

#define SI32_DTM_A_CONTROL_INHF_MASK  0x01000000
#define SI32_DTM_A_CONTROL_INHF_SHIFT  24
// The inhibit signal is inactive.
#define SI32_DTM_A_CONTROL_INHF_NOT_SET_VALUE  0
#define SI32_DTM_A_CONTROL_INHF_NOT_SET_U32 \
   (SI32_DTM_A_CONTROL_INHF_NOT_SET_VALUE << SI32_DTM_A_CONTROL_INHF_SHIFT)
// The inhibit signal is active.
#define SI32_DTM_A_CONTROL_INHF_SET_VALUE  1
#define SI32_DTM_A_CONTROL_INHF_SET_U32 \
   (SI32_DTM_A_CONTROL_INHF_SET_VALUE << SI32_DTM_A_CONTROL_INHF_SHIFT)

#define SI32_DTM_A_CONTROL_DSTREQF_MASK  0x02000000
#define SI32_DTM_A_CONTROL_DSTREQF_SHIFT  25
// The destination peripheral did not request a DMA transfer.
#define SI32_DTM_A_CONTROL_DSTREQF_NOT_SET_VALUE  0
#define SI32_DTM_A_CONTROL_DSTREQF_NOT_SET_U32 \
   (SI32_DTM_A_CONTROL_DSTREQF_NOT_SET_VALUE << SI32_DTM_A_CONTROL_DSTREQF_SHIFT)
// The destination peripheral requested a DMA transfer.
#define SI32_DTM_A_CONTROL_DSTREQF_SET_VALUE  1
#define SI32_DTM_A_CONTROL_DSTREQF_SET_U32 \
   (SI32_DTM_A_CONTROL_DSTREQF_SET_VALUE << SI32_DTM_A_CONTROL_DSTREQF_SHIFT)

#define SI32_DTM_A_CONTROL_SRCREQF_MASK  0x04000000
#define SI32_DTM_A_CONTROL_SRCREQF_SHIFT  26
// The source peripheral did not request a DMA transfer.
#define SI32_DTM_A_CONTROL_SRCREQF_NOT_SET_VALUE  0
#define SI32_DTM_A_CONTROL_SRCREQF_NOT_SET_U32 \
   (SI32_DTM_A_CONTROL_SRCREQF_NOT_SET_VALUE << SI32_DTM_A_CONTROL_SRCREQF_SHIFT)
// The source peripheral requested a DMA transfer.
#define SI32_DTM_A_CONTROL_SRCREQF_SET_VALUE  1
#define SI32_DTM_A_CONTROL_SRCREQF_SET_U32 \
   (SI32_DTM_A_CONTROL_SRCREQF_SET_VALUE << SI32_DTM_A_CONTROL_SRCREQF_SHIFT)

#define SI32_DTM_A_CONTROL_DTMINH_MASK  0x08000000
#define SI32_DTM_A_CONTROL_DTMINH_SHIFT  27
// The DTM module does not ignore DMA requests.
#define SI32_DTM_A_CONTROL_DTMINH_INACTIVE_VALUE  0
#define SI32_DTM_A_CONTROL_DTMINH_INACTIVE_U32 \
   (SI32_DTM_A_CONTROL_DTMINH_INACTIVE_VALUE << SI32_DTM_A_CONTROL_DTMINH_SHIFT)
// The DTM module ignores DMA requests until this bit is cleared.
#define SI32_DTM_A_CONTROL_DTMINH_ACTIVE_VALUE  1
#define SI32_DTM_A_CONTROL_DTMINH_ACTIVE_U32 \
   (SI32_DTM_A_CONTROL_DTMINH_ACTIVE_VALUE << SI32_DTM_A_CONTROL_DTMINH_SHIFT)

#define SI32_DTM_A_CONTROL_TOERRI_MASK  0x10000000
#define SI32_DTM_A_CONTROL_TOERRI_SHIFT  28
// A timeout error has not occurred.
#define SI32_DTM_A_CONTROL_TOERRI_NOT_SET_VALUE  0
#define SI32_DTM_A_CONTROL_TOERRI_NOT_SET_U32 \
   (SI32_DTM_A_CONTROL_TOERRI_NOT_SET_VALUE << SI32_DTM_A_CONTROL_TOERRI_SHIFT)
// A timeout error occurred.
#define SI32_DTM_A_CONTROL_TOERRI_SET_VALUE  1
#define SI32_DTM_A_CONTROL_TOERRI_SET_U32 \
   (SI32_DTM_A_CONTROL_TOERRI_SET_VALUE << SI32_DTM_A_CONTROL_TOERRI_SHIFT)

#define SI32_DTM_A_CONTROL_DMAERRI_MASK  0x20000000
#define SI32_DTM_A_CONTROL_DMAERRI_SHIFT  29
// A DMA error has not occurred.
#define SI32_DTM_A_CONTROL_DMAERRI_NOT_SET_VALUE  0
#define SI32_DTM_A_CONTROL_DMAERRI_NOT_SET_U32 \
   (SI32_DTM_A_CONTROL_DMAERRI_NOT_SET_VALUE << SI32_DTM_A_CONTROL_DMAERRI_SHIFT)
// A DMA error occurred.
#define SI32_DTM_A_CONTROL_DMAERRI_SET_VALUE  1
#define SI32_DTM_A_CONTROL_DMAERRI_SET_U32 \
   (SI32_DTM_A_CONTROL_DMAERRI_SET_VALUE << SI32_DTM_A_CONTROL_DMAERRI_SHIFT)

#define SI32_DTM_A_CONTROL_DTMI_MASK  0x40000000
#define SI32_DTM_A_CONTROL_DTMI_SHIFT  30
// A state transition or timeout has not occurred.
#define SI32_DTM_A_CONTROL_DTMI_NOT_SET_VALUE  0
#define SI32_DTM_A_CONTROL_DTMI_NOT_SET_U32 \
   (SI32_DTM_A_CONTROL_DTMI_NOT_SET_VALUE << SI32_DTM_A_CONTROL_DTMI_SHIFT)
// A state transition (SECSTIEN or PRISTIEN set to 1) or timeout (TOERRIEN = 1)
// occurred.
#define SI32_DTM_A_CONTROL_DTMI_SET_VALUE  1
#define SI32_DTM_A_CONTROL_DTMI_SET_U32 \
   (SI32_DTM_A_CONTROL_DTMI_SET_VALUE << SI32_DTM_A_CONTROL_DTMI_SHIFT)

#define SI32_DTM_A_CONTROL_DTMEN_MASK  0x80000000
#define SI32_DTM_A_CONTROL_DTMEN_SHIFT  31
// Disable the DTM module.
#define SI32_DTM_A_CONTROL_DTMEN_DISABLED_VALUE  0U
#define SI32_DTM_A_CONTROL_DTMEN_DISABLED_U32 \
   (SI32_DTM_A_CONTROL_DTMEN_DISABLED_VALUE << SI32_DTM_A_CONTROL_DTMEN_SHIFT)
// Enable the DTM module.
#define SI32_DTM_A_CONTROL_DTMEN_ENABLED_VALUE  1U
#define SI32_DTM_A_CONTROL_DTMEN_ENABLED_U32 \
   (SI32_DTM_A_CONTROL_DTMEN_ENABLED_VALUE << SI32_DTM_A_CONTROL_DTMEN_SHIFT)



struct SI32_DTM_A_TIMEOUT_Struct
{
   union
   {
      struct
      {
         // Timeout Counter Reload
         volatile uint16_t TORELOAD;
         // Timeout Counter
         volatile uint16_t TOCOUNT;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DTM_A_TIMEOUT_TORELOAD_MASK  0x0000FFFF
#define SI32_DTM_A_TIMEOUT_TORELOAD_SHIFT  0

#define SI32_DTM_A_TIMEOUT_TOCOUNT_MASK  0xFFFF0000
#define SI32_DTM_A_TIMEOUT_TOCOUNT_SHIFT  16



struct SI32_DTM_A_MSTCOUNT_Struct
{
   union
   {
      struct
      {
         // Master Counter
         volatile uint16_t MSTCOUNT_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DTM_A_MSTCOUNT_MSTCOUNT_MASK  0x0000FFFF
#define SI32_DTM_A_MSTCOUNT_MSTCOUNT_SHIFT  0



struct SI32_DTM_A_STATEADDR_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 2;
         // State Address
         volatile uint32_t STATEADDR_BITS: 30;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DTM_A_STATEADDR_STATEADDR_MASK  0xFFFFFFFC
#define SI32_DTM_A_STATEADDR_STATEADDR_SHIFT  2



struct SI32_DTM_A_STATE_Struct
{
   union
   {
      struct
      {
         // Active State Counter Reload
         volatile uint8_t STRELOAD;
         // Secondary State
         volatile uint32_t SECST: 4;
         // Primary State
         volatile uint32_t PRIST: 4;
         // Destination Module
         volatile uint32_t DSTMOD: 4;
         // Source Module
         volatile uint32_t SRCMOD: 4;
         // DTM Channel Select
         volatile uint32_t DTMCHSEL: 2;
         // Inhibit Signal Polarity
         volatile uint32_t INHSPOL: 1;
         // Module Inhibit Enable
         volatile uint32_t DTMINH: 1;
         // Master Decrement Enable
         volatile uint32_t MSTDECEN: 1;
         // Timeout Enable
         volatile uint32_t TOERRIEN: 1;
         // Secondary State Transition Interrupt Enable
         volatile uint32_t SECSTIEN: 1;
         // Primary State Transition Interrupt Enable
         volatile uint32_t PRISTIEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DTM_A_STATE_STRELOAD_MASK  0x000000FF
#define SI32_DTM_A_STATE_STRELOAD_SHIFT  0

#define SI32_DTM_A_STATE_SECST_MASK  0x00000F00
#define SI32_DTM_A_STATE_SECST_SHIFT  8

#define SI32_DTM_A_STATE_PRIST_MASK  0x0000F000
#define SI32_DTM_A_STATE_PRIST_SHIFT  12

#define SI32_DTM_A_STATE_DSTMOD_MASK  0x000F0000
#define SI32_DTM_A_STATE_DSTMOD_SHIFT  16
// Select destination module DTMnDST.0.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST0_VALUE  0
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST0_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST0_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.1.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST1_VALUE  1
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST1_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST1_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.2.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST2_VALUE  2
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST2_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST2_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.3.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST3_VALUE  3
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST3_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST3_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.4.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST4_VALUE  4
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST4_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST4_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.5.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST5_VALUE  5
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST5_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST5_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.6.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST6_VALUE  6
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST6_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST6_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.7.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST7_VALUE  7
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST7_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST7_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.8.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST8_VALUE  8
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST8_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST8_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.9.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST9_VALUE  9
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST9_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST9_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.10.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST10_VALUE  10
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST10_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST10_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.11.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST11_VALUE  11
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST11_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST11_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.12.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST12_VALUE  12
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST12_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST12_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.13.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST13_VALUE  13
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST13_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST13_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select destination module DTMnDST.14.
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST14_VALUE  14
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST14_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST14_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)
// Select no destination module (DTMnDST.15).
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST15_VALUE  15
#define SI32_DTM_A_STATE_DSTMOD_DTMNDST15_U32 \
   (SI32_DTM_A_STATE_DSTMOD_DTMNDST15_VALUE << SI32_DTM_A_STATE_DSTMOD_SHIFT)

#define SI32_DTM_A_STATE_SRCMOD_MASK  0x00F00000
#define SI32_DTM_A_STATE_SRCMOD_SHIFT  20
// Select source module DTMnSRC.0.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC0_VALUE  0
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC0_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC0_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.1.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC1_VALUE  1
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC1_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC1_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.2.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC2_VALUE  2
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC2_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC2_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.3.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC3_VALUE  3
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC3_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC3_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.4.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC4_VALUE  4
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC4_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC4_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.5.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC5_VALUE  5
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC5_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC5_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.6.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC6_VALUE  6
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC6_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC6_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.7.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC7_VALUE  7
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC7_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC7_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.8.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC8_VALUE  8
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC8_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC8_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.9.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC9_VALUE  9
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC9_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC9_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.10.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC10_VALUE  10
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC10_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC10_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.11.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC11_VALUE  11
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC11_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC11_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.12.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC12_VALUE  12
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC12_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC12_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.13.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC13_VALUE  13
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC13_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC13_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select source module DTMnSRC.14.
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC14_VALUE  14
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC14_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC14_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)
// Select no source module (DTMnSRC.15).
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC15_VALUE  15
#define SI32_DTM_A_STATE_SRCMOD_DTMNSRC15_U32 \
   (SI32_DTM_A_STATE_SRCMOD_DTMNSRC15_VALUE << SI32_DTM_A_STATE_SRCMOD_SHIFT)

#define SI32_DTM_A_STATE_DTMCHSEL_MASK  0x03000000
#define SI32_DTM_A_STATE_DTMCHSEL_SHIFT  24
// Select DTMn channel A for this state.
#define SI32_DTM_A_STATE_DTMCHSEL_CH_A_VALUE  0
#define SI32_DTM_A_STATE_DTMCHSEL_CH_A_U32 \
   (SI32_DTM_A_STATE_DTMCHSEL_CH_A_VALUE << SI32_DTM_A_STATE_DTMCHSEL_SHIFT)
// Select DTMn channel B for this state.
#define SI32_DTM_A_STATE_DTMCHSEL_CH_B_VALUE  1
#define SI32_DTM_A_STATE_DTMCHSEL_CH_B_U32 \
   (SI32_DTM_A_STATE_DTMCHSEL_CH_B_VALUE << SI32_DTM_A_STATE_DTMCHSEL_SHIFT)
// Select DTMn channel C for this state.
#define SI32_DTM_A_STATE_DTMCHSEL_CH_C_VALUE  2
#define SI32_DTM_A_STATE_DTMCHSEL_CH_C_U32 \
   (SI32_DTM_A_STATE_DTMCHSEL_CH_C_VALUE << SI32_DTM_A_STATE_DTMCHSEL_SHIFT)
// Select DTMn channel D for this state.
#define SI32_DTM_A_STATE_DTMCHSEL_CH_D_VALUE  3
#define SI32_DTM_A_STATE_DTMCHSEL_CH_D_U32 \
   (SI32_DTM_A_STATE_DTMCHSEL_CH_D_VALUE << SI32_DTM_A_STATE_DTMCHSEL_SHIFT)

#define SI32_DTM_A_STATE_INHSPOL_MASK  0x04000000
#define SI32_DTM_A_STATE_INHSPOL_SHIFT  26
// A logic low on the pin selected by INHSEL will allow the DTM to proceed.
#define SI32_DTM_A_STATE_INHSPOL_ACTIVE_LOW_VALUE  0
#define SI32_DTM_A_STATE_INHSPOL_ACTIVE_LOW_U32 \
   (SI32_DTM_A_STATE_INHSPOL_ACTIVE_LOW_VALUE << SI32_DTM_A_STATE_INHSPOL_SHIFT)
// A logic high on the pin selected by INHSEL will allow the DTM to proceed.
#define SI32_DTM_A_STATE_INHSPOL_ACTIVE_HIGH_VALUE  1
#define SI32_DTM_A_STATE_INHSPOL_ACTIVE_HIGH_U32 \
   (SI32_DTM_A_STATE_INHSPOL_ACTIVE_HIGH_VALUE << SI32_DTM_A_STATE_INHSPOL_SHIFT)

#define SI32_DTM_A_STATE_DTMINH_MASK  0x08000000
#define SI32_DTM_A_STATE_DTMINH_SHIFT  27
// The DTM module does not ignore any DMA requests.
#define SI32_DTM_A_STATE_DTMINH_INACTIVE_VALUE  0
#define SI32_DTM_A_STATE_DTMINH_INACTIVE_U32 \
   (SI32_DTM_A_STATE_DTMINH_INACTIVE_VALUE << SI32_DTM_A_STATE_DTMINH_SHIFT)
// The DTM module ignores all DMA requests until the inhibit signal selected by
// INHSSEL matches the polarity polarity set by INHSPOL.
#define SI32_DTM_A_STATE_DTMINH_ACTIVE_VALUE  1
#define SI32_DTM_A_STATE_DTMINH_ACTIVE_U32 \
   (SI32_DTM_A_STATE_DTMINH_ACTIVE_VALUE << SI32_DTM_A_STATE_DTMINH_SHIFT)

#define SI32_DTM_A_STATE_MSTDECEN_MASK  0x10000000
#define SI32_DTM_A_STATE_MSTDECEN_SHIFT  28
// Disable master counter decrements.
#define SI32_DTM_A_STATE_MSTDECEN_DISABLED_VALUE  0
#define SI32_DTM_A_STATE_MSTDECEN_DISABLED_U32 \
   (SI32_DTM_A_STATE_MSTDECEN_DISABLED_VALUE << SI32_DTM_A_STATE_MSTDECEN_SHIFT)
// Enable master counter decrements.
#define SI32_DTM_A_STATE_MSTDECEN_ENABLED_VALUE  1
#define SI32_DTM_A_STATE_MSTDECEN_ENABLED_U32 \
   (SI32_DTM_A_STATE_MSTDECEN_ENABLED_VALUE << SI32_DTM_A_STATE_MSTDECEN_SHIFT)

#define SI32_DTM_A_STATE_TOERRIEN_MASK  0x20000000
#define SI32_DTM_A_STATE_TOERRIEN_SHIFT  29
// Disable timeouts and timeout interrupts.
#define SI32_DTM_A_STATE_TOERRIEN_DISABLED_VALUE  0
#define SI32_DTM_A_STATE_TOERRIEN_DISABLED_U32 \
   (SI32_DTM_A_STATE_TOERRIEN_DISABLED_VALUE << SI32_DTM_A_STATE_TOERRIEN_SHIFT)
// Enable timeouts and timeout interrupts.
#define SI32_DTM_A_STATE_TOERRIEN_ENABLED_VALUE  1
#define SI32_DTM_A_STATE_TOERRIEN_ENABLED_U32 \
   (SI32_DTM_A_STATE_TOERRIEN_ENABLED_VALUE << SI32_DTM_A_STATE_TOERRIEN_SHIFT)

#define SI32_DTM_A_STATE_SECSTIEN_MASK  0x40000000
#define SI32_DTM_A_STATE_SECSTIEN_SHIFT  30
// Disable secondary state transition interrupts.
#define SI32_DTM_A_STATE_SECSTIEN_DISABLED_VALUE  0
#define SI32_DTM_A_STATE_SECSTIEN_DISABLED_U32 \
   (SI32_DTM_A_STATE_SECSTIEN_DISABLED_VALUE << SI32_DTM_A_STATE_SECSTIEN_SHIFT)
// Enable secondary state transition interrupts.
#define SI32_DTM_A_STATE_SECSTIEN_ENABLED_VALUE  1
#define SI32_DTM_A_STATE_SECSTIEN_ENABLED_U32 \
   (SI32_DTM_A_STATE_SECSTIEN_ENABLED_VALUE << SI32_DTM_A_STATE_SECSTIEN_SHIFT)

#define SI32_DTM_A_STATE_PRISTIEN_MASK  0x80000000
#define SI32_DTM_A_STATE_PRISTIEN_SHIFT  31
// Disable primary state transition interrupts.
#define SI32_DTM_A_STATE_PRISTIEN_DISABLED_VALUE  0U
#define SI32_DTM_A_STATE_PRISTIEN_DISABLED_U32 \
   (SI32_DTM_A_STATE_PRISTIEN_DISABLED_VALUE << SI32_DTM_A_STATE_PRISTIEN_SHIFT)
// Enable primary state transition interrupts.
#define SI32_DTM_A_STATE_PRISTIEN_ENABLED_VALUE  1U
#define SI32_DTM_A_STATE_PRISTIEN_ENABLED_U32 \
   (SI32_DTM_A_STATE_PRISTIEN_ENABLED_VALUE << SI32_DTM_A_STATE_PRISTIEN_SHIFT)



typedef struct SI32_DTM_A_Struct
{
   struct SI32_DTM_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_DTM_A_TIMEOUT_Struct                TIMEOUT        ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_DTM_A_MSTCOUNT_Struct               MSTCOUNT       ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_DTM_A_STATEADDR_Struct              STATEADDR      ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   struct SI32_DTM_A_STATE_Struct                  STATE          ; // Base Address + 0x40
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
} SI32_DTM_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_DTM_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

