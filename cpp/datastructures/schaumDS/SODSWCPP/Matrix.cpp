#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(int rows, int cols) : _rows(rows), _cols(cols)
{ _a = new T[rows*cols];
}
