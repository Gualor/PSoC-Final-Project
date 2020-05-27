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
    //uint8_t who_am_i = SPI_IMU_Interface_ReadByte(LIS3DH_READ_WHO_AM_I_REG);
    uint8_t who_am_i = IMU_ReadByte(LIS3DH_WHO_AM_I_REG);
    
    sprintf(bufferUART, "WHO AM I REG: 0x%02X [Expected: 0x33]\r\n", who_am_i);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    // Read Status Register
    uint8_t status_reg = IMU_ReadByte(LIS3DH_STATUS_REG);
    
    sprintf(bufferUART, "STATUS REG: 0x%02X \r\n", status_reg);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    /******************************************/
    /*    Setup Control Register 1            */
    /******************************************/
    
    // Read actual value
    uint8_t ctrl_reg1 = IMU_ReadByte(LIS3DH_CTRL_REG1);
    
    sprintf(bufferUART, "CTRL REG1: 0x%02X \r\n", ctrl_reg1);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t CTRL1TX[2] = {LIS3DH_CTRL_REG1, LIS3DH_CTRL_REG1_LOW_POWER_MODE_200};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	/* Write 1 byte to addr */
	SPI_IMU_Interface_Multi_RW(CTRL1TX, 2, &temp, 0);
    
    // Read Control Register 1 again
    ctrl_reg1 = IMU_ReadByte(LIS3DH_CTRL_REG1);
    
    sprintf(bufferUART, "CTRL REG1 AFTER WRITE: 0x%02X \r\n", ctrl_reg1);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    /******************************************/
    /*    Setup Control Register 3            */
    /******************************************/    
    
     // Read actual value
    uint8_t ctrl_reg3 = IMU_ReadByte(LIS3DH_CTRL_REG3);
    
    sprintf(bufferUART, "CTRL REG3: 0x%02X \r\n", ctrl_reg3);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write
    /* Prepare the TX packet */
    uint8_t CTRL3TX[2] = {LIS3DH_CTRL_REG3, LIS3DH_CTRL_REG3_I1_IA1_OVERRUN};
	/* Nothing to RX... */
	temp = 0;
	
	
	SPI_IMU_Interface_Multi_RW(CTRL3TX, 2, &temp, 0);
    
    // Read Control Register 3 again
    ctrl_reg3 = IMU_ReadByte(LIS3DH_CTRL_REG3);
    
    sprintf(bufferUART, "CTRL REG3 AFTER WRITE: 0x%02X \r\n", ctrl_reg3);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    /******************************************/
    /*    Setup Control Register 4            */
    /******************************************/
    
    // Read actual value
    uint8_t ctrl_reg4 = IMU_ReadByte(LIS3DH_CTRL_REG4);
    
    sprintf(bufferUART, "CTRL REG4: 0x%02X \r\n", ctrl_reg4);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t CTRL4TX[2] = {LIS3DH_CTRL_REG4, LIS3DH_CTRL_REG4_BDU_ACTIVE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_IMU_Interface_Multi_RW(CTRL4TX, 2, &temp, 0);
    
    // Read Control Register 4 again
    ctrl_reg4 = IMU_ReadByte(LIS3DH_CTRL_REG4);
    
    sprintf(bufferUART, "CTRL REG4 AFTER WRITE: 0x%02X \r\n", ctrl_reg4);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    /******************************************/
    /*    Setup Control Register 5            */
    /******************************************/
    
    // Read actual value
    uint8_t ctrl_reg5 = IMU_ReadByte(LIS3DH_CTRL_REG5);
    
    sprintf(bufferUART, "CTRL REG5: 0x%02X \r\n", ctrl_reg5);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t CTRL5TX[2] = {LIS3DH_CTRL_REG5, LIS3DH_CTRL_REG5_FIFO_ENABLE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_IMU_Interface_Multi_RW(CTRL5TX, 2, &temp, 0);
    
    // Read Control Register 5 again
    ctrl_reg5 = IMU_ReadByte(LIS3DH_CTRL_REG5);
    
    sprintf(bufferUART, "CTRL REG5 AFTER WRITE: 0x%02X \r\n", ctrl_reg5);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    
    /******************************************/
    /*    Flush FIFO before start             */
    /******************************************/
            
    
    while(!(IMU_ReadByte(LIS3DH_FIFO_SRC_REG) & LIS3DH_FIFO_SRC_REG_EMPTY_MASK))
    {
        
        uint8_t dataTX = LIS3DH_READ_OUT_X_L;
        uint8_t dataRX[6];
        SPI_IMU_Interface_Multi_RW(&dataTX, 1, dataRX, 6);        
        UART_PutString("----FIFO FLUSHING-----\r\n");
    }
   
    UART_PutString("*********FIFO FLUSHED\r\n");
    
    
    
     // Reset FIFO
    uint8_t BYPASSTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_BYPASS_MODE};
	temp = 0;
	SPI_IMU_Interface_Multi_RW(BYPASSTX, 2, &temp, 0);
    
    CyDelayUs(1);
    
    

    /******************************************/
    /*    Setup FIFO Control Register         */
    /******************************************/

    // Read actual value
    uint8_t fifo_ctrl = IMU_ReadByte(LIS3DH_FIFO_CTRL_REG);
    
    sprintf(bufferUART, "FIFO CTRL REG: 0x%02X \r\n", fifo_ctrl);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t FIFOTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_FIFO_MODE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_IMU_Interface_Multi_RW(FIFOTX, 2, &temp, 0);
    
    // Read FIFO Control Register again
    fifo_ctrl = IMU_ReadByte(LIS3DH_FIFO_CTRL_REG);
    
    sprintf(bufferUART, "FIFO CTRL REG AFTER WRITE: 0x%02X \r\n", fifo_ctrl);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    /******************************************/
    /*    Setup INT1_CGF Register             */
    /******************************************/

    // Read actual value
    uint8_t int1_cfg = IMU_ReadByte(LIS3DH_INT1_CFG);
    
    sprintf(bufferUART, "INT1 CFG REG: 0x%02X \r\n", int1_cfg);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t INT1TX[2] = {LIS3DH_INT1_CFG, LIS3DH_INT1_CFG_HIGH_EVENTS};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_IMU_Interface_Multi_RW(INT1TX, 2, &temp, 0);
    
    // Read INT1 CFG Register again
    int1_cfg = IMU_ReadByte(LIS3DH_INT1_CFG);
    
    sprintf(bufferUART, "INT1 CFG REG AFTER WRITE: 0x%02X \r\n", int1_cfg);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    /******************************************/
    /*    Setup INT1_THS Register             */
    /******************************************/

    // Read actual value
    uint8_t int1_ths = IMU_ReadByte(LIS3DH_INT1_THS);
    
    sprintf(bufferUART, "INT1 THS REG: 0x%02X \r\n", int1_ths);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t THSTX[2] = {LIS3DH_INT1_THS, LIS3DH_INT1_THS_VALUE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_IMU_Interface_Multi_RW(THSTX, 2, &temp, 0);
    
    // Read INT1 CFG Register again
    int1_ths = IMU_ReadByte(LIS3DH_INT1_THS);
    
    sprintf(bufferUART, "INT1 THS REG AFTER WRITE: 0x%02X \r\n", int1_ths);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    
    /******************************************/
    /*    Setup INT1_DURATION Register        */
    /******************************************/

    // Read actual value
    uint8_t int1_dur = IMU_ReadByte(LIS3DH_INT1_DURATION);
    
    sprintf(bufferUART, "INT1 DURATION REG: 0x%02X \r\n", int1_dur);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
    // Write 
    
    /* Prepare the TX packet */
    uint8_t DURTX[2] = {LIS3DH_INT1_DURATION, LIS3DH_INT1_DURATION_VALUE};
	/* Nothing to RX... */
	temp = 0;
	
	SPI_IMU_Interface_Multi_RW(DURTX, 2, &temp, 0);
    
    // Read INT1 CFG Register again
    int1_dur = IMU_ReadByte(LIS3DH_INT1_DURATION);
    
    sprintf(bufferUART, "INT1 DURATION REG AFTER WRITE: 0x%02X \r\n", int1_dur);
    UART_PutString(bufferUART);
    
    UART_PutString("*************************************\r\n");
    
}


/** ====== User-level Functions ====== **/

uint8_t IMU_ReadByte(uint8_t address) 
{
    
    // LIS3DH bit set to read
    address |= LIS3DH_READ_BIT;
	/* Prepare the TX data packet: instruction + address */
	uint8_t dataRX = SPI_IMU_Interface_ReadByte(address) ;
	
	return dataRX;
    
}

void IMU_WriteByte(uint8_t address, uint8_t dataByte) 
{
    
	/* Prepare the TX packet */
    uint8_t dataTX[2] = {address, dataByte};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	/* Write 1 byte to addr */
	SPI_IMU_Interface_Multi_RW(dataTX, 2, &temp, 0);
	    
}


void IMU_ReadFIFO(uint8_t *buffer)
{       
    // Address of low X register
	uint8_t dataTX = LIS3DH_READ_OUT_X_L;
  
    // Read one level of the FIFO at the time (6 bytes)
    for(int i = 0; i < 32 ; i++)
    {              
        SPI_IMU_Interface_Multi_RW(&dataTX, 1, &buffer[i*6], LIS3DH_FIFO_BYTES_IN_LEVEL);
    }  
}

void IMU_StoreFIFO(uint8_t *buffer)
{
    // Buffer storing only high registers read from the IMU (8 bit configuration, low power mode)
    uint8_t high_reg_data[LIS3DH_BYTES_IN_FIFO_HIGH_REG];
    uint8_t down_sampled_data[(LIS3DH_BYTES_IN_FIFO_HIGH_REG/LIS3DH_DOWN_SAMPLE)];
    
    // Save only the high registers 
    for(uint8_t i = 0; i < LIS3DH_BYTES_IN_FIFO_HIGH_REG; i++)
    {
        high_reg_data[i] = buffer[i*2 +1];
    }
    
    // Downsample from 96 values to 48 (from 32 levels of FIFO to 16)
    for(uint8_t i = 0; i < (LIS3DH_LEVELS_IN_FIFO/LIS3DH_DOWN_SAMPLE); i++)
    {
        down_sampled_data[i*3] = high_reg_data[(i*3)*2];
        down_sampled_data[i*3 + 1] = high_reg_data[(i*3)*2 + 1];
        down_sampled_data[i*3 + 2] = high_reg_data[(i*3)*2 + 2];
    }

    // Copy the first 5 FIFO in the next positions of the buffer, in order to free the first position to the new incoming FIFO
    memcpy(&IMU_log_queue[LIS3DH_BYTES_IN_FIFO_DOWNSAMPLED], IMU_log_queue, (LIS3DH_BYTES_IN_LOG_BUFFER - LIS3DH_BYTES_IN_FIFO_DOWNSAMPLED));
    
    
    // Copy the new FIFO in the first place of the buffer
    memcpy(&IMU_log_queue, down_sampled_data, LIS3DH_BYTES_IN_FIFO_DOWNSAMPLED);


}

/*
 * Get data payload from the IMU queue.
 */
void IMU_getPayload(uint8_t *messagge, uint8_t index)
{
    // from 0 index to 1 index base
    index = index+1;
    if(index == 5)
    {
        memset(messagge, 0, 60);
        memcpy(messagge, IMU_log_queue, 48);
    }
    else
    {
        memcpy(messagge, &IMU_log_queue[288 - index*60], 60);
    }
}

void IMU_DataSend(uint8_t *buffer)
{
    uint8_t DataSend[5];
    DataSend[0] = 0xA0;
    DataSend[4] = 0xC0;
    
    // Buffer storing only high registers read from the IMU (8 bit configuration, low power mode)
    uint8_t high_reg_data[LIS3DH_BYTES_IN_FIFO_HIGH_REG];
    
     // Save only high registers 
    for(uint8_t i = 0; i < LIS3DH_BYTES_IN_FIFO_HIGH_REG; i++)
    {
        high_reg_data[i] = buffer[i*2 +1];
    }

    // Send 3 registers at time via UART
    for(int i = 0; i < 32 ; i++)
    {   
        // First and last position of DataSend array already initialized, need to loop only from position 1 to 3
        for(int j = 1; j < 4; j++)
        {   
            DataSend[j] = high_reg_data[i*3 + j-1];
        }
        UART_PutArray(DataSend, 5);
    }
}

void IMU_ResetFIFO()
{
    
    // Set bypass mode
    uint8_t BYPASSTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_BYPASS_MODE};
	uint8_t temp = 0;
	SPI_IMU_Interface_Multi_RW(BYPASSTX, 2, &temp, 0);
    
    CyDelayUs(1);
    
    
    
    // Set FIFO mode again
    uint8_t FIFOTX[2] = {LIS3DH_FIFO_CTRL_REG, LIS3DH_FIFO_CTRL_REG_FIFO_MODE};
	temp = 0;
	SPI_IMU_Interface_Multi_RW(FIFOTX, 2, &temp, 0);
}

void IMU_StopISR(void)
{    
    /* Prepare the TX packet with reg address and NULL value to stop ISR occurrences*/
    uint8_t CTRL3TX[2] = {LIS3DH_CTRL_REG3, LIS3DH_CTRL_REG3_NULL};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	
	SPI_IMU_Interface_Multi_RW(CTRL3TX, 2, &temp, 0);
    
}

void IMU_StartISR(void)
{
    
    /* Prepare the TX packet with reg address and previous ISR settings bit */
    uint8_t CTRL3TX[2] = {LIS3DH_CTRL_REG3, LIS3DH_CTRL_REG3_I1_IA1_OVERRUN};
	/* Nothing to RX... */
	uint8_t temp = 0;
	
	SPI_IMU_Interface_Multi_RW(CTRL3TX, 2, &temp, 0);
    
}

/* [] END OF FILE */
