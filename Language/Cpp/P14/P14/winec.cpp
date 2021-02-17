#include "pch.h"
#include "winec.h"

//包含的方法
//Wine::Wine(const char* l, int y, const int yr[], const int bot[])
//{
//	fullname = l;
//	num = y;
//	yb.set(ArrayInt(yr, num), ArrayInt(bot, num));
//}
//
//Wine::Wine(const char* l, int y)
//{
//	fullname = l;
//	num = y;
//}
//
//void Wine::GetBottles()
//{
//	ArrayInt yr(num), bt(num);	//根据数量建立两个数组
//	for (int i = 0; i < num; i++)
//	{
//		cout << "输入年份：";
//		cin >> yr[i];
//		cout << "输入瓶数：";
//		cin >> bt[i];
//	}
//	while (cin.get() != '\n')	//清除回车键
//		continue;
//	yb.set(yr, bt);		//设置pair变量
//}
//
//string& Wine::Label()
//{
//	return fullname;
//}
//
//void Wine::show() const
//{
//	cout << "Wine :" << fullname << endl;
//	cout << "\tyear \tbottles \n";
//	yb.show(num);
//}
//
//int Wine::sum() const
//{
//	return yb.sum();
//}

//私有继承的方法
Wine::Wine(const char* l, int y, const int yr[], const int bot[]):string(l),num(y),PairArray(ArrayInt(yr,y),ArrayInt(bot,y))
{
}

Wine::Wine(const char* l, int y):string(l),num(y)
{
}

void Wine::GetBottles()
{
	ArrayInt yr(num), bt(num);	//根据数量建立两个数组
	for (int i = 0; i < num; i++)
	{
		cout << "输入年份：";
		cin >> yr[i];
		cout << "输入瓶数：";
		cin >> bt[i];
	}
	while (cin.get() != '\n')	//清除回车键
		continue;
	Pair::set(yr, bt);		//设置pair变量
}

string& Wine::Label()
{
	return (string&)(*this);		//通过强制类型转换，将Wine对象转换为string对象，结果为继承而来的string对象
}

void Wine::show() const
{
	cout << "Wine :" << (string&)(*this) << endl;
	cout << "\tyear \tbottles \n";
	Pair::show(num);
}

int Wine::sum() const
{
	return Pair::sum();
}