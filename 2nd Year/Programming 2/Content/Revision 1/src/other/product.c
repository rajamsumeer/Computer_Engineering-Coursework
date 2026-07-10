/* 
Student ID:
Student Name: Raja Sumeer
Date: 05/11/2024 10:10 AM
Purpose of Code: A program that accepts two CLA as INT and prints each value & it's product
*/

#include <stdio.h>
#include <stdlib.h> // Preprocessor Directive for the use of other functions such as atoi
int main(int argc, char *argv[]) {

int product;

int firstArg;
int secondArg;

int numOff;

int numArgs;
numArgs = argc;

// switch case instead of if statements
switch (numArgs) {
    case 4: // if args exceeds 3
    printf("Uh oh! You put in more than 2 CLAs!");
    return 1;
    break;
    case 2: // if args is less than 3
    printf("Uh oh! You need to give a min and max of 2 arguments!");
    return 1;
    break;
    case 1: // if args less than 2
    printf("Uh oh! You need to give a min and max of 2 arguments!");
    return 1;
    break;
}

firstArg = atoi(argv[1]); // find the first CLA as numerical value
if (firstArg > 10) { // condition check for first int value < 10 or > 0
    numOff = firstArg - 10; // check how far off the input value was from range
    printf("Out of range first argument. Keep it below 10 or above 0!\nYour number was %d off the max range of 10", numOff);
    return 1;
} else if (firstArg < 1) {
    printf("Out of range first argument. Keep it below 10 or above 0!");
    return 1;
}

secondArg = atoi(argv[2]); // find the second CLA as numerical value
if (secondArg > 10) { // condition check for second int value < 10 or > 0
    numOff = secondArg - 10; // check how far off the input value was from range
    printf("Out of range second argument. Keep it below 10 or above 0!\nYour number was %d off the max range of 10", numOff);
    return 1;
} else if (secondArg < 1) {
    printf("Out of range second argument. Keep it below 10 or above 0!"); // print warning to keep in range
    return 1;
}

product = (firstArg) * (secondArg);

printf("Your first value was: %d\n", firstArg);
printf("Your second value was: %d\nThe product is: %d", secondArg, product);

return 0;
} // end of main loop
