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

// Version: 2

#ifndef __SI32_USART_A_SUPPORT_H__
#define __SI32_USART_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Stop Bits Enum type

typedef enum SI32_USART_STOP_BITS_Enum
{
   SI32_USART_A_STOP_BITS_0P5_BIT  = 0,
   SI32_USART_A_STOP_BITS_1_BIT    = 1,
   SI32_USART_A_STOP_BITS_1P5_BITS = 2,
   SI32_USART_A_STOP_BITS_2_BITS   = 3
} SI32_USART_A_STOP_BITS_Enum_Type;

//-----------------------------------------------------------------------------
// Define Parity Enum type

typedef enum SI32_USART_A_PARITY_Enum
{
   SI32_USART_A_PARITY_ODD   = 0,
   SI32_USART_A_PARITY_EVEN  = 1,
   SI32_USART_A_PARITY_SET   = 2,
   SI32_USART_A_PARITY_CLEAR = 3
} SI32_USART_A_PARITY_Enum_Type;

//-----------------------------------------------------------------------------
// Define Data Length Enum type

typedef enum SI32_USART_A_DATA_LENGTH_Enum
{
   SI32_USART_A_DATA_LENGTH_5_BITS        = 5,
   SI32_USART_A_DATA_LENGTH_6_BITS        = 6,
   SI32_USART_A_DATA_LENGTH_7_BITS        = 7,
   SI32_USART_A_DATA_LENGTH_8_BITS        = 8,
   SI32_USART_A_DATA_LENGTH_9_BITS_NORMAL = 9,
   SI32_USART_A_DATA_LENGTH_9_BITS_STORED = 9,
   SI32_USART_A_DATA_LENGTH_9_BITS_FIXED  = 10,
   SI32_USART_A_DATA_LENGTH_9_BITS_MATCH  = 10
} SI32_USART_A_DATA_LENGTH_Enum_Type;


//-----------------------------------------------------------------------------
// Define IrDA Pulse Width Enum type

typedef enum SI32_USART_A_IRDA_PULSE_WIDTH_Enum
{
	SI32_USART_A_IRDA_PULSE_WIDTH_1_16TH = 0,
	SI32_USART_A_IRDA_PULSE_WIDTH_1_8TH  = 1,
	SI32_USART_A_IRDA_PULSE_WIDTH_3_16TH = 2,
	SI32_USART_A_IRDA_PULSE_WIDTH_1_4TH  = 3
} SI32_USART_A_IRDA_PULSE_WIDTH_Enum_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_USART_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
