//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 5.5 page 104
//  Testing equality operator for stacks

#include <iostream>
#include <stack>
using namespace std;

class Stack : public stack<char>
{ public:
    bool operator==(const Stack&);
};

int main()
{ Stack s;
  s.push('A');
  s.push('B');
  s.push('C');
  s.push('D');
  s.push('E');
  Stack ss=s;
  if (ss == s) cout << "The two stacks are equal\n";
  else cout << "The two stacks are NOT equal\n";
  s.top() = 'Z';
  if (ss == s) cout << "The two stacks are equal\n";
  else cout << "The two stacks are NOT equal\n";
  s.pop();
  if (ss == s) cout << "The two stacks are equal\n";
  else cout << "The two stacks are NOT equal\n";
  ss.pop();
  if (ss == s) cout << "The two stacks are equal\n";
  else cout << "The two stacks are NOT equal\n";
}

bool Stack::operator==(const Stack& s)
{ Stack s1=s, s2=*this;
  while (!s1.empty())
    if (s1.top() != s2.top()) return false;
    else
    { s1.pop();
      s2.pop();
    }
  return true;
}
