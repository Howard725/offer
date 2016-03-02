#include <iostream>
#include <stdlib.h>

using namespace std;

int CountBlank( char str[], int len, int *length )
{
    int count = 0;

    if ( str != NULL && len > 0 )
    {
        int i = 0;
        *length = 0;
        while( str[i] != '\0' )
        {
            ++(*length);
            if ( str[i] == ' ' )
                ++count;

            ++i;
        }
    }
    return count;
}

void ReplaceBlank( char str[], int len )
{
    //检查参数有效性
    if ( str == NULL || len <= 0 )
        return;

    //获取字符串中的空格数
    int origin_length = 0, cnt_blank = 0;
    cnt_blank = CountBlank( str, len, &origin_length );

    //计算新字符串的长度
    int new_length = origin_length + 2 * cnt_blank;
    if ( origin_length > len )
        return;

    //遍历字符数组，同时替换空格
    int new_tail = new_length, origin_tail = origin_length;
    while( origin_tail >= 0 && new_tail != origin_tail )
    {
        if ( str[origin_tail] != ' ' )
            str[new_tail--] = str[origin_tail];
        else
        {
            str[new_tail--] = '0';
            str[new_tail--] = '2';
            str[new_tail--] = '%';
        }
        origin_tail--;
    }
}


int main() {
    cout << "Hello, World!" << endl;

    const int len = 100;
    char str[len] = "Hello My World.";

    cout << str << endl;

    ReplaceBlank( str, len );

    cout << str << endl;

    system("PAUSE");
    return 0;
}