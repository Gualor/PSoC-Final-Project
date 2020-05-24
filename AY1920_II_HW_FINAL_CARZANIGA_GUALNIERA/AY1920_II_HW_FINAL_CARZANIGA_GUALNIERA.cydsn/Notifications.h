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

    /* Function prototypes. */
    void LED_Notify_Stop(void);
    void LED_Notify_Start(void);
    void LED_Notify_Config(void);

#endif

/* [] END OF FILE */
