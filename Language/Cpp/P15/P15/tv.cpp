#include "pch.h"
#include "tv.h"
#include <iostream>

using namespace std;

bool Tv::volup()	//音量+
{
	if (volume < maxval)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()	//音量-
{
	if (volume > minval)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()	//频道+
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;	//超出最大频道数，返回1
}

void Tv::chandown()	//频道+
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;	//低于最小频道数，回到最大值
}

//显示变量
void Tv::show() const
{
	cout << "Tv is " << (off == state ? "off" : "on") << endl;	//枚举实质为数字，需要转换为字符串
	if (state == on)
	{
		cout << "volume : " << volume << endl;
		cout << "channel : " << channel << endl;
		cout << "mode : " << (mode == antenna ? "antenna" : "cable") << endl;
		cout << "input : " << (input == tv ? "tv" : "dvd") << endl;
	}
}

//设置交互模式
void Tv::set_rmode(Remote& r)
{
	if (state == on)
	{
		r.rmode = (r.rmode == Remote::regular ? Remote::interaction : Remote::regular);
	}
}