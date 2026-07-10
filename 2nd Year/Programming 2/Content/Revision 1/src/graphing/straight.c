/*
// Student ID:
// Student Name: Raja M. Sumeer
// Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

// Date: 19/11/2024

// Code Purpose:
// - Plot a straight line in the integer domain
// -10 to 10, M = 4
// - y = mx+c

// Supporting Code from Author(s):
// Due Credits:
// - Joseph O. for XXCURVE structure.
*/

#include <stdio.h>

// Function for returning product
int formulaFunction(int x, int m) { // formula for y = mx+c
    return (m * x + 0); // return product of m * x
}

int main() {
    int x, 
    int y;
    int m = 4; // slope variable

    fprintf(stdout, "Y-AXIS"); // text for Y axis placement
    for (x = -10; x <= 10; x++) { // range from -10 to 10 for line
    fprintf(stdout, "\n%2d   ", x); // print out y axis
        for (y = 40; y >= -40; y = y-4) { // range for line to fall under each increase
            if (y == formulaFunction(x, m)) { // if y = mx+c
                fprintf(stdout, "*"); // print out each point on y axis
            } else { // if not then print a blank
                fprintf(stdout, "       "); // print out blank on y axis
            }
        }
        fprintf(stdout, "\n"); // go to a new line until loop finishes
    } // end of loop
    fprintf(stdout, "      "); // nudge x axis to the side to avoid y-axis collision
    for (int k = -10; k <= 10; k++) { // print x axis
    fprintf(stdout, "%-7d", k); // print each range value for x axis (-10 to 10)
    }
    fprintf(stdout, "=> X-AXIS"); // text for X axis placement

    return 0;
} // end of main loop
