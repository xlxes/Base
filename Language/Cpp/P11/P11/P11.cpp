// P11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
//#include "mytime.h"
//#include "stonewt.h"
//#include "sto.h"
#include "cpx.h"
using namespace std;


int main()
{
	//P4
	//Time aida(3, 35);
	//Time tosca(2, 48);
	//Time temp;
	//cout << "aida = " << aida << endl;
	//cout << "tosca = " << tosca << endl;
	//temp = aida + tosca;
	//cout << "aida + tosca = " << temp << endl;
	//temp = aida * 1.17;
	//cout << "aida * 1.17 = " << temp << endl;
	//temp = 10.0 * tosca;
	//cout << "10.0 * tosca = " << temp << endl;

	//P5
	//Stonewt a(275.2, Stonewt::FPD);		//浮点磅
	//Stonewt b(285.7, Stonewt::STN);		//英石
	//Stonewt c(21, 8, Stonewt::INPD);	//整数磅
	//Stonewt temp;
	//cout << "a（FPD）: " << a << endl;
	//a.stn_mode();
	//cout << "a(STN) : " << a << endl;
	//cout << "b: " << b << endl;
	//cout << "c: " << c << endl;
	//temp = a + b;
	//cout << "a+b = " << temp << endl
	//temp = a - b; 
	//cout << "a-b = " << temp << endl;
	//temp = 10.0 * c;
	//cout << "10.0 * c = " << temp << endl;
	//temp = c * 10.0;
	//cout << "c * 10.0 = " << temp << endl;

	//P6
	//sto sw[6] = { 10.0, 12.0,15.0 };
	//sto temp(11.0);
	//for (int i = 0; i < 3; i++)
	//{
	//	double input;
	//	cout << "输入" << i + 1 << " : ";
	//	cin >> input;
	//	sw[i+3] = input;
	//}
	//for (int i = 0; i < 6; i++)
	//{
	//	cout << "#" << i + 1 << " : " << sw[i];
	//}
	//sto min = sw[0];
	//sto max = sw[0];
	//int count = 0;
	//for (int i = 0; i < 6; i++)
	//{
	//	if (min > sw[i])
	//		min = sw[i];
	//	if (max < sw[i])
	//		max = sw[i];
	//	if (temp <= sw[i])
	//		count++;
	//}
	//cout << "max : " << max << endl;
	//cout << "min : " << min << endl;
	//cout << "大于11的个数 ： " << count << endl;

	cpx a(3.0, 4.0);
	cpx c;
	cout << "Enter a complex number (q to quit): \n";
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "c的共轭复数 ：" << ~c << endl;
		cout << "a is  " << a << endl;
		cout << "a+c is " << a + c << endl;
		cout << "a-c is " << a - c << endl;
		cout << "a*c is " << a * c << endl;
		cout << "2*c is " << 2 * c << endl;
		cout << "enter a complex number (q to quit): " << endl;
	}
	cout << "Done!" << endl;
	return 0;
}
