#include <lpc21xx.h>        // LPC21xx register definitions
#include "defines.h"        // LCD pin definitions and LCD command macros
#include "types.h"          // User-defined data types (u8, u16, etc.)
#include "delay.h"          // Delay functions required for LCD timing
#include "lcd.h"            // LCD function declarations
//***************************************************************
// Function Name : write_lcd()
// Description   : Sends one byte to LCD.
//                 It can be either command or data dependingon the RS pin status.
// Parameter     : data -> Byte to be transmitted.
//***************************************************************
void write_lcd(u8 data)
{
    SCLRBIT(IOCLR0, RW);          // RW = 0 : Select Write operation
    // Place 8-bit data on LCD data pins (P0.8 to P0.15)
    WBYTE(IOPIN0, LCD_DATA, data);
    SSETBIT(IOSET0, EN);          // EN = 1 : Enable pulse starts
    delay_us(1);                  // Small pulse width as required by LCD
    SCLRBIT(IOCLR0, EN);          // EN = 0 : LCD latches the data
    delay_ms(2);                  // Wait for LCD internal execution
}
//***************************************************************
// Function Name : cmd_lcd()
// Description   : Sends a command to LCD.
// Parameter     : cmd -> LCD command byte.
//***************************************************************
void cmd_lcd(u8 cmd)
{
    SCLRBIT(IOCLR0, RS);          // RS = 0 : Select Command Register
   write_lcd(cmd);               // Send command byte to LCD
}
//***************************************************************
// Function Name : init_lcd()
// Description   : Initializes the LCD in 8-bit mode.
//***************************************************************
void init_lcd()
{
    // Configure LCD data pins (P0.8-P0.15) as outputs
    WBYTE(IODIR0, LCD_DATA, 255);
    // Configure LCD control pins as outputs
    SETBIT(IODIR0, RS);           // RS pin
    SETBIT(IODIR0, RW);           // RW pin
    SETBIT(IODIR0, EN);           // EN pin
    // LCD Power-On Initialization Sequence
    delay_ms(15);                 // Wait after power-up
    cmd_lcd(MODE_8BIT_LINE1);     // Function Set (First initialization)
    delay_ms(5);
    cmd_lcd(MODE_8BIT_LINE1);     // Function Set (Second initialization)
    delay_us(100);
    cmd_lcd(MODE_8BIT_LINE1);     // Function Set (Third initialization)
    // Configure LCD for 8-bit, 2-line display
    cmd_lcd(MODE_8BIT_LINE2);
    // Display ON, Cursor ON
    cmd_lcd(DISP_ON_CUR_ON);
    // Clear entire LCD display
    cmd_lcd(CLEAR_LCD);
    // Move cursor towards right after each character
    cmd_lcd(SHIFT_CUR_RIGHT);
}
//***************************************************************
// Function Name : char_lcd()
// Description   : Displays one character on LCD.
// Parameter     : character -> ASCII character to display.
//***************************************************************
void char_lcd(u8 character)
{
    SETBIT(IOSET0, RS);           // RS = 1 : Select Data Register
   write_lcd(character);         // Send character to LCD
}
//***************************************************************
// Function Name : str_lcd()
// Description   : Displays a NULL terminated string on LCD.
// Parameter     : p -> Pointer to string.
//***************************************************************
void str_lcd(u8 *p)
{
    // Display characters one by one until NULL character is reached
    while(*p)
        char_lcd(*p++);
}
