/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

Date: 04/03/2025

Code Purpose:
- USART Serial & Bluetooth robot communication that allows to control it's motors in directions.
*/
#include <avr/io.h>
#include "usart.h" // include header file for usart functions
#include "motors.h" // include header file for motor functions
#include "ultra.h"
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

int main(void) {
    /* (Arduino A0-A3) as outputs */
    DDRC = 0x0F; // 0b 0000 1111

    /* Initialize the USART and Motors for PWM*/
    usartInit();
    motorsInit();
    ultraInit();

    /* -- Robot motor speed initial --*/
    int setSpeed = 128;

    /* Infinite loop */
    while (1) {

    if (ultraDistance() > 50) {
        speed(setSpeed);
        straight();
    } else {
        stop();
        _delay_ms(500);
        speed(setSpeed);
        left();
    }
}
    return 0;
}
