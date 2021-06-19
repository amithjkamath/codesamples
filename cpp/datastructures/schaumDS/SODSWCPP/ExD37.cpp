//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.37 page 
//  Testing the partition() algorithm

#include <numeric>
#include "Odd.h"
#include "print.h"

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  print(a,10);
  partition(a,a+10,Odd());
  print(a,10);
}
