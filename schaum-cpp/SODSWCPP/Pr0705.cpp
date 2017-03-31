//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.5 on page 147
//  Assignment operators for the Polynomial class

Polynomial& Polynomial::operator+=(const Polynomial& p)
{ *this = *this + p;
  return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& p)
{ *this = *this - p;
  return *this;
}
Polynomial& Polynomial::operator*=(const double x)
{ *this = x * *this;
  return *this;
}
Polynomial& Polynomial::operator*=(const Polynomial& p)
{ *this = *this * p;
  return *this;
}
