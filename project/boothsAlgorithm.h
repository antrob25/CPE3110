#ifndef boothsAlgorithm
#define boothsAlgorithm

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Adds the multiplicand to the accumulator.
void addNums( int accumulator[], int multiplicand[], int multiplierNum );
// Performs the twos compliment of the number.
void twosComplementBits( int multiplicand[], int multiplicandNum );
// Shifts the number's bits to the right.
void bitShiftRight( int accumulator[], int multiplier[], int& qn, int multiplierNum );
// Displays the accumulator and the multiplier bits.
void outputBits( int accumulator[], int multiplier[], int multiplierNum );
// Sets the bit size of the numbers for the multiplication
void boothSetup( int multiplicand[], int multiplier[], int tempNum[], int& multiplicandNum, int& multiplierNum, int boothType);
// Uses booth's algorithm to multiply the two numbers.
void boothAlgorithm( int multiplicand[], int multiplier[], int tempNum[], int multiplierNum, int shiftBitCounter );
// Uses booth's algorithm extended to multiply the two numbers.
void boothAlgorithmExtended( int multiplicand[], int multiplier[], int tempNum[], int multiplierNum, int shiftBitCounter );

#endif