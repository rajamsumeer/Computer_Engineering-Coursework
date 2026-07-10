/*
Student ID:
Student Name: Raja M. Sumeer
Module: Digital Communications @ Year 3, Semester 1 (Technological University Dublin)

## Last modified:
## Program Purpose:
Reads the uncompressed 256x256 binary image file
and compresses it using Run Length Encoding.

## Draft/Protoype code for finalized compressed code
*/
#include <stdio.h>
#include <stdbool.h>
#define readFile "white.divu"

int main() {
	FILE *file = fopen(readFile, "rb");
	if (!file) return 1;
	//some array goes here
	char line[32];
	int count = 0;
	int currentBit = 0;
	bool value;
	for (int row = 0; row < 256; row++) {
	fread(line, 1, 32, file);
	for (int byte = 0; byte < 32; byte++) {
	for (int bit = 7; bit >= 0; bit--) {
	value = (line[byte] & (1 << bit)) ? 1 : 0;
	if (value == currentBit) {
		count++;
	} else {
		fprintf(stdout, "%d %d\n", currentBit, count);
		currentBit = value;
		count = 1;
	}
		//if the bit is 0 count incremement
		//if not stop this count, change value and start new count
	}
	}
	}
	fprintf(stdout, "%d %d\n", currentBit, count);
	fclose(file);
	return 0;
}
