#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

template <typename T>
T Min( T val1, T val2 )
{
    return val1 < val2 ? val1 : val2 ;
}

void PrintMatrixClockwisely( int** matrix, int rows, int columns )
{
    if ( NULL == matrix || rows <= 0 || columns <= 0 )
        return;
    //确定有几个顺时针的循环
    int circle = Min( ( rows + 1 ) / 2, ( columns + 1 ) / 2 );
    for ( int i = 0; i < circle; ++i )
    {
        //分为四步打印
        for ( int j = i; j < columns - i; ++j )
            cout << matrix[i][j] << '\t';
        cout << endl;
        for ( int j = i + 1; j < rows- i; ++j )
            cout << matrix[j][columns-1-i] << '\t';
        cout << endl;
        if ( rows - 1 - i > i )
        {
            for ( int j = columns - i - 2; j > i - 1; --j )
                cout << matrix[rows-1-i][j] << '\t';
            cout << endl;
        }
        if ( i < columns - 1 - i )
        {
            for ( int j = rows - i - 2; j > i; --j )
                cout << matrix[j][i] << '\t';
            cout << endl;
        }
    }
}

int **CreateMatrix( int rows, int columns )
{
    if ( rows <= 0 || columns <= 0 )
        throw "invalid input.";
    int **matrix = new int*[rows];
    for ( int i = 0; i < rows; ++i )
    {
        matrix[i] = new int[columns];
        for ( int j = 0; j < columns; ++j )
            matrix[i][j] = i * columns + j;
    }
    return matrix;
}

int main() {
    cout << "Hello, World!" << endl;

    int rows = 1;
    int columns = 1;

    int **matrix = CreateMatrix( rows, columns );

    PrintMatrixClockwisely( matrix, rows, columns);

    system("PAUSE");
    return 0;
}