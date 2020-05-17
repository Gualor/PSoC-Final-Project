/* ========================================
 *
 * This file contains ISR functions needed
 * to link transitions between finite states 
 * and hardware events.
 *
 * CUSTOM_ISR_CONFIG: Triggered with a long press
 * of 3 seconds of the on-board button, it toggles
 * the configuration mode state.
 *
 * CUSTOM_ISR_START: Triggered with a rapid 
 * click of the on-board button, it increments
 * a press counter and at the second press it
 * toggles the start/stop state.
 *
 * ========================================
*/

/* Include project dependencies. */
#include "InterruptRoutines.h"

/*
 * ISR function that toggles configuration mode.
 */
CY_ISR(CUSTOM_ISR_CONFIG)
{
    /* Toggle config state. */
    config_flag = ~(config_flag);
}

/* 
 * ISR function that implements start/stop functionality.
 */
CY_ISR(CUSTOM_ISR_START)
{
    /* Check for button double click. */
    if (press_counter < 2)
    {
        press_counter++;
    }
    else
    {
        /* Toggle start/stop state. */
        start_flag = ~(start_flag);
        
        /* Reset button press counter. */
        press_counter = 0;
    }
}

/* [] END OF FILE */
