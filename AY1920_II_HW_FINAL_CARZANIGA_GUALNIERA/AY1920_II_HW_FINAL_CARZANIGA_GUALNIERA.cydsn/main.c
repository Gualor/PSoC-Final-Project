/* ========================================
 *
 * This file contains the main function which
 * is designed to enable all ISRs and setup
 * all communication protocols to interface
 * the PSoC board with: 
 * -> 25LC256 EEPROM
 * -> LIS3DH accelerometer
 * -> Serial monitor (UART)
 *
 * ========================================
*/

/* Project dependencies. */
#include "InterruptRoutines.h"
#include "SPI_Interface.h"
#include "LED_Driver.h"
#include "25LC256.h"
#include "LIS3DH.h"
#include "stdio.h"

/* Global variables. */
char bufferUART[100];

/*
 * Main function designated to setup stuff.
 */
int main(void)
{    
    // Enable global interrupts
    CyGlobalIntEnable;
    
        
    // Enable UART communication
    UART_Start();
    
    // Enable SPI Master
    SPIM_Start();
    
    CyDelay(10);
    
    
    // Setup all registers via SPI to LIS3DH accelerometer
    IMU_RegistersSetup();
    
    /* Enable external ISR from IMU */
    ISR_IMU_StartEx(CUSTOM_ISR_IMU);
    
    // Enable configuration mode ISR
    ISR_CONFIG_StartEx(CUSTOM_ISR_CONFIG);
    
    // Enable start/stop mode ISR
    ISR_START_StartEx(CUSTOM_ISR_START);

    
    // Initialize HW timers 
    BUTTON_TIMER_Start();
    CLICK_TIMER_Start();
    
    // Initialize button state
    button_state = STOP_MODE;
    old_button_state = button_state;

    // End of setup
    CyDelay(10);
    
    // Main loop
    for(;;)
    {   
        // If state transition, notify user with LED
        if (button_state != old_button_state)
        {
            // Change LED notification pattern
            LED_Notify(button_state);
            
            // Update button state
            old_button_state = button_state;
        }
        
        
        
        
         // External ISR occurence
        if(IMUDataReady == 1)
        {   
            
            // Read data via SPI from IMU
            IMU_ReadFIFO(IMU_DataBuffer);
            
            
            
            // Send data read from FIFO via UART
            IMU_DataSend(IMU_DataBuffer);
            
                
            // Reset the FIFO to enable next ISR occurrences
            IMU_ResetFIFO();         


            
            // Reset flag to allow new ISR occurrences
            IMUDataReady = 0;
   
            
        }
    }
    
    return 0;
}

/* [] END OF FILE */
