/*
Student ID:
Student Name: Raja M. Sumeer
Module: Programming 2 @ Year 2, Semester 1 (Technological University Dublin)

Date: 03/12/2024 16:10

Code Purpose:
Matrice manipulation and arithmetic of matrices
Using functions for redundancy
*/

#include <stdio.h>

// function to create Array1.txt
void writeFile1() {
FILE *oneMatrix;
oneMatrix = fopen("Array1.txt", "w"); // create the initial Array1 txt file
fprintf(stdout, "Array1.txt has been created.\n");
fclose(oneMatrix);
}

// function to create Array2.txt
void writeFile2() {
FILE *secondMatrix;
secondMatrix = fopen("Array2.txt", "w"); // create the initial Array2 txt file
fprintf(stdout, "Array2.txt has been created.\n");
fclose(secondMatrix);
}

// function to create Array3.txt
void writeFile3() {
FILE *thirdMatrix;
thirdMatrix = fopen("Array3.txt", "w"); // create the initial Array3 txt file
fprintf(stdout, "Array3.txt has been created.\n");
fclose(thirdMatrix);
}

// function to write values to Matrix A (Array1.txt)
int writeMatrixA() {
int counter = 0; // int counter to count matrix R x C
int matrixA[3][2];
int row, col;
FILE *oneMatrix;
oneMatrix = fopen("Array1.txt", "w");
if (oneMatrix == NULL) { // check reading state => file exists or can be accessed
    fprintf(stdout, "Array1.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}
for (row = 0; row < 3; row++) {
    for (col = 0; col < 2; col++) {
        matrixA[row][col] = counter++;
        fprintf(oneMatrix, "%d\t", matrixA[row][col]);
    }
    fprintf(oneMatrix, "\n");
} // end of for loop
fclose(oneMatrix);
fprintf(stdout, "Array1.txt successful.\n");
return 0;
}

// function to write values to Matrix B (Array2.txt)
int writeMatrixB() {
int secondcounter = 0; // int counter to count matrix R x C
int matrixB[2][3];
int row, col;
FILE *secondMatrix;
secondMatrix = fopen("Array2.txt", "w");
if (secondMatrix == NULL) { // check reading state => file exists or can be accessed
    fprintf(stdout, "Array2.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}
// initialize matrix B with values and write contents to Array2.txt
for (row = 0; row < 2; row++) {
    for (col = 0; col < 3; col++) {
        matrixB[row][col] = secondcounter++;
        fprintf(secondMatrix, "%d\t", matrixB[row][col]);
    }
    fprintf(secondMatrix, "\n");
} // end of for loop
fclose(secondMatrix);
fprintf(stdout, "Array2.txt successful.\n");
return 0;
}

// function to read in values from Array1.txt and populate matrix A
int readMatrixA(int matrixA[3][2]) {
int row, col;
FILE *readArrayFile;
readArrayFile = fopen("Array1.txt", "r");
if (readArrayFile == NULL) { // check reading state => file exists or can be accessed
    fprintf(stdout, "Array1.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}

// reading in values from Array1.txt to matrix A 
for (row = 0; row < 3; row++) {
    for (col = 0; col < 2; col++) {
    fscanf(readArrayFile, "%d", &matrixA[row][col]);
    // fprintf(stdout, "%d\t", matrixA[row][col]);
    }
    // fprintf(stdout, "\n");
} // end of for loop
fclose(readArrayFile);
return 0;
}

// function to read in values from Array2.txt and populate matrix B
int readMatrixB(int matrixB[2][3]) {
int row, col;
FILE *readArrayFile2;
readArrayFile2 = fopen("Array2.txt", "r");
if (readArrayFile2 == NULL) { // check reading state => file exists or can be accessed
    printf("Array2.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}

// reading in values from Array2.txt to matrix B
for (row = 0; row < 2; row++) {
    for (col = 0; col < 3; col++) {
    fscanf(readArrayFile2, "%d", &matrixB[row][col]);
    // fprintf(stdout, "%d\t", matrixB[row][col]);
    }
    // fprintf(stdout, "\n");
} // end of for loop
fclose(readArrayFile2);
return 0;
}

// function to multiply matrix A and B and store in matrix C
void matrixMultiplyC(int matrixC[3][3], int matrixA[3][2], int matrixB[2][3]) {
int row, col, k;
for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
        matrixC[row][col] = 0; // initialize matrixC to 0 to avoid junk values
         for (k = 0 ; k < 2; k++) { // columns
        matrixC[row][col] += matrixA[row][k] * matrixB[k][col];
         }
    }
} // end of for loop
}

// function to send the result of matrix C to Command Line
void matrixMultiplyCResult(int matrixC[3][3]) {
int row, col;
fprintf(stdout, "\nResult of Matrix A x Matrix B:\n");
// print out multiplication result of matrix a and b from matrix c
for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
        fprintf(stdout, "%d\t", matrixC[row][col]);
    }
    fprintf(stdout, "\n");
} // end of for loop
}

int writeMatrixD(int matrixD[3][3]) {
int thirdcounter = 0; // another counter for matrix d
int row, col;
FILE *thirdMatrix;
thirdMatrix = fopen("Array3.txt", "w");
if (thirdMatrix == NULL) { // check reading state => file exists or can be accessed
    printf("Array3.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}
// initialize matrix D with values and write contents to Array3.txt
for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
        matrixD[row][col] = thirdcounter++; 
        fprintf(thirdMatrix, "%d\t", matrixD[row][col]);
    }
    fprintf(thirdMatrix, "\n");
} // end of for loop
fclose(thirdMatrix);
fprintf(stdout, "\nArray3.txt successful.\n");
return 0;
}

int readMatrixD(int matrixD[3][3]) {
int row, col;
FILE *readArrayFile3;
readArrayFile3 = fopen("Array3.txt", "r");
if (readArrayFile3 == NULL) { // check reading state => file exists or can be accessed
    printf("Array3.txt cannot be accessed for reading. Verify it exists and try again.\n");
    return 1;
}

// reading in values from Array3.txt to matrix D
for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
    fscanf(readArrayFile3, "%d", &matrixD[row][col]);
    // fprintf(stdout, "%d\t", matrixD[row][col]);
    }
    // fprintf(stdout, "\n");
} // end of for loop
fclose(readArrayFile3);
return 0;
}

void matrixEAdd(int matrixE[3][3], int matrixC[3][3], int matrixD[3][3]) {
int row, col;
for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
        matrixE[row][col] = 0; // initialize matrixE to 0 to avoid junk values
        matrixE[row][col] = matrixC[row][col] + matrixD[row][col];
    }
} // end of for loop
}

void matrixEAddResult(int matrixE[3][3]) {
int row, col;
fprintf(stdout, "\nResult of Matrix C + Matrix D:\n");
// print out addition result of matrix c and d from matrix e
for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
        fprintf(stdout, "%d\t", matrixE[row][col]);
    }
    fprintf(stdout, "\n");
} // end of for loop
}

int main() { // start of & definition of main loop

writeFile1();
writeFile2();
writeFile3();

int matrixA[3][2];
int matrixB[2][3];
int matrixC[3][3];

writeMatrixA();
writeMatrixB();

// Part (i)
readMatrixA(matrixA);
readMatrixB(matrixB);

// Part (ii) A x B
matrixMultiplyC(matrixC, matrixA, matrixB);
matrixMultiplyCResult(matrixC);

// Part (iii)

int matrixD[3][3];
int matrixE[3][3];

writeMatrixD(matrixD);
readMatrixD(matrixD);

matrixEAdd(matrixE, matrixC, matrixD);
matrixEAddResult(matrixE);

return 0;

} // end of main loop
