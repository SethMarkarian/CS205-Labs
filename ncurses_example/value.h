#ifndef Value_H
#define Value_H

#include <iostream>

class Value
{
private:

    int cnt;

public:
    Value();
    ~Value();

    int  get();
    Value operator++(int);
    Value operator--(int);
    void operator=(int value);
};

#endif // Value_H
