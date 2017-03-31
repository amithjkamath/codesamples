#include <iostream>
#include "Queue.h"

int main() {
    std::cout << "Queue program " << __FILE__ << " compiled on " << __DATE__ << " at " << __TIME__ << std::endl;

    Queue<int> newQ = Queue<int>();
    std::cout << " Is Queue empty: " << newQ.isempty() << std::endl;
    newQ.enqueue(5);
    newQ.print();

    newQ.enqueue(6);
    newQ.enqueue(7);
    newQ.enqueue(8);
    std::cout << " Top of the Queue now is: " << newQ.peek() << std::endl;

    newQ.dequeue();
    std::cout << " Top of the Queue now is: " << newQ.peek() << std::endl;
    newQ.enqueue(9);
    newQ.enqueue(1);
    std::cout << " Is Queue empty: " << newQ.isempty() << std::endl;
    newQ.print();

    newQ.dequeue();
    newQ.print();

    return 0;
}