/*******************************************************************************
* File Name: int_EndOfConv.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_int_EndOfConv_H)
#define CY_ISR_int_EndOfConv_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void int_EndOfConv_Start(void);
void int_EndOfConv_StartEx(cyisraddress address);
void int_EndOfConv_Stop(void);

CY_ISR_PROTO(int_EndOfConv_Interrupt);

void int_EndOfConv_SetVector(cyisraddress address);
cyisraddress int_EndOfConv_GetVector(void);

void int_EndOfConv_SetPriority(uint8 priority);
uint8 int_EndOfConv_GetPriority(void);

void int_EndOfConv_Enable(void);
uint8 int_EndOfConv_GetState(void);
void int_EndOfConv_Disable(void);

void int_EndOfConv_SetPending(void);
void int_EndOfConv_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the int_EndOfConv ISR. */
#define int_EndOfConv_INTC_VECTOR            ((reg32 *) int_EndOfConv__INTC_VECT)

/* Address of the int_EndOfConv ISR priority. */
#define int_EndOfConv_INTC_PRIOR             ((reg8 *) int_EndOfConv__INTC_PRIOR_REG)

/* Priority of the int_EndOfConv interrupt. */
#define int_EndOfConv_INTC_PRIOR_NUMBER      int_EndOfConv__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable int_EndOfConv interrupt. */
#define int_EndOfConv_INTC_SET_EN            ((reg32 *) int_EndOfConv__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the int_EndOfConv interrupt. */
#define int_EndOfConv_INTC_CLR_EN            ((reg32 *) int_EndOfConv__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the int_EndOfConv interrupt state to pending. */
#define int_EndOfConv_INTC_SET_PD            ((reg32 *) int_EndOfConv__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the int_EndOfConv interrupt. */
#define int_EndOfConv_INTC_CLR_PD            ((reg32 *) int_EndOfConv__INTC_CLR_PD_REG)


#endif /* CY_ISR_int_EndOfConv_H */


/* [] END OF FILE */
