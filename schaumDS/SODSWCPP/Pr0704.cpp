//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.4 on page 147
//  The *(polynomial,polynomial) operator for the Polynomial class

Polynomial operator*(const Polynomial& p1, const Polynomial& p2)
{ Polynomial p;
  p._degree = p1._degree + p2._degree;
  for (Polynomial::CIt it1=p1._terms.begin();
       it1!=p1._terms.end(); it1++)
    for (Polynomial::CIt it2=p2._terms.begin();
         it2!=p2._terms.end(); it2++)
    { int exp = it1->_exp + it2->_exp;
      double coef = it1->_coef * it2->_coef;
      Polynomial::It it=p._terms.begin();
      for ( ; it != p._terms.end(); it++)
        if (it->_exp <= exp) break;
      if (it->_exp == exp) it->_coef += coef;
      else p._terms.insert(it,Polynomial::Term(coef,exp));
    }
  p.reduce();
  return p;
}
