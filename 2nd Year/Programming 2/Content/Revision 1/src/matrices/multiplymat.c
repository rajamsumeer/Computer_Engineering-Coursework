/*
Student ID:
Student Name: Raja M. Sumeer
Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

Date: 26/11/2024 10:14

Code Purpose:
- Multiply two matrices and send result to Matrice C (+ txt file output)

Due Credits: 
- For loop demonstration from John
- Multiplication of matrices demonstration by John
*/

#include <stdio.h>

int main() {

int matrixA[20][20];
int matrixB[20][20];
int matrixC[20][20];

int row, col, k;
int counter = 0; // counter for matrix a
int secondcounter = 0; // another counter for matrix b

FILE *oneMatrix, *secondMatrix, *thirdMatrix, *readArrayFile, *readArrayFile2;
FILE *fourthMatrix;

// create Array1.txt

oneMatrix = fopen("Array1.txt", "w");
fprintf(stdout, "Array1.txt has been created.\n");

// load Array1.txt with matrix A values

for (row = 0; row < 20; row++) {
    for (col = 0; col < 20; col++) {
        matrixA[row][col] = counter++;
        fprintf(oneMatrix, "%d\t", matrixA[row][col]);
    }
    fprintf(oneMatrix, "\n");
}
fclose(oneMatrix);
fprintf(stdout, "Array1.txt successful.\n");

// create Array2.txt

secondMatrix = fopen("Array2.txt", "w");
fprintf(stdout, "Array2.txt has been created.\n");

// load Array2.txt with matrix B values

for (row = 0; row < 20; row++) {
    for (col = 0; col < 20; col++) {
        matrixB[row][col] = secondcounter++;
        fprintf(secondMatrix, "%d\t", matrixB[row][col]);
    }
    fprintf(secondMatrix, "\n");
} // end of for loop
fclose(secondMatrix);
fprintf(stdout, "Array2.txt successful.\n");

// [section] read in Array.txt values to Matrixs

readArrayFile = fopen("Array1.txt", "r"); // read Array1.txt file
if (readArrayFile == NULL) { // check reading state => file exists or can be accessed
    printf("Array1.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}

// reading in values from Array1.txt to matrix A 
for (row = 0; row < 20; row++) {
    for (col = 0; col < 20; col++) {
    fscanf(readArrayFile, "%d", &matrixA[row][col]);
    }
} // end of for loop
fclose(readArrayFile);

// reading in values from Array2.txt to matrix B
readArrayFile2 = fopen("Array2.txt", "r");
if (readArrayFile2 == NULL) { // check reading state => file exists or can be accessed
    printf("Array2.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}

// reading in values from Array1.txt to matrix B
for (row = 0; row < 20; row++) {
    for (col = 0; col < 20; col++) {
    fscanf(readArrayFile2, "%d", &matrixB[row][col]);
    }
} // end of for loop
fclose(readArrayFile2);

// Multiply Matrix A and B and store in Matrix C

for (row = 0; row < 20; row++) {
    for (col = 0; col < 20; col++) {
        matrixC[row][col] = 0; // initialize matrixC to 0 to avoid junk values
        matrixC[row][col] += matrixA[row][col] * matrixB[row][col]; 
    }
} // end of for loop

// outputting result to textfile (matrix C)

fourthMatrix = fopen("Array3.txt", "w");
fprintf(stdout, "Array3.txt has been created.\n"); // notify that Array3.txt was created

for (row = 0; row < 20; row++) { // increment rows
    for (col = 0; col < 20; col++) { // increment columns
        fprintf(fourthMatrix, "%d\t", matrixC[row][col]); // print out matrixC (A x B result)
    }
    fprintf(fourthMatrix, "\n");
} // end of for loop

fclose(fourthMatrix);
fprintf(stdout, "Array3.txt successful.\n");

return 0;

} // end of main loop
