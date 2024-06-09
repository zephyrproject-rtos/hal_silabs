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
/// @file SI32_LPTIMER_A_Type.h
//
// Script: 0.58
// HAL Source: 0.4
// Version: 1

#ifndef __SI32_LPTIMER_A_TYPE_H__
#define __SI32_LPTIMER_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_LPTIMER_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_LPTIMER_A_initialize(SI32_LPTIMER_A_Type* basePointer,
///      uint32_t control,
///      uint32_t data,
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
///  data
///  Valid range is 32 bits.
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_LPTIMER_A_initialize(SI32_LPTIMER_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*data*/
   uint32_t /*status*/);
///
/// @def SI32_LPTIMER_A_initialize(basePointer, control, data, status)
#define SI32_LPTIMER_A_initialize(basePointer, control, data, status) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->DATA.U32 = data;\
   basePointer->STATUS.U32 = status;\
} while(0)


/// @fn _SI32_LPTIMER_A_write_control(SI32_LPTIMER_A_Type* basePointer,
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
_SI32_LPTIMER_A_write_control(SI32_LPTIMER_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_LPTIMER_A_write_control(basePointer, control)
#define SI32_LPTIMER_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_LPTIMER_A_read_control(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_A_read_control(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_read_control(basePointer)
#define SI32_LPTIMER_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_LPTIMER_A_select_free_run_mode(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_select_free_run_mode(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_select_free_run_mode(basePointer)
#define SI32_LPTIMER_A_select_free_run_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMD_MASK)


/// @fn _SI32_LPTIMER_A_select_rising_edge_increment_mode(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_select_rising_edge_increment_mode(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_select_rising_edge_increment_mode(basePointer)
#define SI32_LPTIMER_A_select_rising_edge_increment_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMD_MASK;\
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMD_RISING_EDGE_U32;\
} while(0)


/// @fn _SI32_LPTIMER_A_select_falling_edge_increment_mode(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_select_falling_edge_increment_mode(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_select_falling_edge_increment_mode(basePointer)
#define SI32_LPTIMER_A_select_falling_edge_increment_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMD_MASK;\
   basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMD_FALLING_EDGE_U32;\
} while(0)


/// @fn _SI32_LPTIMER_A_select_both_edge_increment_mode(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_select_both_edge_increment_mode(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_select_both_edge_increment_mode(basePointer)
#define SI32_LPTIMER_A_select_both_edge_increment_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMD_MASK)


/// @fn _SI32_LPTIMER_A_select_timer_source(SI32_LPTIMER_A_Type* basePointer,
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
_SI32_LPTIMER_A_select_timer_source(SI32_LPTIMER_A_Type* /*basePointer*/,
   uint32_t /*source*/);
///
/// @def SI32_LPTIMER_A_select_timer_source(basePointer, source)
#define SI32_LPTIMER_A_select_timer_source(basePointer, source) do{  \
   basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_EXTSEL_MASK;\
   basePointer->CONTROL_SET = source << SI32_LPTIMER_A_CONTROL_EXTSEL_SHIFT;\
} while(0)


/// @fn _SI32_LPTIMER_A_start_timer_write(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Initiates copy from DATA register to internal timer register.
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_start_timer_write(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_start_timer_write(basePointer)
#define SI32_LPTIMER_A_start_timer_write(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_TMRSET_SET_U32)


/// @fn _SI32_LPTIMER_A_has_timer_write_occurred(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Returns whether or not the last timer write request has finished.
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_has_timer_write_occurred(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_has_timer_write_occurred(basePointer)
#define SI32_LPTIMER_A_has_timer_write_occurred(basePointer) \
(!(bool)(basePointer->CONTROL.TMRSET))


/// @fn _SI32_LPTIMER_A_start_timer_read(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Initiates copy from internal timer register to DATA register.
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_start_timer_read(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_start_timer_read(basePointer)
#define SI32_LPTIMER_A_start_timer_read(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_TMRCAP_SET_U32)


/// @fn _SI32_LPTIMER_A_has_timer_read_occurred(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Returns whether or not the last timer read request has finished.
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_has_timer_read_occurred(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_has_timer_read_occurred(basePointer)
#define SI32_LPTIMER_A_has_timer_read_occurred(basePointer) \
(!(bool)(basePointer->CONTROL.TMRCAP))


/// @fn _SI32_LPTIMER_A_start_comparator_write(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Initiates copy from DATA register to internal comparator register.
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_start_comparator_write(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_start_comparator_write(basePointer)
#define SI32_LPTIMER_A_start_comparator_write(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPSET_SET_U32)


/// @fn _SI32_LPTIMER_A_has_comparator_write_occurred(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Returns whether or not the last comparator write request has finished.
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_has_comparator_write_occurred(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_has_comparator_write_occurred(basePointer)
#define SI32_LPTIMER_A_has_comparator_write_occurred(basePointer) \
(!(bool)(basePointer->CONTROL.CMPSET))


/// @fn _SI32_LPTIMER_A_start_comparator_read(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Initiates copy from internal comparator register to DATA register.
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_start_comparator_read(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_start_comparator_read(basePointer)
#define SI32_LPTIMER_A_start_comparator_read(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPCAP_SET_U32)


/// @fn _SI32_LPTIMER_A_has_comparator_read_occurred(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Returns whether or not the last comparator read request has finished.
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_has_comparator_read_occurred(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_has_comparator_read_occurred(basePointer)
#define SI32_LPTIMER_A_has_comparator_read_occurred(basePointer) \
(!(bool)(basePointer->CONTROL.CMPCAP))


/// @fn _SI32_LPTIMER_A_enable_overflow_interrupt(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_enable_overflow_interrupt(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_enable_overflow_interrupt(basePointer)
#define SI32_LPTIMER_A_enable_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_OVFIEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_A_disable_overflow_interrupt(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_disable_overflow_interrupt(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_disable_overflow_interrupt(basePointer)
#define SI32_LPTIMER_A_disable_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_OVFIEN_MASK)


/// @fn _SI32_LPTIMER_A_is_overflow_interrupt_enabled(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_is_overflow_interrupt_enabled(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_is_overflow_interrupt_enabled(basePointer)
#define SI32_LPTIMER_A_is_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.OVFIEN))


/// @fn _SI32_LPTIMER_A_enable_compare_interrupt(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_enable_compare_interrupt(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_enable_compare_interrupt(basePointer)
#define SI32_LPTIMER_A_enable_compare_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPIEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_A_disable_compare_interrupt(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_disable_compare_interrupt(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_disable_compare_interrupt(basePointer)
#define SI32_LPTIMER_A_disable_compare_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMPIEN_MASK)


/// @fn _SI32_LPTIMER_A_is_compare_interrupt_enabled(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_is_compare_interrupt_enabled(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_is_compare_interrupt_enabled(basePointer)
#define SI32_LPTIMER_A_is_compare_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.CMPIEN))


/// @fn _SI32_LPTIMER_A_enable_output_toggle_upon_overflow(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_enable_output_toggle_upon_overflow(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_enable_output_toggle_upon_overflow(basePointer)
#define SI32_LPTIMER_A_enable_output_toggle_upon_overflow(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_OVFTMD_ENABLED_U32)


/// @fn _SI32_LPTIMER_A_disable_output_toggle_upon_overflow(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_disable_output_toggle_upon_overflow(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_disable_output_toggle_upon_overflow(basePointer)
#define SI32_LPTIMER_A_disable_output_toggle_upon_overflow(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_OVFTMD_MASK)


/// @fn _SI32_LPTIMER_A_enable_output_toggle_upon_compare(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_enable_output_toggle_upon_compare(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_enable_output_toggle_upon_compare(basePointer)
#define SI32_LPTIMER_A_enable_output_toggle_upon_compare(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPTMD_ENABLED_U32)


/// @fn _SI32_LPTIMER_A_disable_output_toggle_upon_compare(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_disable_output_toggle_upon_compare(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_disable_output_toggle_upon_compare(basePointer)
#define SI32_LPTIMER_A_disable_output_toggle_upon_compare(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMPTMD_MASK)


/// @fn _SI32_LPTIMER_A_enable_timer_reset_upon_compare(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_enable_timer_reset_upon_compare(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_enable_timer_reset_upon_compare(basePointer)
#define SI32_LPTIMER_A_enable_timer_reset_upon_compare(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_CMPRSTEN_ENABLED_U32)


/// @fn _SI32_LPTIMER_A_disable_timer_reset_upon_compare(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_disable_timer_reset_upon_compare(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_disable_timer_reset_upon_compare(basePointer)
#define SI32_LPTIMER_A_disable_timer_reset_upon_compare(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_CMPRSTEN_MASK)


/// @fn _SI32_LPTIMER_A_enable_stall_in_debug_mode(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_enable_stall_in_debug_mode(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_enable_stall_in_debug_mode(basePointer)
#define SI32_LPTIMER_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_DBGMD_HALT_U32)


/// @fn _SI32_LPTIMER_A_disable_stall_in_debug_mode(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_disable_stall_in_debug_mode(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_disable_stall_in_debug_mode(basePointer)
#define SI32_LPTIMER_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_LPTIMER_A_start_timer(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_start_timer(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_start_timer(basePointer)
#define SI32_LPTIMER_A_start_timer(basePointer) \
   (basePointer->CONTROL_SET = SI32_LPTIMER_A_CONTROL_RUN_MASK)


/// @fn _SI32_LPTIMER_A_stop_timer(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_stop_timer(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_stop_timer(basePointer)
#define SI32_LPTIMER_A_stop_timer(basePointer) \
   (basePointer->CONTROL_CLR = SI32_LPTIMER_A_CONTROL_RUN_MASK)


/// @fn _SI32_LPTIMER_A_write_data(SI32_LPTIMER_A_Type* basePointer,
///      uint32_t data)
///
/// @brief
/// Writes DATA register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data
///  Valid range is 32 bits.
///
void
_SI32_LPTIMER_A_write_data(SI32_LPTIMER_A_Type* /*basePointer*/,
   uint32_t /*data*/);
///
/// @def SI32_LPTIMER_A_write_data(basePointer, data)
#define SI32_LPTIMER_A_write_data(basePointer, data) \
   (basePointer->DATA.U32 = data)


/// @fn _SI32_LPTIMER_A_read_data(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Reads DATA register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_A_read_data(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_read_data(basePointer)
#define SI32_LPTIMER_A_read_data(basePointer) \
(basePointer->DATA.U32)


/// @fn _SI32_LPTIMER_A_write_status(SI32_LPTIMER_A_Type* basePointer,
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
_SI32_LPTIMER_A_write_status(SI32_LPTIMER_A_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_LPTIMER_A_write_status(basePointer, status)
#define SI32_LPTIMER_A_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_LPTIMER_A_read_status(SI32_LPTIMER_A_Type* basePointer)
///
/// @brief
/// Reads STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LPTIMER_A_read_status(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_read_status(basePointer)
#define SI32_LPTIMER_A_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_LPTIMER_A_is_overflow_interrupt_pending(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_is_overflow_interrupt_pending(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_is_overflow_interrupt_pending(basePointer)
#define SI32_LPTIMER_A_is_overflow_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.OVFI))


/// @fn _SI32_LPTIMER_A_clear_overflow_interrupt(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_clear_overflow_interrupt(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_clear_overflow_interrupt(basePointer)
#define SI32_LPTIMER_A_clear_overflow_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_LPTIMER_A_STATUS_OVFI_MASK)


/// @fn _SI32_LPTIMER_A_is_compare_interrupt_pending(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_LPTIMER_A_is_compare_interrupt_pending(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_is_compare_interrupt_pending(basePointer)
#define SI32_LPTIMER_A_is_compare_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.CMPI))


/// @fn _SI32_LPTIMER_A_clear_compare_interrupt(SI32_LPTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LPTIMER_A_clear_compare_interrupt(SI32_LPTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_LPTIMER_A_clear_compare_interrupt(basePointer)
#define SI32_LPTIMER_A_clear_compare_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_LPTIMER_A_STATUS_CMPI_MASK)



#ifdef __cplusplus
}
#endif

#endif // __SI32_LPTIMER_A_TYPE_H__

//-eof--------------------------------------------------------------------------
