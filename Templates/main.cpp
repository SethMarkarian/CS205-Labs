#include <iostream>
#include <stackt.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    StackT<int> tester;
    tester.push(1);
    tester.push(2);
    tester.push(3);
    std::string tester_string = tester.toStack();
    std::cout << tester_string << endl << "size: " << std::to_string(tester.size()) << endl;
    tester.push(4);
    tester.push(5);
    tester.push(6);
    tester.push(7);
    tester.push(8);
    tester.push(9);
    tester.push(10);
    tester.push(11); // this is to ensure it will go beyond a size of 10
    tester_string = tester.toStack();
    std::cout << tester_string << endl << "size: " << std::to_string(tester.size()) << endl;
    return 0;
}
