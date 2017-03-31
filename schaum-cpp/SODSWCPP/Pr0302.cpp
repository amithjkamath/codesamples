//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.2 on page 64
//  Extra members of the Point class

double Point::magnitude() const { return sqrt(_x*_x+_y*_y); }
double Point::amplitude() const { return atan(_y/_x); }