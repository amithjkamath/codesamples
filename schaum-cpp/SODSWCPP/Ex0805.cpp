//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.5 on page 159
//  Test driver for a Concordance class

#include "Concordance.h"

int main()
{ ifstream fin("Shakespeare.txt");
  ofstream fout("Concordance.out");
  Concordance c;
  fin >> c;
  fout << c;
  cout << c;
}
