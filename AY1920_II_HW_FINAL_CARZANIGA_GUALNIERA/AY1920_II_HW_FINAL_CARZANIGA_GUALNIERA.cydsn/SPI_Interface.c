/**
 * @file SPI_Interface.c
 * @brief Functions required to interface with the SPI MASTER (SPIM).
 * 
 * This source code file contains macros and functions to interface
 * with the SPI Master (SPIM) of the PSoC.
 *
 * @author Mattia Pesenti
 * @date April 9, 2020
*/

#include "SPI_Interface.h"

/*
* @brief Full-Duplex, Single-Operation 1-Byte Trade
*/
uint8_t SPI_IMU_Interface_tradeByte(uint8_t byte) 
{
	/* Enable the Slave */
	CS_IMU_Write(0);
	
	/* Load the TX Buffer */
	SPIM_IMU_WriteTxData(byte);
	
	/* Wait for TX */
    while( !(SPIM_IMU_ReadTxStatus() & SPIM_IMU_STS_BYTE_COMPLETE) );

	/* Read the RX Buffer */
	uint8_t data = SPIM_IMU_ReadRxData();
	
	/* Disable the Slave */
	CS_IMU_Write(1);
	
	return data;
}


/*
* @brief RX-only, Dual-Operation 1-Byte READ
*/
uint8_t SPI_IMU_Interface_ReadByte(uint8_t byteTX) 
{
    /* Enable the Slave */
    CS_IMU_Write(0);
    	
    /* Load the TX Buffer */
    SPIM_IMU_WriteTxData(byteTX);
    	
    /* SPI Dummy Byte */
    SPIM_IMU_WriteTxData(SPI_DUMMY_BYTE);
    	
    /* Wait for TX/RX */
    while(!(SPIM_IMU_ReadTxStatus() & SPIM_IMU_STS_SPI_DONE));
    	
    /* Read the RX Buffer */
    SPIM_IMU_ReadRxData();
    uint8_t byteRX = SPIM_IMU_ReadRxData();
    	
    /* Disable the Slave */
    CS_IMU_Write(1);
    	
    return byteRX;
}

/*
* @brief RX-only, Dual-Operation Multi-Byte READ/WRITE
*/
void SPI_IMU_Interface_Multi_RW(uint8_t* dataTX, uint8_t bytesTX, uint8_t* dataRX, uint8_t bytesRX) {
    /* Enable the Slave */
    CS_IMU_Write(0);
        
    int8_t count = bytesTX, index = 0;
    	
    /* Transmit Data */
    while ( count > 0 ) 
    {
    	/* Load the TX buffer with Data*/
        SPIM_IMU_PutArray(&dataTX[index*SPI_TxBufferSize], (count > SPI_TxBufferSize ? SPI_TxBufferSize : count));
        /* Wait for TX */
        while( !(SPIM_IMU_ReadTxStatus() & SPIM_IMU_STS_SPI_DONE) );
        
        /* Update count */
        count -= SPI_TxBufferSize;
        index++;
    }
        
    /* Clear the RX Buffer */
    SPIM_IMU_ClearFIFO();
    SPIM_IMU_ClearRxBuffer();
        
    /* Init the Dummy TX Buffer */
    uint8_t dummyTX[SPI_RxBufferSize];
    memset(dummyTX, SPI_DUMMY_BYTE, SPI_RxBufferSize);
        
    /* Update count for RX */
    count = bytesRX;
    index = 0;
        
    /* Get the RX Data */
    while ( count > 0 ) 
    {
        /* Load the TX buffer with Dummy Bytes*/
        SPIM_IMU_PutArray(dummyTX, (count > SPI_TxBufferSize ? SPI_TxBufferSize : count));
        /* Wait for TX */
        while( !(SPIM_IMU_ReadTxStatus() & SPIM_IMU_STS_SPI_DONE) );
        /* Read the RX Buffer */
        for( uint8_t j = 0; j < (count > SPI_TxBufferSize ? SPI_TxBufferSize : count); j++ ) 
        {
            dataRX[j + index*SPI_RxBufferSize] = SPIM_IMU_ReadRxData();   
        }
        count -= SPI_RxBufferSize;
        index++;  
    }
        
    /* Disable the Slave */
    CS_IMU_Write(1);
    	
    /* Clear */
    SPIM_IMU_ClearFIFO();
    SPIM_IMU_ClearRxBuffer();
    SPIM_IMU_ClearTxBuffer();
}

/*
* @brief Full-Duplex, Single-Operation 1-Byte Trade
*/
uint8_t SPI_EEPROM_Interface_tradeByte(uint8_t byte) 
{
	/* Enable the Slave */
	CS_EEPROM_Write(0);
	
	/* Load the TX Buffer */
	SPIM_EEPROM_WriteTxData(byte);
	
	/* Wait for TX */
    while( !(SPIM_EEPROM_ReadTxStatus() & SPIM_EEPROM_STS_BYTE_COMPLETE) );
    
	/* Read the RX Buffer */
	uint8_t data = SPIM_EEPROM_ReadRxData();
	
	/* Disable the Slave */
	CS_EEPROM_Write(1);
	
	return data;
}

/*
* @brief RX-only, Dual-Operation 1-Byte READ
*/
uint8_t SPI_EEPROM_Interface_ReadByte(uint8_t byteTX) 
{
    /* Enable the Slave */
    CS_EEPROM_Write(0);
    	
    /* Load the TX Buffer */
    SPIM_EEPROM_WriteTxData(byteTX);
    	
    /* SPI Dummy Byte */
    SPIM_EEPROM_WriteTxData(SPI_DUMMY_BYTE);
    	
    /* Wait for TX/RX */
    while(!(SPIM_EEPROM_ReadTxStatus() & SPIM_EEPROM_STS_SPI_DONE));
    	
    /* Read the RX Buffer */
    SPIM_EEPROM_ReadRxData();
    uint8_t byteRX = SPIM_EEPROM_ReadRxData();
    	
    /* Disable the Slave */
    CS_EEPROM_Write(1);
    	
    return byteRX;
}

/*
* @brief RX-only, Dual-Operation Multi-Byte READ/WRITE
*/
void SPI_EEPROM_Interface_Multi_RW(uint8_t* dataTX, uint8_t bytesTX, uint8_t* dataRX, uint8_t bytesRX) 
{
    /* Enable the Slave */
    CS_EEPROM_Write(0);
        
    int8_t count = bytesTX, index = 0;
    	
    /* Transmit Data */
    while ( count > 0 ) 
    {
    	/* Load the TX buffer with Data*/
        SPIM_EEPROM_PutArray(&dataTX[index*SPI_TxBufferSize], (count > SPI_TxBufferSize ? SPI_TxBufferSize : count));
        /* Wait for TX */
        while( !(SPIM_EEPROM_ReadTxStatus() & SPIM_EEPROM_STS_SPI_DONE) );
        
        /* Update count */
        count -= SPI_TxBufferSize;
        index++;
    }
        
    /* Clear the RX Buffer */
    SPIM_EEPROM_ClearFIFO();
    SPIM_EEPROM_ClearRxBuffer();
        
    /* Init the Dummy TX Buffer */
    uint8_t dummyTX[SPI_RxBufferSize];
    memset(dummyTX, SPI_DUMMY_BYTE, SPI_RxBufferSize);
        
    /* Update count for RX */
    count = bytesRX;
    index = 0;
        
    /* Get the RX Data */
    while ( count > 0 ) 
    {
        /* Load the TX buffer with Dummy Bytes*/
        SPIM_EEPROM_PutArray(dummyTX, (count > SPI_TxBufferSize ? SPI_TxBufferSize : count));
        /* Wait for TX */
        while( !(SPIM_EEPROM_ReadTxStatus() & SPIM_EEPROM_STS_SPI_DONE) );
        /* Read the RX Buffer */
        for( uint8_t j = 0; j < (count > SPI_TxBufferSize ? SPI_TxBufferSize : count); j++ ) 
        {
            dataRX[j + index*SPI_RxBufferSize] = SPIM_EEPROM_ReadRxData();   
        }
        
        count -= SPI_RxBufferSize;
        index++;   
    }
        
    /* Disable the Slave */
    CS_EEPROM_Write(1);
    	
    /* Clear */
    SPIM_EEPROM_ClearFIFO();
    SPIM_EEPROM_ClearRxBuffer();
    SPIM_EEPROM_ClearTxBuffer();
}

/* [] END OF FILE */
