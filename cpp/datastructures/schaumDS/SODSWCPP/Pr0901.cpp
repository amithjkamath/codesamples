//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Problem 9.1 on page 
//  Returning a pair

#include <iostream>
using namespace std;
typedef pair<double,double> Pair;
Pair range(double*,int);

int main()
{ double a[] = {6.6,2.2,8.8,5.5,9.9,5.5,1.1,4.4,7.7};
  Pair p = range(a,9);
  cout << "min=" << p.first << ", max=" << p.second << '\n';
}

Pair range(double* a, int n)
{ if (n==0) return Pair(0.0,0.0);
  double min=a[0], max=a[0];
  for (int i=1; i<n; i++)
  if (a[i] < min) min = a[i];
  else if (a[i] > max) max = a[i];
  return Pair(min,max);
}
