//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Queue.h
//  Interface and implementation of a Queue class template
//  Contiguous implementation

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class T>
class Queue
{ public:
    Queue();
    Queue(const Queue&);
    ~Queue();
    Queue& operator=(const Queue&);
    int size() const;          // returns number of elements
    bool empty() const;        // returns true iff this is empty
    T& front() const;          // returns the front element
    T& back() const;           // returns the back element
    void push_back(const T&);  // inserts given element at back
    void pop_front();          // removes element from front
  protected:
    T* _;                      // dynamic array for queue elements
    int _front;                // index of front element
    int _size;                 // number of elements in queue
    int _cap;                  // number of elements in array
    static const int _CAP=4;   // initial capacity
    void rebuild();            // moves all elements to new array
};

template <class T>
Queue<T>::Queue() : _(new T[_CAP]), _front(0), _size(0), _cap(_CAP)
{ 
}

template <class T>
Queue<T>::Queue(const Queue& q)
  : _(new T[q._cap]), _front(q._front), _size(q._size), _cap(q._cap)
{ for (int i=0; i<_cap; i++)
    _[i] = q._[i];
}

template <class T>
Queue<T>::~Queue()
{ delete [] _;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& q)
{ _ = new T[q._cap];
  _front = q._front;
  _size = q._size;
  _cap = q._cap;
  for (int i=0; i<_cap; i++)
    _[i] = q._[i];
}

template <class T>
int Queue<T>::size() const
{ return _size;
}

template <class T>
bool Queue<T>::empty() const
{ return _size == 0;
}

template <class T>
T& Queue<T>::front() const
{ return _[_front];
}

template <class T>
T& Queue<T>::back() const
{ return _[(_front+_size-1)%_cap];
}

template <class T>
void Queue<T>::pop_front()
{ _front = (_front+1)%_cap;
  --_size;
}

template <class T>
void Queue<T>::push_back(const T& x)
{ if (_size == _cap) rebuild();
  _[(_front+_size)%_cap] = x;
  ++_size;
}

template <class T>
void Queue<T>::rebuild()
{ T* temp = new T[2*_cap];
  for (int i=0; i<_size; i++)
    temp[i] = _[(_front+i)%_cap];
  delete [] _;
  _ = temp;
  _front = 0;
  _cap *= 2;  // double the capacity of the storage array
}

#endif  // QUEUE_H
