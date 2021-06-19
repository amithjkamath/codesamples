//
// Created by Amith Kamath on 3/12/17.
//

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Queue.h"

template <typename T> Queue<T>::Queue(void)
{
    _root = NULL;
    _length = 0;
}

template <typename T> T Queue<T>::peek(void) const
{
    if(_root != NULL)
    {
        return _root->getValue();
    }
    else
    {
        return T(-1);
    }
}

template <typename T> T Queue<T>::dequeue(void)
{
    if(_root != NULL)
    {
        T retVal = _root->getValue();
        Node<T>* root = _root;
        if(root->getNext() != NULL)
        {
            _root = root->getNext();
            root = NULL;
            delete root;
            _length--;
        }
        return retVal;
    }
    else
    {
        return T(-1);
    }
}

template <typename T> void Queue<T>::enqueue(T elem)
{
    Node<T>* currentElem = _root;
    if(_root == NULL)
    {
        Node<T>* newNode = new Node<T>;
        _root = newNode;
        _root->setValue(elem);
        _root->setNext(NULL);
        _length++;
        return;
    }
    for(unsigned long idx = 1; idx < _length; idx++)
    {
        currentElem = currentElem->getNext();
    }
    Node<T>* newNode = new Node<T>;
    newNode->setValue(elem);
    newNode->setNext(NULL);
    currentElem->setNext(newNode);
    _length++;
}

template <typename T> unsigned long Queue<T>::size(void) const
{
    return _length;
}

template <typename T> bool Queue<T>::isempty(void) const
{
    return (_length < 1);
}

template <typename T> void Queue<T>::print(void) const
{
    Node<T>* currentElem = _root;
    std::cout << "{ ";
    for(unsigned long idx = 0; idx < size(); idx++)
    {
        std::cout << currentElem->getValue() << ", ";
        currentElem = currentElem->getNext();
    }
    std::cout << "}"<< std::endl;
}

// declaration of the Queue class.
// Forward declaration for allowed types
template class Queue<int>;
template class Queue<float>;