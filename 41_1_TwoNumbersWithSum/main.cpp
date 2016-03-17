#include <iostream>
#include <stdlib.h>

using namespace std;

bool getTwoNumbersWithSum( const int *array, int length, int sum, int *num1, int *num2 )
{
    bool found = false;
    if ( NULL == array || length <= 0 || num1 == NULL || NULL == num2 )
        return found;

    int ahead = length - 1;
    int behind = 0;
    while ( behind < ahead )
    {
        int curSum = array[ahead] + array[behind];
        if ( curSum > sum )
            ahead--;
        else if ( curSum < sum )
            behind++;
        else
        {
            *num1 = array[behind];
            *num2 = array[ahead];
            found = true;
            break;
        }
    }
    return found;
}

int main() {
    cout << "Hello, World!" << endl;

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int num1 = 0, num2 = 0;
    if ( getTwoNumbersWithSum( array, 8, 16, &num1, &num2 ) )
        cout << "num1: " << num1 << '\t' << "num2: " << num2 << endl;
    else
        cout << "not found." << endl;

    system("PAUSE");
    return 0;
}