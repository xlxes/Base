#include "pch.h"
#include "winec.h"

//�����ķ���
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
//	ArrayInt yr(num), bt(num);	//��������������������
//	for (int i = 0; i < num; i++)
//	{
//		cout << "������ݣ�";
//		cin >> yr[i];
//		cout << "����ƿ����";
//		cin >> bt[i];
//	}
//	while (cin.get() != '\n')	//����س���
//		continue;
//	yb.set(yr, bt);		//����pair����
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

//˽�м̳еķ���
Wine::Wine(const char* l, int y, const int yr[], const int bot[]):string(l),num(y),PairArray(ArrayInt(yr,y),ArrayInt(bot,y))
{
}

Wine::Wine(const char* l, int y):string(l),num(y)
{
}

void Wine::GetBottles()
{
	ArrayInt yr(num), bt(num);	//��������������������
	for (int i = 0; i < num; i++)
	{
		cout << "������ݣ�";
		cin >> yr[i];
		cout << "����ƿ����";
		cin >> bt[i];
	}
	while (cin.get() != '\n')	//����س���
		continue;
	Pair::set(yr, bt);		//����pair����
}

string& Wine::Label()
{
	return (string&)(*this);		//ͨ��ǿ������ת������Wine����ת��Ϊstring���󣬽��Ϊ�̳ж�����string����
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