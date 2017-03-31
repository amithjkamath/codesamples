//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.2 page 412
//  Testing the adjacent_difference() algorithm

#include <numeric>
#include "print.h"

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  print(a,10);
  int b[10];
  adjacent_difference(a,a+10,b);
  print(b,10);
}
