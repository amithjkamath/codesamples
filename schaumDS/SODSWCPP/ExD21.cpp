//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.21 page 
//  Testing the inplace_merge() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {22,55,66,88,11,33,44,77,99};
  print(a,9);
  inplace_merge(a,a+4,a+9);
  print(a,9);
}
