/*******************************************************************************
* File Name: SPIM_EEPROM_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_EEPROM_PVT.h"

static SPIM_EEPROM_BACKUP_STRUCT SPIM_EEPROM_backup =
{
    SPIM_EEPROM_DISABLED,
    SPIM_EEPROM_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_EEPROM_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_EEPROM_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_EEPROM_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_EEPROM_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_EEPROM_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_EEPROM_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EEPROM_Sleep(void) 
{
    /* Save components enable state */
    SPIM_EEPROM_backup.enableState = ((uint8) SPIM_EEPROM_IS_ENABLED);

    SPIM_EEPROM_Stop();
}


/*******************************************************************************
* Function Name: SPIM_EEPROM_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_EEPROM_backup - used when non-retention registers are restored.
*  SPIM_EEPROM_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_EEPROM_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_EEPROM_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_EEPROM_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EEPROM_Wakeup(void) 
{
    #if(SPIM_EEPROM_RX_SOFTWARE_BUF_ENABLED)
        SPIM_EEPROM_rxBufferFull  = 0u;
        SPIM_EEPROM_rxBufferRead  = 0u;
        SPIM_EEPROM_rxBufferWrite = 0u;
    #endif /* (SPIM_EEPROM_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_EEPROM_TX_SOFTWARE_BUF_ENABLED)
        SPIM_EEPROM_txBufferFull  = 0u;
        SPIM_EEPROM_txBufferRead  = 0u;
        SPIM_EEPROM_txBufferWrite = 0u;
    #endif /* (SPIM_EEPROM_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_EEPROM_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_EEPROM_backup.enableState)
    {
        SPIM_EEPROM_Enable();
    }
}


/* [] END OF FILE */
