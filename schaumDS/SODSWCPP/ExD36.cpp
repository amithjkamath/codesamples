//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.36 page 
//  Testing the partial_sum() algorithm

#include <numeric>
#include "print.h"

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  int b[10];
  partial_sum(a,a+10,b);
  print(a,10);
  print(b,10);
}
