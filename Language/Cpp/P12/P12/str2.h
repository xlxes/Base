#pragma once
#include <iostream>

using namespace std;

class str2
{
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	str2(const char* s);
	str2();
	str2(const str2& st);
	~str2();
	int length() const { return len; }
	//��չ
	void str2low();	//��ĸ��Сд
	void str2up();	//��ĸ���д
	int has(const char a) const;
	friend str2 operator+(const str2& f1, const str2 f2);
	//����
	str2& operator=(const str2& st);
	str2& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i)const;
	//��Ԫ
	friend bool operator<(const str2& s1, const str2& s2);
	friend bool operator>(const str2& s1, const str2& s2);
	friend bool operator==(const str2& s1, const str2& s2);
	friend ostream& operator<<(ostream& os, const str2& s1);
	friend istream& operator>>(istream& is, str2 &s1);

	static int howmany();
};
