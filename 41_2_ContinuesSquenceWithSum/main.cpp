#include <iostream>
#include <stdlib.h>

using namespace std;

void printSequence( int small, int big )
{
    if ( small >= big )
        return;
    for ( int i = small; i <= big; ++i )
        cout << i << '\t';
    cout << endl;
}

void ContinuesSquenceWithSum( int sum )
{
    if ( sum < 3 )
        return;

    //初始化一大一小两个指针
    int small = 1, big = 2;
    //初始化加和变量
    int curSum = small + big;
    //计算循环判定条件
    int mid = ( sum + 1 ) / 2;
    while ( small < mid )
    {
        //增加大指针直到大于目标和
        //等于时直接打印
        if ( curSum == sum )
            printSequence(small, big);

        while ( curSum > sum && small < mid )
        {
            //大于目标和时增加小指针，更新和，直到小于目标和，等于时打印
            curSum -= small;
            small++;

            if ( curSum == sum )
                printSequence( small, big );
        }

        big++;
        curSum += big;
    }


}

int main() {
    cout << "Hello, World!" << endl;

    int sum = 0;
    while ( cin >> sum )
    {
        ContinuesSquenceWithSum( sum );
    }

    system("PAUSE");
    return 0;
}