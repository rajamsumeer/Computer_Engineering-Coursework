/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

Date: 04/03/2025
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdio.h>
#include "ultra.h"
#include "usart.h"

// global variables
uint8_t distanceMeasured = 0;
uint16_t startTime, stopTime;

// Timer1 Input Capture ISR
ISR(TIMER1_CAPT_vect) {
    if (TCCR1B & (1<<ICES1)) { // rising edge
        startTime = ICR1;
        TCCR1B &= ~(1<<ICES1); // falling edge
    } else {
        stopTime = ICR1;
        TCCR1B |= (1<<ICES1); // switch back to rising edge
        distanceMeasured = 1;
    }
}

// buffer variable
char str[10];

void ultraInit(void) {
    DDRB &= ~(1<<0);
    DDRD |= (1<<7);
    TCCR1B |= (1<<CS11);
    TCCR1B |= (1<<ICES1);
    TIMSK1 |= (1<<ICIE1);
    sei();
}

// distance calculations
uint16_t pulseTime, distance;

// distance measurement with ultrasonic sensor
uint16_t ultraDistance(void) {
    PORTD |= (1<<7); // trig pin high
    _delay_ms(10); // keep high
    PORTD &= ~(1<<7); // trig pin low
    _delay_ms(1000);
    if (distanceMeasured == 1) {
        distanceMeasured = 0;
    pulseTime = (stopTime - startTime) / 2; // pulse width
    distance = pulseTime / 58; // pulse time in cm
    sprintf(str, "%u\n", distance);
    usartSendString(str);
    _delay_ms(1000);
    return distance;
    }
}
