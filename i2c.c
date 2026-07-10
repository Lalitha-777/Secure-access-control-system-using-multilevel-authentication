#include <lpc21xx.h>        // LPC21xx register definitions
#include "types.h"          // User-defined data types (u8, u16, u32, etc.)
#include "i2c_defines.h"    // I2C pin definitions, bit positions and clock values
//*****************************************************************
// Description   : Initializes the LPC21xx I2C peripheral in Master mode.
void init_i2c(void)
{
    // Clear previous pin function settings for P0.2 (SCL) and P0.3 (SDA)
    PINSEL0 &= ~(15 << (2 * 2));
    // Configure P0.2 as SCL and P0.3 as SDA
    PINSEL0 |= SCL_PIN_FUNC | SDA_PIN_FUNC;
    // Set low period of SCL clock
    I2SCLL = LOAD_VAL;
    // Set high period of SCL clock
    I2SCLH = LOAD_VAL;
    // Enable I2C peripheral
    I2CONSET = 1 << I2EN;
}   //*****************************************************************
//Description   : Generates START condition on I2C bus.
//*****************************************************************
void i2c_start(void)
{
    // Set START bit to generate START condition
    I2CONSET = 1 << STA;
    // Wait until SI (Interrupt Flag) becomes 1,
    // indicating START condition has been transmitted.
    while(((I2CONSET >> SI) & 1) == 0);
    // Clear START flag after transmission
    I2CONCLR = 1 << STAC;
}
//*****************************************************************
// Description   : Generates STOP condition to terminate communication.
//*****************************************************************
void i2c_stop(void)
{
    // Generate STOP condition
    I2CONSET = 1 << STO;
   // Clear SI flag for next communication
    I2CONCLR = 1 << SIC;
}
//*****************************************************************
// Description   : Generates Repeated START condition.
// Used when switching from write mode to read mode without releasing the I2C bus.
//*****************************************************************
void i2c_restart(void)
{
    // Generate repeated START
    I2CONSET = 1 << STA;
    // Clear SI flag
    I2CONCLR = 1 << SIC;
    // Wait until repeated START is transmitted
    while(((I2CONSET >> SI) & 1) == 0);
    // Clear START flag
    I2CONCLR = 1 << STAC;
}
//*****************************************************************
// Description   : Transmits one byte over I2C.
// Parameter     : sdat - Data byte to be transmitted.
//*****************************************************************
void i2c_write(u8 sdat)
{
    // Load data into I2C data register
    I2DAT = sdat;
    // Clear SI flag to begin transmission
    I2CONCLR = 1 << SIC;
    // Wait until byte transmission completes
    while(((I2CONSET >> SI) & 1) == 0);
}
//*****************************************************************
// Description   : Receives one byte and sends NACK.
// Used while receiving the LAST byte from slave.
// Return        : Received byte.
//*****************************************************************
u8 i2c_nack(void)
{
    // AA bit remains cleared, therefore NACK will be sent.
    // Clear SI flag to continue communication
    I2CONCLR = 1 << SIC;
    // Wait until data byte is received
    while(((I2CONSET >> SI) & 1) == 0);
    // Return received byte
    return I2DAT;
}
//*****************************************************************
// Description   : Receives one byte and sends ACK.
// Used while receiving intermediate bytes from slave.
// Return        : Received byte.
//*****************************************************************
u8 i2c_mack(void)
{    // Set AA bit to transmit ACK after receiving data
    I2CONSET = 1 << AA;
    // Clear SI flag to continue reception
    I2CONCLR = 1 << SIC;
    // Wait until data is received
    while(((I2CONSET >> SI) & 1) == 0);
    // Clear AA bit so that future reception can generate NACK if required
    I2CONCLR = 1 << AAC;
    // Return received byte
    return I2DAT;
}
