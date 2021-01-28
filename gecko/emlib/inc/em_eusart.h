/***************************************************************************//**
 * @file
 * @brief Universal asynchronous receiver/transmitter (EUSART) peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef EM_EUSART_H
#define EM_EUSART_H
#include "em_device.h"
#if defined(EUART_PRESENT) || defined(EUSART_PRESENT)
#include "em_eusart_compat.h"
#include <stdbool.h>

/***************************************************************************//**
 * @addtogroup eusart EUSART - Extended USART
 * @brief Extended Universal Synchronous/Asynchronous Receiver/Transmitter
 * @{
 ******************************************************************************/

/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/// Enable selection.
typedef enum {
  /// Disable the peripheral.
  eusartDisable = 0x0,

  /// Enable receiver only, transmitter disabled.
  eusartEnableRx = (EUSART_CMD_RXEN | EUSART_CMD_TXDIS),

  /// Enable transmitter only, receiver disabled.
  eusartEnableTx = (EUSART_CMD_TXEN | EUSART_CMD_RXDIS),

  /// Enable both receiver and transmitter.
  eusartEnable = (EUSART_CMD_RXEN | EUSART_CMD_TXEN)
} EUSART_Enable_TypeDef;

/// Data bit selection.
typedef enum {
  eusartDataBits7 = EUSART_FRAMECFG_DATABITS_SEVEN,     ///< 7 data bits.
  eusartDataBits8 = EUSART_FRAMECFG_DATABITS_EIGHT,     ///< 8 data bits.
  eusartDataBits9 = EUSART_FRAMECFG_DATABITS_NINE,       ///< 9 data bits.
#if defined(EUSART_PRESENT)
  eusartDataBits10 = EUSART_FRAMECFG_DATABITS_TEN,      ///< 10 data bits, SPI mode only.
  eusartDataBits11 = EUSART_FRAMECFG_DATABITS_ELEVEN,   ///< 11 data bits, SPI mode only.
  eusartDataBits12 = EUSART_FRAMECFG_DATABITS_TWELVE,   ///< 12 data bits, SPI mode only.
  eusartDataBits13 = EUSART_FRAMECFG_DATABITS_THIRTEEN, ///< 13 data bits, SPI mode only.
  eusartDataBits14 = EUSART_FRAMECFG_DATABITS_FOURTEEN, ///< 14 data bits, SPI mode only.
  eusartDataBits15 = EUSART_FRAMECFG_DATABITS_FIFTEEN,  ///< 15 data bits, SPI mode only.
  eusartDataBits16 = EUSART_FRAMECFG_DATABITS_SIXTEEN,  ///< 16 data bits, SPI mode only.
#endif
} EUSART_Databits_TypeDef;

/// Parity selection.
typedef enum {
  eusartNoParity   = EUSART_FRAMECFG_PARITY_NONE,    ///< No parity.
  eusartEvenParity = EUSART_FRAMECFG_PARITY_EVEN,    ///< Even parity.
  eusartOddParity  = EUSART_FRAMECFG_PARITY_ODD      ///< Odd parity.
} EUSART_Parity_TypeDef;

/// Stop bits selection.
typedef enum {
  eusartStopbits0p5 = EUSART_FRAMECFG_STOPBITS_HALF,        ///< 0.5 stop bits.
  eusartStopbits1p5 = EUSART_FRAMECFG_STOPBITS_ONEANDAHALF, ///< 1.5 stop bits.
  eusartStopbits1 = EUSART_FRAMECFG_STOPBITS_ONE,           ///< 1 stop bits.
  eusartStopbits2 = EUSART_FRAMECFG_STOPBITS_TWO            ///< 2 stop bits.
} EUSART_Stopbits_TypeDef;

/// Oversampling selection, used for asynchronous operation.
typedef enum {
  eusartOVS16 = EUSART_CFG0_OVS_X16,     ///< 16x oversampling (normal).
  eusartOVS8  = EUSART_CFG0_OVS_X8,      ///< 8x oversampling.
  eusartOVS6  = EUSART_CFG0_OVS_X6,      ///< 6x oversampling.
  eusartOVS4  = EUSART_CFG0_OVS_X4,      ///< 4x oversampling.
  eusartOVS0  = EUSART_CFG0_OVS_DISABLE  ///< Oversampling disabled.
} EUSART_OVS_TypeDef;

/// HW flow control config.
typedef enum {
  eusartHwFlowControlNone = 0, ///< No HW Flow Control.
  eusartHwFlowControlCts,      ///< CTS HW Flow Control.
  eusartHwFlowControlRts,      ///< RTS HW Flow Control.
  eusartHwFlowControlCtsAndRts ///< CTS and RTS HW Flow Control.
} EUSART_HwFlowControl_TypeDef;

/// Loopback enable.
typedef enum {
  eusartLoopbackEnable  = EUSART_CFG0_LOOPBK,
  eusartLoopbackDisable = _EUSART_CFG0_RESETVALUE
} EUSART_LoopbackEnable_TypeDef;

/// Majority vote enable.
typedef enum {
  eusartMajorityVoteEnable  = EUSART_CFG0_MVDIS_DEFAULT,
  eusartMajorityVoteDisable = EUSART_CFG0_MVDIS
} EUSART_MajorityVote_TypeDef;

/// Block reception enable.
typedef enum {
  eusartBlockRxEnable  = EUSART_CMD_RXBLOCKEN,
  eusartBlockRxDisable = EUSART_CMD_RXBLOCKDIS
} EUSART_BlockRx_TypeDef;

/// Tx output tristate enable.
typedef enum {
  eusartTristateTxEnable  = EUSART_CMD_TXTRIEN,
  eusartTristateTxDisable = EUSART_CMD_TXTRIDIS
} EUSART_TristateTx_TypeDef;

/// IrDA filter enable.
typedef enum {
  eusartIrDARxFilterEnable  = EUSART_IRHFCFG_IRHFFILT_ENABLE,
  eusartIrDARxFilterDisable = EUSART_IRHFCFG_IRHFFILT_DISABLE
} EUSART_IrDARxFilterEnable_TypeDef;

/// Pulse width selection for IrDA mode.
typedef enum {
  /// IrDA pulse width is 1/16 for OVS=X16 and 1/8 for OVS=X8
  eusartIrDAPulseWidthOne   = EUSART_IRHFCFG_IRHFPW_ONE,

  /// IrDA pulse width is 2/16 for OVS=X16 and 2/8 for OVS=X8
  eusartIrDAPulseWidthTwo   = EUSART_IRHFCFG_IRHFPW_TWO,

  /// IrDA pulse width is 3/16 for OVS=X16 and 3/8 for OVS=X8
  eusartIrDAPulseWidthThree = EUSART_IRHFCFG_IRHFPW_THREE,

  /// IrDA pulse width is 4/16 for OVS=X16 and 4/8 for OVS=X8
  eusartIrDAPulseWidthFour  = EUSART_IRHFCFG_IRHFPW_FOUR
} EUSART_IrDAPulseWidth_Typedef;

/// PRS trigger enable.
typedef enum {
  /// Disable trigger on both receiver and transmitter.
  eusartPrsTriggerDisable = 0x0,

  /// Enable receive trigger only, transmit disabled.
  eusartPrsTriggerEnableRx = EUSART_TRIGCTRL_RXTEN,

  /// Enable transmit trigger only, receive disabled.
  eusartPrsTriggerEnableTx = EUSART_TRIGCTRL_TXTEN,

  /// Enable trigger on both receive and transmit.
  eusartPrsTriggerEnableRxTx = (EUSART_TRIGCTRL_RXTEN | EUSART_TRIGCTRL_TXTEN)
} EUSART_PrsTriggerEnable_TypeDef;

/// PRS Channel type.
typedef uint8_t EUSART_PrsChannel_TypeDef;

/// IO polarity selection.
typedef enum {
  /// Disable inversion on both Rx and Tx signals.
  eusartInvertIODisable = (EUSART_CFG0_RXINV_DISABLE | EUSART_CFG0_TXINV_DISABLE),

  /// Invert Rx signal, before receiver.
  eusartInvertRxEnable = EUSART_CFG0_RXINV_ENABLE,

  /// Invert Tx signal, after transmitter.
  eusartInvertTxEnable = EUSART_CFG0_TXINV_ENABLE,

  /// Enable trigger on both receive and transmit.
  eusartInvertIOEnable = (EUSART_CFG0_RXINV_ENABLE | EUSART_CFG0_TXINV_ENABLE)
} EUSART_InvertIO_TypeDef;

#if defined(EUSART_PRESENT)
/// Clock polarity/phase mode.
typedef enum {
  /// Clock idle low, sample on rising edge.
  eusartClockMode0 = EUSART_CFG2_CLKPOL_IDLELOW | EUSART_CFG2_CLKPHA_SAMPLELEADING,

  /// Clock idle low, sample on falling edge.
  eusartClockMode1 = EUSART_CFG2_CLKPOL_IDLELOW | EUSART_CFG2_CLKPHA_SAMPLETRAILING,

  /// Clock idle high, sample on falling edge.
  eusartClockMode2 = EUSART_CFG2_CLKPOL_IDLEHIGH | EUSART_CFG2_CLKPHA_SAMPLELEADING,

  /// Clock idle high, sample on rising edge.
  eusartClockMode3 = EUSART_CFG2_CLKPOL_IDLEHIGH | EUSART_CFG2_CLKPHA_SAMPLETRAILING
} EUSART_ClockMode_TypeDef;

/// Chip select polarity.
typedef enum {
  /// Chip select active low.
  eusartCsActiveLow = EUSART_CFG2_CSINV_AL,

  /// Chip select active high.
  eusartCsActiveHigh = EUSART_CFG2_CSINV_AH,
}EUSART_CsPolarity_TypeDef;
#endif

/*******************************************************************************
 *******************************   STRUCTS   ***********************************
 ******************************************************************************/
/// Advanced initialization structure.
typedef struct {
  /// Hardware flow control mode.
  EUSART_HwFlowControl_TypeDef hwFlowControl;

  /// Enable the collision Detection feature.
  /// Internal (setting loopbackEnable) or external loopback must be done to use this feature.
  bool collisionDetectEnable;

  /// If true, data will be send with most significant bit first.
  bool msbFirst;

  /// Enable inversion of Rx and/or Tx signals.
  EUSART_InvertIO_TypeDef invertIO;

  /// Enable the automatic wake up from EM2 to EM1 for DMA Rx operation.
  bool dmaWakeUpOnRx;

  /// Enable the automatic wake up from EM2 to EM1 for DMA Tx operation.
  bool dmaWakeUpOnTx;

  /// Enable DMA requests blocking while framing or parity errors.
  bool dmaHaltOnError;

  /// Start frame that will enable Rx operation. 0x00 Disable this feature.
  uint8_t startFrame;

  /// Enable automatic tristating of transmistter output when there is nothing to transmit.
  bool txAutoTristate;

  /// Enable EUSART capability to use a PRS channel as an input data line for the receiver.
  /// The configured Rx GPIO signal won't be routed to the EUSART receiver.
  bool prsRxEnable;

  /// PRS Channel used to transmit data from PRS to the EUSART.
  EUSART_PrsChannel_TypeDef prsRxChannel;

  /// Enable Multiprocessor mode. Address and data filtering using the 9th bit.
  bool multiProcessorEnable;

  /// Multiprocessor address bit value. If true, 9th bit of address frame must bit 1, 0 otherwise.
  bool multiProcessorAddressBitHigh;
} EUSART_AdvancedInit_TypeDef;

/// Initialization structure.
typedef struct {
  /// Specifies whether TX and/or RX will be enabled when initialization completes.
  EUSART_Enable_TypeDef enable;

  /// EUSART reference clock assumed when configuring baud rate setup. Set
  /// to 0 if using currently configured reference clock.
  uint32_t refFreq;

  /// Desired baud rate. If set to 0, Auto Baud feature is enabled and
  /// the EUSART will wait for (0x55) frame to detect the Baudrate.
  uint32_t baudrate;

  /// Oversampling used.
  EUSART_OVS_TypeDef oversampling;

  /// Number of data bits in frame.
  EUSART_Databits_TypeDef databits;

  /// Parity mode to use.
  EUSART_Parity_TypeDef   parity;

  /// Number of stop bits to use.
  EUSART_Stopbits_TypeDef stopbits;

  /// Majority Vote can be disabled for 16x, 8x and 6x oversampling modes.
  EUSART_MajorityVote_TypeDef majorityVote;

  /// Enable Loop Back configuration.
  EUSART_LoopbackEnable_TypeDef loopbackEnable;

  /// Advanced initialization structure pointer. It can be NULL.
  EUSART_AdvancedInit_TypeDef *advancedSettings;
} EUSART_UartInit_TypeDef;

/// IrDA Initialization structure.
typedef struct {
  /// General EUSART initialization structure.
  EUSART_UartInit_TypeDef init;

  /// Enable the IrDA low frequency mode. Only Rx operation are enabled.
  bool irDALowFrequencyEnable;

  /// Set to enable filter on IrDA demodulator.
  EUSART_IrDARxFilterEnable_TypeDef irDARxFilterEnable;

  /// Configure the pulse width generated by the IrDA modulator as a fraction
  /// of the configured EUSART bit period.
  EUSART_IrDAPulseWidth_Typedef irDAPulseWidth;
} EUSART_IrDAInit_TypeDef;

/// PRS Trigger initialization structure.
typedef struct {
  /// PRS to EUSART trigger mode.
  EUSART_PrsTriggerEnable_TypeDef prs_trigger_enable;

  /// PRS channel to be used to trigger auto transmission.
  EUSART_PrsChannel_TypeDef prs_trigger_channel;
} EUSART_PrsTriggerInit_TypeDef;

#if defined(EUSART_PRESENT)
/// SPI Advanced initialization structure.
typedef struct {
  /// Chip select polarity
  EUSART_CsPolarity_TypeDef csPolarity;

  /// Enable inversion of Rx and/or Tx signals.
  EUSART_InvertIO_TypeDef invertIO;

  /// Enable automatic chip select. CS is managed by the peripheral.
  bool autoCsEnable;

  /// If true, data will be send with most significant bit first.
  bool msbFirst;

  /// Auto CS setup time (before transmission) in baud cycles. Acceptable value ( 0 to 7 baud cycle).
  uint8_t autoCsSetupTime;

  /// Auto CS hold time (after transmission) in baud cycles. Acceptable value ( 0 to 7 baud cycle).
  uint8_t autoCsHoldTime;

  /// Inter-frame time in baud cycles. Acceptable value ( 0 to 7 baud cycle).
  uint8_t autoInterFrameTime;

  /// Enable AUTOTX mode. Transmits as long as the RX FIFO is not full.
  ///  Generates underflow interrupt if the TX FIFO is empty.
  bool autoTxEnable;

  /// Default transmitted data when the TXFIFO is empty.
  uint16_t defaultTxData;

  /// Enable the automatic wake up from EM2 to EM1 for DMA Rx operation.
  /// Only applicable to EM2 (low frequency) capable EUSART instances.
  bool dmaWakeUpOnRx;

  /// Enable EUSART capability to use a PRS channel as an input data line for the receiver.
  /// The configured Rx GPIO signal won't be routed to the EUSART receiver.
  bool prsRxEnable;

  /// PRS Channel used to transmit data from PRS to the EUSART.
  EUSART_PrsChannel_TypeDef prsRxChannel;

  /// Enable EUSART capability to use a PRS channel as an input SPI Clock.
  /// Slave mode only.
  bool prsClockEnable;

  /// PRS Channel used to transmit SCLK from PRS to the EUSART.
  EUSART_PrsChannel_TypeDef prsClockChannel;
} EUSART_SpiAdvancedInit_TypeDef;

/// SPI Initialization structure.
typedef struct {
  /// Specifies whether TX and/or RX will be enabled when initialization completes.
  EUSART_Enable_TypeDef enable;

  /// EUSART reference clock assumed when configuring baud rate setup. Set
  /// to 0 if using currently configured reference clock.
  uint32_t refFreq;

  /// Desired bit rate in Hz.
  uint32_t bitRate;

  /// Number of data bits in frame.
  EUSART_Databits_TypeDef databits;

  /// Select to operate in master or slave mode.
  bool master;

  /// Clock polarity/phase mode.
  EUSART_ClockMode_TypeDef clockMode;

  /// Enable Loop Back configuration.
  EUSART_LoopbackEnable_TypeDef loopbackEnable;

  /// Advanced initialization structure pointer. It can be NULL.
  EUSART_SpiAdvancedInit_TypeDef *advancedSettings;
} EUSART_SpiInit_TypeDef;
#endif

/// Default configuration for EUSART initialization structure in UART mode with high-frequency clock.
#define EUSART_UART_INIT_DEFAULT_HF                                                                   \
  {                                                                                                   \
    eusartEnable,              /* Enable RX/TX when initialization completed. */                      \
    0,                         /* Use current configured reference clock for configuring baud rate.*/ \
    115200,                    /* 115200 bits/s. */                                                   \
    eusartOVS16,               /* Oversampling x16. */                                                \
    eusartDataBits8,           /* 8 data bits. */                                                     \
    eusartNoParity,            /* No parity. */                                                       \
    eusartStopbits1,           /* 1 stop bit. */                                                      \
    eusartMajorityVoteEnable,  /* Majority vote enabled. */                                           \
    eusartLoopbackDisable,     /* Loop back disabled. */                                              \
    NULL,                      /* Default advanced settings. */                                       \
  }

/// Default start frame configuration, i.e. feature disabled.
#define EUSART_DEFAULT_START_FRAME 0x00u

/// Default configuration for EUSART advanced initialization structure.
#define EUSART_ADVANCED_INIT_DEFAULT                                                         \
  {                                                                                          \
    eusartHwFlowControlNone,        /* Flow control disabled. */                             \
    false,                          /* Collision dectection disabled. */                     \
    false,                          /* Data is sent with the least significant bit first. */ \
    eusartInvertIODisable,          /* Rx and Tx signal active high. */                      \
    false,                          /* No DMA wake up on reception. */                       \
    false,                          /* No DMA wake up on transmission. */                    \
    false,                          /* Halt DMA on error disabled. */                        \
    EUSART_DEFAULT_START_FRAME,     /* No start frame.  */                                   \
    false,                          /* Tx auto tristate disabled. */                         \
    false,                          /* Do not use PRS signal as Rx signal.*/                 \
    (EUSART_PrsChannel_TypeDef) 0u, /* EUSART Rx connected to prs channel 0. */              \
    false,                          /* Multiprocessor mode disabled. */                      \
    false,                          /* Multiprocessor address bit : 0.*/                     \
  }

/// Default configuration for EUSART initialization structure in UART mode with low-frequency clock.
#define EUSART_UART_INIT_DEFAULT_LF                                                                    \
  {                                                                                                    \
    eusartEnable,               /* Enable RX/TX when initialization completed. */                      \
    0,                          /* Use current configured reference clock for configuring baud rate.*/ \
    9600,                       /* 9600 bits/s. */                                                     \
    eusartOVS0,                 /* Oversampling disabled. */                                           \
    eusartDataBits8,            /* 8 data bits. */                                                     \
    eusartNoParity,             /* No parity. */                                                       \
    eusartStopbits1,            /* 1 stop bit. */                                                      \
    eusartMajorityVoteDisable,  /* Majority vote enabled. */                                           \
    eusartLoopbackDisable,      /* Loop back disabled. */                                              \
    NULL,                       /* Default advanced settings. */                                       \
  }

/// Default configuration for EUSART initialization structure in IrDA mode with high-frequency clock.
#define EUSART_IRDA_INIT_DEFAULT_HF                                          \
  {                                                                          \
    EUSART_UART_INIT_DEFAULT_HF, /* Default high frequency configuration. */ \
    false,                       /* Disable IrDA low frequency mode. */      \
    eusartIrDARxFilterDisable,   /* Rx Filter disabled. */                   \
    eusartIrDAPulseWidthOne,     /* Pulse width is set to 1/16. */           \
  }

/// Default configuration for EUSART initialization structure in IrDA mode with low-frequency clock.
#define EUSART_IRDA_INIT_DEFAULT_LF                                                                      \
  {                                                                                                      \
    {                                                                                                    \
      eusartEnableRx,             /* Enable RX when initialization completed (Tx not allowed). */        \
      0,                          /* Use current configured reference clock for configuring baud rate.*/ \
      9600,                       /* 9600 bits/s. */                                                     \
      eusartOVS0,                 /* Oversampling disabled. */                                           \
      eusartDataBits8,            /* 8 data bits. */                                                     \
      eusartNoParity,             /* No parity. */                                                       \
      eusartStopbits1,            /* 1 stop bit. */                                                      \
      eusartMajorityVoteDisable,  /* Majority vote enabled. */                                           \
      eusartLoopbackDisable,      /* Loop back disabled. */                                              \
      NULL,                       /* Default advanced settings. */                                       \
    },                                                                                                   \
    true,                         /* Enable IrDA low frequency mode. */                                  \
    eusartIrDARxFilterDisable,    /* Rx Filter disabled. */                                              \
    eusartIrDAPulseWidthOne,      /* Pulse width is set to 1. */                                         \
  }

#if defined(EUSART_PRESENT)
/// Default advanced configuration for EUSART initialization structure in SPI mode with high-frequency clock.
#define EUSART_SPI_ADVANCED_INIT_DEFAULT                                                     \
  {                                                                                          \
    eusartCsActiveLow,              /* CS active low.*/                                      \
    eusartInvertIODisable,          /* Rx and Tx signal active High. */                      \
    true,                           /* AutoCS enabled.*/                                     \
    false,                          /* Data is sent with the least significant bit first. */ \
    0u,                             /* CS setup time is 0 baud cycles */                     \
    0u,                             /* CS hold time is 0 baud cycles */                      \
    0u,                             /* Inter-frame time is 0 baud cycles */                  \
    false,                          /* AutoTx disabled. */                                   \
    0x0000,                         /* Default transmitted data is 0. */                     \
    false,                          /* No DMA wake up on reception. */                       \
    false,                          /* Do not use PRS signal as Rx signal.*/                 \
    (EUSART_PrsChannel_TypeDef) 0u, /* EUSART Rx tied to prs channel 0. */                   \
    false,                          /* Do not use PRS signal as SCLK signal.*/               \
    (EUSART_PrsChannel_TypeDef) 1u, /* EUSART SCLCK tied to prs channel 1. */                \
  }

/// Default configuration for EUSART initialization structure in SPI master mode with high-frequency clock.
#define EUSART_SPI_MASTER_INIT_DEFAULT_HF                                                             \
  {                                                                                                   \
    eusartEnable,              /* Enable RX/TX when initialization completed. */                      \
    0,                         /* Use current configured reference clock for configuring baud rate.*/ \
    10000000,                  /* 10 Mbits/s. */                                                      \
    eusartDataBits8,           /* 8 data bits. */                                                     \
    true,                      /* Master mode enabled. */                                             \
    eusartClockMode0,          /* Clock idle low, sample on rising edge. */                           \
    eusartLoopbackDisable,     /* Loop back disabled. */                                              \
    NULL,                      /* Default advanced settings. */                                       \
  }

/// Default configuration for EUSART initialization structure in SPI slave mode with high-frequency clock.
#define EUSART_SPI_SLAVE_INIT_DEFAULT_HF                                                              \
  {                                                                                                   \
    eusartEnable,              /* Enable RX/TX when initialization completed. */                      \
    0,                         /* Use current configured reference clock for configuring baud rate.*/ \
    10000000,                  /* 10 Mbits/s. */                                                      \
    eusartDataBits8,           /* 8 data bits. */                                                     \
    false,                     /* Master mode enabled. */                                             \
    eusartClockMode0,          /* Clock idle low, sample on rising edge. */                           \
    eusartLoopbackDisable,     /* Loop back disabled. */                                              \
    NULL,                      /* Default advanced settings. */                                       \
  }
#endif

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/***************************************************************************//**
 * Initializes the EUSART when used in UART mode with the high frequency clock.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param init A pointer to the initialization structure.
 ******************************************************************************/
void EUSART_UartInitHf(EUSART_TypeDef *eusart, const EUSART_UartInit_TypeDef *init);

/***************************************************************************//**
 * Initializes the EUSART when used in UART mode with the low frequency clock.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param init A pointer to the initialization structure.
 ******************************************************************************/
void EUSART_UartInitLf(EUSART_TypeDef *eusart, const EUSART_UartInit_TypeDef *init);

/***************************************************************************//**
 * Initializes the EUSART when used in IrDA mode with the high or low
 * frequency clock.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param irdaInit A pointer to the initialization structure.
 ******************************************************************************/
void EUSART_IrDAInit(EUSART_TypeDef *eusart,
                     const EUSART_IrDAInit_TypeDef *irdaInit);

#if defined(EUSART_PRESENT)
/***************************************************************************//**
 * Initializes the EUSART when used in SPI mode.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param init A pointer to the initialization structure.
 ******************************************************************************/
void EUSART_SpiInit(EUSART_TypeDef *eusart, const EUSART_SpiInit_TypeDef *init);
#endif

/***************************************************************************//**
 * Configures the EUSART to its reset state.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 ******************************************************************************/
void EUSART_Reset(EUSART_TypeDef *eusart);

/***************************************************************************//**
 * Enables/disables the EUSART receiver and/or transmitter.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param enable Select the status for the receiver and transmitter.
 ******************************************************************************/
void EUSART_Enable(EUSART_TypeDef *eusart, EUSART_Enable_TypeDef enable);

/***************************************************************************//**
 * Receives one 8 bit frame, (or part of 9 bit frame).
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @note This function is normally used to receive one frame when operating with
 *       frame length of 8 bits. See EUSART_RxExt() for reception of 9 bit frames.
 *       Notice that possible parity/stop bits are not considered a part of the
 *       specified frame bit length.
 * @note This function will stall if buffer is empty until data is received.
 *
 * @return Data received.
 ******************************************************************************/
uint8_t EUSART_Rx(EUSART_TypeDef *eusart);

/***************************************************************************//**
 * Receives one 8-16 bit frame with extended information.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @note This function is normally used to receive one frame and additional RX
 *       status information.
 * @note This function will stall if buffer is empty until data is received.
 *
 * @return Data received and receive status.
 ******************************************************************************/
uint16_t EUSART_RxExt(EUSART_TypeDef *eusart);

/***************************************************************************//**
 * Transmits one frame.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param data Data to transmit.
 *
 * @note Depending on the frame length configuration, 8 (least significant) bits
 *       from @p data are transmitted. If the frame length is 9, 8 bits are
 *       transmitted from @p data. See EUSART_TxExt() for transmitting 9 bit frame
 *       with full control of all 9 bits.
 * @note This function will stall if the 4 frame FIFO is full, until the buffer
 *       becomes available.
 ******************************************************************************/
void EUSART_Tx(EUSART_TypeDef *eusart, uint8_t data);

/***************************************************************************//**
 * Transmits one 8-9 bit frame with extended control.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param data Data to transmit.
 *
 * @note Possible parity/stop bits in asynchronous mode are not
 *       considered part of a specified frame bit length.
 * @note This function will stall if buffer is full until the buffer becomes
 *       available.
 ******************************************************************************/
void EUSART_TxExt(EUSART_TypeDef *eusart, uint16_t data);

#if defined(EUSART_PRESENT)
/***************************************************************************//**
 * Transmits one 8-16 bit frame and return received data.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param data Data to transmit.
 *
 * @return Data received and receive status.
 *
 * @note SPI master mode only.
 * @note This function will stall if the Tx buffer is full until the buffer becomes
 *       available.
 ******************************************************************************/
uint16_t EUSART_Spi_TxRx(EUSART_TypeDef *eusart, uint16_t data);
#endif
/***************************************************************************//**
 * Configures the baudrate (or as close as possible to a specified baudrate).
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param refFreq The EUSART reference clock frequency in Hz that will be used.
 *                 If set to 0, the currently configured peripheral clock is
 *                 used.
 * @param baudrate A baudrate to try to achieve.
 ******************************************************************************/
void EUSART_BaudrateSet(EUSART_TypeDef *eusart,
                        uint32_t refFreq,
                        uint32_t baudrate);

/***************************************************************************//**
 * Gets the current baudrate.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @return The current baudrate.
 ******************************************************************************/
uint32_t EUSART_BaudrateGet(EUSART_TypeDef *eusart);

/***************************************************************************//**
 * Enables/Disables reception operation until the configured start frame is
 * received.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param enable Select the receiver blocking status.
 ******************************************************************************/
void  EUSART_RxBlock(EUSART_TypeDef *eusart,
                     EUSART_BlockRx_TypeDef enable);

/***************************************************************************//**
 * Enables/Disables the tristating of the transmitter output.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param enable Select the transmitter tristate status.
 ******************************************************************************/
void  EUSART_TxTristateSet(EUSART_TypeDef *eusart,
                           EUSART_TristateTx_TypeDef enable);

/***************************************************************************//**
 * Initializes the automatic enabling of transmissions and/or reception using
 * the PRS as a trigger.
 * @note
 *   Initialize EUSART with sl_eusart_initHf() or sl_eusart_initLf() before
 *   enabling the PRS trigger.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 * @param init Pointer to the initialization structure.
 ******************************************************************************/
void EUSART_PrsTriggerEnable(EUSART_TypeDef *eusart,
                             const EUSART_PrsTriggerInit_TypeDef *init);

/***************************************************************************//**
 * Gets EUSART STATUS register.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @return STATUS register value.
 ******************************************************************************/
__STATIC_INLINE uint32_t EUSART_StatusGet(EUSART_TypeDef *eusart)
{
  return eusart->STATUS;
}

/***************************************************************************//**
 * Clears one or more pending EUSART interrupts.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @param flags Pending EUSART interrupt source to clear. Use a bitwise logic OR
 *              combination of valid interrupt flags for EUSART module
 *              (EUSART_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void EUSART_IntClear(EUSART_TypeDef *eusart, uint32_t flags)
{
  eusart->IF_CLR = flags;
}

/***************************************************************************//**
 * Disables one or more EUSART interrupts.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @param flags Pending EUSART interrupt source to clear. Use a bitwise logic OR
 *              combination of valid interrupt flags for EUSART module
 *              (EUSART_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void EUSART_IntDisable(EUSART_TypeDef *eusart, uint32_t flags)
{
  eusart->IEN_CLR = flags;
}

/***************************************************************************//**
 * Enables one or more EUSART interrupts.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @param flags Pending EUSART interrupt source to clear. Use a bitwise logic OR
 *              combination of valid interrupt flags for EUSART module
 *              (EUSART_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void EUSART_IntEnable(EUSART_TypeDef *eusart, uint32_t flags)
{
  eusart->IEN_SET = flags;
}

/***************************************************************************//**
 * Gets pending EUSART interrupt flags.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @return Pending EUSART interrupt sources.
 ******************************************************************************/
__STATIC_INLINE uint32_t EUSART_IntGet(EUSART_TypeDef *eusart)
{
  return eusart->IF;
}

/***************************************************************************//**
 * Gets enabled and pending EUSART interrupt flags.
 * Useful for handling more interrupt sources in the same interrupt handler.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @return Pending and enabled EUSART interrupt sources.
 ******************************************************************************/
__STATIC_INLINE uint32_t EUSART_IntGetEnabled(EUSART_TypeDef *eusart)
{
  uint32_t tmp;

  /* Store EUSARTx->IEN in temporary variable in order to define explicit order
   * of volatile accesses. */
  tmp = eusart->IEN;

  /* Bitwise AND of pending and enabled interrupts */
  return eusart->IF & tmp;
}

/***************************************************************************//**
 * Sets one or more pending EUSART interrupts from SW.
 *
 * @param eusart Pointer to the EUSART peripheral register block.
 *
 * @param flags Interrupt source(s) to set to pending. Use a bitwise logic OR
 *              combination of valid interrupt flags for EUSART module
 *              (EUSART_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void EUSART_IntSet(EUSART_TypeDef *eusart, uint32_t flags)
{
  eusart->IF_SET = flags;
}

#endif /* defined(EUART_PRESENT) || defined(EUSART_PRESENT) */
#endif /* EM_EUSART_H */
