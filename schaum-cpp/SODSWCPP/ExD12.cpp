//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.12 page 416
//  Testing the find() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  print(a,10);
  int* r = find(a,a+10,13);
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index of i
  r = find(a,a+6,13);
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index of i
}
