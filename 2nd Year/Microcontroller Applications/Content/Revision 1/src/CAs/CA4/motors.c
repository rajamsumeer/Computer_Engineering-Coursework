/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

Motors Functions Implementation File

PORTC = PC0-PC3
PC0-1: MOTOR1
PC2-3: MOTOR2
*/
#include <avr/io.h>
#include "motors.h"

/* Make motors turn forward */
void straight(void) {
    PORTC &= ~0x0F;
    PORTC |= (1 << 1) | (1 << 3); // 0b 0000 1010
}

/* Make motors reverse */
void reverse(void) {
    PORTC &= ~0x0F;
    PORTC |= (1 << 0) | (1 << 2); // 0b 0000 0101
}

/* Make motors turn right */
void right(void) {
    PORTC &= ~0x0F;
    PORTC |= (1 << 0) | (1 << 3);  // 0b 0000 1001
}

/* Make motors turn left */
void left(void) {
    PORTC &= ~0x0F;
    PORTC |= (1 << 1) | (1 << 2); // 0b 0000 0110
}

/* Stop both motors by clearing all bits in PORTC */
void stop(void) {
    PORTC &= ~0x0F; // 0b 0000 0000
}
