#include "value.h"

Value::Value()
{
    cnt = 0;
}

Value::~Value() {

    std::cout << "bye!" << std::endl;
}

int  Value::get() {
    return cnt;
}

Value Value::operator++(int) {
    cnt++;
    return *this;
}

Value Value::operator--(int) {
    cnt--;
    return *this;
}

void Value::operator=(int value) {
    cnt = value;
}

