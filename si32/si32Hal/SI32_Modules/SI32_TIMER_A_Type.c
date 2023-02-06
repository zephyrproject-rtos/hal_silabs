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
/// @file SI32_TIMER_A_Type.c
//
// Script: 0.59
// HAL Source: 0.5
// Version: 9

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_TIMER_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_TIMER_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_initialize(
   SI32_TIMER_A_Type * basePointer,
   // Write to CONFIG register.
   uint32_t config,
   // Write to CLKDIV register.
   uint32_t clkdiv,
   // Write to COUNT register.
   uint32_t count,
   // Write to CAPTURE register.
   uint32_t capture)
{
   //{{
   basePointer->CONFIG.U32  = config;
   basePointer->CLKDIV.U32  = clkdiv;
   basePointer->COUNT.U32   = count;
   basePointer->CAPTURE.U32 = capture;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_write_config
//
// Writes to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_write_config(
   SI32_TIMER_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_read_config
//
// Reads CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_read_config(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_clock_source_apb_clock
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_clock_source_apb_clock(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_APB_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_clock_source_external_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_clock_source_external_oscillator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_EXTOSCN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_clock_source_timer_clock_divider
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_clock_source_timer_clock_divider(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_TIMER_CLKDIV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_clock_source_external_ct_pin
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_clock_source_external_ct_pin(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_CT_FALLING_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_enable_low_clock_master_synchronization
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_enable_low_clock_master_synchronization(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMSTREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_disable_low_clock_master_synchronization
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_disable_low_clock_master_synchronization(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMSTREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_split_timer_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_split_timer_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_SPLITEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_single_timer_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_single_timer_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_SPLITEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_enable_low_extra_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_enable_low_extra_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LEXIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_disable_low_extra_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_disable_low_extra_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LEXIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_enable_low_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_enable_low_overflow_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LOVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_disable_low_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_disable_low_overflow_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LOVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_is_low_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_is_low_overflow_interrupt_enabled(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.LOVFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_auto_reload_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_auto_reload_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_AUTO_RELOAD_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_up_down_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_up_down_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_UP_DOWN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_falling_edge_capture_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_falling_edge_capture_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_FALL_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_rising_edge_capture_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_rising_edge_capture_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_RISE_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_capture_low_time_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_capture_low_time_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_LOW_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_capture_high_time_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_capture_high_time_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_HIGH_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_duty_cycle_capture_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_duty_cycle_capture_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_DC_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_low_oneshot_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_low_oneshot_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_ONESHOT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_low_state_indicator
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_low_state_indicator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LSTATE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_clear_low_state_indicator
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_clear_low_state_indicator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LSTATE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_get_low_state_indicator
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_get_low_state_indicator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.LSTATE);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_start_low_timer
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_start_low_timer(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LRUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_stop_low_timer
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_stop_low_timer(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LRUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_is_low_extra_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_is_low_extra_interrupt_pending(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (bool) (basePointer->CONFIG.LEXI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_clear_low_extra_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_clear_low_extra_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LEXI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_is_low_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_is_low_overflow_interrupt_pending(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (bool) (basePointer->CONFIG.LOVFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_clear_low_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_clear_low_overflow_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LOVFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_clock_source_apb_clock
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_clock_source_apb_clock(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_APB_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_clock_source_external_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_clock_source_external_oscillator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_EXTOSCN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_clock_source_timer_clock_divider
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_clock_source_timer_clock_divider(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_TIMER_CLKDIV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_clock_source_external_ct_pin
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_clock_source_external_ct_pin(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_CT_FALLING_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_start_master_run_control
//
// Only supported in Timer0.
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_start_master_run_control(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_MSTRUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_stop_master_run_control
//
// Only supported in Timer0.
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_stop_master_run_control(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_MSTRUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_enable_high_clock_master_synchronization
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_enable_high_clock_master_synchronization(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMSTREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_disable_high_clock_master_synchronization
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_disable_high_clock_master_synchronization(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMSTREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_enable_stall_in_debug_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_disable_stall_in_debug_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_enable_high_extra_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_enable_high_extra_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HEXIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_disable_high_extra_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_disable_high_extra_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HEXIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_enable_high_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_enable_high_overflow_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HOVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_disable_high_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_disable_high_overflow_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HOVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_is_high_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_is_high_overflow_interrupt_enabled(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.HOVFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_auto_reload_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_auto_reload_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_AUTO_RELOAD_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_up_down_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_up_down_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_UP_DOWN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_falling_edge_capture_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_falling_edge_capture_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_FALL_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_rising_edge_capture_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_rising_edge_capture_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_RISE_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_capture_low_time_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_capture_low_time_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_LOW_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_capture_high_time_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_capture_high_time_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_HIGH_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_duty_cycle_capture_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_duty_cycle_capture_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_DC_CAPTURE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_oneshot_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_oneshot_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_ONESHOT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_square_wave_output_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_square_wave_output_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
	basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_TOGGLE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_select_high_pwm_mode
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_select_high_pwm_mode(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_PWM_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_high_state_indicator
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_high_state_indicator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HSTATE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_clear_high_state_indicator
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_clear_high_state_indicator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HSTATE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_get_high_state_indicator
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_get_high_state_indicator(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (bool) (basePointer->CONFIG.HSTATE);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_start_high_timer
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_start_high_timer(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HRUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_stop_high_timer
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_stop_high_timer(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HRUN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_is_high_extra_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_is_high_extra_interrupt_pending(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.HEXI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_clear_high_extra_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_clear_high_extra_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HEXI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_is_high_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_TIMER_A_is_high_overflow_interrupt_pending(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.HOVFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_clear_high_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_clear_high_overflow_interrupt(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HOVFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_write_clkdiv
//
// Writes to CLKDIV register.
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_write_clkdiv(
   SI32_TIMER_A_Type * basePointer,
   uint32_t clkdiv)
{
   //{{
   basePointer->CLKDIV.U32 = clkdiv;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_read_clkdiv
//
// Reads CLKDIV register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_read_clkdiv(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return basePointer->CLKDIV.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_clock_divider_counter
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_clock_divider_counter(
   SI32_TIMER_A_Type * basePointer,
   uint32_t counter)
{
   assert(counter < 256);   // counter < 2^8
   //{{
   basePointer->CLKDIV.CLKDIVCT = counter;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_clock_divider_reload
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_clock_divider_reload(
   SI32_TIMER_A_Type * basePointer,
   uint32_t reload)
{
   assert(reload < 256);   // reload < 2^8
   //{{
   basePointer->CLKDIV.CLKDIVRL = reload;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_write_count
//
// Writes to COUNT register.
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_write_count(
   SI32_TIMER_A_Type * basePointer,
   uint32_t count)
{
   //{{
   basePointer->COUNT.U32 = count;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_read_count
//
// Reads COUNT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_read_count(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return basePointer->COUNT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_high_count
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_high_count(
   SI32_TIMER_A_Type * basePointer,
   uint32_t count)
{
   assert(count < 65536);   // count < 2^16
   //{{
   basePointer->COUNT.HCOUNT = count;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_get_high_count
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_get_high_count(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (basePointer->COUNT.HCOUNT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_low_count
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_low_count(
   SI32_TIMER_A_Type * basePointer,
   uint32_t count)
{
   assert(count < 65536);   // count < 2^16
   //{{
   basePointer->COUNT.LCOUNT = count;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_get_low_count
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_get_low_count(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (basePointer->COUNT.LCOUNT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_write_capture
//
// Writes to CAPTURE register.
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_write_capture(
   SI32_TIMER_A_Type * basePointer,
   uint32_t capture)
{
   //{{
   basePointer->CAPTURE.U32 = capture;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_read_capture
//
// Reads CAPTURE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_read_capture(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return basePointer->CAPTURE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_high_reload
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_high_reload(
   SI32_TIMER_A_Type * basePointer,
   uint32_t reload)
{
   assert(reload < 65536);   // reload < 2^16
   //{{
   basePointer->CAPTURE.HCCR = reload;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_get_high_capture
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_get_high_capture(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (basePointer->CAPTURE.HCCR);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_set_low_reload
//
//-----------------------------------------------------------------------------
void
_SI32_TIMER_A_set_low_reload(
   SI32_TIMER_A_Type * basePointer,
   uint32_t reload)
{
   assert(reload < 65536);   // reload < 2^16
   //{{
   basePointer->CAPTURE.LCCR = reload;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_TIMER_A_get_low_capture
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_TIMER_A_get_low_capture(
   SI32_TIMER_A_Type * basePointer)
{
   //{{
   return (basePointer->CAPTURE.LCCR);
   //}}
}


//-eof--------------------------------------------------------------------------
