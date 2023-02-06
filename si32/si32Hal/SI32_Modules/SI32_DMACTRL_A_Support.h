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

#ifndef __SI32_DMACTRL_A_SUPPORT_H__
#define __SI32_DMACTRL_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define State ENUMS
typedef enum SI32_DMACTRL_A_STATE_Enum
{
  SI32_DMACTRL_IDLE                      = 0x0,
  SI32_DMACTRL_READ_CHANNEL_DATA         = 0x1,
  SI32_DMACTRL_READ_SRC_PTR              = 0x2,
  SI32_DMACTRL_READ_DST_PTR              = 0x3,
  SI32_DMACTRL_READ_SRC_DATA             = 0x4,
  SI32_DMACTRL_WRITE_DST_DATA            = 0x5,
  SI32_DMACTRL_WAIT_FOR_DMA_REQ_CLEAR    = 0x6,
  SI32_DMACTRL_WRITE_CHANNEL_DATA        = 0x7,
  SI32_DMACTRL_STALLED                   = 0x8,
  SI32_DMACTRL_DONE                      = 0x9,
  SI32_DMACTRL_SCATTER_GATHER_TRANSITION = 0xA
} SI32_DMACTRL_A_STATE_Enum_Type;



#ifdef __cplusplus
}
#endif

#endif // __SI32_DMACTRL_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
