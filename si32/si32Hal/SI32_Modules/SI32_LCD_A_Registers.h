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

#ifndef __SI32_LCD_A_REGISTERS_H__
#define __SI32_LCD_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_LCD_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Module Enable
         volatile uint32_t LCDEN: 1;
                  uint32_t reserved0: 1;
         // Charge Pump Full Power Drive Mode Enable
         volatile uint32_t CPFPDEN: 1;
         // LCD Missing Clock Detector Enable
         volatile uint32_t MCDEN: 1;
         // RTC Clock Request Enable
         volatile uint32_t RTCCEN: 1;
         // Bias Enable
         volatile uint32_t BIASEN: 1;
         // DCDC Bias Output Enable
         volatile uint32_t DCDCBIASEN: 1;
         // DCDC Bias Standby Enable
         volatile uint32_t DCDCSTDBYEN: 1;
         // Charge Pump Bypass Enable
         volatile uint32_t CPBEN: 1;
         // High-Contrast-Voltage Low-Power Mode Enable
         volatile uint32_t HCVLPMEN: 1;
         // VBAT Monitor Low Power Enable
         volatile uint32_t VBMLPEN: 1;
         // Charge-Pump Oscillator Low-Power Enable
         volatile uint32_t CPOLPEN: 1;
         // Comparator Buffer Low-Power Enable
         volatile uint32_t CMPBLPEN: 1;
         // Bias Switching Enable
         volatile uint32_t BIASSEN: 1;
         // Reference Band Gap Switching Enable
         volatile uint32_t RBGSEN: 1;
                  uint32_t reserved1: 1;
         // Charge-Pump Auto-Contrast Enable
         volatile uint32_t CPACEN: 1;
         // Force Bias Continuous Mode Enable
         volatile uint32_t FBIASCEN: 1;
                  uint32_t reserved2: 6;
         // High-Contrast-Voltage Comparator Bypass Enable
         volatile uint32_t HCVCBYPEN: 1;
         // High-Contrast-Voltage Comparator Force On Enable
         volatile uint32_t HCVCFOEN: 1;
         // High-Contrast-Voltage Comparator Hysteresis
         volatile uint32_t HCVCHMD: 1;
         // High-Contrast-Voltage Comparator Bias
         volatile uint32_t HCVCBMD: 1;
                  uint32_t reserved3: 2;
         // High-Contrast-Voltage Comparator Status
         volatile uint32_t CPCS: 1;
                  uint32_t reserved4: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_CONFIG_LCDEN_MASK  0x00000001
#define SI32_LCD_A_CONFIG_LCDEN_SHIFT  0
// Disable the LCD module.
#define SI32_LCD_A_CONFIG_LCDEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_LCDEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_LCDEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_LCDEN_SHIFT)
// Enable the LCD module.
#define SI32_LCD_A_CONFIG_LCDEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_LCDEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_LCDEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_LCDEN_SHIFT)

#define SI32_LCD_A_CONFIG_CPFPDEN_MASK  0x00000004
#define SI32_LCD_A_CONFIG_CPFPDEN_SHIFT  2
// Disable the LCD charge pump's full power drive mode. The charge pump draws less
// power but operates with reduced output current capabilities.
#define SI32_LCD_A_CONFIG_CPFPDEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_CPFPDEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_CPFPDEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_CPFPDEN_SHIFT)
// Enable the LCD charge pump's full output drive mode. The charge pump operates at
// full power.
#define SI32_LCD_A_CONFIG_CPFPDEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_CPFPDEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_CPFPDEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_CPFPDEN_SHIFT)

#define SI32_LCD_A_CONFIG_MCDEN_MASK  0x00000008
#define SI32_LCD_A_CONFIG_MCDEN_SHIFT  3
// Disable the dedicated LCD missing clock detector.
#define SI32_LCD_A_CONFIG_MCDEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_MCDEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_MCDEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_MCDEN_SHIFT)
// Enable the dedicated LCD missing clock detector.
#define SI32_LCD_A_CONFIG_MCDEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_MCDEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_MCDEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_MCDEN_SHIFT)

#define SI32_LCD_A_CONFIG_RTCCEN_MASK  0x00000010
#define SI32_LCD_A_CONFIG_RTCCEN_SHIFT  4
// The LCD module does not require the RTC clock.
#define SI32_LCD_A_CONFIG_RTCCEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_RTCCEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_RTCCEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_RTCCEN_SHIFT)
// The LCD module requires an active and valid RTC clock (RTC0TCLK).
#define SI32_LCD_A_CONFIG_RTCCEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_RTCCEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_RTCCEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_RTCCEN_SHIFT)

#define SI32_LCD_A_CONFIG_BIASEN_MASK  0x00000020
#define SI32_LCD_A_CONFIG_BIASEN_SHIFT  5
// Disable the LCD bias current.
#define SI32_LCD_A_CONFIG_BIASEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_BIASEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_BIASEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_BIASEN_SHIFT)
// Enable the LCD bias current.
#define SI32_LCD_A_CONFIG_BIASEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_BIASEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_BIASEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_BIASEN_SHIFT)

#define SI32_LCD_A_CONFIG_DCDCBIASEN_MASK  0x00000040
#define SI32_LCD_A_CONFIG_DCDCBIASEN_SHIFT  6
// Disable the secondary bias current output.
#define SI32_LCD_A_CONFIG_DCDCBIASEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_DCDCBIASEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_DCDCBIASEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_DCDCBIASEN_SHIFT)
// Enable the secondary bias current output.
#define SI32_LCD_A_CONFIG_DCDCBIASEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_DCDCBIASEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_DCDCBIASEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_DCDCBIASEN_SHIFT)

#define SI32_LCD_A_CONFIG_DCDCSTDBYEN_MASK  0x00000080
#define SI32_LCD_A_CONFIG_DCDCSTDBYEN_SHIFT  7
// The DCDC bias is enabled in Power Mode 8.
#define SI32_LCD_A_CONFIG_DCDCSTDBYEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_DCDCSTDBYEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_DCDCSTDBYEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_DCDCSTDBYEN_SHIFT)
// The DCDC bias is disabled in Power Mode 8.
#define SI32_LCD_A_CONFIG_DCDCSTDBYEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_DCDCSTDBYEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_DCDCSTDBYEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_DCDCSTDBYEN_SHIFT)

#define SI32_LCD_A_CONFIG_CPBEN_MASK  0x00000100
#define SI32_LCD_A_CONFIG_CPBEN_SHIFT  8
// The LCD charge pump generates the VLCD voltage.
#define SI32_LCD_A_CONFIG_CPBEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_CPBEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_CPBEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_CPBEN_SHIFT)
// Bypass the LCD charge pump and connect VLCD directly to VBAT.
#define SI32_LCD_A_CONFIG_CPBEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_CPBEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_CPBEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_CPBEN_SHIFT)

#define SI32_LCD_A_CONFIG_HCVLPMEN_MASK  0x00000200
#define SI32_LCD_A_CONFIG_HCVLPMEN_SHIFT  9
// Disable the high-contrast-voltage low-power mode.
#define SI32_LCD_A_CONFIG_HCVLPMEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_HCVLPMEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_HCVLPMEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_HCVLPMEN_SHIFT)
// Enable the high-contrast-voltage low-power mode. This mode reduces power
// consumption when VLCD is higher than VBAT.
#define SI32_LCD_A_CONFIG_HCVLPMEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_HCVLPMEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_HCVLPMEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_HCVLPMEN_SHIFT)

#define SI32_LCD_A_CONFIG_VBMLPEN_MASK  0x00000400
#define SI32_LCD_A_CONFIG_VBMLPEN_SHIFT  10
// Disable the LCD VBAT Monitor low power mode.
#define SI32_LCD_A_CONFIG_VBMLPEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_VBMLPEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_VBMLPEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_VBMLPEN_SHIFT)
// Enable the LCD VBAT Monitor low power mode.
#define SI32_LCD_A_CONFIG_VBMLPEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_VBMLPEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_VBMLPEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_VBMLPEN_SHIFT)

#define SI32_LCD_A_CONFIG_CPOLPEN_MASK  0x00000800
#define SI32_LCD_A_CONFIG_CPOLPEN_SHIFT  11
// Disable the charge-pump oscillator low-power mode.
#define SI32_LCD_A_CONFIG_CPOLPEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_CPOLPEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_CPOLPEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_CPOLPEN_SHIFT)
// Enable the charge-pump oscillator low-power mode.
#define SI32_LCD_A_CONFIG_CPOLPEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_CPOLPEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_CPOLPEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_CPOLPEN_SHIFT)

#define SI32_LCD_A_CONFIG_CMPBLPEN_MASK  0x00001000
#define SI32_LCD_A_CONFIG_CMPBLPEN_SHIFT  12
// Disable the comparator buffer low-power mode.
#define SI32_LCD_A_CONFIG_CMPBLPEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_CMPBLPEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_CMPBLPEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_CMPBLPEN_SHIFT)
// Enable the comparator buffer low-power mode.
#define SI32_LCD_A_CONFIG_CMPBLPEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_CMPBLPEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_CMPBLPEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_CMPBLPEN_SHIFT)

#define SI32_LCD_A_CONFIG_BIASSEN_MASK  0x00002000
#define SI32_LCD_A_CONFIG_BIASSEN_SHIFT  13
// Disable bias switching.
#define SI32_LCD_A_CONFIG_BIASSEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_BIASSEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_BIASSEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_BIASSEN_SHIFT)
// Enable bias switching.
#define SI32_LCD_A_CONFIG_BIASSEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_BIASSEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_BIASSEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_BIASSEN_SHIFT)

#define SI32_LCD_A_CONFIG_RBGSEN_MASK  0x00004000
#define SI32_LCD_A_CONFIG_RBGSEN_SHIFT  14
// Disable reference band gap switching mode.
#define SI32_LCD_A_CONFIG_RBGSEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_RBGSEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_RBGSEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_RBGSEN_SHIFT)
// Enable reference band gap switching mode.
#define SI32_LCD_A_CONFIG_RBGSEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_RBGSEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_RBGSEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_RBGSEN_SHIFT)

#define SI32_LCD_A_CONFIG_CPACEN_MASK  0x00010000
#define SI32_LCD_A_CONFIG_CPACEN_SHIFT  16
// VLCD continues to track VBAT when VBAT drops below the programmed VLCD value.
#define SI32_LCD_A_CONFIG_CPACEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_CPACEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_CPACEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_CPACEN_SHIFT)
// The module automatically enables the charge pump and maintains the VLCD voltage
// when VBAT drops below the programmed VBAT monitor level.
#define SI32_LCD_A_CONFIG_CPACEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_CPACEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_CPACEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_CPACEN_SHIFT)

#define SI32_LCD_A_CONFIG_FBIASCEN_MASK  0x00020000
#define SI32_LCD_A_CONFIG_FBIASCEN_SHIFT  17
// The bias operates as configured.
#define SI32_LCD_A_CONFIG_FBIASCEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_FBIASCEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_FBIASCEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_FBIASCEN_SHIFT)
// Force the bias to operate in continuous mode. The bias will cleanly transition
// from its configuration settings to continuous mode.
#define SI32_LCD_A_CONFIG_FBIASCEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_FBIASCEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_FBIASCEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_FBIASCEN_SHIFT)

#define SI32_LCD_A_CONFIG_HCVCBYPEN_MASK  0x01000000
#define SI32_LCD_A_CONFIG_HCVCBYPEN_SHIFT  24
// Hardware enables the high-contrast-voltage comparator as needed.
#define SI32_LCD_A_CONFIG_HCVCBYPEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_HCVCBYPEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_HCVCBYPEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_HCVCBYPEN_SHIFT)
// High-contrast-voltage comparator in bypass mode.
#define SI32_LCD_A_CONFIG_HCVCBYPEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_HCVCBYPEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_HCVCBYPEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_HCVCBYPEN_SHIFT)

#define SI32_LCD_A_CONFIG_HCVCFOEN_MASK  0x02000000
#define SI32_LCD_A_CONFIG_HCVCFOEN_SHIFT  25
// Hardware enables the high-contrast-voltage comparator as needed.
#define SI32_LCD_A_CONFIG_HCVCFOEN_DISABLED_VALUE  0
#define SI32_LCD_A_CONFIG_HCVCFOEN_DISABLED_U32 \
   (SI32_LCD_A_CONFIG_HCVCFOEN_DISABLED_VALUE << SI32_LCD_A_CONFIG_HCVCFOEN_SHIFT)
// High-contrast-voltage comparator force on enabled.
#define SI32_LCD_A_CONFIG_HCVCFOEN_ENABLED_VALUE  1
#define SI32_LCD_A_CONFIG_HCVCFOEN_ENABLED_U32 \
   (SI32_LCD_A_CONFIG_HCVCFOEN_ENABLED_VALUE << SI32_LCD_A_CONFIG_HCVCFOEN_SHIFT)

#define SI32_LCD_A_CONFIG_HCVCHMD_MASK  0x04000000
#define SI32_LCD_A_CONFIG_HCVCHMD_SHIFT  26
// Set the high-contrast-voltage comparator to high-hysteresis mode. This is the
// recommended setting.
#define SI32_LCD_A_CONFIG_HCVCHMD_HIGH_VALUE  0
#define SI32_LCD_A_CONFIG_HCVCHMD_HIGH_U32 \
   (SI32_LCD_A_CONFIG_HCVCHMD_HIGH_VALUE << SI32_LCD_A_CONFIG_HCVCHMD_SHIFT)
// Set the high-contrast-voltage comparator to low-hysteresis mode.
#define SI32_LCD_A_CONFIG_HCVCHMD_LOW_VALUE  1
#define SI32_LCD_A_CONFIG_HCVCHMD_LOW_U32 \
   (SI32_LCD_A_CONFIG_HCVCHMD_LOW_VALUE << SI32_LCD_A_CONFIG_HCVCHMD_SHIFT)

#define SI32_LCD_A_CONFIG_HCVCBMD_MASK  0x08000000
#define SI32_LCD_A_CONFIG_HCVCBMD_SHIFT  27
// Set the high-contrast-voltage comparator to high bias mode.
#define SI32_LCD_A_CONFIG_HCVCBMD_HIGH_VALUE  0
#define SI32_LCD_A_CONFIG_HCVCBMD_HIGH_U32 \
   (SI32_LCD_A_CONFIG_HCVCBMD_HIGH_VALUE << SI32_LCD_A_CONFIG_HCVCBMD_SHIFT)
// Set the high-contrast-voltage comparator to low-bias mode. This is the
// recommended setting.
#define SI32_LCD_A_CONFIG_HCVCBMD_LOW_VALUE  1
#define SI32_LCD_A_CONFIG_HCVCBMD_LOW_U32 \
   (SI32_LCD_A_CONFIG_HCVCBMD_LOW_VALUE << SI32_LCD_A_CONFIG_HCVCBMD_SHIFT)

#define SI32_LCD_A_CONFIG_CPCS_MASK  0x40000000
#define SI32_LCD_A_CONFIG_CPCS_SHIFT  30
// VBAT is greater than VLCD.
#define SI32_LCD_A_CONFIG_CPCS_VBAT_VALUE  0
#define SI32_LCD_A_CONFIG_CPCS_VBAT_U32 \
   (SI32_LCD_A_CONFIG_CPCS_VBAT_VALUE << SI32_LCD_A_CONFIG_CPCS_SHIFT)
// VLCD is greater than VBAT.
#define SI32_LCD_A_CONFIG_CPCS_VLCD_VALUE  1
#define SI32_LCD_A_CONFIG_CPCS_VLCD_U32 \
   (SI32_LCD_A_CONFIG_CPCS_VLCD_VALUE << SI32_LCD_A_CONFIG_CPCS_SHIFT)



struct SI32_LCD_A_CLKCONTROL_Struct
{
   union
   {
      struct
      {
         // Clock Divider
         volatile uint32_t CLKDIV: 10;
                  uint32_t reserved0: 18;
         // RTC Input Clock Divider
         volatile uint32_t RTCCLKDIV: 2;
                  uint32_t reserved1: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_CLKCONTROL_CLKDIV_MASK  0x000003FF
#define SI32_LCD_A_CLKCONTROL_CLKDIV_SHIFT  0

#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_MASK  0x30000000
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_SHIFT  28
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_1_VALUE  0
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_1_U32 \
   (SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_1_VALUE << SI32_LCD_A_CLKCONTROL_RTCCLKDIV_SHIFT)
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_2_VALUE  1
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_2_U32 \
   (SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_2_VALUE << SI32_LCD_A_CLKCONTROL_RTCCLKDIV_SHIFT)
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_4_VALUE  2
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_4_U32 \
   (SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_4_VALUE << SI32_LCD_A_CLKCONTROL_RTCCLKDIV_SHIFT)
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_8_VALUE  3
#define SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_8_U32 \
   (SI32_LCD_A_CLKCONTROL_RTCCLKDIV_DIVIDE_BY_8_VALUE << SI32_LCD_A_CLKCONTROL_RTCCLKDIV_SHIFT)



struct SI32_LCD_A_BLKCONTROL_Struct
{
   union
   {
      struct
      {
         // Hardware Blinking Enable
         volatile uint8_t BLKMASK;
         // Hardware Blinking Rate Divider Exponent
         volatile uint32_t BLKREXP: 4;
                  uint32_t reserved0: 20;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_BLKCONTROL_BLKMASK_MASK  0x000000FF
#define SI32_LCD_A_BLKCONTROL_BLKMASK_SHIFT  0

#define SI32_LCD_A_BLKCONTROL_BLKREXP_MASK  0x00000F00
#define SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT  8
// Set blink rate divider to divide by 2.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_2_VALUE  2
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_2_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_2_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 4.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_4_VALUE  3
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_4_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_4_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 8.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_8_VALUE  4
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_8_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_8_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 16.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_16_VALUE  5
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_16_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_16_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 32.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_32_VALUE  6
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_32_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_32_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 64.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_64_VALUE  7
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_64_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_64_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 128.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_128_VALUE  8
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_128_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_128_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 256.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_256_VALUE  9
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_256_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_256_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 512.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_512_VALUE  10
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_512_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_512_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 1024.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_1024_VALUE  11
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_1024_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_1024_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 2048.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_2048_VALUE  12
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_2048_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_2048_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)
// Set blink rate divider to divide by 4096.
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_4096_VALUE  13
#define SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_4096_U32 \
   (SI32_LCD_A_BLKCONTROL_BLKREXP_DIVIDE_BY_4096_VALUE << SI32_LCD_A_BLKCONTROL_BLKREXP_SHIFT)



struct SI32_LCD_A_SEGCONTROL_Struct
{
   union
   {
      struct
      {
         // Hardware Bias Mode
         volatile uint32_t BIASMD: 1;
         // Segment Mode
         volatile uint32_t SEGMD: 2;
                  uint32_t reserved0: 1;
         // Segment Blank Enable
         volatile uint32_t BLANKEN: 1;
         // Reset Phase Enable
         volatile uint32_t RPHEN: 1;
         // Reset Phase Mode
         volatile uint32_t RPHMD: 3;
                  uint32_t reserved1: 23;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGCONTROL_BIASMD_MASK  0x00000001
#define SI32_LCD_A_SEGCONTROL_BIASMD_SHIFT  0
// Select 1/3 bias. Use for three-mux segment mode and four-mux segment mode.
#define SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE  0
#define SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_U32 \
   (SI32_LCD_A_SEGCONTROL_BIASMD_ONE_THIRD_VALUE << SI32_LCD_A_SEGCONTROL_BIASMD_SHIFT)
// Select 1/2 bias. Use for two-mux segment mode.
#define SI32_LCD_A_SEGCONTROL_BIASMD_ONE_HALF_VALUE  1
#define SI32_LCD_A_SEGCONTROL_BIASMD_ONE_HALF_U32 \
   (SI32_LCD_A_SEGCONTROL_BIASMD_ONE_HALF_VALUE << SI32_LCD_A_SEGCONTROL_BIASMD_SHIFT)

#define SI32_LCD_A_SEGCONTROL_SEGMD_MASK  0x00000006
#define SI32_LCD_A_SEGCONTROL_SEGMD_SHIFT  1
// Select static segment mode with one common COMn.0 used.
#define SI32_LCD_A_SEGCONTROL_SEGMD_STATIC_VALUE  0
#define SI32_LCD_A_SEGCONTROL_SEGMD_STATIC_U32 \
   (SI32_LCD_A_SEGCONTROL_SEGMD_STATIC_VALUE << SI32_LCD_A_SEGCONTROL_SEGMD_SHIFT)
// Select two-mux segment mode with two commons (COMn.0 and COMn.1) used.
#define SI32_LCD_A_SEGCONTROL_SEGMD_2_MUX_VALUE  1
#define SI32_LCD_A_SEGCONTROL_SEGMD_2_MUX_U32 \
   (SI32_LCD_A_SEGCONTROL_SEGMD_2_MUX_VALUE << SI32_LCD_A_SEGCONTROL_SEGMD_SHIFT)
// Select three-mux segment mode with three commons (COMn.0, COMn.1, COMn.2) used.
#define SI32_LCD_A_SEGCONTROL_SEGMD_3_MUX_VALUE  2
#define SI32_LCD_A_SEGCONTROL_SEGMD_3_MUX_U32 \
   (SI32_LCD_A_SEGCONTROL_SEGMD_3_MUX_VALUE << SI32_LCD_A_SEGCONTROL_SEGMD_SHIFT)
// Select four-mux segment mode with four commons (COMn.0, COMn.1, COMn.2 and
// COMn.3) used.
#define SI32_LCD_A_SEGCONTROL_SEGMD_4_MUX_VALUE  3
#define SI32_LCD_A_SEGCONTROL_SEGMD_4_MUX_U32 \
   (SI32_LCD_A_SEGCONTROL_SEGMD_4_MUX_VALUE << SI32_LCD_A_SEGCONTROL_SEGMD_SHIFT)

#define SI32_LCD_A_SEGCONTROL_BLANKEN_MASK  0x00000010
#define SI32_LCD_A_SEGCONTROL_BLANKEN_SHIFT  4
// Operate segments normally.
#define SI32_LCD_A_SEGCONTROL_BLANKEN_DISABLED_VALUE  0
#define SI32_LCD_A_SEGCONTROL_BLANKEN_DISABLED_U32 \
   (SI32_LCD_A_SEGCONTROL_BLANKEN_DISABLED_VALUE << SI32_LCD_A_SEGCONTROL_BLANKEN_SHIFT)
// Blank the LCD by disabling all LCD segment and common pins.
#define SI32_LCD_A_SEGCONTROL_BLANKEN_ENABLED_VALUE  1
#define SI32_LCD_A_SEGCONTROL_BLANKEN_ENABLED_U32 \
   (SI32_LCD_A_SEGCONTROL_BLANKEN_ENABLED_VALUE << SI32_LCD_A_SEGCONTROL_BLANKEN_SHIFT)

#define SI32_LCD_A_SEGCONTROL_RPHEN_MASK  0x00000020
#define SI32_LCD_A_SEGCONTROL_RPHEN_SHIFT  5
// Hardware switches the LCD segment and common pin controls directly from one
// state to another.
#define SI32_LCD_A_SEGCONTROL_RPHEN_DISABLED_VALUE  0
#define SI32_LCD_A_SEGCONTROL_RPHEN_DISABLED_U32 \
   (SI32_LCD_A_SEGCONTROL_RPHEN_DISABLED_VALUE << SI32_LCD_A_SEGCONTROL_RPHEN_SHIFT)
// Hardware switches the LCD segment and common pin controls to intermediate states
// for several RTC clock cycles before switching to the next state.
#define SI32_LCD_A_SEGCONTROL_RPHEN_ENABLED_VALUE  1
#define SI32_LCD_A_SEGCONTROL_RPHEN_ENABLED_U32 \
   (SI32_LCD_A_SEGCONTROL_RPHEN_ENABLED_VALUE << SI32_LCD_A_SEGCONTROL_RPHEN_SHIFT)

#define SI32_LCD_A_SEGCONTROL_RPHMD_MASK  0x000001C0
#define SI32_LCD_A_SEGCONTROL_RPHMD_SHIFT  6



struct SI32_LCD_A_CTRSTCONTROL_Struct
{
   union
   {
      struct
      {
         // Contrast Voltage
         volatile uint32_t CTRST: 5;
                  uint32_t reserved0: 11;
         // Contrast Busy Flag
         volatile uint32_t CTRSTBF: 1;
                  uint32_t reserved1: 12;
         // Charge Pump Capacitor Divider Enable
         volatile uint32_t CPCDEN: 1;
                  uint32_t reserved2: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_CTRSTCONTROL_CTRST_MASK  0x0000001F
#define SI32_LCD_A_CTRSTCONTROL_CTRST_SHIFT  0

#define SI32_LCD_A_CTRSTCONTROL_CTRSTBF_MASK  0x00010000
#define SI32_LCD_A_CTRSTCONTROL_CTRSTBF_SHIFT  16
// An update of the internal contrast registers is not in progress.
#define SI32_LCD_A_CTRSTCONTROL_CTRSTBF_NOT_SET_VALUE  0
#define SI32_LCD_A_CTRSTCONTROL_CTRSTBF_NOT_SET_U32 \
   (SI32_LCD_A_CTRSTCONTROL_CTRSTBF_NOT_SET_VALUE << SI32_LCD_A_CTRSTCONTROL_CTRSTBF_SHIFT)
// The internal contrast registers are busy updating.
#define SI32_LCD_A_CTRSTCONTROL_CTRSTBF_SET_VALUE  1
#define SI32_LCD_A_CTRSTCONTROL_CTRSTBF_SET_U32 \
   (SI32_LCD_A_CTRSTCONTROL_CTRSTBF_SET_VALUE << SI32_LCD_A_CTRSTCONTROL_CTRSTBF_SHIFT)

#define SI32_LCD_A_CTRSTCONTROL_CPCDEN_MASK  0x20000000
#define SI32_LCD_A_CTRSTCONTROL_CPCDEN_SHIFT  29
// Disable the charge pump capacitor divider.
#define SI32_LCD_A_CTRSTCONTROL_CPCDEN_DISABLED_VALUE  0
#define SI32_LCD_A_CTRSTCONTROL_CPCDEN_DISABLED_U32 \
   (SI32_LCD_A_CTRSTCONTROL_CPCDEN_DISABLED_VALUE << SI32_LCD_A_CTRSTCONTROL_CPCDEN_SHIFT)
// Enable the charge pump capacitor divider.
#define SI32_LCD_A_CTRSTCONTROL_CPCDEN_ENABLED_VALUE  1
#define SI32_LCD_A_CTRSTCONTROL_CPCDEN_ENABLED_U32 \
   (SI32_LCD_A_CTRSTCONTROL_CPCDEN_ENABLED_VALUE << SI32_LCD_A_CTRSTCONTROL_CPCDEN_SHIFT)



struct SI32_LCD_A_VBMCONTROL_Struct
{
   union
   {
      struct
      {
         // VBAT Monitor Threshold
         volatile uint32_t VBMTH: 5;
                  uint32_t reserved0: 11;
         // VBAT Monitor Busy Flag
         volatile uint32_t VBMBF: 1;
                  uint32_t reserved1: 5;
         // VBAT Monitor Clock Divider
         volatile uint32_t VBMCLKDIV: 3;
                  uint32_t reserved2: 4;
         // VBAT Monitor Capacitor Divider Enable
         volatile uint32_t VBMCDEN: 1;
         // VBAT Monitor Offset Enable
         volatile uint32_t VBMOEN: 1;
         // VBAT Monitor Enable
         volatile uint32_t VBMEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_VBMCONTROL_VBMTH_MASK  0x0000001F
#define SI32_LCD_A_VBMCONTROL_VBMTH_SHIFT  0

#define SI32_LCD_A_VBMCONTROL_VBMBF_MASK  0x00010000
#define SI32_LCD_A_VBMCONTROL_VBMBF_SHIFT  16
// An update of the internal VBAT monitor registers is not in progress.
#define SI32_LCD_A_VBMCONTROL_VBMBF_NOT_SET_VALUE  0
#define SI32_LCD_A_VBMCONTROL_VBMBF_NOT_SET_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMBF_NOT_SET_VALUE << SI32_LCD_A_VBMCONTROL_VBMBF_SHIFT)
// The internal VBAT monitor registers are busy updating.
#define SI32_LCD_A_VBMCONTROL_VBMBF_SET_VALUE  1
#define SI32_LCD_A_VBMCONTROL_VBMBF_SET_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMBF_SET_VALUE << SI32_LCD_A_VBMCONTROL_VBMBF_SHIFT)

#define SI32_LCD_A_VBMCONTROL_VBMCLKDIV_MASK  0x01C00000
#define SI32_LCD_A_VBMCONTROL_VBMCLKDIV_SHIFT  22

#define SI32_LCD_A_VBMCONTROL_VBMCDEN_MASK  0x20000000
#define SI32_LCD_A_VBMCONTROL_VBMCDEN_SHIFT  29
// Disable the VBAT monitor capacitor divider.
#define SI32_LCD_A_VBMCONTROL_VBMCDEN_DISABLED_VALUE  0
#define SI32_LCD_A_VBMCONTROL_VBMCDEN_DISABLED_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMCDEN_DISABLED_VALUE << SI32_LCD_A_VBMCONTROL_VBMCDEN_SHIFT)
// Enable the VBAT monitor capacitor divider.
#define SI32_LCD_A_VBMCONTROL_VBMCDEN_ENABLED_VALUE  1
#define SI32_LCD_A_VBMCONTROL_VBMCDEN_ENABLED_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMCDEN_ENABLED_VALUE << SI32_LCD_A_VBMCONTROL_VBMCDEN_SHIFT)

#define SI32_LCD_A_VBMCONTROL_VBMOEN_MASK  0x40000000
#define SI32_LCD_A_VBMCONTROL_VBMOEN_SHIFT  30
// The VBAT monitor threshold set by the VBMTH field functions as an absolute
// threshold value for the VBAT monitor.
#define SI32_LCD_A_VBMCONTROL_VBMOEN_DISABLED_VALUE  0
#define SI32_LCD_A_VBMCONTROL_VBMOEN_DISABLED_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMOEN_DISABLED_VALUE << SI32_LCD_A_VBMCONTROL_VBMOEN_SHIFT)
// The VBAT monitor threshold set by the VBMTH field functions as an offset to the
// LCD contrast value set by CTRSTMD.
#define SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_VALUE  1
#define SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMOEN_ENABLED_VALUE << SI32_LCD_A_VBMCONTROL_VBMOEN_SHIFT)

#define SI32_LCD_A_VBMCONTROL_VBMEN_MASK  0x80000000
#define SI32_LCD_A_VBMCONTROL_VBMEN_SHIFT  31
// Disable the VBAT monitor.
#define SI32_LCD_A_VBMCONTROL_VBMEN_DISABLED_VALUE  0U
#define SI32_LCD_A_VBMCONTROL_VBMEN_DISABLED_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMEN_DISABLED_VALUE << SI32_LCD_A_VBMCONTROL_VBMEN_SHIFT)
// Enable the VBAT monitor.
#define SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_VALUE  1U
#define SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_U32 \
   (SI32_LCD_A_VBMCONTROL_VBMEN_ENABLED_VALUE << SI32_LCD_A_VBMCONTROL_VBMEN_SHIFT)



struct SI32_LCD_A_SEGMASK0_Struct
{
   union
   {
      struct
      {
         // Segment Enable
         volatile uint32_t SEGEN;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGMASK0_SEGEN_MASK  0xFFFFFFFF
#define SI32_LCD_A_SEGMASK0_SEGEN_SHIFT  0



struct SI32_LCD_A_SEGMASK1_Struct
{
   union
   {
      struct
      {
         // Segment Enable
         volatile uint8_t SEGEN;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGMASK1_SEGEN_MASK  0x000000FF
#define SI32_LCD_A_SEGMASK1_SEGEN_SHIFT  0



struct SI32_LCD_A_SEGDATA0_Struct
{
   union
   {
      // This is a Union register
      volatile uint8_t  U8[4];
      volatile uint16_t U16[2];
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGDATA0_SEGPIN0_MASK  0x0000000F
#define SI32_LCD_A_SEGDATA0_SEGPIN0_SHIFT  0

#define SI32_LCD_A_SEGDATA0_SEGPIN1_MASK  0x000000F0
#define SI32_LCD_A_SEGDATA0_SEGPIN1_SHIFT  4

#define SI32_LCD_A_SEGDATA0_SEGPIN2_MASK  0x00000F00
#define SI32_LCD_A_SEGDATA0_SEGPIN2_SHIFT  8

#define SI32_LCD_A_SEGDATA0_SEGPIN3_MASK  0x0000F000
#define SI32_LCD_A_SEGDATA0_SEGPIN3_SHIFT  12

#define SI32_LCD_A_SEGDATA0_SEGPIN4_MASK  0x000F0000
#define SI32_LCD_A_SEGDATA0_SEGPIN4_SHIFT  16

#define SI32_LCD_A_SEGDATA0_SEGPIN5_MASK  0x00F00000
#define SI32_LCD_A_SEGDATA0_SEGPIN5_SHIFT  20

#define SI32_LCD_A_SEGDATA0_SEGPIN6_MASK  0x0F000000
#define SI32_LCD_A_SEGDATA0_SEGPIN6_SHIFT  24

#define SI32_LCD_A_SEGDATA0_SEGPIN7_MASK  0xF0000000
#define SI32_LCD_A_SEGDATA0_SEGPIN7_SHIFT  28



struct SI32_LCD_A_SEGDATA1_Struct
{
   union
   {
      // This is a Union register
      volatile uint8_t  U8[4];
      volatile uint16_t U16[2];
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGDATA1_SEGPIN8_MASK  0x0000000F
#define SI32_LCD_A_SEGDATA1_SEGPIN8_SHIFT  0

#define SI32_LCD_A_SEGDATA1_SEGPIN9_MASK  0x000000F0
#define SI32_LCD_A_SEGDATA1_SEGPIN9_SHIFT  4

#define SI32_LCD_A_SEGDATA1_SEGPIN10_MASK  0x00000F00
#define SI32_LCD_A_SEGDATA1_SEGPIN10_SHIFT  8

#define SI32_LCD_A_SEGDATA1_SEGPIN11_MASK  0x0000F000
#define SI32_LCD_A_SEGDATA1_SEGPIN11_SHIFT  12

#define SI32_LCD_A_SEGDATA1_SEGPIN12_MASK  0x000F0000
#define SI32_LCD_A_SEGDATA1_SEGPIN12_SHIFT  16

#define SI32_LCD_A_SEGDATA1_SEGPIN13_MASK  0x00F00000
#define SI32_LCD_A_SEGDATA1_SEGPIN13_SHIFT  20

#define SI32_LCD_A_SEGDATA1_SEGPIN14_MASK  0x0F000000
#define SI32_LCD_A_SEGDATA1_SEGPIN14_SHIFT  24

#define SI32_LCD_A_SEGDATA1_SEGPIN15_MASK  0xF0000000
#define SI32_LCD_A_SEGDATA1_SEGPIN15_SHIFT  28



struct SI32_LCD_A_SEGDATA2_Struct
{
   union
   {
      // This is a Union register
      volatile uint8_t  U8[4];
      volatile uint16_t U16[2];
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGDATA2_SEGPIN16_MASK  0x0000000F
#define SI32_LCD_A_SEGDATA2_SEGPIN16_SHIFT  0

#define SI32_LCD_A_SEGDATA2_SEGPIN17_MASK  0x000000F0
#define SI32_LCD_A_SEGDATA2_SEGPIN17_SHIFT  4

#define SI32_LCD_A_SEGDATA2_SEGPIN18_MASK  0x00000F00
#define SI32_LCD_A_SEGDATA2_SEGPIN18_SHIFT  8

#define SI32_LCD_A_SEGDATA2_SEGPIN19_MASK  0x0000F000
#define SI32_LCD_A_SEGDATA2_SEGPIN19_SHIFT  12

#define SI32_LCD_A_SEGDATA2_SEGPIN20_MASK  0x000F0000
#define SI32_LCD_A_SEGDATA2_SEGPIN20_SHIFT  16

#define SI32_LCD_A_SEGDATA2_SEGPIN21_MASK  0x00F00000
#define SI32_LCD_A_SEGDATA2_SEGPIN21_SHIFT  20

#define SI32_LCD_A_SEGDATA2_SEGPIN22_MASK  0x0F000000
#define SI32_LCD_A_SEGDATA2_SEGPIN22_SHIFT  24

#define SI32_LCD_A_SEGDATA2_SEGPIN23_MASK  0xF0000000
#define SI32_LCD_A_SEGDATA2_SEGPIN23_SHIFT  28



struct SI32_LCD_A_SEGDATA3_Struct
{
   union
   {
      // This is a Union register
      volatile uint8_t  U8[4];
      volatile uint16_t U16[2];
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGDATA3_SEGPIN24_MASK  0x0000000F
#define SI32_LCD_A_SEGDATA3_SEGPIN24_SHIFT  0

#define SI32_LCD_A_SEGDATA3_SEGPIN25_MASK  0x000000F0
#define SI32_LCD_A_SEGDATA3_SEGPIN25_SHIFT  4

#define SI32_LCD_A_SEGDATA3_SEGPIN26_MASK  0x00000F00
#define SI32_LCD_A_SEGDATA3_SEGPIN26_SHIFT  8

#define SI32_LCD_A_SEGDATA3_SEGPIN27_MASK  0x0000F000
#define SI32_LCD_A_SEGDATA3_SEGPIN27_SHIFT  12

#define SI32_LCD_A_SEGDATA3_SEGPIN28_MASK  0x000F0000
#define SI32_LCD_A_SEGDATA3_SEGPIN28_SHIFT  16

#define SI32_LCD_A_SEGDATA3_SEGPIN29_MASK  0x00F00000
#define SI32_LCD_A_SEGDATA3_SEGPIN29_SHIFT  20

#define SI32_LCD_A_SEGDATA3_SEGPIN30_MASK  0x0F000000
#define SI32_LCD_A_SEGDATA3_SEGPIN30_SHIFT  24

#define SI32_LCD_A_SEGDATA3_SEGPIN31_MASK  0xF0000000
#define SI32_LCD_A_SEGDATA3_SEGPIN31_SHIFT  28



struct SI32_LCD_A_SEGDATA4_Struct
{
   union
   {
      // This is a Union register
      volatile uint8_t  U8[4];
      volatile uint16_t U16[2];
      volatile uint32_t U32;
   };
};

#define SI32_LCD_A_SEGDATA4_SEGPIN32_MASK  0x0000000F
#define SI32_LCD_A_SEGDATA4_SEGPIN32_SHIFT  0

#define SI32_LCD_A_SEGDATA4_SEGPIN33_MASK  0x000000F0
#define SI32_LCD_A_SEGDATA4_SEGPIN33_SHIFT  4

#define SI32_LCD_A_SEGDATA4_SEGPIN34_MASK  0x00000F00
#define SI32_LCD_A_SEGDATA4_SEGPIN34_SHIFT  8

#define SI32_LCD_A_SEGDATA4_SEGPIN35_MASK  0x0000F000
#define SI32_LCD_A_SEGDATA4_SEGPIN35_SHIFT  12

#define SI32_LCD_A_SEGDATA4_SEGPIN36_MASK  0x000F0000
#define SI32_LCD_A_SEGDATA4_SEGPIN36_SHIFT  16

#define SI32_LCD_A_SEGDATA4_SEGPIN37_MASK  0x00F00000
#define SI32_LCD_A_SEGDATA4_SEGPIN37_SHIFT  20

#define SI32_LCD_A_SEGDATA4_SEGPIN38_MASK  0x0F000000
#define SI32_LCD_A_SEGDATA4_SEGPIN38_SHIFT  24

#define SI32_LCD_A_SEGDATA4_SEGPIN39_MASK  0xF0000000
#define SI32_LCD_A_SEGDATA4_SEGPIN39_SHIFT  28



typedef struct SI32_LCD_A_Struct
{
   struct SI32_LCD_A_CONFIG_Struct                 CONFIG         ; // Base Address + 0x0
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved0;
   uint32_t                                        reserved1[4];
   struct SI32_LCD_A_CLKCONTROL_Struct             CLKCONTROL     ; // Base Address + 0x20
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   struct SI32_LCD_A_BLKCONTROL_Struct             BLKCONTROL     ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_LCD_A_SEGCONTROL_Struct             SEGCONTROL     ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   uint32_t                                        reserved11[4];
   struct SI32_LCD_A_CTRSTCONTROL_Struct           CTRSTCONTROL   ; // Base Address + 0x60
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   uint32_t                                        reserved14;
   struct SI32_LCD_A_VBMCONTROL_Struct             VBMCONTROL     ; // Base Address + 0x70
   uint32_t                                        reserved15;
   uint32_t                                        reserved16;
   uint32_t                                        reserved17;
   struct SI32_LCD_A_SEGMASK0_Struct               SEGMASK0       ; // Base Address + 0x80
   volatile uint32_t                               SEGMASK0_SET;
   volatile uint32_t                               SEGMASK0_CLR;
   uint32_t                                        reserved18;
   struct SI32_LCD_A_SEGMASK1_Struct               SEGMASK1       ; // Base Address + 0x90
   volatile uint32_t                               SEGMASK1_SET;
   volatile uint32_t                               SEGMASK1_CLR;
   uint32_t                                        reserved19;
   struct SI32_LCD_A_SEGDATA0_Struct               SEGDATA0       ; // Base Address + 0xa0
   uint32_t                                        reserved20;
   uint32_t                                        reserved21;
   uint32_t                                        reserved22;
   struct SI32_LCD_A_SEGDATA1_Struct               SEGDATA1       ; // Base Address + 0xb0
   uint32_t                                        reserved23;
   uint32_t                                        reserved24;
   uint32_t                                        reserved25;
   struct SI32_LCD_A_SEGDATA2_Struct               SEGDATA2       ; // Base Address + 0xc0
   uint32_t                                        reserved26;
   uint32_t                                        reserved27;
   uint32_t                                        reserved28;
   struct SI32_LCD_A_SEGDATA3_Struct               SEGDATA3       ; // Base Address + 0xd0
   uint32_t                                        reserved29;
   uint32_t                                        reserved30;
   uint32_t                                        reserved31;
   struct SI32_LCD_A_SEGDATA4_Struct               SEGDATA4       ; // Base Address + 0xe0
   uint32_t                                        reserved32;
   uint32_t                                        reserved33;
   uint32_t                                        reserved34;
   uint32_t                                        reserved35[4];
   uint32_t                                        reserved36[4];
} SI32_LCD_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_LCD_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

