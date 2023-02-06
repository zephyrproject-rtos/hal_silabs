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

#ifndef __SI32_USB_A_REGISTERS_H__
#define __SI32_USB_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_USB_A_FADDR_Struct
{
   union
   {
      struct
      {
         // Function Address
         volatile uint32_t FADDR_BITS: 7;
         // Function Address Update
         volatile uint32_t FADDRUPD: 1;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_FADDR_FADDR_MASK  0x0000007F
#define SI32_USB_A_FADDR_FADDR_SHIFT  0

#define SI32_USB_A_FADDR_FADDRUPD_MASK  0x00000080
#define SI32_USB_A_FADDR_FADDRUPD_SHIFT  7
// The last address written to FADDR is in effect.
#define SI32_USB_A_FADDR_FADDRUPD_NOT_SET_VALUE  0
#define SI32_USB_A_FADDR_FADDRUPD_NOT_SET_U32 \
   (SI32_USB_A_FADDR_FADDRUPD_NOT_SET_VALUE << SI32_USB_A_FADDR_FADDRUPD_SHIFT)
// The last address written to FADDR is not yet in effect.
#define SI32_USB_A_FADDR_FADDRUPD_SET_VALUE  1
#define SI32_USB_A_FADDR_FADDRUPD_SET_U32 \
   (SI32_USB_A_FADDR_FADDRUPD_SET_VALUE << SI32_USB_A_FADDR_FADDRUPD_SHIFT)



struct SI32_USB_A_POWER_Struct
{
   union
   {
      struct
      {
         // Suspend Detection Enable
         volatile uint32_t SUSDEN: 1;
         // Suspend Mode Flag
         volatile uint32_t SUSMDF: 1;
         // Force Resume
         volatile uint32_t RESUME: 1;
         // Reset Detect Flag
         volatile uint32_t RSTDETF: 1;
         // USB Inhibit
         volatile uint32_t USBINH: 1;
         // USB Dither Enable
         volatile uint32_t DITHEN: 1;
                  uint32_t reserved0: 1;
         // ISO Update Mode
         volatile uint32_t ISOUPDMD: 1;
                  uint32_t reserved1: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_POWER_SUSDEN_MASK  0x00000001
#define SI32_USB_A_POWER_SUSDEN_SHIFT  0
// Disable suspend detection. The USB module will ignore suspend signaling on the
// bus.
#define SI32_USB_A_POWER_SUSDEN_DISABLED_VALUE  0
#define SI32_USB_A_POWER_SUSDEN_DISABLED_U32 \
   (SI32_USB_A_POWER_SUSDEN_DISABLED_VALUE << SI32_USB_A_POWER_SUSDEN_SHIFT)
// Enable suspend detection. The USB module will enter suspend mode if it detects
// suspend signalling on the bus.
#define SI32_USB_A_POWER_SUSDEN_ENABLED_VALUE  1
#define SI32_USB_A_POWER_SUSDEN_ENABLED_U32 \
   (SI32_USB_A_POWER_SUSDEN_ENABLED_VALUE << SI32_USB_A_POWER_SUSDEN_SHIFT)

#define SI32_USB_A_POWER_SUSMDF_MASK  0x00000002
#define SI32_USB_A_POWER_SUSMDF_SHIFT  1
// The USB module is not in suspend mode.
#define SI32_USB_A_POWER_SUSMDF_NOT_SET_VALUE  0
#define SI32_USB_A_POWER_SUSMDF_NOT_SET_U32 \
   (SI32_USB_A_POWER_SUSMDF_NOT_SET_VALUE << SI32_USB_A_POWER_SUSMDF_SHIFT)
// The USB module is in suspend mode.
#define SI32_USB_A_POWER_SUSMDF_SET_VALUE  1
#define SI32_USB_A_POWER_SUSMDF_SET_U32 \
   (SI32_USB_A_POWER_SUSMDF_SET_VALUE << SI32_USB_A_POWER_SUSMDF_SHIFT)

#define SI32_USB_A_POWER_RESUME_MASK  0x00000004
#define SI32_USB_A_POWER_RESUME_SHIFT  2
#define SI32_USB_A_POWER_RESUME_STOP_VALUE  0
#define SI32_USB_A_POWER_RESUME_STOP_U32 \
   (SI32_USB_A_POWER_RESUME_STOP_VALUE << SI32_USB_A_POWER_RESUME_SHIFT)
#define SI32_USB_A_POWER_RESUME_GENERATE_VALUE  1
#define SI32_USB_A_POWER_RESUME_GENERATE_U32 \
   (SI32_USB_A_POWER_RESUME_GENERATE_VALUE << SI32_USB_A_POWER_RESUME_SHIFT)

#define SI32_USB_A_POWER_RSTDETF_MASK  0x00000008
#define SI32_USB_A_POWER_RSTDETF_SHIFT  3
// Reset signaling is not present on the bus.
#define SI32_USB_A_POWER_RSTDETF_NOT_SET_VALUE  0
#define SI32_USB_A_POWER_RSTDETF_NOT_SET_U32 \
   (SI32_USB_A_POWER_RSTDETF_NOT_SET_VALUE << SI32_USB_A_POWER_RSTDETF_SHIFT)
// Reset signaling detected on the bus.
#define SI32_USB_A_POWER_RSTDETF_SET_VALUE  1
#define SI32_USB_A_POWER_RSTDETF_SET_U32 \
   (SI32_USB_A_POWER_RSTDETF_SET_VALUE << SI32_USB_A_POWER_RSTDETF_SHIFT)

#define SI32_USB_A_POWER_USBINH_MASK  0x00000010
#define SI32_USB_A_POWER_USBINH_SHIFT  4
// Enable the USB module.
#define SI32_USB_A_POWER_USBINH_INACTIVE_VALUE  0
#define SI32_USB_A_POWER_USBINH_INACTIVE_U32 \
   (SI32_USB_A_POWER_USBINH_INACTIVE_VALUE << SI32_USB_A_POWER_USBINH_SHIFT)
// USB module inhibited. All USB traffic is ignored.
#define SI32_USB_A_POWER_USBINH_ACTIVE_VALUE  1
#define SI32_USB_A_POWER_USBINH_ACTIVE_U32 \
   (SI32_USB_A_POWER_USBINH_ACTIVE_VALUE << SI32_USB_A_POWER_USBINH_SHIFT)

#define SI32_USB_A_POWER_DITHEN_MASK  0x00000020
#define SI32_USB_A_POWER_DITHEN_SHIFT  5
// Disable automatic USB dithering.
#define SI32_USB_A_POWER_DITHEN_DISABLED_VALUE  0
#define SI32_USB_A_POWER_DITHEN_DISABLED_U32 \
   (SI32_USB_A_POWER_DITHEN_DISABLED_VALUE << SI32_USB_A_POWER_DITHEN_SHIFT)
// Enable automatic USB dithering.
#define SI32_USB_A_POWER_DITHEN_ENABLED_VALUE  1
#define SI32_USB_A_POWER_DITHEN_ENABLED_U32 \
   (SI32_USB_A_POWER_DITHEN_ENABLED_VALUE << SI32_USB_A_POWER_DITHEN_SHIFT)

#define SI32_USB_A_POWER_ISOUPDMD_MASK  0x00000080
#define SI32_USB_A_POWER_ISOUPDMD_SHIFT  7
// When software writes IPRDYI = 1, USB will send the packet when the next IN token
// is received.
#define SI32_USB_A_POWER_ISOUPDMD_SEND_ON_IN_VALUE  0
#define SI32_USB_A_POWER_ISOUPDMD_SEND_ON_IN_U32 \
   (SI32_USB_A_POWER_ISOUPDMD_SEND_ON_IN_VALUE << SI32_USB_A_POWER_ISOUPDMD_SHIFT)
// When software writes IPRDYI = 1, USB will wait for a SOF token before sending
// the packet. If an IN token is received before a SOF token, USB will send a zero-
// length data packet.
#define SI32_USB_A_POWER_ISOUPDMD_SEND_ON_SOF_VALUE  1
#define SI32_USB_A_POWER_ISOUPDMD_SEND_ON_SOF_U32 \
   (SI32_USB_A_POWER_ISOUPDMD_SEND_ON_SOF_VALUE << SI32_USB_A_POWER_ISOUPDMD_SHIFT)



struct SI32_USB_A_IOINT_Struct
{
   union
   {
      struct
      {
         // Endpoint 0 Interrupt Flag
         volatile uint32_t EP0I: 1;
         // IN Endpoint 1 Interrupt Flag
         volatile uint32_t IN1I: 1;
         // IN Endpoint 2 Interrupt Flag
         volatile uint32_t IN2I: 1;
         // IN Endpoint 3 Interrupt Flag
         volatile uint32_t IN3I: 1;
         // IN Endpoint 4 Interrupt Flag
         volatile uint32_t IN4I: 1;
                  uint32_t reserved0: 12;
         // OUT Endpoint 1 Interrupt Flag
         volatile uint32_t OUT1I: 1;
         // OUT Endpoint 2 Interrupt Flag
         volatile uint32_t OUT2I: 1;
         // OUT Endpoint 3 Interrupt Flag
         volatile uint32_t OUT3I: 1;
         // OUT Endpoint 4 Interrupt Flag
         volatile uint32_t OUT4I: 1;
                  uint32_t reserved1: 11;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_IOINT_EP0I_MASK  0x00000001
#define SI32_USB_A_IOINT_EP0I_SHIFT  0
// Read: Endpoint 0 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_EP0I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_EP0I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_EP0I_NOT_SET_VALUE << SI32_USB_A_IOINT_EP0I_SHIFT)
// Read: Endpoint 0 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_EP0I_SET_VALUE  1
#define SI32_USB_A_IOINT_EP0I_SET_U32 \
   (SI32_USB_A_IOINT_EP0I_SET_VALUE << SI32_USB_A_IOINT_EP0I_SHIFT)

#define SI32_USB_A_IOINT_IN1I_MASK  0x00000002
#define SI32_USB_A_IOINT_IN1I_SHIFT  1
// Read: IN Endpoint 1 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_IN1I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_IN1I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_IN1I_NOT_SET_VALUE << SI32_USB_A_IOINT_IN1I_SHIFT)
// Read: IN Endpoint 1 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_IN1I_SET_VALUE  1
#define SI32_USB_A_IOINT_IN1I_SET_U32 \
   (SI32_USB_A_IOINT_IN1I_SET_VALUE << SI32_USB_A_IOINT_IN1I_SHIFT)

#define SI32_USB_A_IOINT_IN2I_MASK  0x00000004
#define SI32_USB_A_IOINT_IN2I_SHIFT  2
// Read: IN Endpoint 2 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_IN2I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_IN2I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_IN2I_NOT_SET_VALUE << SI32_USB_A_IOINT_IN2I_SHIFT)
// Read: IN Endpoint 2 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_IN2I_SET_VALUE  1
#define SI32_USB_A_IOINT_IN2I_SET_U32 \
   (SI32_USB_A_IOINT_IN2I_SET_VALUE << SI32_USB_A_IOINT_IN2I_SHIFT)

#define SI32_USB_A_IOINT_IN3I_MASK  0x00000008
#define SI32_USB_A_IOINT_IN3I_SHIFT  3
// Read: IN Endpoint 3 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_IN3I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_IN3I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_IN3I_NOT_SET_VALUE << SI32_USB_A_IOINT_IN3I_SHIFT)
// Read: IN Endpoint 3 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_IN3I_SET_VALUE  1
#define SI32_USB_A_IOINT_IN3I_SET_U32 \
   (SI32_USB_A_IOINT_IN3I_SET_VALUE << SI32_USB_A_IOINT_IN3I_SHIFT)

#define SI32_USB_A_IOINT_IN4I_MASK  0x00000010
#define SI32_USB_A_IOINT_IN4I_SHIFT  4
// Read: IN Endpoint 4 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_IN4I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_IN4I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_IN4I_NOT_SET_VALUE << SI32_USB_A_IOINT_IN4I_SHIFT)
// Read: IN Endpoint 4 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_IN4I_SET_VALUE  1
#define SI32_USB_A_IOINT_IN4I_SET_U32 \
   (SI32_USB_A_IOINT_IN4I_SET_VALUE << SI32_USB_A_IOINT_IN4I_SHIFT)

#define SI32_USB_A_IOINT_OUT1I_MASK  0x00020000
#define SI32_USB_A_IOINT_OUT1I_SHIFT  17
// Read: OUT Endpoint 1 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_OUT1I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_OUT1I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_OUT1I_NOT_SET_VALUE << SI32_USB_A_IOINT_OUT1I_SHIFT)
// Read: OUT Endpoint 1 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_OUT1I_SET_VALUE  1
#define SI32_USB_A_IOINT_OUT1I_SET_U32 \
   (SI32_USB_A_IOINT_OUT1I_SET_VALUE << SI32_USB_A_IOINT_OUT1I_SHIFT)

#define SI32_USB_A_IOINT_OUT2I_MASK  0x00040000
#define SI32_USB_A_IOINT_OUT2I_SHIFT  18
// Read: OUT Endpoint 2 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_OUT2I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_OUT2I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_OUT2I_NOT_SET_VALUE << SI32_USB_A_IOINT_OUT2I_SHIFT)
// Read: OUT Endpoint 2 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_OUT2I_SET_VALUE  1
#define SI32_USB_A_IOINT_OUT2I_SET_U32 \
   (SI32_USB_A_IOINT_OUT2I_SET_VALUE << SI32_USB_A_IOINT_OUT2I_SHIFT)

#define SI32_USB_A_IOINT_OUT3I_MASK  0x00080000
#define SI32_USB_A_IOINT_OUT3I_SHIFT  19
// Read: OUT Endpoint 3 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_OUT3I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_OUT3I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_OUT3I_NOT_SET_VALUE << SI32_USB_A_IOINT_OUT3I_SHIFT)
// Read: OUT Endpoint 3 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_OUT3I_SET_VALUE  1
#define SI32_USB_A_IOINT_OUT3I_SET_U32 \
   (SI32_USB_A_IOINT_OUT3I_SET_VALUE << SI32_USB_A_IOINT_OUT3I_SHIFT)

#define SI32_USB_A_IOINT_OUT4I_MASK  0x00100000
#define SI32_USB_A_IOINT_OUT4I_SHIFT  20
// Read: OUT Endpoint 4 interrupt has not occurred. Write: No effect.
#define SI32_USB_A_IOINT_OUT4I_NOT_SET_VALUE  0
#define SI32_USB_A_IOINT_OUT4I_NOT_SET_U32 \
   (SI32_USB_A_IOINT_OUT4I_NOT_SET_VALUE << SI32_USB_A_IOINT_OUT4I_SHIFT)
// Read: OUT Endpoint 4 interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_IOINT_OUT4I_SET_VALUE  1
#define SI32_USB_A_IOINT_OUT4I_SET_U32 \
   (SI32_USB_A_IOINT_OUT4I_SET_VALUE << SI32_USB_A_IOINT_OUT4I_SHIFT)



struct SI32_USB_A_CMINT_Struct
{
   union
   {
      struct
      {
         // Suspend Interrupt Flag
         volatile uint32_t SUSI: 1;
         // Resume Interrupt Flag
         volatile uint32_t RESI: 1;
         // Reset Interrupt Flag
         volatile uint32_t RSTI: 1;
         // Start of Frame Interrupt Flag
         volatile uint32_t SOFI: 1;
                  uint32_t reserved0: 28;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_CMINT_SUSI_MASK  0x00000001
#define SI32_USB_A_CMINT_SUSI_SHIFT  0
// Read: Suspend interrupt has not occurred. Write: No effect.
#define SI32_USB_A_CMINT_SUSI_NOT_SET_VALUE  0
#define SI32_USB_A_CMINT_SUSI_NOT_SET_U32 \
   (SI32_USB_A_CMINT_SUSI_NOT_SET_VALUE << SI32_USB_A_CMINT_SUSI_SHIFT)
// Read: Suspend interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_CMINT_SUSI_SET_VALUE  1
#define SI32_USB_A_CMINT_SUSI_SET_U32 \
   (SI32_USB_A_CMINT_SUSI_SET_VALUE << SI32_USB_A_CMINT_SUSI_SHIFT)

#define SI32_USB_A_CMINT_RESI_MASK  0x00000002
#define SI32_USB_A_CMINT_RESI_SHIFT  1
// Read: Resume interrupt has not occurred. Write: No effect.
#define SI32_USB_A_CMINT_RESI_NOT_SET_VALUE  0
#define SI32_USB_A_CMINT_RESI_NOT_SET_U32 \
   (SI32_USB_A_CMINT_RESI_NOT_SET_VALUE << SI32_USB_A_CMINT_RESI_SHIFT)
// Read: Resume interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_CMINT_RESI_SET_VALUE  1
#define SI32_USB_A_CMINT_RESI_SET_U32 \
   (SI32_USB_A_CMINT_RESI_SET_VALUE << SI32_USB_A_CMINT_RESI_SHIFT)

#define SI32_USB_A_CMINT_RSTI_MASK  0x00000004
#define SI32_USB_A_CMINT_RSTI_SHIFT  2
// Read: Reset interrupt has not occurred. Write: No effect.
#define SI32_USB_A_CMINT_RSTI_NOT_SET_VALUE  0
#define SI32_USB_A_CMINT_RSTI_NOT_SET_U32 \
   (SI32_USB_A_CMINT_RSTI_NOT_SET_VALUE << SI32_USB_A_CMINT_RSTI_SHIFT)
// Read: Reset interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_CMINT_RSTI_SET_VALUE  1
#define SI32_USB_A_CMINT_RSTI_SET_U32 \
   (SI32_USB_A_CMINT_RSTI_SET_VALUE << SI32_USB_A_CMINT_RSTI_SHIFT)

#define SI32_USB_A_CMINT_SOFI_MASK  0x00000008
#define SI32_USB_A_CMINT_SOFI_SHIFT  3
// Read: SOF interrupt has not occurred. Write: No effect.
#define SI32_USB_A_CMINT_SOFI_NOT_SET_VALUE  0
#define SI32_USB_A_CMINT_SOFI_NOT_SET_U32 \
   (SI32_USB_A_CMINT_SOFI_NOT_SET_VALUE << SI32_USB_A_CMINT_SOFI_SHIFT)
// Read: SOF interrupt occurred. Write: Clear the interrupt.
#define SI32_USB_A_CMINT_SOFI_SET_VALUE  1
#define SI32_USB_A_CMINT_SOFI_SET_U32 \
   (SI32_USB_A_CMINT_SOFI_SET_VALUE << SI32_USB_A_CMINT_SOFI_SHIFT)



struct SI32_USB_A_IOINTE_Struct
{
   union
   {
      struct
      {
         // Endpoint 0 Interrupt Enable
         volatile uint32_t EP0IEN: 1;
         // IN Endpoint 1 Interrupt Enable
         volatile uint32_t IN1IEN: 1;
         // IN Endpoint 2 Interrupt Enable
         volatile uint32_t IN2IEN: 1;
         // IN Endpoint 3 Interrupt Enable
         volatile uint32_t IN3IEN: 1;
         // IN Endpoint 4 Interrupt Enable
         volatile uint32_t IN4IEN: 1;
                  uint32_t reserved0: 12;
         // OUT Endpoint 1 Interrupt Enable
         volatile uint32_t OUT1IEN: 1;
         // OUT Endpoint 2 Interrupt Enable
         volatile uint32_t OUT2IEN: 1;
         // OUT Endpoint 3 Interrupt Enable
         volatile uint32_t OUT3IEN: 1;
         // OUT Endpoint 4 Interrupt Enable
         volatile uint32_t OUT4IEN: 1;
                  uint32_t reserved1: 11;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_IOINTE_EP0IEN_MASK  0x00000001
#define SI32_USB_A_IOINTE_EP0IEN_SHIFT  0
// Disable the Endpoint 0 interrupt.
#define SI32_USB_A_IOINTE_EP0IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_EP0IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_EP0IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_EP0IEN_SHIFT)
// Enable the Endpoint 0 interrupt.
#define SI32_USB_A_IOINTE_EP0IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_EP0IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_EP0IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_EP0IEN_SHIFT)

#define SI32_USB_A_IOINTE_IN1IEN_MASK  0x00000002
#define SI32_USB_A_IOINTE_IN1IEN_SHIFT  1
// Disable the IN Endpoint 1 interrupt.
#define SI32_USB_A_IOINTE_IN1IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_IN1IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_IN1IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_IN1IEN_SHIFT)
// Enable the IN Endpoint 1 interrupt.
#define SI32_USB_A_IOINTE_IN1IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_IN1IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_IN1IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_IN1IEN_SHIFT)

#define SI32_USB_A_IOINTE_IN2IEN_MASK  0x00000004
#define SI32_USB_A_IOINTE_IN2IEN_SHIFT  2
// Disable the IN Endpoint 2 interrupt.
#define SI32_USB_A_IOINTE_IN2IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_IN2IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_IN2IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_IN2IEN_SHIFT)
// Enable the IN Endpoint 2 interrupt.
#define SI32_USB_A_IOINTE_IN2IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_IN2IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_IN2IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_IN2IEN_SHIFT)

#define SI32_USB_A_IOINTE_IN3IEN_MASK  0x00000008
#define SI32_USB_A_IOINTE_IN3IEN_SHIFT  3
// Disable the IN Endpoint 3 interrupt.
#define SI32_USB_A_IOINTE_IN3IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_IN3IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_IN3IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_IN3IEN_SHIFT)
// Enable the IN Endpoint 3 interrupt.
#define SI32_USB_A_IOINTE_IN3IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_IN3IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_IN3IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_IN3IEN_SHIFT)

#define SI32_USB_A_IOINTE_IN4IEN_MASK  0x00000010
#define SI32_USB_A_IOINTE_IN4IEN_SHIFT  4
// Disable the IN Endpoint 4 interrupt.
#define SI32_USB_A_IOINTE_IN4IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_IN4IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_IN4IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_IN4IEN_SHIFT)
// Enable the IN Endpoint 4 interrupt.
#define SI32_USB_A_IOINTE_IN4IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_IN4IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_IN4IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_IN4IEN_SHIFT)

#define SI32_USB_A_IOINTE_OUT1IEN_MASK  0x00020000
#define SI32_USB_A_IOINTE_OUT1IEN_SHIFT  17
// Disable the OUT Endpoint 1 interrupt.
#define SI32_USB_A_IOINTE_OUT1IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_OUT1IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_OUT1IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_OUT1IEN_SHIFT)
// Enable the OUT Endpoint 1 interrupt.
#define SI32_USB_A_IOINTE_OUT1IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_OUT1IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_OUT1IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_OUT1IEN_SHIFT)

#define SI32_USB_A_IOINTE_OUT2IEN_MASK  0x00040000
#define SI32_USB_A_IOINTE_OUT2IEN_SHIFT  18
// Disable the OUT Endpoint 2 interrupt.
#define SI32_USB_A_IOINTE_OUT2IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_OUT2IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_OUT2IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_OUT2IEN_SHIFT)
// Enable the OUT Endpoint 2 interrupt.
#define SI32_USB_A_IOINTE_OUT2IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_OUT2IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_OUT2IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_OUT2IEN_SHIFT)

#define SI32_USB_A_IOINTE_OUT3IEN_MASK  0x00080000
#define SI32_USB_A_IOINTE_OUT3IEN_SHIFT  19
// Disable the OUT Endpoint 3 interrupt.
#define SI32_USB_A_IOINTE_OUT3IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_OUT3IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_OUT3IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_OUT3IEN_SHIFT)
// Enable the OUT Endpoint 3 interrupt.
#define SI32_USB_A_IOINTE_OUT3IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_OUT3IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_OUT3IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_OUT3IEN_SHIFT)

#define SI32_USB_A_IOINTE_OUT4IEN_MASK  0x00100000
#define SI32_USB_A_IOINTE_OUT4IEN_SHIFT  20
// Disable the OUT Endpoint 4 interrupt.
#define SI32_USB_A_IOINTE_OUT4IEN_DISABLED_VALUE  0
#define SI32_USB_A_IOINTE_OUT4IEN_DISABLED_U32 \
   (SI32_USB_A_IOINTE_OUT4IEN_DISABLED_VALUE << SI32_USB_A_IOINTE_OUT4IEN_SHIFT)
// Enable the OUT Endpoint 4 interrupt.
#define SI32_USB_A_IOINTE_OUT4IEN_ENABLED_VALUE  1
#define SI32_USB_A_IOINTE_OUT4IEN_ENABLED_U32 \
   (SI32_USB_A_IOINTE_OUT4IEN_ENABLED_VALUE << SI32_USB_A_IOINTE_OUT4IEN_SHIFT)



struct SI32_USB_A_CMINTEPE_Struct
{
   union
   {
      struct
      {
         // Suspend Interrupt Enable
         volatile uint32_t SUSIEN: 1;
         // Resume Interrupt Enable
         volatile uint32_t RESIEN: 1;
         // Reset Interrupt Enable
         volatile uint32_t RSTIEN: 1;
         // Start of Frame Interrupt Enable
         volatile uint32_t SOFIEN: 1;
                  uint32_t reserved0: 12;
         // Endpoint 0 Enable
         volatile uint32_t EP0EN: 1;
         // Endpoint 1 Enable
         volatile uint32_t EP1EN: 1;
         // Endpoint 2 Enable
         volatile uint32_t EP2EN: 1;
         // Endpoint 3 Enable
         volatile uint32_t EP3EN: 1;
         // Endpoint 4 Enable
         volatile uint32_t EP4EN: 1;
                  uint32_t reserved1: 11;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_CMINTEPE_SUSIEN_MASK  0x00000001
#define SI32_USB_A_CMINTEPE_SUSIEN_SHIFT  0
// Disable the Suspend interrupt.
#define SI32_USB_A_CMINTEPE_SUSIEN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_SUSIEN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_SUSIEN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_SUSIEN_SHIFT)
// Enable the Suspend interrupt.
#define SI32_USB_A_CMINTEPE_SUSIEN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_SUSIEN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_SUSIEN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_SUSIEN_SHIFT)

#define SI32_USB_A_CMINTEPE_RESIEN_MASK  0x00000002
#define SI32_USB_A_CMINTEPE_RESIEN_SHIFT  1
// Disable the Resume interrupt.
#define SI32_USB_A_CMINTEPE_RESIEN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_RESIEN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_RESIEN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_RESIEN_SHIFT)
// Enable the Resume interrupt.
#define SI32_USB_A_CMINTEPE_RESIEN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_RESIEN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_RESIEN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_RESIEN_SHIFT)

#define SI32_USB_A_CMINTEPE_RSTIEN_MASK  0x00000004
#define SI32_USB_A_CMINTEPE_RSTIEN_SHIFT  2
// Disable the Reset interrupt.
#define SI32_USB_A_CMINTEPE_RSTIEN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_RSTIEN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_RSTIEN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_RSTIEN_SHIFT)
// Enable the Reset interrupt.
#define SI32_USB_A_CMINTEPE_RSTIEN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_RSTIEN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_RSTIEN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_RSTIEN_SHIFT)

#define SI32_USB_A_CMINTEPE_SOFIEN_MASK  0x00000008
#define SI32_USB_A_CMINTEPE_SOFIEN_SHIFT  3
// Disable the SOF interrupt.
#define SI32_USB_A_CMINTEPE_SOFIEN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_SOFIEN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_SOFIEN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_SOFIEN_SHIFT)
// Enable the SOF interrupt.
#define SI32_USB_A_CMINTEPE_SOFIEN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_SOFIEN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_SOFIEN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_SOFIEN_SHIFT)

#define SI32_USB_A_CMINTEPE_EP0EN_MASK  0x00010000
#define SI32_USB_A_CMINTEPE_EP0EN_SHIFT  16
// Disable Endpoint 0 (no NACK, ACK, or STALL on the USB network).
#define SI32_USB_A_CMINTEPE_EP0EN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_EP0EN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP0EN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_EP0EN_SHIFT)
// Enable Endpoint 0 (normal).
#define SI32_USB_A_CMINTEPE_EP0EN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_EP0EN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP0EN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_EP0EN_SHIFT)

#define SI32_USB_A_CMINTEPE_EP1EN_MASK  0x00020000
#define SI32_USB_A_CMINTEPE_EP1EN_SHIFT  17
// Disable Endpoint 1 (no NACK, ACK, or STALL on the USB network).
#define SI32_USB_A_CMINTEPE_EP1EN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_EP1EN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP1EN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_EP1EN_SHIFT)
// Enable Endpoint 1 (normal).
#define SI32_USB_A_CMINTEPE_EP1EN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_EP1EN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP1EN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_EP1EN_SHIFT)

#define SI32_USB_A_CMINTEPE_EP2EN_MASK  0x00040000
#define SI32_USB_A_CMINTEPE_EP2EN_SHIFT  18
// Disable Endpoint 2 (no NACK, ACK, or STALL on the USB network).
#define SI32_USB_A_CMINTEPE_EP2EN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_EP2EN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP2EN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_EP2EN_SHIFT)
// Enable Endpoint 2 (normal).
#define SI32_USB_A_CMINTEPE_EP2EN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_EP2EN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP2EN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_EP2EN_SHIFT)

#define SI32_USB_A_CMINTEPE_EP3EN_MASK  0x00080000
#define SI32_USB_A_CMINTEPE_EP3EN_SHIFT  19
// Disable Endpoint 3 (no NACK, ACK, or STALL on the USB network).
#define SI32_USB_A_CMINTEPE_EP3EN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_EP3EN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP3EN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_EP3EN_SHIFT)
// Enable Endpoint 3 (normal).
#define SI32_USB_A_CMINTEPE_EP3EN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_EP3EN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP3EN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_EP3EN_SHIFT)

#define SI32_USB_A_CMINTEPE_EP4EN_MASK  0x00100000
#define SI32_USB_A_CMINTEPE_EP4EN_SHIFT  20
// Disable Endpoint 4 (no NACK, ACK, or STALL on the USB network).
#define SI32_USB_A_CMINTEPE_EP4EN_DISABLED_VALUE  0
#define SI32_USB_A_CMINTEPE_EP4EN_DISABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP4EN_DISABLED_VALUE << SI32_USB_A_CMINTEPE_EP4EN_SHIFT)
// Enable Endpoint 4 (normal).
#define SI32_USB_A_CMINTEPE_EP4EN_ENABLED_VALUE  1
#define SI32_USB_A_CMINTEPE_EP4EN_ENABLED_U32 \
   (SI32_USB_A_CMINTEPE_EP4EN_ENABLED_VALUE << SI32_USB_A_CMINTEPE_EP4EN_SHIFT)



struct SI32_USB_A_CRCONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 4;
         // Oscillator Open-Loop Mode Enable
         volatile uint32_t OLEN: 1;
         // Low Speed Clock Recovery Mode
         volatile uint32_t LSCRMD: 1;
         // Clock Recovery Single Step Enable
         volatile uint32_t CRSSEN: 1;
         // Clock Recovery Enable
         volatile uint32_t CREN: 1;
                  uint32_t reserved1: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_CRCONTROL_OLEN_MASK  0x00000010
#define SI32_USB_A_CRCONTROL_OLEN_SHIFT  4
// Do not freeze the USB oscillator output frequency (closed loop mode).
#define SI32_USB_A_CRCONTROL_OLEN_DISABLED_VALUE  0
#define SI32_USB_A_CRCONTROL_OLEN_DISABLED_U32 \
   (SI32_USB_A_CRCONTROL_OLEN_DISABLED_VALUE << SI32_USB_A_CRCONTROL_OLEN_SHIFT)
// Freeze the USB oscillator output frequency (open loop mode).
#define SI32_USB_A_CRCONTROL_OLEN_ENABLED_VALUE  1
#define SI32_USB_A_CRCONTROL_OLEN_ENABLED_U32 \
   (SI32_USB_A_CRCONTROL_OLEN_ENABLED_VALUE << SI32_USB_A_CRCONTROL_OLEN_SHIFT)

#define SI32_USB_A_CRCONTROL_LSCRMD_MASK  0x00000020
#define SI32_USB_A_CRCONTROL_LSCRMD_SHIFT  5
// Full Speed Mode.
#define SI32_USB_A_CRCONTROL_LSCRMD_FULL_SPEED_VALUE  0
#define SI32_USB_A_CRCONTROL_LSCRMD_FULL_SPEED_U32 \
   (SI32_USB_A_CRCONTROL_LSCRMD_FULL_SPEED_VALUE << SI32_USB_A_CRCONTROL_LSCRMD_SHIFT)
// Low Speed Mode.
#define SI32_USB_A_CRCONTROL_LSCRMD_LOW_SPEED_VALUE  1
#define SI32_USB_A_CRCONTROL_LSCRMD_LOW_SPEED_U32 \
   (SI32_USB_A_CRCONTROL_LSCRMD_LOW_SPEED_VALUE << SI32_USB_A_CRCONTROL_LSCRMD_SHIFT)

#define SI32_USB_A_CRCONTROL_CRSSEN_MASK  0x00000040
#define SI32_USB_A_CRCONTROL_CRSSEN_SHIFT  6
// Normal calibration mode.
#define SI32_USB_A_CRCONTROL_CRSSEN_DISABLED_VALUE  0
#define SI32_USB_A_CRCONTROL_CRSSEN_DISABLED_U32 \
   (SI32_USB_A_CRCONTROL_CRSSEN_DISABLED_VALUE << SI32_USB_A_CRCONTROL_CRSSEN_SHIFT)
// Single step mode.
#define SI32_USB_A_CRCONTROL_CRSSEN_ENABLED_VALUE  1
#define SI32_USB_A_CRCONTROL_CRSSEN_ENABLED_U32 \
   (SI32_USB_A_CRCONTROL_CRSSEN_ENABLED_VALUE << SI32_USB_A_CRCONTROL_CRSSEN_SHIFT)

#define SI32_USB_A_CRCONTROL_CREN_MASK  0x00000080
#define SI32_USB_A_CRCONTROL_CREN_SHIFT  7
// Disable clock recovery.
#define SI32_USB_A_CRCONTROL_CREN_DISABLED_VALUE  0
#define SI32_USB_A_CRCONTROL_CREN_DISABLED_U32 \
   (SI32_USB_A_CRCONTROL_CREN_DISABLED_VALUE << SI32_USB_A_CRCONTROL_CREN_SHIFT)
// Enable clock recovery.
#define SI32_USB_A_CRCONTROL_CREN_ENABLED_VALUE  1
#define SI32_USB_A_CRCONTROL_CREN_ENABLED_U32 \
   (SI32_USB_A_CRCONTROL_CREN_ENABLED_VALUE << SI32_USB_A_CRCONTROL_CREN_SHIFT)



struct SI32_USB_A_FRAME_Struct
{
   union
   {
      struct
      {
         // Frame Number
         volatile uint32_t FRAMENUM: 11;
                  uint32_t reserved0: 21;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_FRAME_FRAMENUM_MASK  0x000007FF
#define SI32_USB_A_FRAME_FRAMENUM_SHIFT  0



struct SI32_USB_A_TCONTROL_Struct
{
   union
   {
      struct
      {
         // D- Signal State
         volatile uint32_t DN: 1;
         // D+ Signal State
         volatile uint32_t DP: 1;
         // Differential Receiver State
         volatile uint32_t DFREC: 1;
         // Physical Layer Test
         volatile uint32_t PHYTST: 2;
         // USB Speed Select
         volatile uint32_t SSEL: 1;
         // Physical Layer Enable
         volatile uint32_t PHYEN: 1;
         // Internal Pull-up Resistor Enable
         volatile uint32_t PUEN: 1;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_TCONTROL_DN_MASK  0x00000001
#define SI32_USB_A_TCONTROL_DN_SHIFT  0
// D- signal currently at logic 0.
#define SI32_USB_A_TCONTROL_DN_LOGIC_0_VALUE  0
#define SI32_USB_A_TCONTROL_DN_LOGIC_0_U32 \
   (SI32_USB_A_TCONTROL_DN_LOGIC_0_VALUE << SI32_USB_A_TCONTROL_DN_SHIFT)
// D- signal currently at logic 1.
#define SI32_USB_A_TCONTROL_DN_LOGIC_1_VALUE  1
#define SI32_USB_A_TCONTROL_DN_LOGIC_1_U32 \
   (SI32_USB_A_TCONTROL_DN_LOGIC_1_VALUE << SI32_USB_A_TCONTROL_DN_SHIFT)

#define SI32_USB_A_TCONTROL_DP_MASK  0x00000002
#define SI32_USB_A_TCONTROL_DP_SHIFT  1
// D+ signal currently at logic 0.
#define SI32_USB_A_TCONTROL_DP_LOGIC_0_VALUE  0
#define SI32_USB_A_TCONTROL_DP_LOGIC_0_U32 \
   (SI32_USB_A_TCONTROL_DP_LOGIC_0_VALUE << SI32_USB_A_TCONTROL_DP_SHIFT)
// D+ signal currently at logic 1.
#define SI32_USB_A_TCONTROL_DP_LOGIC_1_VALUE  1
#define SI32_USB_A_TCONTROL_DP_LOGIC_1_U32 \
   (SI32_USB_A_TCONTROL_DP_LOGIC_1_VALUE << SI32_USB_A_TCONTROL_DP_SHIFT)

#define SI32_USB_A_TCONTROL_DFREC_MASK  0x00000004
#define SI32_USB_A_TCONTROL_DFREC_SHIFT  2
// Differential 0 signalling is present on the bus.
#define SI32_USB_A_TCONTROL_DFREC_DIFF_0_VALUE  0
#define SI32_USB_A_TCONTROL_DFREC_DIFF_0_U32 \
   (SI32_USB_A_TCONTROL_DFREC_DIFF_0_VALUE << SI32_USB_A_TCONTROL_DFREC_SHIFT)
// Differential 1 signalling is present on the bus.
#define SI32_USB_A_TCONTROL_DFREC_DIFF_1_VALUE  1
#define SI32_USB_A_TCONTROL_DFREC_DIFF_1_U32 \
   (SI32_USB_A_TCONTROL_DFREC_DIFF_1_VALUE << SI32_USB_A_TCONTROL_DFREC_SHIFT)

#define SI32_USB_A_TCONTROL_PHYTST_MASK  0x00000018
#define SI32_USB_A_TCONTROL_PHYTST_SHIFT  3
// Mode 0: Normal (non-test mode) (D+ = X, D- = X).
#define SI32_USB_A_TCONTROL_PHYTST_MODE0_VALUE  0
#define SI32_USB_A_TCONTROL_PHYTST_MODE0_U32 \
   (SI32_USB_A_TCONTROL_PHYTST_MODE0_VALUE << SI32_USB_A_TCONTROL_PHYTST_SHIFT)
// Mode 1: Differential 1 Forced (D+ = 1, D- = 0).
#define SI32_USB_A_TCONTROL_PHYTST_MODE1_VALUE  1
#define SI32_USB_A_TCONTROL_PHYTST_MODE1_U32 \
   (SI32_USB_A_TCONTROL_PHYTST_MODE1_VALUE << SI32_USB_A_TCONTROL_PHYTST_SHIFT)
// Mode 2: Differential 0 Forced (D+ = 0, D- = 1).
#define SI32_USB_A_TCONTROL_PHYTST_MODE2_VALUE  2
#define SI32_USB_A_TCONTROL_PHYTST_MODE2_U32 \
   (SI32_USB_A_TCONTROL_PHYTST_MODE2_VALUE << SI32_USB_A_TCONTROL_PHYTST_SHIFT)
// Mode 3: Single-Ended 0 Forced (D+ = 0, D- = 0).
#define SI32_USB_A_TCONTROL_PHYTST_MODE3_VALUE  3
#define SI32_USB_A_TCONTROL_PHYTST_MODE3_U32 \
   (SI32_USB_A_TCONTROL_PHYTST_MODE3_VALUE << SI32_USB_A_TCONTROL_PHYTST_SHIFT)

#define SI32_USB_A_TCONTROL_SSEL_MASK  0x00000020
#define SI32_USB_A_TCONTROL_SSEL_SHIFT  5
// USB operates as a Low Speed device. If enabled, the internal pull-up resistor
// appears on the D- line.
#define SI32_USB_A_TCONTROL_SSEL_LOW_SPEED_VALUE  0
#define SI32_USB_A_TCONTROL_SSEL_LOW_SPEED_U32 \
   (SI32_USB_A_TCONTROL_SSEL_LOW_SPEED_VALUE << SI32_USB_A_TCONTROL_SSEL_SHIFT)
// USB operates as a Full Speed device. If enabled, the internal pull-up resistor
// appears on the D+ line.
#define SI32_USB_A_TCONTROL_SSEL_FULL_SPEED_VALUE  1
#define SI32_USB_A_TCONTROL_SSEL_FULL_SPEED_U32 \
   (SI32_USB_A_TCONTROL_SSEL_FULL_SPEED_VALUE << SI32_USB_A_TCONTROL_SSEL_SHIFT)

#define SI32_USB_A_TCONTROL_PHYEN_MASK  0x00000040
#define SI32_USB_A_TCONTROL_PHYEN_SHIFT  6
// Disable the USB physical layer Transceiver (suspend).
#define SI32_USB_A_TCONTROL_PHYEN_DISABLED_VALUE  0
#define SI32_USB_A_TCONTROL_PHYEN_DISABLED_U32 \
   (SI32_USB_A_TCONTROL_PHYEN_DISABLED_VALUE << SI32_USB_A_TCONTROL_PHYEN_SHIFT)
// Enable the USB physical layer Transceiver (normal).
#define SI32_USB_A_TCONTROL_PHYEN_ENABLED_VALUE  1
#define SI32_USB_A_TCONTROL_PHYEN_ENABLED_U32 \
   (SI32_USB_A_TCONTROL_PHYEN_ENABLED_VALUE << SI32_USB_A_TCONTROL_PHYEN_SHIFT)

#define SI32_USB_A_TCONTROL_PUEN_MASK  0x00000080
#define SI32_USB_A_TCONTROL_PUEN_SHIFT  7
// Disable the internal pull-up resistor (device effectively detached from the USB
// network).
#define SI32_USB_A_TCONTROL_PUEN_DISABLED_VALUE  0
#define SI32_USB_A_TCONTROL_PUEN_DISABLED_U32 \
   (SI32_USB_A_TCONTROL_PUEN_DISABLED_VALUE << SI32_USB_A_TCONTROL_PUEN_SHIFT)
// Enable the internal pull-up resistor when VBUS is present (device is attached to
// the USB network).
#define SI32_USB_A_TCONTROL_PUEN_ENABLED_VALUE  1
#define SI32_USB_A_TCONTROL_PUEN_ENABLED_U32 \
   (SI32_USB_A_TCONTROL_PUEN_ENABLED_VALUE << SI32_USB_A_TCONTROL_PUEN_SHIFT)



struct SI32_USB_A_CLKSEL_Struct
{
   union
   {
      struct
      {
         // USB Clock Select
         volatile uint32_t CLKSEL_BITS: 2;
                  uint32_t reserved0: 2;
         // USB Clock Divider
         volatile uint32_t CLKDIV: 2;
         // USB Reset
         volatile uint32_t RESET: 1;
                  uint32_t reserved1: 25;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_CLKSEL_CLKSEL_MASK  0x00000003
#define SI32_USB_A_CLKSEL_CLKSEL_SHIFT  0
// Select the USB Oscillator as the USB clock.
#define SI32_USB_A_CLKSEL_CLKSEL_USBNOSC_VALUE  0
#define SI32_USB_A_CLKSEL_CLKSEL_USBNOSC_U32 \
   (SI32_USB_A_CLKSEL_CLKSEL_USBNOSC_VALUE << SI32_USB_A_CLKSEL_CLKSEL_SHIFT)
// Select the PLL output as the USB clock.
#define SI32_USB_A_CLKSEL_CLKSEL_PLLNOSC_VALUE  1
#define SI32_USB_A_CLKSEL_CLKSEL_PLLNOSC_U32 \
   (SI32_USB_A_CLKSEL_CLKSEL_PLLNOSC_VALUE << SI32_USB_A_CLKSEL_CLKSEL_SHIFT)
// Select the External Oscillator output (EXTOSCn) as the USB clock.
#define SI32_USB_A_CLKSEL_CLKSEL_EXTOSCN_VALUE  2
#define SI32_USB_A_CLKSEL_CLKSEL_EXTOSCN_U32 \
   (SI32_USB_A_CLKSEL_CLKSEL_EXTOSCN_VALUE << SI32_USB_A_CLKSEL_CLKSEL_SHIFT)

#define SI32_USB_A_CLKSEL_CLKDIV_MASK  0x00000030
#define SI32_USB_A_CLKSEL_CLKDIV_SHIFT  4
// The USB module uses the selected input clock divided by 1.
#define SI32_USB_A_CLKSEL_CLKDIV_DIV1_VALUE  0
#define SI32_USB_A_CLKSEL_CLKDIV_DIV1_U32 \
   (SI32_USB_A_CLKSEL_CLKDIV_DIV1_VALUE << SI32_USB_A_CLKSEL_CLKDIV_SHIFT)
// The USB module uses the selected input clock divided by 2.
#define SI32_USB_A_CLKSEL_CLKDIV_DIV2_VALUE  1
#define SI32_USB_A_CLKSEL_CLKDIV_DIV2_U32 \
   (SI32_USB_A_CLKSEL_CLKDIV_DIV2_VALUE << SI32_USB_A_CLKSEL_CLKDIV_SHIFT)
// The USB module uses the selected input clock divided by 4.
#define SI32_USB_A_CLKSEL_CLKDIV_DIV4_VALUE  2
#define SI32_USB_A_CLKSEL_CLKDIV_DIV4_U32 \
   (SI32_USB_A_CLKSEL_CLKDIV_DIV4_VALUE << SI32_USB_A_CLKSEL_CLKDIV_SHIFT)
// The USB module uses the selected input clock divided by 8.
#define SI32_USB_A_CLKSEL_CLKDIV_DIV8_VALUE  3
#define SI32_USB_A_CLKSEL_CLKDIV_DIV8_U32 \
   (SI32_USB_A_CLKSEL_CLKDIV_DIV8_VALUE << SI32_USB_A_CLKSEL_CLKDIV_SHIFT)

#define SI32_USB_A_CLKSEL_RESET_MASK  0x00000040
#define SI32_USB_A_CLKSEL_RESET_SHIFT  6
// Do not reset the USB module.
#define SI32_USB_A_CLKSEL_RESET_NOT_SET_VALUE  0
#define SI32_USB_A_CLKSEL_RESET_NOT_SET_U32 \
   (SI32_USB_A_CLKSEL_RESET_NOT_SET_VALUE << SI32_USB_A_CLKSEL_RESET_SHIFT)
// Reset the USB module.
#define SI32_USB_A_CLKSEL_RESET_SET_VALUE  1
#define SI32_USB_A_CLKSEL_RESET_SET_U32 \
   (SI32_USB_A_CLKSEL_RESET_SET_VALUE << SI32_USB_A_CLKSEL_RESET_SHIFT)



struct SI32_USB_A_OSCCONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 5;
         // USB Oscillator Suspend
         volatile uint32_t SUSPEND: 1;
                  uint32_t reserved1: 1;
         // USB Oscillator Enable
         volatile uint32_t OSCEN: 1;
                  uint32_t reserved2: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_OSCCONTROL_SUSPEND_MASK  0x00000020
#define SI32_USB_A_OSCCONTROL_SUSPEND_SHIFT  5
// The USB oscillator is not suspended.
#define SI32_USB_A_OSCCONTROL_SUSPEND_DISABLED_VALUE  0
#define SI32_USB_A_OSCCONTROL_SUSPEND_DISABLED_U32 \
   (SI32_USB_A_OSCCONTROL_SUSPEND_DISABLED_VALUE << SI32_USB_A_OSCCONTROL_SUSPEND_SHIFT)
// Suspend the USB oscillator.
#define SI32_USB_A_OSCCONTROL_SUSPEND_ENABLED_VALUE  1
#define SI32_USB_A_OSCCONTROL_SUSPEND_ENABLED_U32 \
   (SI32_USB_A_OSCCONTROL_SUSPEND_ENABLED_VALUE << SI32_USB_A_OSCCONTROL_SUSPEND_SHIFT)

#define SI32_USB_A_OSCCONTROL_OSCEN_MASK  0x00000080
#define SI32_USB_A_OSCCONTROL_OSCEN_SHIFT  7
// Disable the USB oscillator.
#define SI32_USB_A_OSCCONTROL_OSCEN_DISABLED_VALUE  0
#define SI32_USB_A_OSCCONTROL_OSCEN_DISABLED_U32 \
   (SI32_USB_A_OSCCONTROL_OSCEN_DISABLED_VALUE << SI32_USB_A_OSCCONTROL_OSCEN_SHIFT)
// Enable the USB oscillator.
#define SI32_USB_A_OSCCONTROL_OSCEN_ENABLED_VALUE  1
#define SI32_USB_A_OSCCONTROL_OSCEN_ENABLED_U32 \
   (SI32_USB_A_OSCCONTROL_OSCEN_ENABLED_VALUE << SI32_USB_A_OSCCONTROL_OSCEN_SHIFT)



struct SI32_USB_A_AFADJUST_Struct
{
   union
   {
      struct
      {
         // USB Oscillator Fine Output Frequency Adjust
         volatile uint32_t FINEFADJ: 6;
         // USB Oscillator Dithering Enable
         volatile uint32_t DITHEN: 1;
                  uint32_t reserved0: 25;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_AFADJUST_FINEFADJ_MASK  0x0000003F
#define SI32_USB_A_AFADJUST_FINEFADJ_SHIFT  0

#define SI32_USB_A_AFADJUST_DITHEN_MASK  0x00000040
#define SI32_USB_A_AFADJUST_DITHEN_SHIFT  6
// Disable USB oscillator dithering.
#define SI32_USB_A_AFADJUST_DITHEN_DISABLED_VALUE  0
#define SI32_USB_A_AFADJUST_DITHEN_DISABLED_U32 \
   (SI32_USB_A_AFADJUST_DITHEN_DISABLED_VALUE << SI32_USB_A_AFADJUST_DITHEN_SHIFT)
// Enable USB oscillator dithering.
#define SI32_USB_A_AFADJUST_DITHEN_ENABLED_VALUE  1
#define SI32_USB_A_AFADJUST_DITHEN_ENABLED_U32 \
   (SI32_USB_A_AFADJUST_DITHEN_ENABLED_VALUE << SI32_USB_A_AFADJUST_DITHEN_SHIFT)



struct SI32_USB_A_FADJUST_Struct
{
   union
   {
      struct
      {
         // Oscillator Output Frequency Adjust
         volatile uint32_t FADJ: 7;
                  uint32_t reserved0: 25;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_FADJUST_FADJ_MASK  0x0000007F
#define SI32_USB_A_FADJUST_FADJ_SHIFT  0



struct SI32_USB_A_DMAFIFO_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_DMAFIFO_DMAFIFO_MASK  0xFFFFFFFF
#define SI32_USB_A_DMAFIFO_DMAFIFO_SHIFT  0



struct SI32_USB_A_DMACONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 4;
         // USB DMA Debug Mode
         volatile uint32_t DBGMD: 1;
         // Timeout Error Flag
         volatile uint32_t TERRF: 1;
         // USB DMA Busy Flag
         volatile uint32_t DBUSYF: 1;
         // USB DMA Buffer Flush Control
         volatile uint32_t DFIFOFL: 1;
                  uint32_t reserved1: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_DMACONTROL_DBGMD_MASK  0x00000010
#define SI32_USB_A_DMACONTROL_DBGMD_SHIFT  4
// The USB module will continue to operate while the core is halted in debug mode.
#define SI32_USB_A_DMACONTROL_DBGMD_RUN_VALUE  0
#define SI32_USB_A_DMACONTROL_DBGMD_RUN_U32 \
   (SI32_USB_A_DMACONTROL_DBGMD_RUN_VALUE << SI32_USB_A_DMACONTROL_DBGMD_SHIFT)
// A debug breakpoint will prevent the USB DMA buffer from transferring data to and
// from the USB FIFOs when the core is halted.
#define SI32_USB_A_DMACONTROL_DBGMD_HALT_VALUE  1
#define SI32_USB_A_DMACONTROL_DBGMD_HALT_U32 \
   (SI32_USB_A_DMACONTROL_DBGMD_HALT_VALUE << SI32_USB_A_DMACONTROL_DBGMD_SHIFT)

#define SI32_USB_A_DMACONTROL_TERRF_MASK  0x00000020
#define SI32_USB_A_DMACONTROL_TERRF_SHIFT  5
// A timeout error has not occurred.
#define SI32_USB_A_DMACONTROL_TERRF_NOT_SET_VALUE  0
#define SI32_USB_A_DMACONTROL_TERRF_NOT_SET_U32 \
   (SI32_USB_A_DMACONTROL_TERRF_NOT_SET_VALUE << SI32_USB_A_DMACONTROL_TERRF_SHIFT)
// A timeout error occurred.
#define SI32_USB_A_DMACONTROL_TERRF_SET_VALUE  1
#define SI32_USB_A_DMACONTROL_TERRF_SET_U32 \
   (SI32_USB_A_DMACONTROL_TERRF_SET_VALUE << SI32_USB_A_DMACONTROL_TERRF_SHIFT)

#define SI32_USB_A_DMACONTROL_DBUSYF_MASK  0x00000040
#define SI32_USB_A_DMACONTROL_DBUSYF_SHIFT  6
// The DMA buffer is not busy.
#define SI32_USB_A_DMACONTROL_DBUSYF_NOT_SET_VALUE  0
#define SI32_USB_A_DMACONTROL_DBUSYF_NOT_SET_U32 \
   (SI32_USB_A_DMACONTROL_DBUSYF_NOT_SET_VALUE << SI32_USB_A_DMACONTROL_DBUSYF_SHIFT)
// The DMA buffer is busy reading or writing an 8-word packet.
#define SI32_USB_A_DMACONTROL_DBUSYF_SET_VALUE  1
#define SI32_USB_A_DMACONTROL_DBUSYF_SET_U32 \
   (SI32_USB_A_DMACONTROL_DBUSYF_SET_VALUE << SI32_USB_A_DMACONTROL_DBUSYF_SHIFT)

#define SI32_USB_A_DMACONTROL_DFIFOFL_MASK  0x00000080
#define SI32_USB_A_DMACONTROL_DFIFOFL_SHIFT  7
// Flush the USB DMA buffer.
#define SI32_USB_A_DMACONTROL_DFIFOFL_SET_VALUE  1
#define SI32_USB_A_DMACONTROL_DFIFOFL_SET_U32 \
   (SI32_USB_A_DMACONTROL_DFIFOFL_SET_VALUE << SI32_USB_A_DMACONTROL_DFIFOFL_SHIFT)



struct SI32_USB_A_EP0CONTROL_Struct
{
   union
   {
      struct
      {
         // OUT Packet Ready Interrupt Flag
         volatile uint32_t OPRDYI: 1;
         // IN Packet Ready Indicator
         volatile uint32_t IPRDYI: 1;
         // Sent Stall Interrupt Flag
         volatile uint32_t STSTLI: 1;
         // Data End
         volatile uint32_t DEND: 1;
         // Setup End Interrupt Flag
         volatile uint32_t SUENDI: 1;
         // Send Stall
         volatile uint32_t SDSTL: 1;
         // Serviced Out Packet Ready Interrupt Flag
         volatile uint32_t OPRDYIS: 1;
         // Serviced Setup End Interrupt Flag
         volatile uint32_t SUENDIS: 1;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_EP0CONTROL_OPRDYI_MASK  0x00000001
#define SI32_USB_A_EP0CONTROL_OPRDYI_SHIFT  0
// A packet is not available.
#define SI32_USB_A_EP0CONTROL_OPRDYI_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_OPRDYI_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_OPRDYI_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_OPRDYI_SHIFT)
// A packet is available.
#define SI32_USB_A_EP0CONTROL_OPRDYI_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_OPRDYI_SET_U32 \
   (SI32_USB_A_EP0CONTROL_OPRDYI_SET_VALUE << SI32_USB_A_EP0CONTROL_OPRDYI_SHIFT)

#define SI32_USB_A_EP0CONTROL_IPRDYI_MASK  0x00000002
#define SI32_USB_A_EP0CONTROL_IPRDYI_SHIFT  1
// A packet is not ready for transmission to host.
#define SI32_USB_A_EP0CONTROL_IPRDYI_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_IPRDYI_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_IPRDYI_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_IPRDYI_SHIFT)
// A packet is ready for transmission to host.
#define SI32_USB_A_EP0CONTROL_IPRDYI_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_IPRDYI_SET_U32 \
   (SI32_USB_A_EP0CONTROL_IPRDYI_SET_VALUE << SI32_USB_A_EP0CONTROL_IPRDYI_SHIFT)

#define SI32_USB_A_EP0CONTROL_STSTLI_MASK  0x00000004
#define SI32_USB_A_EP0CONTROL_STSTLI_SHIFT  2
// Read: A STALL handshake has not been sent or is cleared. Write: Clear the
// interrupt.
#define SI32_USB_A_EP0CONTROL_STSTLI_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_STSTLI_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_STSTLI_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_STSTLI_SHIFT)
// Read: STALL handshake sent. Write: No effect.
#define SI32_USB_A_EP0CONTROL_STSTLI_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_STSTLI_SET_U32 \
   (SI32_USB_A_EP0CONTROL_STSTLI_SET_VALUE << SI32_USB_A_EP0CONTROL_STSTLI_SHIFT)

#define SI32_USB_A_EP0CONTROL_DEND_MASK  0x00000008
#define SI32_USB_A_EP0CONTROL_DEND_SHIFT  3
// The current packet is not the last packet of the transfer.
#define SI32_USB_A_EP0CONTROL_DEND_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_DEND_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_DEND_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_DEND_SHIFT)
// The current packet is the last packet of the transfer.
#define SI32_USB_A_EP0CONTROL_DEND_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_DEND_SET_U32 \
   (SI32_USB_A_EP0CONTROL_DEND_SET_VALUE << SI32_USB_A_EP0CONTROL_DEND_SHIFT)

#define SI32_USB_A_EP0CONTROL_SUENDI_MASK  0x00000010
#define SI32_USB_A_EP0CONTROL_SUENDI_SHIFT  4
// The current packet is not the last packet of setup.
#define SI32_USB_A_EP0CONTROL_SUENDI_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_SUENDI_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_SUENDI_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_SUENDI_SHIFT)
// The current packet is the last packet of setup.
#define SI32_USB_A_EP0CONTROL_SUENDI_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_SUENDI_SET_U32 \
   (SI32_USB_A_EP0CONTROL_SUENDI_SET_VALUE << SI32_USB_A_EP0CONTROL_SUENDI_SHIFT)

#define SI32_USB_A_EP0CONTROL_SDSTL_MASK  0x00000020
#define SI32_USB_A_EP0CONTROL_SDSTL_SHIFT  5
// The STALL handshake has been transmitted or not triggered.
#define SI32_USB_A_EP0CONTROL_SDSTL_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_SDSTL_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_SDSTL_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_SDSTL_SHIFT)
// Initiate a STALL condition.
#define SI32_USB_A_EP0CONTROL_SDSTL_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_SDSTL_SET_U32 \
   (SI32_USB_A_EP0CONTROL_SDSTL_SET_VALUE << SI32_USB_A_EP0CONTROL_SDSTL_SHIFT)

#define SI32_USB_A_EP0CONTROL_OPRDYIS_MASK  0x00000040
#define SI32_USB_A_EP0CONTROL_OPRDYIS_SHIFT  6
// The out packet has not been processed.
#define SI32_USB_A_EP0CONTROL_OPRDYIS_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_OPRDYIS_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_OPRDYIS_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_OPRDYIS_SHIFT)
// The out packet has been received and accepted.
#define SI32_USB_A_EP0CONTROL_OPRDYIS_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_OPRDYIS_SET_U32 \
   (SI32_USB_A_EP0CONTROL_OPRDYIS_SET_VALUE << SI32_USB_A_EP0CONTROL_OPRDYIS_SHIFT)

#define SI32_USB_A_EP0CONTROL_SUENDIS_MASK  0x00000080
#define SI32_USB_A_EP0CONTROL_SUENDIS_SHIFT  7
// Setup end has not been serviced.
#define SI32_USB_A_EP0CONTROL_SUENDIS_NOT_SET_VALUE  0
#define SI32_USB_A_EP0CONTROL_SUENDIS_NOT_SET_U32 \
   (SI32_USB_A_EP0CONTROL_SUENDIS_NOT_SET_VALUE << SI32_USB_A_EP0CONTROL_SUENDIS_SHIFT)
// Setup end has been serviced.
#define SI32_USB_A_EP0CONTROL_SUENDIS_SET_VALUE  1
#define SI32_USB_A_EP0CONTROL_SUENDIS_SET_U32 \
   (SI32_USB_A_EP0CONTROL_SUENDIS_SET_VALUE << SI32_USB_A_EP0CONTROL_SUENDIS_SHIFT)



struct SI32_USB_A_EP0COUNT_Struct
{
   union
   {
      struct
      {
         // Endpoint 0 OUT Data Count
         volatile uint32_t COUNT: 7;
                  uint32_t reserved0: 25;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_EP0COUNT_COUNT_MASK  0x0000007F
#define SI32_USB_A_EP0COUNT_COUNT_SHIFT  0



struct SI32_USB_A_EP0FIFO_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_USB_A_EP0FIFO_FIFO_MASK  0xFFFFFFFF
#define SI32_USB_A_EP0FIFO_FIFO_SHIFT  0



typedef struct SI32_USB_A_Struct
{
   struct SI32_USB_A_FADDR_Struct                  FADDR          ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_USB_A_POWER_Struct                  POWER          ; // Base Address + 0x10
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   struct SI32_USB_A_IOINT_Struct                  IOINT          ; // Base Address + 0x20
   uint32_t                                        reserved6;
   volatile uint32_t                               IOINT_CLR;
   uint32_t                                        reserved7;
   struct SI32_USB_A_CMINT_Struct                  CMINT          ; // Base Address + 0x30
   uint32_t                                        reserved8;
   volatile uint32_t                               CMINT_CLR;
   uint32_t                                        reserved9;
   struct SI32_USB_A_IOINTE_Struct                 IOINTE         ; // Base Address + 0x40
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   struct SI32_USB_A_CMINTEPE_Struct               CMINTEPE       ; // Base Address + 0x50
   uint32_t                                        reserved13;
   uint32_t                                        reserved14;
   uint32_t                                        reserved15;
   struct SI32_USB_A_CRCONTROL_Struct              CRCONTROL      ; // Base Address + 0x60
   uint32_t                                        reserved16;
   uint32_t                                        reserved17;
   uint32_t                                        reserved18;
   struct SI32_USB_A_FRAME_Struct                  FRAME          ; // Base Address + 0x70
   uint32_t                                        reserved19;
   uint32_t                                        reserved20;
   uint32_t                                        reserved21;
   uint32_t                                        reserved22[96];
   struct SI32_USB_A_TCONTROL_Struct               TCONTROL       ; // Base Address + 0x200
   uint32_t                                        reserved23;
   uint32_t                                        reserved24;
   uint32_t                                        reserved25;
   uint32_t                                        reserved26[60];
   struct SI32_USB_A_CLKSEL_Struct                 CLKSEL         ; // Base Address + 0x300
   uint32_t                                        reserved27;
   uint32_t                                        reserved28;
   uint32_t                                        reserved29;
   struct SI32_USB_A_OSCCONTROL_Struct             OSCCONTROL     ; // Base Address + 0x310
   volatile uint32_t                               OSCCONTROL_SET;
   volatile uint32_t                               OSCCONTROL_CLR;
   uint32_t                                        reserved30;
   struct SI32_USB_A_AFADJUST_Struct               AFADJUST       ; // Base Address + 0x320
   volatile uint32_t                               AFADJUST_SET;
   volatile uint32_t                               AFADJUST_CLR;
   uint32_t                                        reserved31;
   struct SI32_USB_A_FADJUST_Struct                FADJUST        ; // Base Address + 0x330
   uint32_t                                        reserved32;
   uint32_t                                        reserved33;
   uint32_t                                        reserved34;
   uint32_t                                        reserved35[4];
   uint32_t                                        reserved36[4];
   uint32_t                                        reserved37[40];
   struct SI32_USB_A_DMAFIFO_Struct                DMAFIFO        ; // Base Address + 0x400
   uint32_t                                        reserved38;
   uint32_t                                        reserved39;
   uint32_t                                        reserved40;
   struct SI32_USB_A_DMACONTROL_Struct             DMACONTROL     ; // Base Address + 0x410
   uint32_t                                        reserved41;
   uint32_t                                        reserved42;
   uint32_t                                        reserved43;
   uint32_t                                        reserved44[252];
   struct SI32_USB_A_EP0CONTROL_Struct             EP0CONTROL     ; // Base Address + 0x810
   uint32_t                                        reserved45;
   uint32_t                                        reserved46;
   uint32_t                                        reserved47;
   struct SI32_USB_A_EP0COUNT_Struct               EP0COUNT       ; // Base Address + 0x820
   uint32_t                                        reserved48;
   uint32_t                                        reserved49;
   uint32_t                                        reserved50;
   struct SI32_USB_A_EP0FIFO_Struct                EP0FIFO        ; // Base Address + 0x830
   uint32_t                                        reserved51;
   uint32_t                                        reserved52;
   uint32_t                                        reserved53;
} SI32_USB_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_USB_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

