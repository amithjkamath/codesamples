//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.16 page 
//  Testing the for_each() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

void print(int);

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  for_each(a,a+10,print);
}

void print(int x)
{ cout << x << " ";
}
