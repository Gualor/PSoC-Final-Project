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

/* Include project dependencies. */
#include "InterruptRoutines.h"

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

    /* Main loop. */
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
