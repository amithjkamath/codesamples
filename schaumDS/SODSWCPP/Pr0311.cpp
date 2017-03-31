//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.11 on page 65
//  Another member functions for the Line class

double Line::distanceTo(Point& p) const
{ return abs(_a*p._x+_b*p._y+_c)/sqrt(_a*_a+_b*_b);
}
