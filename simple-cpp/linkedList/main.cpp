#include <iostream>
#include "List.h"

int main() {
    std::cout << __FILE__ << " compiled on " << __DATE__ << std::endl;

    int array[10] = {1, 4, 2, 5, 3 ,6, 4, 7, 9, 8};

    List<int> l = List<int>(array, 10);
    l.print();

    l.addElementAt(3, 5);
    l.print();
    l.print(3);

    l.removeElementAt(2);
    l.print();

    List<float> fl = List<float>(5, 4.5);
    fl.print();

    fl.addElementAt(3, 5);
    fl.print();
    fl.print(3);

    fl.removeElementAt(0);
    fl.print();

    return 0;
}