//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.1 on page 147
//  The -(term) operator for the Polynomial class

Polynomial::Term operator-(const Polynomial::Term& term)
{ Polynomial::Term t(term);
  t._coef *= -1.0;
  return t;
}
