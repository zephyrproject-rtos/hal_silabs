//-----------------------------------------------------------------------------
// Copyright 2013 (c) Silicon Laboratories Inc.
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
// Script: 0.62
// Version: 1

#ifndef __SI32_PLL_A_REGISTERS_H__
#define __SI32_PLL_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_PLL_A_DIVIDER_Struct
{
   union
   {
      struct
      {
         // M Divider Value
         volatile uint32_t M: 12;
                  uint32_t reserved0: 4;
         // N Divider Value
         volatile uint32_t N: 12;
                  uint32_t reserved1: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PLL_A_DIVIDER_M_MASK  0x00000FFF
#define SI32_PLL_A_DIVIDER_M_SHIFT  0

#define SI32_PLL_A_DIVIDER_N_MASK  0x0FFF0000
#define SI32_PLL_A_DIVIDER_N_SHIFT  16



struct SI32_PLL_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // CAL Saturation (Low) Flag
         volatile uint32_t LLMTF: 1;
         // CAL Saturation (High) Flag
         volatile uint32_t HLMTF: 1;
         // Phase-Lock and Frequency-Lock Locked Interrupt Flag
         volatile uint32_t LCKI: 1;
                  uint32_t reserved0: 6;
         // Limit Interrupt Enable
         volatile uint32_t LMTIEN: 1;
         // Locked Interrupt Enable
         volatile uint32_t LCKIEN: 1;
         // Lock Interrupt Polarity
         volatile uint32_t LCKPOL: 1;
                  uint32_t reserved1: 4;
         // Reference Clock Selection Control
         volatile uint32_t REFSEL: 3;
                  uint32_t reserved2: 1;
         // Lock Threshold Control
         volatile uint32_t LOCKTH: 2;
                  uint32_t reserved3: 4;
         // DCO Output Updates Stall
         volatile uint32_t STALL: 1;
                  uint32_t reserved4: 1;
         // Dithering Enable
         volatile uint32_t DITHEN: 1;
         // Edge Lock Select
         volatile uint32_t EDGSEL: 1;
         // PLL Output Mode
         volatile uint32_t OUTMD: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PLL_A_CONTROL_LLMTF_MASK  0x00000001
#define SI32_PLL_A_CONTROL_LLMTF_SHIFT  0
// DCO period is not saturated low.
#define SI32_PLL_A_CONTROL_LLMTF_NOT_SET_VALUE  0
#define SI32_PLL_A_CONTROL_LLMTF_NOT_SET_U32 \
   (SI32_PLL_A_CONTROL_LLMTF_NOT_SET_VALUE << SI32_PLL_A_CONTROL_LLMTF_SHIFT)
// DCO period is saturated low.
#define SI32_PLL_A_CONTROL_LLMTF_SET_VALUE  1
#define SI32_PLL_A_CONTROL_LLMTF_SET_U32 \
   (SI32_PLL_A_CONTROL_LLMTF_SET_VALUE << SI32_PLL_A_CONTROL_LLMTF_SHIFT)

#define SI32_PLL_A_CONTROL_HLMTF_MASK  0x00000002
#define SI32_PLL_A_CONTROL_HLMTF_SHIFT  1
// DCO period is not saturated high.
#define SI32_PLL_A_CONTROL_HLMTF_NOT_SET_VALUE  0
#define SI32_PLL_A_CONTROL_HLMTF_NOT_SET_U32 \
   (SI32_PLL_A_CONTROL_HLMTF_NOT_SET_VALUE << SI32_PLL_A_CONTROL_HLMTF_SHIFT)
// DCO period is saturated high.
#define SI32_PLL_A_CONTROL_HLMTF_SET_VALUE  1
#define SI32_PLL_A_CONTROL_HLMTF_SET_U32 \
   (SI32_PLL_A_CONTROL_HLMTF_SET_VALUE << SI32_PLL_A_CONTROL_HLMTF_SHIFT)

#define SI32_PLL_A_CONTROL_LCKI_MASK  0x00000004
#define SI32_PLL_A_CONTROL_LCKI_SHIFT  2
// DCO is disabled or not locked.
#define SI32_PLL_A_CONTROL_LCKI_NOT_SET_VALUE  0
#define SI32_PLL_A_CONTROL_LCKI_NOT_SET_U32 \
   (SI32_PLL_A_CONTROL_LCKI_NOT_SET_VALUE << SI32_PLL_A_CONTROL_LCKI_SHIFT)
// DCO is enabled and locked.
#define SI32_PLL_A_CONTROL_LCKI_SET_VALUE  1
#define SI32_PLL_A_CONTROL_LCKI_SET_U32 \
   (SI32_PLL_A_CONTROL_LCKI_SET_VALUE << SI32_PLL_A_CONTROL_LCKI_SHIFT)

#define SI32_PLL_A_CONTROL_LMTIEN_MASK  0x00000200
#define SI32_PLL_A_CONTROL_LMTIEN_SHIFT  9
// Saturation (high and low) interrupt disabled.
#define SI32_PLL_A_CONTROL_LMTIEN_DISABLED_VALUE  0
#define SI32_PLL_A_CONTROL_LMTIEN_DISABLED_U32 \
   (SI32_PLL_A_CONTROL_LMTIEN_DISABLED_VALUE << SI32_PLL_A_CONTROL_LMTIEN_SHIFT)
// Saturation (high and low) interrupt enabled.
#define SI32_PLL_A_CONTROL_LMTIEN_ENABLED_VALUE  1
#define SI32_PLL_A_CONTROL_LMTIEN_ENABLED_U32 \
   (SI32_PLL_A_CONTROL_LMTIEN_ENABLED_VALUE << SI32_PLL_A_CONTROL_LMTIEN_SHIFT)

#define SI32_PLL_A_CONTROL_LCKIEN_MASK  0x00000400
#define SI32_PLL_A_CONTROL_LCKIEN_SHIFT  10
// The PLL locking does not cause an interrupt
#define SI32_PLL_A_CONTROL_LCKIEN_DISABLED_VALUE  0
#define SI32_PLL_A_CONTROL_LCKIEN_DISABLED_U32 \
   (SI32_PLL_A_CONTROL_LCKIEN_DISABLED_VALUE << SI32_PLL_A_CONTROL_LCKIEN_SHIFT)
// An interrupt is generated if LCKI matches the state selected by LCKPOL.
#define SI32_PLL_A_CONTROL_LCKIEN_ENABLED_VALUE  1
#define SI32_PLL_A_CONTROL_LCKIEN_ENABLED_U32 \
   (SI32_PLL_A_CONTROL_LCKIEN_ENABLED_VALUE << SI32_PLL_A_CONTROL_LCKIEN_SHIFT)

#define SI32_PLL_A_CONTROL_LCKPOL_MASK  0x00000800
#define SI32_PLL_A_CONTROL_LCKPOL_SHIFT  11
// The lock state PLL interrupt will occur when LCKI is 0.
#define SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_LOW_VALUE  0
#define SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_LOW_U32 \
   (SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_LOW_VALUE << SI32_PLL_A_CONTROL_LCKPOL_SHIFT)
// The lock state PLL interrupt will occur when LCKI is 1.
#define SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_HIGH_VALUE  1
#define SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_HIGH_U32 \
   (SI32_PLL_A_CONTROL_LCKPOL_ACTIVE_HIGH_VALUE << SI32_PLL_A_CONTROL_LCKPOL_SHIFT)

#define SI32_PLL_A_CONTROL_REFSEL_MASK  0x00070000
#define SI32_PLL_A_CONTROL_REFSEL_SHIFT  16
// PLL reference clock (FREF) is the RTC0TCLK.
#define SI32_PLL_A_CONTROL_REFSEL_RTC0OSC_VALUE  0
#define SI32_PLL_A_CONTROL_REFSEL_RTC0OSC_U32 \
   (SI32_PLL_A_CONTROL_REFSEL_RTC0OSC_VALUE << SI32_PLL_A_CONTROL_REFSEL_SHIFT)
// PLL reference clock (FREF) is the divided Low Power Oscillator (LPOSC0).
#define SI32_PLL_A_CONTROL_REFSEL_LPOSC0DIV_VALUE  1
#define SI32_PLL_A_CONTROL_REFSEL_LPOSC0DIV_U32 \
   (SI32_PLL_A_CONTROL_REFSEL_LPOSC0DIV_VALUE << SI32_PLL_A_CONTROL_REFSEL_SHIFT)
// PLL reference clock (FREF) is the external oscillator output (EXTOSC0).
#define SI32_PLL_A_CONTROL_REFSEL_EXTOSC0_VALUE  2
#define SI32_PLL_A_CONTROL_REFSEL_EXTOSC0_U32 \
   (SI32_PLL_A_CONTROL_REFSEL_EXTOSC0_VALUE << SI32_PLL_A_CONTROL_REFSEL_SHIFT)
// PLL reference clock (FREF) is the USB0 oscillator (USB0OSC).
#define SI32_PLL_A_CONTROL_REFSEL_USBOSC0_VALUE  3
#define SI32_PLL_A_CONTROL_REFSEL_USBOSC0_U32 \
   (SI32_PLL_A_CONTROL_REFSEL_USBOSC0_VALUE << SI32_PLL_A_CONTROL_REFSEL_SHIFT)
// PLL reference clock (FREF) is the Low Power Oscillator (LPOSC0).
#define SI32_PLL_A_CONTROL_REFSEL_LPOSC0_VALUE  4
#define SI32_PLL_A_CONTROL_REFSEL_LPOSC0_U32 \
   (SI32_PLL_A_CONTROL_REFSEL_LPOSC0_VALUE << SI32_PLL_A_CONTROL_REFSEL_SHIFT)

#define SI32_PLL_A_CONTROL_LOCKTH_MASK  0x00300000
#define SI32_PLL_A_CONTROL_LOCKTH_SHIFT  20

#define SI32_PLL_A_CONTROL_STALL_MASK  0x04000000
#define SI32_PLL_A_CONTROL_STALL_SHIFT  26
// In phase-lock and frequency-lock modes, spectrum spreading, and dithering
// operate normally, if enabled.
#define SI32_PLL_A_CONTROL_STALL_DISABLED_VALUE  0
#define SI32_PLL_A_CONTROL_STALL_DISABLED_U32 \
   (SI32_PLL_A_CONTROL_STALL_DISABLED_VALUE << SI32_PLL_A_CONTROL_STALL_SHIFT)
// In phase-lock and frequency-lock modes, spectrum spreading, and dithering are
// prevented from updating the output of the DCO.
#define SI32_PLL_A_CONTROL_STALL_ENABLED_VALUE  1
#define SI32_PLL_A_CONTROL_STALL_ENABLED_U32 \
   (SI32_PLL_A_CONTROL_STALL_ENABLED_VALUE << SI32_PLL_A_CONTROL_STALL_SHIFT)

#define SI32_PLL_A_CONTROL_DITHEN_MASK  0x10000000
#define SI32_PLL_A_CONTROL_DITHEN_SHIFT  28
// Automatic DCO output dithering disabled.
#define SI32_PLL_A_CONTROL_DITHEN_DISABLED_VALUE  0
#define SI32_PLL_A_CONTROL_DITHEN_DISABLED_U32 \
   (SI32_PLL_A_CONTROL_DITHEN_DISABLED_VALUE << SI32_PLL_A_CONTROL_DITHEN_SHIFT)
// Automatic DCO output dithering enabled.
#define SI32_PLL_A_CONTROL_DITHEN_ENABLED_VALUE  1
#define SI32_PLL_A_CONTROL_DITHEN_ENABLED_U32 \
   (SI32_PLL_A_CONTROL_DITHEN_ENABLED_VALUE << SI32_PLL_A_CONTROL_DITHEN_SHIFT)

#define SI32_PLL_A_CONTROL_EDGSEL_MASK  0x20000000
#define SI32_PLL_A_CONTROL_EDGSEL_SHIFT  29
// Lock DCO output frequency to the falling edge of the reference frequency.
#define SI32_PLL_A_CONTROL_EDGSEL_FALLING_EDGE_VALUE  0
#define SI32_PLL_A_CONTROL_EDGSEL_FALLING_EDGE_U32 \
   (SI32_PLL_A_CONTROL_EDGSEL_FALLING_EDGE_VALUE << SI32_PLL_A_CONTROL_EDGSEL_SHIFT)
// Lock DCO output frequency to the rising edge of the reference frequency.
#define SI32_PLL_A_CONTROL_EDGSEL_RISING_EDGE_VALUE  1
#define SI32_PLL_A_CONTROL_EDGSEL_RISING_EDGE_U32 \
   (SI32_PLL_A_CONTROL_EDGSEL_RISING_EDGE_VALUE << SI32_PLL_A_CONTROL_EDGSEL_SHIFT)

#define SI32_PLL_A_CONTROL_OUTMD_MASK  0xC0000000
#define SI32_PLL_A_CONTROL_OUTMD_SHIFT  30
// DCO output is off.
#define SI32_PLL_A_CONTROL_OUTMD_OFF_VALUE  0U
#define SI32_PLL_A_CONTROL_OUTMD_OFF_U32 \
   (SI32_PLL_A_CONTROL_OUTMD_OFF_VALUE << SI32_PLL_A_CONTROL_OUTMD_SHIFT)
// DCO output is in Free-Running DCO mode.
#define SI32_PLL_A_CONTROL_OUTMD_DCO_VALUE  1U
#define SI32_PLL_A_CONTROL_OUTMD_DCO_U32 \
   (SI32_PLL_A_CONTROL_OUTMD_DCO_VALUE << SI32_PLL_A_CONTROL_OUTMD_SHIFT)
// DCO output is in frequency-lock mode (reference source required).
#define SI32_PLL_A_CONTROL_OUTMD_FLL_VALUE  2U
#define SI32_PLL_A_CONTROL_OUTMD_FLL_U32 \
   (SI32_PLL_A_CONTROL_OUTMD_FLL_VALUE << SI32_PLL_A_CONTROL_OUTMD_SHIFT)
// DCO output is in phase-lock mode (reference source required).
#define SI32_PLL_A_CONTROL_OUTMD_PLL_VALUE  3U
#define SI32_PLL_A_CONTROL_OUTMD_PLL_U32 \
   (SI32_PLL_A_CONTROL_OUTMD_PLL_VALUE << SI32_PLL_A_CONTROL_OUTMD_SHIFT)



struct SI32_PLL_A_SSPR_Struct
{
   union
   {
      struct
      {
         // Spectrum Spreading Amplitude
         volatile uint32_t SSAMP: 3;
                  uint32_t reserved0: 5;
         // Spectrum Spreading Update Interval
         volatile uint32_t SSUINV: 5;
                  uint32_t reserved1: 19;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PLL_A_SSPR_SSAMP_MASK  0x00000007
#define SI32_PLL_A_SSPR_SSAMP_SHIFT  0
// Disable Spectrum Spreading.
#define SI32_PLL_A_SSPR_SSAMP_DISABLED_VALUE  0
#define SI32_PLL_A_SSPR_SSAMP_DISABLED_U32 \
   (SI32_PLL_A_SSPR_SSAMP_DISABLED_VALUE << SI32_PLL_A_SSPR_SSAMP_SHIFT)
// Spectrum Spreading set to approximately +/- 0.1% of TDCO.
#define SI32_PLL_A_SSPR_SSAMP_SETTING1_VALUE  1
#define SI32_PLL_A_SSPR_SSAMP_SETTING1_U32 \
   (SI32_PLL_A_SSPR_SSAMP_SETTING1_VALUE << SI32_PLL_A_SSPR_SSAMP_SHIFT)
// Spectrum Spreading set to approximately +/- 0.2% of TDCO.
#define SI32_PLL_A_SSPR_SSAMP_SETTING2_VALUE  2
#define SI32_PLL_A_SSPR_SSAMP_SETTING2_U32 \
   (SI32_PLL_A_SSPR_SSAMP_SETTING2_VALUE << SI32_PLL_A_SSPR_SSAMP_SHIFT)
// Spectrum Spreading set to approximately +/- 0.4% of TDCO.
#define SI32_PLL_A_SSPR_SSAMP_SETTING3_VALUE  3
#define SI32_PLL_A_SSPR_SSAMP_SETTING3_U32 \
   (SI32_PLL_A_SSPR_SSAMP_SETTING3_VALUE << SI32_PLL_A_SSPR_SSAMP_SHIFT)
// Spectrum Spreading set to approximately +/- 0.8% of TDCO.
#define SI32_PLL_A_SSPR_SSAMP_SETTING4_VALUE  4
#define SI32_PLL_A_SSPR_SSAMP_SETTING4_U32 \
   (SI32_PLL_A_SSPR_SSAMP_SETTING4_VALUE << SI32_PLL_A_SSPR_SSAMP_SHIFT)
// Spectrum Spreading set to approximately +/- 1.6% of TDCO.
#define SI32_PLL_A_SSPR_SSAMP_SETTING5_VALUE  5
#define SI32_PLL_A_SSPR_SSAMP_SETTING5_U32 \
   (SI32_PLL_A_SSPR_SSAMP_SETTING5_VALUE << SI32_PLL_A_SSPR_SSAMP_SHIFT)

#define SI32_PLL_A_SSPR_SSUINV_MASK  0x00001F00
#define SI32_PLL_A_SSPR_SSUINV_SHIFT  8



struct SI32_PLL_A_CALCONFIG_Struct
{
   union
   {
      struct
      {
         // DCO Dither Setting
         volatile uint32_t DITHER: 4;
         // DCO Calibration Value
         volatile uint32_t CAL: 12;
         // DCO Range
         volatile uint32_t RANGE: 3;
                  uint32_t reserved0: 13;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PLL_A_CALCONFIG_DITHER_MASK  0x0000000F
#define SI32_PLL_A_CALCONFIG_DITHER_SHIFT  0

#define SI32_PLL_A_CALCONFIG_CAL_MASK  0x0000FFF0
#define SI32_PLL_A_CALCONFIG_CAL_SHIFT  4

#define SI32_PLL_A_CALCONFIG_RANGE_MASK  0x00070000
#define SI32_PLL_A_CALCONFIG_RANGE_SHIFT  16
// DCO operates from 23 to 37 MHz.
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE0_VALUE  0
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE0_U32 \
   (SI32_PLL_A_CALCONFIG_RANGE_RANGE0_VALUE << SI32_PLL_A_CALCONFIG_RANGE_SHIFT)
// DCO operates from 33 to 54 MHz.
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE1_VALUE  1
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE1_U32 \
   (SI32_PLL_A_CALCONFIG_RANGE_RANGE1_VALUE << SI32_PLL_A_CALCONFIG_RANGE_SHIFT)
// DCO operates from 45 to 71 MHz.
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE2_VALUE  2
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE2_U32 \
   (SI32_PLL_A_CALCONFIG_RANGE_RANGE2_VALUE << SI32_PLL_A_CALCONFIG_RANGE_SHIFT)
// DCO operates from 53 to 80 MHz.
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE3_VALUE  3
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE3_U32 \
   (SI32_PLL_A_CALCONFIG_RANGE_RANGE3_VALUE << SI32_PLL_A_CALCONFIG_RANGE_SHIFT)
// DCO operates from 73 to 80 MHz.
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE4_VALUE  4
#define SI32_PLL_A_CALCONFIG_RANGE_RANGE4_U32 \
   (SI32_PLL_A_CALCONFIG_RANGE_RANGE4_VALUE << SI32_PLL_A_CALCONFIG_RANGE_SHIFT)



typedef struct SI32_PLL_A_Struct
{
   struct SI32_PLL_A_DIVIDER_Struct                DIVIDER        ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_PLL_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
   struct SI32_PLL_A_SSPR_Struct                   SSPR           ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_PLL_A_CALCONFIG_Struct              CALCONFIG      ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10[4];
   uint32_t                                        reserved11[4];
   uint32_t                                        reserved12[4];
} SI32_PLL_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PLL_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

