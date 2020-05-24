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
    
    // Enable all SPI Master
    SPIM_IMU_Start();
    SPIM_EEPROM_Start();
    
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
    
    // Initialize LED RGB
    RGB_Start();
    
    // Initialize button state
    button_state = STOP_MODE;
    
    // Initialize IMU data flag
    //IMU_interrupt_flag = 0;
    IMU_data_ready_flag = 0;
    IMU_over_threshold_flag = 0;
    
    // End of setup
    CyDelay(10);
 
    // Main loop
    for(;;)
    {     
        // External ISR occurence
        if(IMU_interrupt_flag == 1)
        {   
            // Check if ISR has been triggered by FIFO data overrun
            if((IMU_ReadByte(LIS3DH_FIFO_SRC_REG)) & (LIS3DH_FIFO_SRC_REG_OVR_MASK))
            {
                // Read data via SPI from IMU
                IMU_ReadFIFO(IMU_DataBuffer);
    
                //Send data read from FIFO via UART
                IMU_DataSend(IMU_DataBuffer);
                    
                // Reset the FIFO to enable next ISR occurrences
                IMU_ResetFIFO();
                
                // Drive RGB LED with IMU data
                RGB_Driver(IMU_DataBuffer); 
            }
            
            // Over threshold event occured
            else
            {   
                // Read LIS3DH interrupt register
                uint8_t int1_src_reg = IMU_ReadByte(LIS3DH_INT1_SRC);
                
                // Set over threshold flag
                IMU_over_threshold_flag = 1;
            }
            
            // Reset flag to allow new ISR occurrences
            IMU_interrupt_flag = 0;
        }   
    }
    
    return 0;
}

/* [] END OF FILE */
