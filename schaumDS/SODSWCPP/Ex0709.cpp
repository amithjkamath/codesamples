//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 7.8 page 139
//  Implementation of Integer class: Integer.cpp

#include <cctype>   // defines isdigit() function
#include <sstream>  // defines ostringstream class
#include <numeric>  // defines inner_product() function
#include "Integer.h"

//////////////////////////////////////////////////////////////////////
//  friend functions:

ostream& operator<<(ostream& ostr, const Integer& x)
{ return ostr << x.toString();
}

istream& operator>>(istream& istr, Integer& x)
{ string s;
  istr >> s;
  x = Integer::toInteger(s);
  return istr;
}

Integer operator-(const Integer& x)
{ Integer y(x);
  y._neg = !(x._neg);
  return y;
}

Integer operator*(int n, const Integer& x)
{ if (n==0 || x==Integer::ZERO) return Integer::ZERO;
  const int R = Integer::RADIX;
  Integer y=Integer::NAI;
  if (n<0) n = -n;
  if (n<0 && !x._neg) y._neg = true;
  if (n>0 &&  x._neg) y._neg = true;
  Integer::CIt it=x._.begin();
  int n0=n%R, n1=n/R;
  unsigned x0=*it++, x1;
  unsigned u=n0*x0;
  y._.push_back(u%R);
  u /= R;  // carry
  while (it!=x._.end())
  { x1 = *it++;
    u += n0*x1 + n1*x0;
    y._.push_back(u%R);
    u /= R;  // carry
    x0 = x1;
  }
  u += n1*x0;
  while (u>0)
  { y._.push_back(u%R);
    u /= R;
  }
  return y;
}

Integer operator*(const Integer& x, int n)
{ return n*x;
}

Integer operator+(const Integer& x, const Integer& y)
{ if (x==Integer::ZERO) return Integer(y);
  if (y==Integer::ZERO) return Integer(x);
  if (x._neg && !y._neg) return y - -x;
  if (!x._neg && y._neg) return x - -y;
  Integer z=Integer::NAI;
  const int R = Integer::RADIX;
  int sum=0;
  Integer::CIt itx=x._.begin(), ity=y._.begin();
  while (itx!=x._.end() && ity!=y._.end())
  { sum += *itx++ + *ity++;
    z._.push_back(sum%R);
    sum /= R;  // carry
  }
  while (itx!=x._.end())
  { sum += *itx++;
    z._.push_back(sum%R);
    sum /= R;  // carry
  }
  while (ity!=y._.end())
  { sum += *ity++;
    z._.push_back(sum%R);
    sum /= R;  // carry
  }
  return z;
}

Integer operator-(const Integer& x, const Integer& y)
{ if (x==y) return Integer::ZERO;
  if (x<y) return -(y - x);
  // x > y (so x._.size() >= y._.size()):
  if (x==Integer::ZERO) return -y;
  if (y==Integer::ZERO) return x;
  if (x._neg && !y._neg) return -(-x + y);
  if (!x._neg && y._neg) return x + -y;
  if (x._neg && y._neg) return -(x - y);
  // x > y > 0:
  Integer z=Integer::NAI;
  const int R = Integer::RADIX;
  Integer::CIt itx=x._.begin(), ity=y._.begin();
  int diff=0, borrow=0;
  while (ity!=y._.end())
  { diff = *itx++ - *ity++ - borrow;
    if (diff<0)
    { diff += R;
      borrow = 1;
    }
    z._.push_back(diff);
  }
  diff = *itx - borrow;
  if (diff>0) z._.push_back(diff);
  return z;
}

Integer operator*(const Integer& x, const Integer& y)
{ if (x==Integer::ZERO || y==Integer::ZERO) return Integer::ZERO;
  Integer z=Integer::NAI;
  if (x._neg && !y._neg || y._neg && !x._neg) z._neg = true;
  const int R = Integer::RADIX;
  unsigned u=0;
  Integer::CIt it1=x._.begin(), it2=x._.begin();
  Integer::CRIt rit=y._.rend();
  while (rit!=y._.rbegin())
  { u = inner_product(it1,++it2,--rit,u/R);
    z._.push_back(u%R);
  }
  while (it2!=x._.end())
  { u = inner_product(++it1,++it2,rit,u/R);
    z._.push_back(u%R);
  }
  while (it1!=x._.end())
  { u = inner_product(++it1,it2,rit,u/R);
    z._.push_back(u%R);
  }
  u /= R;  // carry
  while (u>0)
  { z._.push_back(u%R);
    u /= R;
  }
  return z;
}

Integer abs(const Integer& x)
{ Integer y(x);
  y._neg = false;
  return y;
}

int sign(const Integer& x)
{ if (x._neg) return -1;
  if (x==Integer::ZERO) return 0;
  return 1;
}

//////////////////////////////////////////////////////////////////////
//  public member functions:

Integer::Integer(int n) : _neg(n<0)
{ _.push_front(_neg?-n:n);
}

Integer::Integer(const string& s) : _neg(false)
{ *this = toInteger(s);
}

Integer& Integer::operator+=(const Integer& x)
{ *this = *this + x;
  return *this;
}

Integer& Integer::operator-=(const Integer& x)
{ *this = *this - x;
  return *this;
}

Integer& Integer::operator*=(int n)
{ *this = *this * n;
  return *this;
}

Integer& Integer::operator*=(const Integer& x)
{ *this = *this * x;
  return *this;
}

bool Integer::operator==(const Integer& x) const
{ return (_neg == x._neg && _ == x._);
}

bool Integer::operator!=(const Integer& x) const
{ return !(*this == x);
}

bool Integer::operator<(const Integer& x) const
{ if (*this == x) return false;
  if (_neg && !x._neg) return true;
  if (!_neg && x._neg) return false;
  if (_neg && x._neg) return (abs(*this) > abs(x));
  if (_.size() < x._.size()) return true;
  if (_.size() > x._.size()) return false;
  Integer::CIt it=_.begin(), jt=x._.begin();
  while (it!=_.end())
    if (*it<*jt) return true;
    else if (*it++>*jt++) return false;
  return false;
}

bool Integer::operator<=(const Integer& x) const
{ return !(x < *this);
}

bool Integer::operator>(const Integer& x) const
{ return (x < *this);
}

bool Integer::operator>=(const Integer& x) const
{ return !(*this < x);
}

int Integer::toInt() const
{ if (_.size()==0) return 0;
  int n=_.front();
  return (_neg?-n:n);
}

double Integer::toDouble() const
{ if (_.size()==0) return 0.0;
  Integer::CRIt it=_.rbegin();  // last element of _ list
  double t=double(*it++);
  while (t<DBL_MAX-RADIX && it!=_.rend())
    t = RADIX*t + double(*it++);
  if (it==_.rend()) return (_neg?-t:t);
  else return 0.0;
}

// FIX:  ***************************************************
string Integer::toString() const
{ if (_.empty()) return "NAI";
  string s=(_neg?"-":"");
  Integer::CRIt it=_.rbegin();  // last element of _ list
  s += Integer::toString(*it++);
  while ( it!=_.rend())
    s += Integer::pad(Integer::toString(*it++));
  return s;
}

bool Integer::isNegative() const
{ return _neg;
}

//////////////////////////////////////////////////////////////////////
//  protected member functions:

string Integer::pad(string s)
{ if (s.length()>=WIDTH) return s;
  return string(WIDTH-s.length(),'0') + s; 
}

Integer Integer::NotAnInteger()  // not an integer
{ Integer z;
  z._.clear();      // empty list
  return z;
}

int Integer::toInt(string s)
{ int len=s.length(), n=0, k;
  for (int i=0; i<len; i++)
    if (!isdigit(s[i])) return 0;
  for (k=0; k<len; k++)  // remove leading 0s
    if (s[k]!='0') break; 
  s = s.substr(k);
  if (s.empty()) return 0;
  istringstream in(s);
  in >> n;
  return n;
}

string Integer::toString(int n)
{ ostringstream out;
  out << n;
  return out.str();
}

Integer Integer::toInteger(string s)
{ Integer x=NotAnInteger();
  if (s.empty() || s=="NAI") return x;
  if (s[0]=='-')
  { x._neg = true;
    s = s.substr(1);
  }
  for (int i=0; i<s.length(); i++)
    if (!isdigit(s[i])) return NotAnInteger();
  for (int len=s.length(); len>WIDTH; len -= WIDTH)
  { x._.push_back(Integer::toInt(s.substr(len-WIDTH)));  // last 4 digits
    s = s.substr(0,len-WIDTH);  // truncate last 4 digits
  }
  x._.push_back(Integer::toInt(s));
  return x;
}

//////////////////////////////////////////////////////////////////////
//  static constants:

const Integer Integer::ZERO(0);
const Integer Integer::ONE(1);
const Integer Integer::NAI("NAI");       // Not An Integer
const int Integer::WIDTH=4;              // 4 digits per list element
const int Integer::RADIX=pow(10,WIDTH);  // 10^4=10,000
