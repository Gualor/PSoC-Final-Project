/* ========================================
 *
 * This header file defines the ISR function
 * prototypes and the finite state machines
 * variables to enable all project features.
 *
 * ========================================
*/

#ifndef __INTERRUPT_ROUTINES_H__
    
    /* Header guard. */
    #define __INTERRUPT_ROUTINES_H__
    
    /* Include project dependencies. */
    #include "project.h"
    #include "25LC256.h"
    #include "LIS3DH.h"
    #include "Notifications.h"
    
    /* State machine type. */
    typedef enum {
        STOP_MODE,
        START_MODE,
        CONFIG_MODE
    } button_t;
    
    /* ISR functions prototypes. */
    CY_ISR_PROTO(CUSTOM_ISR_CONFIG);
    CY_ISR_PROTO(CUSTOM_ISR_START);
    CY_ISR_PROTO(CUSTOM_ISR_IMU);
    
    /* LIS3DH interrupt flags. */
    volatile uint8_t IMU_data_ready_flag;
    volatile uint8_t IMU_over_threshold_flag;
    
    /* Internal state variable. */
    volatile button_t button_state;
    volatile uint8_t send_flag;
    
#endif

/* [] END OF FILE */
