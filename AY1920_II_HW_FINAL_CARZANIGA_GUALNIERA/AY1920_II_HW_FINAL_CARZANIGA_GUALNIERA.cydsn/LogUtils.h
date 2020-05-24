/* ========================================
 *
 * This header file contains prototypes of 
 * utility functions used to create and 
 * manage log messages as well as a custom
 * data type.
 *
 * ========================================
*/

#ifndef __LOG_UTILS_H__
    
    /* Header guard. */
    #define __LOG_UTILS_H__
    
    /* Project dependencies. */
    #include "project.h"
    
    /* Useful constants definition. */
    #define LOG_MESSAGE_HEADER_BYTE  4
    #define LOG_MESSAGE_DATA_BYTE   60
    #define LOG_MESSAGE_TOT_BYTE    64
    
    /* Log message type. */
    typedef struct {
        uint8_t logID;
        uint8_t intReg;
        uint16_t timestamp;
        uint8_t dataSize;
        uint8_t data[LOG_MESSAGE_DATA_BYTE];
    } log_t;
    
    /* Function prototypes. */
    log_t LOG_createMessage(uint8_t logID, uint8_t intReg, uint8_t* dataPtr, uint8_t nBytes);
    void LOG_insertPayload(log_t* msg, uint8_t* dataPtr, uint8_t size);
    void LOG_insertTimestamp(log_t* msg);
    
#endif

/* [] END OF FILE */
