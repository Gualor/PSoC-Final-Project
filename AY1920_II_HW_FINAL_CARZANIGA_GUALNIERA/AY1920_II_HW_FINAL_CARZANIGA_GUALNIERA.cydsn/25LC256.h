/**
 * @file 25LC256.h
 * @brief Functions required to interface with the SPI EEPROM 25LC256.
 * 
 * This header file contains macros and function prototypes to interface
 * with the EEPROM 25LC256.
 *
 * @author Mattia Pesenti
 * @date 9 April, 2020
*/

#ifndef __25LC256_H__
    
    #define __25LC256_H__

    #include "SPI_Interface.h"
    #include "LogUtils.h"

    #define SLAVE_CS_Write CS_1_Write
    #define SPIM           SPIM_1

    extern uint8_t eeprom_Status;

     /*** ========= MACROS ========= ***/   

    /** Instruction Set **/
    #define SPI_EEPROM_READ    0b00000011
    #define SPI_EEPROM_WRITE   0b00000010
    #define SPI_EEPROM_WRDI    0b00000100
    #define SPI_EEPROM_WREN    0b00000110
    #define SPI_EEPROM_RDSR    0b00000101
    #define SPI_EEPROM_WRSR    0b00000001

    /* Write Complete Time */
    #define SPI_EEPROM_Twc 5

    /* EEPROM Status Registrer Masks */
    #define SPI_EEPROM_WRITE_IN_PROCESS_SHIFT    0
    #define SPI_EEPROM_WRITE_ENABLE_LATCH_SHIFT  1
    #define SPI_EEPROM_BLOCK_PROTECTION_0_SHIFT  2
    #define SPI_EEPROM_BLOCK_PROTECTION_1_SHIFT  3
    #define SPI_EEPROM_WPEN_SHIFT                7

    #define SPI_EEPROM_WRITE_IN_PROGRESS    ((uint8_t) 0x01u << SPI_EEPROM_WRITE_IN_PROCESS_SHIFT)
    #define SPI_EEPROM_WRITE_ENABLE_LATCH   ((uint8_t) 0x01u << SPI_EEPROM_WRITE_ENABLE_LATCH_SHIFT)
    #define SPI_EEPROM_BLOCK_PROTECTION_0   ((uint8_t) 0x01u << SPI_EEPROM_BLOCK_PROTECTION_0_SHIFT)
    #define SPI_EEPROM_BLOCK_PROTECTION_1   ((uint8_t) 0x01u << SPI_EEPROM_BLOCK_PROTECTION_1_SHIFT)
    #define SPI_EEPROM_WPEN                 ((uint8_t) 0x01u << SPI_EEPROM_WPEN_SHIFT)

    #define SPI_EEPROM_PAGE_SIZE    64
    #define SPI_EEPROM_PAGE_COUNT   512
    #define SPI_EEPROM_SIZE_BYTE    0x7FFF

    /* EEPROM User defined regiter masks. */
    #define CTRL_REG_PSOC_STATUS    0x0000
    #define CTRL_REG_LOG_PAGES_LOW  0x0008
    #define CTRL_REG_LOG_PAGES_HIGH 0x0016
    #define LOG_DATA_BASE_ADDR      0x0040
    #define LOG_PAGES_PER_EVENT     5

    #define CTRL_REG_PSOC_START_STOP_SHIFT  0
    #define CTRL_REG_PSOC_CONFIG_MODE_SHIFT 1
    #define CTRL_REG_PSOC_SEND_FLAG_SHIFT   2
    #define CTRL_REG_PSOC_RESET_FLAG_SHIFT  3

    #define CTRL_REG_PSOC_SET_START         ((uint8_t) 0x01u << CTRL_REG_PSOC_START_STOP_SHIFT)
    #define CTRL_REG_PSOC_SET_CONFIG        ((uint8_t) 0x01u << CTRL_REG_PSOC_CONFIG_MODE_SHIFT)
    #define CTRL_REG_PSOC_SET_SEND_FLAG     ((uint8_t) 0x01u << CTRL_REG_PSOC_SEND_FLAG_SHIFT)
    #define CTRL_REG_PSOC_SET_RESET_FLAG    ((uint8_t) 0x01u << CTRL_REG_PSOC_RESET_FLAG_SHIFT)

    /*** ========= FUNCTION DECLARATIONS ========= ***/

    /** ====== Helper Functions ====== **/

    /*
    * @brief Read the STATUS registrer of the device.
    *
    * @return Status of the device (1 unsigned byte)
    */
    uint8_t EEPROM_readStatus(void);

    /*
    * @brief Issue the WRITE ENABLE (WREN) instruction.
    */
    void EEPROM_writeEnable(void);

    /** ====== User-level Functions ====== **/

    /*
    * @brief Read a single byte @ addr.
    *
    * @param[in]: 16-bit memory address to read from.
    * @return Read value (1 unsigned byte).
    */
    uint8_t EEPROM_readByte(uint16_t addr);

    /*
    * @brief Write a single byte with the value dataByte @ addr.
    *
    * @param[in]: 16-bit memory address to write to.
    * @param[out]: 8-bit (unsigned byte) value to write in the memory location.
    */
    void EEPROM_writeByte(uint16_t addr, uint8_t dataByte);

    /*
    * @brief Read 1+ bytes from memory.
    *
    * @param[in]: 16-bit memory address to from read.
    * @param[out]: uint8_t* pointer to the output data (cast operation required for different data type).
    * @param[in]: Number of bytes to read.
    *
    */
    void EEPROM_readPage(uint16_t addr, uint8_t* data, uint8_t nBytes);
     
    /*
    * @brief Write 1+ bytes from memory.
    *
    * @param[in]: 16-bit memory address to write to.
    * @param[in]: uint8_t* pointer to the input data (max 64 bytes).
    */
    void EEPROM_writePage(uint16_t addr, uint8_t* data, uint8_t nBytes);

    /*
    * @brief Wait until the Write Process is Complete
    * 
    * @note This is a blocking function!
    */
    void EEPROM_waitForWriteComplete(void);


    //////////////////////////////////////////////////////////////////
    void EEPROM_saveStartStopState(uint8_t state);

    uint8_t EEPROM_retrieveStartStopState(void);

    void EEPROM_saveConfigFlag(uint8_t flag);

    uint8_t EEPROM_retrieveConfigFlag(void);

    void EEPROM_saveSendFlag(uint8_t flag);

    uint8_t EEPROM_retrieveSendFlag(void);
    
    void EEPROM_saveResetFlag(uint8_t flag);
    
    uint8_t EEPROM_retrieveResetFlag(void);

    uint16_t EEPROM_retrieveLogPages(void);

    void EEPROM_incrementLogCounter(void);

    void EEPROM_storeLogBuffer(uint8_t* dataPtr, uint8_t nBytes);
    
    void EEPROM_storeLogMessage(log_t message, uint8_t dataSize);
    //////////////////////////////////////////////////////////////////////
    
#endif

/* [] END OF FILE */