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
/// @file SI32_ENCDEC_A_Type.c
//
// Script: 0.58
// HAL Source: 0.1
// Version: 18

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_ENCDEC_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_initialize(
   SI32_ENCDEC_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_write_control(
   SI32_ENCDEC_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_control
//
// Read from CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ENCDEC_A_read_control(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_enable_input_ready_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_enable_input_ready_interrupt(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_INRDYIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_disable_input_ready_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_disable_input_ready_interrupt(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_INRDYIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_input_ready_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_input_ready_interrupt_enabled(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.INRDYIEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_enable_output_ready_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_enable_output_ready_interrupt(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_ORDYIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_disable_output_ready_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_disable_output_ready_interrupt(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_ORDYIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_output_ready_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_output_ready_interrupt_enabled(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.ORDYIEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_enable_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_enable_error_interrupt(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_ERRIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_disable_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_disable_error_interrupt(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_ERRIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_error_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_error_interrupt_enabled(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.ERRIEN;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_reset_module
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_reset_module(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_RESET_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_manchester_output_size_small
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_manchester_output_size_small(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_MOSIZE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_manchester_output_size_large
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_manchester_output_size_large(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_MOSIZE_LARGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_encode_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_encode_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_EDMD_ENCODE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_decode_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_decode_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_EDMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_manchester_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_manchester_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OPMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_three_out_of_six_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_three_out_of_six_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OPMD_3OUTOF6_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_enter_bypass_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_enter_bypass_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_BEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_exit_bypass_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_exit_bypass_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_BEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_enable_dma_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_enable_dma_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_DMAEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_disable_dma_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_disable_dma_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_DMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_enable_stall_in_debug_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_DBGMD_HALT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_disable_stall_in_debug_mode(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_output_order_no_change
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_output_order_no_change(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_output_order_flip_half_word
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_output_order_flip_half_word(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK;
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OORDER_HALF_WORD_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_output_order_flip_word
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_output_order_flip_word(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK;
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OORDER_WORD_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_output_order_flip_lower_three_bytes
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_output_order_flip_lower_three_bytes(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_OORDER_MASK;
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_OORDER_LOWER_THREE_BYTES_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_input_order_no_change
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_input_order_no_change(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_input_order_flip_half_word
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_input_order_flip_half_word(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK;
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_IORDER_HALF_WORD_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_input_order_flip_word
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_input_order_flip_word(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK;
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_IORDER_WORD_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_select_input_order_flip_lower_three_bytes
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_select_input_order_flip_lower_three_bytes(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_ENCDEC_A_CONTROL_IORDER_MASK;
   basePointer->CONTROL_SET = SI32_ENCDEC_A_CONTROL_IORDER_LOWER_THREE_BYTES_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_write_status
//
// Write to STATUS register.
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_write_status(
   SI32_ENCDEC_A_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_status
//
// Reads from STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ENCDEC_A_read_status(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_input_ready_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_input_ready_interrupt_pending(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.INRDYI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_output_ready_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_output_ready_interrupt_pending(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.ORDYI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_error_interrupt_flag_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_error_interrupt_flag_pending(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.DERRI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_clear_error_interrupt_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_clear_error_interrupt_flag(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.DERRI = SI32_ENCDEC_A_STATUS_DERRI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_data_underrun_flag_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_data_underrun_flag_pending(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.DURI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_clear_data_underrun_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_clear_data_underrun_flag(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.DURI = SI32_ENCDEC_A_STATUS_DURI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_is_data_overrun_flag_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_ENCDEC_A_is_data_overrun_flag_pending(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.DORI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_clear_data_overrun_flag
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_clear_data_overrun_flag(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS.DORI = SI32_ENCDEC_A_STATUS_DORI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_write_datain_u32
//
// Write to DATAIN register.
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_write_datain_u32(
   SI32_ENCDEC_A_Type * basePointer,
   uint32_t datain)
{
   //{{
   basePointer->DATAIN.U32 = datain;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_write_datain_u16
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_write_datain_u16(
   SI32_ENCDEC_A_Type * basePointer,
   uwide16_t datain)
{
   assert(datain < 65536);   // datain < 2^16
   //{{
   basePointer->DATAIN.U16 = datain;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_write_datain_u8
//
//-----------------------------------------------------------------------------
void
_SI32_ENCDEC_A_write_datain_u8(
   SI32_ENCDEC_A_Type * basePointer,
   uwide8_t datain)
{
   assert(datain < 256);   // datain < 2^8
   //{{
   basePointer->DATAIN.U8 = datain;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_dataout_u32
//
// Reads from DATAOUT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ENCDEC_A_read_dataout_u32(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->DATAOUT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_dataout_u16
//
//-----------------------------------------------------------------------------
uint16_t
_SI32_ENCDEC_A_read_dataout_u16(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->DATAOUT.U16;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_dataout_u8
//
//-----------------------------------------------------------------------------
uint8_t
_SI32_ENCDEC_A_read_dataout_u8(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->DATAOUT.U8;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_dataoutc_u32
//
// Reads from DATAOUTC register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_ENCDEC_A_read_dataoutc_u32(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->DATAOUTC.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_dataoutc_u16
//
//-----------------------------------------------------------------------------
uint16_t
_SI32_ENCDEC_A_read_dataoutc_u16(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->DATAOUTC.U16;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_ENCDEC_A_read_dataoutc_u8
//
//-----------------------------------------------------------------------------
uint8_t
_SI32_ENCDEC_A_read_dataoutc_u8(
   SI32_ENCDEC_A_Type * basePointer)
{
   //{{
   return basePointer->DATAOUTC.U8;
   //}}
}


//-eof--------------------------------------------------------------------------
