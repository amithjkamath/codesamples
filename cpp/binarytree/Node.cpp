//
// Created by Amith Kamath on 3/13/17.
//
#include <cstdlib>
#include "Node.h"
#include <iostream>


template <typename T> Node<T>::Node(T data)
{
    _data = data;
    _left = NULL;
    _right = NULL;
}

template <typename T> T Node<T>::getData(void)
{
    return _data;
}

template <typename T> Node<T>* Node<T>::getLeft(void)
{
    return _left;
}

template <typename T> Node<T>* Node<T>::getRight(void)
{
    return _right;
}

template <typename T> void Node<T>::setLeft(Node<T>* pToNode)
{
    _left = pToNode;
}

template <typename T> void Node<T>::setRight(Node<T>* pToNode)
{
    _right = pToNode;
}

template <typename T> void Node<T>::setData(T data)
{
    _data = data;
}

template <typename T> bool Node<T>::hasLeft(void)
{
    return (_left != NULL);
}

template <typename T> bool Node<T>::hasRight(void)
{
    return (_right != NULL);
}

template <typename T> void Node<T>::print(void)
{
    // in order traversal.
    if(hasLeft())
        _left->print();

    std::cout << _data << ", ";

    if(hasRight())
        _right->print();
}

// forward declarations to enable these specializations.
template class Node<int>;
template class Node<float>;