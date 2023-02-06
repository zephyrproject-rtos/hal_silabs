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

#include "sim3l1xx.h"

//------------------------------------------------------------------------------
// boot oscillator is 20MHz
uint32_t SystemCoreClock = 20000000;

//------------------------------------------------------------------------------
void SystemInit(void)
{
  // To disable the pin reset delay described below, make sure the preprocessor
  // symbol si32HalOption_disable_pin_reset_delay is defined by your toolchain.
# if !defined(si32HalOption_disable_pin_reset_delay)
  // If the reset pin was the source of the last reset, delay for 500 msec.
  // Firmware can disable the debug port by inadvertantly setting the AHB
  // clock source to a disabled clock. If this happens too quickly after a
  // reset, it is not possible for a debug agent to gain control and thus
  // not possible to reprogram the on-chip flash. Adding a delay here gives
  // a debug agent sufficient time to connect.
  if ((SI32_RSTSRC_0->RESETFLAG.PINRF == 1)
  &&  (SI32_RSTSRC_0->RESETFLAG.PORRF == 0)
  &&  (SI32_RSTSRC_0->RESETFLAG.VMONRF == 0))
  {
    // Set the SysTick timer to count down 10M ticks @ 20MHz (~500 msec)
    SysTick->LOAD = 0xA00000;
    SysTick->VAL  = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    // Wait for the count down to complete
    while (0 == (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) {}

    // Set the SysTick timer to reset values
    SysTick->CTRL = 0;
    SysTick->LOAD = 0;
    SysTick->VAL  = 0;
  }
# endif

  // invoke the application's system initialization.
  mySystemInit();
}

//------------------------------------------------------------------------------
void SystemCoreClockUpdate(void)
{
  // TBD - examine the clock registers and compute the system core clock value.
}

//-eof--------------------------------------------------------------------------
