//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.15 on page 10
//  Inputting words from cin

#include <iostream>
using namespace std;

int main()
{ string word;
  while (cin >> word)
    cout << "\t[" << word << "] " << word.length() << "\n";
}
