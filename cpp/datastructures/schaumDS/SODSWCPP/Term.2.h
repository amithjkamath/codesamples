#include <iostream.h>

class Term
{ // instances represent individual terms of a polynomial

    friend ostream& operator<<(ostream&, const Term&);

  public:
	Term() : coef(0.0), exp(0) { }
    Term(double c, int e) : coef(c), exp(e) { }

    double coef;
    int exp;
};

ostream& operator<<(ostream& os, const Term& t)
{ if (t.coef == -1.0) os << "-";
  else if (t.coef != 0.0) os << float(t.coef);
  if (t.exp == 0) os;
  else if (t.exp == 1) os << "x";
  else os << "x^" << t.exp;
  return os;
}
