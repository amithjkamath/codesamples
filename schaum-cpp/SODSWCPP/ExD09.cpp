//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.9 page 415
//  Testing the equal() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {0,1,0,1,1,1,0,1,1,0};
  int b[] = {0,1,0,0,1,1,0,1,0,0};
  print(a,10);
  print(b,10);
  cout << "equal(a,a+10,b)=" << equal(a,a+10,b) << '\n';
  cout << "equal(a+1,a+4,a+5)=" << equal(a+1,a+4,a+5) << '\n';
}
