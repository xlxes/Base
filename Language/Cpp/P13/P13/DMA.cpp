#include "pch.h"
#include "DMA.h"
#include <iostream>
#include <cstring>

using namespace std;

ABC::ABC()
{};

ABC::~ABC()
{};

baseDMA::baseDMA(const char* i, int r)
{
	unsigned int len;
	len = strlen(i);
	label = new char[len+ 1];
	strcpy_s(label, len + 1, i);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)
{
	unsigned int len;
	len = strlen(rs.label);
	label = new char[len + 1];
	strcpy_s(label, len + 1, rs.label);
	rating = rs.rating;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	unsigned int len;
	len = strlen(rs.label);
	label = new char[len + 1];
	strcpy_s(label, len + 1, rs.label);
	rating = rs.rating;
	return *this;
}

ostream& operator<<(ostream& os, const baseDMA& rs)
{
	os << "Label : " << rs.label << endl;
	os << "Rareing : " << rs.rating << endl;
	return os;
}

void baseDMA::View()
{
	cout << "Label : " << label << endl;
	cout << "Rating : " << rating << endl;
}

lacksDMA::lacksDMA(const char* c, const char* i, int r) :baseDMA(i, r)
{
	strncpy_s(color, 40, c, col_len - 1);
	color[col_len - 1] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs) :baseDMA(rs)
{
	strncpy_s(color, 40, c, col_len - 1);
	color[col_len - 1] = '\0';
}

ostream& operator<<(ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;	//使用基类的方法输出基类部分
	os << "Color : " << ls.color << endl;
	return os;
}

void lacksDMA::View()
{
	baseDMA::View();
	cout << "Color : " << color << endl;
}

hasDMA::hasDMA(const char * s, const char * i, int r) :baseDMA(i, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const baseDMA & rs) :baseDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

//对于派生类的复制构造函数，可以不用从头构建，直接使用基类的，加上新的成员变量
hasDMA::hasDMA(const hasDMA& hs) :baseDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);
	delete[] style;
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	return *this;
}

ostream& operator<<(ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;	//使用基类的方法输出基类部分
	os << "Style : " << hs.style << endl;
	return os;
}

void hasDMA::View()
{
	baseDMA::View();
	cout << "Style : " << style << endl;
}