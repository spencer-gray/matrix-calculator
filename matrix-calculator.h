#ifndef Mat
#define Mat

#include <iostream>
using namespace std;

class Matrix {

public:
	class Proxy {
		friend class Matrix;
	public:
		double& operator[](int col)
		{
			return parent.data[row][col];
		}
	private:
		Proxy(Matrix &parent_, int row_) :
		parent(parent_),
		row(row_)
		{}

		Matrix& parent;
		int row;
	};

	Proxy operator[](int row)
	{
		return Proxy(*this, row);
	}



public:
	int row;
	int col;
	double **data;
	//Constructors
	Matrix();
	Matrix(int r, int c);
	~Matrix();


	void ones();
	void zeros();
	void rand();

	Matrix(const Matrix & m);
	void print();

	//Operators
	Matrix & operator=(const Matrix &m);

	//Scalar Operators
	Matrix operator+(double num);
	Matrix operator+=(double num);
	Matrix operator-(double num);
	Matrix operator-=(double num);
	Matrix operator*(double num);
	Matrix operator*=(double num);
	Matrix operator/(double num);
	Matrix operator/=(double num);

	// Matrix Operators
	Matrix operator+(const Matrix & m);
	Matrix operator+=(const Matrix & m);
	Matrix operator-(const Matrix & m);
	Matrix operator-=(const Matrix & m);
	Matrix& operator*(const Matrix & m);
	Matrix& operator*=(const Matrix & m);
    
    //IO
	friend istream & operator>>(istream &input, Matrix &m);
	friend ostream & operator<<(ostream &ouput, Matrix &m);
};
#endif
