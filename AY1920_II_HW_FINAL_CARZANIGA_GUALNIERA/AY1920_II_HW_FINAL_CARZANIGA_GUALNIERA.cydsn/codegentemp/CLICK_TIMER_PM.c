/*******************************************************************************
* File Name: CLICK_TIMER_PM.c
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

#include "CLICK_TIMER.h"

static CLICK_TIMER_backupStruct CLICK_TIMER_backup;


/*******************************************************************************
* Function Name: CLICK_TIMER_SaveConfig
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
*  CLICK_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void CLICK_TIMER_SaveConfig(void) 
{
    #if (!CLICK_TIMER_UsingFixedFunction)
        CLICK_TIMER_backup.TimerUdb = CLICK_TIMER_ReadCounter();
        CLICK_TIMER_backup.InterruptMaskValue = CLICK_TIMER_STATUS_MASK;
        #if (CLICK_TIMER_UsingHWCaptureCounter)
            CLICK_TIMER_backup.TimerCaptureCounter = CLICK_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!CLICK_TIMER_UDB_CONTROL_REG_REMOVED)
            CLICK_TIMER_backup.TimerControlRegister = CLICK_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: CLICK_TIMER_RestoreConfig
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
*  CLICK_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CLICK_TIMER_RestoreConfig(void) 
{   
    #if (!CLICK_TIMER_UsingFixedFunction)

        CLICK_TIMER_WriteCounter(CLICK_TIMER_backup.TimerUdb);
        CLICK_TIMER_STATUS_MASK =CLICK_TIMER_backup.InterruptMaskValue;
        #if (CLICK_TIMER_UsingHWCaptureCounter)
            CLICK_TIMER_SetCaptureCount(CLICK_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!CLICK_TIMER_UDB_CONTROL_REG_REMOVED)
            CLICK_TIMER_WriteControlRegister(CLICK_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: CLICK_TIMER_Sleep
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
*  CLICK_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void CLICK_TIMER_Sleep(void) 
{
    #if(!CLICK_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(CLICK_TIMER_CTRL_ENABLE == (CLICK_TIMER_CONTROL & CLICK_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            CLICK_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            CLICK_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    CLICK_TIMER_Stop();
    CLICK_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: CLICK_TIMER_Wakeup
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
*  CLICK_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CLICK_TIMER_Wakeup(void) 
{
    CLICK_TIMER_RestoreConfig();
    #if(!CLICK_TIMER_UDB_CONTROL_REG_REMOVED)
        if(CLICK_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                CLICK_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
