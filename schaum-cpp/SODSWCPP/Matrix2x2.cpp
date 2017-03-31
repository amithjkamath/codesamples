//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Matrix2x2.cpp
//  Implementation of Matrix class

#include <iomanip>  // defines setw() function
#include <sstream>  // defines ostringstream class
#include "Matrix2x2.h"

//////////////////////////////////////////////////////////////////////
//  friend functions:

ostream& operator<<(ostream& ostr, const Matrix& matrix)
{ return ostr << matrix.toString();
}

Matrix operator-(const Matrix& m)
{ return Matrix(-m._a,-m._b,-m._c,-m._d);
}

Matrix operator*(const double c, const Matrix& m)
{ return Matrix(c*m._a,c*m._b,c*m._c,c*m._d);
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{ return Matrix(m1._a+m2._a,m1._b+m2._b,m1._c+m2._c,m1._d+m2._d);
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{ return Matrix(m1._a-m2._a,m1._b-m2._b,m1._c-m2._c,m1._d-m2._d);
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{ double a = m1._a*m2._a + m1._b*m2._c;
  double b = m1._a*m2._b + m1._b*m2._d;
  double c = m1._c*m2._a + m1._d*m2._c;
  double d = m1._c*m2._b + m1._d*m2._d;
  return Matrix(a,b,c,d);
}

//////////////////////////////////////////////////////////////////////
//  public members:

Matrix::Matrix(double a, double b, double c, double d)
  : _a(a),  _b(b),  _c(c),  _d(d) { }

Matrix::Matrix(const Matrix& m)
  : _a(m._a),  _b(m._b),  _c(m._c),  _d(m._d) { }

Matrix& Matrix::operator=(const Matrix& m)
{ _a = m._a;
  _b = m._b;
  _c = m._c;
  _d = m._d;
 return *this;
}

bool Matrix::operator==(const Matrix& m) const
{ return _a == m._a && _b == m._b && _c == m._c && _d == m._d;
}

bool Matrix::operator!=(const Matrix& m) const
{ return _a != m._a || _b != m._b || _c != m._c || _d != m._d;
}

double Matrix::det() const
{ return _a*_d-_b*_c;
}

bool Matrix::isSingular() const
{ return _a*_d == _b*_c;
}

Matrix Matrix::inverse() const
{ double d = det();
  return Matrix(-_d/d,_b/d,_c/d,-_a/d);
}

Matrix Matrix::pow(int p) const
{ Matrix m = *this;
  if (p == 0) return IDENTITY;
  if (p == 1) return m;
  if (p%2) return m*pow(p-1);  // e.g., m^5 = m*m^4
  Matrix mm = pow(p/2);
  return mm*mm;                // e.g., m^3 = m^3*m^3
}

string Matrix::toString() const
{ ostringstream out;
  out << "\n" << setw(8) << _a << setw(8) << _b
      << "\n" << setw(8) << _c << setw(8) << _d << "\n";
  return out.str();
}

const Matrix Matrix::ZERO(0.0,0.0,0.0,0.0);
const Matrix Matrix::IDENTITY(1.0,0.0,0.0,1.0);
