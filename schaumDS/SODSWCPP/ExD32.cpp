//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.32 page 
//  Testing the next_permutation() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="ABCD";
  for (int i=0; i<24; i++)
  { next_permutation(s,s+4);
    cout << (i%8?'\t':'\n') << s;
  }
}
