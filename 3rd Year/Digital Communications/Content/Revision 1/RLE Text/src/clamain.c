/*
Student ID:
Student Name: Raja M. Sumeer
Module: Digital Communications @ Year 3, Semester 1 (Technological University Dublin)

## Last modified: 27/10/2025
## Program Purpose:
Implements & demonstrates a lossless compression method called Run Length Encoding 
for text data compression using input data from the command line (user arguments).
- Replaces repetitive characters with pairs (character, count).
- Generates a .RLE file of the compressed text data.
- Performs character & compression analysis and sends to terminal output.

## Sources:
https://www.geeksforgeeks.org/dsa/least-frequent-element-array/
*/

//-----------LIBRARIES & FILES------------//
#include <stdio.h>
#include <string.h> // for sprintf
#define writeFile "bin/cla.rle"

//-----------MAIN PROGRAM------------//
int main(int argc, char *argv[]) {
//-----------FILE OPENING------------//
    FILE *outputFile = fopen(writeFile, "w");
//-----------LOCAL VARIABLES------------//
   int estimatedCompressionSize = 0;
   int count = 1;
   char input[256]= {0}; // all elements at 0
   int charactersCount = 0; // character count from file input [.txt]
   int numArgs = argc -1; // get amount of arguments from CL (minus program name)
   char countToString[20];

//-----------SWITCH CASE FOR HANDLING USER CLA------------//
    switch (numArgs) {
    case 0:
    fprintf(stdout, "You need to give an argument of characters!\n");
    return 1;
    case 1:
    for (int i = 0; argv[1][i] != '\0'; i++) { // get characters until delimiter
        charactersCount++; // increment characters count
        input[i] = argv[1][i]; // store each character in array
    }
    break;
    default: // if more than one arg (./clamain.exe aabbcc dddk <= invalid)
    fprintf(stdout, "Only one argument of characters!\n");
    return 1;
   }
   char currentCharacter = input[0]; // start at first character in array

//-----------FOR LOOP------------//
    // loop through array until END
    for (int i = 1; input[i] != '\0'; i++) {
        // if next character same as current character, increment count
        if (input[i] == currentCharacter) {
            count++;
        // if next character changes, change value and reset count
        } else {
            // fprintf(stdout, "%c%d", currentCharacter, count);
            fwrite(&currentCharacter, 1, 1, outputFile); // write character
            sprintf(countToString, "%d", count); // convert int count to string
            fwrite(&countToString, 1, strlen(countToString), outputFile); // write converted count
            currentCharacter = input[i]; // update to new character in array
            count = 1; // reset count
            estimatedCompressionSize += 2; // char and value is 2 bytes [not using RAM size which'd equal 5 bytes e.g E7]
        }
    }

//-----------LOCAL VARIABLES------------//
    // Character frequency analysis
    int characterTotal = 0;
    int characterMinFrequency = 50; // use magic number for now to find difference
    int characterMaxFrequency = 0;
    int leastFrequentCharacter, mostFrequentCharacter;

/*-----------FOR LOOPS------------
            NESTED LOOPS TO FIND CHARACTER FREQUENCY
            CHECK EACH CHARACTER IN ARRAY THEN INCREMENT COUNT IF REPEATS
*/
    for (int j = 0; j < input[j] != '\0'; j++) { // until delimiter
        characterTotal = 0; // reset counter

    for (int k = 0; k < input[k] != '\0'; k++) { // until delimiter
        if (input[j] == input[k]) { // e.g does input[1] = input[2]? (e = e in [ee]eebbbcc....)
            characterTotal++; // increment counter
        }
    }
    
    // FINDING MOST/LEAST FREQUENT CHARACTER
    if (characterTotal < characterMinFrequency) {
        characterMinFrequency = characterTotal;
        leastFrequentCharacter = input[j];
    } else if (characterTotal > characterMaxFrequency) {
        characterMaxFrequency = characterTotal;
        mostFrequentCharacter = input[j];
    }
    }

//-----------FINAL LOOP RUN------------//
    estimatedCompressionSize += 2;
    float estimatedCompressionRatio = ((float)(charactersCount) / estimatedCompressionSize);
    fwrite(&currentCharacter, 1, 1, outputFile);
    sprintf(countToString, "%d", count);
    fwrite(&countToString, 1, strlen(countToString), outputFile);
    fprintf(stdout, "RLE file generated!\n--------------------\nDisplaying Metadata:\n--------------------\n");
    // fprintf(stdout, "%c%d\n", currentCharacter, count);
    fprintf(stdout, "Total Characters: %d\n", charactersCount);
    fprintf(stdout, "Most frequent: '%c' (%d times)\n", mostFrequentCharacter, characterMaxFrequency);
    fprintf(stdout, "Least frequent: '%c' (%d times)\n", leastFrequentCharacter, characterMinFrequency);
    fprintf(stdout, "Compression Size: %d\n", estimatedCompressionSize);
    fprintf(stdout, "Compression Ratio: %.2f:1\n", estimatedCompressionRatio);
    fclose(outputFile);
    return 0;
}