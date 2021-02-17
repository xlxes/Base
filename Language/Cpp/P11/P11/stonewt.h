#ifndef STONEWT_H_
#define STONEWT_H_

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Stonewt
{
public:
	enum Mode { STN, INPD, FPD };	//英石格式 整数磅格式 浮点磅格式
private:
	enum {Lbs_per_stn = 14};
	int stone;			//英石
	double pds_left;	//磅转英石 存留下来的英石
	double pounds;		//磅
	int pounds_int;		//磅的整数部分
	Mode mode;
	void set_stn();
	void set_pds();
	void set_pds_int();
public:
	Stonewt(double lbs, Mode form);
	Stonewt(int stn, double lbs, Mode form);
	Stonewt();
	~Stonewt();
	void stn_mode();
	void pds_mode();
	void int_pds_mode();

	operator int() const;	//int()强制转换
	operator double()const;	//double()强制转换
	//运算符重载
	Stonewt operator+(const Stonewt& st)const;
	Stonewt operator-(const Stonewt& st)const;
	Stonewt operator*(double n)const;
	//友元函数
	friend Stonewt operator*(double n, const Stonewt& st);
	friend ostream& operator<<(ostream& os, const Stonewt& st);

};

#endif // !STONEWT_H_

