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
    
    /* Function prototypes. */
    void RGB_Init(void);
    void RGB_Driver(uint8_t *dataPtr);
    void PWM_Driver(uint8_t *dataPtr);
    void IMU_Data_Process(uint8_t *dataPtr);
    uint8_t Absolute_Value(uint8_t value);
    
#endif    

/* [] END OF FILE */
