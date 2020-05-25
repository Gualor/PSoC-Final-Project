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
 * Save send flag into the EEPROM.
 */
void EEPROM_saveResetFlag(uint8_t flag)
{
    // Read current register content
    uint8_t ctrl_reg = EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Check state and setup mask
    if (flag == 1)
    {
        ctrl_reg |= CTRL_REG_PSOC_SET_RESET_FLAG;
    }
    else
    {
        ctrl_reg &= ~CTRL_REG_PSOC_SET_RESET_FLAG;
    }
    
    // Overwrite register content
    EEPROM_writeByte(CTRL_REG_PSOC_STATUS, ctrl_reg);
    EEPROM_waitForWriteComplete();
}

/*
 * Retrieve configuration mode flag from the EEPROM.
 */
uint8_t EEPROM_retrieveResetFlag(void)
{
    // Read current register content
    uint8_t ctrl_reg =  EEPROM_readByte(CTRL_REG_PSOC_STATUS);
    
    // Retrieve bit
    ctrl_reg &= CTRL_REG_PSOC_SET_RESET_FLAG;
    ctrl_reg = (ctrl_reg >> CTRL_REG_PSOC_RESET_FLAG_SHIFT) & 0x01;
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
    
    // Avoid variable overflow
    if (reg_count < sizeof(uint16_t))
    {
        // Increment counter
        reg_count++;
    
        // Store data in buffer
        uint8_t buffer[2];
        buffer[0] = reg_count & 0x00FF;
        buffer[1] = (reg_count >> 8) & 0x00FF;
        
        // Overwrite registers
        EEPROM_writePage(CTRL_REG_LOG_PAGES_LOW, buffer, 2);
        EEPROM_waitForWriteComplete();
    }   
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
        // Check how many log pages are currently stored
        uint16_t page_count = EEPROM_retrieveLogPages();
    
        // Compute first available address 
        uint16_t page_addr = LOG_DATA_BASE_ADDR + page_count * SPI_EEPROM_PAGE_SIZE;
        
        // Check if address is valid
        if (page_addr <= SPI_EEPROM_SIZE_BYTE - SPI_EEPROM_PAGE_SIZE)
        {
            // Write EEPROM page
            EEPROM_writePage(page_addr, dataPtr, nBytes);
            EEPROM_waitForWriteComplete();
        }
    }
}

/*
 * Store log type messages of 64 bytes inside first
 * unoccupied memory page.
 */
void EEPROM_storeLogMessage(log_t message, uint8_t dataSize)
{
    uint8_t buffer[64];
    
    // Updack struct and place data inside buffer
    buffer[0] = message.logID;
    buffer[1] = message.intReg;
    buffer[2] = (message.timestamp | 0xFF);
    buffer[3] = ((message.timestamp >> 8) | 0xFF);
    memcpy(message.data, &buffer[4], dataSize);
    
    // Store buffer in memory (size = header + payload)
    EEPROM_storeLogData(buffer, LOG_MESSAGE_HEADER_BYTE + dataSize);
    
    // Increment number of written pages
    EEPROM_incrementLogCounter();
}

/*
 * Overwrite all EEPROM memory with zeros and set reset flag inside
 * control register psoc status.
 */
void EEPROM_resetMemory(void)
{
    // Fill up buffer with zeros
    uint8_t resetBuffer[SPI_EEPROM_PAGE_SIZE];
    memset(resetBuffer, 0, SPI_EEPROM_PAGE_SIZE);
    
    // First available address
    uint16_t page_addr = 0x0000;
    
    // Reset all pages
    for (uint16_t i=0; i<SPI_EEPROM_PAGE_COUNT; i++)
    {
        // Compute next page address
        page_addr += SPI_EEPROM_PAGE_SIZE;
        
        // Reset page
        EEPROM_writePage(page_addr, resetBuffer, SPI_EEPROM_PAGE_SIZE);
    }
    
    // Set reset flag inside control register
    EEPROM_saveResetFlag(1);
    
}

/* [] END OF FILE */
