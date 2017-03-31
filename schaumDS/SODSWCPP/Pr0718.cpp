//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.18 on page 148
//  The arithmetic assignment operators for the Integer class

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
