//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.22 page 
//  Testing the iter_swap() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {11,22,33,44,55,66,77,88,99};
  int b[] = {10,20,30,40,50,60,70,80,90};
  print(a,9);
  print(b,9);
  iter_swap(a+4,b+7);
  print(a,9);
  print(b,9);
}
