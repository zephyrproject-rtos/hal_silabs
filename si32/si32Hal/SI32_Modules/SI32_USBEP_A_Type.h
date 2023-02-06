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
/// @file SI32_USBEP_A_Type.h
//
// Script: 0.58
// HAL Source: 0.5
// Version: 1

#ifndef __SI32_USBEP_A_TYPE_H__
#define __SI32_USBEP_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_USBEP_A_Registers.h"

#define SI32_USBEP_A_EPCONTROL_ALWAYS_SET_ON_WRITE_MASK \
  ( SI32_USBEP_A_EPCONTROL_OPRDYI_SET_U32 |      \
    SI32_USBEP_A_EPCONTROL_OSTSTLI_SET_U32 |     \
    SI32_USBEP_A_EPCONTROL_OORF_SET_U32 |      \
    SI32_USBEP_A_EPCONTROL_ISTSTLI_SET_U32 |     \
    SI32_USBEP_A_EPCONTROL_IURF_SET_U32 )    

#define SI32_USBEP_A_EPCONTROL_ALWAYS_CLEAR_ON_WRITE_MASK   \
    ( SI32_USBEP_A_EPCONTROL_IFIFOFL_SET_VALUE | \
      SI32_USBEP_A_EPCONTROL_OFIFOFL_SET_VALUE ) \

#define USBEP_EPCONTROL_WRITE(basePointer, _U32) ( (_U32) | (basePointer->EPCONTROL.U32|SI32_USBEP_A_EPCONTROL_ALWAYS_SET_ON_WRITE_MASK)) 
#define USBEP_EPCONTROL_CLEAR_MASK( basePointer, _MASK) ( USBEP_EPCONTROL_WRITE(basePointer, 0)&(~(_MASK)))
#define USBEP_EPCONTROL_SET_MASK( basePointer, _MASK) ( USBEP_EPCONTROL_WRITE(basePointer, 0)|(_MASK) )


#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_USBEP_A_initialize(SI32_USBEP_A_Type* basePointer,
///      uint32_t epmpsize,
///      uint32_t epcontrol)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  epmpsize
///  Valid range is 32 bits.
///  Write to EPMPSIZE register.
///
/// @param[in]
///  epcontrol
///  Valid range is 32 bits.
///  Write to EPCONTROL register.
///
void
_SI32_USBEP_A_initialize(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t, /*epmpsize*/
   uint32_t /*epcontrol*/);
///
/// @def SI32_USBEP_A_initialize(basePointer, epmpsize, epcontrol)
#define SI32_USBEP_A_initialize(basePointer, epmpsize, epcontrol) do{  \
   basePointer->EPMPSIZE.U32 = epmpsize;\
   basePointer->EPCONTROL.U32 = epcontrol;\
} while(0)


/// @fn _SI32_USBEP_A_write_epmpsize(SI32_USBEP_A_Type* basePointer,
///      uint32_t epmpsize)
///
/// @brief
/// Writes to EPMPSIZE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  epmpsize
///  Valid range is 32 bits.
///
void
_SI32_USBEP_A_write_epmpsize(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t /*epmpsize*/);
///
/// @def SI32_USBEP_A_write_epmpsize(basePointer, epmpsize)
#define SI32_USBEP_A_write_epmpsize(basePointer, epmpsize) \
   (basePointer->EPMPSIZE.U32 = epmpsize)


/// @fn _SI32_USBEP_A_read_epmpsize(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Reads EPMPSIZE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_read_epmpsize(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_read_epmpsize(basePointer)
#define SI32_USBEP_A_read_epmpsize(basePointer) \
(basePointer->EPMPSIZE.U32)


/// @fn _SI32_USBEP_A_set_in_max_packet_size(SI32_USBEP_A_Type* basePointer,
///      uint32_t size)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  size
///  Valid range is 8 bits.
///  Sets size in increments of 8, and a value of 128 is interpreted as
///  1023 bytes.
///
void
_SI32_USBEP_A_set_in_max_packet_size(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t /*size*/);
///
/// @def SI32_USBEP_A_set_in_max_packet_size(basePointer, size)
#define SI32_USBEP_A_set_in_max_packet_size(basePointer, size) \
   (basePointer->EPMPSIZE.IMAXP = size)


/// @fn _SI32_USBEP_A_get_in_max_packet_size(SI32_USBEP_A_Type* basePointer)
///
/// @return
///  Return size which is IMAXP bits * 8 if IMAXP < 128, or 1023 bytes if
///  IMAXP = 128.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_get_in_max_packet_size(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_get_in_max_packet_size(basePointer)
#define SI32_USBEP_A_get_in_max_packet_size(basePointer) \
((uint32_t) (basePointer->EPMPSIZE.IMAXP))


/// @fn _SI32_USBEP_A_set_out_max_packet_size(SI32_USBEP_A_Type* basePointer,
///      uint32_t size)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  size
///  Valid range is 8 bits.
///  Sets size in increments of 8, and a value of 128 is interpreted as
///  1023 bytes.
///
void
_SI32_USBEP_A_set_out_max_packet_size(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t /*size*/);
///
/// @def SI32_USBEP_A_set_out_max_packet_size(basePointer, size)
#define SI32_USBEP_A_set_out_max_packet_size(basePointer, size) \
   (basePointer->EPMPSIZE.OMAXP = size)


/// @fn _SI32_USBEP_A_get_out_max_packet_size(SI32_USBEP_A_Type* basePointer)
///
/// @return
///  Return size which is OMAXP bits * 8 if OMAXP < 128, or 1023 bytes if
///  OMAXP = 128.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_get_out_max_packet_size(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_get_out_max_packet_size(basePointer)
#define SI32_USBEP_A_get_out_max_packet_size(basePointer) \
((uint32_t) (basePointer->EPMPSIZE.OMAXP))


/// @fn _SI32_USBEP_A_write_epcontrol(SI32_USBEP_A_Type* basePointer,
///      uint32_t epcontrol)
///
/// @brief
/// Writes to EPCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  epcontrol
///  Valid range is 32 bits.
///
void
_SI32_USBEP_A_write_epcontrol(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t /*epcontrol*/);
///
/// @def SI32_USBEP_A_write_epcontrol(basePointer, epcontrol)
#define SI32_USBEP_A_write_epcontrol(basePointer, epcontrol) \
   (basePointer->EPCONTROL.U32 = epcontrol)


/// @fn _SI32_USBEP_A_read_epcontrol(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Read EPCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_read_epcontrol(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_read_epcontrol(basePointer)
#define SI32_USBEP_A_read_epcontrol(basePointer) \
(basePointer->EPCONTROL.U32)


/// @fn _SI32_USBEP_A_set_in_packet_ready(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_set_in_packet_ready(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_set_in_packet_ready(basePointer)
#define SI32_USBEP_A_set_in_packet_ready(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IPRDYI_SET_U32))


/// @fn _SI32_USBEP_A_is_in_fifo_empty(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if FIFO empty, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_is_in_fifo_empty(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_is_in_fifo_empty(basePointer)
#define SI32_USBEP_A_is_in_fifo_empty(basePointer) \
((bool) !(basePointer->EPCONTROL.IFIFONEF))


/// @fn _SI32_USBEP_A_clear_in_data_underrun(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_clear_in_data_underrun(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_clear_in_data_underrun(basePointer)
#define SI32_USBEP_A_clear_in_data_underrun(basePointer) \
   (basePointer->EPCONTROL.U32  = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_IURF_MASK))


/// @fn _SI32_USBEP_A_is_in_data_underrun_set(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// In Isochronous mode, True indicates a zero length packet sent after an
/// IN.  In Interrupt/Bulk mode, True indicates a NAK sent in response to
/// an IN token.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_is_in_data_underrun_set(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_is_in_data_underrun_set(basePointer)
#define SI32_USBEP_A_is_in_data_underrun_set(basePointer) \
((bool)(basePointer->EPCONTROL.IURF))


/// @fn _SI32_USBEP_A_flush_in_fifo(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_flush_in_fifo(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_flush_in_fifo(basePointer)
#define SI32_USBEP_A_flush_in_fifo(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IFIFOFL_SET_U32))  

/// @fn _SI32_USBEP_A_send_in_stall(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_send_in_stall(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_send_in_stall(basePointer)
#define SI32_USBEP_A_send_in_stall(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ISDSTL_SET_U32))


/// @fn _SI32_USBEP_A_stop_in_stall(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_stop_in_stall(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_stop_in_stall(basePointer)
#define SI32_USBEP_A_stop_in_stall(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_ISDSTL_MASK))


/// @fn _SI32_USBEP_A_is_in_stall_sent(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if stall transmitted, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_is_in_stall_sent(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_is_in_stall_sent(basePointer)
#define SI32_USBEP_A_is_in_stall_sent(basePointer) \
((bool) (basePointer->EPCONTROL.ISTSTLI))


/// @fn _SI32_USBEP_A_clear_in_stall_sent(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_clear_in_stall_sent(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_clear_in_stall_sent(basePointer)
#define SI32_USBEP_A_clear_in_stall_sent(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_ISTSTLI_MASK))


/// @fn _SI32_USBEP_A_reset_in_data_toggle(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_reset_in_data_toggle(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_reset_in_data_toggle(basePointer)
#define SI32_USBEP_A_reset_in_data_toggle(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ICLRDT_RESET_U32))


/// @fn _SI32_USBEP_A_enable_split_mode(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_split_mode(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_split_mode(basePointer)
#define SI32_USBEP_A_enable_split_mode(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_SPLITEN_ENABLED_U32))


/// @fn _SI32_USBEP_A_disable_split_mode(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_disable_split_mode(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_disable_split_mode(basePointer)
#define SI32_USBEP_A_disable_split_mode(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_SPLITEN_MASK))

/// @fn _SI32_USBEP_A_select_data_toggle_on_ack(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_select_data_toggle_on_ack(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_select_data_toggle_on_ack(basePointer)
#define SI32_USBEP_A_select_data_toggle_on_ack(basePointer) \
   (basePointer->EPCONTROL.FDTEN = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_FDTEN_MASK))


/// @fn _SI32_USBEP_A_select_data_toggle_on_packet(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_select_data_toggle_on_packet(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_select_data_toggle_on_packet(basePointer)
#define SI32_USBEP_A_select_data_toggle_on_packet(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_FDTEN_ENABLED_U32))


/// @fn _SI32_USBEP_A_enable_in_dma(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_in_dma(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_in_dma(basePointer)
#define SI32_USBEP_A_enable_in_dma(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IDMAEN_ENABLED_U32))


/// @fn _SI32_USBEP_A_disable_in_dma(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_disable_in_dma(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_disable_in_dma(basePointer)
#define SI32_USBEP_A_disable_in_dma(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_IDMAEN_MASK))


/// @fn _SI32_USBEP_A_set_endpoint_direction_in(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Only valid when endpoint not configured for SPLIT mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_set_endpoint_direction_in(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_set_endpoint_direction_in(basePointer)
#define SI32_USBEP_A_set_endpoint_direction_in(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_DIRSEL_IN_U32))


/// @fn _SI32_USBEP_A_set_endpoint_direction_out(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Only valid when endpoint not configured for SPLIT mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_set_endpoint_direction_out(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_set_endpoint_direction_out(basePointer)
#define SI32_USBEP_A_set_endpoint_direction_out(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_DIRSEL_MASK))


/// @fn _SI32_USBEP_A_select_in_bulk_interrupt_mode(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_select_in_bulk_interrupt_mode(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_select_in_bulk_interrupt_mode(basePointer)
#define SI32_USBEP_A_select_in_bulk_interrupt_mode(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_IISOEN_MASK))


/// @fn _SI32_USBEP_A_select_in_isochronous_mode(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_select_in_isochronous_mode(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_select_in_isochronous_mode(basePointer)
#define SI32_USBEP_A_select_in_isochronous_mode(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_IISOEN_ISO_U32))


/// @fn _SI32_USBEP_A_enable_inprdy_auto_set(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Allows In Packet Ready Bit (INPRDY) to be automatically set by
/// hardware.
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_inprdy_auto_set(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_inprdy_auto_set(basePointer)
#define SI32_USBEP_A_enable_inprdy_auto_set(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_AUTOSETEN_ENABLED_U32))


/// @fn _SI32_USBEP_A_disable_inprdy_auto_set(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Prevents In Packet Ready Bit (INPRDY) from being automatically set by
/// hardware.
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_disable_inprdy_auto_set(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_disable_inprdy_auto_set(basePointer)
#define SI32_USBEP_A_disable_inprdy_auto_set(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_AUTOSETEN_MASK))


/// @fn _SI32_USBEP_A_clear_outpacket_ready(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_clear_outpacket_ready(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_clear_outpacket_ready(basePointer)
#define SI32_USBEP_A_clear_outpacket_ready(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_OPRDYI_MASK))


/// @fn _SI32_USBEP_A_is_outpacket_ready(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if OPRDY is set, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_is_outpacket_ready(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_is_outpacket_ready(basePointer)
#define SI32_USBEP_A_is_outpacket_ready(basePointer) \
((bool)(basePointer->EPCONTROL.OPRDYI))


/// @fn _SI32_USBEP_A_is_out_fifo_full(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if FIFO is full, otherwise returns FALSE.  If double
/// buffering is enabled, FIFO is full when FIFO contains two packets.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_is_out_fifo_full(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_is_out_fifo_full(basePointer)
#define SI32_USBEP_A_is_out_fifo_full(basePointer) \
((bool)(basePointer->EPCONTROL.OFIFOFF))


/// @fn _SI32_USBEP_A_clear_out_data_overrun(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_clear_out_data_overrun(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_clear_out_data_overrun(basePointer)
#define SI32_USBEP_A_clear_out_data_overrun(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_OORF_MASK))


/// @fn _SI32_USBEP_A_has_out_data_overrun_occurred(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if data packets lost due to FIFO overrun, otherwise
/// returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_has_out_data_overrun_occurred(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_has_out_data_overrun_occurred(basePointer)
#define SI32_USBEP_A_has_out_data_overrun_occurred(basePointer) \
((bool) (basePointer->EPCONTROL.OORF))


/// @fn _SI32_USBEP_A_has_out_data_error_set_occurred(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if CRC or bit error occurred, otherwise returns FALSE.
/// Only valid in isochronous mode.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_has_out_data_error_set_occurred(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_has_out_data_error_set_occurred(basePointer)
#define SI32_USBEP_A_has_out_data_error_set_occurred(basePointer) \
((bool) (basePointer->EPCONTROL.ODERRF))


/// @fn _SI32_USBEP_A_flush_out_fifo(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_flush_out_fifo(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_flush_out_fifo(basePointer)
#define SI32_USBEP_A_flush_out_fifo(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OFIFOFL_SET_U32))


/// @fn _SI32_USBEP_A_send_out_stall(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_send_out_stall(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_send_out_stall(basePointer)
#define SI32_USBEP_A_send_out_stall(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OSDSTL_SEND_U32))


/// @fn _SI32_USBEP_A_stop_out_stall(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_stop_out_stall(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_stop_out_stall(basePointer)
#define SI32_USBEP_A_stop_out_stall(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_OSDSTL_MASK))


/// @fn _SI32_USBEP_A_is_out_stall_sent(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if stall transmitted, otherwise returns false;.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USBEP_A_is_out_stall_sent(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_is_out_stall_sent(basePointer)
#define SI32_USBEP_A_is_out_stall_sent(basePointer) \
((bool) (basePointer->EPCONTROL.OSTSTLI))


/// @fn _SI32_USBEP_A_clear_out_stall_sent(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_clear_out_stall_sent(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_clear_out_stall_sent(basePointer)
#define SI32_USBEP_A_clear_out_stall_sent(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK( basePointer, SI32_USBEP_A_EPCONTROL_OSTSTLI_MASK))


/// @fn _SI32_USBEP_A_reset_out_data_toggle(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_reset_out_data_toggle(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_reset_out_data_toggle(basePointer)
#define SI32_USBEP_A_reset_out_data_toggle(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OCLRDT_RESET_U32))


/// @fn _SI32_USBEP_A_enable_out_dma_for_last_packet(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_out_dma_for_last_packet(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_out_dma_for_last_packet(basePointer)
#define SI32_USBEP_A_enable_out_dma_for_last_packet(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ODMAMD_NO_DMA_U32))


/// @fn _SI32_USBEP_A_disable_out_dma_for_last_packet(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_disable_out_dma_for_last_packet(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_disable_out_dma_for_last_packet(basePointer)
#define SI32_USBEP_A_disable_out_dma_for_last_packet(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_ODMAMD_MASK))


/// @fn _SI32_USBEP_A_enable_out_dma(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_out_dma(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_out_dma(basePointer)
#define SI32_USBEP_A_enable_out_dma(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_ODMAEN_ENABLED_U32))


/// @fn _SI32_USBEP_A_disable_out_dma(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_disable_out_dma(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_disable_out_dma(basePointer)
#define SI32_USBEP_A_disable_out_dma(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_ODMAEN_MASK))


/// @fn _SI32_USBEP_A_enable_out_bulk_interrupt_mode(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_out_bulk_interrupt_mode(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_out_bulk_interrupt_mode(basePointer)
#define SI32_USBEP_A_enable_out_bulk_interrupt_mode(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_OISOEN_MASK))


/// @fn _SI32_USBEP_A_enable_out_isochronous_mode(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_out_isochronous_mode(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_out_isochronous_mode(basePointer)
#define SI32_USBEP_A_enable_out_isochronous_mode(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_OISOEN_ISO_U32))


/// @fn _SI32_USBEP_A_enable_oprdy_auto_clear(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_enable_oprdy_auto_clear(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_enable_oprdy_auto_clear(basePointer)
#define SI32_USBEP_A_enable_oprdy_auto_clear(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_WRITE(basePointer, SI32_USBEP_A_EPCONTROL_AUTOCLREN_ENABLED_U32))


/// @fn _SI32_USBEP_A_disable_oprdy_auto_clear(SI32_USBEP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USBEP_A_disable_oprdy_auto_clear(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_disable_oprdy_auto_clear(basePointer)
#define SI32_USBEP_A_disable_oprdy_auto_clear(basePointer) \
   (basePointer->EPCONTROL.U32 = USBEP_EPCONTROL_CLEAR_MASK(basePointer, SI32_USBEP_A_EPCONTROL_AUTOCLREN_MASK))


/// @fn _SI32_USBEP_A_read_data_count(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Reads number of data bytes in the last received packet in the OUT
/// FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_read_data_count(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_read_data_count(basePointer)
#define SI32_USBEP_A_read_data_count(basePointer) \
(basePointer->EPCOUNT.COUNT)


/// @fn _SI32_USBEP_A_write_fifo_u32(SI32_USBEP_A_Type* basePointer,
///      uint32_t dataval)
///
/// @brief
/// Write a full word to the USB FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///  Valid range is 32 bits.
///
void
_SI32_USBEP_A_write_fifo_u32(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t /*dataval*/);
///
/// @def SI32_USBEP_A_write_fifo_u32(basePointer, dataval)
#define SI32_USBEP_A_write_fifo_u32(basePointer, dataval) \
   (basePointer->EPFIFO.U32 = dataval)


/// @fn _SI32_USBEP_A_write_fifo_u16(SI32_USBEP_A_Type* basePointer,
///      uint32_t dataval)
///
/// @brief
/// Write the least-significant 2 bytes to the USB FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///  Valid range is 32 bits.
///
void
_SI32_USBEP_A_write_fifo_u16(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t /*dataval*/);
///
/// @def SI32_USBEP_A_write_fifo_u16(basePointer, dataval)
#define SI32_USBEP_A_write_fifo_u16(basePointer, dataval) \
   (basePointer->EPFIFO.U16 = dataval)


/// @fn _SI32_USBEP_A_write_fifo_u8(SI32_USBEP_A_Type* basePointer,
///      uint32_t dataval)
///
/// @brief
/// Write the least significant byte of data to the USB FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///  Valid range is 32 bits.
///
void
_SI32_USBEP_A_write_fifo_u8(SI32_USBEP_A_Type* /*basePointer*/,
   uint32_t /*dataval*/);
///
/// @def SI32_USBEP_A_write_fifo_u8(basePointer, dataval)
#define SI32_USBEP_A_write_fifo_u8(basePointer, dataval) \
   (basePointer->EPFIFO.U8 = dataval)


/// @fn _SI32_USBEP_A_read_fifo_u32(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Reads full word from FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_read_fifo_u32(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_read_fifo_u32(basePointer)
#define SI32_USBEP_A_read_fifo_u32(basePointer) \
(basePointer->EPFIFO.U32)


/// @fn _SI32_USBEP_A_read_fifo_u16(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Reads half word from FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_read_fifo_u16(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_read_fifo_u16(basePointer)
#define SI32_USBEP_A_read_fifo_u16(basePointer) \
(basePointer->EPFIFO.U16)


/// @fn _SI32_USBEP_A_read_fifo_u8(SI32_USBEP_A_Type* basePointer)
///
/// @brief
/// Reads byte from FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USBEP_A_read_fifo_u8(SI32_USBEP_A_Type* /*basePointer*/);
///
/// @def SI32_USBEP_A_read_fifo_u8(basePointer)
#define SI32_USBEP_A_read_fifo_u8(basePointer) \
(basePointer->EPFIFO.U8)



#ifdef __cplusplus
}
#endif

#endif // __SI32_USBEP_A_TYPE_H__

//-eof--------------------------------------------------------------------------
