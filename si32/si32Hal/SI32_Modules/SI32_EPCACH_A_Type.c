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
/// @file SI32_EPCACH_A_Type.c
//
// Script: 0.58
// HAL Source: 0.1
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_EPCACH_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_initialize(
   SI32_EPCACH_A_Type * basePointer,
   // Write to MODE register.
   uint32_t mode,
   // Write to CONTROL register.
   uint32_t control,
   // Write to CCAPV register.
   uint32_t ccapv,
   // Write to CCAPVUPD register.
   uint32_t ccapvupd)
{
   //{{
   basePointer->MODE.U32 = mode;
   basePointer->CONTROL.U32 = control;
   basePointer->CCAPV.U32 = ccapv;
   basePointer->CCAPVUPD.U32 = ccapvupd;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_write_mode
//
// Write to MODE register.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_write_mode(
   SI32_EPCACH_A_Type * basePointer,
   uint32_t mode)
{
   //{{
   basePointer->MODE.U32 = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_read_mode
//
// Read MODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCACH_A_read_mode(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_output_mode_toggle
//
// Toggle channel output at the next capture/compare event.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_output_mode_toggle(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.COSEL = SI32_EPCACH_A_MODE_COSEL_TOGGLE_OUTPUT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_output_mode_set
//
// Set the channel output at the next capture/compare event.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_output_mode_set(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.COSEL = SI32_EPCACH_A_MODE_COSEL_SET_OUTPUT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_output_mode_clear
//
// Clear the channel output at the next capture/compare event.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_output_mode_clear(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.COSEL = SI32_EPCACH_A_MODE_COSEL_CLEAR_OUTPUT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_output_mode_none
//
// Capture/compare events do not control the output state.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_output_mode_none(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.COSEL = SI32_EPCACH_A_MODE_COSEL_NO_CHANGE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_set_width_for_n_bit_edge_aligned_pwm_mode
//
// This field represents the n-bit PWM for this channel. When in n-bit
// PWM mode, the channel will behave as if the PCA Counter/Timer is only
// n bits wide.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_set_width_for_n_bit_edge_aligned_pwm_mode(
   SI32_EPCACH_A_Type * basePointer,
   uint32_t nbits)
{
   assert(nbits < 16);   // nbits < 2^4
   //{{
   basePointer->MODE.PWMMD = nbits;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_differential_signal_generator
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_differential_signal_generator(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.DIFGEN = SI32_EPCACH_A_MODE_DIFGEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_differential_signal_generator
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_differential_signal_generator(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.DIFGEN = SI32_EPCACH_A_MODE_DIFGEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_operating_mode_edge_aligned_pwm
//
// Configure the channel for edge-aligned PWM mode.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_operating_mode_edge_aligned_pwm(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CMD = SI32_EPCACH_A_MODE_CMD_EDGE_PWM_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_operating_mode_center_aligned_pwm
//
// Configure the channel for center-aligned PWM mode.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_operating_mode_center_aligned_pwm(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CMD = SI32_EPCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_operating_mode_high_frequency_square_wave
//
// Configure the channel for high-frequency/square-wave mode.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_operating_mode_high_frequency_square_wave(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CMD = SI32_EPCACH_A_MODE_CMD_HF_SQUARE_WAVE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_operating_mode_timer_capture
//
// Configure the channel for timer/capture mode.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_operating_mode_timer_capture(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CMD = SI32_EPCACH_A_MODE_CMD_TIMER_CAPTURE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_operating_mode_n_bit_edge_aligned_pwm
//
// Configure the channel for n-bit edge-aligned PWM mode.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_operating_mode_n_bit_edge_aligned_pwm(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->MODE.CMD = SI32_EPCACH_A_MODE_CMD_N_BIT_PWM_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_write_control(
   SI32_EPCACH_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_read_control
//
// Read CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCACH_A_read_control(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_clear_output_state
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_clear_output_state(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_COUTST_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_set_output_state
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_set_output_state(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_COUTST_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_get_output_state
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCACH_A_get_output_state(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.COUTST);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_positive_edge_input_capture
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_positive_edge_input_capture(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CPCAPEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_positive_edge_input_capture
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_positive_edge_input_capture(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CPCAPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_negative_edge_input_capture
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_negative_edge_input_capture(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CNCAPEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_negative_edge_input_capture
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_negative_edge_input_capture(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CNCAPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_is_register_update_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCACH_A_is_register_update_busy(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.CUPDCF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_differential_y_phase_state_low
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_differential_y_phase_state_low(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_YPHST_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_differential_y_phase_state_high
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_differential_y_phase_state_high(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_YPHST_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_active_y_phase
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_active_y_phase(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_ACTIVEPH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_active_x_phase
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_active_x_phase(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_ACTIVEPH_XACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_differential_x_phase_state_low
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_differential_x_phase_state_low(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_XPHST_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_select_differential_x_phase_state_high
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_select_differential_x_phase_state_high(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_XPHST_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_capture_compare_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_capture_compare_interrupt(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CCIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_capture_compare_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_capture_compare_interrupt(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_is_capture_compare_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCACH_A_is_capture_compare_interrupt_enabled(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.CCIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_capture_compare_dma_request
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_capture_compare_dma_request(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CCDEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_capture_compare_dma_request
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_capture_compare_dma_request(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CCDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_capture_compare_sync_signal
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_capture_compare_sync_signal(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CCSEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_capture_compare_sync_signal
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_capture_compare_sync_signal(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CCSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_intermediate_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_intermediate_overflow_interrupt(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CIOVFIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_intermediate_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_intermediate_overflow_interrupt(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CIOVFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_is_intermediate_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_EPCACH_A_is_intermediate_overflow_interrupt_enabled(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.CIOVFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_intermediate_overflow_dma_request
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_intermediate_overflow_dma_request(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CIOVFDEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_intermediate_overflow_dma_request
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_intermediate_overflow_dma_request(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CIOVFDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_enable_intermediate_overflow_sync_signal
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_enable_intermediate_overflow_sync_signal(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EPCACH_A_CONTROL_CIOVFSEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_disable_intermediate_overflow_sync_signal
//
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_disable_intermediate_overflow_sync_signal(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EPCACH_A_CONTROL_CIOVFSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_write_ccapv
//
// Write to CCAPV register.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_write_ccapv(
   SI32_EPCACH_A_Type * basePointer,
   uint32_t ccapv)
{
   //{{
   basePointer->CCAPV.U32 = ccapv;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_read_ccapv
//
// Read the capture/compare register value.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCACH_A_read_ccapv(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   return basePointer->CCAPV.CCAPV_BITS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_write_ccapvupd
//
// Write to CCAPVUPD register.
//-----------------------------------------------------------------------------
void
_SI32_EPCACH_A_write_ccapvupd(
   SI32_EPCACH_A_Type * basePointer,
   uint32_t ccapvupd)
{
   //{{
   basePointer->CCAPVUPD.U32 = ccapvupd;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EPCACH_A_read_ccapvupd
//
// Read the capture/compare register update value.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EPCACH_A_read_ccapvupd(
   SI32_EPCACH_A_Type * basePointer)
{
   //{{
   return basePointer->CCAPVUPD.CCAPVUPD_BITS;
   //}}
}


//-eof--------------------------------------------------------------------------
