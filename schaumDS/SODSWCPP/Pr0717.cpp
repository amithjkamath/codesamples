//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.17 on page 148
//  The *(Integer,int) operator for the Integer class

Integer operator*(const Integer& x, int n)
{ return n*x;
}
