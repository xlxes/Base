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
	enum Mode { STN, INPD, FPD };	//Ӣʯ��ʽ ��������ʽ �������ʽ
private:
	enum {Lbs_per_stn = 14};
	int stone;			//Ӣʯ
	double pds_left;	//��תӢʯ ����������Ӣʯ
	double pounds;		//��
	int pounds_int;		//������������
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

	operator int() const;	//int()ǿ��ת��
	operator double()const;	//double()ǿ��ת��
	//���������
	Stonewt operator+(const Stonewt& st)const;
	Stonewt operator-(const Stonewt& st)const;
	Stonewt operator*(double n)const;
	//��Ԫ����
	friend Stonewt operator*(double n, const Stonewt& st);
	friend ostream& operator<<(ostream& os, const Stonewt& st);

};

#endif // !STONEWT_H_

