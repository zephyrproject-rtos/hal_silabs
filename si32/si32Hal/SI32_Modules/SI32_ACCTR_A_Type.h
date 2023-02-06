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
/// @file SI32_ACCTR_A_Type.h
//
// Script: 0.62
// HAL Source: 0.8
// Version: 1

#ifndef __SI32_ACCTR_A_TYPE_H__
#define __SI32_ACCTR_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_ACCTR_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_ACCTR_A_initialize_module(SI32_ACCTR_A_Type* basePointer,
///      uint32_t config,
///      uint32_t control,
///      uint32_t lcconfig,
///      uint32_t lctiming,
///      uint32_t lcmode,
///      uint32_t lcclkcontrol,
///      uint32_t lccount,
///      uint32_t dbconfig,
///      uint32_t comp0,
///      uint32_t comp1)
///
/// @brief
/// Initialize Module.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  lcconfig
///  Valid range is 32 bits.
///
/// @param[in]
///  lctiming
///  Valid range is 32 bits.
///
/// @param[in]
///  lcmode
///  Valid range is 32 bits.
///
/// @param[in]
///  lcclkcontrol
///  Valid range is 32 bits.
///
/// @param[in]
///  lccount
///  Valid range is 32 bits.
///
/// @param[in]
///  dbconfig
///  Valid range is 32 bits.
///
/// @param[in]
///  comp0
///  Valid range is 32 bits.
///
/// @param[in]
///  comp1
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_initialize_module(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*control*/
   uint32_t, /*lcconfig*/
   uint32_t, /*lctiming*/
   uint32_t, /*lcmode*/
   uint32_t, /*lcclkcontrol*/
   uint32_t, /*lccount*/
   uint32_t, /*dbconfig*/
   uint32_t, /*comp0*/
   uint32_t /*comp1*/);
///
/// @def SI32_ACCTR_A_initialize_module(basePointer, config, control, lcconfig, lctiming, lcmode, lcclkcontrol, lccount, dbconfig, comp0, comp1)
#define SI32_ACCTR_A_initialize_module(basePointer, config, control, lcconfig, lctiming, lcmode, lcclkcontrol, lccount, dbconfig, comp0, comp1) do{  \
   basePointer->CONFIG.U32=config;\
   basePointer->CONTROL.U32=control;\
   basePointer->LCCONFIG.U32=lcconfig;\
   basePointer->TIMING.U32=lctiming;\
   basePointer->LCMODE.U32=lcmode;\
   basePointer->LCCLKCONTROL.U32=lcclkcontrol;\
   basePointer->LCCOUNT.U32=lccount;\
   basePointer->DBCONFIG.U32=dbconfig;\
   basePointer->COMP0.U32=comp0;\
   basePointer->COMP1.U32=comp1;\
} while(0)


/// @fn _SI32_ACCTR_A_write_config(SI32_ACCTR_A_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Write to CONFIG register. Writing to this register resets the module.
/// Sequential writes to this register require polling on the write status
/// flag UPDSTSF.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_config(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_ACCTR_A_write_config(basePointer, config)
#define SI32_ACCTR_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_ACCTR_A_read_config(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_config(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_config(basePointer)
#define SI32_ACCTR_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_ACCTR_A_reset_module(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_reset_module(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_reset_module(basePointer)
#define SI32_ACCTR_A_reset_module(basePointer) \
   (basePointer->CONFIG.U32 = (basePointer->CONFIG.U32))


/// @fn _SI32_ACCTR_A_disable_module(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_module(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_module(basePointer)
#define SI32_ACCTR_A_disable_module(basePointer) \
   (basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_is_write_in_progress(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_write_in_progress(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_write_in_progress(basePointer)
#define SI32_ACCTR_A_is_write_in_progress(basePointer) \
(basePointer->CONFIG.UPDSTSF)


/// @fn _SI32_ACCTR_A_select_no_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_no_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_no_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_no_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_NONE_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_cmp0_and_cmp1_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_cmp0_and_cmp1_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_cmp0_and_cmp1_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_lc_mode_cmp0_and_cmp1_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_LCC1_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_cmp0_and_integ0_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_cmp0_and_integ0_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_cmp0_and_integ0_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_lc_mode_cmp0_and_integ0_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_LCC0_INT0_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_cmp1_and_integ1_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_cmp1_and_integ1_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_cmp1_and_integ1_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_lc_mode_cmp1_and_integ1_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_LCC1_INT1_VALUE)


/// @fn _SI32_ACCTR_A_select_integ0_and_integ1_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_integ0_and_integ1_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_integ0_and_integ1_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_integ0_and_integ1_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_INT0_INT1_VALUE)


/// @fn _SI32_ACCTR_A_select_switch_mode_cmp0_and_cmp1_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_switch_mode_cmp0_and_cmp1_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_switch_mode_cmp0_and_cmp1_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_switch_mode_cmp0_and_cmp1_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_CMP1_VALUE)


/// @fn _SI32_ACCTR_A_select_switch_mode_cmp0_and_integ0_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_switch_mode_cmp0_and_integ0_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_switch_mode_cmp0_and_integ0_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_switch_mode_cmp0_and_integ0_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_CMP0_INT0_VALUE)


/// @fn _SI32_ACCTR_A_select_switch_mode_cmp1_and_integ1_debug_outputs(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_switch_mode_cmp1_and_integ1_debug_outputs(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_switch_mode_cmp1_and_integ1_debug_outputs(basePointer)
#define SI32_ACCTR_A_select_switch_mode_cmp1_and_integ1_debug_outputs(basePointer) \
   (basePointer->CONFIG.DBGSEL = SI32_ACCTR_A_CONFIG_DBGSEL_CMP1_INT1_VALUE)


/// @fn _SI32_ACCTR_A_enable_switch_from_quadrature_to_dual_on_flutter(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_switch_from_quadrature_to_dual_on_flutter(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_switch_from_quadrature_to_dual_on_flutter(basePointer)
#define SI32_ACCTR_A_enable_switch_from_quadrature_to_dual_on_flutter(basePointer) \
   (basePointer->CONFIG.FLQDEN = SI32_ACCTR_A_CONFIG_FLQDEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_switch_from_quadrature_to_dual_on_flutter(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_switch_from_quadrature_to_dual_on_flutter(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_switch_from_quadrature_to_dual_on_flutter(basePointer)
#define SI32_ACCTR_A_disable_switch_from_quadrature_to_dual_on_flutter(basePointer) \
   (basePointer->CONFIG.FLQDEN = SI32_ACCTR_A_CONFIG_FLQDEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_stop_count_on_flutter(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_stop_count_on_flutter(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_stop_count_on_flutter(basePointer)
#define SI32_ACCTR_A_enable_stop_count_on_flutter(basePointer) \
   (basePointer->CONFIG.FLSTPEN = SI32_ACCTR_A_CONFIG_FLSTPEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_stop_count_on_flutter(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_stop_count_on_flutter(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_stop_count_on_flutter(basePointer)
#define SI32_ACCTR_A_disable_stop_count_on_flutter(basePointer) \
   (basePointer->CONFIG.FLSTPEN = SI32_ACCTR_A_CONFIG_FLSTPEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_reed_switch_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_reed_switch_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_reed_switch_mode(basePointer)
#define SI32_ACCTR_A_select_reed_switch_mode(basePointer) \
   (basePointer->CONFIG.TOPMD = SI32_ACCTR_A_CONFIG_TOPMD_SWITCH_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode(basePointer)
#define SI32_ACCTR_A_select_lc_mode(basePointer) \
   (basePointer->CONFIG.TOPMD = SI32_ACCTR_A_CONFIG_TOPMD_LC_VALUE)


/// @fn _SI32_ACCTR_A_select_single_channel_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_single_channel_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_single_channel_mode(basePointer)
#define SI32_ACCTR_A_select_single_channel_mode(basePointer) \
   (basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_SINGLE_VALUE)


/// @fn _SI32_ACCTR_A_select_dual_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_dual_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_dual_mode(basePointer)
#define SI32_ACCTR_A_select_dual_mode(basePointer) \
   (basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_DUAL_VALUE)


/// @fn _SI32_ACCTR_A_select_quadrature_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_quadrature_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_quadrature_mode(basePointer)
#define SI32_ACCTR_A_select_quadrature_mode(basePointer) \
   (basePointer->CONFIG.PCMD = SI32_ACCTR_A_CONFIG_PCMD_QUADRATURE_VALUE)


/// @fn _SI32_ACCTR_A_write_control(SI32_ACCTR_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Write to CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_control(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_ACCTR_A_write_control(basePointer, control)
#define SI32_ACCTR_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_ACCTR_A_read_control(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_control(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_control(basePointer)
#define SI32_ACCTR_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_ACCTR_A_select_analog_comparator_low_threshold_32_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_32_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_low_threshold_32_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_low_threshold_32_percent(basePointer) do{  \
   basePointer->CONTROL.CMPLTH =\
      SI32_ACCTR_A_CONTROL_CMPLTH_32_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_analog_comparator_low_threshold_36_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_36_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_low_threshold_36_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_low_threshold_36_percent(basePointer) do{  \
   basePointer->CONTROL.CMPLTH =\
      SI32_ACCTR_A_CONTROL_CMPLTH_36_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_analog_comparator_low_threshold_40_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_40_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_low_threshold_40_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_low_threshold_40_percent(basePointer) do{  \
   basePointer->CONTROL.CMPLTH =\
      SI32_ACCTR_A_CONTROL_CMPLTH_40_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_analog_comparator_low_threshold_44_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_low_threshold_44_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_low_threshold_44_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_low_threshold_44_percent(basePointer) do{  \
   basePointer->CONTROL.CMPLTH =\
      SI32_ACCTR_A_CONTROL_CMPLTH_44_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_analog_comparator_high_threshold_48_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_48_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_high_threshold_48_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_high_threshold_48_percent(basePointer) do{  \
   basePointer->CONTROL.CMPHTH =\
      SI32_ACCTR_A_CONTROL_CMPHTH_48_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_analog_comparator_high_threshold_52_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_52_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_high_threshold_52_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_high_threshold_52_percent(basePointer) do{  \
   basePointer->CONTROL.CMPHTH =\
      SI32_ACCTR_A_CONTROL_CMPHTH_52_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_analog_comparator_high_threshold_56_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_56_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_high_threshold_56_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_high_threshold_56_percent(basePointer) do{  \
   basePointer->CONTROL.CMPHTH =\
      SI32_ACCTR_A_CONTROL_CMPHTH_56_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_analog_comparator_high_threshold_60_percent(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_analog_comparator_high_threshold_60_percent(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_analog_comparator_high_threshold_60_percent(basePointer)
#define SI32_ACCTR_A_select_analog_comparator_high_threshold_60_percent(basePointer) do{  \
   basePointer->CONTROL.CMPHTH =\
      SI32_ACCTR_A_CONTROL_CMPHTH_60_PERCENT_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_select_calibrate_until_pass(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_calibrate_until_pass(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_calibrate_until_pass(basePointer)
#define SI32_ACCTR_A_select_calibrate_until_pass(basePointer) \
   (basePointer->CONTROL.CALMD = SI32_ACCTR_A_CONTROL_CALMD_UNTIL_PASS_VALUE)


/// @fn _SI32_ACCTR_A_select_calibrate_until_fail(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_calibrate_until_fail(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_calibrate_until_fail(basePointer)
#define SI32_ACCTR_A_select_calibrate_until_fail(basePointer) \
   (basePointer->CONTROL.CALMD = SI32_ACCTR_A_CONTROL_CALMD_UNTIL_FAIL_VALUE)


/// @fn _SI32_ACCTR_A_select_full_pull_up_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_full_pull_up_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_full_pull_up_mode(basePointer)
#define SI32_ACCTR_A_select_full_pull_up_mode(basePointer) \
   (basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_FULL_VALUE)


/// @fn _SI32_ACCTR_A_select_small_pull_up_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_small_pull_up_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_small_pull_up_mode(basePointer)
#define SI32_ACCTR_A_select_small_pull_up_mode(basePointer) \
   (basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_SMALL_VALUE)


/// @fn _SI32_ACCTR_A_select_medium_pull_up_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_medium_pull_up_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_medium_pull_up_mode(basePointer)
#define SI32_ACCTR_A_select_medium_pull_up_mode(basePointer) \
   (basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_MEDIUM_VALUE)


/// @fn _SI32_ACCTR_A_select_large_pull_up_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_large_pull_up_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_large_pull_up_mode(basePointer)
#define SI32_ACCTR_A_select_large_pull_up_mode(basePointer) \
   (basePointer->CONTROL.CALPUMD = SI32_ACCTR_A_CONTROL_CALPUMD_LARGE_VALUE)


/// @fn _SI32_ACCTR_A_enable_force_continuous_pull_ups(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_force_continuous_pull_ups(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_force_continuous_pull_ups(basePointer)
#define SI32_ACCTR_A_enable_force_continuous_pull_ups(basePointer) \
   (basePointer->CONTROL.FPUPEN = SI32_ACCTR_A_CONTROL_FPUPEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_force_continuous_pull_ups(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_force_continuous_pull_ups(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_force_continuous_pull_ups(basePointer)
#define SI32_ACCTR_A_disable_force_continuous_pull_ups(basePointer) \
   (basePointer->CONTROL.FPUPEN = SI32_ACCTR_A_CONTROL_FPUPEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_force_input_to_ground(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_force_input_to_ground(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_force_input_to_ground(basePointer)
#define SI32_ACCTR_A_enable_force_input_to_ground(basePointer) \
   (basePointer->CONTROL.FPDNEN = SI32_ACCTR_A_CONTROL_FPDNEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_force_input_to_ground(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_force_input_to_ground(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_force_input_to_ground(basePointer)
#define SI32_ACCTR_A_disable_force_input_to_ground(basePointer) \
   (basePointer->CONTROL.FPDNEN = SI32_ACCTR_A_CONTROL_FPDNEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_set_pull_up_value(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t puval)
///
/// @brief
/// Set pull-up value.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  puval
///  Valid range is 5 bits.
///
void
_SI32_ACCTR_A_set_pull_up_value(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*puval*/);
///
/// @def SI32_ACCTR_A_set_pull_up_value(basePointer, puval)
#define SI32_ACCTR_A_set_pull_up_value(basePointer, puval) \
   (basePointer->CONTROL.PUVAL = puval)


/// @fn _SI32_ACCTR_A_get_pull_up_value(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Get pull-up value.
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_pull_up_value(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_pull_up_value(basePointer)
#define SI32_ACCTR_A_get_pull_up_value(basePointer) \
(basePointer->CONTROL.PUVAL)


/// @fn _SI32_ACCTR_A_select_calibrate_pc0(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_calibrate_pc0(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_calibrate_pc0(basePointer)
#define SI32_ACCTR_A_select_calibrate_pc0(basePointer) \
   (basePointer->CONTROL.CALSEL = SI32_ACCTR_A_CONTROL_CALSEL_IN0_VALUE)


/// @fn _SI32_ACCTR_A_select_calibrate_pc1(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_calibrate_pc1(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_calibrate_pc1(basePointer)
#define SI32_ACCTR_A_select_calibrate_pc1(basePointer) \
   (basePointer->CONTROL.CALSEL = SI32_ACCTR_A_CONTROL_CALSEL_IN1_VALUE)


/// @fn _SI32_ACCTR_A_was_calibration_successful(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_was_calibration_successful(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_was_calibration_successful(basePointer)
#define SI32_ACCTR_A_was_calibration_successful(basePointer) \
(basePointer->CONTROL.CALRF)


/// @fn _SI32_ACCTR_A_start_calibration(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_start_calibration(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_start_calibration(basePointer)
#define SI32_ACCTR_A_start_calibration(basePointer) \
   (basePointer->CONTROL.CALBUSYF = SI32_ACCTR_A_CONTROL_CALBUSYF_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_calibration_busy(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_calibration_busy(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_calibration_busy(basePointer)
#define SI32_ACCTR_A_is_calibration_busy(basePointer) \
(basePointer->CONTROL.CALBUSYF)


/// @fn _SI32_ACCTR_A_write_lcconfig(SI32_ACCTR_A_Type* basePointer,
///      uint32_t lcconfig)
///
/// @brief
/// Write to LCCONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  lcconfig
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_lcconfig(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*lcconfig*/);
///
/// @def SI32_ACCTR_A_write_lcconfig(basePointer, lcconfig)
#define SI32_ACCTR_A_write_lcconfig(basePointer, lcconfig) \
   (basePointer->LCCONFIG.U32=lcconfig)


/// @fn _SI32_ACCTR_A_read_lcconfig(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from LCCONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_lcconfig(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_lcconfig(basePointer)
#define SI32_ACCTR_A_read_lcconfig(basePointer) \
(basePointer->LCCONFIG.U32)


/// @fn _SI32_ACCTR_A_select_extend_low_pulses(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_extend_low_pulses(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_extend_low_pulses(basePointer)
#define SI32_ACCTR_A_select_extend_low_pulses(basePointer) \
   (basePointer->LCCONFIG.PEMD = SI32_ACCTR_A_LCCONFIG_PEMD_LOW_VALUE)


/// @fn _SI32_ACCTR_A_select_extend_high_pulses(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_extend_high_pulses(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_extend_high_pulses(basePointer)
#define SI32_ACCTR_A_select_extend_high_pulses(basePointer) \
   (basePointer->LCCONFIG.PEMD = SI32_ACCTR_A_LCCONFIG_PEMD_HIGH_VALUE)


/// @fn _SI32_ACCTR_A_select_no_pulse_extension(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_no_pulse_extension(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_no_pulse_extension(basePointer)
#define SI32_ACCTR_A_select_no_pulse_extension(basePointer) \
   (basePointer->LCCONFIG.PEMD = SI32_ACCTR_A_LCCONFIG_PEMD_NONE_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_0_full_range(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_0_full_range(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_0_full_range(basePointer)
#define SI32_ACCTR_A_select_comparator_0_full_range(basePointer) \
   (basePointer->LCCONFIG.CMP0THR = SI32_ACCTR_A_LCCONFIG_CMP0THR_FULL_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_0_low_range(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_0_low_range(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_0_low_range(basePointer)
#define SI32_ACCTR_A_select_comparator_0_low_range(basePointer) \
   (basePointer->LCCONFIG.CMP0THR = SI32_ACCTR_A_LCCONFIG_CMP0THR_LOW_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_1_full_range(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_1_full_range(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_1_full_range(basePointer)
#define SI32_ACCTR_A_select_comparator_1_full_range(basePointer) \
   (basePointer->LCCONFIG.CMP1THR = SI32_ACCTR_A_LCCONFIG_CMP1THR_FULL_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_1_low_range(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_1_low_range(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_1_low_range(basePointer)
#define SI32_ACCTR_A_select_comparator_1_low_range(basePointer) \
   (basePointer->LCCONFIG.CMP1THR = SI32_ACCTR_A_LCCONFIG_CMP1THR_LOW_VALUE)


/// @fn _SI32_ACCTR_A_set_lc_comparator_0_coarse_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 63.
///
void
_SI32_ACCTR_A_set_lc_comparator_0_coarse_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_0_coarse_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_0_coarse_threshold(basePointer, threshold) \
   (basePointer->LCCONFIG.CMP0CTH = threshold)


/// @fn _SI32_ACCTR_A_set_lc_comparator_0_fine_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 7.
///
void
_SI32_ACCTR_A_set_lc_comparator_0_fine_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_0_fine_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_0_fine_threshold(basePointer, threshold) \
   (basePointer->LCCONFIG.CMP0FTH = threshold)


/// @fn _SI32_ACCTR_A_set_lc_comparator_1_coarse_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 63.
///
void
_SI32_ACCTR_A_set_lc_comparator_1_coarse_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_1_coarse_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_1_coarse_threshold(basePointer, threshold) \
   (basePointer->LCCONFIG.CMP1CTH = threshold)


/// @fn _SI32_ACCTR_A_set_lc_comparator_1_fine_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 7.
///
void
_SI32_ACCTR_A_set_lc_comparator_1_fine_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_1_fine_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_1_fine_threshold(basePointer, threshold) \
   (basePointer->LCCONFIG.CMP1FTH = threshold)


/// @fn _SI32_ACCTR_A_set_lc_comparator_0_full_range_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 63.
///
void
_SI32_ACCTR_A_set_lc_comparator_0_full_range_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_0_full_range_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_0_full_range_threshold(basePointer, threshold) do{  \
      basePointer->LCCONFIG.U32 =\
      (basePointer->LCCONFIG.U32\
            & (~SI32_ACCTR_A_LCCONFIG_CMP0CTH_MASK))\
            | (SI32_ACCTR_A_LCCONFIG_CMP0THR_MASK |\
        (threshold<<SI32_ACCTR_A_LCCONFIG_CMP0CTH_SHIFT));\
} while(0)


/// @fn _SI32_ACCTR_A_set_lc_comparator_0_low_range_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 48.
///
void
_SI32_ACCTR_A_set_lc_comparator_0_low_range_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_0_low_range_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_0_low_range_threshold(basePointer, threshold) do{  \
      basePointer->LCCONFIG.U32 =\
      (basePointer->LCCONFIG.U32\
            & (~SI32_ACCTR_A_LCCONFIG_CMP0THR_MASK &\
         ~SI32_ACCTR_A_LCCONFIG_CMP0CTH_MASK &\
         ~SI32_ACCTR_A_LCCONFIG_CMP0FTH_MASK))\
            | (((threshold/6)<<SI32_ACCTR_A_LCCONFIG_CMP0CTH_SHIFT) |\
         (threshold%6)<<SI32_ACCTR_A_LCCONFIG_CMP0FTH_SHIFT);\
} while(0)


/// @fn _SI32_ACCTR_A_set_lc_comparator_1_full_range_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 63.
///
void
_SI32_ACCTR_A_set_lc_comparator_1_full_range_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_1_full_range_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_1_full_range_threshold(basePointer, threshold) do{  \
      basePointer->LCCONFIG.U32 =\
      (basePointer->LCCONFIG.U32\
            & (~SI32_ACCTR_A_LCCONFIG_CMP1CTH_MASK))\
            | (SI32_ACCTR_A_LCCONFIG_CMP1THR_MASK |\
        (threshold<<SI32_ACCTR_A_LCCONFIG_CMP1CTH_SHIFT));\
} while(0)


/// @fn _SI32_ACCTR_A_set_lc_comparator_1_low_range_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 0 to 48.
///
void
_SI32_ACCTR_A_set_lc_comparator_1_low_range_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*threshold*/);
///
/// @def SI32_ACCTR_A_set_lc_comparator_1_low_range_threshold(basePointer, threshold)
#define SI32_ACCTR_A_set_lc_comparator_1_low_range_threshold(basePointer, threshold) do{  \
      basePointer->LCCONFIG.U32 =\
      (basePointer->LCCONFIG.U32\
            & (~SI32_ACCTR_A_LCCONFIG_CMP1THR_MASK &\
         ~SI32_ACCTR_A_LCCONFIG_CMP1CTH_MASK &\
         ~SI32_ACCTR_A_LCCONFIG_CMP1FTH_MASK))\
            | (((threshold/6)<<SI32_ACCTR_A_LCCONFIG_CMP1CTH_SHIFT) |\
         (threshold%6)<<SI32_ACCTR_A_LCCONFIG_CMP1FTH_SHIFT);\
} while(0)


/// @fn _SI32_ACCTR_A_select_comparator_low_side_hysteresis_0_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_0_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_low_side_hysteresis_0_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_low_side_hysteresis_0_mV(basePointer) \
   (basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_0_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_low_side_hysteresis_5_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_5_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_low_side_hysteresis_5_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_low_side_hysteresis_5_mV(basePointer) \
   (basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_5_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_low_side_hysteresis_10_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_10_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_low_side_hysteresis_10_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_low_side_hysteresis_10_mV(basePointer) \
   (basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_10_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_low_side_hysteresis_20_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_low_side_hysteresis_20_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_low_side_hysteresis_20_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_low_side_hysteresis_20_mV(basePointer) \
   (basePointer->LCCONFIG.CMPLHYS = SI32_ACCTR_A_LCCONFIG_CMPLHYS_20_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_high_side_hysteresis_0_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_0_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_high_side_hysteresis_0_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_high_side_hysteresis_0_mV(basePointer) \
   (basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_0_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_high_side_hysteresis_5_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_5_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_high_side_hysteresis_5_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_high_side_hysteresis_5_mV(basePointer) \
   (basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_5_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_high_side_hysteresis_10_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_10_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_high_side_hysteresis_10_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_high_side_hysteresis_10_mV(basePointer) \
   (basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_10_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_high_side_hysteresis_20_mV(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_high_side_hysteresis_20_mV(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_high_side_hysteresis_20_mV(basePointer)
#define SI32_ACCTR_A_select_comparator_high_side_hysteresis_20_mV(basePointer) \
   (basePointer->LCCONFIG.CMPHHYS = SI32_ACCTR_A_LCCONFIG_CMPHHYS_20_MV_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_response_time_200_ns(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_response_time_200_ns(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_response_time_200_ns(basePointer)
#define SI32_ACCTR_A_select_comparator_response_time_200_ns(basePointer) \
   (basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_200_NS_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_response_time_400_ns(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_response_time_400_ns(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_response_time_400_ns(basePointer)
#define SI32_ACCTR_A_select_comparator_response_time_400_ns(basePointer) \
   (basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_400_NS_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_response_time_1_us(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_response_time_1_us(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_response_time_1_us(basePointer)
#define SI32_ACCTR_A_select_comparator_response_time_1_us(basePointer) \
   (basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_1_US_VALUE)


/// @fn _SI32_ACCTR_A_select_comparator_response_time_5_us(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_comparator_response_time_5_us(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_comparator_response_time_5_us(basePointer)
#define SI32_ACCTR_A_select_comparator_response_time_5_us(basePointer) \
   (basePointer->LCCONFIG.CMPMD = SI32_ACCTR_A_LCCONFIG_CMPMD_5_US_VALUE)


/// @fn _SI32_ACCTR_A_enable_use_lc_comparator_0_for_counter_1(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_use_lc_comparator_0_for_counter_1(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_use_lc_comparator_0_for_counter_1(basePointer)
#define SI32_ACCTR_A_enable_use_lc_comparator_0_for_counter_1(basePointer) do{  \
   basePointer->LCCONFIG.CMP0CNT1EN =\
      SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_ENABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_disable_use_lc_comparator_0_for_counter_1(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_use_lc_comparator_0_for_counter_1(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_use_lc_comparator_0_for_counter_1(basePointer)
#define SI32_ACCTR_A_disable_use_lc_comparator_0_for_counter_1(basePointer) do{  \
   basePointer->LCCONFIG.CMP0CNT1EN =\
      SI32_ACCTR_A_LCCONFIG_CMP0CNT1EN_DISABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_enable_force_lc_comparator_0_on(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_force_lc_comparator_0_on(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_force_lc_comparator_0_on(basePointer)
#define SI32_ACCTR_A_enable_force_lc_comparator_0_on(basePointer) do{  \
   basePointer->LCCONFIG.FCMP0EN =\
      SI32_ACCTR_A_LCCONFIG_FCMP0EN_ENABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_disable_force_lc_comparator_0_on(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_force_lc_comparator_0_on(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_force_lc_comparator_0_on(basePointer)
#define SI32_ACCTR_A_disable_force_lc_comparator_0_on(basePointer) do{  \
   basePointer->LCCONFIG.FCMP0EN =\
      SI32_ACCTR_A_LCCONFIG_FCMP0EN_DISABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_enable_force_lc_comparator_1_on(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_force_lc_comparator_1_on(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_force_lc_comparator_1_on(basePointer)
#define SI32_ACCTR_A_enable_force_lc_comparator_1_on(basePointer) do{  \
   basePointer->LCCONFIG.FCMP1EN =\
      SI32_ACCTR_A_LCCONFIG_FCMP1EN_ENABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_disable_force_lc_comparator_1_on(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_force_lc_comparator_1_on(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_force_lc_comparator_1_on(basePointer)
#define SI32_ACCTR_A_disable_force_lc_comparator_1_on(basePointer) do{  \
   basePointer->LCCONFIG.FCMP1EN =\
      SI32_ACCTR_A_LCCONFIG_FCMP1EN_DISABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_write_lctiming(SI32_ACCTR_A_Type* basePointer,
///      uint32_t lctiming)
///
/// @brief
/// Write to LCTIMING register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  lctiming
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_lctiming(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*lctiming*/);
///
/// @def SI32_ACCTR_A_write_lctiming(basePointer, lctiming)
#define SI32_ACCTR_A_write_lctiming(basePointer, lctiming) \
   (basePointer->TIMING.U32=lctiming)


/// @fn _SI32_ACCTR_A_read_lctiming(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from LCTIMING register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_lctiming(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_lctiming(basePointer)
#define SI32_ACCTR_A_read_lctiming(basePointer) \
(basePointer->TIMING.U32)


/// @fn _SI32_ACCTR_A_get_lc_timing_state(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_lc_timing_state(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_lc_timing_state(basePointer)
#define SI32_ACCTR_A_get_lc_timing_state(basePointer) \
(basePointer->TIMING.STATE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_pulse_0_offset(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_pulse_0_offset(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_pulse_0_offset(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_pulse_0_offset(basePointer) \
   (basePointer->TIMING.B0OEN=SI32_ACCTR_A_TIMING_B0OEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_pulse_0_offset(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_pulse_0_offset(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_pulse_0_offset(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_pulse_0_offset(basePointer) \
   (basePointer->TIMING.B0OEN=SI32_ACCTR_A_TIMING_B0OEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_pulse_1_offset(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_pulse_1_offset(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_pulse_1_offset(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_pulse_1_offset(basePointer) \
   (basePointer->TIMING.B1OEN=SI32_ACCTR_A_TIMING_B1OEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_pulse_1_offset(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_pulse_1_offset(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_pulse_1_offset(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_pulse_1_offset(basePointer) \
   (basePointer->TIMING.B1OEN=SI32_ACCTR_A_TIMING_B1OEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_set_zone_p_time(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t time)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  time
///  Valid range is 3 bits.
///
void
_SI32_ACCTR_A_set_zone_p_time(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*time*/);
///
/// @def SI32_ACCTR_A_set_zone_p_time(basePointer, time)
#define SI32_ACCTR_A_set_zone_p_time(basePointer, time) \
   (basePointer->TIMING.ZONEP = time)


/// @fn _SI32_ACCTR_A_get_zone_p_time(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_zone_p_time(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_zone_p_time(basePointer)
#define SI32_ACCTR_A_get_zone_p_time(basePointer) \
(basePointer->TIMING.ZONEP)


/// @fn _SI32_ACCTR_A_set_zone_a_time(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t time)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  time
///  Valid range is 3 bits.
///
void
_SI32_ACCTR_A_set_zone_a_time(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*time*/);
///
/// @def SI32_ACCTR_A_set_zone_a_time(basePointer, time)
#define SI32_ACCTR_A_set_zone_a_time(basePointer, time) \
   (basePointer->TIMING.ZONEA = time)


/// @fn _SI32_ACCTR_A_get_zone_a_time(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_zone_a_time(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_zone_a_time(basePointer)
#define SI32_ACCTR_A_get_zone_a_time(basePointer) \
(basePointer->TIMING.ZONEA)


/// @fn _SI32_ACCTR_A_set_zone_b_time(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t time)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  time
///  Valid range is 3 bits.
///
void
_SI32_ACCTR_A_set_zone_b_time(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*time*/);
///
/// @def SI32_ACCTR_A_set_zone_b_time(basePointer, time)
#define SI32_ACCTR_A_set_zone_b_time(basePointer, time) \
   (basePointer->TIMING.ZONEB = time)


/// @fn _SI32_ACCTR_A_get_zone_b_time(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_zone_b_time(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_zone_b_time(basePointer)
#define SI32_ACCTR_A_get_zone_b_time(basePointer) \
(basePointer->TIMING.ZONEB)


/// @fn _SI32_ACCTR_A_set_zone_c_time(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t time)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  time
///  Valid range is 3 bits.
///
void
_SI32_ACCTR_A_set_zone_c_time(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*time*/);
///
/// @def SI32_ACCTR_A_set_zone_c_time(basePointer, time)
#define SI32_ACCTR_A_set_zone_c_time(basePointer, time) \
   (basePointer->TIMING.ZONEC = time)


/// @fn _SI32_ACCTR_A_get_zone_c_time(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_zone_c_time(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_zone_c_time(basePointer)
#define SI32_ACCTR_A_get_zone_c_time(basePointer) \
(basePointer->TIMING.ZONEC)


/// @fn _SI32_ACCTR_A_set_zone_d_time(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t time)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  time
///  Valid range is 3 bits.
///
void
_SI32_ACCTR_A_set_zone_d_time(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*time*/);
///
/// @def SI32_ACCTR_A_set_zone_d_time(basePointer, time)
#define SI32_ACCTR_A_set_zone_d_time(basePointer, time) \
   (basePointer->TIMING.ZONED = time)


/// @fn _SI32_ACCTR_A_get_zone_d_time(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_zone_d_time(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_zone_d_time(basePointer)
#define SI32_ACCTR_A_get_zone_d_time(basePointer) \
(basePointer->TIMING.ZONED)


/// @fn _SI32_ACCTR_A_select_disable_wake_after_zone(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_disable_wake_after_zone(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_disable_wake_after_zone(basePointer)
#define SI32_ACCTR_A_select_disable_wake_after_zone(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_wake_after_zone_p(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_wake_after_zone_p(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_wake_after_zone_p(basePointer)
#define SI32_ACCTR_A_select_wake_after_zone_p(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEP_VALUE)


/// @fn _SI32_ACCTR_A_select_wake_after_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_wake_after_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_wake_after_zone_a(basePointer)
#define SI32_ACCTR_A_select_wake_after_zone_a(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEA_VALUE)


/// @fn _SI32_ACCTR_A_select_wake_after_zone_b(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_wake_after_zone_b(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_wake_after_zone_b(basePointer)
#define SI32_ACCTR_A_select_wake_after_zone_b(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEB_VALUE)


/// @fn _SI32_ACCTR_A_select_wake_after_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_wake_after_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_wake_after_zone_c(basePointer)
#define SI32_ACCTR_A_select_wake_after_zone_c(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONEC_VALUE)


/// @fn _SI32_ACCTR_A_select_wake_after_zone_d(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_wake_after_zone_d(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_wake_after_zone_d(basePointer)
#define SI32_ACCTR_A_select_wake_after_zone_d(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WZONED_VALUE)


/// @fn _SI32_ACCTR_A_select_wake_after_lc_sequence(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_wake_after_lc_sequence(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_wake_after_lc_sequence(basePointer)
#define SI32_ACCTR_A_select_wake_after_lc_sequence(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WEND_VALUE)


/// @fn _SI32_ACCTR_A_select_wake_and_stop_after_lc_sequence(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_wake_and_stop_after_lc_sequence(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_wake_and_stop_after_lc_sequence(basePointer)
#define SI32_ACCTR_A_select_wake_and_stop_after_lc_sequence(basePointer) \
   (basePointer->TIMING.WAKEMD = SI32_ACCTR_A_TIMING_WAKEMD_WKSTOP_VALUE)


/// @fn _SI32_ACCTR_A_start_sequencer(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_start_sequencer(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_start_sequencer(basePointer)
#define SI32_ACCTR_A_start_sequencer(basePointer) \
   (basePointer->TIMING.START = SI32_ACCTR_A_TIMING_START_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_4_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_4_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_4_cycle_period(basePointer)
#define SI32_ACCTR_A_select_4_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_4_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_8_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_8_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_8_cycle_period(basePointer)
#define SI32_ACCTR_A_select_8_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_8_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_16_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_16_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_16_cycle_period(basePointer)
#define SI32_ACCTR_A_select_16_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_16_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_32_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_32_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_32_cycle_period(basePointer)
#define SI32_ACCTR_A_select_32_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_32_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_64_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_64_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_64_cycle_period(basePointer)
#define SI32_ACCTR_A_select_64_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_64_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_128_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_128_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_128_cycle_period(basePointer)
#define SI32_ACCTR_A_select_128_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_128_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_256_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_256_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_256_cycle_period(basePointer)
#define SI32_ACCTR_A_select_256_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_256_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_512_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_512_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_512_cycle_period(basePointer)
#define SI32_ACCTR_A_select_512_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_512_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_1024_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_1024_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_1024_cycle_period(basePointer)
#define SI32_ACCTR_A_select_1024_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_1024_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_2048_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_2048_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_2048_cycle_period(basePointer)
#define SI32_ACCTR_A_select_2048_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_2048_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_4096_cycle_period(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_4096_cycle_period(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_4096_cycle_period(basePointer)
#define SI32_ACCTR_A_select_4096_cycle_period(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_4096_CYCLES_VALUE)


/// @fn _SI32_ACCTR_A_select_single_sample_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_single_sample_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_single_sample_mode(basePointer)
#define SI32_ACCTR_A_select_single_sample_mode(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_SINGLE_SAMPLE_VALUE)


/// @fn _SI32_ACCTR_A_select_consecutive_mode(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_consecutive_mode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_consecutive_mode(basePointer)
#define SI32_ACCTR_A_select_consecutive_mode(basePointer) \
   (basePointer->TIMING.PERIOD = SI32_ACCTR_A_TIMING_PERIOD_CONSECUTIVE_SAMPLE_VALUE)


/// @fn _SI32_ACCTR_A_set_period_value(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Sets actual value of Period field.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 4 bits.
///
void
_SI32_ACCTR_A_set_period_value(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_ACCTR_A_set_period_value(basePointer, value)
#define SI32_ACCTR_A_set_period_value(basePointer, value) \
   (basePointer->TIMING.PERIOD = value)


/// @fn _SI32_ACCTR_A_get_period_value(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Gets actual value of Period field.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_ACCTR_A_get_period_value(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_period_value(basePointer)
#define SI32_ACCTR_A_get_period_value(basePointer) \
(basePointer->TIMING.PERIOD)


/// @fn _SI32_ACCTR_A_get_period_cycles(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Calculates number of cycles accordion to period setting.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_ACCTR_A_get_period_cycles(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_period_cycles(basePointer)
#define SI32_ACCTR_A_get_period_cycles(basePointer) \
(((basePointer->TIMING.PERIOD<11)?(0x00000004<<basePointer->TIMING.PERIOD):0xFFFF))


/// @fn _SI32_ACCTR_A_write_lcmode(SI32_ACCTR_A_Type* basePointer,
///      uint32_t lcmode)
///
/// @brief
/// Write to LCMODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  lcmode
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_lcmode(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*lcmode*/);
///
/// @def SI32_ACCTR_A_write_lcmode(basePointer, lcmode)
#define SI32_ACCTR_A_write_lcmode(basePointer, lcmode) \
   (basePointer->LCMODE.U32=lcmode)


/// @fn _SI32_ACCTR_A_read_lcmode(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from LCMODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_lcmode(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_lcmode(basePointer)
#define SI32_ACCTR_A_read_lcmode(basePointer) \
(basePointer->LCMODE.U32)


/// @fn _SI32_ACCTR_A_enable_lc_automatic_tracking(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_automatic_tracking(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_automatic_tracking(basePointer)
#define SI32_ACCTR_A_enable_lc_automatic_tracking(basePointer) \
   (basePointer->LCMODE.ATRKEN=SI32_ACCTR_A_LCMODE_ATRKEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_automatic_tracking(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_automatic_tracking(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_automatic_tracking(basePointer)
#define SI32_ACCTR_A_disable_lc_automatic_tracking(basePointer) \
   basePointer->LCMODE.ATRKEN=SI32_ACCTR_A_LCMODE_ATRKEN_DISABLED_VALUE;\


/// @fn _SI32_ACCTR_A_enable_lc_automatic_center_discriminator(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_automatic_center_discriminator(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_automatic_center_discriminator(basePointer)
#define SI32_ACCTR_A_enable_lc_automatic_center_discriminator(basePointer) \
   (basePointer->LCMODE.ACDEN=SI32_ACCTR_A_LCMODE_ACDEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_automatic_center_discriminator(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_automatic_center_discriminator(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_automatic_center_discriminator(basePointer)
#define SI32_ACCTR_A_disable_lc_automatic_center_discriminator(basePointer) \
   (basePointer->LCMODE.ACDEN=SI32_ACCTR_A_LCMODE_ACDEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_zero(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_zero(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_zero(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_zero(basePointer) \
   (basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_ZERO_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_1(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_1(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_1(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_1(basePointer) \
   (basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS1_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_2(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_2(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_2(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_2(basePointer) \
   (basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS2_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_3(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_3(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_3(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_0_hysterisis_minus_3(basePointer) \
   (basePointer->LCMODE.LCD0HYS=SI32_ACCTR_A_LCMODE_LCD0HYS_MINUS3_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_zero(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_zero(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_zero(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_zero(basePointer) \
   (basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_ZERO_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_1(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_1(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_1(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_1(basePointer) \
   (basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS1_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_2(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_2(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_2(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_2(basePointer) \
   (basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS2_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_3(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_3(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_3(basePointer)
#define SI32_ACCTR_A_select_lc_discriminator_1_hysterisis_minus_3(basePointer) \
   (basePointer->LCMODE.LCD1HYS=SI32_ACCTR_A_LCMODE_LCD1HYS_MINUS3_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_0_input_active_zone_a(basePointer)
#define SI32_ACCTR_A_select_lc_counter_0_input_active_zone_a(basePointer) \
   (basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONEA_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_b(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_b(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_0_input_active_zone_b(basePointer)
#define SI32_ACCTR_A_select_lc_counter_0_input_active_zone_b(basePointer) \
   (basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONEB_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_0_input_active_zone_c(basePointer)
#define SI32_ACCTR_A_select_lc_counter_0_input_active_zone_c(basePointer) \
   (basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONEC_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_0_input_active_zone_d(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_0_input_active_zone_d(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_0_input_active_zone_d(basePointer)
#define SI32_ACCTR_A_select_lc_counter_0_input_active_zone_d(basePointer) \
   (basePointer->LCMODE.C0ZONE=SI32_ACCTR_A_LCMODE_C0ZONE_ZONED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_1_input_active_zone_a(basePointer)
#define SI32_ACCTR_A_select_lc_counter_1_input_active_zone_a(basePointer) \
   (basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONEA_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_b(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_b(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_1_input_active_zone_b(basePointer)
#define SI32_ACCTR_A_select_lc_counter_1_input_active_zone_b(basePointer) \
   (basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONEB_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_1_input_active_zone_c(basePointer)
#define SI32_ACCTR_A_select_lc_counter_1_input_active_zone_c(basePointer) \
   (basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONEC_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_counter_1_input_active_zone_d(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_counter_1_input_active_zone_d(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_counter_1_input_active_zone_d(basePointer)
#define SI32_ACCTR_A_select_lc_counter_1_input_active_zone_d(basePointer) \
   (basePointer->LCMODE.C1ZONE=SI32_ACCTR_A_LCMODE_C1ZONE_ZONED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_0_output_disable(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_0_output_disable(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_0_output_disable(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_0_output_disable(basePointer) \
   (basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_c(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_c(basePointer) \
   (basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_C_ONLY_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a(basePointer) \
   (basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_A_ONLY_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a_and_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a_and_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a_and_c(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_0_output_active_zone_a_and_c(basePointer) \
   (basePointer->LCMODE.P0ZONE=SI32_ACCTR_A_LCMODE_P0ZONE_A_AND_C_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_1_output_disable(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_1_output_disable(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_1_output_disable(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_1_output_disable(basePointer) \
   (basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_c(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_c(basePointer) \
   (basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_C_ONLY_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a(basePointer) \
   (basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_A_ONLY_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a_and_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a_and_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a_and_c(basePointer)
#define SI32_ACCTR_A_select_lc_pulse_1_output_active_zone_a_and_c(basePointer) \
   (basePointer->LCMODE.P1ZONE=SI32_ACCTR_A_LCMODE_P1ZONE_A_AND_C_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_output_pulse_mode_disabled(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_disabled(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_output_pulse_mode_disabled(basePointer)
#define SI32_ACCTR_A_select_lc_output_pulse_mode_disabled(basePointer) \
   (basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_output_pulse_mode_toggle(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_toggle(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_output_pulse_mode_toggle(basePointer)
#define SI32_ACCTR_A_select_lc_output_pulse_mode_toggle(basePointer) \
   (basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_TOGGLE_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_low(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_low(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_low(basePointer)
#define SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_low(basePointer) \
   (basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_PULSE_LOW_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_high(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_high(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_high(basePointer)
#define SI32_ACCTR_A_select_lc_output_pulse_mode_pulse_high(basePointer) \
   (basePointer->LCMODE.PMD=SI32_ACCTR_A_LCMODE_PMD_PULSE_HIGH_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_0_zone_a(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_0_zone_a(basePointer) \
   (basePointer->LCMODE.B0ZONEAEN=SI32_ACCTR_A_LCMODE_B0ZONEAEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_0_zone_a(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_0_zone_a(basePointer) \
   (basePointer->LCMODE.B0ZONEAEN=SI32_ACCTR_A_LCMODE_B0ZONEAEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_b(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_b(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_0_zone_b(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_0_zone_b(basePointer) \
   (basePointer->LCMODE.B0ZONEBEN=SI32_ACCTR_A_LCMODE_B0ZONEBEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_b(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_b(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_0_zone_b(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_0_zone_b(basePointer) \
   (basePointer->LCMODE.B0ZONEBEN=SI32_ACCTR_A_LCMODE_B0ZONEBEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_0_zone_c(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_0_zone_c(basePointer) \
   (basePointer->LCMODE.B0ZONECEN=SI32_ACCTR_A_LCMODE_B0ZONECEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_0_zone_c(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_0_zone_c(basePointer) \
   (basePointer->LCMODE.B0ZONECEN=SI32_ACCTR_A_LCMODE_B0ZONECEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_0_zone_p(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_0_zone_p(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_0_zone_p(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_0_zone_p(basePointer) \
   (basePointer->LCMODE.B0ZONEPEN=SI32_ACCTR_A_LCMODE_B0ZONEPEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_0_zone_p(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_0_zone_p(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_0_zone_p(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_0_zone_p(basePointer) \
   (basePointer->LCMODE.B0ZONEPEN=SI32_ACCTR_A_LCMODE_B0ZONEPEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_counter_0_pulse_high_polarity(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_counter_0_pulse_high_polarity(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_counter_0_pulse_high_polarity(basePointer)
#define SI32_ACCTR_A_select_lc_bias_counter_0_pulse_high_polarity(basePointer) \
   (basePointer->LCMODE.B0POL=SI32_ACCTR_A_LCMODE_B0POL_PULSE_HIGH_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_counter_0_pulse_low_polarity(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_counter_0_pulse_low_polarity(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_counter_0_pulse_low_polarity(basePointer)
#define SI32_ACCTR_A_select_lc_bias_counter_0_pulse_low_polarity(basePointer) \
   (basePointer->LCMODE.B0POL=SI32_ACCTR_A_LCMODE_B0POL_PULSE_LOW_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_1_zone_a(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_1_zone_a(basePointer) \
   (basePointer->LCMODE.B1ZONEAEN=SI32_ACCTR_A_LCMODE_B1ZONEAEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_a(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_a(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_1_zone_a(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_1_zone_a(basePointer) \
   (basePointer->LCMODE.B1ZONEAEN=SI32_ACCTR_A_LCMODE_B1ZONEAEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_b(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_b(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_1_zone_b(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_1_zone_b(basePointer) \
   (basePointer->LCMODE.B1ZONEBEN=SI32_ACCTR_A_LCMODE_B1ZONEBEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_b(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_b(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_1_zone_b(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_1_zone_b(basePointer) \
   (basePointer->LCMODE.B1ZONEBEN=SI32_ACCTR_A_LCMODE_B1ZONEBEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_1_zone_c(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_1_zone_c(basePointer) \
   (basePointer->LCMODE.B1ZONECEN=SI32_ACCTR_A_LCMODE_B1ZONECEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_c(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_c(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_1_zone_c(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_1_zone_c(basePointer) \
   (basePointer->LCMODE.B1ZONECEN=SI32_ACCTR_A_LCMODE_B1ZONECEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_lc_bias_counter_1_zone_p(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_lc_bias_counter_1_zone_p(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_lc_bias_counter_1_zone_p(basePointer)
#define SI32_ACCTR_A_enable_lc_bias_counter_1_zone_p(basePointer) \
   (basePointer->LCMODE.B1ZONEPEN=SI32_ACCTR_A_LCMODE_B1ZONEPEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_lc_bias_counter_1_zone_p(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_lc_bias_counter_1_zone_p(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_lc_bias_counter_1_zone_p(basePointer)
#define SI32_ACCTR_A_disable_lc_bias_counter_1_zone_p(basePointer) \
   (basePointer->LCMODE.B1ZONEPEN=SI32_ACCTR_A_LCMODE_B1ZONEPEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_counter_1_pulse_high_polarity(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_counter_1_pulse_high_polarity(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_counter_1_pulse_high_polarity(basePointer)
#define SI32_ACCTR_A_select_lc_bias_counter_1_pulse_high_polarity(basePointer) \
   (basePointer->LCMODE.B1POL=SI32_ACCTR_A_LCMODE_B1POL_PULSE_HIGH_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_counter_1_pulse_low_polarity(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_counter_1_pulse_low_polarity(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_counter_1_pulse_low_polarity(basePointer)
#define SI32_ACCTR_A_select_lc_bias_counter_1_pulse_low_polarity(basePointer) \
   (basePointer->LCMODE.B1POL=SI32_ACCTR_A_LCMODE_B1POL_PULSE_LOW_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_mode_0_disable(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_mode_0_disable(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_mode_0_disable(basePointer)
#define SI32_ACCTR_A_select_lc_bias_mode_0_disable(basePointer) \
   (basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE0_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_mode_1_external_only(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_mode_1_external_only(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_mode_1_external_only(basePointer)
#define SI32_ACCTR_A_select_lc_bias_mode_1_external_only(basePointer) \
   (basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE1_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_mode_2_internal_only(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_mode_2_internal_only(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_mode_2_internal_only(basePointer)
#define SI32_ACCTR_A_select_lc_bias_mode_2_internal_only(basePointer) \
   (basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE2_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_bias_mode_3_internal_external(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_bias_mode_3_internal_external(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_bias_mode_3_internal_external(basePointer)
#define SI32_ACCTR_A_select_lc_bias_mode_3_internal_external(basePointer) \
   (basePointer->LCMODE.BMD=SI32_ACCTR_A_LCMODE_BMD_MODE3_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_0_pass_through_single_ended(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_0_pass_through_single_ended(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_0_pass_through_single_ended(basePointer)
#define SI32_ACCTR_A_select_lc_mode_0_pass_through_single_ended(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE0_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_1_pass_through_differential(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_1_pass_through_differential(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_1_pass_through_differential(basePointer)
#define SI32_ACCTR_A_select_lc_mode_1_pass_through_differential(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE1_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_2_pass_through_sample_and_hold_single_ended(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_2_pass_through_sample_and_hold_single_ended(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_2_pass_through_sample_and_hold_single_ended(basePointer)
#define SI32_ACCTR_A_select_lc_mode_2_pass_through_sample_and_hold_single_ended(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE2_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_3_pass_through_sample_and_hold_differential(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_3_pass_through_sample_and_hold_differential(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_3_pass_through_sample_and_hold_differential(basePointer)
#define SI32_ACCTR_A_select_lc_mode_3_pass_through_sample_and_hold_differential(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE3_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_4_timed_single_ended(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_4_timed_single_ended(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_4_timed_single_ended(basePointer)
#define SI32_ACCTR_A_select_lc_mode_4_timed_single_ended(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE4_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_5_timed_differential(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_5_timed_differential(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_5_timed_differential(basePointer)
#define SI32_ACCTR_A_select_lc_mode_5_timed_differential(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE5_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_6_timed_sample_and_hold_single_ended(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_6_timed_sample_and_hold_single_ended(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_6_timed_sample_and_hold_single_ended(basePointer)
#define SI32_ACCTR_A_select_lc_mode_6_timed_sample_and_hold_single_ended(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE6_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_7_timed_sample_and_hold_differential(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_7_timed_sample_and_hold_differential(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_7_timed_sample_and_hold_differential(basePointer)
#define SI32_ACCTR_A_select_lc_mode_7_timed_sample_and_hold_differential(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE7_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_8_external_stop_rising_edge(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_8_external_stop_rising_edge(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_8_external_stop_rising_edge(basePointer)
#define SI32_ACCTR_A_select_lc_mode_8_external_stop_rising_edge(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE8_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_9_external_stop_falling_edge(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_9_external_stop_falling_edge(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_9_external_stop_falling_edge(basePointer)
#define SI32_ACCTR_A_select_lc_mode_9_external_stop_falling_edge(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE9_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_10_external_stop_sample_and_hold_rising_edge(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_10_external_stop_sample_and_hold_rising_edge(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_10_external_stop_sample_and_hold_rising_edge(basePointer)
#define SI32_ACCTR_A_select_lc_mode_10_external_stop_sample_and_hold_rising_edge(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE10_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_11_external_stop_sample_and_hold_falling_edge(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_11_external_stop_sample_and_hold_falling_edge(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_11_external_stop_sample_and_hold_falling_edge(basePointer)
#define SI32_ACCTR_A_select_lc_mode_11_external_stop_sample_and_hold_falling_edge(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE11_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_12_no_pulse_single_ended(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_12_no_pulse_single_ended(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_12_no_pulse_single_ended(basePointer)
#define SI32_ACCTR_A_select_lc_mode_12_no_pulse_single_ended(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE12_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_13_no_pulse_differential(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_13_no_pulse_differential(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_13_no_pulse_differential(basePointer)
#define SI32_ACCTR_A_select_lc_mode_13_no_pulse_differential(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE13_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_14_no_pulse_sample_and_hold_single_ended(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_14_no_pulse_sample_and_hold_single_ended(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_14_no_pulse_sample_and_hold_single_ended(basePointer)
#define SI32_ACCTR_A_select_lc_mode_14_no_pulse_sample_and_hold_single_ended(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE14_VALUE)


/// @fn _SI32_ACCTR_A_select_lc_mode_15_no_pulse_sample_and_hold_differential(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_select_lc_mode_15_no_pulse_sample_and_hold_differential(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_select_lc_mode_15_no_pulse_sample_and_hold_differential(basePointer)
#define SI32_ACCTR_A_select_lc_mode_15_no_pulse_sample_and_hold_differential(basePointer) \
   (basePointer->LCMODE.LCMD=SI32_ACCTR_A_LCMODE_LCMD_MODE15_VALUE)


/// @fn _SI32_ACCTR_A_write_lcclkcontrol(SI32_ACCTR_A_Type* basePointer,
///      uint32_t lcclkcontrol)
///
/// @brief
/// Write to LCCLKCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  lcclkcontrol
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_lcclkcontrol(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*lcclkcontrol*/);
///
/// @def SI32_ACCTR_A_write_lcclkcontrol(basePointer, lcclkcontrol)
#define SI32_ACCTR_A_write_lcclkcontrol(basePointer, lcclkcontrol) \
   (basePointer->LCCLKCONTROL.U32=lcclkcontrol)


/// @fn _SI32_ACCTR_A_read_lcclkcontrol(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from LCCLKCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_lcclkcontrol(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_lcclkcontrol(basePointer)
#define SI32_ACCTR_A_read_lcclkcontrol(basePointer) \
(basePointer->LCCLKCONTROL.U32)


/// @fn _SI32_ACCTR_A_get_lc_oscillator_calibration_value(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_ACCTR_A_get_lc_oscillator_calibration_value(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_lc_oscillator_calibration_value(basePointer)
#define SI32_ACCTR_A_get_lc_oscillator_calibration_value(basePointer) \
(basePointer->LCCLKCONTROL.CLKCYCLES)


/// @fn _SI32_ACCTR_A_start_lc_oscillator_calibration(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_start_lc_oscillator_calibration(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_start_lc_oscillator_calibration(basePointer)
#define SI32_ACCTR_A_start_lc_oscillator_calibration(basePointer) do{  \
   basePointer->LCCLKCONTROL.CLKCAL =\
      SI32_ACCTR_A_LCCLKCONTROL_CLKCAL_START_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_is_lc_oscillator_calibration_in_progess(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_lc_oscillator_calibration_in_progess(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_lc_oscillator_calibration_in_progess(basePointer)
#define SI32_ACCTR_A_is_lc_oscillator_calibration_in_progess(basePointer) \
(basePointer->LCCLKCONTROL.CLKCAL)


/// @fn _SI32_ACCTR_A_set_lc_oscillator_reload_value(SI32_ACCTR_A_Type* basePointer,
///      uwide16_t reload)
///
/// @brief
/// Set LC oscillator reload value.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  reload
///  Valid range is 12 bits.
///
void
_SI32_ACCTR_A_set_lc_oscillator_reload_value(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide16_t /*reload*/);
///
/// @def SI32_ACCTR_A_set_lc_oscillator_reload_value(basePointer, reload)
#define SI32_ACCTR_A_set_lc_oscillator_reload_value(basePointer, reload) \
   (basePointer->LCCLKCONTROL.RELOAD = reload)


/// @fn _SI32_ACCTR_A_get_lc_oscillator_reload_value(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Get LC oscillator reload value.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_ACCTR_A_get_lc_oscillator_reload_value(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_lc_oscillator_reload_value(basePointer)
#define SI32_ACCTR_A_get_lc_oscillator_reload_value(basePointer) \
(basePointer->LCCLKCONTROL.RELOAD)


/// @fn _SI32_ACCTR_A_read_lc_limits(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from LCLIMITS register. Read only register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_lc_limits(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_lc_limits(basePointer)
#define SI32_ACCTR_A_read_lc_limits(basePointer) \
(basePointer->LCLIMITS.U32)


/// @fn _SI32_ACCTR_A_write_lccount(SI32_ACCTR_A_Type* basePointer,
///      uint32_t lccount)
///
/// @brief
/// Write to LCCOUNT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  lccount
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_lccount(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*lccount*/);
///
/// @def SI32_ACCTR_A_write_lccount(basePointer, lccount)
#define SI32_ACCTR_A_write_lccount(basePointer, lccount) \
   (basePointer->LCCOUNT.U32=lccount)


/// @fn _SI32_ACCTR_A_read_lccount(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from LCCOUNT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_lccount(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_lccount(basePointer)
#define SI32_ACCTR_A_read_lccount(basePointer) \
(basePointer->LCCOUNT.U32)


/// @fn _SI32_ACCTR_A_set_lc_count_0_discriminator(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///  Set count 0 discriminator field.
///
void
_SI32_ACCTR_A_set_lc_count_0_discriminator(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_ACCTR_A_set_lc_count_0_discriminator(basePointer, value)
#define SI32_ACCTR_A_set_lc_count_0_discriminator(basePointer, value) \
   (basePointer->LCCOUNT.CD0 = value)


/// @fn _SI32_ACCTR_A_get_lc_count_0_discriminator(SI32_ACCTR_A_Type* basePointer)
///
/// @return
///  Get count 0 discriminator field.
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_lc_count_0_discriminator(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_lc_count_0_discriminator(basePointer)
#define SI32_ACCTR_A_get_lc_count_0_discriminator(basePointer) \
(basePointer->LCCOUNT.CD0)


/// @fn _SI32_ACCTR_A_set_lc_count_1_discriminator(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t value)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///  Set count 1 discriminator field.
///
void
_SI32_ACCTR_A_set_lc_count_1_discriminator(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_ACCTR_A_set_lc_count_1_discriminator(basePointer, value)
#define SI32_ACCTR_A_set_lc_count_1_discriminator(basePointer, value) \
   (basePointer->LCCOUNT.CD1 = value)


/// @fn _SI32_ACCTR_A_get_lc_count_1_discriminator(SI32_ACCTR_A_Type* basePointer)
///
/// @return
///  Get count 1 discriminator field.
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_lc_count_1_discriminator(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_lc_count_1_discriminator(basePointer)
#define SI32_ACCTR_A_get_lc_count_1_discriminator(basePointer) \
(basePointer->LCCOUNT.CD1)


/// @fn _SI32_ACCTR_A_write_dbconfig(SI32_ACCTR_A_Type* basePointer,
///      uint32_t dbconfig)
///
/// @brief
/// Write to DBCONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dbconfig
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_dbconfig(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*dbconfig*/);
///
/// @def SI32_ACCTR_A_write_dbconfig(basePointer, dbconfig)
#define SI32_ACCTR_A_write_dbconfig(basePointer, dbconfig) \
   (basePointer->DBCONFIG.U32=dbconfig)


/// @fn _SI32_ACCTR_A_read_dbconfig(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from DBCONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_dbconfig(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_dbconfig(basePointer)
#define SI32_ACCTR_A_read_dbconfig(basePointer) \
(basePointer->DBCONFIG.U32)


/// @fn _SI32_ACCTR_A_set_debounce_low_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t ldbth)
///
/// @brief
/// Set debounce low threshold.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ldbth
///  Valid range is 8 bits.
///
void
_SI32_ACCTR_A_set_debounce_low_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*ldbth*/);
///
/// @def SI32_ACCTR_A_set_debounce_low_threshold(basePointer, ldbth)
#define SI32_ACCTR_A_set_debounce_low_threshold(basePointer, ldbth) \
   (basePointer->DBCONFIG.LDBTH = ldbth)


/// @fn _SI32_ACCTR_A_get_debounce_low_threshold(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Get debounce low threshold.
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_debounce_low_threshold(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_debounce_low_threshold(basePointer)
#define SI32_ACCTR_A_get_debounce_low_threshold(basePointer) \
(basePointer->DBCONFIG.LDBTH)


/// @fn _SI32_ACCTR_A_set_debounce_high_threshold(SI32_ACCTR_A_Type* basePointer,
///      uwide8_t hdbth)
///
/// @brief
/// Set debounce high threshold.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  hdbth
///  Valid range is 8 bits.
///
void
_SI32_ACCTR_A_set_debounce_high_threshold(SI32_ACCTR_A_Type* /*basePointer*/,
   uwide8_t /*hdbth*/);
///
/// @def SI32_ACCTR_A_set_debounce_high_threshold(basePointer, hdbth)
#define SI32_ACCTR_A_set_debounce_high_threshold(basePointer, hdbth) \
   (basePointer->DBCONFIG.HDBTH = hdbth)


/// @fn _SI32_ACCTR_A_get_debounce_high_threshold(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Get debounce high threshold.
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_debounce_high_threshold(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_debounce_high_threshold(basePointer)
#define SI32_ACCTR_A_get_debounce_high_threshold(basePointer) \
(basePointer->DBCONFIG.HDBTH)


/// @fn _SI32_ACCTR_A_enable_debounce_integrator_disconnect(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_debounce_integrator_disconnect(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_debounce_integrator_disconnect(basePointer)
#define SI32_ACCTR_A_enable_debounce_integrator_disconnect(basePointer) do{  \
   basePointer->DBCONFIG.INTEGDCEN =\
      SI32_ACCTR_A_DBCONFIG_INTEGDCEN_ENABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_disable_debounce_integrator_disconnect(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_debounce_integrator_disconnect(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_debounce_integrator_disconnect(basePointer)
#define SI32_ACCTR_A_disable_debounce_integrator_disconnect(basePointer) do{  \
   basePointer->DBCONFIG.INTEGDCEN =\
      SI32_ACCTR_A_DBCONFIG_INTEGDCEN_DISABLED_VALUE;\
} while(0)


/// @fn _SI32_ACCTR_A_is_debounce_integrator_0_high(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_debounce_integrator_0_high(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_debounce_integrator_0_high(basePointer)
#define SI32_ACCTR_A_is_debounce_integrator_0_high(basePointer) \
(basePointer->DBCONFIG.INTEG0)


/// @fn _SI32_ACCTR_A_is_debounce_integrator_1_high(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_debounce_integrator_1_high(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_debounce_integrator_1_high(basePointer)
#define SI32_ACCTR_A_is_debounce_integrator_1_high(basePointer) \
(basePointer->DBCONFIG.INTEG1)


/// @fn _SI32_ACCTR_A_read_count0(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from COUNT0 register. Read only register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_count0(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_count0(basePointer)
#define SI32_ACCTR_A_read_count0(basePointer) \
(basePointer->COUNT0.U32)


/// @fn _SI32_ACCTR_A_read_count1(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from COUNT1 register. Read only register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_count1(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_count1(basePointer)
#define SI32_ACCTR_A_read_count1(basePointer) \
(basePointer->COUNT1.U32)


/// @fn _SI32_ACCTR_A_write_comp0(SI32_ACCTR_A_Type* basePointer,
///      uint32_t comp0)
///
/// @brief
/// Write to COMP0 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  comp0
///  Valid range is 24 bits.
///
void
_SI32_ACCTR_A_write_comp0(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*comp0*/);
///
/// @def SI32_ACCTR_A_write_comp0(basePointer, comp0)
#define SI32_ACCTR_A_write_comp0(basePointer, comp0) \
   (basePointer->COMP0.U32=comp0)


/// @fn _SI32_ACCTR_A_read_comp0(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from COMP0 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_comp0(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_comp0(basePointer)
#define SI32_ACCTR_A_read_comp0(basePointer) \
(basePointer->COMP0.U32)


/// @fn _SI32_ACCTR_A_write_comp1(SI32_ACCTR_A_Type* basePointer,
///      uint32_t comp1)
///
/// @brief
/// Write to COMP1 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  comp1
///  Valid range is 24 bits.
///
void
_SI32_ACCTR_A_write_comp1(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*comp1*/);
///
/// @def SI32_ACCTR_A_write_comp1(basePointer, comp1)
#define SI32_ACCTR_A_write_comp1(basePointer, comp1) \
   (basePointer->COMP1.U32=comp1)


/// @fn _SI32_ACCTR_A_read_comp1(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from COMP1 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_comp1(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_comp1(basePointer)
#define SI32_ACCTR_A_read_comp1(basePointer) \
(basePointer->COMP1.U32)


/// @fn _SI32_ACCTR_A_write_status(SI32_ACCTR_A_Type* basePointer,
///      uint32_t status)
///
/// @brief
/// Write Status Register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_ACCTR_A_write_status(SI32_ACCTR_A_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_ACCTR_A_write_status(basePointer, status)
#define SI32_ACCTR_A_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_ACCTR_A_read_status(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Read from STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ACCTR_A_read_status(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_read_status(basePointer)
#define SI32_ACCTR_A_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_ACCTR_A_is_direction_change_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_direction_change_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_direction_change_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_direction_change_interrupt_flag_set(basePointer) \
(basePointer->STATUS.DIRCHGI)


/// @fn _SI32_ACCTR_A_clear_direction_change_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_direction_change_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_direction_change_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_direction_change_interrupt_flag(basePointer) \
   (basePointer->STATUS.DIRCHGI = SI32_ACCTR_A_STATUS_DIRCHGI_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_overflow_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_overflow_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_overflow_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_overflow_interrupt_flag_set(basePointer) \
(basePointer->STATUS.OVFI)


/// @fn _SI32_ACCTR_A_clear_overflow_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_overflow_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_overflow_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_overflow_interrupt_flag(basePointer) \
   (basePointer->STATUS.OVFI = SI32_ACCTR_A_STATUS_OVFI_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_digital_comparator_0_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_digital_comparator_0_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_digital_comparator_0_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_digital_comparator_0_interrupt_flag_set(basePointer) \
(basePointer->STATUS.CMP0I)


/// @fn _SI32_ACCTR_A_clear_digital_comparator_0_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_digital_comparator_0_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_digital_comparator_0_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_digital_comparator_0_interrupt_flag(basePointer) \
   (basePointer->STATUS.CMP0I = SI32_ACCTR_A_STATUS_CMP0I_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_digital_comparator_1_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_digital_comparator_1_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_digital_comparator_1_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_digital_comparator_1_interrupt_flag_set(basePointer) \
(basePointer->STATUS.CMP1I)


/// @fn _SI32_ACCTR_A_clear_digital_comparator_1_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_digital_comparator_1_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_digital_comparator_1_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_digital_comparator_1_interrupt_flag(basePointer) \
   (basePointer->STATUS.CMP1I = SI32_ACCTR_A_STATUS_CMP1I_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_debounce_integrator_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_debounce_integrator_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_debounce_integrator_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_debounce_integrator_interrupt_flag_set(basePointer) \
(basePointer->STATUS.TRANSI)


/// @fn _SI32_ACCTR_A_clear_debounce_integrator_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_debounce_integrator_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_debounce_integrator_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_debounce_integrator_interrupt_flag(basePointer) \
   (basePointer->STATUS.TRANSI = SI32_ACCTR_A_STATUS_TRANSI_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_quadrature_error_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_quadrature_error_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_quadrature_error_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_quadrature_error_interrupt_flag_set(basePointer) \
(basePointer->STATUS.QERRI)


/// @fn _SI32_ACCTR_A_clear_quadrature_error_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_quadrature_error_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_quadrature_error_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_quadrature_error_interrupt_flag(basePointer) \
   (basePointer->STATUS.QERRI = SI32_ACCTR_A_STATUS_QERRI_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_flutter_stop_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_flutter_stop_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_flutter_stop_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_flutter_stop_interrupt_flag_set(basePointer) \
(basePointer->STATUS.FLSTOPI)


/// @fn _SI32_ACCTR_A_clear_flutter_stop_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_flutter_stop_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_flutter_stop_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_flutter_stop_interrupt_flag(basePointer) \
   (basePointer->STATUS.FLSTOPI = SI32_ACCTR_A_STATUS_FLSTOPI_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_is_flutter_start_interrupt_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_flutter_start_interrupt_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_flutter_start_interrupt_flag_set(basePointer)
#define SI32_ACCTR_A_is_flutter_start_interrupt_flag_set(basePointer) \
(basePointer->STATUS.FLSTARTI)


/// @fn _SI32_ACCTR_A_clear_flutter_start_interrupt_flag(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_clear_flutter_start_interrupt_flag(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_clear_flutter_start_interrupt_flag(basePointer)
#define SI32_ACCTR_A_clear_flutter_start_interrupt_flag(basePointer) \
   (basePointer->STATUS.FLSTARTI = SI32_ACCTR_A_STATUS_FLSTARTI_NOT_SET_VALUE)


/// @fn _SI32_ACCTR_A_enable_direction_change_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_direction_change_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_direction_change_interrupt(basePointer)
#define SI32_ACCTR_A_enable_direction_change_interrupt(basePointer) \
   (basePointer->STATUS.DIRCHGIEN = SI32_ACCTR_A_STATUS_DIRCHGIEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_direction_change_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_direction_change_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_direction_change_interrupt(basePointer)
#define SI32_ACCTR_A_disable_direction_change_interrupt(basePointer) \
   (basePointer->STATUS.DIRCHGIEN = SI32_ACCTR_A_STATUS_DIRCHGIEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_counter_overflow_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_counter_overflow_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_counter_overflow_interrupt(basePointer)
#define SI32_ACCTR_A_enable_counter_overflow_interrupt(basePointer) \
   (basePointer->STATUS.OVFIEN = SI32_ACCTR_A_STATUS_OVFIEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_counter_overflow_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_counter_overflow_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_counter_overflow_interrupt(basePointer)
#define SI32_ACCTR_A_disable_counter_overflow_interrupt(basePointer) \
   (basePointer->STATUS.OVFIEN = SI32_ACCTR_A_STATUS_OVFIEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_digital_comparator_0_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_digital_comparator_0_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_digital_comparator_0_interrupt(basePointer)
#define SI32_ACCTR_A_enable_digital_comparator_0_interrupt(basePointer) \
   (basePointer->STATUS.CMP0IEN = SI32_ACCTR_A_STATUS_CMP0IEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_digital_comparator_0_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_digital_comparator_0_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_digital_comparator_0_interrupt(basePointer)
#define SI32_ACCTR_A_disable_digital_comparator_0_interrupt(basePointer) \
   (basePointer->STATUS.CMP0IEN = SI32_ACCTR_A_STATUS_CMP0IEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_digital_comparator_1_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_digital_comparator_1_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_digital_comparator_1_interrupt(basePointer)
#define SI32_ACCTR_A_enable_digital_comparator_1_interrupt(basePointer) \
   (basePointer->STATUS.CMP1IEN = SI32_ACCTR_A_STATUS_CMP1IEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_digital_comparator_1_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_digital_comparator_1_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_digital_comparator_1_interrupt(basePointer)
#define SI32_ACCTR_A_disable_digital_comparator_1_interrupt(basePointer) \
   (basePointer->STATUS.CMP1IEN = SI32_ACCTR_A_STATUS_CMP1IEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_debounce_integrator_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_debounce_integrator_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_debounce_integrator_interrupt(basePointer)
#define SI32_ACCTR_A_enable_debounce_integrator_interrupt(basePointer) \
   (basePointer->STATUS.TRANSIEN = SI32_ACCTR_A_STATUS_TRANSIEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_debounce_integrator_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_debounce_integrator_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_debounce_integrator_interrupt(basePointer)
#define SI32_ACCTR_A_disable_debounce_integrator_interrupt(basePointer) \
   (basePointer->STATUS.TRANSIEN = SI32_ACCTR_A_STATUS_TRANSIEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_quadrature_error_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_quadrature_error_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_quadrature_error_interrupt(basePointer)
#define SI32_ACCTR_A_enable_quadrature_error_interrupt(basePointer) \
   (basePointer->STATUS.QERRIEN = SI32_ACCTR_A_STATUS_QERRIEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_quadrature_error_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_quadrature_error_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_quadrature_error_interrupt(basePointer)
#define SI32_ACCTR_A_disable_quadrature_error_interrupt(basePointer) \
   (basePointer->STATUS.QERRIEN = SI32_ACCTR_A_STATUS_QERRIEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_flutter_stop_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_flutter_stop_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_flutter_stop_interrupt(basePointer)
#define SI32_ACCTR_A_enable_flutter_stop_interrupt(basePointer) \
   (basePointer->STATUS.FLSTOPIEN = SI32_ACCTR_A_STATUS_FLSTOPIEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_flutter_stop_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_flutter_stop_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_flutter_stop_interrupt(basePointer)
#define SI32_ACCTR_A_disable_flutter_stop_interrupt(basePointer) \
   (basePointer->STATUS.FLSTOPIEN = SI32_ACCTR_A_STATUS_FLSTOPIEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_enable_flutter_start_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_flutter_start_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_flutter_start_interrupt(basePointer)
#define SI32_ACCTR_A_enable_flutter_start_interrupt(basePointer) \
   (basePointer->STATUS.FLSTARTIEN = SI32_ACCTR_A_STATUS_FLSTARTIEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_flutter_start_interrupt(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_flutter_start_interrupt(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_flutter_start_interrupt(basePointer)
#define SI32_ACCTR_A_disable_flutter_start_interrupt(basePointer) \
   (basePointer->STATUS.FLSTARTIEN = SI32_ACCTR_A_STATUS_FLSTARTIEN_DISABLED_VALUE)


/// @fn _SI32_ACCTR_A_is_debounce_integrator_0_output_high(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_debounce_integrator_0_output_high(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_debounce_integrator_0_output_high(basePointer)
#define SI32_ACCTR_A_is_debounce_integrator_0_output_high(basePointer) \
(basePointer->STATUS.IN0)


/// @fn _SI32_ACCTR_A_is_debounce_integrator_1_output_high(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_debounce_integrator_1_output_high(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_debounce_integrator_1_output_high(basePointer)
#define SI32_ACCTR_A_is_debounce_integrator_1_output_high(basePointer) \
(basePointer->STATUS.IN1)


/// @fn _SI32_ACCTR_A_get_pulse_counter_state(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_pulse_counter_state(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_pulse_counter_state(basePointer)
#define SI32_ACCTR_A_get_pulse_counter_state(basePointer) \
(basePointer->STATUS.STATE)


/// @fn _SI32_ACCTR_A_is_flutter_detetion_flag_set(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_flutter_detetion_flag_set(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_flutter_detetion_flag_set(basePointer)
#define SI32_ACCTR_A_is_flutter_detetion_flag_set(basePointer) \
(basePointer->STATUS.FLF)


/// @fn _SI32_ACCTR_A_get_history(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_ACCTR_A_get_history(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_get_history(basePointer)
#define SI32_ACCTR_A_get_history(basePointer) \
(basePointer->STATUS.DIRHIST)


/// @fn _SI32_ACCTR_A_is_analog_comparator_0_output_high(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_analog_comparator_0_output_high(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_analog_comparator_0_output_high(basePointer)
#define SI32_ACCTR_A_is_analog_comparator_0_output_high(basePointer) \
(basePointer->STATUS.CMP0OUT)


/// @fn _SI32_ACCTR_A_is_analog_comparator_1_output_high(SI32_ACCTR_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ACCTR_A_is_analog_comparator_1_output_high(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_is_analog_comparator_1_output_high(basePointer)
#define SI32_ACCTR_A_is_analog_comparator_1_output_high(basePointer) \
(basePointer->STATUS.CMP1OUT)


/// @fn _SI32_ACCTR_A_enable_debug_output(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Enable debug output.
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_enable_debug_output(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_enable_debug_output(basePointer)
#define SI32_ACCTR_A_enable_debug_output(basePointer) \
   (basePointer->DEBUGEN.DBGOEN = SI32_ACCTR_A_DEBUGEN_DBGOEN_ENABLED_VALUE)


/// @fn _SI32_ACCTR_A_disable_debug_output(SI32_ACCTR_A_Type* basePointer)
///
/// @brief
/// Disable debug output.
///
/// @param[in]
///  basePointer
///
void
_SI32_ACCTR_A_disable_debug_output(SI32_ACCTR_A_Type* /*basePointer*/);
///
/// @def SI32_ACCTR_A_disable_debug_output(basePointer)
#define SI32_ACCTR_A_disable_debug_output(basePointer) \
   (basePointer->DEBUGEN.DBGOEN = SI32_ACCTR_A_DEBUGEN_DBGOEN_DISABLED_VALUE)



#ifdef __cplusplus
}
#endif

#endif // __SI32_ACCTR_A_TYPE_H__

//-eof--------------------------------------------------------------------------
