#include "boothsAlgorithm.h"

void addNums(int accumulator[], int multiplicand[], int mulitplierNum) 
{ 
    int carry = 0; 
    for ( int i = 0; i < mulitplierNum; i++ ) 
    {       
        accumulator[i] = accumulator[i] + multiplicand[i] + carry; 
          
        if (accumulator[i] > 1) 
        { 
            accumulator[i] = accumulator[i] % 2; 
            carry = 1; 
        } 
        else
            carry = 0; 
    } 
} 

void onesComplementBits(int multiplicand[], int multiplicandNum) 
{ 
    int i, temp[12] = {0}; 
    temp[0] = 1; 
      
    for (i = 0; i < multiplicandNum; i++) 
        multiplicand[i] = (multiplicand[i] + 1) % 2; 
    
    addNums(multiplicand, temp, multiplicandNum); 
} 

void bitShiftRight(int accumulator[], int mulitplier[], int& qn, int mulitplierNum) 
{ 
    int temp; 
    temp = accumulator[0]; 
    qn = mulitplier[0]; 
      
    for (int i = 0; i < mulitplierNum - 1; i++) 
    { 
        accumulator[i] = accumulator[i + 1]; 
        mulitplier[i] = mulitplier[i + 1]; 
    } 

    mulitplier[mulitplierNum - 1] = temp; 
} 

void outputBits(int accumulator[], int mulitplier[], int mulitplierNum) 
{ 
    // displays the accumulator bits
    for (int i = mulitplierNum - 1; i >= 0; i--) 
        cout << accumulator[i]; 

    cout << "   "; 
      
    // Displays the multiplier bits
    for (int i = mulitplierNum - 1; i >= 0; i--) 
        cout << mulitplier[i]; 
} 

void boothSetup( int multiplicand[], int mulitplier[], int tempNum[], int& multiplicandNum, int& mulitplierNum)
{
    string bits;
    int bitNum = 0;

    while ( bitNum < 4 || bitNum > 12)
    {
        cout << "Enter a number with the bit size of 4 to 12" << endl;
        cin >> bits;
        bitNum = bits.size();
        if ( bitNum < 4 || bitNum > 12 )
            cout << "Wrong bit size" << endl;
    }    

    for ( int i = 0; i < bitNum; i++ )
    {
        if ( bits[i] == '1' )
            multiplicand[i] = 1;
        else
            multiplicand[i] = 0;
        multiplicandNum++;
    }
      
    // copy multiplicand to tempNum 
    for (int i = multiplicandNum - 1; i >= 0; i--) 
        tempNum[i] = multiplicand[i];

    reverse(multiplicand, multiplicand + multiplicandNum); 
  
    onesComplementBits(tempNum, multiplicandNum); 

    bitNum = 0;
    while ( bitNum < 4 || bitNum > 12 )
    {
        cout << "Enter a number with the bit size of 4 to 12" << endl;
        cin >> bits;
        bitNum = bits.size();
        if ( bitNum < 4 || bitNum > 12 )
            cout << "Wrong bit size" << endl;

    }

    for ( int i = 0; i < bitNum; i++ )
    {
        if ( bits[i] == '1' )
            mulitplier[i] = 1;
        else
            mulitplier[i] = 0;
        mulitplierNum++;
    }

    reverse(mulitplier, mulitplier + mulitplierNum); 
}
  
void boothAlgorithm(int multiplicand[], int mulitplier[], int tempNum[], int mulitplierNum, int shiftBitCounter) 
{ 
    int qn = 0, accumulator[12] = { 0 }; 
    int temp = 0; 
    cout << "qn   ext   multiplicand   accumulator    mulitplier   Counter\n"; 
    cout << "            initial        "; 
      
    outputBits(accumulator, mulitplier, mulitplierNum); 
    cout << "      " << shiftBitCounter << "\n"; 
      
    while ( shiftBitCounter != 0 ) 
    { 
        cout << mulitplier[0] << "      " << qn; 
        if ( (qn + mulitplier[0]) == 1 ) 
        { 
            if (temp == 0) 
            { 
                addNums(accumulator, tempNum, mulitplierNum); 
                cout << "    ac = ac - mc   "; 
                  
                for (int i = mulitplierNum - 1; i >= 0; i--) 
                    cout << accumulator[i]; 

                temp = 1; 
            } 
        
            else if (temp == 1) 
            { 
                // add multiplicand to accumulator 
                addNums(accumulator, multiplicand, mulitplierNum); 
                cout << "    ac = ac + mc   "; 
                  
                for (int i = mulitplierNum - 1; i >= 0; i--) 
                    cout << accumulator[i]; 

                temp = 0; 
            } 

            cout << "\n         "; 
            bitShiftRight(accumulator, mulitplier, qn, mulitplierNum); 
        } 
        
        if (qn - mulitplier[0] == 0) 
        {
            cout << " ";
            bitShiftRight(accumulator, mulitplier, qn, mulitplierNum); 
        }    
        cout << "   bitShiftRight  "; 
         
        outputBits(accumulator, mulitplier, mulitplierNum); 
         
        cout << "   "; 
          
        // decrement counter 
        shiftBitCounter--; 
        cout << "   " << shiftBitCounter << "\n"; 
    } 

    cout << endl << "Result = ";       
    for (int8_t i = mulitplierNum - 1; i >= 0; i--) 
        cout << mulitplier[i]; 
    cout << endl;
} 