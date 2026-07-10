/*
Student ID:
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin)

Motors Functions Header File
*/
#ifndef MOTORS_H_
#define MOTORS_H_

void straight(void);
void reverse(void);
void right(void);
void left(void);
void stop(void);
void motorsInit(void);
void speed(uint8_t dutycycle);

#endif
