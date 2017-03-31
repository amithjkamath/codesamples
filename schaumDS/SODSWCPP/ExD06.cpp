//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.6 page 413
//  Testing the copy_backward() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {100,111,122,133,144,155,166,177,188,199};
  print(a,10);
  copy_backward(a+7,a+10,a+5);
  print(a,10);
  int b[3];
  copy_backward(a+7,a+10,b+3);
  print(b,3);
}
