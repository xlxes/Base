#include "pch.h"
#include "golf.h"
#include <iostream>



Golf::Golf()
{
	strcpy_s(fullname,8,"No name");
	handicap = 0;
}

Golf::Golf(const char* name, int hc)
{
	strcpy_s(fullname, sizeof(name), name);
	handicap = hc;
}

Golf::~Golf()
{
}

const Golf& Golf::setgolf(const Golf& g)
{
	strcpy_s(fullname,sizeof(g.fullname), g.fullname);
	handicap = g.handicap;
	return *this;
}

void Golf::showgolf()
{
	using std::cout;
	using std::endl;
	cout << "Golfer : " << fullname << endl;
	cout << "handicap : " << handicap << endl;
}