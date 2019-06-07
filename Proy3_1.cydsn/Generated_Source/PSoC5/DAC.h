/*******************************************************************************
* File Name: DAC.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the DVDAC component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_DVDAC_DAC_H)
#define CY_DVDAC_DAC_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Data Struct Definition
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} DAC_BACKUP_STRUCT;

/* Component init state */
extern uint8 DAC_initVar;


/***************************************
*        API constants
***************************************/
#define DAC_RESOLUTION                 (10u)
#define DAC_INTERNAL_CLOCK_USED        (1u)

#define DAC_INTEGER_PORTION_SHIFT      (DAC_RESOLUTION - 8u)
#define DAC_DITHERED_ARRAY_SIZE        ((uint8)(1u << DAC_INTEGER_PORTION_SHIFT))
#define DAC_FRACTIONAL_PORTION_MASK    (DAC_DITHERED_ARRAY_SIZE - 1u)
#define DAC_INTEGER_PORTION_MAX_VALUE  (0xFFu)

/* DMA Configuration */
#define DAC_DMA_BYTES_PER_BURST        (1u)
#define DAC_DMA_REQUEST_PER_BURST      (1u)
#define DAC_DMA_SRC_BASE               (CYDEV_SRAM_BASE)
#define DAC_DMA_DST_BASE               (CYDEV_PERIPH_BASE)


#if   (DAC_RESOLUTION ==  9u)
    #define DAC_DVDAC_MAX_VALUE        (0x1FEu)
#elif (DAC_RESOLUTION == 10u)
    #define DAC_DVDAC_MAX_VALUE        (0x3FCu)
#elif (DAC_RESOLUTION == 11u)
    #define DAC_DVDAC_MAX_VALUE        (0x7F8u)
#else   /* Resolution 12 bits */
    #define DAC_DVDAC_MAX_VALUE        (0xFF0u)
#endif  /* (DAC_RESOLUTION ==  9u) */


/***************************************
*        Function Prototypes
***************************************/

void DAC_Init(void)                ;
void DAC_Enable(void)              ;
void DAC_Start(void)               ;
void DAC_Stop(void)                ;
void DAC_SetValue(uint16 value)    ;
void DAC_Sleep(void)               ;
void DAC_Wakeup(void)              ;
void DAC_SaveConfig(void)          ;
void DAC_RestoreConfig(void)       ;

#endif /* CY_DVDAC_DAC_H */


/* [] END OF FILE */
