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

#ifndef __SI32_EPCACH_A_REGISTERS_H__
#define __SI32_EPCACH_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_EPCACH_A_MODE_Struct
{
   union
   {
      struct
      {
         // Channel Output Function Select
         volatile uint32_t COSEL: 2;
         // PWM N-Bit Mode
         volatile uint32_t PWMMD: 4;
         // Differential Signal Generator Enable
         volatile uint32_t DIFGEN: 1;
                  uint32_t reserved0: 1;
         // Channel Operating Mode
         volatile uint32_t CMD: 3;
                  uint32_t reserved1: 21;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCACH_A_MODE_COSEL_MASK  0x00000003
#define SI32_EPCACH_A_MODE_COSEL_SHIFT  0
// Toggle the channel output at the next capture/compare, overflow, or intermediate
// event.
#define SI32_EPCACH_A_MODE_COSEL_TOGGLE_OUTPUT_VALUE  0
#define SI32_EPCACH_A_MODE_COSEL_TOGGLE_OUTPUT_U32 \
   (SI32_EPCACH_A_MODE_COSEL_TOGGLE_OUTPUT_VALUE << SI32_EPCACH_A_MODE_COSEL_SHIFT)
// Set the channel output at the next capture/compare, overflow, or intermediate
// event.
#define SI32_EPCACH_A_MODE_COSEL_SET_OUTPUT_VALUE  1
#define SI32_EPCACH_A_MODE_COSEL_SET_OUTPUT_U32 \
   (SI32_EPCACH_A_MODE_COSEL_SET_OUTPUT_VALUE << SI32_EPCACH_A_MODE_COSEL_SHIFT)
// Clear the output at the next capture/compare, overflow, or intermediate event.
#define SI32_EPCACH_A_MODE_COSEL_CLEAR_OUTPUT_VALUE  2
#define SI32_EPCACH_A_MODE_COSEL_CLEAR_OUTPUT_U32 \
   (SI32_EPCACH_A_MODE_COSEL_CLEAR_OUTPUT_VALUE << SI32_EPCACH_A_MODE_COSEL_SHIFT)
// Capture/Compare, overflow, or intermediate events do not control the output
// state.
#define SI32_EPCACH_A_MODE_COSEL_NO_CHANGE_VALUE  3
#define SI32_EPCACH_A_MODE_COSEL_NO_CHANGE_U32 \
   (SI32_EPCACH_A_MODE_COSEL_NO_CHANGE_VALUE << SI32_EPCACH_A_MODE_COSEL_SHIFT)

#define SI32_EPCACH_A_MODE_PWMMD_MASK  0x0000003C
#define SI32_EPCACH_A_MODE_PWMMD_SHIFT  2

#define SI32_EPCACH_A_MODE_DIFGEN_MASK  0x00000040
#define SI32_EPCACH_A_MODE_DIFGEN_SHIFT  6
// Disable the differential signal generator. The channel will output a single non-
// differential output.
#define SI32_EPCACH_A_MODE_DIFGEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_MODE_DIFGEN_DISABLED_U32 \
   (SI32_EPCACH_A_MODE_DIFGEN_DISABLED_VALUE << SI32_EPCACH_A_MODE_DIFGEN_SHIFT)
// Enable the differential signal generator. The channel will output two
// differential outputs: X Phase (XPH) and Y Phase (YPH).
#define SI32_EPCACH_A_MODE_DIFGEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_MODE_DIFGEN_ENABLED_U32 \
   (SI32_EPCACH_A_MODE_DIFGEN_ENABLED_VALUE << SI32_EPCACH_A_MODE_DIFGEN_SHIFT)

#define SI32_EPCACH_A_MODE_CMD_MASK  0x00000700
#define SI32_EPCACH_A_MODE_CMD_SHIFT  8
// Configure the channel for edge-aligned PWM mode.
#define SI32_EPCACH_A_MODE_CMD_EDGE_PWM_VALUE  0
#define SI32_EPCACH_A_MODE_CMD_EDGE_PWM_U32 \
   (SI32_EPCACH_A_MODE_CMD_EDGE_PWM_VALUE << SI32_EPCACH_A_MODE_CMD_SHIFT)
// Configure the channel for center-aligned PWM mode.
#define SI32_EPCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_VALUE  1
#define SI32_EPCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_U32 \
   (SI32_EPCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_VALUE << SI32_EPCACH_A_MODE_CMD_SHIFT)
// Configure the channel for high-frequency/square-wave mode.
#define SI32_EPCACH_A_MODE_CMD_HF_SQUARE_WAVE_VALUE  2
#define SI32_EPCACH_A_MODE_CMD_HF_SQUARE_WAVE_U32 \
   (SI32_EPCACH_A_MODE_CMD_HF_SQUARE_WAVE_VALUE << SI32_EPCACH_A_MODE_CMD_SHIFT)
// Configure the channel for timer/capture mode.
#define SI32_EPCACH_A_MODE_CMD_TIMER_CAPTURE_VALUE  3
#define SI32_EPCACH_A_MODE_CMD_TIMER_CAPTURE_U32 \
   (SI32_EPCACH_A_MODE_CMD_TIMER_CAPTURE_VALUE << SI32_EPCACH_A_MODE_CMD_SHIFT)
// Configure the channel for n-bit edge-aligned PWM mode.
#define SI32_EPCACH_A_MODE_CMD_N_BIT_PWM_VALUE  4
#define SI32_EPCACH_A_MODE_CMD_N_BIT_PWM_U32 \
   (SI32_EPCACH_A_MODE_CMD_N_BIT_PWM_VALUE << SI32_EPCACH_A_MODE_CMD_SHIFT)



struct SI32_EPCACH_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Channel Output State
         volatile uint32_t COUTST: 1;
         // Positive Edge Input Capture Enable
         volatile uint32_t CPCAPEN: 1;
         // Negative Edge Input Capture Enable
         volatile uint32_t CNCAPEN: 1;
         // Channel Register Update Complete Flag
         volatile uint32_t CUPDCF: 1;
                  uint32_t reserved0: 1;
         // Differential Y Phase State
         volatile uint32_t YPHST: 1;
         // Active Channel Select
         volatile uint32_t ACTIVEPH: 1;
         // Differential X Phase State
         volatile uint32_t XPHST: 1;
         // Capture/Compare Interrupt Enable
         volatile uint32_t CCIEN: 1;
         // Capture/Compare DMA Request Enable
         volatile uint32_t CCDEN: 1;
         // Capture/Compare Synchronization Signal Enable
         volatile uint32_t CCSEN: 1;
         // Intermediate Overflow Interrupt Enable
         volatile uint32_t CIOVFIEN: 1;
         // Intermediate Overflow DMA Request Enable
         volatile uint32_t CIOVFDEN: 1;
         // Intermediate Overflow Synchronization Signal Enable
         volatile uint32_t CIOVFSEN: 1;
                  uint32_t reserved1: 18;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCACH_A_CONTROL_COUTST_MASK  0x00000001
#define SI32_EPCACH_A_CONTROL_COUTST_SHIFT  0
// The channel output state is low.
#define SI32_EPCACH_A_CONTROL_COUTST_LOW_VALUE  0
#define SI32_EPCACH_A_CONTROL_COUTST_LOW_U32 \
   (SI32_EPCACH_A_CONTROL_COUTST_LOW_VALUE << SI32_EPCACH_A_CONTROL_COUTST_SHIFT)
// The channel output state is high.
#define SI32_EPCACH_A_CONTROL_COUTST_HIGH_VALUE  1
#define SI32_EPCACH_A_CONTROL_COUTST_HIGH_U32 \
   (SI32_EPCACH_A_CONTROL_COUTST_HIGH_VALUE << SI32_EPCACH_A_CONTROL_COUTST_SHIFT)

#define SI32_EPCACH_A_CONTROL_CPCAPEN_MASK  0x00000002
#define SI32_EPCACH_A_CONTROL_CPCAPEN_SHIFT  1
// Disable positive-edge input capture.
#define SI32_EPCACH_A_CONTROL_CPCAPEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CPCAPEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CPCAPEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CPCAPEN_SHIFT)
// Enable positive-edge input capture.
#define SI32_EPCACH_A_CONTROL_CPCAPEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CPCAPEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CPCAPEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CPCAPEN_SHIFT)

#define SI32_EPCACH_A_CONTROL_CNCAPEN_MASK  0x00000004
#define SI32_EPCACH_A_CONTROL_CNCAPEN_SHIFT  2
// Disable negative-edge input capture.
#define SI32_EPCACH_A_CONTROL_CNCAPEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CNCAPEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CNCAPEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CNCAPEN_SHIFT)
// Enable negative-edge input capture.
#define SI32_EPCACH_A_CONTROL_CNCAPEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CNCAPEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CNCAPEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CNCAPEN_SHIFT)

#define SI32_EPCACH_A_CONTROL_CUPDCF_MASK  0x00000008
#define SI32_EPCACH_A_CONTROL_CUPDCF_SHIFT  3
// A EPCA channel register update completed or is not pending.
#define SI32_EPCACH_A_CONTROL_CUPDCF_NOT_SET_VALUE  0
#define SI32_EPCACH_A_CONTROL_CUPDCF_NOT_SET_U32 \
   (SI32_EPCACH_A_CONTROL_CUPDCF_NOT_SET_VALUE << SI32_EPCACH_A_CONTROL_CUPDCF_SHIFT)
// A EPCA channel register update has not completed and is still pending.
#define SI32_EPCACH_A_CONTROL_CUPDCF_SET_VALUE  1
#define SI32_EPCACH_A_CONTROL_CUPDCF_SET_U32 \
   (SI32_EPCACH_A_CONTROL_CUPDCF_SET_VALUE << SI32_EPCACH_A_CONTROL_CUPDCF_SHIFT)

#define SI32_EPCACH_A_CONTROL_YPHST_MASK  0x00000020
#define SI32_EPCACH_A_CONTROL_YPHST_SHIFT  5
// Set the Y Phase output state to low.
#define SI32_EPCACH_A_CONTROL_YPHST_LOW_VALUE  0
#define SI32_EPCACH_A_CONTROL_YPHST_LOW_U32 \
   (SI32_EPCACH_A_CONTROL_YPHST_LOW_VALUE << SI32_EPCACH_A_CONTROL_YPHST_SHIFT)
// Set the Y Phase output state to high.
#define SI32_EPCACH_A_CONTROL_YPHST_HIGH_VALUE  1
#define SI32_EPCACH_A_CONTROL_YPHST_HIGH_U32 \
   (SI32_EPCACH_A_CONTROL_YPHST_HIGH_VALUE << SI32_EPCACH_A_CONTROL_YPHST_SHIFT)

#define SI32_EPCACH_A_CONTROL_ACTIVEPH_MASK  0x00000040
#define SI32_EPCACH_A_CONTROL_ACTIVEPH_SHIFT  6
// The Y Phase is active and X Phase is inactive.
#define SI32_EPCACH_A_CONTROL_ACTIVEPH_YACTIVE_VALUE  0
#define SI32_EPCACH_A_CONTROL_ACTIVEPH_YACTIVE_U32 \
   (SI32_EPCACH_A_CONTROL_ACTIVEPH_YACTIVE_VALUE << SI32_EPCACH_A_CONTROL_ACTIVEPH_SHIFT)
// The X Phase is active and Y Phase is inactive.
#define SI32_EPCACH_A_CONTROL_ACTIVEPH_XACTIVE_VALUE  1
#define SI32_EPCACH_A_CONTROL_ACTIVEPH_XACTIVE_U32 \
   (SI32_EPCACH_A_CONTROL_ACTIVEPH_XACTIVE_VALUE << SI32_EPCACH_A_CONTROL_ACTIVEPH_SHIFT)

#define SI32_EPCACH_A_CONTROL_XPHST_MASK  0x00000080
#define SI32_EPCACH_A_CONTROL_XPHST_SHIFT  7
// Set the X Phase output state to low.
#define SI32_EPCACH_A_CONTROL_XPHST_LOW_VALUE  0
#define SI32_EPCACH_A_CONTROL_XPHST_LOW_U32 \
   (SI32_EPCACH_A_CONTROL_XPHST_LOW_VALUE << SI32_EPCACH_A_CONTROL_XPHST_SHIFT)
// Set the X Phase output state to high.
#define SI32_EPCACH_A_CONTROL_XPHST_HIGH_VALUE  1
#define SI32_EPCACH_A_CONTROL_XPHST_HIGH_U32 \
   (SI32_EPCACH_A_CONTROL_XPHST_HIGH_VALUE << SI32_EPCACH_A_CONTROL_XPHST_SHIFT)

#define SI32_EPCACH_A_CONTROL_CCIEN_MASK  0x00000100
#define SI32_EPCACH_A_CONTROL_CCIEN_SHIFT  8
// Disable the channel capture/compare interrupt.
#define SI32_EPCACH_A_CONTROL_CCIEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CCIEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CCIEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CCIEN_SHIFT)
// Enable the channel capture/compare interrupt.
#define SI32_EPCACH_A_CONTROL_CCIEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CCIEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CCIEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CCIEN_SHIFT)

#define SI32_EPCACH_A_CONTROL_CCDEN_MASK  0x00000200
#define SI32_EPCACH_A_CONTROL_CCDEN_SHIFT  9
// Do not request DMA data when a channel capture/compare event occurs.
#define SI32_EPCACH_A_CONTROL_CCDEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CCDEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CCDEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CCDEN_SHIFT)
// Request DMA data when a channel capture/compare event occurs.
#define SI32_EPCACH_A_CONTROL_CCDEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CCDEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CCDEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CCDEN_SHIFT)

#define SI32_EPCACH_A_CONTROL_CCSEN_MASK  0x00000400
#define SI32_EPCACH_A_CONTROL_CCSEN_SHIFT  10
// Do not send a synchronization signal when a channel capture/compare event
// occurs.
#define SI32_EPCACH_A_CONTROL_CCSEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CCSEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CCSEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CCSEN_SHIFT)
// Send a synchronization signal when a channel capture/compare event occurs.
#define SI32_EPCACH_A_CONTROL_CCSEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CCSEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CCSEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CCSEN_SHIFT)

#define SI32_EPCACH_A_CONTROL_CIOVFIEN_MASK  0x00000800
#define SI32_EPCACH_A_CONTROL_CIOVFIEN_SHIFT  11
// Disable the channel intermediate overflow interrupt.
#define SI32_EPCACH_A_CONTROL_CIOVFIEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CIOVFIEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CIOVFIEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CIOVFIEN_SHIFT)
// Enable the channel intermediate overflow interrupt.
#define SI32_EPCACH_A_CONTROL_CIOVFIEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CIOVFIEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CIOVFIEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CIOVFIEN_SHIFT)

#define SI32_EPCACH_A_CONTROL_CIOVFDEN_MASK  0x00001000
#define SI32_EPCACH_A_CONTROL_CIOVFDEN_SHIFT  12
// Do not request DMA data when a channel intermediate overflow event occurs.
#define SI32_EPCACH_A_CONTROL_CIOVFDEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CIOVFDEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CIOVFDEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CIOVFDEN_SHIFT)
// Request DMA data when a channel intermediate overflow event occurs.
#define SI32_EPCACH_A_CONTROL_CIOVFDEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CIOVFDEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CIOVFDEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CIOVFDEN_SHIFT)

#define SI32_EPCACH_A_CONTROL_CIOVFSEN_MASK  0x00002000
#define SI32_EPCACH_A_CONTROL_CIOVFSEN_SHIFT  13
// Do not send a synchronization signal when a channel intermediate overflow event
// occurs.
#define SI32_EPCACH_A_CONTROL_CIOVFSEN_DISABLED_VALUE  0
#define SI32_EPCACH_A_CONTROL_CIOVFSEN_DISABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CIOVFSEN_DISABLED_VALUE << SI32_EPCACH_A_CONTROL_CIOVFSEN_SHIFT)
// Send a synchronization signal when a channel intermediate overflow occurs.
#define SI32_EPCACH_A_CONTROL_CIOVFSEN_ENABLED_VALUE  1
#define SI32_EPCACH_A_CONTROL_CIOVFSEN_ENABLED_U32 \
   (SI32_EPCACH_A_CONTROL_CIOVFSEN_ENABLED_VALUE << SI32_EPCACH_A_CONTROL_CIOVFSEN_SHIFT)



struct SI32_EPCACH_A_CCAPV_Struct
{
   union
   {
      struct
      {
         // Channel Compare Value
         volatile uint32_t CCAPV_BITS: 18;
                  uint32_t reserved0: 14;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCACH_A_CCAPV_CCAPV_MASK  0x0003FFFF
#define SI32_EPCACH_A_CCAPV_CCAPV_SHIFT  0



struct SI32_EPCACH_A_CCAPVUPD_Struct
{
   union
   {
      struct
      {
         // Channel Compare Update Value
         volatile uint32_t CCAPVUPD_BITS: 18;
                  uint32_t reserved0: 14;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EPCACH_A_CCAPVUPD_CCAPVUPD_MASK  0x0003FFFF
#define SI32_EPCACH_A_CCAPVUPD_CCAPVUPD_SHIFT  0



typedef struct SI32_EPCACH_A_Struct
{
   struct SI32_EPCACH_A_MODE_Struct                MODE           ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_EPCACH_A_CONTROL_Struct             CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
   struct SI32_EPCACH_A_CCAPV_Struct               CCAPV          ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_EPCACH_A_CCAPVUPD_Struct            CCAPVUPD       ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
} SI32_EPCACH_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_EPCACH_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

