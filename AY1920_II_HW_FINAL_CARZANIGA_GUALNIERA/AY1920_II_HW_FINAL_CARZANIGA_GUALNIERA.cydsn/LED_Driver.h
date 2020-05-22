/* ========================================
 *
 * This header file defines utility function
 * prototypes used to drive the LED RGB. 
 *
 * ========================================
*/

#ifndef __LED_DRIVER_H__
    
    /* Header guard. */
    #define __LED_DRIVER_H__
    
    /* Project dependendcies. */
    #include "project.h"
    #include "InterruptRoutines.h"
    
    /* Function prototypes. */
    void RGB_Driver(uint8_t *dataPtr);
    void RGB_Stop(void);
    void RGB_Start(void);
    void PWM_Driver(uint8_t *dataPtr);
    void IMU_Data_Process(uint8_t *dataPtr);
    uint8_t Absolute_Value(uint8_t value);
    void LED_Notify(button_t state);
    
#endif    

/* [] END OF FILE */
