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
/// @file SI32_PCACH_A_Type.h
//
// Script: 0.58
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_PCACH_A_TYPE_H__
#define __SI32_PCACH_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_PCACH_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_PCACH_A_initialize(SI32_PCACH_A_Type* basePointer,
///      uint32_t mode,
///      uint32_t control,
///      uint32_t ccapv,
///      uint32_t ccapvupd)
///
/// @brief
/// Writes all PCACH registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  ccapv
///  Valid range is 32 bits.
///
/// @param[in]
///  ccapvupd
///  Valid range is 32 bits.
///
void
_SI32_PCACH_A_initialize(SI32_PCACH_A_Type* /*basePointer*/,
   uint32_t, /*mode*/
   uint32_t, /*control*/
   uint32_t, /*ccapv*/
   uint32_t /*ccapvupd*/);
///
/// @def SI32_PCACH_A_initialize(basePointer, mode, control, ccapv, ccapvupd)
#define SI32_PCACH_A_initialize(basePointer, mode, control, ccapv, ccapvupd) do{  \
   basePointer->MODE.U32 = mode;\
   basePointer->CONTROL.U32 = control;\
   basePointer->CCAPV.U32 = ccapv;\
   basePointer->CCAPVUPD.U32 = ccapvupd;\
} while(0)


/// @fn _SI32_PCACH_A_write_mode(SI32_PCACH_A_Type* basePointer,
///      uint32_t mode)
///
/// @brief
/// Writes to MODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
void
_SI32_PCACH_A_write_mode(SI32_PCACH_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_PCACH_A_write_mode(basePointer, mode)
#define SI32_PCACH_A_write_mode(basePointer, mode) \
   (basePointer->MODE.U32 = mode)


/// @fn _SI32_PCACH_A_read_mode(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Reads MODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCACH_A_read_mode(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_read_mode(basePointer)
#define SI32_PCACH_A_read_mode(basePointer) \
(basePointer->MODE.U32)


/// @fn _SI32_PCACH_A_select_output_mode_toggle(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Toggle channel output at the next capture/compare event.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_output_mode_toggle(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_output_mode_toggle(basePointer)
#define SI32_PCACH_A_select_output_mode_toggle(basePointer) \
   (basePointer->MODE.COSEL = SI32_PCACH_A_MODE_COSEL_TOGGLE_OUTPUT_VALUE)


/// @fn _SI32_PCACH_A_select_output_mode_set(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Set the channel output at the next capture/compare event.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_output_mode_set(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_output_mode_set(basePointer)
#define SI32_PCACH_A_select_output_mode_set(basePointer) \
   (basePointer->MODE.COSEL = SI32_PCACH_A_MODE_COSEL_SET_OUTPUT_VALUE)


/// @fn _SI32_PCACH_A_select_output_mode_clear(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Clear the channel output at the next capture/compare event.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_output_mode_clear(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_output_mode_clear(basePointer)
#define SI32_PCACH_A_select_output_mode_clear(basePointer) \
   (basePointer->MODE.COSEL = SI32_PCACH_A_MODE_COSEL_CLEAR_OUTPUT_VALUE)


/// @fn _SI32_PCACH_A_select_output_mode_none(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Capture/compare events do not control the output state.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_output_mode_none(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_output_mode_none(basePointer)
#define SI32_PCACH_A_select_output_mode_none(basePointer) \
   (basePointer->MODE.COSEL = SI32_PCACH_A_MODE_COSEL_NO_CHANGE_VALUE)


/// @fn _SI32_PCACH_A_set_width_for_n_bit_edge_aligned_pwm_mode(SI32_PCACH_A_Type* basePointer,
///      uint32_t nbits)
///
/// @brief
/// This field represents the n-bit PWM for this channel. When in n-bit
/// PWM mode, the channel will behave as if the PCA Counter/Timer is only
/// n bits wide.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  nbits
///  Valid range is 4 bits.
///
void
_SI32_PCACH_A_set_width_for_n_bit_edge_aligned_pwm_mode(SI32_PCACH_A_Type* /*basePointer*/,
   uint32_t /*nbits*/);
///
/// @def SI32_PCACH_A_set_width_for_n_bit_edge_aligned_pwm_mode(basePointer, nbits)
#define SI32_PCACH_A_set_width_for_n_bit_edge_aligned_pwm_mode(basePointer, nbits) \
   (basePointer->MODE.PWMMD = nbits)


/// @fn _SI32_PCACH_A_select_operating_mode_edge_aligned_pwm(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Configure the channel for edge-aligned PWM mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_operating_mode_edge_aligned_pwm(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_operating_mode_edge_aligned_pwm(basePointer)
#define SI32_PCACH_A_select_operating_mode_edge_aligned_pwm(basePointer) \
   (basePointer->MODE.CMD = SI32_PCACH_A_MODE_CMD_EDGE_PWM_VALUE)


/// @fn _SI32_PCACH_A_select_operating_mode_center_aligned_pwm(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Configure the channel for center-aligned PWM mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_operating_mode_center_aligned_pwm(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_operating_mode_center_aligned_pwm(basePointer)
#define SI32_PCACH_A_select_operating_mode_center_aligned_pwm(basePointer) \
   (basePointer->MODE.CMD = SI32_PCACH_A_MODE_CMD_CENTER_ALIGNED_PWM_VALUE)


/// @fn _SI32_PCACH_A_select_operating_mode_high_frequency_square_wave(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Configure the channel for high-frequency/square-wave mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_operating_mode_high_frequency_square_wave(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_operating_mode_high_frequency_square_wave(basePointer)
#define SI32_PCACH_A_select_operating_mode_high_frequency_square_wave(basePointer) \
   (basePointer->MODE.CMD =SI32_PCACH_A_MODE_CMD_HF_SQUARE_WAVE_VALUE)


/// @fn _SI32_PCACH_A_select_operating_mode_timer_capture(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Configure the channel for timer/capture mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_operating_mode_timer_capture(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_operating_mode_timer_capture(basePointer)
#define SI32_PCACH_A_select_operating_mode_timer_capture(basePointer) \
   (basePointer->MODE.CMD = SI32_PCACH_A_MODE_CMD_TIMER_CAPTURE_VALUE)


/// @fn _SI32_PCACH_A_select_operating_mode_n_bit_edge_aligned_pwm(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Configure the channel for n-bit edge-aligned PWM mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_select_operating_mode_n_bit_edge_aligned_pwm(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_select_operating_mode_n_bit_edge_aligned_pwm(basePointer)
#define SI32_PCACH_A_select_operating_mode_n_bit_edge_aligned_pwm(basePointer) \
   (basePointer->MODE.CMD = SI32_PCACH_A_MODE_CMD_N_BIT_PWM_VALUE)


/// @fn _SI32_PCACH_A_write_control(SI32_PCACH_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes to CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_PCACH_A_write_control(SI32_PCACH_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_PCACH_A_write_control(basePointer, control)
#define SI32_PCACH_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_PCACH_A_read_control(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCACH_A_read_control(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_read_control(basePointer)
#define SI32_PCACH_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_PCACH_A_clear_output_state(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_clear_output_state(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_clear_output_state(basePointer)
#define SI32_PCACH_A_clear_output_state(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCACH_A_CONTROL_COUTST_MASK)


/// @fn _SI32_PCACH_A_set_output_state(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_set_output_state(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_set_output_state(basePointer)
#define SI32_PCACH_A_set_output_state(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCACH_A_CONTROL_COUTST_MASK)


/// @fn _SI32_PCACH_A_get_output_state(SI32_PCACH_A_Type* basePointer)
///
/// @return
///  Returns TRUE if output state high, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PCACH_A_get_output_state(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_get_output_state(basePointer)
#define SI32_PCACH_A_get_output_state(basePointer) \
((bool)(basePointer->CONTROL.COUTST))


/// @fn _SI32_PCACH_A_enable_positive_edge_input_capture(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_enable_positive_edge_input_capture(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_enable_positive_edge_input_capture(basePointer)
#define SI32_PCACH_A_enable_positive_edge_input_capture(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCACH_A_CONTROL_CPCAPEN_MASK)


/// @fn _SI32_PCACH_A_disable_positive_edge_input_capture(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_disable_positive_edge_input_capture(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_disable_positive_edge_input_capture(basePointer)
#define SI32_PCACH_A_disable_positive_edge_input_capture(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCACH_A_CONTROL_CPCAPEN_MASK)


/// @fn _SI32_PCACH_A_enable_negative_edge_input_capture(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_enable_negative_edge_input_capture(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_enable_negative_edge_input_capture(basePointer)
#define SI32_PCACH_A_enable_negative_edge_input_capture(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCACH_A_CONTROL_CNCAPEN_MASK)


/// @fn _SI32_PCACH_A_disable_negative_edge_input_capture(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_disable_negative_edge_input_capture(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_disable_negative_edge_input_capture(basePointer)
#define SI32_PCACH_A_disable_negative_edge_input_capture(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCACH_A_CONTROL_CNCAPEN_MASK)


/// @fn _SI32_PCACH_A_is_register_update_busy(SI32_PCACH_A_Type* basePointer)
///
/// @return
///  Returns TRUE if PCA channel register update has not been completed and
///  is still pending, otherwise returns false.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PCACH_A_is_register_update_busy(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_is_register_update_busy(basePointer)
#define SI32_PCACH_A_is_register_update_busy(basePointer) \
((bool)(basePointer->CONTROL.CUPDCF))


/// @fn _SI32_PCACH_A_enable_capture_compare_interrupt(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_enable_capture_compare_interrupt(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_enable_capture_compare_interrupt(basePointer)
#define SI32_PCACH_A_enable_capture_compare_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCACH_A_CONTROL_CCIEN_MASK)


/// @fn _SI32_PCACH_A_disable_capture_compare_interrupt(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_disable_capture_compare_interrupt(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_disable_capture_compare_interrupt(basePointer)
#define SI32_PCACH_A_disable_capture_compare_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCACH_A_CONTROL_CCIEN_MASK)


/// @fn _SI32_PCACH_A_is_capture_compare_interrupt_enabled(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_PCACH_A_is_capture_compare_interrupt_enabled(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_is_capture_compare_interrupt_enabled(basePointer)
#define SI32_PCACH_A_is_capture_compare_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.CCIEN))


/// @fn _SI32_PCACH_A_enable_intermediate_overflow_interrupt(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_enable_intermediate_overflow_interrupt(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_enable_intermediate_overflow_interrupt(basePointer)
#define SI32_PCACH_A_enable_intermediate_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_PCACH_A_CONTROL_CIOVFIEN_MASK)


/// @fn _SI32_PCACH_A_disable_intermediate_overflow_interrupt(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PCACH_A_disable_intermediate_overflow_interrupt(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_disable_intermediate_overflow_interrupt(basePointer)
#define SI32_PCACH_A_disable_intermediate_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PCACH_A_CONTROL_CIOVFIEN_MASK)


/// @fn _SI32_PCACH_A_is_intermediate_overflow_interrupt_enabled(SI32_PCACH_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_PCACH_A_is_intermediate_overflow_interrupt_enabled(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_is_intermediate_overflow_interrupt_enabled(basePointer)
#define SI32_PCACH_A_is_intermediate_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.CIOVFIEN))


/// @fn _SI32_PCACH_A_write_ccapv(SI32_PCACH_A_Type* basePointer,
///      uint32_t ccapv)
///
/// @brief
/// Writes to CCAPV register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ccapv
///  Valid range is 32 bits.
///
void
_SI32_PCACH_A_write_ccapv(SI32_PCACH_A_Type* /*basePointer*/,
   uint32_t /*ccapv*/);
///
/// @def SI32_PCACH_A_write_ccapv(basePointer, ccapv)
#define SI32_PCACH_A_write_ccapv(basePointer, ccapv) \
   (basePointer->CCAPV.U32 = ccapv)


/// @fn _SI32_PCACH_A_read_ccapv(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Reads CCAPV register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCACH_A_read_ccapv(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_read_ccapv(basePointer)
#define SI32_PCACH_A_read_ccapv(basePointer) \
((uint32_t)(basePointer->CCAPV.U32))


/// @fn _SI32_PCACH_A_write_ccapvupd(SI32_PCACH_A_Type* basePointer,
///      uint32_t ccapvupd)
///
/// @brief
/// Writes to  CCAPVUPD register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ccapvupd
///  Valid range is 32 bits.
///
void
_SI32_PCACH_A_write_ccapvupd(SI32_PCACH_A_Type* /*basePointer*/,
   uint32_t /*ccapvupd*/);
///
/// @def SI32_PCACH_A_write_ccapvupd(basePointer, ccapvupd)
#define SI32_PCACH_A_write_ccapvupd(basePointer, ccapvupd) \
   (basePointer->CCAPVUPD.U32 = ccapvupd)


/// @fn _SI32_PCACH_A_read_ccapvupd(SI32_PCACH_A_Type* basePointer)
///
/// @brief
/// Reads CCAPVUPD register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PCACH_A_read_ccapvupd(SI32_PCACH_A_Type* /*basePointer*/);
///
/// @def SI32_PCACH_A_read_ccapvupd(basePointer)
#define SI32_PCACH_A_read_ccapvupd(basePointer) \
((uint32_t)(basePointer->CCAPVUPD.U32))



#ifdef __cplusplus
}
#endif

#endif // __SI32_PCACH_A_TYPE_H__

//-eof--------------------------------------------------------------------------
