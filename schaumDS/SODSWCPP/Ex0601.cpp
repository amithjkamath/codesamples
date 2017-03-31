//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.1 page 110
//  Using a queue of strings

#include <iostream>
#include <queue>  // defines the queue<T> class template
using namespace std;
template <class T> void print(const queue<T>&);

int main()
{ queue<string> q;    print(q);
  q.push("Jean");     print(q);
  q.push("Stefan");   print(q);
  q.pop();            print(q);
  q.push("Paul");     print(q);
  q.push("Jessica");  print(q);
  q.push("David");    print(q);
  q.pop();            print(q);}

template <class T> void print(const queue<T>& q)
{ queue<T> qq=q;
  cout << "size=" << qq.size();
  if (qq.empty()) cout << "; the queue is empty.";
  else
  { cout << "; front=" << qq.front()
         << ", back=" << qq.back() 
         << ": (" << qq.front();
    qq.pop();
    while (!qq.empty())
    { cout << ", " << qq.front();
      qq.pop();
    }
    cout << ").";
  }
  cout << "\n";
}
