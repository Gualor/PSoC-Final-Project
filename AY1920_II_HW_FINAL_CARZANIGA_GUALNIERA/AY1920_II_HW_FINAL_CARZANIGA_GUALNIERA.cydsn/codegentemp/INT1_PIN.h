/*******************************************************************************
* File Name: INT1_PIN.h  
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

#if !defined(CY_PINS_INT1_PIN_H) /* Pins INT1_PIN_H */
#define CY_PINS_INT1_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "INT1_PIN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 INT1_PIN__PORT == 15 && ((INT1_PIN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    INT1_PIN_Write(uint8 value);
void    INT1_PIN_SetDriveMode(uint8 mode);
uint8   INT1_PIN_ReadDataReg(void);
uint8   INT1_PIN_Read(void);
void    INT1_PIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   INT1_PIN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the INT1_PIN_SetDriveMode() function.
     *  @{
     */
        #define INT1_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define INT1_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define INT1_PIN_DM_RES_UP          PIN_DM_RES_UP
        #define INT1_PIN_DM_RES_DWN         PIN_DM_RES_DWN
        #define INT1_PIN_DM_OD_LO           PIN_DM_OD_LO
        #define INT1_PIN_DM_OD_HI           PIN_DM_OD_HI
        #define INT1_PIN_DM_STRONG          PIN_DM_STRONG
        #define INT1_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define INT1_PIN_MASK               INT1_PIN__MASK
#define INT1_PIN_SHIFT              INT1_PIN__SHIFT
#define INT1_PIN_WIDTH              1u

/* Interrupt constants */
#if defined(INT1_PIN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in INT1_PIN_SetInterruptMode() function.
     *  @{
     */
        #define INT1_PIN_INTR_NONE      (uint16)(0x0000u)
        #define INT1_PIN_INTR_RISING    (uint16)(0x0001u)
        #define INT1_PIN_INTR_FALLING   (uint16)(0x0002u)
        #define INT1_PIN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define INT1_PIN_INTR_MASK      (0x01u) 
#endif /* (INT1_PIN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define INT1_PIN_PS                     (* (reg8 *) INT1_PIN__PS)
/* Data Register */
#define INT1_PIN_DR                     (* (reg8 *) INT1_PIN__DR)
/* Port Number */
#define INT1_PIN_PRT_NUM                (* (reg8 *) INT1_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define INT1_PIN_AG                     (* (reg8 *) INT1_PIN__AG)                       
/* Analog MUX bux enable */
#define INT1_PIN_AMUX                   (* (reg8 *) INT1_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define INT1_PIN_BIE                    (* (reg8 *) INT1_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define INT1_PIN_BIT_MASK               (* (reg8 *) INT1_PIN__BIT_MASK)
/* Bypass Enable */
#define INT1_PIN_BYP                    (* (reg8 *) INT1_PIN__BYP)
/* Port wide control signals */                                                   
#define INT1_PIN_CTL                    (* (reg8 *) INT1_PIN__CTL)
/* Drive Modes */
#define INT1_PIN_DM0                    (* (reg8 *) INT1_PIN__DM0) 
#define INT1_PIN_DM1                    (* (reg8 *) INT1_PIN__DM1)
#define INT1_PIN_DM2                    (* (reg8 *) INT1_PIN__DM2) 
/* Input Buffer Disable Override */
#define INT1_PIN_INP_DIS                (* (reg8 *) INT1_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define INT1_PIN_LCD_COM_SEG            (* (reg8 *) INT1_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define INT1_PIN_LCD_EN                 (* (reg8 *) INT1_PIN__LCD_EN)
/* Slew Rate Control */
#define INT1_PIN_SLW                    (* (reg8 *) INT1_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define INT1_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) INT1_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define INT1_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) INT1_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define INT1_PIN_PRTDSI__OE_SEL0        (* (reg8 *) INT1_PIN__PRTDSI__OE_SEL0) 
#define INT1_PIN_PRTDSI__OE_SEL1        (* (reg8 *) INT1_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define INT1_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) INT1_PIN__PRTDSI__OUT_SEL0) 
#define INT1_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) INT1_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define INT1_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) INT1_PIN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(INT1_PIN__SIO_CFG)
    #define INT1_PIN_SIO_HYST_EN        (* (reg8 *) INT1_PIN__SIO_HYST_EN)
    #define INT1_PIN_SIO_REG_HIFREQ     (* (reg8 *) INT1_PIN__SIO_REG_HIFREQ)
    #define INT1_PIN_SIO_CFG            (* (reg8 *) INT1_PIN__SIO_CFG)
    #define INT1_PIN_SIO_DIFF           (* (reg8 *) INT1_PIN__SIO_DIFF)
#endif /* (INT1_PIN__SIO_CFG) */

/* Interrupt Registers */
#if defined(INT1_PIN__INTSTAT)
    #define INT1_PIN_INTSTAT            (* (reg8 *) INT1_PIN__INTSTAT)
    #define INT1_PIN_SNAP               (* (reg8 *) INT1_PIN__SNAP)
    
	#define INT1_PIN_0_INTTYPE_REG 		(* (reg8 *) INT1_PIN__0__INTTYPE)
#endif /* (INT1_PIN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_INT1_PIN_H */


/* [] END OF FILE */
