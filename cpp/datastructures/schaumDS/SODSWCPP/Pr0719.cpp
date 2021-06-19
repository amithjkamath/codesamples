//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.19 on page 148
//  Relational operators for the Integer class

bool Integer::operator!=(const Integer& x) const
{ return !(*this == x);
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
