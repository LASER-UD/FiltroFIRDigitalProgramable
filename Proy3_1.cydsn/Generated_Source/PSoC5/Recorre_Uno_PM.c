/*******************************************************************************
* File Name: Recorre_Uno_PM.c
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

#include "Recorre_Uno.h"

static Recorre_Uno_backupStruct Recorre_Uno_backup;


/*******************************************************************************
* Function Name: Recorre_Uno_SaveConfig
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
*  Recorre_Uno_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Recorre_Uno_SaveConfig(void) 
{
    #if (!Recorre_Uno_UsingFixedFunction)
        Recorre_Uno_backup.TimerUdb = Recorre_Uno_ReadCounter();
        Recorre_Uno_backup.InterruptMaskValue = Recorre_Uno_STATUS_MASK;
        #if (Recorre_Uno_UsingHWCaptureCounter)
            Recorre_Uno_backup.TimerCaptureCounter = Recorre_Uno_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Recorre_Uno_UDB_CONTROL_REG_REMOVED)
            Recorre_Uno_backup.TimerControlRegister = Recorre_Uno_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Recorre_Uno_RestoreConfig
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
*  Recorre_Uno_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Recorre_Uno_RestoreConfig(void) 
{   
    #if (!Recorre_Uno_UsingFixedFunction)

        Recorre_Uno_WriteCounter(Recorre_Uno_backup.TimerUdb);
        Recorre_Uno_STATUS_MASK =Recorre_Uno_backup.InterruptMaskValue;
        #if (Recorre_Uno_UsingHWCaptureCounter)
            Recorre_Uno_SetCaptureCount(Recorre_Uno_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Recorre_Uno_UDB_CONTROL_REG_REMOVED)
            Recorre_Uno_WriteControlRegister(Recorre_Uno_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Recorre_Uno_Sleep
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
*  Recorre_Uno_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Recorre_Uno_Sleep(void) 
{
    #if(!Recorre_Uno_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Recorre_Uno_CTRL_ENABLE == (Recorre_Uno_CONTROL & Recorre_Uno_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Recorre_Uno_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Recorre_Uno_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Recorre_Uno_Stop();
    Recorre_Uno_SaveConfig();
}


/*******************************************************************************
* Function Name: Recorre_Uno_Wakeup
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
*  Recorre_Uno_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Recorre_Uno_Wakeup(void) 
{
    Recorre_Uno_RestoreConfig();
    #if(!Recorre_Uno_UDB_CONTROL_REG_REMOVED)
        if(Recorre_Uno_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Recorre_Uno_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
