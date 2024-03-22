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
// This file applies to the SIM3L1XX_LDO_A module
//
// Script: 0.61
// Version: 1

#ifndef __SI32_LDO_A_REGISTERS_H__
#define __SI32_LDO_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_LDO_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Analog LDO Output Value Select
         volatile uint32_t ALDOOVAL: 5;
         // Analog LDO Bias Select
         volatile uint32_t ALDOBSEL: 1;
         // Analog LDO Source Select
         volatile uint32_t ALDOSSEL: 1;
                  uint32_t reserved0: 1;
         // Memory LDO Output Value Select
         volatile uint32_t MLDOOVAL: 5;
         // Memory LDO Bias Select
         volatile uint32_t MLDOBSEL: 1;
         // Memory LDO Source Select
         volatile uint32_t MLDOSSEL: 1;
                  uint32_t reserved1: 1;
         // Digital LDO Output Value Select
         volatile uint32_t DLDOOVAL: 5;
         // Digital LDO Bias Select
         volatile uint32_t DLDOBSEL: 1;
         // Digital LDO Source Select
         volatile uint32_t DLDOSSEL: 1;
                  uint32_t reserved2: 9;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LDO_A_CONTROL_ALDOOVAL_MASK  0x0000001F
#define SI32_LDO_A_CONTROL_ALDOOVAL_SHIFT  0

#define SI32_LDO_A_CONTROL_ALDOBSEL_MASK  0x00000020
#define SI32_LDO_A_CONTROL_ALDOBSEL_SHIFT  5
// Select a low bias for the analog LDO.
#define SI32_LDO_A_CONTROL_ALDOBSEL_LOW_VALUE  0
#define SI32_LDO_A_CONTROL_ALDOBSEL_LOW_U32 \
   (SI32_LDO_A_CONTROL_ALDOBSEL_LOW_VALUE << SI32_LDO_A_CONTROL_ALDOBSEL_SHIFT)
// Select a high bias for the analog LDO.
#define SI32_LDO_A_CONTROL_ALDOBSEL_HIGH_VALUE  1
#define SI32_LDO_A_CONTROL_ALDOBSEL_HIGH_U32 \
   (SI32_LDO_A_CONTROL_ALDOBSEL_HIGH_VALUE << SI32_LDO_A_CONTROL_ALDOBSEL_SHIFT)

#define SI32_LDO_A_CONTROL_ALDOSSEL_MASK  0x00000040
#define SI32_LDO_A_CONTROL_ALDOSSEL_SHIFT  6
// Select the VBAT pin as the input voltage to the analog LDO.
#define SI32_LDO_A_CONTROL_ALDOSSEL_VBAT_VALUE  0
#define SI32_LDO_A_CONTROL_ALDOSSEL_VBAT_U32 \
   (SI32_LDO_A_CONTROL_ALDOSSEL_VBAT_VALUE << SI32_LDO_A_CONTROL_ALDOSSEL_SHIFT)
// Select the output of the DC-DC converter as the input voltage to the analog LDO.
#define SI32_LDO_A_CONTROL_ALDOSSEL_DCDC_VALUE  1
#define SI32_LDO_A_CONTROL_ALDOSSEL_DCDC_U32 \
   (SI32_LDO_A_CONTROL_ALDOSSEL_DCDC_VALUE << SI32_LDO_A_CONTROL_ALDOSSEL_SHIFT)

#define SI32_LDO_A_CONTROL_MLDOOVAL_MASK  0x00001F00
#define SI32_LDO_A_CONTROL_MLDOOVAL_SHIFT  8

#define SI32_LDO_A_CONTROL_MLDOBSEL_MASK  0x00002000
#define SI32_LDO_A_CONTROL_MLDOBSEL_SHIFT  13
// Select a low bias for the memory LDO.
#define SI32_LDO_A_CONTROL_MLDOBSEL_LOW_VALUE  0
#define SI32_LDO_A_CONTROL_MLDOBSEL_LOW_U32 \
   (SI32_LDO_A_CONTROL_MLDOBSEL_LOW_VALUE << SI32_LDO_A_CONTROL_MLDOBSEL_SHIFT)
// Select a high bias for the memory LDO.
#define SI32_LDO_A_CONTROL_MLDOBSEL_HIGH_VALUE  1
#define SI32_LDO_A_CONTROL_MLDOBSEL_HIGH_U32 \
   (SI32_LDO_A_CONTROL_MLDOBSEL_HIGH_VALUE << SI32_LDO_A_CONTROL_MLDOBSEL_SHIFT)

#define SI32_LDO_A_CONTROL_MLDOSSEL_MASK  0x00004000
#define SI32_LDO_A_CONTROL_MLDOSSEL_SHIFT  14
// Select the VBAT pin as the input voltage to the memory LDO.
#define SI32_LDO_A_CONTROL_MLDOSSEL_VBAT_VALUE  0
#define SI32_LDO_A_CONTROL_MLDOSSEL_VBAT_U32 \
   (SI32_LDO_A_CONTROL_MLDOSSEL_VBAT_VALUE << SI32_LDO_A_CONTROL_MLDOSSEL_SHIFT)
// Select the output of the DC-DC converter as the input voltage to the memory LDO.
#define SI32_LDO_A_CONTROL_MLDOSSEL_DCDC_VALUE  1
#define SI32_LDO_A_CONTROL_MLDOSSEL_DCDC_U32 \
   (SI32_LDO_A_CONTROL_MLDOSSEL_DCDC_VALUE << SI32_LDO_A_CONTROL_MLDOSSEL_SHIFT)

#define SI32_LDO_A_CONTROL_DLDOOVAL_MASK  0x001F0000
#define SI32_LDO_A_CONTROL_DLDOOVAL_SHIFT  16

#define SI32_LDO_A_CONTROL_DLDOBSEL_MASK  0x00200000
#define SI32_LDO_A_CONTROL_DLDOBSEL_SHIFT  21
// Select a low bias for the digital LDO.
#define SI32_LDO_A_CONTROL_DLDOBSEL_LOW_VALUE  0
#define SI32_LDO_A_CONTROL_DLDOBSEL_LOW_U32 \
   (SI32_LDO_A_CONTROL_DLDOBSEL_LOW_VALUE << SI32_LDO_A_CONTROL_DLDOBSEL_SHIFT)
// Select a high bias for the digital LDO.
#define SI32_LDO_A_CONTROL_DLDOBSEL_HIGH_VALUE  1
#define SI32_LDO_A_CONTROL_DLDOBSEL_HIGH_U32 \
   (SI32_LDO_A_CONTROL_DLDOBSEL_HIGH_VALUE << SI32_LDO_A_CONTROL_DLDOBSEL_SHIFT)

#define SI32_LDO_A_CONTROL_DLDOSSEL_MASK  0x00400000
#define SI32_LDO_A_CONTROL_DLDOSSEL_SHIFT  22
// Select the VBAT pin as the input voltage to the digital LDO.
#define SI32_LDO_A_CONTROL_DLDOSSEL_VBAT_VALUE  0
#define SI32_LDO_A_CONTROL_DLDOSSEL_VBAT_U32 \
   (SI32_LDO_A_CONTROL_DLDOSSEL_VBAT_VALUE << SI32_LDO_A_CONTROL_DLDOSSEL_SHIFT)
// Select the output of the DC-DC converter as the input voltage to the digital
// LDO.
#define SI32_LDO_A_CONTROL_DLDOSSEL_DCDC_VALUE  1
#define SI32_LDO_A_CONTROL_DLDOSSEL_DCDC_U32 \
   (SI32_LDO_A_CONTROL_DLDOSSEL_DCDC_VALUE << SI32_LDO_A_CONTROL_DLDOSSEL_SHIFT)



typedef struct SI32_LDO_A_Struct
{
   struct SI32_LDO_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
} SI32_LDO_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_LDO_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

