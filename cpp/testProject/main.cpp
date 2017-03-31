#include <iostream>

void printFcn(int val)
{
    std::cout << "Int printed is " << val << std::endl;
}

void printFcn(float val)
{
    std::cout << "Float printed is " << val << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    printFcn(3);
    //printFcn(3.14); // fails: ambiguous call.
    printFcn((float)3.14);

    return 0;
}