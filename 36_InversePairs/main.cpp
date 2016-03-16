#include <iostream>
#include <stdlib.h>

using namespace std;

int inversePairsRecursively( int* array, int* copy, int start, int end )
{
    if ( NULL == array || NULL == copy || start >= end )
        return 0;
/*    if ( NULL == array || NULL == copy || start > end )
        return 0;
    if ( start == end )
    {
        copy[start] = array[start];
        return 0;
    }*/

    int mid = (start + end ) / 2;

    int leftPairs = inversePairsRecursively(array, copy, start, mid);
    int rightPairs = inversePairsRecursively(array, copy, mid + 1, end );
/*    int leftPairs = inversePairsRecursively(copy, array, start, mid);
    int rightPairs = inversePairsRecursively(copy, array, mid + 1, end );*/

    int count = 0;
    int leftEnd = mid;
    int rightEnd = end;
    int copyIndex = end;
    while ( leftEnd >= start && rightEnd >= mid + 1 )
    {
        if ( array[leftEnd] > array[rightEnd] )
        {
            count += rightEnd - mid;
            copy[copyIndex--] = array[leftEnd--];
        }
        else
        {
            copy[copyIndex--] = array[rightEnd--];
        }
    }

    while ( leftEnd >= start )
        copy[copyIndex--] = array[leftEnd--];
    while ( rightEnd >= mid + 1 )
        copy[copyIndex--] = array[rightEnd--];

    for ( copyIndex = end; copyIndex >= start; --copyIndex )
        array[copyIndex] = copy[copyIndex];

    return leftPairs + rightPairs + count;

}

int inversePairs( int *array, int length )
{
    if ( NULL == array || length <= 0 )
        return 0;

    //初始化copy
    int *copy = new int[ length ];
    for ( int i = 0; i < length; ++i )
        copy[i] = array[i];
    //调用递归获取逆序对，返回
    int count = inversePairsRecursively( array, copy, 0, length - 1 );

    delete[] copy;
    return count;
}

int main() {
    cout << "Hello, World!" << endl;

    int array[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    cout << inversePairs( array, 8 ) << endl;

    system("PAUSE");
    return 0;
}