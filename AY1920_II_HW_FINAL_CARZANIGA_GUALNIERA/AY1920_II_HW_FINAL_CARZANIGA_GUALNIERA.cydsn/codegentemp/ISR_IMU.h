/*******************************************************************************
* File Name: ISR_IMU.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_ISR_IMU_H)
#define CY_ISR_ISR_IMU_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISR_IMU_Start(void);
void ISR_IMU_StartEx(cyisraddress address);
void ISR_IMU_Stop(void);

CY_ISR_PROTO(ISR_IMU_Interrupt);

void ISR_IMU_SetVector(cyisraddress address);
cyisraddress ISR_IMU_GetVector(void);

void ISR_IMU_SetPriority(uint8 priority);
uint8 ISR_IMU_GetPriority(void);

void ISR_IMU_Enable(void);
uint8 ISR_IMU_GetState(void);
void ISR_IMU_Disable(void);

void ISR_IMU_SetPending(void);
void ISR_IMU_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_IMU ISR. */
#define ISR_IMU_INTC_VECTOR            ((reg32 *) ISR_IMU__INTC_VECT)

/* Address of the ISR_IMU ISR priority. */
#define ISR_IMU_INTC_PRIOR             ((reg8 *) ISR_IMU__INTC_PRIOR_REG)

/* Priority of the ISR_IMU interrupt. */
#define ISR_IMU_INTC_PRIOR_NUMBER      ISR_IMU__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_IMU interrupt. */
#define ISR_IMU_INTC_SET_EN            ((reg32 *) ISR_IMU__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_IMU interrupt. */
#define ISR_IMU_INTC_CLR_EN            ((reg32 *) ISR_IMU__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_IMU interrupt state to pending. */
#define ISR_IMU_INTC_SET_PD            ((reg32 *) ISR_IMU__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_IMU interrupt. */
#define ISR_IMU_INTC_CLR_PD            ((reg32 *) ISR_IMU__INTC_CLR_PD_REG)


#endif /* CY_ISR_ISR_IMU_H */


/* [] END OF FILE */
