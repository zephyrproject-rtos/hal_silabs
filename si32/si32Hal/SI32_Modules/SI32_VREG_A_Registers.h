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
// Script: 0.57
// Version: 1

#ifndef __SI32_VREG_A_REGISTERS_H__
#define __SI32_VREG_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_VREG_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // VBUS Valid Flag
         volatile uint32_t VBUSVLDF: 1;
         // Voltage Regulator Suspend Enable
         volatile uint32_t SUSEN: 1;
                  uint32_t reserved0: 3;
         // Band Gap Disable
         volatile uint32_t BGDIS: 1;
         // VREGIN Sense Enable
         volatile uint32_t SENSEEN: 1;
         // VBUS Invalid Interrupt Flag
         volatile uint32_t VBUSIVLDI: 1;
         // VBUS Invalid Interrupt Enable
         volatile uint32_t VBUSIVLDIEN: 1;
                  uint32_t reserved1: 22;
         // Voltage Regulator Disable
         volatile uint32_t VREGDIS: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_VREG_A_CONTROL_VBUSVLDF_MASK  0x00000001
#define SI32_VREG_A_CONTROL_VBUSVLDF_SHIFT  0
// The current voltage on the VBUS pin is below the valid threshold.
#define SI32_VREG_A_CONTROL_VBUSVLDF_NOT_SET_VALUE  0
#define SI32_VREG_A_CONTROL_VBUSVLDF_NOT_SET_U32 \
   (SI32_VREG_A_CONTROL_VBUSVLDF_NOT_SET_VALUE << SI32_VREG_A_CONTROL_VBUSVLDF_SHIFT)
// The current voltage on the VBUS pin is above the valid threshold.
#define SI32_VREG_A_CONTROL_VBUSVLDF_SET_VALUE  1
#define SI32_VREG_A_CONTROL_VBUSVLDF_SET_U32 \
   (SI32_VREG_A_CONTROL_VBUSVLDF_SET_VALUE << SI32_VREG_A_CONTROL_VBUSVLDF_SHIFT)

#define SI32_VREG_A_CONTROL_SUSEN_MASK  0x00000002
#define SI32_VREG_A_CONTROL_SUSEN_SHIFT  1
// Disable regulator suspend mode.
#define SI32_VREG_A_CONTROL_SUSEN_DISABLED_VALUE  0
#define SI32_VREG_A_CONTROL_SUSEN_DISABLED_U32 \
   (SI32_VREG_A_CONTROL_SUSEN_DISABLED_VALUE << SI32_VREG_A_CONTROL_SUSEN_SHIFT)
// Enable regulator suspend mode.
#define SI32_VREG_A_CONTROL_SUSEN_ENABLED_VALUE  1
#define SI32_VREG_A_CONTROL_SUSEN_ENABLED_U32 \
   (SI32_VREG_A_CONTROL_SUSEN_ENABLED_VALUE << SI32_VREG_A_CONTROL_SUSEN_SHIFT)

#define SI32_VREG_A_CONTROL_BGDIS_MASK  0x00000020
#define SI32_VREG_A_CONTROL_BGDIS_SHIFT  5
// Enable the voltage regulator band gap.
#define SI32_VREG_A_CONTROL_BGDIS_INACTIVE_VALUE  0
#define SI32_VREG_A_CONTROL_BGDIS_INACTIVE_U32 \
   (SI32_VREG_A_CONTROL_BGDIS_INACTIVE_VALUE << SI32_VREG_A_CONTROL_BGDIS_SHIFT)
// Disable the voltage regulator band gap.
#define SI32_VREG_A_CONTROL_BGDIS_ACTIVE_VALUE  1
#define SI32_VREG_A_CONTROL_BGDIS_ACTIVE_U32 \
   (SI32_VREG_A_CONTROL_BGDIS_ACTIVE_VALUE << SI32_VREG_A_CONTROL_BGDIS_SHIFT)

#define SI32_VREG_A_CONTROL_SENSEEN_MASK  0x00000040
#define SI32_VREG_A_CONTROL_SENSEEN_SHIFT  6
// Disable VREGIN voltage sensing.
#define SI32_VREG_A_CONTROL_SENSEEN_DISABLED_VALUE  0
#define SI32_VREG_A_CONTROL_SENSEEN_DISABLED_U32 \
   (SI32_VREG_A_CONTROL_SENSEEN_DISABLED_VALUE << SI32_VREG_A_CONTROL_SENSEEN_SHIFT)
// Enable VREGIN voltage sensing.
#define SI32_VREG_A_CONTROL_SENSEEN_ENABLED_VALUE  1
#define SI32_VREG_A_CONTROL_SENSEEN_ENABLED_U32 \
   (SI32_VREG_A_CONTROL_SENSEEN_ENABLED_VALUE << SI32_VREG_A_CONTROL_SENSEEN_SHIFT)

#define SI32_VREG_A_CONTROL_VBUSIVLDI_MASK  0x00000080
#define SI32_VREG_A_CONTROL_VBUSIVLDI_SHIFT  7
// The voltage on the VBUS pin has not dropped below the valid threshold.
#define SI32_VREG_A_CONTROL_VBUSIVLDI_NOT_SET_VALUE  0
#define SI32_VREG_A_CONTROL_VBUSIVLDI_NOT_SET_U32 \
   (SI32_VREG_A_CONTROL_VBUSIVLDI_NOT_SET_VALUE << SI32_VREG_A_CONTROL_VBUSIVLDI_SHIFT)
// The voltage on the VBUS pin dropped below the valid threshold since the last
// time this bit was cleared.
#define SI32_VREG_A_CONTROL_VBUSIVLDI_SET_VALUE  1
#define SI32_VREG_A_CONTROL_VBUSIVLDI_SET_U32 \
   (SI32_VREG_A_CONTROL_VBUSIVLDI_SET_VALUE << SI32_VREG_A_CONTROL_VBUSIVLDI_SHIFT)

#define SI32_VREG_A_CONTROL_VBUSIVLDIEN_MASK  0x00000100
#define SI32_VREG_A_CONTROL_VBUSIVLDIEN_SHIFT  8
// Disable the VBUS invalid interrupt.
#define SI32_VREG_A_CONTROL_VBUSIVLDIEN_DISABLED_VALUE  0
#define SI32_VREG_A_CONTROL_VBUSIVLDIEN_DISABLED_U32 \
   (SI32_VREG_A_CONTROL_VBUSIVLDIEN_DISABLED_VALUE << SI32_VREG_A_CONTROL_VBUSIVLDIEN_SHIFT)
// Enable the VBUS invalid interrupt.
#define SI32_VREG_A_CONTROL_VBUSIVLDIEN_ENABLED_VALUE  1
#define SI32_VREG_A_CONTROL_VBUSIVLDIEN_ENABLED_U32 \
   (SI32_VREG_A_CONTROL_VBUSIVLDIEN_ENABLED_VALUE << SI32_VREG_A_CONTROL_VBUSIVLDIEN_SHIFT)

#define SI32_VREG_A_CONTROL_VREGDIS_MASK  0x80000000
#define SI32_VREG_A_CONTROL_VREGDIS_SHIFT  31
// Enable the voltage regulator.
#define SI32_VREG_A_CONTROL_VREGDIS_INACTIVE_VALUE  0U
#define SI32_VREG_A_CONTROL_VREGDIS_INACTIVE_U32 \
   (SI32_VREG_A_CONTROL_VREGDIS_INACTIVE_VALUE << SI32_VREG_A_CONTROL_VREGDIS_SHIFT)
// Disable the voltage regulator.
#define SI32_VREG_A_CONTROL_VREGDIS_ACTIVE_VALUE  1U
#define SI32_VREG_A_CONTROL_VREGDIS_ACTIVE_U32 \
   (SI32_VREG_A_CONTROL_VREGDIS_ACTIVE_VALUE << SI32_VREG_A_CONTROL_VREGDIS_SHIFT)



typedef struct SI32_VREG_A_Struct
{
   struct SI32_VREG_A_CONTROL_Struct               CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   uint32_t                                        reserved1[4];
} SI32_VREG_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_VREG_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

