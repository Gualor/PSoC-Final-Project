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
    void Notify_Init(volatile led_t *state);
    void Notify_Status(volatile led_t *state);
    
    /* Definition of blinking pattern constants. */
    #define STOP_NOTIFY     (blink_t){0,  10}
    #define START_NOTIFY    (blink_t){10, 10}
    #define CONFIG_NOTIFY   (blink_t){2,  10}
    
    /* 
     * New LED patterns can be added here... 
     */
       
#endif

/* [] END OF FILE */
