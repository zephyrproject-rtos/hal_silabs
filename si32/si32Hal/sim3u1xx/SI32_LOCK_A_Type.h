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
/// @file SI32_LOCK_A_Type.h
//
// This file applies to the SIM3U1XX_LOCK_A module
//
// Script: 0.58
// HAL Source: 0.5
// Version: 1

#ifndef __SI32_LOCK_A_TYPE_H__
#define __SI32_LOCK_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3U1XX_LOCK_A_Registers.h"
#include "SI32_LOCK_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_LOCK_A_initialize(SI32_LOCK_A_Type* basePointer,
///      uint32_t periphlock0,
///      uint32_t periphlock1)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  periphlock0
///  Valid range is 32 bits.
///  PERIPHLOCK0 register.
///
/// @param[in]
///  periphlock1
///  Valid range is 1 bit.
///  PERIPHLOCK1 register.
///
void
_SI32_LOCK_A_initialize(SI32_LOCK_A_Type* /*basePointer*/,
   uint32_t, /*periphlock0*/
   uint32_t /*periphlock1*/);
///
/// @def SI32_LOCK_A_initialize(basePointer, periphlock0, periphlock1)
#define SI32_LOCK_A_initialize(basePointer, periphlock0, periphlock1) do{  \
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_2;\
   basePointer->PERIPHLOCK0.U32 = periphlock0;\
   basePointer->PERIPHLOCK1.U32 = periphlock1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_LOCK_VALUE;\
} while(0)


/// @fn _SI32_LOCK_A_unlock_peripheral_locking_registers(SI32_LOCK_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LOCK_A_unlock_peripheral_locking_registers(SI32_LOCK_A_Type* /*basePointer*/);
///
/// @def SI32_LOCK_A_unlock_peripheral_locking_registers(basePointer)
#define SI32_LOCK_A_unlock_peripheral_locking_registers(basePointer) do{  \
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_2;\
} while(0)


/// @fn _SI32_LOCK_A_lock_peripheral_locking_registers(SI32_LOCK_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LOCK_A_lock_peripheral_locking_registers(SI32_LOCK_A_Type* /*basePointer*/);
///
/// @def SI32_LOCK_A_lock_peripheral_locking_registers(basePointer)
#define SI32_LOCK_A_lock_peripheral_locking_registers(basePointer) \
   (basePointer->KEY.KEY_BITS = SI32_LOCK_A_LOCK_VALUE)


/// @fn _SI32_LOCK_A_check_lock_register_status(SI32_LOCK_A_Type* basePointer)
///
/// @return
///  Current status of the lock registers. 00 : PERIPHLOCKx registers are
///  locked and no valid values have been written to KEYB. 01 : PERIPHLOCKx
///  registers are locked and the first valid value (0xA5) has been written
///  to KEYB. 10 : PERIPHLOCKx registers are unlocked. Any subsequent
///  writes to KEYB will lock the interface. 11 : Reserved.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LOCK_A_check_lock_register_status(SI32_LOCK_A_Type* /*basePointer*/);
///
/// @def SI32_LOCK_A_check_lock_register_status(basePointer)
#define SI32_LOCK_A_check_lock_register_status(basePointer) \
(basePointer->KEY.U32)


/// @fn _SI32_LOCK_A_write_periphlock0(SI32_LOCK_A_Type* basePointer,
///      uint32_t periphlock0)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  periphlock0
///  Valid range is 32 bits.
///  Write PERIPHLOCK0 register.
///
void
_SI32_LOCK_A_write_periphlock0(SI32_LOCK_A_Type* /*basePointer*/,
   uint32_t /*periphlock0*/);
///
/// @def SI32_LOCK_A_write_periphlock0(basePointer, periphlock0)
#define SI32_LOCK_A_write_periphlock0(basePointer, periphlock0) do{  \
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_2;\
   basePointer->PERIPHLOCK0.U32 = periphlock0;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_LOCK_VALUE;\
} while(0)


/// @fn _SI32_LOCK_A_read_periphlock0(SI32_LOCK_A_Type* basePointer)
///
/// @return
///  Read PERIPHLOCK0 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LOCK_A_read_periphlock0(SI32_LOCK_A_Type* /*basePointer*/);
///
/// @def SI32_LOCK_A_read_periphlock0(basePointer)
#define SI32_LOCK_A_read_periphlock0(basePointer) \
(basePointer->PERIPHLOCK0.U32)


/// @fn _SI32_LOCK_A_write_periphlock1(SI32_LOCK_A_Type* basePointer,
///      uint32_t periphlock1)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  periphlock1
///  Valid range is 1 bit.
///  Write PERIPHLOCK1 register.
///
void
_SI32_LOCK_A_write_periphlock1(SI32_LOCK_A_Type* /*basePointer*/,
   uint32_t /*periphlock1*/);
///
/// @def SI32_LOCK_A_write_periphlock1(basePointer, periphlock1)
#define SI32_LOCK_A_write_periphlock1(basePointer, periphlock1) do{  \
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_2;\
   basePointer->PERIPHLOCK1.U32 = periphlock1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_LOCK_VALUE;\
} while(0)


/// @fn _SI32_LOCK_A_read_periphlock1(SI32_LOCK_A_Type* basePointer)
///
/// @return
///  Read PERIPHLOCK1 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_LOCK_A_read_periphlock1(SI32_LOCK_A_Type* /*basePointer*/);
///
/// @def SI32_LOCK_A_read_periphlock1(basePointer)
#define SI32_LOCK_A_read_periphlock1(basePointer) \
(basePointer->PERIPHLOCK1.U32)


/// @fn _SI32_LOCK_A_lock_module(SI32_LOCK_A_Type* basePointer,
///      SI32_LOCK_A_Enum_Type module)
///
/// @brief
/// This function will automatically unlock and lock the interface to the
/// module locks.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  module
///  Valid range is 5 bits.
///  Peripheral set to lock.
///
void
_SI32_LOCK_A_lock_module(SI32_LOCK_A_Type* /*basePointer*/,
   SI32_LOCK_A_Enum_Type /*module*/);
///
/// @def SI32_LOCK_A_lock_module(basePointer, module)
#define SI32_LOCK_A_lock_module(basePointer, module) \
   _SI32_LOCK_A_lock_module(basePointer, module) 


/// @fn _SI32_LOCK_A_unlock_module(SI32_LOCK_A_Type* basePointer,
///      SI32_LOCK_A_Enum_Type module)
///
/// @brief
/// This function will automatically unlock and lock the interface to the
/// module locks.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  module
///  Valid range is 5 bits.
///  Peripheral set to unlock.
///
void
_SI32_LOCK_A_unlock_module(SI32_LOCK_A_Type* /*basePointer*/,
   SI32_LOCK_A_Enum_Type /*module*/);
///
/// @def SI32_LOCK_A_unlock_module(basePointer, module)
#define SI32_LOCK_A_unlock_module(basePointer, module) \
   _SI32_LOCK_A_unlock_module(basePointer, module) 


/// @fn _SI32_LOCK_A_is_module_locked(SI32_LOCK_A_Type* basePointer,
///      SI32_LOCK_A_Enum_Type module)
///
/// @return
///  True = Locked, False = Unlocked.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  module
///  Valid range is 5 bits.
///  Peripheral set to check.
///
bool
_SI32_LOCK_A_is_module_locked(SI32_LOCK_A_Type* /*basePointer*/,
   SI32_LOCK_A_Enum_Type /*module*/);
///
/// @def SI32_LOCK_A_is_module_locked(basePointer, module)
#define SI32_LOCK_A_is_module_locked(basePointer, module) \
   _SI32_LOCK_A_is_module_locked(basePointer, module) 


/// @fn _SI32_LOCK_A_unlock_all_modules(SI32_LOCK_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LOCK_A_unlock_all_modules(SI32_LOCK_A_Type* /*basePointer*/);
///
/// @def SI32_LOCK_A_unlock_all_modules(basePointer)
#define SI32_LOCK_A_unlock_all_modules(basePointer) do{  \
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_2;\
   basePointer->PERIPHLOCK0_CLR =\
      SI32_LOCK_A_PERIPHLOCK0_ALL_LOCKS_MASK;\
   basePointer->PERIPHLOCK1_CLR = SI32_LOCK_A_PERIPHLOCK1_PMUL_MASK;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_LOCK_VALUE;\
} while(0)


/// @fn _SI32_LOCK_A_lock_all_modules(SI32_LOCK_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_LOCK_A_lock_all_modules(SI32_LOCK_A_Type* /*basePointer*/);
///
/// @def SI32_LOCK_A_lock_all_modules(basePointer)
#define SI32_LOCK_A_lock_all_modules(basePointer) do{  \
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_1;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_UNLOCK_VALUE_2;\
   basePointer->PERIPHLOCK0_SET =\
      SI32_LOCK_A_PERIPHLOCK0_ALL_LOCKS_MASK;\
   basePointer->PERIPHLOCK1_SET = SI32_LOCK_A_PERIPHLOCK1_PMUL_MASK;\
   basePointer->KEY.KEY_BITS = SI32_LOCK_A_LOCK_VALUE;\
} while(0)



#ifdef __cplusplus
}
#endif

#endif // __SI32_LOCK_A_TYPE_H__

//-eof--------------------------------------------------------------------------
