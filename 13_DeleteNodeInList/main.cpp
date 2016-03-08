#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void DeleteNode( ListNode ** pListHead, ListNode* pToBeDeleted )
{
    if ( NULL == pListHead || NULL == pToBeDeleted )
        throw "invalid input.";

    //是否为头结点
    if ( pToBeDeleted == *pListHead )
    {
        *pListHead = pToBeDeleted->m_pNext;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
    else if ( NULL == pToBeDeleted->m_pNext ) //是否为未结点
    {
        ListNode *temp = *pListHead;
        while( temp->m_pNext != pToBeDeleted )
        {
            temp = temp->m_pNext;
        }
        temp->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
    else//否则为中间结点
    {
        ListNode *temp = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = temp->m_nValue;
        pToBeDeleted->m_pNext = temp->m_pNext;
        delete temp;
        temp = NULL;
    }
}

void print( ListNode ** pListHead )
{
    if ( NULL == pListHead )
        throw "invalid input.";

    ListNode* temp = *pListHead;
    while ( temp != NULL )
    {
        cout << temp->m_nValue << '\t';
        temp = temp->m_pNext;
    }
    cout << endl;
}

int main() {
    cout << "Hello, World!" << endl;

    ListNode *node1 = new ListNode();
    ListNode *node2 = new ListNode();
    ListNode *node3 = new ListNode();
    ListNode *node4 = new ListNode();

    node1->m_nValue = 1, node1->m_pNext = node2;
    node2->m_nValue = 2, node2->m_pNext = node3;
    node3->m_nValue = 3, node3->m_pNext = node4;
    node4->m_nValue = 4, node4->m_pNext = NULL;

    print( &node1 );

    DeleteNode( &node1, node1 );
    print( &node1 );

    DeleteNode( &node1, node3 );
    print( &node1 );

    DeleteNode( &node1, node3 );
    print( &node1 );

    system("PAUSE");
    return 0;
}




























