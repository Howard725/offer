#include <iostream>
#include <stdlib.h>

using namespace std;

int compare( const void *arg1, const void *arg2 )
{
    return *(int*)arg1 - *(int*)arg2;
}

bool isContinousCards( int* number, int length ) {
    if (NULL == number || length <= 0)
        return false;

    //对number进行排序
    qsort(number, length, sizeof(int), compare);

    //从头遍历，计数0以及不连续的空档位置
    int cntOf0 = 0, cntOfGap = 0;
    for (int i = 0; i < length - 1; ++i)
    {
        if ( number[i] == 0 )
            cntOf0++;
        else
        {
            int temp = number[i+1] - number[i] - 1;
            if ( temp < 0 )
                return false;
            else
                cntOfGap += temp;
        }
    }

    //对比计数，得出结论
    return cntOf0 >= cntOfGap;
}

int main() {
    cout << "Hello, World!" << endl;

    int numbers[] = { 1, 0, 5, 3, 0 };

    if ( isContinousCards( numbers, 5 ) )
        cout << "true" << endl;
    else
        cout << "false" << endl;

    system("PAUSE");
    return 0;
}