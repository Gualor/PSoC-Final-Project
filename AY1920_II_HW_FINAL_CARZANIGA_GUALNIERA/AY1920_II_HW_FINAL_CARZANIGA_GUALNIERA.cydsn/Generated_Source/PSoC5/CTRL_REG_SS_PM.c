/*******************************************************************************
* File Name: CTRL_REG_SS_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CTRL_REG_SS.h"

/* Check for removal by optimization */
#if !defined(CTRL_REG_SS_Sync_ctrl_reg__REMOVED)

static CTRL_REG_SS_BACKUP_STRUCT  CTRL_REG_SS_backup = {0u};

    
/*******************************************************************************
* Function Name: CTRL_REG_SS_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CTRL_REG_SS_SaveConfig(void) 
{
    CTRL_REG_SS_backup.controlState = CTRL_REG_SS_Control;
}


/*******************************************************************************
* Function Name: CTRL_REG_SS_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void CTRL_REG_SS_RestoreConfig(void) 
{
     CTRL_REG_SS_Control = CTRL_REG_SS_backup.controlState;
}


/*******************************************************************************
* Function Name: CTRL_REG_SS_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CTRL_REG_SS_Sleep(void) 
{
    CTRL_REG_SS_SaveConfig();
}


/*******************************************************************************
* Function Name: CTRL_REG_SS_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CTRL_REG_SS_Wakeup(void)  
{
    CTRL_REG_SS_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
