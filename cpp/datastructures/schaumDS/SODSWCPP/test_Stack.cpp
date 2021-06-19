//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Stack.cpp
//  Test driver for the Stack class template

#include "Stack.hpp"
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
