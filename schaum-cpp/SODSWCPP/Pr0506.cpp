//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 5.6 page 104
//  Testing reverse() function for stacks

#include <iostream>
#include <stack>
using namespace std;

class Stack : public stack<char>
{ public:
    void clear();
};

int main()
{ Stack s;
  s.push('A');
  s.push('B');
  s.push('C');
  s.push('D');
  s.push('E');
  cout << "s.size() = " << s.size() << "\n";
  if (s.empty()) cout << "The stack is empty.\n";
  else cout << "The stack is NOT empty.\n";
  s.clear();
  cout << "s.size() = " << s.size() << "\n";
  if (s.empty()) cout << "The stack is empty.\n";
  else cout << "The stack is NOT empty.\n";
}

void Stack::clear()
{ while (!empty())
    pop();
}
