/*******************************************************************************
* File Name: POT_PIN.h  
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

#if !defined(CY_PINS_POT_PIN_H) /* Pins POT_PIN_H */
#define CY_PINS_POT_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "POT_PIN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 POT_PIN__PORT == 15 && ((POT_PIN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    POT_PIN_Write(uint8 value);
void    POT_PIN_SetDriveMode(uint8 mode);
uint8   POT_PIN_ReadDataReg(void);
uint8   POT_PIN_Read(void);
void    POT_PIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   POT_PIN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the POT_PIN_SetDriveMode() function.
     *  @{
     */
        #define POT_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define POT_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define POT_PIN_DM_RES_UP          PIN_DM_RES_UP
        #define POT_PIN_DM_RES_DWN         PIN_DM_RES_DWN
        #define POT_PIN_DM_OD_LO           PIN_DM_OD_LO
        #define POT_PIN_DM_OD_HI           PIN_DM_OD_HI
        #define POT_PIN_DM_STRONG          PIN_DM_STRONG
        #define POT_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define POT_PIN_MASK               POT_PIN__MASK
#define POT_PIN_SHIFT              POT_PIN__SHIFT
#define POT_PIN_WIDTH              1u

/* Interrupt constants */
#if defined(POT_PIN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in POT_PIN_SetInterruptMode() function.
     *  @{
     */
        #define POT_PIN_INTR_NONE      (uint16)(0x0000u)
        #define POT_PIN_INTR_RISING    (uint16)(0x0001u)
        #define POT_PIN_INTR_FALLING   (uint16)(0x0002u)
        #define POT_PIN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define POT_PIN_INTR_MASK      (0x01u) 
#endif /* (POT_PIN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT_PIN_PS                     (* (reg8 *) POT_PIN__PS)
/* Data Register */
#define POT_PIN_DR                     (* (reg8 *) POT_PIN__DR)
/* Port Number */
#define POT_PIN_PRT_NUM                (* (reg8 *) POT_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define POT_PIN_AG                     (* (reg8 *) POT_PIN__AG)                       
/* Analog MUX bux enable */
#define POT_PIN_AMUX                   (* (reg8 *) POT_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define POT_PIN_BIE                    (* (reg8 *) POT_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define POT_PIN_BIT_MASK               (* (reg8 *) POT_PIN__BIT_MASK)
/* Bypass Enable */
#define POT_PIN_BYP                    (* (reg8 *) POT_PIN__BYP)
/* Port wide control signals */                                                   
#define POT_PIN_CTL                    (* (reg8 *) POT_PIN__CTL)
/* Drive Modes */
#define POT_PIN_DM0                    (* (reg8 *) POT_PIN__DM0) 
#define POT_PIN_DM1                    (* (reg8 *) POT_PIN__DM1)
#define POT_PIN_DM2                    (* (reg8 *) POT_PIN__DM2) 
/* Input Buffer Disable Override */
#define POT_PIN_INP_DIS                (* (reg8 *) POT_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define POT_PIN_LCD_COM_SEG            (* (reg8 *) POT_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define POT_PIN_LCD_EN                 (* (reg8 *) POT_PIN__LCD_EN)
/* Slew Rate Control */
#define POT_PIN_SLW                    (* (reg8 *) POT_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define POT_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) POT_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define POT_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) POT_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define POT_PIN_PRTDSI__OE_SEL0        (* (reg8 *) POT_PIN__PRTDSI__OE_SEL0) 
#define POT_PIN_PRTDSI__OE_SEL1        (* (reg8 *) POT_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define POT_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) POT_PIN__PRTDSI__OUT_SEL0) 
#define POT_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) POT_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define POT_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) POT_PIN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(POT_PIN__SIO_CFG)
    #define POT_PIN_SIO_HYST_EN        (* (reg8 *) POT_PIN__SIO_HYST_EN)
    #define POT_PIN_SIO_REG_HIFREQ     (* (reg8 *) POT_PIN__SIO_REG_HIFREQ)
    #define POT_PIN_SIO_CFG            (* (reg8 *) POT_PIN__SIO_CFG)
    #define POT_PIN_SIO_DIFF           (* (reg8 *) POT_PIN__SIO_DIFF)
#endif /* (POT_PIN__SIO_CFG) */

/* Interrupt Registers */
#if defined(POT_PIN__INTSTAT)
    #define POT_PIN_INTSTAT            (* (reg8 *) POT_PIN__INTSTAT)
    #define POT_PIN_SNAP               (* (reg8 *) POT_PIN__SNAP)
    
	#define POT_PIN_0_INTTYPE_REG 		(* (reg8 *) POT_PIN__0__INTTYPE)
#endif /* (POT_PIN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_POT_PIN_H */


/* [] END OF FILE */
