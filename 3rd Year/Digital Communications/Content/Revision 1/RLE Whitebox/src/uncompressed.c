/*
Student ID:
Student Name: Raja M. Sumeer
Module: Digital Communications @ Year 3, Semester 1 (Technological University Dublin)

## Last modified: 20/10/2025
## Program Purpose:
Makes a 256x256 uncompressed binary image file (all white pixels)
Writes metadata followed by pixel data.
Allows user to manually set or clear bits
*/

//-----------LIBRARIES & FILES------------//
#include <stdio.h> // fprintf,scanf, fopen,fread
#include <stdint.h> // for uint8_t, uint16_t
#include <stdbool.h> // for bool
#define writeFile "bin/white.divu" // uncompressed file write
#define readFile "bin/white.divu"

//-----------GLOBAL VARIABLES------------//
bool userCLAFlag = false; //skip/continue for user manual input

/*-----------HEADER STRUCTURE------------
            METADATA of 128 Bytes [2+2+124]
*/
typedef struct {
	uint16_t height;
	uint16_t width;
	uint8_t padding[124];
} headerStruct;

/*-----------FUNCTIONS------------
			USER INPUT DECLARATION FUNCTION
*/
void userCLA(char *action, int *whichByte, int *whichBit);

//-----------MAIN PROGRAM------------//
int main() {
//-----------LOCAL VARIABLES------------//
	char action; // user command (d, s or c)
	int whichByte, whichBit;
	userCLA(&action, &whichByte, &whichBit);
	
//-----------OPENING FILES [WRITE]------------//
	FILE *file = fopen(writeFile, "wb");
	if (!file) return 1;

//-----------WRITING HEADER [UNCOMPRESSED FILE]------------//
	headerStruct writeHeader = {256, 256, {0}};
	for (int i = 0; i < 124; i++){
	     writeHeader.padding[i] = 0xF0; // fill padding
	}
	fwrite(&writeHeader, sizeof(headerStruct), 1, file);
	
	/* define char [1 byte] array for 32 bytes per line
		each bit represents one white pixel
		(32 x 8 = 256)
	*/
	char line[32] = {0};

//-----------USER INPUT HANDLING & BIT/BYTE SETTINGS------------//
	/* handle user input based on flag
		and automatically set bits/byte
	*/
	if (userCLAFlag == true) {
	fprintf(stdout, "Skipping manual input..\n");
	userCLAFlag = false;
	whichByte = 0; whichBit = 0;
	} else if (action == 's') { // set bit
	line[whichByte] |= (1<<whichBit);
	} else if (action == 'c') { // clear bit
	line[whichByte] &= ~(1<<whichBit); 
	}
	// write line 256 times
	for (int row = 0; row < 256; row++) {
		fwrite(line, 1, 32, file); // one row of 32 byes
	}
	fclose(file);

	//-----------OPENING FILES [READ]------------//
    file = fopen(readFile, "rb");
    if (!file) return 1;

//-----------READ HEADER [METADATA] & SETTINGS DISPLAY EARLIER------------//
	headerStruct readHeader;
	fread(&readHeader, sizeof(headerStruct), 1, file);
	fprintf(stdout, "Header Data:\n%d by %d\n", readHeader.height, readHeader.width);
    
	// check and display the bit/byte state configured by input earlier
    fread(line, 1, 32, file);
    if (line[whichByte] & (1<<whichBit)) {
    	fprintf(stdout, "Bit %d of Byte %d set\n", whichBit, whichByte);
    } else {
    	fprintf(stdout, "Bit %d of Byte %d clear\n",whichBit, whichByte);
    }

    fclose(file);
	return 0;
}

/*-----------FUNCTIONS------------
			USER INPUT DEFINITION FUNCTION
	actions = default (d), set (s) and clear (c)
	default action will skip & auto set bits/byte
*/
void userCLA(char *action, int *whichByte, int *whichBit) {
	fprintf(stdout, "Type action: (d, c, s)\n");
	fscanf(stdin, "%c", action);
	if (*action == 'd') {
		userCLAFlag = true;
		return;
	}
	// default option wasn't selected
	fprintf(stdout, "Which byte and bit?\n");
	fscanf(stdin, "%d", whichByte);
	fscanf(stdin, "%d", whichBit);
}