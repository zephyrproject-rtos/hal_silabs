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
/// @file SI32_USBEP_A_Type.c
//
// Script: 0.58
// HAL Source: 0.5
// Version: 3

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_USBEP_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_USBEP_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_initialize(
   SI32_USBEP_A_Type * basePointer,
   // Write to EPMPSIZE register.
   uint32_t epmpsize,
   // Write to EPCONTROL register.
   uint32_t epcontrol)
{
   //{{
   basePointer->EPMPSIZE.U32 = epmpsize;
   basePointer->EPCONTROL.U32 = epcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_write_epmpsize
//
// Writes to EPMPSIZE register.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_write_epmpsize(
   SI32_USBEP_A_Type * basePointer,
   uint32_t epmpsize)
{
   //{{
   basePointer->EPMPSIZE.U32 = epmpsize;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_read_epmpsize
//
// Reads EPMPSIZE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_read_epmpsize(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return basePointer->EPMPSIZE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_set_in_max_packet_size
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_set_in_max_packet_size(
   SI32_USBEP_A_Type * basePointer,
   // Sets size in increments of 8, and a value of 128 is interpreted as
   // 1023 bytes.
   uint32_t size)
{
   assert(size < 256);   // size < 2^8
   //{{
   basePointer->EPMPSIZE.IMAXP = size;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_get_in_max_packet_size
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_get_in_max_packet_size(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (uint32_t) (basePointer->EPMPSIZE.IMAXP);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_set_out_max_packet_size
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_set_out_max_packet_size(
   SI32_USBEP_A_Type * basePointer,
   // Sets size in increments of 8, and a value of 128 is interpreted as
   // 1023 bytes.
   uint32_t size)
{
   assert(size < 256);   // size < 2^8
   //{{
   basePointer->EPMPSIZE.OMAXP = size;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_get_out_max_packet_size
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_get_out_max_packet_size(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (uint32_t) (basePointer->EPMPSIZE.OMAXP);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_write_epcontrol
//
// Writes to EPCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_write_epcontrol(
   SI32_USBEP_A_Type * basePointer,
   uint32_t epcontrol)
{
   //{{
   basePointer->EPCONTROL.U32 = epcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_read_epcontrol
//
// Read EPCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_read_epcontrol(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return basePointer->EPCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_set_in_packet_ready
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_set_in_packet_ready(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IPRDYI_SET_U32);                                
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_is_in_fifo_empty
//
// Returns TRUE if FIFO empty, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_is_in_fifo_empty(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool) !(basePointer->EPCONTROL.IFIFONEF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_clear_in_data_underrun
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_clear_in_data_underrun(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32  = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_IURF_MASK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_is_in_data_underrun_set
//
// In Isochronous mode, True indicates a zero length packet sent after an
// IN.  In Interrupt/Bulk mode, True indicates a NAK sent in response to
// an IN token.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_is_in_data_underrun_set(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->EPCONTROL.IURF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_flush_in_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_flush_in_fifo(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IFIFOFL_SET_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_send_in_stall
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_send_in_stall(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ISDSTL_SET_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_stop_in_stall
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_stop_in_stall(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ISDSTL_NOT_SET_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_is_in_stall_sent
//
// Returns TRUE if stall transmitted, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_is_in_stall_sent(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool) (basePointer->EPCONTROL.ISTSTLI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_clear_in_stall_sent
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_clear_in_stall_sent(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ISTSTLI_NOT_SET_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_reset_in_data_toggle
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_reset_in_data_toggle(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
  basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ICLRDT_RESET_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_split_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_split_mode(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_SPLITEN_ENABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_disable_split_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_disable_split_mode(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_SPLITEN_DISABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_select_data_toggle_on_ack
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_select_data_toggle_on_ack(
   SI32_USBEP_A_Type * basePointer)
{
   //{{ 
   basePointer->EPCONTROL.FDTEN = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_FDTEN_DISABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_select_data_toggle_on_packet
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_select_data_toggle_on_packet(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_FDTEN_ENABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_in_dma
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_in_dma(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IDMAEN_ENABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_disable_in_dma
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_disable_in_dma(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IDMAEN_DISABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_set_endpoint_direction_in
//
// Only valid when endpoint not configured for SPLIT mode.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_set_endpoint_direction_in(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_DIRSEL_IN_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_set_endpoint_direction_out
//
// Only valid when endpoint not configured for SPLIT mode.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_set_endpoint_direction_out(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_DIRSEL_OUT_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_select_in_bulk_interrupt_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_select_in_bulk_interrupt_mode(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IISOEN_BULK_INT_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_select_in_isochronous_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_select_in_isochronous_mode(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IISOEN_ISO_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_inprdy_auto_set
//
// Allows In Packet Ready Bit (INPRDY) to be automatically set by
// hardware.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_inprdy_auto_set(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_AUTOSETEN_ENABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_disable_inprdy_auto_set
//
// Prevents In Packet Ready Bit (INPRDY) from being automatically set by
// hardware.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_disable_inprdy_auto_set(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
  basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_AUTOSETEN_DISABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_clear_outpacket_ready
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_clear_outpacket_ready(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_OPRDYI_MASK);  
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_is_outpacket_ready
//
// Returns TRUE if OPRDY is set, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_is_outpacket_ready(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->EPCONTROL.OPRDYI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_is_out_fifo_full
//
// Returns TRUE if FIFO is full, otherwise returns FALSE.  If double
// buffering is enabled, FIFO is full when FIFO contains two packets.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_is_out_fifo_full(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->EPCONTROL.OFIFOFF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_clear_out_data_overrun
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_clear_out_data_overrun(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_OORF_MASK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_has_out_data_overrun_occurred
//
// Returns TRUE if data packets lost due to FIFO overrun, otherwise
// returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_has_out_data_overrun_occurred(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool) (basePointer->EPCONTROL.OORF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_has_out_data_error_set_occurred
//
// Returns TRUE if CRC or bit error occurred, otherwise returns FALSE.
// Only valid in isochronous mode.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_has_out_data_error_set_occurred(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool) (basePointer->EPCONTROL.ODERRF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_flush_out_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_flush_out_fifo(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OFIFOFL_SET_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_send_out_stall
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_send_out_stall(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OSDSTL_SEND_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_stop_out_stall
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_stop_out_stall(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OSDSTL_STOP_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_is_out_stall_sent
//
// Returns TRUE if stall transmitted, otherwise returns false;.
//-----------------------------------------------------------------------------
bool
_SI32_USBEP_A_is_out_stall_sent(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return (bool) (basePointer->EPCONTROL.OSTSTLI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_clear_out_stall_sent
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_clear_out_stall_sent(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_OSTSTLI_MASK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_reset_out_data_toggle
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_reset_out_data_toggle(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OCLRDT_RESET_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_out_dma_for_last_packet
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_out_dma_for_last_packet(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
  basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ODMAMD_NO_DMA_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_disable_out_dma_for_last_packet
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_disable_out_dma_for_last_packet(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
  basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ODMAMD_AUTO_DMA_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_out_dma
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_out_dma(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
  basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ODMAEN_ENABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_disable_out_dma
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_disable_out_dma(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
  basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ODMAEN_DISABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_out_bulk_interrupt_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_out_bulk_interrupt_mode(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OISOEN_BULK_INT_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_out_isochronous_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_out_isochronous_mode(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OISOEN_ISO_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_enable_oprdy_auto_clear
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_enable_oprdy_auto_clear(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_AUTOCLREN_ENABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_disable_oprdy_auto_clear
//
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_disable_oprdy_auto_clear(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_AUTOCLREN_DISABLED_U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_read_data_count
//
// Reads number of data bytes in the last received packet in the OUT
// FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_read_data_count(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return basePointer->EPCOUNT.COUNT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_write_fifo_u32
//
// Write a full word to the USB FIFO.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_write_fifo_u32(
   SI32_USBEP_A_Type * basePointer,
   uint32_t dataval)
{
   //{{
   basePointer->EPFIFO.U32 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_write_fifo_u16
//
// Write the least-significant 2 bytes to the USB FIFO.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_write_fifo_u16(
   SI32_USBEP_A_Type * basePointer,
   uint32_t dataval)
{
   //{{
   basePointer->EPFIFO.U16 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_write_fifo_u8
//
// Write the least significant byte of data to the USB FIFO.
//-----------------------------------------------------------------------------
void
_SI32_USBEP_A_write_fifo_u8(
   SI32_USBEP_A_Type * basePointer,
   uint32_t dataval)
{
   //{{
   basePointer->EPFIFO.U8 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_read_fifo_u32
//
// Reads full word from FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_read_fifo_u32(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return basePointer->EPFIFO.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_read_fifo_u16
//
// Reads half word from FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_read_fifo_u16(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return basePointer->EPFIFO.U16;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USBEP_A_read_fifo_u8
//
// Reads byte from FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USBEP_A_read_fifo_u8(
   SI32_USBEP_A_Type * basePointer)
{
   //{{
   return basePointer->EPFIFO.U8;
   //}}
}


  //-eof--------------------------------------------------------------------------
