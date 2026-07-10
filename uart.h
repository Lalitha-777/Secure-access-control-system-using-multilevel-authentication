//uart.h
//============================================================
// UART Clock Configuration

#define FOSC 12000000       // External Crystal Frequency
#define PLL 5              // PLL Multiplier
#define CCLK (FOSC*PLL)   // CPU Clock
#define PCLK (CCLK/4)     // Peripheral Clock
#define BAUD 9600  // UART Baud Rate

// UART Baud Rate Divisor
#define DIVISOR (PCLK/(16*BAUD))
//============================================================
// UART Pin Configuration
#define TXD0_PIN 0x00000001   // TXD0 Function Select
#define RXD0_PIN 0x00000004   // RXD0 Function Select
//============================================================
// UART Line Control Register
#define DLAB 7    // Divisor Latch Access Bit
#define _8BIT 3    // 8-bit Data Length
#define WORD_LENGTH_SELECT _8BIT
//============================================================
// UART Line Status Register Bits
#define TEMT_BIT 6    // Transmission Complete Bit
#define DR_BIT   0    // Data Ready Bit
//============================================================
// UART Function Prototypes
void init_uart0(void);   // Initialize UART0
void u0_Tx_byte(unsigned char byte);     // Transmit one byte
unsigned char u0_Rx_byte(void);       // Receive one byte
void u0_Tx_str(char *str);            // Transmit string
char *u0_Rx_str(void);                // Receive string+
void UART0_isr(void) __irq;            // UART0 Interrupt Service Routine
