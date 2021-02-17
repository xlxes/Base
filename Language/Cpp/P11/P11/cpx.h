#ifndef CPX_H_
#define CPX_H_


#include <iostream>
//#include <string>
#include <stdio.h>
#include <cmath>

using namespace std;

class cpx
{
private:
	double real;
	double imag;

public:
	cpx();
	cpx(double n1);
	cpx(double n1, double n2);
	~cpx();

	cpx operator+(const cpx& c)const;
	cpx operator-(const cpx& c)const;
	cpx operator*(const cpx& c)const;
	cpx operator*(double n)const;
	cpx operator~()const;

	friend cpx operator*(double n, const cpx& c);
	friend ostream& operator<<(ostream& os, const cpx& c);
	friend istream& operator>>(istream& is,cpx& c);
};

#endif // !CPX_H_

