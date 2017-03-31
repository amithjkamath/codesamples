#include <iostream>
#include "heap.h"


int main() {
    std::cout << __FILE__ << " compiled on " << __DATE__ << " and " << __TIME__ << std::endl;

    int array[] = {5, 2, 9, 10, 4, 8, 4, 6, 8};

    heap thisheap(array, 9);

    thisheap.printlinear();

    std::cout << "Max: " << thisheap.max() << std::endl;

    return 0;
}