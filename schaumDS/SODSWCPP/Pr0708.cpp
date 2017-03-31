//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.8 on page 147
//  Derivative and antiderivative functions for the Polynomial class

Polynomial::Term derivative(const Polynomial::Term& t)
{ if (t._exp == 0) return Polynomial::Term(0.0,0);
  return Polynomial::Term(t._exp*t._coef,t._exp-1);
}
Polynomial::Term antiderivative(const Polynomial::Term& t)
{ if (t._coef == 0) return Polynomial::Term(1.0,0);
  return Polynomial::Term(t._coef/(t._exp+1),t._exp+1);
}
