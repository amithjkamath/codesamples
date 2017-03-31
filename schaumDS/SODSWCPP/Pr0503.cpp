//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 5.3 page 104
//  Testing bottom() function for stacks

#include <iostream>
#include <stack>
using namespace std;

class Stack : public stack<char>
{ public:
    char& bottom();
};

void print(Stack);
 
char& Stack::bottom()
{ Stack s;
  while (!empty())
  { s.push(top());
    pop();
  }
  push(s.top());
  s.pop();
  char& c=top();
  while (!s.empty())
  { push(s.top());
    s.pop();
  }
  return c;
}

int main()
{ Stack s;
  s.push('A');
  s.push('B');
  s.push('C');
  s.push('D');
  s.push('E');
  print(s);
  cout << "s.bottom() = " << s.bottom() << "\n";
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
