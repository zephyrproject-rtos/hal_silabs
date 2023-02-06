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
//
// This file applies to the SIM3C1XX_PBHD_A module
//
// Version: 1

#ifndef __SI32_PBHD_A_SUPPORT_H__
#define __SI32_PBHD_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the PBHD Slew Enum type

typedef enum SI32_PBHD_A_Slew_Enum
{
   SI32_PBHD_A_SLEW_FASTEST = 0,
   SI32_PBHD_A_SLEW_FASTER  = 1,
   SI32_PBHD_A_SLEW_SLOWER  = 2,
   SI32_PBHD_A_SLEW_SLOWEST = 3
} SI32_PBHD_A_Slew_Enum_Type;

//-----------------------------------------------------------------------------
// Define the PBHD Function Enum type

typedef enum SI32_PBHD_A_Function_Enum
{
   SI32_PBHD_A_FUNCTION_GPIO    = 0,
   SI32_PBHD_A_FUNCTION_PMLS    = 1,
   SI32_PBHD_A_FUNCTION_EPCA    = 2,
   SI32_PBHD_A_FUNCTION_UART    = 3,
   SI32_PBHD_A_FUNCTION_LPTIMER = 4
} SI32_PBHD_A_Function_Enum_Type;

//-----------------------------------------------------------------------------
// Define the PBHD Safe State Enum type

typedef enum SI32_PBHD_A_Safe_State_Enum
{
   SI32_PBHD_A_SAFE_STATE_HIZ    = 0,
   SI32_PBHD_A_SAFE_STATE_HIGH   = 1,
   SI32_PBHD_A_SAFE_STATE_LOW    = 2,
   SI32_PBHD_A_SAFE_STATE_IGNORE = 3
} SI32_PBHD_A_Safe_State_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PBHD_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
