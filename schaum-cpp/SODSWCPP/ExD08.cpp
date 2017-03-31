//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.8 page 415
//  Testing the count_if() algorithm

#include <algorithm>
#include "Odd.h"

int main()
{ int a[] = {0,1,0,1,1,1,0,1,1,0};
  print(a,10);
  int n = count_if(a,a+10,Odd());
  cout << "n=" << n << '\n';
}
