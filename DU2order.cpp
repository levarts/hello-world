#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double F(double, double, double);
void solve(int, int, int, int, double);
void print(double*, double*, double*, int, double);

int main()
{
	int a = 3, b = 4; //отрезок

	int y = 2, y1 = 2; //начальные условия для ф-ции Y и ее производной Y1

	double h1 = 0.1; //шаг решения
	double h2 = 0.01;
	double h3 = 0.002;

	solve(a, b, y, y1, h1);
	solve(a, b, y, y1, h2);
	solve(a, b, y, y1, h3);

	return 0;
}

double F(double x, double y1, double y) //это выраженное y''
{
	return (3 * y + (x - 2)*y1) / ((x - 2)*(x - 2));
}

void solve(int a, int b, int y, int y1, double h) //решение методом эйлера
{
	const int n = (b - a) / h + 1;
	double X[n], Y[n], Y1[n]; 
	X[0] = a; Y[0] = y, Y1[0] = y1;
	
	/*константа должна быть на этапе компиляции уже, а в данном случае она зависит от переменных.
	Соответсвенно выходом является создание динимических массивов*/
	
	int n = (b - a) / h + 1;

	/*double* X = new double[n];
	double* Y = new double[n];
	double* Y1 = new double[n];*/

	X[0] = a, Y[0] = y, Y1[0] = y1;

	for (int i = 1; i < n; i++)
	{
		Y1[i] = Y1[i - 1] + h*F(X[i - 1], Y1[i - 1], Y[i - 1]);
		Y[i] = Y[i - 1] + h*Y1[i - 1];  //значения искомой функции Y
		X[i] = X[i - 1] + h;
	}

	print(X, Y, Y1, n, h);
	
	/*delete[] X;
	delete[] Y;
	delete[] Y1;*/
}

void print(double* X, double* Y, double* Y1, int n, double h)
{
	cout << "solution of a second-order differential equation with step = " << h << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "X[" << i << "]=" << X[i] << " " << "  Y[" << i << "]=" << Y[i] << "  DY[" << i << "]=" << Y1[i] << endl;
	}
	cout << endl;
}