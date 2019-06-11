/*******************************************************************************
* File Name: PWM_Dir_PM.c
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

#include "PWM_Dir.h"

static PWM_Dir_backupStruct PWM_Dir_backup;


/*******************************************************************************
* Function Name: PWM_Dir_SaveConfig
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
*  PWM_Dir_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Dir_SaveConfig(void) 
{

    #if(!PWM_Dir_UsingFixedFunction)
        #if(!PWM_Dir_PWMModeIsCenterAligned)
            PWM_Dir_backup.PWMPeriod = PWM_Dir_ReadPeriod();
        #endif /* (!PWM_Dir_PWMModeIsCenterAligned) */
        PWM_Dir_backup.PWMUdb = PWM_Dir_ReadCounter();
        #if (PWM_Dir_UseStatus)
            PWM_Dir_backup.InterruptMaskValue = PWM_Dir_STATUS_MASK;
        #endif /* (PWM_Dir_UseStatus) */

        #if(PWM_Dir_DeadBandMode == PWM_Dir__B_PWM__DBM_256_CLOCKS || \
            PWM_Dir_DeadBandMode == PWM_Dir__B_PWM__DBM_2_4_CLOCKS)
            PWM_Dir_backup.PWMdeadBandValue = PWM_Dir_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Dir_KillModeMinTime)
             PWM_Dir_backup.PWMKillCounterPeriod = PWM_Dir_ReadKillTime();
        #endif /* (PWM_Dir_KillModeMinTime) */

        #if(PWM_Dir_UseControl)
            PWM_Dir_backup.PWMControlRegister = PWM_Dir_ReadControlRegister();
        #endif /* (PWM_Dir_UseControl) */
    #endif  /* (!PWM_Dir_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Dir_RestoreConfig
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
*  PWM_Dir_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Dir_RestoreConfig(void) 
{
        #if(!PWM_Dir_UsingFixedFunction)
            #if(!PWM_Dir_PWMModeIsCenterAligned)
                PWM_Dir_WritePeriod(PWM_Dir_backup.PWMPeriod);
            #endif /* (!PWM_Dir_PWMModeIsCenterAligned) */

            PWM_Dir_WriteCounter(PWM_Dir_backup.PWMUdb);

            #if (PWM_Dir_UseStatus)
                PWM_Dir_STATUS_MASK = PWM_Dir_backup.InterruptMaskValue;
            #endif /* (PWM_Dir_UseStatus) */

            #if(PWM_Dir_DeadBandMode == PWM_Dir__B_PWM__DBM_256_CLOCKS || \
                PWM_Dir_DeadBandMode == PWM_Dir__B_PWM__DBM_2_4_CLOCKS)
                PWM_Dir_WriteDeadTime(PWM_Dir_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Dir_KillModeMinTime)
                PWM_Dir_WriteKillTime(PWM_Dir_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Dir_KillModeMinTime) */

            #if(PWM_Dir_UseControl)
                PWM_Dir_WriteControlRegister(PWM_Dir_backup.PWMControlRegister);
            #endif /* (PWM_Dir_UseControl) */
        #endif  /* (!PWM_Dir_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Dir_Sleep
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
*  PWM_Dir_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Dir_Sleep(void) 
{
    #if(PWM_Dir_UseControl)
        if(PWM_Dir_CTRL_ENABLE == (PWM_Dir_CONTROL & PWM_Dir_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Dir_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Dir_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Dir_UseControl) */

    /* Stop component */
    PWM_Dir_Stop();

    /* Save registers configuration */
    PWM_Dir_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Dir_Wakeup
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
*  PWM_Dir_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Dir_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Dir_RestoreConfig();

    if(PWM_Dir_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Dir_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
