//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.6 page 121
//  Implementing the Queue class with the standard list class

template <class T>
class Queue
{ public:
    Queue();                              // default constructor
    Queue(const Queue&);                     // copy constructor
    ~Queue();                                      // destructor
    Queue& operator=(const Queue&);       // assignment operator
    int size() const;              // returns number of elements
    bool empty();                   // returns true iff is empty
    T& front();                  // returns the element in front
    T& back();                    // returns the element in back
    void push(const T&);        // inserts given element at back
    void pop();                    // removes element from front
  protected:
    list<T> _;                      // vector for queue elements
};

template <class T>
Queue<T>::Queue()
{ 
}

template <class T>
Queue<T>::Queue(const Queue& s) : _(s._)
{ 
}

template <class T>
Queue<T>::~Queue()
{ 
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& s)
{ _ = s._;
}

template <class T>
int Queue<T>::size() const
{ return _.size();
}

template <class T>
bool Queue<T>::empty() const
{ return _.empty();
}

template <class T>
T& Queue<T>::front()
{ return _.front();
}

template <class T>
T& Queue<T>::back()
{ return _.back();
}

template <class T>
void Queue<T>::pop()
{ _.pop_front();
}

template <class T>
void Queue<T>::push(const T& x)
{ _.push_back(x);
}
