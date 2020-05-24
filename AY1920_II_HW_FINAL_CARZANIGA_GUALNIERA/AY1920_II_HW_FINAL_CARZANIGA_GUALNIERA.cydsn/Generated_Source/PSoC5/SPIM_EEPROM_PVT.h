/*******************************************************************************
* File Name: .h
* Version 2.50
*
* Description:
*  This private header file contains internal definitions for the SPIM
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_PVT_SPIM_EEPROM_H)
#define CY_SPIM_PVT_SPIM_EEPROM_H

#include "SPIM_EEPROM.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_EEPROM_swStatusTx;
extern volatile uint8 SPIM_EEPROM_swStatusRx;

#if(SPIM_EEPROM_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_EEPROM_txBuffer[SPIM_EEPROM_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_EEPROM_txBufferRead;
    extern volatile uint8 SPIM_EEPROM_txBufferWrite;
    extern volatile uint8 SPIM_EEPROM_txBufferFull;
#endif /* (SPIM_EEPROM_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_EEPROM_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_EEPROM_rxBuffer[SPIM_EEPROM_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_EEPROM_rxBufferRead;
    extern volatile uint8 SPIM_EEPROM_rxBufferWrite;
    extern volatile uint8 SPIM_EEPROM_rxBufferFull;
#endif /* (SPIM_EEPROM_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_EEPROM_H */


/* [] END OF FILE */
