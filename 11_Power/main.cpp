#include <iostream>
#include <stdlib.h>

#define _EPSYLON_POS (0.0000001)
#define _EPSYLON_NEG (-0.0000001)

using namespace std;

bool Equals( double val1, double val2 )
{
    return ( (val1 - val2 > _EPSYLON_NEG) && (val1 - val2 < _EPSYLON_POS) );
}

/*double PowerUnsigned( double base, unsigned int exponent )
{
    double result = 1.0;
    for ( int i = 1; i <= exponent; ++i )
        result *= base;
    return result;
}*/

double PowerUnsigned( double base, unsigned int exponent )
{
    if ( exponent == 0 )
        return 1;
    else if ( exponent == 1 )
        return base;
    else
    {
        double result = 1.0;
        result = PowerUnsigned( base, exponent >> 1 );
        result *= result;
        if ( exponent & 1 )
            result *= base;
        return result;
    }

}

double Power( double base, int exponent )
{
    if ( Equals( base, 0.0 ) && exponent < 0 )
        throw "bad input.";

    unsigned int exponentAbs = ( unsigned int )exponent;
    if ( exponent < 0 )
        exponentAbs = (unsigned int)(-exponent);
    double result = PowerUnsigned( base, exponentAbs );

    if ( exponent < 0 )
        result = 1.0 / result;

    return result;
}

int main() {
    cout << "Hello, World!" << endl;

    cout << Power( 1.1, 5 ) << endl;
    cout << Power( 1.1, 0 ) << endl;
    cout << Power( 1.1, -5 ) << endl;

    cout << Power( -1.1, 5 ) << endl;
    cout << Power( -1.1, -5 ) << endl;
    cout << Power( -1.1, 0 ) << endl;

    cout << Power( 0, 5 ) << endl;
    cout << Power( 0, 0 ) << endl;

    try {
        cout << Power( 0, -5 ) << endl;
    } catch ( const char* ex) {
        cout << ex << endl;
    }


    system("PAUSE");
    return 0;
}



















