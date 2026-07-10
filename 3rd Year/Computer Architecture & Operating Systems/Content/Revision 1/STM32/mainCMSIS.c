#include <stdint.h>

#include "./vendor/CMSIS/Device/ST/STM32F3/Include/stm32f3xx.h"

#define LED_PIN 3

int main(void)
{
  RCC->AHBENR |= (1 << RCC_AHBENR_GPIOBEN_Pos);

  GPIOB->MODER |= (1 << GPIO_MODER_MODER3_Pos);
  
  while(1)
  {
    GPIOB->ODR ^= (1 << LED_PIN);
    
    for (uint32_t i = 0; i < 1000000U; i++);

  }

}
