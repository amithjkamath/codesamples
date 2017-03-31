//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.10 page 415
//  Testing the fill() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  print(a,10);
  fill(a+6,a+9,0);
  print(a,10);
}
