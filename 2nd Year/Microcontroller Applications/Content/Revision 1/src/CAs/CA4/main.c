/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

Date: 04/03/2025

Code Purpose:
- USART Serial & Bluetooth robot communication that allows to control it's motors in directions.
*/
#include <avr/io.h>
#include "motors.h" // include header file for motor functions
#include "usart.h" // include header file for usart functions

int main(void) {
    /* (Arduino A0-A3) as outputs */
    DDRC = 0x0F; // 0b 0000 1111

    /* Initialize the USART */
    usartInit();

    /* Infinite loop */
    while (1) {
        /* Check if character received */
        if (usartCharReceived()) {

        /* Read character from buffer */
        char character = usartReadChar();

        /* Echo back character received by buffer */
        usartSendChar(character);

        /* Robot directions based on recieved character */
        if (character == 'F') {
            straight();
            usartSendString("\nStraight\n");
        } else if (character == 'B') {
            reverse();
            usartSendString("\nReverse\n");
        } else if (character == 'R') {
            right();
            usartSendString("\nRight\n");
        } else if (character == 'L') {
            left();
            usartSendString("\nLeft\n");
        } else if (character == 'S') {
            stop();
            usartSendString("\nStopping\n");
        }
    }
}
    return 0;
}
