//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.8 on page 14
//  Using nested for loops to print a diamond of stars

#include <iostream>
using namespace std;

int main()
{ const int N=7;
  for (int i=0; i<=2*N; i++)
  { for (int j=0; j<=2*N; j++)
      if (i<=N)
        if (j<N-i || j>N+i) cout << " ";
        else cout << "*";
      else
        if (j<i-N || j>3*N-i) cout << " ";
        else cout << "*";
    cout << "\n";
  } 
}
