/*
Student ID: , Student Name: R Sumeer
Technological University Dublin @Third Year - Computer Arch & Operating Systems (Semester 2)
File: Main blink program w/USART & button on ST Nucleo Board
Program purpose: Toggles onboard LED using a button with debounce logic, millis() Systick interrupt and sends msg to USART
Last Modified: 09/04/2026 @15:38
*/
#include <stdint.h>
#include "stm32f3xx.h"
#include "usart.h"

#define LED_PIN 3 // PB3 (User LED)
#define BUTTON_PIN 12 // D2 (26/PA12)

/*
* Systick2.c
@functions
* void delay_ms(uint32_t milliseconds)
* void systick_handler(void) - Systick interrupt handler called every 1ms
* millis(void) - Returns time in ms, atomic protected
* usartInit() - Initializes USART2
* usartSendString() - Sends an array of chars over Serial

@global variables
* uint32_t ticks
*/

void delay_ms(uint32_t milliseconds);

uint32_t ticks;

void systick_handler(void)
{
    ticks++;
}

uint32_t millis(void)
{
    uint32_t ms;
    __disable_irq(); // Systick cannot modify during read 
    ms = ticks;
    __enable_irq();
    return ms;
}

int main(void)
{
    // LED (PB3)
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // Enable clock for GPIOB
    GPIOB->MODER &= ~GPIO_MODER_MODER3_Msk; // Clear mode bits for PB3 (00 at bits 7:6)
    GPIOB->MODER |=  (0x1 << GPIO_MODER_MODER3_Pos); // Set mode bits to 01 (General purpose) for PB3

    // BUTTON (PA12)
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // Enable clock for GPIOA
    GPIOA->MODER &= ~(GPIO_MODER_MODER12);//(0x3 << (BUTTON_PIN * 2)); // Clear mode bits (00) for input mode
    // BUTTON PULLUP
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR12);//(0x3 << (BUTTON_PIN * 2)); // Clear bits at 25:24
    GPIOA->PUPDR |=  (GPIO_PUPDR_PUPDR12_0);//(0x1 << (BUTTON_PIN * 2)); // Set mode bits to 01 (pull-up)

    usartInit();

    SysTick_Config(8000);
    __enable_irq();

    uint32_t pressed = 0;
    uint8_t lastPinState = 0;

    while (1)
    {
        // Read button state & invert logic (1 = pressed, 0 = not pressed)
        uint8_t readPinState = !(GPIOA->IDR & GPIO_IDR_12);//!(GPIOA->IDR & (1 << BUTTON_PIN));

        // Rising edge detection
        if (readPinState && !lastPinState) {
            uint32_t now = millis();
            if ((now - pressed > 20)) { // debounce check after 20ms
                pressed = now;
                GPIOB->ODR ^= (GPIO_ODR_3);//(1 << LED_PIN);
                usartSendString("Button pressed\n");  
            }
        }
        lastPinState = readPinState; // update state for next edge detection
    }
}

void delay_ms(uint32_t milliseconds)
{
  uint32_t start = ticks;
  uint32_t end = start + milliseconds;

  if (end < start) // handle overflow
  {
    while (ticks > start); // wait for ticks to wrap around to zero
  }

  while (ticks < end);
}