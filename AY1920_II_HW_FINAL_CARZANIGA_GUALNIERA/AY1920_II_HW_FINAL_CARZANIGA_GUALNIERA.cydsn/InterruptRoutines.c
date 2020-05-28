/* ========================================
 *
 * This file contains ISR functions needed
 * to link transitions between finite states 
 * and hardware events.
 *
 * CUSTOM_ISR_CONFIG: Triggered with a long 
 * press of 2 seconds of the on-board button, 
 * it toggles the configuration mode state and
 * save config flag inside EEPROM.
 * (Priotity level: 5)
 *
 * CUSTOM_ISR_START: Triggered with a double
 * click event (with time delta between clicks
 * less than 1s), it toggles the start/stop
 * state and save it inside the EEPROM.
 * (Priority level: 6)
 *
 * ========================================
*/

/* Include project dependencies. */
#include "InterruptRoutines.h"

/*
 * ISR function that toggles configuration mode
 * and save state inside EEPROM.
 */
CY_ISR(CUSTOM_ISR_CONFIG)
{   
    // Toggle configuration state
    if (button_state != CONFIG_MODE)
    {
        // Stop IMU interrupt events
        if (button_state == START_MODE)
        {
            IMU_Stop();
        }

        // Enter configuration mode
        button_state = CONFIG_MODE;
        
        // Save config flag inside EEPROM
        EEPROM_saveConfigFlag(1);
        
        // Blink on-board LED
        LED_Notify_Config();
    }
    else
    {
        // Resume start/stop mode
        button_state = EEPROM_retrieveStartStopState();
        
        // Reset config flag inside EEPROM
        EEPROM_saveConfigFlag(0);
        
        if (button_state == STOP_MODE)
        {
            // Turn on-board LED off
            LED_Notify_Stop();
        }
        else if (button_state == START_MODE)
        {
            // Turn on-board LED on
            LED_Notify_Start();
            
            // Restart IMU interrupt events
            IMU_Start();
        }

        // Save send flag inside EEPROM
        EEPROM_saveSendFlag(send_flag);
    }
}

/* 
 * ISR function that implements start/stop functionality
 * and save state inside EEPROM.
 */
CY_ISR(CUSTOM_ISR_START)
{   
    // Toggle start/stop state
    if (button_state == START_MODE)
    {   
        // Restart IMU interrupt events
        IMU_Stop();
        
        // Save stop bit inside EEPROM
        EEPROM_saveStartStopState(0);

        // Turn on-board LED off
        LED_Notify_Stop();
                
        // Update button state
        button_state = STOP_MODE;
    }
    else if (button_state == STOP_MODE)
    {   
        // Restart IMU interrupt events
        IMU_Start();
        
        // Save start bit inside EEPROM
        EEPROM_saveStartStopState(1);

        // Turn on-board LED on
        LED_Notify_Start();
                
        // Update button state
        button_state = START_MODE;
    }
}

/*
 * ISR function that notify incoming external ISR from LIS3DH.
 */
CY_ISR(CUSTOM_ISR_IMU)
{
    // IMU interrupt data overrun event handler
    if (IMU_ReadByte(LIS3DH_FIFO_SRC_REG) & LIS3DH_FIFO_SRC_REG_OVR_MASK)
    {
        IMU_data_ready_flag = 1;
    }
    
    // IMU interrupt over threshold event handler
    if (IMU_ReadByte(LIS3DH_INT1_SRC) & LIS3DH_INT1_SRC_IA_MASK)
    {
        IMU_over_threshold_flag = 1;
    }
}

/* [] END OF FILE */
