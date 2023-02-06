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
/// @file SI32_DEVICEID_A_Type.h
//
// This file applies to the SIM3C1XX_DEVICEID_A module
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_DEVICEID_A_TYPE_H__
#define __SI32_DEVICEID_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3C1XX_DEVICEID_A_Registers.h"

// support definitions
#include "SI32_DEVICEID_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_DEVICEID_A_read_device_id(SI32_DEVICEID_A_Type* basePointer)
///
/// @return
///  Device ID in 4 32-bit words.
///
/// @param[in]
///  basePointer
///
SI32_DEVICEID_Type
_SI32_DEVICEID_A_read_device_id(SI32_DEVICEID_A_Type* /*basePointer*/);
///
/// @def SI32_DEVICEID_A_read_device_id(basePointer)
#define SI32_DEVICEID_A_read_device_id(basePointer) \
   _SI32_DEVICEID_A_read_device_id(basePointer)



#ifdef __cplusplus
}
#endif

#endif // __SI32_DEVICEID_A_TYPE_H__

//-eof--------------------------------------------------------------------------
