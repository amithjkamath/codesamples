//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.28 page 
//  Testing the merge() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {22,55,66,88};
  int b[] = {11,33,44,77,99};
  int c[9];
  merge(a,a+4,b,b+5,c);
  print(c,9);
}
