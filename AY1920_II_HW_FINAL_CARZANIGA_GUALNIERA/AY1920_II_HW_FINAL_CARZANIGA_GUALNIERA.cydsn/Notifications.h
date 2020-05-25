/* ========================================
 *
 * This header file contains the utility
 * function prototypes that enable user
 * notifications using the on-board LED.
 *
 * ========================================
*/

#ifndef __NOTIFICATIONS_H__
    
    /* Header guard. */
    #define __NOTIFICATIONS_H__
    
    /* Include dependencies. */
    #include "project.h"

    /* Useful constants. */
    #define POT_MID_RANGE   127
    #define POT_DEAD_BAND   POT_MID_RANGE/2
    
    /* LED utility functions. */
    void LED_Notify_Stop(void);
    void LED_Notify_Start(void);
    void LED_Notify_Config(void);
    
    /* POT utility functions. */
    uint8_t POT_Read_Value(uint8_t oldFlag);

#endif

/* [] END OF FILE */
