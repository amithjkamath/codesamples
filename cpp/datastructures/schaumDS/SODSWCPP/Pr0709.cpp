//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.9 on page 148
//  Derivative and antiderivative functions for the Polynomial class

Polynomial derivative(const Polynomial& p1)
{ if (p1._degree < 0) return Polynomial::ZERO;
  Polynomial p;
  p._degree = ( p1._degree>1 ? p1._degree - 1 : 0);
  for (Polynomial::CIt it=p1._terms.begin();
       it!=p1._terms.end(); it++)
    if (it->_exp>0) p._terms.push_back(derivative(*it));
  return p;
}
Polynomial antiderivative(const Polynomial& p1)
{ Polynomial p;
  p._degree = p1._degree + 1;
  for (Polynomial::CIt it=p1._terms.begin(); it!=p1._terms.end(); 
       it++)
    p._terms.push_back(antiderivative(*it));
  return p;
}
