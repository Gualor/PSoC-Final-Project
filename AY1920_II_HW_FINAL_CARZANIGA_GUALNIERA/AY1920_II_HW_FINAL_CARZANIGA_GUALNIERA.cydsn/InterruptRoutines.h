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
    #include "stdbool.h"
    
    /* ISR functions prototypes. */
    CY_ISR_PROTO(CUSTOM_ISR_CONFIG);
    CY_ISR_PROTO(CUSTOM_ISR_START);
    
    /* State machine variables. */
    volatile bool start_flag;
    volatile bool config_flag;
    
    /* Button press counter. */
    volatile uint8_t press_counter;
    
#endif

/* [] END OF FILE */
