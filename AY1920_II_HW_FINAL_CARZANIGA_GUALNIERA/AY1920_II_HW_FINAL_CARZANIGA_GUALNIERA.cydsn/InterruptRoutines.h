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
    #include "stdio.h"
    
    /* Constants definition. */
    #define SYS_TICK_PER_SECOND 1000
    
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
    
    volatile uint8 IMU_interrupt_flag;  // Variable containing the status of the packet [0 not ready, 1 ready]
    
    volatile uint8 IMU_data_ready_flag;  // Variable containing the status of the packet [0 not ready, 1 ready]
    
    volatile uint8 IMU_over_threshold_flag;  // Variable containing the status of the packet [0 not ready, 1 ready]
    
    /* Finite state machine variables. */
    volatile button_t button_state;
    volatile button_t old_button_state;
    
#endif

/* [] END OF FILE */
