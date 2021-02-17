#include "pch.h"
#include "tv.h"
#include <iostream>

using namespace std;

bool Tv::volup()	//����+
{
	if (volume < maxval)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()	//����-
{
	if (volume > minval)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()	//Ƶ��+
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;	//�������Ƶ����������1
}

void Tv::chandown()	//Ƶ��+
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;	//������СƵ�������ص����ֵ
}

//��ʾ����
void Tv::show() const
{
	cout << "Tv is " << (off == state ? "off" : "on") << endl;	//ö��ʵ��Ϊ���֣���Ҫת��Ϊ�ַ���
	if (state == on)
	{
		cout << "volume : " << volume << endl;
		cout << "channel : " << channel << endl;
		cout << "mode : " << (mode == antenna ? "antenna" : "cable") << endl;
		cout << "input : " << (input == tv ? "tv" : "dvd") << endl;
	}
}

//���ý���ģʽ
void Tv::set_rmode(Remote& r)
{
	if (state == on)
	{
		r.rmode = (r.rmode == Remote::regular ? Remote::interaction : Remote::regular);
	}
}