//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.40 page 
//  Testing the push_heap() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {66,44,88,33,55,11,99,22,77};
  print(a,8);
  make_heap(a,a+8);
  print(a,8);
  print(a,9);
  push_heap(a,a+9);
  print(a,9);
}
