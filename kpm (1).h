#ifndef __KPM_H__
#define __KPM_H__

#include "types.h"

//**************************************************************
// 4x4 Matrix Keypad Row Connections
//**************************************************************

#define row0 16      // P0.16
#define row1 17      // P0.17
#define row2 18      // P0.18
#define row3 19      // P0.19

//**************************************************************
// 4x4 Matrix Keypad Column Connections
//**************************************************************

#define col0 20      // P0.20
#define col1 21      // P0.21
#define col2 22      // P0.22
#define col3 23      // P0.23

//**************************************************************
// Function Prototypes
//**************************************************************

// Initialize keypad GPIO pins
void init_kpm(void);

// Scan keypad columns
u32 colscan(void);

// Scan keypad and return pressed key
s32 keyscan(void);

// Check active row
u32 rowcheck(void);

// Check active column
u32 colcheck(void);

// Read multi-digit numeric value
s32 readnum(void);

// Read ID from keypad
void id_kpm(s8 *ptr);

// Read password from keypad
// Password characters are usually masked on LCD
void password_kpm(s8 *ptr);
#endif
