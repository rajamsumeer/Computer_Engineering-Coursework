#include <stdint.h>

#include "stm32f3xx.h"

#define LED_PIN 3

int main(void)
{
  

// 1. Enable Clock for GPIOB (Peripheral Clock Enable Register)
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // 2. Configure PB3 as Output
    // Clear mode bits for PB3 (00 at bits 7:6)
    GPIOB->MODER &= ~GPIO_MODER_MODER3_Msk; 
    // Set mode bits to 01 (General purpose output mode) for PB3
    GPIOB->MODER |= (1 << GPIO_MODER_MODER3_Pos);


  
  while(1)
  {
    GPIOB->ODR ^= (1 << LED_PIN);
    
    for (uint32_t i = 0; i < 1000000U; i++);

  }

}
