//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.10 on page 14
//  Prints a multiplication table

#include <iomanip.h>
#include <iostream>
using namespace std;

int main()
{ setiosflags(ios::right);
  const int N=12;
  for (int x=1; x <= N; x++)
  { for (int y=1; y <= N; y++)
      cout << setw(5) << x*y;
    cout << endl;
  }
}
