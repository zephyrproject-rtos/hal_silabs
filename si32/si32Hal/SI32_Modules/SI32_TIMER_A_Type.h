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
/// @file SI32_TIMER_A_Type.h
//
// Script: 0.59
// HAL Source: 0.5
// Version: 1

#ifndef __SI32_TIMER_A_TYPE_H__
#define __SI32_TIMER_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_TIMER_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_TIMER_A_initialize(SI32_TIMER_A_Type* basePointer,
///      uint32_t config,
///      uint32_t clkdiv,
///      uint32_t count,
///      uint32_t capture)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
/// @param[in]
///  clkdiv
///  Valid range is 32 bits.
///  Write to CLKDIV register.
///
/// @param[in]
///  count
///  Valid range is 32 bits.
///  Write to COUNT register.
///
/// @param[in]
///  capture
///  Valid range is 32 bits.
///  Write to CAPTURE register.
///
void
_SI32_TIMER_A_initialize(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*clkdiv*/
   uint32_t, /*count*/
   uint32_t /*capture*/);
///
/// @def SI32_TIMER_A_initialize(basePointer, config, clkdiv, count, capture)
#define SI32_TIMER_A_initialize(basePointer, config, clkdiv, count, capture) do{  \
   basePointer->CONFIG.U32  = config;\
   basePointer->CLKDIV.U32  = clkdiv;\
   basePointer->COUNT.U32   = count;\
   basePointer->CAPTURE.U32 = capture;\
} while(0)


/// @fn _SI32_TIMER_A_write_config(SI32_TIMER_A_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Writes to CONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_TIMER_A_write_config(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_TIMER_A_write_config(basePointer, config)
#define SI32_TIMER_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_TIMER_A_read_config(SI32_TIMER_A_Type* basePointer)
///
/// @brief
/// Reads CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_read_config(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_read_config(basePointer)
#define SI32_TIMER_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_TIMER_A_select_low_clock_source_apb_clock(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_clock_source_apb_clock(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_clock_source_apb_clock(basePointer)
#define SI32_TIMER_A_select_low_clock_source_apb_clock(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_APB_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_clock_source_external_oscillator(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_clock_source_external_oscillator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_clock_source_external_oscillator(basePointer)
#define SI32_TIMER_A_select_low_clock_source_external_oscillator(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_EXTOSCN_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_clock_source_timer_clock_divider(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_clock_source_timer_clock_divider(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_clock_source_timer_clock_divider(basePointer)
#define SI32_TIMER_A_select_low_clock_source_timer_clock_divider(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_TIMER_CLKDIV_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_clock_source_external_ct_pin(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_clock_source_external_ct_pin(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_clock_source_external_ct_pin(basePointer)
#define SI32_TIMER_A_select_low_clock_source_external_ct_pin(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LCLK_CT_FALLING_EDGE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_enable_low_clock_master_synchronization(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_enable_low_clock_master_synchronization(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_enable_low_clock_master_synchronization(basePointer)
#define SI32_TIMER_A_enable_low_clock_master_synchronization(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMSTREN_MASK)


/// @fn _SI32_TIMER_A_disable_low_clock_master_synchronization(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_disable_low_clock_master_synchronization(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_disable_low_clock_master_synchronization(basePointer)
#define SI32_TIMER_A_disable_low_clock_master_synchronization(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMSTREN_MASK)


/// @fn _SI32_TIMER_A_select_split_timer_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_split_timer_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_split_timer_mode(basePointer)
#define SI32_TIMER_A_select_split_timer_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_SPLITEN_MASK)


/// @fn _SI32_TIMER_A_select_single_timer_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_single_timer_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_single_timer_mode(basePointer)
#define SI32_TIMER_A_select_single_timer_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_SPLITEN_MASK)


/// @fn _SI32_TIMER_A_enable_low_extra_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_enable_low_extra_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_enable_low_extra_interrupt(basePointer)
#define SI32_TIMER_A_enable_low_extra_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LEXIEN_MASK)


/// @fn _SI32_TIMER_A_disable_low_extra_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_disable_low_extra_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_disable_low_extra_interrupt(basePointer)
#define SI32_TIMER_A_disable_low_extra_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LEXIEN_MASK)


/// @fn _SI32_TIMER_A_enable_low_overflow_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_enable_low_overflow_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_enable_low_overflow_interrupt(basePointer)
#define SI32_TIMER_A_enable_low_overflow_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LOVFIEN_MASK)


/// @fn _SI32_TIMER_A_disable_low_overflow_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_disable_low_overflow_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_disable_low_overflow_interrupt(basePointer)
#define SI32_TIMER_A_disable_low_overflow_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LOVFIEN_MASK)


/// @fn _SI32_TIMER_A_is_low_overflow_interrupt_enabled(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_is_low_overflow_interrupt_enabled(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_is_low_overflow_interrupt_enabled(basePointer)
#define SI32_TIMER_A_is_low_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.LOVFIEN))


/// @fn _SI32_TIMER_A_select_low_auto_reload_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_auto_reload_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_auto_reload_mode(basePointer)
#define SI32_TIMER_A_select_low_auto_reload_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_AUTO_RELOAD_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_up_down_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_up_down_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_up_down_mode(basePointer)
#define SI32_TIMER_A_select_low_up_down_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_UP_DOWN_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_falling_edge_capture_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_falling_edge_capture_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_falling_edge_capture_mode(basePointer)
#define SI32_TIMER_A_select_low_falling_edge_capture_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_FALL_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_rising_edge_capture_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_rising_edge_capture_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_rising_edge_capture_mode(basePointer)
#define SI32_TIMER_A_select_low_rising_edge_capture_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_RISE_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_capture_low_time_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_capture_low_time_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_capture_low_time_mode(basePointer)
#define SI32_TIMER_A_select_low_capture_low_time_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_LOW_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_capture_high_time_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_capture_high_time_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_capture_high_time_mode(basePointer)
#define SI32_TIMER_A_select_low_capture_high_time_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_HIGH_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_duty_cycle_capture_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_duty_cycle_capture_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_duty_cycle_capture_mode(basePointer)
#define SI32_TIMER_A_select_low_duty_cycle_capture_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_DC_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_low_oneshot_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_low_oneshot_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_low_oneshot_mode(basePointer)
#define SI32_TIMER_A_select_low_oneshot_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LMD_ONESHOT_U32;\
} while(0)


/// @fn _SI32_TIMER_A_set_low_state_indicator(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_set_low_state_indicator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_set_low_state_indicator(basePointer)
#define SI32_TIMER_A_set_low_state_indicator(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LSTATE_MASK)


/// @fn _SI32_TIMER_A_clear_low_state_indicator(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_clear_low_state_indicator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_clear_low_state_indicator(basePointer)
#define SI32_TIMER_A_clear_low_state_indicator(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LSTATE_MASK)


/// @fn _SI32_TIMER_A_get_low_state_indicator(SI32_TIMER_A_Type* basePointer)
///
/// @return
///  Returns TRUE if event occurred, returns FALSE if event has not
///  occurred.
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_get_low_state_indicator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_get_low_state_indicator(basePointer)
#define SI32_TIMER_A_get_low_state_indicator(basePointer) \
((bool)(basePointer->CONFIG.LSTATE))


/// @fn _SI32_TIMER_A_start_low_timer(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_start_low_timer(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_start_low_timer(basePointer)
#define SI32_TIMER_A_start_low_timer(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_LRUN_MASK)


/// @fn _SI32_TIMER_A_stop_low_timer(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_stop_low_timer(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_stop_low_timer(basePointer)
#define SI32_TIMER_A_stop_low_timer(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LRUN_MASK)


/// @fn _SI32_TIMER_A_is_low_extra_interrupt_pending(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_is_low_extra_interrupt_pending(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_is_low_extra_interrupt_pending(basePointer)
#define SI32_TIMER_A_is_low_extra_interrupt_pending(basePointer) \
((bool) (basePointer->CONFIG.LEXI))


/// @fn _SI32_TIMER_A_clear_low_extra_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_clear_low_extra_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_clear_low_extra_interrupt(basePointer)
#define SI32_TIMER_A_clear_low_extra_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LEXI_MASK)


/// @fn _SI32_TIMER_A_is_low_overflow_interrupt_pending(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_is_low_overflow_interrupt_pending(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_is_low_overflow_interrupt_pending(basePointer)
#define SI32_TIMER_A_is_low_overflow_interrupt_pending(basePointer) \
((bool) (basePointer->CONFIG.LOVFI))


/// @fn _SI32_TIMER_A_clear_low_overflow_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_clear_low_overflow_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_clear_low_overflow_interrupt(basePointer)
#define SI32_TIMER_A_clear_low_overflow_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_LOVFI_MASK)


/// @fn _SI32_TIMER_A_select_high_clock_source_apb_clock(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_clock_source_apb_clock(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_clock_source_apb_clock(basePointer)
#define SI32_TIMER_A_select_high_clock_source_apb_clock(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_APB_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_clock_source_external_oscillator(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_clock_source_external_oscillator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_clock_source_external_oscillator(basePointer)
#define SI32_TIMER_A_select_high_clock_source_external_oscillator(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_EXTOSCN_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_clock_source_timer_clock_divider(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_clock_source_timer_clock_divider(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_clock_source_timer_clock_divider(basePointer)
#define SI32_TIMER_A_select_high_clock_source_timer_clock_divider(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_TIMER_CLKDIV_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_clock_source_external_ct_pin(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_clock_source_external_ct_pin(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_clock_source_external_ct_pin(basePointer)
#define SI32_TIMER_A_select_high_clock_source_external_ct_pin(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HCLK_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HCLK_CT_FALLING_EDGE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_start_master_run_control(SI32_TIMER_A_Type* basePointer)
///
/// @brief
/// Only supported in Timer0.
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_start_master_run_control(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_start_master_run_control(basePointer)
#define SI32_TIMER_A_start_master_run_control(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_MSTRUN_MASK)


/// @fn _SI32_TIMER_A_stop_master_run_control(SI32_TIMER_A_Type* basePointer)
///
/// @brief
/// Only supported in Timer0.
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_stop_master_run_control(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_stop_master_run_control(basePointer)
#define SI32_TIMER_A_stop_master_run_control(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_MSTRUN_MASK)


/// @fn _SI32_TIMER_A_enable_high_clock_master_synchronization(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_enable_high_clock_master_synchronization(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_enable_high_clock_master_synchronization(basePointer)
#define SI32_TIMER_A_enable_high_clock_master_synchronization(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMSTREN_MASK)


/// @fn _SI32_TIMER_A_disable_high_clock_master_synchronization(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_disable_high_clock_master_synchronization(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_disable_high_clock_master_synchronization(basePointer)
#define SI32_TIMER_A_disable_high_clock_master_synchronization(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMSTREN_MASK)


/// @fn _SI32_TIMER_A_enable_stall_in_debug_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_enable_stall_in_debug_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_enable_stall_in_debug_mode(basePointer)
#define SI32_TIMER_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_DBGMD_MASK)


/// @fn _SI32_TIMER_A_disable_stall_in_debug_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_disable_stall_in_debug_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_disable_stall_in_debug_mode(basePointer)
#define SI32_TIMER_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_DBGMD_MASK)


/// @fn _SI32_TIMER_A_enable_high_extra_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_enable_high_extra_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_enable_high_extra_interrupt(basePointer)
#define SI32_TIMER_A_enable_high_extra_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HEXIEN_MASK)


/// @fn _SI32_TIMER_A_disable_high_extra_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_disable_high_extra_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_disable_high_extra_interrupt(basePointer)
#define SI32_TIMER_A_disable_high_extra_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HEXIEN_MASK)


/// @fn _SI32_TIMER_A_enable_high_overflow_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_enable_high_overflow_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_enable_high_overflow_interrupt(basePointer)
#define SI32_TIMER_A_enable_high_overflow_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HOVFIEN_MASK)


/// @fn _SI32_TIMER_A_disable_high_overflow_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_disable_high_overflow_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_disable_high_overflow_interrupt(basePointer)
#define SI32_TIMER_A_disable_high_overflow_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HOVFIEN_MASK)


/// @fn _SI32_TIMER_A_is_high_overflow_interrupt_enabled(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_is_high_overflow_interrupt_enabled(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_is_high_overflow_interrupt_enabled(basePointer)
#define SI32_TIMER_A_is_high_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.HOVFIEN))


/// @fn _SI32_TIMER_A_select_high_auto_reload_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_auto_reload_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_auto_reload_mode(basePointer)
#define SI32_TIMER_A_select_high_auto_reload_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_AUTO_RELOAD_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_up_down_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_up_down_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_up_down_mode(basePointer)
#define SI32_TIMER_A_select_high_up_down_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_UP_DOWN_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_falling_edge_capture_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_falling_edge_capture_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_falling_edge_capture_mode(basePointer)
#define SI32_TIMER_A_select_high_falling_edge_capture_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_FALL_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_rising_edge_capture_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_rising_edge_capture_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_rising_edge_capture_mode(basePointer)
#define SI32_TIMER_A_select_high_rising_edge_capture_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_RISE_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_capture_low_time_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_capture_low_time_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_capture_low_time_mode(basePointer)
#define SI32_TIMER_A_select_high_capture_low_time_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_LOW_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_capture_high_time_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_capture_high_time_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_capture_high_time_mode(basePointer)
#define SI32_TIMER_A_select_high_capture_high_time_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_HIGH_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_duty_cycle_capture_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_duty_cycle_capture_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_duty_cycle_capture_mode(basePointer)
#define SI32_TIMER_A_select_high_duty_cycle_capture_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_DC_CAPTURE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_oneshot_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_oneshot_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_oneshot_mode(basePointer)
#define SI32_TIMER_A_select_high_oneshot_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_ONESHOT_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_square_wave_output_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_square_wave_output_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_square_wave_output_mode(basePointer)
#define SI32_TIMER_A_select_square_wave_output_mode(basePointer) do{  \
	basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_TOGGLE_U32;\
} while(0)


/// @fn _SI32_TIMER_A_select_high_pwm_mode(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_select_high_pwm_mode(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_select_high_pwm_mode(basePointer)
#define SI32_TIMER_A_select_high_pwm_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HMD_MASK;\
   basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HMD_PWM_U32;\
} while(0)


/// @fn _SI32_TIMER_A_set_high_state_indicator(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_set_high_state_indicator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_set_high_state_indicator(basePointer)
#define SI32_TIMER_A_set_high_state_indicator(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HSTATE_MASK)


/// @fn _SI32_TIMER_A_clear_high_state_indicator(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_clear_high_state_indicator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_clear_high_state_indicator(basePointer)
#define SI32_TIMER_A_clear_high_state_indicator(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HSTATE_MASK)


/// @fn _SI32_TIMER_A_get_high_state_indicator(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_get_high_state_indicator(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_get_high_state_indicator(basePointer)
#define SI32_TIMER_A_get_high_state_indicator(basePointer) \
((bool) (basePointer->CONFIG.HSTATE))


/// @fn _SI32_TIMER_A_start_high_timer(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_start_high_timer(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_start_high_timer(basePointer)
#define SI32_TIMER_A_start_high_timer(basePointer) \
   (basePointer->CONFIG_SET = SI32_TIMER_A_CONFIG_HRUN_MASK)


/// @fn _SI32_TIMER_A_stop_high_timer(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_stop_high_timer(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_stop_high_timer(basePointer)
#define SI32_TIMER_A_stop_high_timer(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HRUN_MASK)


/// @fn _SI32_TIMER_A_is_high_extra_interrupt_pending(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_is_high_extra_interrupt_pending(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_is_high_extra_interrupt_pending(basePointer)
#define SI32_TIMER_A_is_high_extra_interrupt_pending(basePointer) \
((bool)(basePointer->CONFIG.HEXI))


/// @fn _SI32_TIMER_A_clear_high_extra_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_clear_high_extra_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_clear_high_extra_interrupt(basePointer)
#define SI32_TIMER_A_clear_high_extra_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HEXI_MASK)


/// @fn _SI32_TIMER_A_is_high_overflow_interrupt_pending(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_TIMER_A_is_high_overflow_interrupt_pending(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_is_high_overflow_interrupt_pending(basePointer)
#define SI32_TIMER_A_is_high_overflow_interrupt_pending(basePointer) \
((bool)(basePointer->CONFIG.HOVFI))


/// @fn _SI32_TIMER_A_clear_high_overflow_interrupt(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_TIMER_A_clear_high_overflow_interrupt(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_clear_high_overflow_interrupt(basePointer)
#define SI32_TIMER_A_clear_high_overflow_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_TIMER_A_CONFIG_HOVFI_MASK)


/// @fn _SI32_TIMER_A_write_clkdiv(SI32_TIMER_A_Type* basePointer,
///      uint32_t clkdiv)
///
/// @brief
/// Writes to CLKDIV register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  clkdiv
///  Valid range is 32 bits.
///
void
_SI32_TIMER_A_write_clkdiv(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*clkdiv*/);
///
/// @def SI32_TIMER_A_write_clkdiv(basePointer, clkdiv)
#define SI32_TIMER_A_write_clkdiv(basePointer, clkdiv) \
   (basePointer->CLKDIV.U32 = clkdiv)


/// @fn _SI32_TIMER_A_read_clkdiv(SI32_TIMER_A_Type* basePointer)
///
/// @brief
/// Reads CLKDIV register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_read_clkdiv(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_read_clkdiv(basePointer)
#define SI32_TIMER_A_read_clkdiv(basePointer) \
(basePointer->CLKDIV.U32)


/// @fn _SI32_TIMER_A_set_clock_divider_counter(SI32_TIMER_A_Type* basePointer,
///      uint32_t counter)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  counter
///  Valid range is 8 bits.
///
void
_SI32_TIMER_A_set_clock_divider_counter(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*counter*/);
///
/// @def SI32_TIMER_A_set_clock_divider_counter(basePointer, counter)
#define SI32_TIMER_A_set_clock_divider_counter(basePointer, counter) \
   (basePointer->CLKDIV.CLKDIVCT = counter)


/// @fn _SI32_TIMER_A_set_clock_divider_reload(SI32_TIMER_A_Type* basePointer,
///      uint32_t reload)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  reload
///  Valid range is 8 bits.
///
void
_SI32_TIMER_A_set_clock_divider_reload(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*reload*/);
///
/// @def SI32_TIMER_A_set_clock_divider_reload(basePointer, reload)
#define SI32_TIMER_A_set_clock_divider_reload(basePointer, reload) \
   (basePointer->CLKDIV.CLKDIVRL = reload)


/// @fn _SI32_TIMER_A_write_count(SI32_TIMER_A_Type* basePointer,
///      uint32_t count)
///
/// @brief
/// Writes to COUNT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 32 bits.
///
void
_SI32_TIMER_A_write_count(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_TIMER_A_write_count(basePointer, count)
#define SI32_TIMER_A_write_count(basePointer, count) \
   (basePointer->COUNT.U32 = count)


/// @fn _SI32_TIMER_A_read_count(SI32_TIMER_A_Type* basePointer)
///
/// @brief
/// Reads COUNT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_read_count(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_read_count(basePointer)
#define SI32_TIMER_A_read_count(basePointer) \
(basePointer->COUNT.U32)


/// @fn _SI32_TIMER_A_set_high_count(SI32_TIMER_A_Type* basePointer,
///      uint32_t count)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 16 bits.
///
void
_SI32_TIMER_A_set_high_count(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_TIMER_A_set_high_count(basePointer, count)
#define SI32_TIMER_A_set_high_count(basePointer, count) \
   (basePointer->COUNT.HCOUNT = count)


/// @fn _SI32_TIMER_A_get_high_count(SI32_TIMER_A_Type* basePointer)
///
/// @return
///  Gets high timer count.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_get_high_count(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_get_high_count(basePointer)
#define SI32_TIMER_A_get_high_count(basePointer) \
((basePointer->COUNT.HCOUNT))


/// @fn _SI32_TIMER_A_set_low_count(SI32_TIMER_A_Type* basePointer,
///      uint32_t count)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 16 bits.
///
void
_SI32_TIMER_A_set_low_count(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_TIMER_A_set_low_count(basePointer, count)
#define SI32_TIMER_A_set_low_count(basePointer, count) \
   (basePointer->COUNT.LCOUNT = count)


/// @fn _SI32_TIMER_A_get_low_count(SI32_TIMER_A_Type* basePointer)
///
/// @return
///  Gets low timer count.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_get_low_count(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_get_low_count(basePointer)
#define SI32_TIMER_A_get_low_count(basePointer) \
((basePointer->COUNT.LCOUNT))


/// @fn _SI32_TIMER_A_write_capture(SI32_TIMER_A_Type* basePointer,
///      uint32_t capture)
///
/// @brief
/// Writes to CAPTURE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  capture
///  Valid range is 32 bits.
///
void
_SI32_TIMER_A_write_capture(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*capture*/);
///
/// @def SI32_TIMER_A_write_capture(basePointer, capture)
#define SI32_TIMER_A_write_capture(basePointer, capture) \
   (basePointer->CAPTURE.U32 = capture)


/// @fn _SI32_TIMER_A_read_capture(SI32_TIMER_A_Type* basePointer)
///
/// @brief
/// Reads CAPTURE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_read_capture(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_read_capture(basePointer)
#define SI32_TIMER_A_read_capture(basePointer) \
(basePointer->CAPTURE.U32)


/// @fn _SI32_TIMER_A_set_high_reload(SI32_TIMER_A_Type* basePointer,
///      uint32_t reload)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  reload
///  Valid range is 16 bits.
///
void
_SI32_TIMER_A_set_high_reload(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*reload*/);
///
/// @def SI32_TIMER_A_set_high_reload(basePointer, reload)
#define SI32_TIMER_A_set_high_reload(basePointer, reload) \
   (basePointer->CAPTURE.HCCR = reload)


/// @fn _SI32_TIMER_A_get_high_capture(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_get_high_capture(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_get_high_capture(basePointer)
#define SI32_TIMER_A_get_high_capture(basePointer) \
((basePointer->CAPTURE.HCCR))


/// @fn _SI32_TIMER_A_set_low_reload(SI32_TIMER_A_Type* basePointer,
///      uint32_t reload)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  reload
///  Valid range is 16 bits.
///
void
_SI32_TIMER_A_set_low_reload(SI32_TIMER_A_Type* /*basePointer*/,
   uint32_t /*reload*/);
///
/// @def SI32_TIMER_A_set_low_reload(basePointer, reload)
#define SI32_TIMER_A_set_low_reload(basePointer, reload) \
   (basePointer->CAPTURE.LCCR = reload)


/// @fn _SI32_TIMER_A_get_low_capture(SI32_TIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_TIMER_A_get_low_capture(SI32_TIMER_A_Type* /*basePointer*/);
///
/// @def SI32_TIMER_A_get_low_capture(basePointer)
#define SI32_TIMER_A_get_low_capture(basePointer) \
((basePointer->CAPTURE.LCCR))



#ifdef __cplusplus
}
#endif

#endif // __SI32_TIMER_A_TYPE_H__

//-eof--------------------------------------------------------------------------
