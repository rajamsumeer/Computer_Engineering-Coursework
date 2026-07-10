/*
Program:
Module: Programming 2

Student Name: Sumeer
Student ID:

Date of Creation: 15/01/2025 @ approx 22:00

Program Purpose:
- C program.
- Generates a random number between 1 and 50.
*/

#include <stdio.h> // preprocessor directive to include definitions for I/O
#include <stdlib.h> // preprocessor directive to include definitions for srand()
#include <time.h>  // preprocessor directive to include definitions time generator
int main() {

srand(time(NULL)); // initialize once for number generator / second

int randomNum;
randomNum = rand() % 50 + 1; // number generator between 1 to 50 and generate random number
fprintf(stdout, "Your random number is:\n[%d]", randomNum);

return 0;

} // end of main loop
