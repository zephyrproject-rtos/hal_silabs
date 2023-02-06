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

#ifndef __SI32_DCDC_A_REGISTERS_H__
#define __SI32_DCDC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_DCDC_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // DC-DC Converter Ready Low Flag
         volatile uint32_t RDYLOWF: 1;
         // DC-DC Converter Ready High Flag
         volatile uint32_t RDYHIGHF: 1;
         // DC-DC Converter Dropout Flag
         volatile uint32_t DROPOUTF: 1;
         // Bandgap Ready Flag
         volatile uint32_t BGRDYF: 1;
                  uint32_t reserved0: 4;
         // Oscillator Disable
         volatile uint32_t OSCDIS: 1;
         // Clock Source Select
         volatile uint32_t CLKSEL: 1;
         // Clock Divider
         volatile uint32_t CLKDIV: 3;
         // ADC Synchronization Enable
         volatile uint32_t ADCSYNCEN: 1;
         // Clock Inversion Enable
         volatile uint32_t CLKINVEN: 1;
         // ADC Clock Inversion Enable
         volatile uint32_t ADCCLKINVEN: 1;
         // Output Voltage Select
         volatile uint32_t OUTVSEL: 5;
                  uint32_t reserved1: 1;
         // Module Interrupt Enable
         volatile uint32_t MIEN: 1;
                  uint32_t reserved2: 1;
         // Minimum Pulse Width Select
         volatile uint32_t MINPWSEL: 2;
         // Power Switch Mode
         volatile uint32_t PSMD: 2;
         // Asynchronous Mode Enable
         volatile uint32_t ASYNCEN: 1;
         // Automatic Bypass Enable
         volatile uint32_t ABEN: 1;
         // Bypass Enable
         volatile uint32_t BEN: 1;
         // DC-DC Converter Enable
         volatile uint32_t DCDCEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DCDC_A_CONTROL_RDYLOWF_MASK  0x00000001
#define SI32_DCDC_A_CONTROL_RDYLOWF_SHIFT  0
// The output voltage (VDC) is below the threshold set in the RDYLOWTH threshold
// field (RDYLOWTH).
#define SI32_DCDC_A_CONTROL_RDYLOWF_NOT_SET_VALUE  0
#define SI32_DCDC_A_CONTROL_RDYLOWF_NOT_SET_U32 \
   (SI32_DCDC_A_CONTROL_RDYLOWF_NOT_SET_VALUE << SI32_DCDC_A_CONTROL_RDYLOWF_SHIFT)
// The output voltage (VDC) is above the threshold set in the RDYLOWTH threshold
// field (RDYLOWTH).
#define SI32_DCDC_A_CONTROL_RDYLOWF_SET_VALUE  1
#define SI32_DCDC_A_CONTROL_RDYLOWF_SET_U32 \
   (SI32_DCDC_A_CONTROL_RDYLOWF_SET_VALUE << SI32_DCDC_A_CONTROL_RDYLOWF_SHIFT)

#define SI32_DCDC_A_CONTROL_RDYHIGHF_MASK  0x00000002
#define SI32_DCDC_A_CONTROL_RDYHIGHF_SHIFT  1
// The output voltage (VDC) has not exceeded 105% of the programmed output value.
#define SI32_DCDC_A_CONTROL_RDYHIGHF_NOT_SET_VALUE  0
#define SI32_DCDC_A_CONTROL_RDYHIGHF_NOT_SET_U32 \
   (SI32_DCDC_A_CONTROL_RDYHIGHF_NOT_SET_VALUE << SI32_DCDC_A_CONTROL_RDYHIGHF_SHIFT)
// The output voltage (VDC) has exceeded 105% of the programmed output value.
#define SI32_DCDC_A_CONTROL_RDYHIGHF_SET_VALUE  1
#define SI32_DCDC_A_CONTROL_RDYHIGHF_SET_U32 \
   (SI32_DCDC_A_CONTROL_RDYHIGHF_SET_VALUE << SI32_DCDC_A_CONTROL_RDYHIGHF_SHIFT)

#define SI32_DCDC_A_CONTROL_DROPOUTF_MASK  0x00000004
#define SI32_DCDC_A_CONTROL_DROPOUTF_SHIFT  2
// The input voltage (VBATDC) is more than 0.4 V above the output voltage (VDC).
// The DC-DC converter is not in dropout.
#define SI32_DCDC_A_CONTROL_DROPOUTF_NOT_SET_VALUE  0
#define SI32_DCDC_A_CONTROL_DROPOUTF_NOT_SET_U32 \
   (SI32_DCDC_A_CONTROL_DROPOUTF_NOT_SET_VALUE << SI32_DCDC_A_CONTROL_DROPOUTF_SHIFT)
// The input voltage (VBATDC) is less than 0.4 V above the output voltage (VDC).
// The DC-DC converter is in dropout, and firmware should enable the bypass switch
// (BEN=1).
#define SI32_DCDC_A_CONTROL_DROPOUTF_SET_VALUE  1
#define SI32_DCDC_A_CONTROL_DROPOUTF_SET_U32 \
   (SI32_DCDC_A_CONTROL_DROPOUTF_SET_VALUE << SI32_DCDC_A_CONTROL_DROPOUTF_SHIFT)

#define SI32_DCDC_A_CONTROL_BGRDYF_MASK  0x00000008
#define SI32_DCDC_A_CONTROL_BGRDYF_SHIFT  3
// The bandgap voltage is not above the threshold.
#define SI32_DCDC_A_CONTROL_BGRDYF_NOT_SET_VALUE  0
#define SI32_DCDC_A_CONTROL_BGRDYF_NOT_SET_U32 \
   (SI32_DCDC_A_CONTROL_BGRDYF_NOT_SET_VALUE << SI32_DCDC_A_CONTROL_BGRDYF_SHIFT)
// The bandgap voltage is above the threshold.
#define SI32_DCDC_A_CONTROL_BGRDYF_SET_VALUE  1
#define SI32_DCDC_A_CONTROL_BGRDYF_SET_U32 \
   (SI32_DCDC_A_CONTROL_BGRDYF_SET_VALUE << SI32_DCDC_A_CONTROL_BGRDYF_SHIFT)

#define SI32_DCDC_A_CONTROL_OSCDIS_MASK  0x00000100
#define SI32_DCDC_A_CONTROL_OSCDIS_SHIFT  8
// Enable the DC-DC local oscillator.
#define SI32_DCDC_A_CONTROL_OSCDIS_INACTIVE_VALUE  0
#define SI32_DCDC_A_CONTROL_OSCDIS_INACTIVE_U32 \
   (SI32_DCDC_A_CONTROL_OSCDIS_INACTIVE_VALUE << SI32_DCDC_A_CONTROL_OSCDIS_SHIFT)
// Disable the DC-DC local oscillator.
#define SI32_DCDC_A_CONTROL_OSCDIS_ACTIVE_VALUE  1
#define SI32_DCDC_A_CONTROL_OSCDIS_ACTIVE_U32 \
   (SI32_DCDC_A_CONTROL_OSCDIS_ACTIVE_VALUE << SI32_DCDC_A_CONTROL_OSCDIS_SHIFT)

#define SI32_DCDC_A_CONTROL_CLKSEL_MASK  0x00000200
#define SI32_DCDC_A_CONTROL_CLKSEL_SHIFT  9
// Select the local DC-DC oscillator as the clock source.
#define SI32_DCDC_A_CONTROL_CLKSEL_DCDCOSC_VALUE  0
#define SI32_DCDC_A_CONTROL_CLKSEL_DCDCOSC_U32 \
   (SI32_DCDC_A_CONTROL_CLKSEL_DCDCOSC_VALUE << SI32_DCDC_A_CONTROL_CLKSEL_SHIFT)
// Select the APB clock as the clock source.
#define SI32_DCDC_A_CONTROL_CLKSEL_APB_VALUE  1
#define SI32_DCDC_A_CONTROL_CLKSEL_APB_U32 \
   (SI32_DCDC_A_CONTROL_CLKSEL_APB_VALUE << SI32_DCDC_A_CONTROL_CLKSEL_SHIFT)

#define SI32_DCDC_A_CONTROL_CLKDIV_MASK  0x00001C00
#define SI32_DCDC_A_CONTROL_CLKDIV_SHIFT  10
// Use the APB clock divided by 1 as the converter switching frequency.
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV1_VALUE  0
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV1_U32 \
   (SI32_DCDC_A_CONTROL_CLKDIV_DIV1_VALUE << SI32_DCDC_A_CONTROL_CLKDIV_SHIFT)
// Use the APB clock divided by 2 as the converter switching frequency.
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV2_VALUE  1
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV2_U32 \
   (SI32_DCDC_A_CONTROL_CLKDIV_DIV2_VALUE << SI32_DCDC_A_CONTROL_CLKDIV_SHIFT)
// Use the APB clock divided by 4 as the converter switching frequency.
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV4_VALUE  2
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV4_U32 \
   (SI32_DCDC_A_CONTROL_CLKDIV_DIV4_VALUE << SI32_DCDC_A_CONTROL_CLKDIV_SHIFT)
// Use the APB clock divided by 8 as the converter switching frequency.
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV8_VALUE  3
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV8_U32 \
   (SI32_DCDC_A_CONTROL_CLKDIV_DIV8_VALUE << SI32_DCDC_A_CONTROL_CLKDIV_SHIFT)
// Use the APB clock divided by 16 as the converter switching frequency.
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV16_VALUE  4
#define SI32_DCDC_A_CONTROL_CLKDIV_DIV16_U32 \
   (SI32_DCDC_A_CONTROL_CLKDIV_DIV16_VALUE << SI32_DCDC_A_CONTROL_CLKDIV_SHIFT)

#define SI32_DCDC_A_CONTROL_ADCSYNCEN_MASK  0x00002000
#define SI32_DCDC_A_CONTROL_ADCSYNCEN_SHIFT  13
// Do not synchronize the ADC to the DC-DC converter.
#define SI32_DCDC_A_CONTROL_ADCSYNCEN_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_ADCSYNCEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_ADCSYNCEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_ADCSYNCEN_SHIFT)
// Synchronize the ADC to the DC-DC converter.
#define SI32_DCDC_A_CONTROL_ADCSYNCEN_ENABLED_VALUE  1
#define SI32_DCDC_A_CONTROL_ADCSYNCEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_ADCSYNCEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_ADCSYNCEN_SHIFT)

#define SI32_DCDC_A_CONTROL_CLKINVEN_MASK  0x00004000
#define SI32_DCDC_A_CONTROL_CLKINVEN_SHIFT  14
// Do not invert the APB clock input.
#define SI32_DCDC_A_CONTROL_CLKINVEN_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_CLKINVEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_CLKINVEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_CLKINVEN_SHIFT)
// Invert the APB clock input.
#define SI32_DCDC_A_CONTROL_CLKINVEN_ENABLED_VALUE  1
#define SI32_DCDC_A_CONTROL_CLKINVEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_CLKINVEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_CLKINVEN_SHIFT)

#define SI32_DCDC_A_CONTROL_ADCCLKINVEN_MASK  0x00008000
#define SI32_DCDC_A_CONTROL_ADCCLKINVEN_SHIFT  15
// Do not invert the ADC clock derived from the DC-DC switching frequency.
#define SI32_DCDC_A_CONTROL_ADCCLKINVEN_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_ADCCLKINVEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_ADCCLKINVEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_ADCCLKINVEN_SHIFT)
// Invert the ADC clock derived from the DC-DC switching frequency.
#define SI32_DCDC_A_CONTROL_ADCCLKINVEN_ENABLED_VALUE  1
#define SI32_DCDC_A_CONTROL_ADCCLKINVEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_ADCCLKINVEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_ADCCLKINVEN_SHIFT)

#define SI32_DCDC_A_CONTROL_OUTVSEL_MASK  0x001F0000
#define SI32_DCDC_A_CONTROL_OUTVSEL_SHIFT  16

#define SI32_DCDC_A_CONTROL_MIEN_MASK  0x00400000
#define SI32_DCDC_A_CONTROL_MIEN_SHIFT  22
// Disable DC-DC module interrupts.
#define SI32_DCDC_A_CONTROL_MIEN_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_MIEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_MIEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_MIEN_SHIFT)
// Enable DC-DC module interrupts.
#define SI32_DCDC_A_CONTROL_MIEN_ENABLED_VALUE  1
#define SI32_DCDC_A_CONTROL_MIEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_MIEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_MIEN_SHIFT)

#define SI32_DCDC_A_CONTROL_MINPWSEL_MASK  0x03000000
#define SI32_DCDC_A_CONTROL_MINPWSEL_SHIFT  24
// Disable pulse skipping.
#define SI32_DCDC_A_CONTROL_MINPWSEL_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_MINPWSEL_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_MINPWSEL_DISABLED_VALUE << SI32_DCDC_A_CONTROL_MINPWSEL_SHIFT)
// Set the minimum pulse width to 10 ns.
#define SI32_DCDC_A_CONTROL_MINPWSEL_10_NS_VALUE  1
#define SI32_DCDC_A_CONTROL_MINPWSEL_10_NS_U32 \
   (SI32_DCDC_A_CONTROL_MINPWSEL_10_NS_VALUE << SI32_DCDC_A_CONTROL_MINPWSEL_SHIFT)
// Set the minimum pulse width to 20 ns.
#define SI32_DCDC_A_CONTROL_MINPWSEL_20_NS_VALUE  2
#define SI32_DCDC_A_CONTROL_MINPWSEL_20_NS_U32 \
   (SI32_DCDC_A_CONTROL_MINPWSEL_20_NS_VALUE << SI32_DCDC_A_CONTROL_MINPWSEL_SHIFT)
// Set the minimum pulse width to 40 ns.
#define SI32_DCDC_A_CONTROL_MINPWSEL_40_NS_VALUE  3
#define SI32_DCDC_A_CONTROL_MINPWSEL_40_NS_U32 \
   (SI32_DCDC_A_CONTROL_MINPWSEL_40_NS_VALUE << SI32_DCDC_A_CONTROL_MINPWSEL_SHIFT)

#define SI32_DCDC_A_CONTROL_PSMD_MASK  0x0C000000
#define SI32_DCDC_A_CONTROL_PSMD_SHIFT  26
// Mode 0. Set the M1 and M2 power switches to each use one MOSFET only.
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL0_VALUE  0
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL0_U32 \
   (SI32_DCDC_A_CONTROL_PSMD_SWSEL0_VALUE << SI32_DCDC_A_CONTROL_PSMD_SHIFT)
// Mode 1. Set the M1 and M2 power switches to each use 2 MOSFETS in parallel.
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL1_VALUE  1
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL1_U32 \
   (SI32_DCDC_A_CONTROL_PSMD_SWSEL1_VALUE << SI32_DCDC_A_CONTROL_PSMD_SHIFT)
// Mode 2. Set the M1 and M2 power switches to each use 3 MOSFETS in parallel.
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL2_VALUE  2
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL2_U32 \
   (SI32_DCDC_A_CONTROL_PSMD_SWSEL2_VALUE << SI32_DCDC_A_CONTROL_PSMD_SHIFT)
// Mode 3. Set the M1 and M2 power switches to each use 4 MOSFETS in parallel.
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL3_VALUE  3
#define SI32_DCDC_A_CONTROL_PSMD_SWSEL3_U32 \
   (SI32_DCDC_A_CONTROL_PSMD_SWSEL3_VALUE << SI32_DCDC_A_CONTROL_PSMD_SHIFT)

#define SI32_DCDC_A_CONTROL_ASYNCEN_MASK  0x10000000
#define SI32_DCDC_A_CONTROL_ASYNCEN_SHIFT  28
// Enable DC-DC synchronous mode.
#define SI32_DCDC_A_CONTROL_ASYNCEN_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_ASYNCEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_ASYNCEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_ASYNCEN_SHIFT)
// Enable DC-DC asynchronous mode.  This mode is more efficient for very light
// output loads.
#define SI32_DCDC_A_CONTROL_ASYNCEN_ENABLED_VALUE  1
#define SI32_DCDC_A_CONTROL_ASYNCEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_ASYNCEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_ASYNCEN_SHIFT)

#define SI32_DCDC_A_CONTROL_ABEN_MASK  0x20000000
#define SI32_DCDC_A_CONTROL_ABEN_SHIFT  29
// Disable automatic bypass.
#define SI32_DCDC_A_CONTROL_ABEN_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_ABEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_ABEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_ABEN_SHIFT)
// Enable automatic bypass.
#define SI32_DCDC_A_CONTROL_ABEN_ENABLED_VALUE  1
#define SI32_DCDC_A_CONTROL_ABEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_ABEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_ABEN_SHIFT)

#define SI32_DCDC_A_CONTROL_BEN_MASK  0x40000000
#define SI32_DCDC_A_CONTROL_BEN_SHIFT  30
// Disable the MBYP bypass switch.
#define SI32_DCDC_A_CONTROL_BEN_DISABLED_VALUE  0
#define SI32_DCDC_A_CONTROL_BEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_BEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_BEN_SHIFT)
// Enable the MBYP bypass switch.
#define SI32_DCDC_A_CONTROL_BEN_ENABLED_VALUE  1
#define SI32_DCDC_A_CONTROL_BEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_BEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_BEN_SHIFT)

#define SI32_DCDC_A_CONTROL_DCDCEN_MASK  0x80000000
#define SI32_DCDC_A_CONTROL_DCDCEN_SHIFT  31
// Disable the DC-DC converter.
#define SI32_DCDC_A_CONTROL_DCDCEN_DISABLED_VALUE  0U
#define SI32_DCDC_A_CONTROL_DCDCEN_DISABLED_U32 \
   (SI32_DCDC_A_CONTROL_DCDCEN_DISABLED_VALUE << SI32_DCDC_A_CONTROL_DCDCEN_SHIFT)
// Enable the DC-DC converter.
#define SI32_DCDC_A_CONTROL_DCDCEN_ENABLED_VALUE  1U
#define SI32_DCDC_A_CONTROL_DCDCEN_ENABLED_U32 \
   (SI32_DCDC_A_CONTROL_DCDCEN_ENABLED_VALUE << SI32_DCDC_A_CONTROL_DCDCEN_SHIFT)



struct SI32_DCDC_A_CONFIG_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 4;
         // Inductor Peak Current Limit
         volatile uint32_t ILIMIT: 3;
                  uint32_t reserved1: 9;
         // Interrupt Mode
         volatile uint32_t INTMD: 2;
                  uint32_t reserved2: 2;
         // Converter Ready Low Threshold
         volatile uint32_t RDYLOWTH: 2;
                  uint32_t reserved3: 10;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DCDC_A_CONFIG_ILIMIT_MASK  0x00000070
#define SI32_DCDC_A_CONFIG_ILIMIT_SHIFT  4
// Limit the peak inductor current to 200 mA.
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT1_VALUE  1
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT1_U32 \
   (SI32_DCDC_A_CONFIG_ILIMIT_LIMIT1_VALUE << SI32_DCDC_A_CONFIG_ILIMIT_SHIFT)
// Limit the peak inductor current to 300 mA.
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT2_VALUE  2
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT2_U32 \
   (SI32_DCDC_A_CONFIG_ILIMIT_LIMIT2_VALUE << SI32_DCDC_A_CONFIG_ILIMIT_SHIFT)
// Limit the peak inductor current to 400 mA.
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT3_VALUE  3
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT3_U32 \
   (SI32_DCDC_A_CONFIG_ILIMIT_LIMIT3_VALUE << SI32_DCDC_A_CONFIG_ILIMIT_SHIFT)
// Limit the peak inductor current to 500 mA.
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT4_VALUE  4
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT4_U32 \
   (SI32_DCDC_A_CONFIG_ILIMIT_LIMIT4_VALUE << SI32_DCDC_A_CONFIG_ILIMIT_SHIFT)
// Limit the peak inductor current to 600 mA.
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT5_VALUE  5
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT5_U32 \
   (SI32_DCDC_A_CONFIG_ILIMIT_LIMIT5_VALUE << SI32_DCDC_A_CONFIG_ILIMIT_SHIFT)
// Limit the peak inductor current to 700 mA.
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT6_VALUE  6
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT6_U32 \
   (SI32_DCDC_A_CONFIG_ILIMIT_LIMIT6_VALUE << SI32_DCDC_A_CONFIG_ILIMIT_SHIFT)
// Limit the peak inductor current to 800 mA.
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT7_VALUE  7
#define SI32_DCDC_A_CONFIG_ILIMIT_LIMIT7_U32 \
   (SI32_DCDC_A_CONFIG_ILIMIT_LIMIT7_VALUE << SI32_DCDC_A_CONFIG_ILIMIT_SHIFT)

#define SI32_DCDC_A_CONFIG_INTMD_MASK  0x00030000
#define SI32_DCDC_A_CONFIG_INTMD_SHIFT  16
// Generate an interrupt when the regulated converter output voltage is too low,
// according to the RDYLOWF flag.
#define SI32_DCDC_A_CONFIG_INTMD_OUTPUT_TOO_LOW_VALUE  0
#define SI32_DCDC_A_CONFIG_INTMD_OUTPUT_TOO_LOW_U32 \
   (SI32_DCDC_A_CONFIG_INTMD_OUTPUT_TOO_LOW_VALUE << SI32_DCDC_A_CONFIG_INTMD_SHIFT)
// Generate an interrupt when the regulated converter output voltage is not too low
// according to the RDYLOWF flag.
#define SI32_DCDC_A_CONFIG_INTMD_OUTPUT_NOT_TOO_LOW_VALUE  1
#define SI32_DCDC_A_CONFIG_INTMD_OUTPUT_NOT_TOO_LOW_U32 \
   (SI32_DCDC_A_CONFIG_INTMD_OUTPUT_NOT_TOO_LOW_VALUE << SI32_DCDC_A_CONFIG_INTMD_SHIFT)
// Generate an interrupt when the output voltage is out of regulation. The
// converter output can be either too high or too low, according to the RDYLOWF and
// RDYHIGHF flags.
#define SI32_DCDC_A_CONFIG_INTMD_OUT_OF_REG_VALUE  2
#define SI32_DCDC_A_CONFIG_INTMD_OUT_OF_REG_U32 \
   (SI32_DCDC_A_CONFIG_INTMD_OUT_OF_REG_VALUE << SI32_DCDC_A_CONFIG_INTMD_SHIFT)
// Generate an interrupt when the output voltage is in regulation.
#define SI32_DCDC_A_CONFIG_INTMD_IN_REG_VALUE  3
#define SI32_DCDC_A_CONFIG_INTMD_IN_REG_U32 \
   (SI32_DCDC_A_CONFIG_INTMD_IN_REG_VALUE << SI32_DCDC_A_CONFIG_INTMD_SHIFT)

#define SI32_DCDC_A_CONFIG_RDYLOWTH_MASK  0x00300000
#define SI32_DCDC_A_CONFIG_RDYLOWTH_SHIFT  20
// Hardware sets the RDYLOWF flag if the regulated output voltage is greater than
// 95% of the programmed output voltage.
#define SI32_DCDC_A_CONFIG_RDYLOWTH_95_PERCENT_VALUE  0
#define SI32_DCDC_A_CONFIG_RDYLOWTH_95_PERCENT_U32 \
   (SI32_DCDC_A_CONFIG_RDYLOWTH_95_PERCENT_VALUE << SI32_DCDC_A_CONFIG_RDYLOWTH_SHIFT)
// Hardware sets the RDYLOWF flag if the regulated output voltage is greater than
// 90% of the programmed output voltage.
#define SI32_DCDC_A_CONFIG_RDYLOWTH_90_PERCENT_VALUE  1
#define SI32_DCDC_A_CONFIG_RDYLOWTH_90_PERCENT_U32 \
   (SI32_DCDC_A_CONFIG_RDYLOWTH_90_PERCENT_VALUE << SI32_DCDC_A_CONFIG_RDYLOWTH_SHIFT)
// Hardware sets the RDYLOWF flag if the regulated output voltage is greater than
// 85% of the programmed output voltage.
#define SI32_DCDC_A_CONFIG_RDYLOWTH_85_PERCENT_VALUE  2
#define SI32_DCDC_A_CONFIG_RDYLOWTH_85_PERCENT_U32 \
   (SI32_DCDC_A_CONFIG_RDYLOWTH_85_PERCENT_VALUE << SI32_DCDC_A_CONFIG_RDYLOWTH_SHIFT)
// Hardware sets the RDYLOWF flag if the regulated output voltage is greater than
// 80% of the programmed output voltage.
#define SI32_DCDC_A_CONFIG_RDYLOWTH_80_PERCENT_VALUE  3
#define SI32_DCDC_A_CONFIG_RDYLOWTH_80_PERCENT_U32 \
   (SI32_DCDC_A_CONFIG_RDYLOWTH_80_PERCENT_VALUE << SI32_DCDC_A_CONFIG_RDYLOWTH_SHIFT)



typedef struct SI32_DCDC_A_Struct
{
   struct SI32_DCDC_A_CONTROL_Struct               CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_DCDC_A_CONFIG_Struct                CONFIG         ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   uint32_t                                        reserved4[4];
   uint32_t                                        reserved5[4];
} SI32_DCDC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_DCDC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

