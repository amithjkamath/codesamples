//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Queue.cpp
//  Test driver for the Queue class template

#include "Queue.hpp"
template <class T>
void print(Queue<T>);          // prints a copy of given queue

int main()
{ Queue<string> q;        print(q);
  q.push_back("first");   print(q);
  q.push_back("second");  print(q);
  q.push_back("third");   print(q);
  q.pop_front();          print(q);
  q.push_back("fourth");  print(q);
  q.push_back("fifth");   print(q);
  q.push_back("sixth");   print(q);
}

template <class T>
void print(Queue<T> q)
{ cout << "size=" << q.size();
  if (q.size()>0)
  { cout << ", front=" << q.front()
         << ", back=" << q.back() << ": (" << q.front();
    q.pop_front();
    while (!q.empty())
    { cout << "," << q.front();
      q.pop_front();
    }
    cout << ")";
  }
  cout << "\n";
}
