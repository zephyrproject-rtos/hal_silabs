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
/// @file SI32_DMACTRL_A_Type.h
//
// Script: 0.58
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_DMACTRL_A_TYPE_H__
#define __SI32_DMACTRL_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_DMACTRL_A_Registers.h"

// support definitions
#include "SI32_DMACTRL_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_DMACTRL_A_initialize(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t config,
///      uint32_t baseptr,
///      uint32_t chswrcn,
///      uint32_t chreqm,
///      uint32_t chen,
///      uint32_t chalt,
///      uint32_t chhp,
///      uint32_t berr)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
/// @param[in]
///  baseptr
///  Valid range is 32 bits.
///  Write to BASEPTR register.
///
/// @param[in]
///  chswrcn
///  Valid range is 32 bits.
///  Write to CHSWRCN register.
///
/// @param[in]
///  chreqm
///  Valid range is 32 bits.
///  Write to CHREQM register.
///
/// @param[in]
///  chen
///  Valid range is 32 bits.
///  Write to CHEN register.
///
/// @param[in]
///  chalt
///  Valid range is 32 bits.
///  Write to CHALT register.
///
/// @param[in]
///  chhp
///  Valid range is 32 bits.
///  Write to CHHP register.
///
/// @param[in]
///  berr
///  Valid range is 32 bits.
///  Write to BERR register.
///
void
_SI32_DMACTRL_A_initialize(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*baseptr*/
   uint32_t, /*chswrcn*/
   uint32_t, /*chreqm*/
   uint32_t, /*chen*/
   uint32_t, /*chalt*/
   uint32_t, /*chhp*/
   uint32_t /*berr*/);
///
/// @def SI32_DMACTRL_A_initialize(basePointer, config, baseptr, chswrcn, chreqm, chen, chalt, chhp, berr)
#define SI32_DMACTRL_A_initialize(basePointer, config, baseptr, chswrcn, chreqm, chen, chalt, chhp, berr) do{  \
   basePointer->CONFIG.U32 = config;\
   basePointer->BASEPTR.U32 = baseptr;\
   basePointer->CHSWRCN.U32 = chswrcn;\
   basePointer->CHREQMCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHREQMSET.U32 = chreqm;\
   basePointer->CHENCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHENSET.U32 = chen;\
   basePointer->CHALTCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHALTSET.U32 = chalt;\
   basePointer->CHHPCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHHPSET.U32 = chhp;\
   basePointer->BERRCLR.U32 = berr;\
} while(0)


/// @fn _SI32_DMACTRL_A_is_enabled(SI32_DMACTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_DMACTRL_A_is_enabled(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_is_enabled(basePointer)
#define SI32_DMACTRL_A_is_enabled(basePointer) \
((bool)(basePointer->STATUS.DMAENSTS))


/// @fn _SI32_DMACTRL_A_get_state(SI32_DMACTRL_A_Type* basePointer)
///
/// @return
///  Current state of DMA.
///
/// @param[in]
///  basePointer
///
SI32_DMACTRL_A_STATE_Enum_Type
_SI32_DMACTRL_A_get_state(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_get_state(basePointer)
#define SI32_DMACTRL_A_get_state(basePointer) \
((SI32_DMACTRL_A_STATE_Enum_Type)basePointer->STATUS.STATE)


/// @fn _SI32_DMACTRL_A_get_number_of_channels(SI32_DMACTRL_A_Type* basePointer)
///
/// @return
///  Number of dma channels available.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DMACTRL_A_get_number_of_channels(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_get_number_of_channels(basePointer)
#define SI32_DMACTRL_A_get_number_of_channels(basePointer) \
(basePointer->STATUS.NUMCHAN + 1)


/// @fn _SI32_DMACTRL_A_write_config(SI32_DMACTRL_A_Type* basePointer,
///      uwide8_t config)
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
_SI32_DMACTRL_A_write_config(SI32_DMACTRL_A_Type* /*basePointer*/,
   uwide8_t /*config*/);
///
/// @def SI32_DMACTRL_A_write_config(basePointer, config)
#define SI32_DMACTRL_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_DMACTRL_A_enable_module(SI32_DMACTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DMACTRL_A_enable_module(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_enable_module(basePointer)
#define SI32_DMACTRL_A_enable_module(basePointer) \
   (basePointer->CONFIG.DMAEN = SI32_DMACTRL_A_CONFIG_DMAEN_ENABLED_VALUE)


/// @fn _SI32_DMACTRL_A_disable_module(SI32_DMACTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DMACTRL_A_disable_module(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_disable_module(basePointer)
#define SI32_DMACTRL_A_disable_module(basePointer) \
   (basePointer->CONFIG.DMAEN = SI32_DMACTRL_A_CONFIG_DMAEN_DISABLED_VALUE)


/// @fn _SI32_DMACTRL_A_read_baseptr(SI32_DMACTRL_A_Type* basePointer)
///
/// @brief
/// Read BASEPTR register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DMACTRL_A_read_baseptr(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_read_baseptr(basePointer)
#define SI32_DMACTRL_A_read_baseptr(basePointer) \
(basePointer->BASEPTR.U32)


/// @fn _SI32_DMACTRL_A_write_baseptr(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t baseptr)
///
/// @brief
/// Write to BASEPTR register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  baseptr
///  Valid range is 32 bits.
///
void
_SI32_DMACTRL_A_write_baseptr(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*baseptr*/);
///
/// @def SI32_DMACTRL_A_write_baseptr(basePointer, baseptr)
#define SI32_DMACTRL_A_write_baseptr(basePointer, baseptr) \
   (basePointer->BASEPTR.U32 = (baseptr & SI32_DMACTRL_A_BASEPTR_BASEPTR_MASK))


/// @fn _SI32_DMACTRL_A_read_abaseptr(SI32_DMACTRL_A_Type* basePointer)
///
/// @brief
/// Read ABASEPTR register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DMACTRL_A_read_abaseptr(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_read_abaseptr(basePointer)
#define SI32_DMACTRL_A_read_abaseptr(basePointer) \
(basePointer->ABASEPTR.U32)


/// @fn _SI32_DMACTRL_A_write_chswrcn(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t chswrcn)
///
/// @brief
/// Write to CHSWRCN register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  chswrcn
///  Valid range is 32 bits.
///
void
_SI32_DMACTRL_A_write_chswrcn(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*chswrcn*/);
///
/// @def SI32_DMACTRL_A_write_chswrcn(basePointer, chswrcn)
#define SI32_DMACTRL_A_write_chswrcn(basePointer, chswrcn) \
   (basePointer->CHSWRCN.U32 = chswrcn)


/// @fn _SI32_DMACTRL_A_generate_software_request(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///  Set the channels software request bit.
///
void
_SI32_DMACTRL_A_generate_software_request(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_generate_software_request(basePointer, channel_number)
#define SI32_DMACTRL_A_generate_software_request(basePointer, channel_number) \
   (basePointer->CHSWRCN.U32 |= (1 << channel_number))


/// @fn _SI32_DMACTRL_A_read_chreqm(SI32_DMACTRL_A_Type* basePointer)
///
/// @brief
/// Read CHREQM register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_DMACTRL_A_read_chreqm(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_read_chreqm(basePointer)
#define SI32_DMACTRL_A_read_chreqm(basePointer) \
(basePointer->CHREQMSET.U32)


/// @fn _SI32_DMACTRL_A_write_chreqm(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t chreqm)
///
/// @brief
/// Write to CHREQM register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  chreqm
///  Valid range is 32 bits.
///
void
_SI32_DMACTRL_A_write_chreqm(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*chreqm*/);
///
/// @def SI32_DMACTRL_A_write_chreqm(basePointer, chreqm)
#define SI32_DMACTRL_A_write_chreqm(basePointer, chreqm) do{  \
   basePointer->CHREQMCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHREQMSET.U32 = chreqm;\
} while(0)


/// @fn _SI32_DMACTRL_A_enable_data_request(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_enable_data_request(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_enable_data_request(basePointer, channel_number)
#define SI32_DMACTRL_A_enable_data_request(basePointer, channel_number) \
   (basePointer->CHREQMCLR.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_disable_data_request(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_disable_data_request(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_disable_data_request(basePointer, channel_number)
#define SI32_DMACTRL_A_disable_data_request(basePointer, channel_number) \
   (basePointer->CHREQMSET.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_read_chen(SI32_DMACTRL_A_Type* basePointer)
///
/// @brief
/// Read CHEN register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_DMACTRL_A_read_chen(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_read_chen(basePointer)
#define SI32_DMACTRL_A_read_chen(basePointer) \
(basePointer->CHENSET.U32)


/// @fn _SI32_DMACTRL_A_write_chen(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t chen)
///
/// @brief
/// Write to CHEN register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  chen
///  Valid range is 32 bits.
///
void
_SI32_DMACTRL_A_write_chen(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*chen*/);
///
/// @def SI32_DMACTRL_A_write_chen(basePointer, chen)
#define SI32_DMACTRL_A_write_chen(basePointer, chen) do{  \
   basePointer->CHENCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHENSET.U32 = chen;\
} while(0)


/// @fn _SI32_DMACTRL_A_is_channel_enabled(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @return
///  Returns TRUE if channel is enabled, meaning dma operation in progres,s
///  and False if not enabled, meaning last operation is finished.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
bool
_SI32_DMACTRL_A_is_channel_enabled(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_is_channel_enabled(basePointer, channel_number)
#define SI32_DMACTRL_A_is_channel_enabled(basePointer, channel_number) \
((bool)((basePointer->CHENSET.U32 >> channel_number) & 0x1))


/// @fn _SI32_DMACTRL_A_enable_channel(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_enable_channel(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_enable_channel(basePointer, channel_number)
#define SI32_DMACTRL_A_enable_channel(basePointer, channel_number) \
   (basePointer->CHENSET.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_disable_channel(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_disable_channel(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_disable_channel(basePointer, channel_number)
#define SI32_DMACTRL_A_disable_channel(basePointer, channel_number) \
   (basePointer->CHENCLR.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_read_chalt(SI32_DMACTRL_A_Type* basePointer)
///
/// @brief
/// Read CHALT registe.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_DMACTRL_A_read_chalt(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_read_chalt(basePointer)
#define SI32_DMACTRL_A_read_chalt(basePointer) \
(basePointer->CHALTSET.U32)


/// @fn _SI32_DMACTRL_A_write_chalt(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t chalt)
///
/// @brief
/// Write to CHALT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  chalt
///  Valid range is 32 bits.
///
void
_SI32_DMACTRL_A_write_chalt(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*chalt*/);
///
/// @def SI32_DMACTRL_A_write_chalt(basePointer, chalt)
#define SI32_DMACTRL_A_write_chalt(basePointer, chalt) do{  \
   basePointer->CHALTCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHALTSET.U32 = chalt;\
} while(0)


/// @fn _SI32_DMACTRL_A_is_primary_selected(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @return
///  Returns TRUE if primary data structure is selected and False if
///  alternate data structure is selected.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
bool
_SI32_DMACTRL_A_is_primary_selected(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_is_primary_selected(basePointer, channel_number)
#define SI32_DMACTRL_A_is_primary_selected(basePointer, channel_number) \
(!(bool)((basePointer->CHALTSET.U32 >> channel_number) & 0x1))


/// @fn _SI32_DMACTRL_A_select_alternate_data_structure(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_select_alternate_data_structure(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_select_alternate_data_structure(basePointer, channel_number)
#define SI32_DMACTRL_A_select_alternate_data_structure(basePointer, channel_number) \
   (basePointer->CHALTSET.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_select_primary_data_structure(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_select_primary_data_structure(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_select_primary_data_structure(basePointer, channel_number)
#define SI32_DMACTRL_A_select_primary_data_structure(basePointer, channel_number) \
   (basePointer->CHALTCLR.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_read_chhp(SI32_DMACTRL_A_Type* basePointer)
///
/// @brief
/// Read CHHP register.
///
/// @param[in]
///  basePointer
///
uwide16_t
_SI32_DMACTRL_A_read_chhp(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_read_chhp(basePointer)
#define SI32_DMACTRL_A_read_chhp(basePointer) \
(basePointer->CHHPSET.U32)


/// @fn _SI32_DMACTRL_A_write_chhp(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t chhp)
///
/// @brief
/// Write to CHHP register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  chhp
///  Valid range is 32 bits.
///
void
_SI32_DMACTRL_A_write_chhp(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*chhp*/);
///
/// @def SI32_DMACTRL_A_write_chhp(basePointer, chhp)
#define SI32_DMACTRL_A_write_chhp(basePointer, chhp) do{  \
   basePointer->CHHPCLR.U32 = 0xFFFFFFFF;\
   basePointer->CHHPSET.U32 = chhp;\
} while(0)


/// @fn _SI32_DMACTRL_A_select_channel_high_priority(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_select_channel_high_priority(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_select_channel_high_priority(basePointer, channel_number)
#define SI32_DMACTRL_A_select_channel_high_priority(basePointer, channel_number) \
   (basePointer->CHHPSET.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_select_channel_default_priority(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t channel_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel_number
///  Valid range is 4 bits.
///
void
_SI32_DMACTRL_A_select_channel_default_priority(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*channel_number*/);
///
/// @def SI32_DMACTRL_A_select_channel_default_priority(basePointer, channel_number)
#define SI32_DMACTRL_A_select_channel_default_priority(basePointer, channel_number) \
   (basePointer->CHHPCLR.U32 = (1 << channel_number))


/// @fn _SI32_DMACTRL_A_read_berr(SI32_DMACTRL_A_Type* basePointer)
///
/// @brief
/// Read BERR register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DMACTRL_A_read_berr(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_read_berr(basePointer)
#define SI32_DMACTRL_A_read_berr(basePointer) \
(basePointer->BERRCLR.U32)


/// @fn _SI32_DMACTRL_A_write_berr(SI32_DMACTRL_A_Type* basePointer,
///      uint32_t berr)
///
/// @brief
/// Write to BERR register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  berr
///  Valid range is 32 bits.
///
void
_SI32_DMACTRL_A_write_berr(SI32_DMACTRL_A_Type* /*basePointer*/,
   uint32_t /*berr*/);
///
/// @def SI32_DMACTRL_A_write_berr(basePointer, berr)
#define SI32_DMACTRL_A_write_berr(basePointer, berr) \
   (basePointer->BERRCLR.U32 = berr)


/// @fn _SI32_DMACTRL_A_clear_bus_error(SI32_DMACTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DMACTRL_A_clear_bus_error(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_clear_bus_error(basePointer)
#define SI32_DMACTRL_A_clear_bus_error(basePointer) \
   (basePointer->BERRCLR.ERROR = SI32_DMACTRL_A_BERRCLR_ERROR_CLEAR_VALUE)


/// @fn _SI32_DMACTRL_A_is_bus_error_set(SI32_DMACTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_DMACTRL_A_is_bus_error_set(SI32_DMACTRL_A_Type* /*basePointer*/);
///
/// @def SI32_DMACTRL_A_is_bus_error_set(basePointer)
#define SI32_DMACTRL_A_is_bus_error_set(basePointer) \
((bool)(basePointer->BERRCLR.ERROR))



#ifdef __cplusplus
}
#endif

#endif // __SI32_DMACTRL_A_TYPE_H__

//-eof--------------------------------------------------------------------------
