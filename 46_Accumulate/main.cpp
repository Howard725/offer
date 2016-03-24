#include <iostream>
#include <stdlib.h>
#include "Temp.h"
#include "B.h"

using namespace std;

unsigned int Temp::n = 0;
unsigned int Temp::sum = 0;

unsigned int sumSolution1 (const unsigned int n)
{
    Temp::reset();

    Temp *array = new Temp[n];
    delete [] array;
    array = NULL;

    return Temp::getSum();
}

class A;
A* Array[2];

unsigned int sumSolution2 (const unsigned int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    return Array[!!n]->Sum( n );
}

typedef unsigned int (*fun) (unsigned int n);

fun funArray[2];

unsigned int fun0 (unsigned int n )
{
    return 0;
}

unsigned int funN (unsigned int n )
{
    return funArray[!!n](n-1) + n;
}

unsigned int sumSolution3( const unsigned int n )
{
    funArray[0] = fun0;
    funArray[1] = funN;

    return funArray[!!n](n);

}

int main() {
    cout << "Hello, World!" << endl;

    int n = 10;

    cout << sumSolution1( n ) << endl;

    cout << sumSolution2( n ) << endl;

    cout << sumSolution3( n ) << endl;

    system("PAUSE");
    return 0;
}