//
// Created by Administrator on 2016/3/2.
//

#include <iostream>
#include <stack>
#include "List.h"

using namespace std;

Node CreateNode( int value )
{
    Node node = new ListNode();
    if ( node == NULL )
        return NULL;
    else
    {
        node->m_nKey = value;
        node->m_pNext = NULL;
        return node;
    }
}

void AddToTail( Node* pHead, int value )
{
    Node tempNode = new ListNode();
    tempNode->m_nKey = value;
    tempNode->m_pNext = NULL;

    if ( *pHead == NULL )
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

void PrintReversinglyRecursively( const Node Head )
{
    if ( Head == NULL )
        return;
    PrintReversinglyRecursively( Head->m_pNext );
    cout << Head->m_nKey << endl;
}

void PrintReversinglyIteratively( const Node Head )
{
    if ( Head == NULL )
        return;

    stack<Node> nodes;
    Node iter = Head;
    do
    {
        nodes.push(iter);
        iter = iter->m_pNext;
    }while( iter != NULL );

    while( !nodes.empty() )
    {
        iter = nodes.top();
        cout << iter->m_nKey << '\t';
        nodes.pop();
    }
    cout << endl;
}




























