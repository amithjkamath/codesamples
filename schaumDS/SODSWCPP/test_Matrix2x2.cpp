//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Matrix.cpp
//  Test driver for Matrix class

#include <iomanip>
#include "Matrix.h"

int main()
{ Matrix m0;
  cout << "m0 = " << m0 << "\n";
  Matrix m1(1,2,3,4);
  cout << "m1 = " << m1 << "\n";
  Matrix m2=m1;
  cout << "m2 = " << m2 << "\n";
  cout << "-m2 = " << -m2 << "\n";
  cout << "-0.11*m2 = " << -0.11*m2 << "\n";
  m0 = m2;
  cout << "m0 = " << m0 << "\n";
  if (m0 == m2) cout << "m0 == m2\n";
  if (m0 != m2) cout << "m0 != m2\n";
  cout << "m0.det() = " << m0.det() << "\n";
  if (m0.isSingular()) cout << "m0 is singular\n";
  else cout << "m0 is nonsingular\n";
  m0 = Matrix::ZERO;
  cout << "m0.det() = " << m0.det() << "\n";
  if (m0.isSingular()) cout << "m0 is singular\n";
  else cout << "m0 is nonsingular\n";
  m1 = Matrix::IDENTITY;
  cout << "m1.det() = " << m1.det() << "\n";
  if (m1.isSingular()) cout << "m1 is singular\n";
  else cout << "m1 is nonsingular\n";
  Matrix m3 = m2.inverse();
  cout << "m3 = " << m3 << "\n";
  cout << "m3.det() = " << m3.det() << "\n";
  cout << "100*m1+m3 = " << 100*m1+m3 << "\n";

  cout << "100*m1-m3 = " << 100*m1-m3 << "\n";
  cout << "m2 = " << m2 << "\n";
  Matrix m4(6,-3,4,-2);
  cout << "m4 = " << m4 << "\n";
  cout << "m2*m4 = " << m2*m4 << "\n";
  cout << "m2.pow(3) = " << m2.pow(3) << "\n";
}
