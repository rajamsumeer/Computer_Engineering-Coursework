/*
Student ID:
Student Name: Raja M. Sumeer
Module: Digital Communications @ Year 3, Semester 1 (Technological University Dublin)

## Last modified: 20/10/2025
## Program Purpose:
Reads the uncompressed 256x256 binary image file
and compresses it using Run Length Encoding.
RLE: Finds frequent values and replaces with a single one along with count

## Program output Result:
white.divu from 9KB to 1KB (white.divc)
*/

//-----------LIBRARIES & FILES------------//
#include <stdio.h>
#include <stdint.h> // for uint8_t, uint16_t
#define readFile "bin/white.divu" // uncompressed file reading
#define writeFile "bin/white.divc" // compressed file writing

/*-----------HEADER STRUCTURE------------
            METADATA of 128 Bytes [2+2+124]
*/
typedef struct {
    uint16_t width;
    uint16_t height;
    uint8_t padding[124];
} headerStruct;

//-----------MAIN PROGRAM------------//
int main() {
//-----------FILE OPENING------------//
    FILE *inputFile = fopen(readFile, "rb");
    FILE *outputFile = fopen(writeFile, "wb");
    if (!inputFile || !outputFile) return 1;

//-----------WRITING HEADER [COMPRESSED FILE]------------//
    headerStruct writeHeader = {256, 256, {0}};
    for (int i = 0; i < 124; i++) {
        writeHeader.padding[i] = 0xF0; // fill padding
    }
    fwrite(&writeHeader, sizeof(headerStruct), 1, outputFile);

/*-----------READ HEADER [UNCOMPRESSED FILE]------------
Skip metadata & go where pixel data starts
*/
    headerStruct readHeader;
    fread(&readHeader, sizeof(headerStruct), 1, inputFile); // pixel data starts

//-----------LOCAL VARIABLES------------//
    char line[32];
    int value; // reoccuring bit value (0/1)
    uint32_t count = 0; // number of bits with same value
    int currentBit = 0; // bit value being looked at

//-----------RLE COMPRESSION------------//
    for (int row = 0; row < 256; row++) {
        fread(line, 1, 32, inputFile); // read one row of 32 bytes
    for (int byte = 0; byte < 32; byte++) {
    for (int bit = 7; bit >= 0; bit--) {
        value = (line[byte] & (1 << bit)) ? 1 : 0; // get bit 0 or 1
    // if bit being looked at matches current bit then increment count
    if  (value == currentBit) {
        count++;
    // if bit being looked at changes value, then stop count, change value and start new count
    } else {
    fwrite(&currentBit, 1, 1, outputFile);
    fwrite(&count, 3, 1, outputFile);
    currentBit = value;
    count = 1;
          }
        }
      }
    }

//-----------FINAL LOOP RUN & CLOSING FILES------------//
    fwrite(&currentBit, 1, 1, outputFile);
    fwrite(&count, 3, 1, outputFile);
    // show RLE: [value][count]
    fprintf(stdout, "%d %d\n", value, count);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}