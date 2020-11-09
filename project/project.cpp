#include "boothsAlgorithm.h"

int main() 
{ 
    // multiplicand is the multiplicand, mulitplier is the multiplier, and tempNum is a temperary array for arithmetic purposes
    int tempNum[12], multiplicand[12], mulitplier[12]; 
    // multiplicandNum is the number of bits in multiplicand, mulitplierNum is the number of bits in mulitplier, and shiftBitCounter is the number of bits left to shift
    int multiplicandNum = 0, mulitplierNum = 0, shiftBitCounter, boothType; 

    cout << "Choose the type of booth's algorithm:  \n";
    cout << "0 is for normal booth and 1 is for extended booth" << endl;
    cin >> boothType;

    switch ( boothType )
    {
        case 0:
            boothSetup( multiplicand, mulitplier, tempNum, multiplicandNum, mulitplierNum);
            shiftBitCounter = mulitplierNum; 
            boothAlgorithm(multiplicand, mulitplier, tempNum, mulitplierNum, shiftBitCounter); 
            break;
        case 1:
            break;
        default:
            cout << "Choose a number between 0 and 1!" << endl;
            break;
    }
    return 0;    
} 