/**
 * @file LIS3DH.c
 * @brief Functions required to interface with the SPI  LIS3DH ACCELEROMETER.
 * 
 * This c file contains the API functions to interface
 * with the SPI LIS3DH ACCELEROMETER.
 *
*/

#include "LIS3DH.h"
#include <stdio.h>

char bufferUART[100];

/** ====== Helper Functions ====== **/
void IMU_RegistersSetup()
{
     UART_PutString("*********    LIS3DH TEST    *********\r\n");
    
    // Read WHO_AM_I Register
    uint8_t who_am_i = SPI_Interface_ReadByte(LIS3DH_READ_WHO_AM_I_REG);
    
    sprintf(bufferUART, "WHO AM I REG: 0x%02X [Expected: 0x33]\r\n", who_am_i);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    // Read Status Register
    uint8_t status_reg = SPI_Interface_ReadByte(LIS3DH_READ_STATUS_REG);
    
    sprintf(bufferUART, "STATUS REG: 0x%02X \r\n", status_reg);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    /******************************************/
    /*    Setup Control Register 1            */
    /******************************************/
    
    // Read actual value
    uint8_t ctrl_reg1 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG1);
    
    sprintf(bufferUART, "CTRL REG1: 0x%02X \r\n", ctrl_reg1);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t CTRL1TX[2] = {LIS3DH_CTRL_REG1, LIS3DH_CTRL_REG1_LOW_POWER_MODE_400};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	/* Write 1 byte to addr */
	SPI_Interface_Multi_RW(CTRL1TX, 2, &temp, 0);
    
    // Read Control Register 1 again
    ctrl_reg1 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG1);
    
    sprintf(bufferUART, "CTRL REG1 AFTER WRITE: 0x%02X \r\n", ctrl_reg1);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    /******************************************/
    /*    Setup Control Register 3            */
    /******************************************/    
    
     // Read actual value
    uint8_t ctrl_reg3 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG3);
    
    sprintf(bufferUART, "CTRL REG3: 0x%02X \r\n", ctrl_reg3);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write
    /* Prepare the TX packet */
    uint8_t CTRL3TX[2] = {LIS3DH_CTRL_REG3, LIS3DH_CTRL_REG3_I1_OVERRUN};
	/* Nothing to RX... */
	temp = 0;
	
	
	SPI_Interface_Multi_RW(CTRL3TX, 2, &temp, 0);
    
    // Read Control Register 3 again
    ctrl_reg3 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG3);
    
    sprintf(bufferUART, "CTRL REG3 AFTER WRITE: 0x%02X \r\n", ctrl_reg3);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    /******************************************/
    /*    Setup Control Register 4            */
    /******************************************/
    
    // Read actual value
    uint8_t ctrl_reg4 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG4);
    
    sprintf(bufferUART, "CTRL REG4: 0x%02X \r\n", ctrl_reg4);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t CTRL4TX[2] = {LIS3DH_CTRL_REG4, LIS3DH_CTRL_REG4_BDU_ACTIVE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_Interface_Multi_RW(CTRL4TX, 2, &temp, 0);
    
    // Read Control Register 4 again
    ctrl_reg4 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG4);
    
    sprintf(bufferUART, "CTRL REG4 AFTER WRITE: 0x%02X \r\n", ctrl_reg4);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    /******************************************/
    /*    Setup Control Register 5            */
    /******************************************/
    
    // Read actual value
    uint8_t ctrl_reg5 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG5);
    
    sprintf(bufferUART, "CTRL REG5: 0x%02X \r\n", ctrl_reg5);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t CTRL5TX[2] = {LIS3DH_CTRL_REG5, LIS3DH_CTRL_REG5_FIFO_ENABLE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_Interface_Multi_RW(CTRL5TX, 2, &temp, 0);
    
    // Read Control Register 5 again
    ctrl_reg5 = SPI_Interface_ReadByte(LIS3DH_READ_CTRL_REG5);
    
    sprintf(bufferUART, "CTRL REG5 AFTER WRITE: 0x%02X \r\n", ctrl_reg5);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    
    /******************************************/
    /*    Flush FIFO before start             */
    /******************************************/
            
    
    while(!(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG) & LIS3DH_FIFO_EMPTY_MASK))
    {
        
        uint8_t dataTX = LIS3DH_READ_OUT_X_L;
        uint8_t dataRX[6];
        SPI_Interface_Multi_RW(&dataTX, 1, dataRX, 6);        
        UART_PutString("----FIFO FLUSHING-----\r\n");
    }
   
    UART_PutString("*********FIFO FLUSHED\r\n");
    
    
    
     // Reset FIFO
    uint8_t BYPASSTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_BYPASS_MODE};
	temp = 0;
	SPI_Interface_Multi_RW(BYPASSTX, 2, &temp, 0);
    
    CyDelayUs(1);
    
    

    /******************************************/
    /*    Setup FIFO Control Register         */
    /******************************************/

    // Read actual value
    uint8_t fifo_ctrl = SPI_Interface_ReadByte(LIS3DH_READ_FIFO_CTRL_REG);
    
    sprintf(bufferUART, "FIFO CTRL REG: 0x%02X \r\n", fifo_ctrl);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t FIFOTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_FIFO_MODE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_Interface_Multi_RW(FIFOTX, 2, &temp, 0);
    
    // Read FIFO Control Register again
    fifo_ctrl = SPI_Interface_ReadByte(LIS3DH_READ_FIFO_CTRL_REG);
    
    sprintf(bufferUART, "FIFO CTRL REG AFTER WRITE: 0x%02X \r\n", fifo_ctrl);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n"); 
    
}


/** ====== User-level Functions ====== **/

uint8_t IMU_ReadByte(uint8_t address) 
{
    
    // LIS3DH bit set to read
    address |= LIS3DH_READ_BIT;
	/* Prepare the TX data packet: instruction + address */
	uint8_t dataRX = SPI_Interface_ReadByte(address) ;
	
	return dataRX;
    
}

void IMU_WriteByte(uint8_t address, uint8_t dataByte) 
{
    
	/* Prepare the TX packet */
    uint8_t dataTX[2] = {address, dataByte};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	/* Write 1 byte to addr */
	SPI_Interface_Multi_RW(dataTX, 2, &temp, 0);
	    
}

void IMU_ReadMultyByte(uint8_t address, uint8_t* dataRX, uint8_t nBytes) 
{
    
     // LIS3DH bit set to read and auto increment address to read
    address =  address | LIS3DH_READ_BIT | LIS3DH_AUTO_INCREMENT_ADDRESS;
    
	/* Prepare the TX data packet: instructon + address */
	/* Read the nBytes */
	SPI_Interface_Multi_RW(&address, 1, dataRX,  nBytes);
	
	
		
}


void IMU_WriteMultyByte(uint8_t address, uint8_t* data, uint8_t nBytes) 
{
    
    // Auto increment bit address to write
    address |= LIS3DH_AUTO_INCREMENT_ADDRESS;
    
	uint8_t dataTX[1+nBytes];
    dataTX[0] = address;
    /* Copy the input data in the memory */
	memcpy(&dataTX[1], data, nBytes);

	/* Nothing to RX... */
	uint8_t temp = 0;
    
	/* Read the nBytes */
	SPI_Interface_Multi_RW(dataTX, nBytes, &temp, 0);
		
}


void IMU_ReadFIFO(uint8_t *buffer)
{   
    //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
    
    // Obtain the number of unread samples in the FIFO throuh masking the FIFO src reg
    //uint8_t dataToRead = (SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG) & LIS3DH_FIFO_DATA_TO_READ);
    
    //UART_PutChar(dataToRead);
	uint8_t dataTX = LIS3DH_READ_OUT_X_L;
  
    // Read one level of the FIFO at the time (6 bytes)
    for(int i = 0; i < 32 ; i++)
    {              
        SPI_Interface_Multi_RW(&dataTX, 1, &buffer[i*6], LIS3DH_FIFO_BYTES_IN_LEVEL);
        //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
    }
    //UART_PutChar(SPI_Interface_ReadByte(LIS3DH_READ_FIFO_SRC_REG));
}

void IMU_DataSend(uint8_t *buffer)
{
    uint8_t DataBuffer[8];
    DataBuffer[0] = 0xA0;
    DataBuffer[7] = 0xC0;

    
    // Send uart 6 registers at time
    for(int i = 0; i < 32 ; i++)
    {              
        for(int j = 1; j < 7; j++)
        {   
            DataBuffer[j] = buffer[i*6 + j-1];
        }
        UART_PutArray(DataBuffer, 8);
    }
}

void IMU_ResetFIFO()
{
    
    // Set bypass mode
    uint8_t BYPASSTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_BYPASS_MODE};
	uint8_t temp = 0;
	SPI_Interface_Multi_RW(BYPASSTX, 2, &temp, 0);
    
    CyDelayUs(1);
    
    
    
    // Set FIFO mode again
    uint8_t FIFOTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_FIFO_MODE};
	temp = 0;
	SPI_Interface_Multi_RW(FIFOTX, 2, &temp, 0);
   
    
}

/* [] END OF FILE */
