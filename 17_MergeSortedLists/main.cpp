#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode **Merge( ListNode **List1, ListNode **List2 )
{
    if ( ( NULL == List1 || NULL == *List1 ) && ( NULL == List2 || NULL == *List2 ) )
        return NULL;
    else if ( NULL == List1 || NULL == *List1 )
        return List2;
    else if ( NULL == List2 || NULL == *List2 )
        return List1;
    else
    {
        ListNode **Merged = NULL;
        if ((*List1)->m_nValue < (*List2)->m_nValue)
        {
            Merged = List1;
            (*Merged)->m_pNext = *Merge( &((*List1)->m_pNext), List2 );
        }
        else
        {
            Merged = List2;
            (*Merged)->m_pNext = *Merge( List1, &((*List2)->m_pNext) );
        }
        return Merged;
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
    ListNode *node5 = new ListNode();

    node1->m_nValue = 1, node1->m_pNext = node2;
    node2->m_nValue = 3, node2->m_pNext = node3;
    node3->m_nValue = 5, node3->m_pNext = node4;
    node4->m_nValue = 7, node4->m_pNext = node5;
    node5->m_nValue = 9, node5->m_pNext = NULL;

    print(&node1);

    ListNode *node6 = new ListNode();
    ListNode *node7 = new ListNode();
    ListNode *node8 = new ListNode();
    ListNode *node9 = new ListNode();
    ListNode *node0 = new ListNode();

    node6->m_nValue = 2, node6->m_pNext = node7;
    node7->m_nValue = 4, node7->m_pNext = node8;
    node8->m_nValue = 6, node8->m_pNext = node9;
    node9->m_nValue = 8, node9->m_pNext = node0;
    node0->m_nValue = 10, node0->m_pNext = NULL;

    print(&node6);

    ListNode **merged = Merge( &node5, &node0 );

    print(merged);

    system("PAUSE");
    return 0;
}