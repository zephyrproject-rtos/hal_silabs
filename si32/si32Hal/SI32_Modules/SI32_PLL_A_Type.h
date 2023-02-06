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
/// @file SI32_PLL_A_Type.h
//
// Script: 0.62
// HAL Source: 0.7
// Version: 1

#ifndef __SI32_PLL_A_TYPE_H__
#define __SI32_PLL_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_PLL_A_Registers.h"
#include "SI32_PLL_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_PLL_A_initialize(SI32_PLL_A_Type* basePointer,
///      uint32_t divider,
///      uint32_t control,
///      uint32_t sspr,
///      uint32_t calconfig)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divider
///  Valid range is 32 bits.
///  Write to DIVIDER register.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
/// @param[in]
///  sspr
///  Valid range is 32 bits.
///  Write to SSPR register.
///
/// @param[in]
///  calconfig
///  Valid range is 32 bits.
///  Write to CALCONFIG register.
///
void
_SI32_PLL_A_initialize(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t, /*divider*/
   uint32_t, /*control*/
   uint32_t, /*sspr*/
   uint32_t /*calconfig*/);
///
/// @def SI32_PLL_A_initialize(basePointer, divider, control, sspr, calconfig)
#define SI32_PLL_A_initialize(basePointer, divider, control, sspr, calconfig) do{  \
   basePointer->DIVIDER.U32 = divider;\
   basePointer->CONTROL.U32 = control;\
   basePointer->SSPR.U32 = sspr;\
   basePointer->CALCONFIG.U32 = calconfig;\
} while(0)


/// @fn _SI32_PLL_A_write_divider(SI32_PLL_A_Type* basePointer,
///      uint32_t divider)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divider
///  Valid range is 32 bits.
///  Write to DIVIDER register.
///
void
_SI32_PLL_A_write_divider(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*divider*/);
///
/// @def SI32_PLL_A_write_divider(basePointer, divider)
#define SI32_PLL_A_write_divider(basePointer, divider) \
   (basePointer->DIVIDER.U32 = divider)


/// @fn _SI32_PLL_A_read_divider(SI32_PLL_A_Type* basePointer)
///
/// @return
///  Read DIVIDER register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_read_divider(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_read_divider(basePointer)
#define SI32_PLL_A_read_divider(basePointer) \
(basePointer->DIVIDER.U32)


/// @fn _SI32_PLL_A_set_numerator(SI32_PLL_A_Type* basePointer,
///      uint32_t n_value)
///
/// @brief
/// PLL output frequency is reference frequency * (N/M). N is stored as
/// N-1 in the register. set_numerator will perform the -1 for you and
/// should be passed the actual numerator.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  n_value
///  Valid range is 12 bits.
///
void
_SI32_PLL_A_set_numerator(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*n_value*/);
///
/// @def SI32_PLL_A_set_numerator(basePointer, n_value)
#define SI32_PLL_A_set_numerator(basePointer, n_value) do{  \
   basePointer->DIVIDER.U32 =\
      ((basePointer->DIVIDER.U32) & ~SI32_PLL_A_DIVIDER_N_MASK) |\
     ((n_value - 1) << SI32_PLL_A_DIVIDER_N_SHIFT);\
} while(0)


/// @fn _SI32_PLL_A_get_numerator(SI32_PLL_A_Type* basePointer)
///
/// @return
///  Return N.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_get_numerator(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_get_numerator(basePointer)
#define SI32_PLL_A_get_numerator(basePointer) \
(basePointer->DIVIDER.N)


/// @fn _SI32_PLL_A_set_denominator(SI32_PLL_A_Type* basePointer,
///      uint32_t m_value)
///
/// @brief
/// PLL output frequency is reference frequency * (N/M). M is stored as
/// M-1 in the register. set_denominator will perform the -1 for you and
/// should be passed the actual numerator.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  m_value
///  Valid range is 12 bits.
///
void
_SI32_PLL_A_set_denominator(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*m_value*/);
///
/// @def SI32_PLL_A_set_denominator(basePointer, m_value)
#define SI32_PLL_A_set_denominator(basePointer, m_value) do{  \
   basePointer->DIVIDER.U32 =\
     ((basePointer->DIVIDER.U32) & ~SI32_PLL_A_DIVIDER_M_MASK) | (m_value - 1);\
} while(0)


/// @fn _SI32_PLL_A_get_denominator(SI32_PLL_A_Type* basePointer)
///
/// @return
///  Return M.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_get_denominator(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_get_denominator(basePointer)
#define SI32_PLL_A_get_denominator(basePointer) \
(basePointer->DIVIDER.M)


/// @fn _SI32_PLL_A_write_control(SI32_PLL_A_Type* basePointer,
///      uint32_t control)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
void
_SI32_PLL_A_write_control(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_PLL_A_write_control(basePointer, control)
#define SI32_PLL_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_PLL_A_read_control(SI32_PLL_A_Type* basePointer)
///
/// @return
///  Read CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_read_control(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_read_control(basePointer)
#define SI32_PLL_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_PLL_A_select_dco_free_running_mode(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_dco_free_running_mode(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_dco_free_running_mode(basePointer)
#define SI32_PLL_A_select_dco_free_running_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_OUTMD_MASK;\
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_OUTMD_DCO_U32;\
} while(0)


/// @fn _SI32_PLL_A_select_dco_frequency_lock_mode(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_dco_frequency_lock_mode(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_dco_frequency_lock_mode(basePointer)
#define SI32_PLL_A_select_dco_frequency_lock_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_OUTMD_MASK;\
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_OUTMD_FLL_U32;\
} while(0)


/// @fn _SI32_PLL_A_select_dco_phase_lock_mode(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_dco_phase_lock_mode(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_dco_phase_lock_mode(basePointer)
#define SI32_PLL_A_select_dco_phase_lock_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_OUTMD_PLL_U32)


/// @fn _SI32_PLL_A_select_disable_dco_output(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_disable_dco_output(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_disable_dco_output(basePointer)
#define SI32_PLL_A_select_disable_dco_output(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_OUTMD_MASK)


/// @fn _SI32_PLL_A_lock_on_rising_edge(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_lock_on_rising_edge(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_lock_on_rising_edge(basePointer)
#define SI32_PLL_A_lock_on_rising_edge(basePointer) \
   (basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_EDGSEL_RISING_EDGE_U32)


/// @fn _SI32_PLL_A_lock_on_falling_edge(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_lock_on_falling_edge(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_lock_on_falling_edge(basePointer)
#define SI32_PLL_A_lock_on_falling_edge(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_EDGSEL_MASK)


/// @fn _SI32_PLL_A_enable_dither(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_enable_dither(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_enable_dither(basePointer)
#define SI32_PLL_A_enable_dither(basePointer) \
   (basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_DITHEN_ENABLED_U32)


/// @fn _SI32_PLL_A_disable_dither(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_disable_dither(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_disable_dither(basePointer)
#define SI32_PLL_A_disable_dither(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_DITHEN_MASK)


/// @fn _SI32_PLL_A_enable_dco_update_stall(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_enable_dco_update_stall(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_enable_dco_update_stall(basePointer)
#define SI32_PLL_A_enable_dco_update_stall(basePointer) \
   (basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_STALL_ENABLED_U32)


/// @fn _SI32_PLL_A_disable_dco_update_stall(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_disable_dco_update_stall(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_disable_dco_update_stall(basePointer)
#define SI32_PLL_A_disable_dco_update_stall(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_STALL_MASK)


/// @fn _SI32_PLL_A_set_lock_threshold_value(SI32_PLL_A_Type* basePointer,
///      uint32_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 2 bits.
///
void
_SI32_PLL_A_set_lock_threshold_value(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*threshold*/);
///
/// @def SI32_PLL_A_set_lock_threshold_value(basePointer, threshold)
#define SI32_PLL_A_set_lock_threshold_value(basePointer, threshold) \
   (basePointer->CONTROL.LOCKTH = threshold)


/// @fn _SI32_PLL_A_get_lock_threshold_value(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_get_lock_threshold_value(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_get_lock_threshold_value(basePointer)
#define SI32_PLL_A_get_lock_threshold_value(basePointer) \
(basePointer->CONTROL.LOCKTH)


/// @fn _SI32_PLL_A_select_reference_clock_source_rtc0osc(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_reference_clock_source_rtc0osc(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_reference_clock_source_rtc0osc(basePointer)
#define SI32_PLL_A_select_reference_clock_source_rtc0osc(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK)


/// @fn _SI32_PLL_A_select_reference_clock_source_lp0oscdiv(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_reference_clock_source_lp0oscdiv(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_reference_clock_source_lp0oscdiv(basePointer)
#define SI32_PLL_A_select_reference_clock_source_lp0oscdiv(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;\
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_LPOSC0DIV_U32;\
} while(0)


/// @fn _SI32_PLL_A_select_reference_clock_source_ext0osc(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_reference_clock_source_ext0osc(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_reference_clock_source_ext0osc(basePointer)
#define SI32_PLL_A_select_reference_clock_source_ext0osc(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;\
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_EXTOSC0_U32;\
} while(0)


/// @fn _SI32_PLL_A_select_reference_clock_source_usb0osc(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_reference_clock_source_usb0osc(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_reference_clock_source_usb0osc(basePointer)
#define SI32_PLL_A_select_reference_clock_source_usb0osc(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;\
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_USBOSC0_U32;\
} while(0)


/// @fn _SI32_PLL_A_select_reference_clock_source_lp0osc(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_reference_clock_source_lp0osc(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_reference_clock_source_lp0osc(basePointer)
#define SI32_PLL_A_select_reference_clock_source_lp0osc(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_REFSEL_MASK;\
   basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_REFSEL_LPOSC0_U32;\
} while(0)


/// @fn _SI32_PLL_A_select_locked_interrupt_on_locked_mode(SI32_PLL_A_Type* basePointer)
///
/// @brief
/// 0 = interrupt will occur when PLL loses lock, 1 = interrupt will occur
/// when PLL is locked.
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_locked_interrupt_on_locked_mode(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_locked_interrupt_on_locked_mode(basePointer)
#define SI32_PLL_A_select_locked_interrupt_on_locked_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_HIGH_U32)


/// @fn _SI32_PLL_A_select_locked_interrupt_on_unlocked_mode(SI32_PLL_A_Type* basePointer)
///
/// @brief
/// 0 = interrupt will occur when PLL loses lock, 1 = interrupt will occur
/// when PLL is locked.
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_select_locked_interrupt_on_unlocked_mode(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_select_locked_interrupt_on_unlocked_mode(basePointer)
#define SI32_PLL_A_select_locked_interrupt_on_unlocked_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_LCKPOL_MASK)


/// @fn _SI32_PLL_A_enable_locked_interrupt(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_enable_locked_interrupt(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_enable_locked_interrupt(basePointer)
#define SI32_PLL_A_enable_locked_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_LCKIEN_ENABLED_U32)


/// @fn _SI32_PLL_A_disable_locked_interrupt(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_disable_locked_interrupt(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_disable_locked_interrupt(basePointer)
#define SI32_PLL_A_disable_locked_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_LCKIEN_MASK)


/// @fn _SI32_PLL_A_is_locked_interrupt_enabled(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_PLL_A_is_locked_interrupt_enabled(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_is_locked_interrupt_enabled(basePointer)
#define SI32_PLL_A_is_locked_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.LCKIEN))


/// @fn _SI32_PLL_A_enable_saturation_interrupt(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_enable_saturation_interrupt(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_enable_saturation_interrupt(basePointer)
#define SI32_PLL_A_enable_saturation_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_PLL_A_CONTROL_LMTIEN_ENABLED_U32)


/// @fn _SI32_PLL_A_disable_saturation_interrupt(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PLL_A_disable_saturation_interrupt(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_disable_saturation_interrupt(basePointer)
#define SI32_PLL_A_disable_saturation_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_PLL_A_CONTROL_LMTIEN_MASK)


/// @fn _SI32_PLL_A_is_saturation_interrupt_enabled(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_PLL_A_is_saturation_interrupt_enabled(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_is_saturation_interrupt_enabled(basePointer)
#define SI32_PLL_A_is_saturation_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.LMTIEN))


/// @fn _SI32_PLL_A_is_locked(SI32_PLL_A_Type* basePointer)
///
/// @return
///  True = pll locked.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PLL_A_is_locked(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_is_locked(basePointer)
#define SI32_PLL_A_is_locked(basePointer) \
((bool)(basePointer->CONTROL.LCKI))


/// @fn _SI32_PLL_A_is_locked_interrupt_pending(SI32_PLL_A_Type* basePointer)
///
/// @return
///  True = interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PLL_A_is_locked_interrupt_pending(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_is_locked_interrupt_pending(basePointer)
#define SI32_PLL_A_is_locked_interrupt_pending(basePointer) \
((bool)!(basePointer->CONTROL.LCKI ^ basePointer->CONTROL.LCKPOL))


/// @fn _SI32_PLL_A_is_saturation_high_interrupt_pending(SI32_PLL_A_Type* basePointer)
///
/// @return
///  True = saturated high, RANGE value should be decreased.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PLL_A_is_saturation_high_interrupt_pending(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_is_saturation_high_interrupt_pending(basePointer)
#define SI32_PLL_A_is_saturation_high_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.HLMTF))


/// @fn _SI32_PLL_A_is_saturation_low_interrupt_pending(SI32_PLL_A_Type* basePointer)
///
/// @return
///  True = saturated low, RANGE value should be increased.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PLL_A_is_saturation_low_interrupt_pending(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_is_saturation_low_interrupt_pending(basePointer)
#define SI32_PLL_A_is_saturation_low_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.LLMTF))


/// @fn _SI32_PLL_A_write_sspr(SI32_PLL_A_Type* basePointer,
///      uint32_t sspr)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  sspr
///  Valid range is 32 bits.
///  Write to SSPR register.
///
void
_SI32_PLL_A_write_sspr(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*sspr*/);
///
/// @def SI32_PLL_A_write_sspr(basePointer, sspr)
#define SI32_PLL_A_write_sspr(basePointer, sspr) \
   (basePointer->SSPR.U32 = sspr)


/// @fn _SI32_PLL_A_read_sspr(SI32_PLL_A_Type* basePointer)
///
/// @return
///  Read SSPR register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_read_sspr(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_read_sspr(basePointer)
#define SI32_PLL_A_read_sspr(basePointer) \
(basePointer->SSPR.U32)


/// @fn _SI32_PLL_A_set_spectrum_spreading_update_interval(SI32_PLL_A_Type* basePointer,
///      uint32_t update_interval)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  update_interval
///  Valid range is 5 bits.
///  Interval is given by 4 * TDCO * (update_interval + 1).
///
void
_SI32_PLL_A_set_spectrum_spreading_update_interval(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*update_interval*/);
///
/// @def SI32_PLL_A_set_spectrum_spreading_update_interval(basePointer, update_interval)
#define SI32_PLL_A_set_spectrum_spreading_update_interval(basePointer, update_interval) \
   (basePointer->SSPR.SSUINV = update_interval)


/// @fn _SI32_PLL_A_set_spectrum_spreading_amplitude(SI32_PLL_A_Type* basePointer,
///      SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_Enum_Type ss_amplitude)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ss_amplitude
///  Valid range is 3 bits.
///  0 = disabled, 1 = +/- 0.1% of TDCO, 2 = +/- 0.2% of TDCO, 3 = +/- 0.4%
///  of TDCO, 4 = +/- 0.8% of TDCO, 5 = +/- 1.6% of TDCO, 6-7 = reserved.
///
void
_SI32_PLL_A_set_spectrum_spreading_amplitude(SI32_PLL_A_Type* /*basePointer*/,
   SI32_PLL_A_SPECTRUM_SPREADING_AMPLITUDE_Enum_Type /*ss_amplitude*/);
///
/// @def SI32_PLL_A_set_spectrum_spreading_amplitude(basePointer, ss_amplitude)
#define SI32_PLL_A_set_spectrum_spreading_amplitude(basePointer, ss_amplitude) \
   (basePointer->SSPR.SSAMP = ss_amplitude)


/// @fn _SI32_PLL_A_write_calconfig(SI32_PLL_A_Type* basePointer,
///      uint32_t calconfig)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  calconfig
///  Valid range is 32 bits.
///  Write to CALCONFIG register.
///
void
_SI32_PLL_A_write_calconfig(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*calconfig*/);
///
/// @def SI32_PLL_A_write_calconfig(basePointer, calconfig)
#define SI32_PLL_A_write_calconfig(basePointer, calconfig) \
   (basePointer->CALCONFIG.U32 = calconfig)


/// @fn _SI32_PLL_A_read_calconfig(SI32_PLL_A_Type* basePointer)
///
/// @return
///  Read CALCONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_read_calconfig(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_read_calconfig(basePointer)
#define SI32_PLL_A_read_calconfig(basePointer) \
(basePointer->CALCONFIG.U32)


/// @fn _SI32_PLL_A_set_output_frequency_range(SI32_PLL_A_Type* basePointer,
///      SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_Enum_Type range)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  range
///  Valid range is 3 bits.
///  0 = 23 to 37 MHz, 1 = 33 to 54 MHz, 2 = 45 to 71 MHz, 3 = 53 to 82
///  MHz, 4 = 73 to maximum SYSCLK MHz, 5-7 = reserved.
///
void
_SI32_PLL_A_set_output_frequency_range(SI32_PLL_A_Type* /*basePointer*/,
   SI32_PLL_A_OUTPUT_FREQUENCY_RANGE_Enum_Type /*range*/);
///
/// @def SI32_PLL_A_set_output_frequency_range(basePointer, range)
#define SI32_PLL_A_set_output_frequency_range(basePointer, range) do{  \
   basePointer->CALCONFIG.U32 &= ~SI32_PLL_A_CALCONFIG_RANGE_MASK;\
   basePointer->CALCONFIG.U32 |= range << SI32_PLL_A_CALCONFIG_RANGE_SHIFT;\
} while(0)


/// @fn _SI32_PLL_A_set_frequency_adjuster_value(SI32_PLL_A_Type* basePointer,
///      uint32_t adjust_value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  adjust_value
///  Valid range is 12 bits.
///
void
_SI32_PLL_A_set_frequency_adjuster_value(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*adjust_value*/);
///
/// @def SI32_PLL_A_set_frequency_adjuster_value(basePointer, adjust_value)
#define SI32_PLL_A_set_frequency_adjuster_value(basePointer, adjust_value) do{  \
   basePointer->CALCONFIG.U32 &= !SI32_PLL_A_CALCONFIG_CAL_MASK;\
   basePointer->CALCONFIG.U32 |=\
      adjust_value << SI32_PLL_A_CALCONFIG_CAL_SHIFT;\
} while(0)


/// @fn _SI32_PLL_A_get_frequency_adjuster_value(SI32_PLL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PLL_A_get_frequency_adjuster_value(SI32_PLL_A_Type* /*basePointer*/);
///
/// @def SI32_PLL_A_get_frequency_adjuster_value(basePointer)
#define SI32_PLL_A_get_frequency_adjuster_value(basePointer) \
(basePointer->CALCONFIG.CAL)


/// @fn _SI32_PLL_A_set_dithering_value(SI32_PLL_A_Type* basePointer,
///      uint32_t dither_value)
///
/// @brief
/// Dithering controls how often a 1 is added to the frequency adjuster
/// value (CAL) to create an average frequency in between two CAL settings
/// (CAL and CAL + 1).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dither_value
///  Valid range is 4 bits.
///
void
_SI32_PLL_A_set_dithering_value(SI32_PLL_A_Type* /*basePointer*/,
   uint32_t /*dither_value*/);
///
/// @def SI32_PLL_A_set_dithering_value(basePointer, dither_value)
#define SI32_PLL_A_set_dithering_value(basePointer, dither_value) do{  \
   basePointer->CALCONFIG.U32 &= !SI32_PLL_A_CALCONFIG_DITHER_MASK;\
   basePointer->CALCONFIG.U32 |=\
      dither_value << SI32_PLL_A_CALCONFIG_DITHER_SHIFT;\
} while(0)



#ifdef __cplusplus
}
#endif

#endif // __SI32_PLL_A_TYPE_H__

//-eof--------------------------------------------------------------------------
