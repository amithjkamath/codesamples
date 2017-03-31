//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.2 on page 156
//  Using pair as a return type

#include <iostream>
#include <limits>  // defines the constant INT_MAX
using namespace std;
typedef pair<int,bool> Pair;
Pair factorial(int);

int main()
{ for (int n=-2; n<16; n++)
  { Pair p=factorial(n);
    if (p.second) cout << n << "!\t= " << p.first;
    else cout << "overflow for n = " << n;
    cout << '\n';
  }
}

Pair factorial(int n)
{ if (n<0) return Pair(0,false);
  if (n<2) return Pair(1,true);
  int f=2;
  for (int k=3; k<=n; k++)
    if (f > INT_MAX/k) return Pair(0,false);
    else f *= k;
  return Pair(f,true);
}
