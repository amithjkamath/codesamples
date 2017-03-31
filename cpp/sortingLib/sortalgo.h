//
// Created by Amith Kamath on 3/7/17.
//

#ifndef BASIC_SORTALGO_H
#define BASIC_SORTALGO_H
#include "List.h"

namespace sortalgo
{
    template <typename T> void bubblesort(List<T>&);
    template <typename T> void insertionsort(List<T>&);
    template <typename T> void mergesort(List<T>&);
    template <typename T> void quicksort(List<T>&);
}

#endif //BASIC_SORTALGO_H
