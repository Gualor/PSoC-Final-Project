/*******************************************************************************
* File Name: TIMER_BUTTON_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "TIMER_BUTTON.h"

static TIMER_BUTTON_backupStruct TIMER_BUTTON_backup;


/*******************************************************************************
* Function Name: TIMER_BUTTON_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_BUTTON_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TIMER_BUTTON_SaveConfig(void) 
{
    #if (!TIMER_BUTTON_UsingFixedFunction)
        TIMER_BUTTON_backup.TimerUdb = TIMER_BUTTON_ReadCounter();
        TIMER_BUTTON_backup.InterruptMaskValue = TIMER_BUTTON_STATUS_MASK;
        #if (TIMER_BUTTON_UsingHWCaptureCounter)
            TIMER_BUTTON_backup.TimerCaptureCounter = TIMER_BUTTON_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!TIMER_BUTTON_UDB_CONTROL_REG_REMOVED)
            TIMER_BUTTON_backup.TimerControlRegister = TIMER_BUTTON_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: TIMER_BUTTON_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_BUTTON_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_BUTTON_RestoreConfig(void) 
{   
    #if (!TIMER_BUTTON_UsingFixedFunction)

        TIMER_BUTTON_WriteCounter(TIMER_BUTTON_backup.TimerUdb);
        TIMER_BUTTON_STATUS_MASK =TIMER_BUTTON_backup.InterruptMaskValue;
        #if (TIMER_BUTTON_UsingHWCaptureCounter)
            TIMER_BUTTON_SetCaptureCount(TIMER_BUTTON_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!TIMER_BUTTON_UDB_CONTROL_REG_REMOVED)
            TIMER_BUTTON_WriteControlRegister(TIMER_BUTTON_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: TIMER_BUTTON_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_BUTTON_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void TIMER_BUTTON_Sleep(void) 
{
    #if(!TIMER_BUTTON_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(TIMER_BUTTON_CTRL_ENABLE == (TIMER_BUTTON_CONTROL & TIMER_BUTTON_CTRL_ENABLE))
        {
            /* Timer is enabled */
            TIMER_BUTTON_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            TIMER_BUTTON_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    TIMER_BUTTON_Stop();
    TIMER_BUTTON_SaveConfig();
}


/*******************************************************************************
* Function Name: TIMER_BUTTON_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TIMER_BUTTON_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_BUTTON_Wakeup(void) 
{
    TIMER_BUTTON_RestoreConfig();
    #if(!TIMER_BUTTON_UDB_CONTROL_REG_REMOVED)
        if(TIMER_BUTTON_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                TIMER_BUTTON_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
