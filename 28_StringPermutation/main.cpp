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


int main() {
    cout << "Hello, World!" << endl;

    char test[] = "";

    Permutation( test );

    system("PAUSE");
    return 0;
}



















