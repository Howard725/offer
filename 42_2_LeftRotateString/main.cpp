#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void reverseString( char *start, char *end )
{
    if ( NULL == start || NULL == end )
        return;

    char temp = '\0';
    while ( start < end )
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void leftRotateString( char *String, int index )
{
    if ( NULL == String || index <= 0 )
        return;

    char *start = String, *target = String, *end = String;
    int length = 0;
    while ( *end != '\0' )
    {
        length++;
        end++;
    }
    if ( index > length )
        return;
    else
        target += ( index - 1 );

    reverseString( start, target );
    reverseString( target + 1, --end );
    reverseString( start, end );
}

int main() {
    cout << "Hello, World!" << endl;

    char temp[100];
    while ( gets(temp) )
    {
        leftRotateString( temp, 1 );
        cout << temp << endl;
    }

    system("PAUSE");
    return 0;
}