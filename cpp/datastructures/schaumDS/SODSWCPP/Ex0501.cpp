//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 5.1 page 93
//  Using a stack of strings

#include <iostream>
#include <stack>  // defines the stack<T> class template
using namespace std;

int main()
{ stack<string> s;
  s.push("first");
  s.push("second");
  s.push("third");
  s.push("fourth");
  cout << "s.size() = " << s.size() << "\n";
  while (!s.empty())
  { cout << "s.top() = " << s.top() << "\n";
    s.pop();
  }
  cout << "s.size() = " << s.size() << "\n";
}
