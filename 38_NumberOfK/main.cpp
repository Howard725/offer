#include <iostream>
#include <stdlib.h>

using namespace std;

int getFirstK( int *array, int length, int k, int start, int end )
{
    if ( NULL == array || start > end )
        return -1;

    int mid = ( start + end ) / 2;
    int pos = -1;
    if ( array[mid] < k )
        pos = getFirstK( array, length, k, mid + 1, end );
    else if ( array[mid] == k && ( mid == 0 || array[mid-1] != k ) )
        pos = mid;
    else
        pos = getFirstK( array, length, k, start, mid - 1 );

    return pos;
}

int getLastK( int *array, int length, int k, int start, int end )
{
    if ( NULL == array || start > end )
        return -1;

    int mid = ( start + end ) / 2;
    int pos = -1;
    if ( array[mid] > k )
        pos = getLastK( array, length, k, start, mid - 1 );
    else if ( array[mid] == k && ( mid == length - 1 || array[mid+1] != k ) )
        pos = mid;
    else
        pos = getLastK( array, length, k, mid + 1, end );

    return pos;
}

int numberOfK( int* array, int length, int k )
{
    if ( NULL == array )
        return -1;

    //二分找到第一个K
    int startPos = getFirstK( array, length, k, 0, length - 1 );
    //二分找到最后一个K
    int endPos = getLastK( array, length, k, 0, length - 1 );
    //返回K的个数
    if ( startPos == -1 || endPos == -1 )
        return -1;
    else
        return endPos - startPos + 1;
}

int main() {
    cout << "Hello, World!" << endl;

    int array[] = { 1 };

    cout << numberOfK( array, 1, 1 ) << endl;

    system("PAUSE");
    return 0;
}