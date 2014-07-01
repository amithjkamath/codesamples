#ifndef MATRIX_HEADER
#define MATRIX_HEADER

class matrix {

public:
	matrix(int x, int y);
	
	bool isZero();

	int getNumRows() const;
	int getNumCols() const;

	virtual void setVal(double val, int x, int y);
	virtual double getVal(int x, int y) const;

	void display() const;

	matrix operator+(matrix& other);
	matrix operator-(matrix& other);
	matrix operator*(matrix& other);
	matrix operator*(double val);
	friend matrix operator*(double num, matrix& mat);
	//this is an ambiguous overload, even though it is a friend function.
	//friend matrix operator*(matrix& mat, double num);
	~matrix();
	
private:

	void numRows(int n);
	void numCols(int n);
	void setToZero();

	double** myElements;
	int rows;
	int cols;
};

#endif
