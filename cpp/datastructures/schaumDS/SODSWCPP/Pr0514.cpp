//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Problem 5.14 page 105
//  A list implementation of a Stack class

#include <iostream>
#include <list>
using namespace std;

template <class T>
class Stack
{ public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);
    int size() const;      // returns number of elements in this
    bool empty() const;    // returns true iff this is empty
    T& top();              // returns the top element
    void push(const T&);   // inserts given element on top
    void pop();            // removes element from top
  protected:
    list<T> _;             // vector for stack elements
};

typedef Stack<char> charStack;
void print(const charStack&);

int main()
{ charStack s;
  print(s);
  s.push('A');
  s.push('B');
  s.push('C');
  s.push('D');
  s.push('E');
  print(s);
  s.pop();
  print(s);
}

void print(const charStack& ss)
{ charStack s=ss;
  cout << "size=" << s.size();
  if (s.empty()) cout << "; the stack is empty.";
  else
  { cout << "; top=" << s.top() << ": (" << s.top();
    s.pop();
    while (!s.empty())
    { cout << "," << s.top();
      s.pop();
    }
    cout << ").";
  }
  cout << "\n";
}

template <class T>
Stack<T>::Stack()
{ 
}

template <class T>
Stack<T>::Stack(const Stack& s) : _(s._)
{ 
}

template <class T>
Stack<T>::~Stack()
{ 
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& s)
{ _ = s._;
}

template <class T>
int Stack<T>::size() const
{ return _.size();
}

template <class T>
bool Stack<T>::empty() const
{ return _.empty();
}

template <class T>
T& Stack<T>::top()
{ return _.back();
}

template <class T>
void Stack<T>::pop()
{ _.pop_back();
}

template <class T>
void Stack<T>::push(const T& x)
{ _.push_back(x);
}
