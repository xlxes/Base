// P7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

//t1-5
//float get_ave(int, int);
//
//void show(const double ar[], int n);
//double average(const double ar[], int n);
//int fill(double ar[], int limit);
//
//struct box
//{
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
//void show_box(box);
//void set_box(box *ps);
//
//long double probability(unsigned numbers, unsigned picks);
//
//long long int recure(int);

//t6
/*const int Size = 10;
int Fill_array(double ar[], int n);
void Show_array(const double ar[], int n);
void Reverse_array(double ar[], int n);
*/
//t7
/*
const int  MAX = 5;
double * fill_array(double * begin, double * end);
void show_array(const double * begin, const double * end);
void revalue(double r, double *begin, double *end);
*/
//t8
/*const int seasons = 4;
const char* sname[] = { "spring","summer","fall","winter" };
void fill(double ar[], int n);
void show(double ar[], int n);
*/
//t8b
/*
const int seasons = 4;
struct season_data
{
	double arr[seasons];
};
const char * sname[] = { "spring","summer","fall","winter" };
season_data fill_str();
void show_str(season_data);
*/
//t9
/*const int SLEN = 30;
struct student
{
	char fullanme[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);
*/

//t10
double calculate(double x, double y, double(*pf)(double, double));;
double add(double x, double y);
double sub(double x, double y);
double mean(double x, double y);

int main()
{
	/*int a = 0, b = 0;
	cout << "请输入两个数：" << endl;
	cin >> a;
	cin >> b;
	while (a != 0 && b != 0)
	{
		cout << "ave: " << get_ave(a, b) << endl;
		cout << "请输入两个数：" << endl;
		cin >> a;
		cin >> b;
	}*/

	/*const int max = 10;
	double scores[max];
	int size = fill(scores, max);
	show(scores, size);
	if (size > 0)
	{
		cout << "平均数为：" << average(scores, size) << endl;
	}*/

	/*box exa = { "xwy",2,3,4 };
	set_box(&exa);
	show_box(exa);*/

	/*double total, choice, mtotal;
	long double pro1, pro2;
	cout << "牌堆1，输入总数和挑选数：";
	while ((cin>>total>>choice)&&choice<=total)
	{
		cout << "牌堆2，输入总数: ";
		if (!(cin >> mtotal))
			break;
		pro1 = probability(total, choice);
		pro2 = probability(mtotal, 1);
		cout << "分别的机率为(分之1)：" << endl;
		cout << "p1: " << pro1 << "   p2: " << pro2 << endl;
		cout << "获奖几率为(分之1)：";
		cout << pro1*pro2 << endl;
		cout << "下两个数： （瞎鸡儿按退出）";
	}
	cout << "走好";*/

	/*int number;
	long long int result;
	cout << "输入数字：";
	while (cin >> number)
	{
		result = recure(number);
		cout << number << "! = " << result << endl;
		cout << "next number: ";
	}
	cout << "over";*/
    
	/*double value[Size];
	int len = Fill_array(value, Size);
	cout << "显示数组" << len << "个元素" << endl;
	Show_array(value, len);
	cout << "翻转数组\n";
	Reverse_array(value, len);
	Show_array(value, len);*/

	/*double pro[MAX];
	double * pbegin = pro;
	double * pend = fill_array(pbegin,pbegin+MAX);
	show_array(pbegin,pend);
	if ((pend-pbegin) > 0)
	{
		cout << "Enter revalue factor";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input";
		}
		revalue(factor,pbegin,pend);
		show_array(pbegin,pend);
	}
	cout << "done! " << endl;
	cin.get();
	cin.get();*/

	/*double expenses[seasons];
	fill(expenses, seasons);
	show(expenses, seasons);*/

	/*season_data datas = fill_str();
	show_str(datas);*/

	/*cout << "enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student *ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "done" << endl;*/

		double a, b;
		double(*pf[3])(double, double) = { add,sub,mean };
		const char * op[3] = { "add","sub","mean" };
		cout << "enter pairs of numbers (q to quit)" << endl;
		while (cin >> a >> b)
		{
			for (int i = 0; i < 3; i++)
			{
				cout << op[i] << ": " << a << " and " << b
					<< " = " << calculate(a, b, pf[i]) << endl;
			}
		}
	return 0;
}

//t1-6
//float get_ave(int c, int d)
//{
//	return float(2.0 * c*d / (c + d));
//}
//
//int fill(double ar[], int limit)
//{
//	double temp;
//	int i = 0;
//	for (i = 0; i < limit; i++)
//	{
//		cout << "输入成绩#" << i + 1 << " : ";
//		cin >> temp;
//		if (!cin)
//		{
//			cin.clear();
//			while (cin.get() != '\n')
//				continue;
//			cout << "bad input" << endl;
//			break;
//		}
//		if (temp < 0)
//			break;
//		else
//		{
//			ar[i] = temp;
//		}
//	}
//	return i;	//返回个数
//}
//
//double average(const double ar[], int n)
//{
//	double sum = 0.0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += ar[i];
//	}
//	return sum / n;
//}
//
//void show(const double ar[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "score #" << i + 1 << " : " << ar[i] << endl;
//	}
//}
//
//void show_box(box sp)
//{
//	cout << "Box maker: " << sp.maker << endl;
//	cout << "height: " << sp.height << endl;
//	cout << "width: " << sp.width << endl;
//	cout << "length: " << sp.length << endl;
//	cout << "volume: " << sp.volume << endl;
//}
//
//void set_box(box *ps)
//{
//	ps->volume = ps->height*ps->length*ps->width;
//}
//
//long double probability(unsigned numbers, unsigned picks)
//{
//	long double result = 1.0;
//	long double n;
//	unsigned p;
//	for (n = numbers, p = picks; p > 0; n--, p--)
//	{
//		result = result * n / p;
//	}
//	return result;
//}
//
//long long int recure(int n)
//{
//	long long int result;
//	if (n > 0)
//		result = n * recure(n - 1);
//	else
//		result = 1;
//	return result;
//}

/*
int Fill_array(double ar[], int n)
{
	using namespace std;
	double temp;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << ": ";
		cin >> temp; //输入非数字会导致与double 类型不匹配 导致输入失败
		if (!cin)	//输入失败
			break;
		ar[i] = temp;
	}
	cout << endl;
	return i;
}

void Show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个元素为： " << ar[i] << endl;
	}
}

void Reverse_array(double ar[], int n)
{
	double temp;
	for (int i = 1, j = n - 2; i < j; i++, j--)
	{
		temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}
}


double * fill_array(double * begin, double * end)
{
	using namespace std;
	double temp;
	int i = 0;
	while (begin < end)
	{
		cout << "enter value #" << (i + 1) << ":";
		cin >> temp;
		if (!temp)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input\n";
			break;
		}
		else if (temp < 0)
			break;
		*begin = temp;		//指针指向的数值对象
		begin++;			//指针（地址）++
		i++;
	}
	return begin;		//返回指针
}

void show_array(const double * begin, const double * end)
{
	using namespace std;
	int i = 1;
	while (begin < end)
	{
		cout << "data: #" << i << ": " << *begin << endl;
		begin++;
		i++;
	}
}

void revalue(double r, double *begin, double *end)
{
	while (begin < end)
	{
		*begin = *begin * r;
		begin++;
	}
}


void fill(double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "enter expense of " << sname[i] << " is ";
		cin >> ar[i];
	}
}

void show(double ar[], int n)
{
	using namespace std;
	double total = 0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < n; i++)
	{
		cout << sname[i] << "expense :" << ar[i] << endl;
		total += ar[i];
	}
	cout << "total : " << total << endl;
}

season_data fill_str()
{
	using namespace std;
	season_data expense;
	for (int i = 0; i < seasons; i++)
	{
		cout << "enter expense of " << sname[i] << ": ";
		cin >> expense.arr[i];
	}
	return expense;
}

void show_str(season_data expense)
{
	cout << "\nEXPENSES\n";
	double total = 0;
	for (int i = 0; i < seasons; i++)
	{
		cout << sname[i] << " : " << expense.arr[i] << endl;
		total += expense.arr[i];
	}
	cout << "total : " << total << endl;
}


int getinfo(student pa[], int n)
{
	int num_arry_elem = n;		//最大个数
	char tmp[SLEN];				//存储名字
	for (int i = 0; i < n; i++)
	{
		cout << "enter name :";
		cin.getline(tmp, SLEN);
		bool blank_line = true;
		for (unsigned int j = 0; j < strlen(tmp); j++)
		{
			if (!isspace(tmp[j]))
			{
				blank_line = false;
				break;
			}
		}
		if (blank_line)
		{
			num_arry_elem = i;
			break;
		}
		strcpy_s(pa[i].fullanme, tmp);	//写入结构体的名字对象
		cout << "enter hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "enter ooplevel: ";
		cin >> pa[i].ooplevel;
		cin.get();
	}
	cout << endl;
	return num_arry_elem;		//返回实际个数
}

void display1(student st)
{
	cout << st.fullanme << '\t'
		<< st.hobby << '\t' << st.ooplevel << endl;
}

void display2(const student *ps)
{
	cout << ps->fullanme << '\t'
		<< ps->hobby << '\t' << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << pa[i].fullanme << '\t'
			<< pa[i].hobby << '\t' << pa[i].ooplevel << endl;
	}
}

*/

double calculate(double x, double y, double(*pf)(double, double))
{
	return (*pf)(x, y);
}
double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}
double mean(double x, double y)
{
	return (x + y) / 2.0;
}