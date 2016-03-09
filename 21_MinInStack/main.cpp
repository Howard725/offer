#include <iostream>
#include "StackWithMin.h"

using namespace std;

template <typename T>
void checkStack( StackWithMin<T> stack )
{
    cout << "Top: " << stack.top() << endl;
    cout << "Min: " << stack.min() << endl;

    cout << endl;
}

int main() {
    cout << "Hello, World!" << endl;

    int capacity = 3;
    StackWithMin<int> stackWithMin( capacity );
//    stackWithMin.top();
    stackWithMin.push( 5 );
    checkStack( stackWithMin );

    stackWithMin.push( 6 );
    checkStack( stackWithMin );

    stackWithMin.push( 3 );
    checkStack( stackWithMin );

    stackWithMin.push( -1 );
    checkStack( stackWithMin );

    stackWithMin.pop();
    checkStack( stackWithMin );

    stackWithMin.pop();
    checkStack( stackWithMin );

    stackWithMin.pop();
    checkStack( stackWithMin );

    stackWithMin.pop();
    checkStack( stackWithMin );

    stackWithMin.pop();
    checkStack( stackWithMin );

    return 0;
}