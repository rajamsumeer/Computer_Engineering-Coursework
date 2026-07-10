/*
Student ID:
Student Name: Raja Sumeer
Date: 01/11/2024 17:11
Code Purpose: Copying contents between 2 files.
--------------
--------------
Supporting Code from Author(s): Mark Deegan, Joeseph O.
Help Sources:
https://stackoverflow.com/questions/49063518/why-does-fgetc-return-int-instead-of-char
https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/
--------------
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
char name1[100];
char name2[100];
FILE *fptrCreate, *fptrCreate2, *fptr, *fptr2;
fptrCreate = fopen("file1.txt", "w"); // create the initial first file
fprintf(fptrCreate, "This is file 1 content!");
fclose(fptrCreate);
printf("File 1 has been created.\n");

fptrCreate2 = fopen("file2.txt", "w"); // create the second file
fprintf(fptrCreate2, "This is file 2 content!");
fclose(fptrCreate2);
printf("File 2 has been created.\n");

printf("Enter the file name you wish to copy the contents from.\n");
scanf("%s", &name1); // scan input from keyboard for copying file
fptr = fopen(name1, "r"); // open the file for reading contents using read mode
if (fptr == NULL) {  // if copying file doesn't exist or wrong extension, let you know
    printf("The file you want to open for copying contents cannot be accessed. Verify it exists and try again.");
    return 1;
}

printf("Enter the file name you wish to copy contents to.\n");
scanf("%s", &name2); // scan input from keyboard for writing to file
fptr2 = fopen(name2, "w"); // open second file and write to it using write mode
if (fptr2 == NULL) { // if writing to file doesn't exist or wrong extension, let you know
    printf("The file you want to copy contents to cannot be accessed. Verify it exists and try again.");
    return 1;
}

int content; // fgetc returns integers and not characters
while ((content = fgetc(fptr)) != EOF) { // read each content until End of File
    fputc(content, fptr2); // write read content into desired file
}
fclose(fptr);
fclose(fptr2);
printf("Copied the contents to the desired file!");
return 0;
} // end of main loop
