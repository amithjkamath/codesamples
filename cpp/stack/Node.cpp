//
// Created by Amith Kamath on 3/1/17.
//

#include "Node.h"
#include <iostream>

template <typename T>
void Node<T>::print(void)
{
    std::cout << "Node: {" << _value << "}" << std::endl;
};

// Forward declaration for allowed types
template class Node<int>;
template class Node<float>;