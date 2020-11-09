#ifndef boothsAlgorithm
#define boothsAlgorithm

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Adds the multiplicand to the accumulator.
void addNums( int accumulator[], int multiplicand[], int mulitplierNum );
// Performs the ones compliment of the number.
void onesComplementBits( int multiplicand[], int multiplicandNum );
// Shifts the number's bits to the right.
void bitShiftRight( int accumulator[], int mulitplier[], int& qn, int mulitplierNum );
// Displays the accumulator and the multiplier bits.
void outputBits( int accumulator[], int mulitplier[], int mulitplierNum );
// Sets the bit size of the numbers for the multiplication
void boothSetup( int multiplicand[], int mulitplier[], int temp[], int& multiplicandNum, int& mulitplierNum);
// Uses booth's algorithm to multiply the two numbers.
void boothAlgorithm( int multiplicand[], int mulitplier[], int temp[], int mulitplierNum, int shiftBitCounter );

#endif