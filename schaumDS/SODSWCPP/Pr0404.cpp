//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.4 on page 85
//  Recursive max of array function

double max(double a[], int n)
{ if (n == 1) return a[0];  // basis
  double m = max(a,n-1);    // recursion
  if (a[n-1] > m) return a[n-1];
  else return m;
}
