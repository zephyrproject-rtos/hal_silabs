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
// This file applies to the SIM3C1XX_DMAXBAR_A module
//
// Version: 1

#ifndef __SI32_DMAXBAR_A_Support_Guard__
#define __SI32_DMAXBAR_A_Support_Guard__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the number of DMA channels.

#define SI32_DMACTRL_NUM_CHANNELS   16

//-----------------------------------------------------------------------------
// Define the DMA Crossbar Channel Select Enum Type

typedef enum SI32_DMAXBAR_CHNSEL_Enum
{
    SI32_DMAXBAR_CHAN0_SPI1_RX        = 0x01,
    SI32_DMAXBAR_CHAN0_USART0_RX      = 0x02,
    SI32_DMAXBAR_CHAN0_I2C0_TX        = 0x03,
    SI32_DMAXBAR_CHAN0_DMA0T0_RISE    = 0x04,
    SI32_DMAXBAR_CHAN0_DMA0T0_FALL    = 0x05,
    SI32_DMAXBAR_CHAN0_DMA0T1_RISE    = 0x06,
    SI32_DMAXBAR_CHAN0_DMA0T1_FALL    = 0x07,
    SI32_DMAXBAR_CHAN0_TIMER0L        = 0x08,
    SI32_DMAXBAR_CHAN0_TIMER0H        = 0x09,
    SI32_DMAXBAR_CHAN0_TIMER1L        = 0x0A,
    SI32_DMAXBAR_CHAN0_TIMER1H        = 0x0B,
    SI32_DMAXBAR_CHAN0_NONE           = 0x0F,

    SI32_DMAXBAR_CHAN1_SPI0_RX        = 0x11,
    SI32_DMAXBAR_CHAN1_USART1_RX      = 0x12,
    SI32_DMAXBAR_CHAN1_I2C0_RX        = 0x13,
    SI32_DMAXBAR_CHAN1_IDAC1          = 0x14,
    SI32_DMAXBAR_CHAN1_EPCA0_CONTROL  = 0x15,
    SI32_DMAXBAR_CHAN1_DMA0T0_RISE    = 0x16,
    SI32_DMAXBAR_CHAN1_DMA0T0_FALL    = 0x17,
    SI32_DMAXBAR_CHAN1_DMA0T1_RISE    = 0x18,
    SI32_DMAXBAR_CHAN1_DMA0T1_FALL    = 0x19,
    SI32_DMAXBAR_CHAN1_TIMER0L        = 0x1A,
    SI32_DMAXBAR_CHAN1_TIMER1L        = 0x1B,
    SI32_DMAXBAR_CHAN1_TIMER1H        = 0x1C,
    SI32_DMAXBAR_CHAN1_NONE           = 0x1F,

    SI32_DMAXBAR_CHAN2_SPI0_TX        = 0x21,
    SI32_DMAXBAR_CHAN2_USART0_TX      = 0x22,
    SI32_DMAXBAR_CHAN2_SARADC0        = 0x23,
    SI32_DMAXBAR_CHAN2_IDAC1          = 0x24,
    SI32_DMAXBAR_CHAN2_I2S0_TX        = 0x25,
    SI32_DMAXBAR_CHAN2_EPCA0_CONTROL  = 0x26,
    SI32_DMAXBAR_CHAN2_DMA0T0_RISE    = 0x27,
    SI32_DMAXBAR_CHAN2_DMA0T0_FALL    = 0x28,
    SI32_DMAXBAR_CHAN2_DMA0T1_RISE    = 0x29,
    SI32_DMAXBAR_CHAN2_DMA0T1_FALL    = 0x2A,
    SI32_DMAXBAR_CHAN2_NONE           = 0x2F,

    SI32_DMAXBAR_CHAN3_SARADC1        = 0x31,
    SI32_DMAXBAR_CHAN3_IDAC0          = 0x32,
    SI32_DMAXBAR_CHAN3_I2S0_TX        = 0x33,
    SI32_DMAXBAR_CHAN3_EPCA0_CAPTURE  = 0x34,
    SI32_DMAXBAR_CHAN3_DMA0T0_RISE    = 0x35,
    SI32_DMAXBAR_CHAN3_DMA0T0_FALL    = 0x36,
    SI32_DMAXBAR_CHAN3_DMA0T1_RISE    = 0x37,
    SI32_DMAXBAR_CHAN3_DMA0T1_FALL    = 0x38,
    SI32_DMAXBAR_CHAN3_TIMER1H        = 0x39,
    SI32_DMAXBAR_CHAN3_NONE           = 0x3F,

    SI32_DMAXBAR_CHAN4_SPI1_TX        = 0x41,
    SI32_DMAXBAR_CHAN4_USART0_TX      = 0x42,
    SI32_DMAXBAR_CHAN4_SARADC0        = 0x43,
    SI32_DMAXBAR_CHAN4_I2S0_RX        = 0x44,
    SI32_DMAXBAR_CHAN4_EPCA0_CAPTURE  = 0x45,
    SI32_DMAXBAR_CHAN4_DMA0T0_RISE    = 0x46,
    SI32_DMAXBAR_CHAN4_DMA0T0_FALL    = 0x47,
    SI32_DMAXBAR_CHAN4_DMA0T1_RISE    = 0x48,
    SI32_DMAXBAR_CHAN4_DMA0T1_FALL    = 0x49,
    SI32_DMAXBAR_CHAN4_TIMER0H        = 0x4A,
    SI32_DMAXBAR_CHAN4_NONE           = 0x4F,

    SI32_DMAXBAR_CHAN5_AES0_TX        = 0x51,
    SI32_DMAXBAR_CHAN5_USART1_TX      = 0x52,
    SI32_DMAXBAR_CHAN5_SARADC0        = 0x53,
    SI32_DMAXBAR_CHAN5_I2S0_RX        = 0x54,
    SI32_DMAXBAR_CHAN5_DMA0T0_RISE    = 0x55,
    SI32_DMAXBAR_CHAN5_DMA0T0_FALL    = 0x56,
    SI32_DMAXBAR_CHAN5_DMA0T1_RISE    = 0x57,
    SI32_DMAXBAR_CHAN5_DMA0T1_FALL    = 0x58,
    SI32_DMAXBAR_CHAN5_NONE           = 0x5F,

    SI32_DMAXBAR_CHAN6_AES0_RX        = 0x61,
    SI32_DMAXBAR_CHAN6_USART0_RX      = 0x62,
    SI32_DMAXBAR_CHAN6_I2C0_RX        = 0x63,
    SI32_DMAXBAR_CHAN6_IDAC0          = 0x64,
    SI32_DMAXBAR_CHAN6_DMA0T0_RISE    = 0x65,
    SI32_DMAXBAR_CHAN6_DMA0T0_FALL    = 0x66,
    SI32_DMAXBAR_CHAN6_DMA0T1_RISE    = 0x67,
    SI32_DMAXBAR_CHAN6_DMA0T1_FALL    = 0x68,
    SI32_DMAXBAR_CHAN6_TIMER0H        = 0x69,
    SI32_DMAXBAR_CHAN6_NONE           = 0x6F,

    SI32_DMAXBAR_CHAN7_AES0_XOR       = 0x71,
    SI32_DMAXBAR_CHAN7_SPI1_TX        = 0x72,
    SI32_DMAXBAR_CHAN7_USART0_TX      = 0x73,
    SI32_DMAXBAR_CHAN7_DMA0T0_RISE    = 0x74,
    SI32_DMAXBAR_CHAN7_DMA0T0_FALL    = 0x75,
    SI32_DMAXBAR_CHAN7_DMA0T1_RISE    = 0x76,
    SI32_DMAXBAR_CHAN7_DMA0T1_FALL    = 0x77,
    SI32_DMAXBAR_CHAN7_TIMER0L        = 0x78,
    SI32_DMAXBAR_CHAN7_TIMER1L        = 0x79,
    SI32_DMAXBAR_CHAN7_TIMER1H        = 0x7A,
    SI32_DMAXBAR_CHAN7_NONE           = 0x7F,

    SI32_DMAXBAR_CHAN8_USART1_RX      = 0x81,
    SI32_DMAXBAR_CHAN8_SPI1_RX        = 0x82,
    SI32_DMAXBAR_CHAN8_USART0_RX      = 0x83,
    SI32_DMAXBAR_CHAN8_EPCA0_CAPTURE  = 0x84,
    SI32_DMAXBAR_CHAN8_DMA0T0_RISE    = 0x85,
    SI32_DMAXBAR_CHAN8_DMA0T0_FALL    = 0x86,
    SI32_DMAXBAR_CHAN8_DMA0T1_RISE    = 0x87,
    SI32_DMAXBAR_CHAN8_DMA0T1_FALL    = 0x88,
    SI32_DMAXBAR_CHAN8_NONE           = 0x8F,

    SI32_DMAXBAR_CHAN9_USART1_TX      = 0x91,
    SI32_DMAXBAR_CHAN9_I2C0_TX        = 0x92,
    SI32_DMAXBAR_CHAN9_EPCA0_CAPTURE  = 0x93,
    SI32_DMAXBAR_CHAN9_DMA0T0_RISE    = 0x94,
    SI32_DMAXBAR_CHAN9_DMA0T0_FALL    = 0x95,
    SI32_DMAXBAR_CHAN9_DMA0T1_RISE    = 0x96,
    SI32_DMAXBAR_CHAN9_DMA0T1_FALL    = 0x97,
    SI32_DMAXBAR_CHAN9_TIMER0H        = 0x98,
    SI32_DMAXBAR_CHAN9_NONE           = 0x9F,

    SI32_DMAXBAR_CHAN10_AES0_TX       = 0xA1,
    SI32_DMAXBAR_CHAN10_SARADC1       = 0xA2,
    SI32_DMAXBAR_CHAN10_I2S0_RX       = 0xA3,
    SI32_DMAXBAR_CHAN10_DMA0T0_RISE   = 0xA4,
    SI32_DMAXBAR_CHAN10_DMA0T0_FALL   = 0xA5,
    SI32_DMAXBAR_CHAN10_DMA0T1_RISE   = 0xA6,
    SI32_DMAXBAR_CHAN10_DMA0T1_FALL   = 0xA7,
    SI32_DMAXBAR_CHAN10_TIMER1H       = 0xA8,
    SI32_DMAXBAR_CHAN10_NONE          = 0xAF,

    SI32_DMAXBAR_CHAN11_AES0_RX       = 0xB1,
    SI32_DMAXBAR_CHAN11_USART1_RX     = 0xB2,
    SI32_DMAXBAR_CHAN11_USART0_RX     = 0xB3,
    SI32_DMAXBAR_CHAN11_I2C0_RX       = 0xB4,
    SI32_DMAXBAR_CHAN11_I2S0_RX       = 0xB5,
    SI32_DMAXBAR_CHAN11_DMA0T0_RISE   = 0xB6,
    SI32_DMAXBAR_CHAN11_DMA0T0_FALL   = 0xB7,
    SI32_DMAXBAR_CHAN11_DMA0T1_RISE   = 0xB8,
    SI32_DMAXBAR_CHAN11_DMA0T1_FALL   = 0xB9,
    SI32_DMAXBAR_CHAN11_TIMER0H       = 0xBA,
    SI32_DMAXBAR_CHAN11_NONE          = 0xBF,

    SI32_DMAXBAR_CHAN12_AES0_XOR      = 0xC1,
    SI32_DMAXBAR_CHAN12_USART1_TX     = 0xC2,
    SI32_DMAXBAR_CHAN12_SPI1_TX       = 0xC3,
    SI32_DMAXBAR_CHAN12_IDAC1         = 0xC4,
    SI32_DMAXBAR_CHAN12_I2S0_TX       = 0xC5,
    SI32_DMAXBAR_CHAN12_DMA0T0_RISE   = 0xC6,
    SI32_DMAXBAR_CHAN12_DMA0T0_FALL   = 0xC7,
    SI32_DMAXBAR_CHAN12_DMA0T1_RISE   = 0xC8,
    SI32_DMAXBAR_CHAN12_DMA0T1_FALL   = 0xC9,
    SI32_DMAXBAR_CHAN12_TIMER0L       = 0xCA,
    SI32_DMAXBAR_CHAN12_TIMER1L       = 0xCB,
    SI32_DMAXBAR_CHAN12_TIMER1H       = 0xCC,
    SI32_DMAXBAR_CHAN12_NONE          = 0xCF,

    SI32_DMAXBAR_CHAN13_SPI0_RX       = 0xD1,
    SI32_DMAXBAR_CHAN13_USART0_RX     = 0xD2,
    SI32_DMAXBAR_CHAN13_IDAC1         = 0xD3,
    SI32_DMAXBAR_CHAN13_I2S0_TX       = 0xD4,
    SI32_DMAXBAR_CHAN13_DMA0T0_RISE   = 0xD5,
    SI32_DMAXBAR_CHAN13_DMA0T0_FALL   = 0xD6,
    SI32_DMAXBAR_CHAN13_DMA0T1_RISE   = 0xD7,
    SI32_DMAXBAR_CHAN13_DMA0T1_FALL   = 0xD8,
    SI32_DMAXBAR_CHAN13_TIMER0H       = 0xD9,
    SI32_DMAXBAR_CHAN13_NONE          = 0xDF,

    SI32_DMAXBAR_CHAN14_SPI0_TX       = 0xE1,
    SI32_DMAXBAR_CHAN14_USART0_TX     = 0xE2,
    SI32_DMAXBAR_CHAN14_IDAC0         = 0xE3,
    SI32_DMAXBAR_CHAN14_EPCA0_CONTROL = 0xE4,
    SI32_DMAXBAR_CHAN14_DMA0T0_RISE   = 0xE5,
    SI32_DMAXBAR_CHAN14_DMA0T0_FALL   = 0xE6,
    SI32_DMAXBAR_CHAN14_DMA0T1_RISE   = 0xE7,
    SI32_DMAXBAR_CHAN14_DMA0T1_FALL   = 0xE8,
    SI32_DMAXBAR_CHAN14_TIMER0L       = 0xE9,
    SI32_DMAXBAR_CHAN14_TIMER1L       = 0xEA,
    SI32_DMAXBAR_CHAN14_NONE          = 0xEF,

    SI32_DMAXBAR_CHAN15_SARADC1       = 0xF1,
    SI32_DMAXBAR_CHAN15_IDAC0         = 0xF2,
    SI32_DMAXBAR_CHAN15_EPCA0_CONTROL = 0xF3,
    SI32_DMAXBAR_CHAN15_DMA0T0_RISE   = 0xF4,
    SI32_DMAXBAR_CHAN15_DMA0T0_FALL   = 0xF5,
    SI32_DMAXBAR_CHAN15_DMA0T1_RISE   = 0xF6,
    SI32_DMAXBAR_CHAN15_DMA0T1_FALL   = 0xF7,
    SI32_DMAXBAR_CHAN15_TIMER0H       = 0xF8,
    SI32_DMAXBAR_CHAN15_TIMER1H       = 0xF9,
    SI32_DMAXBAR_CHAN15_NONE          = 0xFF
}
SI32_DMAXBAR_CHNSEL_Enum_Type;

// Extracts DMA channel number from SI32_DMAXBAR_CHNSEL_Enum_Type
#define SI32_DMAXBAR_CHANNEL_OF(chsel)  (((chsel) & 0xF0) >> 4)

//-----------------------------------------------------------------------------
// Define the DMA Endpoints

#define  SI32_ADC_0_RX_ENDPOINT         &SI32_ADC_0->DATA.U32
#define  SI32_ADC_1_RX_ENDPOINT         &SI32_ADC_1->DATA.U32
#define  SI32_AES_0_TX_ENDPOINT         &SI32_AES_0->DATAFIFO.U32
#define  SI32_AES_0_RX_ENDPOINT         &SI32_AES_0->DATAFIFO.U32
#define  SI32_AES_0_XOR_ENDPOINT        &SI32_AES_0->XORFIFO.U32
#define  SI32_EPCA_0_CH0_RX_ENDPOINT    &SI32_EPCA_0_CH0->CCAPV.U32
#define  SI32_EPCA_0_CH1_RX_ENDPOINT    &SI32_EPCA_0_CH1->CCAPV.U32
#define  SI32_EPCA_0_CH2_RX_ENDPOINT    &SI32_EPCA_0_CH2->CCAPV.U32
#define  SI32_EPCA_0_CH3_RX_ENDPOINT    &SI32_EPCA_0_CH3->CCAPV.U32
#define  SI32_EPCA_0_CH4_RX_ENDPOINT    &SI32_EPCA_0_CH4->CCAPV.U32
#define  SI32_EPCA_0_CH5_RX_ENDPOINT    &SI32_EPCA_0_CH5->CCAPV.U32
#define  SI32_EPCA_0_TX_ENDPOINT        &SI32_EPCA_0->DTARGET.U32
#define  SI32_EPCA_0_CH0_TX_ENDPOINT    &SI32_EPCA_0_CH0->CCAPVUPD.U32
#define  SI32_EPCA_0_CH1_TX_ENDPOINT    &SI32_EPCA_0_CH1->CCAPVUPD.U32
#define  SI32_EPCA_0_CH2_TX_ENDPOINT    &SI32_EPCA_0_CH2->CCAPVUPD.U32
#define  SI32_EPCA_0_CH3_TX_ENDPOINT    &SI32_EPCA_0_CH3->CCAPVUPD.U32
#define  SI32_EPCA_0_CH4_TX_ENDPOINT    &SI32_EPCA_0_CH4->CCAPVUPD.U32
#define  SI32_EPCA_0_CH5_TX_ENDPOINT    &SI32_EPCA_0_CH5->CCAPVUPD.U32
#define  SI32_I2C_0_RX_ENDPOINT         &SI32_I2C_0->DATA.U32
#define  SI32_I2C_0_TX_ENDPOINT         &SI32_I2C_0->DATA.U32
#define  SI32_I2S_0_RX_ENDPOINT         &SI32_I2S_0->RXFIFO.U32
#define  SI32_I2S_0_TX_ENDPOINT         &SI32_I2S_0->TXFIFO.U32
#define  SI32_IDAC_0_TX_ENDPOINT        &SI32_IDAC_0->DATA.U32
#define  SI32_IDAC_1_TX_ENDPOINT        &SI32_IDAC_1->DATA.U32
#define  SI32_SPI_0_RX_ENDPOINT         &SI32_SPI_0->DATA.U32
#define  SI32_SPI_0_TX_ENDPOINT         &SI32_SPI_0->DATA.U32
#define  SI32_SPI_1_RX_ENDPOINT         &SI32_SPI_1->DATA.U32
#define  SI32_SPI_1_TX_ENDPOINT         &SI32_SPI_1->DATA.U32
#define  SI32_USART_0_RX_ENDPOINT       &SI32_USART_0->DATA.U32
#define  SI32_USART_0_TX_ENDPOINT       &SI32_USART_0->DATA.U32
#define  SI32_USART_1_RX_ENDPOINT       &SI32_USART_1->DATA.U32
#define  SI32_USART_1_TX_ENDPOINT       &SI32_USART_1->DATA.U32

#ifdef __cplusplus
}
#endif

#endif // __SI32_DMAXBAR_A_Support_Guard__

//-eof--------------------------------------------------------------------------
