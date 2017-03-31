//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.41 page 
//  Testing the random_shuffle() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="ABCDEFGHIJ";
  cout << s << '\n';
  for (int i=0; i<4; i++)
  { random_shuffle(s,s+10);
    cout << s << '\n';
  }
}
