//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.12 on page 65
//  Another member function for the Line class

bool Line::contains(Point& p) const
{ return (_a*p.x() + _b*p.y() + _c == 0);
}
