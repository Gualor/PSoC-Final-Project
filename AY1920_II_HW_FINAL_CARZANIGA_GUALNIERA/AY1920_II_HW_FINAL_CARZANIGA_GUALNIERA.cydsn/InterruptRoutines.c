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
 * a press counter on the first click. On the 
 * second click get the time delta from the
 * first one and if less than 1 second, toggle
 * start/stop state.
 * (Priority level: 6)
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
}

/* 
 * ISR function that implements start/stop functionality.
 */
CY_ISR(CUSTOM_ISR_START)
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
}


/*
 * ISR function that notify incoming external ISR from LIS3DH FIFO overrun
 */
CY_ISR(CUSTOM_ISR_IMU)
{
    //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_CTRL_REG));
    //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
    IMUDataReady = 1;
    
    //IMU_ReadFIFO(IMU_DataBuffer);
    
    //IMU_DataSend(IMU_DataBuffer);
    
    //IMU_ResetFIFO();
    
    
}

/* [] END OF FILE */
