/*******************************************************************************
* File Name: Columnas.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Columnas_ALIASES_H) /* Pins Columnas_ALIASES_H */
#define CY_PINS_Columnas_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Columnas_0			(Columnas__0__PC)
#define Columnas_0_INTR	((uint16)((uint16)0x0001u << Columnas__0__SHIFT))

#define Columnas_1			(Columnas__1__PC)
#define Columnas_1_INTR	((uint16)((uint16)0x0001u << Columnas__1__SHIFT))

#define Columnas_2			(Columnas__2__PC)
#define Columnas_2_INTR	((uint16)((uint16)0x0001u << Columnas__2__SHIFT))

#define Columnas_INTR_ALL	 ((uint16)(Columnas_0_INTR| Columnas_1_INTR| Columnas_2_INTR))

#endif /* End Pins Columnas_ALIASES_H */


/* [] END OF FILE */
