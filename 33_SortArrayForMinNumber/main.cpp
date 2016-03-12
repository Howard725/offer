#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare( const void* numberStr1, const void* numberStr2 )
{
    if ( NULL == numberStr1 || NULL == numberStr2 )
        return 0;
    strcpy(g_StrCombine1, *(const char **) numberStr1);
    strcat(g_StrCombine1, *(const char **) numberStr2);

    strcpy(g_StrCombine2, *(const char **) numberStr2);
    strcat(g_StrCombine2, *(const char **) numberStr1);

    return strcmp( g_StrCombine1, g_StrCombine2 );
}

void PrintMinNumber( int* numbers, int length )
{
    if ( NULL == numbers || length <= 0 )
        return;

    //将numbers转化为字符串数组
//    char** numbersStrs = (char**)(new int[length]);
    char** numbersStrs = new char*[length];
    for ( int i = 0; i < length; ++i )
    {
        numbersStrs[i] = new char[g_MaxNumberLength];
        sprintf( numbersStrs[i], "%d", numbers[i] );
    }
    //将对字符串数组进行排序
    qsort( numbersStrs, length, sizeof(char*), compare );
    //打印字符串数组
    for ( int i = 0; i < length; ++i )
//        printf( "%s", numbersStrs[i] );
        cout << numbersStrs[i];
    cout << endl;

    //释放资源
    for ( int i = 0; i < length; ++i )
        delete[] numbersStrs[i];
    delete [] numbersStrs;
}

int main() {
    cout << "Hello, World!" << endl;

    int numbers[] = { 123, 321, 1, 3, 2 };
//    int numbers[] = { 1 };
    PrintMinNumber( numbers, 5 );

    system("PAUSE");
    return 0;
}