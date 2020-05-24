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
    #include "stdio.h"
    
    /* LED driver utility functions. */
    void RGB_Stop(void);
    void RGB_Start(void);
    void RGB_Driver(uint8_t* dataPtr);
    void RGB_dataProcess(uint8_t* dataPtr);
    void PWM_Driver(uint8_t* dataPtr);
    uint8_t Absolute_Value(int8_t value);
    void Moving_Average(uint8_t* dataPtr, uint8_t* filtPtr, uint8_t windowSize);
    
    /* LED driver value. */
    uint8_t RGB_DataBuffer[3];
    
#endif    

/* [] END OF FILE */
