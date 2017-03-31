//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.34 on page 86
//  Recursive implementation of the tangent function

double t(double x)
{ if (-0.005 < x && x < 0.005) return x + x*x*x/3;  // basis
  return 2*t(x/2)/(1 - t(x/2)*t(x/2));              // recursion
}
