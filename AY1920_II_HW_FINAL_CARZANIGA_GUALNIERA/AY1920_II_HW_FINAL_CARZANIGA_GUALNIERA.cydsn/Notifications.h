/* ========================================
 *
 * This header file defines useful data tyeps,
 * constants and variables for handling visual
 * feedbacks with LED blinking to notify user.
 *
 * ========================================
*/

#ifndef __NOTIFICATIONS_H__
    
    /* Header guard. */
    #define __NOTIFICATIONS_H__
    
    /* Project dependencies. */
    #include "project.h"
    
    /* Contains LED duty cycle information. */
    typedef struct {
        uint8_t compare_val;
        uint8_t period;
    } blink_t;
    
    /* Contains dynamic LED state infornation. */
    typedef struct {
        blink_t mode;
        uint8_t counter;
    } led_t;
    
    /* Function prototypes. */
    void Notify_Status(led_t *state);
    
    /* Blinking pattern constants. */
    const blink_t START_NOTIFY  = {100, 100};
    const blink_t STOP_NOTIFY   = {0,   100};
    const blink_t CONFIG_NOTIFY = {20,  100};
    
    /* On-board led state. */
    volatile led_t notify_led; 
       
#endif

/* [] END OF FILE */
