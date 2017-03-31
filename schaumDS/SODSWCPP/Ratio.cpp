//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Ratio.cpp
//  Implementation of Ratio class

#include "Ratio.h"

//////////////////////////////////////////////////////////////////////
//  friend functions:

ostream& operator<<(ostream& ostr, const Ratio& r)
{ return ostr << r._num << "/" << r._den;
}

istream& operator>>(istream& istr, Ratio& r)
{ istr >> r._num;
  istr.ignore(1);
  istr >> r._den;
  r.reduce();
  return istr;
}

Ratio operator+(const Ratio& r1, const Ratio& r2)
{ Ratio r(r1._num*r2._den+r2._num*r1._den,r1._den*r2._den);
  r.reduce();
  return r;
}

Ratio operator-(const Ratio& r1, const Ratio& r2)
{ Ratio r(r1._num*r2._den-r2._num*r1._den,r1._den*r2._den);
  r.reduce();
  return r;
}

Ratio operator*(const Ratio& r1, const Ratio& r2)
{ Ratio r(r1._num*r2._num,r1._den*r2._den);
  r.reduce();
  return r;
}

Ratio operator/(const Ratio& r1, const Ratio& r2)
{ Ratio r(r1._num*r2._den,r1._den*r2._num);
  r.reduce();
  return r;
}

//////////////////////////////////////////////////////////////////////
//  public members:

Ratio::Ratio(long num, long den) : _num(num), _den(den)
{ reduce();
}

long Ratio::numerator() const
{ return _num;
}

long Ratio::denominator() const
{ return _den;
}

Ratio Ratio::reciprocal() const
{ Ratio r(_den,_num);
  r.reduce();
  return r;
}

void Ratio::invert()
{ long temp = _num;
  _num = _den;
  _den = temp;
  reduce();
}

Ratio::operator double() const
{ return double(_num)/_den;
}

//////////////////////////////////////////////////////////////////////
//  private members:

long Ratio::gcd(long m, long n)
{ if (m == n) return n;               // basis
  else if (m < n) return gcd(m,n-m);  // recursion
  else return gcd(m-n,n);             // recursion
}

void Ratio::reduce()
{ if (_num == 0 || _den == 0)
  { _num = 0;
    _den = 1;
    return;
  }
  if (_den < 0)
  { _den *= -1;
    _num *= -1;
  }
  if (_num == 1) return;
  int sgn = (_num<0?-1:1);
  long g = gcd(sgn*_num,_den);
  _num /= g;
  _den /= g;
}
