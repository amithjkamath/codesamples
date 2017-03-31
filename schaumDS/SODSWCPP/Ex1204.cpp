//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 12.4 on page 238
//  Testing a priority queue of integers

#include <iostream>  // defines the cout object
#include <queue>     // defines the priority_queue class template
using namespace std;
typedef priority_queue<int> PriorityQueue;
void print(PriorityQueue);  // prints a copy of given queue

int main()
{ PriorityQueue pq;  print(pq);
  pq.push(44);       print(pq);
  pq.push(66);       print(pq);
  pq.push(22);       print(pq);
  pq.push(55);       print(pq);
  pq.push(33);       print(pq);
}

void print(PriorityQueue q)
{ cout << "size=" << q.size();
  if (q.size()>0)
  { cout << ", top=" << q.top() << ": (" << q.top();
    q.pop();
    while (!q.empty())
    { cout << "," << q.top();
      q.pop();
    }
    cout << ")";
  }
  cout << "\n";
}
