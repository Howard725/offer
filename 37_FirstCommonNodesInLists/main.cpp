#include <iostream>

using namespace std;

struct ListNode
{
    int _value;
    ListNode* _pNext;
};

int getListLength( ListNode** list )
{
    if ( NULL == list || NULL == *list )
        return 0;

    int lengthOfList = 1;
    ListNode *pHead = *list;
    while ( pHead->_pNext != NULL )
    {
        lengthOfList++;
        pHead = pHead->_pNext;
    }
}

ListNode *firstCommonNode( ListNode** pList1, ListNode** pList2 )
{
    if ( NULL == pList1 || NULL == pList2 || *pList1 == NULL || *pList2 == NULL )
        return NULL;

    int lengthOfList1 = getListLength( pList1 );
    int lengthOfList2 = getListLength( pList2 );

    ListNode *list1 = *pList1, *list2 = *pList2;
    if ( lengthOfList1 > lengthOfList2 )
    {
        int diff = lengthOfList1 - lengthOfList2;
        while ( diff-- )
        {
            list1 = list1->_pNext;
        }
    }
    else if ( lengthOfList2 > lengthOfList1 )
    {
        int diff = lengthOfList2 - lengthOfList1;
        while ( diff-- )
        {
            list2 = list2->_pNext;
        }
    }

    while ( list1 != list2 && list1 != NULL && list2 != NULL )
    {
        list1 = list1->_pNext;
        list2 = list2->_pNext;
    }

    return list1;

}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}