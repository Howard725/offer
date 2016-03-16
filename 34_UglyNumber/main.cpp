#include <iostream>
#include <stdlib.h>

using namespace std;

int Min( int val1, int val2, int val3 )
{
    int min = val1;
    min = val2 < min ? val2 : min;
    min = val3 < min ? val3 : min;
    return min;
}

int getUglyNumber( int index )
{
    if ( index <= 0 )
        return -1;
    if ( index == 1 )
        return 1;

    //根据index创建数组
    int *ptrUglyNumber = new int[index];
    ptrUglyNumber[0] = 1;

    //初始化记录位置的三个游标
    int iMulti2 = 0;
    int iMulti3 = 0;
    int iMulti5 = 0;

    //循环计算目标位置的丑数
    for ( int i = 1; i < index; ++i )
    {
        //判断根据三个游标计算出的数字的最小值，并添加到数组中
        int min = Min( ptrUglyNumber[iMulti2] * 2, ptrUglyNumber[iMulti3] * 3, ptrUglyNumber[iMulti5] * 5 );
        ptrUglyNumber[i] = min;
        //更新游标
        while( ptrUglyNumber[iMulti2] * 2 <= ptrUglyNumber[i] && iMulti2 < i )
            iMulti2++;
        while( ptrUglyNumber[iMulti3] * 3 <= ptrUglyNumber[i] && iMulti3 < i )
            iMulti3++;
        while( ptrUglyNumber[iMulti5] * 5 <= ptrUglyNumber[i] && iMulti5 < i )
            iMulti5++;
    }

    //释放资源
    int ugly = ptrUglyNumber[index-1];
    delete []ptrUglyNumber;
    return ugly;
}

int main() {
    cout << "Hello, World!" << endl;

    int n = 0;
    while ( cin >> n )
    {
        cout << getUglyNumber( n ) << endl;
    }

    system("PAUSE");
    return 0;
}