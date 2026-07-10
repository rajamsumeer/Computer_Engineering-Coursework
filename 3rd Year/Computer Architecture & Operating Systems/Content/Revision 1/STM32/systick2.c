/*
Student ID: , Student Name: R Sumeer
Technological University Dublin @Third Year - Computer Arch & Operating Systems (Semester 2)
File: Main blink program w/USART & button on ST Nucleo Board
Last Modified: 08/04/2026 @21:44
*/
#include <stdint.h>
#include "stm32f3xx.h"
#include "usart.h"

#define LED_PIN        3
#define BUTTON_PIN     12

void delay_ms(uint32_t milliseconds);

uint32_t ticks;

void systick_handler(void)
{
    ticks++;
}

uint32_t millis(void)
{
    uint32_t ms;
    __disable_irq();
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

    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR12);//(0x3 << (BUTTON_PIN * 2)); // Clear bits at 25:24
    GPIOA->PUPDR |=  (GPIO_PUPDR_PUPDR12_0);//(0x1 << (BUTTON_PIN * 2)); // Set mode bits to 01 (pull-up)

    usartInit();

    SysTick_Config(8000); //8Mhz
    __enable_irq();

    uint32_t pressed = 0;
    uint8_t lastPinState = 0;

    while (1)
    {
        uint8_t readPinState = !(GPIOA->IDR & GPIO_IDR_12);//!(GPIOA->IDR & (1 << BUTTON_PIN)); //(on Press)

        if (readPinState && !lastPinState) {
            uint32_t now = millis();
            if ((now - pressed > 20)) { // check after 20ms
                pressed = now;
                GPIOB->ODR ^= (GPIO_ODR_3);//(1 << LED_PIN);
                usartSendString("Button pressed\n");  
            }
        }
        lastPinState = readPinState;
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