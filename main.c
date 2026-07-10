#include "lcd.h"            // LCD driver function declarations
#include "kpm.h"            // Keypad driver function declarations
#include "i2c.h"            // I2C communication driver
#include "i2c_eeprom.h"     // EEPROM read/write functions using I2C
#include "uart.h"           // UART communication functions
#include "r305.h"           // R305 fingerprint sensor functions
#include "delay.h"          // Software delay functions
#include "menu.h"     // External interrupt and menu function declarations
#include "types.h"          // User-defined data types like u8, s8, u16
#include "l293d.h"          // L293D motor driver control functions
extern u8 menu_flag;        // Global flag updated by external interrupt to enter menu mode
int main()
{
    init_lcd();             // Initialize 16x2 LCD display
    init_kpm();             // Initialize keypad GPIO pins
    init_uart0();           // Initialize UART0 for communication with fingerprint module
    init_i2c();             // Initialize I2C peripheral for EEPROM communication
    init_eint2();           // Configure External Interrupt 2 for menu button
    init_ids();             // Read or initialize stored fingerprint IDs from EEPROM
    init_l293d();           // Initialize L293D motor driver pins (door lock control)
    cmd_lcd(0x01);          // Clear LCD display
    str_lcd("SECURE ACCESS");   // Display project title on first row
    cmd_lcd(0xC0);          // Move LCD cursor to second row
    str_lcd("CONTROL SYSTEM");  // Display project subtitle
    delay_ms(1000);         // Keep welcome message visible for 1 second
    while(1)                // Infinite loop - embedded applications never terminate
    {        // Check whether the administrator pressed the external interrupt button
        if(menu_flag == 1)
        {
            menu();         // Enter administrator menu (Enroll/Delete/Password operations)
        }         // Continuously allow users to authenticate
        login();            // Login using fingerprint or password
    }
}
