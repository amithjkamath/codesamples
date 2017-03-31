//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.20 on page 62
//  Test driver for RandomPoint class

#include <iostream>
using namespace std;

int main()
{ RandomPoint p0;
  cout << "p0 = " << p0 << "\n";
  RandomPoint p1(100,400);
  cout << "p1 = " << p1 << "\n";
  RandomPoint p2(1000,60000,2000,80000);
  cout << "p2 = " << p2 << "\n";
}
