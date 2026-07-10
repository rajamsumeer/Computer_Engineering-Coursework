/*
Student ID: , Student Name: R Sumeer
Technological University Dublin @Third Year - Computer Arch & Operating Systems (Semester 2)
File: USART Header file for STM Nucleo Board
Last Modified: 08/04/2026 @21:44
*/
#ifndef USART_H
#define USART_H

void usartInit(void);
void usartSendChar(char c);
void usartSendString(char *str);

#endif
