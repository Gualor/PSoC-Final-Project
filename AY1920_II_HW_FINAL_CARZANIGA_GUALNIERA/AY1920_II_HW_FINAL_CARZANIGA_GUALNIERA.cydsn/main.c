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
#include "LogUtils.h"
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
    
    // Setup all registers via SPI to LIS3DH
    IMU_RegistersSetup();
    
    // Enable external ISR from IMU
    ISR_IMU_StartEx(CUSTOM_ISR_IMU);
    
    // Enable configuration mode ISR
    ISR_CONFIG_StartEx(CUSTOM_ISR_CONFIG);
    
    // Enable start/stop mode ISR
    ISR_START_StartEx(CUSTOM_ISR_START);

    // Initialize timers 
    BUTTON_TIMER_Start();
    CLICK_TIMER_Start();
    MAIN_TIMER_Start();
    
    // Initialize ADC
    ADC_DELSIG_Start();
    
    // Initialize LED RGB
    RGB_Start();
    
    // Initialize button state
    button_state = STOP_MODE;
    
    // Initialize IMU data flag
    IMU_interrupt_flag = 0;

    // End of setup
    CyDelay(10);
    
    // Define send flag
    uint8_t send_flag = 0;
 
    // Main loop
    for(;;)
    {   
        // Enter configuration mode
        if (button_state == CONFIG_MODE)
        {
            // TODO: IMU_Stop()
            
            // While in configuration mode
            while(EEPROM_retrieveConfigFlag() == 1)
            {
                // Assign new send flag based on knob
                send_flag = POT_Read_Value(send_flag);
                
                // Drive LED blue channel based on flag
                RGB_sendFlagNotify(send_flag);
            }
            
            // Save send flag inside EEPROM
            EEPROM_saveSendFlag(send_flag);

            // TODO: IMU_Start()
        }
        
        // External ISR occurence
        if(IMU_interrupt_flag == 1)
        {   
            // Check if ISR has been triggered by FIFO data overrun
            if((IMU_ReadByte(LIS3DH_FIFO_SRC_REG)) & (LIS3DH_FIFO_SRC_REG_OVR_MASK))
            {
                // Read data via SPI from IMU
                IMU_ReadFIFO(IMU_DataBuffer);
                
                // Store the read FIFO in the LOG buffer
                IMU_StoreFIFO(IMU_DataBuffer);
    
                //Send data read from FIFO via UART
                IMU_DataSend(IMU_DataBuffer);
                    
                
                // Drive RGB LED with IMU data
                RGB_Driver(IMU_DataBuffer); 
            }
            
            // Over threshold event occured
            else
            {   
                // Read LIS3DH interrupt register
                uint8_t int1_src_reg = IMU_ReadByte(LIS3DH_INT1_SRC);
                
                // Find free memory slot inside EEPROM
                uint16_t page_cnt_reg = EEPROM_retrieveLogPages();
                
                /* TODO
                uint8_t id = get_id();
                uint8_t data = get_data();
                log_t logMessage = LOG_createMessage(id, data, 64);
                */
                
                // Set over threshold flag
                IMU_over_threshold_flag = 1;
            }
            
            // Reset the FIFO to enable next ISR occurrences
            IMU_ResetFIFO();
            // Reset flag interrupt flag
            IMU_interrupt_flag = 0;
        }   
    }
    
    return 0;
}

/* [] END OF FILE */
