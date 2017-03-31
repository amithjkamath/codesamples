//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.16 on page 148
//  The *(int,Integer) operator for the Integer class

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
