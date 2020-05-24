/*******************************************************************************
* File Name: CS_EEPROM.h  
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

#if !defined(CY_PINS_CS_EEPROM_H) /* Pins CS_EEPROM_H */
#define CY_PINS_CS_EEPROM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CS_EEPROM_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CS_EEPROM__PORT == 15 && ((CS_EEPROM__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CS_EEPROM_Write(uint8 value);
void    CS_EEPROM_SetDriveMode(uint8 mode);
uint8   CS_EEPROM_ReadDataReg(void);
uint8   CS_EEPROM_Read(void);
void    CS_EEPROM_SetInterruptMode(uint16 position, uint16 mode);
uint8   CS_EEPROM_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CS_EEPROM_SetDriveMode() function.
     *  @{
     */
        #define CS_EEPROM_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CS_EEPROM_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CS_EEPROM_DM_RES_UP          PIN_DM_RES_UP
        #define CS_EEPROM_DM_RES_DWN         PIN_DM_RES_DWN
        #define CS_EEPROM_DM_OD_LO           PIN_DM_OD_LO
        #define CS_EEPROM_DM_OD_HI           PIN_DM_OD_HI
        #define CS_EEPROM_DM_STRONG          PIN_DM_STRONG
        #define CS_EEPROM_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CS_EEPROM_MASK               CS_EEPROM__MASK
#define CS_EEPROM_SHIFT              CS_EEPROM__SHIFT
#define CS_EEPROM_WIDTH              1u

/* Interrupt constants */
#if defined(CS_EEPROM__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CS_EEPROM_SetInterruptMode() function.
     *  @{
     */
        #define CS_EEPROM_INTR_NONE      (uint16)(0x0000u)
        #define CS_EEPROM_INTR_RISING    (uint16)(0x0001u)
        #define CS_EEPROM_INTR_FALLING   (uint16)(0x0002u)
        #define CS_EEPROM_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CS_EEPROM_INTR_MASK      (0x01u) 
#endif /* (CS_EEPROM__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CS_EEPROM_PS                     (* (reg8 *) CS_EEPROM__PS)
/* Data Register */
#define CS_EEPROM_DR                     (* (reg8 *) CS_EEPROM__DR)
/* Port Number */
#define CS_EEPROM_PRT_NUM                (* (reg8 *) CS_EEPROM__PRT) 
/* Connect to Analog Globals */                                                  
#define CS_EEPROM_AG                     (* (reg8 *) CS_EEPROM__AG)                       
/* Analog MUX bux enable */
#define CS_EEPROM_AMUX                   (* (reg8 *) CS_EEPROM__AMUX) 
/* Bidirectional Enable */                                                        
#define CS_EEPROM_BIE                    (* (reg8 *) CS_EEPROM__BIE)
/* Bit-mask for Aliased Register Access */
#define CS_EEPROM_BIT_MASK               (* (reg8 *) CS_EEPROM__BIT_MASK)
/* Bypass Enable */
#define CS_EEPROM_BYP                    (* (reg8 *) CS_EEPROM__BYP)
/* Port wide control signals */                                                   
#define CS_EEPROM_CTL                    (* (reg8 *) CS_EEPROM__CTL)
/* Drive Modes */
#define CS_EEPROM_DM0                    (* (reg8 *) CS_EEPROM__DM0) 
#define CS_EEPROM_DM1                    (* (reg8 *) CS_EEPROM__DM1)
#define CS_EEPROM_DM2                    (* (reg8 *) CS_EEPROM__DM2) 
/* Input Buffer Disable Override */
#define CS_EEPROM_INP_DIS                (* (reg8 *) CS_EEPROM__INP_DIS)
/* LCD Common or Segment Drive */
#define CS_EEPROM_LCD_COM_SEG            (* (reg8 *) CS_EEPROM__LCD_COM_SEG)
/* Enable Segment LCD */
#define CS_EEPROM_LCD_EN                 (* (reg8 *) CS_EEPROM__LCD_EN)
/* Slew Rate Control */
#define CS_EEPROM_SLW                    (* (reg8 *) CS_EEPROM__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CS_EEPROM_PRTDSI__CAPS_SEL       (* (reg8 *) CS_EEPROM__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CS_EEPROM_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CS_EEPROM__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CS_EEPROM_PRTDSI__OE_SEL0        (* (reg8 *) CS_EEPROM__PRTDSI__OE_SEL0) 
#define CS_EEPROM_PRTDSI__OE_SEL1        (* (reg8 *) CS_EEPROM__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CS_EEPROM_PRTDSI__OUT_SEL0       (* (reg8 *) CS_EEPROM__PRTDSI__OUT_SEL0) 
#define CS_EEPROM_PRTDSI__OUT_SEL1       (* (reg8 *) CS_EEPROM__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CS_EEPROM_PRTDSI__SYNC_OUT       (* (reg8 *) CS_EEPROM__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CS_EEPROM__SIO_CFG)
    #define CS_EEPROM_SIO_HYST_EN        (* (reg8 *) CS_EEPROM__SIO_HYST_EN)
    #define CS_EEPROM_SIO_REG_HIFREQ     (* (reg8 *) CS_EEPROM__SIO_REG_HIFREQ)
    #define CS_EEPROM_SIO_CFG            (* (reg8 *) CS_EEPROM__SIO_CFG)
    #define CS_EEPROM_SIO_DIFF           (* (reg8 *) CS_EEPROM__SIO_DIFF)
#endif /* (CS_EEPROM__SIO_CFG) */

/* Interrupt Registers */
#if defined(CS_EEPROM__INTSTAT)
    #define CS_EEPROM_INTSTAT            (* (reg8 *) CS_EEPROM__INTSTAT)
    #define CS_EEPROM_SNAP               (* (reg8 *) CS_EEPROM__SNAP)
    
	#define CS_EEPROM_0_INTTYPE_REG 		(* (reg8 *) CS_EEPROM__0__INTTYPE)
#endif /* (CS_EEPROM__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CS_EEPROM_H */


/* [] END OF FILE */
