/*******************************************************************************
* File Name: Muestreo_PM.c
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

#include "Muestreo.h"

static Muestreo_backupStruct Muestreo_backup;


/*******************************************************************************
* Function Name: Muestreo_SaveConfig
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
*  Muestreo_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Muestreo_SaveConfig(void) 
{
    #if (!Muestreo_UsingFixedFunction)
        Muestreo_backup.TimerUdb = Muestreo_ReadCounter();
        Muestreo_backup.InterruptMaskValue = Muestreo_STATUS_MASK;
        #if (Muestreo_UsingHWCaptureCounter)
            Muestreo_backup.TimerCaptureCounter = Muestreo_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Muestreo_UDB_CONTROL_REG_REMOVED)
            Muestreo_backup.TimerControlRegister = Muestreo_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Muestreo_RestoreConfig
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
*  Muestreo_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Muestreo_RestoreConfig(void) 
{   
    #if (!Muestreo_UsingFixedFunction)

        Muestreo_WriteCounter(Muestreo_backup.TimerUdb);
        Muestreo_STATUS_MASK =Muestreo_backup.InterruptMaskValue;
        #if (Muestreo_UsingHWCaptureCounter)
            Muestreo_SetCaptureCount(Muestreo_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Muestreo_UDB_CONTROL_REG_REMOVED)
            Muestreo_WriteControlRegister(Muestreo_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Muestreo_Sleep
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
*  Muestreo_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Muestreo_Sleep(void) 
{
    #if(!Muestreo_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Muestreo_CTRL_ENABLE == (Muestreo_CONTROL & Muestreo_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Muestreo_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Muestreo_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Muestreo_Stop();
    Muestreo_SaveConfig();
}


/*******************************************************************************
* Function Name: Muestreo_Wakeup
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
*  Muestreo_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Muestreo_Wakeup(void) 
{
    Muestreo_RestoreConfig();
    #if(!Muestreo_UDB_CONTROL_REG_REMOVED)
        if(Muestreo_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Muestreo_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
