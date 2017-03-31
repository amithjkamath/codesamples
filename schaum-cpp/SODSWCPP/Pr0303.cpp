//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.3 on page 64
//  Extra members of the Point class

void Point::rotate(double alpha)
{ double r = magnitude();
  double theta = amplitude() + alpha;
  _x = r*cos(theta);
  _y = r*sin(theta);
}
