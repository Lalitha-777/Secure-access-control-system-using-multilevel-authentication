//l293d.h
#ifndef __l293d
#define __l293d

//---------------------------------------------------------------------
// LPC2148 GPIO pins connected to the L293D motor driver inputs
//---------------------------------------------------------------------
#define M1 5          // Motor Input-1 connected to P0.5
#define M2 6          // Motor Input-2 connected to P0.6

void init_l293d(void);// Initializes the motor control pins as GPIO outputs.
void door_open(void);// Rotates the motor in the forward direction to open the door.
void door_close(void);// Rotates the motor in the reverse direction to close the door.
void motor_stop(void);   // Stops the motor by clearing both motor control pins.

#endif                                                                                                                                               
