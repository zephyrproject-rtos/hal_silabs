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
/// @file SI32_ACCTR_A_Type.c
//
// Script: 0.62
// HAL Source: 0.8
// Version: 17

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_ACCTR_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_initialize_module
//
// Initialize Module.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_initialize_module(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t config,
   uint32_t control,
   uint32_t lcconfig,
   uint32_t lctiming,
   uint32_t lcmode,
   uint32_t lcclkcontrol,
   uint32_t lccount,
   uint32_t dbconfig,
   uint32_t comp0,
   uint32_t comp1)
{
   //{{
   basePointer->CONFIG.U32=config;
   basePointer->CONTROL.U32=control;
   basePointer->LCCONFIG.U32=lcconfig;
   basePointer->TIMING.U32=lctiming;
   basePointer->LCMODE.U32=lcmode;
   basePointer->LCCLKCONTROL.U32=lcclkcontrol;
   basePointer->LCCOUNT.U32=lccount;
   basePointer->DBCONFIG.U32=dbconfig;
   basePointer->COMP0.U32=comp0;
   basePointer->COMP1.U32=comp1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_config
//
// Write to CONFIG register. Writing to this register resets the module.
// Sequential writes to this register require polling on the write status
// flag UPDSTSF.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_config(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_config
//
// Read from CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_config(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_reset_module
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_reset_module(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.U32 = (basePointer->CONFIG.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_module(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_write_in_progress
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_write_in_progress(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.UPDSTSF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_no_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_no_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_NONE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_cmp0_and_cmp1_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_cmp0_and_cmp1_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_LCC1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_cmp0_and_integ0_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_cmp0_and_integ0_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_INT0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_cmp1_and_integ1_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_cmp1_and_integ1_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_LCC1_INT1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_integ0_and_integ1_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_integ0_and_integ1_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_INT0_INT1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_switch_mode_cmp0_and_cmp1_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_switch_mode_cmp0_and_cmp1_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_CMP1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_switch_mode_cmp0_and_integ0_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_switch_mode_cmp0_and_integ0_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_INT0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_switch_mode_cmp1_and_integ1_debug_outputs
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_switch_mode_cmp1_and_integ1_debug_outputs(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_CMP1_INT1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_switch_from_quadrature_to_dual_on_flutter
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_switch_from_quadrature_to_dual_on_flutter(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.FLQDEN = SI32_ACCTR_A_CONFIG_FLQDEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_switch_from_quadrature_to_dual_on_flutter
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_switch_from_quadrature_to_dual_on_flutter(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.FLQDEN = SI32_ACCTR_A_CONFIG_FLQDEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_stop_count_on_flutter
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_stop_count_on_flutter(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.FLSTPEN = SI32_ACCTR_A_CONFIG_FLSTPEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_stop_count_on_flutter
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_stop_count_on_flutter(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.FLSTPEN = SI32_ACCTR_A_CONFIG_FLSTPEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_reed_switch_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_reed_switch_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.TOPMD = SI32_ACCTR_A_CONFIG_TOPMD_SWITCH_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.TOPMD = SI32_ACCTR_A_CONFIG_TOPMD_LC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_single_channel_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_single_channel_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_SINGLE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_dual_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_dual_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_DUAL_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_quadrature_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_quadrature_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_QUADRATURE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_control(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_control
//
// Read from CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_control(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_low_threshold_32_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_32_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPLTH =
      SI32_ACCTR_A_CONTROL_CMPLTH_32_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_low_threshold_36_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_36_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPLTH =
      SI32_ACCTR_A_CONTROL_CMPLTH_36_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_low_threshold_40_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_40_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPLTH =
      SI32_ACCTR_A_CONTROL_CMPLTH_40_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_low_threshold_44_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_44_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPLTH =
      SI32_ACCTR_A_CONTROL_CMPLTH_44_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_high_threshold_48_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_48_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPHTH =
      SI32_ACCTR_A_CONTROL_CMPHTH_48_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_high_threshold_52_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_52_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPHTH =
      SI32_ACCTR_A_CONTROL_CMPHTH_52_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_high_threshold_56_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_56_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPHTH =
      SI32_ACCTR_A_CONTROL_CMPHTH_56_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_analog_comparator_high_threshold_60_percent
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_60_percent(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CMPHTH =
      SI32_ACCTR_A_CONTROL_CMPHTH_60_PERCENT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_calibrate_until_pass
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_calibrate_until_pass(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALMD = SI32_ACCTR_A_CONTROL_CALMD_UNTIL_PASS_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_calibrate_until_fail
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_calibrate_until_fail(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALMD = SI32_ACCTR_A_CONTROL_CALMD_UNTIL_FAIL_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_full_pull_up_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_full_pull_up_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_FULL_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_small_pull_up_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_small_pull_up_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_SMALL_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_medium_pull_up_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_medium_pull_up_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_MEDIUM_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_large_pull_up_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_large_pull_up_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_LARGE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_force_continuous_pull_ups
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_force_continuous_pull_ups(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.FPUPEN = SI32_ACCTR_A_CONTROL_FPUPEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_force_continuous_pull_ups
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_force_continuous_pull_ups(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.FPUPEN = SI32_ACCTR_A_CONTROL_FPUPEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_force_input_to_ground
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_force_input_to_ground(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.FPDNEN = SI32_ACCTR_A_CONTROL_FPDNEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_force_input_to_ground
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_force_input_to_ground(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.FPDNEN = SI32_ACCTR_A_CONTROL_FPDNEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_pull_up_value
//
// Set pull-up value.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_pull_up_value(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t puval)
{
   assert(puval < 32);   // puval < 2^5
   //{{
   basePointer->CONTROL.PUVAL = puval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_pull_up_value
//
// Get pull-up value.
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_pull_up_value(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.PUVAL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_calibrate_pc0
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_calibrate_pc0(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALSEL = SI32_ACCTR_A_CONTROL_CALSEL_IN0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_calibrate_pc1
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_calibrate_pc1(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALSEL = SI32_ACCTR_A_CONTROL_CALSEL_IN1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_was_calibration_successful
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_was_calibration_successful(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.CALRF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_start_calibration
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_start_calibration(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.CALBUSYF = SI32_ACCTR_A_CONTROL_CALBUSYF_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_calibration_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_calibration_busy(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.CALBUSYF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_lcconfig
//
// Write to LCCONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_lcconfig(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t lcconfig)
{
   //{{
   basePointer->LCCONFIG.U32=lcconfig;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_lcconfig
//
// Read from LCCONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_lcconfig(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_extend_low_pulses
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_extend_low_pulses(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.PEMD = SI32_ACCTR_A_LCCONFIG_PEMD_LOW_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_extend_high_pulses
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_extend_high_pulses(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.PEMD = SI32_ACCTR_A_LCCONFIG_PEMD_HIGH_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_no_pulse_extension
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_no_pulse_extension(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.PEMD = SI32_ACCTR_A_LCCONFIG_PEMD_NONE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_0_full_range
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_0_full_range(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMP0THR = SI32_ACCTR_A_LCCONFIG_CMP0THR_FULL_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_0_low_range
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_0_low_range(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMP0THR = SI32_ACCTR_A_LCCONFIG_CMP0THR_LOW_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_1_full_range
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_1_full_range(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMP1THR = SI32_ACCTR_A_LCCONFIG_CMP1THR_FULL_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_1_low_range
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_1_low_range(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMP1THR = SI32_ACCTR_A_LCCONFIG_CMP1THR_LOW_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_0_coarse_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_0_coarse_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 63));
   //{{
   basePointer->LCCONFIG.CMP0CTH = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_0_fine_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_0_fine_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 7));
   //{{
   basePointer->LCCONFIG.CMP0FTH = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_1_coarse_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_1_coarse_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 63));
   //{{
   basePointer->LCCONFIG.CMP1CTH = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_1_fine_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_1_fine_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 7));
   //{{
   basePointer->LCCONFIG.CMP1FTH = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_0_full_range_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_0_full_range_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 63));
   //{{
   // This register requires a sinle 32-bit read modify write.
   basePointer->LCCONFIG.U32 =
      (basePointer->LCCONFIG.U32
      // clear bits
      & (~SI32_ACCTR_A_LCCONFIG_CMP0CTH_MASK))
      // set bits
      | (SI32_ACCTR_A_LCCONFIG_CMP0THR_MASK |
        (threshold<<SI32_ACCTR_A_LCCONFIG_CMP0CTH_SHIFT));
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_0_low_range_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_0_low_range_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 48));
   //{{
   // This register requires a single 32-bit read modify write.
   basePointer->LCCONFIG.U32 =
      (basePointer->LCCONFIG.U32
      // clear bits
      & (~SI32_ACCTR_A_LCCONFIG_CMP0THR_MASK &
         ~SI32_ACCTR_A_LCCONFIG_CMP0CTH_MASK &
         ~SI32_ACCTR_A_LCCONFIG_CMP0FTH_MASK))
      // set bits
      | (((threshold/6)<<SI32_ACCTR_A_LCCONFIG_CMP0CTH_SHIFT) |
         (threshold%6)<<SI32_ACCTR_A_LCCONFIG_CMP0FTH_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_1_full_range_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_1_full_range_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 63));
   //{{
   // This register requires a single 32-bit read modify write.
   basePointer->LCCONFIG.U32 =
      (basePointer->LCCONFIG.U32
      // clear bits
      & (~SI32_ACCTR_A_LCCONFIG_CMP1CTH_MASK))
      // set bits
      | (SI32_ACCTR_A_LCCONFIG_CMP1THR_MASK |
        (threshold<<SI32_ACCTR_A_LCCONFIG_CMP1CTH_SHIFT));
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_comparator_1_low_range_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_comparator_1_low_range_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t threshold)
{
   assert((threshold >= 0) && (threshold <= 48));
   //{{
   // This register requires a single 32-bit read modify write.
   basePointer->LCCONFIG.U32 =
      (basePointer->LCCONFIG.U32
      // clear bits
      & (~SI32_ACCTR_A_LCCONFIG_CMP1THR_MASK &
         ~SI32_ACCTR_A_LCCONFIG_CMP1CTH_MASK &
         ~SI32_ACCTR_A_LCCONFIG_CMP1FTH_MASK))
      // set bits
      | (((threshold/6)<<SI32_ACCTR_A_LCCONFIG_CMP1CTH_SHIFT) |
         (threshold%6)<<SI32_ACCTR_A_LCCONFIG_CMP1FTH_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_low_side_hysteresis_0_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_0_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_0_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_low_side_hysteresis_5_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_5_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_5_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_low_side_hysteresis_10_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_10_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_10_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_low_side_hysteresis_20_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_20_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_20_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_high_side_hysteresis_0_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_0_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_0_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_high_side_hysteresis_5_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_5_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_5_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_high_side_hysteresis_10_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_10_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_10_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_high_side_hysteresis_20_mV
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_20_mV(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_20_MV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_response_time_200_ns
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_response_time_200_ns(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_200_NS_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_response_time_400_ns
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_response_time_400_ns(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_400_NS_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_response_time_1_us
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_response_time_1_us(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_1_US_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_comparator_response_time_5_us
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_comparator_response_time_5_us(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_5_US_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_use_lc_comparator_0_for_counter_1
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_use_lc_comparator_0_for_counter_1(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMP0CNT1EN =
      SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_use_lc_comparator_0_for_counter_1
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_use_lc_comparator_0_for_counter_1(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.CMP0CNT1EN =
      SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_force_lc_comparator_0_on
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_force_lc_comparator_0_on(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.FCMP0EN =
      SI32_ACCTR_A_LCCONFIG_FCMP0EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_force_lc_comparator_0_on
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_force_lc_comparator_0_on(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.FCMP0EN =
      SI32_ACCTR_A_LCCONFIG_FCMP0EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_force_lc_comparator_1_on
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_force_lc_comparator_1_on(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.FCMP1EN =
      SI32_ACCTR_A_LCCONFIG_FCMP1EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_force_lc_comparator_1_on
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_force_lc_comparator_1_on(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCONFIG.FCMP1EN =
      SI32_ACCTR_A_LCCONFIG_FCMP1EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_lctiming
//
// Write to LCTIMING register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_lctiming(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t lctiming)
{
   //{{
   basePointer->TIMING.U32=lctiming;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_lctiming
//
// Read from LCTIMING register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_lctiming(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_lc_timing_state
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_lc_timing_state(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.STATE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_pulse_0_offset
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_pulse_0_offset(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.B0OEN=SI32_ACCTR_A_TIMING_B0OEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_pulse_0_offset
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_pulse_0_offset(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.B0OEN=SI32_ACCTR_A_TIMING_B0OEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_pulse_1_offset
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_pulse_1_offset(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.B1OEN=SI32_ACCTR_A_TIMING_B1OEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_pulse_1_offset
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_pulse_1_offset(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.B1OEN=SI32_ACCTR_A_TIMING_B1OEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_zone_p_time
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_zone_p_time(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t time)
{
   assert(time < 8);   // time < 2^3
   //{{
   basePointer->TIMING.ZONEP = time;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_zone_p_time
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_zone_p_time(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.ZONEP;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_zone_a_time
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_zone_a_time(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t time)
{
   assert(time < 8);   // time < 2^3
   //{{
   basePointer->TIMING.ZONEA = time;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_zone_a_time
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_zone_a_time(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.ZONEA;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_zone_b_time
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_zone_b_time(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t time)
{
   assert(time < 8);   // time < 2^3
   //{{
   basePointer->TIMING.ZONEB = time;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_zone_b_time
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_zone_b_time(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.ZONEB;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_zone_c_time
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_zone_c_time(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t time)
{
   assert(time < 8);   // time < 2^3
   //{{
   basePointer->TIMING.ZONEC = time;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_zone_c_time
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_zone_c_time(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.ZONEC;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_zone_d_time
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_zone_d_time(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t time)
{
   assert(time < 8);   // time < 2^3
   //{{
   basePointer->TIMING.ZONED = time;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_zone_d_time
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_zone_d_time(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.ZONED;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_disable_wake_after_zone
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_disable_wake_after_zone(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_wake_after_zone_p
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_wake_after_zone_p(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEP_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_wake_after_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_wake_after_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEA_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_wake_after_zone_b
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_wake_after_zone_b(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEB_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_wake_after_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_wake_after_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_wake_after_zone_d
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_wake_after_zone_d(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_wake_after_lc_sequence
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_wake_after_lc_sequence(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WEND_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_wake_and_stop_after_lc_sequence
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_wake_and_stop_after_lc_sequence(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WKSTOP_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_start_sequencer
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_start_sequencer(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.START = SI32_ACCTR_A_TIMING_START_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_4_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_4_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_4_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_8_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_8_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_8_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_16_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_16_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_16_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_32_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_32_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_32_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_64_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_64_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_64_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_128_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_128_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_128_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_256_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_256_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_256_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_512_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_512_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_512_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_1024_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_1024_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_1024_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_2048_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_2048_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_2048_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_4096_cycle_period
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_4096_cycle_period(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_4096_CYCLES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_single_sample_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_single_sample_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_SINGLE_SAMPLE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_consecutive_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_consecutive_mode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_CONSECUTIVE_SAMPLE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_period_value
//
// Sets actual value of Period field.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_period_value(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t value)
{
   assert(value < 16);   // value < 2^4
   //{{
   basePointer->TIMING.PERIOD = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_period_value
//
// Gets actual value of Period field.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_ACCTR_A_get_period_value(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->TIMING.PERIOD;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_period_cycles
//
// Calculates number of cycles accordion to period setting.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_ACCTR_A_get_period_cycles(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return ((basePointer->TIMING.PERIOD<11)?(0x00000004<<basePointer->TIMING.PERIOD):0xFFFF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_lcmode
//
// Write to LCMODE register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_lcmode(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t lcmode)
{
   //{{
   basePointer->LCMODE.U32=lcmode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_lcmode
//
// Read from LCMODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_lcmode(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCMODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_automatic_tracking
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_automatic_tracking(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.ATRKEN=SI32_ACCTR_A_LCMODE_ATRKEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_automatic_tracking
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_automatic_tracking(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.ATRKEN=SI32_ACCTR_A_LCMODE_ATRKEN_DISABLED_VALUE;\
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_automatic_center_discriminator
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_automatic_center_discriminator(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.ACDEN=SI32_ACCTR_A_LCMODE_ACDEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_automatic_center_discriminator
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_automatic_center_discriminator(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.ACDEN=SI32_ACCTR_A_LCMODE_ACDEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_zero
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_zero(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_ZERO_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_1
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_1(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_2
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_2(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_3
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_3(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS3_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_zero
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_zero(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_ZERO_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_1
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_1(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_2
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_2(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_3
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_3(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS3_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONEA_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_b
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_b(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONEB_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONEC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_d
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_d(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONEA_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_b
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_b(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONEB_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONEC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_d
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_d(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_0_output_disable
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_0_output_disable(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_C_ONLY_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_A_ONLY_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a_and_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a_and_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_A_AND_C_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_1_output_disable
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_1_output_disable(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_C_ONLY_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_A_ONLY_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a_and_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a_and_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_A_AND_C_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_output_pulse_mode_disabled
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_disabled(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_output_pulse_mode_toggle
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_toggle(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_TOGGLE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_low
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_low(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_PULSE_LOW_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_high
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_high(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_PULSE_HIGH_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0ZONEAEN=SI32_ACCTR_A_LCMODE_B0ZONEAEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
basePointer->LCMODE.B0ZONEAEN=SI32_ACCTR_A_LCMODE_B0ZONEAEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_b
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_b(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0ZONEBEN=SI32_ACCTR_A_LCMODE_B0ZONEBEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_b
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_b(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0ZONEBEN=SI32_ACCTR_A_LCMODE_B0ZONEBEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0ZONECEN=SI32_ACCTR_A_LCMODE_B0ZONECEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0ZONECEN=SI32_ACCTR_A_LCMODE_B0ZONECEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_p
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_p(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0ZONEPEN=SI32_ACCTR_A_LCMODE_B0ZONEPEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_p
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_p(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0ZONEPEN=SI32_ACCTR_A_LCMODE_B0ZONEPEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_counter_0_pulse_high_polarity
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_counter_0_pulse_high_polarity(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0POL=SI32_ACCTR_A_LCMODE_B0POL_PULSE_HIGH_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_counter_0_pulse_low_polarity
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_counter_0_pulse_low_polarity(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B0POL=SI32_ACCTR_A_LCMODE_B0POL_PULSE_LOW_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1ZONEAEN=SI32_ACCTR_A_LCMODE_B1ZONEAEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_a
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_a(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1ZONEAEN=SI32_ACCTR_A_LCMODE_B1ZONEAEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_b
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_b(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1ZONEBEN=SI32_ACCTR_A_LCMODE_B1ZONEBEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_b
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_b(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1ZONEBEN=SI32_ACCTR_A_LCMODE_B1ZONEBEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1ZONECEN=SI32_ACCTR_A_LCMODE_B1ZONECEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_c
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_c(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1ZONECEN=SI32_ACCTR_A_LCMODE_B1ZONECEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_p
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_p(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1ZONEPEN=SI32_ACCTR_A_LCMODE_B1ZONEPEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_p
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_p(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
basePointer->LCMODE.B1ZONEPEN=SI32_ACCTR_A_LCMODE_B1ZONEPEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_counter_1_pulse_high_polarity
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_counter_1_pulse_high_polarity(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1POL=SI32_ACCTR_A_LCMODE_B1POL_PULSE_HIGH_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_counter_1_pulse_low_polarity
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_counter_1_pulse_low_polarity(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.B1POL=SI32_ACCTR_A_LCMODE_B1POL_PULSE_LOW_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_mode_0_disable
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_mode_0_disable(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_mode_1_external_only
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_mode_1_external_only(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_mode_2_internal_only
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_mode_2_internal_only(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_bias_mode_3_internal_external
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_bias_mode_3_internal_external(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE3_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_0_pass_through_single_ended
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_0_pass_through_single_ended(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_1_pass_through_differential
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_1_pass_through_differential(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_2_pass_through_sample_and_hold_single_ended
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_2_pass_through_sample_and_hold_single_ended(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_3_pass_through_sample_and_hold_differential
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_3_pass_through_sample_and_hold_differential(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE3_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_4_timed_single_ended
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_4_timed_single_ended(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE4_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_5_timed_differential
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_5_timed_differential(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE5_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_6_timed_sample_and_hold_single_ended
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_6_timed_sample_and_hold_single_ended(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE6_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_7_timed_sample_and_hold_differential
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_7_timed_sample_and_hold_differential(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE7_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_8_external_stop_rising_edge
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_8_external_stop_rising_edge(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE8_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_9_external_stop_falling_edge
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_9_external_stop_falling_edge(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE9_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_10_external_stop_sample_and_hold_rising_edge
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_10_external_stop_sample_and_hold_rising_edge(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE10_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_11_external_stop_sample_and_hold_falling_edge
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_11_external_stop_sample_and_hold_falling_edge(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE11_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_12_no_pulse_single_ended
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_12_no_pulse_single_ended(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE12_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_13_no_pulse_differential
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_13_no_pulse_differential(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE13_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_14_no_pulse_sample_and_hold_single_ended
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_14_no_pulse_sample_and_hold_single_ended(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE14_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_select_lc_mode_15_no_pulse_sample_and_hold_differential
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_select_lc_mode_15_no_pulse_sample_and_hold_differential(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE15_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_lcclkcontrol
//
// Write to LCCLKCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_lcclkcontrol(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t lcclkcontrol)
{
   //{{
   basePointer->LCCLKCONTROL.U32=lcclkcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_lcclkcontrol
//
// Read from LCCLKCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_lcclkcontrol(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCLKCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_lc_oscillator_calibration_value
//
//-----------------------------------------------------------------------------
uwide16_t
_SI32_ACCTR_A_get_lc_oscillator_calibration_value(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCLKCONTROL.CLKCYCLES;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_start_lc_oscillator_calibration
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_start_lc_oscillator_calibration(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->LCCLKCONTROL.CLKCAL =
      SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_START_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_lc_oscillator_calibration_in_progess
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_lc_oscillator_calibration_in_progess(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCLKCONTROL.CLKCAL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_oscillator_reload_value
//
// Set LC oscillator reload value.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_oscillator_reload_value(
   SI32_ACCTR_A_Type * basePointer,
   uwide16_t reload)
{
   assert(reload < 4096);   // reload < 2^12
   //{{
   basePointer->LCCLKCONTROL.RELOAD = reload;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_lc_oscillator_reload_value
//
// Get LC oscillator reload value.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_ACCTR_A_get_lc_oscillator_reload_value(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCLKCONTROL.RELOAD ;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_lc_limits
//
// Read from LCLIMITS register. Read only register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_lc_limits(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCLIMITS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_lccount
//
// Write to LCCOUNT register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_lccount(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t lccount)
{
   //{{
   basePointer->LCCOUNT.U32=lccount;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_lccount
//
// Read from LCCOUNT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_lccount(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCOUNT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_count_0_discriminator
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_count_0_discriminator(
   SI32_ACCTR_A_Type * basePointer,
   // Set count 0 discriminator field.
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->LCCOUNT.CD0 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_lc_count_0_discriminator
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_lc_count_0_discriminator(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCOUNT.CD0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_lc_count_1_discriminator
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_lc_count_1_discriminator(
   SI32_ACCTR_A_Type * basePointer,
   // Set count 1 discriminator field.
   uwide8_t value)
{
   assert(value < 256);   // value < 2^8
   //{{
   basePointer->LCCOUNT.CD1 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_lc_count_1_discriminator
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_lc_count_1_discriminator(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->LCCOUNT.CD1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_dbconfig
//
// Write to DBCONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_dbconfig(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t dbconfig)
{
   //{{
   basePointer->DBCONFIG.U32=dbconfig;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_dbconfig
//
// Read from DBCONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_dbconfig(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->DBCONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_debounce_low_threshold
//
// Set debounce low threshold.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_debounce_low_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t ldbth)
{
   assert(ldbth < 256);   // ldbth < 2^8
   //{{
   basePointer->DBCONFIG.LDBTH = ldbth;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_debounce_low_threshold
//
// Get debounce low threshold.
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_debounce_low_threshold(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->DBCONFIG.LDBTH;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_set_debounce_high_threshold
//
// Set debounce high threshold.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_set_debounce_high_threshold(
   SI32_ACCTR_A_Type * basePointer,
   uwide8_t hdbth)
{
   assert(hdbth < 256);   // hdbth < 2^8
   //{{
   basePointer->DBCONFIG.HDBTH = hdbth;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_debounce_high_threshold
//
// Get debounce high threshold.
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_debounce_high_threshold(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->DBCONFIG.HDBTH;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_debounce_integrator_disconnect
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_debounce_integrator_disconnect(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->DBCONFIG.INTEGDCEN =
      SI32_ACCTR_A_DBCONFIG_INTEGDCEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_debounce_integrator_disconnect
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_debounce_integrator_disconnect(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->DBCONFIG.INTEGDCEN =
      SI32_ACCTR_A_DBCONFIG_INTEGDCEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_debounce_integrator_0_high
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_debounce_integrator_0_high(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->DBCONFIG.INTEG0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_debounce_integrator_1_high
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_debounce_integrator_1_high(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->DBCONFIG.INTEG1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_count0
//
// Read from COUNT0 register. Read only register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_count0(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->COUNT0.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_count1
//
// Read from COUNT1 register. Read only register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_count1(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->COUNT1.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_comp0
//
// Write to COMP0 register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_comp0(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t comp0)
{
   assert(comp0 < 16777216);   // comp0 < 2^24
   //{{
   basePointer->COMP0.U32=comp0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_comp0
//
// Read from COMP0 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_comp0(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->COMP0.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_comp1
//
// Write to COMP1 register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_comp1(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t comp1)
{
   assert(comp1 < 16777216);   // comp1 < 2^24
   //{{
   basePointer->COMP1.U32=comp1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_comp1
//
// Read from COMP1 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_comp1(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->COMP1.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_write_status
//
// Write Status Register.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_write_status(
   SI32_ACCTR_A_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_read_status
//
// Read from STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ACCTR_A_read_status(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_direction_change_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_direction_change_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.DIRCHGI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_direction_change_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_direction_change_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.DIRCHGI = SI32_ACCTR_A_STATUS_DIRCHGI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_overflow_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_overflow_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.OVFI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_overflow_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_overflow_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.OVFI = SI32_ACCTR_A_STATUS_OVFI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_digital_comparator_0_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_digital_comparator_0_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.CMP0I;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_digital_comparator_0_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_digital_comparator_0_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.CMP0I = SI32_ACCTR_A_STATUS_CMP0I_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_digital_comparator_1_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_digital_comparator_1_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.CMP1I;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_digital_comparator_1_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_digital_comparator_1_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.CMP1I = SI32_ACCTR_A_STATUS_CMP1I_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_debounce_integrator_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_debounce_integrator_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.TRANSI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_debounce_integrator_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_debounce_integrator_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.TRANSI = SI32_ACCTR_A_STATUS_TRANSI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_quadrature_error_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_quadrature_error_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.QERRI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_quadrature_error_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_quadrature_error_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.QERRI = SI32_ACCTR_A_STATUS_QERRI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_flutter_stop_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_flutter_stop_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.FLSTOPI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_flutter_stop_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_flutter_stop_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.FLSTOPI = SI32_ACCTR_A_STATUS_FLSTOPI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_flutter_start_interrupt_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_flutter_start_interrupt_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.FLSTARTI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_clear_flutter_start_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_clear_flutter_start_interrupt_flag(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.FLSTARTI = SI32_ACCTR_A_STATUS_FLSTARTI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_direction_change_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_direction_change_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.DIRCHGIEN = SI32_ACCTR_A_STATUS_DIRCHGIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_direction_change_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_direction_change_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.DIRCHGIEN = SI32_ACCTR_A_STATUS_DIRCHGIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_counter_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_counter_overflow_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.OVFIEN = SI32_ACCTR_A_STATUS_OVFIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_counter_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_counter_overflow_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.OVFIEN = SI32_ACCTR_A_STATUS_OVFIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_digital_comparator_0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_digital_comparator_0_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.CMP0IEN = SI32_ACCTR_A_STATUS_CMP0IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_digital_comparator_0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_digital_comparator_0_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.CMP0IEN = SI32_ACCTR_A_STATUS_CMP0IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_digital_comparator_1_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_digital_comparator_1_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.CMP1IEN = SI32_ACCTR_A_STATUS_CMP1IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_digital_comparator_1_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_digital_comparator_1_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.CMP1IEN = SI32_ACCTR_A_STATUS_CMP1IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_debounce_integrator_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_debounce_integrator_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.TRANSIEN = SI32_ACCTR_A_STATUS_TRANSIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_debounce_integrator_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_debounce_integrator_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.TRANSIEN = SI32_ACCTR_A_STATUS_TRANSIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_quadrature_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_quadrature_error_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.QERRIEN = SI32_ACCTR_A_STATUS_QERRIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_quadrature_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_quadrature_error_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.QERRIEN = SI32_ACCTR_A_STATUS_QERRIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_flutter_stop_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_flutter_stop_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.FLSTOPIEN = SI32_ACCTR_A_STATUS_FLSTOPIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_flutter_stop_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_flutter_stop_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.FLSTOPIEN = SI32_ACCTR_A_STATUS_FLSTOPIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_flutter_start_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_flutter_start_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.FLSTARTIEN = SI32_ACCTR_A_STATUS_FLSTARTIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_flutter_start_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_flutter_start_interrupt(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.FLSTARTIEN = SI32_ACCTR_A_STATUS_FLSTARTIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_debounce_integrator_0_output_high
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_debounce_integrator_0_output_high(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.IN0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_debounce_integrator_1_output_high
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_debounce_integrator_1_output_high(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.IN1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_pulse_counter_state
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_pulse_counter_state(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.STATE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_flutter_detetion_flag_set
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_flutter_detetion_flag_set(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.FLF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_get_history
//
//-----------------------------------------------------------------------------
uwide8_t
_SI32_ACCTR_A_get_history(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.DIRHIST;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_analog_comparator_0_output_high
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_analog_comparator_0_output_high(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.CMP0OUT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_is_analog_comparator_1_output_high
//
//-----------------------------------------------------------------------------
bool
_SI32_ACCTR_A_is_analog_comparator_1_output_high(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.CMP1OUT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_enable_debug_output
//
// Enable debug output.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_enable_debug_output(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->DEBUGEN.DBGOEN = SI32_ACCTR_A_DEBUGEN_DBGOEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ACCTR_A_disable_debug_output
//
// Disable debug output.
//-----------------------------------------------------------------------------
void
_SI32_ACCTR_A_disable_debug_output(
   SI32_ACCTR_A_Type * basePointer)
{
   //{{
   basePointer->DEBUGEN.DBGOEN = SI32_ACCTR_A_DEBUGEN_DBGOEN_DISABLED_VALUE;
   //}}
}


//-eof--------------------------------------------------------------------------
