//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.7 on page 147
//  The !=(polynomial) operator for the Polynomial class

bool Polynomial::operator!=(const Polynomial& p) const
{ return _terms != p._terms;
}
