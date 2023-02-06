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
/// @file SI32_LPTIMER_B_Type.h
//
// Script: 0.59
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_LPTIMER_B_TYPE_H__
#define __SI32_LPTIMER_B_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_LPTIMER_B_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_LPTIMER_B_initialize(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t control,
///      uint32_t count,
///      uint32_t threshold,
///      uint32_t status)
///
/// @brief
/// Writes all LPTIMER registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  count
///  Valid range is 32 bits.
///
/// @param[in]
///  threshold
///  Valid range is 32 bits.
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_LPTIMER_B_initialize(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*count*/
   uint32_t, /*threshold*/
   uint32_t /*status*/);
///
/// @def SI32_LPTIMER_B_initialize(basePointer, control, count, threshold, status)
#define SI32_LPTIMER_B_initialize(basePointer, control, count, threshold, status) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->COUNT.U32 = count;\
   basePointer->THRESHOLD.U32 = threshold;\
   basePointer->STATUS.U32 = status;\
} while(0)


/// @fn _SI32_LPTIMER_B_write_control(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_LPTIMER_B_write_control(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_LPTIMER_B_write_control(basePointer, control)
#define SI32_LPTIMER_B_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_LPTIMER_B_read_control(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_B_read_control(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_read_control(basePointer)
#define SI32_LPTIMER_B_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_LPTIMER_B_select_free_run_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_select_free_run_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_select_free_run_mode(basePointer)
#define SI32_LPTIMER_B_select_free_run_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMD_MASK)


/// @fn _SI32_LPTIMER_B_select_rising_edge_increment_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_select_rising_edge_increment_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_select_rising_edge_increment_mode(basePointer)
#define SI32_LPTIMER_B_select_rising_edge_increment_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMD_MASK;\
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMD_RISING_EDGE_U32;\
} while(0)


/// @fn _SI32_LPTIMER_B_select_falling_edge_increment_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_select_falling_edge_increment_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_select_falling_edge_increment_mode(basePointer)
#define SI32_LPTIMER_B_select_falling_edge_increment_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMD_MASK;\
   basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMD_FALLING_EDGE_U32;\
} while(0)


/// @fn _SI32_LPTIMER_B_select_both_edge_increment_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_select_both_edge_increment_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_select_both_edge_increment_mode(basePointer)
#define SI32_LPTIMER_B_select_both_edge_increment_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMD_MASK)


/// @fn _SI32_LPTIMER_B_select_timer_source(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t source)
///
/// @brief
/// Selects the external trigger for the timer.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  source
///  Valid range is 4 bits.
///  External trigger source select from 0 to 15 (0 = LPTnT0, ..., 15 =
///  LPTnT15).
///
void
_SI32_LPTIMER_B_select_timer_source(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*source*/);
///
/// @def SI32_LPTIMER_B_select_timer_source(basePointer, source)
#define SI32_LPTIMER_B_select_timer_source(basePointer, source) do{  \
   basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_EXTSEL_MASK;\
   basePointer->CONTROL_SET = source << SI32_LPTIMER_B_CONTROL_EXTSEL_SHIFT;\
} while(0)


/// @fn _SI32_LPTIMER_B_start_timer_write(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Initiates copy from DATA register to internal timer register.
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_start_timer_write(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_start_timer_write(basePointer)
#define SI32_LPTIMER_B_start_timer_write(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_TMRSET_SET_U32)


/// @fn _SI32_LPTIMER_B_has_timer_write_occurred(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Returns whether or not the last timer write request has finished.
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_has_timer_write_occurred(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_has_timer_write_occurred(basePointer)
#define SI32_LPTIMER_B_has_timer_write_occurred(basePointer) \
(!(bool)(basePointer->CONTROL.TMRSET))


/// @fn _SI32_LPTIMER_B_start_timer_read(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Initiates copy from internal timer register to DATA register.
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_start_timer_read(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_start_timer_read(basePointer)
#define SI32_LPTIMER_B_start_timer_read(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_TMRCAP_SET_U32)


/// @fn _SI32_LPTIMER_B_has_timer_read_occurred(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Returns whether or not the last timer read request has finished.
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_has_timer_read_occurred(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_has_timer_read_occurred(basePointer)
#define SI32_LPTIMER_B_has_timer_read_occurred(basePointer) \
(!(bool)(basePointer->CONTROL.TMRCAP))


/// @fn _SI32_LPTIMER_B_enter_high_speed_timer_access_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enter_high_speed_timer_access_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enter_high_speed_timer_access_mode(basePointer)
#define SI32_LPTIMER_B_enter_high_speed_timer_access_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_HSMDEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_exit_high_speed_timer_access_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_exit_high_speed_timer_access_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_exit_high_speed_timer_access_mode(basePointer)
#define SI32_LPTIMER_B_exit_high_speed_timer_access_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_HSMDEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_compare0_threshold(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_compare0_threshold(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_compare0_threshold(basePointer)
#define SI32_LPTIMER_B_enable_compare0_threshold(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0EN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_compare0_threshold(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_compare0_threshold(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_compare0_threshold(basePointer)
#define SI32_LPTIMER_B_disable_compare0_threshold(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0EN_MASK)


/// @fn _SI32_LPTIMER_B_enable_compare1_threshold(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_compare1_threshold(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_compare1_threshold(basePointer)
#define SI32_LPTIMER_B_enable_compare1_threshold(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1EN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_compare1_threshold(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_compare1_threshold(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_compare1_threshold(basePointer)
#define SI32_LPTIMER_B_disable_compare1_threshold(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1EN_MASK)


/// @fn _SI32_LPTIMER_B_enable_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_output(basePointer)
#define SI32_LPTIMER_B_enable_output(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OUTEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_output(basePointer)
#define SI32_LPTIMER_B_disable_output(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OUTEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_overflow_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_overflow_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_overflow_interrupt(basePointer)
#define SI32_LPTIMER_B_enable_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OVFIEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_overflow_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_overflow_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_overflow_interrupt(basePointer)
#define SI32_LPTIMER_B_disable_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OVFIEN_MASK)


/// @fn _SI32_LPTIMER_B_is_overflow_interrupt_enabled(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_is_overflow_interrupt_enabled(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_is_overflow_interrupt_enabled(basePointer)
#define SI32_LPTIMER_B_is_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.OVFIEN))


/// @fn _SI32_LPTIMER_B_enable_compare0_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_compare0_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_compare0_interrupt(basePointer)
#define SI32_LPTIMER_B_enable_compare0_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0IEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_compare0_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_compare0_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_compare0_interrupt(basePointer)
#define SI32_LPTIMER_B_disable_compare0_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0IEN_MASK)


/// @fn _SI32_LPTIMER_B_is_compare0_interrupt_enabled(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_is_compare0_interrupt_enabled(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_is_compare0_interrupt_enabled(basePointer)
#define SI32_LPTIMER_B_is_compare0_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.CMP0IEN))


/// @fn _SI32_LPTIMER_B_enable_overflow_set_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_overflow_set_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_overflow_set_output(basePointer)
#define SI32_LPTIMER_B_enable_overflow_set_output(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OVFOEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_overflow_set_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_overflow_set_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_overflow_set_output(basePointer)
#define SI32_LPTIMER_B_disable_overflow_set_output(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OVFOEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_compare0_event_to_clear_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_compare0_event_to_clear_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_compare0_event_to_clear_output(basePointer)
#define SI32_LPTIMER_B_enable_compare0_event_to_clear_output(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0OEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_compare0_event_to_clear_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_compare0_event_to_clear_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_compare0_event_to_clear_output(basePointer)
#define SI32_LPTIMER_B_disable_compare0_event_to_clear_output(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0OEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_compare1_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_compare1_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_compare1_interrupt(basePointer)
#define SI32_LPTIMER_B_enable_compare1_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1IEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_compare1_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_compare1_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_compare1_interrupt(basePointer)
#define SI32_LPTIMER_B_disable_compare1_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1IEN_MASK)


/// @fn _SI32_LPTIMER_B_is_compare1_interrupt_enabled(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_is_compare1_interrupt_enabled(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_is_compare1_interrupt_enabled(basePointer)
#define SI32_LPTIMER_B_is_compare1_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.CMP1IEN))


/// @fn _SI32_LPTIMER_B_enable_compare1_event_to_set_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_compare1_event_to_set_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_compare1_event_to_set_output(basePointer)
#define SI32_LPTIMER_B_enable_compare1_event_to_set_output(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1OEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_compare1_event_to_set_output(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_compare1_event_to_set_output(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_compare1_event_to_set_output(basePointer)
#define SI32_LPTIMER_B_disable_compare1_event_to_set_output(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1OEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_output_inversion(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_output_inversion(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_output_inversion(basePointer)
#define SI32_LPTIMER_B_enable_output_inversion(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_OUTINVEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_output_inversion(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_output_inversion(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_output_inversion(basePointer)
#define SI32_LPTIMER_B_disable_output_inversion(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_OUTINVEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_timer_reset_upon_compare0(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_timer_reset_upon_compare0(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_timer_reset_upon_compare0(basePointer)
#define SI32_LPTIMER_B_enable_timer_reset_upon_compare0(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP0RSTEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_timer_reset_upon_compare0(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_timer_reset_upon_compare0(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_timer_reset_upon_compare0(basePointer)
#define SI32_LPTIMER_B_disable_timer_reset_upon_compare0(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP0RSTEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_timer_reset_upon_compare1(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_timer_reset_upon_compare1(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_timer_reset_upon_compare1(basePointer)
#define SI32_LPTIMER_B_enable_timer_reset_upon_compare1(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_CMP1RSTEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_timer_reset_upon_compare1(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_timer_reset_upon_compare1(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_timer_reset_upon_compare1(basePointer)
#define SI32_LPTIMER_B_disable_timer_reset_upon_compare1(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_CMP1RSTEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_module_clock(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_module_clock(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_module_clock(basePointer)
#define SI32_LPTIMER_B_enable_module_clock(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_MCLKEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_B_disable_module_clock(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_module_clock(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_module_clock(basePointer)
#define SI32_LPTIMER_B_disable_module_clock(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_MCLKEN_MASK)


/// @fn _SI32_LPTIMER_B_enable_stall_in_debug_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_enable_stall_in_debug_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_enable_stall_in_debug_mode(basePointer)
#define SI32_LPTIMER_B_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_DBGMD_HALT_U32)


/// @fn _SI32_LPTIMER_B_disable_stall_in_debug_mode(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_disable_stall_in_debug_mode(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_disable_stall_in_debug_mode(basePointer)
#define SI32_LPTIMER_B_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_DBGMD_MASK)


/// @fn _SI32_LPTIMER_B_start_timer(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_start_timer(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_start_timer(basePointer)
#define SI32_LPTIMER_B_start_timer(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_B_CONTROL_RUN_MASK)


/// @fn _SI32_LPTIMER_B_stop_timer(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_stop_timer(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_stop_timer(basePointer)
#define SI32_LPTIMER_B_stop_timer(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_B_CONTROL_RUN_MASK)


/// @fn _SI32_LPTIMER_B_write_count(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t count)
///
/// @brief
/// Writes COUNT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 32 bits.
///
void
_SI32_LPTIMER_B_write_count(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_LPTIMER_B_write_count(basePointer, count)
#define SI32_LPTIMER_B_write_count(basePointer, count) \
   (basePointer->COUNT.U32 = count)


/// @fn _SI32_LPTIMER_B_read_count(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Reads COUNT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_B_read_count(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_read_count(basePointer)
#define SI32_LPTIMER_B_read_count(basePointer) \
(basePointer->COUNT.U32)


/// @fn _SI32_LPTIMER_B_write_timer_value(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Writes the Timer Value field.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 16 bits.
///
void
_SI32_LPTIMER_B_write_timer_value(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_LPTIMER_B_write_timer_value(basePointer, value)
#define SI32_LPTIMER_B_write_timer_value(basePointer, value) \
   (basePointer->COUNT.TIMER = value)


/// @fn _SI32_LPTIMER_B_read_timer_value(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Reads the Timer Value field.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_B_read_timer_value(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_read_timer_value(basePointer)
#define SI32_LPTIMER_B_read_timer_value(basePointer) \
(basePointer->COUNT.TIMER)


/// @fn _SI32_LPTIMER_B_write_threshold(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t threshold)
///
/// @brief
/// Writes THRESHOLD register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 32 bits.
///
void
_SI32_LPTIMER_B_write_threshold(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*threshold*/);
///
/// @def SI32_LPTIMER_B_write_threshold(basePointer, threshold)
#define SI32_LPTIMER_B_write_threshold(basePointer, threshold) \
   (basePointer->THRESHOLD.U32 = threshold)


/// @fn _SI32_LPTIMER_B_read_threshold(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Reads THRESHOLD register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_B_read_threshold(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_read_threshold(basePointer)
#define SI32_LPTIMER_B_read_threshold(basePointer) \
(basePointer->THRESHOLD.U32)


/// @fn _SI32_LPTIMER_B_write_compare0(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t compare0)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  compare0
///  Valid range is 16 bits.
///
void
_SI32_LPTIMER_B_write_compare0(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*compare0*/);
///
/// @def SI32_LPTIMER_B_write_compare0(basePointer, compare0)
#define SI32_LPTIMER_B_write_compare0(basePointer, compare0) \
   (basePointer->THRESHOLD.COMPARE0 = compare0)


/// @fn _SI32_LPTIMER_B_read_compare0(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_B_read_compare0(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_read_compare0(basePointer)
#define SI32_LPTIMER_B_read_compare0(basePointer) \
(basePointer->THRESHOLD.COMPARE0)


/// @fn _SI32_LPTIMER_B_write_compare1(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t compare1)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  compare1
///  Valid range is 16 bits.
///
void
_SI32_LPTIMER_B_write_compare1(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*compare1*/);
///
/// @def SI32_LPTIMER_B_write_compare1(basePointer, compare1)
#define SI32_LPTIMER_B_write_compare1(basePointer, compare1) \
   (basePointer->THRESHOLD.COMPARE1 = compare1)


/// @fn _SI32_LPTIMER_B_read_compare1(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_B_read_compare1(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_read_compare1(basePointer)
#define SI32_LPTIMER_B_read_compare1(basePointer) \
(basePointer->THRESHOLD.COMPARE1)


/// @fn _SI32_LPTIMER_B_write_status(SI32_LPTIMER_B_Type* basePointer,
///      uint32_t status)
///
/// @brief
/// Writes STATUS register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_LPTIMER_B_write_status(SI32_LPTIMER_B_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_LPTIMER_B_write_status(basePointer, status)
#define SI32_LPTIMER_B_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_LPTIMER_B_read_status(SI32_LPTIMER_B_Type* basePointer)
///
/// @brief
/// Reads STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_B_read_status(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_read_status(basePointer)
#define SI32_LPTIMER_B_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_LPTIMER_B_is_overflow_interrupt_pending(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_is_overflow_interrupt_pending(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_is_overflow_interrupt_pending(basePointer)
#define SI32_LPTIMER_B_is_overflow_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.OVFI))


/// @fn _SI32_LPTIMER_B_clear_overflow_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_clear_overflow_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_clear_overflow_interrupt(basePointer)
#define SI32_LPTIMER_B_clear_overflow_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_LPTIMER_B_STATUS_OVFI_MASK)


/// @fn _SI32_LPTIMER_B_is_compare0_interrupt_pending(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_is_compare0_interrupt_pending(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_is_compare0_interrupt_pending(basePointer)
#define SI32_LPTIMER_B_is_compare0_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.CMP0I))


/// @fn _SI32_LPTIMER_B_clear_compare0_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_clear_compare0_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_clear_compare0_interrupt(basePointer)
#define SI32_LPTIMER_B_clear_compare0_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_LPTIMER_B_STATUS_CMP0I_MASK)


/// @fn _SI32_LPTIMER_B_is_compare1_interrupt_pending(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_B_is_compare1_interrupt_pending(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_is_compare1_interrupt_pending(basePointer)
#define SI32_LPTIMER_B_is_compare1_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.CMP1I))


/// @fn _SI32_LPTIMER_B_clear_compare1_interrupt(SI32_LPTIMER_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_B_clear_compare1_interrupt(SI32_LPTIMER_B_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_B_clear_compare1_interrupt(basePointer)
#define SI32_LPTIMER_B_clear_compare1_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_LPTIMER_B_STATUS_CMP1I_MASK)



#ifdef __cplusplus
}
#endif

#endif // __SI32_LPTIMER_B_TYPE_H__

//-eof--------------------------------------------------------------------------
