//
// Created by Administrator on 2016/3/24.
//

#ifndef INC_46_ACCUMULATE_B_H
#define INC_46_ACCUMULATE_B_H


#include "A.h"

extern A* Array[2];

class B: public A {

public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n-1) + n;
    }

};


#endif //INC_46_ACCUMULATE_B_H
