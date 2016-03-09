#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int _value;
    BinaryTreeNode* _pLeft;
    BinaryTreeNode* _pRight;
};

bool verifySequence( int sequence[], int length )
{
    if ( NULL == sequence || length <= 0 )
        return false;
    if ( length == 1 )
        return true;

    int root = sequence[ length - 1 ];
    int right = 0, left = 0;
    while ( sequence[left] < root && left < length - 1 ) left++;
    for ( right = left; right < length - 1; ++right )
    {
        if ( sequence[right] < root )
            return false;
    }

    bool result = true;
    if ( left > 0 )
        result = result && verifySequence( sequence, left );
    if ( length - 1 - left > 0 )
        result = result && verifySequence( sequence + left , length - 1 - left );

    return result;

}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}