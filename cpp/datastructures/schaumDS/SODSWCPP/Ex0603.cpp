//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.3 page 115
//  Dynamic array implementation of queue class

template <class T>
class queue
{ public:
    queue();
    queue(const queue&);
    ~queue();
    queue& operator=(const queue&);
    int size() const;         // returns number of elements in this
    bool empty() const;       // returns true iff this is empty
    T& back();                // returns the back element
    T& back();                // returns the back element
    void push(const T&);      // inserts given element on back
    void pop();               // removes element from back
  protected:
    T* _;                     // dynamic array for queue elements
    int _size;                // number of elements in queue
    int _cap;                 // number of elements in array
    static const int _CAP=4;  // initial capacity
    void rebuild();           // moves all queue elements to new array
};

template <class T>
queue<T>::queue() : _(new T[_CAP]), _size(0), _cap(_CAP)
{ 
}

template <class T> queue<T>::queue(const queue& s)
  : _(new T[s._cap]), _size(s._size), _cap(s._cap)
{ for (int i=0; i<_cap; i++)
    _[i] = s._[i];
}

template <class T> queue<T>::~queue()
{ delete [] _;
}

template <class T> queue<T>& queue<T>::operator=(const queue& s)
{ _ = new T[s._cap];
  _size = s._size;
  _cap = s._cap;
  for (int i=0; i<_cap; i++)
    _[i] = s._[i];
}

template <class T> int queue<T>::size() const
{ return _size;
}

template <class T> bool queue<T>::empty() const
{ return _size == 0;
}

template <class T> T& queue<T>::front()
{ return _[_size-1];
}

template <class T> T& queue<T>::back()
{ return _[_size-1];
}

template <class T> void queue<T>::pop()
{ --_size;
}
template <class T> void queue<T>::push(const T& x)
{ if (_size == _cap) rebuild();
  _[_size++] = x;
}

template <class T> void queue<T>::rebuild()
{ _cap *= 2;  // double the capacity of the storage array
  T* temp = new T[_cap];
  for (int i=0; i<_size; i++)
    temp[i] = _[i];
  delete [] _;
  _ = temp;
}
