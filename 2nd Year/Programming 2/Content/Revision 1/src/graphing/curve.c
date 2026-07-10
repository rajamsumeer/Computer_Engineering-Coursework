/*
// Student ID:
// Student Name: Raja M. Sumeer
// Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

// Date: 26/11/2024 00:49

// Code Purpose:
// - Plot a curve line where y = x^2 

// - Spacing out method (%3d, %-5d)

// Supporting Code from Author(s):
// - Joseph O.
// Due Credits:
// - Joseph O.
*/

#include <stdio.h>

int main() {
    int x, 
    int y;

    fprintf(stdout, "Y-AXIS"); // text for Y axis placement
    for (y = 70; y >= 0; y = y-2) { // y = 70, decrement y by 2 each time
    fprintf(stdout, "\n%3d   ", y); // print out y axis
        for (x = -10; x <= 10; x++) { // range from -10 to 10 for curve
            if (y == x * x) { // if y = x^2
                fprintf(stdout, "*"); // print out each point on y axis
            } else { // if not then print a blank
                fprintf(stdout, "     "); // print out blank on y axis
            }
        }
        fprintf(stdout, "\n"); // go to a new line until loop finishes
    } // end of loop
    fprintf(stdout, "      "); // nudge x axis to the side to avoid y-axis collision
    for (int k = -10; k <= 10; k++) { // print x axis
    fprintf(stdout, "%-5d", k); // print each range value for x axis (-10 to 10)
    }
    fprintf(stdout, "\t=> X-AXIS"); // text for X axis placement

    return 0;
} // end of main loop
