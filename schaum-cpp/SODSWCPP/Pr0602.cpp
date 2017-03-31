//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.2 page 121
//  Testing reverse() function for queues

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T> void print(queue<T>);
template <class T> void reverse(queue<T>&);

int main()
{ queue<char> q;
  q.push('A');
  q.push('B');
  q.push('C');
  q.push('D');
  q.push('E');
  print(q);
  reverse(q);
  print(q);
}

template <class T>
void print(queue<T> q)
{ cout << "size=" << q.size();
  if (q.size()>0)
  { cout << ",\tfront=" << q.front() << ":\t(" << q.front();
    q.pop();
    while (!q.empty())
    { cout << "," << q.front();
      q.pop();
    }
    cout << ")";
  }
  cout << "\n";
}

template <class T> void reverse(queue<T>& q)
{ stack<T> s;
  while (!q.empty())
  { s.push(q.front());
    q.pop();
  }
  while (!s.empty())
  { q.push(s.top());
    s.pop();
  }
}
