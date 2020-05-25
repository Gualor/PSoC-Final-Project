/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* Include dependencies. */
#include "Notifications.h"

/*
 * Notify stop mode by turning on-board LED off.
 */
void LED_Notify_Stop(void)
{
    // If LED PWM is enabled
    if (PWM_NOTIFY_ReadControlRegister() & PWM_NOTIFY_CTRL_ENABLE)
    {
        // Disable PWM
        PWM_NOTIFY_Stop();
    }
}

/*
 * Notify start mode by turning on-board LED on.
 */
void LED_Notify_Start(void)
{
    // If LED PWM is not enabled
    if (!(PWM_NOTIFY_ReadControlRegister() & PWM_NOTIFY_CTRL_ENABLE))
    {
        // Enable PWM
        PWM_NOTIFY_Start();
    }
    
    // Change PWM compare value
    PWM_NOTIFY_WriteCompare(255);
}

/*
 * Notify config mode by blinking on-board LED.
 */
void LED_Notify_Config(void)
{
    // If LED PWM is not enabled
    if (!(PWM_NOTIFY_ReadControlRegister() & PWM_NOTIFY_CTRL_ENABLE))
    {
        // Enable PWM
        PWM_NOTIFY_Start();
    }
    
    // Change PWM compare value
    PWM_NOTIFY_WriteCompare(127);
}

/*
 * Read user input value through potentiometer sampling
 * to set a logic flag:
 * 0%->24%:     0
 * 25%->50%:    don't change
 * 51&->100%:   1
 */
uint8_t POT_Read_Value(uint8_t oldFlag)
{
    // Read potentiometer value
    int16_t raw = ADC_DELSIG_Read16();
    if (raw > 255) raw = 255;
    else if (raw < 0) raw = 0;
    
    // Convert to unsigned 8-bit integer
    uint8_t pot_val = (uint8_t)(raw & 0xFF);
    
    // Set flag based on read value
    uint8_t flag;
    if (pot_val < (POT_MID_RANGE - POT_DEAD_BAND))
    {
        flag = 0;
    }
    else if (pot_val > (POT_MID_RANGE + POT_DEAD_BAND))
    {
        flag = 1;
    }
    else
    {
        flag = oldFlag;
    }
    
    // Return new flag
    return flag;
}

/* [] END OF FILE */
