/*******************************************************************************
* File Name: PWM_RG_PM.c
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

#include "PWM_RG.h"

static PWM_RG_backupStruct PWM_RG_backup;


/*******************************************************************************
* Function Name: PWM_RG_SaveConfig
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
*  PWM_RG_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_RG_SaveConfig(void) 
{

    #if(!PWM_RG_UsingFixedFunction)
        #if(!PWM_RG_PWMModeIsCenterAligned)
            PWM_RG_backup.PWMPeriod = PWM_RG_ReadPeriod();
        #endif /* (!PWM_RG_PWMModeIsCenterAligned) */
        PWM_RG_backup.PWMUdb = PWM_RG_ReadCounter();
        #if (PWM_RG_UseStatus)
            PWM_RG_backup.InterruptMaskValue = PWM_RG_STATUS_MASK;
        #endif /* (PWM_RG_UseStatus) */

        #if(PWM_RG_DeadBandMode == PWM_RG__B_PWM__DBM_256_CLOCKS || \
            PWM_RG_DeadBandMode == PWM_RG__B_PWM__DBM_2_4_CLOCKS)
            PWM_RG_backup.PWMdeadBandValue = PWM_RG_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_RG_KillModeMinTime)
             PWM_RG_backup.PWMKillCounterPeriod = PWM_RG_ReadKillTime();
        #endif /* (PWM_RG_KillModeMinTime) */

        #if(PWM_RG_UseControl)
            PWM_RG_backup.PWMControlRegister = PWM_RG_ReadControlRegister();
        #endif /* (PWM_RG_UseControl) */
    #endif  /* (!PWM_RG_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_RG_RestoreConfig
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
*  PWM_RG_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_RG_RestoreConfig(void) 
{
        #if(!PWM_RG_UsingFixedFunction)
            #if(!PWM_RG_PWMModeIsCenterAligned)
                PWM_RG_WritePeriod(PWM_RG_backup.PWMPeriod);
            #endif /* (!PWM_RG_PWMModeIsCenterAligned) */

            PWM_RG_WriteCounter(PWM_RG_backup.PWMUdb);

            #if (PWM_RG_UseStatus)
                PWM_RG_STATUS_MASK = PWM_RG_backup.InterruptMaskValue;
            #endif /* (PWM_RG_UseStatus) */

            #if(PWM_RG_DeadBandMode == PWM_RG__B_PWM__DBM_256_CLOCKS || \
                PWM_RG_DeadBandMode == PWM_RG__B_PWM__DBM_2_4_CLOCKS)
                PWM_RG_WriteDeadTime(PWM_RG_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_RG_KillModeMinTime)
                PWM_RG_WriteKillTime(PWM_RG_backup.PWMKillCounterPeriod);
            #endif /* (PWM_RG_KillModeMinTime) */

            #if(PWM_RG_UseControl)
                PWM_RG_WriteControlRegister(PWM_RG_backup.PWMControlRegister);
            #endif /* (PWM_RG_UseControl) */
        #endif  /* (!PWM_RG_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_RG_Sleep
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
*  PWM_RG_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_RG_Sleep(void) 
{
    #if(PWM_RG_UseControl)
        if(PWM_RG_CTRL_ENABLE == (PWM_RG_CONTROL & PWM_RG_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_RG_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_RG_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_RG_UseControl) */

    /* Stop component */
    PWM_RG_Stop();

    /* Save registers configuration */
    PWM_RG_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_RG_Wakeup
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
*  PWM_RG_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_RG_Wakeup(void) 
{
     /* Restore registers values */
    PWM_RG_RestoreConfig();

    if(PWM_RG_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_RG_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
