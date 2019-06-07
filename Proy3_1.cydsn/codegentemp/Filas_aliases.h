/*******************************************************************************
* File Name: Filas.h  
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

#if !defined(CY_PINS_Filas_ALIASES_H) /* Pins Filas_ALIASES_H */
#define CY_PINS_Filas_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Filas_0			(Filas__0__PC)
#define Filas_0_INTR	((uint16)((uint16)0x0001u << Filas__0__SHIFT))

#define Filas_1			(Filas__1__PC)
#define Filas_1_INTR	((uint16)((uint16)0x0001u << Filas__1__SHIFT))

#define Filas_2			(Filas__2__PC)
#define Filas_2_INTR	((uint16)((uint16)0x0001u << Filas__2__SHIFT))

#define Filas_3			(Filas__3__PC)
#define Filas_3_INTR	((uint16)((uint16)0x0001u << Filas__3__SHIFT))

#define Filas_INTR_ALL	 ((uint16)(Filas_0_INTR| Filas_1_INTR| Filas_2_INTR| Filas_3_INTR))

#endif /* End Pins Filas_ALIASES_H */


/* [] END OF FILE */
