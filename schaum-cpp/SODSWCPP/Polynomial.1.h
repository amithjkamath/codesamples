#include <iostream.h>

class Term
{ // instances represent individual terms of a polynomial
    friend ostream& operator<<(ostream&, const Term&);
  public:
    Term() : coef(0.0), exp(0) { }
    Term(const Term& t) : coef(t.coef), exp(t.exp), next(t.next) { }
    Term(double c, int e) : coef(c), exp(e) { }
    Term(double c, int e, Term* n) : coef(c), exp(e), next(n) { }
    Term abs();
  public:
    double coef;
    int exp;
    Term* next;
};

class Polynomial
{ // instances represent polynomials; e.g., 4x^7 - 2x + 5
    friend ostream& operator<<(ostream&, const Polynomial&);
  public:
    Polynomial() : term(0), degree(-1) { }
    Polynomial(double c) : term(new Term(c,0)), degree(0) { }
    Polynomial(double c, int d) : term(new Term(c,d)), degree(d) { }
    Polynomial& operator+=(const Term&);
  private:
    Term* term;
    int degree;
};

ostream& operator<<(ostream& os, const Term& t)
{ if (t.coef == -1.0) os << "-";
  else if (t.coef != 0.0) os << float(t.coef);
  if (t.exp == 0) os;
  else if (t.exp == 1) os << "x";
  else os << "x^" << t.exp;
  return os;
}

ostream& operator<<(ostream& os, const Polynomial& p)
{ Term* t = p.term;
  if (!t) return os;
  os << *t;
  t = t->next;
  while (t)
  { if (t->coef < 0.0) os << " - " << t->abs();
    else os << " + " << *t;
    t = t->next;
  }
  return os;
}

Term Term::abs()
{ Term term(-coef,exp);
  return term;
}

Polynomial& Polynomial::operator+=(const Term& t)
{ if (term == 0) term = new Term(t.coef,t.exp,0);
  else if (term->exp == t.exp) term->coef += t.coef;
  else if (term->exp > t.exp) term = new Term(t.coef,t.exp,term);
  else
  { Term* pt = term; 
    while (pt->next && pt->exp < t.exp)
      pt = pt->next;
    pt->next = new Term(t.coef,t.exp,pt->next);
  }
  return *this;
}

