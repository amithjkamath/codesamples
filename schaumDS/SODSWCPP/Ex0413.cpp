//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.13 page 83
//  A recursive solution to the Towers of Hanoi puzzle

#include <iostream>
using namespace std;

void hanoi(int,char,char,char);

int main()
{ hanoi(4,'A','B','C');
}

void hanoi(int n, char x, char y, char z)
{ if (n == 1)  // basis
    cout << "Move top disk from peg " << x << " to peg " << z << "\n";
  else         // recursion
  { hanoi(n-1,x,z,y);
    hanoi(1,x,y,z);
    hanoi(n-1,y,x,z);
  }
}
