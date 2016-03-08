#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
void swap( T *val1, T *val2 )
{
    T temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

bool IsOdd( int val )
{
    return ( val & 0x1 );
}

void Reorder( int array[], int length, bool (*func)(int) )
{
    if ( NULL == array || length <= 0 )
        throw "bad input.";

    int left = 0, right = length - 1;
    while ( left < right )
    {
        while ( left < right && func(array[left]) )
            ++left;
        while ( left < right && !func(array[right]) )
            --right;

        if ( left < right )
            swap( &array[left], &array[right] );
    }
}

void print( int array[], int length )
{
    for ( int i = 0; i < length; ++i )
        cout << array[i] << '\t';
    cout << endl;
}

int main() {
    cout << "Hello, World!" << endl;

    int array[] = { 1, 2, 3, 4, 5 };
    Reorder( array, 5, IsOdd );
    print( array, 5 );

    int array2[] = { 2, 4, 6, 8, 10 };
    Reorder( array, 5, IsOdd );
    print( array2, 5 );

    int array3[] = { 1, 3, 5, 7, 9 };
    Reorder( array, 5, IsOdd);
    print( array3, 5 );

    system("PAUSE");
    return 0;
}