
// Data Structures with C++ by John R. Hubbard
// Copyright McGraw-Hill 2000
// Example C.6, page 291-2
// Using a priority_queue Object

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{  
  priority_queue<string> pq;
  pq.push("Japan");
  pq.push("Japan");
  pq.push("Korea");
  pq.push("China");
  pq.push("India");
  pq.push("Nepal");
  pq.push("Qatar");
  pq.push("Yemen");
  pq.push("Egypt");
  pq.push("Ziare");
  pq.push("Lybia");
  pq.push("Italy");
  pq.push("Spain");
  pq.push("Chile");
  while(!pq.empty())
    {
      cout << pq.top() << "\n";
      pq.pop();
    }
}
