//
// Created by Administrator on 2016/3/2.
//

#include <stddef.h>
#include "BinaryTree.h"

BNode Construct( int preOrder[], int lengthOfPre, int midOrder[], int lengthOfMid )
{
    //验证参数有效性
    if ( preOrder == NULL || midOrder == NULL || lengthOfPre != lengthOfMid
            || lengthOfPre == 0 )
        return NULL;

    //以前序的第一个值为根
    int root = *preOrder, lengthOfLeft = 0, lengthOfRight = 0;
    while ( lengthOfLeft < lengthOfMid && midOrder[lengthOfLeft] != root )
    {
            lengthOfLeft++;
    }
    //如果lengthOfLeft到达了边界以外，证明该节点不存在，返回
    if ( lengthOfLeft >= lengthOfMid )
        return NULL;
    lengthOfRight = lengthOfMid - lengthOfLeft - 1;

    //建立根节点，并递归的建立左右子树
    BNode RootNode = new BinaryTreeNode();
    RootNode->m_nValue = root;
    RootNode->m_pLeft = Construct( preOrder+1, lengthOfLeft, midOrder, lengthOfLeft );
    RootNode->m_pRight = Construct( preOrder+lengthOfLeft+1, lengthOfRight, midOrder+lengthOfLeft+1, lengthOfRight);

    return RootNode;
}
