//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
//
// Script: 0.61
// Version: 1

#ifndef __SI32_VREF_B_REGISTERS_H__
#define __SI32_VREF_B_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_VREF_B_CONTROL_Struct
{
   union
   {
      struct
      {
         // Voltage Reference Doubler
         volatile uint32_t VREF2X: 1;
         // Temperature Sensor Enable
         volatile uint32_t TEMPEN: 1;
         // VREF Output Enable
         volatile uint32_t VREFOUTEN: 1;
                  uint32_t reserved0: 29;
      };
      volatile uint32_t U32;
   };
};

#define SI32_VREF_B_CONTROL_VREF2X_MASK  0x00000001
#define SI32_VREF_B_CONTROL_VREF2X_SHIFT  0
// VREF output is nominally 1.2 V
#define SI32_VREF_B_CONTROL_VREF2X_DISABLED_VALUE  0
#define SI32_VREF_B_CONTROL_VREF2X_DISABLED_U32 \
   (SI32_VREF_B_CONTROL_VREF2X_DISABLED_VALUE << SI32_VREF_B_CONTROL_VREF2X_SHIFT)
// VREF output is nominally 2.4 V
#define SI32_VREF_B_CONTROL_VREF2X_ENABLED_VALUE  1
#define SI32_VREF_B_CONTROL_VREF2X_ENABLED_U32 \
   (SI32_VREF_B_CONTROL_VREF2X_ENABLED_VALUE << SI32_VREF_B_CONTROL_VREF2X_SHIFT)

#define SI32_VREF_B_CONTROL_TEMPEN_MASK  0x00000002
#define SI32_VREF_B_CONTROL_TEMPEN_SHIFT  1
// Disable the temperature sensor.
#define SI32_VREF_B_CONTROL_TEMPEN_DISABLED_VALUE  0
#define SI32_VREF_B_CONTROL_TEMPEN_DISABLED_U32 \
   (SI32_VREF_B_CONTROL_TEMPEN_DISABLED_VALUE << SI32_VREF_B_CONTROL_TEMPEN_SHIFT)
// Enable the temperature sensor.
#define SI32_VREF_B_CONTROL_TEMPEN_ENABLED_VALUE  1
#define SI32_VREF_B_CONTROL_TEMPEN_ENABLED_U32 \
   (SI32_VREF_B_CONTROL_TEMPEN_ENABLED_VALUE << SI32_VREF_B_CONTROL_TEMPEN_SHIFT)

#define SI32_VREF_B_CONTROL_VREFOUTEN_MASK  0x00000004
#define SI32_VREF_B_CONTROL_VREFOUTEN_SHIFT  2
// Internal VREF is not driven on the VREF pin.
#define SI32_VREF_B_CONTROL_VREFOUTEN_DISABLED_VALUE  0
#define SI32_VREF_B_CONTROL_VREFOUTEN_DISABLED_U32 \
   (SI32_VREF_B_CONTROL_VREFOUTEN_DISABLED_VALUE << SI32_VREF_B_CONTROL_VREFOUTEN_SHIFT)
// Internal VREF is driven out to the VREF pin.
#define SI32_VREF_B_CONTROL_VREFOUTEN_ENABLED_VALUE  1
#define SI32_VREF_B_CONTROL_VREFOUTEN_ENABLED_U32 \
   (SI32_VREF_B_CONTROL_VREFOUTEN_ENABLED_VALUE << SI32_VREF_B_CONTROL_VREFOUTEN_SHIFT)



typedef struct SI32_VREF_B_Struct
{
   struct SI32_VREF_B_CONTROL_Struct               CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
} SI32_VREF_B_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_VREF_B_REGISTERS_H__

//-eof--------------------------------------------------------------------------

