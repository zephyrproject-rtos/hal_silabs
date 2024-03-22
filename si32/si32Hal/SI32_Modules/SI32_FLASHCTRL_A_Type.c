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
/// @file SI32_FLASHCTRL_A_Type.c
//
// Script: 0.58
// HAL Source: 0.3
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_FLASHCTRL_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_initialize(
   SI32_FLASHCTRL_A_Type * basePointer,
   // Write to CONFIG register.
   uint32_t config,
   // Write to TCONTROL register.
   uint32_t tcontrol)
{
   //{{
   basePointer->CONFIG.U32 = config;
   basePointer->TCONTROL.U32 = tcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_write_config(
   SI32_FLASHCTRL_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_read_config
//
// Reads CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_FLASHCTRL_A_read_config(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_select_flash_speed_mode
//
// Selects the Flash speed mode: 0 = mode 0, 1 = mode 1, 2 = mode 2, 3 =
// mode 3.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_select_flash_speed_mode(
   SI32_FLASHCTRL_A_Type * basePointer,
   uint32_t mode)
{
   assert(mode < 4);   // mode < 2^2
   //{{
   basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_SPMD_MASK;
   basePointer->CONFIG_SET = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_enter_read_store_mode
//
// The first Flash access is passed directly to the AHB.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_enter_read_store_mode(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_RDSEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_exit_read_store_mode
//
// The first Flash access is stored in the prefetch before being passed
// to the AHB.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_exit_read_store_mode(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_RDSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_enable_data_prefetch
//
// Allows data accesses to be stored and queued in the prefetch buffer.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_enable_data_prefetch(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_DPFEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_disable_data_prefetch
//
// Excludes data accesses from the prefetch buffer.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_disable_data_prefetch(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_DPFEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_enable_prefetch
//
// Enables the prefetch engine.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_enable_prefetch(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_PFINH_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_disable_prefetch
//
// Disables the prefetch engine.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_disable_prefetch(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_PFINH_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_enter_multi_byte_write_mode
//
// The write / erase interface will not relock after an operation
// completes.   In addition, sequential writes will take less time than
// they would if they were performed individually.   An erase operation
// initiated in this mode will cause the Flash to relock. When this mode
// is used, code should be running from a memory space other than Flash.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_enter_multi_byte_write_mode(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_SQWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_exit_multi_byte_write_mode
//
// The write / erase interface will relock after an operation completes.
// The interface is automatically relocked after executing this function.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_exit_multi_byte_write_mode(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_SQWEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_enter_flash_erase_mode
//
// Writes to the WRDATA register will initiate a write to Flash at the
// address in WRADDR.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_enter_flash_erase_mode(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_ERASEEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_exit_flash_erase_mode
//
// Writes to the WRDATA register will initiate an erase of the Flash page
// at the page of the address in WRADDR.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_exit_flash_erase_mode(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_ERASEEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_is_flash_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_FLASHCTRL_A_is_flash_busy(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.BUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_is_buffer_full
//
//-----------------------------------------------------------------------------
bool
_SI32_FLASHCTRL_A_is_buffer_full(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.BUFSTS);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_write_wraddr
//
// Write to WRADDR register.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_write_wraddr(
   SI32_FLASHCTRL_A_Type * basePointer,
   uint32_t address)
{
   //{{
   basePointer->WRADDR.U32 = address;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_read_wraddr
//
// Reads WRADDR register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_FLASHCTRL_A_read_wraddr(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   return (basePointer->WRADDR.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_write_wrdata
//
// Write to WRDATA register.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_write_wrdata(
   SI32_FLASHCTRL_A_Type * basePointer,
   uint32_t dataval)
{
   //{{
   basePointer->WRDATA.U32 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_write_flash_key
//
// Writes a value to the Flash Key register bits.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_write_flash_key(
   SI32_FLASHCTRL_A_Type * basePointer,
   uint32_t key)
{
   assert(key < 256);   // key < 2^8
   //{{
   basePointer->KEY.KEY_BITS = key;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_write_tcontrol
//
// Write to TCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_write_tcontrol(
   SI32_FLASHCTRL_A_Type * basePointer,
   uint32_t tcontrol)
{
   //{{
   basePointer->TCONTROL.U32 = tcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_read_tcontrol
//
// Reads TCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_FLASHCTRL_A_read_tcontrol(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   return basePointer->TCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_select_flash_read_time_slow
//
// Configure the Flash read controller for faster AHB clocks.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_select_flash_read_time_slow(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.FLRTMD = SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SLOW_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_FLASHCTRL_A_select_flash_read_time_fast
//
// Configure the Flash read controller for slower AHB clocks.
//-----------------------------------------------------------------------------
void
_SI32_FLASHCTRL_A_select_flash_read_time_fast(
   SI32_FLASHCTRL_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.FLRTMD = SI32_FLASHCTRL_A_TCONTROL_FLRTMD_FAST_VALUE;
   //}}
}


//-eof--------------------------------------------------------------------------
