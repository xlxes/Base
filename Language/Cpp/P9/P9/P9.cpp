// P9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "golf.h"
#include "sales.h"
#include <string>
using namespace std;

/*P1*/
//const int men = 5;
/*P2*/
//void strcount(const string str);
/*P3*/
//struct chaff
//{
//	char dross[20];
//	int slag;
//};

int main()
{

	/*P1*/
 //   std::cout << "Hello World!\n"; 
	//golf golfer[men];
	//for (int i = 0; i < men; i++)
	//{
	//	if (setgolf(golfer[i]) == 0)
	//		break;
	//}
	//for (int j = 0; j < men; j++)
	//{
	//	showgolf(golfer[j]);
	//}
	//golf anna;
	//setgolf(anna, "anna", 24);
	//showgolf(anna);
	//handicap(anna, 20);
	//showgolf(anna);

	/*P2*/
	//string input;
	//cout << "enter a line: ";
	//getline(cin, input);
	//while (input != "")	//检测是否为空
	//{
	//	strcount(input);
	//	cout << "enter next line: ";
	//	getline(cin, input);
	//}
	//cout << "end !";

	/*P3*/
	//chaff *p = new chaff[2];	//构建动态数组
	//strcpy_s(p[0].dross, "xwy like");
	//p[0].slag = 5;
	//strcpy_s(p[1].dross, "xmy");
	//p[1].slag = 6;
	//for (int i = 0; i < 2; i++)
	//{
	//	cout << p[i].dross << " " << p[i].slag << endl;
	//}
	//delete [] p;

	using namespace SALES;
	Sales salesbook;
	double salesList[] = { 12.2,11.16,10.61,16.24,11.53 };
	setSales(salesbook, salesList, 
		sizeof(salesList) / sizeof(salesList[0]));
	showSales(salesbook);
	Sales salespen;
	setSales(salespen);
	showSales(salespen);

	return 0;
}

//void strcount(const string str)
//{
//	static int total = 0;
//	int count = 0;
//	cout << "\"" << str << "\" contains\n";
//	count = str.size();
//	total += count;
//	cout << "total : " << total << endl;
//	cout << "count : " << count << endl;
//}

