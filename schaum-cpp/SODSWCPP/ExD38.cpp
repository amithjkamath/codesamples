//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.38 page 
//  Testing the pop_heap() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {44,88,33,77,11,99,66,22,55};
  print(a,9);
  make_heap(a,a+9);
  print(a,9);
  pop_heap(a,a+9);
  print(a,9);
  print(a,8);
}
