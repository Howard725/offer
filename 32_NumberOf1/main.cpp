#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int NumberOf1( const char* number, int length )
{
    if ( NULL == number || length < 0 || *number < '0' || *number > '9' || number[length] != '\0' )
        throw "Invalid input.";

    if ( length == 0 )
        return 0;

    //取最高位
    int first = *number - '0';
    if ( length == 1 )
    {
        if ( first >= 1 )
            return 1;
        else
            return 0;
    }

    //计算1在最高位时出现的次数
    int numOnFirstDigit = 0;
    if ( first > 1 )
    {
        numOnFirstDigit = (int)pow( 10, length - 1 );
    }
    else
    {
        numOnFirstDigit = atoi( number + 1 ) + 1;
    }
    //计算1其他位出现的次数
    int numOnOtherDigits = 0;
    numOnOtherDigits = first * ( length - 1 ) * (int)pow( 10, length - 2 );
    //递归计算剩余的分段
    int numOnLowerDigits = NumberOf1( number + 1, length - 1 );

    //返回上述计算结果的加和
    return numOnFirstDigit + numOnOtherDigits + numOnLowerDigits;
}

int NumberOf1Between1AndN( int n )
{
    if ( n <= 0 )
        return 0;

    char number[50];
    sprintf( number, "%d", n );
    return NumberOf1( number, strlen( number ) );
}

int main() {
    cout << "Hello, World!" << endl;

    int n;
    while ( cin >> n )
        cout << NumberOf1Between1AndN( n ) << endl;

    system("PAUSE");
    return 0;
}