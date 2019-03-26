#include <iostream>
#include "binarytreet.h"

using namespace std;

int main()
{
    BinaryTreeT<int> bt = BinaryTreeT<int>();
    bt.insert(5);
    bt.insert(8);
    node * n = bt.search(5);
    bt.destroy();
}
