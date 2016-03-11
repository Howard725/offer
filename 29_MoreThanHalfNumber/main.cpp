#include <iostream>
#include <stdlib.h>

using namespace std;

bool CheckMoreThanHalf( int* numbers,int length, int result )
{
    if ( NULL == numbers || length <= 0 )
        return false;
    int times = 0;
    for ( int i = 0; i < length; ++i )
    {
        if ( result == numbers[i] )
            times++;
    }
    return times * 2 > length;
}

int MoreThanHalfNum( int* numbers, int length )
{
    if ( NULL == numbers || length <= 0 )
        return 0;
    int result = numbers[0];
    int times = 1;
    for ( int i = 0; i < length; ++i )
    {
        if (times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if ( result == numbers[i] )
            times++;
        else
            times--;
    }
    if ( ! CheckMoreThanHalf( numbers, length, result ))
        return 0;
    return result;
}

int main() {
    cout << "Hello, World!" << endl;

//    int numbers[] = { 1, 2, 2, 3, 5, 6, 7, 2 };
    int numbers[] = { 1, 2, 2, 3, 5, 2, 2, 2 };

    cout << MoreThanHalfNum(numbers, 8) << endl;

    system("PAUSE");
    return 0;
}