#include <iostream>

using namespace std;

struct ComplexListNode
{
    int _value;
    ComplexListNode *_pNext;
    ComplexListNode *_pSibling;
};

void CopyNextNode( ComplexListNode* pHead )
{
    if ( NULL == pHead )
        return;
    ComplexListNode* cursor = pHead;
    while (cursor != NULL )
    {
        //新建结点，并复制源节点的内容
        ComplexListNode* newNode = new ComplexListNode();
        newNode->_value = cursor->_value;
        newNode->_pNext = cursor->_pNext;
        newNode->_pSibling = NULL;

        //将源节点的next指针指向新建的节点
        cursor->_pNext = newNode;

        //源节点转为新节点的下一个节点
        cursor = newNode->_pNext;
    }

}

void RestablishSibling( ComplexListNode *pHead )
{
    if ( NULL == pHead )
        return;
    //设置游标
    ComplexListNode* cursor = pHead;
    while ( cursor != NULL )
    {
        //检查是否有sibling，若有建立链接；
        if ( cursor->_pSibling != NULL )
        {
            cursor->_pNext->_pSibling = cursor->_pSibling->_pNext;
        }
        //游标后移两个位置
        cursor = cursor->_pNext->_pNext;
    }

}

//与书上代码不同，理论验证通过
ComplexListNode* GetFinalList( ComplexListNode* pHead )
{
    if ( NULL == pHead )
        return NULL;
    ComplexListNode* newList = pHead->_pNext;
    ComplexListNode* oldCursor = pHead, *newCursor = newList;
    while( 1 )
    {
        oldCursor->_pNext = newCursor->_pNext;
        oldCursor = oldCursor->_pNext;
        if ( newCursor->_pNext != NULL )
        {
            newCursor->_pNext = newCursor->_pNext->_pNext;
            newCursor = newCursor->_pNext;
        }
        else
        {
            break;
        }
    }
    return newList;
}


ComplexListNode* Clone( ComplexListNode* pHead )
{
    if ( NULL == pHead )
        return NULL;

    //沿next指针复制每个节点并插入到相应节点的后面
    CopyNextNode( pHead );
    //重建每个_pSibling指针
    RestablishSibling( pHead );
    //将两个链表分开，返回重建后的头指针
    return GetFinalList( pHead );
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}