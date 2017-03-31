//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Point.cpp
//  Test driver for Point class

#include "Point.h"

int main()
{ Point p0;  // invokes default constructor
  cout << "p0 = " << p0 << "\n";  // invokes output operator
  Point p1;  // invokes default constructor
  cout << "p1 = " << p1 << "\n";  // invokes output operator
  if (p1 == p0) cout << "p1 == p0\n";  // invokes equality operator
  if (p1 != p0) cout << "p1 != p0\n";  // invokes inequality operator
  Point p2=p0;  // initialization invokes copy constructor
  cout << "p2 = " << p2 << "\n";  // invokes output operator
  if (p2 == p0) cout << "p2 == p0\n";  // invokes equality operator
  if (p2 != p0) cout << "p2 != p0\n";  // invokes inequality operator
  p1 = Point(5,-2);  // assignment invokes assignment operator
  cout << "p1 = " << p1 << "\n";  // invokes output operator
  if (p2 == p1) cout << "p2 == p1\n";  // invokes equality operator
  if (p2 != p1) cout << "p2 != p1\n";  // invokes inequality operator
  p2 = p1;  // assignment invokes assignment operator
  cout << "p2 = " << p2 << "\n";  // invokes output operator
  if (p2 == p1) cout << "p2 == p1\n";  // invokes equality operator
  if (p2 != p1) cout << "p2 != p1\n";  // invokes inequality operator
  p0 = Point(2,2);
  cout << "p0 = " << p0 << "\n";  // invokes output operator
  cout << "distance(p0,p2) = " << distance(p0,p2) << "\n";
  p1 = p2 - p0;
  cout << "p1 = " << p1 << "\n";  // invokes output operator
  cout << "p1.magnitude() = " << p1.magnitude() << "\n";
  p1 -= Point(3,3);
  cout << "p1 = " << p1 << "\n";  // invokes output operator
  p1.rotate(3.141592653589793);
  cout << "p1 = " << p1 << "\n";  // invokes output operator
}
