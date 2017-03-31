//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.4 page 412
//  Testing the binary_search() algorithm

#include <algorithm>
#include "print.h"

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  print(a,10);
  bool found = binary_search(a,a+10,21);
  cout << "found=" << found << '\n';
  found = binary_search(a+2,a+7,21);
  cout << "found=" << found << '\n';
}
