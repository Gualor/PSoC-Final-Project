/*******************************************************************************
* File Name: ONBOARD_LED.h  
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

#if !defined(CY_PINS_ONBOARD_LED_H) /* Pins ONBOARD_LED_H */
#define CY_PINS_ONBOARD_LED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ONBOARD_LED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ONBOARD_LED__PORT == 15 && ((ONBOARD_LED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ONBOARD_LED_Write(uint8 value);
void    ONBOARD_LED_SetDriveMode(uint8 mode);
uint8   ONBOARD_LED_ReadDataReg(void);
uint8   ONBOARD_LED_Read(void);
void    ONBOARD_LED_SetInterruptMode(uint16 position, uint16 mode);
uint8   ONBOARD_LED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ONBOARD_LED_SetDriveMode() function.
     *  @{
     */
        #define ONBOARD_LED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ONBOARD_LED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ONBOARD_LED_DM_RES_UP          PIN_DM_RES_UP
        #define ONBOARD_LED_DM_RES_DWN         PIN_DM_RES_DWN
        #define ONBOARD_LED_DM_OD_LO           PIN_DM_OD_LO
        #define ONBOARD_LED_DM_OD_HI           PIN_DM_OD_HI
        #define ONBOARD_LED_DM_STRONG          PIN_DM_STRONG
        #define ONBOARD_LED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ONBOARD_LED_MASK               ONBOARD_LED__MASK
#define ONBOARD_LED_SHIFT              ONBOARD_LED__SHIFT
#define ONBOARD_LED_WIDTH              1u

/* Interrupt constants */
#if defined(ONBOARD_LED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ONBOARD_LED_SetInterruptMode() function.
     *  @{
     */
        #define ONBOARD_LED_INTR_NONE      (uint16)(0x0000u)
        #define ONBOARD_LED_INTR_RISING    (uint16)(0x0001u)
        #define ONBOARD_LED_INTR_FALLING   (uint16)(0x0002u)
        #define ONBOARD_LED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ONBOARD_LED_INTR_MASK      (0x01u) 
#endif /* (ONBOARD_LED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ONBOARD_LED_PS                     (* (reg8 *) ONBOARD_LED__PS)
/* Data Register */
#define ONBOARD_LED_DR                     (* (reg8 *) ONBOARD_LED__DR)
/* Port Number */
#define ONBOARD_LED_PRT_NUM                (* (reg8 *) ONBOARD_LED__PRT) 
/* Connect to Analog Globals */                                                  
#define ONBOARD_LED_AG                     (* (reg8 *) ONBOARD_LED__AG)                       
/* Analog MUX bux enable */
#define ONBOARD_LED_AMUX                   (* (reg8 *) ONBOARD_LED__AMUX) 
/* Bidirectional Enable */                                                        
#define ONBOARD_LED_BIE                    (* (reg8 *) ONBOARD_LED__BIE)
/* Bit-mask for Aliased Register Access */
#define ONBOARD_LED_BIT_MASK               (* (reg8 *) ONBOARD_LED__BIT_MASK)
/* Bypass Enable */
#define ONBOARD_LED_BYP                    (* (reg8 *) ONBOARD_LED__BYP)
/* Port wide control signals */                                                   
#define ONBOARD_LED_CTL                    (* (reg8 *) ONBOARD_LED__CTL)
/* Drive Modes */
#define ONBOARD_LED_DM0                    (* (reg8 *) ONBOARD_LED__DM0) 
#define ONBOARD_LED_DM1                    (* (reg8 *) ONBOARD_LED__DM1)
#define ONBOARD_LED_DM2                    (* (reg8 *) ONBOARD_LED__DM2) 
/* Input Buffer Disable Override */
#define ONBOARD_LED_INP_DIS                (* (reg8 *) ONBOARD_LED__INP_DIS)
/* LCD Common or Segment Drive */
#define ONBOARD_LED_LCD_COM_SEG            (* (reg8 *) ONBOARD_LED__LCD_COM_SEG)
/* Enable Segment LCD */
#define ONBOARD_LED_LCD_EN                 (* (reg8 *) ONBOARD_LED__LCD_EN)
/* Slew Rate Control */
#define ONBOARD_LED_SLW                    (* (reg8 *) ONBOARD_LED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ONBOARD_LED_PRTDSI__CAPS_SEL       (* (reg8 *) ONBOARD_LED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ONBOARD_LED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ONBOARD_LED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ONBOARD_LED_PRTDSI__OE_SEL0        (* (reg8 *) ONBOARD_LED__PRTDSI__OE_SEL0) 
#define ONBOARD_LED_PRTDSI__OE_SEL1        (* (reg8 *) ONBOARD_LED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ONBOARD_LED_PRTDSI__OUT_SEL0       (* (reg8 *) ONBOARD_LED__PRTDSI__OUT_SEL0) 
#define ONBOARD_LED_PRTDSI__OUT_SEL1       (* (reg8 *) ONBOARD_LED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ONBOARD_LED_PRTDSI__SYNC_OUT       (* (reg8 *) ONBOARD_LED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ONBOARD_LED__SIO_CFG)
    #define ONBOARD_LED_SIO_HYST_EN        (* (reg8 *) ONBOARD_LED__SIO_HYST_EN)
    #define ONBOARD_LED_SIO_REG_HIFREQ     (* (reg8 *) ONBOARD_LED__SIO_REG_HIFREQ)
    #define ONBOARD_LED_SIO_CFG            (* (reg8 *) ONBOARD_LED__SIO_CFG)
    #define ONBOARD_LED_SIO_DIFF           (* (reg8 *) ONBOARD_LED__SIO_DIFF)
#endif /* (ONBOARD_LED__SIO_CFG) */

/* Interrupt Registers */
#if defined(ONBOARD_LED__INTSTAT)
    #define ONBOARD_LED_INTSTAT            (* (reg8 *) ONBOARD_LED__INTSTAT)
    #define ONBOARD_LED_SNAP               (* (reg8 *) ONBOARD_LED__SNAP)
    
	#define ONBOARD_LED_0_INTTYPE_REG 		(* (reg8 *) ONBOARD_LED__0__INTTYPE)
#endif /* (ONBOARD_LED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ONBOARD_LED_H */


/* [] END OF FILE */
