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
/// @file SI32_ENCDEC_A_Type.h
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_ENCDEC_A_TYPE_H__
#define __SI32_ENCDEC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_ENCDEC_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_ENCDEC_A_initialize(SI32_ENCDEC_A_Type* basePointer,
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
_SI32_ENCDEC_A_initialize(SI32_ENCDEC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_ENCDEC_A_initialize(basePointer, control)
#define SI32_ENCDEC_A_initialize(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_ENCDEC_A_write_control(SI32_ENCDEC_A_Type* basePointer,
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
_SI32_ENCDEC_A_write_control(SI32_ENCDEC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_ENCDEC_A_write_control(basePointer, control)
#define SI32_ENCDEC_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_ENCDEC_A_read_control(SI32_ENCDEC_A_Type* basePointer)
///
/// @brief
/// Read from CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ENCDEC_A_read_control(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_control(basePointer)
#define SI32_ENCDEC_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_ENCDEC_A_enable_input_ready_interrupt(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_enable_input_ready_interrupt(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_enable_input_ready_interrupt(basePointer)
#define SI32_ENCDEC_A_enable_input_ready_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_INRDYIEN_ENABLED_U32)


/// @fn _SI32_ENCDEC_A_disable_input_ready_interrupt(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_disable_input_ready_interrupt(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_disable_input_ready_interrupt(basePointer)
#define SI32_ENCDEC_A_disable_input_ready_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_INRDYIEN_MASK)


/// @fn _SI32_ENCDEC_A_is_input_ready_interrupt_enabled(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_input_ready_interrupt_enabled(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_input_ready_interrupt_enabled(basePointer)
#define SI32_ENCDEC_A_is_input_ready_interrupt_enabled(basePointer) \
(basePointer->CONTROL.INRDYIEN)


/// @fn _SI32_ENCDEC_A_enable_output_ready_interrupt(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_enable_output_ready_interrupt(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_enable_output_ready_interrupt(basePointer)
#define SI32_ENCDEC_A_enable_output_ready_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_ORDYIEN_ENABLED_U32)


/// @fn _SI32_ENCDEC_A_disable_output_ready_interrupt(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_disable_output_ready_interrupt(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_disable_output_ready_interrupt(basePointer)
#define SI32_ENCDEC_A_disable_output_ready_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_ORDYIEN_MASK)


/// @fn _SI32_ENCDEC_A_is_output_ready_interrupt_enabled(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_output_ready_interrupt_enabled(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_output_ready_interrupt_enabled(basePointer)
#define SI32_ENCDEC_A_is_output_ready_interrupt_enabled(basePointer) \
(basePointer->CONTROL.ORDYIEN)


/// @fn _SI32_ENCDEC_A_enable_error_interrupt(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_enable_error_interrupt(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_enable_error_interrupt(basePointer)
#define SI32_ENCDEC_A_enable_error_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_ERRIEN_ENABLED_U32)


/// @fn _SI32_ENCDEC_A_disable_error_interrupt(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_disable_error_interrupt(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_disable_error_interrupt(basePointer)
#define SI32_ENCDEC_A_disable_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_ERRIEN_MASK)


/// @fn _SI32_ENCDEC_A_is_error_interrupt_enabled(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_error_interrupt_enabled(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_error_interrupt_enabled(basePointer)
#define SI32_ENCDEC_A_is_error_interrupt_enabled(basePointer) \
(basePointer->CONTROL.ERRIEN)


/// @fn _SI32_ENCDEC_A_reset_module(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_reset_module(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_reset_module(basePointer)
#define SI32_ENCDEC_A_reset_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_RESET_ACTIVE_U32)


/// @fn _SI32_ENCDEC_A_select_manchester_output_size_small(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_manchester_output_size_small(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_manchester_output_size_small(basePointer)
#define SI32_ENCDEC_A_select_manchester_output_size_small(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_MOSIZE_MASK)


/// @fn _SI32_ENCDEC_A_select_manchester_output_size_large(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_manchester_output_size_large(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_manchester_output_size_large(basePointer)
#define SI32_ENCDEC_A_select_manchester_output_size_large(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_MOSIZE_LARGE_U32)


/// @fn _SI32_ENCDEC_A_select_encode_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_encode_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_encode_mode(basePointer)
#define SI32_ENCDEC_A_select_encode_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_EDMD_ENCODE_U32)


/// @fn _SI32_ENCDEC_A_select_decode_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_decode_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_decode_mode(basePointer)
#define SI32_ENCDEC_A_select_decode_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_EDMD_MASK)


/// @fn _SI32_ENCDEC_A_select_manchester_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_manchester_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_manchester_mode(basePointer)
#define SI32_ENCDEC_A_select_manchester_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OPMD_MASK)


/// @fn _SI32_ENCDEC_A_select_three_out_of_six_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_three_out_of_six_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_three_out_of_six_mode(basePointer)
#define SI32_ENCDEC_A_select_three_out_of_six_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OPMD_3OUTOF6_U32)


/// @fn _SI32_ENCDEC_A_enter_bypass_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_enter_bypass_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_enter_bypass_mode(basePointer)
#define SI32_ENCDEC_A_enter_bypass_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_BEN_ENABLED_U32)


/// @fn _SI32_ENCDEC_A_exit_bypass_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_exit_bypass_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_exit_bypass_mode(basePointer)
#define SI32_ENCDEC_A_exit_bypass_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_BEN_MASK)


/// @fn _SI32_ENCDEC_A_enable_dma_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_enable_dma_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_enable_dma_mode(basePointer)
#define SI32_ENCDEC_A_enable_dma_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_DMAEN_ENABLED_U32)


/// @fn _SI32_ENCDEC_A_disable_dma_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_disable_dma_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_disable_dma_mode(basePointer)
#define SI32_ENCDEC_A_disable_dma_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_DMAEN_MASK)


/// @fn _SI32_ENCDEC_A_enable_stall_in_debug_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_enable_stall_in_debug_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_enable_stall_in_debug_mode(basePointer)
#define SI32_ENCDEC_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_DBGMD_HALT_U32)


/// @fn _SI32_ENCDEC_A_disable_stall_in_debug_mode(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_disable_stall_in_debug_mode(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_disable_stall_in_debug_mode(basePointer)
#define SI32_ENCDEC_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_ENCDEC_A_select_output_order_no_change(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_output_order_no_change(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_output_order_no_change(basePointer)
#define SI32_ENCDEC_A_select_output_order_no_change(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK)


/// @fn _SI32_ENCDEC_A_select_output_order_flip_half_word(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_output_order_flip_half_word(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_output_order_flip_half_word(basePointer)
#define SI32_ENCDEC_A_select_output_order_flip_half_word(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK;\
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OORDER_HALF_WORD_U32;\
} while(0)


/// @fn _SI32_ENCDEC_A_select_output_order_flip_word(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_output_order_flip_word(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_output_order_flip_word(basePointer)
#define SI32_ENCDEC_A_select_output_order_flip_word(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK;\
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OORDER_WORD_U32;\
} while(0)


/// @fn _SI32_ENCDEC_A_select_output_order_flip_lower_three_bytes(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_output_order_flip_lower_three_bytes(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_output_order_flip_lower_three_bytes(basePointer)
#define SI32_ENCDEC_A_select_output_order_flip_lower_three_bytes(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK;\
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OORDER_LOWER_THREE_BYTES_U32;\
} while(0)


/// @fn _SI32_ENCDEC_A_select_input_order_no_change(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_input_order_no_change(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_input_order_no_change(basePointer)
#define SI32_ENCDEC_A_select_input_order_no_change(basePointer) \
   (basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK)


/// @fn _SI32_ENCDEC_A_select_input_order_flip_half_word(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_input_order_flip_half_word(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_input_order_flip_half_word(basePointer)
#define SI32_ENCDEC_A_select_input_order_flip_half_word(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK;\
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_IORDER_HALF_WORD_U32;\
} while(0)


/// @fn _SI32_ENCDEC_A_select_input_order_flip_word(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_input_order_flip_word(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_input_order_flip_word(basePointer)
#define SI32_ENCDEC_A_select_input_order_flip_word(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK;\
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_IORDER_WORD_U32;\
} while(0)


/// @fn _SI32_ENCDEC_A_select_input_order_flip_lower_three_bytes(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_select_input_order_flip_lower_three_bytes(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_select_input_order_flip_lower_three_bytes(basePointer)
#define SI32_ENCDEC_A_select_input_order_flip_lower_three_bytes(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK;\
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_IORDER_LOWER_THREE_BYTES_U32;\
} while(0)


/// @fn _SI32_ENCDEC_A_write_status(SI32_ENCDEC_A_Type* basePointer,
///      uint32_t status)
///
/// @brief
/// Write to STATUS register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_ENCDEC_A_write_status(SI32_ENCDEC_A_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_ENCDEC_A_write_status(basePointer, status)
#define SI32_ENCDEC_A_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_ENCDEC_A_read_status(SI32_ENCDEC_A_Type* basePointer)
///
/// @brief
/// Reads from STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ENCDEC_A_read_status(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_status(basePointer)
#define SI32_ENCDEC_A_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_ENCDEC_A_is_input_ready_interrupt_pending(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_input_ready_interrupt_pending(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_input_ready_interrupt_pending(basePointer)
#define SI32_ENCDEC_A_is_input_ready_interrupt_pending(basePointer) \
(basePointer->STATUS.INRDYI)


/// @fn _SI32_ENCDEC_A_is_output_ready_interrupt_pending(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_output_ready_interrupt_pending(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_output_ready_interrupt_pending(basePointer)
#define SI32_ENCDEC_A_is_output_ready_interrupt_pending(basePointer) \
(basePointer->STATUS.ORDYI)


/// @fn _SI32_ENCDEC_A_is_error_interrupt_flag_pending(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_error_interrupt_flag_pending(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_error_interrupt_flag_pending(basePointer)
#define SI32_ENCDEC_A_is_error_interrupt_flag_pending(basePointer) \
(basePointer->STATUS.DERRI)


/// @fn _SI32_ENCDEC_A_clear_error_interrupt_flag(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_clear_error_interrupt_flag(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_clear_error_interrupt_flag(basePointer)
#define SI32_ENCDEC_A_clear_error_interrupt_flag(basePointer) \
   (basePointer->STATUS.DERRI = SI32_ENCDEC_A_STATUS_DERRI_NOT_SET_VALUE)


/// @fn _SI32_ENCDEC_A_is_data_underrun_flag_pending(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_data_underrun_flag_pending(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_data_underrun_flag_pending(basePointer)
#define SI32_ENCDEC_A_is_data_underrun_flag_pending(basePointer) \
(basePointer->STATUS.DURI)


/// @fn _SI32_ENCDEC_A_clear_data_underrun_flag(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_clear_data_underrun_flag(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_clear_data_underrun_flag(basePointer)
#define SI32_ENCDEC_A_clear_data_underrun_flag(basePointer) \
   (basePointer->STATUS.DURI = SI32_ENCDEC_A_STATUS_DURI_NOT_SET_VALUE)


/// @fn _SI32_ENCDEC_A_is_data_overrun_flag_pending(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_ENCDEC_A_is_data_overrun_flag_pending(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_is_data_overrun_flag_pending(basePointer)
#define SI32_ENCDEC_A_is_data_overrun_flag_pending(basePointer) \
(basePointer->STATUS.DORI)


/// @fn _SI32_ENCDEC_A_clear_data_overrun_flag(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_ENCDEC_A_clear_data_overrun_flag(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_clear_data_overrun_flag(basePointer)
#define SI32_ENCDEC_A_clear_data_overrun_flag(basePointer) \
   (basePointer->STATUS.DORI = SI32_ENCDEC_A_STATUS_DORI_NOT_SET_VALUE)


/// @fn _SI32_ENCDEC_A_write_datain_u32(SI32_ENCDEC_A_Type* basePointer,
///      uint32_t datain)
///
/// @brief
/// Write to DATAIN register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  datain
///  Valid range is 32 bits.
///
void
_SI32_ENCDEC_A_write_datain_u32(SI32_ENCDEC_A_Type* /*basePointer*/,
   uint32_t /*datain*/);
///
/// @def SI32_ENCDEC_A_write_datain_u32(basePointer, datain)
#define SI32_ENCDEC_A_write_datain_u32(basePointer, datain) \
   (basePointer->DATAIN.U32 = datain)


/// @fn _SI32_ENCDEC_A_write_datain_u16(SI32_ENCDEC_A_Type* basePointer,
///      uwide16_t datain)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  datain
///  Valid range is 16 bits.
///
void
_SI32_ENCDEC_A_write_datain_u16(SI32_ENCDEC_A_Type* /*basePointer*/,
   uwide16_t /*datain*/);
///
/// @def SI32_ENCDEC_A_write_datain_u16(basePointer, datain)
#define SI32_ENCDEC_A_write_datain_u16(basePointer, datain) \
   (basePointer->DATAIN.U16 = datain)


/// @fn _SI32_ENCDEC_A_write_datain_u8(SI32_ENCDEC_A_Type* basePointer,
///      uwide8_t datain)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  datain
///  Valid range is 8 bits.
///
void
_SI32_ENCDEC_A_write_datain_u8(SI32_ENCDEC_A_Type* /*basePointer*/,
   uwide8_t /*datain*/);
///
/// @def SI32_ENCDEC_A_write_datain_u8(basePointer, datain)
#define SI32_ENCDEC_A_write_datain_u8(basePointer, datain) \
   (basePointer->DATAIN.U8 = datain)


/// @fn _SI32_ENCDEC_A_read_dataout_u32(SI32_ENCDEC_A_Type* basePointer)
///
/// @brief
/// Reads from DATAOUT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ENCDEC_A_read_dataout_u32(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_dataout_u32(basePointer)
#define SI32_ENCDEC_A_read_dataout_u32(basePointer) \
(basePointer->DATAOUT.U32)


/// @fn _SI32_ENCDEC_A_read_dataout_u16(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint16_t
_SI32_ENCDEC_A_read_dataout_u16(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_dataout_u16(basePointer)
#define SI32_ENCDEC_A_read_dataout_u16(basePointer) \
(basePointer->DATAOUT.U16)


/// @fn _SI32_ENCDEC_A_read_dataout_u8(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint8_t
_SI32_ENCDEC_A_read_dataout_u8(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_dataout_u8(basePointer)
#define SI32_ENCDEC_A_read_dataout_u8(basePointer) \
(basePointer->DATAOUT.U8)


/// @fn _SI32_ENCDEC_A_read_dataoutc_u32(SI32_ENCDEC_A_Type* basePointer)
///
/// @brief
/// Reads from DATAOUTC register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_ENCDEC_A_read_dataoutc_u32(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_dataoutc_u32(basePointer)
#define SI32_ENCDEC_A_read_dataoutc_u32(basePointer) \
(basePointer->DATAOUTC.U32)


/// @fn _SI32_ENCDEC_A_read_dataoutc_u16(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint16_t
_SI32_ENCDEC_A_read_dataoutc_u16(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_dataoutc_u16(basePointer)
#define SI32_ENCDEC_A_read_dataoutc_u16(basePointer) \
(basePointer->DATAOUTC.U16)


/// @fn _SI32_ENCDEC_A_read_dataoutc_u8(SI32_ENCDEC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint8_t
_SI32_ENCDEC_A_read_dataoutc_u8(SI32_ENCDEC_A_Type* /*basePointer*/);
///
/// @def SI32_ENCDEC_A_read_dataoutc_u8(basePointer)
#define SI32_ENCDEC_A_read_dataoutc_u8(basePointer) \
(basePointer->DATAOUTC.U8)



#ifdef __cplusplus
}
#endif

#endif // __SI32_ENCDEC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
