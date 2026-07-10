//motor.c
#include <lpc21xx.h>      // LPC21xx register definitions
#include "l293d.h"        // Motor pin definitions and function prototypes
//***************************************************************
// Function Name : init_l293d()
// Description   : Initializes the GPIO pins connected to the
//                 L293D motor driver as output pins.
//***************************************************************
void init_l293d(void)
{
    // Configure motor control pins (M1 and M2) as outputs
    IODIR0 |= ((1 << M1) | (1 << M2));
}
//***************************************************************
// Function Name : door_open()
// Description   : Rotates the motor in forward direction to
//                 open the door.
//***************************************************************
void door_open(void)
{
    // Set M1 HIGH
    IOSET0 = 1 << M1;
    // Set M2 LOW
    IOCLR0 = 1 << M2;
    // Motor rotates in forward direction
}
//***************************************************************
// Function Name : door_close()
// Description   : Rotates the motor in reverse direction to
//                 close the door.
//***************************************************************
void door_close(void)
{
    // Set M1 LOW
    IOCLR0 = 1 << M1;
    // Set M2 HIGH
    IOSET0 = 1 << M2;
    // Motor rotates in reverse direction
}
//***************************************************************
// Function Name : motor_stop()
// Description   : Stops the motor by making both control pins LOW.
//***************************************************************
void motor_stop(void)
{
    // Make both motor control pins LOW
    IOCLR0 = 1 << M1;
    IOCLR0 = 1 << M2;
   // Motor stops rotating
}
