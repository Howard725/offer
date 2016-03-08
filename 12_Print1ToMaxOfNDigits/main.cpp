#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print( char *digits, int length )
{
    if ( NULL == digits || length <= 0 )
        throw "bad invoke.";

    int begin = 0;
    while( digits[begin] == '0' || begin < length )
        begin++;
    puts( digits + begin );
}

void PrintDigitsRecursive( char *digits, int length, int pos )
{
    if ( NULL == digits || length <=0 || pos < 0 )
        throw "bad invoke.";

    if ( pos ==  length - 1 )
    {
        print(digits, length);
        return;
    }
    else
    {
        for ( int i = 0; i < 10; ++i )
        {
            digits[pos+1] = '0' + i;
            PrintDigitsRecursive(digits, length, pos + 1);
        }
        return;
    }
}

void Print1ToMaxOfNDigits( int n )
{
    if ( n <= 0 )
        throw "bad input";

    //创建相应的数组
    char *digits = new char[n+1];
    digits[n] = '\0';

    for ( int i = 0; i < 10; ++i )
    {
        digits[0] = '0' + i;
        PrintDigitsRecursive( digits, n, 0 );
    }

    delete []digits;
}

int main() {
    cout << "Hello, World!" << endl;

    try {
        Print1ToMaxOfNDigits( 2 );
//        Print1ToMaxOfNDigits( 5 );
//        Print1ToMaxOfNDigits( 100 );
        Print1ToMaxOfNDigits( 0 );
        Print1ToMaxOfNDigits( -1 );
    }
    catch (const char * ex)
    {
        cout << ex << endl;
    }


    system("PAUSE");
    return 0;
}



















