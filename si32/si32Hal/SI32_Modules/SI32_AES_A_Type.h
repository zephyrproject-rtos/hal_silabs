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
/// @file SI32_AES_A_Type.h
//
// Script: 0.58
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_AES_A_TYPE_H__
#define __SI32_AES_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_AES_A_Registers.h"

// support definitions
#include "SI32_AES_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_AES_A_initialize(SI32_AES_A_Type* basePointer,
///      uint32_t control,
///      uint32_t xfrsize,
///      uint32_t status)
///
/// @brief
/// Writes all AES registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  xfrsize
///  Valid range is 32 bits.
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_AES_A_initialize(SI32_AES_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*xfrsize*/
   uint32_t /*status*/);
///
/// @def SI32_AES_A_initialize(basePointer, control, xfrsize, status)
#define SI32_AES_A_initialize(basePointer, control, xfrsize, status) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->XFRSIZE.U32 = xfrsize;\
   basePointer->STATUS.U32 = status;\
} while(0)


/// @fn _SI32_AES_A_write_control(SI32_AES_A_Type* basePointer,
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
_SI32_AES_A_write_control(SI32_AES_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_AES_A_write_control(basePointer, control)
#define SI32_AES_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_AES_A_read_control(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_AES_A_read_control(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_read_control(basePointer)
#define SI32_AES_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_AES_A_start_operation(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_start_operation(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_start_operation(basePointer)
#define SI32_AES_A_start_operation(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_XFRSTA_START_U32)


/// @fn _SI32_AES_A_enable_key_capture(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enable_key_capture(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enable_key_capture(basePointer)
#define SI32_AES_A_enable_key_capture(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_KEYCPEN_ENABLED_U32)


/// @fn _SI32_AES_A_disable_key_capture(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_disable_key_capture(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_disable_key_capture(basePointer)
#define SI32_AES_A_disable_key_capture(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYCPEN_MASK)


/// @fn _SI32_AES_A_select_encryption_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_encryption_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_encryption_mode(basePointer)
#define SI32_AES_A_select_encryption_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_EDMD_ENCRYPT_U32)


/// @fn _SI32_AES_A_select_decryption_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_decryption_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_decryption_mode(basePointer)
#define SI32_AES_A_select_decryption_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_EDMD_MASK)


/// @fn _SI32_AES_A_select_software_mode(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Data transfers are not handled by the DMA.
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_software_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_software_mode(basePointer)
#define SI32_AES_A_select_software_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_SWMDEN_ENABLED_U32)


/// @fn _SI32_AES_A_select_dma_mode(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Data transfers are handled by the DMA.
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_dma_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_dma_mode(basePointer)
#define SI32_AES_A_select_dma_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_SWMDEN_MASK)


/// @fn _SI32_AES_A_enter_bypass_hardware_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enter_bypass_hardware_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enter_bypass_hardware_mode(basePointer)
#define SI32_AES_A_enter_bypass_hardware_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_BEN_ENABLED_U32)


/// @fn _SI32_AES_A_exit_bypass_hardware_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_exit_bypass_hardware_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_exit_bypass_hardware_mode(basePointer)
#define SI32_AES_A_exit_bypass_hardware_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_BEN_MASK)


/// @fn _SI32_AES_A_select_xor_path_none(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_xor_path_none(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_xor_path_none(basePointer)
#define SI32_AES_A_select_xor_path_none(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_XOREN_MASK)


/// @fn _SI32_AES_A_select_xor_path_input(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_xor_path_input(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_xor_path_input(basePointer)
#define SI32_AES_A_select_xor_path_input(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_XOREN_MASK;\
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_XOREN_XOR_INPUT_U32;\
} while(0)


/// @fn _SI32_AES_A_select_xor_path_output(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_xor_path_output(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_xor_path_output(basePointer)
#define SI32_AES_A_select_xor_path_output(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_XOREN_MASK;\
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_XOREN_XOR_OUTPUT_U32;\
} while(0)


/// @fn _SI32_AES_A_enter_counter_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enter_counter_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enter_counter_mode(basePointer)
#define SI32_AES_A_enter_counter_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_HCTREN_ENABLED_U32)


/// @fn _SI32_AES_A_exit_counter_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_exit_counter_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_exit_counter_mode(basePointer)
#define SI32_AES_A_exit_counter_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_HCTREN_MASK)


/// @fn _SI32_AES_A_enter_cipher_block_chaining_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enter_cipher_block_chaining_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enter_cipher_block_chaining_mode(basePointer)
#define SI32_AES_A_enter_cipher_block_chaining_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_HCBCEN_ENABLED_U32)


/// @fn _SI32_AES_A_exit_cipher_block_chaining_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_exit_cipher_block_chaining_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_exit_cipher_block_chaining_mode(basePointer)
#define SI32_AES_A_exit_cipher_block_chaining_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_HCBCEN_MASK)


/// @fn _SI32_AES_A_select_key_size_128(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_key_size_128(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_key_size_128(basePointer)
#define SI32_AES_A_select_key_size_128(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYSIZE_MASK)


/// @fn _SI32_AES_A_select_key_size_192(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_key_size_192(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_key_size_192(basePointer)
#define SI32_AES_A_select_key_size_192(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYSIZE_MASK;\
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_KEYSIZE_KEY192_U32;\
} while(0)


/// @fn _SI32_AES_A_select_key_size_256(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_select_key_size_256(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_select_key_size_256(basePointer)
#define SI32_AES_A_select_key_size_256(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_KEYSIZE_MASK;\
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_KEYSIZE_KEY256_U32;\
} while(0)


/// @fn _SI32_AES_A_enable_error_interrupt(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enable_error_interrupt(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enable_error_interrupt(basePointer)
#define SI32_AES_A_enable_error_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_ERRIEN_ENABLED_U32)


/// @fn _SI32_AES_A_disable_error_interrupt(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_disable_error_interrupt(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_disable_error_interrupt(basePointer)
#define SI32_AES_A_disable_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_ERRIEN_MASK)


/// @fn _SI32_AES_A_is_error_interrupt_enabled(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_is_error_interrupt_enabled(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_is_error_interrupt_enabled(basePointer)
#define SI32_AES_A_is_error_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.ERRIEN))


/// @fn _SI32_AES_A_enable_operation_complete_interrupt(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enable_operation_complete_interrupt(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enable_operation_complete_interrupt(basePointer)
#define SI32_AES_A_enable_operation_complete_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_OCIEN_ENABLED_U32)


/// @fn _SI32_AES_A_disable_operation_complete_interrupt(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_disable_operation_complete_interrupt(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_disable_operation_complete_interrupt(basePointer)
#define SI32_AES_A_disable_operation_complete_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_OCIEN_MASK)


/// @fn _SI32_AES_A_is_operation_complete_interrupt_enabled(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_is_operation_complete_interrupt_enabled(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_is_operation_complete_interrupt_enabled(basePointer)
#define SI32_AES_A_is_operation_complete_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.OCIEN))


/// @fn _SI32_AES_A_enable_stall_in_debug_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enable_stall_in_debug_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enable_stall_in_debug_mode(basePointer)
#define SI32_AES_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_AES_A_disable_stall_in_debug_mode(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_disable_stall_in_debug_mode(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_disable_stall_in_debug_mode(basePointer)
#define SI32_AES_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_DBGMD_RUN_U32)


/// @fn _SI32_AES_A_enable_module(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_enable_module(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_enable_module(basePointer)
#define SI32_AES_A_enable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_RESET_MASK)


/// @fn _SI32_AES_A_disable_module(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_disable_module(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_disable_module(basePointer)
#define SI32_AES_A_disable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_AES_A_CONTROL_RESET_ACTIVE_U32)


/// @fn _SI32_AES_A_reset_module(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Disables, then enables the module.
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_reset_module(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_reset_module(basePointer)
#define SI32_AES_A_reset_module(basePointer) do{  \
   basePointer->CONTROL_SET = SI32_AES_A_CONTROL_RESET_ACTIVE_U32;\
   basePointer->CONTROL_CLR = SI32_AES_A_CONTROL_RESET_MASK;\
} while(0)


/// @fn _SI32_AES_A_write_xfrsize(SI32_AES_A_Type* basePointer,
///      uint32_t xfrsize)
///
/// @brief
/// Writes XFRSIZE register.  The contents of XFRSIZE plus 1 indicates the
/// number of 4-word blocks left to process.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  xfrsize
///  Valid range is 32 bits.
///
void
_SI32_AES_A_write_xfrsize(SI32_AES_A_Type* /*basePointer*/,
   uint32_t /*xfrsize*/);
///
/// @def SI32_AES_A_write_xfrsize(basePointer, xfrsize)
#define SI32_AES_A_write_xfrsize(basePointer, xfrsize) \
   (basePointer->XFRSIZE.U32 = xfrsize)


/// @fn _SI32_AES_A_read_xfrsize(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Reads XFRSIZE register.  The contents of XFRSIZE plus 1 indicates the
/// number of 4-word blocks left to process.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_AES_A_read_xfrsize(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_read_xfrsize(basePointer)
#define SI32_AES_A_read_xfrsize(basePointer) \
(basePointer->XFRSIZE.U32)


/// @fn _SI32_AES_A_write_datafifo(SI32_AES_A_Type* basePointer,
///      uint32_t data_word)
///
/// @brief
/// Writes DATAFIFO register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data_word
///
void
_SI32_AES_A_write_datafifo(SI32_AES_A_Type* /*basePointer*/,
   uint32_t /*data_word*/);
///
/// @def SI32_AES_A_write_datafifo(basePointer, data_word)
#define SI32_AES_A_write_datafifo(basePointer, data_word) \
   (basePointer->DATAFIFO.U32 = data_word)


/// @fn _SI32_AES_A_read_datafifo(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Reads DATAFIFO register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_AES_A_read_datafifo(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_read_datafifo(basePointer)
#define SI32_AES_A_read_datafifo(basePointer) \
(basePointer->DATAFIFO.U32)


/// @fn _SI32_AES_A_write_xorfifo(SI32_AES_A_Type* basePointer,
///      uint32_t xor_word)
///
/// @brief
/// Writes XORFIFO register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  xor_word
///
void
_SI32_AES_A_write_xorfifo(SI32_AES_A_Type* /*basePointer*/,
   uint32_t /*xor_word*/);
///
/// @def SI32_AES_A_write_xorfifo(basePointer, xor_word)
#define SI32_AES_A_write_xorfifo(basePointer, xor_word) \
   (basePointer->XORFIFO.U32 = xor_word)


/// @fn _SI32_AES_A_write_xorfifo_full(SI32_AES_A_Type* basePointer,
///      SI32_AES_A_Initialization_Vector_Type xor_vector)
///
/// @brief
/// Writes XORFIFO register with 4 words.  Index 0 of the passed struct is
/// written first.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  xor_vector
///
void
_SI32_AES_A_write_xorfifo_full(SI32_AES_A_Type* /*basePointer*/,
   SI32_AES_A_Initialization_Vector_Type /*xor_vector*/);
///
/// @def SI32_AES_A_write_xorfifo_full(basePointer, xor_vector)
#define SI32_AES_A_write_xorfifo_full(basePointer, xor_vector) do{  \
   basePointer->XORFIFO.U32 = xor_vector.iv[0];\
   basePointer->XORFIFO.U32 = xor_vector.iv[1];\
   basePointer->XORFIFO.U32 = xor_vector.iv[2];\
   basePointer->XORFIFO.U32 = xor_vector.iv[3];\
} while(0)


/// @fn _SI32_AES_A_write_hardware_key(SI32_AES_A_Type* basePointer,
///      SI32_AES_A_Hardware_Key_Type key)
///
/// @brief
/// Writes all HWKEY registers.  The word at index 0 of the passed struct
/// is copied into HWKEY0.  If the key size is less than 256 bits, only
/// the appropriate number of words is copied to the HWKEY registers.
/// Any remaining registers are cleared.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  key
///
void
_SI32_AES_A_write_hardware_key(SI32_AES_A_Type* /*basePointer*/,
   SI32_AES_A_Hardware_Key_Type /*key*/);
///
/// @def SI32_AES_A_write_hardware_key(basePointer, key)
#define SI32_AES_A_write_hardware_key(basePointer, key) \
   _SI32_AES_A_write_hardware_key(basePointer, key)


/// @fn _SI32_AES_A_read_hardware_key(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Reads all HWKEY registers.  The word at index 0 of the returned struct
/// is copied from HWKEY0.  If the key size is less than 256 bits, only
/// the appropriate number of words is copied to the return value.   Any
/// remaining words are cleared.
///
/// @param[in]
///  basePointer
///
SI32_AES_A_Hardware_Key_Type
_SI32_AES_A_read_hardware_key(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_read_hardware_key(basePointer)
#define SI32_AES_A_read_hardware_key(basePointer) \
   _SI32_AES_A_read_hardware_key(basePointer)


/// @fn _SI32_AES_A_write_hardware_counter(SI32_AES_A_Type* basePointer,
///      SI32_AES_A_Hardware_Counter_Type counter)
///
/// @brief
/// Writes all HWCTR registers.  The word at index 0 of the passed struct
/// is copied into HWCTR0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  counter
///
void
_SI32_AES_A_write_hardware_counter(SI32_AES_A_Type* /*basePointer*/,
   SI32_AES_A_Hardware_Counter_Type /*counter*/);
///
/// @def SI32_AES_A_write_hardware_counter(basePointer, counter)
#define SI32_AES_A_write_hardware_counter(basePointer, counter) do{  \
   basePointer->HWCTR0.HWCTR0_BITS = counter.hwctr[0];\
   basePointer->HWCTR1.HWCTR1_BITS = counter.hwctr[1];\
   basePointer->HWCTR2.HWCTR2_BITS = counter.hwctr[2];\
   basePointer->HWCTR3.HWCTR3_BITS = counter.hwctr[3];\
} while(0)


/// @fn _SI32_AES_A_read_hardware_counter(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Reads all HWCTR registers.  The word at index 0 of the returned struct
/// is copied from HWCTR0.
///
/// @param[in]
///  basePointer
///
SI32_AES_A_Hardware_Counter_Type
_SI32_AES_A_read_hardware_counter(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_read_hardware_counter(basePointer)
#define SI32_AES_A_read_hardware_counter(basePointer) \
   _SI32_AES_A_read_hardware_counter(basePointer)


/// @fn _SI32_AES_A_write_status(SI32_AES_A_Type* basePointer,
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
_SI32_AES_A_write_status(SI32_AES_A_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_AES_A_write_status(basePointer, status)
#define SI32_AES_A_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_AES_A_read_status(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Reads STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_AES_A_read_status(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_read_status(basePointer)
#define SI32_AES_A_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_AES_A_has_data_underrun_occurred(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_has_data_underrun_occurred(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_has_data_underrun_occurred(basePointer)
#define SI32_AES_A_has_data_underrun_occurred(basePointer) \
((bool)(basePointer->STATUS.DURF))


/// @fn _SI32_AES_A_has_data_overrun_occurred(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_has_data_overrun_occurred(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_has_data_overrun_occurred(basePointer)
#define SI32_AES_A_has_data_overrun_occurred(basePointer) \
((bool)(basePointer->STATUS.DORF))


/// @fn _SI32_AES_A_has_xor_data_overrun_occurred(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_has_xor_data_overrun_occurred(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_has_xor_data_overrun_occurred(basePointer)
#define SI32_AES_A_has_xor_data_overrun_occurred(basePointer) \
((bool)(basePointer->STATUS.XORF))


/// @fn _SI32_AES_A_get_datafifo_count(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Returns the number of words (up to 4) in the internal data FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_AES_A_get_datafifo_count(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_get_datafifo_count(basePointer)
#define SI32_AES_A_get_datafifo_count(basePointer) \
(basePointer->STATUS.DFIFOLVL)


/// @fn _SI32_AES_A_get_xorfifo_count(SI32_AES_A_Type* basePointer)
///
/// @brief
/// Returns the number of words (up to 4) in the internal XOR FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_AES_A_get_xorfifo_count(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_get_xorfifo_count(basePointer)
#define SI32_AES_A_get_xorfifo_count(basePointer) \
(basePointer->STATUS.XFIFOLVL)


/// @fn _SI32_AES_A_is_busy(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_is_busy(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_is_busy(basePointer)
#define SI32_AES_A_is_busy(basePointer) \
((bool)(basePointer->STATUS.BUSYF))


/// @fn _SI32_AES_A_is_operation_complete_interrupt_pending(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_is_operation_complete_interrupt_pending(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_is_operation_complete_interrupt_pending(basePointer)
#define SI32_AES_A_is_operation_complete_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.OCI))


/// @fn _SI32_AES_A_clear_operation_complete_interrupt(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_clear_operation_complete_interrupt(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_clear_operation_complete_interrupt(basePointer)
#define SI32_AES_A_clear_operation_complete_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_AES_A_STATUS_OCI_MASK)


/// @fn _SI32_AES_A_is_error_interrupt_pending(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_AES_A_is_error_interrupt_pending(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_is_error_interrupt_pending(basePointer)
#define SI32_AES_A_is_error_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.ERRI))


/// @fn _SI32_AES_A_clear_error_interrupt(SI32_AES_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_AES_A_clear_error_interrupt(SI32_AES_A_Type* /*basePointer*/);
///
/// @def SI32_AES_A_clear_error_interrupt(basePointer)
#define SI32_AES_A_clear_error_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_AES_A_STATUS_ERRI_MASK)



#ifdef __cplusplus
}
#endif

#endif // __SI32_AES_A_TYPE_H__

//-eof--------------------------------------------------------------------------
