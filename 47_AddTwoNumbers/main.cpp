#include <iostream>
#include <stdlib.h>

using namespace std;

int add( int val1, int val2 )
{

    int XOR = 0;
    int AND = 0;

    do
    {
        XOR = val1 ^ val2;
        AND = val1 & val2;
        AND = AND << 1;

        val1 = XOR;
        val2 = AND;
    }while( val2 );

    return val1;
}

int main() {
    cout << "Hello, World!" << endl;

    cout << add( 123, -25 ) << endl;

    system("PAUSE");
    return 0;
}