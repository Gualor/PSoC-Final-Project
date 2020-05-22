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
    #include "Notifications.h"
    #include "LIS3DH.h"
    
    /* Constants definition. */
    #define SYS_TICK_PER_SECOND 1000
    
    /* Constants definition. */
    #define DOUBLE_CLICK_RESET_TIME 10
    
    /* State machine type. */
    typedef enum {
        STOP_MODE,
        START_MODE,
        CONFIG_MODE
    } button_t;
    
    /* ISR functions prototypes. */
    CY_ISR_PROTO(CUSTOM_ISR_CONFIG);
    CY_ISR_PROTO(CUSTOM_ISR_START);
    CY_ISR_PROTO(CUSTOM_ISR_NOTIFY);
    CY_ISR_PROTO(CUSTOM_ISR_IMU);

    /* Button press variables. */
    volatile uint8_t press_counter;
    volatile uint8_t press_timer;
    
    /* Finite state machine variables. */
    volatile button_t button_state;
    volatile button_t old_button_state;
    
    /* Current on-board LED state. */
    volatile led_t notify_led;
    
    volatile uint8 IMUDataReady;  // Variable containing the status of the packet [0 not ready, 1 ready]
    
#endif

/* [] END OF FILE */
