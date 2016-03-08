#include <iostream>
#include <stdlib.h>

using namespace std;

long long Fibonacci( int n )
{
    if ( n < 0 )
        throw "bad input";

    int res[2] = {0, 1};
    if ( n <= 1 )
        return res[n];

    long long result = 0;
    long long N_1 = 1, N_2 = 0;
    for ( int i = 2; i <= n; ++i )
    {
        result = N_1 + N_2;
        N_2 = N_1;
        N_1 = result;
    }
    return result;
}

int Fibonacci_bad(int n)
{
    if ( n <= 0 )
        return 0;
    if ( n == 1 )
        return 1;
    return Fibonacci_bad(n - 1) + Fibonacci_bad(n - 2);
}

int main() {
    cout << "Hello, World!" << endl;
    cout << Fibonacci(6) << endl;

    system("PAUSE");
    return 0;
}