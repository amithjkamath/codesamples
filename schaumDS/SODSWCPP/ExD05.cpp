//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.5 page 413
//  Testing the copy() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {100,111,122,133,144,155,166,177,188,199};
  print(a,10);
  copy(a+7,a+10,a+2);
  print(a,10);
  int b[3];
  copy(a+7,a+10,b);
  print(b,3);
}
