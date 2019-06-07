/*******************************************************************************
* File Name: Filas.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Filas_H) /* Pins Filas_H */
#define CY_PINS_Filas_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Filas_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Filas__PORT == 15 && ((Filas__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Filas_Write(uint8 value);
void    Filas_SetDriveMode(uint8 mode);
uint8   Filas_ReadDataReg(void);
uint8   Filas_Read(void);
void    Filas_SetInterruptMode(uint16 position, uint16 mode);
uint8   Filas_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Filas_SetDriveMode() function.
     *  @{
     */
        #define Filas_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Filas_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Filas_DM_RES_UP          PIN_DM_RES_UP
        #define Filas_DM_RES_DWN         PIN_DM_RES_DWN
        #define Filas_DM_OD_LO           PIN_DM_OD_LO
        #define Filas_DM_OD_HI           PIN_DM_OD_HI
        #define Filas_DM_STRONG          PIN_DM_STRONG
        #define Filas_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Filas_MASK               Filas__MASK
#define Filas_SHIFT              Filas__SHIFT
#define Filas_WIDTH              4u

/* Interrupt constants */
#if defined(Filas__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Filas_SetInterruptMode() function.
     *  @{
     */
        #define Filas_INTR_NONE      (uint16)(0x0000u)
        #define Filas_INTR_RISING    (uint16)(0x0001u)
        #define Filas_INTR_FALLING   (uint16)(0x0002u)
        #define Filas_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Filas_INTR_MASK      (0x01u) 
#endif /* (Filas__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Filas_PS                     (* (reg8 *) Filas__PS)
/* Data Register */
#define Filas_DR                     (* (reg8 *) Filas__DR)
/* Port Number */
#define Filas_PRT_NUM                (* (reg8 *) Filas__PRT) 
/* Connect to Analog Globals */                                                  
#define Filas_AG                     (* (reg8 *) Filas__AG)                       
/* Analog MUX bux enable */
#define Filas_AMUX                   (* (reg8 *) Filas__AMUX) 
/* Bidirectional Enable */                                                        
#define Filas_BIE                    (* (reg8 *) Filas__BIE)
/* Bit-mask for Aliased Register Access */
#define Filas_BIT_MASK               (* (reg8 *) Filas__BIT_MASK)
/* Bypass Enable */
#define Filas_BYP                    (* (reg8 *) Filas__BYP)
/* Port wide control signals */                                                   
#define Filas_CTL                    (* (reg8 *) Filas__CTL)
/* Drive Modes */
#define Filas_DM0                    (* (reg8 *) Filas__DM0) 
#define Filas_DM1                    (* (reg8 *) Filas__DM1)
#define Filas_DM2                    (* (reg8 *) Filas__DM2) 
/* Input Buffer Disable Override */
#define Filas_INP_DIS                (* (reg8 *) Filas__INP_DIS)
/* LCD Common or Segment Drive */
#define Filas_LCD_COM_SEG            (* (reg8 *) Filas__LCD_COM_SEG)
/* Enable Segment LCD */
#define Filas_LCD_EN                 (* (reg8 *) Filas__LCD_EN)
/* Slew Rate Control */
#define Filas_SLW                    (* (reg8 *) Filas__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Filas_PRTDSI__CAPS_SEL       (* (reg8 *) Filas__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Filas_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Filas__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Filas_PRTDSI__OE_SEL0        (* (reg8 *) Filas__PRTDSI__OE_SEL0) 
#define Filas_PRTDSI__OE_SEL1        (* (reg8 *) Filas__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Filas_PRTDSI__OUT_SEL0       (* (reg8 *) Filas__PRTDSI__OUT_SEL0) 
#define Filas_PRTDSI__OUT_SEL1       (* (reg8 *) Filas__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Filas_PRTDSI__SYNC_OUT       (* (reg8 *) Filas__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Filas__SIO_CFG)
    #define Filas_SIO_HYST_EN        (* (reg8 *) Filas__SIO_HYST_EN)
    #define Filas_SIO_REG_HIFREQ     (* (reg8 *) Filas__SIO_REG_HIFREQ)
    #define Filas_SIO_CFG            (* (reg8 *) Filas__SIO_CFG)
    #define Filas_SIO_DIFF           (* (reg8 *) Filas__SIO_DIFF)
#endif /* (Filas__SIO_CFG) */

/* Interrupt Registers */
#if defined(Filas__INTSTAT)
    #define Filas_INTSTAT            (* (reg8 *) Filas__INTSTAT)
    #define Filas_SNAP               (* (reg8 *) Filas__SNAP)
    
	#define Filas_0_INTTYPE_REG 		(* (reg8 *) Filas__0__INTTYPE)
	#define Filas_1_INTTYPE_REG 		(* (reg8 *) Filas__1__INTTYPE)
	#define Filas_2_INTTYPE_REG 		(* (reg8 *) Filas__2__INTTYPE)
	#define Filas_3_INTTYPE_REG 		(* (reg8 *) Filas__3__INTTYPE)
#endif /* (Filas__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Filas_H */


/* [] END OF FILE */
