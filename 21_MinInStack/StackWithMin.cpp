//
// Created by Administrator on 2016/3/9.
//

#include "StackWithMin.h"

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




















