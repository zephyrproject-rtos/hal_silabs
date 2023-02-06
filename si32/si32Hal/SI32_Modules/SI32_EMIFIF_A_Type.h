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
/// @file SI32_EMIFIF_A_Type.h
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_EMIFIF_A_TYPE_H__
#define __SI32_EMIFIF_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_EMIFIF_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_EMIFIF_A_initialize(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t config,
///      uint32_t ifrt,
///      uint32_t ifwt,
///      uint32_t ifrcst,
///      uint32_t ifwcst)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to IFCONFIG register.
///
/// @param[in]
///  ifrt
///  Valid range is 32 bits.
///  Write to IFRT register.
///
/// @param[in]
///  ifwt
///  Valid range is 32 bits.
///  Write to IFWT register.
///
/// @param[in]
///  ifrcst
///  Valid range is 32 bits.
///  Write to IFRCST register.
///
/// @param[in]
///  ifwcst
///  Valid range is 32 bits.
///  Write to IFWCST register.
///
void
_SI32_EMIFIF_A_initialize(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*ifrt*/
   uint32_t, /*ifwt*/
   uint32_t, /*ifrcst*/
   uint32_t /*ifwcst*/);
///
/// @def SI32_EMIFIF_A_initialize(basePointer, config, ifrt, ifwt, ifrcst, ifwcst)
#define SI32_EMIFIF_A_initialize(basePointer, config, ifrt, ifwt, ifrcst, ifwcst) \
   _SI32_EMIFIF_A_initialize(basePointer, config, ifrt, ifwt, ifrcst, ifwcst) 


/// @fn _SI32_EMIFIF_A_read_config(SI32_EMIFIF_A_Type* basePointer)
///
/// @brief
/// Read IFCONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EMIFIF_A_read_config(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_read_config(basePointer)
#define SI32_EMIFIF_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_EMIFIF_A_write_config(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to IFCONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_EMIFIF_A_write_config(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_EMIFIF_A_write_config(basePointer, value)
#define SI32_EMIFIF_A_write_config(basePointer, value) \
   (basePointer->CONFIG.U32 = value)


/// @fn _SI32_EMIFIF_A_select_8bit_mode(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_select_8bit_mode(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_select_8bit_mode(basePointer)
#define SI32_EMIFIF_A_select_8bit_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_BUSWIDTH_MASK)


/// @fn _SI32_EMIFIF_A_select_16bit_mode(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_select_16bit_mode(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_select_16bit_mode(basePointer)
#define SI32_EMIFIF_A_select_16bit_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_BUSWIDTH_MASK)


/// @fn _SI32_EMIFIF_A_select_muxed_mode(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_select_muxed_mode(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_select_muxed_mode(basePointer)
#define SI32_EMIFIF_A_select_muxed_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_MUXMD_MASK)


/// @fn _SI32_EMIFIF_A_select_nonmuxed_mode(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_select_nonmuxed_mode(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_select_nonmuxed_mode(basePointer)
#define SI32_EMIFIF_A_select_nonmuxed_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_MUXMD_MASK)


/// @fn _SI32_EMIFIF_A_enable_address_shift(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_enable_address_shift(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_enable_address_shift(basePointer)
#define SI32_EMIFIF_A_enable_address_shift(basePointer) \
   (basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_ASEN_MASK)


/// @fn _SI32_EMIFIF_A_disable_address_shift(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_disable_address_shift(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_disable_address_shift(basePointer)
#define SI32_EMIFIF_A_disable_address_shift(basePointer) \
   (basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_ASEN_MASK)


/// @fn _SI32_EMIFIF_A_enable_read_only(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_enable_read_only(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_enable_read_only(basePointer)
#define SI32_EMIFIF_A_enable_read_only(basePointer) \
   (basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_ROEN_MASK)


/// @fn _SI32_EMIFIF_A_disable_read_only(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_disable_read_only(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_disable_read_only(basePointer)
#define SI32_EMIFIF_A_disable_read_only(basePointer) \
   (basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_ROEN_MASK)


/// @fn _SI32_EMIFIF_A_enable_write_data_hold(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_enable_write_data_hold(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_enable_write_data_hold(basePointer)
#define SI32_EMIFIF_A_enable_write_data_hold(basePointer) \
   (basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_WDHINH_MASK)


/// @fn _SI32_EMIFIF_A_disable_write_data_hold(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_disable_write_data_hold(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_disable_write_data_hold(basePointer)
#define SI32_EMIFIF_A_disable_write_data_hold(basePointer) \
   (basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_WDHINH_MASK)


/// @fn _SI32_EMIFIF_A_enable_oeb_delay(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_enable_oeb_delay(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_enable_oeb_delay(basePointer)
#define SI32_EMIFIF_A_enable_oeb_delay(basePointer) \
   (basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_DELAYOE_MASK)


/// @fn _SI32_EMIFIF_A_disable_oeb_delay(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_disable_oeb_delay(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_disable_oeb_delay(basePointer)
#define SI32_EMIFIF_A_disable_oeb_delay(basePointer) \
   (basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_DELAYOE_MASK)


/// @fn _SI32_EMIFIF_A_enable_keep_value(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_enable_keep_value(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_enable_keep_value(basePointer)
#define SI32_EMIFIF_A_enable_keep_value(basePointer) \
   (basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_KLREN_MASK)


/// @fn _SI32_EMIFIF_A_disable_keep_value(SI32_EMIFIF_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EMIFIF_A_disable_keep_value(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_disable_keep_value(basePointer)
#define SI32_EMIFIF_A_disable_keep_value(basePointer) \
   (basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_KLREN_MASK)


/// @fn _SI32_EMIFIF_A_read_ifrt(SI32_EMIFIF_A_Type* basePointer)
///
/// @brief
/// Read IFRT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EMIFIF_A_read_ifrt(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_read_ifrt(basePointer)
#define SI32_EMIFIF_A_read_ifrt(basePointer) \
(basePointer->IFRT.U32)


/// @fn _SI32_EMIFIF_A_write_ifrt(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to IFRT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_EMIFIF_A_write_ifrt(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_EMIFIF_A_write_ifrt(basePointer, value)
#define SI32_EMIFIF_A_write_ifrt(basePointer, value) \
   (basePointer->IFRT.U32 = value)


/// @fn _SI32_EMIFIF_A_set_read_timing(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t addr_setup,
///      uint32_t addr_hold,
///      uint32_t data_hold,
///      uint32_t data_wait)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  addr_setup
///  Valid range is 4 bits.
///  RADDRSET bits.
///
/// @param[in]
///  addr_hold
///  Valid range is 4 bits.
///  RADDRHOLD bits.
///
/// @param[in]
///  data_hold
///  Valid range is 4 bits.
///  RDATAHOLD bits.
///
/// @param[in]
///  data_wait
///  Valid range is 6 bits.
///  RDATAWAIT bits.
///
void
_SI32_EMIFIF_A_set_read_timing(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t, /*addr_setup*/
   uint32_t, /*addr_hold*/
   uint32_t, /*data_hold*/
   uint32_t /*data_wait*/);
///
/// @def SI32_EMIFIF_A_set_read_timing(basePointer, addr_setup, addr_hold, data_hold, data_wait)
#define SI32_EMIFIF_A_set_read_timing(basePointer, addr_setup, addr_hold, data_hold, data_wait) do{  \
   basePointer->IFRT.U32 = (addr_setup << SI32_EMIFIF_A_IFRT_RASET_SHIFT)\
                         | (addr_hold << SI32_EMIFIF_A_IFRT_RAHOLD_SHIFT)\
                         | (data_hold << SI32_EMIFIF_A_IFRT_RDHOLD_SHIFT)\
                         | (data_wait << SI32_EMIFIF_A_IFRT_RDWAIT_SHIFT);\
} while(0)


/// @fn _SI32_EMIFIF_A_read_ifwt(SI32_EMIFIF_A_Type* basePointer)
///
/// @brief
/// read IFWT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EMIFIF_A_read_ifwt(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_read_ifwt(basePointer)
#define SI32_EMIFIF_A_read_ifwt(basePointer) \
(basePointer->IFWT.U32)


/// @fn _SI32_EMIFIF_A_write_ifwt(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to IFWR register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_EMIFIF_A_write_ifwt(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_EMIFIF_A_write_ifwt(basePointer, value)
#define SI32_EMIFIF_A_write_ifwt(basePointer, value) \
   (basePointer->IFWT.U32 = value)


/// @fn _SI32_EMIFIF_A_set_write_timing(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t addr_setup,
///      uint32_t addr_hold,
///      uint32_t data_hold,
///      uint32_t data_wait)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  addr_setup
///  Valid range is 4 bits.
///  WADDRSET bits.
///
/// @param[in]
///  addr_hold
///  Valid range is 4 bits.
///  WADDRHOLD bits.
///
/// @param[in]
///  data_hold
///  Valid range is 4 bits.
///  WDATAHOLD bits.
///
/// @param[in]
///  data_wait
///  Valid range is 6 bits.
///  WDATAWAIT bits.
///
void
_SI32_EMIFIF_A_set_write_timing(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t, /*addr_setup*/
   uint32_t, /*addr_hold*/
   uint32_t, /*data_hold*/
   uint32_t /*data_wait*/);
///
/// @def SI32_EMIFIF_A_set_write_timing(basePointer, addr_setup, addr_hold, data_hold, data_wait)
#define SI32_EMIFIF_A_set_write_timing(basePointer, addr_setup, addr_hold, data_hold, data_wait) do{  \
   basePointer->IFWT.U32 = (addr_setup << SI32_EMIFIF_A_IFWT_WASET_SHIFT)\
                         | (addr_hold << SI32_EMIFIF_A_IFWT_WAHOLD_SHIFT)\
                         | (data_hold << SI32_EMIFIF_A_IFWT_WDHOLD_SHIFT)\
                         | (data_wait << SI32_EMIFIF_A_IFWT_WDWAIT_SHIFT);\
} while(0)


/// @fn _SI32_EMIFIF_A_read_ifrcst(SI32_EMIFIF_A_Type* basePointer)
///
/// @brief
/// Read IFRCST register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EMIFIF_A_read_ifrcst(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_read_ifrcst(basePointer)
#define SI32_EMIFIF_A_read_ifrcst(basePointer) \
(basePointer->IFRCST.U32)


/// @fn _SI32_EMIFIF_A_write_ifrcst(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to IFRCST register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_EMIFIF_A_write_ifrcst(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_EMIFIF_A_write_ifrcst(basePointer, value)
#define SI32_EMIFIF_A_write_ifrcst(basePointer, value) \
   (basePointer->IFRCST.U32 = value)


/// @fn _SI32_EMIFIF_A_set_read_control_states(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t csn,
///      uint32_t oeb,
///      uint32_t wrb,
///      uint32_t alem)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  csn
///  Valid range is 4 bits.
///  CSRAS (bit 0), CSRAH (bit 1), CSRDW (bit 2), and CSRDH (bit 3)bits.
///
/// @param[in]
///  oeb
///  Valid range is 4 bits.
///  OERAS (bit 0), OERAH (bit 1), OERDW (bit 2), and OERDH (bit 3)bits.
///
/// @param[in]
///  wrb
///  Valid range is 4 bits.
///  WRRAS (bit 0), WRRAH (bit 1), WRRDW (bit 2), and WRRDH (bit 3)bits.
///
/// @param[in]
///  alem
///  Valid range is 4 bits.
///  ALERAS (bit 0), ALERAH (bit 1), ALERDW (bit 2), and ALERDH (bit
///  3)bits.
///
void
_SI32_EMIFIF_A_set_read_control_states(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t, /*csn*/
   uint32_t, /*oeb*/
   uint32_t, /*wrb*/
   uint32_t /*alem*/);
///
/// @def SI32_EMIFIF_A_set_read_control_states(basePointer, csn, oeb, wrb, alem)
#define SI32_EMIFIF_A_set_read_control_states(basePointer, csn, oeb, wrb, alem) do{  \
   basePointer->IFRCST.U32 = (csn << SI32_EMIFIF_A_IFRCST_CSRAS_SHIFT)\
                           | (oeb << SI32_EMIFIF_A_IFRCST_OERAS_SHIFT)\
                           | (wrb << SI32_EMIFIF_A_IFRCST_WRRAS_SHIFT)\
                           | (alem << SI32_EMIFIF_A_IFRCST_ALERAS_SHIFT);\
} while(0)


/// @fn _SI32_EMIFIF_A_read_ifwcst(SI32_EMIFIF_A_Type* basePointer)
///
/// @brief
/// Read IFWCST register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EMIFIF_A_read_ifwcst(SI32_EMIFIF_A_Type* /*basePointer*/);
///
/// @def SI32_EMIFIF_A_read_ifwcst(basePointer)
#define SI32_EMIFIF_A_read_ifwcst(basePointer) \
(basePointer->IFWCST.U32)


/// @fn _SI32_EMIFIF_A_write_ifwcst(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t value)
///
/// @brief
/// Write to IFWCST register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  value
///  Valid range is 32 bits.
///
void
_SI32_EMIFIF_A_write_ifwcst(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t /*value*/);
///
/// @def SI32_EMIFIF_A_write_ifwcst(basePointer, value)
#define SI32_EMIFIF_A_write_ifwcst(basePointer, value) \
   (basePointer->IFWCST.U32 = value)


/// @fn _SI32_EMIFIF_A_set_write_control_states(SI32_EMIFIF_A_Type* basePointer,
///      uint32_t csn,
///      uint32_t oeb,
///      uint32_t wrb,
///      uint32_t alem)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  csn
///  Valid range is 4 bits.
///  CSWAS (bit 0), CSWAH (bit 1), CSWDW (bit 2), and CSWDH (bit 3)bits.
///
/// @param[in]
///  oeb
///  Valid range is 4 bits.
///  OEWAS (bit 0), OEWAH (bit 1), OEWDW (bit 2), and OEWDH (bit 3)bits.
///
/// @param[in]
///  wrb
///  Valid range is 4 bits.
///  WRWAS (bit 0), WRWAH (bit 1), WRWDW (bit 2), and WRWDH (bit 3)bits.
///
/// @param[in]
///  alem
///  Valid range is 4 bits.
///  ALEWAS (bit 0), ALEWAH (bit 1), ALEWDW (bit 2), and ALERDH (bit
///  3)bits.
///
void
_SI32_EMIFIF_A_set_write_control_states(SI32_EMIFIF_A_Type* /*basePointer*/,
   uint32_t, /*csn*/
   uint32_t, /*oeb*/
   uint32_t, /*wrb*/
   uint32_t /*alem*/);
///
/// @def SI32_EMIFIF_A_set_write_control_states(basePointer, csn, oeb, wrb, alem)
#define SI32_EMIFIF_A_set_write_control_states(basePointer, csn, oeb, wrb, alem) do{  \
   basePointer->IFWCST.U32 = (csn << SI32_EMIFIF_A_IFWCST_CSWAS_SHIFT)\
                           | (oeb << SI32_EMIFIF_A_IFWCST_OEWAS_SHIFT)\
                           | (wrb << SI32_EMIFIF_A_IFWCST_WRWAS_SHIFT)\
                           | (alem << SI32_EMIFIF_A_IFWCST_ALEWAS_SHIFT);\
} while(0)



#ifdef __cplusplus
}
#endif

#endif // __SI32_EMIFIF_A_TYPE_H__

//-eof--------------------------------------------------------------------------
