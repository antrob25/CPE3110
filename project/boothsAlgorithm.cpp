#include "boothsAlgorithm.h"

void addNums(int accumulator[], int multiplicand[], int multiplierNum) 
{ 
    int carry = 0; 
    for ( int i = 0; i < multiplierNum; i++ ) 
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

void twosComplementBits(int multiplicand[], int multiplicandNum) 
{ 
    int temp[multiplicandNum] = {0}; 
    temp[0] = 1; 
      
    for (int i = 0; i < multiplicandNum; i++) 
        multiplicand[i] = (multiplicand[i] + 1) % 2; 
    
    addNums(multiplicand, temp, multiplicandNum); 
} 

void bitShiftRight(int accumulator[], int multiplier[], int& qn, int multiplierNum) 
{ 
    int temp; 
    temp = accumulator[0]; 
    qn = multiplier[0]; 
      
    for (int i = 0; i < multiplierNum - 1; i++) 
    { 
        accumulator[i] = accumulator[i + 1]; 
        multiplier[i] = multiplier[i + 1]; 
    } 

    multiplier[multiplierNum - 1] = temp; 
} 

void outputBits(int accumulator[], int multiplier[], int multiplierNum) 
{ 
    // displays the accumulator bits
    for (int i = multiplierNum - 1; i >= 0; i--) 
        cout << accumulator[i]; 

    cout << "   "; 
      
    // Displays the multiplier bits
    for (int i = multiplierNum - 1; i >= 0; i--) 
        cout << multiplier[i]; 
} 

void boothSetup( int multiplicand[], int multiplier[], int tempNum[], int& multiplicandNum, int& multiplierNum, int boothType)
{
    string bits;
    int bitNum = 0;

    if ( boothType == 0 )
    {
        while ( bitNum < 4 || bitNum > 12)
        {
            cout << "Enter a number with the bit size of 4 to 12" << endl;
            cin >> bits;
            bitNum = bits.size();
            if ( bitNum < 4 || bitNum > 12 )
                cout << "Wrong bit size" << endl;
        }
    }
    else if ( boothType == 1 )
    {
        while ( (bitNum < 4 || bitNum > 12) && (bitNum %2 != 0) )
        {
            cout << "Enter a number with the bit size of 4 to 12" << endl;
            cin >> bits;
            bitNum = bits.size();
            if ( bitNum < 4 || bitNum > 12 )
                cout << "Wrong bit size" << endl;
            if ( bitNum %2 != 0)
                cout << "Number does not have an even number of bits" << endl;
        }
    }       

    for ( int i = 0; i < bitNum; i++ )
    {
        if ( bits[i] == '1' )
            multiplicand[i] = 1;
        else
            multiplicand[i] = 0;
        multiplicandNum++;
    }
    
    reverse(multiplicand, multiplicand + multiplicandNum); 

    // copy multiplicand to tempNum 
    for (int i = multiplicandNum - 1; i >= 0; i--) 
        tempNum[i] = multiplicand[i];

    twosComplementBits(tempNum, multiplicandNum); 

    bitNum = 0;
    if ( boothType == 0 )
    {
        while ( bitNum < 4 || bitNum > 12 )
        {
            cout << "Enter a number with the bit size of 4 to 12" << endl;
            cin >> bits;
            bitNum = bits.size();
            if ( bitNum < 4 || bitNum > 12 )
                cout << "Wrong bit size" << endl;
        }
    }

    else 
    {
        while ( ( bitNum < 4 || bitNum > 12 ) && (bitNum %2 != 0) )
        {
            cout << "Enter a number with the bit size of 4 to 12" << endl;
            cin >> bits;
            bitNum = bits.size();
            if ( bitNum < 4 || bitNum > 12 )
                cout << "Wrong bit size" << endl;
            if ( bitNum %2 != 0)
                cout << "Number does not have an even number of bits" << endl;
        }
    }

    for ( int i = 0; i < bitNum; i++ )
    {
        if ( bits[i] == '1' )
            multiplier[i] = 1;
        else
            multiplier[i] = 0;
        multiplierNum++;
    }

    reverse( multiplier, multiplier + multiplierNum ); 
}
  
void boothAlgorithm( int multiplicand[], int multiplier[], int tempNum[], int multiplierNum, int shiftBitCounter ) 
{ 
    int qn = 0, accumulator[12] = { 0 }; 
    int temp = 0, counter = 0;
    cout << "qn   ext   multiplicand   accumulator    multiplier   Counter\n"; 
    cout << "            initial        "; 
      
    outputBits(accumulator, multiplier, multiplierNum); 
    cout << "       " << shiftBitCounter << "\n"; 
      
    while ( shiftBitCounter != 0 ) 
    { 
        cout << multiplier[0] << "      " << qn; 
        if ( (qn + multiplier[0]) == 1 ) 
        { 
            if (temp == 0) 
            { 
                addNums(accumulator, tempNum, multiplierNum); 
                counter++; 
                cout << "    ac = ac - mc   "; 
                  
                for (int i = multiplierNum - 1; i >= 0; i--) 
                    cout << accumulator[i]; 

                temp = 1; 
            } 
        
            else if (temp == 1) 
            { 
                // add multiplicand to accumulator 
                addNums( accumulator, multiplicand, multiplierNum ); 
                counter++; 
                cout << "    ac = ac + mc   "; 
                  
                for (int i = multiplierNum - 1; i >= 0; i--) 
                    cout << accumulator[i]; 

                temp = 0; 
            } 

            cout << "\n         "; 
            bitShiftRight( accumulator, multiplier, qn, multiplierNum ); 
            shiftBitCounter--; 
            counter++; 
        } 
        
        else if (qn - multiplier[0] == 0) 
        {
            cout << " ";
            bitShiftRight(accumulator, multiplier, qn, multiplierNum); 
            shiftBitCounter--; 
            counter++; 
        }    
        cout << "   bitShiftRight  "; 
        outputBits(accumulator, multiplier, multiplierNum); 
        cout << "       " << shiftBitCounter << "\n"; 
    } 

    cout << endl << "Result = "; 
    for ( int i = multiplierNum - 1; i >= 0; i-- ) 
        cout << accumulator[i];
    cout << " ";
    for ( int i = multiplierNum - 1; i >= 0; i--  )
        cout << multiplier[i];
    cout << "   Execution Time: " << counter << endl;
} 

void boothAlgorithmExtended(int multiplicand[], int multiplier[], int tempNum[], int multiplierNum, int shiftBitCounter) 
{ 
    int qn = 0, accumulator[12] = { 0 }; 
    int temp = 0, counter = 0;
    
    cout << "qn   ext   multiplicand   accumulator    multiplier   Counter\n"; 
    cout << "            initial        "; 
      
    outputBits(accumulator, multiplier, multiplierNum); 
    cout << "      " << shiftBitCounter << "\n"; 
      
    while ( shiftBitCounter != 0 ) 
    {
        cout << multiplier[0] << "      " << qn;
        if ((qn + multiplier[0]) == 1)
        {
            if (temp == 0)
            {
                addNums(accumulator, tempNum, multiplierNum);
                counter++;
                cout << "    ac = ac - mc   ";

                for (int i = multiplierNum - 1; i >= 0; i--)
                    cout << accumulator[i];

                temp = 1;
            }

            else if (temp == 1)
            {
                // add multiplicand to accumulator
                addNums(accumulator, multiplicand, multiplierNum);
                counter++;
                cout << "    ac = ac + mc   ";

                for (int i = multiplierNum - 1; i >= 0; i--)
                    cout << accumulator[i];

                temp = 0;
            }

            cout << "\n         ";
            bitShiftRight(accumulator, multiplier, qn, multiplierNum);
            shiftBitCounter--;
            counter++; 
        }

        else if (qn - multiplier[0] == 0)
        {
            cout << " ";
            bitShiftRight(accumulator, multiplier, qn, multiplierNum);
            shiftBitCounter--;
            counter++;
        }
        cout << "   bitShiftRight  ";
        outputBits(accumulator, multiplier, multiplierNum);
        cout << "       " << shiftBitCounter << "\n";    
    } 

    cout << endl << "Result = ";
    for ( int i = multiplierNum - 1; i >= 0; i-- ) 
        cout << accumulator[i];
    cout << " ";    
    for ( int i = multiplierNum - 1; i >= 0; i--  )
        cout << multiplier[i];
    cout << "   Execution Time: " << counter << endl;
} 