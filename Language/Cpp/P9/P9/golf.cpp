#include "pch.h"
#include <iostream>		//һ��Ҫ��pch.h�ļ����ڵ�һ��
#include "golf.h"

using namespace std;


int setgolf(golf &g)
{
	cout << "name : ";
	cin.get(g.fullname, Len);
	if (g.fullname == '\0')
		return 0;
	cout << "handicap : ";
	while (!(cin >> g.handicap))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "please input handicap again!" << endl;
	}
	cin.get();
	return 1;
}

void setgolf(golf &g, const char*name, int hc)
{
	strcpy_s(g.fullname, Len, name);
	g.handicap = hc;
}

void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf &g)
{
	cout << "name : " << g.fullname << endl;
	cout << "handicap : " << g.handicap << endl;
}