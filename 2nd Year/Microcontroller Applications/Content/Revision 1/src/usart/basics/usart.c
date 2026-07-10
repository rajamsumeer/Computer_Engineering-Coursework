/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

Date: 18/02/2025
*/
#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    // USART Control and Status Register B: Transmitter & Reciever (enabling)
    UCSR0B |=((1<<TXEN0) | (1<<RXEN0));

    // USART Control and Status Register C: (comm)
    // UMSEL Mode: 0 = Asynchronous (only two lines TX/RX) 
    UCSR0C &= ~((0<<UMSEL00) | (0<<UMSEL01) | (0<<UPM00) | (0<<UPM01) | (0<<USBS0) | (1<<UCSZ00) | (1<<UCSZ01));

    UBRR0 = 103; // Set Baud Rate 9600

    // Set Pin 5 as output on PORTB
    DDRB |= (1<<5);
    while(1) {
        // if char recieved (RXD)
        if (UCSR0A & (1<<RXC0)) {
            // write & read from buffer
            // get char out of USART buffer
            UDR0 = 'a';
            _delay_ms(1000);
        }
    }
    return 0;
}
