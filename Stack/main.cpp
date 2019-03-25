#include <iostream>
#include "stackt.h"

using namespace std;

int main()
{
    StackT<int> i = StackT<int>();
    i.push(4);
    int j = i.pop();
    i.push(5);
    i.push(6);
    int s = i.size();
}
