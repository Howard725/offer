//
// Created by Administrator on 2016/3/9.
//

#ifndef INC_21_MININSTACK_STACKWITHMIN_H
#define INC_21_MININSTACK_STACKWITHMIN_H

#include <stack>

#define STACK_MAX_SIZE ( 100 )

using namespace std;

template <typename T>
class StackWithMin<T> {
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


#endif //INC_21_MININSTACK_STACKWITHMIN_H
