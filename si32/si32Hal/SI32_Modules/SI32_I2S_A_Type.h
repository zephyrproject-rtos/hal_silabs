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
/// @file SI32_I2S_A_Type.h
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_I2S_A_TYPE_H__
#define __SI32_I2S_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_I2S_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_I2S_A_initialize(SI32_I2S_A_Type* basePointer,
///      uint32_t txcontrol,
///      uint32_t txmode,
///      uint32_t fsduty,
///      uint32_t rxcontrol,
///      uint32_t rxmode,
///      uint32_t clkcontrol,
///      uint32_t fifocontrol,
///      uint32_t intcontrol,
///      uint32_t dmacontrol,
///      uint32_t dbgcontrol)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  txcontrol
///  Valid range is 32 bits.
///  TXCONTROL register.
///
/// @param[in]
///  txmode
///  Valid range is 32 bits.
///  TXMODE register.
///
/// @param[in]
///  fsduty
///  FSDUTY register.
///
/// @param[in]
///  rxcontrol
///  Valid range is 32 bits.
///  RXCONTROL register.
///
/// @param[in]
///  rxmode
///  Valid range is 32 bits.
///  RXMODE register.
///
/// @param[in]
///  clkcontrol
///  Valid range is 32 bits.
///  CLKCONTROL register.
///
/// @param[in]
///  fifocontrol
///  Valid range is 32 bits.
///  FIFOCONTROL register.
///
/// @param[in]
///  intcontrol
///  Valid range is 32 bits.
///  INTCONTROL register.
///
/// @param[in]
///  dmacontrol
///  Valid range is 32 bits.
///  DMACONTROL register.
///
/// @param[in]
///  dbgcontrol
///  Valid range is 32 bits.
///  DBGCONTROL register.
///
void
_SI32_I2S_A_initialize(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t, /*txcontrol*/
   uint32_t, /*txmode*/
   uint32_t, /*fsduty*/
   uint32_t, /*rxcontrol*/
   uint32_t, /*rxmode*/
   uint32_t, /*clkcontrol*/
   uint32_t, /*fifocontrol*/
   uint32_t, /*intcontrol*/
   uint32_t, /*dmacontrol*/
   uint32_t /*dbgcontrol*/);
///
/// @def SI32_I2S_A_initialize(basePointer, txcontrol, txmode, fsduty, rxcontrol, rxmode, clkcontrol, fifocontrol, intcontrol, dmacontrol, dbgcontrol)
#define SI32_I2S_A_initialize(basePointer, txcontrol, txmode, fsduty, rxcontrol, rxmode, clkcontrol, fifocontrol, intcontrol, dmacontrol, dbgcontrol) \
   _SI32_I2S_A_initialize(basePointer, txcontrol, txmode, fsduty, rxcontrol, rxmode, clkcontrol, fifocontrol, intcontrol, dmacontrol, dbgcontrol) 


/// @fn _SI32_I2S_A_read_txcontrol(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads TXCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_txcontrol(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_txcontrol(basePointer)
#define SI32_I2S_A_read_txcontrol(basePointer) \
(basePointer->TXCONTROL.U32)


/// @fn _SI32_I2S_A_write_txcontrol(SI32_I2S_A_Type* basePointer,
///      uint32_t txcontrol)
///
/// @brief
/// Writes to TXCONTRL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  txcontrol
///
void
_SI32_I2S_A_write_txcontrol(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*txcontrol*/);
///
/// @def SI32_I2S_A_write_txcontrol(basePointer, txcontrol)
#define SI32_I2S_A_write_txcontrol(basePointer, txcontrol) \
   (basePointer->TXCONTROL.U32   = txcontrol)


/// @fn _SI32_I2S_A_enable_frame_sync(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_frame_sync(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_frame_sync(basePointer)
#define SI32_I2S_A_enable_frame_sync(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSGEN_MASK)


/// @fn _SI32_I2S_A_disable_frame_sync(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_frame_sync(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_frame_sync(basePointer)
#define SI32_I2S_A_disable_frame_sync(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSGEN_MASK)


/// @fn _SI32_I2S_A_select_tx_frame_sync_synchronize(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Configures DFS to sync with external signal.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_frame_sync_synchronize(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_frame_sync_synchronize(basePointer)
#define SI32_I2S_A_select_tx_frame_sync_synchronize(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSSEN_MASK)


/// @fn _SI32_I2S_A_select_tx_frame_sync_immediate(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Configures DFS to not sync with external signal.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_frame_sync_immediate(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_frame_sync_immediate(basePointer)
#define SI32_I2S_A_select_tx_frame_sync_immediate(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSSEN_MASK)


/// @fn _SI32_I2S_A_select_tx_data_first_rising_edge(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_data_first_rising_edge(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_data_first_rising_edge(basePointer)
#define SI32_I2S_A_select_tx_data_first_rising_edge(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_DDIS_MASK)


/// @fn _SI32_I2S_A_select_tx_data_nth_rising_edge(SI32_I2S_A_Type* basePointer,
///      uint32_t cycles_delay)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  cycles_delay
///  Valid range is 2 to 257.
///  Number of cycles (n) to delay data capture.
///
void
_SI32_I2S_A_select_tx_data_nth_rising_edge(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*cycles_delay*/);
///
/// @def SI32_I2S_A_select_tx_data_nth_rising_edge(basePointer, cycles_delay)
#define SI32_I2S_A_select_tx_data_nth_rising_edge(basePointer, cycles_delay) do{  \
\
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSDEL_MASK;\
   basePointer->TXCONTROL_SET = (cycles_delay-2) << SI32_I2S_A_TXCONTROL_FSDEL_SHIFT;\
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_DDIS_MASK;\
} while(0)


/// @fn _SI32_I2S_A_select_tx_unused_data_fill_zeros(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_unused_data_fill_zeros(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_unused_data_fill_zeros(basePointer)
#define SI32_I2S_A_select_tx_unused_data_fill_zeros(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FILLSEL_MASK)


/// @fn _SI32_I2S_A_select_tx_unused_data_fill_ones(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_unused_data_fill_ones(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_unused_data_fill_ones(basePointer)
#define SI32_I2S_A_select_tx_unused_data_fill_ones(basePointer) do{  \
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FILLSEL_MASK;\
   basePointer->TXCONTROL_SET = 0x1 << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_tx_unused_data_fill_sign(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_unused_data_fill_sign(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_unused_data_fill_sign(basePointer)
#define SI32_I2S_A_select_tx_unused_data_fill_sign(basePointer) do{  \
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FILLSEL_MASK;\
   basePointer->TXCONTROL_SET = 0x2 << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_tx_unused_data_fill_random(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_unused_data_fill_random(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_unused_data_fill_random(basePointer)
#define SI32_I2S_A_select_tx_unused_data_fill_random(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FILLSEL_MASK)


/// @fn _SI32_I2S_A_select_tx_frame_sync_as_external_pin(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Selects an external signal as frame sync source.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_frame_sync_as_external_pin(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_frame_sync_as_external_pin(basePointer)
#define SI32_I2S_A_select_tx_frame_sync_as_external_pin(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSSRCSEL_MASK)


/// @fn _SI32_I2S_A_select_tx_frame_sync_as_internal_generator(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Selects the internal generater as frame sync source.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_frame_sync_as_internal_generator(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_frame_sync_as_internal_generator(basePointer)
#define SI32_I2S_A_select_tx_frame_sync_as_internal_generator(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSSRCSEL_MASK)


/// @fn _SI32_I2S_A_select_tx_right_justified_data(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_right_justified_data(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_right_justified_data(basePointer)
#define SI32_I2S_A_select_tx_right_justified_data(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_JSEL_MASK)


/// @fn _SI32_I2S_A_select_tx_left_justified_data(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_left_justified_data(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_left_justified_data(basePointer)
#define SI32_I2S_A_select_tx_left_justified_data(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_JSEL_MASK)


/// @fn _SI32_I2S_A_enable_tx_frame_sync_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_frame_sync_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_frame_sync_inversion(basePointer)
#define SI32_I2S_A_enable_tx_frame_sync_inversion(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_FSINVEN_MASK)


/// @fn _SI32_I2S_A_disable_tx_frame_sync_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_frame_sync_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_frame_sync_inversion(basePointer)
#define SI32_I2S_A_disable_tx_frame_sync_inversion(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_FSINVEN_MASK)


/// @fn _SI32_I2S_A_enable_tx_clock_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_clock_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_clock_inversion(basePointer)
#define SI32_I2S_A_enable_tx_clock_inversion(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_SCLKINVEN_MASK)


/// @fn _SI32_I2S_A_disable_tx_clock_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_clock_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_clock_inversion(basePointer)
#define SI32_I2S_A_disable_tx_clock_inversion(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_SCLKINVEN_MASK)


/// @fn _SI32_I2S_A_select_tx_left_channel_first(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_left_channel_first(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_left_channel_first(basePointer)
#define SI32_I2S_A_select_tx_left_channel_first(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_ORDER_MASK)


/// @fn _SI32_I2S_A_select_tx_right_channel_first(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_right_channel_first(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_right_channel_first(basePointer)
#define SI32_I2S_A_select_tx_right_channel_first(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_ORDER_MASK)


/// @fn _SI32_I2S_A_select_tx_8bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_8bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_8bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_tx_8bits_per_mono_sample(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK)


/// @fn _SI32_I2S_A_select_tx_9bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_9bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_9bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_tx_9bits_per_mono_sample(basePointer) do{  \
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;\
   basePointer->TXCONTROL_SET = 0x1 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_tx_16bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_16bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_16bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_tx_16bits_per_mono_sample(basePointer) do{  \
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;\
   basePointer->TXCONTROL_SET = 0x2 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_tx_24bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_24bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_24bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_tx_24bits_per_mono_sample(basePointer) do{  \
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;\
   basePointer->TXCONTROL_SET = 0x3 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_tx_32bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_32bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_32bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_tx_32bits_per_mono_sample(basePointer) do{  \
   basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_MBSEL_MASK;\
   basePointer->TXCONTROL_SET = 0x4 <<SI32_I2S_A_TXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_enable_tx(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx(basePointer)
#define SI32_I2S_A_enable_tx(basePointer) \
   (basePointer->TXCONTROL_SET = SI32_I2S_A_TXCONTROL_TXEN_MASK)


/// @fn _SI32_I2S_A_disable_tx(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx(basePointer)
#define SI32_I2S_A_disable_tx(basePointer) \
   (basePointer->TXCONTROL_CLR = SI32_I2S_A_TXCONTROL_TXEN_MASK)


/// @fn _SI32_I2S_A_read_txmode(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads TXMODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_txmode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_txmode(basePointer)
#define SI32_I2S_A_read_txmode(basePointer) \
(basePointer->TXMODE.U32)


/// @fn _SI32_I2S_A_write_txmode(SI32_I2S_A_Type* basePointer,
///      uint32_t txmode)
///
/// @brief
/// Write to TXMODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  txmode
///
void
_SI32_I2S_A_write_txmode(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*txmode*/);
///
/// @def SI32_I2S_A_write_txmode(basePointer, txmode)
#define SI32_I2S_A_write_txmode(basePointer, txmode) \
   (basePointer->TXMODE.U32      = txmode)


/// @fn _SI32_I2S_A_set_tx_tdm_slots(SI32_I2S_A_Type* basePointer,
///      uint32_t number_bits,
///      uwide8_t slot_number,
///      uint32_t length)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  number_bits
///  Valid range is 1 to 4096.
///  Bits per slot.
///
/// @param[in]
///  slot_number
///  Valid range is 8 bits.
///  First slot in which to send data.
///
/// @param[in]
///  length
///  Valid range is 1 to 32.
///  Number of slots for which to send data.
///
void
_SI32_I2S_A_set_tx_tdm_slots(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t, /*number_bits*/
   uwide8_t, /*slot_number*/
   uint32_t /*length*/);
///
/// @def SI32_I2S_A_set_tx_tdm_slots(basePointer, number_bits, slot_number, length)
#define SI32_I2S_A_set_tx_tdm_slots(basePointer, number_bits, slot_number, length) do{  \
\
   basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_CYCLE_MASK\
                             | SI32_I2S_A_TXMODE_START_MASK\
                             | SI32_I2S_A_TXMODE_SLOTS_MASK;\
\
   basePointer->TXMODE_SET = ((number_bits-1) << SI32_I2S_A_TXMODE_CYCLE_SHIFT)\
                             | ((slot_number-1) << SI32_I2S_A_TXMODE_START_SHIFT)\
                             | ((length-1) << SI32_I2S_A_TXMODE_SLOTS_SHIFT);\
} while(0)


/// @fn _SI32_I2S_A_select_tx_last_bit_drive(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_last_bit_drive(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_last_bit_drive(basePointer)
#define SI32_I2S_A_select_tx_last_bit_drive(basePointer) \
   (basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_DEDIS_MASK)


/// @fn _SI32_I2S_A_select_tx_last_bit_hiz(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_last_bit_hiz(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_last_bit_hiz(basePointer)
#define SI32_I2S_A_select_tx_last_bit_hiz(basePointer) \
   (basePointer->TXMODE_SET = SI32_I2S_A_TXMODE_DEDIS_MASK)


/// @fn _SI32_I2S_A_select_tx_unselected_bits_drive_zero(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_unselected_bits_drive_zero(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_unselected_bits_drive_zero(basePointer)
#define SI32_I2S_A_select_tx_unselected_bits_drive_zero(basePointer) \
   (basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_DIMD_MASK)


/// @fn _SI32_I2S_A_select_tx_unselected_bits_hiz(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_unselected_bits_hiz(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_unselected_bits_hiz(basePointer)
#define SI32_I2S_A_select_tx_unselected_bits_hiz(basePointer) \
   (basePointer->TXMODE_SET = SI32_I2S_A_TXMODE_DIMD_MASK)


/// @fn _SI32_I2S_A_enable_tx_tdm(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_tdm(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_tdm(basePointer)
#define SI32_I2S_A_enable_tx_tdm(basePointer) \
   (basePointer->TXMODE_SET = SI32_I2S_A_TXMODE_TDMEN_MASK)


/// @fn _SI32_I2S_A_disable_tx_tdm(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_tdm(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_tdm(basePointer)
#define SI32_I2S_A_disable_tx_tdm(basePointer) \
   (basePointer->TXMODE_CLR = SI32_I2S_A_TXMODE_TDMEN_MASK)


/// @fn _SI32_I2S_A_read_fsduty(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads FSDUTY register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_fsduty(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_fsduty(basePointer)
#define SI32_I2S_A_read_fsduty(basePointer) \
(basePointer->FSDUTY.U32)


/// @fn _SI32_I2S_A_write_fsduty(SI32_I2S_A_Type* basePointer,
///      uint32_t fsduty)
///
/// @brief
/// Writes to FSDUTY register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  fsduty
///
void
_SI32_I2S_A_write_fsduty(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*fsduty*/);
///
/// @def SI32_I2S_A_write_fsduty(basePointer, fsduty)
#define SI32_I2S_A_write_fsduty(basePointer, fsduty) \
   (basePointer->FSDUTY.U32 = fsduty)


/// @fn _SI32_I2S_A_set_frame_sync_duty_cycle(SI32_I2S_A_Type* basePointer,
///      uwide16_t low_cycles,
///      uwide16_t high_cycles)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  low_cycles
///  Valid range is 16 bits.
///  Clock cycles for low phase.
///
/// @param[in]
///  high_cycles
///  Valid range is 16 bits.
///  Clock cycles for high phase.
///
void
_SI32_I2S_A_set_frame_sync_duty_cycle(SI32_I2S_A_Type* /*basePointer*/,
   uwide16_t, /*low_cycles*/
   uwide16_t /*high_cycles*/);
///
/// @def SI32_I2S_A_set_frame_sync_duty_cycle(basePointer, low_cycles, high_cycles)
#define SI32_I2S_A_set_frame_sync_duty_cycle(basePointer, low_cycles, high_cycles) do{  \
      basePointer->FSDUTY.FSLOW = low_cycles-1;\
   basePointer->FSDUTY.FSHIGH = high_cycles-1;\
} while(0)


/// @fn _SI32_I2S_A_read_rxcontrol(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads RXCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_rxcontrol(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_rxcontrol(basePointer)
#define SI32_I2S_A_read_rxcontrol(basePointer) \
(basePointer->RXCONTROL.U32)


/// @fn _SI32_I2S_A_write_rxcontrol(SI32_I2S_A_Type* basePointer,
///      uint32_t rxcontrol)
///
/// @brief
/// Writes to RXCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  rxcontrol
///
void
_SI32_I2S_A_write_rxcontrol(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*rxcontrol*/);
///
/// @def SI32_I2S_A_write_rxcontrol(basePointer, rxcontrol)
#define SI32_I2S_A_write_rxcontrol(basePointer, rxcontrol) \
   (basePointer->RXCONTROL.U32   = rxcontrol)


/// @fn _SI32_I2S_A_select_rx_data_first_rising_edge(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_data_first_rising_edge(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_data_first_rising_edge(basePointer)
#define SI32_I2S_A_select_rx_data_first_rising_edge(basePointer) \
   (basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_DDIS_MASK)


/// @fn _SI32_I2S_A_select_rx_data_nth_rising_edge(SI32_I2S_A_Type* basePointer,
///      uint32_t cycles_delay)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  cycles_delay
///  Valid range is 2 to 257.
///  Number of cycles (n) to delay data capture.
///
void
_SI32_I2S_A_select_rx_data_nth_rising_edge(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*cycles_delay*/);
///
/// @def SI32_I2S_A_select_rx_data_nth_rising_edge(basePointer, cycles_delay)
#define SI32_I2S_A_select_rx_data_nth_rising_edge(basePointer, cycles_delay) do{  \
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_FSDEL_MASK;\
   basePointer->RXCONTROL_SET = cycles_delay-2;\
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_DDIS_MASK;\
} while(0)


/// @fn _SI32_I2S_A_select_rx_right_justified_data(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_right_justified_data(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_right_justified_data(basePointer)
#define SI32_I2S_A_select_rx_right_justified_data(basePointer) \
   (basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_JSEL_MASK)


/// @fn _SI32_I2S_A_select_rx_left_justified_data(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_left_justified_data(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_left_justified_data(basePointer)
#define SI32_I2S_A_select_rx_left_justified_data(basePointer) \
   (basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_JSEL_MASK)


/// @fn _SI32_I2S_A_enable_rx_frame_sync_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_frame_sync_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_frame_sync_inversion(basePointer)
#define SI32_I2S_A_enable_rx_frame_sync_inversion(basePointer) \
   (basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_FSINVEN_MASK)


/// @fn _SI32_I2S_A_disable_rx_frame_sync_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_frame_sync_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_frame_sync_inversion(basePointer)
#define SI32_I2S_A_disable_rx_frame_sync_inversion(basePointer) \
   (basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_FSINVEN_MASK)


/// @fn _SI32_I2S_A_enable_rx_clock_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_clock_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_clock_inversion(basePointer)
#define SI32_I2S_A_enable_rx_clock_inversion(basePointer) \
   (basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_SCLKINVEN_MASK)


/// @fn _SI32_I2S_A_disable_rx_clock_inversion(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_clock_inversion(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_clock_inversion(basePointer)
#define SI32_I2S_A_disable_rx_clock_inversion(basePointer) \
   (basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_SCLKINVEN_MASK)


/// @fn _SI32_I2S_A_select_rx_left_channel_first(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_left_channel_first(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_left_channel_first(basePointer)
#define SI32_I2S_A_select_rx_left_channel_first(basePointer) \
   (basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_ORDER_MASK)


/// @fn _SI32_I2S_A_select_rx_right_channel_first(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_right_channel_first(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_right_channel_first(basePointer)
#define SI32_I2S_A_select_rx_right_channel_first(basePointer) \
   (basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_ORDER_MASK)


/// @fn _SI32_I2S_A_select_rx_8bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_8bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_8bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_rx_8bits_per_mono_sample(basePointer) \
   (basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK)


/// @fn _SI32_I2S_A_select_rx_9bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_9bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_9bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_rx_9bits_per_mono_sample(basePointer) do{  \
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;\
   basePointer->RXCONTROL_SET = 0x1 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_rx_16bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_16bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_16bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_rx_16bits_per_mono_sample(basePointer) do{  \
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;\
   basePointer->RXCONTROL_SET = 0x2 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_rx_24bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_24bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_24bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_rx_24bits_per_mono_sample(basePointer) do{  \
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;\
   basePointer->RXCONTROL_SET = 0x3 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_rx_32bits_per_mono_sample(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_32bits_per_mono_sample(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_32bits_per_mono_sample(basePointer)
#define SI32_I2S_A_select_rx_32bits_per_mono_sample(basePointer) do{  \
   basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_MBSEL_MASK;\
   basePointer->RXCONTROL_SET = 0x4 <<SI32_I2S_A_RXCONTROL_MBSEL_SHIFT;\
} while(0)


/// @fn _SI32_I2S_A_select_rx_frame_sync_as_external_pin(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Selectcs an external signal as the framc sync source.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_frame_sync_as_external_pin(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_frame_sync_as_external_pin(basePointer)
#define SI32_I2S_A_select_rx_frame_sync_as_external_pin(basePointer) \
   (basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_FSSRCSEL_MASK)


/// @fn _SI32_I2S_A_select_rx_frame_sync_as_internal_generator(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Selects the internal generator as the fram sync source.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_frame_sync_as_internal_generator(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_frame_sync_as_internal_generator(basePointer)
#define SI32_I2S_A_select_rx_frame_sync_as_internal_generator(basePointer) \
   (basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_FSSRCSEL_MASK)


/// @fn _SI32_I2S_A_enable_rx(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx(basePointer)
#define SI32_I2S_A_enable_rx(basePointer) \
   (basePointer->RXCONTROL_SET = SI32_I2S_A_RXCONTROL_RXEN_MASK)


/// @fn _SI32_I2S_A_disable_rx(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx(basePointer)
#define SI32_I2S_A_disable_rx(basePointer) \
   (basePointer->RXCONTROL_CLR = SI32_I2S_A_RXCONTROL_RXEN_MASK)


/// @fn _SI32_I2S_A_read_rxmode(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads RXMODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_rxmode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_rxmode(basePointer)
#define SI32_I2S_A_read_rxmode(basePointer) \
(basePointer->RXMODE.U32)


/// @fn _SI32_I2S_A_write_rxmode(SI32_I2S_A_Type* basePointer,
///      uint32_t rxmode)
///
/// @brief
/// Writes to RXMODE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  rxmode
///
void
_SI32_I2S_A_write_rxmode(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*rxmode*/);
///
/// @def SI32_I2S_A_write_rxmode(basePointer, rxmode)
#define SI32_I2S_A_write_rxmode(basePointer, rxmode) \
   (basePointer->RXMODE.U32      = rxmode)


/// @fn _SI32_I2S_A_set_rx_tdm_slots(SI32_I2S_A_Type* basePointer,
///      uint32_t number_bits,
///      uwide8_t slot_number,
///      uint32_t length)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  number_bits
///  Valid range is 1 to 4096.
///  Bits per slot.
///
/// @param[in]
///  slot_number
///  Valid range is 8 bits.
///  First slot in which to receive data.
///
/// @param[in]
///  length
///  Valid range is 1 to 32.
///  Number of slots for which to send data.
///
void
_SI32_I2S_A_set_rx_tdm_slots(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t, /*number_bits*/
   uwide8_t, /*slot_number*/
   uint32_t /*length*/);
///
/// @def SI32_I2S_A_set_rx_tdm_slots(basePointer, number_bits, slot_number, length)
#define SI32_I2S_A_set_rx_tdm_slots(basePointer, number_bits, slot_number, length) do{  \
   basePointer->RXMODE_CLR = SI32_I2S_A_RXMODE_CYCLE_MASK\
                             | SI32_I2S_A_RXMODE_START_MASK\
                             | SI32_I2S_A_RXMODE_SLOTS_MASK;\
\
   basePointer->RXMODE_SET = ((number_bits-1) << SI32_I2S_A_RXMODE_CYCLE_SHIFT)\
                             | ((slot_number-1) << SI32_I2S_A_RXMODE_START_SHIFT)\
                             | ((length-1) << SI32_I2S_A_RXMODE_SLOTS_SHIFT);\
} while(0)


/// @fn _SI32_I2S_A_enable_rx_tdm(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_tdm(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_tdm(basePointer)
#define SI32_I2S_A_enable_rx_tdm(basePointer) \
   (basePointer->RXMODE_SET = SI32_I2S_A_RXMODE_TDMEN_MASK)


/// @fn _SI32_I2S_A_disable_rx_tdm(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_tdm(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_tdm(basePointer)
#define SI32_I2S_A_disable_rx_tdm(basePointer) \
   (basePointer->RXMODE_CLR = SI32_I2S_A_RXMODE_TDMEN_MASK)


/// @fn _SI32_I2S_A_read_clkcontrol(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads CLKCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_clkcontrol(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_clkcontrol(basePointer)
#define SI32_I2S_A_read_clkcontrol(basePointer) \
(basePointer->CLKCONTROL.U32)


/// @fn _SI32_I2S_A_write_clkcontrol(SI32_I2S_A_Type* basePointer,
///      uint32_t clkcontrol)
///
/// @brief
/// Writes to CLKCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  clkcontrol
///
void
_SI32_I2S_A_write_clkcontrol(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*clkcontrol*/);
///
/// @def SI32_I2S_A_write_clkcontrol(basePointer, clkcontrol)
#define SI32_I2S_A_write_clkcontrol(basePointer, clkcontrol) \
   (basePointer->CLKCONTROL.U32  = clkcontrol)


/// @fn _SI32_I2S_A_set_clock_divider(SI32_I2S_A_Type* basePointer,
///      uint32_t integer,
///      uwide8_t fractional)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  integer
///  Valid range is 1 to 1023.
///  Integer portion of clock divider.
///
/// @param[in]
///  fractional
///  Valid range is 8 bits.
///  Fractional portion of clock divider.
///
void
_SI32_I2S_A_set_clock_divider(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t, /*integer*/
   uwide8_t /*fractional*/);
///
/// @def SI32_I2S_A_set_clock_divider(basePointer, integer, fractional)
#define SI32_I2S_A_set_clock_divider(basePointer, integer, fractional) do{  \
   basePointer->CLKCONTROL_CLR = SI32_I2S_A_CLKCONTROL_INTDIV_MASK\
                                | SI32_I2S_A_CLKCONTROL_FRACDIV_MASK;\
   basePointer->CLKCONTROL_SET = (integer << SI32_I2S_A_CLKCONTROL_INTDIV_SHIFT)\
                                  |(fractional << SI32_I2S_A_CLKCONTROL_FRACDIV_SHIFT);\
} while(0)


/// @fn _SI32_I2S_A_select_extend_high_cycle(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Make high phase of clock wider if dudy cycle not even.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_extend_high_cycle(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_extend_high_cycle(basePointer)
#define SI32_I2S_A_select_extend_high_cycle(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_DUTYMD_MASK)


/// @fn _SI32_I2S_A_select_extend_low_cycle(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Make low phase of clock wider if duty cycle not even.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_extend_low_cycle(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_extend_low_cycle(basePointer)
#define SI32_I2S_A_select_extend_low_cycle(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_DUTYMD_MASK)


/// @fn _SI32_I2S_A_enable_clock_divider(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_clock_divider(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_clock_divider(basePointer)
#define SI32_I2S_A_enable_clock_divider(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_DIVEN_MASK)


/// @fn _SI32_I2S_A_disable_clock_divider(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_clock_divider(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_clock_divider(basePointer)
#define SI32_I2S_A_disable_clock_divider(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_DIVEN_MASK)


/// @fn _SI32_I2S_A_update_clock_divider(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Initiates an update of the clock divider, applying new settings and
/// refreshing the status.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_update_clock_divider(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_update_clock_divider(basePointer)
#define SI32_I2S_A_update_clock_divider(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_CLKUPD_MASK)


/// @fn _SI32_I2S_A_select_tx_clock_source_as_divider_out(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_clock_source_as_divider_out(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_clock_source_as_divider_out(basePointer)
#define SI32_I2S_A_select_tx_clock_source_as_divider_out(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_TXCLKSEL_MASK)


/// @fn _SI32_I2S_A_select_tx_clock_source_as_pin_in(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_clock_source_as_pin_in(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_clock_source_as_pin_in(basePointer)
#define SI32_I2S_A_select_tx_clock_source_as_pin_in(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_TXCLKSEL_MASK)


/// @fn _SI32_I2S_A_select_rx_clock_source_as_divider_out(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_clock_source_as_divider_out(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_clock_source_as_divider_out(basePointer)
#define SI32_I2S_A_select_rx_clock_source_as_divider_out(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_RXCLKSEL_MASK)


/// @fn _SI32_I2S_A_select_rx_clock_source_as_pin_in(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_clock_source_as_pin_in(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_clock_source_as_pin_in(basePointer)
#define SI32_I2S_A_select_rx_clock_source_as_pin_in(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RXCLKSEL_MASK)


/// @fn _SI32_I2S_A_reset_divider(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reset I2S block divider.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_reset_divider(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_reset_divider(basePointer)
#define SI32_I2S_A_reset_divider(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RESET_MASK)


/// @fn _SI32_I2S_A_start_rx_clock(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_start_rx_clock(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_start_rx_clock(basePointer)
#define SI32_I2S_A_start_rx_clock(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RXCLKEN_MASK)


/// @fn _SI32_I2S_A_stop_rx_clock(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_stop_rx_clock(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_stop_rx_clock(basePointer)
#define SI32_I2S_A_stop_rx_clock(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_RXCLKEN_MASK)


/// @fn _SI32_I2S_A_start_tx_clock(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_start_tx_clock(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_start_tx_clock(basePointer)
#define SI32_I2S_A_start_tx_clock(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_TXCLKEN_MASK)


/// @fn _SI32_I2S_A_stop_tx_clock(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_stop_tx_clock(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_stop_tx_clock(basePointer)
#define SI32_I2S_A_stop_tx_clock(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_TXCLKEN_MASK)


/// @fn _SI32_I2S_A_select_rx_dclk_pin_as_output(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Set rx DCLK pin to output mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_dclk_pin_as_output(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_dclk_pin_as_output(basePointer)
#define SI32_I2S_A_select_rx_dclk_pin_as_output(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_RXSCLKMD_MASK)


/// @fn _SI32_I2S_A_select_rx_dclk_pin_as_input(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Set rx DCLK pin to input mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_dclk_pin_as_input(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_dclk_pin_as_input(basePointer)
#define SI32_I2S_A_select_rx_dclk_pin_as_input(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_RXSCLKMD_MASK)


/// @fn _SI32_I2S_A_select_tx_dclk_pin_as_output(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Set tx DCLK pin to output mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_dclk_pin_as_output(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_dclk_pin_as_output(basePointer)
#define SI32_I2S_A_select_tx_dclk_pin_as_output(basePointer) \
   (basePointer->CLKCONTROL_CLR  = SI32_I2S_A_CLKCONTROL_TXSCLKMD_MASK)


/// @fn _SI32_I2S_A_select_tx_dclk_pin_as_input(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Set tx DCLK pin to input mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_dclk_pin_as_input(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_dclk_pin_as_input(basePointer)
#define SI32_I2S_A_select_tx_dclk_pin_as_input(basePointer) \
   (basePointer->CLKCONTROL_SET  = SI32_I2S_A_CLKCONTROL_TXSCLKMD_MASK)


/// @fn _SI32_I2S_A_read_fifocontrol(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads FIFOCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_fifocontrol(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_fifocontrol(basePointer)
#define SI32_I2S_A_read_fifocontrol(basePointer) \
(basePointer->FIFOCONTROL.U32)


/// @fn _SI32_I2S_A_write_fifocontrol(SI32_I2S_A_Type* basePointer,
///      uint32_t fifocontrol)
///
/// @brief
/// Writes to FIFOCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  fifocontrol
///
void
_SI32_I2S_A_write_fifocontrol(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*fifocontrol*/);
///
/// @def SI32_I2S_A_write_fifocontrol(basePointer, fifocontrol)
#define SI32_I2S_A_write_fifocontrol(basePointer, fifocontrol) \
   _SI32_I2S_A_write_fifocontrol(basePointer, fifocontrol) 


/// @fn _SI32_I2S_A_set_fifo_watermarks(SI32_I2S_A_Type* basePointer,
///      uint32_t tx_watermark,
///      uint32_t rx_watermark)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  tx_watermark
///  Valid range is 4 bits.
///  Transmit FIFO depth.
///
/// @param[in]
///  rx_watermark
///  Valid range is 4 bits.
///  Receive FIFO depth.
///
void
_SI32_I2S_A_set_fifo_watermarks(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t, /*tx_watermark*/
   uint32_t /*rx_watermark*/);
///
/// @def SI32_I2S_A_set_fifo_watermarks(basePointer, tx_watermark, rx_watermark)
#define SI32_I2S_A_set_fifo_watermarks(basePointer, tx_watermark, rx_watermark) do{  \
   basePointer->FIFOCONTROL_CLR = SI32_I2S_A_FIFOCONTROL_TXFIFOWM_MASK\
                                  | SI32_I2S_A_FIFOCONTROL_RXFIFOWM_MASK;\
\
   basePointer->FIFOCONTROL_SET =  tx_watermark\
                                   | (rx_watermark << SI32_I2S_A_FIFOCONTROL_RXFIFOWM_SHIFT);\
} while(0)


/// @fn _SI32_I2S_A_flush_tx_fifo(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_flush_tx_fifo(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_flush_tx_fifo(basePointer)
#define SI32_I2S_A_flush_tx_fifo(basePointer) \
   (basePointer->FIFOCONTROL_SET = SI32_I2S_A_FIFOCONTROL_TXFIFOFL_MASK)


/// @fn _SI32_I2S_A_flush_rx_fifo(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_flush_rx_fifo(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_flush_rx_fifo(basePointer)
#define SI32_I2S_A_flush_rx_fifo(basePointer) \
   (basePointer->FIFOCONTROL_SET = SI32_I2S_A_FIFOCONTROL_RXFIFOFL_MASK)


/// @fn _SI32_I2S_A_read_intcontrol(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads INTCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_intcontrol(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_intcontrol(basePointer)
#define SI32_I2S_A_read_intcontrol(basePointer) \
(basePointer->INTCONTROL.U32)


/// @fn _SI32_I2S_A_write_intcontrol(SI32_I2S_A_Type* basePointer,
///      uint32_t intcontrol)
///
/// @brief
/// Writes to INTCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  intcontrol
///
void
_SI32_I2S_A_write_intcontrol(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*intcontrol*/);
///
/// @def SI32_I2S_A_write_intcontrol(basePointer, intcontrol)
#define SI32_I2S_A_write_intcontrol(basePointer, intcontrol) \
   (basePointer->INTCONTROL.U32  = intcontrol)


/// @fn _SI32_I2S_A_enable_tx_fifo_underflow_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_fifo_underflow_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_fifo_underflow_interrupt(basePointer)
#define SI32_I2S_A_enable_tx_fifo_underflow_interrupt(basePointer) \
   (basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_TXUFIEN_MASK)


/// @fn _SI32_I2S_A_disable_tx_fifo_underflow_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_fifo_underflow_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_fifo_underflow_interrupt(basePointer)
#define SI32_I2S_A_disable_tx_fifo_underflow_interrupt(basePointer) \
   (basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_TXUFIEN_MASK)


/// @fn _SI32_I2S_A_is_tx_fifo_underflow_interrupt_enabled(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_tx_fifo_underflow_interrupt_enabled(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_tx_fifo_underflow_interrupt_enabled(basePointer)
#define SI32_I2S_A_is_tx_fifo_underflow_interrupt_enabled(basePointer) \
((bool)(basePointer->INTCONTROL.TXUFIEN))


/// @fn _SI32_I2S_A_enable_tx_fifo_watermark_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_fifo_watermark_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_fifo_watermark_interrupt(basePointer)
#define SI32_I2S_A_enable_tx_fifo_watermark_interrupt(basePointer) \
   (basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_TXLWMIEN_MASK)


/// @fn _SI32_I2S_A_disable_tx_fifo_watermark_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_fifo_watermark_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_fifo_watermark_interrupt(basePointer)
#define SI32_I2S_A_disable_tx_fifo_watermark_interrupt(basePointer) \
   (basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_TXLWMIEN_MASK)


/// @fn _SI32_I2S_A_is_tx_fifo_watermark_interrupt_enabled(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_tx_fifo_watermark_interrupt_enabled(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_tx_fifo_watermark_interrupt_enabled(basePointer)
#define SI32_I2S_A_is_tx_fifo_watermark_interrupt_enabled(basePointer) \
((bool)(basePointer->INTCONTROL.TXLWMIEN))


/// @fn _SI32_I2S_A_enable_rx_fifo_overflow_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_fifo_overflow_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_fifo_overflow_interrupt(basePointer)
#define SI32_I2S_A_enable_rx_fifo_overflow_interrupt(basePointer) \
   (basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_RXOFIEN_MASK)


/// @fn _SI32_I2S_A_disable_rx_fifo_overflow_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_fifo_overflow_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_fifo_overflow_interrupt(basePointer)
#define SI32_I2S_A_disable_rx_fifo_overflow_interrupt(basePointer) \
   (basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_RXOFIEN_MASK)


/// @fn _SI32_I2S_A_is_rx_fifo_overflow_interrupt_enabled(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_rx_fifo_overflow_interrupt_enabled(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_rx_fifo_overflow_interrupt_enabled(basePointer)
#define SI32_I2S_A_is_rx_fifo_overflow_interrupt_enabled(basePointer) \
((bool)(basePointer->INTCONTROL.RXOFIEN))


/// @fn _SI32_I2S_A_disable_rx_fifo_watermark_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_fifo_watermark_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_fifo_watermark_interrupt(basePointer)
#define SI32_I2S_A_disable_rx_fifo_watermark_interrupt(basePointer) \
   (basePointer->INTCONTROL_CLR = SI32_I2S_A_INTCONTROL_RXHWMIEN_MASK)


/// @fn _SI32_I2S_A_enable_rx_fifo_watermark_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_fifo_watermark_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_fifo_watermark_interrupt(basePointer)
#define SI32_I2S_A_enable_rx_fifo_watermark_interrupt(basePointer) \
   (basePointer->INTCONTROL_SET = SI32_I2S_A_INTCONTROL_RXHWMIEN_MASK)


/// @fn _SI32_I2S_A_is_rx_fifo_watermark_interrupt_enabled(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_rx_fifo_watermark_interrupt_enabled(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_rx_fifo_watermark_interrupt_enabled(basePointer)
#define SI32_I2S_A_is_rx_fifo_watermark_interrupt_enabled(basePointer) \
((bool)(basePointer->INTCONTROL.RXHWMIEN))


/// @fn _SI32_I2S_A_read_dmacontrol(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads DMACONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_dmacontrol(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_dmacontrol(basePointer)
#define SI32_I2S_A_read_dmacontrol(basePointer) \
(basePointer->DMACONTROL.U32)


/// @fn _SI32_I2S_A_write_dmacontrol(SI32_I2S_A_Type* basePointer,
///      uint32_t dmacontrol)
///
/// @brief
/// Writes to DMACONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dmacontrol
///
void
_SI32_I2S_A_write_dmacontrol(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*dmacontrol*/);
///
/// @def SI32_I2S_A_write_dmacontrol(basePointer, dmacontrol)
#define SI32_I2S_A_write_dmacontrol(basePointer, dmacontrol) \
   (basePointer->DMACONTROL.U32  = dmacontrol)


/// @fn _SI32_I2S_A_enable_tx_dma_channel(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_dma_channel(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_dma_channel(basePointer)
#define SI32_I2S_A_enable_tx_dma_channel(basePointer) \
   (basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_TXDMAEN_MASK)


/// @fn _SI32_I2S_A_disable_tx_dma_channel(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_dma_channel(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_dma_channel(basePointer)
#define SI32_I2S_A_disable_tx_dma_channel(basePointer) \
   (basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_TXDMAEN_MASK)


/// @fn _SI32_I2S_A_enable_rx_dma_channel(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_dma_channel(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_dma_channel(basePointer)
#define SI32_I2S_A_enable_rx_dma_channel(basePointer) \
   (basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_RXDMAEN_MASK)


/// @fn _SI32_I2S_A_disable_rx_dma_channel(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_dma_channel(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_dma_channel(basePointer)
#define SI32_I2S_A_disable_rx_dma_channel(basePointer) \
   (basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_RXDMAEN_MASK)


/// @fn _SI32_I2S_A_select_tx_dma_single_word_transfer(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_dma_single_word_transfer(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_dma_single_word_transfer(basePointer)
#define SI32_I2S_A_select_tx_dma_single_word_transfer(basePointer) \
   (basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_TXDMABMD_MASK)


/// @fn _SI32_I2S_A_select_tx_dma_four_word_transfer(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_tx_dma_four_word_transfer(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_tx_dma_four_word_transfer(basePointer)
#define SI32_I2S_A_select_tx_dma_four_word_transfer(basePointer) \
   (basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_TXDMABMD_MASK)


/// @fn _SI32_I2S_A_select_rx_dma_single_word_transfer(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_dma_single_word_transfer(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_dma_single_word_transfer(basePointer)
#define SI32_I2S_A_select_rx_dma_single_word_transfer(basePointer) \
   (basePointer->DMACONTROL_CLR = SI32_I2S_A_DMACONTROL_RXDMABMD_MASK)


/// @fn _SI32_I2S_A_select_rx_dma_four_word_transfer(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_select_rx_dma_four_word_transfer(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_select_rx_dma_four_word_transfer(basePointer)
#define SI32_I2S_A_select_rx_dma_four_word_transfer(basePointer) \
   (basePointer->DMACONTROL_SET = SI32_I2S_A_DMACONTROL_RXDMABMD_MASK)


/// @fn _SI32_I2S_A_read_dbgcontrol(SI32_I2S_A_Type* basePointer)
///
/// @brief
/// Reads DBGCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_dbgcontrol(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_dbgcontrol(basePointer)
#define SI32_I2S_A_read_dbgcontrol(basePointer) \
(basePointer->DBGCONTROL.U32)


/// @fn _SI32_I2S_A_write_dbgcontrol(SI32_I2S_A_Type* basePointer,
///      uint32_t dbgcontrol)
///
/// @brief
/// Writes to DBGCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dbgcontrol
///
void
_SI32_I2S_A_write_dbgcontrol(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*dbgcontrol*/);
///
/// @def SI32_I2S_A_write_dbgcontrol(basePointer, dbgcontrol)
#define SI32_I2S_A_write_dbgcontrol(basePointer, dbgcontrol) \
   (basePointer->DBGCONTROL.U32  = dbgcontrol)


/// @fn _SI32_I2S_A_enable_tx_clock_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_clock_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_clock_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_enable_tx_clock_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_TXDBGMD_MASK)


/// @fn _SI32_I2S_A_disable_tx_clock_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_clock_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_clock_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_disable_tx_clock_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_TXDBGMD_MASK)


/// @fn _SI32_I2S_A_enable_rx_clock_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_clock_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_clock_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_enable_rx_clock_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_RXDBGMD_MASK)


/// @fn _SI32_I2S_A_disable_rx_clock_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_clock_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_clock_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_disable_rx_clock_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_RXDBGMD_MASK)


/// @fn _SI32_I2S_A_enable_tx_dma_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_tx_dma_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_tx_dma_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_enable_tx_dma_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_TXDBGHEN_MASK)


/// @fn _SI32_I2S_A_disable_tx_dma_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_tx_dma_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_tx_dma_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_disable_tx_dma_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_TXDBGHEN_MASK)


/// @fn _SI32_I2S_A_enable_rx_dma_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_enable_rx_dma_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_enable_rx_dma_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_enable_rx_dma_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_SET = SI32_I2S_A_DBGCONTROL_RXDBGHEN_MASK)


/// @fn _SI32_I2S_A_disable_rx_dma_stall_in_debug_mode(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_disable_rx_dma_stall_in_debug_mode(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_disable_rx_dma_stall_in_debug_mode(basePointer)
#define SI32_I2S_A_disable_rx_dma_stall_in_debug_mode(basePointer) \
   (basePointer->DBGCONTROL_CLR = SI32_I2S_A_DBGCONTROL_RXDBGHEN_MASK)


/// @fn _SI32_I2S_A_is_tx_fifo_underflow_interrupt_pending(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_tx_fifo_underflow_interrupt_pending(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_tx_fifo_underflow_interrupt_pending(basePointer)
#define SI32_I2S_A_is_tx_fifo_underflow_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.TXUFI)


/// @fn _SI32_I2S_A_is_rx_fifo_overflow_interrupt_pending(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_rx_fifo_overflow_interrupt_pending(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_rx_fifo_overflow_interrupt_pending(basePointer)
#define SI32_I2S_A_is_rx_fifo_overflow_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.RXOFI)


/// @fn _SI32_I2S_A_is_tx_fifo_watermark_interrupt_pending(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_tx_fifo_watermark_interrupt_pending(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_tx_fifo_watermark_interrupt_pending(basePointer)
#define SI32_I2S_A_is_tx_fifo_watermark_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.TXLWMI)


/// @fn _SI32_I2S_A_is_rx_fifo_watermark_interrupt_pending(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_rx_fifo_watermark_interrupt_pending(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_rx_fifo_watermark_interrupt_pending(basePointer)
#define SI32_I2S_A_is_rx_fifo_watermark_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.RXHWMI)


/// @fn _SI32_I2S_A_clear_tx_fifo_underflow_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_clear_tx_fifo_underflow_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_clear_tx_fifo_underflow_interrupt(basePointer)
#define SI32_I2S_A_clear_tx_fifo_underflow_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_I2S_A_STATUS_TXUFI_MASK)


/// @fn _SI32_I2S_A_clear_rx_fifo_overflow_interrupt(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_clear_rx_fifo_overflow_interrupt(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_clear_rx_fifo_overflow_interrupt(basePointer)
#define SI32_I2S_A_clear_rx_fifo_overflow_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_I2S_A_STATUS_RXOFI_MASK)


/// @fn _SI32_I2S_A_is_any_interrupt_pending(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_any_interrupt_pending(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_any_interrupt_pending(basePointer)
#define SI32_I2S_A_is_any_interrupt_pending(basePointer) \
   _SI32_I2S_A_is_any_interrupt_pending(basePointer) 


/// @fn _SI32_I2S_A_clear_all_interrupts(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_I2S_A_clear_all_interrupts(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_clear_all_interrupts(basePointer)
#define SI32_I2S_A_clear_all_interrupts(basePointer) do{  \
   basePointer->STATUS_CLR = (SI32_I2S_A_STATUS_TXUFI_MASK\
	                           | SI32_I2S_A_STATUS_RXOFI_MASK);\
} while(0)


/// @fn _SI32_I2S_A_is_divider_update_pending(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_divider_update_pending(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_divider_update_pending(basePointer)
#define SI32_I2S_A_is_divider_update_pending(basePointer) \
((bool)basePointer->STATUS.CDBUSYF)


/// @fn _SI32_I2S_A_is_counter_stopped(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_counter_stopped(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_counter_stopped(basePointer)
#define SI32_I2S_A_is_counter_stopped(basePointer) \
((bool)basePointer->STATUS.CDSTS)


/// @fn _SI32_I2S_A_is_tx_extclock_synchronized(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_tx_extclock_synchronized(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_tx_extclock_synchronized(basePointer)
#define SI32_I2S_A_is_tx_extclock_synchronized(basePointer) \
((bool)basePointer->STATUS.TXCLKSELRF)


/// @fn _SI32_I2S_A_is_rx_extclock_synchronized(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_rx_extclock_synchronized(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_rx_extclock_synchronized(basePointer)
#define SI32_I2S_A_is_rx_extclock_synchronized(basePointer) \
((bool)basePointer->STATUS.RXCLKSELRF)


/// @fn _SI32_I2S_A_is_tx_clock_synchronized(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_tx_clock_synchronized(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_tx_clock_synchronized(basePointer)
#define SI32_I2S_A_is_tx_clock_synchronized(basePointer) \
((bool)basePointer->STATUS.TXCLKENRF)


/// @fn _SI32_I2S_A_is_rx_clock_synchronized(SI32_I2S_A_Type* basePointer)
///
/// @return
///  True = Yes.
///
/// @param[in]
///  basePointer
///
bool
_SI32_I2S_A_is_rx_clock_synchronized(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_is_rx_clock_synchronized(basePointer)
#define SI32_I2S_A_is_rx_clock_synchronized(basePointer) \
((bool)basePointer->STATUS.RXCLKENRF)


/// @fn _SI32_I2S_A_get_tx_fifo_count(SI32_I2S_A_Type* basePointer)
///
/// @return
///  Number of words in TX FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_get_tx_fifo_count(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_get_tx_fifo_count(basePointer)
#define SI32_I2S_A_get_tx_fifo_count(basePointer) \
(basePointer->FIFOSTATUS.TXFIFONUM)


/// @fn _SI32_I2S_A_get_rx_fifo_count(SI32_I2S_A_Type* basePointer)
///
/// @return
///  Number of words in RX FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_get_rx_fifo_count(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_get_rx_fifo_count(basePointer)
#define SI32_I2S_A_get_rx_fifo_count(basePointer) \
(basePointer->FIFOSTATUS.RXFIFONUM)


/// @fn _SI32_I2S_A_write_tx_fifo_u32(SI32_I2S_A_Type* basePointer,
///      uint32_t data_out)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  data_out
///
void
_SI32_I2S_A_write_tx_fifo_u32(SI32_I2S_A_Type* /*basePointer*/,
   uint32_t /*data_out*/);
///
/// @def SI32_I2S_A_write_tx_fifo_u32(basePointer, data_out)
#define SI32_I2S_A_write_tx_fifo_u32(basePointer, data_out) \
   (basePointer->TXFIFO.U32 = data_out)


/// @fn _SI32_I2S_A_read_rx_fifo_u32(SI32_I2S_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_I2S_A_read_rx_fifo_u32(SI32_I2S_A_Type* /*basePointer*/);
///
/// @def SI32_I2S_A_read_rx_fifo_u32(basePointer)
#define SI32_I2S_A_read_rx_fifo_u32(basePointer) \
(basePointer->RXFIFO.U32)



#ifdef __cplusplus
}
#endif

#endif // __SI32_I2S_A_TYPE_H__

//-eof--------------------------------------------------------------------------
