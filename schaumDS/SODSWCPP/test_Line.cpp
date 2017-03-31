//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Line.cpp
//  Test driver for Line class

#include "Point.h"
#include "Line.h"

int main()
{ Point p1(4,1);
  cout << "p1 = " << p1 << "\n";
  Line line1(2,3,6);
  cout << "line1: " << line1 << "\n";
  cout << "line1.xIntercept() = " << line1.xIntercept() << "\n";
  cout << "line1.yIntercept() = " << line1.yIntercept() << "\n";
  Line line2(-2,12);
  cout << "line2: " << line2 << "\n";
  Line line3(p1,3);
  cout << "line3: " << line3 << "\n";
  Point p2(0,5);
  cout << "p2 = " << p2 << "\n";
  Line line4(p1,p2);
  cout << "line4: " << line4 << "\n";
  if (p2.isOn(line4)) cout << "p2 is on line4\n";
  cout << "line4: " << line4 << "\n";
  if (line4.contains(p2)) cout << "line4 contains p2 \n";
  cout << "line1.distanceTo(p2) = " << line1.distanceTo(p2) << "\n";
  cout << "p2.distanceTo(line1) = " << p2.distanceTo(line1) << "\n";
  cout << "line4.distanceTo(p2) = " << line4.distanceTo(p2) << "\n";
}
