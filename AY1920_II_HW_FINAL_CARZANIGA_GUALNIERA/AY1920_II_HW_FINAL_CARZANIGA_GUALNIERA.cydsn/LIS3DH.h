/**
 * @file LIS3DH.h
 * @brief Functions required to interface with the SPI LIS3DH.
 * 
 * This header file contains macros and function prototypes to interface
 * with the LIS3DH accelerometer.
 *
*/

#ifndef __LIS3DH_H__
    #define __LIS3DH_H__

    #include "SPI_Interface.h"
    #include "project.h"
    
    #define LIS3DH_BYTES_IN_FIFO 192
    uint8_t IMU_DataBuffer[LIS3DH_BYTES_IN_FIFO];
    
    
    
    

     /*** ========= MACROS ========= ***/   

    /** Instruction Set **/
    #define LIS3DH_READ_BIT 0b10000000
    #define LIS3DH_AUTO_INCREMENT_ADDRESS 0b01000000
    
    #define LIS3DH_FIFO_BYTES_IN_LEVEL 6
    
    /**
    * \brief Address of the read address byte on SPI 0b1110 1000  (Read[0], Increment address[1], register address[2:7] )
    *                                 WHO AM I REG  0b1000 1111
    */
    #define LIS3DH_READ_WHO_AM_I_REG  0x8F

    // 0b10100111
    #define LIS3DH_READ_STATUS_REG  0xA7


    // 0b10100000
    #define LIS3DH_READ_CTRL_REG1 0xA0

    // 0b10000000
    #define LIS3DH_READ_CTRL_REG3 0xA2

    // 0b10100011
    #define LIS3DH_READ_CTRL_REG4 0xA3

    // 0b10100100
    #define LIS3DH_READ_CTRL_REG5 0xA4

    // 0b10100100
    #define LIS3DH_READ_FIFO_CTRL_REG 0xAE

    // 0b10100100
    #define LIS3DH_READ_FIFO_SRC_REG 0xAF


    /**
    *   \brief Address of the X axis output low register  A8 OR E8 for auto-increment address
    */
    #define LIS3DH_READ_OUT_X_L 0xE8

    /**
    *   \brief Address of the X axis output low register  A8 OR E8 for auto-increment address
    */
    #define LIS3DH_READ_OUT_Y_H 0xAB





    /**
    *   \brief Address of the Control register 1
    */
    #define LIS3DH_CTRL_REG1 0x20


    /**
    *   \brief Hex value to set low power mode to the accelerator and 100Hz data rate 0b0101 1111
    */
    #define LIS3DH_CTRL_REG1_LOW_POWER_MODE 0x5F


    /**
    *   \brief Hex value to set low power mode to the accelerator and 100Hz data rate 0b0101 1111
    */
    #define LIS3DH_CTRL_REG1_LOW_POWER_MODE_400 0x7F


    /**
    *   \brief Hex value to set low power mode to the accelerator and 100Hz data rate 0b0101 1111
    */
    #define LIS3DH_CTRL_REG1_NORMAL_MODE 0x57


    /**
    *   \brief Address of the Control register 3
    */
    #define LIS3DH_CTRL_REG3 0x22

    /**
    *   \brief Hex value to enable interrupt on pin INT1 when overrun occurs
    */
    #define LIS3DH_CTRL_REG3_I1_OVERRUN 0x02

    /**
    *   \brief Hex value to enable interrupt on pin INT1 when overrun occurs
    */
    #define LIS3DH_CTRL_REG3_NULL 0x00


    /**
    *   \brief Address of the Control register 4
    */
    #define LIS3DH_CTRL_REG4 0x23

    /**
    *   \brief Hex value to set output registers not updated until MSB and LSB reading, FSR +-2g
    */
    #define LIS3DH_CTRL_REG4_BDU_ACTIVE 0x80

    /**
    *   \brief Hex value to set output registers not updated until MSB and LSB reading, FSR +-2g
    */
    #define LIS3DH_CTRL_REG4_CONTINUOS_UPDATE 0x00

    /**
    *   \brief Address of the Control register 5
    */
    #define LIS3DH_CTRL_REG5 0x24

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_CTRL_REG5_FIFO_ENABLE 0x40

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_CTRL_REG5_FIFO_DISABLE 0x00

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_CTRL_REG5_REBOOT_MEMORY 0xC0

    /**
    *   \brief Address of the FIFO Control register 
    */
    #define LIS3DH_FIFO_CTRL_REG 0x2E

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_FIFO_CTRL_REG_BYPASS_MODE 0x00

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_FIFO_CTRL_REG_FIFO_MODE 0x40

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_FIFO_CTRL_REG_WTM 0x5F

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_FIFO_CTRL_REG_STREAM_MODE 0x80


    /**
    *   \brief Binary mask to check if FIFO_SRC_REG has empyt bit
    */
    #define LIS3DH_FIFO_EMPTY_MASK 0b00100000
    
       /**
    *   \brief Binary mask to check if FIFO_SRC_REG has empyt bit
    */
    #define LIS3DH_FIFO_OVR_MASK 0b01000000
    
    
    /**
    *   \brief Binary mask to check if FIFO_SRC_REG has empyt bit
    */
    #define LIS3DH_FIFO_DATA_TO_READ 0b00011111



    /**
    *   \brief Mask for the status register in order to check if data available
    */
    #define STATUS_REG_MASK 0x08 // 0b00001000 mask


    /*** ========= FUNCTION DECLARATIONS ========= ***/

    /** ====== Helper Functions ====== **/

    void IMU_RegistersSetup();
    
    void IMU_ReadFIFO(uint8_t *buffer);
    
    void IMU_DataSend(uint8_t *buffer);
    
    void IMU_ResetFIFO();
    
    /** ====== User-level Functions ====== **/

    /*
    * @brief Read a single byte @ addr.
    *
    * @param[in]: 16-bit memory address to read from.
    * @return Read value (1 unsigned byte).
    */
    uint8_t IMU_ReadByte(uint8_t address);

    /*
    * @brief Write a single byte with the value dataByte @ addr.
    *
    * @param[in]: 16-bit memory address to write to.
    * @param[out]: 8-bit (unsigned byte) value to write in the memory location.
    */
    void IMU_WriteByte(uint8_t address, uint8_t dataByte);

    /*
    * @brief Read 1+ bytes from memory.
    *
    * @param[in]: 16-bit memory address to from read.
    * @param[out]: uint8_t* pointer to the output data (cast operation required for different data type).
    * @param[in]: Number of bytes to read.
    *
    */
    void IMU_ReadMultyByte(uint8_t address, uint8_t* dataRX, uint8_t nBytes);
     
    /*
    * @brief Write 1+ bytes from memory.
    *
    * @param[in]: 16-bit memory address to write to.
    * @param[in]: uint8_t* pointer to the input data (max 64 bytes).
    */
    void IMU_WriteMultyByte(uint8_t address, uint8_t* data, uint8_t nBytes);
    
#endif

/* [] END OF FILE */