#include "pch.h"
#include <iostream>
#include <string>
#include "Person.h"

Person::Person(const string &ln, const char *fn)
{
	lname = ln;
	strcpy_s(fname, LIMIT, fn);
}

Person::~Person()
{}

void Person::Show()const
{
	using std::cout;
	using std::endl;
	cout << "name is : " << lname << endl;
}

void Person::FormalShow()const
{
	using std::cout;
	using std::endl;
	cout << "all name is : " << lname << " , " << fname << endl;
}