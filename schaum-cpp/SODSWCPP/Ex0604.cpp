//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.4 page 117
//  Testing the dynamic array implementation of queue class

#include <iostream>
#include "Queue.h"  // defines the queue<T> class template
using namespace std;

int main()
{ queue<string> s;   print(s);
  s.push("first");   print(s);
  s.push("second");  print(s);
  s.push("third");   print(s);
  s.pop();           print(s);
  s.push("fourth");  print(s);
  s.push("fifth");   print(s);
  s.push("sixth");   print(s);
}

template <class T>
void print(queue<T> s)
{ cout << "size=" << s.size();
  if (s.size()>0)
  { cout << ", back=" << s.back() << ": (" << s.back();
    s.pop();
    while (!s.empty())
    { cout << "," << s.back();
      s.pop();
    }
    cout << ")";
  }
  cout << "\n";
}
