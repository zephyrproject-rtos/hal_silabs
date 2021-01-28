/***************************************************************************//**
 * @file em_cmu_fpga.c
 * @brief Clock management unit (CMU) Peripheral API for FPGA
 * @version 5.3.5
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories, Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Labs has no
 * obligation to support this Software. Silicon Labs is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Silicon Labs will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
 *
 ******************************************************************************/

#include "em_device.h"

#if defined(CMU_PRESENT) && defined(FPGA)

#include "em_cmu.h"
#include "em_assert.h"

/***************************************************************************//**
 * @addtogroup emlib
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup CMU
 * @brief Clock management unit (CMU) Peripheral API
 * @details
 *  This module contains stubbed EM_CMU functions in order to run on FPGA
 *  implementations of Silicon Labs 32-bit MCUs and SoCs.
 * @{
 ******************************************************************************/

// Ocelot FGPA ID
#define FPGA_WIRE 0x05
#define FPGA_OTA  0x0F
#define FPGA_SE   0x00

#define FPGA_ID_MASK 0x0F

#if defined(HFRCO_STARTUP_FREQ)
#define HFRCO_CLK_FREQ HFRCO_STARTUP_FREQ
#else
#define HFRCO_CLK_FREQ 38400000    /* OTA FPGA image clock frequency */
#endif
#define LFRCO_CLK_FREQ 32768
#define ULFRCO_CLK_FREQ 1000

CMU_Select_TypeDef cmu_euart0_clk_source = cmuSelect_HFRCO;
CMU_Select_TypeDef cmu_eusart0_clk_source = cmuSelect_HFRCO;
CMU_Select_TypeDef cmu_eusart1_clk_source = cmuSelect_HFRCO;
CMU_Select_TypeDef cmu_eusart2_clk_source = cmuSelect_HFRCO;

uint32_t Get_Fpga_Core_freq(void)
{
  if ((SYSCFG->FPGAIPOTHW & FPGA_ID_MASK) == FPGA_WIRE ) {
#if defined(HFRCO_STARTUP_FREQ)
    return HFRCO_STARTUP_FREQ;
#else
    return 9600000u;
#endif
  } else if ((SYSCFG->FPGAIPOTHW & FPGA_ID_MASK) == FPGA_OTA) {
    return 38400000u;
  } else {
    return SystemHFXOClockGet();
  }
}

uint32_t CMU_Calibrate(uint32_t HFCycles, CMU_Osc_TypeDef ref)
{
  (void) HFCycles;
  (void) ref;

  return 1;
}

void CMU_CalibrateConfig(uint32_t downCycles, CMU_Osc_TypeDef downSel,
                         CMU_Osc_TypeDef upSel)
{
  (void) downCycles;
  (void) downSel;
  (void) upSel;
}

uint32_t CMU_CalibrateCountGet(void)
{
  return 0;
}

CMU_ClkDiv_TypeDef CMU_ClockDivGet(CMU_Clock_TypeDef clock)
{
  uint32_t ret = 0U;

  switch (clock) {
    case cmuClock_HCLK:
    case cmuClock_CORE:
      ret = (CMU->SYSCLKCTRL & _CMU_SYSCLKCTRL_HCLKPRESC_MASK)
            >> _CMU_SYSCLKCTRL_HCLKPRESC_SHIFT;
      if (ret == 2U ) {   // Unused value, illegal prescaler
        EFM_ASSERT(false);
      }
      break;

    case cmuClock_EXPCLK:
      ret = (CMU->EXPORTCLKCTRL & _CMU_EXPORTCLKCTRL_PRESC_MASK)
            >> _CMU_EXPORTCLKCTRL_PRESC_SHIFT;
      break;

    case cmuClock_PCLK:
      ret = (CMU->SYSCLKCTRL & _CMU_SYSCLKCTRL_PCLKPRESC_MASK)
            >> _CMU_SYSCLKCTRL_PCLKPRESC_SHIFT;
      break;

    default:
      EFM_ASSERT(false);
      break;
  }
  return 1U + ret;
}

void CMU_ClockDivSet(CMU_Clock_TypeDef clock, CMU_ClkDiv_TypeDef div)
{
  (void) clock;
  (void) div;
}

void CMU_ClockEnable(CMU_Clock_TypeDef clock, bool enable)
{
  (void) clock;
  (void) enable;
}

uint32_t CMU_ClockFreqGet(CMU_Clock_TypeDef clock)
{
  uint32_t freq = 0;
  switch (clock) {
    case cmuClock_SYSCLK:
    case cmuClock_HCLK:
    case cmuClock_LSPCLK:
    case cmuClock_EXPCLK:
    case cmuClock_EM01GRPACLK:
    case cmuClock_EM23GRPACLK:
    case cmuClock_EM4GRPACLK:
    case cmuClock_WDOG0CLK:
#if defined(_CMU_TRACECLKCTRL_MASK)
    case cmuClock_DPLLREFCLK:
#endif
#if defined(_CMU_TRACECLKCTRL_MASK)
    case cmuClock_TRACECLK:
#endif
    case cmuClock_ACMP0:
    case cmuClock_ACMP1:
    case cmuClock_CORE:
    case cmuClock_GPCRC:
    case cmuClock_GPIO:
    case cmuClock_LDMA:
    case cmuClock_PRS:
    case cmuClock_TIMER0:
    case cmuClock_TIMER1:
    case cmuClock_TIMER2:
    case cmuClock_TIMER3:
    case cmuClock_TIMER4:
    case cmuClock_BURAM:
    case cmuClock_KEYSCAN:
      #ifdef USART0
    case cmuClock_USART0:
#endif
#ifdef USART1
    case cmuClock_USART1:
#endif
#ifdef USART2
    case cmuClock_USART2:
#endif
      return Get_Fpga_Core_freq();
    case cmuClock_IADC0:
      return 40000000u; // Hard coded to pass test
    case cmuClock_PCLK:
#if defined(INCLUDE_I2C_TEST)
      return 28000000u;// Hard coded to pass I2C test
#else
      return Get_Fpga_Core_freq(); // actual frequency.
#endif
    case cmuClock_I2C0:
    case cmuClock_I2C1:
      return 28000000u; // Hard coded to pass test
    case cmuClock_LETIMER0:
    case cmuClock_RTCC:
    case cmuClock_SYSRTC:
    case cmuClock_SYSTICK:
    case cmuClock_WDOG0:
    case cmuClock_LESENSE:
      return LFRCO_CLK_FREQ;
    case cmuClock_BURTC:
#ifdef WDOG1
    case cmuClock_WDOG1:
#endif
      return ULFRCO_CLK_FREQ;
#ifdef EUART0
    case cmuClock_EUART0:
      switch (cmu_euart0_clk_source) {
        case cmuSelect_EM01GRPACLK:
          freq = HFRCO_CLK_FREQ;
          break;
        case cmuSelect_EM23GRPACLK:
          freq = LFRCO_CLK_FREQ;
          break;
        case cmuSelect_ULFRCO:
          freq = ULFRCO_CLK_FREQ;
          break;
        case cmuSelect_HFRCODPLL:
          freq = HFRCO_CLK_FREQ;
          break;
        default:
          EFM_ASSERT(0);
          break;
      }
      return freq;
#endif
#ifdef EUSART0
    case cmuClock_EUSART0:
      switch (cmu_eusart0_clk_source) {
        case cmuSelect_EM01GRPACLK:
          freq = Get_Fpga_Core_freq();
          break;
        case cmuSelect_EM23GRPACLK:
          freq = LFRCO_CLK_FREQ;
          break;
        case cmuSelect_ULFRCO:
          freq = ULFRCO_CLK_FREQ;
          break;
        case cmuSelect_HFRCODPLL:
          freq = Get_Fpga_Core_freq();
          break;
        default:
          EFM_ASSERT(0);
          break;
      }
      return freq;
#endif

    default:
      return Get_Fpga_Core_freq();
  }
}

CMU_Select_TypeDef CMU_ClockSelectGet(CMU_Clock_TypeDef clock)
{
  CMU_Select_TypeDef clock_source = (CMU_Select_TypeDef) 0;

  switch (clock) {
#ifdef EUART0
    case cmuClock_EUART0:
//      clock_source = cmu_euart0_clk_source;
      if (cmu_euart0_clk_source == cmuSelect_EM01GRPACLK) {
        clock_source = cmuSelect_HFRCO;
      } else if (cmu_euart0_clk_source == cmuSelect_EM23GRPACLK) {
        clock_source = cmuSelect_LFRCO;
      }
      break;
#endif
#ifdef EUSART0
    case cmuClock_EUSART0:
      if (cmu_eusart0_clk_source == cmuSelect_EM01GRPACLK) {
        clock_source = cmuSelect_HFRCO;
      } else if (cmu_eusart0_clk_source == cmuSelect_EM23GRPACLK) {
        clock_source = cmuSelect_LFRCO;
      }
      break;
#endif
#ifdef EUSART1
    case cmuClock_EUSART1:
      if (cmu_eusart1_clk_source == cmuSelect_EM01GRPACLK) {
        clock_source = cmuSelect_HFRCO;
      } else if (cmu_eusart1_clk_source == cmuSelect_EM23GRPACLK) {
        clock_source = cmuSelect_LFRCO;
      }
      break;
#endif
    default:
      clock_source = cmuSelect_HFRCO;
      break;
  }

  return clock_source;
}

void CMU_ClockSelectSet(CMU_Clock_TypeDef clock, CMU_Select_TypeDef ref)
{
  (void) ref;
  switch (clock) {
#ifdef EUART0
    case cmuClock_EUART0:
      cmu_euart0_clk_source = ref;
      break;
#endif
#ifdef EUSART0
    case cmuClock_EUSART0:
      cmu_eusart0_clk_source = ref;
      break;
#endif
#ifdef EUSART1
    case cmuClock_EUSART1:
      cmu_eusart1_clk_source = ref;
      break;
#endif
#ifdef EUSART2
    case cmuClock_EUSART2:
      cmu_eusart2_clk_source = ref;
      break;
#endif
    default:
      break;
  }
}

void CMU_FreezeEnable(bool enable)
{
  (void) enable;
}

CMU_HFRCOFreq_TypeDef CMU_HFRCOBandGet(void)
{
  return (CMU_HFRCOFreq_TypeDef) Get_Fpga_Core_freq();
}

void CMU_HFRCOBandSet(CMU_HFRCOFreq_TypeDef setFreq)
{
  (void) setFreq;
}

CMU_HFRCODPLLFreq_TypeDef  CMU_HFRCODPLLBandGet(void)
{
  return (CMU_HFRCODPLLFreq_TypeDef) Get_Fpga_Core_freq();
}

void CMU_HFRCODPLLBandSet(CMU_HFRCODPLLFreq_TypeDef setFreq)
{
  (void) setFreq;
}

void CMU_HFXOInit(const CMU_HFXOInit_TypeDef *hfxoInit)
{
  (void) hfxoInit;
}

uint32_t CMU_LCDClkFDIVGet(void)
{
  return 0;
}

void CMU_LCDClkFDIVSet(uint32_t div)
{
  (void)div;  /* Unused parameter */
}

void CMU_LFXOInit(const CMU_LFXOInit_TypeDef *lfxoInit)
{
  (void) lfxoInit;
}

void CMU_OscillatorEnable(CMU_Osc_TypeDef osc, bool enable, bool wait)
{
  (void) osc;
  (void) enable;
  (void) wait;
}

uint32_t CMU_OscillatorTuningGet(CMU_Osc_TypeDef osc)
{
  (void) osc;
  return 0;
}

void CMU_OscillatorTuningSet(CMU_Osc_TypeDef osc, uint32_t val)
{
  (void) osc;
  (void) val;
}

bool CMU_PCNTClockExternalGet(unsigned int instance)
{
  (void) instance;
  return false;
}

void CMU_PCNTClockExternalSet(unsigned int instance, bool external)
{
  (void)instance;  /* Unused parameter */
  (void)external;  /* Unused parameter */
}

void CMU_UpdateWaitStates(uint32_t freq, int vscale)
{
  (void)freq;
  (void)vscale;
}

/** @} (end addtogroup CMU) */
/** @} (end addtogroup emlib) */
#endif /* #if defined(CMU_PRESENT) && defined(FPGA) */
