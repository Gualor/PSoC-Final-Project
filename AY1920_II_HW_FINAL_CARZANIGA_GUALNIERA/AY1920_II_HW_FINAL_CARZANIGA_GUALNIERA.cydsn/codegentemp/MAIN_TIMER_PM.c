/*******************************************************************************
* File Name: MAIN_TIMER_PM.c
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

#include "MAIN_TIMER.h"

static MAIN_TIMER_backupStruct MAIN_TIMER_backup;


/*******************************************************************************
* Function Name: MAIN_TIMER_SaveConfig
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
*  MAIN_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void MAIN_TIMER_SaveConfig(void) 
{
    #if (!MAIN_TIMER_UsingFixedFunction)
        MAIN_TIMER_backup.TimerUdb = MAIN_TIMER_ReadCounter();
        MAIN_TIMER_backup.InterruptMaskValue = MAIN_TIMER_STATUS_MASK;
        #if (MAIN_TIMER_UsingHWCaptureCounter)
            MAIN_TIMER_backup.TimerCaptureCounter = MAIN_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!MAIN_TIMER_UDB_CONTROL_REG_REMOVED)
            MAIN_TIMER_backup.TimerControlRegister = MAIN_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: MAIN_TIMER_RestoreConfig
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
*  MAIN_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void MAIN_TIMER_RestoreConfig(void) 
{   
    #if (!MAIN_TIMER_UsingFixedFunction)

        MAIN_TIMER_WriteCounter(MAIN_TIMER_backup.TimerUdb);
        MAIN_TIMER_STATUS_MASK =MAIN_TIMER_backup.InterruptMaskValue;
        #if (MAIN_TIMER_UsingHWCaptureCounter)
            MAIN_TIMER_SetCaptureCount(MAIN_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!MAIN_TIMER_UDB_CONTROL_REG_REMOVED)
            MAIN_TIMER_WriteControlRegister(MAIN_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: MAIN_TIMER_Sleep
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
*  MAIN_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void MAIN_TIMER_Sleep(void) 
{
    #if(!MAIN_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(MAIN_TIMER_CTRL_ENABLE == (MAIN_TIMER_CONTROL & MAIN_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            MAIN_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            MAIN_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    MAIN_TIMER_Stop();
    MAIN_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: MAIN_TIMER_Wakeup
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
*  MAIN_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void MAIN_TIMER_Wakeup(void) 
{
    MAIN_TIMER_RestoreConfig();
    #if(!MAIN_TIMER_UDB_CONTROL_REG_REMOVED)
        if(MAIN_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                MAIN_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
