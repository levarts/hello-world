﻿#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double F(double, double, double);
void solve(int, int, int, int, double);
void print(double*, double*, double*, int, double);

int main()
{
	int a = 3, b = 4; 

	int y = 2, y1 = 2;
	
	double h1 = 0.1;
	double h2 = 0.01;
	double h3 = 0.002;

	solve(a, b, y, y1, h1);
	solve(a, b, y, y1, h2);
	solve(a, b, y, y1, h3);

	return 0;
}

double F(double x, double y1, double y)
{
	return (3 * y + (x - 2)*y1) / ((x - 2)*(x - 2));
}

void solve(int a, int b, int y, int y1, double h)
{
	const int n = (b - a) / h + 1;
	double X[n], Y[n], Y1[n]; 
	X[0] = a; Y[0] = y, Y1[0] = y1;
	
	int n = (b - a) / h + 1;

	X[0] = a, Y[0] = y, Y1[0] = y1;

	for (int i = 1; i < n; i++)
	{
		Y1[i] = Y1[i - 1] + h*F(X[i - 1], Y1[i - 1], Y[i - 1]);
		Y[i] = Y[i - 1] + h*Y1[i - 1]; 
		X[i] = X[i - 1] + h;
	}

	print(X, Y, Y1, n, h);
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