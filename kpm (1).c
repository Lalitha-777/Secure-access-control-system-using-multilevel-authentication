#include "kpm.h"             // Function declarations for keypad driver
#include "types.h"           // User-defined data types (u8, s8, u32, etc.)
#include "defines.h"          // GPIO manipulation macros
#include "delay.h"           // Delay functions
#include "lcd.h"             // LCD display functions
#include <lpc21xx.h>         // LPC21xx register definitions
u8 menu_flag = 0;            // Global flag set by external interrupt to enter menu mode
// Keypad Lookup Table
// Maps row number and column number to the corresponding key value.
s32 kpmlut[4][4] ={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','-'},{'*','0','=','B'}}; // '=' is used as Enter key, 'B' is used as Backspace
//************************************************************
// Purpose  : Configure keypad row pins as output pins.
//************************************************************
void init_kpm(void)
{
    // Configure row pins (P1.16-P1.19) as outputs.
    // Column pins remain as inputs.
    WNIBBLE(IODIR1, row0, 15);
}
//************************************************************
// Function : colscan()
// Purpose  : Check whether any key is pressed.
// Return   : 0 -> Key pressed           1 -> No key pressed
//************************************************************
u32 colscan(void)
{
    // Read all column pins.
    // If any column becomes LOW, a key is pressed.
    return (RNIBBLE(IOPIN1, col0) < 15) ? 0 : 1;
}
//************************************************************
// Function : rowcheck()
// Purpose  : Find which row contains the pressed key.
// Return   : Row number (0-3)
//************************************************************
u32 rowcheck(void)
{
    u32 rno;
    // Scan every row one by one.
    for(rno = 0; rno < 4; rno++)
    {
        // Drive only one row LOW at a time.
        WNIBBLE(IOPIN1, row0, ~(1 << rno));
        // If any column becomes LOW,
        // the pressed key belongs to this row.
        if(colscan() == 0)
        {
            break;
        }
    }
    // Restore all rows to inactive state.
    WNIBBLE(IOPIN1, row0, 0x0);
    return rno;
}
//************************************************************
// Function : colcheck()
// Purpose  : Find which column contains the pressed key.
// Return   : Column number (0-3)
//************************************************************
u32 colcheck(void)
{
    u32 cno;
    // Scan all four columns.
    for(cno = 0; cno < 4; cno++)
    {
        // Active LOW keypad.
        if(RBIT(IOPIN1, (col0 + cno)) == 0)
        {
            break;
        }
    }
    return cno;
}
//************************************************************
// Function : keyscan()
// Purpose  : Detect a key press and return the key value.
// Return   : ASCII value of key -1 if menu interrupt occurs.
//************************************************************
s32 keyscan(void)
{
    s32 keyv;
    s32 rno, cno;
    // Wait until any key is pressed.
    // Exit immediately if external interrupt requests menu mode.
    while(colscan() && menu_flag == 0);
    if(menu_flag == 1)
    {
        return -1;
    }
    // Find row number.
    rno = rowcheck();
    // Find column number.
    cno = colcheck();
    // Obtain actual key from lookup table.
    keyv = kpmlut[rno][cno];
    // Wait until user releases the key.
    while(!colscan());
    // Debounce delay.
    delay_ms(100);
    return keyv;
}
//************************************************************
// Function : readnum()
// Purpose  : Read a numeric value from keypad.
// Enter    : '='     Delete   : 'B'
// Return   : Integer entered by user.
//************************************************************
s32 readnum(void)
{
    s32 key,cnt = 0;
    int num = 0;
    while(1)
    {
        key = keyscan();
        // Exit if menu interrupt occurs.
        if(key == -1)
        {
            cnt = 0;
            return -1;
        }
        // Accept only numeric digits.
        if((key >= '0') && (key <= '9') && (cnt < 4))
        {
            cnt++;
            // Display entered digit.
            char_lcd(key);
            // Convert ASCII digit into integer.
            num = num * 10 + (key - 48);
        }
       // Backspace operation.
        else if((key == 'B') && (cnt != 0))
        {
            cnt--;
            cmd_lcd(0x10);      // Move cursor left.
            char_lcd(' ');      // Erase digit.
            cmd_lcd(0x10);      // Move cursor back.
            // Remove last digit from number.
            num /= 10;
        }
        // '=' acts as Enter key.
        else if((key == '=') && (cnt != 0))
        {
            cnt = 0;
            return num;
        }
    }
}
//************************************************************
// Function : password_kpm()
// Purpose  : Read a 4-digit password from keypad.
// Digits are displayed as '*'.
//************************************************************
void password_kpm(char *p)
{
    u8 a;
    u8 cnt = 0;
    while(1)
    {
        a = keyscan();
        // Accept only numeric digits.
        if((a >= '0') && (a <= '9') && (cnt != 4))
        {
            cnt++;
            delay_ms(300);
            // Hide entered digit.
            cmd_lcd(0x10);
            char_lcd('*');
            // Store actual password character.
            *p = a;
            p++;
        }
        // Backspace.
        else if((a == 'B') && (cnt != 0))
        {
            cmd_lcd(0x10);
            char_lcd(' ');
            cmd_lcd(0x10);
            cnt--;
            p--;
        }
        // Password entry complete.
        else if((a == '=') && (cnt == 4))
        {
            cnt = 0;
            // Append NULL terminator.
            *p = '\0';
            return;
        }
    }
}
//************************************************************
// Function : id_kpm()
// Purpose  : Read a 4-digit User ID from keypad.
//************************************************************
void id_kpm(s8 *p)
{
    s8 a;
    s8 cnt = 0;
    while(1)
    {
        a = keyscan();
        // Accept numeric digits only.
        if((a >= '0') && (a <= '9') && (cnt != 4))
        {
            // Display entered digit.
            char_lcd(a);
            // Store digit in ID buffer.
            p[cnt] = a;
            cnt++;
        }
        // Backspace operation.
        else if((a == 'B') && (cnt != 0))
        {
            cnt--;
            cmd_lcd(0x10);
            char_lcd(' ');
            cmd_lcd(0x10);
        }
        // Finish entering ID.
        else if((a == '=') && (cnt == 4))
        {
            // Append string terminator.
            p[cnt] = '\0';
            return;
        }
    }
}
