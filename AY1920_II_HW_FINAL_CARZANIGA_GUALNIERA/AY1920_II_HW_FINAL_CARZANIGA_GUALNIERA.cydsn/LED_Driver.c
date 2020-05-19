/* ========================================
 *
 * This file contains utility functions used
 * to drive the RGB LED based on IMU data.
 *
 * RGB_Driver: high level function that enable
 * LED driving based on IMU data coming from LIS3DH.
 *
 * PWM_Driver: set the PWM compare values 
 * to change the duty cycles of all LED channels.
 *
 * IMU_Data_Process: map raw IMU data to cover
 * the full range of the LED by taking the
 * absolute value of each axis, doubling it
 * and negate the RGB value to drive common
 * anode LED.
 *
 * Absolute_value: light weight abs function
 * that does not use conditional statements.
 *
 * ========================================
*/

/* Project dependencies. */
#include "LED_Driver.h"

/*
 * Drive LED RGB by setting PWM duty cycles based
 * on xyz-axes IMU data so that:
 * -> X value drives RED channel
 * -> Y value drives GREEN channel
 * -> Z value drives BLUE channel
 */
void RGB_Driver(uint8_t *dataPtr)
{
    // Process IMU data in place
    IMU_Data_Process(dataPtr);
    
    // Set PWM compare values
    PWM_Driver(dataPtr);
}

/*
 * Initialize pulse width modulators.
 */
void RGB_Init(void)
{
    // Enable red/green PWM
    PWM_RG_Start();
    
    // Enable blue PWM
    PWM_B_Start();
}

/*
 * Write PWM_RG and PWM_B compare values.
 */
void PWM_Driver(uint8_t *dataPtr)
{
    // Set red channel PWM compare value
    PWM_RG_WriteCompare1(dataPtr[0]);
    
    // Set green channel PWM compare value
    PWM_RG_WriteCompare2(dataPtr[1]);
    
    //Set blue channel PWM compare value
    PWM_B_WriteCompare(dataPtr[2]);
}

/*
 * Process IMU data in place to map full LED range.
 */
void IMU_Data_Process(uint8_t *dataPtr)
{    
    // For all 3 channels
    for (uint8_t i=0; i<3; i++)
    {   
        // Get absolute value and multiply by 2 to use full range
        uint16_t tmp = (int16_t)Absolute_Value(dataPtr[i])*2;
        
        // Avoid uint8_t variable overflow
        if (tmp > 255)
        {
            tmp = 255;
        }
        
        // Get negated value to drive common anode LED
        dataPtr[i] = ~((uint8_t)tmp);
    }
}

/*
 * Get absolute value of int8_t variable without
 * conditional jumps.
 */
uint8_t Absolute_Value(uint8_t value)
{
    // Get sign of val
    uint8_t mask = (value >> 7);
    
    // XOR mask and subtract mask
    return (value ^ mask) - mask;
}

/* [] END OF FILE */
