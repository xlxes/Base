#include "pch.h"
#include "port.h"
#include <iostream>
#include <cstring>

static void cpstr(char* p_des_txt, const char* p_src_txt, unsigned des_arr_size)
{
	unsigned str_len = strlen(p_src_txt) < des_arr_size ? strlen(p_src_txt) : des_arr_size - 1;
	strcpy_s(p_des_txt, str_len+1,p_src_txt);
	p_des_txt[str_len] = '\0';
}

port::port(const char* br, const char* st, int b) 
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strcpy_s(style, 20, st);
	bottles = b;
}

port::port(const port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, 20, p.style);
	bottles = p.bottles;
}

port& port::operator=(const port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, 20, p.style);
	bottles = p.bottles;
	return *this;
}

port& port::operator+=(int b)
{
	bottles += b;
	return *this;
}

port& port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void port::show() const
{
	cout << "brand: " << brand << endl;
	cout << "style: " << style << endl;
	cout << "bottle: " << bottles << endl;
}

ostream& operator<<(ostream& os, const port& p)
{
	os << p.brand << " , " << p.style << " , " << p.bottles;
	return os;
}

//vintageport¶¨Òå

vintageport::vintageport()
{
	nickname = new char[5];
	strcpy_s(nickname, 5, "none");
	year = 0;
}

vintageport::vintageport(const char* br, int b, const char* nn, int y) :port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
	year = y;
}

vintageport::vintageport(const vintageport& vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}

vintageport& vintageport::operator=(const vintageport& vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
	return *this;
}

void vintageport::show() const
{
	port::show();
	cout << "nickname: " << nickname << endl;
	cout << "year: " << year << endl;
}

ostream& operator<<(ostream& os, const vintageport& vp)
{
	os << (const port&)vp;
	os << " , " << vp.nickname << " , " << vp.year;
	return os;
}