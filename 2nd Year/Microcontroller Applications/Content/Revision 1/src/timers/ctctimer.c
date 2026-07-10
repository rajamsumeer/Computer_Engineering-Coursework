#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRB |= (1 << 5); // Set LED as output

    TCCR1B |= (1 << WGM12); // Configure timer 1 for CTC mode
    TIMSK1 |= (1 << OCIE1A); // Enable CTC interrupt
    sei(); // Enable global interrupts

    OCR1A = 7812; // Set CTC compare value to 2 Hz at 1 MHz AVR clock, with a prescaler of 64
    TCCR1B |= ((1 << CS10) | (1 << CS12)); // Start timer at Fcpu /64

    for (;;)
    {
        // Main loop does nothing, ISR handles the LED toggling
    }
}

ISR(TIMER1_COMPA_vect)
{
    PORTB ^= (1 << 5); // Toggle the LED
}
