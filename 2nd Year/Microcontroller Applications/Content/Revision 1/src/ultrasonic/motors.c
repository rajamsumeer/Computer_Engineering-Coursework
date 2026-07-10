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

/* Initialize PWM control for Motors*/
void motorsInit(void) {
    // PORTD pins as output
    DDRD |= (1 << 6);
    DDRD |= (1 << 5);

    // Fast PWM mode
    TCCR0A |= (1 << WGM00) | (1 << WGM01);
    TCCR0B &= ~(1 << WGM02);

    TCCR0A |= (1 << COM0A1) | (1 << COM0B1); // Non-inverting mode
    TCCR0B |= (1 << CS01); // Prescaler of 8
}

/* Set Duty Cycle of PWM signal for OC registers */
void speed(uint8_t dutycycle) {
    OCR0A = dutycycle;
    OCR0B = dutycycle * 0.95; // 5% offset at all times on motor
}
