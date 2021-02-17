// P8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>


using namespace std;


/*P1
void show_str(const char* str);
void show_str(const char*str, int n);
*/

/*P2
struct CandyBar
{
	string name;
	double weight;
	int hot;
};
void set_candy(CandyBar &t,const char * name ="Millennium Munch" , double weight = 2.85, int hot = 350);
void show_candy(const CandyBar &t);
*/

/*P3
void change_A(string &t);
*/

/*P4
struct stringy
{
	char * str;
	int ct;
};
void set(stringy &t, char *str);
void show(const stringy &t, int n = 1);
void show(const string &t, int n = 1);
*/

/*P5
const int limit = 5;
template <typename T>
T max5(T ar[]);
*/

/*P6*/
//template <typename T>
//T maxn(T ar[], int n);
//template <> const char * maxn(const char* ar[], int n);

/*P7*/
//template <typename T>
//T SumArray(T arr[], int n);
//template <typename T>
//T SumArray(T * arr[], int n);
//struct debts
//{
//	char name[50];
//	double amount;
//};

int main()
{
	/*P1
	char str1[] = "xwy";
	char str2[] = "xmy";
	const int time_str = 5;
	show_str(str1);
	show_str(str2, time_str);*/

	/*P2
	CandyBar x;
	const char *p = "xwy";
	double weight = 12;
	int hot = 180;
	set_candy(x,p, weight, hot);
	show_candy(x);
	*/

	/*P3
	string p;
	cout << "输入字符" << endl;
	while (1)
	{
		getline(cin, p);
		if (p == "q")
			break;
		change_A(p);
		cout << "转换结果： " << p << endl;
	}
	cout << "bye!";
	*/

	/*P4
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	delete[] beany.str;		//必须删除new申请的内存空间
	return 0;
	*/

	/*P5
	int ari[limit] = { 1,2,3,4,5 };
	double ard[limit] = { 12,13,14,15,16 };
	int maxi = max5(ari);
	double maxd = max5(ard);
	cout << "max of int " << maxi << endl;
	cout << "max of double " << maxd << endl;
	return 0;
	*/

	/*P6*/
	//int ari[6] = { 0,1,2,3,4,5 };
	//double ard[4] = { 1.1,1.2,1.3,2.3 };
	//const char* ars[5] = { "a","asdf","qwer","xwylovexmy","forever" };
	//cout << "the max of ari is " << maxn(ari, 6) << endl;
	//cout << "the max of ard is " << maxn(ard, 4) << endl;
	//cout << "the max of string is " << maxn(ars, 5) << endl;

	/*P7*/
	//int things[6] = { 13,31,103,301,310,130 };
	//struct debts mr_E[3] =
	//{
	//	{"Ima Wolfe",2400.0},
	//	{"Ura Foxe",1300.0},
	//	{"Iby Stout",1800.0}
	//};
	//double * pd[3];
	//for (int i = 0; i < 3; i++)
	//{
	//	pd[i] = &mr_E[i].amount;
	//}
	//cout << "sum of things is " << SumArray(things, 6) << endl;
	//cout << "sum of debts is " << SumArray(pd, 3);
	//return 0;
	
}

/*
void show_str(const char* str)
{
	cout << str << endl;
}

void show_str(const char*str, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << str << endl;
	}
}
*/

/*
void set_candy(CandyBar &t, const char* name, double weight, int hot)
{
	t.name = name;
	t.weight = weight;
	t.hot = hot;
}

void show_candy(const CandyBar &t)
{
	cout << "name : " << t.name << endl;
	cout << "weight : " << t.weight << endl;
	cout << "hot : " << t.hot << endl;
}
*/

/*
void change_A(string &t)
{
	int limit = t.size();
	for (int i = 0; i < limit; i++)
	{
		t[i] = toupper(t[i]) ;
	}
}
*/

/*
void set(stringy &t, char *str)
{
	t.ct = strlen(str);
	t.str = new char[t.ct + 1];
	strcpy_s(t.str, t.ct + 1, str);
}

void show(const stringy &t, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << t.str << endl;
	}
}

void show(const string &t, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << t << endl;
	}
}
*/

/*
template <typename T>
T max5(T ar[])
{
	T max = ar[0];
	for (int i = 1; i < limit; i++)
	{
		if (ar[i] > max)
		{
			max = ar[i];
		}
	}
	return max;
}
*/

//template <typename T>
//T maxn(T ar[], int n)
//{
//	T max = ar[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (ar[i] > max)
//		{
//			max = ar[i];
//		}
//	}
//	return max;
//}
//
//template <> const char * maxn(const char* ar[], int n)
//{
//	const char* maxs = ar[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (strlen(maxs) < strlen(ar[i]))
//			maxs = ar[i];
//	}
//	return maxs;
//}

//template <typename T>
//T SumArray(T arr[], int n)
//{
//	T sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr[i];
//	}
//	return sum;
//}
//
//template <typename T>
//T SumArray(T *ar[], int n)
//{
//	T sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += *ar[i];
//	}
//	return sum;
//}