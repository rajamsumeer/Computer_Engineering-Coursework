/*
Student ID:
Student Name: Raja M. Sumeer
Module: Digital Communications @ Year 3, Semester 1 (Technological University Dublin)

## Last modified: 20/10/2025
## Program Purpose:
*/

//-----------LIBRARIES------------//
#include <stdio.h>

//-----------MAIN PROGRAM------------//
int main() {
    // hardcoded char array
    char input[] = "eeeeeeebbbbbcccc";

//-----------LOCAL VARIABLES------------//
    char currentCharacter = input[0]; // start at first character in array
    int count = 1;
    int frequency[128] = {0}; // every 128 ASCII character

//-----------FOR LOOPS------------//
    // count character frequency count
    for (int i = 0; input[i] != '\0'; i++) {
    frequency[input[i]]++;
    }

    // loop through array until END
    for (int i = 1; input[i] != '\0'; i++) {
        // if next character same as current character, increment count
        if (input[i] == currentCharacter) {
            count++;
        // if next character changes, change value and reset count
        } else {
            fprintf(stdout, "%c %d\n", currentCharacter, count);
            currentCharacter = input[i]; // update to new character in array
            count = 1; // reset count
        }
    }

//-----------LOCAL VARIABLES------------//
    // Character frequency analysis
    int characterTotal = 0;
    char frequentCharacter, lessfreqCharacter;
    int lowestCharFreq = 10, highestCharFreq = 1;

//-----------FOR LOOP------------//
    // find character frequencies
    for (int j = 0; j < 128; j++) {
    if (frequency[j] > 0) { // does char appear? if so increment it's count
        characterTotal += frequency[j];
        // is char's count lower than 10?
        if (frequency[j] < lowestCharFreq) { 
            lowestCharFreq = frequency[j]; 
            lessfreqCharacter = j; 
        }

        // is char's count higher than 1?
        if (frequency[j] > highestCharFreq) { 
            highestCharFreq = frequency[j]; 
            frequentCharacter = j; 
        }
        }
    }

//-----------FINAL LOOP RUN------------//
    fprintf(stdout, "%c %d\n", currentCharacter, count);
    fprintf(stdout, "Total Characters: %d\n", sizeof(input)-1);
    fprintf(stdout, "Most frequent: '%c' (%d times)\n", frequentCharacter, highestCharFreq);
    fprintf(stdout, "Least frequent: '%c' (%d times)\n", lessfreqCharacter, lowestCharFreq);
    return 0;
}