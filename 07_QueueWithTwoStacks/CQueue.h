//
// Created by Administrator on 2016/3/4.
//

#ifndef INC_07_QUEUEWITHTWOSTACKS_CQUEUE_H
#define INC_07_QUEUEWITHTWOSTACKS_CQUEUE_H

#include <stack>
#include <stddef.h>

using namespace std;

template <typename T>
class CQueue {
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail( const T& node );
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue(void) { }

template <typename T>
CQueue<T>::~CQueue(void) { }

template <typename T>
void CQueue<T>::appendTail( const T &node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if ( stack2.empty() )
    {
        if ( stack1.empty() )
        {
            throw "empty";
        }
        else
        {
            while ( !stack1.empty() )
            {
                T temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }
    }
    T res = stack2.top();
    stack2.pop();
    return res;
}

#endif //INC_07_QUEUEWITHTWOSTACKS_CQUEUE_H
