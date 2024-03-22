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
// Script: 0.57
// Version: 1

#ifndef __SI32_PCACH_A_REGISTERS_H__
#define __SI32_PCACH_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_PCACH_A_MODE_Struct
{
   union
   {
      struct
      {
         // Channel Output Function Select
         volatile uint32_t COSEL: 2;
         // PWM N-Bit Mode
         volatile uint32_t PWMMD: 4;
                  uint32_t reserved0: 2;
         // Channel Operating Mode
         volatile uint32_t CMD: 3;
                  uint32_t reserved1: 21;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PCACH_A_MODE_COSEL_MASK  0x00000003
#define SI32_PCACH_A_MODE_COSEL_SHIFT  0
// Toggle the channel output at the next capture/compare, overflow, or intermediate
// event.
#define SI32_PCACH_A_MODE_COSEL_TOGGLE_OUTPUT_VALUE  0
#define SI32_PCACH_A_MODE_COSEL_TOGGLE_OUTPUT_U32 \
   (SI32_PCACH_A_MODE_COSEL_TOGGLE_OUTPUT_VALUE << SI32_PCACH_A_MODE_COSEL_SHIFT)
// Set the channel output at the next capture/compare, overflow, or intermediate
// event.
#define SI32_PCACH_A_MODE_COSEL_SET_OUTPUT_VALUE  1
#define SI32_PCACH_A_MODE_COSEL_SET_OUTPUT_U32 \
   (SI32_PCACH_A_MODE_COSEL_SET_OUTPUT_VALUE << SI32_PCACH_A_MODE_COSEL_SHIFT)
// Clear the output at the next capture/compare, overflow, or intermediate event.
#define SI32_PCACH_A_MODE_COSEL_CLEAR_OUTPUT_VALUE  2
#define SI32_PCACH_A_MODE_COSEL_CLEAR_OUTPUT_U32 \
   (SI32_PCACH_A_MODE_COSEL_CLEAR_OUTPUT_VALUE << SI32_PCACH_A_MODE_COSEL_SHIFT)
// Capture/Compare, overflow, or intermediate events do not control the output
// state.
#define SI32_PCACH_A_MODE_COSEL_NO_CHANGE_VALUE  3
#define SI32_PCACH_A_MODE_COSEL_NO_CHANGE_U32 \
   (SI32_PCACH_A_MODE_COSEL_NO_CHANGE_VALUE << SI32_PCACH_A_MODE_COSEL_SHIFT)

#define SI32_PCACH_A_MODE_PWMMD_MASK  0x0000003C
#define SI32_PCACH_A_MODE_PWMMD_SHIFT  2

#define SI32_PCACH_A_MODE_CMD_MASK  0x00000700
#define SI32_PCACH_A_MODE_CMD_SHIFT  8
// Configure the channel for edge-aligned PWM mode.
#define SI32_PCACH_A_MODE_CMD_EDGE_PWM_VALUE  0
#define SI32_PCACH_A_MODE_CMD_EDGE_PWM_U32 \
   (SI32_PCACH_A_MODE_CMD_EDGE_PWM_VALUE << SI32_PCACH_A_MODE_CMD_SHIFT)
// Configure the channel for center-aligned PWM mode.
#define SI32_PCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_VALUE  1
#define SI32_PCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_U32 \
   (SI32_PCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_VALUE << SI32_PCACH_A_MODE_CMD_SHIFT)
// Configure the channel for high-frequency/square-wave mode.
#define SI32_PCACH_A_MODE_CMD_HF_SQUARE_WAVE_VALUE  2
#define SI32_PCACH_A_MODE_CMD_HF_SQUARE_WAVE_U32 \
   (SI32_PCACH_A_MODE_CMD_HF_SQUARE_WAVE_VALUE << SI32_PCACH_A_MODE_CMD_SHIFT)
// Configure the channel for timer/capture mode.
#define SI32_PCACH_A_MODE_CMD_TIMER_CAPTURE_VALUE  3
#define SI32_PCACH_A_MODE_CMD_TIMER_CAPTURE_U32 \
   (SI32_PCACH_A_MODE_CMD_TIMER_CAPTURE_VALUE << SI32_PCACH_A_MODE_CMD_SHIFT)
// Configure the channel for n-bit edge-aligned PWM mode.
#define SI32_PCACH_A_MODE_CMD_N_BIT_PWM_VALUE  4
#define SI32_PCACH_A_MODE_CMD_N_BIT_PWM_U32 \
   (SI32_PCACH_A_MODE_CMD_N_BIT_PWM_VALUE << SI32_PCACH_A_MODE_CMD_SHIFT)



struct SI32_PCACH_A_CONTROL_Struct
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
                  uint32_t reserved0: 4;
         // Capture/Compare Interrupt Enable
         volatile uint32_t CCIEN: 1;
                  uint32_t reserved1: 2;
         // Intermediate Overflow Interrupt Enable
         volatile uint32_t CIOVFIEN: 1;
                  uint32_t reserved2: 20;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PCACH_A_CONTROL_COUTST_MASK  0x00000001
#define SI32_PCACH_A_CONTROL_COUTST_SHIFT  0
// The channel output state is low.
#define SI32_PCACH_A_CONTROL_COUTST_LOW_VALUE  0
#define SI32_PCACH_A_CONTROL_COUTST_LOW_U32 \
   (SI32_PCACH_A_CONTROL_COUTST_LOW_VALUE << SI32_PCACH_A_CONTROL_COUTST_SHIFT)
// The channel output state is high.
#define SI32_PCACH_A_CONTROL_COUTST_HIGH_VALUE  1
#define SI32_PCACH_A_CONTROL_COUTST_HIGH_U32 \
   (SI32_PCACH_A_CONTROL_COUTST_HIGH_VALUE << SI32_PCACH_A_CONTROL_COUTST_SHIFT)

#define SI32_PCACH_A_CONTROL_CPCAPEN_MASK  0x00000002
#define SI32_PCACH_A_CONTROL_CPCAPEN_SHIFT  1
// Disable positive-edge input capture.
#define SI32_PCACH_A_CONTROL_CPCAPEN_DISABLED_VALUE  0
#define SI32_PCACH_A_CONTROL_CPCAPEN_DISABLED_U32 \
   (SI32_PCACH_A_CONTROL_CPCAPEN_DISABLED_VALUE << SI32_PCACH_A_CONTROL_CPCAPEN_SHIFT)
// Enable positive-edge input capture.
#define SI32_PCACH_A_CONTROL_CPCAPEN_ENABLED_VALUE  1
#define SI32_PCACH_A_CONTROL_CPCAPEN_ENABLED_U32 \
   (SI32_PCACH_A_CONTROL_CPCAPEN_ENABLED_VALUE << SI32_PCACH_A_CONTROL_CPCAPEN_SHIFT)

#define SI32_PCACH_A_CONTROL_CNCAPEN_MASK  0x00000004
#define SI32_PCACH_A_CONTROL_CNCAPEN_SHIFT  2
// Disable negative-edge input capture.
#define SI32_PCACH_A_CONTROL_CNCAPEN_DISABLED_VALUE  0
#define SI32_PCACH_A_CONTROL_CNCAPEN_DISABLED_U32 \
   (SI32_PCACH_A_CONTROL_CNCAPEN_DISABLED_VALUE << SI32_PCACH_A_CONTROL_CNCAPEN_SHIFT)
// Enable negative-edge input capture.
#define SI32_PCACH_A_CONTROL_CNCAPEN_ENABLED_VALUE  1
#define SI32_PCACH_A_CONTROL_CNCAPEN_ENABLED_U32 \
   (SI32_PCACH_A_CONTROL_CNCAPEN_ENABLED_VALUE << SI32_PCACH_A_CONTROL_CNCAPEN_SHIFT)

#define SI32_PCACH_A_CONTROL_CUPDCF_MASK  0x00000008
#define SI32_PCACH_A_CONTROL_CUPDCF_SHIFT  3
// A PCA channel register update completed or is not pending.
#define SI32_PCACH_A_CONTROL_CUPDCF_NOT_SET_VALUE  0
#define SI32_PCACH_A_CONTROL_CUPDCF_NOT_SET_U32 \
   (SI32_PCACH_A_CONTROL_CUPDCF_NOT_SET_VALUE << SI32_PCACH_A_CONTROL_CUPDCF_SHIFT)
// A PCA channel register update has not completed and is still pending.
#define SI32_PCACH_A_CONTROL_CUPDCF_SET_VALUE  1
#define SI32_PCACH_A_CONTROL_CUPDCF_SET_U32 \
   (SI32_PCACH_A_CONTROL_CUPDCF_SET_VALUE << SI32_PCACH_A_CONTROL_CUPDCF_SHIFT)

#define SI32_PCACH_A_CONTROL_CCIEN_MASK  0x00000100
#define SI32_PCACH_A_CONTROL_CCIEN_SHIFT  8
// Disable the channel capture/compare interrupt.
#define SI32_PCACH_A_CONTROL_CCIEN_DISABLED_VALUE  0
#define SI32_PCACH_A_CONTROL_CCIEN_DISABLED_U32 \
   (SI32_PCACH_A_CONTROL_CCIEN_DISABLED_VALUE << SI32_PCACH_A_CONTROL_CCIEN_SHIFT)
// Enable the channel capture/compare interrupt.
#define SI32_PCACH_A_CONTROL_CCIEN_ENABLED_VALUE  1
#define SI32_PCACH_A_CONTROL_CCIEN_ENABLED_U32 \
   (SI32_PCACH_A_CONTROL_CCIEN_ENABLED_VALUE << SI32_PCACH_A_CONTROL_CCIEN_SHIFT)

#define SI32_PCACH_A_CONTROL_CIOVFIEN_MASK  0x00000800
#define SI32_PCACH_A_CONTROL_CIOVFIEN_SHIFT  11
// Disable the channel intermediate overflow interrupt.
#define SI32_PCACH_A_CONTROL_CIOVFIEN_DISABLED_VALUE  0
#define SI32_PCACH_A_CONTROL_CIOVFIEN_DISABLED_U32 \
   (SI32_PCACH_A_CONTROL_CIOVFIEN_DISABLED_VALUE << SI32_PCACH_A_CONTROL_CIOVFIEN_SHIFT)
// Enable the channel intermediate overflow interrupt.
#define SI32_PCACH_A_CONTROL_CIOVFIEN_ENABLED_VALUE  1
#define SI32_PCACH_A_CONTROL_CIOVFIEN_ENABLED_U32 \
   (SI32_PCACH_A_CONTROL_CIOVFIEN_ENABLED_VALUE << SI32_PCACH_A_CONTROL_CIOVFIEN_SHIFT)



struct SI32_PCACH_A_CCAPV_Struct
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

#define SI32_PCACH_A_CCAPV_CCAPV_MASK  0x0003FFFF
#define SI32_PCACH_A_CCAPV_CCAPV_SHIFT  0



struct SI32_PCACH_A_CCAPVUPD_Struct
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

#define SI32_PCACH_A_CCAPVUPD_CCAPVUPD_MASK  0x0003FFFF
#define SI32_PCACH_A_CCAPVUPD_CCAPVUPD_SHIFT  0



typedef struct SI32_PCACH_A_Struct
{
   struct SI32_PCACH_A_MODE_Struct                 MODE           ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_PCACH_A_CONTROL_Struct              CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
   struct SI32_PCACH_A_CCAPV_Struct                CCAPV          ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_PCACH_A_CCAPVUPD_Struct             CCAPVUPD       ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
} SI32_PCACH_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PCACH_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

