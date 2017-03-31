#include <iostream>
#include "Stack.h"

int main() {
    std::cout << "Queue program " << __FILE__ << " compiled on " << __DATE__ << " at " << __TIME__ << std::endl;

    Stack<int> newS = Stack<int>();
    std::cout << " Is Stack empty: " << newS.isempty() << std::endl;
    newS.push(5);
    newS.print();

    std::cout << " Top of the Stack now is: " << newS.peek() << std::endl;
    newS.push(6);
    newS.push(7);
    newS.push(8);
    std::cout << " Top of the Stack now is: " << newS.peek() << std::endl;
    newS.pop();
    std::cout << " Top of the Stack now is: " << newS.peek() << std::endl;
    newS.push(9);
    newS.push(1);
    std::cout << " Is Stack empty: " << newS.isempty() << std::endl;
    newS.print();

    newS.pop();
    newS.print();

    return 0;
}