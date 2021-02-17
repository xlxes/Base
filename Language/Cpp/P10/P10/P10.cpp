// P10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "BankAccount.h"
#include "Person.h"
#include "Golf.h"
#include "sales.h"
#include "stack.h"
#include "move.h"
#include "plorg.h"
#include "list.h"
//void get_customer(customer& cu);

int main()
{


	//P1
	//BankAccount ba("xwy", "xmy666", 6543210);
	//ba.show();
	//ba.deposit(123456);
	//ba.show();
	//ba.withdraw(666);
	//ba.show();

	//P2
	//Person one;
	//Person two("xwy");
	//Person three("xwy", "xmy");
	//one.Show();
	//one.FormalShow();
	//two.Show();
	//two.FormalShow();
	//three.Show();
	//three.FormalShow();

	//P3
	//Golf golfer1("xwy", 5);
	//golfer1.showgolf();
	//Golf golfer2;
	//golfer2.setgolf(golfer1);
	//golfer2.showgolf();
	//Golf golfer3;
	//golfer3.showgolf();

	//P4
	//using namespace std;
	//using namespace SALES;
	//double salesList[] = { 12.2,11.6,12.65,143.34,11.54 };
	//Sales salesbook(salesList, sizeof(salesList) / sizeof(salesList[0]));
	//salesbook.showSales();
	//Sales salespen;
	//salespen.setSales();
	//salespen.showSales();

	//P5
	//using namespace std;
	//Stack st;
	//customer temp;
	//double payment = 0;
	//char ch;
	//cout << "输入A去加入一个客户结构体" << endl;
	//cout << "输入P弹出并显示一个客户，Q退出" << endl;
	//while (cin >> ch && (ch = toupper(ch)) != 'Q')
	//{
	//	while (cin.get() != '\n')
	//		continue;
	//	if (ch != 'A'&&ch != 'P')
	//	{
	//		cout << "请输入A P或Q";
	//		continue;
	//	}
	//	switch (ch)
	//	{
	//	case 'A':
	//		if (st.isfull())
	//			cout << "stack is full" << endl;
	//		else
	//		{
	//			get_customer(temp);
	//			st.push(temp);
	//		}
	//		break;
	//	case'P':
	//		if (st.isempty())
	//			cout << "stack is empty" << endl;
	//		else
	//		{
	//			st.pop(temp);
	//			payment += temp.payment;
	//			cout << temp.fullnanme << " processed. ";
	//			cout << "Payments now total $" << payment << endl;
	//		}
	//		break;
	//	default:
	//		break;
	//	}
	//	cout << "输入A去加入一个客户结构体" << endl;
	//	cout << "输入P弹出并显示一个客户，Q退出" << endl;
	//}
	//cout << "Done!" << endl;

	//P6
	//Move one;
	//Move two(3, 3);
	//one.showmove();
	//two.showmove();
	//one = one.add(two);
	//one.showmove();
	//one.reset(1,1);
	//one.showmove();

	//P7
	//Plorg one;
	//Plorg two("222", 20);
	//one.showplorg();
	//one.set_ci(10);
	//one.showplorg();
	//two.showplorg();
	//two.set_ci(60);
	//two.showplorg();


	using std::cout;
	using std::cin;
	using std::endl;
	cout << "输入C向列表添加项目，输入S显示列表，输入P对每个参数进行操作，输入Q退出程序" << endl;
	Item_me data;
	char ch;
	List l1;
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;		//处理回车
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case 'C':
				if(l1.isfull())
					cout << "列表已满" << endl;
				else
				{
					cout << "输入数据： " << endl;
					cin >> data;
					l1.add(data);
				}
				break;
		case 'P':
			if (l1.isempty())
				cout << "列表是空的" << endl;
			else
			{
				l1.visit(plus100);
				cout << "每个数据均加100" << endl;
			}
		case 'S':
			l1.showitem();
			break;
		}
		cout << "输入C向列表添加项目，输入S显示列表，输入P对每个参数进行操作，输入Q退出程序" << endl;
	}
	cout << "bye!";
	return 0;
}

//void get_customer(customer& cu)
//{
//	cout << "enter name: ";
//	cin.getline(cu.fullnanme, 35);
//	cout << "enter payment: ";
//	cin >> cu.payment;
//	while (cin.get() != '\n')
//		continue;
//}

