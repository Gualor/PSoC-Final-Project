/* ========================================
 *
 * This file contains utility functions used
 * to drive the RGB LED based on IMU data as
 * well as the PSoC on-board LED used for
 * user notifications.
 *
 * RGB_Driver: high level function that enable
 * LED driving based on IMU data coming from LIS3DH.
 *
 * RGB_Start: initialize and start both PWM_RG
 * and PWM_B to drive the RGB LED.
 *
 * RGB_Stop: Disable both PWM_RG and PWM_B
 * turning off the RGB LED.
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
 * LED_Notify: based on the internal state,
 * commute the on-board LED blinking pattern
 * to notify the user of the current mode:
 * -> STOP_MODE: LED off
 * -> START_MODE: LED on
 * -> CONFIG_MODE: LED blink
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
void RGB_Driver(uint8_t* dataPtr)
{   
    // Apply moving average filter
    Moving_Average(dataPtr, RGB_DataBuffer, 32);
    
    // Process IMU data in place
    RGB_dataProcess(RGB_DataBuffer);
    
    // Set PWM compare values
    PWM_Driver(RGB_DataBuffer);
}

/*
 * Start RGB pulse width modulators.
 */
void RGB_Start(void)
{
    // Enable red/green PWM
    PWM_RG_Start();
    
    // Enable blue PWM
    PWM_B_Start();
}

/*
 * Stop RGB pulse width modulators.
 */
void RGB_Stop(void)
{
    // Disable red/green PWM
    PWM_RG_Stop();
    
    // Disable blue PWM
    PWM_B_Stop();
}

/*
 * Write PWM_RG and PWM_B compare values.
 */
void PWM_Driver(uint8* dataPtr)
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
void RGB_dataProcess(uint8_t* dataPtr)
{   
    // For all 3 channels
    for (uint8_t i=0; i<3; i++)
    {
        // Take absolute value
        dataPtr[i] = Absolute_Value(dataPtr[i]);
        
        // Avoid variable overflow
        if (dataPtr[i] > 127)
        {
            dataPtr[i] = 127;
        }
        
        // Multiply by 2 to use full range of uint8
        dataPtr[i] *= 2;
        
        // Get negated value to drive common anode LED
        dataPtr[i] = ~((uint8_t)dataPtr[i]);
    }
}

/*
 * Compute moving average filter across window.
 */
void Moving_Average(uint8_t* dataPtr, uint8_t* filtPtr, uint8_t windowSize)
{
    int16_t dataSum[3] = {0,0,0};
    
    // For all sample in window
    for (uint8_t i=0; i<windowSize; i++)
    {
        // For all 3 channels
        for (uint8_t j=0; j<3; j++)
        {
            // Sum the sample
            int8_t tmp = dataPtr[1+i*6+j*2];
            dataSum[j] += (int16_t)tmp;
        }
    }
    
    // For all 3 channels
    for (uint8_t i=0; i<3; i++)
    {
        // Assign window average value
        filtPtr[i] = (uint8_t)(dataSum[i]/windowSize);
    }
}

/*
 * Get absolute value of int8_t variable without
 * conditional jumps.
 */
uint8_t Absolute_Value(int8_t value)
{
    // Get sign bit
    const int8_t mask = value >> 7;
    
    // Compute abs value
    return (uint8_t)((value + mask) ^ mask);
}

/* [] END OF FILE */
