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

#ifndef __SI32_USBEP_A_REGISTERS_H__
#define __SI32_USBEP_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_USBEP_A_EPMPSIZE_Struct
{
   union
   {
      struct
      {
         // IN Maximum Packet Size
         volatile uint8_t IMAXP;
                  uint32_t reserved0: 8;
         // OUT Maximum Packet Size
         volatile uint8_t OMAXP;
                  uint32_t reserved1: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USBEP_A_EPMPSIZE_IMAXP_MASK  0x000000FF
#define SI32_USBEP_A_EPMPSIZE_IMAXP_SHIFT  0

#define SI32_USBEP_A_EPMPSIZE_OMAXP_MASK  0x00FF0000
#define SI32_USBEP_A_EPMPSIZE_OMAXP_SHIFT  16



struct SI32_USBEP_A_EPCONTROL_Struct
{
   union
   {
      struct
      {
         // IN Packet Ready Indicator
         volatile uint32_t IPRDYI: 1;
         // IN FIFO Not Empty Flag
         volatile uint32_t IFIFONEF: 1;
         // IN FIFO Underrun Flag
         volatile uint32_t IURF: 1;
         // IN FIFO Flush
         volatile uint32_t IFIFOFL: 1;
         // IN Send Stall
         volatile uint32_t ISDSTL: 1;
         // IN Sent Stall Interrupt Flag
         volatile uint32_t ISTSTLI: 1;
         // IN Clear Data Toggle
         volatile uint32_t ICLRDT: 1;
                  uint32_t reserved0: 3;
         // FIFO Split Enable
         volatile uint32_t SPLITEN: 1;
         // Force Data Toggle Enable
         volatile uint32_t FDTEN: 1;
         // IN Endpoint DMA Enable
         volatile uint32_t IDMAEN: 1;
         // Endpoint Direction Select
         volatile uint32_t DIRSEL: 1;
         // IN Isochronous Transfer Enable
         volatile uint32_t IISOEN: 1;
         // IN Endpoint IPRDYI Automatic Set Enable
         volatile uint32_t AUTOSETEN: 1;
         // OUT Packet Ready
         volatile uint32_t OPRDYI: 1;
         // OUT FIFO Full
         volatile uint32_t OFIFOFF: 1;
         // OUT FIFO Overrun Flag
         volatile uint32_t OORF: 1;
         // OUT Data Error Flag
         volatile uint32_t ODERRF: 1;
         // OUT FIFO Flush
         volatile uint32_t OFIFOFL: 1;
         // OUT Send Stall
         volatile uint32_t OSDSTL: 1;
         // OUT Sent Stall Interrupt Flag
         volatile uint32_t OSTSTLI: 1;
         // OUT Clear Data Toggle
         volatile uint32_t OCLRDT: 1;
                  uint32_t reserved1: 4;
         // OUT Endpoint DMA Mode
         volatile uint32_t ODMAMD: 1;
         // OUT Endpoint DMA Enable
         volatile uint32_t ODMAEN: 1;
         // OUT Isochronous Transfer Enable
         volatile uint32_t OISOEN: 1;
         // OUT Endpoint OPRDYI Auto-Clear Enable
         volatile uint32_t AUTOCLREN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USBEP_A_EPCONTROL_IPRDYI_MASK  0x00000001
#define SI32_USBEP_A_EPCONTROL_IPRDYI_SHIFT  0
// The packet has been sent or there is an open FIFO slot.
#define SI32_USBEP_A_EPCONTROL_IPRDYI_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_IPRDYI_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_IPRDYI_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_IPRDYI_SHIFT)
// A packet is loaded in the FIFO.
#define SI32_USBEP_A_EPCONTROL_IPRDYI_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_IPRDYI_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_IPRDYI_SET_VALUE << SI32_USBEP_A_EPCONTROL_IPRDYI_SHIFT)

#define SI32_USBEP_A_EPCONTROL_IFIFONEF_MASK  0x00000002
#define SI32_USBEP_A_EPCONTROL_IFIFONEF_SHIFT  1
// The IN Endpoint FIFO is empty.
#define SI32_USBEP_A_EPCONTROL_IFIFONEF_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_IFIFONEF_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_IFIFONEF_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_IFIFONEF_SHIFT)
// The IN Endpoint FIFO contains one or more packets.
#define SI32_USBEP_A_EPCONTROL_IFIFONEF_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_IFIFONEF_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_IFIFONEF_SET_VALUE << SI32_USBEP_A_EPCONTROL_IFIFONEF_SHIFT)

#define SI32_USBEP_A_EPCONTROL_IURF_MASK  0x00000004
#define SI32_USBEP_A_EPCONTROL_IURF_SHIFT  2
// Underrun has not occurred.
#define SI32_USBEP_A_EPCONTROL_IURF_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_IURF_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_IURF_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_IURF_SHIFT)
// Underrun occurred.
#define SI32_USBEP_A_EPCONTROL_IURF_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_IURF_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_IURF_SET_VALUE << SI32_USBEP_A_EPCONTROL_IURF_SHIFT)

#define SI32_USBEP_A_EPCONTROL_IFIFOFL_MASK  0x00000008
#define SI32_USBEP_A_EPCONTROL_IFIFOFL_SHIFT  3
// Flush the IN FIFO.
#define SI32_USBEP_A_EPCONTROL_IFIFOFL_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_IFIFOFL_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_IFIFOFL_SET_VALUE << SI32_USBEP_A_EPCONTROL_IFIFOFL_SHIFT)

#define SI32_USBEP_A_EPCONTROL_ISDSTL_MASK  0x00000010
#define SI32_USBEP_A_EPCONTROL_ISDSTL_SHIFT  4
// Stop sending a stall.
#define SI32_USBEP_A_EPCONTROL_ISDSTL_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_ISDSTL_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_ISDSTL_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_ISDSTL_SHIFT)
// Generate a stall.
#define SI32_USBEP_A_EPCONTROL_ISDSTL_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_ISDSTL_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_ISDSTL_SET_VALUE << SI32_USBEP_A_EPCONTROL_ISDSTL_SHIFT)

#define SI32_USBEP_A_EPCONTROL_ISTSTLI_MASK  0x00000020
#define SI32_USBEP_A_EPCONTROL_ISTSTLI_SHIFT  5
// Read: A stall condition has not been sent since this bit was last cleared.
// Write: Clear the interrupt.
#define SI32_USBEP_A_EPCONTROL_ISTSTLI_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_ISTSTLI_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_ISTSTLI_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_ISTSTLI_SHIFT)
// Read: A stall condition has been sent since this bit was last cleared. Write: No
// effect.
#define SI32_USBEP_A_EPCONTROL_ISTSTLI_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_ISTSTLI_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_ISTSTLI_SET_VALUE << SI32_USBEP_A_EPCONTROL_ISTSTLI_SHIFT)

#define SI32_USBEP_A_EPCONTROL_ICLRDT_MASK  0x00000040
#define SI32_USBEP_A_EPCONTROL_ICLRDT_SHIFT  6
// Do not reset the IN data toggle.
#define SI32_USBEP_A_EPCONTROL_ICLRDT_NO_RESET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_ICLRDT_NO_RESET_U32 \
   (SI32_USBEP_A_EPCONTROL_ICLRDT_NO_RESET_VALUE << SI32_USBEP_A_EPCONTROL_ICLRDT_SHIFT)
// Reset the IN data toggle.
#define SI32_USBEP_A_EPCONTROL_ICLRDT_RESET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_ICLRDT_RESET_U32 \
   (SI32_USBEP_A_EPCONTROL_ICLRDT_RESET_VALUE << SI32_USBEP_A_EPCONTROL_ICLRDT_SHIFT)

#define SI32_USBEP_A_EPCONTROL_SPLITEN_MASK  0x00000400
#define SI32_USBEP_A_EPCONTROL_SPLITEN_SHIFT  10
// Do not split the endpoint FIFO.
#define SI32_USBEP_A_EPCONTROL_SPLITEN_DISABLED_VALUE  0
#define SI32_USBEP_A_EPCONTROL_SPLITEN_DISABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_SPLITEN_DISABLED_VALUE << SI32_USBEP_A_EPCONTROL_SPLITEN_SHIFT)
// Split the endpoint FIFO.
#define SI32_USBEP_A_EPCONTROL_SPLITEN_ENABLED_VALUE  1
#define SI32_USBEP_A_EPCONTROL_SPLITEN_ENABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_SPLITEN_ENABLED_VALUE << SI32_USBEP_A_EPCONTROL_SPLITEN_SHIFT)

#define SI32_USBEP_A_EPCONTROL_FDTEN_MASK  0x00000800
#define SI32_USBEP_A_EPCONTROL_FDTEN_SHIFT  11
// The endpoint data toggle switches only when an ACK is received following a data
// packet transmission.
#define SI32_USBEP_A_EPCONTROL_FDTEN_DISABLED_VALUE  0
#define SI32_USBEP_A_EPCONTROL_FDTEN_DISABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_FDTEN_DISABLED_VALUE << SI32_USBEP_A_EPCONTROL_FDTEN_SHIFT)
// The endpoint data toggle is forced to switch after every data packet is
// transmitted, regardless of ACK reception.
#define SI32_USBEP_A_EPCONTROL_FDTEN_ENABLED_VALUE  1
#define SI32_USBEP_A_EPCONTROL_FDTEN_ENABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_FDTEN_ENABLED_VALUE << SI32_USBEP_A_EPCONTROL_FDTEN_SHIFT)

#define SI32_USBEP_A_EPCONTROL_IDMAEN_MASK  0x00001000
#define SI32_USBEP_A_EPCONTROL_IDMAEN_SHIFT  12
// Disable the DMA request for the IN endpoint.
#define SI32_USBEP_A_EPCONTROL_IDMAEN_DISABLED_VALUE  0
#define SI32_USBEP_A_EPCONTROL_IDMAEN_DISABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_IDMAEN_DISABLED_VALUE << SI32_USBEP_A_EPCONTROL_IDMAEN_SHIFT)
// Enable the DMA request for the IN endpoint.
#define SI32_USBEP_A_EPCONTROL_IDMAEN_ENABLED_VALUE  1
#define SI32_USBEP_A_EPCONTROL_IDMAEN_ENABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_IDMAEN_ENABLED_VALUE << SI32_USBEP_A_EPCONTROL_IDMAEN_SHIFT)

#define SI32_USBEP_A_EPCONTROL_DIRSEL_MASK  0x00002000
#define SI32_USBEP_A_EPCONTROL_DIRSEL_SHIFT  13
// Select the endpoint direction as OUT.
#define SI32_USBEP_A_EPCONTROL_DIRSEL_OUT_VALUE  0
#define SI32_USBEP_A_EPCONTROL_DIRSEL_OUT_U32 \
   (SI32_USBEP_A_EPCONTROL_DIRSEL_OUT_VALUE << SI32_USBEP_A_EPCONTROL_DIRSEL_SHIFT)
// Select the endpoint direction as IN.
#define SI32_USBEP_A_EPCONTROL_DIRSEL_IN_VALUE  1
#define SI32_USBEP_A_EPCONTROL_DIRSEL_IN_U32 \
   (SI32_USBEP_A_EPCONTROL_DIRSEL_IN_VALUE << SI32_USBEP_A_EPCONTROL_DIRSEL_SHIFT)

#define SI32_USBEP_A_EPCONTROL_IISOEN_MASK  0x00004000
#define SI32_USBEP_A_EPCONTROL_IISOEN_SHIFT  14
// Configure the endpoint for Bulk/Interrupt transfers.
#define SI32_USBEP_A_EPCONTROL_IISOEN_BULK_INT_VALUE  0
#define SI32_USBEP_A_EPCONTROL_IISOEN_BULK_INT_U32 \
   (SI32_USBEP_A_EPCONTROL_IISOEN_BULK_INT_VALUE << SI32_USBEP_A_EPCONTROL_IISOEN_SHIFT)
// Configure the endpoint for Isochronous transfers.
#define SI32_USBEP_A_EPCONTROL_IISOEN_ISO_VALUE  1
#define SI32_USBEP_A_EPCONTROL_IISOEN_ISO_U32 \
   (SI32_USBEP_A_EPCONTROL_IISOEN_ISO_VALUE << SI32_USBEP_A_EPCONTROL_IISOEN_SHIFT)

#define SI32_USBEP_A_EPCONTROL_AUTOSETEN_MASK  0x00008000
#define SI32_USBEP_A_EPCONTROL_AUTOSETEN_SHIFT  15
// The IPRDYI bit is not automatically set by hardware.
#define SI32_USBEP_A_EPCONTROL_AUTOSETEN_DISABLED_VALUE  0
#define SI32_USBEP_A_EPCONTROL_AUTOSETEN_DISABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_AUTOSETEN_DISABLED_VALUE << SI32_USBEP_A_EPCONTROL_AUTOSETEN_SHIFT)
// The IPRDYI bit is automatically set by hardware.
#define SI32_USBEP_A_EPCONTROL_AUTOSETEN_ENABLED_VALUE  1
#define SI32_USBEP_A_EPCONTROL_AUTOSETEN_ENABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_AUTOSETEN_ENABLED_VALUE << SI32_USBEP_A_EPCONTROL_AUTOSETEN_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OPRDYI_MASK  0x00010000
#define SI32_USBEP_A_EPCONTROL_OPRDYI_SHIFT  16
// A data packet is not available.
#define SI32_USBEP_A_EPCONTROL_OPRDYI_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_OPRDYI_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OPRDYI_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_OPRDYI_SHIFT)
// A data packet is available.
#define SI32_USBEP_A_EPCONTROL_OPRDYI_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OPRDYI_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OPRDYI_SET_VALUE << SI32_USBEP_A_EPCONTROL_OPRDYI_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OFIFOFF_MASK  0x00020000
#define SI32_USBEP_A_EPCONTROL_OFIFOFF_SHIFT  17
// The OUT endpoint FIFO is not full.
#define SI32_USBEP_A_EPCONTROL_OFIFOFF_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_OFIFOFF_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OFIFOFF_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_OFIFOFF_SHIFT)
// The OUT endpoint FIFO is full.
#define SI32_USBEP_A_EPCONTROL_OFIFOFF_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OFIFOFF_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OFIFOFF_SET_VALUE << SI32_USBEP_A_EPCONTROL_OFIFOFF_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OORF_MASK  0x00040000
#define SI32_USBEP_A_EPCONTROL_OORF_SHIFT  18
// No data overrun.
#define SI32_USBEP_A_EPCONTROL_OORF_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_OORF_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OORF_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_OORF_SHIFT)
// A data packet was lost because of a full FIFO since this flag was last cleared.
#define SI32_USBEP_A_EPCONTROL_OORF_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OORF_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OORF_SET_VALUE << SI32_USBEP_A_EPCONTROL_OORF_SHIFT)

#define SI32_USBEP_A_EPCONTROL_ODERRF_MASK  0x00080000
#define SI32_USBEP_A_EPCONTROL_ODERRF_SHIFT  19
// A CRC or bit-stuff error has not occurred.
#define SI32_USBEP_A_EPCONTROL_ODERRF_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_ODERRF_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_ODERRF_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_ODERRF_SHIFT)
// A CRC or bit-stuff error occurred.
#define SI32_USBEP_A_EPCONTROL_ODERRF_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_ODERRF_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_ODERRF_SET_VALUE << SI32_USBEP_A_EPCONTROL_ODERRF_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OFIFOFL_MASK  0x00100000
#define SI32_USBEP_A_EPCONTROL_OFIFOFL_SHIFT  20
// Flush the OUT FIFO.
#define SI32_USBEP_A_EPCONTROL_OFIFOFL_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OFIFOFL_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OFIFOFL_SET_VALUE << SI32_USBEP_A_EPCONTROL_OFIFOFL_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OSDSTL_MASK  0x00200000
#define SI32_USBEP_A_EPCONTROL_OSDSTL_SHIFT  21
// Stop sending a stall.
#define SI32_USBEP_A_EPCONTROL_OSDSTL_STOP_VALUE  0
#define SI32_USBEP_A_EPCONTROL_OSDSTL_STOP_U32 \
   (SI32_USBEP_A_EPCONTROL_OSDSTL_STOP_VALUE << SI32_USBEP_A_EPCONTROL_OSDSTL_SHIFT)
// Generate a stall.
#define SI32_USBEP_A_EPCONTROL_OSDSTL_SEND_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OSDSTL_SEND_U32 \
   (SI32_USBEP_A_EPCONTROL_OSDSTL_SEND_VALUE << SI32_USBEP_A_EPCONTROL_OSDSTL_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OSTSTLI_MASK  0x00400000
#define SI32_USBEP_A_EPCONTROL_OSTSTLI_SHIFT  22
// Read: A stall condition has not been sent since this bit was last cleared.
// Write: Clear the interrupt.
#define SI32_USBEP_A_EPCONTROL_OSTSTLI_NOT_SET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_OSTSTLI_NOT_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OSTSTLI_NOT_SET_VALUE << SI32_USBEP_A_EPCONTROL_OSTSTLI_SHIFT)
// Read: A stall condition has been sent since this bit was last cleared. Write: No
// effect.
#define SI32_USBEP_A_EPCONTROL_OSTSTLI_SET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OSTSTLI_SET_U32 \
   (SI32_USBEP_A_EPCONTROL_OSTSTLI_SET_VALUE << SI32_USBEP_A_EPCONTROL_OSTSTLI_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OCLRDT_MASK  0x00800000
#define SI32_USBEP_A_EPCONTROL_OCLRDT_SHIFT  23
// Do not reset the OUT data toggle.
#define SI32_USBEP_A_EPCONTROL_OCLRDT_NO_RESET_VALUE  0
#define SI32_USBEP_A_EPCONTROL_OCLRDT_NO_RESET_U32 \
   (SI32_USBEP_A_EPCONTROL_OCLRDT_NO_RESET_VALUE << SI32_USBEP_A_EPCONTROL_OCLRDT_SHIFT)
// Reset the OUT data toggle.
#define SI32_USBEP_A_EPCONTROL_OCLRDT_RESET_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OCLRDT_RESET_U32 \
   (SI32_USBEP_A_EPCONTROL_OCLRDT_RESET_VALUE << SI32_USBEP_A_EPCONTROL_OCLRDT_SHIFT)

#define SI32_USBEP_A_EPCONTROL_ODMAMD_MASK  0x10000000
#define SI32_USBEP_A_EPCONTROL_ODMAMD_SHIFT  28
// Automatic DMA service is requested on the last packet of the transfer until less
// than four bytes remain in the packet. At this time, an interrupt is generated.
// The firmware must read or write the last few bytes of the packet, if any remain.
#define SI32_USBEP_A_EPCONTROL_ODMAMD_AUTO_DMA_VALUE  0
#define SI32_USBEP_A_EPCONTROL_ODMAMD_AUTO_DMA_U32 \
   (SI32_USBEP_A_EPCONTROL_ODMAMD_AUTO_DMA_VALUE << SI32_USBEP_A_EPCONTROL_ODMAMD_SHIFT)
// No DMA service is requested on the last packet of the transfer. When the DMA
// recognizes the last packet, an interrupt is generated. The firmware must handle
// the entirety of the last packet.
#define SI32_USBEP_A_EPCONTROL_ODMAMD_NO_DMA_VALUE  1
#define SI32_USBEP_A_EPCONTROL_ODMAMD_NO_DMA_U32 \
   (SI32_USBEP_A_EPCONTROL_ODMAMD_NO_DMA_VALUE << SI32_USBEP_A_EPCONTROL_ODMAMD_SHIFT)

#define SI32_USBEP_A_EPCONTROL_ODMAEN_MASK  0x20000000
#define SI32_USBEP_A_EPCONTROL_ODMAEN_SHIFT  29
// Disable the DMA request for the OUT endpoint.
#define SI32_USBEP_A_EPCONTROL_ODMAEN_DISABLED_VALUE  0
#define SI32_USBEP_A_EPCONTROL_ODMAEN_DISABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_ODMAEN_DISABLED_VALUE << SI32_USBEP_A_EPCONTROL_ODMAEN_SHIFT)
// Enable the DMA request for the OUT endpoint.
#define SI32_USBEP_A_EPCONTROL_ODMAEN_ENABLED_VALUE  1
#define SI32_USBEP_A_EPCONTROL_ODMAEN_ENABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_ODMAEN_ENABLED_VALUE << SI32_USBEP_A_EPCONTROL_ODMAEN_SHIFT)

#define SI32_USBEP_A_EPCONTROL_OISOEN_MASK  0x40000000
#define SI32_USBEP_A_EPCONTROL_OISOEN_SHIFT  30
// Configure the endpoint for Bulk/Interrupt transfers.
#define SI32_USBEP_A_EPCONTROL_OISOEN_BULK_INT_VALUE  0
#define SI32_USBEP_A_EPCONTROL_OISOEN_BULK_INT_U32 \
   (SI32_USBEP_A_EPCONTROL_OISOEN_BULK_INT_VALUE << SI32_USBEP_A_EPCONTROL_OISOEN_SHIFT)
// Configure the endpoint for Isochronous transfers.
#define SI32_USBEP_A_EPCONTROL_OISOEN_ISO_VALUE  1
#define SI32_USBEP_A_EPCONTROL_OISOEN_ISO_U32 \
   (SI32_USBEP_A_EPCONTROL_OISOEN_ISO_VALUE << SI32_USBEP_A_EPCONTROL_OISOEN_SHIFT)

#define SI32_USBEP_A_EPCONTROL_AUTOCLREN_MASK  0x80000000
#define SI32_USBEP_A_EPCONTROL_AUTOCLREN_SHIFT  31
// The OPRDYI bit is not automatically cleared by hardware.
#define SI32_USBEP_A_EPCONTROL_AUTOCLREN_DISABLED_VALUE  0U
#define SI32_USBEP_A_EPCONTROL_AUTOCLREN_DISABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_AUTOCLREN_DISABLED_VALUE << SI32_USBEP_A_EPCONTROL_AUTOCLREN_SHIFT)
// The OPRDYI bit is automatically cleared by hardware.
#define SI32_USBEP_A_EPCONTROL_AUTOCLREN_ENABLED_VALUE  1U
#define SI32_USBEP_A_EPCONTROL_AUTOCLREN_ENABLED_U32 \
   (SI32_USBEP_A_EPCONTROL_AUTOCLREN_ENABLED_VALUE << SI32_USBEP_A_EPCONTROL_AUTOCLREN_SHIFT)



struct SI32_USBEP_A_EPCOUNT_Struct
{
   union
   {
      struct
      {
         // Endpoint OUT Data Count
         volatile uint32_t COUNT: 10;
                  uint32_t reserved0: 22;
      };
      volatile uint32_t U32;
   };
};

#define SI32_USBEP_A_EPCOUNT_COUNT_MASK  0x000003FF
#define SI32_USBEP_A_EPCOUNT_COUNT_SHIFT  0



struct SI32_USBEP_A_EPFIFO_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_USBEP_A_EPFIFO_FIFO_MASK  0xFFFFFFFF
#define SI32_USBEP_A_EPFIFO_FIFO_SHIFT  0



typedef struct SI32_USBEP_A_Struct
{
   struct SI32_USBEP_A_EPMPSIZE_Struct             EPMPSIZE       ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_USBEP_A_EPCONTROL_Struct            EPCONTROL      ; // Base Address + 0x10
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   struct SI32_USBEP_A_EPCOUNT_Struct              EPCOUNT        ; // Base Address + 0x20
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   struct SI32_USBEP_A_EPFIFO_Struct               EPFIFO         ; // Base Address + 0x30
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
} SI32_USBEP_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_USBEP_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

