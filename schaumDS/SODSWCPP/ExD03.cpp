//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.3 page 412
//  Testing the adjacent_find() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {0,1,0,1,1,1,0,1,1,0};
  print(a,10);
  int* r = adjacent_find(a,a+10);
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index of i
}
