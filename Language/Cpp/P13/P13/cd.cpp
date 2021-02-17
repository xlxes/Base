#include "pch.h"
#include "cd.h"
#include <iostream>
#include <cstring>

using namespace std;

//题1
////复制字符串并加上'\0'
//static void cpstr(char* p_des_txt, const char* p_src_txt, unsigned des_arr_size)
//{
//	unsigned str_len = strlen(p_src_txt) < des_arr_size ? strlen(p_src_txt) : des_arr_size - 1;
//	strcpy_s(p_des_txt, str_len+1,p_src_txt);
//	p_des_txt[str_len] = '\0';
//}
//
////初始化
//Cd::Cd(const char* s1, const char* s2, int n, double x) :selections(n), playtime(x)
//{
//	cpstr(performers, s1, 50);
//	cpstr(label, s2, 20);
//}
//
//
//
//void Cd::Report() const
//{
//	cout << performers << " , " << label << " , " << selections << " , " << playtime;
//}
//
//Classic::Classic(const char* songs_list,const char* s1,const char* s2,int n,double x):Cd(s1,s2,n,x)
//{
//	cpstr(m_songs, songs_list, mk_size);
//};
//
//void Classic::Report() const
//{
//	Cd::Report();
//	cout << " , " << m_songs << endl;
//}

static char* cpNewStr(const char* p_src_txt)
{
	unsigned str_len = strlen(p_src_txt);
	char* p_des_txt = new char[str_len + 1];
	strcpy_s(p_des_txt, str_len + 1, p_src_txt);
	return(p_des_txt);
}


//基类
Cd::Cd(const char* s1, const char* s2, int n, double x) :selections(n), playtime(x)
{
	performers = cpNewStr(s1);
	label = cpNewStr(s2);
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

//深度复制构造函数
Cd::Cd(const Cd& d) :selections(d.selections), playtime(d.playtime)
{
	performers = cpNewStr(d.performers);
	label = cpNewStr(d.label);
}

Cd& Cd::operator=(const Cd& d)
{
	if (&d == this)
		return *this;
	delete[] performers;
	performers = cpNewStr(d.performers);
	delete[] label;
	label = cpNewStr(d.label);
	selections = d.selections;
	playtime = d.playtime;
	return (*this);
}

void Cd::Report() const
{
	cout << performers << " , " << label << " , " << selections << " , " << playtime;
}

//派生类
Classic::Classic(const char* song_list, const char* s1, const char* s2, int n, double x):Cd(s1,s2,n,x)
{
	songs = cpNewStr(song_list);
}

Classic::Classic(const Classic& c):Cd(c)
{
	songs = cpNewStr(c.songs);
}

Classic::~Classic()
{
	delete[] songs;
}

Classic& Classic::operator=(const Classic& c)
{
	if (&c == this)
		return *this;
	Cd::operator=(c);	//此句话重要 用于复制基类部分
	delete[] songs;
	songs = cpNewStr(c.songs);
	return (*this);
}

void Classic::Report() const
{
	Cd::Report();
	cout << " , " << songs << endl;
}