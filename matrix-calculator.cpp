#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Mat.h"
using namespace std;

Matrix::Matrix()
{
	row = 0;
	col = 0;
	data = new double*[row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double[col];
	}
}

// constructor
Matrix::Matrix(int r, int c)
{
	row = r;
	col = c;
	data = new double*[row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double[col];
		for (int j = 0; j < col; j++)
		{
			data[i][j] = 0;
		}
	}

}

// delete memory
Matrix::~Matrix()
{
	for (int i = 0; i < row; i ++)
	{
		delete data[i];
	}
	delete [] data;
}

// Fill matrix with 1's
void Matrix::ones()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = 1;
		}
	}

}

// Fill matrix with 0's
void Matrix::zeros()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = 0;
		}
	}
}

// Fill matrix with random numbers between 0 - 1
void Matrix::rand()
{
	srand (time(NULL));
	double randNUM;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			randNUM = ((double) std::rand() / (RAND_MAX));
			this->data[i][j] = randNUM;
		}
	}
}

// Copy the constructor
Matrix::Matrix(const Matrix & m)
{
	row = m.row;
	col = m.col;
	data = new double *[row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double [col];
		for (int j = 0; j < col; j++)
		{
			data[i][j] = m.data[i][j];
		}
	}
}

// Prints matrix for testing or output
void Matrix::print()
{
	for (int r = 0; r < row; r++)
	{
		for(int c = 0; c < col; c++)
		{
			cout << data[r][c] << ' ';
		}
		cout << endl;
	}
}

// Assigning matrix to another
Matrix& Matrix::operator=(const Matrix & m)
{
	if (this == &m)
		return (*this);
	else if (this->row != m.row && this->col != m.col)
	{
		cerr << "Error: Not the same size" << endl;
		return (*this);
	}
	delete [] data;
	this->row = m.row;
	this->col = m.col;
	this->data = new double *[row];
	for (int i = 0; i < row; i++)
	{
		this->data[i] = new double[col];
		for (int j = 0; j < col; j++)
		{
			this->data[i][j] = m.data[i][j];
		}
	}
	return (*this);
}

//Scalar Arithmatic

Matrix Matrix::operator+(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] + num;
		}
	}
	return (*this);
}

Matrix Matrix::operator+=(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] += num;
		}
	}
	return (*this);
}

Matrix Matrix::operator-(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] - num;
		}
	}
	return (*this);
}

Matrix Matrix::operator-=(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] -= num;
		}
	}
	return (*this);
}

Matrix Matrix::operator*(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] * num;
		}
	}
	return (*this);
}

Matrix Matrix::operator*=(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] *= num;
		}
	}
	return (*this);
}

Matrix Matrix::operator/(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] / num;
		}
	}
	return (*this);
}

Matrix Matrix::operator/=(double num)
{

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = this->data[i][j] /= num;
		}
	}
	return (*this);
}

// Matrix Arithmetic

Matrix Matrix::operator+(const Matrix & m)
{
	if (this->row != m.row && this->col != m.col)
	{
		cerr << "Incorrect size" << endl;
		exit(1);
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j ++)
		{
			this->data[i][j] = this->data[i][j] + m.data[i][j];
		}
	}
	return (*this);
}

Matrix Matrix::operator+=(const Matrix & m)
{
	if (this->row != m.row && this->col != m.col)
	{
		cerr << "Incorrect size" << endl;
		exit(1);
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j ++)
		{
			this->data[i][j] = this->data[i][j] += m.data[i][j];
		}
	}
	return (*this);
}

Matrix Matrix::operator-(const Matrix & m)
{
	if (this->row != m.row && this->col != m.col)
	{
		cerr << "Incorrect size" << endl;
		exit(1);
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j ++)
		{
			this->data[i][j] = this->data[i][j] - m.data[i][j];
		}
	}
	return (*this);
}

Matrix Matrix::operator-=(const Matrix & m)
{
	if (this->row != m.row && this->col != m.col)
	{
		cerr << "Incorrect size" << endl;
		exit(1);
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j ++)
		{
			this->data[i][j] = this->data[i][j] -= m.data[i][j];
		}
	}
	return (*this);
}

Matrix & Matrix::operator*(const Matrix & m)
{
	Matrix temp(row, m.col);
	for (int i = 0; i < temp.row; i++){
		for (int j = 0; j < temp.col; j++){
			for (int k = 0; k < col; k++)
			{
				temp.data[i][j] += (data[i][k] * m.data[k][j]);
			}
		}
	}
	return (*this = temp);
}

Matrix & Matrix::operator*=(const Matrix & m)
{
	Matrix temp(row, m.col);
	for (int i = 0; i < temp.row; i++){
		for (int j = 0; j < temp.col; j++){
			for (int k = 0; k < col; k++)
			{
				temp.data[i][j] += (data[i][k] *= m.data[k][j]);
			}
		}
	}
	return (*this = temp);
}

ostream & operator<<(ostream &output, Matrix &m)
{
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			output << (m.data[i][j]) << " ";
		}
		output << endl;
	}
	return output;
}

istream & operator>>(istream &input, Matrix &m)
{	
	if (!(m.row == 0) && !(m.col == 0)){ 
		cerr << "error: m is not a NULL matrix" << endl; 
		return input;
	}
	cout << "Enter row: ";
	input >> m.row;
	cout << "Enter a column: ";
	input >> m.col;

	m.data = new double*[m.row];
	for(int i = 0; i < m.row; i++)
	{
		m.data[i] = new double[m.col];
	}

	for (int r = 0; r < m.row; r++)
	{
		for(int c = 0; c < m.col; c++)
		{
			cout << "Enter [" << r << "][" << c << "] position: ";
			input >> m.data[r][c];
		}
	}
	

	return input;

}