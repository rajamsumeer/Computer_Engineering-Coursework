/*
Student ID: 
Student Name: Raja Sumeer
Date: 30/10/2024 15:02
Code Purpose: Adds numbers together from arguments and creates a result text file.
Supporting Code from Author(s): Mark Deegan via xxCLA03.c code from Github
Credits: Joseph Obong for <stdlib.h> and atoi explanation
Credits: Mark Deegan for Textfile creation on Brightspace under "File Handling in C"
Credits: saving a file to a folder - https://www.reddit.com/r/C_Programming/comments/qkk624/fopenfiletxt_vs_fopenusersmynamefiletxt/
*/
#include <stdio.h>
#include <stdlib.h> // define library for other functions such as atio
#include <math.h>
int main(int argc, char* argv[]) {
    int integerArgs;
    int i;
    int value;
    int value2;
    int total = 0;
    integerArgs = argc -1; // number of arguments provided in argc
    
    // now using an example from Joseph to use only one for loop
    // for loop to convert arguments and sum arguments
    if (integerArgs> 0) {
    for (i = 1; i <= integerArgs; i++) {
        value = atoi(argv[i]); // convert each argument into a numerical value
        total += value; // add arguments together for total
        printf("[%d] %s\n", i, argv[i]);
    }
    printf("\nYour result is %d", total);
    }

    // create a text file for results
    FILE *fptr; // declare file pointer
    fptr = fopen("Lesson2/results.txt", "w");
    fprintf(fptr, "Your result is %d", total);
    fclose(fptr);

    // START OF PART 2
    // MIN VALUE
    int minvalue = atoi(argv[1]);
    int maxvalue;
    int finalvalue;
    for (i = 1; i <= integerArgs; i++) {
    maxvalue = atoi(argv[i]); // convert to numerical value
    } // end of i loop
    if (minvalue < maxvalue) { // if min is less than max, final (min val) is min
        finalvalue = minvalue;
    } else if (minvalue > maxvalue) { // if min is greater than max, final (min val) is max val
        finalvalue = maxvalue;
    }
    printf("\nThe min value of those numbers is: %d", finalvalue);

    // MAX VALUE
    if (minvalue < maxvalue) { // if min val is less than max val then max val is max 
        finalvalue = maxvalue;
    } else if (minvalue > maxvalue) { // if min val is greater than max val then max val is min val
        finalvalue = minvalue;
    }
    printf("\nThe max value of those numbers is: %d", finalvalue);

    // AVERAGE
    float divsummed;
    divsummed = total / integerArgs; // divide the total by number of inputs to get average
    printf("\nThe average of those numbers is: %1.f", divsummed);

    return 0;
} // end of main loop
