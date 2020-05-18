/* ========================================
 *
 * This file contains the main function which
 * is designed to enable all ISR and setup
 * all communication protocols to interface
 * the PSoC board with the LIS3DH accelerometer
 * and the EEPROM.
 *
 * ========================================
*/

/* Project dependencies. */
#include "InterruptRoutines.h"
#include "SPI_Interface.h"
#include "LED_Driver.h"

#include <stdio.h>
#include <string.h>

#define UART_PutBuffer UART_PutString(bufferUART)
char bufferUART[100];

/*
 * Main function designated to setup stuff.
 */
int main(void)
{
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    
    /* Enable configuration mode ISR. */
    ISR_CONFIG_StartEx(CUSTOM_ISR_CONFIG);
    
    /* Enable start/stop mode ISR. */
    ISR_START_StartEx(CUSTOM_ISR_START);
    
    /* Start UART */
    UART_Start();
    
    /* Start SPI Master */
    SPIM_Start();
    
    CyDelay(10);
    
    UART_PutString("*********    LIS3DH TEST    *********\r\n");
    
    // Read WHO_AM_I Register
    uint8_t who_am_i = SPI_Interface_ReadByte(LIS3DH_SPI_WHO_AM_I_REG);
    
    sprintf(bufferUART, "WHO AM I REG: 0x%02X [Expected: 0x33]\r\n", who_am_i);
    UART_PutBuffer;
    
    UART_PutString("*************************************\r\n");
    
    
    // Read Status Register
    uint8_t status_reg = SPI_Interface_ReadByte(LIS3DH_SPI_STATUS_REG);
    
    sprintf(bufferUART, "STATUS REG: 0x%02X \r\n", status_reg);
    UART_PutBuffer;
    
    UART_PutString("*************************************\r\n");
    
    
    // Read Control Register 1
    uint8_t ctrl_reg1 = SPI_Interface_ReadByte(LIS3DH_SPI_CTRL_REG1);
    
    sprintf(bufferUART, "CTRL REG1: 0x%02X \r\n", ctrl_reg1);
    UART_PutBuffer;
    
    UART_PutString("*************************************\r\n");

    /* Main loop. */
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
