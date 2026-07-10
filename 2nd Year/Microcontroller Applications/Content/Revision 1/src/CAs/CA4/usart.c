/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

USART Functions Implementation File
*/
#include <avr/io.h>
#include "usart.h"
#include <stdint.h>  // for uint_8

void usartInit(void) {

    /* Transmitter and Reciever */
    UCSR0B |= ((1<<TXEN0) | (1<<RXEN0));

    /* Asynchronous Mode (two lines) */
    UCSR0C &= ~((1<<UMSEL00) | (1<<UMSEL01));
    
    /* Control & Status Register A is cleared */
    UCSR0A |= (1 << UDRE0);

    /* Set Baud Rate (bps) 9600 */
    UBRR0 = 103;
    
    /* 8-Bit Data */
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
    UCSR0B &= ~(1 << UCSZ02);
    
    /* Parity Bits */
    UCSR0C &= ~((1<<UPM00) | (1<<UPM01));
    
    /* 1 Stop Bit */
    UCSR0C &= ~(1<<USBS0);
}

/* Read & send character from buffer */
char usartReadChar(void) {
    return UDR0;
}

/* Wait for buffer to be cleared and send character */
void usartSendChar(char c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

/* Check if character recieved */
uint8_t usartCharReceived(void) {
    if (UCSR0A & (1<<RXC0)) {
     return 1;
    } else {
    return 0;
    }
}

/* Send a string of characters */
void usartSendString(char character[]) {
    // first character
    int i = 0;
    while (character[i]) {
        // Send each recieved character (individual char in a string of chars)
        usartSendChar(character[i]);
        i++;
    }
}
