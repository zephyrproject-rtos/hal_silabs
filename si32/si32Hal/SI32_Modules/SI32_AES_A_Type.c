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
/// @file SI32_AES_A_Type.c
//
// Script: 0.58
// HAL Source: 0.3
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_AES_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_AES_A_initialize
//
// Writes all AES registers.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_initialize(
   SI32_AES_A_Type * basePointer,
   uint32_t control,
   uint32_t xfrsize,
   uint32_t status)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->XFRSIZE.U32 = xfrsize;
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_control(
   SI32_AES_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_AES_A_read_control(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_start_operation
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_start_operation(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_XFRSTA_START_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enable_key_capture
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enable_key_capture(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_KEYCPEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_disable_key_capture
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_disable_key_capture(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYCPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_encryption_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_encryption_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_EDMD_ENCRYPT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_decryption_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_decryption_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_EDMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_software_mode
//
// Data transfers are not handled by the DMA.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_software_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_SWMDEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_dma_mode
//
// Data transfers are handled by the DMA.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_dma_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_SWMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enter_bypass_hardware_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enter_bypass_hardware_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_BEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_exit_bypass_hardware_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_exit_bypass_hardware_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_BEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_xor_path_none
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_xor_path_none(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_XOREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_xor_path_input
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_xor_path_input(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_XOREN_MASK;
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_XOREN_XOR_INPUT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_xor_path_output
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_xor_path_output(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_XOREN_MASK;
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_XOREN_XOR_OUTPUT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enter_counter_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enter_counter_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_HCTREN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_exit_counter_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_exit_counter_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_HCTREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enter_cipher_block_chaining_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enter_cipher_block_chaining_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_HCBCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_exit_cipher_block_chaining_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_exit_cipher_block_chaining_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_HCBCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_key_size_128
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_key_size_128(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYSIZE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_key_size_192
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_key_size_192(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYSIZE_MASK;
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_KEYSIZE_KEY192_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_select_key_size_256
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_select_key_size_256(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYSIZE_MASK;
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_KEYSIZE_KEY256_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enable_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enable_error_interrupt(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_ERRIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_disable_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_disable_error_interrupt(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_ERRIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_is_error_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_is_error_interrupt_enabled(
   SI32_AES_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.ERRIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enable_operation_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enable_operation_complete_interrupt(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_OCIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_disable_operation_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_disable_operation_complete_interrupt(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_OCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_is_operation_complete_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_is_operation_complete_interrupt_enabled(
   SI32_AES_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.OCIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enable_stall_in_debug_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_disable_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_disable_stall_in_debug_mode(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_DBGMD_RUN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_enable_module(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_RESET_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_disable_module(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_RESET_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_reset_module
//
// Disables, then enables the module.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_reset_module(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_RESET_ACTIVE_U32;
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_RESET_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_xfrsize
//
// Writes XFRSIZE register.  The contents of XFRSIZE plus 1 indicates the
// number of 4-word blocks left to process.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_xfrsize(
   SI32_AES_A_Type * basePointer,
   uint32_t xfrsize)
{
   //{{
   basePointer->XFRSIZE.U32 = xfrsize;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_read_xfrsize
//
// Reads XFRSIZE register.  The contents of XFRSIZE plus 1 indicates the
// number of 4-word blocks left to process.
//-----------------------------------------------------------------------------
uint32_t
_SI32_AES_A_read_xfrsize(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return basePointer->XFRSIZE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_datafifo
//
// Writes DATAFIFO register.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_datafifo(
   SI32_AES_A_Type * basePointer,
   uint32_t data_word)
{
   //{{
   basePointer->DATAFIFO.U32 = data_word;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_read_datafifo
//
// Reads DATAFIFO register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_AES_A_read_datafifo(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return basePointer->DATAFIFO.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_xorfifo
//
// Writes XORFIFO register.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_xorfifo(
   SI32_AES_A_Type * basePointer,
   uint32_t xor_word)
{
   //{{
   basePointer->XORFIFO.U32 = xor_word;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_xorfifo_full
//
// Writes XORFIFO register with 4 words.  Index 0 of the passed struct is
// written first.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_xorfifo_full(
   SI32_AES_A_Type * basePointer,
   SI32_AES_A_Initialization_Vector_Type xor_vector)
{
   //{{
   basePointer->XORFIFO.U32 = xor_vector.iv[0];
   basePointer->XORFIFO.U32 = xor_vector.iv[1];
   basePointer->XORFIFO.U32 = xor_vector.iv[2];
   basePointer->XORFIFO.U32 = xor_vector.iv[3];
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_hardware_key
//
// Writes all HWKEY registers.  The word at index 0 of the passed struct
// is copied into HWKEY0.  If the key size is less than 256 bits, only
// the appropriate number of words is copied to the HWKEY registers.
// Any remaining registers are cleared.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_hardware_key(
   SI32_AES_A_Type * basePointer,
   SI32_AES_A_Hardware_Key_Type key)
{
   //{{
   basePointer->HWKEY0.HWKEY0_BITS = key.hwkey[0];
   basePointer->HWKEY1.HWKEY1_BITS = key.hwkey[1];
   basePointer->HWKEY2.HWKEY2_BITS = key.hwkey[2];
   basePointer->HWKEY3.HWKEY3_BITS = key.hwkey[3];
   if (basePointer->CONTROL.KEYSIZE
       == SI32_AES_A_CONTROL_KEYSIZE_KEY128_VALUE)
   {
      basePointer->HWKEY4.HWKEY4_BITS = 0;
      basePointer->HWKEY5.HWKEY5_BITS = 0;
      basePointer->HWKEY6.HWKEY6_BITS = 0;
      basePointer->HWKEY7.HWKEY7_BITS = 0;
   }
   else if (basePointer->CONTROL.KEYSIZE
            == SI32_AES_A_CONTROL_KEYSIZE_KEY192_VALUE)
   {
      basePointer->HWKEY4.HWKEY4_BITS = key.hwkey[4];
      basePointer->HWKEY5.HWKEY5_BITS = key.hwkey[5];
      basePointer->HWKEY6.HWKEY6_BITS = 0;
      basePointer->HWKEY7.HWKEY7_BITS = 0;
   }
   else if (basePointer->CONTROL.KEYSIZE
            == SI32_AES_A_CONTROL_KEYSIZE_KEY256_VALUE)
   {
      basePointer->HWKEY4.HWKEY4_BITS = key.hwkey[4];
      basePointer->HWKEY5.HWKEY5_BITS = key.hwkey[5];
      basePointer->HWKEY6.HWKEY6_BITS = key.hwkey[6];
      basePointer->HWKEY7.HWKEY7_BITS = key.hwkey[7];
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_read_hardware_key
//
// Reads all HWKEY registers.  The word at index 0 of the returned struct
// is copied from HWKEY0.  If the key size is less than 256 bits, only
// the appropriate number of words is copied to the return value.   Any
// remaining words are cleared.
//-----------------------------------------------------------------------------
SI32_AES_A_Hardware_Key_Type
_SI32_AES_A_read_hardware_key(
   SI32_AES_A_Type * basePointer)
{
   //{{
   SI32_AES_A_Hardware_Key_Type ret;
   ret.hwkey[0] = basePointer->HWKEY0.HWKEY0_BITS;
   ret.hwkey[1] = basePointer->HWKEY1.HWKEY1_BITS;
   ret.hwkey[2] = basePointer->HWKEY2.HWKEY2_BITS;
   ret.hwkey[3] = basePointer->HWKEY3.HWKEY3_BITS;
   if (basePointer->CONTROL.KEYSIZE
       == SI32_AES_A_CONTROL_KEYSIZE_KEY128_VALUE)
   {
      ret.hwkey[4] = 0;
      ret.hwkey[5] = 0;
      ret.hwkey[6] = 0;
      ret.hwkey[7] = 0;
   }
   else if (basePointer->CONTROL.KEYSIZE
            == SI32_AES_A_CONTROL_KEYSIZE_KEY192_VALUE)
   {
      ret.hwkey[4] = basePointer->HWKEY4.HWKEY4_BITS;
      ret.hwkey[5] = basePointer->HWKEY5.HWKEY5_BITS;
      ret.hwkey[6] = 0;
      ret.hwkey[7] = 0;
   }
   else if (basePointer->CONTROL.KEYSIZE
            == SI32_AES_A_CONTROL_KEYSIZE_KEY256_VALUE)
   {
      ret.hwkey[4] = basePointer->HWKEY4.HWKEY4_BITS;
      ret.hwkey[5] = basePointer->HWKEY5.HWKEY5_BITS;
      ret.hwkey[6] = basePointer->HWKEY6.HWKEY6_BITS;
      ret.hwkey[7] = basePointer->HWKEY7.HWKEY7_BITS;
   }
   return ret;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_hardware_counter
//
// Writes all HWCTR registers.  The word at index 0 of the passed struct
// is copied into HWCTR0.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_hardware_counter(
   SI32_AES_A_Type * basePointer,
   SI32_AES_A_Hardware_Counter_Type counter)
{
   //{{
   basePointer->HWCTR0.HWCTR0_BITS = counter.hwctr[0];
   basePointer->HWCTR1.HWCTR1_BITS = counter.hwctr[1];
   basePointer->HWCTR2.HWCTR2_BITS = counter.hwctr[2];
   basePointer->HWCTR3.HWCTR3_BITS = counter.hwctr[3];
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_read_hardware_counter
//
// Reads all HWCTR registers.  The word at index 0 of the returned struct
// is copied from HWCTR0.
//-----------------------------------------------------------------------------
SI32_AES_A_Hardware_Counter_Type
_SI32_AES_A_read_hardware_counter(
   SI32_AES_A_Type * basePointer)
{
   //{{
   SI32_AES_A_Hardware_Counter_Type counter;
   counter.hwctr[0] = basePointer->HWCTR0.HWCTR0_BITS;
   counter.hwctr[1] = basePointer->HWCTR1.HWCTR1_BITS;
   counter.hwctr[2] = basePointer->HWCTR2.HWCTR2_BITS;
   counter.hwctr[3] = basePointer->HWCTR3.HWCTR3_BITS;
   return counter;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_write_status
//
// Writes STATUS register.
//-----------------------------------------------------------------------------
void
_SI32_AES_A_write_status(
   SI32_AES_A_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_read_status
//
// Reads STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_AES_A_read_status(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_has_data_underrun_occurred
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_has_data_underrun_occurred(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.DURF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_has_data_overrun_occurred
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_has_data_overrun_occurred(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.DORF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_has_xor_data_overrun_occurred
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_has_xor_data_overrun_occurred(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.XORF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_get_datafifo_count
//
// Returns the number of words (up to 4) in the internal data FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_AES_A_get_datafifo_count(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.DFIFOLVL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_get_xorfifo_count
//
// Returns the number of words (up to 4) in the internal XOR FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_AES_A_get_xorfifo_count(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.XFIFOLVL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_is_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_is_busy(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.BUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_is_operation_complete_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_is_operation_complete_interrupt_pending(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.OCI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_clear_operation_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_clear_operation_complete_interrupt(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_AES_A_STATUS_OCI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_is_error_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_AES_A_is_error_interrupt_pending(
   SI32_AES_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.ERRI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_AES_A_clear_error_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_AES_A_clear_error_interrupt(
   SI32_AES_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_AES_A_STATUS_ERRI_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
