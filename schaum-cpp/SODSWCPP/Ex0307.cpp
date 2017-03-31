//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.7 on page 55
//  Test driver for Line class

#include <iostream>
using namespace std;

int main()
{ Point p1(4,1);
  cout << "p1 = " << p1 << "\n";
  Line line1(2,3,6);
  cout << "line1: " << line1 << "\n";
  Line line2(-2,12);
  cout << "line2: " << line2 << "\n";
  Line line3(p1,3);
  cout << "line3: " << line3 << "\n";
  Point p2(0,5);
  cout << "p2 = " << p2 << "\n";
  Line line4(p1,p2);
  cout << "line4: " << line4 << "\n";
}
