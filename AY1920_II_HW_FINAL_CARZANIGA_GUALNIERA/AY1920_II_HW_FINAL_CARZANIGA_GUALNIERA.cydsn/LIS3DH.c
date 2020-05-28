/**
 * @file LIS3DH.c
 * @brief Functions required to interface with the SPI  LIS3DH ACCELEROMETER.
 * 
 * This c file contains the API functions to interface
 * with the SPI LIS3DH ACCELEROMETER.
 *
*/

#include "LIS3DH.h"

uint8_t IMU_ReadByte(uint8_t address) 
{
    // LIS3DH bit set to read
    address |= LIS3DH_READ_BIT;
	/* Prepare the TX data packet: instruction + address */
	uint8_t dataRX = SPI_IMU_Interface_ReadByte(address) ;
	
	return dataRX;
}

/* 
 * Setup IMU registers and enter in stop mode.
 */
void IMU_Init(void)
{
    // Reset all registers before setup
    IMU_Setup();
    
    // Disable IMU data acquisition and transmission
    IMU_Stop();
}

/*
 * Initialize all IMU control registers to ensure
 * correct fuctioning of application.
 */
void IMU_Setup(void)
{
    // Nothing to RX
	uint8_t temp = 0;
    uint8_t BUFFTX[2];
    
    // Setup control register 1
    BUFFTX[0] = LIS3DH_CTRL_REG1;
    BUFFTX[1] = LIS3DH_CTRL_REG1_STOP_XYZ;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup control register 3
    BUFFTX[0] = LIS3DH_CTRL_REG3;
    BUFFTX[1] = LIS3DH_CTRL_REG3_NULL;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup control register 4
    BUFFTX[0] = LIS3DH_CTRL_REG4;
    BUFFTX[1] = LIS3DH_CTRL_REG4_BDU_ACTIVE;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup control register 5
    BUFFTX[0] = LIS3DH_CTRL_REG5;
    BUFFTX[1] = LIS3DH_CTRL_REG5_FIFO_ENABLE;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup FIFO control register
    BUFFTX[0] = LIS3DH_FIFO_CTRL_REG;
    BUFFTX[1] = LIS3DH_FIFO_CTRL_REG_BYPASS_MODE;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup interrupt 1 configuration register
    BUFFTX[0] = LIS3DH_INT1_CFG;
    BUFFTX[1] = LIS3DH_ITN1_CFG_DISABLE_EVENTS;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
}

/*
 * Disable IMU data acquisition and related interrupts.
 */
void IMU_Stop(void)
{
    // Nothing to RX
	uint8_t temp = 0;
    uint8_t BUFFTX[2];
    
    // Setup control register 1
    BUFFTX[0] = LIS3DH_CTRL_REG1;
    BUFFTX[1] = LIS3DH_CTRL_REG1_STOP_XYZ;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup control register 3
    BUFFTX[0] = LIS3DH_CTRL_REG3;
    BUFFTX[1] = LIS3DH_CTRL_REG3_NULL;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
  
    // Setup control register 5
    BUFFTX[0] = LIS3DH_CTRL_REG5;
    BUFFTX[1] = LIS3DH_CTRL_REG5_FIFO_DISABLE;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup FIFO control register
    BUFFTX[0] = LIS3DH_FIFO_CTRL_REG;
    BUFFTX[1] = LIS3DH_FIFO_CTRL_REG_BYPASS_MODE;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup interrupt 1 configuration register
    BUFFTX[0] = LIS3DH_INT1_CFG;
    BUFFTX[1] = LIS3DH_ITN1_CFG_DISABLE_EVENTS;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
}

/*
 * Disable IMU data acquisition and related interrupts.
 */
void IMU_Start(void)
{
    // Nothing to RX
	uint8_t temp = 0;
    uint8_t BUFFTX[2];
    
    // Setup control register 1
    BUFFTX[0] = LIS3DH_CTRL_REG1;
    BUFFTX[1] = LIS3DH_CTRL_REG1_START_XYZ;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup control register 3
    BUFFTX[0] = LIS3DH_CTRL_REG3;
    BUFFTX[1] = LIS3DH_CTRL_REG3_I1_IA1_OVERRUN;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
  
    // Setup control register 5
    BUFFTX[0] = LIS3DH_CTRL_REG5;
    BUFFTX[1] = LIS3DH_CTRL_REG5_FIFO_ENABLE;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup FIFO control register
    BUFFTX[0] = LIS3DH_FIFO_CTRL_REG;
    BUFFTX[1] = LIS3DH_FIFO_CTRL_REG_FIFO_MODE;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
    
    // Setup interrupt 1 configuration register
    BUFFTX[0] = LIS3DH_INT1_CFG;
    BUFFTX[1] = LIS3DH_INT1_CFG_XYZ_HIGH_EVENTS;
	SPI_IMU_Interface_Multi_RW(BUFFTX, 2, &temp, 0);
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
