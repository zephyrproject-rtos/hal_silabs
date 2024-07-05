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

// Version: 1

#ifndef __SI32_ECRC_A_SUPPORT_H__
#define __SI32_ECRC_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Processing Order Enum type

typedef enum SI32_ECRC_A_PROCESSING_ORDER_Enum
{
   SI32_ECRC_A_PROCESSING_ORDER_NO_BYTE_REORIENTATION = 0,
   SI32_ECRC_A_PROCESSING_ORDER_16_BIT_BIG_ENDIAN     = 1,
   SI32_ECRC_A_PROCESSING_ORDER_32_BIT_BIG_ENDIAN     = 2
} SI32_ECRC_A_PROCESSING_ORDER_Enum_Type;

//-----------------------------------------------------------------------------
// Define Device Peripheral Enum type

typedef enum SI32_ECRC_A_DEVICE_PERIPHERAL_Enum
{
   SI32_ECRC_A_DEVICE_PERIPHERAL_0  = 0,
   SI32_ECRC_A_DEVICE_PERIPHERAL_1  = 1,
   SI32_ECRC_A_DEVICE_PERIPHERAL_2  = 2,
   SI32_ECRC_A_DEVICE_PERIPHERAL_3  = 3,
   SI32_ECRC_A_DEVICE_PERIPHERAL_4  = 4,
   SI32_ECRC_A_DEVICE_PERIPHERAL_5  = 5,
   SI32_ECRC_A_DEVICE_PERIPHERAL_6  = 6,
   SI32_ECRC_A_DEVICE_PERIPHERAL_7  = 7,
   SI32_ECRC_A_DEVICE_PERIPHERAL_8  = 8,
   SI32_ECRC_A_DEVICE_PERIPHERAL_9  = 9,
   SI32_ECRC_A_DEVICE_PERIPHERAL_10 = 10,
   SI32_ECRC_A_DEVICE_PERIPHERAL_11 = 11,
   SI32_ECRC_A_DEVICE_PERIPHERAL_12 = 12,
   SI32_ECRC_A_DEVICE_PERIPHERAL_13 = 13,
   SI32_ECRC_A_DEVICE_PERIPHERAL_14 = 14,
   SI32_ECRC_A_DEVICE_PERIPHERAL_15 = 15,
} SI32_ECRC_A_DEVICE_PERIPHERAL_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_ECRC_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------