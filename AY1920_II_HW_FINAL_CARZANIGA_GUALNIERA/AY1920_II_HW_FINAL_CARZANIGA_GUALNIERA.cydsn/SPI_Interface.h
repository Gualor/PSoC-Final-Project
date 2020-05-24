/**
 * @file SPI_Interface.h
 * @brief Functions required to interface with the SPI MASTER (SPIM).
 * 
 * This header file contains macros and function prototypes to interface
 * with the SPI Master (SPIM) of the PSoC.
 *
 * @author Mattia Pesenti
 * @date 9 April, 2020
*/

/*											 
 * NOTE: in the .h Lib of the SPI Slave     		   *
 *       you need to define SLAVE_CS_Write  		   *
 *       with the name of the Chip Select    		   * 
 *       pin (as defined in the Top Design)  		   *
 * E.g.: #define SLAVE_CS_Write CS_1_Write (default)   *
*/

#pragma once

#include "project.h"

#define SPI_DUMMY_BYTE  0x00

/* ======= PARAMETERS DEPENDING ON THE MASTER ======= */
#define SPI_TxBufferSize 8
#define SPI_RxBufferSize 8
/* ================================================= */



/**
*   \brief Hex value to set high mode to the accelerator and 100Hz data rate
*/
#define LIS3DH_NORMAL_MODE_CTRL_REG1 0x57

    
/**
*   \brief Address of the read address byte on SPI 0b1110 1000  (Read[0], Increment address[1], register address[2:7] )
                                     WHO AM I REG  0b1000 1111
*/
#define LIS3DH_SPI_WHO_AM_I_REG  0x8F

// 0b10100111
#define LIS3DH_SPI_STATUS_REG  0xA7


// 0b1010 0000
#define LIS3DH_SPI_CTRL_REG1  0xA0


/*
* @brief Full-Duplex, Single-Operation 1-Byte Trade
*
* This Function writes 1 byte (TX) on the MOSI line while reading (RX)
* one byte from the slave on the MISO line (simultaneous TX/RX)
*
* @param[in]: uint8_t byte > 1-byte word to TX
*
* @return: uint8_t > received 1-byte word 
*/
uint8_t SPI_IMU_Interface_tradeByte(uint8_t byte);

/*
* @brief RX-only, Dual-Operation 1-Byte READ
*
* This Function requests 1 byte from the SPI Slave.
* First, it sends (TX) a 1-byte address/instruction to the Slave
* that replies on the next clock cycle.
* One byte from the slave is read on the MISO line 
* on the next clock cycle, while transmetting a 
* dummy byte (0x00)
*
* @param[in]: uint8_t byte > 1-byte address/instruction to TX
*
* @return: uint8_t > received 1-byte word 
*/
uint8_t SPI_IMU_Interface_ReadByte(uint8_t addr);

/*
* @brief Full-Duplex, Multi-Byte Trade (RX/TX)
*
* This Function writes *nBytes* bytes (TX) on the MOSI line while reading (RX)
* *nBytes* bytes from the slave on the MISO line (simultaneous TX/RX)
*
* @param[in]:  uint8_t* dataTX > Pointer to the input (TX) data array
* @param[out]: uint8_t* dataRX > Pointer to the output (RX) data array
* @param[in]:  uint8_t nBytes  > Number of bytes to TX/RX
*/
void SPI_IMU_Interface_Multi_Trade(uint8_t* dataTX, uint8_t* dataRX, uint8_t nBytes);

/*
* @brief RX-only, Dual-Operation Multi-Byte READ/WRITE
*
* This Function FIRST sends *bytesTX* bytes to the SPI Slave.
* Then, it reads *bytesRX* bytes from the slave while 
* transmitting dummy bytes (0x00).
* Read/write operations are not simultaneous: data may be requested
* to the slave with the TX operation and then read afterwards.
*
* @param[in]:  uint8_t* dataTX > Pointer to the input (TX) data array
* @param[in]:  uint8_t bytesTX > Number of bytes to transmit
* @param[out]: uint8_t* dataRX > Pointer to the output (RX) data array
* @param[in]:  uint8_t bytesRX  > Number of bytes to receive
*/
void SPI_IMU_Interface_Multi_RW(uint8_t* dataTX, uint8_t bytesTX, uint8_t* dataRX, uint8_t bytesRX);

/*
* @brief Full-Duplex, Single-Operation 1-Byte Trade
*
* This Function writes 1 byte (TX) on the MOSI line while reading (RX)
* one byte from the slave on the MISO line (simultaneous TX/RX)
*
* @param[in]: uint8_t byte > 1-byte word to TX
*
* @return: uint8_t > received 1-byte word 
*/
uint8_t SPI_EEPROM_Interface_tradeByte(uint8_t byte);

/*
* @brief RX-only, Dual-Operation 1-Byte READ
*
* This Function requests 1 byte from the SPI Slave.
* First, it sends (TX) a 1-byte address/instruction to the Slave
* that replies on the next clock cycle.
* One byte from the slave is read on the MISO line 
* on the next clock cycle, while transmetting a 
* dummy byte (0x00)
*
* @param[in]: uint8_t byte > 1-byte address/instruction to TX
*
* @return: uint8_t > received 1-byte word 
*/
uint8_t SPI_EEPROM_Interface_ReadByte(uint8_t addr);

/*
* @brief Full-Duplex, Multi-Byte Trade (RX/TX)
*
* This Function writes *nBytes* bytes (TX) on the MOSI line while reading (RX)
* *nBytes* bytes from the slave on the MISO line (simultaneous TX/RX)
*
* @param[in]:  uint8_t* dataTX > Pointer to the input (TX) data array
* @param[out]: uint8_t* dataRX > Pointer to the output (RX) data array
* @param[in]:  uint8_t nBytes  > Number of bytes to TX/RX
*/
void SPI_EEPROM_Interface_Multi_Trade(uint8_t* dataTX, uint8_t* dataRX, uint8_t nBytes);

/*
* @brief RX-only, Dual-Operation Multi-Byte READ/WRITE
*
* This Function FIRST sends *bytesTX* bytes to the SPI Slave.
* Then, it reads *bytesRX* bytes from the slave while 
* transmitting dummy bytes (0x00).
* Read/write operations are not simultaneous: data may be requested
* to the slave with the TX operation and then read afterwards.
*
* @param[in]:  uint8_t* dataTX > Pointer to the input (TX) data array
* @param[in]:  uint8_t bytesTX > Number of bytes to transmit
* @param[out]: uint8_t* dataRX > Pointer to the output (RX) data array
* @param[in]:  uint8_t bytesRX  > Number of bytes to receive
*/
void SPI_EEPROM_Interface_Multi_RW(uint8_t* dataTX, uint8_t bytesTX, uint8_t* dataRX, uint8_t bytesRX);

/* [] END OF FILE */
