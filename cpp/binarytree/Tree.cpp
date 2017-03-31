//
// Created by Amith Kamath on 3/13/17.
//

#include <cstdlib>
#include <iostream>
#include <stack>
#include "Tree.h"

template <typename T> Tree<T>::Tree(void)
{
}

template <typename T> Tree<T>::Tree(T* array, unsigned long length)
{
    for(unsigned long idx = 0; idx < length; idx++)
    {
        insert(array[idx]);
    }
}

template <typename T> void Tree<T>::insert(T data)
{
    if(_root == NULL)
    {
        Node<T>* newNode = new Node<T>(data);
        _root = newNode;
        _size++;
    }
    else
    {
        Node<T>* currentNode = _root;
        bool isDone = false;
        while(!isDone)
        {
            if(data < currentNode->getData())
            {
                if(currentNode->hasLeft())
                {
                    currentNode = currentNode->getLeft();
                    continue;
                }
                else
                {
                    Node<T>* newNode = new Node<T>(data);
                    currentNode->setLeft(newNode);
                    _size++;
                    isDone = true;
                }
            }
            else
            {
                if(currentNode->hasRight())
                {
                    currentNode = currentNode->getRight();
                    continue;
                }
                else
                {
                    Node<T>* newNode = new Node<T>(data);
                    currentNode->setRight(newNode);
                    _size++;
                    isDone = true;
                }
            }
        }
    }
}

template <typename T> void Tree<T>::remove(T data)
{
    //TODO
}

template <typename T> bool Tree<T>::hasData(T data) const
{
    Node<T>* node = findBST(data);
    return (node != NULL);
}

template <typename T> Node<T>* Tree<T>::find(T data) const
{
    std::stack<Node<T>*> nodestack;
    nodestack.push(_root);
    while(!nodestack.empty())
    {
        Node<T>* thisNode = nodestack.top();
        nodestack.pop();
        if(thisNode->getData() == data)
            return thisNode;
        if(thisNode->hasRight())
            nodestack.push(thisNode->getRight());
        if(thisNode->hasLeft())
            nodestack.push(thisNode->getLeft());
    }
    return NULL;
}

template <typename T> Node<T>* Tree<T>::findBST(T data) const
{
    Node<T>* currentNode = _root;
    while(currentNode != NULL)
    {
        if(currentNode->getData() == data)
        {
            return currentNode;
        }
        else if(data < currentNode->getData())
        {
            currentNode = currentNode->getLeft();
        }
        else
        {
            currentNode = currentNode->getRight();
        }
    }
    return NULL;
}

template <typename T>
unsigned long Tree<T>::size(void) const
{
    return _size;
}

template <typename T>
void Tree<T>::print(void) const
{
    std::cout << " Tree includes: { ";
    _root->print();
    std::cout << "}" << std::endl;
}


template <typename T> Tree<T>::~Tree(void)
{
    //TODO
}


// forward declaration for these specific specializations.
template class Tree<int>;
template class Tree<float>;