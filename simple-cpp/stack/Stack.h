//
// Created by Amith Kamath on 3/12/17.
//

#ifndef BASIC_STACK_H
#define BASIC_STACK_H

#include "Node.h"

template <class T>
class Stack
{
public:
    Stack(void);

    T peek(void) const;
    T pop(void);
    void push(T);
    unsigned long size(void) const;
    bool isempty(void) const;

    void print(void) const;

private:
    Node<T>* _root;
    unsigned long _length;
};


#endif //BASIC_STACK_H
