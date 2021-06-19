//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.4 on page 64
//  Friend function for the Point class

Point operator-(const Point& point)
{ return Point(-1*point._x,-1*point._y);
}
