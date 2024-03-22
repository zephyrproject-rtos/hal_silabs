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
/// @file SI32_I2S_A_Type.c
//
// Script: 0.58
// HAL Source: 0.1
// Version: 7

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_I2S_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_I2S_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_initialize(
   SI32_I2S_A_Type * basePointer,
   // TXCONTROL register.
   uint32_t txcontrol,
   // TXMODE register.
   uint32_t txmode,
   // FSDUTY register.
   uint32_t fsduty,
   // RXCONTROL register.
   uint32_t rxcontrol,
   // RXMODE register.
   uint32_t rxmode,
   // CLKCONTROL register.
   uint32_t clkcontrol,
   // FIFOCONTROL register.
   uint32_t fifocontrol,
   // INTCONTROL register.
   uint32_t intcontrol,
   // DMACONTROL register.
   uint32_t dmacontrol,
   // DBGCONTROL register.
   uint32_t dbgcontrol)
{
   //{{
   basePointer->TXCONTROL.U32   = txcontrol;
   basePointer->TXMODE.U32      = txmode;
   basePointer->FSDUTY.U32      = fsduty;
   basePointer->RXCONTROL.U32   = rxcontrol;
   basePointer->RXMODE.U32      = rxmode;
   basePointer->CLKCONTROL.U32  = clkcontrol;
   basePointer->FIFOCONTROL.U32 = fifocontrol;
   basePointer->INTCONTROL.U32  = intcontrol;
   basePointer->DMACONTROL.U32  = dmacontrol;
   basePointer->DBGCONTROL.U32  = dbgcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_txcontrol
//
// Reads TXCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_txcontrol(
   SI32_I2S_A_Type * basePointer)
{
   //{{
  return basePointer->TXCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_txcontrol
//
// Writes to TXCONTRL register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_txcontrol(
   SI32_I2S_A_Type * basePointer,
   uint32_t txcontrol)
{
   //{{
   basePointer->TXCONTROL.U32   = txcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_frame_sync
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_frame_sync(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_frame_sync
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_frame_sync(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_frame_sync_synchronize
//
// Configures DFS to sync with external signal.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_frame_sync_synchronize(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_frame_sync_immediate
//
// Configures DFS to not sync with external signal.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_frame_sync_immediate(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_data_first_rising_edge
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_data_first_rising_edge(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_DDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_data_nth_rising_edge
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_data_nth_rising_edge(
   SI32_I2S_A_Type * basePointer,
   // Number of cycles (n) to delay data capture.
   uint32_t cycles_delay)
{
   assert((cycles_delay >= 2) && (cycles_delay <= 257));
   //{{

   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSDEL_MASK;
   basePointer->TXCONTROL_SET = (cycles_delay-2) << SI32_I2S_A_TXCONTROL_FSDEL_SHIFT;
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_DDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_unused_data_fill_zeros
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_unused_data_fill_zeros(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FILLSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_unused_data_fill_ones
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_unused_data_fill_ones(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FILLSEL_MASK;
   basePointer->TXCONTROL_SET = 0x1 << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_unused_data_fill_sign
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_unused_data_fill_sign(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FILLSEL_MASK;
   basePointer->TXCONTROL_SET = 0x2 << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_unused_data_fill_random
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_unused_data_fill_random(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FILLSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_frame_sync_as_external_pin
//
// Selects an external signal as frame sync source.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_frame_sync_as_external_pin(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSSRCSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_frame_sync_as_internal_generator
//
// Selects the internal generater as frame sync source.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_frame_sync_as_internal_generator(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSSRCSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_right_justified_data
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_right_justified_data(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_JSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_left_justified_data
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_left_justified_data(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_JSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_frame_sync_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_frame_sync_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_frame_sync_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_frame_sync_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_clock_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_clock_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_SCLKINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_clock_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_clock_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_SCLKINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_left_channel_first
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_left_channel_first(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_ORDER_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_right_channel_first
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_right_channel_first(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_ORDER_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_8bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_8bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_9bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_9bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;
   basePointer->TXCONTROL_SET = 0x1 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_16bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_16bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;
   basePointer->TXCONTROL_SET = 0x2 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_24bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_24bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;
   basePointer->TXCONTROL_SET = 0x3 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_32bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_32bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;
   basePointer->TXCONTROL_SET = 0x4 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_TXEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_TXEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_txmode
//
// Reads TXMODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_txmode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->TXMODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_txmode
//
// Write to TXMODE register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_txmode(
   SI32_I2S_A_Type * basePointer,
   uint32_t txmode)
{
   //{{
   basePointer->TXMODE.U32      = txmode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_set_tx_tdm_slots
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_set_tx_tdm_slots(
   SI32_I2S_A_Type * basePointer,
   // Bits per slot.
   uint32_t number_bits,
   // First slot in which to send data.
   uwide8_t slot_number,
   // Number of slots for which to send data.
   uint32_t length)
{
   assert((number_bits >= 1) && (number_bits <= 4096));
   assert(slot_number < 256);   // slot_number < 2^8
   assert((length >= 1) && (length <= 32));
   //{{

   basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_CYCLE_MASK
                             | SI32_I2S_A_TXMODE_START_MASK
                             | SI32_I2S_A_TXMODE_SLOTS_MASK;

   basePointer->TXMODE_SET = ((number_bits-1) << SI32_I2S_A_TXMODE_CYCLE_SHIFT)
                             | ((slot_number-1) << SI32_I2S_A_TXMODE_START_SHIFT)
                             | ((length-1) << SI32_I2S_A_TXMODE_SLOTS_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_last_bit_drive
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_last_bit_drive(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_DEDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_last_bit_hiz
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_last_bit_hiz(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXMODE_SET = SI32_I2S_A_TXMODE_DEDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_unselected_bits_drive_zero
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_unselected_bits_drive_zero(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_DIMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_unselected_bits_hiz
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_unselected_bits_hiz(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXMODE_SET = SI32_I2S_A_TXMODE_DIMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_tdm
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_tdm(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXMODE_SET = SI32_I2S_A_TXMODE_TDMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_tdm
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_tdm(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_TDMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_fsduty
//
// Reads FSDUTY register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_fsduty(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->FSDUTY.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_fsduty
//
// Writes to FSDUTY register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_fsduty(
   SI32_I2S_A_Type * basePointer,
   uint32_t fsduty)
{
   //{{
   basePointer->FSDUTY.U32 = fsduty;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_set_frame_sync_duty_cycle
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_set_frame_sync_duty_cycle(
   SI32_I2S_A_Type * basePointer,
   // Clock cycles for low phase.
   uwide16_t low_cycles,
   // Clock cycles for high phase.
   uwide16_t high_cycles)
{
   assert(low_cycles < 65536);   // low_cycles < 2^16
   assert(high_cycles < 65536);   // high_cycles < 2^16
   //{{
   // NO SET/CLR AVALIABLE
   basePointer->FSDUTY.FSLOW = low_cycles-1;
   basePointer->FSDUTY.FSHIGH = high_cycles-1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_rxcontrol
//
// Reads RXCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_rxcontrol(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->RXCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_rxcontrol
//
// Writes to RXCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_rxcontrol(
   SI32_I2S_A_Type * basePointer,
   uint32_t rxcontrol)
{
   //{{
   basePointer->RXCONTROL.U32   = rxcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_data_first_rising_edge
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_data_first_rising_edge(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_DDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_data_nth_rising_edge
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_data_nth_rising_edge(
   SI32_I2S_A_Type * basePointer,
   // Number of cycles (n) to delay data capture.
   uint32_t cycles_delay)
{
   assert((cycles_delay >= 2) && (cycles_delay <= 257));
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_FSDEL_MASK;
   basePointer->RXCONTROL_SET = cycles_delay-2;
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_DDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_right_justified_data
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_right_justified_data(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_JSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_left_justified_data
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_left_justified_data(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_JSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_frame_sync_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_frame_sync_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_FSINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_frame_sync_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_frame_sync_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_FSINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_clock_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_clock_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_SCLKINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_clock_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_clock_inversion(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_SCLKINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_left_channel_first
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_left_channel_first(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_ORDER_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_right_channel_first
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_right_channel_first(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_ORDER_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_8bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_8bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_9bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_9bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;
   basePointer->RXCONTROL_SET = 0x1 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_16bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_16bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;
   basePointer->RXCONTROL_SET = 0x2 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_24bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_24bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;
   basePointer->RXCONTROL_SET = 0x3 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_32bits_per_mono_sample
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_32bits_per_mono_sample(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;
   basePointer->RXCONTROL_SET = 0x4 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_frame_sync_as_external_pin
//
// Selectcs an external signal as the framc sync source.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_frame_sync_as_external_pin(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_FSSRCSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_frame_sync_as_internal_generator
//
// Selects the internal generator as the fram sync source.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_frame_sync_as_internal_generator(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_FSSRCSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_RXEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_RXEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_rxmode
//
// Reads RXMODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_rxmode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->RXMODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_rxmode
//
// Writes to RXMODE register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_rxmode(
   SI32_I2S_A_Type * basePointer,
   uint32_t rxmode)
{
   //{{
   basePointer->RXMODE.U32      = rxmode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_set_rx_tdm_slots
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_set_rx_tdm_slots(
   SI32_I2S_A_Type * basePointer,
   // Bits per slot.
   uint32_t number_bits,
   // First slot in which to receive data.
   uwide8_t slot_number,
   // Number of slots for which to send data.
   uint32_t length)
{
   assert((number_bits >= 1) && (number_bits <= 4096));
   assert(slot_number < 256);   // slot_number < 2^8
   assert((length >= 1) && (length <= 32));
   //{{
   basePointer->RXMODE_CLR = SI32_I2S_A_RXMODE_CYCLE_MASK
                             | SI32_I2S_A_RXMODE_START_MASK
                             | SI32_I2S_A_RXMODE_SLOTS_MASK;

   basePointer->RXMODE_SET = ((number_bits-1) << SI32_I2S_A_RXMODE_CYCLE_SHIFT)
                             | ((slot_number-1) << SI32_I2S_A_RXMODE_START_SHIFT)
                             | ((length-1) << SI32_I2S_A_RXMODE_SLOTS_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_tdm
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_tdm(
   SI32_I2S_A_Type * basePointer)
{
   //{{
    basePointer->RXMODE_SET = SI32_I2S_A_RXMODE_TDMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_tdm
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_tdm(
   SI32_I2S_A_Type * basePointer)
{
   //{{
    basePointer->RXMODE_CLR = SI32_I2S_A_RXMODE_TDMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_clkcontrol
//
// Reads CLKCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_clkcontrol(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->CLKCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_clkcontrol
//
// Writes to CLKCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_clkcontrol(
   SI32_I2S_A_Type * basePointer,
   uint32_t clkcontrol)
{
   //{{
   basePointer->CLKCONTROL.U32  = clkcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_set_clock_divider
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_set_clock_divider(
   SI32_I2S_A_Type * basePointer,
   // Integer portion of clock divider.
   uint32_t integer,
   // Fractional portion of clock divider.
   uwide8_t fractional)
{
   assert((integer >= 1) && (integer <= 1023));
   assert(fractional < 256);   // fractional < 2^8
   //{{
   basePointer->CLKCONTROL_CLR = SI32_I2S_A_CLKCONTROL_INTDIV_MASK
                                | SI32_I2S_A_CLKCONTROL_FRACDIV_MASK;
   basePointer->CLKCONTROL_SET = (integer << SI32_I2S_A_CLKCONTROL_INTDIV_SHIFT)
                                  |(fractional << SI32_I2S_A_CLKCONTROL_FRACDIV_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_extend_high_cycle
//
// Make high phase of clock wider if dudy cycle not even.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_extend_high_cycle(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_DUTYMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_extend_low_cycle
//
// Make low phase of clock wider if duty cycle not even.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_extend_low_cycle(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_DUTYMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_clock_divider
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_clock_divider(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_DIVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_clock_divider
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_clock_divider(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_DIVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_update_clock_divider
//
// Initiates an update of the clock divider, applying new settings and
// refreshing the status.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_update_clock_divider(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_CLKUPD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_clock_source_as_divider_out
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_clock_source_as_divider_out(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_TXCLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_clock_source_as_pin_in
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_clock_source_as_pin_in(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_TXCLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_clock_source_as_divider_out
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_clock_source_as_divider_out(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_RXCLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_clock_source_as_pin_in
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_clock_source_as_pin_in(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RXCLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_reset_divider
//
// Reset I2S block divider.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_reset_divider(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RESET_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_start_rx_clock
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_start_rx_clock(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RXCLKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_stop_rx_clock
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_stop_rx_clock(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_RXCLKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_start_tx_clock
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_start_tx_clock(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_TXCLKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_stop_tx_clock
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_stop_tx_clock(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_TXCLKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_dclk_pin_as_output
//
// Set rx DCLK pin to output mode.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_dclk_pin_as_output(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_RXSCLKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_dclk_pin_as_input
//
// Set rx DCLK pin to input mode.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_dclk_pin_as_input(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RXSCLKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_dclk_pin_as_output
//
// Set tx DCLK pin to output mode.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_dclk_pin_as_output(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_TXSCLKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_dclk_pin_as_input
//
// Set tx DCLK pin to input mode.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_dclk_pin_as_input(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_TXSCLKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_fifocontrol
//
// Reads FIFOCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_fifocontrol(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->FIFOCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_fifocontrol
//
// Writes to FIFOCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_fifocontrol(
   SI32_I2S_A_Type * basePointer,
   uint32_t fifocontrol)
{
   //{{
   basePointer->FIFOCONTROL.U32 = fifocontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_set_fifo_watermarks
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_set_fifo_watermarks(
   SI32_I2S_A_Type * basePointer,
   // Transmit FIFO depth.
   uint32_t tx_watermark,
   // Receive FIFO depth.
   uint32_t rx_watermark)
{
   assert(tx_watermark < 16);   // tx_watermark < 2^4
   assert(rx_watermark < 16);   // rx_watermark < 2^4
   //{{
   basePointer->FIFOCONTROL_CLR = SI32_I2S_A_FIFOCONTROL_TXFIFOWM_MASK
                                  | SI32_I2S_A_FIFOCONTROL_RXFIFOWM_MASK;

   basePointer->FIFOCONTROL_SET =  tx_watermark
                                   | (rx_watermark << SI32_I2S_A_FIFOCONTROL_RXFIFOWM_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_flush_tx_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_flush_tx_fifo(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->FIFOCONTROL_SET = SI32_I2S_A_FIFOCONTROL_TXFIFOFL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_flush_rx_fifo
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_flush_rx_fifo(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->FIFOCONTROL_SET = SI32_I2S_A_FIFOCONTROL_RXFIFOFL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_intcontrol
//
// Reads INTCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_intcontrol(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->INTCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_intcontrol
//
// Writes to INTCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_intcontrol(
   SI32_I2S_A_Type * basePointer,
   uint32_t intcontrol)
{
   //{{
   basePointer->INTCONTROL.U32  = intcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_fifo_underflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_fifo_underflow_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
  basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_TXUFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_fifo_underflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_fifo_underflow_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_TXUFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_tx_fifo_underflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_tx_fifo_underflow_interrupt_enabled(
   SI32_I2S_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->INTCONTROL.TXUFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_fifo_watermark_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_fifo_watermark_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_TXLWMIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_fifo_watermark_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_fifo_watermark_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_TXLWMIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_tx_fifo_watermark_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_tx_fifo_watermark_interrupt_enabled(
   SI32_I2S_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->INTCONTROL.TXLWMIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_fifo_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_fifo_overflow_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_RXOFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_fifo_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_fifo_overflow_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_RXOFIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_rx_fifo_overflow_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_rx_fifo_overflow_interrupt_enabled(
   SI32_I2S_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->INTCONTROL.RXOFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_fifo_watermark_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_fifo_watermark_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
  basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_RXHWMIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_fifo_watermark_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_fifo_watermark_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_RXHWMIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_rx_fifo_watermark_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_rx_fifo_watermark_interrupt_enabled(
   SI32_I2S_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->INTCONTROL.RXHWMIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_dmacontrol
//
// Reads DMACONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_dmacontrol(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->DMACONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_dmacontrol
//
// Writes to DMACONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_dmacontrol(
   SI32_I2S_A_Type * basePointer,
   uint32_t dmacontrol)
{
   //{{
   basePointer->DMACONTROL.U32  = dmacontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_dma_channel
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_dma_channel(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_TXDMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_dma_channel
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_dma_channel(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_TXDMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_dma_channel
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_dma_channel(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_RXDMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_dma_channel
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_dma_channel(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_RXDMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_dma_single_word_transfer
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_dma_single_word_transfer(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_TXDMABMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_tx_dma_four_word_transfer
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_tx_dma_four_word_transfer(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_TXDMABMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_dma_single_word_transfer
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_dma_single_word_transfer(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_RXDMABMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_select_rx_dma_four_word_transfer
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_select_rx_dma_four_word_transfer(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_RXDMABMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_dbgcontrol
//
// Reads DBGCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_dbgcontrol(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->DBGCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_dbgcontrol
//
// Writes to DBGCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_dbgcontrol(
   SI32_I2S_A_Type * basePointer,
   uint32_t dbgcontrol)
{
   //{{
   basePointer->DBGCONTROL.U32  = dbgcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_clock_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_clock_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_TXDBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_clock_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_clock_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_TXDBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_clock_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_clock_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_RXDBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_clock_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_clock_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_RXDBGMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_tx_dma_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_tx_dma_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_TXDBGHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_tx_dma_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_tx_dma_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_TXDBGHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_enable_rx_dma_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_enable_rx_dma_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_RXDBGHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_disable_rx_dma_stall_in_debug_mode
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_disable_rx_dma_stall_in_debug_mode(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_RXDBGHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_tx_fifo_underflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_tx_fifo_underflow_interrupt_pending(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.TXUFI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_rx_fifo_overflow_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_rx_fifo_overflow_interrupt_pending(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.RXOFI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_tx_fifo_watermark_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_tx_fifo_watermark_interrupt_pending(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.TXLWMI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_rx_fifo_watermark_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_rx_fifo_watermark_interrupt_pending(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.RXHWMI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_clear_tx_fifo_underflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_clear_tx_fifo_underflow_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_I2S_A_STATUS_TXUFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_clear_rx_fifo_overflow_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_clear_rx_fifo_overflow_interrupt(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_I2S_A_STATUS_RXOFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_any_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_any_interrupt_pending(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.U32
                 & (SI32_I2S_A_STATUS_TXUFI_MASK
 	                | SI32_I2S_A_STATUS_RXOFI_MASK
 	                | SI32_I2S_A_STATUS_TXLWMI_MASK
                    | SI32_I2S_A_STATUS_RXHWMI_MASK));
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_clear_all_interrupts
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_clear_all_interrupts(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = (SI32_I2S_A_STATUS_TXUFI_MASK
	                           | SI32_I2S_A_STATUS_RXOFI_MASK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_divider_update_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_divider_update_pending(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.CDBUSYF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_counter_stopped
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_counter_stopped(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.CDSTS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_tx_extclock_synchronized
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_tx_extclock_synchronized(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.TXCLKSELRF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_rx_extclock_synchronized
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_rx_extclock_synchronized(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.RXCLKSELRF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_tx_clock_synchronized
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_tx_clock_synchronized(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.TXCLKENRF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_is_rx_clock_synchronized
//
//-----------------------------------------------------------------------------
bool
_SI32_I2S_A_is_rx_clock_synchronized(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.RXCLKENRF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_get_tx_fifo_count
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_get_tx_fifo_count(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->FIFOSTATUS.TXFIFONUM;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_get_rx_fifo_count
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_get_rx_fifo_count(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->FIFOSTATUS.RXFIFONUM;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_write_tx_fifo_u32
//
//-----------------------------------------------------------------------------
void
_SI32_I2S_A_write_tx_fifo_u32(
   SI32_I2S_A_Type * basePointer,
   uint32_t data_out)
{
   //{{
   basePointer->TXFIFO.U32 = data_out;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_I2S_A_read_rx_fifo_u32
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_I2S_A_read_rx_fifo_u32(
   SI32_I2S_A_Type * basePointer)
{
   //{{
   return basePointer->RXFIFO.U32;
   //}}
}


//-eof--------------------------------------------------------------------------
