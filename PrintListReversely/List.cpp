//
// Created by Administrator on 2016/3/2.
//

#include <iostream>
#include "List.h"

void AddToTail( Node* pHead, int value )
{
    Node tempNode = new ListNode();
    tempNode->m_nKey = value;
    tempNode->m_pNext = NULL;

    if ( pHead == NULL )
    {
        *pHead = tempNode;
    }
    else
    {
        Node nodeIndex = *pHead;
        while ( nodeIndex->m_pNext != NULL )
        {
            nodeIndex = nodeIndex->m_pNext;
        }
        nodeIndex->m_pNext = tempNode;
    }
}

void RemoveNode( Node* pHead, int value )
{
    if ( pHead == NULL )
        return;

    Node ToBeDeleted = NULL;
    if ((*pHead)->m_nKey == value )
    {
        ToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        Node node = *pHead;
        while(node->m_pNext != NULL )
        {
            if (node->m_pNext->m_nKey == value )
            {
                ToBeDeleted = node->m_pNext;
                node->m_pNext = ToBeDeleted->m_pNext;
                break;
            }
            node = node->m_pNext;
        }
    }
    if ( ToBeDeleted != NULL )
        delete ToBeDeleted;
}

static void PrintRecursly( const Node list )
{
    if ( list == NULL )
        return;
    PrintRecursly( list->m_pNext );
    cout << list->m_nKey << endl;
}

void PrintReversely( Node* pHead )
{
    if ( pHead == NULL )
        return;
    PrintRecursly( *pHead );
}





























