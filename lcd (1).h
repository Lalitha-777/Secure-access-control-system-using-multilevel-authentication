//lcd.h
#include <string.h>     // Provides standard string handling functions
#include "types.h"      // Contains user-defined data types (u8, u16, u32, etc.)

//---------------------------------------------------------------------
// LCD Data and Control Pin Definitions
//---------------------------------------------------------------------
#define LCD_DATA 8       // LCD data bus connected to P0.8 - P0.15
#define RS       16      // Register Select pin connected to P0.16
#define EN       17      // Enable pin connected to P0.17
#define RW       18      // Read/Write pin connected to P0.18

//---------------------------------------------------------------------
// LCD Command Definitions
//---------------------------------------------------------------------
#define CLEAR_LCD             0x01    // Clear entire LCD display
#define RET_CUR_HOME          0x02    // Return cursor to home position

//---------------------------------------------------------------------
// Display ON/OFF Control Commands
//---------------------------------------------------------------------
#define DISP_OFF              0x08    // Turn display OFF
#define DISP_ON               0x0C    // Turn display ON with cursor OFF
#define DISP_ON_CUR_ON        0x0E    // Display ON with cursor ON
#define DISP_ON_CUR_ON_BLK_ON 0x0F    // Display ON with blinking cursor

//---------------------------------------------------------------------
// Entry Mode Commands
//---------------------------------------------------------------------
#define DISP_SHIFT_OFF_INC    0x06    // Increment cursor without shifting display
#define DISP_SHIFT_INC        0x07    // Increment cursor and shift display

//---------------------------------------------------------------------
// LCD Function Set Commands
//---------------------------------------------------------------------
#define MODE_8BIT_LINE1       0x30    // 8-bit interface, single-line display
#define MODE_8BIT_LINE2       0x38    // 8-bit interface, dual-line display
#define MODE_4BIT_LINE1       0x20    // 4-bit interface, single-line display
#define MODE_4BIT_LINE2       0x28    // 4-bit interface, dual-line display

//---------------------------------------------------------------------
// DDRAM Address Commands (Cursor Position)
//---------------------------------------------------------------------
#define GOTO_LINE1_POS_0      0x80    // Move cursor to Line 1, Position 0
#define GOTO_LINE2_POS_0      0xC0    // Move cursor to Line 2, Position 0
#define GOTO_LINE3_POS_0      0x94    // Move cursor to Line 3, Position 0 (20x4 LCD)
#define GOTO_LINE4_POS_0      0xD4    // Move cursor to Line 4, Position 0 (20x4 LCD)


//---------------------------------------------------------------------
// Cursor Shift Commands
//---------------------------------------------------------------------
#define SHIFT_CUR_LEFT        0x10    // Move cursor one position to the left
#define SHIFT_CUR_RIGHT       0x14    // Move cursor one position to the right

//---------------------------------------------------------------------
// LCD Function Prototypes
//---------------------------------------------------------------------

// Sends one byte (command/data) to the LCD.
void write_lcd(u8);

// Sends a command instruction to the LCD.
void cmd_lcd(u8);

// Initializes the LCD in 8-bit, dual-line mode.
void init_lcd(void);

// Displays a single character on the LCD.
void char_lcd(u8);

// Displays a null-terminated string on the LCD.
void str_lcd(u8 *);
