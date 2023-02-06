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

#ifndef __SI32_TIMER_A_REGISTERS_H__
#define __SI32_TIMER_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_TIMER_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Low Clock Source
         volatile uint32_t LCLK: 2;
                  uint32_t reserved0: 2;
         // Low Run Master Enable
         volatile uint32_t LMSTREN: 1;
         // Split Mode Enable
         volatile uint32_t SPLITEN: 1;
         // Low Timer Extra Interrupt Enable
         volatile uint32_t LEXIEN: 1;
         // Low Timer Overflow Interrupt Enable
         volatile uint32_t LOVFIEN: 1;
         // Low Timer Mode
         volatile uint32_t LMD: 3;
                  uint32_t reserved1: 1;
         // Low Multi Purpose State Indicator
         volatile uint32_t LSTATE: 1;
         // Run Control Low
         volatile uint32_t LRUN: 1;
         // Low Timer Extra Interrupt Flag
         volatile uint32_t LEXI: 1;
         // Low Timer Overflow Interrupt
         volatile uint32_t LOVFI: 1;
         // High Clock Source
         volatile uint32_t HCLK: 2;
                  uint32_t reserved2: 1;
         // Master Run Control
         volatile uint32_t MSTRUN: 1;
         // High Master Enable
         volatile uint32_t HMSTREN: 1;
         // Timer Debug Mode
         volatile uint32_t DBGMD: 1;
         // High Timer Extra Interrupt Enable
         volatile uint32_t HEXIEN: 1;
         // High Timer Overflow Interrupt Enable
         volatile uint32_t HOVFIEN: 1;
         // High Timer Mode
         volatile uint32_t HMD: 4;
         // High Multi Purpose State Indicator
         volatile uint32_t HSTATE: 1;
         // High Run Control
         volatile uint32_t HRUN: 1;
         // High Timer Extra Interrupt Flag
         volatile uint32_t HEXI: 1;
         // High Timer Overflow Interrupt Flag
         volatile uint32_t HOVFI: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_TIMER_A_CONFIG_LCLK_MASK  0x00000003
#define SI32_TIMER_A_CONFIG_LCLK_SHIFT  0
// Select the APB clock as the timer source.
#define SI32_TIMER_A_CONFIG_LCLK_APB_VALUE  0
#define SI32_TIMER_A_CONFIG_LCLK_APB_U32 \
   (SI32_TIMER_A_CONFIG_LCLK_APB_VALUE << SI32_TIMER_A_CONFIG_LCLK_SHIFT)
// Select the external oscillator clock as the timer source. The external
// oscillator must run slower than one-half the APB clock.
#define SI32_TIMER_A_CONFIG_LCLK_EXTOSCN_VALUE  1
#define SI32_TIMER_A_CONFIG_LCLK_EXTOSCN_U32 \
   (SI32_TIMER_A_CONFIG_LCLK_EXTOSCN_VALUE << SI32_TIMER_A_CONFIG_LCLK_SHIFT)
// Select the dedicated 8-bit prescaler as the timer source.
#define SI32_TIMER_A_CONFIG_LCLK_TIMER_CLKDIV_VALUE  2
#define SI32_TIMER_A_CONFIG_LCLK_TIMER_CLKDIV_U32 \
   (SI32_TIMER_A_CONFIG_LCLK_TIMER_CLKDIV_VALUE << SI32_TIMER_A_CONFIG_LCLK_SHIFT)
// Select falling edges of the CT signal as the timer clock source.
#define SI32_TIMER_A_CONFIG_LCLK_CT_FALLING_EDGE_VALUE  3
#define SI32_TIMER_A_CONFIG_LCLK_CT_FALLING_EDGE_U32 \
   (SI32_TIMER_A_CONFIG_LCLK_CT_FALLING_EDGE_VALUE << SI32_TIMER_A_CONFIG_LCLK_SHIFT)

#define SI32_TIMER_A_CONFIG_LMSTREN_MASK  0x00000010
#define SI32_TIMER_A_CONFIG_LMSTREN_SHIFT  4
// MSTRUN does not need to be set for the low timer to run.
#define SI32_TIMER_A_CONFIG_LMSTREN_DISABLED_VALUE  0
#define SI32_TIMER_A_CONFIG_LMSTREN_DISABLED_U32 \
   (SI32_TIMER_A_CONFIG_LMSTREN_DISABLED_VALUE << SI32_TIMER_A_CONFIG_LMSTREN_SHIFT)
// MSTRUN must be set for the low timer to run.
#define SI32_TIMER_A_CONFIG_LMSTREN_ENABLED_VALUE  1
#define SI32_TIMER_A_CONFIG_LMSTREN_ENABLED_U32 \
   (SI32_TIMER_A_CONFIG_LMSTREN_ENABLED_VALUE << SI32_TIMER_A_CONFIG_LMSTREN_SHIFT)

#define SI32_TIMER_A_CONFIG_SPLITEN_MASK  0x00000020
#define SI32_TIMER_A_CONFIG_SPLITEN_SHIFT  5
// The timer operates as a single 32-bit timer controlled by the high timer fields.
#define SI32_TIMER_A_CONFIG_SPLITEN_DISABLED_VALUE  0
#define SI32_TIMER_A_CONFIG_SPLITEN_DISABLED_U32 \
   (SI32_TIMER_A_CONFIG_SPLITEN_DISABLED_VALUE << SI32_TIMER_A_CONFIG_SPLITEN_SHIFT)
// The timer operates as two independent 16-bit timers.
#define SI32_TIMER_A_CONFIG_SPLITEN_ENABLED_VALUE  1
#define SI32_TIMER_A_CONFIG_SPLITEN_ENABLED_U32 \
   (SI32_TIMER_A_CONFIG_SPLITEN_ENABLED_VALUE << SI32_TIMER_A_CONFIG_SPLITEN_SHIFT)

#define SI32_TIMER_A_CONFIG_LEXIEN_MASK  0x00000040
#define SI32_TIMER_A_CONFIG_LEXIEN_SHIFT  6
// The state of the LEXI flag does not affect the low timer interrupt.
#define SI32_TIMER_A_CONFIG_LEXIEN_DISABLED_VALUE  0
#define SI32_TIMER_A_CONFIG_LEXIEN_DISABLED_U32 \
   (SI32_TIMER_A_CONFIG_LEXIEN_DISABLED_VALUE << SI32_TIMER_A_CONFIG_LEXIEN_SHIFT)
// A low timer interrupt request is generated if LEXI is set to 1.
#define SI32_TIMER_A_CONFIG_LEXIEN_ENABLED_VALUE  1
#define SI32_TIMER_A_CONFIG_LEXIEN_ENABLED_U32 \
   (SI32_TIMER_A_CONFIG_LEXIEN_ENABLED_VALUE << SI32_TIMER_A_CONFIG_LEXIEN_SHIFT)

#define SI32_TIMER_A_CONFIG_LOVFIEN_MASK  0x00000080
#define SI32_TIMER_A_CONFIG_LOVFIEN_SHIFT  7
// The state of LOVFI does not affect the low timer interrupt.
#define SI32_TIMER_A_CONFIG_LOVFIEN_DISABLED_VALUE  0
#define SI32_TIMER_A_CONFIG_LOVFIEN_DISABLED_U32 \
   (SI32_TIMER_A_CONFIG_LOVFIEN_DISABLED_VALUE << SI32_TIMER_A_CONFIG_LOVFIEN_SHIFT)
// A low timer interrupt request is generated if LOVFI = 1.
#define SI32_TIMER_A_CONFIG_LOVFIEN_ENABLED_VALUE  1
#define SI32_TIMER_A_CONFIG_LOVFIEN_ENABLED_U32 \
   (SI32_TIMER_A_CONFIG_LOVFIEN_ENABLED_VALUE << SI32_TIMER_A_CONFIG_LOVFIEN_SHIFT)

#define SI32_TIMER_A_CONFIG_LMD_MASK  0x00000700
#define SI32_TIMER_A_CONFIG_LMD_SHIFT  8
// The low timer is in Auto-Reload Mode.
#define SI32_TIMER_A_CONFIG_LMD_AUTO_RELOAD_VALUE  0
#define SI32_TIMER_A_CONFIG_LMD_AUTO_RELOAD_U32 \
   (SI32_TIMER_A_CONFIG_LMD_AUTO_RELOAD_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)
// The low timer is in Up/Down Count Mode.
#define SI32_TIMER_A_CONFIG_LMD_UP_DOWN_VALUE  1
#define SI32_TIMER_A_CONFIG_LMD_UP_DOWN_U32 \
   (SI32_TIMER_A_CONFIG_LMD_UP_DOWN_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)
// The low timer is in Falling Edge Capture Mode.
#define SI32_TIMER_A_CONFIG_LMD_FALL_CAPTURE_VALUE  2
#define SI32_TIMER_A_CONFIG_LMD_FALL_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_LMD_FALL_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)
// The low timer is in Rising Edge Capture Mode.
#define SI32_TIMER_A_CONFIG_LMD_RISE_CAPTURE_VALUE  3
#define SI32_TIMER_A_CONFIG_LMD_RISE_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_LMD_RISE_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)
// The low timer is in Low Time Capture Mode.
#define SI32_TIMER_A_CONFIG_LMD_LOW_CAPTURE_VALUE  4
#define SI32_TIMER_A_CONFIG_LMD_LOW_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_LMD_LOW_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)
// The low timer is in High Time Capture Mode.
#define SI32_TIMER_A_CONFIG_LMD_HIGH_CAPTURE_VALUE  5
#define SI32_TIMER_A_CONFIG_LMD_HIGH_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_LMD_HIGH_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)
// The low timer is in Duty Cycle Capture Mode.
#define SI32_TIMER_A_CONFIG_LMD_DC_CAPTURE_VALUE  6
#define SI32_TIMER_A_CONFIG_LMD_DC_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_LMD_DC_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)
// The low timer is in Oneshot Mode.
#define SI32_TIMER_A_CONFIG_LMD_ONESHOT_VALUE  7
#define SI32_TIMER_A_CONFIG_LMD_ONESHOT_U32 \
   (SI32_TIMER_A_CONFIG_LMD_ONESHOT_VALUE << SI32_TIMER_A_CONFIG_LMD_SHIFT)

#define SI32_TIMER_A_CONFIG_LSTATE_MASK  0x00001000
#define SI32_TIMER_A_CONFIG_LSTATE_SHIFT  12
#define SI32_TIMER_A_CONFIG_LSTATE_NOT_SET_VALUE  0
#define SI32_TIMER_A_CONFIG_LSTATE_NOT_SET_U32 \
   (SI32_TIMER_A_CONFIG_LSTATE_NOT_SET_VALUE << SI32_TIMER_A_CONFIG_LSTATE_SHIFT)
#define SI32_TIMER_A_CONFIG_LSTATE_SET_VALUE  1
#define SI32_TIMER_A_CONFIG_LSTATE_SET_U32 \
   (SI32_TIMER_A_CONFIG_LSTATE_SET_VALUE << SI32_TIMER_A_CONFIG_LSTATE_SHIFT)

#define SI32_TIMER_A_CONFIG_LRUN_MASK  0x00002000
#define SI32_TIMER_A_CONFIG_LRUN_SHIFT  13
// Stop the low timer if split mode is enabled (SPLITEN = 1).
#define SI32_TIMER_A_CONFIG_LRUN_STOP_VALUE  0
#define SI32_TIMER_A_CONFIG_LRUN_STOP_U32 \
   (SI32_TIMER_A_CONFIG_LRUN_STOP_VALUE << SI32_TIMER_A_CONFIG_LRUN_SHIFT)
// The low timer runs if split mode is enabled (SPLITEN = 1) and (LMSTREN = 0 or
// MSTRUN = 1 in Timer 0).
#define SI32_TIMER_A_CONFIG_LRUN_START_VALUE  1
#define SI32_TIMER_A_CONFIG_LRUN_START_U32 \
   (SI32_TIMER_A_CONFIG_LRUN_START_VALUE << SI32_TIMER_A_CONFIG_LRUN_SHIFT)

#define SI32_TIMER_A_CONFIG_LEXI_MASK  0x00004000
#define SI32_TIMER_A_CONFIG_LEXI_SHIFT  14
// Read: A low timer extra interrupt is not pending. Write: Clear the interrupt.
#define SI32_TIMER_A_CONFIG_LEXI_NOT_SET_VALUE  0
#define SI32_TIMER_A_CONFIG_LEXI_NOT_SET_U32 \
   (SI32_TIMER_A_CONFIG_LEXI_NOT_SET_VALUE << SI32_TIMER_A_CONFIG_LEXI_SHIFT)
// Read: Indicates the low 16-bit timer has been captured, reloaded with all 1's
// when counting down, or the timer matched the capture register in PWM mode. This
// interrupt flag can be set by hardware in all modes except Auto-Reload and
// Toggle. This flag is not set by hardware when split mode is disabled (SPLITEN =
// 0). Write: Force a low timer extra interrupt.
#define SI32_TIMER_A_CONFIG_LEXI_SET_VALUE  1
#define SI32_TIMER_A_CONFIG_LEXI_SET_U32 \
   (SI32_TIMER_A_CONFIG_LEXI_SET_VALUE << SI32_TIMER_A_CONFIG_LEXI_SHIFT)

#define SI32_TIMER_A_CONFIG_LOVFI_MASK  0x00008000
#define SI32_TIMER_A_CONFIG_LOVFI_SHIFT  15
// Read: A low timer overflow interrupt is not pending. Write: Clear the interrupt.
#define SI32_TIMER_A_CONFIG_LOVFI_NOT_SET_VALUE  0
#define SI32_TIMER_A_CONFIG_LOVFI_NOT_SET_U32 \
   (SI32_TIMER_A_CONFIG_LOVFI_NOT_SET_VALUE << SI32_TIMER_A_CONFIG_LOVFI_SHIFT)
// Read: The low 16-bit timer has wrapped or reloaded after reaching all 1's. This
// bit is set by the module regardless of the state of SPLITEN and can be set in
// all modes. Write: Force a low timer overflow interrupt.
#define SI32_TIMER_A_CONFIG_LOVFI_SET_VALUE  1
#define SI32_TIMER_A_CONFIG_LOVFI_SET_U32 \
   (SI32_TIMER_A_CONFIG_LOVFI_SET_VALUE << SI32_TIMER_A_CONFIG_LOVFI_SHIFT)

#define SI32_TIMER_A_CONFIG_HCLK_MASK  0x00030000
#define SI32_TIMER_A_CONFIG_HCLK_SHIFT  16
// Select the APB clock as the timer source.
#define SI32_TIMER_A_CONFIG_HCLK_APB_VALUE  0
#define SI32_TIMER_A_CONFIG_HCLK_APB_U32 \
   (SI32_TIMER_A_CONFIG_HCLK_APB_VALUE << SI32_TIMER_A_CONFIG_HCLK_SHIFT)
// Select the external oscillator clock as the timer source. The external
// oscillator must run slower than one-half the APB clock.
#define SI32_TIMER_A_CONFIG_HCLK_EXTOSCN_VALUE  1
#define SI32_TIMER_A_CONFIG_HCLK_EXTOSCN_U32 \
   (SI32_TIMER_A_CONFIG_HCLK_EXTOSCN_VALUE << SI32_TIMER_A_CONFIG_HCLK_SHIFT)
// Select the dedicated 8-bit prescaler as the timer source.
#define SI32_TIMER_A_CONFIG_HCLK_TIMER_CLKDIV_VALUE  2
#define SI32_TIMER_A_CONFIG_HCLK_TIMER_CLKDIV_U32 \
   (SI32_TIMER_A_CONFIG_HCLK_TIMER_CLKDIV_VALUE << SI32_TIMER_A_CONFIG_HCLK_SHIFT)
// Select falling edges of the CT signal as the timer clock source.
#define SI32_TIMER_A_CONFIG_HCLK_CT_FALLING_EDGE_VALUE  3
#define SI32_TIMER_A_CONFIG_HCLK_CT_FALLING_EDGE_U32 \
   (SI32_TIMER_A_CONFIG_HCLK_CT_FALLING_EDGE_VALUE << SI32_TIMER_A_CONFIG_HCLK_SHIFT)

#define SI32_TIMER_A_CONFIG_MSTRUN_MASK  0x00080000
#define SI32_TIMER_A_CONFIG_MSTRUN_SHIFT  19
// Disable the master run control for all timers.
#define SI32_TIMER_A_CONFIG_MSTRUN_STOP_VALUE  0
#define SI32_TIMER_A_CONFIG_MSTRUN_STOP_U32 \
   (SI32_TIMER_A_CONFIG_MSTRUN_STOP_VALUE << SI32_TIMER_A_CONFIG_MSTRUN_SHIFT)
// Enable the master run control for all timers.
#define SI32_TIMER_A_CONFIG_MSTRUN_START_VALUE  1
#define SI32_TIMER_A_CONFIG_MSTRUN_START_U32 \
   (SI32_TIMER_A_CONFIG_MSTRUN_START_VALUE << SI32_TIMER_A_CONFIG_MSTRUN_SHIFT)

#define SI32_TIMER_A_CONFIG_HMSTREN_MASK  0x00100000
#define SI32_TIMER_A_CONFIG_HMSTREN_SHIFT  20
// MSTRUN does not need to be set for the timer to run.
#define SI32_TIMER_A_CONFIG_HMSTREN_DISABLED_VALUE  0
#define SI32_TIMER_A_CONFIG_HMSTREN_DISABLED_U32 \
   (SI32_TIMER_A_CONFIG_HMSTREN_DISABLED_VALUE << SI32_TIMER_A_CONFIG_HMSTREN_SHIFT)
// MSTRUN must be set for the timer to run.
#define SI32_TIMER_A_CONFIG_HMSTREN_ENABLED_VALUE  1
#define SI32_TIMER_A_CONFIG_HMSTREN_ENABLED_U32 \
   (SI32_TIMER_A_CONFIG_HMSTREN_ENABLED_VALUE << SI32_TIMER_A_CONFIG_HMSTREN_SHIFT)

#define SI32_TIMER_A_CONFIG_DBGMD_MASK  0x00200000
#define SI32_TIMER_A_CONFIG_DBGMD_SHIFT  21
// The timer will continue to operate while the core is halted in debug mode.
#define SI32_TIMER_A_CONFIG_DBGMD_RUN_VALUE  0
#define SI32_TIMER_A_CONFIG_DBGMD_RUN_U32 \
   (SI32_TIMER_A_CONFIG_DBGMD_RUN_VALUE << SI32_TIMER_A_CONFIG_DBGMD_SHIFT)
// A debug breakpoint will cause the Timer to halt.
#define SI32_TIMER_A_CONFIG_DBGMD_HALT_VALUE  1
#define SI32_TIMER_A_CONFIG_DBGMD_HALT_U32 \
   (SI32_TIMER_A_CONFIG_DBGMD_HALT_VALUE << SI32_TIMER_A_CONFIG_DBGMD_SHIFT)

#define SI32_TIMER_A_CONFIG_HEXIEN_MASK  0x00400000
#define SI32_TIMER_A_CONFIG_HEXIEN_SHIFT  22
// The state of the HEXI flag does not affect the high timer interrupt.
#define SI32_TIMER_A_CONFIG_HEXIEN_DISABLED_VALUE  0
#define SI32_TIMER_A_CONFIG_HEXIEN_DISABLED_U32 \
   (SI32_TIMER_A_CONFIG_HEXIEN_DISABLED_VALUE << SI32_TIMER_A_CONFIG_HEXIEN_SHIFT)
// A high timer interrupt request is generated if HEXI is set to 1.
#define SI32_TIMER_A_CONFIG_HEXIEN_ENABLED_VALUE  1
#define SI32_TIMER_A_CONFIG_HEXIEN_ENABLED_U32 \
   (SI32_TIMER_A_CONFIG_HEXIEN_ENABLED_VALUE << SI32_TIMER_A_CONFIG_HEXIEN_SHIFT)

#define SI32_TIMER_A_CONFIG_HOVFIEN_MASK  0x00800000
#define SI32_TIMER_A_CONFIG_HOVFIEN_SHIFT  23
// The state of HOVFI does not affect the high timer interrupt.
#define SI32_TIMER_A_CONFIG_HOVFIEN_DISABLED_VALUE  0
#define SI32_TIMER_A_CONFIG_HOVFIEN_DISABLED_U32 \
   (SI32_TIMER_A_CONFIG_HOVFIEN_DISABLED_VALUE << SI32_TIMER_A_CONFIG_HOVFIEN_SHIFT)
// A high timer interrupt request is generated if HOVFI is set to 1.
#define SI32_TIMER_A_CONFIG_HOVFIEN_ENABLED_VALUE  1
#define SI32_TIMER_A_CONFIG_HOVFIEN_ENABLED_U32 \
   (SI32_TIMER_A_CONFIG_HOVFIEN_ENABLED_VALUE << SI32_TIMER_A_CONFIG_HOVFIEN_SHIFT)

#define SI32_TIMER_A_CONFIG_HMD_MASK  0x0F000000
#define SI32_TIMER_A_CONFIG_HMD_SHIFT  24
// The high 16-bit timer or entire 32-bit timer is in Auto-Reload Mode.
#define SI32_TIMER_A_CONFIG_HMD_AUTO_RELOAD_VALUE  0
#define SI32_TIMER_A_CONFIG_HMD_AUTO_RELOAD_U32 \
   (SI32_TIMER_A_CONFIG_HMD_AUTO_RELOAD_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in Up/Down Count Mode.
#define SI32_TIMER_A_CONFIG_HMD_UP_DOWN_VALUE  1
#define SI32_TIMER_A_CONFIG_HMD_UP_DOWN_U32 \
   (SI32_TIMER_A_CONFIG_HMD_UP_DOWN_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in Falling Edge Capture Mode.
#define SI32_TIMER_A_CONFIG_HMD_FALL_CAPTURE_VALUE  2
#define SI32_TIMER_A_CONFIG_HMD_FALL_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_HMD_FALL_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in Rising Edge Capture Mode.
#define SI32_TIMER_A_CONFIG_HMD_RISE_CAPTURE_VALUE  3
#define SI32_TIMER_A_CONFIG_HMD_RISE_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_HMD_RISE_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in Low Time Capture Mode.
#define SI32_TIMER_A_CONFIG_HMD_LOW_CAPTURE_VALUE  4
#define SI32_TIMER_A_CONFIG_HMD_LOW_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_HMD_LOW_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in High Time Capture Mode.
#define SI32_TIMER_A_CONFIG_HMD_HIGH_CAPTURE_VALUE  5
#define SI32_TIMER_A_CONFIG_HMD_HIGH_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_HMD_HIGH_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in Duty Cycle Capture Mode.
#define SI32_TIMER_A_CONFIG_HMD_DC_CAPTURE_VALUE  6
#define SI32_TIMER_A_CONFIG_HMD_DC_CAPTURE_U32 \
   (SI32_TIMER_A_CONFIG_HMD_DC_CAPTURE_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in Oneshot Mode.
#define SI32_TIMER_A_CONFIG_HMD_ONESHOT_VALUE  7
#define SI32_TIMER_A_CONFIG_HMD_ONESHOT_U32 \
   (SI32_TIMER_A_CONFIG_HMD_ONESHOT_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in Square Wave Output Mode.
#define SI32_TIMER_A_CONFIG_HMD_TOGGLE_VALUE  8
#define SI32_TIMER_A_CONFIG_HMD_TOGGLE_U32 \
   (SI32_TIMER_A_CONFIG_HMD_TOGGLE_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)
// The high 16-bit timer or entire 32-bit timer is in PWM Mode.
#define SI32_TIMER_A_CONFIG_HMD_PWM_VALUE  9
#define SI32_TIMER_A_CONFIG_HMD_PWM_U32 \
   (SI32_TIMER_A_CONFIG_HMD_PWM_VALUE << SI32_TIMER_A_CONFIG_HMD_SHIFT)

#define SI32_TIMER_A_CONFIG_HSTATE_MASK  0x10000000
#define SI32_TIMER_A_CONFIG_HSTATE_SHIFT  28
#define SI32_TIMER_A_CONFIG_HSTATE_NOT_SET_VALUE  0
#define SI32_TIMER_A_CONFIG_HSTATE_NOT_SET_U32 \
   (SI32_TIMER_A_CONFIG_HSTATE_NOT_SET_VALUE << SI32_TIMER_A_CONFIG_HSTATE_SHIFT)
#define SI32_TIMER_A_CONFIG_HSTATE_SET_VALUE  1
#define SI32_TIMER_A_CONFIG_HSTATE_SET_U32 \
   (SI32_TIMER_A_CONFIG_HSTATE_SET_VALUE << SI32_TIMER_A_CONFIG_HSTATE_SHIFT)

#define SI32_TIMER_A_CONFIG_HRUN_MASK  0x20000000
#define SI32_TIMER_A_CONFIG_HRUN_SHIFT  29
// Stop the high timer or entire 32-bit timer.
#define SI32_TIMER_A_CONFIG_HRUN_STOP_VALUE  0
#define SI32_TIMER_A_CONFIG_HRUN_STOP_U32 \
   (SI32_TIMER_A_CONFIG_HRUN_STOP_VALUE << SI32_TIMER_A_CONFIG_HRUN_SHIFT)
// The high timer runs if HMSTREN = 0 or MSTRUN (in Timer 0) = 1. The full 32-bit
// timer runs if split mode is disabled and (HMSTREN = 0 or MSTRUN = 1).
#define SI32_TIMER_A_CONFIG_HRUN_START_VALUE  1
#define SI32_TIMER_A_CONFIG_HRUN_START_U32 \
   (SI32_TIMER_A_CONFIG_HRUN_START_VALUE << SI32_TIMER_A_CONFIG_HRUN_SHIFT)

#define SI32_TIMER_A_CONFIG_HEXI_MASK  0x40000000
#define SI32_TIMER_A_CONFIG_HEXI_SHIFT  30
// Read: A high timer extra interrupt is not pending. Write: Clear the interrupt.
#define SI32_TIMER_A_CONFIG_HEXI_NOT_SET_VALUE  0
#define SI32_TIMER_A_CONFIG_HEXI_NOT_SET_U32 \
   (SI32_TIMER_A_CONFIG_HEXI_NOT_SET_VALUE << SI32_TIMER_A_CONFIG_HEXI_SHIFT)
// Read: Indicates the high 16-bit timer (or 32-bit timer if SPLITEN = 0) has been
// captured, reloaded with all 1's when counting down, or the timer matched the
// capture register in PWM mode. This interrupt flag can be set by the timer module
// in all modes except Auto-Reload and Toggle. Write: Force a high timer extra
// interrupt.
#define SI32_TIMER_A_CONFIG_HEXI_SET_VALUE  1
#define SI32_TIMER_A_CONFIG_HEXI_SET_U32 \
   (SI32_TIMER_A_CONFIG_HEXI_SET_VALUE << SI32_TIMER_A_CONFIG_HEXI_SHIFT)

#define SI32_TIMER_A_CONFIG_HOVFI_MASK  0x80000000
#define SI32_TIMER_A_CONFIG_HOVFI_SHIFT  31
// Read: A high timer overflow interrupt is not pending. Write: Clear the
// interrupt.
#define SI32_TIMER_A_CONFIG_HOVFI_NOT_SET_VALUE  0U
#define SI32_TIMER_A_CONFIG_HOVFI_NOT_SET_U32 \
   (SI32_TIMER_A_CONFIG_HOVFI_NOT_SET_VALUE << SI32_TIMER_A_CONFIG_HOVFI_SHIFT)
// Read: If split mode is enabled (SPLITEN = 1), this value indicates the high
// 16-bit timer has wrapped or reloaded after reaching all 1's. If split mode is
// disabled (SPLITEN = 0), this value indicates the 32-bit timer has wrapped or
// reloaded after reaching all 1's. The timer module can set this bit in all modes.
// Write: Force a high timer overflow interrupt.
#define SI32_TIMER_A_CONFIG_HOVFI_SET_VALUE  1U
#define SI32_TIMER_A_CONFIG_HOVFI_SET_U32 \
   (SI32_TIMER_A_CONFIG_HOVFI_SET_VALUE << SI32_TIMER_A_CONFIG_HOVFI_SHIFT)



struct SI32_TIMER_A_CLKDIV_Struct
{
   union
   {
      struct
      {
         // Clock Divider Reload Value
         volatile uint8_t CLKDIVRL;
                  uint32_t reserved0: 8;
         // Clock Divider Counter
         volatile uint8_t CLKDIVCT;
                  uint32_t reserved1: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_TIMER_A_CLKDIV_CLKDIVRL_MASK  0x000000FF
#define SI32_TIMER_A_CLKDIV_CLKDIVRL_SHIFT  0

#define SI32_TIMER_A_CLKDIV_CLKDIVCT_MASK  0x00FF0000
#define SI32_TIMER_A_CLKDIV_CLKDIVCT_SHIFT  16



struct SI32_TIMER_A_COUNT_Struct
{
   union
   {
      struct
      {
         // Low Timer Count
         volatile uint16_t LCOUNT;
         // High Timer Count
         volatile uint16_t HCOUNT;
      };
      volatile uint32_t U32;
   };
};

#define SI32_TIMER_A_COUNT_LCOUNT_MASK  0x0000FFFF
#define SI32_TIMER_A_COUNT_LCOUNT_SHIFT  0

#define SI32_TIMER_A_COUNT_HCOUNT_MASK  0xFFFF0000
#define SI32_TIMER_A_COUNT_HCOUNT_SHIFT  16



struct SI32_TIMER_A_CAPTURE_Struct
{
   union
   {
      struct
      {
         // Low Timer Capture/Reload
         volatile uint16_t LCCR;
         // High Timer Capture/Reload
         volatile uint16_t HCCR;
      };
      volatile uint32_t U32;
   };
};

#define SI32_TIMER_A_CAPTURE_LCCR_MASK  0x0000FFFF
#define SI32_TIMER_A_CAPTURE_LCCR_SHIFT  0

#define SI32_TIMER_A_CAPTURE_HCCR_MASK  0xFFFF0000
#define SI32_TIMER_A_CAPTURE_HCCR_SHIFT  16



typedef struct SI32_TIMER_A_Struct
{
   struct SI32_TIMER_A_CONFIG_Struct               CONFIG         ; // Base Address + 0x0
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved0;
   struct SI32_TIMER_A_CLKDIV_Struct               CLKDIV         ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_TIMER_A_COUNT_Struct                COUNT          ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_TIMER_A_CAPTURE_Struct              CAPTURE        ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
} SI32_TIMER_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_TIMER_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

