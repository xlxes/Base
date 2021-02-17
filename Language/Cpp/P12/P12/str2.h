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
	//扩展
	void str2low();	//字母变小写
	void str2up();	//字母变大写
	int has(const char a) const;
	friend str2 operator+(const str2& f1, const str2 f2);
	//重载
	str2& operator=(const str2& st);
	str2& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i)const;
	//友元
	friend bool operator<(const str2& s1, const str2& s2);
	friend bool operator>(const str2& s1, const str2& s2);
	friend bool operator==(const str2& s1, const str2& s2);
	friend ostream& operator<<(ostream& os, const str2& s1);
	friend istream& operator>>(istream& is, str2 &s1);

	static int howmany();
};
