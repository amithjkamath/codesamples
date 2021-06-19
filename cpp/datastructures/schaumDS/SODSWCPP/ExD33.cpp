//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.33 page 
//  Testing the nth_element() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {77,22,99,55,44,88,11,33,66};
  print(a,9);
  nth_element(a,a+3,a+9);
  print(a,9);
}
