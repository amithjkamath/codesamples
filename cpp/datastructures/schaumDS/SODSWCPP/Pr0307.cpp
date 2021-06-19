//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.7 on page 65
//  Friend function for the Point class

double distance(const Point& p1, const Point& p2)
{ float dx=(p1._x-p2._x);
  float dy=(p1._y-p2._y);
  return sqrt(dx*dx+dy*dy);
}
