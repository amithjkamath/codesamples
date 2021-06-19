//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Matrix.cp
//  Interface and implementation of Matrix class template

#ifndef MATRIX_H
#define MATRIX_H
#include <iomanip>   // defines setw() function
#include <iostream>  // defines cin and cout objects
#include <sstream>   // defines ostringstream class
using namespace std;

template <int I=1, int J=1, int K=1> class Matrix
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
  private:
    int _rows, _cols;
    double* _;
};

//////////////////////////////////////////////////////////////////////
//  friend functions:

template <int I, int J>
Matrix<I,J> operator-(const Matrix<I,J>& m)
{ Matrix<I,J> mm(m);
  for (int i=0; i<I*J; i++)
    mm._[i] *= -1;
  return mm;
}

template <int I, int J>
Matrix<I,J> operator*(const double c, const Matrix<I,J>& m)
{ Matrix<I,J> mm(m);
  for (int i=0; i<I*J; i++)
    mm._[i] *= c;
  return mm;
}

template <int I, int J>
Matrix<I,J> operator+(const Matrix<I,J>& m1, const Matrix<I,J>& m2)
{ Matrix<I,J> mm(m1);
  for (int i=0; i<I*J; i++)
    mm._[i] += m2._[i];
  return mm;
}

template <int I, int J>
Matrix<I,J> operator-(const Matrix<I,J>& m1, const Matrix<I,J>& m2)
{ Matrix<I,J> mm(m1);
  for (int i=0; i<I*J; i++)
    mm._[i] -= m2._[i];
  return mm;
}

template <int I, int J, int K>
Matrix<I,J> operator*(const Matrix<I,K>& m1, const Matrix<K,J>& m2)
{ Matrix<I,J> mm;
  for (int i=0; i<I; i++)
    for (int j=0; j<J; j++)
      for (int k=0; k<K; k++)
        mm._[J*i+j] += m1._[K*i+k]*m2._[J*k+j];
  return mm;
}

//////////////////////////////////////////////////////////////////////
//  public members:

template <int I, int J, int K>
Matrix<I,J,K>::Matrix()
{ _ = new double[I*J];
  for (int i=0; i<I*J; i++)
    _[i] = 0.0;
}

template <int I, int J, int K>
Matrix<I,J,K>::Matrix(const Matrix<I,J>& m)
{ _ = new souble[I*J];
  for (int i=0; i<I*J; i++)
    _[i] = m._[i];
}

template <int I, int J, int K>
Matrix<I,J,K>::~Matrix()
{ delete [] _;
}

template <int I, int J, int K>
Matrix<I,J>& Matrix<I,J,K>::operator=(const Matrix<I,J>& m)
{ for (int i=0; i<I*J; i++)
    _[i] = m._[i];
  return *this;
}

template <int I, int J, int K>
bool Matrix<I,J,K>::operator==(const Matrix<I,J>& m) const
{ for (int i=0; i<I*J; i++)
    if (_[i] != m._[i]) return false;
 return true;
}

template <int I, int J, int K>
bool Matrix<I,J,K>::operator!=(const Matrix<I,J>& m) const
{ for (int i=0; i<I*J; i++)
    if (_[i] != m._[i]) return true;
 return false;
}

template <int I, int J, int K>
double& Matrix<I,J,K>::operator()(int i, int j)
{ return _[J*i+j];
}

template <int I, int J, int K>
double Matrix<I,J,K>::operator()(int i, int j) const
{ return _[J*i+j];
}

template <int I, int J, int K>
int Matrix<I,J,K>::rows() const
{ return I;
}

template <int I, int J, int K>
int Matrix<I,J,K>::columns() const
{ return J;
}

template <int I, int J, int K>
string Matrix<I,J,K>::toString() const
{ ostringstream out;
  for (int i=0; i<I; i++)
  { for (int j=0; j<J; j++)
      out << setw(8) << _[J*i+j];
    out << "\n";
  }
  return out.str();
}

template <int I, int J, int K>
void Matrix<I,J,K>::load(const double* a, int n)
{ n = (n>I*J?I*J:n);
  for (int i=0; i<n; i++)
    _[i] = a[i];
}
/*
template <int I, int J, int K>
Matrix<I,J> Matrix<I,J,K>::row(int i) const
{ Matrix<I,J> m(1,I);
  for (int j=0; j<I; j++)
    m._[j] = _[I*i+j];
  return m;
}
*/