#include <iostream>
#include <stdlib.h>
#include "CMyString.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    CMyString str1( "this is str1." );
//    CMyString *str1 = new CMyString( "this is str1." );
    //测试复制自身
    str1 = str1;

    CMyString str2,str3;
    str2 = str3 = str1;

    system("PAUSE");
    return 0;
}