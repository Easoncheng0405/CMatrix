#pragma once
#include <iostream>
using namespace std;
class CMatrix
{
private:
	int** arr;
	int row, column;
public:
	CMatrix();                     //默认构造函数
	CMatrix(int n);                //n行n列
	CMatrix(int n, int m);         //n行m列
	CMatrix(const CMatrix& matrix);//拷贝构造函数
	~CMatrix();                    //析构函数

	CMatrix& operator +(const CMatrix& matrix);   //矩阵之间的加法运算
	CMatrix& operator +=(const CMatrix& matrix);  //矩阵之间自加运算
	CMatrix& operator -(const CMatrix& matrix);   //矩阵之间的减法运算
	CMatrix& operator -=(const CMatrix& matrix);  //矩阵之间自减运算
	CMatrix& operator *(const CMatrix& matrix);   //矩阵间的乘法运算
	CMatrix& operator *(int v);                   //矩阵与整数的预算
	CMatrix& operator *=(const CMatrix& matrix);  //矩阵之间的自乘运算
	CMatrix& operator *=(int v);                  //矩阵与整数的自乘运算
	CMatrix& operator /=(int v);                  //矩阵与整数的自除运算
	CMatrix& operator /(int v);
	CMatrix& operator =(const CMatrix& matrix);   //矩阵的赋值
	bool operator ==(const CMatrix& matrix);      //判断两个矩阵是否相等
	inline int* operator [](int index)            //重载[]运算符获得与二维数组同样的操作效果
	{ return arr[index]; }
	//重载输入输出
	friend ostream & operator<<(ostream &out, CMatrix &obj);
	friend istream & operator >> (istream &in, CMatrix &matrix);
	
	

	
	void setRow(int row, int v);					//将第row行赋值v
	void setColumn(int column, int v);			//将第column列赋值v
	void setAll(int v);							//将矩阵全部赋值为v
	inline int** getArr() { return arr; }       //获取二维数组头指针
	CMatrix& turn();                            //转置矩阵
	void freeArr(int** arr,int r);
};

