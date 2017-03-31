//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 5.7 page 104
//  Testing bottom() function for stacks

#include <iostream>
#include <stack>
using namespace std;
class Stack;
void print(Stack);

class Stack : public stack<char>
{ public:
    void popBottom();
};

int main()
{ Stack s;
  s.push('A');
  s.push('B');
  s.push('C');
  s.push('D');
  s.push('E');
  print(s);
  s.popBottom();
  print(s);
  s.popBottom();
  print(s);
}

void print(Stack s)
{ cout << "size=" << s.size();
  if (s.size()>0)
  { cout << ",\ttop=" << s.top() << ":\t(" << s.top();
    s.pop();
    while (!s.empty())
    { cout << "," << s.top();
      s.pop();
    }
    cout << ")";
  }
  cout << "\n";
}
 
void Stack::popBottom()
{ Stack s;
  while (!empty())
  { s.push(top());
    pop();
  }
  s.pop();
  while (!s.empty())
  { push(s.top());
    s.pop();
  }
}
