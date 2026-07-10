/*
Student ID:
Student Name: Raja M. Sumeer
Module: Digital Communications @ Year 3, Semester 1 (Technological University Dublin)

## Last modified: 27/10/2025
## Program Purpose:
Implements & demonstrates a lossless compression method called Run Length Encoding 
for text data compression using input data from a file.
- Replaces repetitive characters with pairs (character, count).
- Generates a .RLE file of the compressed text data.
- Performs character & compression analysis and sends to terminal output.

## Sources:
https://www.geeksforgeeks.org/dsa/least-frequent-element-array/
*/

//-----------LIBRARIES & FILES------------//
#include <stdio.h>
#include <string.h> // for sprintf
#define inputFile "file.txt"
#define writeFile "bin/file.rle"

//-----------MAIN PROGRAM------------//
int main() {
//-----------FILE OPENING------------//
    FILE *outputFile = fopen(writeFile, "w");
    FILE *finput = fopen(inputFile, "r");
    if (!finput || finput == NULL) return 1;

//-----------LOCAL VARIABLES------------//
    int estimatedCompressionSize = 0;
    char input[256]= {0}; // all elements at 0
    char character;
    int charactersCount = 0; // character count from file input [.txt]
    int z = 0;
    while ((character = fgetc(finput)) != EOF) { // get each character from input until delimiter
      charactersCount++; // increment characters count
      input[z++] = character; // store each character in array
   }
   char currentCharacter = input[0]; // start at first character in array
   int count = 1;
   char countToString[20];

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
    fclose(finput);
    fprintf(stdout, "Most frequent: '%c' (%d times)\n", mostFrequentCharacter, characterMaxFrequency);
    fprintf(stdout, "Least frequent: '%c' (%d times)\n", leastFrequentCharacter, characterMinFrequency);
    fprintf(stdout, "Compression Size: %d\n", estimatedCompressionSize);
    fprintf(stdout, "Compression Ratio: %.2f:1\n", estimatedCompressionRatio);
    fclose(outputFile);
    return 0;
}