/*******************************************************************************
* File Name: BUTTON_TIMER_PM.c
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

#include "BUTTON_TIMER.h"

static BUTTON_TIMER_backupStruct BUTTON_TIMER_backup;


/*******************************************************************************
* Function Name: BUTTON_TIMER_SaveConfig
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
*  BUTTON_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void BUTTON_TIMER_SaveConfig(void) 
{
    #if (!BUTTON_TIMER_UsingFixedFunction)
        BUTTON_TIMER_backup.TimerUdb = BUTTON_TIMER_ReadCounter();
        BUTTON_TIMER_backup.InterruptMaskValue = BUTTON_TIMER_STATUS_MASK;
        #if (BUTTON_TIMER_UsingHWCaptureCounter)
            BUTTON_TIMER_backup.TimerCaptureCounter = BUTTON_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!BUTTON_TIMER_UDB_CONTROL_REG_REMOVED)
            BUTTON_TIMER_backup.TimerControlRegister = BUTTON_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: BUTTON_TIMER_RestoreConfig
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
*  BUTTON_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void BUTTON_TIMER_RestoreConfig(void) 
{   
    #if (!BUTTON_TIMER_UsingFixedFunction)

        BUTTON_TIMER_WriteCounter(BUTTON_TIMER_backup.TimerUdb);
        BUTTON_TIMER_STATUS_MASK =BUTTON_TIMER_backup.InterruptMaskValue;
        #if (BUTTON_TIMER_UsingHWCaptureCounter)
            BUTTON_TIMER_SetCaptureCount(BUTTON_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!BUTTON_TIMER_UDB_CONTROL_REG_REMOVED)
            BUTTON_TIMER_WriteControlRegister(BUTTON_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: BUTTON_TIMER_Sleep
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
*  BUTTON_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void BUTTON_TIMER_Sleep(void) 
{
    #if(!BUTTON_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(BUTTON_TIMER_CTRL_ENABLE == (BUTTON_TIMER_CONTROL & BUTTON_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            BUTTON_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            BUTTON_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    BUTTON_TIMER_Stop();
    BUTTON_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: BUTTON_TIMER_Wakeup
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
*  BUTTON_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void BUTTON_TIMER_Wakeup(void) 
{
    BUTTON_TIMER_RestoreConfig();
    #if(!BUTTON_TIMER_UDB_CONTROL_REG_REMOVED)
        if(BUTTON_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                BUTTON_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
