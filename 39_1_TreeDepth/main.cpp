#include <iostream>

using namespace std;

struct TreeNode
{
    int _value;
    TreeNode* _pLeft;
    TreeNode* _pRight;
};

int Max( int val1, int val2 )
{
    return val1 > val2 ? val1 : val2;
}

int depthOfTree( TreeNode *root )
{
    if ( NULL == root )
        return 0;

    int leftDepth = depthOfTree( root->_pLeft );
    int rightDepth = depthOfTree( root->_pRight );

    return Max( leftDepth, rightDepth ) + 1;
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}