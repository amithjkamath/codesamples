//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  PriorityQueue.h
//  Interface and implementation of a PriorityQueue class template
//  Contiguous implementation

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class PriorityQueue
{ public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue&);
    ~PriorityQueue();
    PriorityQueue& operator=(const PriorityQueue&);
    int size() const;          // returns number of elements
    bool empty() const;        // returns true iff this is empty
    const T& top() const;      // returns the front element
    void push(const T&);       // inserts given element at back
    void pop();                // removes element from front
  protected:
    vector<T> _;               // dynamic array for queue elements
    void heapifyDown();        // restores the heap property
    void heapifyUp();          // restores the heap property
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{ 
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& q) : _(q._)
{ 
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{ 
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue& q)
{ _ = q._;
}

template <class T>
int PriorityQueue<T>::size() const
{ return _.size();
}

template <class T>
bool PriorityQueue<T>::empty() const
{ return _.empty();
}

template <class T>
const T& PriorityQueue<T>::top() const
{ return _.front();
}

template <class T>
void PriorityQueue<T>::pop()
{ _.front() = _.back();  // delete the front element 
  _.pop_back();          // move the back element to the front
  heapifyDown();         // restore the heap property
}

template <class T>
void PriorityQueue<T>::push(const T& x)
{ _.push_back(x);        // insert the new element at the back
  heapifyUp();           // restore the heap property
}

template <class T>
void PriorityQueue<T>::heapifyDown()
{ int n=_.size(), j;
  for (int i=0; i<n/2; i=j)
  { j=2*i+1;              // _[j] and _[j+1] are the children of _[i]
    if (j<n && _[j]<_[j+1]) ++j;
    if (_[i] >= _[j]) break;
    swap(_[i],_[j]);
  } 
}

template <class T>
void PriorityQueue<T>::heapifyUp()
{ int n=_.size(), i;
  for (int j=n-1; j>0; j=i)
  { i=(j-1)/2;            // _[i] is the parent of _[j]
    if (_[j] <= _[i]) break;
    swap(_[j],_[i]);
  } 
}

#endif  // PRIORITY_QUEUE_H
