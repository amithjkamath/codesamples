//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Matrix.cpp
//  Test driver for Matrix class

#include "Matrix.hpp"

int main()
{ Matrix<2,3> m;
  m(1,2) = 44.4;
  m(0,1) = 66.6;
  cout << m.toString() << "\n";
  Matrix<2,3> m1(m);
  m1(1,0) = 99.9;
  cout << m1.toString() << "\n";
}
