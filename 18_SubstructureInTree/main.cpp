#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

bool HasSub( BinaryTreeNode *rootA, BinaryTreeNode *rootB )
{
    if ( NULL == rootB )
        return true;
    if ( NULL == rootA )
        return false;

    if ( rootA->m_nValue != rootB->m_nValue )
        return false;

    return HasSub( rootA->m_pLeft, rootB->m_pRight )
            && HasSub( rootB->m_pRight, rootB->m_pRight );
}

bool HasSubtree( BinaryTreeNode *rootA, BinaryTreeNode *rootB )
{
    if ( NULL == rootB )
        return true;
    if ( NULL == rootA )
        return false;

    bool result = false;
    if ( rootA->m_nValue == rootB->m_nValue )
        result = HasSub( rootA->m_pLeft, rootB->m_pLeft )
                    && HasSub( rootA->m_pRight, rootB->m_pRight );
    if ( !result )
        result = HasSubtree( rootA->m_pLeft, rootB );
    if ( !result )
        result = HasSubtree( rootA->m_pRight, rootB );

    return result;
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}