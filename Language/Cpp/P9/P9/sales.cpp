#include "pch.h"
#include <iostream>
#include "sales.h"

namespace SALES
{
	using std::cin;
	using std::cout;
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

	//输入结构体 数组 以及数组长度
	void setSales(Sales &s, const double ar[], int n)
	{
		unsigned times = n < QUARTERS ? (unsigned)n : QUARTERS;
		for (int i = 0; i < times; i++)
		{
			s.sales[i] = ar[i];
		}
		for (int i = times; i < QUARTERS; i++)
		{
			s.sales[i] = 0;
		}
		s.average = calaverage(s.sales, times);
		s.max = calmax(s.sales, times);
		s.min = calmin(s.sales, times);
	}

	void setSales(Sales &s)
	{
		cout << "enter 4 sales: ";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "sales" << i + 1 << ": ";
			cin >> s.sales[i];
		}
		s.average = calaverage(s.sales, QUARTERS);
		s.max = calmax(s.sales, QUARTERS);
		s.min = calmin(s.sales, QUARTERS);
	}

	void showSales(const Sales &s)
	{
		cout << "sales :";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << s.sales[i]<<" ";
		}
		cout << endl;
		cout << "average : " << s.average << endl;
		cout << "max : " << s.max << endl;
		cout << "min : " << s.min << endl;
	}
}