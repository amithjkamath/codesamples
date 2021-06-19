//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.33 on page 86
//  Mutually recursive implementations of the
//  hyperbolic sine and hyperbolic cosine functions

double s(double x)
{ if (-0.005 < x && x < 0.005) return x + x*x*x/6;  // basis
  return 2*s(x/2)*c(x/2);                           // recursion
}

double c(double x)
{ if (-0.005 < x && x < 0.005) return x + x*x*x/2;  // basis
  return 1 + 2*s(x/2)*s(x/2);                           // recursion
}
