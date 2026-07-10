/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

Date: 18/02/2025
*/
#include <avr/io.h>
int main(void)
{
    // Transmitter & Reciever
    for (int i = 3; i < 5; i++) {
        UCSR0B |= (1<<i);
    }
    // UCSR0B |=((1<<3) | (1<<4));

    UCSR0C &= ~((0<<6) | (0<<7) | (0<<4) | (0<<5) | (0<<3) | (1<<1) | (1<<2) | (0<<0));

    UBRR0 = 103;

    char character;

    DDRB |= (1<<5);
    while(1) {
        // if char rx'd
        if (UCSR0A & (1<<RXC0)) {
            // get char out of USART buffer
            character = UDR0;

            if (character == 'a') {
                PORTB |= (1<<5);
            } else if (character == 'b') {
                PORTB &= ~(1<<5);
            }
        }
    }
    return 0;
}
