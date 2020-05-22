/* ========================================
 *
 * This file contains ISR functions needed
 * to link transitions between finite states 
 * and hardware events.
 *
 * CUSTOM_ISR_CONFIG: Triggered with a long 
 * press of 2 seconds of the on-board button, 
 * it toggles the configuration mode state.
 * (Priotity level: 5)
 *
 * CUSTOM_ISR_START: Triggered with a rapid 
 * click of the on-board button, it increments
 * a press counter and at the second press it
 * toggles the start/stop state.
 * (Priority level: 6)
 *
 * CUSTOM_ISR_NOTIFY: Triggered by a timer
 * every 100ms, it handles with low priority
 * the on-board notification LED to signal
 * the current mode.
 * (Priority level: 5)
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
    // Toggle configuration state
    if (button_state != CONFIG_MODE)
    {
        // Enter configuration mode
        button_state = CONFIG_MODE;
    }
    else
    {
        // Resume stop mode by default
        button_state = STOP_MODE;
    }
    
    // Reset button press counter
    press_counter = 0;
}

/* 
 * ISR function that implements start/stop functionality.
 */
CY_ISR(CUSTOM_ISR_START)
{   
    // Check button press counter
    if (press_counter < 1)
    {
        // Setup internal timer
        CySysTickClear();
        CySysTickStart();
        press_counter++;
    }
    else
    {
        // Get time passed from first button press
        uint32_t delta_time = CySysTickGetValue();

        // Toggle button state if time delta is less than 1 second
        if (delta_time < SYS_TICK_PER_SECOND)
        {
            // Toggle start/stop state
            if (button_state == START_MODE)
            {
                button_state = STOP_MODE;
            }
            else if (button_state == STOP_MODE)
            {
                button_state = START_MODE;
            }
            
            // Stop internal timer
            CySysTickStop();
        }
        
        // Reset button press counter
        press_counter = 0;
    }
}


/*
CY_ISR(CUSTOM_ISR_START)
{   
    // Check button press counter
    if (press_counter < 1)
    {
        press_timer = 0;
        press_counter++;
    }
    else
    {
        // Toggle start/stop state
        if (button_state == START_MODE)
        {
            button_state = STOP_MODE;
        }
        else if (button_state == STOP_MODE)
        {
            button_state = START_MODE;
        }
        
        // Reset button press counter
        press_counter = 0;
    }
}
*/

/*
 * ISR function that implements LED visual feedbacks
 * based on internal state.
 */
CY_ISR(CUSTOM_ISR_NOTIFY)
{   
    // Read control register
    NOTIFY_TIMER_ReadStatusRegister();
    
    // Increment timer for double button click
    press_timer++;
    if (press_timer >= DOUBLE_CLICK_RESET_TIME)
    {
        press_counter = 0;
    }
    
    // If state transition
    if (button_state != old_button_state)
    {
        // Update notification mode
        if (button_state == STOP_MODE)
        {
            notify_led.mode = STOP_NOTIFY;
        }
        else if (button_state == START_MODE)
        {
            notify_led.mode = START_NOTIFY;
        }
        else if (button_state == CONFIG_MODE)
        {
            notify_led.mode = CONFIG_NOTIFY;
        }
        
        // Reset LED counter
        notify_led.counter = 0;
        old_button_state = button_state;
    }
    
    // Toggle LED state to notify state
    Notify_Status(&notify_led);
    
    
}

/*
 * ISR function that notify incoming external ISR from LIS3DH FIFO overrun
 */
CY_ISR(CUSTOM_ISR_IMU)
{
    //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
    IMUDataReady = 1;
    
    //IMU_ReadFIFO(IMU_DataBuffer);
    
    //IMU_DataSend(IMU_DataBuffer);
    
    //IMU_ResetFIFO();         
    
}

/* [] END OF FILE */
