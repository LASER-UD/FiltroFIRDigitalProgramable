/*******************************************************************************
* File Name: DAC_PM.c
* Version 2.10
*
* Description:
*  This file provides the power management source code to the API for the
*  DVDAC component.
*
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DAC.h"
#include "DAC_VDAC8.h"

static DAC_BACKUP_STRUCT  DAC_backup;


/*******************************************************************************
* Function Name: DAC_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. The
*  DAC_Sleep() API saves the current component state. Then it
*  calls the DAC_Stop() function and calls
*  DAC_SaveConfig() to save the hardware configuration. Call the
*  DAC_Sleep() function before calling the CyPmSleep() or the
*  CyPmHibernate() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DAC_Sleep(void) 
{
    /* Save VDAC8's enable state */
    if(0u != (DAC_VDAC8_PWRMGR & DAC_VDAC8_ACT_PWR_EN))
    {
        DAC_backup.enableState = 1u;
    }
    else
    {
        DAC_backup.enableState = 0u;
    }

    DAC_Stop();
    DAC_SaveConfig();
}


/*******************************************************************************
* Function Name: DAC_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when
*  DAC_Sleep() was called. The DAC_Wakeup() function
*  calls the DAC_RestoreConfig() function to restore the
*  configuration. If the component was enabled before the
*  DAC_Sleep() function was called, the DVDAC_Wakeup() function
*  will also re-enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DAC_Wakeup(void) 
{
    DAC_RestoreConfig();

    if(DAC_backup.enableState == 1u)
    {
        DAC_Enable();
    }
}


/*******************************************************************************
* Function Name: DAC_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component configuration and non-retention registers.
*  This function is called by the DAC_Sleep() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DAC_SaveConfig(void) 
{
    DAC_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: DAC_RestoreConfig
********************************************************************************
*
* Summary:
*  This function restores the component configuration and non-retention
*  registers. This function is called by the DAC_Wakeup() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DAC_RestoreConfig(void) 
{
    DAC_VDAC8_RestoreConfig();
}


/* [] END OF FILE */
