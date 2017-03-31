//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.9 on page 14
//  Using nested for loops to print an "X" of stars

#include <iostream>
using namespace std;

int main()
{ const int N=7;
  for (int i=0; i<N; i++)
  { for (int j=0; j<N; j++)
      if (j==i || j==N-1-i) cout << "*";
      else cout << " ";
    cout << "\n";
  } 
}
