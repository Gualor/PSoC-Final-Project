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
    
    #define LIS3DH_FIFO_BYTES_IN_LEVEL 6
    #define LIS3DH_LEVELS_IN_FIFO 32
    #define LIS3DH_BYTES_IN_FIFO 192
    #define LIS3DH_BYTES_IN_FIFO_HIGH_REG 96
    #define LIS3DH_FIFO_STORED 6
    #define LIS3DH_DOWN_SAMPLE 2
    #define LIS3DH_BYTES_IN_FIFO_DOWNSAMPLED LIS3DH_BYTES_IN_FIFO_HIGH_REG/LIS3DH_DOWN_SAMPLE
    #define LIS3DH_BYTES_IN_LOG_BUFFER LIS3DH_BYTES_IN_FIFO_DOWNSAMPLED * LIS3DH_FIFO_STORED // 16 levels * 3 registers * 6 FIFO
    
    
    uint8_t IMU_DataBuffer[LIS3DH_BYTES_IN_FIFO];
    
    uint8_t IMU_log_queue[LIS3DH_BYTES_IN_LOG_BUFFER];
    

     /*** ========= MACROS ========= ***/   

    /** Instruction Set **/
    #define LIS3DH_READ_BIT 0b10000000
    #define LIS3DH_AUTO_INCREMENT_ADDRESS 0b01000000
    
    
    
    /**
    * \brief Address of the read address of  WHO AM I REG
    */
    #define LIS3DH_WHO_AM_I_REG  0x0F
    
    /**
    * \brief Address of the read address of  WHO AM I REG
    */
    #define LIS3DH_STATUS_REG  0x27
    
    /**
    *   \brief Mask for the status register in order to check if data available
    */
    #define STATUS_REG_MASK 0x08

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
    *   \brief Hex value to set low power mode to the accelerator and 200Hz data rate 0b0101 1111
    */
    #define LIS3DH_CTRL_REG1_LOW_POWER_MODE_200 0x6F
    
    /**
    *   \brief Hex value to set low power mode to the accelerator and 400Hz data rate 0b0101 1111
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
    *   \brief Hex value to enable interrupt on overrun
    */
    #define LIS3DH_CTRL_REG3_I1_OVERRUN 0x02
    
    /**
    *   \brief Hex value to enable interrupt on IA1 and overrun
    */
    #define LIS3DH_CTRL_REG3_I1_IA1_OVERRUN 0x42

    /**
    *   \brief Hex value to enable interrupt on pin INT1 when overrun occurs
    */
    #define LIS3DH_CTRL_REG3_NULL 0x00

    /**
    *   \brief Address of the Control register 4
    */
    #define LIS3DH_CTRL_REG4 0x23

    /**
    *   \brief Hex value to set output registers not updated until MSB and LSB reading, FSR +-2g and SPI 4 wire interface
    */
    #define LIS3DH_CTRL_REG4_BDU_ACTIVE 0x80

    /**
    *   \brief Address of the Control register 5
    */
    #define LIS3DH_CTRL_REG5 0x24

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_CTRL_REG5_FIFO_ENABLE 0x40

    /**
    *   \brief Hex value to disable FIFO mode
    */
    #define LIS3DH_CTRL_REG5_FIFO_DISABLE 0x00
    
    /**
    *   \brief Hex value to enable FIFO mode and latched option for isr
    */
    #define LIS3DH_CTRL_REG5_FIFO_ENABLE_LIR_INT1 0x48

    /**
    *   \brief Hex value to reboot memory
    */
    #define LIS3DH_CTRL_REG5_REBOOT_MEMORY 0xC0

    /**
    *   \brief Address of the FIFO Control register 
    */
    #define LIS3DH_FIFO_CTRL_REG 0x2E

    /**
    *   \brief Hex value to enable BYPASS mode
    */
    #define LIS3DH_FIFO_CTRL_REG_BYPASS_MODE 0x00

    /**
    *   \brief Hex value to enable FIFO mode
    */
    #define LIS3DH_FIFO_CTRL_REG_FIFO_MODE 0x40

    /**
    *   \brief Hex value to enable FIFO mode with wtm
    */
    #define LIS3DH_FIFO_CTRL_REG_WTM 0x5F

    /**
    *   \brief Hex value to enable STREAM mode
    */
    #define LIS3DH_FIFO_CTRL_REG_STREAM_MODE 0x80
    
    /**
    *   \brief Address of the FIFO Control register 
    */
    #define LIS3DH_FIFO_SRC_REG 0x2F
    
    /**
    *   \brief Binary mask to check if FIFO_SRC_REG has empyt bit set to 1
    */
    #define LIS3DH_FIFO_SRC_REG_EMPTY_MASK 0b00100000
    
    /**
    *   \brief Binary mask to check if FIFO_SRC_REG has overrun bit set to 1
    */
    #define LIS3DH_FIFO_SRC_REG_OVR_MASK 0b01000000
    
    /**
    *   \brief Binary mask to check how many data are store in the FIFO
    */
    #define LIS3DH_FIFO_SRC_DATA_TO_READ 0b00011111
    
    /**
    *   \brief Address of the INT1 CFG register 
    */
    #define LIS3DH_INT1_CFG 0x30
    
    /**
    *   \brief Hex value to set isr on high events for all the 3 axis
    */
    #define LIS3DH_INT1_CFG_HIGH_EVENTS 0x2A
    
    /**
    *   \brief Address of the INT1 SRC register 
    */
    #define LIS3DH_INT1_SRC 0x31
    
    /**
    *   \brief Mask for INT1 SRC register to detect isr occurrences
    */
    #define LIS3DH_INT1_SRC_IA_MASK 0b01000000
    
    /**
    *   \brief Address of the INT1 THS register 
    */
    #define LIS3DH_INT1_THS 0x32
    
    /**
    *   \brief Hex value for the threshold of each IMU axis
    */
    #define LIS3DH_INT1_THS_VALUE 0x64 //@+-2G FSR ---> 1 LSB = 16mG ---> 0x64 ---> 1.6G
    
    /**
    *   \brief Address of the INT1 DURATION register 
    */
    #define LIS3DH_INT1_DURATION 0x33
    
    /**
    *   \brief Hex value for the time duration of an overthreshold event
    */
    //#define LIS3DH_INT1_DURATION_VALUE 0x0A // @ 200Hx ODR --> 5 ms every lsb --> 50ms total
    
    #define LIS3DH_INT1_DURATION_VALUE 0x04 // @ 200Hx ODR --> 5 ms every lsb --> 20ms total



    /*** ========= FUNCTION DECLARATIONS ========= ***/

    /** ====== Helper Functions ====== **/

    void IMU_RegistersSetup(void);
    
    void IMU_ReadFIFO(uint8_t *buffer);
    
    void IMU_DataSend(uint8_t *buffer);
    
    void IMU_StoreFIFO(uint8_t *buffer);
    
    void IMU_ResetFIFO(void);
    
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