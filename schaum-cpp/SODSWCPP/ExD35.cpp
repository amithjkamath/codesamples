//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.35 page 
//  Testing the partial_sort_copy() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {77,22,99,55,44,88,11,33,66};
  print(a,9);
  int b[3];
  partial_sort_copy(a,a+9,b,b+3);
  print(a,9);
  print(b,3);
}
