#include <iostream>
#include <stdlib.h>

using namespace std;

char firstNotRepeatingChar( char* array )
{
    char result = '\0';
    if ( NULL == array )
        return result;
    if ( *array == '\0' )
        return result;

    //初始化哈希表
    int *hashChar = new int[256];
    for ( int i = 0; i < 256; ++i )
        hashChar[i] = 0;

    //遍历字符串填充哈希表
    char* temp = array;
    while ( *temp != '\0' )
    {
        hashChar[*temp]++;
        temp++;
    }

    //再次遍历寻找目标字符
    temp = array;
    while ( *temp != '\0' )
    {
        if ( hashChar[*temp] == 1 )
        {
            result = *temp;
            break;
        }
        temp++;
    }

    //释放资源
    delete[] hashChar;
    return result;

}

int main() {
    cout << "Hello, World!" << endl;

    cout << firstNotRepeatingChar("abcabc") << endl;

    system("PAUSE");
    return 0;
}