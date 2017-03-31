//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.16 on page 66
//  Adding a member function to the Point class

double Point::distanceTo(Line& line) const
{ double a = line._a;
  double b = line._b;
  double c = line._c;
  return abs(a*_x+b*_y+c)/sqrt(a*a+b*b);
}

