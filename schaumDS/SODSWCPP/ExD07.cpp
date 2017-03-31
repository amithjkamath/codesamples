//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.7 page 414
//  Testing the count() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {0,1,0,1,1,1,0,1,1,0};
  print(a,10);
  int n = count(a,a+10,1);
  cout << "n=" << n << '\n';
}
