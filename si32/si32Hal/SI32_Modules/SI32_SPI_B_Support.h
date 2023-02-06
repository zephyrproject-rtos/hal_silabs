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

#ifndef __SI32_SPI_B_Support_Guard__
#define __SI32_SPI_B_Support_Guard__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Clock Mode ENUMS
typedef enum SI32_SPI_B_CLOCK_MODE_Enum
{
  SI32_SPI_SAMPLE_FIRST_IDLE_LOW    = 0x0,
  SI32_SPI_SHIFT_FIRST_IDLE_LOW     = 0x1,
  SI32_SPI_SAMPLE_FIRST_IDLE_HIGH   = 0x2,
  SI32_SPI_SHIFT_FIRST_IDLE_HIGH    = 0x3
} SI32_SPI_B_CLOCK_MODE_Enum_Type;


//-----------------------------------------------------------------------------
// Define the LOCK Enum type

typedef enum SI32_SPI_B_FIFO_THRESHOLD_Enum
{
  SI32_SPI_FIFO_THRESHOLD_ONE           = 0x0,
  SI32_SPI_FIFO_THRESHOLD_TWO           = 0x1,
  SI32_SPI_FIFO_THRESHOLD_FOUR          = 0x2,
  SI32_SPI_FIFO_THRESHOLD_FULL_OR_EMPTY = 0x3,
} SI32_SPI_B_FIFO_THRESHOLD_Enum_Type;

//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __SI32_SPI_A_Support_Guard__

//-eof--------------------------------------------------------------------------
