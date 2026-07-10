//i2c.h
#include "types.h"
//**************************************************************
// Function Prototypes
//**************************************************************
// Initialize I2C peripheral
void init_i2c(void);

// Generate START condition
void i2c_start(void);

// Generate STOP condition
void i2c_stop(void);

// Generate Repeated START condition
void i2c_restart(void);

// Transmit one byte over I2C
void i2c_write(u8 sdat);

// Read one byte and send ACK
u8 i2c_mack(void);

// Read one byte and send NACK
u8 i2c_nack(void);
