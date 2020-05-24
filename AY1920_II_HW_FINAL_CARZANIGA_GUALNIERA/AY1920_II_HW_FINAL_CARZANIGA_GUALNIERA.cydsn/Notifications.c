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

/* [] END OF FILE */
