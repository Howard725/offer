//
// Created by Administrator on 2016/3/24.
//

#ifndef INC_46_ACCUMULATE_TEMP_H
#define INC_46_ACCUMULATE_TEMP_H


class Temp {

public:
    Temp(){
        ++n;
        sum += n;
    }

    static void reset(){
        sum = 0;
        n = 0;
    }

    static unsigned int getSum(){
        return sum;
    }

private:
    static unsigned int sum;
    static unsigned int n;

};


#endif //INC_46_ACCUMULATE_TEMP_H
