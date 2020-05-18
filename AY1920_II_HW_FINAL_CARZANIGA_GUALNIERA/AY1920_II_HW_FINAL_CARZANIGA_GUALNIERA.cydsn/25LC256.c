/**
 * @file 25LC256.c
 * @brief Functions required to interface with the SPI EEPROM 25LC256.
 * 
 * This c file contains the API functions to interface
 * with the SPI EEPROM 25LC256.
 *
 * @author Mattia Pesenti
 * @date 24 March, 2020
*/

#include "25LC256.h"

uint8_t eeprom_Status;

/** ====== Helper Functions ====== **/

uint8_t EEPROM_readStatus() {
    
	return SPI_Interface_ReadByte(SPI_EEPROM_RDSR);
    
}

void EEPROM_writeEnable() {
    
	/* Send 1-byte Instruction */
	SPI_Interface_tradeByte(SPI_EEPROM_WREN);
    
}

/** ====== User-level Functions ====== **/

uint8_t EEPROM_readByte(uint16_t addr) {

	/* Prepare the TX data packet: instruction + address */
	uint8_t dataTX[3] = {SPI_EEPROM_READ, ((addr & 0xFF00) >> 8 ), (addr & 0x00FF)};
	
	/* Prepare the RX byte */
	uint8_t dataRX = 0;
	
	/* Read 1 byte from addr */
	SPI_Interface_Multi_RW(dataTX, 3, &dataRX, 1);
    
    return dataRX;
	
	
    
}

void EEPROM_writeByte(uint16_t addr, uint8_t dataByte) {
    
    /* Enable WRITE operations */
    EEPROM_writeEnable();
	
	/* Prepare the TX packet */
    uint8_t dataTX[4] = {SPI_EEPROM_WRITE, ((addr & 0xFF00) >> 8), (addr & 0x00FF), dataByte};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	/* Write 1 byte to addr */
	SPI_Interface_Multi_RW(dataTX, 4, &temp, 0);
	    
}

void EEPROM_readPage(uint16_t addr, uint8_t* dataRX, uint8_t nBytes) {
    
	
		
}

void EEPROM_writePage(uint16_t addr, uint8_t* data, uint8_t nBytes) {
	    
    
	
}

void EEPROM_waitForWriteComplete() {
    
    while( EEPROM_readStatus() & SPI_EEPROM_WRITE_IN_PROGRESS );
    
}

/* [] END OF FILE */
