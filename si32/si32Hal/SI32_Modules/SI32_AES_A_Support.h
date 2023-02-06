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

#ifndef __SI32_AES_A_Support_Guard__
#define __SI32_AES_A_Support_Guard__

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the Initialization Vector Structure

typedef struct SI32_AES_A_Initialization_Vector_Struct
{
   volatile uint32_t iv[4];
} SI32_AES_A_Initialization_Vector_Type;

//-----------------------------------------------------------------------------
// Define the Hardware Key Structure

typedef struct SI32_AES_A_Hardware_Key_Struct
{
   volatile uint32_t hwkey[8];
} SI32_AES_A_Hardware_Key_Type;

//-----------------------------------------------------------------------------
// Define the Hardware Counter Structure

typedef struct SI32_AES_A_Hardware_Counter_Struct
{
   volatile uint32_t hwctr[4];
} SI32_AES_A_Hardware_Counter_Type;

//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __SI32_AES_A_Guard__

//-eof--------------------------------------------------------------------------
