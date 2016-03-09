#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

bool IsPushAndPopOrder( const int *pushSerial, const int lengthOfPush, int *popSerial, int lengthOfPop )
{
    if ( NULL == pushSerial || NULL == popSerial
            || lengthOfPush <= 0 || lengthOfPop <= 0 )
        throw "Invalid input. ";

    bool result = false;
    if ( lengthOfPop != lengthOfPush )
        result = false;
    else
    {
        stack<int> Stack;
        int indexOfPush = 0, indexOfPop = 0;
        while( indexOfPop < lengthOfPop )
        {
            if ( Stack.empty() || popSerial[indexOfPop] != Stack.top() )
            {
                while( pushSerial[indexOfPush] != popSerial[indexOfPop] && indexOfPush < lengthOfPush )
                    Stack.push( pushSerial[indexOfPush++] );
                if ( indexOfPush == lengthOfPush )
                {
                    result = false;
                    break;
                }
                else
                {
                    indexOfPop++;
                    indexOfPush++;
                }
            }
            else
            {
                Stack.pop();
                indexOfPop++;
            }
        }
        if ( indexOfPop == lengthOfPop )
            result = true;
    }
    return result;
}

int main() {
    cout << "Hello, World!" << endl;

    int pushSerial[] = { 1, 2, 3, 4, 5 };
    int popSerial[] = { 4, 3, 5, 2, 1 };

    cout << IsPushAndPopOrder( pushSerial, 5, popSerial, 5 ) << endl;

    system("PAUSE");
    return 0;
}