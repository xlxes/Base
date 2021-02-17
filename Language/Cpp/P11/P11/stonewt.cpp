#include "pch.h"
#include "stonewt.h"

void Stonewt::set_stn()	//磅转为英石
{
	stone = int(pounds) / Lbs_per_stn;  //磅转化为英石
	pds_left = int(pounds) % Lbs_per_stn + pounds - int(pounds);//损耗的pounds
}

void Stonewt::set_pds()	//英石转为磅
{
	pounds = stone * Lbs_per_stn + pds_left;
}

void Stonewt::set_pds_int()	//计算磅转换为整数时的损耗
{
	pounds_int = int(pounds);
}

Stonewt::Stonewt(double lbs, Mode form)		//构造函数(单参数-重量) 
{
	mode = form;
	if (mode == STN)	//英石格式
	{
		stone = int(lbs) / Lbs_per_stn;		//得到英石
		pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);	//得到剩余部分英镑
		set_pds();		//得到浮点英镑	
		set_pds_int();	//得到整数损耗
	}
	else if (form == INPD)		//整数磅格式
	{
		pounds_int = int(lbs);	//得到整数英镑
		pounds = lbs;			//得到浮点英镑
		set_stn();				//得到英石
	}
	else if (form == FPD)		//浮点磅格式
	{
		pounds = lbs;		//得到浮点英镑
		set_pds_int();		//得到整数英镑
		set_stn();			//得到英石
	}
	else
	{
		cout << "模式输入错误。\n";
		stone = pounds = pds_left = 0.0;
		mode = STN;
	}
}

Stonewt::Stonewt(int stn, double lbs, Mode form)	//构造函数（双参数）
{
	mode = form;
	if (form == STN)
	{
		stone = stn;
		pds_left = lbs;
		set_pds();
		set_pds_int();
	}
	else if (form == INPD)
	{
		pounds_int = int(stn*Lbs_per_stn + lbs);
		pounds = stn * Lbs_per_stn + lbs;
		set_stn();
	}
	else if (form == FPD)
	{
		pounds = stn * Lbs_per_stn + lbs;
		set_pds_int();
		set_stn();
	}
	else
	{
		cout << "模式输入错误。\n";
		stone = pounds = pds_left = 0;
		mode = STN;
	}
}

Stonewt::Stonewt()	//默认构造函数
{
	stone = pounds = pds_left = 0;
	mode = STN;
}

Stonewt::~Stonewt()
{}

void Stonewt::stn_mode()		//英石为单位
{
	mode = STN;
}

void Stonewt::pds_mode()		//磅为单位，为浮点数
{
	mode = FPD;
}

void Stonewt::int_pds_mode()	//磅为单位，且为整数
{
	mode = INPD;
}

Stonewt::operator int()const	 //int转换函数
{
	return int(pounds + 0.5);
}

Stonewt::operator double()const	//double转换函数
{
	return pounds;
}

Stonewt Stonewt::operator+(const Stonewt& st)const
{
	return Stonewt(pounds + st.pounds, mode);
}

Stonewt Stonewt::operator-(const Stonewt& st)const
{
	return Stonewt(pounds - st.pounds, mode);
}

Stonewt Stonewt::operator*(double n)const
{
	return Stonewt(pounds*n, mode);
}

Stonewt operator*(double n, const Stonewt& st)
{
	return Stonewt(n*st.pounds, st.mode);
}

ostream& operator<<(ostream& os, const Stonewt& st)
{
	if (st.mode == Stonewt::STN)
		os << st.stone << "stone， " << st.pds_left << "pounds.\n";
	else if (st.mode == Stonewt::INPD)
		os << st.pounds_int << "pounds(整数)\n";
	else if (st.mode == Stonewt::FPD)
		os << st.pounds << "pounds(浮点数)\n";
	else
		os << "格式错误！\n";
	return os;
}
