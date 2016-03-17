#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int _value;
    BinaryTreeNode *_pLeft;
    BinaryTreeNode *_pRight;
};

bool isBalanced( BinaryTreeNode *root, int *depthOfThis )
{
    if ( NULL == root )
    {
        *depthOfThis = 0;
        return true;
    }

    int depthOfLeft = 0;
    int depthOfRight = 0;
    if ( ! isBalanced( root->_pLeft, &depthOfLeft ) || ! isBalanced( root->_pRight, &depthOfRight ) )
        return false;

    *depthOfThis = 1 + depthOfLeft > depthOfRight ? depthOfLeft : depthOfRight;

    return  depthOfLeft - depthOfRight >= -1 && depthOfLeft - depthOfRight <= 1 ;
}

bool isBalanced( BinaryTreeNode *root )
{
    if ( NULL == root )
        return false;

    int depthOfTree = 0;
    return isBalanced( root, &depthOfTree );
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}