#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
T MinInOrder( T array[], int left, int right )
{
    if ( NULL == array || left > right )
        throw "bad input.";
    T min = array[left];
    for ( int i = left + 1; i <= right; ++i )
    {
        if ( array[i] < min )
            min = array[i];
    }
    return min;
}

template <typename T>
T Min( T array[], int length )
{
    if ( NULL == array || length <= 0 )
        throw "bad input.";

    //初始化游标
    int left = 0, right = length - 1, center = left;
    //initialize min
    T min = array[left];
    //当最左元素小于最右元素时最小元素即为最左元素
    while ( array[left] >= array[right] )
    {
        //如果游标相邻则最小值为右游标
        if ( right - left == 1 )
        {
            min = array[right];
            break;
        }

        //二分搜索
        center = ( left + right ) / 2;
        //如果三个值相等则顺序搜索
        if ( array[left] == array[center] && array[center] == array[right] )
        {
            min = MinInOrder( array, left, right );
            break;
        }

        //否则移动游标，二分
        if ( array[left] <= array[center] )
            left = center;
        else if ( array[center] <= array[right] )
            right = center;

    }

    return min;
}


int main()
{
    cout << "Hello World!" << endl;

    int array1[] = { 2, 2, 3, 4, 7, 0, 1 };
    cout << Min(array1, 7) << endl;
    double array2[] = { 1.0, 1.0, 2, 3, 5, 8, 9 };
    cout << Min(array2, 7) << endl;
    int array3[] = { 1, 1, 1, 1, 0, 1, 2 };
    cout << Min(array3, 7) << endl;


    system("PAUSE");
    return 0;
}