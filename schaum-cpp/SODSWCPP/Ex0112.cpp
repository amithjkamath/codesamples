//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.12 on page 9
//  Using a separate function

#include <iostream>
using namespace std;
void printRow(const int, const int);  // prototype

int main()
{ const int N=10;
  for (int i=0; i<N; i++)
    printRow(i,N);
}

void printRow(const int row, const int N)  // implementation
{ for (int j=0; j<2*N; j++)
    if (j<N-row || j>N+row) cout << " ";
    else cout << "*";
  cout << "\n";
}
