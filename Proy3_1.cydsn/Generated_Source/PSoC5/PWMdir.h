/*******************************************************************************
* File Name: PWMdir.h  
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

#if !defined(CY_PINS_PWMdir_H) /* Pins PWMdir_H */
#define CY_PINS_PWMdir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWMdir_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWMdir__PORT == 15 && ((PWMdir__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PWMdir_Write(uint8 value);
void    PWMdir_SetDriveMode(uint8 mode);
uint8   PWMdir_ReadDataReg(void);
uint8   PWMdir_Read(void);
void    PWMdir_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMdir_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PWMdir_SetDriveMode() function.
     *  @{
     */
        #define PWMdir_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PWMdir_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PWMdir_DM_RES_UP          PIN_DM_RES_UP
        #define PWMdir_DM_RES_DWN         PIN_DM_RES_DWN
        #define PWMdir_DM_OD_LO           PIN_DM_OD_LO
        #define PWMdir_DM_OD_HI           PIN_DM_OD_HI
        #define PWMdir_DM_STRONG          PIN_DM_STRONG
        #define PWMdir_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PWMdir_MASK               PWMdir__MASK
#define PWMdir_SHIFT              PWMdir__SHIFT
#define PWMdir_WIDTH              1u

/* Interrupt constants */
#if defined(PWMdir__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMdir_SetInterruptMode() function.
     *  @{
     */
        #define PWMdir_INTR_NONE      (uint16)(0x0000u)
        #define PWMdir_INTR_RISING    (uint16)(0x0001u)
        #define PWMdir_INTR_FALLING   (uint16)(0x0002u)
        #define PWMdir_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PWMdir_INTR_MASK      (0x01u) 
#endif /* (PWMdir__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMdir_PS                     (* (reg8 *) PWMdir__PS)
/* Data Register */
#define PWMdir_DR                     (* (reg8 *) PWMdir__DR)
/* Port Number */
#define PWMdir_PRT_NUM                (* (reg8 *) PWMdir__PRT) 
/* Connect to Analog Globals */                                                  
#define PWMdir_AG                     (* (reg8 *) PWMdir__AG)                       
/* Analog MUX bux enable */
#define PWMdir_AMUX                   (* (reg8 *) PWMdir__AMUX) 
/* Bidirectional Enable */                                                        
#define PWMdir_BIE                    (* (reg8 *) PWMdir__BIE)
/* Bit-mask for Aliased Register Access */
#define PWMdir_BIT_MASK               (* (reg8 *) PWMdir__BIT_MASK)
/* Bypass Enable */
#define PWMdir_BYP                    (* (reg8 *) PWMdir__BYP)
/* Port wide control signals */                                                   
#define PWMdir_CTL                    (* (reg8 *) PWMdir__CTL)
/* Drive Modes */
#define PWMdir_DM0                    (* (reg8 *) PWMdir__DM0) 
#define PWMdir_DM1                    (* (reg8 *) PWMdir__DM1)
#define PWMdir_DM2                    (* (reg8 *) PWMdir__DM2) 
/* Input Buffer Disable Override */
#define PWMdir_INP_DIS                (* (reg8 *) PWMdir__INP_DIS)
/* LCD Common or Segment Drive */
#define PWMdir_LCD_COM_SEG            (* (reg8 *) PWMdir__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWMdir_LCD_EN                 (* (reg8 *) PWMdir__LCD_EN)
/* Slew Rate Control */
#define PWMdir_SLW                    (* (reg8 *) PWMdir__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWMdir_PRTDSI__CAPS_SEL       (* (reg8 *) PWMdir__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWMdir_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWMdir__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWMdir_PRTDSI__OE_SEL0        (* (reg8 *) PWMdir__PRTDSI__OE_SEL0) 
#define PWMdir_PRTDSI__OE_SEL1        (* (reg8 *) PWMdir__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWMdir_PRTDSI__OUT_SEL0       (* (reg8 *) PWMdir__PRTDSI__OUT_SEL0) 
#define PWMdir_PRTDSI__OUT_SEL1       (* (reg8 *) PWMdir__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWMdir_PRTDSI__SYNC_OUT       (* (reg8 *) PWMdir__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PWMdir__SIO_CFG)
    #define PWMdir_SIO_HYST_EN        (* (reg8 *) PWMdir__SIO_HYST_EN)
    #define PWMdir_SIO_REG_HIFREQ     (* (reg8 *) PWMdir__SIO_REG_HIFREQ)
    #define PWMdir_SIO_CFG            (* (reg8 *) PWMdir__SIO_CFG)
    #define PWMdir_SIO_DIFF           (* (reg8 *) PWMdir__SIO_DIFF)
#endif /* (PWMdir__SIO_CFG) */

/* Interrupt Registers */
#if defined(PWMdir__INTSTAT)
    #define PWMdir_INTSTAT            (* (reg8 *) PWMdir__INTSTAT)
    #define PWMdir_SNAP               (* (reg8 *) PWMdir__SNAP)
    
	#define PWMdir_0_INTTYPE_REG 		(* (reg8 *) PWMdir__0__INTTYPE)
#endif /* (PWMdir__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWMdir_H */


/* [] END OF FILE */
