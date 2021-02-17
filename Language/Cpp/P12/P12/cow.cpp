#include "pch.h"
#include "cow.h"
#include <iostream>
#include <cstring>

using namespace std;

cow::cow()
{}

cow::cow(const char*nm, const char* ho, double wt)
{
	strcpy_s(name, strlen(nm) + 1, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	weight = wt;
}

cow::cow(const cow& c)
{
	strcpy_s(name, strlen(c.name) + 1, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
}

cow::~cow()
{
	delete[] hobby;
}

cow& cow::operator=(const cow& c)
{
	if (this == &c)
		return *this;
	delete[] hobby;
	strcpy_s(name, strlen(c.name) + 1, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
	return *this;
}

void cow::showcow() const
{
	cout << "name :" << name << endl;
	cout << "hobby :" << hobby << endl;
	cout << "weight :" << weight << endl;
}