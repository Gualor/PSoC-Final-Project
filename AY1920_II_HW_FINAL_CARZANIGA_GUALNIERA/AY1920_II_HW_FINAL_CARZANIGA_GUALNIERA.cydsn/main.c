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
#include "LED_Driver.h"


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
    
    CyDelay(10);
    
    // Enable configuration mode ISR
    ISR_CONFIG_StartEx(CUSTOM_ISR_CONFIG);
    
    // Enable start/stop mode ISR
    ISR_START_StartEx(CUSTOM_ISR_START);
    
    // Enable notification ISR
    //ISR_NOTIFY_StartEx(CUSTOM_ISR_NOTIFY);
    

    
   
    
    // Initialize HW timers 
    //NOTIFY_TIMER_Start();
    BUTTON_TIMER_Start();
    
    // Initialize button state
    button_state = STOP_MODE;
    old_button_state = button_state;

    
    // Initialize notifications
    //Notify_Init(&notify_led);
    
    // Initialize LED driver
    RGB_Init();
    
    // End of setup
    CyDelay(10);
    
    // Main loop
    for(;;)
    {
        
        // If state transition, notify user with LED
        if (button_state != old_button_state)
        {
            if (button_state == STOP_MODE)
            {
                //PWM_NOTIFY_Stop();
            }
            else if (button_state == START_MODE)
            {
                //PWM_NOTIFY_Start();
                //PWM_NOTIFY_WriteCompare(255);
            }
            else if (button_state == CONFIG_MODE)
            {
                //PWM_NOTIFY_Start();
                //PWM_NOTIFY_WriteCompare(127);
            }
            old_button_state = button_state;
        }
        
        
        // External ISR occurence
        if(IMUDataReady == 1)
        {   
            //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
            
            // Read data via SPI from IMU
            IMU_ReadFIFO(IMU_DataBuffer);
            
            //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
            
            // Send data read from FIFO via UART
            //IMU_DataSend(IMU_DataBuffer);
            //UART_PutChar('A');
                
            // Reset the FIFO to enable next ISR occurrences
            IMU_ResetFIFO();         
            
            /*
            while (SPI_Interface_ReadByte(LIS3DH_READ_FIFO_CTRL_REG) != LIS3DH_FIFO_CTRL_REG_FIFO_MODE)
            {
                IMU_ResetFIFO();         
            }
            */

            
            // Reset flag to allow new ISR occurrences
            IMUDataReady = 0;
            //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
            UART_PutChar('A');
            
        }
        
        // Check if missed an ISR
        else if((IMUDataReady == 0) && ((SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG) & LIS3DH_FIFO_OVR_MASK)))
        {
            IMU_ResetFIFO();
            UART_PutChar('F');
        }
        
        else
        {
            //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
            UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_CTRL_REG));
        }
        
        
        
    }
    
    return 0;
}

/* [] END OF FILE */
