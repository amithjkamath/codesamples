//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_RandomLine.cpp
//  Test driver for RandomLine class

#include "RandomLine.h"

int main()
{ RandomLine line0;
  cout << "line0: " << line0 << "\n";
  RandomLine line1;
  cout << "line1: " << line1 << "\n";
  line0 = RandomLine();
  cout << "line0: " << line0 << "\n";
}
