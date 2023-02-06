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
/// @file SI32_EPCA_A_Type.h
//
// Script: 0.58
// HAL Source: 1.0
// Version: 2

#ifndef __SI32_EPCA_A_TYPE_H__
#define __SI32_EPCA_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_EPCA_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_EPCA_A_initialize(SI32_EPCA_A_Type* basePointer,
///      uint32_t mode,
///      uint32_t control,
///      uint32_t status,
///      uint32_t counter,
///      uint32_t limit,
///      uint32_t limitupd,
///      uint32_t dtime,
///      uint32_t dtarget)
///
/// @brief
/// Writes all EPCA registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///  The specified DPTR field is incremented after the function completes.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
/// @param[in]
///  counter
///  Valid range is 32 bits.
///
/// @param[in]
///  limit
///  Valid range is 32 bits.
///
/// @param[in]
///  limitupd
///  Valid range is 32 bits.
///
/// @param[in]
///  dtime
///  Valid range is 32 bits.
///
/// @param[in]
///  dtarget
///  Valid range is 32 bits.
///  Writes based on the specified DPTR field in the mode parameter.
///
void
_SI32_EPCA_A_initialize(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t, /*mode*/
   uint32_t, /*control*/
   uint32_t, /*status*/
   uint32_t, /*counter*/
   uint32_t, /*limit*/
   uint32_t, /*limitupd*/
   uint32_t, /*dtime*/
   uint32_t /*dtarget*/);
///
/// @def SI32_EPCA_A_initialize(basePointer, mode, control, status, counter, limit, limitupd, dtime, dtarget)
#define SI32_EPCA_A_initialize(basePointer, mode, control, status, counter, limit, limitupd, dtime, dtarget) do{  \
   basePointer->MODE.U32 = mode;\
   basePointer->CONTROL.U32 = control;\
   basePointer->STATUS.U32 = status;\
   basePointer->COUNTER.U32 = counter;\
   basePointer->LIMIT.U32 = limit;\
   basePointer->LIMITUPD.U32 = limitupd;\
   basePointer->DTIME.U32 = dtime;\
   basePointer->DTARGET.U32 = dtarget;\
} while(0)


/// @fn _SI32_EPCA_A_write_mode(SI32_EPCA_A_Type* basePointer,
///      uint32_t mode)
///
/// @brief
/// Writes MODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///
void
_SI32_EPCA_A_write_mode(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_EPCA_A_write_mode(basePointer, mode)
#define SI32_EPCA_A_write_mode(basePointer, mode) \
   (basePointer->MODE.U32 = mode)


/// @fn _SI32_EPCA_A_read_mode(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Reads MODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EPCA_A_read_mode(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_read_mode(basePointer)
#define SI32_EPCA_A_read_mode(basePointer) \
(basePointer->MODE.U32)


/// @fn _SI32_EPCA_A_select_input_clock_divisor(SI32_EPCA_A_Type* basePointer,
///      uint32_t divisor)
///
/// @brief
/// Selects the divisor for the input clock.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divisor
///  Valid range is 1 to 1024.
///  EPCA clock frequency is given by (input clock frequency) / (divisor +
///  1).
///
void
_SI32_EPCA_A_select_input_clock_divisor(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*divisor*/);
///
/// @def SI32_EPCA_A_select_input_clock_divisor(basePointer, divisor)
#define SI32_EPCA_A_select_input_clock_divisor(basePointer, divisor) \
   (basePointer->MODE.CLKDIV = divisor)


/// @fn _SI32_EPCA_A_select_input_clock_apb(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_input_clock_apb(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_input_clock_apb(basePointer)
#define SI32_EPCA_A_select_input_clock_apb(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_APB_VALUE)


/// @fn _SI32_EPCA_A_select_input_clock_timer0_overflow(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_input_clock_timer0_overflow(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_input_clock_timer0_overflow(basePointer)
#define SI32_EPCA_A_select_input_clock_timer0_overflow(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_TIMER0_VALUE)


/// @fn _SI32_EPCA_A_select_input_clock_eci_high_to_low(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_input_clock_eci_high_to_low(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_input_clock_eci_high_to_low(basePointer)
#define SI32_EPCA_A_select_input_clock_eci_high_to_low(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_HL_ECI_VALUE)


/// @fn _SI32_EPCA_A_select_input_clock_external_oscillator(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_input_clock_external_oscillator(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_input_clock_external_oscillator(basePointer)
#define SI32_EPCA_A_select_input_clock_external_oscillator(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_EXTOSCN_VALUE)


/// @fn _SI32_EPCA_A_select_input_clock_eci(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_input_clock_eci(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_input_clock_eci(basePointer)
#define SI32_EPCA_A_select_input_clock_eci(basePointer) \
   (basePointer->MODE.CLKSEL = SI32_EPCA_A_MODE_CLKSEL_ECI_VALUE)


/// @fn _SI32_EPCA_A_select_high_drive_port_0_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects non-differential output from channels 0-5 to high-drive pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_high_drive_port_0_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_high_drive_port_0_differential(basePointer)
#define SI32_EPCA_A_select_high_drive_port_0_differential(basePointer) \
   (basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_NO_DIFF_VALUE)


/// @fn _SI32_EPCA_A_select_high_drive_port_1_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects differential output from channel 5 and non-differential output
/// from channels 1-4 to high-drive pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_high_drive_port_1_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_high_drive_port_1_differential(basePointer)
#define SI32_EPCA_A_select_high_drive_port_1_differential(basePointer) \
   (basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_ONE_DIFF_VALUE)


/// @fn _SI32_EPCA_A_select_high_drive_port_2_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects differential output from channels 4-5 and non-differential
/// output from channels 2-3 to high-drive pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_high_drive_port_2_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_high_drive_port_2_differential(basePointer)
#define SI32_EPCA_A_select_high_drive_port_2_differential(basePointer) \
   (basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_TWO_DIFF_VALUE)


/// @fn _SI32_EPCA_A_select_high_drive_port_3_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects differential output from channels 3-5 to high-drive pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_high_drive_port_3_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_high_drive_port_3_differential(basePointer)
#define SI32_EPCA_A_select_high_drive_port_3_differential(basePointer) \
   (basePointer->MODE.HDOSEL = SI32_EPCA_A_MODE_HDOSEL_THREE_DIFF_VALUE)


/// @fn _SI32_EPCA_A_get_dma_write_end_index(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Returns last register to be accessed in a new DMA write transfer set.
///
/// @return
///  Last register: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
///  CCAPVUPD).
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EPCA_A_get_dma_write_end_index(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_get_dma_write_end_index(basePointer)
#define SI32_EPCA_A_get_dma_write_end_index(basePointer) \
(basePointer->MODE.DEND)


/// @fn _SI32_EPCA_A_set_dma_write_end_index(SI32_EPCA_A_Type* basePointer,
///      uint32_t index)
///
/// @brief
/// Sets last register to be accessed in a new DMA write transfer set.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 3 bits.
///  Last register: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
///  CCAPVUPD).
///
void
_SI32_EPCA_A_set_dma_write_end_index(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*index*/);
///
/// @def SI32_EPCA_A_set_dma_write_end_index(basePointer, index)
#define SI32_EPCA_A_set_dma_write_end_index(basePointer, index) \
   (basePointer->MODE.DEND = index)


/// @fn _SI32_EPCA_A_get_dma_write_transfer_pointer(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Returns current target of the DMA.
///
/// @return
///  Target: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
///  CCAPVUPD).
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EPCA_A_get_dma_write_transfer_pointer(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_get_dma_write_transfer_pointer(basePointer)
#define SI32_EPCA_A_get_dma_write_transfer_pointer(basePointer) \
(basePointer->MODE.DPTR)


/// @fn _SI32_EPCA_A_set_dma_write_transfer_pointer(SI32_EPCA_A_Type* basePointer,
///      uint32_t index)
///
/// @brief
/// Sets current target of the DMA.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 3 bits.
///  Target: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
///  CCAPVUPD).
///
void
_SI32_EPCA_A_set_dma_write_transfer_pointer(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*index*/);
///
/// @def SI32_EPCA_A_set_dma_write_transfer_pointer(basePointer, index)
#define SI32_EPCA_A_set_dma_write_transfer_pointer(basePointer, index) \
   (basePointer->MODE.DPTR = index)


/// @fn _SI32_EPCA_A_get_dma_target_start_index(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Returns first register to be accessed in a new DMA write transfer set.
///
/// @return
///  First register: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
///  CCAPVUPD).
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EPCA_A_get_dma_target_start_index(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_get_dma_target_start_index(basePointer)
#define SI32_EPCA_A_get_dma_target_start_index(basePointer) \
(basePointer->MODE.DSTART)


/// @fn _SI32_EPCA_A_set_dma_target_start_index(SI32_EPCA_A_Type* basePointer,
///      uint32_t index)
///
/// @brief
/// Sets first register to be accessed in a new DMA write transfer set.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  index
///  Valid range is 3 bits.
///  First register: (0 = LIMIT, 1 = channel 0 CCAPVUPD, ..., 6 = channel 5
///  CCAPVUPD).
///
void
_SI32_EPCA_A_set_dma_target_start_index(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*index*/);
///
/// @def SI32_EPCA_A_set_dma_target_start_index(basePointer, index)
#define SI32_EPCA_A_set_dma_target_start_index(basePointer, index) \
   (basePointer->MODE.DSTART = index)


/// @fn _SI32_EPCA_A_is_dma_busy(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_EPCA_A_is_dma_busy(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_is_dma_busy(basePointer)
#define SI32_EPCA_A_is_dma_busy(basePointer) \
(basePointer->MODE.DBUSYF)


/// @fn _SI32_EPCA_A_set_dma_busy(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_set_dma_busy(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_set_dma_busy(basePointer)
#define SI32_EPCA_A_set_dma_busy(basePointer) \
   (basePointer->MODE.DBUSYF = SI32_EPCA_A_MODE_DBUSYF_BUSY_VALUE)


/// @fn _SI32_EPCA_A_clear_dma_busy(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_clear_dma_busy(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_clear_dma_busy(basePointer)
#define SI32_EPCA_A_clear_dma_busy(basePointer) \
   (basePointer->MODE.DBUSYF = SI32_EPCA_A_MODE_DBUSYF_IDLE_VALUE)


/// @fn _SI32_EPCA_A_select_standard_drive_port_0_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects non-differential output from channels 0-5 to standard pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_standard_drive_port_0_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_standard_drive_port_0_differential(basePointer)
#define SI32_EPCA_A_select_standard_drive_port_0_differential(basePointer) \
   (basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_NO_DIFF_VALUE)


/// @fn _SI32_EPCA_A_select_standard_drive_port_1_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects differential output from channel 2 and non-differential output
/// from channels 0-1 and 3-4 to standard pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_standard_drive_port_1_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_standard_drive_port_1_differential(basePointer)
#define SI32_EPCA_A_select_standard_drive_port_1_differential(basePointer) \
   (basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_ONE_DIFF_VALUE)


/// @fn _SI32_EPCA_A_select_standard_drive_port_2_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects differential output from channels 1-2 and non-differential
/// output from channels 0-3 to standard pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_standard_drive_port_2_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_standard_drive_port_2_differential(basePointer)
#define SI32_EPCA_A_select_standard_drive_port_2_differential(basePointer) \
   (basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_TWO_DIFF_VALUE)


/// @fn _SI32_EPCA_A_select_standard_drive_port_3_differential(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Selects differential output from channels 0-2 to standard pins.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_standard_drive_port_3_differential(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_standard_drive_port_3_differential(basePointer)
#define SI32_EPCA_A_select_standard_drive_port_3_differential(basePointer) \
   (basePointer->MODE.STDOSEL = SI32_EPCA_A_MODE_STDOSEL_THREE_DIFF_VALUE)


/// @fn _SI32_EPCA_A_write_control(SI32_EPCA_A_Type* basePointer,
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
_SI32_EPCA_A_write_control(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_EPCA_A_write_control(basePointer, control)
#define SI32_EPCA_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_EPCA_A_read_control(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EPCA_A_read_control(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_read_control(basePointer)
#define SI32_EPCA_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_EPCA_A_enable_counter_overflow_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_counter_overflow_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_counter_overflow_interrupt(basePointer)
#define SI32_EPCA_A_enable_counter_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_OVFIEN_ENABLED_U32)


/// @fn _SI32_EPCA_A_disable_counter_overflow_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_counter_overflow_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_counter_overflow_interrupt(basePointer)
#define SI32_EPCA_A_disable_counter_overflow_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_OVFIEN_MASK)


/// @fn _SI32_EPCA_A_is_counter_overflow_interrupt_enabled(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_EPCA_A_is_counter_overflow_interrupt_enabled(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_is_counter_overflow_interrupt_enabled(basePointer)
#define SI32_EPCA_A_is_counter_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.OVFIEN))


/// @fn _SI32_EPCA_A_enable_counter_overflow_dma_request(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_counter_overflow_dma_request(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_counter_overflow_dma_request(basePointer)
#define SI32_EPCA_A_enable_counter_overflow_dma_request(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_OVFDEN_ENABLED_U32)


/// @fn _SI32_EPCA_A_disable_counter_overflow_dma_request(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_counter_overflow_dma_request(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_counter_overflow_dma_request(basePointer)
#define SI32_EPCA_A_disable_counter_overflow_dma_request(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_OVFDEN_MASK)


/// @fn _SI32_EPCA_A_enable_counter_overflow_synchronization_signal(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_counter_overflow_synchronization_signal(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_counter_overflow_synchronization_signal(basePointer)
#define SI32_EPCA_A_enable_counter_overflow_synchronization_signal(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_OVFSEN_ENABLED_U32)


/// @fn _SI32_EPCA_A_disable_counter_overflow_synchronization_signal(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_counter_overflow_synchronization_signal(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_counter_overflow_synchronization_signal(basePointer)
#define SI32_EPCA_A_disable_counter_overflow_synchronization_signal(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_OVFSEN_MASK)


/// @fn _SI32_EPCA_A_enable_halt_input_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_halt_input_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_halt_input_interrupt(basePointer)
#define SI32_EPCA_A_enable_halt_input_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_HALTIEN_ENABLED_U32)


/// @fn _SI32_EPCA_A_disable_halt_input_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_halt_input_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_halt_input_interrupt(basePointer)
#define SI32_EPCA_A_disable_halt_input_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_HALTIEN_MASK)


/// @fn _SI32_EPCA_A_is_halt_interrupt_enabled(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_EPCA_A_is_halt_interrupt_enabled(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_is_halt_interrupt_enabled(basePointer)
#define SI32_EPCA_A_is_halt_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.HALTIEN))


/// @fn _SI32_EPCA_A_enable_internal_register_update_on_overflow(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_internal_register_update_on_overflow(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_internal_register_update_on_overflow(basePointer)
#define SI32_EPCA_A_enable_internal_register_update_on_overflow(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_NOUPD_MASK)


/// @fn _SI32_EPCA_A_disable_internal_register_update_on_overflow(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_internal_register_update_on_overflow(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_internal_register_update_on_overflow(basePointer)
#define SI32_EPCA_A_disable_internal_register_update_on_overflow(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_NOUPD_ACTIVE_U32)


/// @fn _SI32_EPCA_A_enable_stall_in_debug_mode(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_stall_in_debug_mode(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_stall_in_debug_mode(basePointer)
#define SI32_EPCA_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_EPCA_A_disable_stall_in_debug_mode(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_stall_in_debug_mode(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_stall_in_debug_mode(basePointer)
#define SI32_EPCA_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_DBGMD_RUN_U32)


/// @fn _SI32_EPCA_A_enable_halt_input(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_halt_input(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_halt_input(basePointer)
#define SI32_EPCA_A_enable_halt_input(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_HALTEN_ENABLED_U32)


/// @fn _SI32_EPCA_A_disable_halt_input(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_halt_input(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_halt_input(basePointer)
#define SI32_EPCA_A_disable_halt_input(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_HALTEN_MASK)


/// @fn _SI32_EPCA_A_select_synchronous_input_trigger(SI32_EPCA_A_Type* basePointer,
///      uint32_t trigger)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  trigger
///  Valid range is 0 to 3.
///  Input trigger number (0 = EPCAnT0, ..., 3 = EPCAnT3).
///
void
_SI32_EPCA_A_select_synchronous_input_trigger(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*trigger*/);
///
/// @def SI32_EPCA_A_select_synchronous_input_trigger(basePointer, trigger)
#define SI32_EPCA_A_select_synchronous_input_trigger(basePointer, trigger) do{  \
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_STSEL_MASK;\
   basePointer->CONTROL_SET = trigger << SI32_EPCA_A_CONTROL_STSEL_SHIFT;\
} while(0)


/// @fn _SI32_EPCA_A_select_synchronous_input_trigger_edge_falling(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_synchronous_input_trigger_edge_falling(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_synchronous_input_trigger_edge_falling(basePointer)
#define SI32_EPCA_A_select_synchronous_input_trigger_edge_falling(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_STESEL_MASK)


/// @fn _SI32_EPCA_A_select_synchronous_input_trigger_edge_rising(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_synchronous_input_trigger_edge_rising(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_synchronous_input_trigger_edge_rising(basePointer)
#define SI32_EPCA_A_select_synchronous_input_trigger_edge_rising(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_STESEL_RISING_U32)


/// @fn _SI32_EPCA_A_enable_synchronous_input_trigger(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_enable_synchronous_input_trigger(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_enable_synchronous_input_trigger(basePointer)
#define SI32_EPCA_A_enable_synchronous_input_trigger(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_STEN_ENABLED_U32)


/// @fn _SI32_EPCA_A_disable_synchronous_input_trigger(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_disable_synchronous_input_trigger(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_disable_synchronous_input_trigger(basePointer)
#define SI32_EPCA_A_disable_synchronous_input_trigger(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_STEN_MASK)


/// @fn _SI32_EPCA_A_is_clock_divider_in_phase_2(SI32_EPCA_A_Type* basePointer)
///
/// @return
///  Returns TRUE if clock divider is in second count-down phase, FALSE if
///  clock divider is in first count-down phase.
///
/// @param[in]
///  basePointer
///
bool
_SI32_EPCA_A_is_clock_divider_in_phase_2(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_is_clock_divider_in_phase_2(basePointer)
#define SI32_EPCA_A_is_clock_divider_in_phase_2(basePointer) \
((bool)(basePointer->CONTROL.DIVST))


/// @fn _SI32_EPCA_A_select_clock_divider_state_phase_1(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Sets the clock divider to first count-down phase.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_clock_divider_state_phase_1(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_clock_divider_state_phase_1(basePointer)
#define SI32_EPCA_A_select_clock_divider_state_phase_1(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_DIVST_MASK)


/// @fn _SI32_EPCA_A_select_clock_divider_state_phase_2(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Sets the clock divider to second count-down phase.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_select_clock_divider_state_phase_2(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_select_clock_divider_state_phase_2(basePointer)
#define SI32_EPCA_A_select_clock_divider_state_phase_2(basePointer) \
   (basePointer->CONTROL_SET = SI32_EPCA_A_CONTROL_DIVST_MASK)


/// @fn _SI32_EPCA_A_get_clock_divider(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Gets EPCA clock divider.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EPCA_A_get_clock_divider(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_get_clock_divider(basePointer)
#define SI32_EPCA_A_get_clock_divider(basePointer) \
(basePointer->CONTROL.DIV)


/// @fn _SI32_EPCA_A_set_clock_divider(SI32_EPCA_A_Type* basePointer,
///      uint32_t divider)
///
/// @brief
/// Sets EPCA clock divider.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divider
///  Valid range is 10 bits.
///
void
_SI32_EPCA_A_set_clock_divider(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*divider*/);
///
/// @def SI32_EPCA_A_set_clock_divider(basePointer, divider)
#define SI32_EPCA_A_set_clock_divider(basePointer, divider) do{  \
   basePointer->CONTROL_CLR = SI32_EPCA_A_CONTROL_DIV_MASK;\
   basePointer->CONTROL_SET = divider << SI32_EPCA_A_CONTROL_DIV_SHIFT;\
} while(0)


/// @fn _SI32_EPCA_A_write_status(SI32_EPCA_A_Type* basePointer,
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
_SI32_EPCA_A_write_status(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_EPCA_A_write_status(basePointer, status)
#define SI32_EPCA_A_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_EPCA_A_read_status(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Reads STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EPCA_A_read_status(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_read_status(basePointer)
#define SI32_EPCA_A_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_EPCA_A_is_channel_n_capture_compare_interrupt_pending(SI32_EPCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 5.
///  Channel number (0-5).
///
bool
_SI32_EPCA_A_is_channel_n_capture_compare_interrupt_pending(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_EPCA_A_is_channel_n_capture_compare_interrupt_pending(basePointer, channel)
#define SI32_EPCA_A_is_channel_n_capture_compare_interrupt_pending(basePointer, channel) \
   _SI32_EPCA_A_is_channel_n_capture_compare_interrupt_pending(basePointer, channel) 


/// @fn _SI32_EPCA_A_set_channel_n_capture_compare_interrupt(SI32_EPCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @brief
/// Forces channel n capture/compare interrupt.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 5.
///  Channel number (0-5).
///
void
_SI32_EPCA_A_set_channel_n_capture_compare_interrupt(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_EPCA_A_set_channel_n_capture_compare_interrupt(basePointer, channel)
#define SI32_EPCA_A_set_channel_n_capture_compare_interrupt(basePointer, channel) \
   _SI32_EPCA_A_set_channel_n_capture_compare_interrupt(basePointer, channel) 


/// @fn _SI32_EPCA_A_clear_channel_n_capture_compare_interrupt(SI32_EPCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 5.
///  Channel number (0-5).
///
void
_SI32_EPCA_A_clear_channel_n_capture_compare_interrupt(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_EPCA_A_clear_channel_n_capture_compare_interrupt(basePointer, channel)
#define SI32_EPCA_A_clear_channel_n_capture_compare_interrupt(basePointer, channel) \
   _SI32_EPCA_A_clear_channel_n_capture_compare_interrupt(basePointer, channel) 


/// @fn _SI32_EPCA_A_start_counter_timer(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_start_counter_timer(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_start_counter_timer(basePointer)
#define SI32_EPCA_A_start_counter_timer(basePointer) \
   (basePointer->STATUS_SET = SI32_EPCA_A_STATUS_RUN_START_U32)


/// @fn _SI32_EPCA_A_stop_counter_timer(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_stop_counter_timer(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_stop_counter_timer(basePointer)
#define SI32_EPCA_A_stop_counter_timer(basePointer) \
   (basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_RUN_MASK)


/// @fn _SI32_EPCA_A_is_counter_timer_overflow_interrupt_pending(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_EPCA_A_is_counter_timer_overflow_interrupt_pending(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_is_counter_timer_overflow_interrupt_pending(basePointer)
#define SI32_EPCA_A_is_counter_timer_overflow_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.OVFI))


/// @fn _SI32_EPCA_A_set_counter_timer_overflow_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Forces EPCA counter/timer overflow interrupt.
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_set_counter_timer_overflow_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_set_counter_timer_overflow_interrupt(basePointer)
#define SI32_EPCA_A_set_counter_timer_overflow_interrupt(basePointer) \
   (basePointer->STATUS_SET = SI32_EPCA_A_STATUS_OVFI_SET_U32)


/// @fn _SI32_EPCA_A_clear_counter_timer_overflow_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_clear_counter_timer_overflow_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_clear_counter_timer_overflow_interrupt(basePointer)
#define SI32_EPCA_A_clear_counter_timer_overflow_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_OVFI_MASK)


/// @fn _SI32_EPCA_A_is_register_update_pending(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_EPCA_A_is_register_update_pending(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_is_register_update_pending(basePointer)
#define SI32_EPCA_A_is_register_update_pending(basePointer) \
((bool)(basePointer->STATUS.UPDCF))


/// @fn _SI32_EPCA_A_set_register_update_complete_flag(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_set_register_update_complete_flag(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_set_register_update_complete_flag(basePointer)
#define SI32_EPCA_A_set_register_update_complete_flag(basePointer) \
   (basePointer->STATUS_SET = SI32_EPCA_A_STATUS_UPDCF_FULL_U32)


/// @fn _SI32_EPCA_A_clear_register_update_complete_flag(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_clear_register_update_complete_flag(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_clear_register_update_complete_flag(basePointer)
#define SI32_EPCA_A_clear_register_update_complete_flag(basePointer) \
   (basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_UPDCF_MASK)


/// @fn _SI32_EPCA_A_is_halt_input_interrupt_pending(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_EPCA_A_is_halt_input_interrupt_pending(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_is_halt_input_interrupt_pending(basePointer)
#define SI32_EPCA_A_is_halt_input_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.HALTI))


/// @fn _SI32_EPCA_A_set_halt_input_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Forces halt input interrupt (PB_HDKill).
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_set_halt_input_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_set_halt_input_interrupt(basePointer)
#define SI32_EPCA_A_set_halt_input_interrupt(basePointer) \
   (basePointer->STATUS_SET = SI32_EPCA_A_STATUS_HALTI_SET_U32)


/// @fn _SI32_EPCA_A_clear_halt_input_interrupt(SI32_EPCA_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EPCA_A_clear_halt_input_interrupt(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_clear_halt_input_interrupt(basePointer)
#define SI32_EPCA_A_clear_halt_input_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_EPCA_A_STATUS_HALTI_MASK)


/// @fn _SI32_EPCA_A_is_channel_n_intermediate_overflow_interrupt_pending(SI32_EPCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 5.
///  Channel number (0-5).
///
bool
_SI32_EPCA_A_is_channel_n_intermediate_overflow_interrupt_pending(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_EPCA_A_is_channel_n_intermediate_overflow_interrupt_pending(basePointer, channel)
#define SI32_EPCA_A_is_channel_n_intermediate_overflow_interrupt_pending(basePointer, channel) \
   _SI32_EPCA_A_is_channel_n_intermediate_overflow_interrupt_pending(basePointer, channel) 


/// @fn _SI32_EPCA_A_set_channel_n_intermediate_overflow_interrupt(SI32_EPCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @brief
/// Forces channel n intermediate overflow interrupt.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 5.
///  Channel number (0-5).
///
void
_SI32_EPCA_A_set_channel_n_intermediate_overflow_interrupt(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_EPCA_A_set_channel_n_intermediate_overflow_interrupt(basePointer, channel)
#define SI32_EPCA_A_set_channel_n_intermediate_overflow_interrupt(basePointer, channel) \
   _SI32_EPCA_A_set_channel_n_intermediate_overflow_interrupt(basePointer, channel) 


/// @fn _SI32_EPCA_A_clear_channel_n_intermediate_overflow_interrupt(SI32_EPCA_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 5.
///  Channel number (0-5).
///
void
_SI32_EPCA_A_clear_channel_n_intermediate_overflow_interrupt(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_EPCA_A_clear_channel_n_intermediate_overflow_interrupt(basePointer, channel)
#define SI32_EPCA_A_clear_channel_n_intermediate_overflow_interrupt(basePointer, channel) \
   _SI32_EPCA_A_clear_channel_n_intermediate_overflow_interrupt(basePointer, channel) 


/// @fn _SI32_EPCA_A_write_counter(SI32_EPCA_A_Type* basePointer,
///      uwide16_t counter)
///
/// @brief
/// Writes COUNTER register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  counter
///  Valid range is 32 bits.
///
void
_SI32_EPCA_A_write_counter(SI32_EPCA_A_Type* /*basePointer*/,
   uwide16_t /*counter*/);
///
/// @def SI32_EPCA_A_write_counter(basePointer, counter)
#define SI32_EPCA_A_write_counter(basePointer, counter) \
   (basePointer->COUNTER.U32 = counter)


/// @fn _SI32_EPCA_A_read_counter(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Reads COUNTER register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_EPCA_A_read_counter(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_read_counter(basePointer)
#define SI32_EPCA_A_read_counter(basePointer) \
(basePointer->COUNTER.U32)


/// @fn _SI32_EPCA_A_write_limit(SI32_EPCA_A_Type* basePointer,
///      uwide16_t limit)
///
/// @brief
/// Writes LIMIT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  limit
///  Valid range is 32 bits.
///
void
_SI32_EPCA_A_write_limit(SI32_EPCA_A_Type* /*basePointer*/,
   uwide16_t /*limit*/);
///
/// @def SI32_EPCA_A_write_limit(basePointer, limit)
#define SI32_EPCA_A_write_limit(basePointer, limit) \
   (basePointer->LIMIT.U32 = limit)


/// @fn _SI32_EPCA_A_read_limit(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Reads LIMIT register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_EPCA_A_read_limit(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_read_limit(basePointer)
#define SI32_EPCA_A_read_limit(basePointer) \
(basePointer->LIMIT.U32)


/// @fn _SI32_EPCA_A_write_limitupd(SI32_EPCA_A_Type* basePointer,
///      uwide16_t limitupd)
///
/// @brief
/// Writes LIMITUPD register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  limitupd
///  Valid range is 32 bits.
///
void
_SI32_EPCA_A_write_limitupd(SI32_EPCA_A_Type* /*basePointer*/,
   uwide16_t /*limitupd*/);
///
/// @def SI32_EPCA_A_write_limitupd(basePointer, limitupd)
#define SI32_EPCA_A_write_limitupd(basePointer, limitupd) \
   (basePointer->LIMITUPD.U32 = limitupd)


/// @fn _SI32_EPCA_A_read_limitupd(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Reads LIMITUPD register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_EPCA_A_read_limitupd(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_read_limitupd(basePointer)
#define SI32_EPCA_A_read_limitupd(basePointer) \
(basePointer->LIMITUPD.U32)


/// @fn _SI32_EPCA_A_write_dtime(SI32_EPCA_A_Type* basePointer,
///      uwide16_t dtime)
///
/// @brief
/// Writes DTIME register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dtime
///  Valid range is 32 bits.
///
void
_SI32_EPCA_A_write_dtime(SI32_EPCA_A_Type* /*basePointer*/,
   uwide16_t /*dtime*/);
///
/// @def SI32_EPCA_A_write_dtime(basePointer, dtime)
#define SI32_EPCA_A_write_dtime(basePointer, dtime) \
   (basePointer->DTIME.U32 = dtime)


/// @fn _SI32_EPCA_A_read_dtime(SI32_EPCA_A_Type* basePointer)
///
/// @brief
/// Reads DTIME register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_EPCA_A_read_dtime(SI32_EPCA_A_Type* /*basePointer*/);
///
/// @def SI32_EPCA_A_read_dtime(basePointer)
#define SI32_EPCA_A_read_dtime(basePointer) \
(basePointer->DTIME.U32)


/// @fn _SI32_EPCA_A_write_phase_x_delay_time(SI32_EPCA_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Writes the delay time after deasserting the phase-x output.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_EPCA_A_write_phase_x_delay_time(SI32_EPCA_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_EPCA_A_write_phase_x_delay_time(basePointer, value)
#define SI32_EPCA_A_write_phase_x_delay_time(basePointer, value) \
   (basePointer->DTIME.DTIMEX = value)


/// @fn _SI32_EPCA_A_write_phase_y_delay_time(SI32_EPCA_A_Type* basePointer,
///      uwide8_t value)
///
/// @brief
/// Writes the delay time after deasserting the phase-y output.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 8 bits.
///
void
_SI32_EPCA_A_write_phase_y_delay_time(SI32_EPCA_A_Type* /*basePointer*/,
   uwide8_t /*value*/);
///
/// @def SI32_EPCA_A_write_phase_y_delay_time(basePointer, value)
#define SI32_EPCA_A_write_phase_y_delay_time(basePointer, value) \
   (basePointer->DTIME.DTIMEY = value)


/// @fn _SI32_EPCA_A_write_dtarget(SI32_EPCA_A_Type* basePointer,
///      uint32_t dtarget)
///
/// @brief
/// Writes DTARGET register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dtarget
///  Valid range is 32 bits.
///
void
_SI32_EPCA_A_write_dtarget(SI32_EPCA_A_Type* /*basePointer*/,
   uint32_t /*dtarget*/);
///
/// @def SI32_EPCA_A_write_dtarget(basePointer, dtarget)
#define SI32_EPCA_A_write_dtarget(basePointer, dtarget) \
   (basePointer->DTARGET.U32 = dtarget)



#ifdef __cplusplus
}
#endif

#endif // __SI32_EPCA_A_TYPE_H__

//-eof--------------------------------------------------------------------------
