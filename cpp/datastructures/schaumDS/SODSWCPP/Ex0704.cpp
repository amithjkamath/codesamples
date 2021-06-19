//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 7.4 on page 131
//  Implementation of a Polynomial class: Polynomial.cpp

#include "Polynomial.h"

ostream& operator<<(ostream& ostr, const Polynomial::Term& term)
{ if (term._exp == 0) return ostr << term._coef;
  if (term._coef == 1.0) ostr << "x";
  else if (term._coef == -1.0) ostr << "-x";
  else ostr << term._coef << "x";
  if (term._exp == 1) return ostr;
  else return ostr << "^" << term._exp;
}

Polynomial::Term::Term(double coef, unsigned exp)
  : _coef(coef), _exp(exp) {}

bool Polynomial::Term::operator==(const Term& t) const
{ return _exp == t._exp && _coef == t._coef;
}

bool Polynomial::Term::operator<(const Term& t) const
{ return _exp > t._exp;  // sort terms in decreasing order
}

ostream& operator<<(ostream& ostr, const Polynomial& p)
{ if (p == Polynomial::ZERO) return ostr << 0;
  Polynomial::CIt it=p._terms.begin();
  ostr << *it++;
  while (it != p._terms.end())
    ostr << " + " << *it++;
  return ostr;
}

Polynomial operator*(const double x, const Polynomial& p1)
{ if (x == 0.0) return Polynomial::ZERO;
  Polynomial p(p1);
  for (Polynomial::It it=p._terms.begin(); it != p._terms.end(); it++)
    it->_coef *= x;
  return p;
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
{ Polynomial p;
  p._degree = max(p1._degree,p2._degree);
  p._terms = Polynomial::TermList(p1._terms.size()+p2._terms.size());
  merge(p1._terms.begin(),p1._terms.end(),
        p2._terms.begin(),p2._terms.end(),
        p._terms.begin());
  p.reduce();
  return p;
}

Polynomial::Polynomial(double coef, unsigned exp)
{ if (coef == 0.0)  // the "zero polynomial" has degree -1
  { _terms = TermList(0);
    _degree = -1;
  }
  else
  { _terms = TermList(1,Term(coef,exp));
    _degree = exp;
  }
}

Polynomial::Polynomial(const Polynomial& p)
  : _degree(p._degree), _terms(TermList(p._terms)) { }

Polynomial& Polynomial::operator=(const Polynomial& p)
{ _degree = p._degree;
  _terms = TermList(p._terms);
}

bool Polynomial::operator==(const Polynomial& p) const
{ return _terms == p._terms;
}

double Polynomial::operator()(double x) const
{ CIt it=_terms.begin();
  if (it == _terms.end()) return 0.0;
  double y=it->_coef;
  unsigned e1=it->_exp;
  while (++it != _terms.end())
  { int e2=it->_exp;
    y *= pow(x,e1-e2);
    y += it->_coef;
    e1 = e2;
  }
  return y*pow(x,e1);
}

long Polynomial::degree() const
{ if (*this == ZERO) return -1;  // the zero polynomial
  return _degree;
}

unsigned Polynomial::terms() const
{ return _terms.size();
}

void Polynomial::reduce()
{ // collects terms and removes those with coefficient equal to 0.0
  if (*this == ZERO) return;
  Polynomial::It it1=_terms.begin(), it2=_terms.begin();
  while (it1 != _terms.end())
  { while (++it2 != _terms.end() && it2->_exp == it1->_exp)
      it1->_coef += it2->_coef; 
    if (it1->_coef == 0.0) _terms.erase(it1,it2);
    else _terms.erase(++it1,it2);
    it1 = it2;
  }
  if (_terms.size() == 0) _degree = -1;
  else _degree = _terms.begin()->_exp;
}

const Polynomial Polynomial::ZERO(0.0);   // the "zero polynomial"
