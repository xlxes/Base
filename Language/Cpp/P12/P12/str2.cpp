#include "pch.h" 
#include <cstring>
#include "str2.h"
#include <iostream>

using namespace std;

int str2::num_strings = 0;

int str2::howmany()			//返回字符数量
{
	return num_strings;
}

str2::str2(const char* s)		//从char指针构造函数
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len+1, s);
	num_strings++;
}

str2::str2()		//默认构造函数
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

str2::str2(const str2& st)		//深度复制构造函数
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len+1, st.str);
}

str2::~str2()
{
	num_strings--;
	delete[] str;
}

str2& str2::operator=(const str2& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len+1, st.str);
	return *this;
}

str2& str2::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len+1, s);
	return *this;
}

char& str2::operator[](int i)
{
	return str[i];
}

const char& str2::operator[](int i) const
{
	return str[i];
}

bool operator<(const str2 &st1, const str2 &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const str2 &st1, const str2 &st2)
{
	return (std::strcmp(st1.str, st2.str) > 0);
}

bool operator==(const str2 &st1, const str2 &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const str2& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, str2& st)
{
	char temp[str2::CINLIM];
	is.get(temp, str2::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

void str2::str2low()
{
	for (int i = 0; i < len; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void str2::str2up()
{
	for (int i = 0; i < len; i++)
	{
		str[i] = toupper(str[i]);
	}
}

int str2::has(const char a) const 
{
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		if (a == str[i])
			num++;
	}
	return num;
}

str2 operator+(const str2& f1, const str2 f2)
{
	char* nf = new char[f1.len + f2.len + 1];
	strcpy_s(nf, f1.len + 1, f1.str);
	strcpy_s(nf+f1.len, f2.len + 1, f2.str);
	return str2(nf);		//此处返回实际的构造对象
}