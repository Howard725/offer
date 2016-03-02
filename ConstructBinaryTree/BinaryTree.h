//
// Created by Administrator on 2016/3/2.
//

#ifndef CONSTRUCTBINARYTREE_BINARYTREE_H
#define CONSTRUCTBINARYTREE_BINARYTREE_H

struct BinaryTreeNode;
typedef struct BinaryTreeNode *BNode;

struct BinaryTreeNode {
    int m_nValue;
    BNode m_pLeft;
    BNode m_pRight;
};

BNode Construct( int preOrder[], int lengthOfPre, int midOrder[], int lengthOfMid );

#endif //CONSTRUCTBINARYTREE_BINARYTREE_H
