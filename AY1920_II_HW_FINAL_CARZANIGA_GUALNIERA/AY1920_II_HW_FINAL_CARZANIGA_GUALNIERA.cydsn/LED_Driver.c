/* ========================================
 *
 * This file contains utility functions used
 * to drive the RGB LED based on IMU data.
 *
 * RGB_Driver: high level function that enable
 * LED driving based on IMU data coming from LIS3DH.
 *
 * PWM_Driver: set the PWM compare values to change
 * the duty cycles of all LED channels.
 *
 * Process_Channels: map raw IMU data to cover
 * the full range of the LED by taking the
 * absolute value of each axis and doubling it.
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
 * on xyz-axes IMU data.
 */
void RGB_Driver(uint8_t *dataPtr)
{
    // Process IMU data in place
    Process_Channels(dataPtr);
    
    // Set PWM compare values
    PWM_Driver(dataPtr);
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
void Process_Channels(uint8_t *dataPtr)
{    
    // For all 3 channels
    for (uint8_t i=0; i<3; i++)
    {
        // Get absolute value
        int8_t tmp = Absolute_Value(dataPtr[i]);
    
        // Scale value to use full range
        dataPtr[0] = tmp*2;
    }
}

/*
 * Get absolute value of int8_t variable without
 * conditional jumps.
 */
uint8_t Absolute_Value(uint8_t val)
{
    // Get sign of val
    uint8_t mask = (val >> 7);
    return (val ^ mask) - mask;
}

/* [] END OF FILE */
