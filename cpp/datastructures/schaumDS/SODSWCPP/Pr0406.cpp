//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.6 on page 85
//  Recursive power function

double pow(double x, int n)
{ if (n == 0) return 1.0;  // basis
  return x*pow(x,n-1);     // recursion
}
