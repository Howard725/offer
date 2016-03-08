#include <iostream>
#include <stdlib.h>
#include "CQueue.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    CQueue<string> cQueue;

    cQueue.appendTail( "test1 ");
    cQueue.appendTail( "test2 ");
    cQueue.appendTail( "test3 ");

    for ( int i = 0; i < 2; ++i )
    {
        cout << cQueue.deleteHead() << endl;
    }

    cQueue.appendTail( "test4 ");
    cQueue.appendTail( "test5 ");
    cQueue.appendTail( "test6 ");

    for ( int i = 0; i < 4; ++i )
    {
        cout << cQueue.deleteHead() << endl;
    }

    cout << cQueue.deleteHead() << endl;


    system("PAUSE");
    return 0;
}