//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 5.8 page 102
//  A linked implementation of a Stack class

#include <iostream>
using namespace std;

template <class T>
class Stack
{ public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);
    int size() const;     // returns number of elements
    bool empty() const;   // returns true iff this is empty
    T& top() const;       // returns the top element
    void push(const T&);  // inserts given element on top
    void pop();           // removes element from top
  protected:
    class Node
    { public:
        Node(const T& data, Node* next=0) : _data(data), _next(next) { }
        T _data;
        Node* _next;
    };
    Node* _top;
    int _size;
};

template <class T>
void print(Stack<T>);          // prints a copy of given stack

int main()
{ Stack<string> s;        print(s);
  s.push("first");   print(s);
  s.push("second");  print(s);
  s.push("third");   print(s);
  s.pop();          print(s);
  s.push("fourth");  print(s);
  s.push("fifth");   print(s);
}

template <class T>
Stack<T>::Stack() : _top(0), _size(0)
{ 
}

template <class T>
Stack<T>::Stack(const Stack& s) : _top(0), _size(s._size)
{ if (_size==0) return;
  Node* pp=0;
  for (Node* p=s._top; p; p = p->_next)
    if (p==s._top) pp = _top = new Node(p->_data);
    else pp = pp->_next = new Node(p->_data);
}

template <class T>
Stack<T>::~Stack()
{ while (_top)
  { Node* p=_top;
    _top = _top->_next;
    delete p;
  }
}

template <class T>
int Stack<T>::size() const
{ return _size;
}

template <class T>
bool Stack<T>::empty() const
{ return _size == 0;
}

template <class T>
T& Stack<T>::top() const
{ return _top->_data;
}

template <class T>
void Stack<T>::pop()
{ Node* p=_top;
  _top = _top->_next;
  delete p;
  --_size;
}

template <class T>
void Stack<T>::push(const T& x)
{ if (_size==0) _top = new Node(x);
  else _top = new Node(x,_top);
  ++_size;
}

template <class T>
void print(Stack<T> s)
{ cout << "size=" << s.size();
  if (s.size()>0)
  { cout << ",\ttop=" << s.top() << ":\t(" << s.top();
    s.pop();
    while (!s.empty())
    { cout << "," << s.top();
      s.pop();
    }
    cout << ")";
  }
  cout << "\n";
}

int main()
{ Stack<string> s;        print(s);
  s.push("first");   print(s);
  s.push("second");  print(s);
  s.push("third");   print(s);
  s.pop();           print(s);
  s.push("fourth");  print(s);
  s.push("fifth");   print(s);
}
