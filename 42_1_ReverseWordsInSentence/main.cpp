#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void reverseString( char *start, char *end )
{
    if ( NULL == start || NULL == end )
        return;

    char temp;
    while ( start < end )
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void reverseWordsInSentence( char *sentence )
{
    if ( NULL == sentence )
        return;

    //初始化两个指针
    char *start = sentence, *end = sentence;
    while ( *end != '\0' )
        end++;

    //反转整个字符串
    reverseString( start, --end );

    //循环遍历，同时寻找单词进行反转
    start = end = sentence;
    while ( *start != '\0' )
    {
        if ( *start == ' ' )
        {
            start++;
            end++;
        }
        else if ( *end == ' ' || *end == '\0' )
        {
            reverseString( start, --end );
            end++;
            start = end;
        }
        else
        {
            end++;
        }
    }

}

int main() {
    cout << "Hello, World!" << endl;

    char input[100];
    while ( gets(input ) )
    {
        reverseWordsInSentence( input );
        cout << input << endl;
    }

    system("PAUSE");
    return 0;
}