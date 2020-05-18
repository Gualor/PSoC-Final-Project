/* ========================================
 *
 * This file contains all of the utility
 * functions that enables hardware visual
 * feedbacks to notify the user.
 *
 * Notify_Status: notify user of the internal
 * mode of the firmware with the PSoC on-board 
 * LED. The LED modalities are the following:
 * -> Start mode:  LED on        
 * -> Stop mode:   LED off
 * -> Config mode: LED blink
 *
 * ========================================
*/

/* Inclune project dependencies. */
#include "Notifications.h"

/*
 * Enable LED blinking notifications based
 * on current state.
 */
void Notify_Status(led_t *state)
{
    // Increment counter if less than period, otherwise reset it
    if (state->counter < state->mode.period)
    {
        state->counter++;
    }
    else
    {
        state->counter = 0;
    }
    
    // Toggle LED based on compare value
    if (state->counter == 0)
    {
       ONBOARD_LED_Write(1);
    }
    else if (state->counter == state->mode.compare_val)
    {
        ONBOARD_LED_Write(0);
    } 
}

/* [] END OF FILE */
