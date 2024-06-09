//-----------------------------------------------------------------------------
// Copyright 2013 (c) Silicon Laboratories Inc.
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
/// @file SI32_PLL_A_Type.c
//
// Script: 0.62
// HAL Source: 0.7
// Version: 9

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_PLL_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_PLL_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_initialize(
   SI32_PLL_A_Type * basePointer,
   // Write to DIVIDER register.
   uint32_t divider,
   // Write to CONTROL register.
   uint32_t control,
   // Write to SSPR register.
   uint32_t sspr,
   // Write to CALCONFIG register.
   uint32_t calconfig)
{
   //{{
   basePointer->DIVIDER.U32 = divider;
   basePointer->CONTROL.U32 = control;
   basePointer->SSPR.U32 = sspr;
   basePointer->CALCONFIG.U32 = calconfig;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_write_divider
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_write_divider(
   SI32_PLL_A_Type * basePointer,
   // Write to DIVIDER register.
   uint32_t divider)
{
   //{{
   basePointer->DIVIDER.U32 = divider;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_read_divider
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_read_divider(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->DIVIDER.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_numerator
//
// PLL output frequency is reference frequency * (N/M). N is stored as
// N-1 in the register. set_numerator will perform the -1 for you and
// should be passed the actual numerator.
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_numerator(
   SI32_PLL_A_Type * basePointer,
   uint32_t n_value)
{
   assert(n_value < 4096);   // n_value < 2^12
   //{{
   basePointer->DIVIDER.U32 =
      ((basePointer->DIVIDER.U32) & ~SI32_PLL_A_DIVIDER_N_MASK) |
     ((n_value - 1) << SI32_PLL_A_DIVIDER_N_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_get_numerator
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_get_numerator(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->DIVIDER.N;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_denominator
//
// PLL output frequency is reference frequency * (N/M). M is stored as
// M-1 in the register. set_denominator will perform the -1 for you and
// should be passed the actual numerator.
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_denominator(
   SI32_PLL_A_Type * basePointer,
   uint32_t m_value)
{
   assert(m_value < 4096);   // m_value < 2^12
   //{{
   basePointer->DIVIDER.U32 =
     ((basePointer->DIVIDER.U32) & ~SI32_PLL_A_DIVIDER_M_MASK) | (m_value - 1);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_get_denominator
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_get_denominator(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->DIVIDER.M;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_write_control
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_write_control(
   SI32_PLL_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_read_control
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_read_control(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_dco_free_running_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_dco_free_running_mode(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_OUTMD_MASK;
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_OUTMD_DCO_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_dco_frequency_lock_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_dco_frequency_lock_mode(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_OUTMD_MASK;
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_OUTMD_FLL_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_dco_phase_lock_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_dco_phase_lock_mode(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_OUTMD_PLL_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_disable_dco_output
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_disable_dco_output(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_OUTMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_lock_on_rising_edge
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_lock_on_rising_edge(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_EDGSEL_RISING_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_lock_on_falling_edge
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_lock_on_falling_edge(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_EDGSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_enable_dither
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_enable_dither(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_DITHEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_disable_dither
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_disable_dither(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_DITHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_enable_dco_update_stall
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_enable_dco_update_stall(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_STALL_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_disable_dco_update_stall
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_disable_dco_update_stall(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_STALL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_lock_threshold_value
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_lock_threshold_value(
   SI32_PLL_A_Type * basePointer,
   uint32_t threshold)
{
   assert(threshold < 4);   // threshold < 2^2
   //{{
   basePointer->CONTROL.LOCKTH = threshold;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_get_lock_threshold_value
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_get_lock_threshold_value(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.LOCKTH;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_reference_clock_source_rtc0osc
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_reference_clock_source_rtc0osc(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_reference_clock_source_lp0oscdiv
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_reference_clock_source_lp0oscdiv(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_LPOSC0DIV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_reference_clock_source_ext0osc
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_reference_clock_source_ext0osc(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_EXTOSC0_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_reference_clock_source_usb0osc
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_reference_clock_source_usb0osc(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_USBOSC0_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_reference_clock_source_lp0osc
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_reference_clock_source_lp0osc(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_LPOSC0_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_locked_interrupt_on_locked_mode
//
// 0 = interrupt will occur when PLL loses lock, 1 = interrupt will occur
// when PLL is locked.
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_locked_interrupt_on_locked_mode(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_select_locked_interrupt_on_unlocked_mode
//
// 0 = interrupt will occur when PLL loses lock, 1 = interrupt will occur
// when PLL is locked.
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_select_locked_interrupt_on_unlocked_mode(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_LCKPOL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_enable_locked_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_enable_locked_interrupt(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_LCKIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_disable_locked_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_disable_locked_interrupt(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_LCKIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_is_locked_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_PLL_A_is_locked_interrupt_enabled(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.LCKIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_enable_saturation_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_enable_saturation_interrupt(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_LMTIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_disable_saturation_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_disable_saturation_interrupt(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_LMTIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_is_saturation_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_PLL_A_is_saturation_interrupt_enabled(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.LMTIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_is_locked
//
//-----------------------------------------------------------------------------
bool
_SI32_PLL_A_is_locked(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.LCKI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_is_locked_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_PLL_A_is_locked_interrupt_pending(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return (bool)!(basePointer->CONTROL.LCKI ^ basePointer->CONTROL.LCKPOL);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_is_saturation_high_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_PLL_A_is_saturation_high_interrupt_pending(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.HLMTF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_is_saturation_low_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_PLL_A_is_saturation_low_interrupt_pending(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.LLMTF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_write_sspr
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_write_sspr(
   SI32_PLL_A_Type * basePointer,
   // Write to SSPR register.
   uint32_t sspr)
{
   //{{
   basePointer->SSPR.U32 = sspr;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_read_sspr
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_read_sspr(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->SSPR.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_spectrum_spreading_update_interval
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_spectrum_spreading_update_interval(
   SI32_PLL_A_Type * basePointer,
   // Interval is given by 4 * TDCO * (update_interval + 1).
   uint32_t update_interval)
{
   assert(update_interval < 32);   // update_interval < 2^5
   //{{
   basePointer->SSPR.SSUINV = update_interval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_spectrum_spreading_amplitude
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_spectrum_spreading_amplitude(
   SI32_PLL_A_Type * basePointer,
   // 0 = disabled, 1 = +/- 0.1% of TDCO, 2 = +/- 0.2% of TDCO, 3 = +/- 0.4%
   // of TDCO, 4 = +/- 0.8% of TDCO, 5 = +/- 1.6% of TDCO, 6-7 = reserved.
   SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_Enum_Type ss_amplitude)
{
   assert(ss_amplitude < 8);   // ss_amplitude < 2^3
   //{{
   basePointer->SSPR.SSAMP = ss_amplitude;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_write_calconfig
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_write_calconfig(
   SI32_PLL_A_Type * basePointer,
   // Write to CALCONFIG register.
   uint32_t calconfig)
{
   //{{
   basePointer->CALCONFIG.U32 = calconfig;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_read_calconfig
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_read_calconfig(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->CALCONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_output_frequency_range
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_output_frequency_range(
   SI32_PLL_A_Type * basePointer,
   // 0 = 23 to 37 MHz, 1 = 33 to 54 MHz, 2 = 45 to 71 MHz, 3 = 53 to 82
   // MHz, 4 = 73 to maximum SYSCLK MHz, 5-7 = reserved.
   SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_Enum_Type range)
{
   assert(range < 8);   // range < 2^3
   //{{
   basePointer->CALCONFIG.U32 &= ~SI32_PLL_A_CALCONFIG_RANGE_MASK;
   basePointer->CALCONFIG.U32 |= range << SI32_PLL_A_CALCONFIG_RANGE_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_frequency_adjuster_value
//
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_frequency_adjuster_value(
   SI32_PLL_A_Type * basePointer,
   uint32_t adjust_value)
{
   assert(adjust_value < 4096);   // adjust_value < 2^12
   //{{
   basePointer->CALCONFIG.U32 &= !SI32_PLL_A_CALCONFIG_CAL_MASK;
   basePointer->CALCONFIG.U32 |=
      adjust_value << SI32_PLL_A_CALCONFIG_CAL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_get_frequency_adjuster_value
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PLL_A_get_frequency_adjuster_value(
   SI32_PLL_A_Type * basePointer)
{
   //{{
   return basePointer->CALCONFIG.CAL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PLL_A_set_dithering_value
//
// Dithering controls how often a 1 is added to the frequency adjuster
// value (CAL) to create an average frequency in between two CAL settings
// (CAL and CAL + 1).
//-----------------------------------------------------------------------------
void
_SI32_PLL_A_set_dithering_value(
   SI32_PLL_A_Type * basePointer,
   uint32_t dither_value)
{
   assert(dither_value < 16);   // dither_value < 2^4
   //{{
   basePointer->CALCONFIG.U32 &= !SI32_PLL_A_CALCONFIG_DITHER_MASK;
   basePointer->CALCONFIG.U32 |=
      dither_value << SI32_PLL_A_CALCONFIG_DITHER_SHIFT;
   //}}
}


//-eof--------------------------------------------------------------------------
