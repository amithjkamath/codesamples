//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Matrix2x2.h
//  Interface for Matrix class

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class Matrix
{ // instances represent 2x2 matrices
    friend ostream& operator<<(ostream&, const Matrix&);
    friend Matrix operator-(const Matrix&);
    friend Matrix operator*(const double, const Matrix&);
    friend Matrix operator+(const Matrix&, const Matrix&);
    friend Matrix operator-(const Matrix&, const Matrix&);
    friend Matrix operator*(const Matrix&, const Matrix&);
  public:
    Matrix(double=1.0,double=0.0,double=0.0,double=1.0);
    Matrix(const Matrix&);                 // copy constructor
    Matrix& operator=(const Matrix&);      // assignment operator
    bool operator==(const Matrix&) const;  // equality operator
    bool operator!=(const Matrix&) const;  // inequality operator
    double det() const;
    bool isSingular() const;
    Matrix inverse() const;
    Matrix pow(int) const;
    string toString() const;
    static const Matrix ZERO;      // the 2x2 zero matrix
    static const Matrix IDENTITY;  // the 2x2 identity matrix
  private:
    double _a, _b, _c, _d;
};

#endif  // MATRIX_H
