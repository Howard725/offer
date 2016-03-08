#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode** ReverseList( ListNode **pListHead )
{
    if ( NULL == pListHead || NULL == *pListHead )
        return NULL;
    if ( (*pListHead)->m_pNext == NULL )
        return pListHead;

    ListNode *pPrevious = NULL;
    ListNode *pMiddle = *pListHead;
    ListNode *pNext = NULL;
    while ( pMiddle != NULL )
    {
        pNext = pMiddle->m_pNext;
        pMiddle->m_pNext = pPrevious;

        if ( pNext == NULL )
            return &pMiddle;

        pPrevious = pMiddle;
        pMiddle = pNext;
    }
/*    ListNode *pNext = pMiddle->m_pNext;
    while ( pNext )
    {
        pMiddle->m_pNext = pPrevious;

        pPrevious = pMiddle;
        pMiddle = pNext;
        pNext = pNext->m_pNext;
    }
    pMiddle->m_pNext = pPrevious;
    return &pMiddle;*/
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

    ListNode *node1 = new ListNode();
    ListNode *node2 = new ListNode();
    ListNode *node3 = new ListNode();
    ListNode *node4 = new ListNode();
    ListNode *node5 = new ListNode();

    node1->m_nValue = 1, node1->m_pNext = node2;
    node2->m_nValue = 2, node2->m_pNext = node3;
    node3->m_nValue = 3, node3->m_pNext = node4;
    node4->m_nValue = 4, node4->m_pNext = node5;
    node5->m_nValue = 5, node5->m_pNext = NULL;

    print(&node1);

    ListNode **reversedHead = ReverseList( &node1 );
    print(reversedHead);


    system("PAUSE");
    return 0;
}