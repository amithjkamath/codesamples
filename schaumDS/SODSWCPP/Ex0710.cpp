//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 7.10 page 142
//  A linked implementation of the List class: List.cpp

template <class T>
class List
{   
  protected:
    class Node
    { public:
        Node(const T& data=T(), Node* prev=0, Node* next=0)
         : _data(data), _prev(prev), _next(next)
        { if (_prev == 0) _prev = this;
          if (_next == 0) _next = this;
        }
        T _data;
        Node* _prev, * _next;
    };
    Node* _;  // dummy node
    int _size;
  public:
    class Iterator
    {   friend class List;
      public:
        Iterator(Node* p) : _(p) { }
        T& operator*() {return _->_data; }
        void operator=(const Iterator& it) {_ = it._; }
        bool operator==(const Iterator& it) {return _ == it._; }
        bool operator!=(const Iterator& it) {return _ != it._; }
        Iterator operator++(int)  // postfix
        { Iterator it(_);
          _ = _->_next;
          return it;
        }
        Iterator& operator++() { _ = _->_next; return *this; }
        Iterator operator--(int)  // postfix
        { Iterator it(_);
          _ = _->_prev;
          return it;
        }
        Iterator& operator--() { _ = _->_prev; return *this; }
      protected:
        List<T>::Node* _;
    };
    List();
    List(const List&);
    List(int);
    List(int,const T&);
    List(Iterator&,Iterator&);
    ~List();
    int size() const;           // returns number of elements
    bool empty() const;         // returns true iff this is empty
    T& front() const;           // returns the first element
    T& back() const;            // returns the last element
    Iterator begin();           // points to first element
    Iterator end();             // points to dummy element
    void push_front(const T&);  // inserts given element in front
    void push_back(const T&);   // inserts given element in back
    void pop_front();           // removes element from front
    void pop_back();            // removes element from back
    Iterator insert(Iterator&,const T&);
    Iterator insert(Iterator&,int,const T&);
    void erase(Iterator&);
    void erase(Iterator&,Iterator&);
    void clear();
    void splice(Iterator,List&,Iterator);
};
template <class T>
List<T>::List() : _size(0)
{ _ = new Node();
}
template <class T>
List<T>::List(const List& l) : _size(l._size)
{ _ = new Node();  // dummy node
  Node* pp = _;
  for (Node* p=l._->_next; p != l._; p = p->_next, pp = pp->_next)
    pp->_next = pp->_next->_prev = new Node(p->_data,_,pp);
}
template <class T>
List<T>::List(int n) : _size(n)
{ _ = new Node();  // dummy node
  Node* p = _;
  for (int i=0; i<n; i++)
    p = p->_prev = new Node(T(),_,p);
  _->_next = p;
}
template <class T>
List<T>::List(int n, const T& t) : _size(n)
{ _ = new Node();  // dummy node
  Node* p = _;
  for (int i=0; i<n; i++)
    p = p->_prev = new Node(t,_,p);
  _->_next = p;
}
template <class T>
List<T>::List(Iterator& it1,Iterator& it2) : _size(0)
{ _ = new Node();  // dummy node
  Node* pp = _;
  for (Node* p=it1._; p != it2._; p = p->_next, pp = pp->_next)
  { pp->_next = new Node(p->_data,pp,_);
    ++_size;
  }
  _->_prev = pp;
}
template <class T>
List<T>::~List()
{ Node* p=_->_next;
  while (p != _)
  { Node* pp = p->_next;
    delete p;
    p = pp;
  }
  delete _;
}
template <class T>
int List<T>::size() const
{ return _size;
}
template <class T>
bool List<T>::empty() const
{ return _size == 0;
}
template <class T>
T& List<T>::front() const
{ return _->_next->_data;
}
template <class T>
T& List<T>::back() const
{ return _->_prev->_data;
}

template <class T>
List<T>::Iterator List<T>::begin()
{ return Iterator(_->_next);
}

template <class T>
List<T>::Iterator List<T>::end()
{ return Iterator(_);
}

template <class T>
void List<T>::push_front(const T& x)
{ _->_next = _->_next->_prev = new Node(x,_,_->_next);
  ++_size;
}

template <class T>
void List<T>::push_back(const T& x)
{ _->_prev = _->_prev->_next = new Node(x,_->_prev,_);
  ++_size;
}

template <class T>
void List<T>::pop_front()
{ Node* p = _->_next;
  _->_next = p->_next;
  p->_next->_prev = _;
  delete p;
  --_size;
}

template <class T>
void List<T>::pop_back()
{ Node* p = _->_prev;
  _->_prev = p->_prev;
  p->_prev->_next = _;
  delete p;
  --_size;
}

template <class T>
List<T>::Iterator List<T>::insert(Iterator& it, const T& x)
{ it._->_prev = it._->_prev->_next = new Node(x,it._->_prev,it._);
  it._ = it._->_prev;
  ++_size;
}

template <class T>
List<T>::Iterator List<T>::insert(Iterator& it, int n, const T& x)
{ Node* p=it._, * q = p->_prev;
  for (int i=0; i<n; i++)
    p = p->_prev = new Node(x,q,p);
  it._ = it._->_prev = q->_next = p;
  _size += n;
}
template <class T>
void List<T>::erase(Iterator& it)
{ if (_size == 0) return;
  Node* p = it._;
  p->_prev->_next = p->_next;
  p->_next->_prev = p->_prev;
  it._ = p->_next;
  delete p;
  --_size;
}
template <class T>
void List<T>::erase(Iterator& it1, Iterator& it2)
{ it1._->_prev->_next = it2._;
  it2._->_prev = it1._->_prev;
  Node* p=it1._->_next;
  while (it1._ != it2._)
  { delete it1._;
    it1._ = p;
    p = p->_next;
    --_size;
  }
}
template <class T>
void List<T>::clear()
{ Node* p=_, * q=p->_next;
  while (q != p)
  { p->_next = q->_next;
    q->_next->_prev = p;
    delete q;
    q = p->_next;
  }
  _size = 0;
}
template <class T>
void List<T>::splice(Iterator it1, List& l, Iterator it2)
{ Node* p=it1._, * pp=it1._->_prev, * q=it2._;
  p->_prev = pp->_next = q;
  q->_prev->_next = q->_next;
  q->_next->_prev = q->_prev;
  q->_prev = pp;
  q->_next = p;
  ++_size;
  --l._size;
}
