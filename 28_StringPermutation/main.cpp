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

void Combination( char* pStr, char* pBegin, int m, int n, char* result, char* resultCurrent )
{
    if ( NULL == pStr || NULL == pBegin || m == 0 || result == NULL || NULL == resultCurrent )
        return;

    if ( n == 0 )
    {
        puts(result);
    }
    else if ( m == n )
    {
        for ( int i = 0; i < m; ++i )
            *resultCurrent++ = *pBegin++;
        *resultCurrent = '\0';
        puts(result);
    }
    else
    {
        Combination( pStr, pBegin+1, m-1, n, result, resultCurrent );
        *resultCurrent++ = *pBegin;
        Combination( pStr, pBegin+1, m-1, n-1, result, resultCurrent );
    }

}

void Combination( char* pStr )
{
    if ( NULL == pStr )
        return;
    int length = strlen( pStr );
    char* result = new char[length+1];
    memset( result, 0, length*sizeof(char) );
    for ( int i = 1; i <= length; ++i )
        Combination( pStr, pStr, length, i, result, result );
    delete[] result;
}


int main() {
    cout << "Hello, World!" << endl;

    char test[] = "abc";

    Permutation( test );

    Combination( test );

    system("PAUSE");
    return 0;
}



















