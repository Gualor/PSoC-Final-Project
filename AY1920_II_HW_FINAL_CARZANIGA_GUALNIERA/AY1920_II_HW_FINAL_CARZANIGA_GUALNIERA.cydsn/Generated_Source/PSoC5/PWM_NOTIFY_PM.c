/*******************************************************************************
* File Name: PWM_NOTIFY_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_NOTIFY.h"

static PWM_NOTIFY_backupStruct PWM_NOTIFY_backup;


/*******************************************************************************
* Function Name: PWM_NOTIFY_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NOTIFY_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_NOTIFY_SaveConfig(void) 
{

    #if(!PWM_NOTIFY_UsingFixedFunction)
        #if(!PWM_NOTIFY_PWMModeIsCenterAligned)
            PWM_NOTIFY_backup.PWMPeriod = PWM_NOTIFY_ReadPeriod();
        #endif /* (!PWM_NOTIFY_PWMModeIsCenterAligned) */
        PWM_NOTIFY_backup.PWMUdb = PWM_NOTIFY_ReadCounter();
        #if (PWM_NOTIFY_UseStatus)
            PWM_NOTIFY_backup.InterruptMaskValue = PWM_NOTIFY_STATUS_MASK;
        #endif /* (PWM_NOTIFY_UseStatus) */

        #if(PWM_NOTIFY_DeadBandMode == PWM_NOTIFY__B_PWM__DBM_256_CLOCKS || \
            PWM_NOTIFY_DeadBandMode == PWM_NOTIFY__B_PWM__DBM_2_4_CLOCKS)
            PWM_NOTIFY_backup.PWMdeadBandValue = PWM_NOTIFY_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_NOTIFY_KillModeMinTime)
             PWM_NOTIFY_backup.PWMKillCounterPeriod = PWM_NOTIFY_ReadKillTime();
        #endif /* (PWM_NOTIFY_KillModeMinTime) */

        #if(PWM_NOTIFY_UseControl)
            PWM_NOTIFY_backup.PWMControlRegister = PWM_NOTIFY_ReadControlRegister();
        #endif /* (PWM_NOTIFY_UseControl) */
    #endif  /* (!PWM_NOTIFY_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_NOTIFY_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NOTIFY_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_NOTIFY_RestoreConfig(void) 
{
        #if(!PWM_NOTIFY_UsingFixedFunction)
            #if(!PWM_NOTIFY_PWMModeIsCenterAligned)
                PWM_NOTIFY_WritePeriod(PWM_NOTIFY_backup.PWMPeriod);
            #endif /* (!PWM_NOTIFY_PWMModeIsCenterAligned) */

            PWM_NOTIFY_WriteCounter(PWM_NOTIFY_backup.PWMUdb);

            #if (PWM_NOTIFY_UseStatus)
                PWM_NOTIFY_STATUS_MASK = PWM_NOTIFY_backup.InterruptMaskValue;
            #endif /* (PWM_NOTIFY_UseStatus) */

            #if(PWM_NOTIFY_DeadBandMode == PWM_NOTIFY__B_PWM__DBM_256_CLOCKS || \
                PWM_NOTIFY_DeadBandMode == PWM_NOTIFY__B_PWM__DBM_2_4_CLOCKS)
                PWM_NOTIFY_WriteDeadTime(PWM_NOTIFY_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_NOTIFY_KillModeMinTime)
                PWM_NOTIFY_WriteKillTime(PWM_NOTIFY_backup.PWMKillCounterPeriod);
            #endif /* (PWM_NOTIFY_KillModeMinTime) */

            #if(PWM_NOTIFY_UseControl)
                PWM_NOTIFY_WriteControlRegister(PWM_NOTIFY_backup.PWMControlRegister);
            #endif /* (PWM_NOTIFY_UseControl) */
        #endif  /* (!PWM_NOTIFY_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_NOTIFY_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NOTIFY_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_NOTIFY_Sleep(void) 
{
    #if(PWM_NOTIFY_UseControl)
        if(PWM_NOTIFY_CTRL_ENABLE == (PWM_NOTIFY_CONTROL & PWM_NOTIFY_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_NOTIFY_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_NOTIFY_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_NOTIFY_UseControl) */

    /* Stop component */
    PWM_NOTIFY_Stop();

    /* Save registers configuration */
    PWM_NOTIFY_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_NOTIFY_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_NOTIFY_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_NOTIFY_Wakeup(void) 
{
     /* Restore registers values */
    PWM_NOTIFY_RestoreConfig();

    if(PWM_NOTIFY_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_NOTIFY_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
