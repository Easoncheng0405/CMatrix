#include "stdafx.h"
#include "CMatrix.h"

CMatrix::CMatrix()
{
	row = column = 0;
	arr = nullptr;
}
CMatrix::CMatrix(const CMatrix & matrix)
{
	freeArr(arr, row);
	row = matrix.row, column = matrix.column;
	arr = new int*[row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[column]();

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = matrix.arr[i][j];
}

CMatrix::CMatrix(int n)
{
	row = column = n;
	arr = new int*[row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[column]();
}

CMatrix::CMatrix(int n, int m)
{
	row = n, column = m;
	arr = new int*[row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[column]();
}

CMatrix::~CMatrix()
{
	freeArr(arr, row);
}


CMatrix & CMatrix::operator+(const CMatrix & matrix)
{
	CMatrix* tmp=new CMatrix(matrix.row, matrix.column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			tmp->arr[i][j] = arr[i][j] + matrix.arr[i][j];
	return *tmp;
}

CMatrix & CMatrix::operator-(const CMatrix & matrix)
{
	CMatrix* tmp=new CMatrix(matrix.row, matrix.column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			tmp->arr[i][j] = arr[i][j] - matrix.arr[i][j];
	return *tmp;
}

CMatrix & CMatrix::operator*(const CMatrix & matrix)
{
	CMatrix* tmp = new CMatrix(row,matrix.column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < matrix.column; j++)
			for (int k = 0; k < column; k++)
				tmp->arr[i][j] = tmp->arr[i][j] + arr[i][k] * matrix.arr[k][j];
	return *tmp;
}
CMatrix & CMatrix::operator*(int v)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] *= v;
	return *this;
}
CMatrix & CMatrix::operator/=(int v)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] /= v;
	return *this;
}

CMatrix & CMatrix::operator/(int v)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] /= v;
	return *this;
}


CMatrix& CMatrix::operator=(const CMatrix & matrix)
{
	freeArr(arr, row);
	row = matrix.row, column = matrix.column;
	arr = new int*[row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[column];
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = matrix.arr[i][j];
	return *this;

}

CMatrix& CMatrix::operator +=(const CMatrix & matrix)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] += matrix.arr[i][j];
	return *this;
}

CMatrix & CMatrix::operator*=(const CMatrix & matrix)
{
	int** tmp = new int*[row];
	for (int i = 0; i < row; i++)
		tmp[i] = new int[matrix.column]();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < matrix.column; j++)
			for (int k = 0; k < column; k++)
				tmp[i][j] += arr[i][k] * matrix.arr[k][j];
	freeArr(arr, row);
	this->arr = tmp;
	column = matrix.column;
	return *this;
}

CMatrix& CMatrix::operator -=(const CMatrix & matrix)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] -= matrix.arr[i][j];
	return *this;
}


CMatrix& CMatrix::operator*=(int v)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] *= v;
	return *this;
}


bool CMatrix::operator==(const CMatrix & matrix)
{
	if (row != matrix.row || column != matrix.column)
		return false;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (arr[i][j] != matrix.arr[i][j])
				return false;
	return true;
}


void CMatrix::setRow(int row, int v)
{
	if (row<0 || row>this->row)
		return;
	for (int i = 0; i < row; i++)
		arr[row][i] = v;
}

void CMatrix::setColumn(int column, int v)
{
	if (column<0 || column>this->column)
		return;
	for (int i = 0; i < column; i++)
		arr[i][column] = v;
}

void CMatrix::setAll(int v)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = v;

}

CMatrix & CMatrix::turn()
{
	int **tmp = new int*[column];
	for (int i = 0; i < column; i++)
		tmp[i] = new int[row]();
	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++)
			tmp[i][j] = arr[j][i];
	freeArr(arr, row);
	swap(row, column);
	this->arr = tmp;
	return *this;
}

ostream & operator<<(ostream & out, CMatrix & matrix)
{
	for (int i = 0; i < matrix.row; i++)
	{
		for (int j = 0; j < matrix.column; j++)
			out << matrix.arr[i][j] << " ";
		out << endl;
	}
	return out;
}

istream & operator>>(istream & in, CMatrix & matrix)
{
	for (int i = 0; i < matrix.row; i++)
		for (int j = 0; j < matrix.column; j++)
			in >> matrix.arr[i][j];
	return in;
}

void CMatrix::freeArr(int** arr,int r)
{
	if (!arr)
		return;
	for (int i = 0; i < r; i++)
			delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}
