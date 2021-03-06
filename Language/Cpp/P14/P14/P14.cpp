// P14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "winec.h"
#include "queuetp.h"
#include "person.h"
#include "emp.h"

int main()
{
	using namespace std;

	//P1 \ P2
	//cout << "输入名字：";
	//char lab[50];
	//cin.getline(lab, 50);
	//cout << "输入年份个数：";
	//int num;
	//cin >> num;

	//Wine holding(lab, num);
	//holding.GetBottles();
	//holding.show();

	//const int NUM = 3;
	//int y[NUM] = { 1993,1995,1998 };
	//int b[NUM] = { 48,60,72 };
	//Wine more("Gushing Grap Red", NUM, y, b);
	//more.show();
	//cout << "Total bottles for " << more.Label() << ":" << more.sum() << endl;
	//cout << "bye\n";
	//return 0;

	//P3
	//const int qsize = 5;
	//QueueTp<Worker*>lolas(qsize);
	//Worker* temp;
	//int ct;
	//for (ct = 0; ct < qsize; ct++)
	//{
	//	char ch;
	//	cout << "Enter the command: \n"
	//		<< "A or a enter queue,"
	//		<< "P or p delete queue,"
	//		<< "Q or q quit.\n";
	//	cin >> ch;
	//	while (strchr("apq", ch) == NULL)
	//	{
	//		cout << "Please enter a p or q:";
	//		cin >> ch;
	//	}
	//	if (ch == 'q')
	//		break;
	//	switch (ch)
	//	{
	//	case 'a':
	//		temp = new Worker;
	//		cin.get();
	//		temp->set();
	//		if (lolas.isfull())
	//			cout << "Queue already full\n";
	//		else
	//			lolas.enqueue(temp);
	//		break;
	//	case 'p':
	//		if (lolas.isempty())
	//			cout << "Queue already empty\n";
	//		else
	//			lolas.dequeue(temp);
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//cout << "\nHere the total count:";
	//cout << lolas.queuecount();
	//cout << "Done.\n";
	//return 0;

	//	P4
//	const int Size = 5;
//	Person *per[Size];
//	int num = 0;
//	for (num = 0; num < Size; num++)
//	{
//		char choice;
//		cout << "enter the person: \n" << "g: gunslinger p: poker " << "b: bad dude q: quit\n ";
//		cin >> choice;
//		while (strchr("gpbq", choice) == NULL)
//		{
//			cout << "please enter a p,g,o,q: ";
//			cin >> choice;
//		}
//	if (choice == 'q')
//		break;
//	switch (choice)
//	{
//	case 'g':
//		per[num] = new Gunslinger;
//		break;
//	case 'p':
//		per[num] = new PokerPlayer;
//		break;
//	case 'b':
//		per[num] = new BadDude;
//		break;
//	default:
//		break;
//	}
//	cin.get();	//去除回车
//	per[num]->Set();	//根据其类型设置参数
//}
//	cout << "\nHere is your staff: \n";
//	for (int n = 0; n < num; n++)
//	{
//		cout << endl;
//		per[n]->Show();
//	}
//	for (int i = 0; i < num; i++)
//		delete per[i];
//	cout << "bye\n";
//	return 0;

	employee em("em1", "em2", "em3");
	cout << em << endl;		//按抽象基类的方法
	em.ShowAll();			//按employee方法显示
	
	manager ma("ma1", "ma2", "ma3", 4);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("fi1", "fi2", "fi3", "fi4");
	cout << fi << endl;
	fi.ShowAll();

	highfink hf(ma, "hf");
	hf.ShowAll();
	cout << "Press a key for next phase: \n";
	cin.get();
	cin.ignore();
	highfink hf2;
	hf2.SetAll();

	cout << "using an abstr_emp * pointer: \n";
	abstr_emp *tri[4] = { &em,&fi,&hf,&hf2 };
	for (int i = 0; i < 4; i++)
	{
		tri[i]->ShowAll();
	}
	return 0;
}

//1. 因为不涉及动态内存的分配，使用默认的赋值运算符即可
//2. 定义为虚函数，可以根据指针/引用指向的类型选择不同的函数，实现动态连编
//3. 这样多重继承MI时派生类只有一个基类的子对象
//4. 他的数据部分继承自基类部分即可满足要求
//5. 友元函数不可以继承，在需要的地方进行定义即可
//6. 纯虚基类不可以当做数组数据类型


