#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void Permutation( char* pStr, char* pBegin )
{
    if ( NULL == pStr || NULL == pBegin )
        return;
    if ( *pBegin == '\0' )
    {
        puts(pStr);
        cout << endl;
    }
    else
    {
        char* index = pBegin;
        for ( ; *index != '\0'; ++index )
        {
            char temp = *index;
            *index = *pBegin;
            *pBegin = temp;

            Permutation( pStr, pBegin+1 );

            temp = *index;
            *index = *pBegin;
            *pBegin = temp;
        }
    }

}

void Permutation( char* pStr ) {
    if (NULL == pStr)
        return;
    Permutation(pStr, pStr);
}

void Combination( char* pStr, int length, int n, char* result )
{

}

void Combination( char* pStr )
{
    if ( NULL == pStr )
        return;
    int length = strlen( pStr );
    char* result = new char[length];
    memset( result, 0, length*sizeof(int) );
    for ( int i = 1; i <= length; ++i )
        Combination( pStr, pBegin, length, i, result );
    delete [] result;
}


int main() {
    cout << "Hello, World!" << endl;

    char test[] = "";

    Permutation( test );

    system("PAUSE");
    return 0;
}



















