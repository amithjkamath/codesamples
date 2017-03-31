//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.17 page 
//  Testing the generate() algorithm

#include <algorithm>
#include "print.h"

long fibonacci();

int main()
{ int a[10]={0};
  generate(a,a+10,fibonacci);
  print(a,10);
}

long fibonacci()
{ static int f1=0, f2=1;
  int f0=f1;
  f1 = f2;
  f2 += f0;
  return f0;
}
