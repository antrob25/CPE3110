#include "boothsAlgorithm.h"

int main() 
{ 
    // multiplicand is the multiplicand, multiplier is the multiplier, and tempNum is a temperary array for arithmetic purposes
    int temp[12], multiplicand[12], multiplier[12]; 
    // multiplicandNum is the number of bits in multiplicand, multiplierNum is the number of bits in multiplier, and shiftBitCounter is the number of bits left to shift
    int multiplicandNum = 0, multiplierNum = 0, shiftBitCounter, boothType = -1; 

    while ( boothType < 0 || boothType > 1 )
    {
        cout << "Choose the type of booth's algorithm:  \n";
        cout << "0 is for normal booth and 1 is for extended booth" << endl;
        cin >> boothType;

        switch ( boothType )
        {
            case 0:
                boothSetup( multiplicand, multiplier, temp, multiplicandNum, multiplierNum, boothType);
                shiftBitCounter = multiplierNum; 
                boothAlgorithm(multiplicand, multiplier, temp, multiplierNum, shiftBitCounter); 
                break;
            case 1:
                boothSetup( multiplicand, multiplier, temp, multiplicandNum, multiplierNum, boothType);
                shiftBitCounter = multiplierNum; 
                boothAlgorithm(multiplicand, multiplier, temp, multiplierNum, shiftBitCounter); 
                break;
            default:
                cout << "Choose a number between 0 and 1!" << endl;
                break;
        }
    }    
    return 0;    
} 