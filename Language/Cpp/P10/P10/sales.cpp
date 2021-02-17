#include "pch.h"
#include <iostream>
#include <string>
#include "sales.h"

namespace SALES
{
	using std::cout;
	using std::cin;
	using std::endl;

	//输入double 型数组，以及数字长度，求平均值
	static double calaverage(double arr[], unsigned arrSize)
	{
		double sum = 0;
		for (int i = 0; i < arrSize; i++)
			sum += arr[i];
		return sum / arrSize;
	}

	//输入double 型数组，以及数字长度，求最大值
	static double calmax(double arr[], unsigned arrSize)
	{
		double max = arr[0];
		for (int i = 1; i < arrSize; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}

	//输入double 型数组，以及数字长度，求最小值
	static double calmin(double arr[], unsigned arrSize)
	{
		double min = arr[0];
		for (int i = 1; i < arrSize; i++)
		{
			if (arr[i] < min)
				min = arr[i];
		}
		return min;
	}

	Sales::Sales()
	{
		min = 0;
		max = 0;
		average = 0;
		for (int i = 0; i < QUA; i++)
			sales[i] = 0;
	}

	Sales::~Sales()
	{
	}

	Sales::Sales(const double ar[], int n)
	{
		unsigned times = n < QUA ? (unsigned)n : QUA;
		for (int i = 0; i < times; i++)
			sales[i] = ar[i];
		for (int i = times; i < QUA; i++)
			sales[i] = 0;
		average = calaverage(sales, times);
		min = calmin(sales, times);
		max = calmax(sales, times);
	}

	void Sales::setSales()
	{
		cout << "输入4个数" << endl;
		for (int i = 0; i < QUA; i++)
		{
			cout << "sales" << i + 1 << ": ";
			cin >> sales[i];
		}
		*this = Sales(sales, QUA);
	}

	void Sales::showSales() const
	{
		cout << "sales : " << endl;
		for (int i = 0; i < QUA; i++)
		{
			cout << sales[i] << " " << endl;
		}
		cout << "average : " << average << endl;
		cout << "max : " << max << endl;
		cout << "min : " << min << endl;
	}
}