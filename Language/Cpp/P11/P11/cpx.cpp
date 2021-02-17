#include "pch.h"
#include "cpx.h"
#include <iostream>

cpx::cpx()
{
	real = 0.0;
	imag = 0.0;
}

cpx::cpx(double n1)
{
	real = n1;
	imag = 0.0;
}

cpx::cpx(double n1, double n2)
{
	real = n1;
	imag = n2;
}

cpx::~cpx()
{
}

cpx cpx::operator+(const cpx& c)const
{
	return cpx(real + c.real, imag + c.imag);
}

cpx cpx::operator-(const cpx& c)const
{
	return cpx(real - c.real, imag - c.imag);
}

cpx cpx::operator*(double n)const
{
	return cpx(real * n, imag * n);
}
cpx cpx::operator*(const cpx& c)const
{
	double real_s;
	double imag_s;
	real_s = real * c.real - imag * c.imag;
	imag_s = real * c.imag + imag * c.real;
	return cpx(real_s, imag_s);
}

cpx cpx::operator~()const
{
	return cpx(real, -imag);
}

cpx operator*(double n, const cpx& c)
{
	return cpx(n*c.real, n*c.imag);
}

ostream& operator<<(ostream& os, const cpx& c)
{
	os << "(" << c.real << "," << c.imag << "i)" << endl;
	return os;
}

istream& operator>>(istream& is, cpx& c)		//注意一定要用&符号!!!
{
	cout << "real: ";
	if (is >> c.real)
	{
		cout << "imag: ";
		is >> c.imag;
	}
	return is;
}