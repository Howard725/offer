//
// Created by Administrator on 2016/3/2.
//

#ifndef PRINTLISTREVERSELY_LIST_H
#define PRINTLISTREVERSELY_LIST_H

struct ListNode;
typedef ListNode *Node;

void AddToTail( Node* pHead, int value );
void RemoveNode( Node* pHead, int value );
void PrintReversely( Node* pHead );

struct ListNode{
    int m_nKey;
    Node m_pNext;
};

#endif //PRINTLISTREVERSELY_LIST_H
