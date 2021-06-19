#include <iostream>
#include "sortalgo.h"
#include "List.h"

using namespace std;

int main() {
    int array[10] = {2, 5, 3, 7, 4, 5, 8, 9, 0, 2};
    List<int> intL = List<int>(array, 10);
    intL.print();
    sortalgo::bubblesort(intL);
    intL.print();

    int anotherArr[9] = {3, 7, 6, 0, 1, 2, 4, 11, 5};
    List<int> anotherL = List<int>(anotherArr, 9);
    anotherL.print();
    sortalgo::insertionsort(anotherL);
    anotherL.print();

    int yetAnotherArr[9] = {3, 7, 6, 0, 1, 2, 4, 11, 5};
    List<int> yetAnotherL = List<int>(yetAnotherArr, 9);
    yetAnotherL.print();
    sortalgo::mergesort(yetAnotherL);
    yetAnotherL.print();

    return 0;
}