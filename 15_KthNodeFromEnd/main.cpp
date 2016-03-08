#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* KthNodeFromEnd( ListNode **pListHead, int k )
{
    if ( NULL == pListHead || NULL == *pListHead || k <= 0 )
        return NULL;

    ListNode* p1 = *pListHead;
    ListNode* p2 = *pListHead;
    for ( int i = 0; i < k - 1; ++i )
    {
        if ( ! (p2 = p2->m_pNext) )
            return NULL;
    }
    //两个游标一起移动
    while( p2->m_pNext )
    {
        p1 = p1->m_pNext;
        p2 = p2->m_pNext;
    }
    return p1;
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
    node2->m_nValue = 2, node2->m_pNext = node3;
    node3->m_nValue = 3, node3->m_pNext = node4;
    node4->m_nValue = 4, node4->m_pNext = node5;
    node5->m_nValue = 5, node5->m_pNext = NULL;

    print( &node1 );

    ListNode* res = KthNodeFromEnd( &node1, 2 );
    cout << res->m_nValue << endl;

    res = KthNodeFromEnd( &node1, 5 );
    cout << res->m_nValue << endl;

    res = KthNodeFromEnd( &node1, 0 );
    cout << res->m_nValue << endl;

    system("PAUSE");
    return 0;
}