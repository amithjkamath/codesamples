//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.3 on page 85
//  Recursive sum of array function

double sum(double a[], int n)
{ if (n == 0) return 0.0;      // basis
  return sum(a,n-1) + a[n-1];  // recursion
}
