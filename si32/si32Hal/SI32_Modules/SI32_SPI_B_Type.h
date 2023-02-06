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
/// @file SI32_SPI_B_Type.h
//
// Script: 0.59
// HAL Source: 0.6
// Version: 1

#ifndef __SI32_SPI_B_TYPE_H__
#define __SI32_SPI_B_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// support definitions
#include "SI32_SPI_B_Support.h"

// register definitions
#include "SI32_SPI_B_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_SPI_B_initialize(SI32_SPI_B_Type* basePointer,
///      uint32_t control,
///      uint32_t config,
///      uint32_t clkrate)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
/// @param[in]
///  clkrate
///  Valid range is 16 bits.
///  Write to CLKRATE register.
///
void
_SI32_SPI_B_initialize(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*config*/
   uint32_t /*clkrate*/);
///
/// @def SI32_SPI_B_initialize(basePointer, control, config, clkrate)
#define SI32_SPI_B_initialize(basePointer, control, config, clkrate) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->CONFIG.U32 = config;\
   basePointer->CLKRATE.U32 = clkrate;\
} while(0)


/// @fn _SI32_SPI_B_write_tx_fifo_u32(SI32_SPI_B_Type* basePointer,
///      uint32_t data_u32)
///
/// @brief
/// Write 32-bit data into SPI Transmit FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data_u32
///  Valid range is 32 bits.
///  Data to write to SPI Transmit FIFO.
///
void
_SI32_SPI_B_write_tx_fifo_u32(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*data_u32*/);
///
/// @def SI32_SPI_B_write_tx_fifo_u32(basePointer, data_u32)
#define SI32_SPI_B_write_tx_fifo_u32(basePointer, data_u32) \
   (basePointer->DATA.U32 = data_u32)


/// @fn _SI32_SPI_B_write_tx_fifo_u16(SI32_SPI_B_Type* basePointer,
///      uwide16_t data_u16)
///
/// @brief
/// Write 16-bit data into SPI Transmit FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data_u16
///  Valid range is 16 bits.
///  Data to write to SPI Transmit FIFO.
///
void
_SI32_SPI_B_write_tx_fifo_u16(SI32_SPI_B_Type* /*basePointer*/,
   uwide16_t /*data_u16*/);
///
/// @def SI32_SPI_B_write_tx_fifo_u16(basePointer, data_u16)
#define SI32_SPI_B_write_tx_fifo_u16(basePointer, data_u16) \
   (basePointer->DATA.U16 = data_u16)


/// @fn _SI32_SPI_B_write_tx_fifo_u8(SI32_SPI_B_Type* basePointer,
///      uwide8_t data_u8)
///
/// @brief
/// Write 8-bit data into SPI Transmit FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data_u8
///  Valid range is 8 bits.
///  Data to write to SPI Transmit FIFO.
///
void
_SI32_SPI_B_write_tx_fifo_u8(SI32_SPI_B_Type* /*basePointer*/,
   uwide8_t /*data_u8*/);
///
/// @def SI32_SPI_B_write_tx_fifo_u8(basePointer, data_u8)
#define SI32_SPI_B_write_tx_fifo_u8(basePointer, data_u8) \
   (basePointer->DATA.U8 = data_u8)


/// @fn _SI32_SPI_B_read_rx_fifo_u32(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Read 32-bit data from SPI Receive FIFO.
///
/// @return
///  Data read from SPI Receive FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SPI_B_read_rx_fifo_u32(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_read_rx_fifo_u32(basePointer)
#define SI32_SPI_B_read_rx_fifo_u32(basePointer) \
(basePointer->DATA.U32)


/// @fn _SI32_SPI_B_read_rx_fifo_u16(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Read 16-bit data from SPI Receive FIFO.
///
/// @return
///  Data read from SPI Receive FIFO.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_SPI_B_read_rx_fifo_u16(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_read_rx_fifo_u16(basePointer)
#define SI32_SPI_B_read_rx_fifo_u16(basePointer) \
(basePointer->DATA.U16)


/// @fn _SI32_SPI_B_read_rx_fifo_u8(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Read 8-bit data from SPI Receive FIFO.
///
/// @return
///  Data read from SPI Receive FIFO.
///
/// @param[in]
///  basePointer
///
uwide8_t
_SI32_SPI_B_read_rx_fifo_u8(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_read_rx_fifo_u8(basePointer)
#define SI32_SPI_B_read_rx_fifo_u8(basePointer) \
(basePointer->DATA.U8)


/// @fn _SI32_SPI_B_read_control(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Read CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SPI_B_read_control(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_read_control(basePointer)
#define SI32_SPI_B_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_SPI_B_write_control(SI32_SPI_B_Type* basePointer,
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
_SI32_SPI_B_write_control(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_SPI_B_write_control(basePointer, control)
#define SI32_SPI_B_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_SPI_B_is_rx_fifo_read_request_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_rx_fifo_read_request_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_rx_fifo_read_request_interrupt_pending(basePointer)
#define SI32_SPI_B_is_rx_fifo_read_request_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.RFRQI)


/// @fn _SI32_SPI_B_is_rx_fifo_overrun_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_rx_fifo_overrun_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_rx_fifo_overrun_interrupt_pending(basePointer)
#define SI32_SPI_B_is_rx_fifo_overrun_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.RFORI)


/// @fn _SI32_SPI_B_clear_rx_fifo_overrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_rx_fifo_overrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_rx_fifo_overrun_interrupt(basePointer)
#define SI32_SPI_B_clear_rx_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_RFORI_MASK)


/// @fn _SI32_SPI_B_is_tx_fifo_write_request_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_tx_fifo_write_request_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_tx_fifo_write_request_interrupt_pending(basePointer)
#define SI32_SPI_B_is_tx_fifo_write_request_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.TFRQI)


/// @fn _SI32_SPI_B_is_tx_fifo_overrun_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_tx_fifo_overrun_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_tx_fifo_overrun_interrupt_pending(basePointer)
#define SI32_SPI_B_is_tx_fifo_overrun_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.TFORI)


/// @fn _SI32_SPI_B_clear_tx_fifo_overrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_tx_fifo_overrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_tx_fifo_overrun_interrupt(basePointer)
#define SI32_SPI_B_clear_tx_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_TFORI_MASK)


/// @fn _SI32_SPI_B_is_slave_selected_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if  Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_slave_selected_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_slave_selected_interrupt_pending(basePointer)
#define SI32_SPI_B_is_slave_selected_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.SLVSELI)


/// @fn _SI32_SPI_B_is_mode_fault_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if  Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_mode_fault_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_mode_fault_interrupt_pending(basePointer)
#define SI32_SPI_B_is_mode_fault_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.MDFI)


/// @fn _SI32_SPI_B_clear_mode_fault_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_mode_fault_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_mode_fault_interrupt(basePointer)
#define SI32_SPI_B_clear_mode_fault_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_MDFI_MASK)


/// @fn _SI32_SPI_B_is_underrun_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_underrun_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_underrun_interrupt_pending(basePointer)
#define SI32_SPI_B_is_underrun_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.URI)


/// @fn _SI32_SPI_B_clear_underrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_underrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_underrun_interrupt(basePointer)
#define SI32_SPI_B_clear_underrun_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_URI_MASK)


/// @fn _SI32_SPI_B_is_shift_register_empty_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_shift_register_empty_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_shift_register_empty_interrupt_pending(basePointer)
#define SI32_SPI_B_is_shift_register_empty_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.SREI)


/// @fn _SI32_SPI_B_is_illegal_rx_fifo_access_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_illegal_rx_fifo_access_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_illegal_rx_fifo_access_interrupt_pending(basePointer)
#define SI32_SPI_B_is_illegal_rx_fifo_access_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.RFILI)


/// @fn _SI32_SPI_B_clear_illegal_rx_fifo_access_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_illegal_rx_fifo_access_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_illegal_rx_fifo_access_interrupt(basePointer)
#define SI32_SPI_B_clear_illegal_rx_fifo_access_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_RFILI_MASK)


/// @fn _SI32_SPI_B_is_illegal_tx_fifo_access_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @return
///  TRUE if Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_illegal_tx_fifo_access_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_illegal_tx_fifo_access_interrupt_pending(basePointer)
#define SI32_SPI_B_is_illegal_tx_fifo_access_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.TFILI)


/// @fn _SI32_SPI_B_clear_illegal_tx_fifo_access_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_illegal_tx_fifo_access_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_illegal_tx_fifo_access_interrupt(basePointer)
#define SI32_SPI_B_clear_illegal_tx_fifo_access_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_TFILI_MASK)


/// @fn _SI32_SPI_B_is_any_interrupt_pending(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Check all SPI interrupt flags.
///
/// @return
///  True = Interrupt pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_any_interrupt_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_any_interrupt_pending(basePointer)
#define SI32_SPI_B_is_any_interrupt_pending(basePointer) \
   _SI32_SPI_B_is_any_interrupt_pending(basePointer)


/// @fn _SI32_SPI_B_clear_all_interrupts(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Clear all SPI interrupt flags.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_all_interrupts(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_all_interrupts(basePointer)
#define SI32_SPI_B_clear_all_interrupts(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_RFRQI_MASK\
                            | SI32_SPI_B_CONTROL_RFORI_MASK\
                            | SI32_SPI_B_CONTROL_TFRQI_MASK\
                            | SI32_SPI_B_CONTROL_TFORI_MASK\
                            | SI32_SPI_B_CONTROL_SLVSELI_MASK\
                            | SI32_SPI_B_CONTROL_MDFI_MASK\
                            | SI32_SPI_B_CONTROL_URI_MASK\
                            | SI32_SPI_B_CONTROL_SREI_MASK\
                            | SI32_SPI_B_CONTROL_RFILI_MASK\
                            | SI32_SPI_B_CONTROL_TFILI_MASK;\
} while(0)


/// @fn _SI32_SPI_B_get_nss_pin(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Get instantaneous NSS pin value.
///
/// @return
///  True = logic high, False = logic low.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_get_nss_pin(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_get_nss_pin(basePointer)
#define SI32_SPI_B_get_nss_pin(basePointer) \
((bool)basePointer->CONTROL.NSSSTS)


/// @fn _SI32_SPI_B_is_transfer_in_progress(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Check if the SPI module is busy.
///
/// @return
///  True = Transfer in progress.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_transfer_in_progress(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_transfer_in_progress(basePointer)
#define SI32_SPI_B_is_transfer_in_progress(basePointer) \
((bool)basePointer->CONTROL.BUSYF)


/// @fn _SI32_SPI_B_get_rx_fifo_count(SI32_SPI_B_Type* basePointer)
///
/// @return
///  Number of bytes in RX FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SPI_B_get_rx_fifo_count(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_get_rx_fifo_count(basePointer)
#define SI32_SPI_B_get_rx_fifo_count(basePointer) \
(basePointer->CONTROL.RFCNT)


/// @fn _SI32_SPI_B_get_tx_fifo_count(SI32_SPI_B_Type* basePointer)
///
/// @return
///  Number of bytes in TX FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SPI_B_get_tx_fifo_count(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_get_tx_fifo_count(basePointer)
#define SI32_SPI_B_get_tx_fifo_count(basePointer) \
(basePointer->CONTROL.TFCNT)


/// @fn _SI32_SPI_B_enable_stall_in_debug_mode(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Enables SPI stall in debug mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_stall_in_debug_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_stall_in_debug_mode(basePointer)
#define SI32_SPI_B_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_SPI_B_CONTROL_DBGMD_MASK)


/// @fn _SI32_SPI_B_disable_stall_in_debug_mode(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Disables SPI stall in debug mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_stall_in_debug_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_stall_in_debug_mode(basePointer)
#define SI32_SPI_B_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SPI_B_CONTROL_DBGMD_MASK)


/// @fn _SI32_SPI_B_read_config(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Read CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SPI_B_read_config(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_read_config(basePointer)
#define SI32_SPI_B_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_SPI_B_write_config(SI32_SPI_B_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Write to CONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_SPI_B_write_config(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_SPI_B_write_config(basePointer, config)
#define SI32_SPI_B_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_SPI_B_enable_rx_fifo_read_request_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_rx_fifo_read_request_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_rx_fifo_read_request_interrupt(basePointer)
#define SI32_SPI_B_enable_rx_fifo_read_request_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_RFRQIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_rx_fifo_read_request_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_rx_fifo_read_request_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_rx_fifo_read_request_interrupt(basePointer)
#define SI32_SPI_B_disable_rx_fifo_read_request_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_RFRQIEN_MASK)


/// @fn _SI32_SPI_B_is_rx_fifo_read_request_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_rx_fifo_read_request_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_rx_fifo_read_request_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_rx_fifo_read_request_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.RFRQIEN))


/// @fn _SI32_SPI_B_enable_rx_fifo_overrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_rx_fifo_overrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_rx_fifo_overrun_interrupt(basePointer)
#define SI32_SPI_B_enable_rx_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_RFORIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_rx_fifo_overrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_rx_fifo_overrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_rx_fifo_overrun_interrupt(basePointer)
#define SI32_SPI_B_disable_rx_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_RFORIEN_MASK)


/// @fn _SI32_SPI_B_is_rx_fifo_overrun_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_rx_fifo_overrun_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_rx_fifo_overrun_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_rx_fifo_overrun_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.RFORIEN))


/// @fn _SI32_SPI_B_enable_tx_fifo_write_request_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_tx_fifo_write_request_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_tx_fifo_write_request_interrupt(basePointer)
#define SI32_SPI_B_enable_tx_fifo_write_request_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_TFRQIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_tx_fifo_write_request_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_tx_fifo_write_request_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_tx_fifo_write_request_interrupt(basePointer)
#define SI32_SPI_B_disable_tx_fifo_write_request_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_TFRQIEN_MASK)


/// @fn _SI32_SPI_B_is_tx_fifo_write_request_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_tx_fifo_write_request_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_tx_fifo_write_request_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_tx_fifo_write_request_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.TFRQIEN))


/// @fn _SI32_SPI_B_enable_tx_fifo_overrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_tx_fifo_overrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_tx_fifo_overrun_interrupt(basePointer)
#define SI32_SPI_B_enable_tx_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_TFORIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_tx_fifo_overrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_tx_fifo_overrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_tx_fifo_overrun_interrupt(basePointer)
#define SI32_SPI_B_disable_tx_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_TFORIEN_MASK)


/// @fn _SI32_SPI_B_is_tx_fifo_overrun_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_tx_fifo_overrun_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_tx_fifo_overrun_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_tx_fifo_overrun_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.TFORIEN))


/// @fn _SI32_SPI_B_enable_slave_selected_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_slave_selected_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_slave_selected_interrupt(basePointer)
#define SI32_SPI_B_enable_slave_selected_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_SLVSELIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_slave_selected_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_slave_selected_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_slave_selected_interrupt(basePointer)
#define SI32_SPI_B_disable_slave_selected_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_SLVSELIEN_MASK)


/// @fn _SI32_SPI_B_is_slave_selected_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_slave_selected_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_slave_selected_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_slave_selected_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.SLVSELIEN))


/// @fn _SI32_SPI_B_enable_mode_fault_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_mode_fault_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_mode_fault_interrupt(basePointer)
#define SI32_SPI_B_enable_mode_fault_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_MDFIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_mode_fault_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_mode_fault_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_mode_fault_interrupt(basePointer)
#define SI32_SPI_B_disable_mode_fault_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_MDFIEN_MASK)


/// @fn _SI32_SPI_B_is_mode_fault_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_mode_fault_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_mode_fault_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_mode_fault_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.MDFIEN))


/// @fn _SI32_SPI_B_enable_underrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_underrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_underrun_interrupt(basePointer)
#define SI32_SPI_B_enable_underrun_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_URIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_underrun_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_underrun_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_underrun_interrupt(basePointer)
#define SI32_SPI_B_disable_underrun_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_URIEN_MASK)


/// @fn _SI32_SPI_B_is_underrun_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_underrun_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_underrun_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_underrun_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.URIEN))


/// @fn _SI32_SPI_B_enable_shift_register_empty_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_shift_register_empty_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_shift_register_empty_interrupt(basePointer)
#define SI32_SPI_B_enable_shift_register_empty_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_SREIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_shift_register_empty_interrupt(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_shift_register_empty_interrupt(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_shift_register_empty_interrupt(basePointer)
#define SI32_SPI_B_disable_shift_register_empty_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_SREIEN_MASK)


/// @fn _SI32_SPI_B_is_shift_register_empty_interrupt_enabled(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_shift_register_empty_interrupt_enabled(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_shift_register_empty_interrupt_enabled(basePointer)
#define SI32_SPI_B_is_shift_register_empty_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.SREIEN))


/// @fn _SI32_SPI_B_enable_module(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_module(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_module(basePointer)
#define SI32_SPI_B_enable_module(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_SPIEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_module(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_module(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_module(basePointer)
#define SI32_SPI_B_disable_module(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_SPIEN_MASK)


/// @fn _SI32_SPI_B_select_master_mode(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_master_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_master_mode(basePointer)
#define SI32_SPI_B_select_master_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_MSTEN_ENABLED_U32)


/// @fn _SI32_SPI_B_select_slave_mode(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_slave_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_slave_mode(basePointer)
#define SI32_SPI_B_select_slave_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_MSTEN_MASK)


/// @fn _SI32_SPI_B_select_clock_mode(SI32_SPI_B_Type* basePointer,
///      SI32_SPI_B_CLOCK_MODE_Enum_Type sckmode)
///
/// @brief
/// Configure clock to standard SPI modes.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  sckmode
///  Clock mode.
///
void
_SI32_SPI_B_select_clock_mode(SI32_SPI_B_Type* /*basePointer*/,
   SI32_SPI_B_CLOCK_MODE_Enum_Type /*sckmode*/);
///
/// @def SI32_SPI_B_select_clock_mode(basePointer, sckmode)
#define SI32_SPI_B_select_clock_mode(basePointer, sckmode) \
   _SI32_SPI_B_select_clock_mode(basePointer, sckmode)


/// @fn _SI32_SPI_B_select_clock_idle_high(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_clock_idle_high(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_clock_idle_high(basePointer)
#define SI32_SPI_B_select_clock_idle_high(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_CLKPOL_HIGH_U32)


/// @fn _SI32_SPI_B_select_clock_idle_low(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_clock_idle_low(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_clock_idle_low(basePointer)
#define SI32_SPI_B_select_clock_idle_low(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_CLKPOL_MASK)


/// @fn _SI32_SPI_B_select_data_change_first_edge(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Configure clock phase for first edge.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_data_change_first_edge(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_data_change_first_edge(basePointer)
#define SI32_SPI_B_select_data_change_first_edge(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_CLKPHA_MASK)


/// @fn _SI32_SPI_B_select_data_change_second_edge(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Configure clock phase for second edge.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_data_change_second_edge(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_data_change_second_edge(basePointer)
#define SI32_SPI_B_select_data_change_second_edge(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_CLKPHA_EDGE_U32)


/// @fn _SI32_SPI_B_select_nss_active_high(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Configure NSS to be active high.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_nss_active_high(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_nss_active_high(basePointer)
#define SI32_SPI_B_select_nss_active_high(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_NSSPOL_HIGH_U32)


/// @fn _SI32_SPI_B_select_nss_active_low(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Configure NSS to be active low.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_nss_active_low(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_nss_active_low(basePointer)
#define SI32_SPI_B_select_nss_active_low(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_NSSPOL_MASK)


/// @fn _SI32_SPI_B_select_direction_lsb_first(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Data shifted LSB-first.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_direction_lsb_first(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_direction_lsb_first(basePointer)
#define SI32_SPI_B_select_direction_lsb_first(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_DDIRSEL_LSB_FIRST_U32)


/// @fn _SI32_SPI_B_select_direction_msb_first(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Data shifted MSB-first.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_direction_msb_first(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_direction_msb_first(basePointer)
#define SI32_SPI_B_select_direction_msb_first(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_DDIRSEL_MASK)


/// @fn _SI32_SPI_B_select_3wire_master_mode(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_3wire_master_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_3wire_master_mode(basePointer)
#define SI32_SPI_B_select_3wire_master_mode(basePointer) do{  \
   basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_MSTEN_MASK;\
   basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_NSSMD_MASK;\
} while(0)


/// @fn _SI32_SPI_B_select_4wire_master_mode_nss_high(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_4wire_master_mode_nss_high(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_4wire_master_mode_nss_high(basePointer)
#define SI32_SPI_B_select_4wire_master_mode_nss_high(basePointer) do{  \
   basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_NSSMD_MASK\
                           | SI32_SPI_B_CONFIG_MSTEN_MASK;\
} while(0)


/// @fn _SI32_SPI_B_select_4wire_master_mode_nss_low(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_4wire_master_mode_nss_low(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_4wire_master_mode_nss_low(basePointer)
#define SI32_SPI_B_select_4wire_master_mode_nss_low(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_NSSMD_MASK;\
   basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_NSSMD_4_WIRE_MASTER_NSS_LOW_U32\
                           | SI32_SPI_B_CONFIG_MSTEN_MASK;\
} while(0)


/// @fn _SI32_SPI_B_select_3wire_slave_mode(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_3wire_slave_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_3wire_slave_mode(basePointer)
#define SI32_SPI_B_select_3wire_slave_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_MSTEN_MASK\
                           | SI32_SPI_B_CONFIG_NSSMD_MASK;\
} while(0)


/// @fn _SI32_SPI_B_select_4wire_slave_mode(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_4wire_slave_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_4wire_slave_mode(basePointer)
#define SI32_SPI_B_select_4wire_slave_mode(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_MSTEN_MASK\
                           | SI32_SPI_B_CONFIG_NSSMD_MASK;\
   basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_NSSMD_4_WIRE_SLAVE_U32;\
} while(0)


/// @fn _SI32_SPI_B_clear_nss(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_clear_nss(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_clear_nss(basePointer)
#define SI32_SPI_B_clear_nss(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_NSSMD_4_WIRE_SLAVE_U32)


/// @fn _SI32_SPI_B_set_nss(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_set_nss(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_set_nss(basePointer)
#define SI32_SPI_B_set_nss(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_NSSMD_4_WIRE_SLAVE_U32)


/// @fn _SI32_SPI_B_select_tx_fifo_threshold(SI32_SPI_B_Type* basePointer,
///      SI32_SPI_B_FIFO_THRESHOLD_Enum_Type threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Threshold.
///
void
_SI32_SPI_B_select_tx_fifo_threshold(SI32_SPI_B_Type* /*basePointer*/,
   SI32_SPI_B_FIFO_THRESHOLD_Enum_Type /*threshold*/);
///
/// @def SI32_SPI_B_select_tx_fifo_threshold(basePointer, threshold)
#define SI32_SPI_B_select_tx_fifo_threshold(basePointer, threshold) \
   _SI32_SPI_B_select_tx_fifo_threshold(basePointer, threshold)


/// @fn _SI32_SPI_B_select_rx_fifo_threshold(SI32_SPI_B_Type* basePointer,
///      SI32_SPI_B_FIFO_THRESHOLD_Enum_Type threshold)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Threshold.
///
void
_SI32_SPI_B_select_rx_fifo_threshold(SI32_SPI_B_Type* /*basePointer*/,
   SI32_SPI_B_FIFO_THRESHOLD_Enum_Type /*threshold*/);
///
/// @def SI32_SPI_B_select_rx_fifo_threshold(basePointer, threshold)
#define SI32_SPI_B_select_rx_fifo_threshold(basePointer, threshold) \
   _SI32_SPI_B_select_rx_fifo_threshold(basePointer, threshold)


/// @fn _SI32_SPI_B_set_data_length(SI32_SPI_B_Type* basePointer,
///      uint32_t dlength)
///
/// @brief
/// Set length for SPI transfers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dlength
///  Valid range is 1 to 16.
///  Number of bits per transfer (1-16).
///
void
_SI32_SPI_B_set_data_length(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*dlength*/);
///
/// @def SI32_SPI_B_set_data_length(basePointer, dlength)
#define SI32_SPI_B_set_data_length(basePointer, dlength) \
   (basePointer->CONFIG.DSIZE = (dlength - 1))


/// @fn _SI32_SPI_B_enable_dma_requests(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_dma_requests(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_dma_requests(basePointer)
#define SI32_SPI_B_enable_dma_requests(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_DMAEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_dma_requests(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_dma_requests(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_dma_requests(basePointer)
#define SI32_SPI_B_disable_dma_requests(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SPI_B_CONFIG_DMAEN_MASK)


/// @fn _SI32_SPI_B_flush_rx_fifo(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_flush_rx_fifo(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_flush_rx_fifo(basePointer)
#define SI32_SPI_B_flush_rx_fifo(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_RFIFOFL_MASK)


/// @fn _SI32_SPI_B_flush_tx_fifo(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_flush_tx_fifo(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_flush_tx_fifo(basePointer)
#define SI32_SPI_B_flush_tx_fifo(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_TFIFOFL_MASK)


/// @fn _SI32_SPI_B_reset_module(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Resets the SPIEN and MSTEN bits in the CONFIG register, all bits in
/// the CONTROL register and flushes the RX and TX FIFOs.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_reset_module(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_reset_module(basePointer)
#define SI32_SPI_B_reset_module(basePointer) \
   (basePointer->CONFIG_SET = SI32_SPI_B_CONFIG_RESET_ACTIVE_U32)


/// @fn _SI32_SPI_B_is_module_reset_pending(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// returns true if a reset is still in progress.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SPI_B_is_module_reset_pending(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_is_module_reset_pending(basePointer)
#define SI32_SPI_B_is_module_reset_pending(basePointer) \
((bool) basePointer->CONFIG.RESET)


/// @fn _SI32_SPI_B_read_clkrate(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Read CLKRATE register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_SPI_B_read_clkrate(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_read_clkrate(basePointer)
#define SI32_SPI_B_read_clkrate(basePointer) \
(basePointer->CLKRATE.U32)


/// @fn _SI32_SPI_B_write_clkrate(SI32_SPI_B_Type* basePointer,
///      uwide16_t clkrate)
///
/// @brief
/// Write to CLKRATE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  clkrate
///  Valid range is 16 bits.
///
void
_SI32_SPI_B_write_clkrate(SI32_SPI_B_Type* /*basePointer*/,
   uwide16_t /*clkrate*/);
///
/// @def SI32_SPI_B_write_clkrate(basePointer, clkrate)
#define SI32_SPI_B_write_clkrate(basePointer, clkrate) \
   (basePointer->CLKRATE.U32 = clkrate)


/// @fn _SI32_SPI_B_set_clock_divisor(SI32_SPI_B_Type* basePointer,
///      uint32_t divisor)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divisor
///  Valid range is 1 to 131072.
///  Clock rate divider value.
///
void
_SI32_SPI_B_set_clock_divisor(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*divisor*/);
///
/// @def SI32_SPI_B_set_clock_divisor(basePointer, divisor)
#define SI32_SPI_B_set_clock_divisor(basePointer, divisor) \
   (basePointer->CLKRATE.CLKDIV = ((divisor/2)-1))


/// @fn _SI32_SPI_B_read_configmd(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// Read CONFIGMD register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SPI_B_read_configmd(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_read_configmd(basePointer)
#define SI32_SPI_B_read_configmd(basePointer) \
(basePointer->CONFIGMD.U32)


/// @fn _SI32_SPI_B_write_configmd(SI32_SPI_B_Type* basePointer,
///      uint32_t configmd)
///
/// @brief
/// Write to CONFIGMD register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  configmd
///  Valid range is 32 bits.
///
void
_SI32_SPI_B_write_configmd(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*configmd*/);
///
/// @def SI32_SPI_B_write_configmd(basePointer, configmd)
#define SI32_SPI_B_write_configmd(basePointer, configmd) \
   (basePointer->CONFIGMD.U32 = configmd)


/// @fn _SI32_SPI_B_select_operation_mode_normal(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_operation_mode_normal(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_operation_mode_normal(basePointer)
#define SI32_SPI_B_select_operation_mode_normal(basePointer) \
   (basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_OPMD_MASK)


/// @fn _SI32_SPI_B_select_operation_mode_receive_only(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_operation_mode_receive_only(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_operation_mode_receive_only(basePointer)
#define SI32_SPI_B_select_operation_mode_receive_only(basePointer) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_OPMD_MASK;\
	basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_OPMD_RECEIVE_U32;\
} while(0)


/// @fn _SI32_SPI_B_select_operation_mode_transmit_only(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_operation_mode_transmit_only(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_operation_mode_transmit_only(basePointer)
#define SI32_SPI_B_select_operation_mode_transmit_only(basePointer) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_OPMD_MASK;\
	basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_OPMD_TRANSMIT_U32;\
} while(0)


/// @fn _SI32_SPI_B_select_operation_mode_flow_control(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_operation_mode_flow_control(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_operation_mode_flow_control(basePointer)
#define SI32_SPI_B_select_operation_mode_flow_control(basePointer) \
   (basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_OPMD_FLOWCONTROL_U32)


/// @fn _SI32_SPI_B_enable_auto_nss_mode(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// NSS will automatically assert with the SPI module is configured for
/// single-master mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_auto_nss_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_auto_nss_mode(basePointer)
#define SI32_SPI_B_enable_auto_nss_mode(basePointer) \
   (basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_AUTONSS_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_auto_nss_mode(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// NSS will not automatically assert with the SPI module is configured
/// for single-master mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_auto_nss_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_auto_nss_mode(basePointer)
#define SI32_SPI_B_disable_auto_nss_mode(basePointer) \
   (basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_AUTONSS_MASK)


/// @fn _SI32_SPI_B_enable_cts_flow_control(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_cts_flow_control(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_cts_flow_control(basePointer)
#define SI32_SPI_B_enable_cts_flow_control(basePointer) \
   (basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_CTSEN_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_cts_flow_control(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_cts_flow_control(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_cts_flow_control(basePointer)
#define SI32_SPI_B_disable_cts_flow_control(basePointer) \
   (basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_CTSEN_MASK)


/// @fn _SI32_SPI_B_enable_flow_control_mode(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_flow_control_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_flow_control_mode(basePointer)
#define SI32_SPI_B_enable_flow_control_mode(basePointer) \
   (basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_FLOWMD_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_flow_control_mode(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_flow_control_mode(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_flow_control_mode(basePointer)
#define SI32_SPI_B_disable_flow_control_mode(basePointer) \
   (basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_FLOWMD_MASK)


/// @fn _SI32_SPI_B_enable_software_abort(SI32_SPI_B_Type* basePointer)
///
/// @brief
/// At the end of the current data transmission, the SPI module will be
/// reset.
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_software_abort(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_software_abort(basePointer)
#define SI32_SPI_B_enable_software_abort(basePointer) \
   (basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_ABORT_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_software_abort(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_software_abort(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_software_abort(basePointer)
#define SI32_SPI_B_disable_software_abort(basePointer) \
   (basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_ABORT_MASK)


/// @fn _SI32_SPI_B_enable_transmit_data_on_request(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_enable_transmit_data_on_request(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_enable_transmit_data_on_request(basePointer)
#define SI32_SPI_B_enable_transmit_data_on_request(basePointer) \
   (basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_TXONREQ_ENABLED_U32)


/// @fn _SI32_SPI_B_disable_transmit_data_on_request(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_disable_transmit_data_on_request(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_disable_transmit_data_on_request(basePointer)
#define SI32_SPI_B_disable_transmit_data_on_request(basePointer) \
   (basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_TXONREQ_MASK)


/// @fn _SI32_SPI_B_select_nss_data_count(SI32_SPI_B_Type* basePointer,
///      uint32_t nsscnt)
///
/// @brief
/// Selects the number of data blocks per NSS cycle.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  nsscnt
///  Valid range is 8 bits.
///
void
_SI32_SPI_B_select_nss_data_count(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*nsscnt*/);
///
/// @def SI32_SPI_B_select_nss_data_count(basePointer, nsscnt)
#define SI32_SPI_B_select_nss_data_count(basePointer, nsscnt) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_NSSCNT_MASK;\
	basePointer->CONFIGMD_SET = nsscnt << SI32_SPI_B_CONFIGMD_NSSCNT_SHIFT;\
} while(0)


/// @fn _SI32_SPI_B_select_nss_delay(SI32_SPI_B_Type* basePointer,
///      uint32_t nssdelay)
///
/// @brief
/// Selects the number of half SPI clock cycles between NSS cycles. 0  =
/// one half SPI clock cycle, 1 = two half SPI clock cycles, 2 = three
/// half SPI clock cycles, ...
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  nssdelay
///  Valid range is 8 bits.
///
void
_SI32_SPI_B_select_nss_delay(SI32_SPI_B_Type* /*basePointer*/,
   uint32_t /*nssdelay*/);
///
/// @def SI32_SPI_B_select_nss_delay(basePointer, nssdelay)
#define SI32_SPI_B_select_nss_delay(basePointer, nssdelay) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_NSSDELAY_MASK;\
	basePointer->CONFIGMD_SET = nssdelay << SI32_SPI_B_CONFIGMD_NSSDELAY_SHIFT;\
} while(0)


/// @fn _SI32_SPI_B_select_transfer_count_auto(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_transfer_count_auto(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_transfer_count_auto(basePointer)
#define SI32_SPI_B_select_transfer_count_auto(basePointer) \
   (basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_TFRCNT_MASK)


/// @fn _SI32_SPI_B_select_transfer_count_one(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_transfer_count_one(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_transfer_count_one(basePointer)
#define SI32_SPI_B_select_transfer_count_one(basePointer) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_TFRCNT_MASK;\
	basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_TFRCNT_TRANSFER1_U32;\
} while(0)


/// @fn _SI32_SPI_B_select_transfer_count_two(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_transfer_count_two(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_transfer_count_two(basePointer)
#define SI32_SPI_B_select_transfer_count_two(basePointer) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_TFRCNT_MASK;\
	basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_TFRCNT_TRANSFER2_U32;\
} while(0)


/// @fn _SI32_SPI_B_select_transfer_count_three(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_transfer_count_three(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_transfer_count_three(basePointer)
#define SI32_SPI_B_select_transfer_count_three(basePointer) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_TFRCNT_MASK;\
	basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_TFRCNT_TRANSFER3_U32;\
} while(0)


/// @fn _SI32_SPI_B_select_transfer_count_four(SI32_SPI_B_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SPI_B_select_transfer_count_four(SI32_SPI_B_Type* /*basePointer*/);
///
/// @def SI32_SPI_B_select_transfer_count_four(basePointer)
#define SI32_SPI_B_select_transfer_count_four(basePointer) do{  \
	basePointer->CONFIGMD_CLR = SI32_SPI_B_CONFIGMD_TFRCNT_MASK;\
	basePointer->CONFIGMD_SET = SI32_SPI_B_CONFIGMD_TFRCNT_TRANSFER4_U32;\
} while(0)



#ifdef __cplusplus
}
#endif

#endif // __SI32_SPI_B_TYPE_H__

//-eof--------------------------------------------------------------------------
