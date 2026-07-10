/*
Student ID:
Student Name: Raja M. Sumeer
Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

Date: 10/12/2024 09:30 AM

Code Purpose: 
* Textfile Output Writing and Reading In not used as of right now, planning to do this later
and fully implement code as functions *
- Matice Multiplication
- Transposing of a Matrice

Tasks:
- Part 1: Matrice C[3][2] = { {1, 2}, {2, 3}, {3, 4} }
- Tranpose Matrice C = [2][3]

- Part 2: Matrice D[3][2] = { {4, 4}, {2, 2}, {2, 2} }
- Find E = C^T x D
- 2x3 x 3x2 = 2 x 2 result
*/

#include <stdio.h>
// Functions for Part 1

// function to print out Matrice C
void matrixCPrint(int matrixC[3][2]) {
int row, col;
for (row = 0; row < 3; row++) {
    for (col = 0; col < 2; col++) {
        fprintf(stdout, "%d\t", matrixC[row][col]);
    }
    fprintf(stdout, "\n");
    }
}

// function to get the transpose of Matrice C
void matrixCTransposed(int matrixC[3][2]) {
int row, col;
for (row = 0; row < 2; row++) { // rows become columns
    for (col = 0; col < 3; col++) { // columns become rows
        fprintf(stdout, "%d\t", matrixC[col][row]);
    }
    fprintf(stdout, "\n");
    }
}

int main() {

// Part 1

int matrixC[3][2] = { {1, 2}, {2, 3}, {3, 4} };

fprintf(stdout, "Matrice C\n"); // print out Matrice C under
matrixCPrint(matrixC); // call function

fprintf(stdout, "\nMatrice C^T"); // print out Matrice C Transposed under
fprintf(stdout, "\n");
matrixCTransposed(matrixC);

// Part 2

int matrixD[3][2] = { {4, 4}, {2, 2}, {2, 2} };
int matrixE[2][2];

int row, col, rowmultiplier;

        // Matrice E
for (row = 0; row < 2; row++) {
    for (col = 0; col < 2; col++) {
        matrixE[row][col] = 0; // initialize Matrice E to 0 to avoid junk values
        for (rowmultiplier = 0; rowmultiplier < 3; rowmultiplier++) { // multiply the 3 rows of matrice C and D
        matrixE[row][col] += matrixC[rowmultiplier][row] * matrixD[rowmultiplier][col]; // C^T x D
        /* this functions weirdly, 
        matriceC^T is a 2x3 yet it only gives right values when the row is 3 and columns 2,
        reversed to a 3x2..
        when I put matrixC[row][col], it will gives {12, 12}, {20, 20} and not {14, 14} {22, 22}
        */
        }
    }
} // end of for loop

fprintf(stdout, "\nMatrix E = CT x D\n");
for (row = 0; row < 2; row++) {
    for (col = 0; col < 2; col++) {
        fprintf(stdout, "%d\t", matrixE[row][col]); // print out matrix E which is a 2x2 result from CT x D
    }
    fprintf(stdout, "\n");
} // end of for loop

return 0;

} // end of main loop
