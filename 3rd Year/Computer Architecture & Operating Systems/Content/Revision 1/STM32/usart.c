/*
Student ID: , Student Name: R Sumeer
Technological University Dublin @Third Year - Computer Arch & Operating Systems (Semester 2)
File: USART Implementation for STM Nucleo Board
Last Modified: 08/04/2026 @21:44
*/
#include "usart.h"
#include "stm32f3xx.h"

void usartInit(void) {
// Enable USART2 Clocks
RCC->AHBENR |= (RCC_AHBENR_GPIOAEN);//(1<<17);
RCC->APB1ENR |= (RCC_APB1ENR_USART2EN);//(1<<17);

//PA2 & PA15 to Alternate Function
//PA2
GPIOA->MODER &= ~(GPIO_MODER_MODER2);//(0x3 << 4);
GPIOA->MODER |= (GPIO_MODER_MODER2_1);//(0x2 << 4);
//PA15
GPIOA->MODER &= ~(GPIO_MODER_MODER12);//(0x3 << 30);
GPIOA->MODER |= (GPIO_MODER_MODER12_1);//(0x2 << 30);

//AF7
//PA2
GPIOA->AFR[0] &= ~(GPIO_AFRL_AFRL2);//(0xF << 8);
GPIOA->AFR[0] |= (0x7 << GPIO_AFRL_AFRL2_Pos);//(0x7 << 8);
//PA15
GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH7);//(0xF << 28);
GPIOA->AFR[1] |= (0x7 << GPIO_AFRH_AFRH7_Pos);//(0x7 << 8);

//Configure USART2: (8Mhz/9600)
USART2->BRR = 833;
USART2->CR1 |= USART_CR1_UE | USART_CR1_TE;
}
void usartSendChar(char c) {
    while (!(USART2->ISR & USART_ISR_TXE)); //(!(USART2->ISR & 1 << 7));
    USART2->TDR = c;
}
void usartSendString(char string[]) {
	int i = 0;
	while(string[i] != '\0') {
		usartSendChar(string[i++]);
	}
}
