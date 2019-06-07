/*******************************************************************************
* File Name: Columnas.h  
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

#if !defined(CY_PINS_Columnas_H) /* Pins Columnas_H */
#define CY_PINS_Columnas_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Columnas_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Columnas__PORT == 15 && ((Columnas__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Columnas_Write(uint8 value);
void    Columnas_SetDriveMode(uint8 mode);
uint8   Columnas_ReadDataReg(void);
uint8   Columnas_Read(void);
void    Columnas_SetInterruptMode(uint16 position, uint16 mode);
uint8   Columnas_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Columnas_SetDriveMode() function.
     *  @{
     */
        #define Columnas_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Columnas_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Columnas_DM_RES_UP          PIN_DM_RES_UP
        #define Columnas_DM_RES_DWN         PIN_DM_RES_DWN
        #define Columnas_DM_OD_LO           PIN_DM_OD_LO
        #define Columnas_DM_OD_HI           PIN_DM_OD_HI
        #define Columnas_DM_STRONG          PIN_DM_STRONG
        #define Columnas_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Columnas_MASK               Columnas__MASK
#define Columnas_SHIFT              Columnas__SHIFT
#define Columnas_WIDTH              3u

/* Interrupt constants */
#if defined(Columnas__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Columnas_SetInterruptMode() function.
     *  @{
     */
        #define Columnas_INTR_NONE      (uint16)(0x0000u)
        #define Columnas_INTR_RISING    (uint16)(0x0001u)
        #define Columnas_INTR_FALLING   (uint16)(0x0002u)
        #define Columnas_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Columnas_INTR_MASK      (0x01u) 
#endif /* (Columnas__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Columnas_PS                     (* (reg8 *) Columnas__PS)
/* Data Register */
#define Columnas_DR                     (* (reg8 *) Columnas__DR)
/* Port Number */
#define Columnas_PRT_NUM                (* (reg8 *) Columnas__PRT) 
/* Connect to Analog Globals */                                                  
#define Columnas_AG                     (* (reg8 *) Columnas__AG)                       
/* Analog MUX bux enable */
#define Columnas_AMUX                   (* (reg8 *) Columnas__AMUX) 
/* Bidirectional Enable */                                                        
#define Columnas_BIE                    (* (reg8 *) Columnas__BIE)
/* Bit-mask for Aliased Register Access */
#define Columnas_BIT_MASK               (* (reg8 *) Columnas__BIT_MASK)
/* Bypass Enable */
#define Columnas_BYP                    (* (reg8 *) Columnas__BYP)
/* Port wide control signals */                                                   
#define Columnas_CTL                    (* (reg8 *) Columnas__CTL)
/* Drive Modes */
#define Columnas_DM0                    (* (reg8 *) Columnas__DM0) 
#define Columnas_DM1                    (* (reg8 *) Columnas__DM1)
#define Columnas_DM2                    (* (reg8 *) Columnas__DM2) 
/* Input Buffer Disable Override */
#define Columnas_INP_DIS                (* (reg8 *) Columnas__INP_DIS)
/* LCD Common or Segment Drive */
#define Columnas_LCD_COM_SEG            (* (reg8 *) Columnas__LCD_COM_SEG)
/* Enable Segment LCD */
#define Columnas_LCD_EN                 (* (reg8 *) Columnas__LCD_EN)
/* Slew Rate Control */
#define Columnas_SLW                    (* (reg8 *) Columnas__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Columnas_PRTDSI__CAPS_SEL       (* (reg8 *) Columnas__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Columnas_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Columnas__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Columnas_PRTDSI__OE_SEL0        (* (reg8 *) Columnas__PRTDSI__OE_SEL0) 
#define Columnas_PRTDSI__OE_SEL1        (* (reg8 *) Columnas__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Columnas_PRTDSI__OUT_SEL0       (* (reg8 *) Columnas__PRTDSI__OUT_SEL0) 
#define Columnas_PRTDSI__OUT_SEL1       (* (reg8 *) Columnas__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Columnas_PRTDSI__SYNC_OUT       (* (reg8 *) Columnas__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Columnas__SIO_CFG)
    #define Columnas_SIO_HYST_EN        (* (reg8 *) Columnas__SIO_HYST_EN)
    #define Columnas_SIO_REG_HIFREQ     (* (reg8 *) Columnas__SIO_REG_HIFREQ)
    #define Columnas_SIO_CFG            (* (reg8 *) Columnas__SIO_CFG)
    #define Columnas_SIO_DIFF           (* (reg8 *) Columnas__SIO_DIFF)
#endif /* (Columnas__SIO_CFG) */

/* Interrupt Registers */
#if defined(Columnas__INTSTAT)
    #define Columnas_INTSTAT            (* (reg8 *) Columnas__INTSTAT)
    #define Columnas_SNAP               (* (reg8 *) Columnas__SNAP)
    
	#define Columnas_0_INTTYPE_REG 		(* (reg8 *) Columnas__0__INTTYPE)
	#define Columnas_1_INTTYPE_REG 		(* (reg8 *) Columnas__1__INTTYPE)
	#define Columnas_2_INTTYPE_REG 		(* (reg8 *) Columnas__2__INTTYPE)
#endif /* (Columnas__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Columnas_H */


/* [] END OF FILE */
