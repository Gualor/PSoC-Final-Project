/*******************************************************************************
* File Name: SPIM_EEPROM.h
* Version 2.50
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Master Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_SPIM_EEPROM_H)
#define CY_SPIM_SPIM_EEPROM_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define SPIM_EEPROM_INTERNAL_CLOCK             (1u)

#if(0u != SPIM_EEPROM_INTERNAL_CLOCK)
    #include "SPIM_EEPROM_IntClock.h"
#endif /* (0u != SPIM_EEPROM_INTERNAL_CLOCK) */

#define SPIM_EEPROM_MODE                       (1u)
#define SPIM_EEPROM_DATA_WIDTH                 (8u)
#define SPIM_EEPROM_MODE_USE_ZERO              (1u)
#define SPIM_EEPROM_BIDIRECTIONAL_MODE         (0u)

/* Internal interrupt handling */
#define SPIM_EEPROM_TX_BUFFER_SIZE             (8u)
#define SPIM_EEPROM_RX_BUFFER_SIZE             (8u)
#define SPIM_EEPROM_INTERNAL_TX_INT_ENABLED    (1u)
#define SPIM_EEPROM_INTERNAL_RX_INT_ENABLED    (1u)

#define SPIM_EEPROM_SINGLE_REG_SIZE            (8u)
#define SPIM_EEPROM_USE_SECOND_DATAPATH        (SPIM_EEPROM_DATA_WIDTH > SPIM_EEPROM_SINGLE_REG_SIZE)

#define SPIM_EEPROM_FIFO_SIZE                  (4u)
#define SPIM_EEPROM_TX_SOFTWARE_BUF_ENABLED    ((0u != SPIM_EEPROM_INTERNAL_TX_INT_ENABLED) && \
                                                     (SPIM_EEPROM_TX_BUFFER_SIZE > SPIM_EEPROM_FIFO_SIZE))

#define SPIM_EEPROM_RX_SOFTWARE_BUF_ENABLED    ((0u != SPIM_EEPROM_INTERNAL_RX_INT_ENABLED) && \
                                                     (SPIM_EEPROM_RX_BUFFER_SIZE > SPIM_EEPROM_FIFO_SIZE))


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint8 cntrPeriod;
} SPIM_EEPROM_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SPIM_EEPROM_Init(void)                           ;
void  SPIM_EEPROM_Enable(void)                         ;
void  SPIM_EEPROM_Start(void)                          ;
void  SPIM_EEPROM_Stop(void)                           ;

void  SPIM_EEPROM_EnableTxInt(void)                    ;
void  SPIM_EEPROM_EnableRxInt(void)                    ;
void  SPIM_EEPROM_DisableTxInt(void)                   ;
void  SPIM_EEPROM_DisableRxInt(void)                   ;

void  SPIM_EEPROM_Sleep(void)                          ;
void  SPIM_EEPROM_Wakeup(void)                         ;
void  SPIM_EEPROM_SaveConfig(void)                     ;
void  SPIM_EEPROM_RestoreConfig(void)                  ;

void  SPIM_EEPROM_SetTxInterruptMode(uint8 intSrc)     ;
void  SPIM_EEPROM_SetRxInterruptMode(uint8 intSrc)     ;
uint8 SPIM_EEPROM_ReadTxStatus(void)                   ;
uint8 SPIM_EEPROM_ReadRxStatus(void)                   ;
void  SPIM_EEPROM_WriteTxData(uint8 txData)  \
                                                            ;
uint8 SPIM_EEPROM_ReadRxData(void) \
                                                            ;
uint8 SPIM_EEPROM_GetRxBufferSize(void)                ;
uint8 SPIM_EEPROM_GetTxBufferSize(void)                ;
void  SPIM_EEPROM_ClearRxBuffer(void)                  ;
void  SPIM_EEPROM_ClearTxBuffer(void)                  ;
void  SPIM_EEPROM_ClearFIFO(void)                              ;
void  SPIM_EEPROM_PutArray(const uint8 buffer[], uint8 byteCount) \
                                                            ;

#if(0u != SPIM_EEPROM_BIDIRECTIONAL_MODE)
    void  SPIM_EEPROM_TxEnable(void)                   ;
    void  SPIM_EEPROM_TxDisable(void)                  ;
#endif /* (0u != SPIM_EEPROM_BIDIRECTIONAL_MODE) */

CY_ISR_PROTO(SPIM_EEPROM_TX_ISR);
CY_ISR_PROTO(SPIM_EEPROM_RX_ISR);


/***************************************
*   Variable with external linkage
***************************************/

extern uint8 SPIM_EEPROM_initVar;


/***************************************
*           API Constants
***************************************/

#define SPIM_EEPROM_TX_ISR_NUMBER     ((uint8) (SPIM_EEPROM_TxInternalInterrupt__INTC_NUMBER))
#define SPIM_EEPROM_RX_ISR_NUMBER     ((uint8) (SPIM_EEPROM_RxInternalInterrupt__INTC_NUMBER))

#define SPIM_EEPROM_TX_ISR_PRIORITY   ((uint8) (SPIM_EEPROM_TxInternalInterrupt__INTC_PRIOR_NUM))
#define SPIM_EEPROM_RX_ISR_PRIORITY   ((uint8) (SPIM_EEPROM_RxInternalInterrupt__INTC_PRIOR_NUM))


/***************************************
*    Initial Parameter Constants
***************************************/

#define SPIM_EEPROM_INT_ON_SPI_DONE    ((uint8) (0u   << SPIM_EEPROM_STS_SPI_DONE_SHIFT))
#define SPIM_EEPROM_INT_ON_TX_EMPTY    ((uint8) (0u   << SPIM_EEPROM_STS_TX_FIFO_EMPTY_SHIFT))
#define SPIM_EEPROM_INT_ON_TX_NOT_FULL ((uint8) (1u << \
                                                                           SPIM_EEPROM_STS_TX_FIFO_NOT_FULL_SHIFT))
#define SPIM_EEPROM_INT_ON_BYTE_COMP   ((uint8) (0u  << SPIM_EEPROM_STS_BYTE_COMPLETE_SHIFT))
#define SPIM_EEPROM_INT_ON_SPI_IDLE    ((uint8) (0u   << SPIM_EEPROM_STS_SPI_IDLE_SHIFT))

/* Disable TX_NOT_FULL if software buffer is used */
#define SPIM_EEPROM_INT_ON_TX_NOT_FULL_DEF ((SPIM_EEPROM_TX_SOFTWARE_BUF_ENABLED) ? \
                                                                        (0u) : (SPIM_EEPROM_INT_ON_TX_NOT_FULL))

/* TX interrupt mask */
#define SPIM_EEPROM_TX_INIT_INTERRUPTS_MASK    (SPIM_EEPROM_INT_ON_SPI_DONE  | \
                                                     SPIM_EEPROM_INT_ON_TX_EMPTY  | \
                                                     SPIM_EEPROM_INT_ON_TX_NOT_FULL_DEF | \
                                                     SPIM_EEPROM_INT_ON_BYTE_COMP | \
                                                     SPIM_EEPROM_INT_ON_SPI_IDLE)

#define SPIM_EEPROM_INT_ON_RX_FULL         ((uint8) (0u << \
                                                                          SPIM_EEPROM_STS_RX_FIFO_FULL_SHIFT))
#define SPIM_EEPROM_INT_ON_RX_NOT_EMPTY    ((uint8) (1u << \
                                                                          SPIM_EEPROM_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define SPIM_EEPROM_INT_ON_RX_OVER         ((uint8) (0u << \
                                                                          SPIM_EEPROM_STS_RX_FIFO_OVERRUN_SHIFT))

/* RX interrupt mask */
#define SPIM_EEPROM_RX_INIT_INTERRUPTS_MASK    (SPIM_EEPROM_INT_ON_RX_FULL      | \
                                                     SPIM_EEPROM_INT_ON_RX_NOT_EMPTY | \
                                                     SPIM_EEPROM_INT_ON_RX_OVER)
/* Nubmer of bits to receive/transmit */
#define SPIM_EEPROM_BITCTR_INIT            (((uint8) (SPIM_EEPROM_DATA_WIDTH << 1u)) - 1u)


/***************************************
*             Registers
***************************************/
#if(CY_PSOC3 || CY_PSOC5)
    #define SPIM_EEPROM_TXDATA_REG (* (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F0_REG)
    #define SPIM_EEPROM_TXDATA_PTR (  (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F0_REG)
    #define SPIM_EEPROM_RXDATA_REG (* (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F1_REG)
    #define SPIM_EEPROM_RXDATA_PTR (  (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F1_REG)
#else   /* PSOC4 */
    #if(SPIM_EEPROM_USE_SECOND_DATAPATH)
        #define SPIM_EEPROM_TXDATA_REG (* (reg16 *) \
                                          SPIM_EEPROM_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define SPIM_EEPROM_TXDATA_PTR (  (reg16 *) \
                                          SPIM_EEPROM_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define SPIM_EEPROM_RXDATA_REG (* (reg16 *) \
                                          SPIM_EEPROM_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
        #define SPIM_EEPROM_RXDATA_PTR (  (reg16 *) \
                                          SPIM_EEPROM_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
    #else
        #define SPIM_EEPROM_TXDATA_REG (* (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F0_REG)
        #define SPIM_EEPROM_TXDATA_PTR (  (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F0_REG)
        #define SPIM_EEPROM_RXDATA_REG (* (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F1_REG)
        #define SPIM_EEPROM_RXDATA_PTR (  (reg8 *) \
                                                SPIM_EEPROM_BSPIM_sR8_Dp_u0__F1_REG)
    #endif /* (SPIM_EEPROM_USE_SECOND_DATAPATH) */
#endif     /* (CY_PSOC3 || CY_PSOC5) */

#define SPIM_EEPROM_AUX_CONTROL_DP0_REG (* (reg8 *) \
                                        SPIM_EEPROM_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)
#define SPIM_EEPROM_AUX_CONTROL_DP0_PTR (  (reg8 *) \
                                        SPIM_EEPROM_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)

#if(SPIM_EEPROM_USE_SECOND_DATAPATH)
    #define SPIM_EEPROM_AUX_CONTROL_DP1_REG  (* (reg8 *) \
                                        SPIM_EEPROM_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
    #define SPIM_EEPROM_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
                                        SPIM_EEPROM_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
#endif /* (SPIM_EEPROM_USE_SECOND_DATAPATH) */

#define SPIM_EEPROM_COUNTER_PERIOD_REG     (* (reg8 *) SPIM_EEPROM_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_EEPROM_COUNTER_PERIOD_PTR     (  (reg8 *) SPIM_EEPROM_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_EEPROM_COUNTER_CONTROL_REG    (* (reg8 *) SPIM_EEPROM_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define SPIM_EEPROM_COUNTER_CONTROL_PTR    (  (reg8 *) SPIM_EEPROM_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define SPIM_EEPROM_TX_STATUS_REG          (* (reg8 *) SPIM_EEPROM_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_EEPROM_TX_STATUS_PTR          (  (reg8 *) SPIM_EEPROM_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_EEPROM_RX_STATUS_REG          (* (reg8 *) SPIM_EEPROM_BSPIM_RxStsReg__STATUS_REG)
#define SPIM_EEPROM_RX_STATUS_PTR          (  (reg8 *) SPIM_EEPROM_BSPIM_RxStsReg__STATUS_REG)

#define SPIM_EEPROM_CONTROL_REG            (* (reg8 *) \
                                      SPIM_EEPROM_BSPIM_BidirMode_CtrlReg__CONTROL_REG)
#define SPIM_EEPROM_CONTROL_PTR            (  (reg8 *) \
                                      SPIM_EEPROM_BSPIM_BidirMode_CtrlReg__CONTROL_REG)

#define SPIM_EEPROM_TX_STATUS_MASK_REG     (* (reg8 *) SPIM_EEPROM_BSPIM_TxStsReg__MASK_REG)
#define SPIM_EEPROM_TX_STATUS_MASK_PTR     (  (reg8 *) SPIM_EEPROM_BSPIM_TxStsReg__MASK_REG)
#define SPIM_EEPROM_RX_STATUS_MASK_REG     (* (reg8 *) SPIM_EEPROM_BSPIM_RxStsReg__MASK_REG)
#define SPIM_EEPROM_RX_STATUS_MASK_PTR     (  (reg8 *) SPIM_EEPROM_BSPIM_RxStsReg__MASK_REG)

#define SPIM_EEPROM_TX_STATUS_ACTL_REG     (* (reg8 *) SPIM_EEPROM_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_EEPROM_TX_STATUS_ACTL_PTR     (  (reg8 *) SPIM_EEPROM_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_EEPROM_RX_STATUS_ACTL_REG     (* (reg8 *) SPIM_EEPROM_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_EEPROM_RX_STATUS_ACTL_PTR     (  (reg8 *) SPIM_EEPROM_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

#if(SPIM_EEPROM_USE_SECOND_DATAPATH)
    #define SPIM_EEPROM_AUX_CONTROLDP1     (SPIM_EEPROM_AUX_CONTROL_DP1_REG)
#endif /* (SPIM_EEPROM_USE_SECOND_DATAPATH) */


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define SPIM_EEPROM_STS_SPI_DONE_SHIFT             (0x00u)
#define SPIM_EEPROM_STS_TX_FIFO_EMPTY_SHIFT        (0x01u)
#define SPIM_EEPROM_STS_TX_FIFO_NOT_FULL_SHIFT     (0x02u)
#define SPIM_EEPROM_STS_BYTE_COMPLETE_SHIFT        (0x03u)
#define SPIM_EEPROM_STS_SPI_IDLE_SHIFT             (0x04u)
#define SPIM_EEPROM_STS_RX_FIFO_FULL_SHIFT         (0x04u)
#define SPIM_EEPROM_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x05u)
#define SPIM_EEPROM_STS_RX_FIFO_OVERRUN_SHIFT      (0x06u)

#define SPIM_EEPROM_STS_SPI_DONE           ((uint8) (0x01u << SPIM_EEPROM_STS_SPI_DONE_SHIFT))
#define SPIM_EEPROM_STS_TX_FIFO_EMPTY      ((uint8) (0x01u << SPIM_EEPROM_STS_TX_FIFO_EMPTY_SHIFT))
#define SPIM_EEPROM_STS_TX_FIFO_NOT_FULL   ((uint8) (0x01u << SPIM_EEPROM_STS_TX_FIFO_NOT_FULL_SHIFT))
#define SPIM_EEPROM_STS_BYTE_COMPLETE      ((uint8) (0x01u << SPIM_EEPROM_STS_BYTE_COMPLETE_SHIFT))
#define SPIM_EEPROM_STS_SPI_IDLE           ((uint8) (0x01u << SPIM_EEPROM_STS_SPI_IDLE_SHIFT))
#define SPIM_EEPROM_STS_RX_FIFO_FULL       ((uint8) (0x01u << SPIM_EEPROM_STS_RX_FIFO_FULL_SHIFT))
#define SPIM_EEPROM_STS_RX_FIFO_NOT_EMPTY  ((uint8) (0x01u << SPIM_EEPROM_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define SPIM_EEPROM_STS_RX_FIFO_OVERRUN    ((uint8) (0x01u << SPIM_EEPROM_STS_RX_FIFO_OVERRUN_SHIFT))

/* TX and RX masks for clear on read bits */
#define SPIM_EEPROM_TX_STS_CLR_ON_RD_BYTES_MASK    (0x09u)
#define SPIM_EEPROM_RX_STS_CLR_ON_RD_BYTES_MASK    (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_EEPROM_INT_ENABLE     (0x10u) /* Enable interrupt from statusi */
#define SPIM_EEPROM_TX_FIFO_CLR    (0x01u) /* F0 - TX FIFO */
#define SPIM_EEPROM_RX_FIFO_CLR    (0x02u) /* F1 - RX FIFO */
#define SPIM_EEPROM_FIFO_CLR       (SPIM_EEPROM_TX_FIFO_CLR | SPIM_EEPROM_RX_FIFO_CLR)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_EEPROM_CNTR_ENABLE    (0x20u) /* Enable CNT7 */

/* Bi-Directional mode control bit */
#define SPIM_EEPROM_CTRL_TX_SIGNAL_EN  (0x01u)

/* Datapath Auxillary Control Register definitions */
#define SPIM_EEPROM_AUX_CTRL_FIFO0_CLR         (0x01u)
#define SPIM_EEPROM_AUX_CTRL_FIFO1_CLR         (0x02u)
#define SPIM_EEPROM_AUX_CTRL_FIFO0_LVL         (0x04u)
#define SPIM_EEPROM_AUX_CTRL_FIFO1_LVL         (0x08u)
#define SPIM_EEPROM_STATUS_ACTL_INT_EN_MASK    (0x10u)

/* Component disabled */
#define SPIM_EEPROM_DISABLED   (0u)


/***************************************
*       Macros
***************************************/

/* Returns true if componentn enabled */
#define SPIM_EEPROM_IS_ENABLED (0u != (SPIM_EEPROM_TX_STATUS_ACTL_REG & SPIM_EEPROM_INT_ENABLE))

/* Retuns TX status register */
#define SPIM_EEPROM_GET_STATUS_TX(swTxSts) ( (uint8)(SPIM_EEPROM_TX_STATUS_REG | \
                                                          ((swTxSts) & SPIM_EEPROM_TX_STS_CLR_ON_RD_BYTES_MASK)) )
/* Retuns RX status register */
#define SPIM_EEPROM_GET_STATUS_RX(swRxSts) ( (uint8)(SPIM_EEPROM_RX_STATUS_REG | \
                                                          ((swRxSts) & SPIM_EEPROM_RX_STS_CLR_ON_RD_BYTES_MASK)) )


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define SPIM_EEPROM_WriteByte   SPIM_EEPROM_WriteTxData
#define SPIM_EEPROM_ReadByte    SPIM_EEPROM_ReadRxData
void  SPIM_EEPROM_SetInterruptMode(uint8 intSrc)       ;
uint8 SPIM_EEPROM_ReadStatus(void)                     ;
void  SPIM_EEPROM_EnableInt(void)                      ;
void  SPIM_EEPROM_DisableInt(void)                     ;

#define SPIM_EEPROM_TXDATA                 (SPIM_EEPROM_TXDATA_REG)
#define SPIM_EEPROM_RXDATA                 (SPIM_EEPROM_RXDATA_REG)
#define SPIM_EEPROM_AUX_CONTROLDP0         (SPIM_EEPROM_AUX_CONTROL_DP0_REG)
#define SPIM_EEPROM_TXBUFFERREAD           (SPIM_EEPROM_txBufferRead)
#define SPIM_EEPROM_TXBUFFERWRITE          (SPIM_EEPROM_txBufferWrite)
#define SPIM_EEPROM_RXBUFFERREAD           (SPIM_EEPROM_rxBufferRead)
#define SPIM_EEPROM_RXBUFFERWRITE          (SPIM_EEPROM_rxBufferWrite)

#define SPIM_EEPROM_COUNTER_PERIOD         (SPIM_EEPROM_COUNTER_PERIOD_REG)
#define SPIM_EEPROM_COUNTER_CONTROL        (SPIM_EEPROM_COUNTER_CONTROL_REG)
#define SPIM_EEPROM_STATUS                 (SPIM_EEPROM_TX_STATUS_REG)
#define SPIM_EEPROM_CONTROL                (SPIM_EEPROM_CONTROL_REG)
#define SPIM_EEPROM_STATUS_MASK            (SPIM_EEPROM_TX_STATUS_MASK_REG)
#define SPIM_EEPROM_STATUS_ACTL            (SPIM_EEPROM_TX_STATUS_ACTL_REG)

#define SPIM_EEPROM_INIT_INTERRUPTS_MASK  (SPIM_EEPROM_INT_ON_SPI_DONE     | \
                                                SPIM_EEPROM_INT_ON_TX_EMPTY     | \
                                                SPIM_EEPROM_INT_ON_TX_NOT_FULL_DEF  | \
                                                SPIM_EEPROM_INT_ON_RX_FULL      | \
                                                SPIM_EEPROM_INT_ON_RX_NOT_EMPTY | \
                                                SPIM_EEPROM_INT_ON_RX_OVER      | \
                                                SPIM_EEPROM_INT_ON_BYTE_COMP)
                                                
#define SPIM_EEPROM_DataWidth                  (SPIM_EEPROM_DATA_WIDTH)
#define SPIM_EEPROM_InternalClockUsed          (SPIM_EEPROM_INTERNAL_CLOCK)
#define SPIM_EEPROM_InternalTxInterruptEnabled (SPIM_EEPROM_INTERNAL_TX_INT_ENABLED)
#define SPIM_EEPROM_InternalRxInterruptEnabled (SPIM_EEPROM_INTERNAL_RX_INT_ENABLED)
#define SPIM_EEPROM_ModeUseZero                (SPIM_EEPROM_MODE_USE_ZERO)
#define SPIM_EEPROM_BidirectionalMode          (SPIM_EEPROM_BIDIRECTIONAL_MODE)
#define SPIM_EEPROM_Mode                       (SPIM_EEPROM_MODE)
#define SPIM_EEPROM_DATAWIDHT                  (SPIM_EEPROM_DATA_WIDTH)
#define SPIM_EEPROM_InternalInterruptEnabled   (0u)

#define SPIM_EEPROM_TXBUFFERSIZE   (SPIM_EEPROM_TX_BUFFER_SIZE)
#define SPIM_EEPROM_RXBUFFERSIZE   (SPIM_EEPROM_RX_BUFFER_SIZE)

#define SPIM_EEPROM_TXBUFFER       SPIM_EEPROM_txBuffer
#define SPIM_EEPROM_RXBUFFER       SPIM_EEPROM_rxBuffer

#endif /* (CY_SPIM_SPIM_EEPROM_H) */


/* [] END OF FILE */
