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
    
    // Enable configuration mode ISR
    ISR_CONFIG_StartEx(CUSTOM_ISR_CONFIG);
    
    // Enable start/stop mode ISR
    ISR_START_StartEx(CUSTOM_ISR_START);
    
    // Enable notification ISR
    ISR_NOTIFY_StartEx(CUSTOM_ISR_NOTIFY);
    
    // Enable UART communication
    UART_Start();
    
    // Enable SPI Master
    SPIM_Start();
    
    // Initialize HW timers 
    NOTIFY_TIMER_Start();
    BUTTON_TIMER_Start();
    
    // Initialize button state
    button_state = STOP_MODE;
    
    // Initialize notifications
    Notify_Init(&notify_led);
    
    CyDelay(10);
    
    // Initialize LED driver
    RGB_Init();
    
    int8_t x=-128;
    int8_t y=-128;
    int8_t z=-128;
    
    // Main loop
    for(;;)
    {
        if (x<126)
        {
            x++;
            CyDelay(10);
        }
        else
        {
            if (y<126)
            {
                y++;
                CyDelay(10);
            }
            else
            {
                if (z<126)
                {
                    z++;
                    CyDelay(10);
                }
                else
                {
                    x = -128;
                    y = -128;
                    z = -128;
                }
            }
        }
        
        int8_t imu_data[3] = {x, y, z};
        RGB_Driver((uint8_t*)imu_data);
    }
    
    return 0;
}

/* [] END OF FILE */
