#include <stdint.h>

#define PERIPHERAL_BASE (0x40000000U)

#define AHB2_BASE (PERIPHERAL_BASE + 0x8000000U)
#define AHB1_BASE (PERIPHERAL_BASE + 0x20000U)

#define GPIOB_BASE (AHB2_BASE + 0x400U)

#define RCC_BASE (AHB1_BASE + 0x1000U)


#define RCC_AHBENR_OFFSET (0x14U)
#define RCC_AHBENR ((volatile uint32_t*) (RCC_BASE + RCC_AHBENR_OFFSET))

#define RCC_AHBENR_GPIOBEN (18U)

#define GPIOB_MODER_OFFSET (0x00U)
#define GPIOB_MODER ((volatile uint32_t*) (GPIOB_BASE + GPIOB_MODER_OFFSET))
#define GPIO_MODER_MODER3_0 (6U)
#define GPIO_MODER_MODER3_1 (7U)

#define GPIOB_ODR_OFFSET (0x14U)
#define GPIOB_ODR ((volatile uint32_t*) (GPIOB_BASE + GPIOB_ODR_OFFSET))

#define LED_PIN 3


#define GPIOB_BSRR_OFFSET (0x18)
#define GPIOB_BSRR ((volatile uint32_t*) (GPIOB_BASE + GPIOB_BSRR_OFFSET))
#define GPIOB_BSRR_BS_3 3
#define GPIOB_BSRR_BR_3 19


int main(void)
{

  *RCC_AHBENR |= (1 << RCC_AHBENR_GPIOBEN);

  *GPIOB_MODER |= (1 << GPIO_MODER_MODER3_0);
  *GPIOB_MODER &= ~(1 << GPIO_MODER_MODER3_1);

  
  while(1)
  {
    *GPIOB_ODR ^= (1 << LED_PIN);
    
    for (uint32_t i = 0; i < 1000000U; i++);

  }

}
