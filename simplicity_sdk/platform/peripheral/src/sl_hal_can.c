/***************************************************************************//**
 * @file
 * @brief CAN - Controller Area Network Flexible Data-Rate peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2026 Silicon Laboratories Inc. www.silabs.com</b>
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
#include "sl_hal_can.h"

#if defined(CAN_PRESENT)

#include <stddef.h>
#include "sl_common.h"

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/
#define CAN_REF_IS_VALID(ref)     (CAN_NUM(ref) != -1)

// Maximum interrupts supported.
#define CAN_MAX_INTERRUPT_LINE_SELECT_FLAGS        (_CAN_ILS_MASK)
#define CAN_MAX_INTERRUPT_FLAGS                    (_CAN_IE_MASK)

// Element mask Standard Identifier
#define CAN_STDID_ELEMENT_MASK ((uint32_t)0x1FFC0000U)

// CAN Error State Indicater. TEC/REC counter less than 128
#define CAN_ERROR_STATE_ACTIVE   127

// CAN module MRAM maximum size 8KB.
#define CAN_MESSAGE_RAM_SIZE 0x2000U

// Offset to safely read from Rx FIFO in overwrite mode.
#define CAN_RX_FIFO_SAFE_READ_OFFSET    0U

// Maximum number of message ID filters supported by the hardware.
#define CAN_MAX_MSG_FILTERS_STDID    128
#define CAN_MAX_MSG_FILTERS_EXTID    64

// Maximum number of Rx elements (FIFO + buffer) supported.
#define CAN_MAX_ELEMENTS_RX          64

// Maximum number of Tx-related elements (Tx buffers/fifo or Tx event FIFO).
#define CAN_MAX_ELEMENTS_TX          32

// Maximum data field size for all CAN message elements,
// Rx FIFO0, Rx FIFO1, Rx Buffer, and Tx elements.
#define CAN_MAX_CAN_DATA_FIELD_SIZE  7

/*******************************************************************************
 *****************************   LOCAL VARIABLES   *****************************
 ******************************************************************************/

// configured no of Rx buffers.
static uint8_t rx_buffers_number[CAN_COUNT];

// Convert element size to data length in byte.
static const uint8_t data_field_size[] = { 0x04, 0x05, 0x06, 0x07, 0x08, 0x0A, 0x0E, 0x12 };

/*******************************************************************************
 **************************   LOCAL FUNCTIONS   ********************************
 ******************************************************************************/
static void copy_message_to_ram(CAN_TypeDef *can,
                                const sl_hal_can_tx_frame_object_t *p_tx_object,
                                const uint8_t *p_tx_data,
                                uint32_t buffer_index);
static void can_operating_mode(CAN_TypeDef *can,
                               uint8_t mode);
static void can_standardID_filter_init(CAN_TypeDef *can,
                                       uint8_t no_of_std_filters);
static void can_extendedID_filter_init(CAN_TypeDef *can,
                                       uint8_t no_of_ext_filters);
static void can_rx_fifo_zero_init(CAN_TypeDef *can,
                                  uint8_t no_of_rx_fifo0,
                                  uint8_t rx_fifo0_elements_size);
static void can_rx_fifo_one_init(CAN_TypeDef *can,
                                 uint8_t no_of_rx_fifo1,
                                 uint8_t rx_fifo1_elements_size);
static void can_rx_buffer_init(CAN_TypeDef *can,
                               uint8_t no_of_rx_buffers,
                               uint8_t rx_buffer_size,
                               uint8_t index);
static void can_tx_events_fifo_init(CAN_TypeDef *can,
                                    uint8_t no_of_tx_events,
                                    uint8_t index);
static void can_tx_buffer_and_fifo_queue_init(CAN_TypeDef *can,
                                              uint8_t tx_fifo_queue_mode,
                                              uint8_t no_of_tx_buffers,
                                              uint8_t no_of_tx_fifos,
                                              uint8_t tx_element_size);
static void convert_dlc_to_data_length(uint8_t dlc,
                                       uint8_t *data_length);
/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/
extern __INLINE void sl_hal_can_enter_power_down_mode(CAN_TypeDef *can);
extern __INLINE void sl_hal_can_exit_power_down_mode(CAN_TypeDef *can);
extern __INLINE void sl_hal_can_config_global_filter(CAN_TypeDef *can,
                                                     sl_hal_can_non_matching_frames_t non_matching_std,
                                                     sl_hal_can_non_matching_frames_t non_matching_ext,
                                                     bool reject_remote_std,
                                                     bool reject_remote_ext);
extern __INLINE void sl_hal_can_config_extended_id_mask(CAN_TypeDef *can, uint32_t mask);
extern __INLINE void sl_hal_can_enable_timestamp_counter(CAN_TypeDef *can,
                                                         uint8_t time_stamp_operation,
                                                         uint8_t time_stamp_prescaler);
extern __INLINE void sl_hal_can_disable_timestamp_counter(CAN_TypeDef *can);
extern __INLINE void sl_hal_can_disable_timeout_counter(CAN_TypeDef *can);
extern __INLINE bool sl_hal_can_is_rx_buffer_messages_available(CAN_TypeDef *can,
                                                                uint8_t rx_buffer_index);
extern __INLINE uint32_t sl_hal_can_get_rx_fifo_fill_level(CAN_TypeDef *can,
                                                           sl_hal_can_rx_location_t rx_fifo);
/***************************************************************************//**
 * Sets the CAN Operating Mode
 ******************************************************************************/
static void can_operating_mode(CAN_TypeDef *can,
                               uint8_t mode)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(can);

  // Reset CAN Operation Mode.
  can->CCCR &= ~(CAN_CCCR_TEST | CAN_CCCR_MON | CAN_CCCR_ASM);
  can->TEST &= ~(CAN_TEST_LBCK);

  // Set CAN Operating Mode.
  switch (mode) {
    case SL_HAL_CAN_OPERATION_MODE_NORMAL:
      break;
    case SL_HAL_CAN_OPERATION_MODE_BUS_MONITORING:
      can->CCCR |= CAN_CCCR_MON;
      break;
    case SL_HAL_CAN_OPERATION_MODE_RESTRICTED:
      can->CCCR |= CAN_CCCR_ASM;
      break;
    case SL_HAL_CAN_OPERATION_MODE_INTERNAL_LOOPBACK:
      // Enable write access to TEST register.
      can->CCCR |= CAN_CCCR_TEST;
      // Enable LoopBack mode.
      can->TEST |= CAN_TEST_LBCK;
      can->CCCR |= CAN_CCCR_MON;
      break;
    case SL_HAL_CAN_OPERATION_MODE_EXTERNAL_LOOPBACK:
      // Enable write access to TEST register.
      can->CCCR |= CAN_CCCR_TEST;
      // Enable LoopBack mode.
      can->TEST |= CAN_TEST_LBCK;
      break;
  }
}

/***************************************************************************//**
* Convert DLC of the can frame into a payload length in byte
*******************************************************************************/
static void convert_dlc_to_data_length(uint8_t dlc,
                                       uint8_t *data_length)
{
  if (dlc <= 8) {
    *data_length = dlc;
  } else {
    switch (dlc) {
      case 9:
        *data_length = 12;
        break;
      case 10:
        *data_length = 16;
        break;
      case 11:
        *data_length = 20;
        break;
      case 12:
        *data_length = 24;
        break;
      case 13:
        *data_length = 32;
        break;
      case 14:
        *data_length = 48;
        break;
      case 15:
        *data_length = 64;
        break;
    }
  }
}

/***************************************************************************//**
 * Standard ID Filter Configuration controls the filter path for standard
 * messages
 ******************************************************************************/
static void can_standardID_filter_init(CAN_TypeDef *can,
                                       uint8_t std_filter_count)
{
  // Standard filter list start address and elements number.
  can->SIDFC = ((_CAN_SIDFC_FLSSA_DEFAULT) | ((std_filter_count) << _CAN_SIDFC_LSS_SHIFT));
}

/***************************************************************************//**
 * Extended ID Filter Configuration controls the filter path for extended
 * messages
 ******************************************************************************/
static void can_extendedID_filter_init(CAN_TypeDef *can,
                                       uint8_t ext_filter_count)
{
  uint32_t reg_sidfc;

  reg_sidfc = can->SIDFC;

  // Extended filter list start address and elements number.
  can->XIDFC = (((uint32_t)(reg_sidfc & _CAN_SIDFC_FLSSA_MASK)
                 + (((reg_sidfc & _CAN_SIDFC_LSS_MASK) >> _CAN_SIDFC_LSS_SHIFT) * 4))
                | (ext_filter_count << _CAN_XIDFC_LSE_SHIFT));
}

/***************************************************************************//**
 *  Initializing the Rx FIFO 0 receive buffer
 ******************************************************************************/
static void can_rx_fifo_zero_init(CAN_TypeDef *can,
                                  uint8_t rx_fifo0_count,
                                  uint8_t rx_fifo0_elements_size)
{
  uint32_t reg_xidfc;

  // Configure Rx FIFO 0 element size.
  if (rx_fifo0_count > 0U) {
    can->RXESC &= ~(_CAN_RXESC_F0DS_MASK);
    can->RXESC |= ((rx_fifo0_elements_size) << _CAN_RXESC_F0DS_SHIFT);
  }

  reg_xidfc = can->XIDFC;

  // Rx FIFO 0 start address and elements number.
  can->RXF0C = (((uint32_t)(reg_xidfc & _CAN_XIDFC_FLESA_MASK)
                 + (((reg_xidfc & _CAN_XIDFC_LSE_MASK) >> _CAN_XIDFC_LSE_SHIFT) * 2U * 4U))
                | (rx_fifo0_count << _CAN_RXF0C_F0S_SHIFT));
}

/***************************************************************************//**
 * Initializing the Rx FIFO 1 receive buffer
 ******************************************************************************/
static void can_rx_fifo_one_init(CAN_TypeDef *can,
                                 uint8_t rx_fifo1_count,
                                 uint8_t rx_fifo1_elements_size)
{
  uint32_t data_length;
  uint32_t reg_rxf0c;

  // Configure Rx FIFO 0 element size.
  if (rx_fifo1_count > 0U) {
    can->RXESC &= ~(_CAN_RXESC_F1DS_MASK);
    can->RXESC |= ((rx_fifo1_elements_size) << _CAN_RXESC_F1DS_SHIFT);
  }

  // Rx FIFO 1 start address and elements number.
  data_length = data_field_size[((can->RXESC & _CAN_RXESC_F0DS_MASK) >> _CAN_RXESC_F0DS_SHIFT)];
  reg_rxf0c = can->RXF0C;

  can->RXF1C = (((uint32_t)(reg_rxf0c & _CAN_RXF0C_F0SA_MASK)
                 + (((reg_rxf0c & _CAN_RXF0C_F0S_MASK) >> _CAN_RXF0C_F0S_SHIFT) * data_length * 4U))
                | (rx_fifo1_count << _CAN_RXF1C_F1S_SHIFT));
}

/***************************************************************************//**
 * Initializing the Rx receive buffer.
 ******************************************************************************/
static void can_rx_buffer_init(CAN_TypeDef *can,
                               uint8_t rx_buffer_count,
                               uint8_t rx_buffer_size,
                               uint8_t index)
{
  uint32_t data_length;
  uint32_t reg_rxf1c;

  // Configure Rx buffer element size.
  if (rx_buffer_count > 0U) {
    can->RXESC &= ~(_CAN_RXESC_RBDS_MASK);
    can->RXESC |= ((rx_buffer_size) << _CAN_RXESC_RBDS_SHIFT);
    // Keep track of the number of rx buffers.
    rx_buffers_number[index] = rx_buffer_count;
  }

  // Configuring rx buffer list start address.
  data_length = data_field_size[((can->RXESC & _CAN_RXESC_F1DS_MASK) >> _CAN_RXESC_F1DS_SHIFT)];
  reg_rxf1c = can->RXF1C;

  can->RXBC = ((uint32_t)(reg_rxf1c & _CAN_RXF1C_F1SA_MASK)
               + (((reg_rxf1c & _CAN_RXF1C_F1S_MASK) >> _CAN_RXF1C_F1S_SHIFT) * data_length * 4U));
}

/***************************************************************************//**
 * Initializing the tx event fifo
 ******************************************************************************/
static void can_tx_events_fifo_init(CAN_TypeDef *can,
                                    uint8_t tx_event_count,
                                    uint8_t index)
{
  uint32_t data_length;

  // Tx event FIFO start address and elements number.
  data_length = data_field_size[((can->RXESC & _CAN_RXESC_RBDS_MASK) >> _CAN_RXESC_RBDS_SHIFT)];

  can->TXEFC = (((uint32_t)(can->RXBC & _CAN_RXBC_RBSA_MASK)
                 + (rx_buffers_number[index] * data_length * 4U))
                | (tx_event_count << _CAN_TXEFC_EFS_SHIFT));
}

/***************************************************************************//**
 * Initializing the tx buffer and fifo queue
 ******************************************************************************/
static void can_tx_buffer_and_fifo_queue_init(CAN_TypeDef *can,
                                              uint8_t tx_fifo_queue_mode,
                                              uint8_t tx_buffer_count,
                                              uint8_t tx_fifo_count,
                                              uint8_t tx_element_size)
{
  uint32_t reg_txefc;

  if (tx_fifo_count > 0U) {
    // Select between Tx FIFO and Tx Queue operation modes.
    can->TXBC |= (tx_fifo_queue_mode << _CAN_TXBC_TFQM_SHIFT);
  }

  // Configure Tx element size.
  if ((tx_buffer_count + tx_fifo_count) > 0U) {
    can->TXESC &= ~(_CAN_TXESC_TBDS_MASK);
    can->TXESC = tx_element_size;
  }

  reg_txefc = can->TXEFC;

  // Tx buffer list start address and elements number.
  can->TXBC |= (((uint32_t)(reg_txefc & _CAN_TXEFC_EFSA_MASK)
                 + (((reg_txefc & _CAN_TXEFC_EFS_MASK) >> _CAN_TXEFC_EFS_SHIFT) * 2U * 4U))
                | (tx_buffer_count << _CAN_TXBC_NDTB_SHIFT)
                | (tx_fifo_count << _CAN_TXBC_TFQS_SHIFT));
}

/***************************************************************************//**
 * Initializes the CAN Device Peripheral.
 ******************************************************************************/
sl_status_t sl_hal_can_init(CAN_TypeDef *can,
                            const sl_hal_can_init_params_t *init)
{
  uint32_t status = SL_STATUS_OK;
  uint32_t ram_address;
  uint32_t ram_end_address;
  uint8_t  index;

  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Get CAN instance number.
  index = CAN_NUM(can);

  // Init structure must be provided.
  if (init == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

#if defined(CAN_CLKPEREN_CLKEN)
  // Enable clock for CAN peripheral.
  can->CLKPEREN = CAN_CLKPEREN_CLKEN;
#endif

  // Enable write access to the protected conﬁguration registers.
  can->CCCR |= CAN_CCCR_INIT;

  // Wait for initialization complete.
  while ((can->CCCR & CAN_CCCR_INIT) == 0) ;

  // Enable configuration change.
  can->CCCR |= CAN_CCCR_CCE;

  // Set the automatic retransmission.
  if (init->auto_retransmission == 1) {
    // Enable Automatic Retransmission.
    can->CCCR &= ~(CAN_CCCR_DAR);
  } else {
    // Disable Automatic Retransmission.
    can->CCCR |= CAN_CCCR_DAR;
  }

  // Configure transmit pauses for two CAN bit times before starting the next.
  if (init->transmit_pause == 0) {
    // Transmit Pause Disabled.
    can->CCCR &= ~(CAN_CCCR_TXP);
  } else {
    // Transmit Pause Enabled.
    can->CCCR |= CAN_CCCR_TXP;
  }

  // Configure the Protocol Exception Handling.
  if (init->protocol_exception == 0) {
    //Protocol Exception Handling Enabled.
    can->CCCR &= ~(CAN_CCCR_PXHD);
  } else {
    //Protocol Exception Handling Disabled.
    can->CCCR |= CAN_CCCR_PXHD;
  }

  // Set CAN Frame Format.
  // Clearing the bits BRSE and FDOE.
  can->CCCR &= (~(CAN_CCCR_FDOE | CAN_CCCR_BRSE));

  // Setting the bits BRSE and FDOE.
  if (init->fd_enable == SL_HAL_CAN_FD) {
    // The CAN FD Operation Enable.
    can->CCCR |= _CAN_CCCR_FDOE_MASK;
    if (init->brs_enable == SL_HAL_CAN_BRS_ON) {
      // The CAN Bit Rate Switch Enable.
      can->CCCR |= _CAN_CCCR_BRSE_MASK;
    } else {
      // The CAN Bit Rate Switch Disable.
      can->CCCR &= ~_CAN_CCCR_BRSE_MASK;
    }
  } else {
    // The CAN FD Operation Disable.
    can->CCCR &= ~_CAN_CCCR_FDOE_MASK;
  }

  // Check if the operating mode is valid.
  if ((init->mode != SL_HAL_CAN_OPERATION_MODE_EXTERNAL_LOOPBACK)
      && (init->mode != SL_HAL_CAN_OPERATION_MODE_INTERNAL_LOOPBACK)
      && (init->mode != SL_HAL_CAN_OPERATION_MODE_NORMAL)
      && (init->mode != SL_HAL_CAN_OPERATION_MODE_BUS_MONITORING)
      && (init->mode != SL_HAL_CAN_OPERATION_MODE_RESTRICTED)) {
    return SL_STATUS_INVALID_MODE;
  }
  // Configure the CAN Operating Mode.
  can_operating_mode(can, init->mode);

  if ((init->mram_init_params.std_filters_number > CAN_MAX_MSG_FILTERS_STDID)
      || (init->mram_init_params.ext_filters_number > CAN_MAX_MSG_FILTERS_EXTID)
      || ((init->mram_init_params.rx_fifo0_elements_number
           + init->mram_init_params.rx_fifo1_elements_number
           + init->mram_init_params.rx_buffers_number) > CAN_MAX_ELEMENTS_RX)
      || ((init->mram_init_params.tx_buffer_elements_number
           + init->mram_init_params.tx_fifo_elements_number) > CAN_MAX_ELEMENTS_TX)
      || (init->mram_init_params.tx_events_number > CAN_MAX_ELEMENTS_TX)
      || (init->mram_init_params.rx_fifo0_elements_size > CAN_MAX_CAN_DATA_FIELD_SIZE)
      || (init->mram_init_params.rx_fifo1_elements_size > CAN_MAX_CAN_DATA_FIELD_SIZE)
      || (init->mram_init_params.rx_buffer_size > CAN_MAX_CAN_DATA_FIELD_SIZE)
      || (init->mram_init_params.tx_element_size > CAN_MAX_CAN_DATA_FIELD_SIZE) ) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Initializing the standard ID filter.
  can_standardID_filter_init(can, init->mram_init_params.std_filters_number);

  // Initializing the extended ID filter.
  can_extendedID_filter_init(can, init->mram_init_params.ext_filters_number);

  // Initializing the Rx FIFO 0 receive buffer.
  can_rx_fifo_zero_init(can, init->mram_init_params.rx_fifo0_elements_number,
                        init->mram_init_params.rx_fifo0_elements_size);

  // Initializing the Rx FIFO 1 receive buffer.
  can_rx_fifo_one_init(can, init->mram_init_params.rx_fifo1_elements_number,
                       init->mram_init_params.rx_fifo1_elements_size);

  // Initializing the receive buffer.
  can_rx_buffer_init(can, init->mram_init_params.rx_buffers_number,
                     init->mram_init_params.rx_buffer_size, index);

  // Initializing the tx event fifo buffer.
  can_tx_events_fifo_init(can, init->mram_init_params.tx_events_number, index);

  // Initializing the tx buffer and fifo queue.
  can_tx_buffer_and_fifo_queue_init(can, init->tx_fifo_queue_mode,
                                    init->mram_init_params.tx_buffer_elements_number,
                                    init->mram_init_params.tx_fifo_elements_number,
                                    init->mram_init_params.tx_element_size);

  // CAN MRAM end address.
  ram_end_address = (uint32_t)(&can->MRAMAEIREG);
  ram_end_address += CAN_MESSAGE_RAM_SIZE;

  for (ram_address = ((uint32_t)(&can->MRAMAEIREG)); ram_address < ram_end_address; ram_address += 4U) {
    *(uint32_t *)(ram_address) = 0x00000000;
  }

  // Configure the CAN bit rate.
  status = sl_hal_can_set_bit_rate(can, init->nominal_bitrate, init->data_bitrate);

  return status;
}

/***************************************************************************//**
 * De-Initializes the CAN Device Peripheral.
 ******************************************************************************/
sl_status_t sl_hal_can_deinit(CAN_TypeDef *can)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Stop the CAN module.
  (void)sl_hal_can_stop(can);

  can->DBTP   = _CAN_DBTP_RESETVALUE;
  can->TEST   = _CAN_TEST_RESETVALUE;
  can->NBTP   = _CAN_NBTP_RESETVALUE;
  can->TSCC   = _CAN_TSCC_RESETVALUE;
  can->TSCV   = _CAN_TSCV_RESETVALUE;
  can->TOCC   = _CAN_TOCC_RESETVALUE;
  can->TOCV   = _CAN_TOCV_RESETVALUE;
  can->TDCR   = _CAN_TDCR_RESETVALUE;
  can->IE     = _CAN_IE_RESETVALUE;
  can->IR     = _CAN_IR_RESETVALUE;
  can->ILS    = _CAN_ILS_RESETVALUE;
  can->ILE    = _CAN_ILE_RESETVALUE;
  can->GFC    = _CAN_GFC_RESETVALUE;
  can->SIDFC  = _CAN_SIDFC_RESETVALUE;
  can->XIDFC  = _CAN_XIDFC_RESETVALUE;
  can->XIDAM  = _CAN_XIDAM_RESETVALUE;
  can->NDAT1  = _CAN_NDAT1_RESETVALUE;
  can->NDAT2  = _CAN_NDAT2_RESETVALUE;
  can->RXF0C  = _CAN_RXF0C_RESETVALUE;
  can->RXF0A  = _CAN_RXF0A_RESETVALUE;
  can->RXBC   = _CAN_RXBC_RESETVALUE;
  can->RXF1C  = _CAN_RXF1C_RESETVALUE;
  can->RXF1A  = _CAN_RXF1A_RESETVALUE;
  can->RXESC  = _CAN_RXESC_RESETVALUE;
  can->TXBC   = _CAN_TXBC_RESETVALUE;
  can->TXESC  = _CAN_TXESC_RESETVALUE;
  can->TXBAR  = _CAN_TXBAR_RESETVALUE;
  can->TXBCR  = _CAN_TXBCR_RESETVALUE;
  can->TXBTIE = _CAN_TXBTIE_RESETVALUE;
  can->TXBCIE = _CAN_TXBCIE_RESETVALUE;
  can->TXEFC  = _CAN_TXEFC_RESETVALUE;
  can->TXEFA  = _CAN_TXEFA_RESETVALUE;
  can->DMUI  = _CAN_DMUI_RESETVALUE;
  can->DMUQC  = _CAN_DMUQC_RESETVALUE;
  can->DMUIE  = _CAN_DMUIE_RESETVALUE;
  can->DMUC  = _CAN_DMUC_RESETVALUE;
  can->CCCR   = _CAN_CCCR_RESETVALUE;

  // Return function status.
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Set Nominal and Data Bit Timing
 ******************************************************************************/
sl_status_t sl_hal_can_set_bit_rate(CAN_TypeDef *can,
                                    sl_hal_can_bit_timing_t nominal_bitrate,
                                    sl_hal_can_bit_timing_t data_bitrate)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Set Bit Timing of CAN instance for Nominal Phase.
  can->NBTP = ((((uint32_t)nominal_bitrate.sync_jump_width) << _CAN_NBTP_NSJW_SHIFT)
               | (((uint32_t)nominal_bitrate.phase_seg1) << _CAN_NBTP_NTSEG1_SHIFT)
               | (((uint32_t)nominal_bitrate.phase_seg2) << _CAN_NBTP_NTSEG2_SHIFT)
               | (((uint32_t)nominal_bitrate.prescaler) << _CAN_NBTP_NBRP_SHIFT));

  // Set Bit Timing of CAN instance for Data Phase (if FD is enabled).
  if ((can->CCCR & _CAN_CCCR_BRSE_MASK) == _CAN_CCCR_BRSE_MASK) {
    // set the data bit timing register.
    can->DBTP = ((((uint32_t)data_bitrate.sync_jump_width) << _CAN_DBTP_DSJW_SHIFT)
                 | (((uint32_t)data_bitrate.phase_seg1) << _CAN_DBTP_DTSEG1_SHIFT)
                 | (((uint32_t)data_bitrate.phase_seg2) << _CAN_DBTP_DTSEG2_SHIFT)
                 | (((uint32_t)data_bitrate.prescaler) << _CAN_DBTP_DBRP_SHIFT));

#if defined(SL_HAL_CAN_TDC_ENABLED)
    // Configure TDC offset value.
    can->TDCR = (data_bitrate.phase_seg1 << _CAN_TDCR_TDCO_SHIFT);

    // Enable transmitter delay compensation.
    can->DBTP |= CAN_DBTP_TDC;
#endif
  }

  // Return error code.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 * Configure the CAN reception filter according to the specified parameters in the sl_hal_can_Filter_t structure.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_configure_filter(CAN_TypeDef *can,
                                        const sl_hal_can_filter_t *config_filter)
{
  uint32_t filter_element_word_one;
  uint32_t filter_element_word_two;
  uint32_t *filter_address;

  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Ensure that config_filter must be provided.
  if (config_filter == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  // Check function parameters.
  if (config_filter->id_type == SL_HAL_CAN_ID_STANDARD) {
    // Build filter element.
    if (config_filter->filter_config == SL_HAL_CAN_FILTER_TO_RXBUFFER) {
      filter_element_word_one = ((config_filter->filter_config << 27U)
                                 | (config_filter->filter_id_one << 16U)
                                 | config_filter->rx_buffer_index);
    } else {
      filter_element_word_one = ((config_filter->filter_type << 30U)
                                 | (config_filter->filter_config << 27U)
                                 | (config_filter->filter_id_one << 16U)
                                 | config_filter->filter_id_two);
    }

    // Calculate filter address.
    filter_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)) + (config_filter->filter_index * 4U));

    // Write filter element to the message RAM.
    *filter_address = filter_element_word_one;
  } else { // config_filter->id_type == SL_HAL_CAN_ID_EXTENDED.
    // Build first word of filter element.
    filter_element_word_one = ((config_filter->filter_config << 29U) | config_filter->filter_id_one);

    // Build second word of filter element.
    if (config_filter->filter_config == SL_HAL_CAN_FILTER_TO_RXBUFFER) {
      filter_element_word_two = config_filter->rx_buffer_index;
    } else {
      filter_element_word_two = ((config_filter->filter_type << 30U) | config_filter->filter_id_two);
    }

    // Calculate filter address.
    filter_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)
                                   + (can->XIDFC & _CAN_XIDFC_FLESA_MASK))
                                  + (config_filter->filter_index * 4U * 2U));

    // Write filter element to the message RAM.
    *filter_address = filter_element_word_one;
    filter_address++;
    *filter_address = filter_element_word_two;
  }

  // Return error code.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 * Remove the CAN reception filter .
 ********************************************************************************************************************/
sl_status_t sl_hal_can_remove_rx_filter(CAN_TypeDef *can,
                                        uint8_t id_type,
                                        uint8_t index)
{
  uint32_t *filter_start_address;

  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  if (id_type == SL_HAL_CAN_ID_STANDARD) {
    if (index < ((can->SIDFC & _CAN_SIDFC_LSS_MASK) >> _CAN_SIDFC_LSS_SHIFT)) {
      filter_start_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)) + (index * 4U));
      *filter_start_address = 0;
    } else {
      return SL_STATUS_INVALID_PARAMETER;
    }
  } else { // config_filter->id_type == SL_HAL_CAN_ID_EXTENDED.
    if (index < ((can->XIDFC & _CAN_XIDFC_LSE_MASK) >> _CAN_XIDFC_LSE_SHIFT)) {
      filter_start_address = (uint32_t *)((&can->MRAMAEIREG) + (can->XIDFC & _CAN_XIDFC_FLESA_MASK));
      filter_start_address = (uint32_t *)(filter_start_address + (index * 4U * 2U));
      *filter_start_address = 0;
      filter_start_address++;
      *filter_start_address = 0;
    } else {
      return SL_STATUS_INVALID_PARAMETER;
    }
  }
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 * Configure the Rx FIFO operation mode.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_config_rx_fifo_over_write(CAN_TypeDef *can,
                                                 sl_hal_can_rx_location_t rx_fifo,
                                                 uint8_t operation_mode)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  if (rx_fifo == SL_HAL_CAN_RX_FIFO0) {
    // Select FIFO 0 Operation Mode.
    can->RXF0C &= ~(CAN_RXF0C_F0OM);
    can->RXF0C |= (operation_mode << _CAN_RXF0C_F0OM_SHIFT);
  } else if (rx_fifo == SL_HAL_CAN_RX_FIFO1) {
    // Select FIFO 1 Operation Mode.
    can->RXF1C &= ~(CAN_RXF1C_F1OM);
    can->RXF1C |= (operation_mode << _CAN_RXF1C_F1OM_SHIFT);
  } else {
    // The RX buffer does not support blocking or overwrite mode.
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 * Configure the FIFO watermark.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_config_fifo_water_mark(CAN_TypeDef *can,
                                              sl_hal_can_fifo_watermark_t fifo,
                                              uint8_t water_mark)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Set the level for fifo water_mark interrupt.
  if (fifo == SL_HAL_CAN_CFG_TX_EVENT_FIFO) {
    can->TXEFC &= ~(_CAN_TXEFC_EFWM_MASK);
    can->TXEFC |= (water_mark << _CAN_TXEFC_EFWM_SHIFT);
  } else if (fifo == SL_HAL_CAN_CFG_RX_FIFO0) {
    can->RXF0C &= ~(_CAN_RXF0C_F0WM_MASK);
    can->RXF0C |= (water_mark << _CAN_RXF0C_F0WM_SHIFT);
  } else { // fifo == SL_HAL_CAN_CFG_RX_FIFO1.
    can->RXF1C &= ~(_CAN_RXF1C_F1WM_MASK);
    can->RXF1C |= (water_mark << _CAN_RXF1C_F1WM_SHIFT);
  }

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Start the CAN module.
 ********************************************************************************************************************/
void sl_hal_can_start(CAN_TypeDef *can)
{
  // Make sure the module exists on the selected chip.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Request leave initialisation.
  if ((can->CCCR & CAN_CCCR_INIT) == CAN_CCCR_INIT) {
    // Reset INIT bit to enter normal mode.
    can->CCCR &= ~CAN_CCCR_INIT;

    // Wait for initialization complete.
    while ((can->CCCR & CAN_CCCR_INIT) != 0) ;
  }
}

/*****************************************************************************************************************//**
 *  Stop the CAN module and enable access to configuration registers.
 ********************************************************************************************************************/
void sl_hal_can_stop(CAN_TypeDef *can)
{
  // Make sure the module exists on the selected chip.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Start CAN initialization,Enable write access to the protected conﬁguration registers.
  can->CCCR |= CAN_CCCR_INIT;

  // Wait for initialization complete.
  while ((can->CCCR & CAN_CCCR_INIT) == 0) ;

  // Enable configuration change.
  can->CCCR |= CAN_CCCR_CCE;
}

/*****************************************************************************************************************//**
 *  Add a message to the Tx FIFO/Queue and activate the corresponding transmission request
 ********************************************************************************************************************/
sl_status_t sl_hal_can_add_message_to_tx_fifo(CAN_TypeDef *can,
                                              sl_hal_can_tx_frame_object_t *p_tx_object,
                                              const uint8_t *p_tx_data)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Ensure that p_tx_object and p_tx_data parameters are valid.
  if ((p_tx_object == NULL) || (p_tx_data == NULL)) {
    return SL_STATUS_NULL_POINTER;
  }

  // Check function parameters.
  if (p_tx_object->id_type == SL_HAL_CAN_ID_STANDARD) {
    if (p_tx_object->identifier > 0x7FFU) {
      return SL_STATUS_INVALID_RANGE;
    }
  } else { // p_tx_object->IdType == SL_HAL_CAN_ID_EXTENDED.
    SL_LOG_DEBUG_ASSERT(p_tx_object->identifier <= 0x1FFFFFFFU);
  }

  // Check that the Tx FIFO/Queue has an allocated area into the RAM.
  if ((can->TXBC & _CAN_TXBC_TFQS_MASK) == 0U) {
    return SL_STATUS_ALLOCATION_FAILED;
  }

  if ((((can->ECR & _CAN_ECR_TEC_MASK) >> _CAN_ECR_TEC_SHIFT) <= CAN_ERROR_STATE_ACTIVE)
      && (((can->ECR & _CAN_ECR_REC_MASK) >> _CAN_ECR_REC_SHIFT) <= CAN_ERROR_STATE_ACTIVE)) {
    if (((can->ECR & _CAN_ECR_RP_MASK) >> _CAN_ECR_RP_SHIFT) == 0) {
      p_tx_object->error_state_indicator = SL_HAL_CAN_ESI_ACTIVE;
    } else {
      p_tx_object->error_state_indicator = SL_HAL_CAN_ESI_PASSIVE;
    }
  } else {
    p_tx_object->error_state_indicator = SL_HAL_CAN_ESI_PASSIVE;
  }

  // Check that the Tx FIFO/Queue is not full.
  if ((can->TXFQS & _CAN_TXFQS_TFQF_MASK) != 0U) {
    return SL_STATUS_FULL;
  } else {
    // Retrieve the Tx FIFO put_index.
    uint32_t put_index = ((can->TXFQS & _CAN_TXFQS_TFQPI_MASK) >> _CAN_TXFQS_TFQPI_SHIFT);

    // Check that the data length is valid.
    if (p_tx_object->data_length > 15) {
      return SL_STATUS_INVALID_PARAMETER;
    }

    // Add the message to the Tx FIFO/Queue.
    copy_message_to_ram(can, p_tx_object, p_tx_data, put_index);

    // Activate the corresponding transmission request.
    can->TXBAR = ((uint32_t)1 << put_index);
  }
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Add a message to a dedicated Tx buffer
 ********************************************************************************************************************/
sl_status_t sl_hal_can_add_message_to_tx_buffer(CAN_TypeDef *can,
                                                sl_hal_can_tx_frame_object_t *p_tx_object,
                                                const uint8_t *p_tx_data,
                                                uint8_t buffer_index)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Ensure that p_tx_object and p_tx_data parameters are valid.
  if ((p_tx_object == NULL) || (p_tx_data == NULL)) {
    return SL_STATUS_NULL_POINTER;
  }

  // Check function parameters.
  if (p_tx_object->id_type == SL_HAL_CAN_ID_STANDARD) {
    SL_LOG_DEBUG_ASSERT(p_tx_object->identifier <= 0x7FFU);
  } else { // p_tx_object->id_type == SL_HAL_CAN_ID_EXTENDED.
    SL_LOG_DEBUG_ASSERT(p_tx_object->identifier <= 0x1FFFFFFFU);
  }

  // Check that the selected buffer has an allocated area into the RAM.
  if (buffer_index >= ((can->TXBC & _CAN_TXBC_NDTB_MASK) >> _CAN_TXBC_NDTB_SHIFT)) {
    return SL_STATUS_ALLOCATION_FAILED;
  }

  if ((((can->ECR & _CAN_ECR_TEC_MASK) >> _CAN_ECR_TEC_SHIFT) <= CAN_ERROR_STATE_ACTIVE)
      && (((can->ECR & _CAN_ECR_REC_MASK) >> _CAN_ECR_REC_SHIFT) <= CAN_ERROR_STATE_ACTIVE)) {
    if (((can->ECR & _CAN_ECR_RP_MASK) >> _CAN_ECR_RP_SHIFT) == 0) {
      p_tx_object->error_state_indicator = SL_HAL_CAN_ESI_ACTIVE;
    } else {
      p_tx_object->error_state_indicator = SL_HAL_CAN_ESI_PASSIVE;
    }
  } else {
    p_tx_object->error_state_indicator = SL_HAL_CAN_ESI_PASSIVE;
  }

  // Check that there is no transmission request pending for the selected buffer.
  if ((can->TXBRP & ((uint32_t)1 << buffer_index)) != 0U) {
    return SL_STATUS_TRANSMIT_BUSY;
  } else {
    // Check that the data length is valid.
    if (p_tx_object->data_length > 15) {
      return SL_STATUS_INVALID_PARAMETER;
    }

    // Add the message to the Tx buffer.
    copy_message_to_ram(can, p_tx_object, p_tx_data, buffer_index);

    // Enable transmission request.
    can->TXBAR = (can->TXBAR | ((uint32_t)1 << buffer_index));
  }

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Cancel a Tx buffer transmission request
 ********************************************************************************************************************/
sl_status_t sl_hal_can_request_abort_tx(CAN_TypeDef *can,
                                        uint32_t buffer_index)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Add cancellation request.
  can->TXBCR = (can->TXBCR | (buffer_index));

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Get an CAN frame from the Rx Buffer/FIFO location.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_get_rx_message(CAN_TypeDef *can,
                                      sl_hal_can_rx_location_t rx_location,
                                      uint8_t buffer_index,
                                      sl_hal_can_rx_frame_object_t *p_rx_object,
                                      uint8_t *p_rx_data)
{
  uint32_t *rx_address;
  uint8_t  *p_data;
  uint32_t get_index = 0;
  uint32_t data_length;
  uint8_t  data_bytes;
  uint8_t  index;

  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Get CAN instance number
  index = CAN_NUM(can);

  if (rx_location == SL_HAL_CAN_RX_FIFO0) {     // Rx element is assigned to the Rx FIFO 0.
    // Check that the Rx FIFO 0 has an allocated area into the RAM.
    if ((can->RXF0C & _CAN_RXF0C_F0S_MASK) == 0U) {
      return SL_STATUS_ALLOCATION_FAILED;
    }

    // Check that the Rx FIFO 0 is not empty.
    if ((can->RXF0S & _CAN_RXF0S_F0FL_MASK) == 0U) {
      return SL_STATUS_EMPTY;
    } else {
      // Check that the Rx FIFO 0 is full & overwrite mode is on.
      if (((can->RXF0S & _CAN_RXF0S_F0F_MASK) >> _CAN_RXF0S_F0F_SHIFT) == 1U) {
        if (((can->RXF0C & _CAN_RXF0C_F0OM_MASK) >> _CAN_RXF0C_F0OM_SHIFT) == SL_HAL_CAN_RX_FIFO_OVERWRITE) {
          // When overwrite status is on discard first message in FIFO.
          get_index = CAN_RX_FIFO_SAFE_READ_OFFSET;
        }
      }
      // Calculate Rx FIFO 0 element index.
      get_index += ((can->RXF0S & _CAN_RXF0S_F0GI_MASK) >> _CAN_RXF0S_F0GI_SHIFT);

      // Calculate Rx FIFO 0 element address.
      data_length = data_field_size[((can->RXESC & _CAN_RXESC_F0DS_MASK) >> _CAN_RXESC_F0DS_SHIFT)];
      rx_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)
                                 + (can->RXF0C & _CAN_RXF0C_F0SA_MASK))
                                + (get_index * data_length * 4U));
    }
  } else if (rx_location == SL_HAL_CAN_RX_FIFO1) { // Rx element is assigned to the Rx FIFO 1.
    // Check that the Rx FIFO 1 has an allocated area into the RAM.
    if ((can->RXF1C & _CAN_RXF1C_F1S_MASK) == 0U) {
      return SL_STATUS_ALLOCATION_FAILED;
    }

    // Check that the Rx FIFO 0 is not empty.
    if ((can->RXF1S & _CAN_RXF1S_F1FL_MASK) == 0U) {
      return SL_STATUS_EMPTY;
    } else {
      // Check that the Rx FIFO 1 is full & overwrite mode is on.
      if (((can->RXF1S & _CAN_RXF1S_F1F_MASK) >> _CAN_RXF1S_F1F_SHIFT) == 1U) {
        if (((can->RXF1C & _CAN_RXF1C_F1OM_MASK) >> _CAN_RXF1C_F1OM_SHIFT) == SL_HAL_CAN_RX_FIFO_OVERWRITE) {
          // When overwrite status is on discard first message in FIFO.
          get_index = CAN_RX_FIFO_SAFE_READ_OFFSET;
        }
      }

      // Calculate Rx FIFO 1 element index.
      get_index += ((can->RXF1S & _CAN_RXF1S_F1GI_MASK) >> _CAN_RXF1S_F1GI_SHIFT);

      // Calculate Rx FIFO 1 element address.
      data_length = data_field_size[((can->RXESC & _CAN_RXESC_F1DS_MASK) >> _CAN_RXESC_F1DS_SHIFT)];
      rx_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)
                                 + (can->RXF1C & _CAN_RXF1C_F1SA_MASK))
                                + (get_index * data_length * 4U));
    }
  } else { // Rx element is assigned to a dedicated Rx buffer.
           // Check that the selected buffer has an allocated area into the RAM.
    if (buffer_index >= rx_buffers_number[index]) {
      return SL_STATUS_ALLOCATION_FAILED;
    } else {
      // Calculate Rx buffer address.
      data_length = data_field_size[((can->RXESC & _CAN_RXESC_RBDS_MASK) >> _CAN_RXESC_RBDS_SHIFT)];
      rx_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)
                                 + (can->RXBC & _CAN_RXBC_RBSA_MASK))
                                + (buffer_index * data_length * 4U));
    }
  }

  p_rx_object->word[0] = *rx_address;
  rx_address++;
  p_rx_object->word[1] = *rx_address;

  // Retrieve identifier.
  if (p_rx_object->id_type == SL_HAL_CAN_ID_STANDARD) {   /* Standard ID element */
    p_rx_object->identifier = ((p_rx_object->word[0] & CAN_STDID_ELEMENT_MASK) >> 18);
  }

  // Increment rx_address pointer to payload of Rx FIFO element.
  rx_address++;

  // Retrieve Rx payload.
  p_data = (uint8_t *)rx_address;

  // Check that the data length is valid.
  if (p_rx_object->data_length > 15) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  // Get the data length in byte.
  convert_dlc_to_data_length(p_rx_object->data_length, &data_bytes);

  for (uint8_t byte_counter = 0; byte_counter < data_bytes; byte_counter++) {
    p_rx_data[byte_counter] = p_data[byte_counter];
  }

  if (rx_location == SL_HAL_CAN_RX_FIFO0) {   // Rx element is assigned to the Rx FIFO 0.
    // Acknowledge the Rx FIFO 0 that the oldest element is read so that it increments the get_index.
    can->RXF0A = get_index;
  } else if (rx_location == SL_HAL_CAN_RX_FIFO1) { /* Rx element is assigned to the Rx FIFO 1 */
    // Acknowledge the Rx FIFO 1 that the oldest element is read so that it increments the get_index.
    can->RXF1A = get_index;
  } else { // Rx element is assigned to a dedicated Rx buffer.
           // Clear the New Data flag of the current Rx buffer.
    if (buffer_index < 32) {
      can->NDAT1 = ((uint32_t)1 << buffer_index);
    } else { // 32 <= buffer_index <= 63.
      can->NDAT2 = ((uint32_t)1 << (buffer_index & 0x1FU));
    }
  }

  // Return function status
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Get an CAN Tx event from the Tx Event FIFO zone into the message RAM.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_get_tx_event(CAN_TypeDef *can,
                                    sl_hal_can_tx_event_object_t *p_tx_event)
{
  uint32_t *tx_event_address;
  uint32_t get_index;

  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Check that the Tx Event FIFO has an allocated area into the RAM.
  if ((can->TXEFC & _CAN_TXEFC_EFS_MASK) == 0U) {
    return SL_STATUS_ALLOCATION_FAILED;
  }

  // Check that the Tx event FIFO is not empty.
  if ((can->TXEFS & _CAN_TXEFS_EFFL_MASK) == 0U) {
    return SL_STATUS_EMPTY;
  }

  // Calculate Tx event FIFO element address
  get_index = ((can->TXEFS & _CAN_TXEFS_EFGI_MASK) >> _CAN_TXEFS_EFGI_SHIFT);

  // Calculate RAM address where Tx Event FIFO element is located, that should be read now.
  tx_event_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)
                                   + (can->TXEFC & _CAN_TXEFC_EFSA_MASK))
                                  + (get_index * 2U * 4U));

  p_tx_event->word[0] = *tx_event_address;
  tx_event_address++;
  p_tx_event->word[1] = *tx_event_address;

  // Retrieve identifier.
  if (p_tx_event->id_type == SL_HAL_CAN_ID_STANDARD) {   /* Standard ID element */
    p_tx_event->identifier = ((p_tx_event->word[0] & CAN_STDID_ELEMENT_MASK) >> 18U);
  }

  // Acknowledge the Tx Event FIFO that the oldest element is read so that it increments the get_index.
  can->TXEFA = get_index;

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Get high priority message status.
 ********************************************************************************************************************/
void sl_hal_can_get_hpm_status(CAN_TypeDef *can,
                               sl_hal_can_hpm_status_t *hpm_msg_status)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Get high priority message status.
  hpm_msg_status->filter_list = ((can->HPMS & _CAN_HPMS_FLST_MASK) >> _CAN_HPMS_FLST_SHIFT);
  hpm_msg_status->filter_index = ((can->HPMS & _CAN_HPMS_FIDX_MASK) >> _CAN_HPMS_FIDX_SHIFT);
  hpm_msg_status->hpm_storage = (can->HPMS & _CAN_HPMS_MSI_MASK);
  hpm_msg_status->message_index = (can->HPMS & _CAN_HPMS_BIDX_MASK);
}

/*****************************************************************************************************************//**
 *  Get protocol status.
 ********************************************************************************************************************/
void sl_hal_can_get_protocol_status(CAN_TypeDef *can,
                                    sl_hal_can_protocol_status_t *protocol_status)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Fill the protocol status structure.
  protocol_status->last_error_code = (can->PSR & _CAN_PSR_LEC_MASK);
  protocol_status->data_last_error_code = ((can->PSR & _CAN_PSR_DLEC_MASK) >> _CAN_PSR_DLEC_SHIFT);
  protocol_status->activity = (can->PSR & _CAN_PSR_ACT_MASK);
  protocol_status->error_passive = ((can->PSR & _CAN_PSR_EP_MASK) >> _CAN_PSR_EP_SHIFT);
  protocol_status->warning = ((can->PSR & _CAN_PSR_EW_MASK) >> _CAN_PSR_EW_SHIFT);
  protocol_status->bus_off = ((can->PSR & _CAN_PSR_BO_MASK) >> _CAN_PSR_BO_SHIFT);
  protocol_status->rx_esi_flag = ((can->PSR & _CAN_PSR_RESI_MASK) >> _CAN_PSR_RESI_SHIFT);
  protocol_status->rx_brs_flag = ((can->PSR & _CAN_PSR_RBRS_MASK) >> _CAN_PSR_RBRS_SHIFT);
  protocol_status->rx_fdf_flag = ((can->PSR & _CAN_PSR_RFDF_MASK) >> _CAN_PSR_RFDF_SHIFT);
  protocol_status->protocol_exception = ((can->PSR & _CAN_PSR_PXE_MASK) >> _CAN_PSR_PXE_SHIFT);
  protocol_status->tdc_value = ((can->PSR & _CAN_PSR_TDCV_MASK) >> _CAN_PSR_TDCV_SHIFT);
}

/*****************************************************************************************************************//**
 * Enable the timeout counter.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_enable_timeout_counter(CAN_TypeDef *can,
                                              sl_hal_can_timeout_operation_t timeout_operation,
                                              uint32_t timeout_period,
                                              uint8_t time_stamp_prescaler)
{
// Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Check parameters are valid.
  if ((time_stamp_prescaler > 15U) || (timeout_period > 0xFFFFU)) {
    return SL_STATUS_INVALID_RANGE;
  }

  if (timeout_operation > SL_HAL_CAN_TIMEOUT_RX_FIFO1) {
    return SL_STATUS_INVALID_TYPE;
  }

// Select timeout operation and configure period.
  can->TOCC  = _CAN_TOCC_RESETVALUE;
  can->TOCC |= (timeout_operation << _CAN_TOCC_TOS_SHIFT);
  can->TOCC |= (timeout_period << _CAN_TOCC_TOP_SHIFT);

// Configure prescaler.
  can->TSCC &= ~(_CAN_TSCC_TCP_MASK);
  can->TSCC |= (time_stamp_prescaler << _CAN_TSCC_TCP_SHIFT);

// Enable timeout counter.
  can->TOCC |= CAN_TOCC_ETOC;

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Enable interrupts.
 ********************************************************************************************************************/
void sl_hal_can_enable_interrupts(CAN_TypeDef *can,
                                  uint32_t flag,
                                  uint32_t interrupt_line)
{
  // Make sure the module exists on the selected chip.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Assert on invalid flags.
  SL_LOG_DEBUG_ASSERT(!(flag & ~CAN_MAX_INTERRUPT_FLAGS));
  SL_LOG_DEBUG_ASSERT(!(interrupt_line & ~CAN_MAX_INTERRUPT_LINE_SELECT_FLAGS));

  can->ILS = interrupt_line;
  while (can->ILS != interrupt_line) ;
  // Enable Interrupt lines
  if (can->ILS == _CAN_ILS_RESETVALUE) {
    // Enable Interrupt line 0.
    can->ILE |= CAN_ILE_EINT0;
  } else if (can->ILS == _CAN_ILS_MASK) {
    // Enable Interrupt line 1.
    can->ILE |= CAN_ILE_EINT1;
  } else {
    // Enable Interrupt lines 0 and 1.
    can->ILE = (CAN_ILE_EINT0 | CAN_ILE_EINT1);
  }
  if ((flag & CAN_IE_TCE) != 0U) {
    // Enable Tx Buffer Transmission Interrupt to set TC flag in IR register,
    // but interrupt will only occur if TC is enabled in IE register.
    can->TXBTIE |= 0xFFFFFFFF;
  }
  if ((flag & CAN_IE_TCFE) != 0U) {
    // Enable Tx Buffer Cancellation Finished Interrupt to set TCF flag in IR register,
    //  but interrupt will only occur if TCF is enabled in IE register.
    can->TXBCIE |= 0xFFFFFFFF;
  }
  // Enable the selected interrupts.
  can->IE |= (flag & _CAN_IR_MASK);
}

/*****************************************************************************************************************//**
 *  Disable interrupts.
 ********************************************************************************************************************/
void sl_hal_can_disable_interrupts(CAN_TypeDef *can,
                                   uint32_t flag)
{
  uint32_t reg_ie;
  uint32_t reg_ils;

  // Make sure the module exists on the selected chip.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Assert on invalid flags.
  SL_LOG_DEBUG_ASSERT(!(flag & ~CAN_MAX_INTERRUPT_FLAGS));

  // Disable the selected interrupts.
  can->IE &= ~(flag & _CAN_IR_MASK);

  if ((flag & CAN_IE_TCE) != 0U) {
    // Disable Tx Buffer Transmission Interrupts.
    can->TXBTIE = 0U;
  }

  if ((flag & CAN_IE_TCFE) != 0U) {
    // Disable Tx Buffer Cancellation Finished Interrupt.
    can->TXBCIE = 0U;
  }

  reg_ie = can->IE;
  reg_ils = can->ILS;

  if ((reg_ie | reg_ils) == reg_ils) {
    // Disable Interrupt line 0.
    can->ILE &= ~CAN_ILE_EINT0;
  }

  if ((reg_ie & reg_ils) == 0U) {
    // Disable Interrupt line 1.
    can->ILE &= ~CAN_ILE_EINT1;
  }
}

/*****************************************************************************************************************//**
 *  Copy Tx message to the message RAM.
 ********************************************************************************************************************/
static void copy_message_to_ram(CAN_TypeDef *can,
                                const sl_hal_can_tx_frame_object_t *p_tx_object,
                                const uint8_t *p_tx_data,
                                uint32_t buffer_index)
{
  uint32_t tx_element_word_one;
  uint32_t tx_element_word_two;
  uint32_t *tx_address;
  uint8_t data_bytes;
  uint8_t data_length;

  // Convert the message data length into byte.
  data_length = data_field_size[can->TXESC & _CAN_TXESC_TBDS_MASK];

  // Get the data length in byte.
  convert_dlc_to_data_length(p_tx_object->data_length, &data_bytes);

  // Calculate Tx element address.
  tx_address = (uint32_t *)(((uint32_t)(&can->MRAMAEIREG)
                             + (can->TXBC & _CAN_TXBC_TBSA_MASK))
                            + (buffer_index * data_length * 4U));

  // Build first word of Tx header element.
  if (p_tx_object->id_type == SL_HAL_CAN_ID_STANDARD) {
    tx_element_word_one = ((p_tx_object->error_state_indicator << 31)
                           | (p_tx_object->id_type << 30)
                           | (p_tx_object->frame_type << 29)
                           | (p_tx_object->identifier << 18));
  } else {
    tx_element_word_one = p_tx_object->word[0];
  }
  tx_element_word_two = p_tx_object->word[1];

  // Write Tx element header to the message RAM.
  *tx_address++ = tx_element_word_one;
  *tx_address++ = tx_element_word_two;

  // Fallback to manual copy.
  for (uint32_t byte_counter = 0; byte_counter < data_bytes; byte_counter += 4U) {
    *tx_address = (((uint32_t)p_tx_data[byte_counter + 3U] << 24)
                   | ((uint32_t)p_tx_data[byte_counter + 2U] << 16)
                   | ((uint32_t)p_tx_data[byte_counter + 1U] << 8)
                   | (uint32_t)p_tx_data[byte_counter]);
    tx_address++;
  }
}

/*****************************************************************************************************************//**
 *  Enable interrupts.
 ********************************************************************************************************************/
void sl_hal_can_enable_dmu_interrupts(CAN_TypeDef *can,
                                      uint32_t flag)
{
  // Make sure the module exists on the selected chip.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  SL_LOG_DEBUG_ASSERT(!(flag & ~_CAN_DMUIR_MASK));

  // Enable the selected interrupts.
  can->DMUIE |= (flag & _CAN_DMUIR_MASK);
}

/*****************************************************************************************************************//**
 *  Disable interrupts.
 ********************************************************************************************************************/
void sl_hal_can_disable_dmu_interrupts(CAN_TypeDef *can,
                                       uint32_t flag)
{
  // Make sure the module exists on the selected chip.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  SL_LOG_DEBUG_ASSERT(!(flag & ~_CAN_DMUIR_MASK));

  // Enable the selected interrupts.
  can->DMUIE &= ~(flag & _CAN_DMUIR_MASK);
}

/*****************************************************************************************************************//**
 *  The DMU supports the transfer of TSU timestamps via DMU Virtual Buffer
 ********************************************************************************************************************/
sl_status_t sl_hal_can_enable_dmu_timestamp(CAN_TypeDef *can,
                                            bool value)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // configure for the Transfer Time stamp TTS.
  can->DMUC = value;

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Get the every queueing count value for each DMU element separately
 ********************************************************************************************************************/
sl_status_t sl_hal_can_get_dmu_queueing_counter(CAN_TypeDef *can,
                                                uint8_t *dmu_tx_counter,
                                                uint8_t *dmu_rx0_counter,
                                                uint8_t *dmu_rx1_counter,
                                                uint8_t *dmu_tx_event_counter)
{
  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  *dmu_tx_event_counter = ((can->DMUQC & _CAN_DMUQC_TXEEDC_MASK) >> _CAN_DMUQC_TXEEDC_SHIFT);
  *dmu_rx1_counter = ((can->DMUQC & _CAN_DMUQC_RX1EDC_MASK) >> _CAN_DMUQC_RX1EDC_SHIFT);
  *dmu_rx0_counter = ((can->DMUQC & _CAN_DMUQC_RX0EDC_MASK) >> _CAN_DMUQC_RX0EDC_SHIFT);
  *dmu_tx_counter =  (can->DMUQC & _CAN_DMUQC_TXEEC_MASK);

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Define the DMU element services used for debugging.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_configure_dmu_element_service(CAN_TypeDef *can,
                                                     bool value,
                                                     sl_hal_can_dmu_element_service_t element)
{
  uint32_t service_reg;

  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Configure the DMU element services.
  service_reg = can->DMUI;

  switch (element) {
    case SL_HAL_CAN_DMU_SERVICE_TX:
      service_reg = ((service_reg & ~_CAN_DMUI_DTX_MASK) | (value << _CAN_DMUI_DTX_SHIFT));
      break;
    case SL_HAL_CAN_DMU_SERVICE_RX0:
      service_reg = ((service_reg & ~_CAN_DMUI_DRX0_MASK) | (value << _CAN_DMUI_DRX0_SHIFT));
      break;
    case SL_HAL_CAN_DMU_SERVICE_RX1:
      service_reg = ((service_reg & ~_CAN_DMUI_DRX1_MASK) | (value << _CAN_DMUI_DRX1_SHIFT));
      break;
    case SL_HAL_CAN_DMU_SERVICE_TX_EVENT:
      service_reg = ((service_reg & ~_CAN_DMUI_DTXE_MASK) | (value << _CAN_DMUI_DTXE_SHIFT));
      break;
    default:
      return SL_STATUS_INVALID_PARAMETER;
  }

  can->DMUI = service_reg;

  // Return function status.
  return SL_STATUS_OK;
}

/*****************************************************************************************************************//**
 *  Configure the DMU element handler state for debugging.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_configure_dmu_handler_state(CAN_TypeDef *can,
                                                   sl_hal_can_dmu_handler_state_t value)
{
  uint32_t service_reg;

  // Make sure the module exists on the selected chip.
  if (!CAN_REF_IS_VALID(can)) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  // Configure the DMU t element handler state.
  service_reg = can->DMUI;

  service_reg = ((service_reg & ~_CAN_DMUI_DEHS_MASK)
                 | (((uint32_t)value << _CAN_DMUI_DEHS_SHIFT) & _CAN_DMUI_DEHS_MASK));

  can->DMUI = service_reg;

  // Return function status.
  return SL_STATUS_OK;
}

#endif /* defined(CAN_PRESENT) */
