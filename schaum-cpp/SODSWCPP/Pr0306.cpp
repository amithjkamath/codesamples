//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.6 on page 65
//  Friend functions for the Point class

Point operator*(const double coef, const Point& point)
{ return Point(coef*point._x,coef*point._y);
}

Point operator/(const Point& point, const double divisor)
{ return Point(point._x/divisor,point._y/divisor);
}
