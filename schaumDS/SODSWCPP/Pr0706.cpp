//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.6 on page 147
//  The !=(term) operator for the Polynomial class

bool Polynomial::Term::operator!=(const Term& t) const
{ return _exp != t._exp || _coef != t._coef;
}
