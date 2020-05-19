/*******************************************************************************
* File Name: NOTIFY_TIMER_PM.c
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

#include "NOTIFY_TIMER.h"

static NOTIFY_TIMER_backupStruct NOTIFY_TIMER_backup;


/*******************************************************************************
* Function Name: NOTIFY_TIMER_SaveConfig
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
*  NOTIFY_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void NOTIFY_TIMER_SaveConfig(void) 
{
    #if (!NOTIFY_TIMER_UsingFixedFunction)
        NOTIFY_TIMER_backup.TimerUdb = NOTIFY_TIMER_ReadCounter();
        NOTIFY_TIMER_backup.InterruptMaskValue = NOTIFY_TIMER_STATUS_MASK;
        #if (NOTIFY_TIMER_UsingHWCaptureCounter)
            NOTIFY_TIMER_backup.TimerCaptureCounter = NOTIFY_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!NOTIFY_TIMER_UDB_CONTROL_REG_REMOVED)
            NOTIFY_TIMER_backup.TimerControlRegister = NOTIFY_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: NOTIFY_TIMER_RestoreConfig
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
*  NOTIFY_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void NOTIFY_TIMER_RestoreConfig(void) 
{   
    #if (!NOTIFY_TIMER_UsingFixedFunction)

        NOTIFY_TIMER_WriteCounter(NOTIFY_TIMER_backup.TimerUdb);
        NOTIFY_TIMER_STATUS_MASK =NOTIFY_TIMER_backup.InterruptMaskValue;
        #if (NOTIFY_TIMER_UsingHWCaptureCounter)
            NOTIFY_TIMER_SetCaptureCount(NOTIFY_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!NOTIFY_TIMER_UDB_CONTROL_REG_REMOVED)
            NOTIFY_TIMER_WriteControlRegister(NOTIFY_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: NOTIFY_TIMER_Sleep
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
*  NOTIFY_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void NOTIFY_TIMER_Sleep(void) 
{
    #if(!NOTIFY_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(NOTIFY_TIMER_CTRL_ENABLE == (NOTIFY_TIMER_CONTROL & NOTIFY_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            NOTIFY_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            NOTIFY_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    NOTIFY_TIMER_Stop();
    NOTIFY_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: NOTIFY_TIMER_Wakeup
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
*  NOTIFY_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void NOTIFY_TIMER_Wakeup(void) 
{
    NOTIFY_TIMER_RestoreConfig();
    #if(!NOTIFY_TIMER_UDB_CONTROL_REG_REMOVED)
        if(NOTIFY_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                NOTIFY_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
