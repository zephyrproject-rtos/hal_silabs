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
/// @file SI32_DEVICEID_A_Type.c
//
// This file applies to the SIM3L1XX_DEVICEID_A module
//
// Script: 0.58
// HAL Source: 0.1
// Version: 3

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_DEVICEID_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_DEVICEID_A_read_device_id
//
//-----------------------------------------------------------------------------
SI32_DEVICEID_Type
_SI32_DEVICEID_A_read_device_id(
   SI32_DEVICEID_A_Type * basePointer)
{
   //{{
   SI32_DEVICEID_Type id;

	id.deviceid[0] = basePointer->DEVICEID0.U32;
	id.deviceid[1] = basePointer->DEVICEID1.U32;
	id.deviceid[2] = basePointer->DEVICEID2.U32;
   id.deviceid[3] = basePointer->DEVICEID3.U32;

   return id;
   //}}
}


//-eof--------------------------------------------------------------------------
