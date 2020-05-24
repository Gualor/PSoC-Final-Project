/*******************************************************************************
* File Name: SPIM_IMU_PM.c
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

#include "SPIM_IMU_PVT.h"

static SPIM_IMU_BACKUP_STRUCT SPIM_IMU_backup =
{
    SPIM_IMU_DISABLED,
    SPIM_IMU_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_IMU_SaveConfig
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
void SPIM_IMU_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_IMU_RestoreConfig
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
void SPIM_IMU_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_IMU_Sleep
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
*  SPIM_IMU_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_IMU_Sleep(void) 
{
    /* Save components enable state */
    SPIM_IMU_backup.enableState = ((uint8) SPIM_IMU_IS_ENABLED);

    SPIM_IMU_Stop();
}


/*******************************************************************************
* Function Name: SPIM_IMU_Wakeup
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
*  SPIM_IMU_backup - used when non-retention registers are restored.
*  SPIM_IMU_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_IMU_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_IMU_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_IMU_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_IMU_Wakeup(void) 
{
    #if(SPIM_IMU_RX_SOFTWARE_BUF_ENABLED)
        SPIM_IMU_rxBufferFull  = 0u;
        SPIM_IMU_rxBufferRead  = 0u;
        SPIM_IMU_rxBufferWrite = 0u;
    #endif /* (SPIM_IMU_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_IMU_TX_SOFTWARE_BUF_ENABLED)
        SPIM_IMU_txBufferFull  = 0u;
        SPIM_IMU_txBufferRead  = 0u;
        SPIM_IMU_txBufferWrite = 0u;
    #endif /* (SPIM_IMU_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_IMU_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_IMU_backup.enableState)
    {
        SPIM_IMU_Enable();
    }
}


/* [] END OF FILE */
