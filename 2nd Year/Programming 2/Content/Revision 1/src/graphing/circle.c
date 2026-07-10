/*
// Student ID:
// Student Name: Raja M. Sumeer
// Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

// Date: 19/11/2024

// Code Purpose:
// - Plot a circle (disk) with radius 10 and centre = 0,0
// - X2 + Y2 = R2

// Supporting Code from Author(s):
// Due Credits:
// - Joseph O. for XXCURVE structure.
*/

#include <stdio.h>
#include <math.h>

// integer formula function as directly subbing in to a variable was giving blanks
int formulaFunction(int x, int y) {
    return (x * x + y * y); // return product of X2 + Y2
}

int main() {
    int x, 
    int y;
    int radius = 10;

    fprintf(stdout, "Y-AXIS"); // text for Y axis placement
    for (y = 10; y >= -10; y = y-1) { // y = 10, decrement y by 1 each time
    fprintf(stdout, "\n%3d   ", y); // print out y axis
        for (x = -10; x <= 10; x++) { // range from -10 to 10 for circle
            if (formulaFunction(x, y) == (radius * radius)) { // if X2 + Y2 = R2
                fprintf(stdout, "*"); // print out each point on y axis
            } else { // if not then print a blank
                fprintf(stdout, "     "); // print out blank on y axis
            }
        } // end of loop
        fprintf(stdout, "\n"); // go to a new line until loop finishes
    } // end of loop
    fprintf(stdout, "      "); // nudge x axis to the side to avoid y-axis collision
    for (int k = -10; k <= 10; k++) { // print x axis
    fprintf(stdout, "%-5d", k); // print each range value for x axis (-10 to 10)
    }
    fprintf(stdout, "\t=> X-AXIS"); // text for X axis placement

    return 0;
} // end of main loop
