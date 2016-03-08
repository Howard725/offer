#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void MirrorRecursively( BinaryTreeNode *root )
{
    if ( NULL == root )
        return;
    if ( NULL == root->m_pLeft && NULL == root->m_pRight )
        return;

    BinaryTreeNode *temp = root->m_pLeft;
    root->m_pLeft = root->m_pRight;
    root->m_pRight = temp;
    temp = NULL;

    if ( root->m_pLeft != NULL )
        MirrorRecursively( root->m_pLeft );
    if ( root->m_pRight != NULL )
        MirrorRecursively( root->m_pRight );
}

//循环实现需要用到栈stack

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}