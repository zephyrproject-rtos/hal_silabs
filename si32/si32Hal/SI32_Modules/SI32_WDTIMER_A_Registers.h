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

#ifndef __SI32_WDTIMER_A_REGISTERS_H__
#define __SI32_WDTIMER_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_WDTIMER_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Early Warning Interrupt Enable
         volatile uint32_t EWIEN: 1;
         // Watchdog Timer Debug Mode
         volatile uint32_t DBGMD: 1;
                  uint32_t reserved0: 30;
      };
      volatile uint32_t U32;
   };
};

#define SI32_WDTIMER_A_CONTROL_EWIEN_MASK  0x00000001
#define SI32_WDTIMER_A_CONTROL_EWIEN_SHIFT  0
// Disable the early warning interrupt (EWI).
#define SI32_WDTIMER_A_CONTROL_EWIEN_DISABLED_VALUE  0
#define SI32_WDTIMER_A_CONTROL_EWIEN_DISABLED_U32 \
   (SI32_WDTIMER_A_CONTROL_EWIEN_DISABLED_VALUE << SI32_WDTIMER_A_CONTROL_EWIEN_SHIFT)
// Enable the early warning interrupt (EWI).
#define SI32_WDTIMER_A_CONTROL_EWIEN_ENABLED_VALUE  1
#define SI32_WDTIMER_A_CONTROL_EWIEN_ENABLED_U32 \
   (SI32_WDTIMER_A_CONTROL_EWIEN_ENABLED_VALUE << SI32_WDTIMER_A_CONTROL_EWIEN_SHIFT)

#define SI32_WDTIMER_A_CONTROL_DBGMD_MASK  0x00000002
#define SI32_WDTIMER_A_CONTROL_DBGMD_SHIFT  1
// The WDTIMER module will continue to operate while the core is halted in debug
// mode.
#define SI32_WDTIMER_A_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_WDTIMER_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_WDTIMER_A_CONTROL_DBGMD_RUN_VALUE << SI32_WDTIMER_A_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the WDTIMER module to halt.
#define SI32_WDTIMER_A_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_WDTIMER_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_WDTIMER_A_CONTROL_DBGMD_HALT_VALUE << SI32_WDTIMER_A_CONTROL_DBGMD_SHIFT)



struct SI32_WDTIMER_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Key Status
         volatile uint32_t KEYSTS: 1;
         // Register Access Status
         volatile uint32_t PRIVSTS: 1;
         // Early Warning Interrupt Flag
         volatile uint32_t EWI: 1;
         // Reset Threshold Flag
         volatile uint32_t RTHF: 1;
         // Watchdog Timer Threshold Update Status
         volatile uint32_t UPDSTS: 1;
                  uint32_t reserved0: 27;
      };
      volatile uint32_t U32;
   };
};

#define SI32_WDTIMER_A_STATUS_KEYSTS_MASK  0x00000001
#define SI32_WDTIMER_A_STATUS_KEYSTS_SHIFT  0
// No keys have been processed by the interface.
#define SI32_WDTIMER_A_STATUS_KEYSTS_IDLE_VALUE  0
#define SI32_WDTIMER_A_STATUS_KEYSTS_IDLE_U32 \
   (SI32_WDTIMER_A_STATUS_KEYSTS_IDLE_VALUE << SI32_WDTIMER_A_STATUS_KEYSTS_SHIFT)
// The attention key has been received and the module is awaiting a command.
#define SI32_WDTIMER_A_STATUS_KEYSTS_READY_VALUE  1
#define SI32_WDTIMER_A_STATUS_KEYSTS_READY_U32 \
   (SI32_WDTIMER_A_STATUS_KEYSTS_READY_VALUE << SI32_WDTIMER_A_STATUS_KEYSTS_SHIFT)

#define SI32_WDTIMER_A_STATUS_PRIVSTS_MASK  0x00000002
#define SI32_WDTIMER_A_STATUS_PRIVSTS_SHIFT  1
// The watchdog timer registers are currently read-only.
#define SI32_WDTIMER_A_STATUS_PRIVSTS_READ_ONLY_VALUE  0
#define SI32_WDTIMER_A_STATUS_PRIVSTS_READ_ONLY_U32 \
   (SI32_WDTIMER_A_STATUS_PRIVSTS_READ_ONLY_VALUE << SI32_WDTIMER_A_STATUS_PRIVSTS_SHIFT)
// A write transaction can be performed on the module registers.
#define SI32_WDTIMER_A_STATUS_PRIVSTS_READ_WRITE_VALUE  1
#define SI32_WDTIMER_A_STATUS_PRIVSTS_READ_WRITE_U32 \
   (SI32_WDTIMER_A_STATUS_PRIVSTS_READ_WRITE_VALUE << SI32_WDTIMER_A_STATUS_PRIVSTS_SHIFT)

#define SI32_WDTIMER_A_STATUS_EWI_MASK  0x00000004
#define SI32_WDTIMER_A_STATUS_EWI_SHIFT  2
// Read: An early warning match did not occur. Write: Clear the early warning
// interrupt.
#define SI32_WDTIMER_A_STATUS_EWI_NOT_SET_VALUE  0
#define SI32_WDTIMER_A_STATUS_EWI_NOT_SET_U32 \
   (SI32_WDTIMER_A_STATUS_EWI_NOT_SET_VALUE << SI32_WDTIMER_A_STATUS_EWI_SHIFT)
// Read: An early warning match occurred and the interrupt is pending. Write: Force
// a watchdog timer early warning interrupt to occur.
#define SI32_WDTIMER_A_STATUS_EWI_SET_VALUE  1
#define SI32_WDTIMER_A_STATUS_EWI_SET_U32 \
   (SI32_WDTIMER_A_STATUS_EWI_SET_VALUE << SI32_WDTIMER_A_STATUS_EWI_SHIFT)

#define SI32_WDTIMER_A_STATUS_RTHF_MASK  0x00000008
#define SI32_WDTIMER_A_STATUS_RTHF_SHIFT  3
// The counter is currently less than the reset threshold (RTH) value.
#define SI32_WDTIMER_A_STATUS_RTHF_LT_VALUE  0
#define SI32_WDTIMER_A_STATUS_RTHF_LT_U32 \
   (SI32_WDTIMER_A_STATUS_RTHF_LT_VALUE << SI32_WDTIMER_A_STATUS_RTHF_SHIFT)
// The counter is currently greater than or equal to the reset threshold (RTH)
// value.
#define SI32_WDTIMER_A_STATUS_RTHF_GTE_VALUE  1
#define SI32_WDTIMER_A_STATUS_RTHF_GTE_U32 \
   (SI32_WDTIMER_A_STATUS_RTHF_GTE_VALUE << SI32_WDTIMER_A_STATUS_RTHF_SHIFT)

#define SI32_WDTIMER_A_STATUS_UPDSTS_MASK  0x00000010
#define SI32_WDTIMER_A_STATUS_UPDSTS_SHIFT  4
// An update completed or is not pending. The EWTH and RTH fields can be written.
#define SI32_WDTIMER_A_STATUS_UPDSTS_IDLE_VALUE  0
#define SI32_WDTIMER_A_STATUS_UPDSTS_IDLE_U32 \
   (SI32_WDTIMER_A_STATUS_UPDSTS_IDLE_VALUE << SI32_WDTIMER_A_STATUS_UPDSTS_SHIFT)
// An update of the threshold register is occurring. The EWTH and RTH fields should
// not be modified until hardware clears UPDSTS to 0.
#define SI32_WDTIMER_A_STATUS_UPDSTS_UPDATING_VALUE  1
#define SI32_WDTIMER_A_STATUS_UPDSTS_UPDATING_U32 \
   (SI32_WDTIMER_A_STATUS_UPDSTS_UPDATING_VALUE << SI32_WDTIMER_A_STATUS_UPDSTS_SHIFT)



struct SI32_WDTIMER_A_THRESHOLD_Struct
{
   union
   {
      struct
      {
         // Early Warning Threshold
         volatile uint16_t EWTH;
         // Reset Threshold
         volatile uint16_t RTH;
      };
      volatile uint32_t U32;
   };
};

#define SI32_WDTIMER_A_THRESHOLD_EWTH_MASK  0x0000FFFF
#define SI32_WDTIMER_A_THRESHOLD_EWTH_SHIFT  0

#define SI32_WDTIMER_A_THRESHOLD_RTH_MASK  0xFFFF0000
#define SI32_WDTIMER_A_THRESHOLD_RTH_SHIFT  16



struct SI32_WDTIMER_A_WDTKEY_Struct
{
   union
   {
      struct
      {
         // Watchdog Timer Key
         volatile uint8_t KEY;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_WDTIMER_A_WDTKEY_KEY_MASK  0x000000FF
#define SI32_WDTIMER_A_WDTKEY_KEY_SHIFT  0
// Attention key to start the command sequence.
#define SI32_WDTIMER_A_WDTKEY_KEY_ATTN_VALUE  165
#define SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32 \
   (SI32_WDTIMER_A_WDTKEY_KEY_ATTN_VALUE << SI32_WDTIMER_A_WDTKEY_KEY_SHIFT)
// Reset the watchdog timer.
#define SI32_WDTIMER_A_WDTKEY_KEY_RESET_VALUE  204
#define SI32_WDTIMER_A_WDTKEY_KEY_RESET_U32 \
   (SI32_WDTIMER_A_WDTKEY_KEY_RESET_VALUE << SI32_WDTIMER_A_WDTKEY_KEY_SHIFT)
// Disable the watchdog timer.
#define SI32_WDTIMER_A_WDTKEY_KEY_DISABLE_VALUE  221
#define SI32_WDTIMER_A_WDTKEY_KEY_DISABLE_U32 \
   (SI32_WDTIMER_A_WDTKEY_KEY_DISABLE_VALUE << SI32_WDTIMER_A_WDTKEY_KEY_SHIFT)
// Start the watchdog timer.
#define SI32_WDTIMER_A_WDTKEY_KEY_START_VALUE  238
#define SI32_WDTIMER_A_WDTKEY_KEY_START_U32 \
   (SI32_WDTIMER_A_WDTKEY_KEY_START_VALUE << SI32_WDTIMER_A_WDTKEY_KEY_SHIFT)
// Allow one write access to the module registers.
#define SI32_WDTIMER_A_WDTKEY_KEY_WRITE_VALUE  241
#define SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32 \
   (SI32_WDTIMER_A_WDTKEY_KEY_WRITE_VALUE << SI32_WDTIMER_A_WDTKEY_KEY_SHIFT)
// Lock the module from any other writes until the next system reset.
#define SI32_WDTIMER_A_WDTKEY_KEY_LOCK_VALUE  255
#define SI32_WDTIMER_A_WDTKEY_KEY_LOCK_U32 \
   (SI32_WDTIMER_A_WDTKEY_KEY_LOCK_VALUE << SI32_WDTIMER_A_WDTKEY_KEY_SHIFT)



typedef struct SI32_WDTIMER_A_Struct
{
   struct SI32_WDTIMER_A_CONTROL_Struct            CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_WDTIMER_A_STATUS_Struct             STATUS         ; // Base Address + 0x10
   volatile uint32_t                               STATUS_SET;
   volatile uint32_t                               STATUS_CLR;
   uint32_t                                        reserved1;
   struct SI32_WDTIMER_A_THRESHOLD_Struct          THRESHOLD      ; // Base Address + 0x20
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   struct SI32_WDTIMER_A_WDTKEY_Struct             WDTKEY         ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   uint32_t                                        reserved8[4];
   uint32_t                                        reserved9[4];
} SI32_WDTIMER_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_WDTIMER_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

