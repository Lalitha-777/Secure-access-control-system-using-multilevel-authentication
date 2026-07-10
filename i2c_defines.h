//i2c_defines.h

// LPC2148 Pin Numbers used for I2C communication
#define SCL 2                  // P0.2 is used as Serial Clock Line (SCL)
#define SDA 3                  // P0.3 is used as Serial Data Line (SDA)


//---------------------------------------------------------------------
// PINSEL0 values to configure P0.2 and P0.3 for I2C alternate function
//---------------------------------------------------------------------
#define SCL_PIN_FUNC 0X00000010    // Select I2C function for SCL (P0.2)
#define SDA_PIN_FUNC 0X00000040    // Select I2C function for SDA (P0.3)


//---------------------------------------------------------------------
// Clock Configuration
//---------------------------------------------------------------------
#define FOSC      12000000         // External crystal oscillator frequency (12 MHz)
#define CCLK      (FOSC*5)         // CPU Clock = 60 MHz after PLL multiplication
#define PCLK      (CCLK/4)         // Peripheral Clock supplied to I2C peripheral (15 MHz)
#define I2C_SPEED 100000           // Standard I2C communication speed (100 kHz)

// Load value used to generate the required SCL clock frequency
#define LOAD_VAL  ((PCLK/I2C_SPEED)/2)


//---------------------------------------------------------------------
// I2CONSET Register Bit Positions
// These bits are used to control I2C operations.
//---------------------------------------------------------------------
#define AA    2      // Assert Acknowledge bit
#define SI    3      // Serial Interrupt Flag bit
#define STO   4      // STOP condition bit
#define STA   5      // START condition bit
#define I2EN  6      // I2C Interface Enable bit


//---------------------------------------------------------------------
// I2CONCLR Register Bit Positions
// These bits are used to clear corresponding control bits.
//---------------------------------------------------------------------
#define AAC    2     // Clear Acknowledge bit
#define SIC    3     // Clear Serial Interrupt Flag
#define STAC   5     // Clear START condition bit
#define I2ENC  6     // Disable I2C Interface
