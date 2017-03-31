//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.11 on page 8
//  Using nested for loops to print a triangle of stars

#include <iostream>
using namespace std;

int main()
{ const int N=10;
  for (int i=0; i<N; i++)
  { for (int j=0; j<2*N; j++)
      if (j<N-i || j>N+i) cout << " ";
      else cout << "*";
    cout << "\n";
  } 
}