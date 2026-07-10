/*
Student ID:
Student Name: Raja M. Sumeer
Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

Date: 12/12/2024

Code Purpose:
- Write a Program in C to calculate 2x2 matrice inverses

Tasks:
- Write a Program in C to calculate the 2x2 matrice inverses of:
A[5,6, 4,5] & B[6,4 3,3]
*/

// function for determinant A ( 2x2 matrice) and Part 1.1
int determinantA(int a, int d, int b, int c) {
    return (a * d) - (b * c); // return calculation of formula a*d-b*c
}

// function for determinant B ( 2x2 matrice) and Part 1.2
int determinantB(int a, int d, int b, int c) {
    return (a * d) - (b * c); // return calculation of formula a*d-b*c
}

#include <stdio.h>
#include <math.h>

int main() {

// Part 1.1

int a, d, b, c; // variables for the determinant formula

a = 5, d = 5, b = 6, c = 4; // variables of determinant A

int detA; // variable for the determinant (Matrice A)

float fraction; // variable for inverse determinant formula

detA = determinantA(a, d, b, c); // get determinant of matrice A

fraction = 1.0 / detA; // A^-1 = 1/detA[]

int reverse_b;
reverse_b = b * -1; // turn b into negative value

int reverse_c;
reverse_c = c * -1; // turn c into negative value

fprintf(stdout, "Result of 2x2 Inverse Matrice A:\n");
fprintf(stdout, "Determinant A is '%d'\n", detA);
fprintf(stdout, "A^-1 = 1/%d [%d, %d\n\t%d, %d]", detA, d, reverse_b, reverse_c, a);

// Part 1.2

a = 6, d = 3, b = 4, c = 3; // variables of determinant B

int detB; // variable for the determinant (Matrice B)

detB = determinantB(a, d, b, c); // get determinant of matrice B

fraction = 1.0 / detB; // B^-1 = 1/detB[]

reverse_b = b * -1; // turn b into negative value
reverse_c = c * -1; // turn c into negative value

float outsideXinside_a = fraction * a; // calculate 1/detB * inside matrice variables
float outsideXinside_b = fraction * reverse_b; // calculate 1/detB * inside matrice variables
float outsideXinside_c = fraction * reverse_c; // calculate 1/detB * inside matrice variables
float outsideXinside_d = fraction * d; // calculate 1/detB * inside matrice variables

fprintf(stdout, "\n\n"); // seperate new lines
fprintf(stdout, "Result of 2x2 Inverse Matrice B:\n");
fprintf(stdout, "Determinant B is '%d'\n", detB);
fprintf(stdout, "B^-1 = 1/%d [%.2f, %.2f\n\t%.2f, %.2f]", detB, outsideXinside_d, outsideXinside_b, outsideXinside_c, outsideXinside_a);

return 0;

} // end of main loop
