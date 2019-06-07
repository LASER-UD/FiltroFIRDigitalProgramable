/*******************************************************************************
* File Name: Recorre_Uno.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_Recorre_Uno_H)
#define CY_TIMER_Recorre_Uno_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Recorre_Uno_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Recorre_Uno_Resolution                 24u
#define Recorre_Uno_UsingFixedFunction         0u
#define Recorre_Uno_UsingHWCaptureCounter      0u
#define Recorre_Uno_SoftwareCaptureMode        0u
#define Recorre_Uno_SoftwareTriggerMode        0u
#define Recorre_Uno_UsingHWEnable              0u
#define Recorre_Uno_EnableTriggerMode          0u
#define Recorre_Uno_InterruptOnCaptureCount    0u
#define Recorre_Uno_RunModeUsed                0u
#define Recorre_Uno_ControlRegRemoved          0u

#if defined(Recorre_Uno_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define Recorre_Uno_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (Recorre_Uno_UsingFixedFunction)
    #define Recorre_Uno_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define Recorre_Uno_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End Recorre_Uno_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!Recorre_Uno_UsingFixedFunction)

        uint32 TimerUdb;
        uint8 InterruptMaskValue;
        #if (Recorre_Uno_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!Recorre_Uno_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}Recorre_Uno_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Recorre_Uno_Start(void) ;
void    Recorre_Uno_Stop(void) ;

void    Recorre_Uno_SetInterruptMode(uint8 interruptMode) ;
uint8   Recorre_Uno_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Recorre_Uno_GetInterruptSource() Recorre_Uno_ReadStatusRegister()

#if(!Recorre_Uno_UDB_CONTROL_REG_REMOVED)
    uint8   Recorre_Uno_ReadControlRegister(void) ;
    void    Recorre_Uno_WriteControlRegister(uint8 control) ;
#endif /* (!Recorre_Uno_UDB_CONTROL_REG_REMOVED) */

uint32  Recorre_Uno_ReadPeriod(void) ;
void    Recorre_Uno_WritePeriod(uint32 period) ;
uint32  Recorre_Uno_ReadCounter(void) ;
void    Recorre_Uno_WriteCounter(uint32 counter) ;
uint32  Recorre_Uno_ReadCapture(void) ;
void    Recorre_Uno_SoftwareCapture(void) ;

#if(!Recorre_Uno_UsingFixedFunction) /* UDB Prototypes */
    #if (Recorre_Uno_SoftwareCaptureMode)
        void    Recorre_Uno_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Recorre_Uno_UsingFixedFunction) */

    #if (Recorre_Uno_SoftwareTriggerMode)
        void    Recorre_Uno_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Recorre_Uno_SoftwareTriggerMode) */

    #if (Recorre_Uno_EnableTriggerMode)
        void    Recorre_Uno_EnableTrigger(void) ;
        void    Recorre_Uno_DisableTrigger(void) ;
    #endif /* (Recorre_Uno_EnableTriggerMode) */


    #if(Recorre_Uno_InterruptOnCaptureCount)
        void    Recorre_Uno_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (Recorre_Uno_InterruptOnCaptureCount) */

    #if (Recorre_Uno_UsingHWCaptureCounter)
        void    Recorre_Uno_SetCaptureCount(uint8 captureCount) ;
        uint8   Recorre_Uno_ReadCaptureCount(void) ;
    #endif /* (Recorre_Uno_UsingHWCaptureCounter) */

    void Recorre_Uno_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Recorre_Uno_Init(void)          ;
void Recorre_Uno_Enable(void)        ;
void Recorre_Uno_SaveConfig(void)    ;
void Recorre_Uno_RestoreConfig(void) ;
void Recorre_Uno_Sleep(void)         ;
void Recorre_Uno_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Recorre_Uno__B_TIMER__CM_NONE 0
#define Recorre_Uno__B_TIMER__CM_RISINGEDGE 1
#define Recorre_Uno__B_TIMER__CM_FALLINGEDGE 2
#define Recorre_Uno__B_TIMER__CM_EITHEREDGE 3
#define Recorre_Uno__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Recorre_Uno__B_TIMER__TM_NONE 0x00u
#define Recorre_Uno__B_TIMER__TM_RISINGEDGE 0x04u
#define Recorre_Uno__B_TIMER__TM_FALLINGEDGE 0x08u
#define Recorre_Uno__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Recorre_Uno__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Recorre_Uno_INIT_PERIOD             99999u
#define Recorre_Uno_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << Recorre_Uno_CTRL_CAP_MODE_SHIFT))
#define Recorre_Uno_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << Recorre_Uno_CTRL_TRIG_MODE_SHIFT))
#if (Recorre_Uno_UsingFixedFunction)
    #define Recorre_Uno_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Recorre_Uno_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << Recorre_Uno_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define Recorre_Uno_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Recorre_Uno_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Recorre_Uno_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Recorre_Uno_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (Recorre_Uno_UsingFixedFunction) */
#define Recorre_Uno_INIT_CAPTURE_COUNT      (2u)
#define Recorre_Uno_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << Recorre_Uno_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (Recorre_Uno_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Recorre_Uno_STATUS         (*(reg8 *) Recorre_Uno_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Recorre_Uno_STATUS_MASK    (*(reg8 *) Recorre_Uno_TimerHW__SR0 )
    #define Recorre_Uno_CONTROL        (*(reg8 *) Recorre_Uno_TimerHW__CFG0)
    #define Recorre_Uno_CONTROL2       (*(reg8 *) Recorre_Uno_TimerHW__CFG1)
    #define Recorre_Uno_CONTROL2_PTR   ( (reg8 *) Recorre_Uno_TimerHW__CFG1)
    #define Recorre_Uno_RT1            (*(reg8 *) Recorre_Uno_TimerHW__RT1)
    #define Recorre_Uno_RT1_PTR        ( (reg8 *) Recorre_Uno_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Recorre_Uno_CONTROL3       (*(reg8 *) Recorre_Uno_TimerHW__CFG2)
        #define Recorre_Uno_CONTROL3_PTR   ( (reg8 *) Recorre_Uno_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Recorre_Uno_GLOBAL_ENABLE  (*(reg8 *) Recorre_Uno_TimerHW__PM_ACT_CFG)
    #define Recorre_Uno_GLOBAL_STBY_ENABLE  (*(reg8 *) Recorre_Uno_TimerHW__PM_STBY_CFG)

    #define Recorre_Uno_CAPTURE_LSB         (* (reg16 *) Recorre_Uno_TimerHW__CAP0 )
    #define Recorre_Uno_CAPTURE_LSB_PTR       ((reg16 *) Recorre_Uno_TimerHW__CAP0 )
    #define Recorre_Uno_PERIOD_LSB          (* (reg16 *) Recorre_Uno_TimerHW__PER0 )
    #define Recorre_Uno_PERIOD_LSB_PTR        ((reg16 *) Recorre_Uno_TimerHW__PER0 )
    #define Recorre_Uno_COUNTER_LSB         (* (reg16 *) Recorre_Uno_TimerHW__CNT_CMP0 )
    #define Recorre_Uno_COUNTER_LSB_PTR       ((reg16 *) Recorre_Uno_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Recorre_Uno_BLOCK_EN_MASK                     Recorre_Uno_TimerHW__PM_ACT_MSK
    #define Recorre_Uno_BLOCK_STBY_EN_MASK                Recorre_Uno_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Recorre_Uno_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Recorre_Uno_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Recorre_Uno_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Recorre_Uno_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Recorre_Uno_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Recorre_Uno_CTRL_ENABLE                        ((uint8)((uint8)0x01u << Recorre_Uno_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Recorre_Uno_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Recorre_Uno_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << Recorre_Uno_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Recorre_Uno_CTRL_MODE_SHIFT                 0x01u
        #define Recorre_Uno_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << Recorre_Uno_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Recorre_Uno_CTRL_RCOD_SHIFT        0x02u
        #define Recorre_Uno_CTRL_ENBL_SHIFT        0x00u
        #define Recorre_Uno_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Recorre_Uno_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << Recorre_Uno_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define Recorre_Uno_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << Recorre_Uno_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define Recorre_Uno_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << Recorre_Uno_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define Recorre_Uno_CTRL_RCOD       ((uint8)((uint8)0x03u << Recorre_Uno_CTRL_RCOD_SHIFT))
        #define Recorre_Uno_CTRL_ENBL       ((uint8)((uint8)0x80u << Recorre_Uno_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Recorre_Uno_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Recorre_Uno_RT1_MASK                        ((uint8)((uint8)0x03u << Recorre_Uno_RT1_SHIFT))
    #define Recorre_Uno_SYNC                            ((uint8)((uint8)0x03u << Recorre_Uno_RT1_SHIFT))
    #define Recorre_Uno_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Recorre_Uno_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << Recorre_Uno_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define Recorre_Uno_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << Recorre_Uno_SYNCDSI_SHIFT))

    #define Recorre_Uno_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << Recorre_Uno_CTRL_MODE_SHIFT))
    #define Recorre_Uno_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << Recorre_Uno_CTRL_MODE_SHIFT))
    #define Recorre_Uno_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << Recorre_Uno_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Recorre_Uno_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Recorre_Uno_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Recorre_Uno_STATUS_TC_INT_MASK_SHIFT        (Recorre_Uno_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Recorre_Uno_STATUS_CAPTURE_INT_MASK_SHIFT   (Recorre_Uno_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define Recorre_Uno_STATUS_TC                       ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_TC_SHIFT))
    #define Recorre_Uno_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Recorre_Uno_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Recorre_Uno_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Recorre_Uno_STATUS              (* (reg8 *) Recorre_Uno_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Recorre_Uno_STATUS_MASK         (* (reg8 *) Recorre_Uno_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Recorre_Uno_STATUS_AUX_CTRL     (* (reg8 *) Recorre_Uno_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Recorre_Uno_CONTROL             (* (reg8 *) Recorre_Uno_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(Recorre_Uno_Resolution <= 8u) /* 8-bit Timer */
        #define Recorre_Uno_CAPTURE_LSB         (* (reg8 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Recorre_Uno_CAPTURE_LSB_PTR       ((reg8 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Recorre_Uno_PERIOD_LSB          (* (reg8 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Recorre_Uno_PERIOD_LSB_PTR        ((reg8 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Recorre_Uno_COUNTER_LSB         (* (reg8 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
        #define Recorre_Uno_COUNTER_LSB_PTR       ((reg8 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
    #elif(Recorre_Uno_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define Recorre_Uno_CAPTURE_LSB         (* (reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Recorre_Uno_CAPTURE_LSB_PTR       ((reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Recorre_Uno_PERIOD_LSB          (* (reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Recorre_Uno_PERIOD_LSB_PTR        ((reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Recorre_Uno_COUNTER_LSB         (* (reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
            #define Recorre_Uno_COUNTER_LSB_PTR       ((reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Recorre_Uno_CAPTURE_LSB         (* (reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG )
            #define Recorre_Uno_CAPTURE_LSB_PTR       ((reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG )
            #define Recorre_Uno_PERIOD_LSB          (* (reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG )
            #define Recorre_Uno_PERIOD_LSB_PTR        ((reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG )
            #define Recorre_Uno_COUNTER_LSB         (* (reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG )
            #define Recorre_Uno_COUNTER_LSB_PTR       ((reg16 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(Recorre_Uno_Resolution <= 24u)/* 24-bit Timer */
        #define Recorre_Uno_CAPTURE_LSB         (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Recorre_Uno_CAPTURE_LSB_PTR       ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Recorre_Uno_PERIOD_LSB          (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Recorre_Uno_PERIOD_LSB_PTR        ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Recorre_Uno_COUNTER_LSB         (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
        #define Recorre_Uno_COUNTER_LSB_PTR       ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Recorre_Uno_CAPTURE_LSB         (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Recorre_Uno_CAPTURE_LSB_PTR       ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Recorre_Uno_PERIOD_LSB          (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Recorre_Uno_PERIOD_LSB_PTR        ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Recorre_Uno_COUNTER_LSB         (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
            #define Recorre_Uno_COUNTER_LSB_PTR       ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Recorre_Uno_CAPTURE_LSB         (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__32BIT_F0_REG )
            #define Recorre_Uno_CAPTURE_LSB_PTR       ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__32BIT_F0_REG )
            #define Recorre_Uno_PERIOD_LSB          (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__32BIT_D0_REG )
            #define Recorre_Uno_PERIOD_LSB_PTR        ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__32BIT_D0_REG )
            #define Recorre_Uno_COUNTER_LSB         (* (reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__32BIT_A0_REG )
            #define Recorre_Uno_COUNTER_LSB_PTR       ((reg32 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define Recorre_Uno_COUNTER_LSB_PTR_8BIT       ((reg8 *) Recorre_Uno_TimerUDB_sT24_timerdp_u0__A0_REG )
    
    #if (Recorre_Uno_UsingHWCaptureCounter)
        #define Recorre_Uno_CAP_COUNT              (*(reg8 *) Recorre_Uno_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Recorre_Uno_CAP_COUNT_PTR          ( (reg8 *) Recorre_Uno_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Recorre_Uno_CAPTURE_COUNT_CTRL     (*(reg8 *) Recorre_Uno_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Recorre_Uno_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Recorre_Uno_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Recorre_Uno_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Recorre_Uno_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Recorre_Uno_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Recorre_Uno_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Recorre_Uno_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Recorre_Uno_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Recorre_Uno_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << Recorre_Uno_CTRL_INTCNT_SHIFT))
    #define Recorre_Uno_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << Recorre_Uno_CTRL_TRIG_MODE_SHIFT))
    #define Recorre_Uno_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << Recorre_Uno_CTRL_TRIG_EN_SHIFT))
    #define Recorre_Uno_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << Recorre_Uno_CTRL_CAP_MODE_SHIFT))
    #define Recorre_Uno_CTRL_ENABLE                    ((uint8)((uint8)0x01u << Recorre_Uno_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Recorre_Uno_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Recorre_Uno_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Recorre_Uno_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Recorre_Uno_STATUS_TC_INT_MASK_SHIFT       Recorre_Uno_STATUS_TC_SHIFT
    #define Recorre_Uno_STATUS_CAPTURE_INT_MASK_SHIFT  Recorre_Uno_STATUS_CAPTURE_SHIFT
    #define Recorre_Uno_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Recorre_Uno_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Recorre_Uno_STATUS_FIFOFULL_INT_MASK_SHIFT Recorre_Uno_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Recorre_Uno_STATUS_TC                      ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define Recorre_Uno_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Recorre_Uno_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Recorre_Uno_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Recorre_Uno_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Recorre_Uno_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Recorre_Uno_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << Recorre_Uno_STATUS_FIFOFULL_SHIFT))

    #define Recorre_Uno_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Recorre_Uno_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Recorre_Uno_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Recorre_Uno_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Recorre_Uno_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Recorre_Uno_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_Recorre_Uno_H */


/* [] END OF FILE */
