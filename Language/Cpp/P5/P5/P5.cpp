// P5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "array"
#include "string"
using namespace std;

int main()
{
	/*int i, j;
	int sum = 0;
	cout << "input two numbers: ";
	cin >> i;
	cin >> j;
	if (i > j)
	{
		int temp;
		temp = i;
		i = j;
		j = temp;
	}
	for (; i <= j; i++)
	{
		sum = sum + i;
	}
	cout << "sum : " << sum;*/

	/*const int size = 100;
	array<long double, size>sum = {1};
	for (int i = 1; i < sum.size(); i++)
		sum[i] = sum[i - 1] * (i + 1);
	for (int i = 0; i < sum.size(); i++)
		cout << i + 1 << "!= " << sum[i] << endl;*/

		/*int a, sum = 0;
		cout << "请输入数字：";
		while (cin >> a && a != 0)
		{
			sum = sum + a;
			cout << "sum:" << sum << endl;
		}*/

		/*int year = 0;
		float d_sum = 100;
		float c_sum = 100;
		const float a = 100 * 0.1;	//daphne的获利
		const float b = 0.05;		//cleo的利率
		do
		{
			year += 1;
			d_sum += a;
			c_sum = 1.05*(c_sum);
		}while(c_sum <= d_sum);
		cout << year << "年后" << endl << "da资产：" << d_sum << endl << "cl资产：" << c_sum << endl;*/

		/*const int mon = 12;
		string a = "月的销售量为：";
		int book[mon];
		int sum = 0;

		for (int i = 1; i < 13; i++)
		{
			cout << i << a;
			cin >> book[i-1];
			sum = sum + book[i - 1];
		}
		cout << "总销售量为：" << sum;*/

	/*string a = "月的销售量为：";
	int book[3][12] = { 0 };
	int sum[3] = { 0 };
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 12; i++)
		{
			cout << j + 1 << "年" << i + 1 << a;
			cin >> book[j][i];
			sum[j] = sum[j] + book[j][i];
		}
		cout << "第" << j + 1 << "年销售量：" << sum[j] << endl;
	}
	cout << "总销售量：" << sum[0] + sum[1] + sum[2] << endl;*/

	/*struct car
	{
		string name;
		int year;
	};
	int num;
	cout << "how many car we have?" << endl;
	cin >> num;
	cin.get();	//处理回车，需要使用cin与getline混用的情况，最好配套使用cin与cin.get（）
	car *a = new car[num];
	for (int i = 0; i < num; i++)
	{
		cout << "car #" << i + 1 << ":" << endl;
		cout << "Please enter the make:";
		getline(cin, ((a + i)->name));
		cout << "Please enter the year made:";
		cin>>(a + i)->year;
		cin.get();
	}
	cout << "Here is your collection:\n";
	for (int i = 0; i < num; i++)
		cout << (a + i)->year << " " << (a + i)->name << endl;
	delete[] a;*/

	/*cout << "Enter words (to stop, type the word done):";
	char a[100];
	int sum = 0;
	while (cin >> a && strcmp(a, "done"))
	{
		sum++;
	}
	cout << "总共输入单词数：" << sum << endl;*/

	/*cout << "Enter words (to stop, type the word done):";
	string a;
	int sum = 0;
	while (cin >> a && (a!="done"))
	{
		sum++;
	}
	cout << "总共输入单词数：" << sum << endl;*/

	/*int n;
	cout << "输入显示行数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			cout << ".";
		for (int k = 0; k < i + 1; k++)
			cout << "*";
		cout << endl;
	}*/
	return 0;
}

