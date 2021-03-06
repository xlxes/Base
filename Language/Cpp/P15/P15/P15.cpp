// P15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "tv.h"
#include "exc_mean.h"
#include "sale.h"
#include <iostream>

using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	//P1
	//Tv s42;
	//Remote grey;
	//cout << "initial setting for 42\" Tv: \n";
	//s42.show();		//显示全部
	//grey.mode_show();	//显示遥控器的状态变量
	//s42.onoff();		//开启电视
	//s42.set_rmode(grey);	//设置交互模式
	//grey.mode_show();
	//s42.chanup();
	//cout << "\nadjusted setting for s42 Tv: \n";
	//s42.show();

	//grey.setchan(s42, 10);
	//grey.volup(s42);
	//grey.volup(s42);
	//cout << "\n s42 setting after using remote: \n";
	//s42.show();
	//return 0;

	//P2
	//double x, y, z;
	//cout << "enter 2 numbers: " << endl;
	//while (cin >> x >> y)
	//{
	//	try 
	//	{
	//		z = hmean(x, y);
	//		cout << "harmonic mean of " << x << " and " << y << " is " << z << endl;
	//		cout << "geomettric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
	//		cout << "enter next 2 numbers(q to quit): ";
	//	}
	//	catch (bad_hmean& bh)
	//	{
	//		cout << bh.what();	//给logic赋值的string字符串
	//		cout << "error message : \n" << bh.mesg() << endl;
	//		cout << "try again.\n";
	//		continue;
	//	}
	//	catch (bad_gmean& bg)
	//	{
	//		cout << bg.what();
	//		cout << "error message : \n" << bg.mesg() << endl;
	//		cout << "sorry you have no chance.\n";
	//		break;
	//	}
	//}
	//cout << "bye!\n";
	//return 0;

	//P3
	//double x, y, z;
	//cout << "enter 2 numbers: " << endl;
	//while (cin >> x >> y)
	//{
	//	try
	//	{
	//		z = hmean(x, y);
	//		cout << "harmonic mean of " << x << " and " << y << " is " << z << endl;
	//		cout << "geomettric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
	//		cout << "enter next 2 numbers(q to quit): ";
	//	}
	//	catch (bad_ggmean& bgg)  //孙子类
	//	{
	//		cout << bgg.what();	//给logic赋值的string字符串
	//		cout << "error message : \n";
	//		bgg.mesg();
	//		cout << endl;
	//		cout << "sorry you have no chance.\n";
	//		break;
	//	}
	//	catch (bad_hhmean& bhh)	 //儿子类
	//	{
	//		cout << bhh.what();
	//		cout << "error message : \n";
	//		bhh.mesg();
	//		cout<<endl;
	//		cout << "try again.\n";
	//		continue;
	//	}
	//}
	//cout << "bye!\n";
	//return 0;

	//P4
	double vals1[12] = { 1220,1100,1122,2212,1232,2334,2884,2393,3303,2922,3002,3544 };
	double vals2[12] = { 12,11,22,21,32,24,28,29,33,29,32,35 };
	Sale s1(2011, vals1, 12);
	labeled s2("Blogstar", 2012, vals2, 12);
	Sale::bad_index *s;
	labeled::nbad_index *l;
	cout << "first try block: \n";
	try
	{
		int i;
		cout << "year =" << s1.year_val() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << s1[i] << " ";
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "year =" << s2.year_val() << endl;
		cout << "label =" << s2.label_val() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << s2[i] << " ";
			if (i % 6 == 5)
				cout << endl;
		}
		cout << " end try block1.\n";
	}
	catch (logic_error& bad)		//直接捕获logic_error异常 在用dynamic_cast进行判断是哪个嵌套类
	{
		cout << bad.what();
		if (l = dynamic_cast<labeled::nbad_index *>(&bad))
		{
			cout << "comany :" << l->label_val() << endl;
			cout << "bad index :" << l->bi_val() << endl;
		}
		else if (s = dynamic_cast<Sale::bad_index *>(&bad))
			cout << "bad index :" << s->bi_val() << endl;
	}
	cout << "\n next try block :\n";
	try 
	{
		s2[20] = 37.5;
		//s1[20] = 23345;
		cout << "end of try block2.\n";
	}
	catch (logic_error& bad)
	{
		cout << bad.what();
		if (l = dynamic_cast<labeled::nbad_index *>(&bad))
		{
			cout << "comany :" << l->label_val() << endl;
			cout << "bad index :" << l->bi_val() << endl;
		}
		else if (s = dynamic_cast<Sale::bad_index *>(&bad))
			cout << "bad index :" << s->bi_val() << endl;
	}
	cout << "done. \n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hhmean(a,b,"算数平均数\n");
	return 2.0*a*b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_ggmean(a,b,"几何平均数\n");
	return sqrt(a*b);
}
