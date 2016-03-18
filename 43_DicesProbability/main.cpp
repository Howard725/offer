#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int maxValue = 6;

void DicesProbability( int number )
{
    if ( number < 1 )
        return;

    //初始化两个大小为number*maxValue的数组
    unsigned int *arrays[2];
    arrays[0] = new unsigned int[number * maxValue + 1];
    arrays[1] = new unsigned int[number * maxValue + 1];
    //初始化标志位flag，用于标记当前使用的数组
    int flag = 0;
    //初始化第一个骰子可能出现的点数的次数
    for ( int i = 0; i <= maxValue; ++i )
    {
        arrays[flag][i] = 1;
        arrays[1-flag][i] = 0;
    }
    for ( int i = maxValue + 1; i <= number * maxValue; ++i )
    {
        arrays[flag][i] = 0;
        arrays[1-flag][i] = 0;
    }

    //从第二个开始逐个计算可能出现的点出的次数
    for ( int i = 2; i <= number; ++i )
    {
        flag = 1 - flag;
        for ( int j = 0; j < i; ++j )
            arrays[flag][j] = 0;
        //当前和s的范围为i~i*maxValue
        for ( int j = i; j <= i * maxValue; ++j )
        {
            arrays[flag][j] = 0;
            //和为s出现的次数等于s-1 ~ s-6 之和
            for ( int k = 1; k <= maxValue && j - k >= 1; ++k )
                arrays[flag][j] += arrays[1-flag][j-k];
        }
    }

    //计算所有number个骰子的全部可能性
    double totalSum = pow( maxValue, number );

    //计算所有可能出现的点数的概率并打印
    for ( int i = number; i <= maxValue * number; ++i )
    {
        cout << i << ": " << arrays[flag][i] / totalSum << endl;
    }

}

int main() {
    cout << "Hello, World!" << endl;

    int n = 0;
    while (cin >> n)
    {
        DicesProbability( n );
    }

    system("PAUSE");
    return 0;
}