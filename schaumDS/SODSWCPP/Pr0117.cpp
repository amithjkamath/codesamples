//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.17 on page 15
//  Tests the isPrime(n) function

#include <iostream>
using namespace std;
bool isPrime(int); 

int main()
{ const int N=500;
  for (int n=0; n<N; n++)
    if (isPrime(n)) cout << n << "\t";
}

bool isPrime(int n)
{ if (n<2) return false;
  if (n==2) return true;
  if (n%2==0) return false;
  for (int d=3; d<n; d += 2)
    if (n%d==0) return false;
  return true;
}
