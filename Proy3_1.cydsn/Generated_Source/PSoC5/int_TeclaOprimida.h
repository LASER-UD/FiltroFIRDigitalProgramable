/*******************************************************************************
* File Name: int_TeclaOprimida.h
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
#if !defined(CY_ISR_int_TeclaOprimida_H)
#define CY_ISR_int_TeclaOprimida_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void int_TeclaOprimida_Start(void);
void int_TeclaOprimida_StartEx(cyisraddress address);
void int_TeclaOprimida_Stop(void);

CY_ISR_PROTO(int_TeclaOprimida_Interrupt);

void int_TeclaOprimida_SetVector(cyisraddress address);
cyisraddress int_TeclaOprimida_GetVector(void);

void int_TeclaOprimida_SetPriority(uint8 priority);
uint8 int_TeclaOprimida_GetPriority(void);

void int_TeclaOprimida_Enable(void);
uint8 int_TeclaOprimida_GetState(void);
void int_TeclaOprimida_Disable(void);

void int_TeclaOprimida_SetPending(void);
void int_TeclaOprimida_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the int_TeclaOprimida ISR. */
#define int_TeclaOprimida_INTC_VECTOR            ((reg32 *) int_TeclaOprimida__INTC_VECT)

/* Address of the int_TeclaOprimida ISR priority. */
#define int_TeclaOprimida_INTC_PRIOR             ((reg8 *) int_TeclaOprimida__INTC_PRIOR_REG)

/* Priority of the int_TeclaOprimida interrupt. */
#define int_TeclaOprimida_INTC_PRIOR_NUMBER      int_TeclaOprimida__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable int_TeclaOprimida interrupt. */
#define int_TeclaOprimida_INTC_SET_EN            ((reg32 *) int_TeclaOprimida__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the int_TeclaOprimida interrupt. */
#define int_TeclaOprimida_INTC_CLR_EN            ((reg32 *) int_TeclaOprimida__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the int_TeclaOprimida interrupt state to pending. */
#define int_TeclaOprimida_INTC_SET_PD            ((reg32 *) int_TeclaOprimida__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the int_TeclaOprimida interrupt. */
#define int_TeclaOprimida_INTC_CLR_PD            ((reg32 *) int_TeclaOprimida__INTC_CLR_PD_REG)


#endif /* CY_ISR_int_TeclaOprimida_H */


/* [] END OF FILE */
