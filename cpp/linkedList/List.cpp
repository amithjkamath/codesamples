//
// Created by Amith Kamath on 3/1/17.
//
#include <iostream>
#include "List.h"

template <typename ElemType>
List<ElemType>::List(unsigned long numElements, ElemType defaultValue)
{
    // create a list with numElements elements, default values being 0.
    if(numElements <= 0)
    {
        _root = NULL;
        _length = 0;
    }

    this->_root = new Node<ElemType>;
    _root->setValue(defaultValue);
    Node<ElemType>* currentElem = this->_root;
    for(unsigned long i = 0; i <  numElements-1; i++)
    {
        Node<ElemType>* nextNode = new Node<ElemType>;
        nextNode->setValue(defaultValue);
        currentElem->setNext(nextNode);
        currentElem = nextNode;
    }
    _length = numElements;
}


template <typename ElemType>
List<ElemType>::List(const ElemType* array, unsigned long numElements)
{
    if(array == NULL)
    {
        _root = NULL;
        _length = 0;
        return;
    }
    this->_root = new Node<ElemType>;
    _root->setValue(array[0]);
    Node<ElemType>* currentElem = this->_root;
    for(unsigned long idx = 1; idx < numElements; idx++)
    {
        Node<ElemType>* nextNode = new Node<ElemType>;
        nextNode->setValue(array[idx]);
        currentElem->setNext(nextNode);
        currentElem = nextNode;
    }
    _length = numElements;
}

template <typename ElemType>
List<ElemType> List<ElemType>::operator=(const List<ElemType>& inList)
{
    deleteList();
    this->_root = new Node<ElemType>;
    Node<ElemType>* currentNode = _root;
    for(unsigned long idx = 0; idx < inList.size(); idx++)
    {
        currentNode->setValue(inList.elementAt(idx));
        Node<ElemType>* nextNode = new Node<ElemType>;

        currentNode->setNext(nextNode);
        currentNode = nextNode;
    }
    _length = inList.size();
    return *this;
}

template <typename ElemType>
unsigned long List<ElemType>::size(void) const
{
    return _length;
}

template <typename ElemType>
ElemType List<ElemType>::elementAt(unsigned long position) const
{
    if((position < 0) || (position > _length))
    {
        return INT_MIN;
    }

    Node<ElemType>* currentElem = _root;
    for(unsigned long idx = 0; idx < _length; idx++)
    {
        if(idx == position)
        {
            return currentElem->getValue();
        }
        else
        {
            currentElem = currentElem->getNext();
        }
    }
    return INT_MIN;
}

template <typename ElemType>
ElemType List<ElemType>::operator[](unsigned long indx) const
{
    return elementAt(indx);
}

template <typename ElemType>
void List<ElemType>::replaceAt(unsigned long position, ElemType value)
{
    if((position < 0) || (position > _length))
        return;
    Node<ElemType>* currentElem = _root;
    for(unsigned long idx = 0; idx < _length; idx++)
    {
        if(position == idx)
        {
            currentElem->setValue(value);
            break;
        }
        currentElem = currentElem->getNext();
    }
}

template <typename ElemType>
void List<ElemType>::addElementAt(unsigned long position, ElemType value)
{
    if((position < 0 || (position > _length)))
    {
        return;
    }

    Node<ElemType>* currentElem = _root;
    for(unsigned long i = 0; i < _length; i++)
    {
        if(i == (position-1))
        {
            Node<ElemType>* newElem = new Node<ElemType>;
            newElem->setValue(value);
            Node<ElemType>* nextElem = currentElem->getNext();
            currentElem->setNext(newElem);
            newElem->setNext(nextElem);
            _length++;
            break;
        }
        else
        {
            currentElem = currentElem->getNext();
        }
    }
}

template <typename ElemType>
List<ElemType>* List<ElemType>::subList(unsigned long start, unsigned long end)
{
    if(end < start)
    {
        return NULL;
    }
    else
    {
        unsigned long len = (end-start);
        List<ElemType>* newList = new List<ElemType>(len, 0);

        for(unsigned long idx = start; idx < end; idx++)
        {
            ElemType val = elementAt(idx);
            newList->replaceAt(idx-start, val);
        }
        return newList;
    }
}

template <typename ElemType>
void List<ElemType>::print(unsigned long position)
{
    std::cout << "List{" << position << "} = " << elementAt(position) << std::endl;
}

template <typename ElemType>
void List<ElemType>::print(void)
{
    Node<ElemType>* currentElem = _root;
    std::cout << "{ ";
    for(unsigned long idx = 0; idx < _length; idx++)
    {
        std::cout << currentElem->getValue() << ", ";
        currentElem = currentElem->getNext();
    }
    std::cout << "}"<< std::endl;
}

template <typename ElemType>
bool List<ElemType>::removeElementAt(unsigned long position)
{
    if(position < 0 || position > _length)
    {
        return false;
    }
    Node<ElemType>* currentElem = _root;
    // special case removing the root
    if(position == 0)
    {
        Node<ElemType>* oldRoot = _root;
        _root = _root->getNext();
        delete oldRoot;
        _length--;
        return true;
    }
    for(unsigned long idx = 0; idx < _length; idx++)
    {
        if(idx == (position - 1))
        {
            Node<ElemType>* toRemove = currentElem->getNext();
            currentElem->_next = toRemove->getNext();
            delete toRemove;
            _length--;
            return true;
        }
        else
        {
            currentElem = currentElem->getNext();
        }
    }
    return false;
}

template <typename ElemType>
void List<ElemType>::deleteList(void)
{
    Node<ElemType>* currentElem = _root;
    Node<ElemType>* nextElem;
    for(unsigned long idx = 0; idx < _length; idx++)
    {
        nextElem = currentElem->getNext();
        delete currentElem;
        currentElem = nextElem;
    }
}

template <typename ElemType>
List<ElemType>::~List()
{
    deleteList();
}

// Explicit template instantiations,
// This is needed because the implementations are in a different file (here)
// than the declaration (the header file). Due to this, only int and float
// instantiations will work. All other List<T> instantiations will fail.
template class List<int>;
template class List<float>;