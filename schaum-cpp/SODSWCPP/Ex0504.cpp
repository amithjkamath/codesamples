//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 5.4 page 96
//  Testing the iterative version of the Towers of Hanoi

#include <iostream>
#include <stack>    // defines the stack<T> class template
using namespace std;
void hanoi(int,char,char,char);

int main()
{ hanoi(3, 'A', 'B', 'C');
}

struct Quad
{ Quad() {}
  Quad(int n, char a, char b, char c) : _n(n), _x(a), _y(b), _z(c) {}
  int _n;
  char _x, _y, _z;
};

void hanoi(int n, char x, char y, char z)
{ stack<Quad> s;
  s.push(Quad(n,x,y,z));
  while (!s.empty())
  { Quad q = s.top();
    s.pop();
    n = q._n;
    x = q._x;
    y = q._y;
    z = q._z;
    if (n == 1)
      cout << "Move top disk from peg " << q._x
           << " to peg " << q._z << "\n";
    else
    { s.push(Quad(n-1,y,x,z));
      s.push(Quad(1,x,y,z));
      s.push(Quad(n-1,x,z,y));
    }  
  }
}
