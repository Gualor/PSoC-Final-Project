/*******************************************************************************
* File Name: MOSI_IMU.h  
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

#if !defined(CY_PINS_MOSI_IMU_H) /* Pins MOSI_IMU_H */
#define CY_PINS_MOSI_IMU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOSI_IMU_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOSI_IMU__PORT == 15 && ((MOSI_IMU__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOSI_IMU_Write(uint8 value);
void    MOSI_IMU_SetDriveMode(uint8 mode);
uint8   MOSI_IMU_ReadDataReg(void);
uint8   MOSI_IMU_Read(void);
void    MOSI_IMU_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOSI_IMU_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOSI_IMU_SetDriveMode() function.
     *  @{
     */
        #define MOSI_IMU_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOSI_IMU_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOSI_IMU_DM_RES_UP          PIN_DM_RES_UP
        #define MOSI_IMU_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOSI_IMU_DM_OD_LO           PIN_DM_OD_LO
        #define MOSI_IMU_DM_OD_HI           PIN_DM_OD_HI
        #define MOSI_IMU_DM_STRONG          PIN_DM_STRONG
        #define MOSI_IMU_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOSI_IMU_MASK               MOSI_IMU__MASK
#define MOSI_IMU_SHIFT              MOSI_IMU__SHIFT
#define MOSI_IMU_WIDTH              1u

/* Interrupt constants */
#if defined(MOSI_IMU__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOSI_IMU_SetInterruptMode() function.
     *  @{
     */
        #define MOSI_IMU_INTR_NONE      (uint16)(0x0000u)
        #define MOSI_IMU_INTR_RISING    (uint16)(0x0001u)
        #define MOSI_IMU_INTR_FALLING   (uint16)(0x0002u)
        #define MOSI_IMU_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOSI_IMU_INTR_MASK      (0x01u) 
#endif /* (MOSI_IMU__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOSI_IMU_PS                     (* (reg8 *) MOSI_IMU__PS)
/* Data Register */
#define MOSI_IMU_DR                     (* (reg8 *) MOSI_IMU__DR)
/* Port Number */
#define MOSI_IMU_PRT_NUM                (* (reg8 *) MOSI_IMU__PRT) 
/* Connect to Analog Globals */                                                  
#define MOSI_IMU_AG                     (* (reg8 *) MOSI_IMU__AG)                       
/* Analog MUX bux enable */
#define MOSI_IMU_AMUX                   (* (reg8 *) MOSI_IMU__AMUX) 
/* Bidirectional Enable */                                                        
#define MOSI_IMU_BIE                    (* (reg8 *) MOSI_IMU__BIE)
/* Bit-mask for Aliased Register Access */
#define MOSI_IMU_BIT_MASK               (* (reg8 *) MOSI_IMU__BIT_MASK)
/* Bypass Enable */
#define MOSI_IMU_BYP                    (* (reg8 *) MOSI_IMU__BYP)
/* Port wide control signals */                                                   
#define MOSI_IMU_CTL                    (* (reg8 *) MOSI_IMU__CTL)
/* Drive Modes */
#define MOSI_IMU_DM0                    (* (reg8 *) MOSI_IMU__DM0) 
#define MOSI_IMU_DM1                    (* (reg8 *) MOSI_IMU__DM1)
#define MOSI_IMU_DM2                    (* (reg8 *) MOSI_IMU__DM2) 
/* Input Buffer Disable Override */
#define MOSI_IMU_INP_DIS                (* (reg8 *) MOSI_IMU__INP_DIS)
/* LCD Common or Segment Drive */
#define MOSI_IMU_LCD_COM_SEG            (* (reg8 *) MOSI_IMU__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOSI_IMU_LCD_EN                 (* (reg8 *) MOSI_IMU__LCD_EN)
/* Slew Rate Control */
#define MOSI_IMU_SLW                    (* (reg8 *) MOSI_IMU__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOSI_IMU_PRTDSI__CAPS_SEL       (* (reg8 *) MOSI_IMU__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOSI_IMU_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOSI_IMU__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOSI_IMU_PRTDSI__OE_SEL0        (* (reg8 *) MOSI_IMU__PRTDSI__OE_SEL0) 
#define MOSI_IMU_PRTDSI__OE_SEL1        (* (reg8 *) MOSI_IMU__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOSI_IMU_PRTDSI__OUT_SEL0       (* (reg8 *) MOSI_IMU__PRTDSI__OUT_SEL0) 
#define MOSI_IMU_PRTDSI__OUT_SEL1       (* (reg8 *) MOSI_IMU__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOSI_IMU_PRTDSI__SYNC_OUT       (* (reg8 *) MOSI_IMU__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOSI_IMU__SIO_CFG)
    #define MOSI_IMU_SIO_HYST_EN        (* (reg8 *) MOSI_IMU__SIO_HYST_EN)
    #define MOSI_IMU_SIO_REG_HIFREQ     (* (reg8 *) MOSI_IMU__SIO_REG_HIFREQ)
    #define MOSI_IMU_SIO_CFG            (* (reg8 *) MOSI_IMU__SIO_CFG)
    #define MOSI_IMU_SIO_DIFF           (* (reg8 *) MOSI_IMU__SIO_DIFF)
#endif /* (MOSI_IMU__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOSI_IMU__INTSTAT)
    #define MOSI_IMU_INTSTAT            (* (reg8 *) MOSI_IMU__INTSTAT)
    #define MOSI_IMU_SNAP               (* (reg8 *) MOSI_IMU__SNAP)
    
	#define MOSI_IMU_0_INTTYPE_REG 		(* (reg8 *) MOSI_IMU__0__INTTYPE)
#endif /* (MOSI_IMU__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOSI_IMU_H */


/* [] END OF FILE */
