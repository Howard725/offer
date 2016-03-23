#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

int lastNumberInCircle_Math( int n, int m )
{
    if ( n <= 0 || m <= 0 )
        return -1;

    int last = 0;
    for ( int i = 2; i <= n; ++i )
    {
        last = ( last + m ) % i;
    }

    return last;
}

int lastNumberInCircle( int n, int m )
{
    if ( n <= 0 || m <= 0 )
        return -1;

    //初始化链表std::list
    list<int> circle;
    //循环添加n个数字
    for ( int i = 0; i < n; ++i )
        circle.push_back( i );

    //初始化iterator
    list<int>::iterator iter = circle.begin();

    //模拟操作直到链表size<=1
    while ( circle.size() > 1 )
    {
        //循环找到第m个数字
        for ( int i = 1; i < m; ++i )
        {
            iter++;
            if ( iter == circle.end() )
                iter = circle.begin();
        }

        //记录临时位置
        list<int>::iterator temp = ++iter;
        if ( temp == circle.end() )
            temp = circle.begin();
        //删除目标
        --iter;
        circle.erase( iter );
        iter = temp;
    }

    //返回最后一个数字
    return *iter;
}

int main() {
    cout << "Hello, World!" << endl;

    cout << lastNumberInCircle( 5, 3 ) << endl;

    cout << lastNumberInCircle_Math( 5, 3 ) << endl;

    system("PAUSE");
    return 0;
}