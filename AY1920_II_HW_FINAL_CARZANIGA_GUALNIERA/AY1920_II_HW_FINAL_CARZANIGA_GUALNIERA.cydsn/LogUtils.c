/* ========================================
 *
 * This file contains all function definitions
 * to create and handle log messages.
 *
 * A log message is used to store information
 * regarding IMU over threshold events and it
 * is composed as follows:
 * 
 * +--------------------+
 * |       Log ID       |   <1 byte>
 * +--------------------+
 * |    INT register    |   <1 byte>
 * +--------------------+
 * |      Timestamp     |   <2 bytes>
 * +--------------------+
 * |                    |
 * |        Data        |   <60 bytes>
 * |                    |
 * +--------------------+
 *
 * Log ID: identification number
 * 
 * INT register: info about external interrupt
 *               triggered by over threshold
 *
 * Timestamp: timestamp in seconds of the event
 *            occurrence
 *
 * Data: inertial measurement data, organized
 *       in row of 3 axis value X, Y, Z for a
 *       total of 20 rows (60 bytes)
 *
 * ========================================
*/

#include "LogUtils.h"

/*
 * Create a single log message with 60 bytes of max payload. 
 */
log_t LOG_createMessage(uint8_t logID, uint8_t intReg, uint16_t time, uint8_t* dataPtr, uint8_t nBytes)
{
    // Create log type message
    log_t message;
    
    // Assign log id number
    message.logID = logID;
    
    // Assign interrupt register
    message.intReg = intReg;
    
    // Assign logging timestamp
    message.timestamp = time;
    
    // Insert data payload
    LOG_insertPayload(&message, dataPtr, nBytes);
    
    return message;
}

/*
 * Insert data payload into log data structure.
 */
void LOG_insertPayload(log_t* msg, uint8_t* dataPtr, uint8_t nBytes)
{
    // Copy payload inside data field
    memcpy(msg->data, dataPtr, nBytes);
}

/*
 * Get timestamp in seconds since PSoC booting.
 */
uint16_t LOG_getTimestamp(void)
{
    // Read time in seconds from boot up
    return LOG_TIMER_OVERFLOW - MAIN_TIMER_ReadCounter();
}

/*
 * Get identification number.
 */ 
uint8_t LOG_getID(void)
{
    // Get number of log pages
    uint16_t nPages = EEPROM_retrieveLogPages();
    
    // Get unique sequential ID
    return (uint8_t)(nPages / LOG_PAGES_PER_EVENT);
}

/* [] END OF FILE */
