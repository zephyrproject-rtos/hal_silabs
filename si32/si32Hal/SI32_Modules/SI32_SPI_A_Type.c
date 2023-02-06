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
/// @file SI32_SPI_A_Type.c
//
// Script: 0.59
// HAL Source: 0.4
// Version: 10

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_SPI_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_SPI_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_initialize(
   SI32_SPI_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control,
   // Write to CONFIG register.
   uint32_t config,
   // Write to CLKRATE register.
   uint32_t clkrate)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->CONFIG.U32 = config;
   basePointer->CLKRATE.U32 = clkrate;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_write_tx_fifo_u32
//
// Write 32-bit data into SPI Transmit FIFO.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_write_tx_fifo_u32(
   SI32_SPI_A_Type * basePointer,
   // Data to write to SPI Transmit FIFO.
   uint32_t data_u32)
{
   //{{
   basePointer->DATA.U32 = data_u32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_write_tx_fifo_u16
//
// Write 16-bit data into SPI Transmit FIFO.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_write_tx_fifo_u16(
   SI32_SPI_A_Type * basePointer,
   // Data to write to SPI Transmit FIFO.
   uwide16_t data_u16)
{
   //{{
   basePointer->DATA.U16 = data_u16;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_write_tx_fifo_u8
//
// Write 8-bit data into SPI Transmit FIFO.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_write_tx_fifo_u8(
   SI32_SPI_A_Type * basePointer,
   // Data to write to SPI Transmit FIFO.
   uwide8_t data_u8)
{
   //{{
   basePointer->DATA.U8 = data_u8;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_read_rx_fifo_u32
//
// Read 32-bit data from SPI Receive FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SPI_A_read_rx_fifo_u32(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_read_rx_fifo_u16
//
// Read 16-bit data from SPI Receive FIFO.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_SPI_A_read_rx_fifo_u16(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.U16;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_read_rx_fifo_u8
//
// Read 8-bit data from SPI Receive FIFO.
//-----------------------------------------------------------------------------
uwide8_t
_SI32_SPI_A_read_rx_fifo_u8(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.U8;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_read_control
//
// Read CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SPI_A_read_control(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_write_control(
   SI32_SPI_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_rx_fifo_read_request_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_rx_fifo_read_request_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.RFRQI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_rx_fifo_overrun_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_rx_fifo_overrun_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.RFORI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_rx_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_rx_fifo_overrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_RFORI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_tx_fifo_write_request_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_tx_fifo_write_request_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.TFRQI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_tx_fifo_overrun_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_tx_fifo_overrun_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.TFORI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_tx_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_tx_fifo_overrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_TFORI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_slave_selected_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_slave_selected_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.SLVSELI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_mode_fault_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_mode_fault_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.MDFI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_mode_fault_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_mode_fault_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_MDFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_underrun_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_underrun_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.URI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_underrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_underrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_URI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_shift_register_empty_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_shift_register_empty_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.SREI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_illegal_rx_fifo_access_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_illegal_rx_fifo_access_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.RFILI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_illegal_rx_fifo_access_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_illegal_rx_fifo_access_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_RFILI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_illegal_tx_fifo_access_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_illegal_tx_fifo_access_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.TFILI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_illegal_tx_fifo_access_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_illegal_tx_fifo_access_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_TFILI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_any_interrupt_pending
//
// Check all SPI interrupt flags.
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_any_interrupt_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.U32
                 & (SI32_SPI_A_CONTROL_RFRQI_MASK
                    | SI32_SPI_A_CONTROL_RFORI_MASK
                    | SI32_SPI_A_CONTROL_TFRQI_MASK
                    | SI32_SPI_A_CONTROL_TFORI_MASK
                    | SI32_SPI_A_CONTROL_SLVSELI_MASK
                    | SI32_SPI_A_CONTROL_MDFI_MASK
                    | SI32_SPI_A_CONTROL_URI_MASK
                    | SI32_SPI_A_CONTROL_SREI_MASK
                    | SI32_SPI_A_CONTROL_RFILI_MASK
                    | SI32_SPI_A_CONTROL_TFILI_MASK));
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_all_interrupts
//
// Clear all SPI interrupt flags.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_all_interrupts(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_RFRQI_MASK
                            | SI32_SPI_A_CONTROL_RFORI_MASK
                            | SI32_SPI_A_CONTROL_TFRQI_MASK
                            | SI32_SPI_A_CONTROL_TFORI_MASK
                            | SI32_SPI_A_CONTROL_SLVSELI_MASK
                            | SI32_SPI_A_CONTROL_MDFI_MASK
                            | SI32_SPI_A_CONTROL_URI_MASK
                            | SI32_SPI_A_CONTROL_SREI_MASK
                            | SI32_SPI_A_CONTROL_RFILI_MASK
                            | SI32_SPI_A_CONTROL_TFILI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_get_nss_pin
//
// Get instantaneous NSS pin value.
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_get_nss_pin(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.NSSSTS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_transfer_in_progress
//
// Check if the SPI module is busy.
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_transfer_in_progress(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.BUSYF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_get_rx_fifo_count
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_SPI_A_get_rx_fifo_count(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.RFCNT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_get_tx_fifo_count
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_SPI_A_get_tx_fifo_count(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.TFCNT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_stall_in_debug_mode
//
// Enables SPI stall in debug mode.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_stall_in_debug_mode(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SPI_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_stall_in_debug_mode
//
// Disables SPI stall in debug mode.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_stall_in_debug_mode(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SPI_A_CONTROL_DBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_read_config
//
// Read CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SPI_A_read_config(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_write_config(
   SI32_SPI_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_rx_fifo_read_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_rx_fifo_read_request_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_RFRQIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_rx_fifo_read_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_rx_fifo_read_request_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_RFRQIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_rx_fifo_read_request_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_rx_fifo_read_request_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.RFRQIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_rx_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_rx_fifo_overrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_RFORIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_rx_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_rx_fifo_overrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_RFORIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_rx_fifo_overrun_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_rx_fifo_overrun_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.RFORIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_tx_fifo_write_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_tx_fifo_write_request_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_TFRQIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_tx_fifo_write_request_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_tx_fifo_write_request_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_TFRQIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_tx_fifo_write_request_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_tx_fifo_write_request_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.TFRQIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_tx_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_tx_fifo_overrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_TFORIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_tx_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_tx_fifo_overrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_TFORIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_tx_fifo_overrun_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_tx_fifo_overrun_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.TFORIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_slave_selected_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_slave_selected_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_SLVSELIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_slave_selected_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_slave_selected_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_SLVSELIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_slave_selected_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_slave_selected_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.SLVSELIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_mode_fault_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_mode_fault_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_MDFIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_mode_fault_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_mode_fault_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_MDFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_mode_fault_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_mode_fault_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.MDFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_underrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_underrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_URIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_underrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_underrun_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_URIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_underrun_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_underrun_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.URIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_shift_register_empty_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_shift_register_empty_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_SREIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_shift_register_empty_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_shift_register_empty_interrupt(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_SREIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_shift_register_empty_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_shift_register_empty_interrupt_enabled(
   SI32_SPI_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONFIG.SREIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_module(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_SPIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_module(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_SPIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_master_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_master_mode(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_MSTEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_slave_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_slave_mode(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_MSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_clock_mode
//
// Configure clock to standard SPI modes.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_clock_mode(
   SI32_SPI_A_Type * basePointer,
   // Clock mode.
   SI32_SPI_A_CLOCK_MODE_Enum_Type sckmode)
{
   //{{
   switch (sckmode)
   {
      case 0:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_CLKPOL_MASK
                                 | SI32_SPI_A_CONFIG_CLKPHA_MASK;
         break;
      case 1:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_CLKPOL_MASK;
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_CLKPHA_MASK;
         break;
      case 2:
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_CLKPOL_MASK;
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_CLKPHA_MASK;
         break;
      case 3:
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_CLKPOL_MASK
                                 | SI32_SPI_A_CONFIG_CLKPHA_MASK;
         break;
      default:
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_clock_idle_high
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_clock_idle_high(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_CLKPOL_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_clock_idle_low
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_clock_idle_low(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_CLKPOL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_data_change_first_edge
//
// Configure clock phase for first edge.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_data_change_first_edge(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_CLKPHA_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_data_change_second_edge
//
// Configure clock phase for second edge.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_data_change_second_edge(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_CLKPHA_EDGE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_nss_active_high
//
// Configure NSS to be active high.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_nss_active_high(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_NSSPOL_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_nss_active_low
//
// Configure NSS to be active low.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_nss_active_low(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_NSSPOL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_direction_lsb_first
//
// Data shifted LSB-first.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_direction_lsb_first(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_DDIRSEL_LSB_FIRST_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_direction_msb_first
//
// Data shifted MSB-first.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_direction_msb_first(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_DDIRSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_3wire_master_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_3wire_master_mode(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_MSTEN_MASK;
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_NSSMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_4wire_master_mode_nss_high
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_4wire_master_mode_nss_high(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_NSSMD_MASK
                           | SI32_SPI_A_CONFIG_MSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_4wire_master_mode_nss_low
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_4wire_master_mode_nss_low(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_NSSMD_MASK;
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_NSSMD_4_WIRE_MASTER_NSS_LOW_U32
                           | SI32_SPI_A_CONFIG_MSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_3wire_slave_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_3wire_slave_mode(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_MSTEN_MASK
                           | SI32_SPI_A_CONFIG_NSSMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_4wire_slave_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_4wire_slave_mode(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_MSTEN_MASK
                           | SI32_SPI_A_CONFIG_NSSMD_MASK;
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_NSSMD_4_WIRE_SLAVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_clear_nss
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_clear_nss(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_NSSMD_4_WIRE_SLAVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_set_nss
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_set_nss(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_NSSMD_4_WIRE_SLAVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_tx_fifo_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_tx_fifo_threshold(
   SI32_SPI_A_Type * basePointer,
   // Threshold.
   SI32_SPI_A_FIFO_THRESHOLD_Enum_Type threshold)
{
   //{{
   switch (threshold)
   {
      case 0:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_TFTH_MASK;
         break;
      case 1:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_TFTH_MASK;
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_TFTH_TWO_U32;
         break;
      case 2:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_TFTH_MASK;
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_TFTH_FOUR_U32;
         break;
      case 3:
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_TFTH_EMPTY_U32;
         break;
      default:
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_select_rx_fifo_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_select_rx_fifo_threshold(
   SI32_SPI_A_Type * basePointer,
   // Threshold.
   SI32_SPI_A_FIFO_THRESHOLD_Enum_Type threshold)
{
   //{{
   switch (threshold)
   {
      case 0:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_RFTH_MASK;
         break;
      case 1:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_RFTH_MASK;
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_RFTH_TWO_U32;
         break;
      case 2:
         basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_RFTH_MASK;
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_RFTH_FOUR_U32;
         break;
      case 3:
         basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_RFTH_FULL_U32;
         break;
      default:
         break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_set_data_length
//
// Set length for SPI transfers.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_set_data_length(
   SI32_SPI_A_Type * basePointer,
   // Number of bits per transfer (1-16).
   uint32_t dlength)
{
   assert((dlength >= 1) && (dlength <= 16));
   //{{
   basePointer->CONFIG.DSIZE = (dlength - 1);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_enable_dma_requests
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_enable_dma_requests(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_DMAEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_disable_dma_requests
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_disable_dma_requests(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SPI_A_CONFIG_DMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_flush_rx_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_flush_rx_fifo(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_RFIFOFL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_flush_tx_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_flush_tx_fifo(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_TFIFOFL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_reset_module
//
// Resets the SPIEN and MSTEN bits in the CONFIG register, all bits in
// the CONTROL register and flushes the RX and TX FIFOs.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_reset_module(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SPI_A_CONFIG_RESET_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_is_module_reset_pending
//
// returns true if a reset is still in progress.
//-----------------------------------------------------------------------------
bool
_SI32_SPI_A_is_module_reset_pending(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return (bool) basePointer->CONFIG.RESET;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_read_clkrate
//
// Read CLKRATE register.
//-----------------------------------------------------------------------------
uwide16_t
_SI32_SPI_A_read_clkrate(
   SI32_SPI_A_Type * basePointer)
{
   //{{
   return basePointer->CLKRATE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_write_clkrate
//
// Write to CLKRATE register.
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_write_clkrate(
   SI32_SPI_A_Type * basePointer,
   uwide16_t clkrate)
{
   //{{
   basePointer->CLKRATE.U32 = clkrate;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SPI_A_set_clock_divisor
//
//-----------------------------------------------------------------------------
void
_SI32_SPI_A_set_clock_divisor(
   SI32_SPI_A_Type * basePointer,
   // Clock rate divider value.
   uint32_t divisor)
{
   assert((divisor >= 1) && (divisor <= 131072));
   //{{
   basePointer->CLKRATE.CLKDIV = ((divisor/2)-1);
   //}}
}


//-eof--------------------------------------------------------------------------
