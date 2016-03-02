#include <iostream>
#include <stdlib.h>

using namespace std;

bool find( int* elements, int rows, int columns, int target )
{
    if ( elements != NULL && rows > 0 && columns > 0 )
    {
        int row = 0, col = columns - 1;
        while ( row < rows && col >= 0 )
        {
//            int ref = elements[row][col];
            int ref = elements[ row * columns + col ];
            if ( target < ref )
                --col;
            else if ( target > ref )
                ++row;
            else
                return true;
        }
    }
    return false;
}

int main() {
    cout << "Hello, World!" << endl;

    int elements[][4] = {
            { 1, 2, 8, 9 },
            { 2, 4, 9, 12 },
            { 4, 7, 10, 13 },
            { 6, 8, 11, 15 }
    };

    int target;
    while ( cin >> target )
    {
        bool result = find( (int *) elements, 4, 4, target );
        cout << (result == true ? "true" : "false") << endl;
    }

    system("PAUSE");
    return 0;
}