//
// Created by Administrator on 2016/3/9.
//

#ifndef INC_21_MININSTACK_STACKWITHMIN_H
#define INC_21_MININSTACK_STACKWITHMIN_H

#include <stack>

#define STACK_MAX_SIZE ( 100 )

using namespace std;

template <typename T>
class StackWithMin {
public:
    StackWithMin( int size = STACK_MAX_SIZE );
    ~StackWithMin() {};
    bool IsEmpty() const { return _size <= 0; }
    bool IsFull() const { return _size >= _capacity; }
    void push( const T val );
    void pop();
    const T& top() const ;
    const T& min() const ;

private:
    stack<T> _dataStack;
    stack<T> _minStack;
    int _capacity;
    int _size;
};

template <typename T>
StackWithMin<T>::StackWithMin( int size )
{
    if ( size <= 0 )
        throw "too small size.";

    _capacity = size;
    _size = 0;
}

template <typename T>
void StackWithMin<T>::push( const T val )
{
    if ( IsFull() )
        throw "Stack is full.";

    _dataStack.push( val );

    T temp;
    if ( _size <= 0 )
        temp = val;
    else
    {
        temp = _minStack.top();
        temp = val < temp ? val : temp;
    }
    _minStack.push( temp );

    _size++;
}

template <typename T>
void StackWithMin<T>::pop()
{
    if ( IsEmpty() )
        throw "Stack is empty.";

    _dataStack.pop();
    _minStack.pop();
    _size--;
}

template <typename T>
const T& StackWithMin<T>::top() const
{
    if ( IsEmpty() )
        throw "Stack is empty. ";

    return _dataStack.top();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
    if ( IsEmpty() )
        throw "Stack is Empty.";

    return _minStack.top();
}



#endif //INC_21_MININSTACK_STACKWITHMIN_H
