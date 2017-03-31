//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.17 on page 66
//  Another member function for the Point class

bool Point::isOn(Line& line) const
{ double a = line._a;
  double b = line._b;
  double c = line._c;
  return (a*_x + b*_y + c == 0);
}
