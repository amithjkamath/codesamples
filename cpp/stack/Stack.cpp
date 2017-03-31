//
// Created by Amith Kamath on 3/12/17.
//

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Stack.h"

template <typename T> Stack<T>::Stack(void)
{
    _root = NULL;
    _length = 0;
}

template <typename T> T Stack<T>::peek(void) const
{
    if(_root != NULL)
    {
        Node<T>* currentElem = _root;
        for(unsigned long idx = 0; idx < _length-1; idx++)
        {
            currentElem = currentElem->getNext();
        }
        return currentElem->getValue();
    }
    else
    {
        return T(-1);
    }
}

template <typename T> T Stack<T>::pop(void)
{
    if(_root != NULL)
    {
        Node<T>* currentElem = _root;
        for(unsigned long idx = 0; idx < _length-1; idx++)
        {
            currentElem = currentElem->getNext();
        }
        T retVal = currentElem->getValue();
        currentElem->setValue(T());
        currentElem->setNext(NULL);
        delete currentElem;
        _length--;
        return retVal;
    }
    else
    {
        return T(-1);
    }
}

template <typename T> void Stack<T>::push(T elem)
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

template <typename T> unsigned long Stack<T>::size(void) const
{
    return _length;
}

template <typename T> bool Stack<T>::isempty(void) const
{
    return (_length < 1);
}

template <typename T> void Stack<T>::print(void) const
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
template class Stack<int>;
template class Stack<float>;