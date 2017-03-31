//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.5 on page 85
//  Recursive max of array function

double max(double a[], int n)
{ if (n == 1) return a[0];       // basis
  int n1 = n/2;
  int n2 = n - n1;
  double m1 = max(a,n1);         // recursion on a[0:n1-1]
  double m2 = max(a+n1,n2);      // recursion on a[n1:n-1]
  return ( m1 > m2 ? m1 : m2 );  // = max{m1,m2}
}
