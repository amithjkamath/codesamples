//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.3 on page 147
//  The -(polynomial,polynomial) operator for the Polynomial class

Polynomial operator-(const Polynomial& p1, const Polynomial& p2)
{ return p1 + -p2;
}
