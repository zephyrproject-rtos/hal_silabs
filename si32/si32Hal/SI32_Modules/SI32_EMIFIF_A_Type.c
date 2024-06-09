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
/// @file SI32_EMIFIF_A_Type.c
//
// Script: 0.58
// HAL Source: 0.1
// Version: 3

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_EMIFIF_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_initialize(
   SI32_EMIFIF_A_Type * basePointer,
   // Write to IFCONFIG register.
   uint32_t config,
   // Write to IFRT register.
   uint32_t ifrt,
   // Write to IFWT register.
   uint32_t ifwt,
   // Write to IFRCST register.
   uint32_t ifrcst,
   // Write to IFWCST register.
   uint32_t ifwcst)
{
   //{{
   basePointer->CONFIG.U32 = config;
   basePointer->IFRT.U32     = ifrt;
   basePointer->IFWT.U32     = ifwt;
   basePointer->IFRCST.U32   = ifrcst;
   basePointer->IFWCST.U32   = ifwcst;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_read_config
//
// Read IFCONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EMIFIF_A_read_config(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_write_config
//
// Write to IFCONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_write_config(
   SI32_EMIFIF_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->CONFIG.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_select_8bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_select_8bit_mode(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_BUSWIDTH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_select_16bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_select_16bit_mode(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_BUSWIDTH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_select_muxed_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_select_muxed_mode(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_MUXMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_select_nonmuxed_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_select_nonmuxed_mode(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_MUXMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_enable_address_shift
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_enable_address_shift(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_ASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_disable_address_shift
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_disable_address_shift(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_ASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_enable_read_only
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_enable_read_only(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_ROEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_disable_read_only
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_disable_read_only(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_ROEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_enable_write_data_hold
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_enable_write_data_hold(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_WDHINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_disable_write_data_hold
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_disable_write_data_hold(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_WDHINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_enable_oeb_delay
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_enable_oeb_delay(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_DELAYOE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_disable_oeb_delay
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_disable_oeb_delay(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_DELAYOE_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_enable_keep_value
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_enable_keep_value(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_EMIFIF_A_CONFIG_KLREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_disable_keep_value
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_disable_keep_value(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_EMIFIF_A_CONFIG_KLREN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_read_ifrt
//
// Read IFRT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EMIFIF_A_read_ifrt(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   return basePointer->IFRT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_write_ifrt
//
// Write to IFRT register.
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_write_ifrt(
   SI32_EMIFIF_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->IFRT.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_set_read_timing
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_set_read_timing(
   SI32_EMIFIF_A_Type * basePointer,
   // RADDRSET bits.
   uint32_t addr_setup,
   // RADDRHOLD bits.
   uint32_t addr_hold,
   // RDATAHOLD bits.
   uint32_t data_hold,
   // RDATAWAIT bits.
   uint32_t data_wait)
{
   assert(addr_setup < 16);   // addr_setup < 2^4
   assert(addr_hold < 16);   // addr_hold < 2^4
   assert(data_hold < 16);   // data_hold < 2^4
   assert(data_wait < 64);   // data_wait < 2^6
   //{{
   basePointer->IFRT.U32 = (addr_setup << SI32_EMIFIF_A_IFRT_RASET_SHIFT)
                         | (addr_hold << SI32_EMIFIF_A_IFRT_RAHOLD_SHIFT)
                         | (data_hold << SI32_EMIFIF_A_IFRT_RDHOLD_SHIFT)
                         | (data_wait << SI32_EMIFIF_A_IFRT_RDWAIT_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_read_ifwt
//
// read IFWT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EMIFIF_A_read_ifwt(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   return basePointer->IFWT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_write_ifwt
//
// Write to IFWR register.
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_write_ifwt(
   SI32_EMIFIF_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->IFWT.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_set_write_timing
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_set_write_timing(
   SI32_EMIFIF_A_Type * basePointer,
   // WADDRSET bits.
   uint32_t addr_setup,
   // WADDRHOLD bits.
   uint32_t addr_hold,
   // WDATAHOLD bits.
   uint32_t data_hold,
   // WDATAWAIT bits.
   uint32_t data_wait)
{
   assert(addr_setup < 16);   // addr_setup < 2^4
   assert(addr_hold < 16);   // addr_hold < 2^4
   assert(data_hold < 16);   // data_hold < 2^4
   assert(data_wait < 64);   // data_wait < 2^6
   //{{
   basePointer->IFWT.U32 = (addr_setup << SI32_EMIFIF_A_IFWT_WASET_SHIFT)
                         | (addr_hold << SI32_EMIFIF_A_IFWT_WAHOLD_SHIFT)
                         | (data_hold << SI32_EMIFIF_A_IFWT_WDHOLD_SHIFT)
                         | (data_wait << SI32_EMIFIF_A_IFWT_WDWAIT_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_read_ifrcst
//
// Read IFRCST register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EMIFIF_A_read_ifrcst(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   return basePointer->IFRCST.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_write_ifrcst
//
// Write to IFRCST register.
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_write_ifrcst(
   SI32_EMIFIF_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->IFRCST.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_set_read_control_states
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_set_read_control_states(
   SI32_EMIFIF_A_Type * basePointer,
   // CSRAS (bit 0), CSRAH (bit 1), CSRDW (bit 2), and CSRDH (bit 3)bits.
   uint32_t csn,
   // OERAS (bit 0), OERAH (bit 1), OERDW (bit 2), and OERDH (bit 3)bits.
   uint32_t oeb,
   // WRRAS (bit 0), WRRAH (bit 1), WRRDW (bit 2), and WRRDH (bit 3)bits.
   uint32_t wrb,
   // ALERAS (bit 0), ALERAH (bit 1), ALERDW (bit 2), and ALERDH (bit
   // 3)bits.
   uint32_t alem)
{
   assert(csn < 16);   // csn < 2^4
   assert(oeb < 16);   // oeb < 2^4
   assert(wrb < 16);   // wrb < 2^4
   assert(alem < 16);   // alem < 2^4
   //{{
   basePointer->IFRCST.U32 = (csn << SI32_EMIFIF_A_IFRCST_CSRAS_SHIFT)
                           | (oeb << SI32_EMIFIF_A_IFRCST_OERAS_SHIFT)
                           | (wrb << SI32_EMIFIF_A_IFRCST_WRRAS_SHIFT)
                           | (alem << SI32_EMIFIF_A_IFRCST_ALERAS_SHIFT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_read_ifwcst
//
// Read IFWCST register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_EMIFIF_A_read_ifwcst(
   SI32_EMIFIF_A_Type * basePointer)
{
   //{{
   return basePointer->IFWCST.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_write_ifwcst
//
// Write to IFWCST register.
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_write_ifwcst(
   SI32_EMIFIF_A_Type * basePointer,
   uint32_t value)
{
   //{{
   basePointer->IFWCST.U32 = value;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EMIFIF_A_set_write_control_states
//
//-----------------------------------------------------------------------------
void
_SI32_EMIFIF_A_set_write_control_states(
   SI32_EMIFIF_A_Type * basePointer,
   // CSWAS (bit 0), CSWAH (bit 1), CSWDW (bit 2), and CSWDH (bit 3)bits.
   uint32_t csn,
   // OEWAS (bit 0), OEWAH (bit 1), OEWDW (bit 2), and OEWDH (bit 3)bits.
   uint32_t oeb,
   // WRWAS (bit 0), WRWAH (bit 1), WRWDW (bit 2), and WRWDH (bit 3)bits.
   uint32_t wrb,
   // ALEWAS (bit 0), ALEWAH (bit 1), ALEWDW (bit 2), and ALERDH (bit
   // 3)bits.
   uint32_t alem)
{
   assert(csn < 16);   // csn < 2^4
   assert(oeb < 16);   // oeb < 2^4
   assert(wrb < 16);   // wrb < 2^4
   assert(alem < 16);   // alem < 2^4
   //{{
   basePointer->IFWCST.U32 = (csn << SI32_EMIFIF_A_IFWCST_CSWAS_SHIFT)
                           | (oeb << SI32_EMIFIF_A_IFWCST_OEWAS_SHIFT)
                           | (wrb << SI32_EMIFIF_A_IFWCST_WRWAS_SHIFT)
                           | (alem << SI32_EMIFIF_A_IFWCST_ALEWAS_SHIFT);
   //}}
}


//-eof--------------------------------------------------------------------------
