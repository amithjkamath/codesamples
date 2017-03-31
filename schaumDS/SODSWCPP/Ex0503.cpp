//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 5.3 page 95
//  Using a stack to convert infix expressions to postfix

#include <iostream>
#include <sstream>  // defines the istringstream class
#include <stack>    // defines the stack<T> class template
using namespace std;

int main()
{ stack<char> op;    // stack for operators
  string s;
  cout << "Enter an infix expression: ";
  getline(cin,s);
  istringstream in(s);  // convert input to stringstream
  char c;
  while (in >> c)
  { 
    if (c=='+' || c=='-' || c=='*' || c=='/') op.push(c);
    else if (c==')')
    { cout << op.top() << " ";
      op.pop();
    }
    else if (c>='0' && c<= '9')
    { in.putback(c);
      int n;
      in >> n;
      cout << n << " ";
    }
  }
  cout << op.top() << endl;
}
