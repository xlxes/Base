#include "pch.h"
#include "stonewt.h"

void Stonewt::set_stn()	//��תΪӢʯ
{
	stone = int(pounds) / Lbs_per_stn;  //��ת��ΪӢʯ
	pds_left = int(pounds) % Lbs_per_stn + pounds - int(pounds);//��ĵ�pounds
}

void Stonewt::set_pds()	//ӢʯתΪ��
{
	pounds = stone * Lbs_per_stn + pds_left;
}

void Stonewt::set_pds_int()	//�����ת��Ϊ����ʱ�����
{
	pounds_int = int(pounds);
}

Stonewt::Stonewt(double lbs, Mode form)		//���캯��(������-����) 
{
	mode = form;
	if (mode == STN)	//Ӣʯ��ʽ
	{
		stone = int(lbs) / Lbs_per_stn;		//�õ�Ӣʯ
		pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);	//�õ�ʣ�ಿ��Ӣ��
		set_pds();		//�õ�����Ӣ��	
		set_pds_int();	//�õ��������
	}
	else if (form == INPD)		//��������ʽ
	{
		pounds_int = int(lbs);	//�õ�����Ӣ��
		pounds = lbs;			//�õ�����Ӣ��
		set_stn();				//�õ�Ӣʯ
	}
	else if (form == FPD)		//�������ʽ
	{
		pounds = lbs;		//�õ�����Ӣ��
		set_pds_int();		//�õ�����Ӣ��
		set_stn();			//�õ�Ӣʯ
	}
	else
	{
		cout << "ģʽ�������\n";
		stone = pounds = pds_left = 0.0;
		mode = STN;
	}
}

Stonewt::Stonewt(int stn, double lbs, Mode form)	//���캯����˫������
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
		cout << "ģʽ�������\n";
		stone = pounds = pds_left = 0;
		mode = STN;
	}
}

Stonewt::Stonewt()	//Ĭ�Ϲ��캯��
{
	stone = pounds = pds_left = 0;
	mode = STN;
}

Stonewt::~Stonewt()
{}

void Stonewt::stn_mode()		//ӢʯΪ��λ
{
	mode = STN;
}

void Stonewt::pds_mode()		//��Ϊ��λ��Ϊ������
{
	mode = FPD;
}

void Stonewt::int_pds_mode()	//��Ϊ��λ����Ϊ����
{
	mode = INPD;
}

Stonewt::operator int()const	 //intת������
{
	return int(pounds + 0.5);
}

Stonewt::operator double()const	//doubleת������
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
		os << st.stone << "stone�� " << st.pds_left << "pounds.\n";
	else if (st.mode == Stonewt::INPD)
		os << st.pounds_int << "pounds(����)\n";
	else if (st.mode == Stonewt::FPD)
		os << st.pounds << "pounds(������)\n";
	else
		os << "��ʽ����\n";
	return os;
}
