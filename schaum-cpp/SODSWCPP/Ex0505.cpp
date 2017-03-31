//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 5.5 page 97
//  A dynamic array implementation of a Stack class

#include <iostream>
using namespace std;

template <class T>
class Stack
{ public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);
    int size() const;         // returns number of elements in this
    bool empty() const;       // returns true iff this is empty
    T& top() const;           // returns the top element
    void push(const T&);      // inserts given element on top
    void pop();               // removes element from top
  protected:
    T* _;                     // dynamic array for stack elements
    int _size;                // number of elements in stack
    int _cap;                 // number of elements in array
    static const int _CAP=4;  // initial capacity
    void rebuild();           // moves all stack elements to new array
};

template <class T>
void print(Stack<T>);         // prints a copy of given stack

int main()
{ Stack<string> s;   print(s);
  s.push("first");   print(s);
  s.push("second");  print(s);
  s.push("third");   print(s);
  s.pop();           print(s);
  s.push("fourth");  print(s);
  s.push("fifth");   print(s);
  s.push("sixth");   print(s);
}

template <class T>
Stack<T>::Stack() : _(new T[_CAP]), _size(0), _cap(_CAP)
{ 
}

template <class T>
Stack<T>::Stack(const Stack& s)
  : _(new T[s._cap]), _size(s._size), _cap(s._cap)
{ for (int i=0; i<_cap; i++)
    _[i] = s._[i];
}

template <class T>
Stack<T>::~Stack()
{ delete [] _;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& s)
{ _ = new T[s._cap];
  _size = s._size;
  _cap = s._cap;
  for (int i=0; i<_cap; i++)
    _[i] = s._[i];
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
{ return _[_size-1];
}

template <class T>
void Stack<T>::pop()
{ --_size;
}

template <class T>
void Stack<T>::push(const T& x)
{ if (_size == _cap) rebuild();
  _[_size++] = x;
}

template <class T>
void Stack<T>::rebuild()
{ _cap *= 2;  // double the capacity of the storage array
  T* temp = new T[_cap];
  for (int i=0; i<_size; i++)
    temp[i] = _[i];
  delete [] _;
  _ = temp;
}

template <class T>
void print(Stack<T> s)
{ cout << "size=" << s.size();
  if (s.size()>0)
  { cout << ", top=" << s.top() << ": (" << s.top();
    s.pop();
    while (!s.empty())
    { cout << "," << s.top();
      s.pop();
    }
    cout << ")";
  }
  cout << "\n";
}
