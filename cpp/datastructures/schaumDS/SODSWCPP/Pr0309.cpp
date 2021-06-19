//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.9 on page 65
//  More member functions for the Line class

double Line::slope() const { return -_a/_b; }
double Line::xIntercept() const { return -_c/_a; }
double Line::yIntercept() const { return -_c/_b; }
