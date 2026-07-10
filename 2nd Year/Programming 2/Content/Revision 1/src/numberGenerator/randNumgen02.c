/*
Program:
Module: Programming 2

Student Name: Sumeer
Student ID:

Date of Creation: 15/01/2025 @ approx 22:00

Program Purpose:
- C program.
- Generates a random number between a prompted min and max number range from user.
*/

#include <stdio.h> // preprocessor directive to include definitions for I/O
#include <stdlib.h> // preprocessor directive to include definitions for srand()
#include <time.h>  // preprocessor directive to include definitions time generator
int main() {

srand(time(NULL)); // initialize once for number generator / second

int minNum = 0;
int maxNum = 0;

int howFarOffNum; // variable for how far their exceeded input was from max range

fprintf(stdout, "=> Please input a minimum number range to generate from.\nIt may not go below 0\n");
fscanf(stdin, "%d", &minNum);

// if (minNum < -1000) {
//     howFarOffNum = -1000 - minNum; // calculate exceeded range
//     fprintf(stdout, "Sorry your minimum number was out of the range by [%d]!", howFarOffNum);
//     return 1;
// }

// new min range
if (minNum < 0) {
    howFarOffNum = 0 - minNum; // calculate exceeded range
    fprintf(stdout, "Sorry your minimum number was out of the range by [%d]!\nYou entered: [%d]", howFarOffNum, minNum);
    return 1;
}

fprintf(stdout, "\n=> Please input a maximum number range to generate from.\nIt may not go above 1,000,000\n");
fscanf(stdin, "%d", &maxNum);

if (maxNum > 1000000) {
    howFarOffNum = maxNum - 1000000; // calculate exceeded range
    fprintf(stdout, "Sorry your maximum number was out of the range by [%d]!\nYou entered: [%d]", howFarOffNum, maxNum);
    return 1;
}

int randomNum;
randomNum = rand() % maxNum + minNum; // number generator between input min to input max ranges
fprintf(stdout, "\nYour random number between the ranges is:\n[%d]", randomNum);

return 0;

} // end of main loop
