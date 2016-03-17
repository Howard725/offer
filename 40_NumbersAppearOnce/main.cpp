#include <iostream>
#include <stdlib.h>

using namespace std;

unsigned int findFirstBit1( int val )
{
    unsigned int index = 0;
    while ( ! (val & 1) && index < 8 * sizeof(int) )
    {
        index++;
        val = val >> 1;
    }
    return index;
}

bool hasFirstBit1( int val, int indexOfFirst1 )
{
    return ( val >> indexOfFirst1 ) & 1;
}

void numbersAppearOnce( int *array, int length, int *num1, int *num2 )
{
    if ( NULL == array || length < 2 )
        throw "Invalid input.";

    unsigned int temp = 0;
    for ( int i = 0; i < length; ++i )
        temp ^= array[i];

    unsigned int indexOfFirst1 = findFirstBit1( temp );

    *num1 = *num2 = 0;
    for ( int i = 0; i < length; ++i )
    {
        if ( hasFirstBit1( array[i], indexOfFirst1 ) )
            *num1 ^= array[i];
        else
            *num2 ^= array[i];
    }
}

int main() {
    cout << "Hello, World!" << endl;

    int num1 = 0, num2 = 0;
    int array[] = { 1,  3 };
    numbersAppearOnce( array, 2, &num1, &num2 );

    cout << "num1: " << num1 << '\t' << "num2: " << num2 << endl;

    system("PAUSE");
    return 0;
}