//
// Created by Amith Kamath on 3/12/17.
//

#ifndef BASIC_QUEUE_H
#define BASIC_QUEUE_H

#include "Node.h"

template <class T>
class Queue
{
public:
    Queue(void);

    T peek(void) const;
    T dequeue(void);
    void enqueue(T);
    unsigned long size(void) const;
    bool isempty(void) const;

    void print(void) const;

private:
    Node<T>* _root;
    unsigned long _length;
};


#endif //BASIC_QUEUE_H
