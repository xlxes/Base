#include "pch.h"
#include "plorg.h"
#include <iostream>

Plorg::Plorg(const char* a, int b)
{
	strcpy_s(name, 19, a);
	CI = b;
}

Plorg::~Plorg()
{
}

void Plorg::set_ci(int a)
{
	CI = a;
}

void Plorg::showplorg() const
{
	using std::cout;
	using std::endl;
	cout << "name : " << name << endl;
	cout << "IC : " << CI << endl;
}
