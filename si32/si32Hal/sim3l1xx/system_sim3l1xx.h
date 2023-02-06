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

#ifndef __SYSTEM_SIM3L1XX_H__
#define __SYSTEM_SIM3L1XX_H__

#ifdef __cplusplus
extern "C" {
#endif

// Refer to the CMSIS_V2P00 specification for detailed documentation.
// Contains the system core clock (which is the system clock frequency supplied
// to the SysTick timer and the processor core clock). This variable can be used
// by the user application to setup the SysTick timer or configure other
// parameters. It may also be used by debugger to query the frequency of the
// debug timer or configure the trace clock speed.
// SystemCoreClock is initialized with a correct predefined value.
// The compiler must be configured to avoid the removal of this variable in case
// that the application program is not using it. It is important for debug
// systems that the variable is physically present in memory so that it can be
// examined to configure the debugger.
extern uint32_t SystemCoreClock;

// Refer to the CMSIS_V2P00 specification for detailed documentation.
// Setup the microcontroller system.
// For systems with variable clock speed it also updates the variable SystemCoreClock.
extern void SystemInit(void);

// Application specific system initialization code.  Application needs to have this function.
extern void mySystemInit(void);

// Refer to the CMSIS_V2P00 specification for detailed documentation.
// Updates the variable SystemCoreClock and must be called whenever the core
// clock is changed during program execution. SystemCoreClockUpdate() evaluates
// the clock register settings and calculates the current core clock.
extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_SIM3L1XX_H__ */

//-eof--------------------------------------------------------------------------

