//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.5 page 118
//  Interface and implementation of a Queue class template
//  Linked implementation

#include <iostream>
using namespace std;

template <class T>
class Queue
{ public:
    Queue();
    Queue(const Queue&);
    ~Queue();
    Queue& operator=(const Queue&);
    int size() const;      // returns number of elements
    bool empty() const;    // returns true iff this is empty
    T& front();            // returns the front element
    T& back();             // returns the back element
    void push(const T&);   // inserts given element at back
    void pop();            // removes element from front
  protected:
    class Node
    { public:
        Node(const T& x, Node* next=0) : _(x), _next(next) {}
        T _;
        Node* _next;
    };
    Node* _front, _back;
    int _size;
};

template <class T> Queue<T>::Queue() : _back(0), _size(0)
{ 
}

template <class T>
Queue<T>::Queue(const Queue& s) : _back(0), _size(s._size)
{ if (_size==0) return;
  Node* pp=0;
  for (Node* p=s._back; p; p = p->_next)
    if (p==s._back) pp = _back = new Node(p->_);
    else pp = pp->_next = new Node(p->_);
}

template <class T> Queue<T>::~Queue()
{ while (_back)
  { Node* p=_back;
    _back = _back->_next;
    delete p;
  }
}

template <class T> int Queue<T>::size() const
{ return _size;
}

template <class T> bool Queue<T>::empty() const
{ return _size == 0;
}

template <class T> T& Queue<T>::front()
{ return _front->_;
}

template <class T> T& Queue<T>::back()
{ return _back->_;
}

template <class T> void Queue<T>::push(const T& x)
{ if (_size==0) _front = _back = new Node(x);
  else _back = _back->_next = new Node(x);
  ++_size;
}

template <class T> void Queue<T>::pop()
{ Node* p=_front;
  _front = _front->_next;
  delete p;
  --_size;
}
