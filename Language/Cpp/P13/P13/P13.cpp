// P13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "cd.h"
#include "DMA.h"
#include "port.h"

void Bravo(const Cd& disk);

using namespace std;

int main()
{
	//题1 题2
	//Cd c1("Beatles", "Capitol", 14, 35.5);
	//Classic c2 = Classic("Piano Sonata in B flat , Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	//Cd* pcd = &c1;
	//cout << "Using object directly: \n";
	//c1.Report(); 
	//c2.Report();
	//cout << "Using type cd * pointer to object: \n";
	//pcd->Report();
	//pcd = &c2;
	//pcd->Report();
	//cout << "Calling a function with a cd reference argument: \n";
	//Bravo(c1);
	//Bravo(c2);
	//cout << "Testing assigment: \n";
	//Classic copy;
	//copy = c2;
	//copy.Report();
	//return 0;

	//题3
	/*baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object:\n";
	cout << shirt << endl;
	cout << "Displaying lacksDMA object:\n";
	cout << balloon << endl;
	cout << "Displaying hasDMA object:\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "Result of lacksDMA copy:\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "Result of hasDMA assignment:\n";
	cout << map2 << endl << endl;
	cout << "View函数测试" << endl;
	cout << endl << "Shirt:\n";
	shirt.View();
	cout << endl << "Balloon:\n";
	balloon.View();
	cout << endl << "Map:\n";
	map.View();
	cout << endl << "Balloon2:\n ";
	balloon2.View();
	cout << endl << "Map2:\n";
	map2.View();

	cout << "\nHow many inputs: ";
	int number;
	cin >> number;
	cin.ignore();
	for (int i = 0; i < number; i++)
	{
		cout << "\nEnter 1 for baseDMA class, 2 for lacksDMA class, or 3 for hasDMA class: ";
		char flag;
		while (cin >> flag && (flag != '1' && flag != '2' && flag != '3'))
		{
			cin.ignore();
			cout << "Enter 1, 2, or 3 please: ";
		}
		cin.ignore();
		if (flag == '1')
		{
			char * label = new char[20];
			int rating;
			cout << "Enter the label: ";
			cin.getline(label, 20);
			cout << "Enter the rating: ";
			cin >> rating;
			baseDMA * base = new baseDMA(label, rating);
			cout << endl << "Your input baseDMA is:\n";
			base->View();
		}
		else if (flag == '2')
		{
			char * label = new char[20];
			int rating;
			char * color = new char[40];
			cout << "Enter the label: ";
			cin.getline(label, 20);
			cout << "Enter the rating: ";
			cin >> rating;
			cin.ignore();
			cout << "Enter the color: ";
			cin.getline(color, 40);
			lacksDMA * lacks = new lacksDMA(color, label, rating);
			cout << endl << "Your input lacksDMA is:\n";
			lacks->View();
		}
		else if (flag == '3')
		{
			char * label = new char[20];
			int rating;
			char * style = new char[40];
			cout << "Enter the label: ";
			cin.getline(label, 20);
			cout << "Enter the rating: ";
			cin >> rating;
			cin.ignore();
			cout << "Enter the style: ";
			cin.getline(style, 40);
			hasDMA * has = new hasDMA(style, label, rating);
			cout << endl << "Your input hasDMA is:\n";
			has->View();
		}
	}
	return 0;*/

	//题4
	port wine1("Leonardo", "white", 15);
	port wine2 = wine1;
	cout << "Now your wines are:\n";
	wine1.show();
	wine2.show();
	wine1 += 18;
	wine2 -= 6;
	cout << "After the change, your wines' bottles are:\n";
	cout << "Wine1: ";
	cout << wine1.BottleCount() << endl;
	cout << "Wine2: ";
	cout << wine2.BottleCount() << endl;
	cout << "And the conclusion is\n";
	cout << wine1 << endl;
	cout << wine2 << endl;
	cout << endl;
	cout << "Now your wines upgrade to VintagePort class.\n";
	vintageport wine3("Elma", 21, "tww", 23);
	vintageport wine4;
	(port &)wine4 = (port &)wine3;
	(vintageport &)wine4 = (vintageport &)wine3;
	cout << "Now the new wines are:\n";
	wine3.show();
	wine4.show();
	wine3 += 17;
	wine4 -= 5;
	cout << "After the change, your new wines' bottles are:\n";
	cout << "Wine3: " << endl;
	cout << wine3.BottleCount() << endl;
	cout << "Wine4: " << endl;
	cout << wine4.BottleCount() << endl;
	cout << "And the conclusion is\n";
	cout << wine3 << endl;
	cout << wine4 << endl;
	cout << endl;
	return 0;

	//有的方法没有重新定义，原因在于重新定义的方法
	//都是需要输出或者处理派生类独有的成员变量
	//而如果不需要处理派生类独有的成员变量，就可以直接调用基类的方法即可

	//operator=()是赋值运算符的重载，当赋的类不同时，赋的内容也不同，所以没有声明为虚的
	//而operator<<()是友元函数，一般友元函数不会声明为虚的。
}

void Bravo(const Cd& disk)
{
	disk.Report();
}
