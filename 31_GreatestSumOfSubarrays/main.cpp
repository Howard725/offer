#include <iostream>
#include <stdlib.h>

using namespace std;

int FindGreatestSumOfSubArray( int* array, int length )
{
    if ( NULL == array || length <= 0 )
        throw "Invalid input.";
    int currentSum = 0;
    int maxSum = 0;
    for ( int i = 0; i < length; ++i )
    {
        if ( currentSum <= 0 )
            currentSum = array[i];
        else
            currentSum += array[i];
        maxSum = currentSum > maxSum ? currentSum : maxSum;
    }
    return maxSum;
}

int main() {
    cout << "Hello, World!" << endl;

//    int array[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
    int array[] = { -1, -2, -3, -10, -4, -7, -2, -5 };
    cout << FindGreatestSumOfSubArray( array, 8 ) << endl;

    system("PAUSE");
    return 0;
}