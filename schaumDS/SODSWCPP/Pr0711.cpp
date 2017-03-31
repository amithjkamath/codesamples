//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.11 on page 148
//  An improved output operator the Polynomial class

Polynomial::Term abs(const Polynomial::Term& t)
{ Polynomial::Term term(t);
  if (term._coef < 0) term._coef *= -1.0;
  return term;
}
ostream& operator<<(ostream& ostr, const Polynomial& p)
{ if (p == Polynomial::ZERO) return ostr << 0;
  Polynomial::CIt it=p._terms.begin();
  ostr << *it++;
  while (it != p._terms.end())
    if (it->_coef < 0) ostr << " - " << abs(*it++);
    else ostr << " + " << *it++;
  return ostr;
}
