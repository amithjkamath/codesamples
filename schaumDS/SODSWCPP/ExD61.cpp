//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.61 page 
//  Testing the sort_heap() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {66,88,44,77,33,55,11,99,22};
  print(a,9);
  make_heap(a,a+9);
  print(a,9);
  sort_heap(a,a+9);
  print(a,9);
}
