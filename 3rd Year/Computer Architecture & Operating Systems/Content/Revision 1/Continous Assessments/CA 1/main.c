/*
Student ID:
Student Name: Raja M Sumeer
Module: Computer Arch & OS @ Year 3, Semester 2 (Technological University Dublin)

Date: 22/02/2026
Code Purpose:
CA1 - IEEE 754 Floating Point
Credits: Ben Toland
*/
// Libraries
#include <stdio.h>

int main(void)
{
	union myUnion
	{
		float myFloat;
		unsigned int myUnsignedInt; // 4 bytes of memory
	};

	union myUnion z;

	printf("Please enter a float: ");
	scanf("%f", &z.myFloat);

	printf("The number you entered was: %f\n", z.myFloat); //1
	
	printf("The stored number in hex is: 0x%X\n", z.myUnsignedInt); //2

	unsigned int sign = (z.myUnsignedInt >> 31) & 1;
	printf("The sign bit is: %u\n", sign); //3

	unsigned int biasedExp = (z.myUnsignedInt >> 23) & 0xFF;
	printf("The biased exponent is: %u\n", biasedExp);//4 

	int unbiasedExp = biasedExp - 127;
	printf("The unbiased exponent is: %d\n", unbiasedExp); // Binary Enoded//5

	unsigned int mantissa = z.myUnsignedInt & 0x7FFFFF;
	printf("The mantissa without implied 1 is: 0x%X\n", mantissa);//6

	unsigned int mantissa_implied = mantissa |= (1 << 23);
	printf("The mantissa with implied 1 is: 0x%X\n", mantissa_implied);//7

	return 0;
}