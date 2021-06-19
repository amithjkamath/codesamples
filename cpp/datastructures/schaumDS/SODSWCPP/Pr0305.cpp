//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.5 on page 64
//  Friend function for the Point class

Point operator+(const Point& p1, const Point& p2)
{ return Point(p1._x+p2._x,p1._y+p2._y);
}

Point operator-(const Point& p1, const Point& p2)
{ return Point(p1._x-p2._x,p1._y-p2._y);
}
