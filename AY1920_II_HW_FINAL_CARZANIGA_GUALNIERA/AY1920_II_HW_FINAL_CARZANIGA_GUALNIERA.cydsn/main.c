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
#include "RGB_Driver.h"
#include "LogUtils.h"
#include "25LC256.h"
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
    
    // Initliazide RGB LED
    RGB_Init();

    // Initialize button state
    button_state = STOP_MODE;
    
    // Initialize IMU flags
    IMU_data_ready_flag = 0;
    IMU_over_threshold_flag = 0;

    // End of setup
    CyDelay(10);
    
    // Define send flag
    uint8_t send_flag = 0;

    // Uncomment this to erase EEPROM memory
    EEPROM_resetMemory();
    
    // Main loop
    for(;;)
    {   
        // Board state handler
        switch (button_state)
        {
            case STOP_MODE:
                
                // Do nothing
                break;
            
            case START_MODE:
                
                // Drive LED based on IMU data
                RGB_Driver(IMU_DataBuffer);
                break;
     
            case CONFIG_MODE:
                
                // Turn RGB LED on
                RGB_Start();
                
                // Change send flag to send IMU data over UART
                while(EEPROM_retrieveConfigFlag() == 1)
                {
                    // Assign new send flag based on knob
                    send_flag = POT_Read_Value(send_flag);
                    
                    // Drive LED blue channel based on flag
                    RGB_sendFlagNotify(send_flag);
                }
                RGB_Stop();

                // Save send flag inside EEPROM
                EEPROM_saveSendFlag(send_flag);
                break;  
        }
        
        // IMU ISR FIFO data overrun event
        if (IMU_data_ready_flag == 1)
        {
            // Read data via SPI from IMU
            IMU_ReadFIFO(IMU_DataBuffer);
            
            // Store the read FIFO in the LOG buffer
            IMU_StoreFIFO(IMU_DataBuffer);
            
            // Check EEPROM if send flag is set
            if (EEPROM_retrieveSendFlag() == 1)
            {
                //Send data read from FIFO via UART
                IMU_DataSend(IMU_DataBuffer);
            }

            // Reset the FIFO to enable next ISR occurrences
            IMU_ResetFIFO();
            
            // End of IMU data reading
            IMU_data_ready_flag = 0;
        }
        
        // IMU ISR over threshold event
        if (IMU_over_threshold_flag == 1)
        {   
            // Capture all over threshold event's interrupts
            uint8_t int_reg;
            while((int_reg = IMU_ReadByte(LIS3DH_INT1_SRC)) & (LIS3DH_INT1_SRC_IA_MASK));
            
            // Get sequential ID number
            uint8_t log_id = EEPROM_retrieveLogCount();
            
            // Get timestamp in seconds from boot
            uint16_t timestamp = LOG_getTimestamp();
            
            for (uint8_t i=0; i<LOG_PAGES_PER_EVENT; i++)
            {        
                // Get payload of 60 bytes from the IMU queue
                uint8_t payload[LOG_MESSAGE_DATA_BYTE];
                IMU_getPayload(payload, i);
                
                // Create log type message
                log_t log_message = LOG_createMessage(log_id, int_reg, timestamp, payload);
                
                // Store message inside EEPROM
                EEPROM_storeLogMessage(log_message);
                
                // Get page of first log
                log_t asd = EEPROM_retrieveLogMessage(log_id, i);
                
                // Send message via uart
                //LOG_sendData(&asd);
            }
            
            // End of over threshold event
            IMU_over_threshold_flag = 0;
            
            // Reset the FIFO to enable new ISR occurrences
            IMU_ResetFIFO();
        }   
    }
    
    return 0;
}

/* [] END OF FILE */
