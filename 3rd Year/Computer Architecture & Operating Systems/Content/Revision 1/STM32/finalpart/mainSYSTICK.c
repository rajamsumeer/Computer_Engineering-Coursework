#include <stdint.h>

#include "stm32f3xx.h"

#define LED_PIN 3


void delay_ms(uint32_t milliseconds);

uint32_t ticks;

void systick_handler(void)
{
    ticks++;
}

int main(void)
{
  // 1. Enable Clock for GPIOB (Peripheral Clock Enable Register)
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // 2. Configure PB3 as Output
    // Clear mode bits for PB3 (00 at bits 7:6)
    GPIOB->MODER &= ~GPIO_MODER_MODER3_Msk; 
    // Set mode bits to 01 (General purpose output mode) for PB3
    GPIOB->MODER |= (1 << GPIO_MODER_MODER3_Pos);;

  SysTick_Config(8000);
  __enable_irq();
  
  while(1)
  {
    GPIOB->ODR ^= (1 << LED_PIN);
    
    delay_ms(500);

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
