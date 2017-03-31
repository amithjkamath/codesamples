//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.2 on page 147
//  The -(polynomial) operator for the Polynomial class

Polynomial operator-(const Polynomial& p1)
{ Polynomial p(p1);
  for (Polynomial::It it=p._terms.begin();
       it != p._terms.end(); it++)
    it->_coef *= -1;
  return p;
}
