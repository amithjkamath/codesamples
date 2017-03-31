//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.15 on page 148
//  An input operator for the Integer class

istream& operator>>(istream& istr, Integer& x)
{ string s;
  istr >> s;
  x = Integer::toInteger(s);
  return istr;
}
