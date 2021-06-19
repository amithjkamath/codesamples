//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.26 on page 188
//  An inequality operator for the Tree class

bool Tree::operator!=(const Tree& t) const
{ return !(*this == t);
}
