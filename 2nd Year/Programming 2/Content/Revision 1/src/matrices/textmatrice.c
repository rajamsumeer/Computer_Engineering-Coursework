/*
Student ID:
Student Name: Raja M. Sumeer
Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

Date: 26/11/2024 10:14

Code Purpose:
- Generate textfiles using Matrices as memory for values

Due Credits: 
- For loop demonstration from John
*/

#include <stdio.h>

int main() {

FILE *fptrCreate, *fptr;
fptrCreate = fopen("file1.txt", "w"); // create the initial first file
printf("File 1 has been created.\n");

int numericalMatrixA[21][21][4];// 20 rows, 20 columns, 3 elements

int i;
int j;
int k;

for (i = 0; i < 21; i++) {
    for (j = 0; j < 21; j++) { // column
        for (k = 0; k < 4; k++) { // row
            numericalMatrixA[i][j][k];
        }
    }
} // end of for loop

for (i = 0; i < 21; i++) {
    for (j = 0; j < 21; j++) { // column
        for (k = 0; k < 4; k++) { // element
        fprintf(fptrCreate, "%d %d %d\t", i, j, k);
        }
    }
} // end of for loop

fclose(fptrCreate);
fprintf(stdout, "Array values have been written to file.");

return 0;

} // end of main loop
