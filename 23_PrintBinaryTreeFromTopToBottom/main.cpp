#include <iostream>
#include "queue"

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pLeft;
    ListNode *m_pRight;
};

void PrintFromTopToBottom( ListNode *root )
{
    if ( NULL == root )
        return;
    queue<ListNode*> Queue;
    Queue.push( root );
    while( !Queue.empty() )
    {
        ListNode *temp = Queue.front();
        if ( temp->m_pLeft != NULL )
            Queue.push( temp->m_pLeft );
        if ( temp->m_pRight != NULL )
            Queue.push( temp->m_pRight );
        cout << temp->m_nValue << '\t';
        Queue.pop();
    }

}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}