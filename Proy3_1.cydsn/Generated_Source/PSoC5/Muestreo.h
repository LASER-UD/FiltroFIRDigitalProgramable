/*******************************************************************************
* File Name: Muestreo.h
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

#if !defined(CY_TIMER_Muestreo_H)
#define CY_TIMER_Muestreo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Muestreo_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Muestreo_Resolution                 8u
#define Muestreo_UsingFixedFunction         1u
#define Muestreo_UsingHWCaptureCounter      0u
#define Muestreo_SoftwareCaptureMode        0u
#define Muestreo_SoftwareTriggerMode        0u
#define Muestreo_UsingHWEnable              0u
#define Muestreo_EnableTriggerMode          0u
#define Muestreo_InterruptOnCaptureCount    0u
#define Muestreo_RunModeUsed                0u
#define Muestreo_ControlRegRemoved          0u

#if defined(Muestreo_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define Muestreo_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (Muestreo_UsingFixedFunction)
    #define Muestreo_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define Muestreo_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End Muestreo_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!Muestreo_UsingFixedFunction)

        uint8 TimerUdb;
        uint8 InterruptMaskValue;
        #if (Muestreo_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!Muestreo_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}Muestreo_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Muestreo_Start(void) ;
void    Muestreo_Stop(void) ;

void    Muestreo_SetInterruptMode(uint8 interruptMode) ;
uint8   Muestreo_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Muestreo_GetInterruptSource() Muestreo_ReadStatusRegister()

#if(!Muestreo_UDB_CONTROL_REG_REMOVED)
    uint8   Muestreo_ReadControlRegister(void) ;
    void    Muestreo_WriteControlRegister(uint8 control) ;
#endif /* (!Muestreo_UDB_CONTROL_REG_REMOVED) */

uint8  Muestreo_ReadPeriod(void) ;
void    Muestreo_WritePeriod(uint8 period) ;
uint8  Muestreo_ReadCounter(void) ;
void    Muestreo_WriteCounter(uint8 counter) ;
uint8  Muestreo_ReadCapture(void) ;
void    Muestreo_SoftwareCapture(void) ;

#if(!Muestreo_UsingFixedFunction) /* UDB Prototypes */
    #if (Muestreo_SoftwareCaptureMode)
        void    Muestreo_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Muestreo_UsingFixedFunction) */

    #if (Muestreo_SoftwareTriggerMode)
        void    Muestreo_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Muestreo_SoftwareTriggerMode) */

    #if (Muestreo_EnableTriggerMode)
        void    Muestreo_EnableTrigger(void) ;
        void    Muestreo_DisableTrigger(void) ;
    #endif /* (Muestreo_EnableTriggerMode) */


    #if(Muestreo_InterruptOnCaptureCount)
        void    Muestreo_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (Muestreo_InterruptOnCaptureCount) */

    #if (Muestreo_UsingHWCaptureCounter)
        void    Muestreo_SetCaptureCount(uint8 captureCount) ;
        uint8   Muestreo_ReadCaptureCount(void) ;
    #endif /* (Muestreo_UsingHWCaptureCounter) */

    void Muestreo_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Muestreo_Init(void)          ;
void Muestreo_Enable(void)        ;
void Muestreo_SaveConfig(void)    ;
void Muestreo_RestoreConfig(void) ;
void Muestreo_Sleep(void)         ;
void Muestreo_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Muestreo__B_TIMER__CM_NONE 0
#define Muestreo__B_TIMER__CM_RISINGEDGE 1
#define Muestreo__B_TIMER__CM_FALLINGEDGE 2
#define Muestreo__B_TIMER__CM_EITHEREDGE 3
#define Muestreo__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Muestreo__B_TIMER__TM_NONE 0x00u
#define Muestreo__B_TIMER__TM_RISINGEDGE 0x04u
#define Muestreo__B_TIMER__TM_FALLINGEDGE 0x08u
#define Muestreo__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Muestreo__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Muestreo_INIT_PERIOD             9u
#define Muestreo_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << Muestreo_CTRL_CAP_MODE_SHIFT))
#define Muestreo_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << Muestreo_CTRL_TRIG_MODE_SHIFT))
#if (Muestreo_UsingFixedFunction)
    #define Muestreo_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Muestreo_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << Muestreo_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define Muestreo_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Muestreo_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Muestreo_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Muestreo_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (Muestreo_UsingFixedFunction) */
#define Muestreo_INIT_CAPTURE_COUNT      (2u)
#define Muestreo_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << Muestreo_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (Muestreo_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Muestreo_STATUS         (*(reg8 *) Muestreo_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Muestreo_STATUS_MASK    (*(reg8 *) Muestreo_TimerHW__SR0 )
    #define Muestreo_CONTROL        (*(reg8 *) Muestreo_TimerHW__CFG0)
    #define Muestreo_CONTROL2       (*(reg8 *) Muestreo_TimerHW__CFG1)
    #define Muestreo_CONTROL2_PTR   ( (reg8 *) Muestreo_TimerHW__CFG1)
    #define Muestreo_RT1            (*(reg8 *) Muestreo_TimerHW__RT1)
    #define Muestreo_RT1_PTR        ( (reg8 *) Muestreo_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Muestreo_CONTROL3       (*(reg8 *) Muestreo_TimerHW__CFG2)
        #define Muestreo_CONTROL3_PTR   ( (reg8 *) Muestreo_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Muestreo_GLOBAL_ENABLE  (*(reg8 *) Muestreo_TimerHW__PM_ACT_CFG)
    #define Muestreo_GLOBAL_STBY_ENABLE  (*(reg8 *) Muestreo_TimerHW__PM_STBY_CFG)

    #define Muestreo_CAPTURE_LSB         (* (reg16 *) Muestreo_TimerHW__CAP0 )
    #define Muestreo_CAPTURE_LSB_PTR       ((reg16 *) Muestreo_TimerHW__CAP0 )
    #define Muestreo_PERIOD_LSB          (* (reg16 *) Muestreo_TimerHW__PER0 )
    #define Muestreo_PERIOD_LSB_PTR        ((reg16 *) Muestreo_TimerHW__PER0 )
    #define Muestreo_COUNTER_LSB         (* (reg16 *) Muestreo_TimerHW__CNT_CMP0 )
    #define Muestreo_COUNTER_LSB_PTR       ((reg16 *) Muestreo_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Muestreo_BLOCK_EN_MASK                     Muestreo_TimerHW__PM_ACT_MSK
    #define Muestreo_BLOCK_STBY_EN_MASK                Muestreo_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Muestreo_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Muestreo_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Muestreo_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Muestreo_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Muestreo_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Muestreo_CTRL_ENABLE                        ((uint8)((uint8)0x01u << Muestreo_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Muestreo_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Muestreo_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << Muestreo_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Muestreo_CTRL_MODE_SHIFT                 0x01u
        #define Muestreo_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << Muestreo_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Muestreo_CTRL_RCOD_SHIFT        0x02u
        #define Muestreo_CTRL_ENBL_SHIFT        0x00u
        #define Muestreo_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Muestreo_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << Muestreo_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define Muestreo_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << Muestreo_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define Muestreo_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << Muestreo_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define Muestreo_CTRL_RCOD       ((uint8)((uint8)0x03u << Muestreo_CTRL_RCOD_SHIFT))
        #define Muestreo_CTRL_ENBL       ((uint8)((uint8)0x80u << Muestreo_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Muestreo_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Muestreo_RT1_MASK                        ((uint8)((uint8)0x03u << Muestreo_RT1_SHIFT))
    #define Muestreo_SYNC                            ((uint8)((uint8)0x03u << Muestreo_RT1_SHIFT))
    #define Muestreo_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Muestreo_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << Muestreo_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define Muestreo_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << Muestreo_SYNCDSI_SHIFT))

    #define Muestreo_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << Muestreo_CTRL_MODE_SHIFT))
    #define Muestreo_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << Muestreo_CTRL_MODE_SHIFT))
    #define Muestreo_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << Muestreo_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Muestreo_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Muestreo_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Muestreo_STATUS_TC_INT_MASK_SHIFT        (Muestreo_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Muestreo_STATUS_CAPTURE_INT_MASK_SHIFT   (Muestreo_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define Muestreo_STATUS_TC                       ((uint8)((uint8)0x01u << Muestreo_STATUS_TC_SHIFT))
    #define Muestreo_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << Muestreo_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Muestreo_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << Muestreo_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Muestreo_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << Muestreo_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Muestreo_STATUS              (* (reg8 *) Muestreo_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Muestreo_STATUS_MASK         (* (reg8 *) Muestreo_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Muestreo_STATUS_AUX_CTRL     (* (reg8 *) Muestreo_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Muestreo_CONTROL             (* (reg8 *) Muestreo_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(Muestreo_Resolution <= 8u) /* 8-bit Timer */
        #define Muestreo_CAPTURE_LSB         (* (reg8 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Muestreo_CAPTURE_LSB_PTR       ((reg8 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Muestreo_PERIOD_LSB          (* (reg8 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Muestreo_PERIOD_LSB_PTR        ((reg8 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Muestreo_COUNTER_LSB         (* (reg8 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define Muestreo_COUNTER_LSB_PTR       ((reg8 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(Muestreo_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define Muestreo_CAPTURE_LSB         (* (reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Muestreo_CAPTURE_LSB_PTR       ((reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Muestreo_PERIOD_LSB          (* (reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Muestreo_PERIOD_LSB_PTR        ((reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Muestreo_COUNTER_LSB         (* (reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define Muestreo_COUNTER_LSB_PTR       ((reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Muestreo_CAPTURE_LSB         (* (reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define Muestreo_CAPTURE_LSB_PTR       ((reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define Muestreo_PERIOD_LSB          (* (reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define Muestreo_PERIOD_LSB_PTR        ((reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define Muestreo_COUNTER_LSB         (* (reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define Muestreo_COUNTER_LSB_PTR       ((reg16 *) Muestreo_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(Muestreo_Resolution <= 24u)/* 24-bit Timer */
        #define Muestreo_CAPTURE_LSB         (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Muestreo_CAPTURE_LSB_PTR       ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define Muestreo_PERIOD_LSB          (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Muestreo_PERIOD_LSB_PTR        ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define Muestreo_COUNTER_LSB         (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define Muestreo_COUNTER_LSB_PTR       ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Muestreo_CAPTURE_LSB         (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Muestreo_CAPTURE_LSB_PTR       ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define Muestreo_PERIOD_LSB          (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Muestreo_PERIOD_LSB_PTR        ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define Muestreo_COUNTER_LSB         (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define Muestreo_COUNTER_LSB_PTR       ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Muestreo_CAPTURE_LSB         (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define Muestreo_CAPTURE_LSB_PTR       ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define Muestreo_PERIOD_LSB          (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define Muestreo_PERIOD_LSB_PTR        ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define Muestreo_COUNTER_LSB         (* (reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define Muestreo_COUNTER_LSB_PTR       ((reg32 *) Muestreo_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define Muestreo_COUNTER_LSB_PTR_8BIT       ((reg8 *) Muestreo_TimerUDB_sT8_timerdp_u0__A0_REG )
    
    #if (Muestreo_UsingHWCaptureCounter)
        #define Muestreo_CAP_COUNT              (*(reg8 *) Muestreo_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Muestreo_CAP_COUNT_PTR          ( (reg8 *) Muestreo_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Muestreo_CAPTURE_COUNT_CTRL     (*(reg8 *) Muestreo_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Muestreo_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Muestreo_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Muestreo_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Muestreo_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Muestreo_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Muestreo_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Muestreo_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Muestreo_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Muestreo_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << Muestreo_CTRL_INTCNT_SHIFT))
    #define Muestreo_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << Muestreo_CTRL_TRIG_MODE_SHIFT))
    #define Muestreo_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << Muestreo_CTRL_TRIG_EN_SHIFT))
    #define Muestreo_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << Muestreo_CTRL_CAP_MODE_SHIFT))
    #define Muestreo_CTRL_ENABLE                    ((uint8)((uint8)0x01u << Muestreo_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Muestreo_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Muestreo_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Muestreo_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Muestreo_STATUS_TC_INT_MASK_SHIFT       Muestreo_STATUS_TC_SHIFT
    #define Muestreo_STATUS_CAPTURE_INT_MASK_SHIFT  Muestreo_STATUS_CAPTURE_SHIFT
    #define Muestreo_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Muestreo_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Muestreo_STATUS_FIFOFULL_INT_MASK_SHIFT Muestreo_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Muestreo_STATUS_TC                      ((uint8)((uint8)0x01u << Muestreo_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define Muestreo_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << Muestreo_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Muestreo_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << Muestreo_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Muestreo_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << Muestreo_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Muestreo_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << Muestreo_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Muestreo_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << Muestreo_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Muestreo_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << Muestreo_STATUS_FIFOFULL_SHIFT))

    #define Muestreo_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Muestreo_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Muestreo_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Muestreo_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Muestreo_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Muestreo_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_Muestreo_H */


/* [] END OF FILE */
