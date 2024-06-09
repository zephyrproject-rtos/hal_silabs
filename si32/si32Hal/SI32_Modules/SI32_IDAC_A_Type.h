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
/// @file SI32_IDAC_A_Type.h
//
// Script: 0.58
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_IDAC_A_TYPE_H__
#define __SI32_IDAC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_IDAC_A_Registers.h"

// support definitions
#include "SI32_IDAC_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_IDAC_A_initialize(SI32_IDAC_A_Type* basePointer,
///      uint32_t control)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to the CONTROL register.
///
void
_SI32_IDAC_A_initialize(SI32_IDAC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_IDAC_A_initialize(basePointer, control)
#define SI32_IDAC_A_initialize(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_IDAC_A_write_control(SI32_IDAC_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Write to the CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_IDAC_A_write_control(SI32_IDAC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_IDAC_A_write_control(basePointer, control)
#define SI32_IDAC_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_IDAC_A_read_control(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  Read CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_control(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_control(basePointer)
#define SI32_IDAC_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_IDAC_A_set_output_update_trigger(SI32_IDAC_A_Type* basePointer,
///      SI32_IDAC_A_OUTPUT_UPDATE_TRIGGER_Enum_Type trigger)
///
/// @brief
/// Select the IDAC output update trigger.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  trigger
///  Valid range is 3 bits.
///  IDAC output update trigger source - 0 to 7; see IDAC under Peripheral
///  Interface Description on datasheet for options.
///
void
_SI32_IDAC_A_set_output_update_trigger(SI32_IDAC_A_Type* /*basePointer*/,
   SI32_IDAC_A_OUTPUT_UPDATE_TRIGGER_Enum_Type /*trigger*/);
///
/// @def SI32_IDAC_A_set_output_update_trigger(basePointer, trigger)
#define SI32_IDAC_A_set_output_update_trigger(basePointer, trigger) do{  \
   basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_OUPDT_MASK;\
   basePointer->CONTROL_SET = trigger;\
} while(0)


/// @fn _SI32_IDAC_A_set_external_trigger_channel(SI32_IDAC_A_Type* basePointer,
///      uint32_t trigger_src)
///
/// @brief
/// Sets the external tigger source channel if the output update trigger
/// is set to use an external trigger.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  trigger_src
///  Valid range is 3 bits.
///  DACnTn external trigger source number  - 0 to 7; see IDAC under
///  Peripheral Interface Description on datasheet for options.
///
void
_SI32_IDAC_A_set_external_trigger_channel(SI32_IDAC_A_Type* /*basePointer*/,
   uint32_t /*trigger_src*/);
///
/// @def SI32_IDAC_A_set_external_trigger_channel(basePointer, trigger_src)
#define SI32_IDAC_A_set_external_trigger_channel(basePointer, trigger_src) do{  \
   basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_ETRIG_MASK;\
   basePointer->CONTROL_SET = trigger_src << SI32_IDAC_A_CONTROL_ETRIG_SHIFT;\
} while(0)


/// @fn _SI32_IDAC_A_select_output_fullscale_2ma(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Set full-scale output current to 2mA.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_output_fullscale_2ma(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_output_fullscale_2ma(basePointer)
#define SI32_IDAC_A_select_output_fullscale_2ma(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_OUTMD_MASK;\
   basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_OUTMD_2_MA_U32;\
} while(0)


/// @fn _SI32_IDAC_A_select_output_fullscale_1ma(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Set full-scale output current to 1mA.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_output_fullscale_1ma(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_output_fullscale_1ma(basePointer)
#define SI32_IDAC_A_select_output_fullscale_1ma(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_OUTMD_MASK;\
   basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_OUTMD_1_MA_U32;\
} while(0)


/// @fn _SI32_IDAC_A_select_output_fullscale_0p5ma(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Set full-scale output current to 0.5mA.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_output_fullscale_0p5ma(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_output_fullscale_0p5ma(basePointer)
#define SI32_IDAC_A_select_output_fullscale_0p5ma(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_OUTMD_MASK)


/// @fn _SI32_IDAC_A_select_2x10bit_input_format(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Set input format to four 8-bit words / 32-bit write.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_2x10bit_input_format(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_2x10bit_input_format(basePointer)
#define SI32_IDAC_A_select_2x10bit_input_format(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_INFMT_MASK;\
   basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_INFMT_2_10_BIT_U32;\
} while(0)


/// @fn _SI32_IDAC_A_select_1x10bit_input_format(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Set input format to two 10-bit words / 32-bit write.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_1x10bit_input_format(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_1x10bit_input_format(basePointer)
#define SI32_IDAC_A_select_1x10bit_input_format(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_INFMT_MASK)


/// @fn _SI32_IDAC_A_select_4x8bit_input_format(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Set input format to one 10-bit word / 32-bit write.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_4x8bit_input_format(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_4x8bit_input_format(basePointer)
#define SI32_IDAC_A_select_4x8bit_input_format(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_INFMT_MASK;\
   basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_INFMT_4_8_BIT_U32;\
} while(0)


/// @fn _SI32_IDAC_A_start_dma_operation(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_start_dma_operation(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_start_dma_operation(basePointer)
#define SI32_IDAC_A_start_dma_operation(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_DMARUN_MASK)


/// @fn _SI32_IDAC_A_is_dma_operation_in_progress(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  True = running, False = done.
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_dma_operation_in_progress(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_dma_operation_in_progress(basePointer)
#define SI32_IDAC_A_is_dma_operation_in_progress(basePointer) \
((bool)(basePointer->CONTROL.DMARUN))


/// @fn _SI32_IDAC_A_select_left_justification(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// 10-bit Data will be left-justified.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_left_justification(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_left_justification(basePointer)
#define SI32_IDAC_A_select_left_justification(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_JSEL_MASK)


/// @fn _SI32_IDAC_A_select_right_justification(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// 10-bit Data will be right-justified.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_select_right_justification(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_select_right_justification(basePointer)
#define SI32_IDAC_A_select_right_justification(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_JSEL_MASK)


/// @fn _SI32_IDAC_A_reset_buffer(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Flush data buffer, buffer level reset to zero.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_reset_buffer(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_reset_buffer(basePointer)
#define SI32_IDAC_A_reset_buffer(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_BUFRESET_MASK)


/// @fn _SI32_IDAC_A_enable_trigger(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Trigger source will update output.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_trigger(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_trigger(basePointer)
#define SI32_IDAC_A_enable_trigger(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_TRIGINH_MASK)


/// @fn _SI32_IDAC_A_disable_trigger(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Trigger source will not update output (except On-Demand mode).
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_trigger(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_trigger(basePointer)
#define SI32_IDAC_A_disable_trigger(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_TRIGINH_MASK)


/// @fn _SI32_IDAC_A_enable_buffer_wrap(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Buffer will automatically wrap around.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_buffer_wrap(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_buffer_wrap(basePointer)
#define SI32_IDAC_A_enable_buffer_wrap(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_WRAPEN_MASK)


/// @fn _SI32_IDAC_A_disable_buffer_wrap(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Buffer will not wrap around.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_buffer_wrap(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_buffer_wrap(basePointer)
#define SI32_IDAC_A_disable_buffer_wrap(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_WRAPEN_MASK)


/// @fn _SI32_IDAC_A_enable_buffer_overrun_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_buffer_overrun_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_buffer_overrun_interrupt(basePointer)
#define SI32_IDAC_A_enable_buffer_overrun_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_ORIEN_MASK)


/// @fn _SI32_IDAC_A_disable_buffer_overrun_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_buffer_overrun_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_buffer_overrun_interrupt(basePointer)
#define SI32_IDAC_A_disable_buffer_overrun_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_ORIEN_MASK)


/// @fn _SI32_IDAC_A_is_buffer_overrun_interrupt_enabled(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_buffer_overrun_interrupt_enabled(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_buffer_overrun_interrupt_enabled(basePointer)
#define SI32_IDAC_A_is_buffer_overrun_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.ORIEN))


/// @fn _SI32_IDAC_A_enable_buffer_underrun_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_buffer_underrun_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_buffer_underrun_interrupt(basePointer)
#define SI32_IDAC_A_enable_buffer_underrun_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_URIEN_MASK)


/// @fn _SI32_IDAC_A_disable_buffer_underrun_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_buffer_underrun_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_buffer_underrun_interrupt(basePointer)
#define SI32_IDAC_A_disable_buffer_underrun_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_URIEN_MASK)


/// @fn _SI32_IDAC_A_is_buffer_underrun_interrupt_enabled(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_buffer_underrun_interrupt_enabled(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_buffer_underrun_interrupt_enabled(basePointer)
#define SI32_IDAC_A_is_buffer_underrun_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.URIEN))


/// @fn _SI32_IDAC_A_enable_buffer_went_empty_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_buffer_went_empty_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_buffer_went_empty_interrupt(basePointer)
#define SI32_IDAC_A_enable_buffer_went_empty_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_WEIEN_MASK)


/// @fn _SI32_IDAC_A_disable_buffer_went_empty_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_buffer_went_empty_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_buffer_went_empty_interrupt(basePointer)
#define SI32_IDAC_A_disable_buffer_went_empty_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_WEIEN_MASK)


/// @fn _SI32_IDAC_A_is_buffer_went_empty_interrupt_enabled(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_buffer_went_empty_interrupt_enabled(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_buffer_went_empty_interrupt_enabled(basePointer)
#define SI32_IDAC_A_is_buffer_went_empty_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.WEIEN))


/// @fn _SI32_IDAC_A_enable_stall_in_debug_mode(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_stall_in_debug_mode(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_stall_in_debug_mode(basePointer)
#define SI32_IDAC_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_IDAC_A_disable_stall_in_debug_mode(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_stall_in_debug_mode(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_stall_in_debug_mode(basePointer)
#define SI32_IDAC_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_IDAC_A_enable_load_resistor(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Connect internal load resistor.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_load_resistor(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_load_resistor(basePointer)
#define SI32_IDAC_A_enable_load_resistor(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_LOADEN_MASK)


/// @fn _SI32_IDAC_A_disable_load_resistor(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Disconnect internal load resistor.
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_load_resistor(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_load_resistor(basePointer)
#define SI32_IDAC_A_disable_load_resistor(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_LOADEN_MASK)


/// @fn _SI32_IDAC_A_enable_module(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_enable_module(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_enable_module(basePointer)
#define SI32_IDAC_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_IDAC_A_CONTROL_IDACEN_MASK)


/// @fn _SI32_IDAC_A_disable_module(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_disable_module(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_disable_module(basePointer)
#define SI32_IDAC_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_IDAC_A_CONTROL_IDACEN_MASK)


/// @fn _SI32_IDAC_A_write_data(SI32_IDAC_A_Type* basePointer,
///      uint32_t data_in)
///
/// @brief
/// Write data to latch (On-Demand mode) or to buffer (all other trigger
/// sources).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data_in
///  Valid range is 32 bits.
///  Data, formatted per INFMT bits.
///
void
_SI32_IDAC_A_write_data(SI32_IDAC_A_Type* /*basePointer*/,
   uint32_t /*data_in*/);
///
/// @def SI32_IDAC_A_write_data(basePointer, data_in)
#define SI32_IDAC_A_write_data(basePointer, data_in) \
   (basePointer->DATA.U32 = data_in)


/// @fn _SI32_IDAC_A_read_data(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  Read current output value in the IDAC latch.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_data(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_data(basePointer)
#define SI32_IDAC_A_read_data(basePointer) \
(basePointer->DATA.U32)


/// @fn _SI32_IDAC_A_write_bufstatus(SI32_IDAC_A_Type* basePointer,
///      uint32_t bufstatus)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  bufstatus
///  Valid range is 32 bits.
///  Write to BUFSTATUS register.
///
void
_SI32_IDAC_A_write_bufstatus(SI32_IDAC_A_Type* /*basePointer*/,
   uint32_t /*bufstatus*/);
///
/// @def SI32_IDAC_A_write_bufstatus(basePointer, bufstatus)
#define SI32_IDAC_A_write_bufstatus(basePointer, bufstatus) \
   (basePointer->BUFSTATUS.U32 = bufstatus)


/// @fn _SI32_IDAC_A_read_bufstatus(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  Read BUFSTATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_bufstatus(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_bufstatus(basePointer)
#define SI32_IDAC_A_read_bufstatus(basePointer) \
(basePointer->BUFSTATUS.U32)


/// @fn _SI32_IDAC_A_read_buffer_level(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Returns the number of words in the buffer.
///
/// @return
///  Number of words in buffer.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_buffer_level(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_buffer_level(basePointer)
#define SI32_IDAC_A_read_buffer_level(basePointer) \
(basePointer->BUFSTATUS.LEVEL)


/// @fn _SI32_IDAC_A_is_buffer_overrun_interrupt_pending(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  True = Yes, False = No.
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_buffer_overrun_interrupt_pending(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_buffer_overrun_interrupt_pending(basePointer)
#define SI32_IDAC_A_is_buffer_overrun_interrupt_pending(basePointer) \
((bool)(basePointer->BUFSTATUS.ORI))


/// @fn _SI32_IDAC_A_clear_buffer_overrun_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_clear_buffer_overrun_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_clear_buffer_overrun_interrupt(basePointer)
#define SI32_IDAC_A_clear_buffer_overrun_interrupt(basePointer) \
   (basePointer->BUFSTATUS_CLR = SI32_IDAC_A_BUFSTATUS_ORI_MASK)


/// @fn _SI32_IDAC_A_is_buffer_underrun_interrupt_pending(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  True = Yes, False = No.
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_buffer_underrun_interrupt_pending(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_buffer_underrun_interrupt_pending(basePointer)
#define SI32_IDAC_A_is_buffer_underrun_interrupt_pending(basePointer) \
((bool)(basePointer->BUFSTATUS.URI))


/// @fn _SI32_IDAC_A_clear_buffer_underrun_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_clear_buffer_underrun_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_clear_buffer_underrun_interrupt(basePointer)
#define SI32_IDAC_A_clear_buffer_underrun_interrupt(basePointer) \
   (basePointer->BUFSTATUS_CLR = SI32_IDAC_A_BUFSTATUS_URI_MASK)


/// @fn _SI32_IDAC_A_is_buffer_went_empty_interrupt_pending(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  True = Yes, False = No.
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_buffer_went_empty_interrupt_pending(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_buffer_went_empty_interrupt_pending(basePointer)
#define SI32_IDAC_A_is_buffer_went_empty_interrupt_pending(basePointer) \
((bool)(basePointer->BUFSTATUS.WEI))


/// @fn _SI32_IDAC_A_clear_buffer_went_empty_interrupt(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_clear_buffer_went_empty_interrupt(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_clear_buffer_went_empty_interrupt(basePointer)
#define SI32_IDAC_A_clear_buffer_went_empty_interrupt(basePointer) \
   (basePointer->BUFSTATUS_CLR = SI32_IDAC_A_BUFSTATUS_WEI_MASK)


/// @fn _SI32_IDAC_A_is_any_interrupt_pending(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  True = Yes, False = No.
///
/// @param[in]
///  basePointer
///
bool
_SI32_IDAC_A_is_any_interrupt_pending(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_is_any_interrupt_pending(basePointer)
#define SI32_IDAC_A_is_any_interrupt_pending(basePointer) \
   _SI32_IDAC_A_is_any_interrupt_pending(basePointer)


/// @fn _SI32_IDAC_A_clear_all_interrupts(SI32_IDAC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_IDAC_A_clear_all_interrupts(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_clear_all_interrupts(basePointer)
#define SI32_IDAC_A_clear_all_interrupts(basePointer) do{  \
   basePointer->BUFSTATUS_CLR =\
        (SI32_IDAC_A_BUFSTATUS_ORI_MASK\
	     | SI32_IDAC_A_BUFSTATUS_URI_MASK\
         | SI32_IDAC_A_BUFSTATUS_WEI_MASK);\
} while(0)


/// @fn _SI32_IDAC_A_read_buffer_entry_0(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Read first pending IDAC ouput value.
///
/// @return
///  Slot 0 value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_buffer_entry_0(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_buffer_entry_0(basePointer)
#define SI32_IDAC_A_read_buffer_entry_0(basePointer) \
(basePointer->BUFFER10.BUFFER0)


/// @fn _SI32_IDAC_A_read_buffer_entry_1(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Read second pending IDAC ouput value.
///
/// @return
///  Slot 1 value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_buffer_entry_1(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_buffer_entry_1(basePointer)
#define SI32_IDAC_A_read_buffer_entry_1(basePointer) \
(basePointer->BUFFER10.BUFFER1)


/// @fn _SI32_IDAC_A_read_buffer_entry_2(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Read third pending IDAC ouput value.
///
/// @return
///  Slot 2 value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_buffer_entry_2(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_buffer_entry_2(basePointer)
#define SI32_IDAC_A_read_buffer_entry_2(basePointer) \
(basePointer->BUFFER32.BUFFER2)


/// @fn _SI32_IDAC_A_read_buffer_entry_3(SI32_IDAC_A_Type* basePointer)
///
/// @brief
/// Read fourth pending IDAC ouput value.
///
/// @return
///  Slot 3 value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_buffer_entry_3(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_buffer_entry_3(basePointer)
#define SI32_IDAC_A_read_buffer_entry_3(basePointer) \
(basePointer->BUFFER32.BUFFER3)


/// @fn _SI32_IDAC_A_write_gainadj(SI32_IDAC_A_Type* basePointer,
///      uint32_t gainadj)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  gainadj
///  Valid range is 32 bits.
///  Write to GAINADJ register.
///
void
_SI32_IDAC_A_write_gainadj(SI32_IDAC_A_Type* /*basePointer*/,
   uint32_t /*gainadj*/);
///
/// @def SI32_IDAC_A_write_gainadj(basePointer, gainadj)
#define SI32_IDAC_A_write_gainadj(basePointer, gainadj) \
   (basePointer->GAINADJ.U32 = gainadj)


/// @fn _SI32_IDAC_A_read_gainadj(SI32_IDAC_A_Type* basePointer)
///
/// @return
///  Read GAINADJ register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_IDAC_A_read_gainadj(SI32_IDAC_A_Type* /*basePointer*/);
///
/// @def SI32_IDAC_A_read_gainadj(basePointer)
#define SI32_IDAC_A_read_gainadj(basePointer) \
(basePointer->GAINADJ.U32)


/// @fn _SI32_IDAC_A_set_output_fullscale_adjust(SI32_IDAC_A_Type* basePointer,
///      uint32_t gainadj)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  gainadj
///  Valid range is 5 bits.
///  Adjust full-scale output current.
///
void
_SI32_IDAC_A_set_output_fullscale_adjust(SI32_IDAC_A_Type* /*basePointer*/,
   uint32_t /*gainadj*/);
///
/// @def SI32_IDAC_A_set_output_fullscale_adjust(basePointer, gainadj)
#define SI32_IDAC_A_set_output_fullscale_adjust(basePointer, gainadj) \
   (basePointer->GAINADJ.GAINADJ_BITS = gainadj)



#ifdef __cplusplus
}
#endif

#endif // __SI32_IDAC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
