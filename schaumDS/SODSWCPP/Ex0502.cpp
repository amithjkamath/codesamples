//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 5.2 page 94
//  Using stacks to implement an RPN calculator

#include <iostream>
#include <sstream>  // defines the istringstream class
#include <stack>    // defines the stack<T> class template
using namespace std;

int main()
{ stack<char> oprtr;    // stack for operators
  stack<double> oprnd;  // stack for operands
  string input;
  bool quit=false;
  double x, y;
  while (!quit)
  { cout << "RPN> ";  // user prompt
    cin >> input;
    switch (input[0])
    { case 'Q':  case 'q':
        quit = true;
        break;
      case '+':
        y = oprnd.top();
        oprnd.pop();
        x = oprnd.top();
        oprnd.pop();
        cout << "\t" << x << "+" << y << " = " << x+y << "\n";
        oprnd.push(x+y);
        break;
      case '-':
        y = oprnd.top();
        oprnd.pop();
        x = oprnd.top();
        oprnd.pop();
        cout << "\t" << x << "-" << y << " = " << x-y << "\n";
        oprnd.push(x-y);
        break;
      case '*':
        y = oprnd.top();
        oprnd.pop();
        x = oprnd.top();
        oprnd.pop();
        cout << "\t" << x << "*" << y << " = " << x*y << "\n";
        oprnd.push(x*y);
        break;
      case '/':
        y = oprnd.top();
        oprnd.pop();
        x = oprnd.top();
        oprnd.pop();
        cout << "\t" << x << "/" << y << " = " << x/y << "\n";
        oprnd.push(x/y);
        break;
      default:
        istringstream in(input);  // converts input to stream
        in >> x;                  // reads double from stream
        oprnd.push(x);
    }
  }
}
