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

uint8_t EEPROM_readStatus() 
{
	return SPI_EEPROM_Interface_ReadByte(SPI_EEPROM_RDSR);
}

void EEPROM_writeEnable() 
{
	/* Send 1-byte Instruction */
	SPI_EEPROM_Interface_tradeByte(SPI_EEPROM_WREN);
}

/** ====== User-level Functions ====== **/

uint8_t EEPROM_readByte(uint16_t addr) 
{
	/* Prepare the TX data packet: instruction + address */
	uint8_t dataTX[3] = {SPI_EEPROM_READ, ((addr & 0xFF00) >> 8 ), (addr & 0x00FF)};
	
	/* Prepare the RX byte */
	uint8_t dataRX = 0;
	
	/* Read 1 byte from addr */
	SPI_EEPROM_Interface_Multi_RW(dataTX, 3, &dataRX, 1);
    
    return dataRX;
}

void EEPROM_writeByte(uint16_t addr, uint8_t dataByte) 
{
    /* Enable WRITE operations */
    EEPROM_writeEnable();
	
	/* Prepare the TX packet */
    uint8_t dataTX[4] = {SPI_EEPROM_WRITE, ((addr & 0xFF00) >> 8), (addr & 0x00FF), dataByte};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	/* Write 1 byte to addr */
	SPI_EEPROM_Interface_Multi_RW(dataTX, 4, &temp, 0);
}

void EEPROM_readPage(uint16_t addr, uint8_t* dataRX, uint8_t nBytes) 
{
	/* Prepare the TX data packet: instruction + address */
	uint8_t dataTX[3] = {SPI_EEPROM_READ, ((addr & 0xFF00) >> 8), (addr & 0x00FF)};
	
	/* Read the nBytes */
	SPI_EEPROM_Interface_Multi_RW(dataTX, 3, dataRX, nBytes);
}

void EEPROM_writePage(uint16_t addr, uint8_t* data, uint8_t nBytes) 
{
    /* Enable WRITE operations */
    EEPROM_writeEnable();
	
    CyDelayUs(1);
    
	/* Prepare the TX packet of size nBytes+3 
       [ Write Instruction - Address MSB - Address LSB - +++data+++ ]
    */
	uint8_t dataTX[3+nBytes];
    dataTX[0] = SPI_EEPROM_WRITE;
    dataTX[1] = (addr & 0xFF00) >> 8;
    dataTX[2] = addr & 0x00FF;
    /* Copy the input data in the memory */
	memcpy(&dataTX[3], data, nBytes);
	
	/* Nothing to RX: point to a dummy variable */
	uint8_t temp = 0;
	
	SPI_EEPROM_Interface_Multi_RW(dataTX, 3+nBytes, &temp, 0);
}

void EEPROM_waitForWriteComplete() 
{
    while( EEPROM_readStatus() & SPI_EEPROM_WRITE_IN_PROGRESS );
}

/*
 * Save start/stop state bit into the EEPROM.
 */
void EEPROM_saveStartStopState(uint8_t state)
{
    // Read current register content
    uint8_t ctrl_reg = EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Check state and setup mask
    if (state == 1)
    {
        ctrl_reg |= CTRL_REG_PSOC_SET_START;
    }
    else
    {
        ctrl_reg &= ~CTRL_REG_PSOC_SET_START;
    }
    
    // Overwrite register content
    EEPROM_writeByte(CTRL_REG_PSOC_STATUS, ctrl_reg);
    EEPROM_waitForWriteComplete();
}

/*
 * Retrieve start/stop state bit from the EEPROM.
 */
uint8_t EEPROM_retrieveStartStopState(void)
{
    // Read current register content
    uint8_t ctrl_reg = EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Retrieve bit
    ctrl_reg &= CTRL_REG_PSOC_SET_START;
    ctrl_reg = (ctrl_reg >> CTRL_REG_PSOC_START_STOP_SHIFT) & 0x01;
    return ctrl_reg;
}

/*
 * Save configuration mode flag into the EEPROM.
 */
void EEPROM_saveConfigFlag(uint8_t flag)
{
    // Read current register content
    uint8_t ctrl_reg = EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Check state and setup mask
    if (flag == 1)
    {
        ctrl_reg |= CTRL_REG_PSOC_SET_CONFIG;
    }
    else
    {
        ctrl_reg &= ~CTRL_REG_PSOC_SET_CONFIG;
    }
    
    // Overwrite register content
    EEPROM_writeByte(CTRL_REG_PSOC_STATUS, ctrl_reg);
    EEPROM_waitForWriteComplete();
}

/*
 * Retrieve configuration mode flag from the EEPROM.
 */
uint8_t EEPROM_retrieveConfigFlag(void)
{
    // Read current register content
    uint8_t ctrl_reg =  EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Retrieve bit
    ctrl_reg &= CTRL_REG_PSOC_SET_CONFIG;
    ctrl_reg = (ctrl_reg >> CTRL_REG_PSOC_CONFIG_MODE_SHIFT) & 0x01;
    return ctrl_reg;
}

/*
 * Save send flag into the EEPROM.
 */
void EEPROM_saveSendFlag(uint8_t flag)
{
    // Read current register content
    uint8_t ctrl_reg = EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Check state and setup mask
    if (flag == 1)
    {
        ctrl_reg |= CTRL_REG_PSOC_SET_SEND_FLAG;
    }
    else
    {
        ctrl_reg &= ~CTRL_REG_PSOC_SET_SEND_FLAG;
    }
    
    // Overwrite register content
    EEPROM_writeByte(CTRL_REG_PSOC_STATUS, ctrl_reg);
    EEPROM_waitForWriteComplete();
}

/*
 * Retrieve configuration mode flag from the EEPROM.
 */
uint8_t EEPROM_retrieveSendFlag(void)
{
    // Read current register content
    uint8_t ctrl_reg =  EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Retrieve bit
    ctrl_reg &= CTRL_REG_PSOC_SET_SEND_FLAG;
    ctrl_reg = (ctrl_reg >> CTRL_REG_PSOC_SEND_FLAG_SHIFT) & 0x01;
    return ctrl_reg;
}

/*
 * Read number of logs currently stored in the EEPROM.
 */
uint16_t EEPROM_retrieveLogPages(void)
{
    // Read current registers and increment counter
    uint16_t reg_count = EEPROM_readByte(CTRL_REG_LOG_PAGES_HIGH) << 8;
    reg_count |= EEPROM_readByte(CTRL_REG_LOG_PAGES_LOW);
    
    // Return log counter
    return reg_count;
}

/*
 * Increment by 1 number of logs of the log control register.
 */
void EEPROM_incrementLogCounter()
{
    // Read number of already written pages
    uint16_t reg_count = EEPROM_retrieveLogPages();
    reg_count++;
    
    // Divide into two 8-bit registers
    uint8_t reg_count_low = reg_count & 0x00FF;
    uint8_t reg_count_high = (reg_count >> 8) & 0x00FF;
    
    // Overwrite registers
    EEPROM_writeByte(CTRL_REG_LOG_PAGES_LOW, reg_count_low);
    EEPROM_waitForWriteComplete();
    EEPROM_writeByte(CTRL_REG_LOG_PAGES_HIGH, reg_count_high);
    EEPROM_waitForWriteComplete();
    
    // TODO: CHECK OVERFLOW
}

/*
 * Store log data buffer inside first unoccupied memory page
 * inside the EEPROM. Writing a data buffer of size greater 
 * than page size will be prevented.
 */
void EEPROM_storeLogData(uint8_t* dataPtr, uint8_t nBytes)
{
    // Check page boundary
    if (nBytes <= SPI_EEPROM_PAGE_SIZE)
    {
        // Check of many logs currently stored
        uint16_t page_count = EEPROM_retrieveLogPages();
    
        // Compute first available address 
        uint16_t page_addr = LOG_DATA_BASE_ADDR + page_count * SPI_EEPROM_PAGE_SIZE;
        
        // Write EEPROM page
        EEPROM_writePage(page_addr, dataPtr, nBytes);
        EEPROM_waitForWriteComplete();
    }
}

/* [] END OF FILE */
