/* ========================================
 *
 * This file contains all of the utility
 * functions that enables hardware visual
 * feedbacks to notify the user.
 *
 * Notify_Status: notify user of the internal
 * mode of the firmware with the PSoC on-board 
 * LED. The LED modalities are the following:       
 * -> Stop mode:   LED off
 * -> Start mode:  LED on 
 * -> Config mode: LED blink
 *
 * ========================================
*/

/* Inclune project dependencies. */
#include "Notifications.h"

/*
 * Initialize led_t variable.
 */
void Notify_Init(volatile led_t *led)
{
    // Initialize blink mode
    led->mode = STOP_NOTIFY;
    
    // Initialize period counter
    led->counter = 0;
}

/*
 * Enable LED blinking notifications based
 * on current state.
 */
void Notify_Status(volatile led_t *led)
{
    // Turn on LED
    if (led->counter == 0)
    {
       ONBOARD_LED_Write(1);
    }
    
    // Turn off LED
    if (led->counter == led->mode.compare_val)
    {
        ONBOARD_LED_Write(0);
    } 
    
    // Increment counter if less than period, otherwise reset it
    if (led->counter < led->mode.period-1)
    {
        led->counter++;
    }
    else
    {
        led->counter = 0;
    }
}

/* [] END OF FILE */
