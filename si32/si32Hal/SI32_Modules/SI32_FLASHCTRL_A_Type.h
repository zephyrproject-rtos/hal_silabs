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
/// @file SI32_FLASHCTRL_A_Type.h
//
// Script: 0.58
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_FLASHCTRL_A_TYPE_H__
#define __SI32_FLASHCTRL_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_FLASHCTRL_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_FLASHCTRL_A_initialize(SI32_FLASHCTRL_A_Type* basePointer,
///      uint32_t config,
///      uint32_t tcontrol)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Write to CONFIG register.
///
/// @param[in]
///  tcontrol
///  Write to TCONTROL register.
///
void
_SI32_FLASHCTRL_A_initialize(SI32_FLASHCTRL_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t /*tcontrol*/);
///
/// @def SI32_FLASHCTRL_A_initialize(basePointer, config, tcontrol)
#define SI32_FLASHCTRL_A_initialize(basePointer, config, tcontrol) do{  \
   basePointer->CONFIG.U32 = config;\
   basePointer->TCONTROL.U32 = tcontrol;\
} while(0)


/// @fn _SI32_FLASHCTRL_A_write_config(SI32_FLASHCTRL_A_Type* basePointer,
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
///
void
_SI32_FLASHCTRL_A_write_config(SI32_FLASHCTRL_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_FLASHCTRL_A_write_config(basePointer, config)
#define SI32_FLASHCTRL_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_FLASHCTRL_A_read_config(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Reads CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_FLASHCTRL_A_read_config(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_read_config(basePointer)
#define SI32_FLASHCTRL_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_FLASHCTRL_A_select_flash_speed_mode(SI32_FLASHCTRL_A_Type* basePointer,
///      uint32_t mode)
///
/// @brief
/// Selects the Flash speed mode: 0 = mode 0, 1 = mode 1, 2 = mode 2, 3 =
/// mode 3.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 2 bits.
///
void
_SI32_FLASHCTRL_A_select_flash_speed_mode(SI32_FLASHCTRL_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_FLASHCTRL_A_select_flash_speed_mode(basePointer, mode)
#define SI32_FLASHCTRL_A_select_flash_speed_mode(basePointer, mode) do{  \
   basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_SPMD_MASK;\
   basePointer->CONFIG_SET = mode;\
} while(0)


/// @fn _SI32_FLASHCTRL_A_enter_read_store_mode(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// The first Flash access is passed directly to the AHB.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_enter_read_store_mode(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_enter_read_store_mode(basePointer)
#define SI32_FLASHCTRL_A_enter_read_store_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_RDSEN_ENABLED_U32)


/// @fn _SI32_FLASHCTRL_A_exit_read_store_mode(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// The first Flash access is stored in the prefetch before being passed
/// to the AHB.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_exit_read_store_mode(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_exit_read_store_mode(basePointer)
#define SI32_FLASHCTRL_A_exit_read_store_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_RDSEN_MASK)


/// @fn _SI32_FLASHCTRL_A_enable_data_prefetch(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Allows data accesses to be stored and queued in the prefetch buffer.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_enable_data_prefetch(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_enable_data_prefetch(basePointer)
#define SI32_FLASHCTRL_A_enable_data_prefetch(basePointer) \
   (basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_DPFEN_ENABLED_U32)


/// @fn _SI32_FLASHCTRL_A_disable_data_prefetch(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Excludes data accesses from the prefetch buffer.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_disable_data_prefetch(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_disable_data_prefetch(basePointer)
#define SI32_FLASHCTRL_A_disable_data_prefetch(basePointer) \
   (basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_DPFEN_MASK)


/// @fn _SI32_FLASHCTRL_A_enable_prefetch(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Enables the prefetch engine.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_enable_prefetch(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_enable_prefetch(basePointer)
#define SI32_FLASHCTRL_A_enable_prefetch(basePointer) \
   (basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_PFINH_MASK)


/// @fn _SI32_FLASHCTRL_A_disable_prefetch(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Disables the prefetch engine.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_disable_prefetch(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_disable_prefetch(basePointer)
#define SI32_FLASHCTRL_A_disable_prefetch(basePointer) \
   (basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_PFINH_ACTIVE_U32)


/// @fn _SI32_FLASHCTRL_A_enter_multi_byte_write_mode(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// The write / erase interface will not relock after an operation
/// completes.   In addition, sequential writes will take less time than
/// they would if they were performed individually.   An erase operation
/// initiated in this mode will cause the Flash to relock. When this mode
/// is used, code should be running from a memory space other than Flash.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_enter_multi_byte_write_mode(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_enter_multi_byte_write_mode(basePointer)
#define SI32_FLASHCTRL_A_enter_multi_byte_write_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_SQWEN_MASK)


/// @fn _SI32_FLASHCTRL_A_exit_multi_byte_write_mode(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// The write / erase interface will relock after an operation completes.
/// The interface is automatically relocked after executing this function.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_exit_multi_byte_write_mode(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_exit_multi_byte_write_mode(basePointer)
#define SI32_FLASHCTRL_A_exit_multi_byte_write_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_SQWEN_MASK)


/// @fn _SI32_FLASHCTRL_A_enter_flash_erase_mode(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Writes to the WRDATA register will initiate a write to Flash at the
/// address in WRADDR.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_enter_flash_erase_mode(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_enter_flash_erase_mode(basePointer)
#define SI32_FLASHCTRL_A_enter_flash_erase_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_FLASHCTRL_A_CONFIG_ERASEEN_ENABLED_U32)


/// @fn _SI32_FLASHCTRL_A_exit_flash_erase_mode(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Writes to the WRDATA register will initiate an erase of the Flash page
/// at the page of the address in WRADDR.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_exit_flash_erase_mode(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_exit_flash_erase_mode(basePointer)
#define SI32_FLASHCTRL_A_exit_flash_erase_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_FLASHCTRL_A_CONFIG_ERASEEN_MASK)


/// @fn _SI32_FLASHCTRL_A_is_flash_busy(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @return
///  Returns TRUE if the Flash interface is busy, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_FLASHCTRL_A_is_flash_busy(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_is_flash_busy(basePointer)
#define SI32_FLASHCTRL_A_is_flash_busy(basePointer) \
((bool)(basePointer->CONFIG.BUFSTS))


/// @fn _SI32_FLASHCTRL_A_is_buffer_full(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @return
///  Returns TRUE if the Flash write data buffer is full, otherwise returns
///  FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_FLASHCTRL_A_is_buffer_full(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_is_buffer_full(basePointer)
#define SI32_FLASHCTRL_A_is_buffer_full(basePointer) \
((bool)(basePointer->CONFIG.BUSYF))


/// @fn _SI32_FLASHCTRL_A_write_wraddr(SI32_FLASHCTRL_A_Type* basePointer,
///      uint32_t address)
///
/// @brief
/// Write to WRADDR register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  address
///
void
_SI32_FLASHCTRL_A_write_wraddr(SI32_FLASHCTRL_A_Type* /*basePointer*/,
   uint32_t /*address*/);
///
/// @def SI32_FLASHCTRL_A_write_wraddr(basePointer, address)
#define SI32_FLASHCTRL_A_write_wraddr(basePointer, address) \
   (basePointer->WRADDR.U32 = address)


/// @fn _SI32_FLASHCTRL_A_read_wraddr(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Reads WRADDR register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_FLASHCTRL_A_read_wraddr(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_read_wraddr(basePointer)
#define SI32_FLASHCTRL_A_read_wraddr(basePointer) \
((basePointer->WRADDR.U32))


/// @fn _SI32_FLASHCTRL_A_write_wrdata(SI32_FLASHCTRL_A_Type* basePointer,
///      uint32_t dataval)
///
/// @brief
/// Write to WRDATA register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///
void
_SI32_FLASHCTRL_A_write_wrdata(SI32_FLASHCTRL_A_Type* /*basePointer*/,
   uint32_t /*dataval*/);
///
/// @def SI32_FLASHCTRL_A_write_wrdata(basePointer, dataval)
#define SI32_FLASHCTRL_A_write_wrdata(basePointer, dataval) \
   (basePointer->WRDATA.U32 = dataval)


/// @fn _SI32_FLASHCTRL_A_write_flash_key(SI32_FLASHCTRL_A_Type* basePointer,
///      uint32_t key)
///
/// @brief
/// Writes a value to the Flash Key register bits.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  key
///  Valid range is 8 bits.
///
void
_SI32_FLASHCTRL_A_write_flash_key(SI32_FLASHCTRL_A_Type* /*basePointer*/,
   uint32_t /*key*/);
///
/// @def SI32_FLASHCTRL_A_write_flash_key(basePointer, key)
#define SI32_FLASHCTRL_A_write_flash_key(basePointer, key) \
   (basePointer->KEY.KEY_BITS = key)


/// @fn _SI32_FLASHCTRL_A_write_tcontrol(SI32_FLASHCTRL_A_Type* basePointer,
///      uint32_t tcontrol)
///
/// @brief
/// Write to TCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  tcontrol
///
void
_SI32_FLASHCTRL_A_write_tcontrol(SI32_FLASHCTRL_A_Type* /*basePointer*/,
   uint32_t /*tcontrol*/);
///
/// @def SI32_FLASHCTRL_A_write_tcontrol(basePointer, tcontrol)
#define SI32_FLASHCTRL_A_write_tcontrol(basePointer, tcontrol) \
   (basePointer->TCONTROL.U32 = tcontrol)


/// @fn _SI32_FLASHCTRL_A_read_tcontrol(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Reads TCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_FLASHCTRL_A_read_tcontrol(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_read_tcontrol(basePointer)
#define SI32_FLASHCTRL_A_read_tcontrol(basePointer) \
(basePointer->TCONTROL.U32)


/// @fn _SI32_FLASHCTRL_A_select_flash_read_time_slow(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Configure the Flash read controller for faster AHB clocks.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_select_flash_read_time_slow(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_select_flash_read_time_slow(basePointer)
#define SI32_FLASHCTRL_A_select_flash_read_time_slow(basePointer) \
   (basePointer->TCONTROL.FLRTMD = SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SLOW_VALUE)


/// @fn _SI32_FLASHCTRL_A_select_flash_read_time_fast(SI32_FLASHCTRL_A_Type* basePointer)
///
/// @brief
/// Configure the Flash read controller for slower AHB clocks.
///
/// @param[in]
///  basePointer
///
void
_SI32_FLASHCTRL_A_select_flash_read_time_fast(SI32_FLASHCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_FLASHCTRL_A_select_flash_read_time_fast(basePointer)
#define SI32_FLASHCTRL_A_select_flash_read_time_fast(basePointer) \
   (basePointer->TCONTROL.FLRTMD = SI32_FLASHCTRL_A_TCONTROL_FLRTMD_FAST_VALUE)



#ifdef __cplusplus
}
#endif

#endif // __SI32_FLASHCTRL_A_TYPE_H__

//-eof--------------------------------------------------------------------------
