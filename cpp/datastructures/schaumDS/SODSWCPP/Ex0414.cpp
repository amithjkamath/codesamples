//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.14 on page 84
//  Mutually recursive sine and cosine functions

double s(double x)
{ if (-0.005 < x && x < 0.005) return x - x*x*x/6;  // basis
  return 2*s(x/2)*c(x/2);                       // recursion
}

double c(double x)
{ if (-0.005 < x && x < 0.005) return 1.0 - x*x/2;  // basis
  return 1 - 2*s(x/2)*s(x/2);                   // recursion
}
