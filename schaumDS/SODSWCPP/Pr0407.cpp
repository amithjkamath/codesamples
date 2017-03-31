//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.7 on page 85
//  Recursive power function that makes no more than
//  2*lg(n) recursive calls

double pow(double x, int n)
{ if (n == 0) return 1.0;    // basis
  double p = pow(x,n/2);
  if (n%2 == 0) return p*p;  // recursion (n even)
  else return x*p;           // recursion (n odd)
}
