#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int _Value;
    BinaryTreeNode* _pLeft;
    BinaryTreeNode* _pRight;
};

void ConvertNode( BinaryTreeNode* pRoot, BinaryTreeNode** pNewList )
{
    if ( NULL == pRoot )
        return;
    //设置局部指针变量
    BinaryTreeNode* pCurrent = pRoot;
    //若有左节点则遍历左节点
    if ( pCurrent->_pLeft != NULL )
        ConvertNode( pCurrent->_pLeft, pNewList );
    //与newList建立链接，注意是否为空
    pCurrent->_pLeft = *pNewList;
    if ( *pNewList != NULL )
        (*pNewList)->_pRight = pCurrent;
    //移动pNewList
    (*pNewList) = pCurrent;
    //遍历右节点
    if ( pCurrent->_pRight != NULL )
        ConvertNode( pCurrent, pNewList );
}

BinaryTreeNode* Convert( BinaryTreeNode* pRoot )
{
    if ( NULL == pRoot )
        return NULL;
    //set 新的双向链表指针
    BinaryTreeNode* pNewList = NULL;
    //调用递归
    ConvertNode( pRoot, &pNewList );
    //反转双向链表指针到表头
    BinaryTreeNode* pNewListHead = pNewList;
    while ( pNewListHead->_pLeft != NULL )
        pNewListHead = pNewListHead->_pLeft;
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}