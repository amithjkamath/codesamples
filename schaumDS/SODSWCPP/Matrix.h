//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Matrix.h
//  Interface for Matrix class template

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

template <int I=1, int J=1> class Matrix
{   friend Matrix<I,J> operator-(const Matrix<I,J>&);
    friend Matrix<I,J> operator*(const double, const Matrix<I,J>&);
    friend Matrix<I,J> operator+(const Matrix<I,J>&, const Matrix<I,J>&);
    friend Matrix<I,J> operator-(const Matrix<I,J>&, const Matrix<I,J>&);
    friend Matrix<I,J> operator*(const Matrix<I,K>&, const Matrix<K,J>&);
  public:
    Matrix();                                    // default constructor
    Matrix(const Matrix<I,J>&);                  // copy constructor
    ~Matrix();                                   // destructor
    Matrix<I,J>& operator=(const Matrix<I,J>&);  // assignment operator
    bool operator==(const Matrix<I,J>&) const;   // equality operator
    bool operator!=(const Matrix<I,J>&) const;   // inequality operator
    double& operator()(int,int);                 // subscripting operator
    double operator()(int,int) const;            // subscripting operator
    int rows() const;
    int columns() const;
    string toString() const;
    void load(const double*, int);
//    Matrix<1,J,double> row(int) const;
//    Matrix<I,1,double> column(int) const;
  protected:
    double* _;
};

#endif  // MATRIX_H
