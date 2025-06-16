/***************************************************************************//**
 * @file
 * @brief Universal asynchronous receiver/transmitter (EUSART) peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#include "sl_hal_eusart.h"
#if defined(EUART_PRESENT) || defined(EUSART_PRESENT)

#if defined(SL_HAL_EUSART_PRS_SUPPORTED)
#include "sl_hal_prs.h"
#endif // SL_HAL_EUSART_PRS_SUPPORTED
#include <stddef.h>

/*******************************************************************************
 **************************   LOCAL VARIABLES   ********************************
 ******************************************************************************/
#if defined(EUSART_DALICFG_DALIEN)
static uint8_t dali_tx_nb_packets[EUSART_COUNT];
static uint8_t dali_rx_nb_packets[EUSART_COUNT];
#endif

/*******************************************************************************
 **************************   LOCAL FUNCTIONS   ********************************
 ******************************************************************************/
#if defined(EUSART_DALICFG_DALIEN)
static void eusart_async_init_common(EUSART_TypeDef *eusart,
                                     const sl_hal_eusart_uart_config_t *init,
                                     const sl_hal_eusart_irda_config_t *irda_init,
                                     const sl_hal_eusart_dali_config_t *dali_init);
#else
static void eusart_async_init_common(EUSART_TypeDef *eusart,
                                     const sl_hal_eusart_uart_config_t *init,
                                     const sl_hal_eusart_irda_config_t *irda_init);
#endif

#if defined(_EUSART_CFG0_SYNC_MASK)
static void eusart_sync_init_common(EUSART_TypeDef *eusart,
                                    const sl_hal_eusart_spi_config_t *init);
#endif
static uint8_t eusart_map_oversampling(uint32_t ref_freq, uint32_t baudrate,
                                       sl_hal_eusart_ovs_t ovs);

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

extern __INLINE void sl_hal_eusart_wait_sync(EUSART_TypeDef *eusart,
                                             uint32_t mask);
extern __INLINE void sl_hal_eusart_enable(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_disable(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_wait_ready(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_enable_rx(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_disable_rx(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_enable_tx(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_disable_tx(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_enable_block_rx(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_disable_block_rx(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_enable_tx_tristate(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_disable_tx_tristate(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_clear_rx(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_clear_tx(EUSART_TypeDef *eusart);
extern __INLINE uint32_t sl_hal_eusart_get_status(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_uart_set_clock_div(EUSART_TypeDef *eusart,
                                                      uint32_t clock_divider);
extern __INLINE uint32_t sl_hal_eusart_uart_get_clock_div(EUSART_TypeDef *eusart);
extern __INLINE sl_hal_eusart_ovs_t sl_hal_eusart_uart_get_oversampling(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_clear_interrupts(EUSART_TypeDef *eusart,
                                                    uint32_t flags);
extern __INLINE void sl_hal_eusart_disable_interrupts(EUSART_TypeDef *eusart,
                                                      uint32_t flags);
extern __INLINE void sl_hal_eusart_enable_interrupts(EUSART_TypeDef *eusart,
                                                     uint32_t flags);
extern __INLINE uint32_t sl_hal_eusart_get_pending_interrupts(EUSART_TypeDef *eusart);
extern __INLINE uint32_t sl_hal_eusart_get_enabled_pending_interrupts(EUSART_TypeDef *eusart);
extern __INLINE void sl_hal_eusart_set_interrupts(EUSART_TypeDef *eusart,
                                                  uint32_t flags);

/***************************************************************************//**
 * Initializes the EUSART when used with the high frequency clock.
 ******************************************************************************/
void sl_hal_eusart_init_uart_hf(EUSART_TypeDef *eusart,
                                const sl_hal_eusart_uart_config_t *init)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));
  // Init structure must be provided.
  EFM_ASSERT(init);

  // Assert features specific to HF.
  // The oversampling must not be disabled when using a high frequency clock.
  EFM_ASSERT(init->oversampling != SL_HAL_EUSART_OVS_0);

  // Uart mode only supports up to 9 databits frame.
  EFM_ASSERT(init->data_bits <= SL_HAL_EUSART_DATA_BITS_9);

  // Initialize EUSART with common features to HF and LF.
#if defined(EUSART_DALICFG_DALIEN)
  eusart_async_init_common(eusart, init, NULL, NULL);
#else
  eusart_async_init_common(eusart, init, NULL);
#endif
}

/***************************************************************************//**
 * Initializes the EUSART when used with the low frequency clock.
 ******************************************************************************/
void sl_hal_eusart_init_uart_lf(EUSART_TypeDef *eusart,
                                const sl_hal_eusart_uart_config_t *init)
{
  // Make sure the module exists and is Low frequency capable.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart) && EUSART_EM2_CAPABLE(EUSART_NUM(eusart)));
  // Init structure must be provided.
  EFM_ASSERT(init);

  // Uart mode only supports up to 9 databits frame.
  EFM_ASSERT(init->data_bits <= SL_HAL_EUSART_DATA_BITS_9);
  // The oversampling must be disabled when using a low frequency clock.
  EFM_ASSERT(init->oversampling == SL_HAL_EUSART_OVS_0);
  // The Majority Vote must be disabled when using a low frequency clock.
  EFM_ASSERT(init->majority_vote == SL_HAL_EUSART_MAJORITY_VOTE_DISABLE);
  // Number of stop bits can only be 1 or 2 in LF.
  EFM_ASSERT((init->stop_bits == SL_HAL_EUSART_STOP_BITS_1) || (init->stop_bits == SL_HAL_EUSART_STOP_BITS_2));

  // Initialize EUSART with common features to HF and LF.
#if defined(EUSART_DALICFG_DALIEN)
  eusart_async_init_common(eusart, init, NULL, NULL);
#else
  eusart_async_init_common(eusart, init, NULL);
#endif
}

/***************************************************************************//**
 * Initializes the EUSART when used in IrDA mode with the high or low
 * frequency clock.
 ******************************************************************************/
void sl_hal_eusart_init_irda(EUSART_TypeDef *eusart,
                             const sl_hal_eusart_irda_config_t *irda_config)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));
  // Init structure must be provided.
  EFM_ASSERT(irda_config);

  if (irda_config->irda_mode == SL_HAL_EUSART_IRDA_MODE_LF) {
    // Validate the low frequency capability of the EUSART instance.
    EFM_ASSERT(EUSART_EM2_CAPABLE(EUSART_NUM(eusart)));
    // The oversampling must be disabled when using a low frequency clock.
    EFM_ASSERT(irda_config->eusart_init.oversampling == SL_HAL_EUSART_OVS_0);
    // Number of stop bits can only be 1 or 2 in LF.
    EFM_ASSERT((irda_config->eusart_init.stop_bits == SL_HAL_EUSART_STOP_BITS_1) || (irda_config->eusart_init.stop_bits == SL_HAL_EUSART_STOP_BITS_2));
  } else {
    EFM_ASSERT(irda_config->eusart_init.oversampling != SL_HAL_EUSART_OVS_0);
  }

  // Initialize EUSART with common features to HF and LF.
#if defined(EUSART_DALICFG_DALIEN)
  eusart_async_init_common(eusart, &irda_config->eusart_init, irda_config, NULL);
#else
  eusart_async_init_common(eusart, &irda_config->eusart_init, irda_config);
#endif
}

#if defined(EUSART_DALICFG_DALIEN)
/***************************************************************************//**
 * Initializes the EUSART when used in DALI mode with the high or low
 * frequency clock.
 ******************************************************************************/
void sl_hal_eusart_init_dali(EUSART_TypeDef *eusart,
                             const sl_hal_eusart_dali_config_t *dali_config)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));
  // Init structure must be provided.
  EFM_ASSERT(dali_config);

  if (dali_config->eusart_init.loopback_enable) {
    // If LOOPBK in CFG0 is set to 1 in order to do loopback testing for DALI,
    // then in this case DALIRXENDT should be set to 1 and DALIRXDATABITS should
    // be set the same as DALITXDATABITS.
    EFM_ASSERT(dali_config->tx_data_bits == dali_config->rx_data_bits);
  }

  if (dali_config->dali_low_frequency_enable) {
    // Validate the low frequency capability of the EUSART instance.
    EFM_ASSERT(EUSART_EM2_CAPABLE(EUSART_NUM(eusart)));
    // The oversampling must be disabled when using a low frequency clock.
    EFM_ASSERT(dali_config->eusart_init.oversampling == SL_HAL_EUSART_OVS_0);
  } else {
    EFM_ASSERT(dali_config->eusart_init.oversampling != SL_HAL_EUSART_OVS_0);
  }

  // Initialize EUSART with common features to HF and LF.
  eusart_async_init_common(eusart, &dali_config->eusart_init, NULL, dali_config);
}
#endif

#if defined(_EUSART_CFG0_SYNC_MASK)
/***************************************************************************//**
 * Initializes the EUSART when used in SPI mode.
 ******************************************************************************/
void sl_hal_eusart_init_spi(EUSART_TypeDef *eusart,
                            sl_hal_eusart_spi_config_t const *init)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));
  // Init structure must be provided.
  EFM_ASSERT(init);

  eusart_sync_init_common(eusart, init);
}
#endif

/***************************************************************************//**
 * Configure the EUSART to its reset state.
 ******************************************************************************/
void sl_hal_eusart_reset(EUSART_TypeDef *eusart)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  // Properly disable the module
  sl_hal_eusart_disable_tx(eusart);
  sl_hal_eusart_disable_rx(eusart);
  sl_hal_eusart_wait_sync(eusart, EUSART_SYNCBUSY_RXDIS | EUSART_SYNCBUSY_TXDIS);
  sl_hal_eusart_disable(eusart);
  sl_hal_eusart_wait_ready(eusart);

  // Clear FIFOs.
  sl_hal_eusart_clear_rx(eusart);
  sl_hal_eusart_clear_tx(eusart);

#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_3)  \
  || defined(_SILICON_LABS_32B_SERIES_2_CONFIG_4) \
  || defined(_SILICON_LABS_32B_SERIES_2_CONFIG_5) \
  || defined(_SILICON_LABS_32B_SERIES_2_CONFIG_6)
  // Manual toggling tx_sclk_mst to synchronize handshake
  // when switching from SPI master to other modes
  // so module is disabling correctly.
  uint32_t forcedClkCycle = 4u;

  while (forcedClkCycle--) {
    eusart->CFG2_SET = _EUSART_CFG2_CLKPHA_MASK;
    eusart->CFG2_CLR = _EUSART_CFG2_CLKPHA_MASK;
  }
#endif

  // All registers that end with CFG should be programmed before EUSART gets enabled (EUSARTn_EN is set).
  // Set all configurable register to its reset value.
  // Note: Program desired settings to all registers that have names ending with CFG in the following sequence:
  //  a. CFG2
#if defined(_EUSART_CFG2_MASK)
  eusart->CFG2 = _EUSART_CFG2_RESETVALUE;
#endif
  //  b. CFG1
  eusart->CFG1 = _EUSART_CFG1_RESETVALUE;
  //  c. CFG0
  eusart->CFG0 = _EUSART_CFG0_RESETVALUE;
  //  d. FRAMECFG, DTXDATCFG, TIMINGCFG (Any sequence)
  eusart->FRAMECFG = _EUSART_FRAMECFG_RESETVALUE;

  eusart->TIMINGCFG = _EUSART_TIMINGCFG_RESETVALUE;
  eusart->IRHFCFG = _EUSART_IRHFCFG_RESETVALUE;
#if defined(_EUSART_IRLFCFG_RESETVALUE)
  eusart->IRLFCFG = _EUSART_IRLFCFG_RESETVALUE;
#endif
#if defined(_EUSART_DTXDATCFG_MASK)
  eusart->DTXDATCFG = _EUSART_DTXDATCFG_RESETVALUE;
#if defined(EUSART_DALICFG_DALIEN)
  eusart->DALICFG = _EUSART_DALICFG_RESETVALUE;
#endif
#endif
  eusart->STARTFRAMECFG = _EUSART_STARTFRAMECFG_RESETVALUE;
  eusart->SIGFRAMECFG = _EUSART_SIGFRAMECFG_RESETVALUE;
  eusart->TRIGCTRL = _EUSART_TRIGCTRL_RESETVALUE;
  eusart->IEN = _EUSART_IEN_RESETVALUE;
  eusart->IF_CLR = _EUSART_IF_MASK;
  eusart->CLKDIV = _EUSART_CLKDIV_RESETVALUE;

  while (!(eusart->SYNCBUSY & _EUSART_SYNCBUSY_MASK)) {
    // Wait for all registers to be modified preventing issues when
    // disabling the eusart bus clock just after calling this function.
  }
}

/***************************************************************************//**
 * Receives one 8 bit frame, (or part of 9 bit frame).
 *
 * @note (1) Handles the case where the RX Fifo Watermark has been set to N frames,
 *       and when N is greater than one. Attempt to read a frame from the RX Fifo.
 *       If the read is unsuccessful (i.e. no frames in the RX fifo), the RXFU
 *       interrupt flag is set. If the flag is set, wait to read again until the RXFL
 *       status flag is set, indicating there are N frames in the RX Fifo, where N
 *       is equal to the RX watermark level. Once there are N frames in the Fifo,
 *       read and return one frame. For consecutive N-1 reads there will be data available
 *       in the Fifo. Therefore, the RXUF interrupt will not be triggered eliminating
 *       delays between reads and sending N data frames in "bursts".
 *
 * @note This is a blocking function.
 ******************************************************************************/
uint16_t sl_hal_eusart_rx(EUSART_TypeDef *eusart)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  // If RX watermark has not been configured.
  if ((eusart->CFG1 & _EUSART_CFG1_RXFIW_MASK) == EUSART_CFG1_RXFIW_DEFAULT) {
    while (!(eusart->STATUS & _EUSART_STATUS_RXFL_MASK)) {
      // Wait for incoming data.
    }
    return (uint16_t)eusart->RXDATA;
  }

  // See Note #1.
  uint16_t rx_data = (uint16_t)eusart->RXDATA;
  // If there is underflow i.e Rx data read was unsuccessful
  if (eusart->IF & EUSART_IF_RXUF) {
    while (!(eusart->STATUS & _EUSART_STATUS_RXFL_MASK)) {
      // Wait until data becomes available in Rx fifo.
    }
    // Read Rx data again once data is available in the fifo
    rx_data = (uint16_t)eusart->RXDATA;
  }

  return rx_data;
}

/***************************************************************************//**
 * Receives one 8-9 bit frame with extended information.
 ******************************************************************************/
uint16_t sl_hal_eusart_rx_extended(EUSART_TypeDef *eusart)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  while (!(eusart->STATUS & EUSART_STATUS_RXFL)) {
    // Wait for incoming data.
  }

  return (uint16_t)eusart->RXDATA;
}

/***************************************************************************//**
 * Transmits one frame.
 ******************************************************************************/
void sl_hal_eusart_tx(EUSART_TypeDef *eusart,
                      uint16_t data)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  while (!(eusart->STATUS & _EUSART_STATUS_TXFL_MASK)) {
    // Check that transmit FIFO is not full.
  }

  eusart->TXDATA = (uint32_t)data;
}

/***************************************************************************//**
 * Transmits one 8-9 bit frame with extended control.
 ******************************************************************************/
void sl_hal_eusart_tx_extended(EUSART_TypeDef *eusart,
                               uint16_t data)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  while (!(eusart->STATUS & EUSART_STATUS_TXFL)) {
    // Check that transmit FIFO is not full.
  }

  eusart->TXDATA = (uint32_t)data;
}

#if defined(_EUSART_CFG0_SYNC_MASK)
/***************************************************************************//**
 * Transmits one 8-16 bit frame and return received data.
 ******************************************************************************/
uint16_t sl_hal_eusart_spi_tx_rx(EUSART_TypeDef *eusart, uint16_t data)
{
  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  while (!(eusart->STATUS & EUSART_STATUS_TXFL)) {
    // Check that transmit FIFO is not full.
  }
  eusart->TXDATA = (uint32_t)data;

  while (!(eusart->STATUS & EUSART_STATUS_RXFL)) {
    // Wait for Rx data to be available.
  }
  return (uint16_t)eusart->RXDATA;
}
#endif /* _EUSART_CFG0_SYNC_MASK */

#if defined(EUSART_DALICFG_DALIEN)
/***************************************************************************//**
 * Transmit one DALI frame.
 ******************************************************************************/
void sl_hal_eusart_dali_tx(EUSART_TypeDef *eusart, uint32_t data)
{
  uint32_t packet;

  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  while (!(eusart->STATUS & EUSART_STATUS_TXFL)) {
    // Check that transmit FIFO is not full.
  }

  // When DALICFG.DALIEN is set to 1, then all 16 bits [15:0] represent data.
  // First write to TXDATA register should contain 16 LSBs of the TX frame.
  // Transmission will not start after this first write.
  packet = data;
  // To ensure compatibility with future devices, always write bits [31:16] to 0.
  packet &= 0x0000FFFF;
  eusart->TXDATA = packet;

  // Second write to TXDATA register should contain the remaining TX frame bits.
  // This second write will result in start of transmission.
  if (dali_tx_nb_packets[EUSART_NUM(eusart)] == 2) {
    packet = data >> 16;
    eusart->TXDATA = packet;
  }
}

/***************************************************************************//**
 * Receive one DALI frame.
 ******************************************************************************/
uint32_t sl_hal_eusart_dali_rx(EUSART_TypeDef *eusart)
{
  uint32_t data = 0;

  // Make sure the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  while (!(eusart->STATUS & EUSART_STATUS_RXFL)) {
    // Wait for incoming data.
  }

  // When DALICFG.DALIEN is set to 1, then all 16 bits [15:0] represent data.
  // When receiving a frame that has more than 16 databits,
  // RXDATA register needs to be read twice.
  // First read will provide 16 LSBs of the received frame.
  data |= (eusart->RXDATA & _EUSART_RXDATA_RXDATA_MASK);

  // Second read will provide the remaining RX frame bits.
  if (dali_rx_nb_packets[EUSART_NUM(eusart)] == 2) {
    data |= ((eusart->RXDATA & _EUSART_RXDATA_RXDATA_MASK) <<  16);
  }
  return data;
}
#endif /* EUSART_DALICFG_DALIEN */

#if defined(SL_HAL_EUSART_PRS_SUPPORTED)
/***************************************************************************//**
 * Enable automatic enabling of reception using the PRS as a trigger.
 ******************************************************************************/
void sl_hal_eusart_enable_rx_prs_trigger(EUSART_TypeDef *eusart, uint8_t channel)
{
  // Make sure that the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  // The peripheral must be enabled to configure the PRS trigger.
  EFM_ASSERT(eusart->EN == EUSART_EN_EN);

  if (0) {
#if defined(EUART0)
  } else if (eusart == EUART0) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUART0_TRIGGER);
#endif
#if defined(EUSART0)
  } else if (eusart == EUSART0) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART0_TRIGGER);
#endif
#if defined(EUSART1)
  } else if (eusart == EUSART1) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART1_TRIGGER);
#endif
#if defined(EUSART2)
  } else if (eusart == EUSART2) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART2_TRIGGER);
#endif
#if defined(EUSART3)
  } else if (eusart == EUSART3) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART3_TRIGGER);
#endif
#if defined(EUSART4)
  } else if (eusart == EUSART4) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART4_TRIGGER);
#endif
  } else {
    EFM_ASSERT(false);
  }

  sl_hal_eusart_wait_sync(eusart, EUSART_SYNCBUSY_RXDIS | EUSART_SYNCBUSY_RXTEN);
  eusart->TRIGCTRL_SET = EUSART_TRIGCTRL_RXTEN;
}

/***************************************************************************//**
 * Disable automatic enabling of reception using the PRS as a trigger.
 ******************************************************************************/
void sl_hal_eusart_disable_rx_prs_trigger(EUSART_TypeDef *eusart)
{
  // Make sure that the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  // The peripheral must be enabled to configure the PRS trigger.
  EFM_ASSERT(eusart->EN == EUSART_EN_EN);

  sl_hal_eusart_wait_sync(eusart, EUSART_SYNCBUSY_RXDIS | EUSART_SYNCBUSY_RXTEN);
  eusart->TRIGCTRL_CLR = EUSART_TRIGCTRL_RXTEN;
}

/***************************************************************************//**
 * Enable automatic enabling of transmission using the PRS as a trigger.
 ******************************************************************************/
void sl_hal_eusart_enable_tx_prs_trigger(EUSART_TypeDef *eusart, uint8_t channel)
{
  // Make sure that the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  // The peripheral must be enabled to configure the PRS trigger.
  EFM_ASSERT(eusart->EN == EUSART_EN_EN);

  if (0) {
#if defined(EUART0)
  } else if (eusart == EUART0) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUART0_TRIGGER);
#endif
#if defined(EUSART0)
  } else if (eusart == EUSART0) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART0_TRIGGER);
#endif
#if defined(EUSART1)
  } else if (eusart == EUSART1) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART1_TRIGGER);
#endif
#if defined(EUSART2)
  } else if (eusart == EUSART2) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART2_TRIGGER);
#endif
#if defined(EUSART3)
  } else if (eusart == EUSART3) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART3_TRIGGER);
#endif
#if defined(EUSART4)
  } else if (eusart == EUSART4) {
    sl_hal_prs_connect_channel_consumer(channel,
                                        SL_HAL_PRS_TYPE_ASYNC,
                                        SL_HAL_PRS_CONSUMER_EUSART4_TRIGGER);
#endif
  } else {
    EFM_ASSERT(false);
  }

  sl_hal_eusart_wait_sync(eusart, EUSART_SYNCBUSY_TXDIS | EUSART_SYNCBUSY_TXEN);
  eusart->TRIGCTRL_SET = EUSART_TRIGCTRL_TXTEN;
}

/***************************************************************************//**
 * Disable automatic enabling of transmission using the PRS as a trigger.
 ******************************************************************************/
void sl_hal_eusart_disable_tx_prs_trigger(EUSART_TypeDef *eusart)
{
  // Make sure that the module exists on the selected chip.
  EFM_ASSERT(SL_HAL_EUSART_REF_VALID(eusart));

  // The peripheral must be enabled to configure the PRS trigger.
  EFM_ASSERT(eusart->EN == EUSART_EN_EN);

  sl_hal_eusart_wait_sync(eusart, EUSART_SYNCBUSY_TXDIS | EUSART_SYNCBUSY_TXEN);
  eusart->TRIGCTRL_CLR = EUSART_TRIGCTRL_TXTEN;
}

#endif // defined(SL_HAL_EUSART_SUPPORT_PRS)

#if defined(_EUSART_CFG0_SYNC_MASK)
/***************************************************************************//**
 * Calculate clock divider for spi using baudrate.
 ******************************************************************************/
uint32_t sl_hal_eusart_spi_calculate_clock_div(uint32_t ref_freq,
                                               uint32_t baudrate)
{
  uint32_t clkdiv;
  // Prevent dividing by 0.
  EFM_ASSERT(baudrate);
  EFM_ASSERT(baudrate <= ref_freq);

  clkdiv = ref_freq / baudrate - 1UL;

  // If the desired bit rate requires a divider larger than the Synchronous divider bitfield (CFG2_SDIV),
  // the resulting SPI master bus clock will be undefined because the result will be truncated.
  EFM_ASSERT(clkdiv <= (_EUSART_CFG2_SDIV_MASK >> _EUSART_CFG2_SDIV_SHIFT));

  return clkdiv;
}
#endif

/***************************************************************************//**
 * Calculate clock divider for uart using baudrate.
 ******************************************************************************/
uint32_t sl_hal_eusart_uart_calculate_clock_div(uint32_t ref_freq,
                                                uint32_t baudrate, sl_hal_eusart_ovs_t ovs)
{
  uint32_t clkdiv;
  uint8_t oversample = 0;

  // Prevent dividing by 0.
  EFM_ASSERT(baudrate);

  // In asynchronous mode (ex: UART)
  oversample = eusart_map_oversampling(ref_freq, baudrate, ovs);
  // Calculate and set the CLKDIV with fractional bits.
  clkdiv  = (32 * ref_freq) / (baudrate * oversample);
  clkdiv -= 32;
  clkdiv *= 8;
  // Verify that the resulting clock divider is within limits.
  EFM_ASSERT(clkdiv <= _EUSART_CLKDIV_MASK);
  // If the EFM_ASSERT is not enabled, make sure not to write to reserved bits.
  clkdiv = (clkdiv & _EUSART_CLKDIV_MASK) >> _EUSART_CLKDIV_DIV_SHIFT;
  return clkdiv;
}

/***************************************************************************//**
 * Calculate the baudrate from the clkdiv value and the clock branch frequency
 ******************************************************************************/
uint32_t sl_hal_eusart_uart_calculate_baudrate(uint32_t div,
                                               sl_hal_eusart_ovs_t ovs,
                                               uint32_t freq)
{
  uint32_t oversample;
  uint32_t divisor;
  uint32_t remainder;
  uint32_t quotient;
  uint32_t baudrate;

  div <<= _EUSART_CLKDIV_DIV_SHIFT;
  EFM_ASSERT(div <= _EUSART_CLKDIV_MASK);

  switch (ovs) {
    case _EUSART_CFG0_OVS_X16:
      oversample = 16;
      break;

    case _EUSART_CFG0_OVS_X8:
      oversample = 8;
      break;

    case _EUSART_CFG0_OVS_X6:
      oversample = 6;
      break;

    case _EUSART_CFG0_OVS_X4:
      oversample = 4;
      break;

    case _EUSART_CFG0_OVS_DISABLE:
      oversample = 1;
      break;

    default:
      return 0u;
  }

  divisor = (oversample * (256 + div));
  quotient = freq / divisor;
  remainder = freq % divisor;

  baudrate =  (256 * quotient);
  baudrate += ((256 * remainder) / divisor);
  return baudrate;
}

#if defined(_EUSART_CFG0_SYNC_MASK)
/***************************************************************************//**
 * Calculate the baudrate from the clkdiv value and the clock branch frequency
 ******************************************************************************/
uint32_t sl_hal_eusart_spi_calculate_baudrate(uint32_t div, uint32_t freq)
{
  // Prevent dividing by 0.
  EFM_ASSERT(freq);

  return freq / (div + 1);
}
#endif

/***************************************************************************//**
 * Initializes the EUSART with asynchronous common settings to high
 * and low frequency clock.
 *
 * @param[in] eusart Pointer to the EUSART peripheral register block.
 * @param[in] init A pointer to the initialization structure.
 * @param[in] irda_init A pointer to IrDA initialization structure.
 * @param[in] dali_init A pointer to DALI initialization structure. Only
 *              applicable when DALII is available.
 ******************************************************************************/
#if defined(EUSART_DALICFG_DALIEN)
static void eusart_async_init_common(EUSART_TypeDef *eusart,
                                     const sl_hal_eusart_uart_config_t *init,
                                     const sl_hal_eusart_irda_config_t *irda_init,
                                     const sl_hal_eusart_dali_config_t *dali_init)
#else
static void eusart_async_init_common(EUSART_TypeDef *eusart,
                                     const sl_hal_eusart_uart_config_t *init,
                                     const sl_hal_eusart_irda_config_t *irda_init)
#endif
{
  // Initialize EUSART registers to hardware reset state.
  sl_hal_eusart_reset(eusart);

  // Configure frame format
  eusart->FRAMECFG = (eusart->FRAMECFG & ~(_EUSART_FRAMECFG_DATABITS_MASK
                                           | _EUSART_FRAMECFG_STOPBITS_MASK
                                           | _EUSART_FRAMECFG_PARITY_MASK))
                     | (uint32_t)(init->data_bits << _EUSART_FRAMECFG_DATABITS_SHIFT)
                     | (uint32_t)(init->parity << _EUSART_FRAMECFG_PARITY_SHIFT)
                     | (uint32_t)(init->stop_bits << _EUSART_FRAMECFG_STOPBITS_SHIFT);

  // Configure global configuration register 0.
  eusart->CFG0 = (eusart->CFG0 & ~(_EUSART_CFG0_OVS_MASK
                                   | _EUSART_CFG0_LOOPBK_MASK
                                   | _EUSART_CFG0_MVDIS_MASK))
                 | (uint32_t)(init->oversampling << _EUSART_CFG0_OVS_SHIFT)
                 | (uint32_t)(init->loopback_enable << _EUSART_CFG0_LOOPBK_SHIFT)
                 | (uint32_t)(init->majority_vote << _EUSART_CFG0_MVDIS_SHIFT);

  eusart->CLKDIV = (init->clock_div << _EUSART_CLKDIV_DIV_SHIFT) & _EUSART_CLKDIV_DIV_MASK;

  // Configure advanced features.
  if (init->advanced_config) {
    eusart->CFG0 = (eusart->CFG0 & ~(_EUSART_CFG0_ERRSDMA_MASK | _EUSART_CFG0_AUTOTRI_MASK
                                     | _EUSART_CFG0_RXINV_MASK | _EUSART_CFG0_TXINV_MASK
                                     | _EUSART_CFG0_CCEN_MASK  | _EUSART_CFG0_MPM_MASK
                                     | _EUSART_CFG0_MPAB_MASK  | _EUSART_CFG0_MSBF_MASK))
                   | ((uint32_t)init->advanced_config->dma_halt_on_error << _EUSART_CFG0_ERRSDMA_SHIFT)
                   | ((uint32_t)init->advanced_config->tx_auto_tristate << _EUSART_CFG0_AUTOTRI_SHIFT)
                   | ((uint32_t)init->advanced_config->invert_io << _EUSART_CFG0_RXINV_SHIFT)
                   | ((uint32_t)init->advanced_config->collision_detect << _EUSART_CFG0_CCEN_SHIFT)
                   | ((uint32_t)init->advanced_config->multi_processor_enable << _EUSART_CFG0_MPM_SHIFT)
                   | ((uint32_t)init->advanced_config->multi_processor_address_bit_high << _EUSART_CFG0_MPAB_SHIFT)
                   | ((uint32_t)init->advanced_config->msb_first << _EUSART_CFG0_MSBF_SHIFT);

    // Configure global configuration register 1.
    eusart->CFG1 = (eusart->CFG1 & ~(_EUSART_CFG1_RXFIW_MASK | _EUSART_CFG1_TXFIW_MASK
#if defined(_EUSART_CFG1_RXDMAWU_MASK)
                                     | _EUSART_CFG1_RXDMAWU_MASK
#endif
#if defined(_EUSART_CFG1_TXDMAWU_MASK)
                                     | _EUSART_CFG1_TXDMAWU_MASK
#endif
                                     ))
                   | ((uint32_t)init->advanced_config->rx_fifo_watermark << _EUSART_CFG1_RXFIW_SHIFT)
                   | ((uint32_t)init->advanced_config->tx_fifo_watermark << _EUSART_CFG1_TXFIW_SHIFT)
                   #if defined(_EUSART_CFG1_RXDMAWU_MASK)
                   | ((uint32_t)init->advanced_config->dma_wakeup_on_rx << _EUSART_CFG1_RXDMAWU_SHIFT)
                   #endif
                     #if defined(_EUSART_CFG1_TXDMAWU_MASK)
                   | ((uint32_t)init->advanced_config->dma_wakeup_on_tx << _EUSART_CFG1_TXDMAWU_SHIFT)
                   #endif
    ;

    if (init->advanced_config->hw_flow_control_mode == SL_HAL_EUSART_HW_FLOW_CONTROL_CTS
        || init->advanced_config->hw_flow_control_mode == SL_HAL_EUSART_HW_FLOW_CONTROL_CTS_RTS) {
      eusart->CFG1_SET = EUSART_CFG1_CTSEN;
    }
    // Enable RTS route pin if necessary. CTS is an input so it is enabled by default.
    if ((init->advanced_config->hw_flow_control_mode == SL_HAL_EUSART_HW_FLOW_CONTROL_RTS)
        || (init->advanced_config->hw_flow_control_mode == SL_HAL_EUSART_HW_FLOW_CONTROL_CTS_RTS)) {
#if defined(EUART0)
      GPIO->EUARTROUTE_SET->ROUTEEN = GPIO_EUART_ROUTEEN_RTSPEN;
#elif defined(EUSART0)
      GPIO->EUSARTROUTE_SET[EUSART_NUM(eusart)].ROUTEEN = GPIO_EUSART_ROUTEEN_RTSPEN;
#endif
    } else {
#if defined(EUART0)
      GPIO->EUARTROUTE_CLR->ROUTEEN = GPIO_EUART_ROUTEEN_RTSPEN;
#elif defined(EUSART0)
      GPIO->EUSARTROUTE_CLR[EUSART_NUM(eusart)].ROUTEEN = GPIO_EUSART_ROUTEEN_RTSPEN;
#endif
    }
    eusart->STARTFRAMECFG_SET = (uint32_t)init->advanced_config->start_frame;
    if (init->advanced_config->start_frame) {
      eusart->CFG1_SET = EUSART_CFG1_SFUBRX;
    }
#if defined(SL_HAL_EUSART_PRS_SUPPORTED)
    if (init->advanced_config->prs_rx_enable) {
      eusart->CFG1_SET = EUSART_CFG1_RXPRSEN;
      // Configure PRS channel as input data line for EUSART.
#if defined(EUART_PRESENT)
      sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                          SL_HAL_PRS_TYPE_ASYNC,
                                          SL_HAL_PRS_CONSUMER_EUART0_RX);
#elif defined(EUSART_PRESENT)
      if (eusart == EUSART0) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART0_RX);
      }
#if defined(EUSART1)
      else if (eusart == EUSART1) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART1_RX);
      }
#endif
#if defined(EUSART2)
      else if (eusart == EUSART2) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART2_RX);
      }
#endif
#if defined(EUSART3)
      else if (eusart == EUSART3) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART3_RX);
      }
#endif
#if defined(EUSART4)
      else if (eusart == EUSART4) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART4_RX);
      }
#endif
      else {
        EFM_ASSERT(false);
      }
#endif
    }
#endif // defined(SL_HAL_EUSART_PRS_SUPPORTED)
    // Configure global configuration timing register.
    eusart->TIMINGCFG = (eusart->TIMINGCFG & ~_EUSART_TIMINGCFG_TXDELAY_MASK)
                        | (uint32_t)(init->advanced_config->auto_tx_delay << _EUSART_TIMINGCFG_TXDELAY_SHIFT);
  }

  if (irda_init) {
    if (irda_init->irda_mode == SL_HAL_EUSART_IRDA_MODE_LF) {
#if defined(EUSART_IRLFCFG_IRLFEN)
      eusart->IRLFCFG_SET = EUSART_IRLFCFG_IRLFEN;
#endif
    } else {
      // Configure IrDA HF configuration register.
      eusart->IRHFCFG_SET = (eusart->IRHFCFG & ~(_EUSART_IRHFCFG_IRHFEN_MASK
                                                 | _EUSART_IRHFCFG_IRHFPW_MASK
                                                 | _EUSART_IRHFCFG_IRHFFILT_MASK))
                            | EUSART_IRHFCFG_IRHFEN
                            | ((uint32_t)irda_init->pulse_width << _EUSART_IRHFCFG_IRHFPW_SHIFT)
                            | ((uint32_t)irda_init->hf_rx_filter_enable << _EUSART_IRHFCFG_IRHFFILT_SHIFT);
    }
  }

#if defined(EUSART_DALICFG_DALIEN)
  // DALI-specific configuration section
  if (dali_init) {
    if (init->loopback_enable) {
      // If LOOPBK in CFG0 is set to 1 in order to do loopback testing for DALI,
      // then in this case DALIRXENDT should be set to 1.
      eusart->DALICFG_SET = EUSART_DALICFG_DALIRXENDT;
    }

    if (SL_HAL_EUSART_REF_VALID(eusart)) {
      uint8_t index = EUSART_NUM(eusart);

      // keep track of the number of 16-bits packet to send
      if (dali_init->tx_data_bits <= SL_HAL_EUSART_DALI_DATA_BITS_16) {
        dali_tx_nb_packets[index] = 1;
      } else {
        dali_tx_nb_packets[index] = 2;
      }

      // keep track of the number of 16-bits packet to receive
      if (dali_init->rx_data_bits <= SL_HAL_EUSART_DALI_DATA_BITS_16) {
        dali_rx_nb_packets[index] = 1;
      } else {
        dali_rx_nb_packets[index] = 2;
      }
    }

    // Configure the numbers of bits per TX and RX frames
    eusart->DALICFG = (eusart->DALICFG & ~(_EUSART_DALICFG_DALITXDATABITS_MASK
                                           | _EUSART_DALICFG_DALIRXDATABITS_MASK))
                      | (dali_init->tx_data_bits << _EUSART_DALICFG_DALITXDATABITS_SHIFT)
                      | (dali_init->rx_data_bits << _EUSART_DALICFG_DALIRXDATABITS_SHIFT);
    eusart->DALICFG_SET = EUSART_DALICFG_DALIEN;
  }
#endif
}

#if defined(_EUSART_CFG0_SYNC_MASK)
/***************************************************************************//**
 * Initializes the EUSART with synchronous common settings to high
 * and low frequency clock.
 *
 * @param[in] eusart Pointer to the EUSART peripheral register block.
 * @param[in] init A pointer to the initialization structure.
 ******************************************************************************/
static void eusart_sync_init_common(EUSART_TypeDef *eusart,
                                    sl_hal_eusart_spi_config_t const *init)
{
  // Initialize EUSART registers to hardware reset state.
  sl_hal_eusart_reset(eusart);

  // Configure global configuration register 2.
  eusart->CFG2 = (eusart->CFG2 & ~(_EUSART_CFG2_MASTER_MASK
                                   | _EUSART_CFG2_CLKPOL_MASK
                                   | _EUSART_CFG2_CLKPHA_MASK
                                   | _EUSART_CFG2_FORCELOAD_MASK))
                 | ((uint32_t)init->master << _EUSART_CFG2_MASTER_SHIFT)
                 | ((uint32_t)init->clock_mode << _EUSART_CFG2_CLKPOL_SHIFT)
                 | EUSART_CFG2_FORCELOAD;   // Force load feature enabled by default.

  eusart->CFG0 = (eusart->CFG0 & ~(_EUSART_CFG0_SYNC_MASK
                                   | _EUSART_CFG0_LOOPBK_MASK))
                 | _EUSART_CFG0_SYNC_SYNC
                 | (uint32_t)(init->loopback_enable << _EUSART_CFG0_LOOPBK_SHIFT);

  // Configure frame format
  eusart->FRAMECFG = (eusart->FRAMECFG & ~(_EUSART_FRAMECFG_DATABITS_MASK))
                     | (uint32_t)(init->data_bits << _EUSART_FRAMECFG_DATABITS_SHIFT);

  // Set clock divider for synchronous operation mode.
  eusart->CFG2 = (eusart->CFG2 & ~(_EUSART_CFG2_SDIV_MASK))
                 | ((init->clock_div << _EUSART_CFG2_SDIV_SHIFT) & _EUSART_CFG2_SDIV_MASK);

  if (init->advanced_config) {
    // Configure global configuration register 2.
    eusart->CFG2 = (eusart->CFG2 & ~(_EUSART_CFG2_FORCELOAD_MASK
                                     | _EUSART_CFG2_AUTOCS_MASK
                                     | _EUSART_CFG2_AUTOTX_MASK
                                     | _EUSART_CFG2_CSINV_MASK
                                     | _EUSART_CFG2_CLKPRSEN_MASK))
                   | ((uint32_t)init->advanced_config->force_load << _EUSART_CFG2_FORCELOAD_SHIFT)
                   | ((uint32_t)init->advanced_config->auto_cs_enable << _EUSART_CFG2_AUTOCS_SHIFT)
                   | ((uint32_t)init->advanced_config->auto_tx_enable << _EUSART_CFG2_AUTOTX_SHIFT)
                   | ((uint32_t)init->advanced_config->cs_polarity << _EUSART_CFG2_CSINV_SHIFT)
                   | ((uint32_t)init->advanced_config->prs_clock_enable << _EUSART_CFG2_CLKPRSEN_SHIFT);

    // Only applicable to EM2 (low frequency) capable EUSART instances.
    eusart->CFG1 = (eusart->CFG1 & ~(_EUSART_CFG1_RXFIW_MASK
                                     | _EUSART_CFG1_TXFIW_MASK))
                   | ((uint32_t)init->advanced_config->rx_fifo_watermark << _EUSART_CFG1_RXFIW_SHIFT)
                   | ((uint32_t)init->advanced_config->tx_fifo_watermark << _EUSART_CFG1_TXFIW_SHIFT)
#if defined(_EUSART_CFG1_RXDMAWU_SHIFT)
                   | ((uint32_t)init->advanced_config->dma_wakeup_on_rx << _EUSART_CFG1_RXDMAWU_SHIFT)
#endif
                   | ((uint32_t)init->advanced_config->prs_rx_enable << _EUSART_CFG1_RXPRSEN_SHIFT);

    eusart->CFG0 = (eusart->CFG0 & ~(_EUSART_CFG0_RXINV_MASK
                                     | _EUSART_CFG0_TXINV_MASK))
                   | (uint32_t)(init->advanced_config->invert_io << _EUSART_CFG0_RXINV_SHIFT);
    eusart->CFG0_SET = (uint32_t)init->advanced_config->msb_first << _EUSART_CFG0_MSBF_SHIFT;

    // Configure global configuration Timing register.
    eusart->TIMINGCFG = (eusart->TIMINGCFG & ~(_EUSART_TIMINGCFG_CSSETUP_MASK
                                               | _EUSART_TIMINGCFG_CSHOLD_MASK
                                               | _EUSART_TIMINGCFG_ICS_MASK
                                               | _EUSART_TIMINGCFG_SETUPWINDOW_MASK))
                        | ((uint32_t)(init->advanced_config->auto_cs_setup_time << _EUSART_TIMINGCFG_CSSETUP_SHIFT)
                           & _EUSART_TIMINGCFG_CSSETUP_MASK)
                        | ((uint32_t)(init->advanced_config->auto_cs_hold_time << _EUSART_TIMINGCFG_CSHOLD_SHIFT)
                           & _EUSART_TIMINGCFG_CSHOLD_MASK)
                        | ((uint32_t)(init->advanced_config->auto_inter_frame_time << _EUSART_TIMINGCFG_ICS_SHIFT)
                           & _EUSART_TIMINGCFG_ICS_MASK)
                        | ((uint32_t)(init->advanced_config->setup_window << _EUSART_TIMINGCFG_SETUPWINDOW_SHIFT)
                           & _EUSART_TIMINGCFG_SETUPWINDOW_MASK)
    ;

    eusart->DTXDATCFG = (init->advanced_config->default_tx_data & _EUSART_DTXDATCFG_MASK);
#if defined(SL_HAL_EUSART_PRS_SUPPORTED)
    if (init->advanced_config->prs_rx_enable) {
      // Configure PRS channel as input data line for EUSART.
      if (eusart == EUSART0) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART0_RX);
      }
#if defined(EUSART1)
      else if (eusart == EUSART1) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART1_RX);
      }
#endif
#if defined(EUSART2)
      else if (eusart == EUSART2) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART2_RX);
      }
#endif
#if defined(EUSART3)
      else if (eusart == EUSART3) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART3_RX);
      }
#endif
#if defined(EUSART4)
      else if (eusart == EUSART4) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_rx_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART4_RX);
      }
#endif
      else {
        EFM_ASSERT(false);
      }
    }

    if (init->advanced_config->prs_clock_enable) {
      // Configure PRS channel as SCLK input for EUSART.
      if (eusart == EUSART0) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_clock_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART0_CLK);
      }
#if defined(EUSART1)
      else if (eusart == EUSART1) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_clock_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART1_CLK);
      }
#endif
#if defined(EUSART2)
      else if (eusart == EUSART2) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_clock_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART2_CLK);
      }
#endif
#if defined(EUSART3)
      else if (eusart == EUSART3) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_clock_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART3_CLK);
      }
#endif
#if defined(EUSART4)
      else if (eusart == EUSART4) {
        sl_hal_prs_connect_channel_consumer(init->advanced_config->prs_clock_channel,
                                            SL_HAL_PRS_TYPE_ASYNC,
                                            SL_HAL_PRS_CONSUMER_EUSART4_CLK);
      }
#endif
      else {
        EFM_ASSERT(false);
      }
    }
#endif // #if defined(SL_HAL_EUSART_PRS_SUPPORTED)
  }
}
#endif

/***************************************************************************//**
 *  Map oversampling enum value to ovesampling real value.
 *
 * @param[in] ref_freq Peripheral clock frequency.
 * @param[in] baudrate Transmission speed.
 * @param[in] ovs Oversampling rate.
 *
 * @return Real ovesampling value.
 ******************************************************************************/
static uint8_t eusart_map_oversampling(uint32_t ref_freq,
                                       uint32_t baudrate,
                                       sl_hal_eusart_ovs_t ovs)
{
  uint8_t oversample = 0;
  // Map oversampling.
  switch (ovs) {
    case SL_HAL_EUSART_OVS_16:
      EFM_ASSERT(baudrate <= (ref_freq / 16));
      oversample = 16;
      break;

    case SL_HAL_EUSART_OVS_8:
      EFM_ASSERT(baudrate <= (ref_freq / 8));
      oversample = 8;
      break;

    case SL_HAL_EUSART_OVS_6:
      EFM_ASSERT(baudrate <= (ref_freq / 6));
      oversample = 6;
      break;

    case SL_HAL_EUSART_OVS_4:
      EFM_ASSERT(baudrate <= (ref_freq / 4));
      oversample = 4;
      break;

    case SL_HAL_EUSART_OVS_0:
      EFM_ASSERT(ref_freq >= (3 * baudrate));
      oversample = 1;
      break;

    default:
      // Invalid input
      EFM_ASSERT(0);
      break;
  }

  return oversample;
}
#endif /* defined(EUSART_PRESENT) */
