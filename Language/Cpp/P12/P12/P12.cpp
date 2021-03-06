// P12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include "cow.h"
#include "str2.h"
#include "stock.h"
#include "stack.h"
#include "queue.h"

const int STKS = 4;
using namespace std;

const int MIN_PER_HR = 60;	//每小时分钟数
bool newcustomer(double x);	//是否有新客户到来

int main()
{
	//题1
	//cow c1;
	//cow c2("xmy", "asdf", 34);
	//c1 = c2;
	//c2.showcow();
	//c1.showcow();

	//题2
	//str2 s1("and I am a C++ student.");
	//str2 s2 = "please enter your name";
	//str2 s3;
	//cout << s2;
	//cin >> s3;
	//s2 = "my name is " + s3;
	//cout << s2 << ".\n";
	//s2 = s2 + s1;
	//s2.str2up();
	//cout << "The string \n" << s2 << "\n contains " << s2.has('A') << " 'A'characters in it.\n";
	//s1 = "red";
	//str2 rgb[3] = { str2(s1),str2("green"),str2("blue") };
	//cout << " enter the name of a primary color for mixing light: ";
	//str2 ans;
	//bool success = false;
	//while (cin >> ans)
	//{
	//	ans.str2low();
	//	for (int i = 0; i < 3; i++)
	//	{
	//		if (ans == rgb[i])
	//		{
	//			cout << "That is right!\n";
	//			success = true;
	//			break;
	//		}
	//	}
	//	if (success)
	//		break;
	//	else
	//		cout << "try again!\n";
	//}
	//cout << "Bye!\n";
	//return 0;

	//题3
	//stock stocks[STKS] = {
	//	stock("NanoSmart",12,20.0),
	//	stock("Boffo Objects",200,2.0),
	//	stock("Monolithic Obelists",130,3.25),
	//	stock("Fleep Enterprises",60,6.5)
	//};
	//cout << "Stock holdings: \n";
	//int st;
	//for (st = 0; st < STKS; st++)
	//{
	//	cout << stocks[st];
	//}
	//const stock* top = &stocks[0];
	//for (st = 1; st < STKS; st++)
	//{
	//
	//	top = &top->topval(stocks[st]);
	//}
	//cout << "\n Most valuable holding: \n";
	//cout << *top;
	//return 0;

	//题4
	//stack s;
	//Item it[20] = { 0 };	//创建数组
	//for (int i = 0; i < 11; i++)
	//{
	//	it[i] = i + 1;
	//	s.push(it[i]);	//存入栈
	//}
	//cout << s;
	//stack s1(s);
	//cout << "s1 = " << s1;
	//stack s2 = s;
	//cout << s2;

	cout << "银行ATM队列模拟实验" << endl;
	cout << "输入队列最大数量：";
	int qs;
	cin >> qs;
	queue line(qs);		//创建队列
	cout << "输入模拟时间（单位小时）：";
	int hours;
	cin >> hours;
	long mins = MIN_PER_HR * hours;	//转为分钟
	cout << "输入平均每小时客户总量：";
	double person;
	cin >> person;
	double min_per_cust = MIN_PER_HR / person;	//每个客户平均耗时

	Item2 temp;
	long turnaways = 0;		//拒绝次数
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int i = 0; i < mins; i++)	//时间增加
	{
		if (newcustomer(min_per_cust))	//新客户到来
		{
			if (line.isfull())	
				turnaways++;	//队列满 拒绝数+1
			else
			{
				customers++;	//客户数+1
				temp.set(i);	//设置该客户的需要服务时间,以及到达时间i
				line.addqueue(temp);	//将该客户加入到队列
			}
		}
		if (wait_time <= 0 && !line.isempty())	//该客户服务结束
		{
			line.delqueue(temp);				//删除该客户
			served++;							//服务人数+1
			wait_time = temp.ptime();			//重置其需要等待时间
			line_wait += i - temp.when();	    //在队列中等待的时间
		}
		if (wait_time > 0)	//有客户正在办理业务
			wait_time--;
		sum_line += line.queuecount();		//每分钟的队列长度
	}

	//报告模拟情况
	if (customers > 0)
	{
		cout << "接收客户人数：" << customers << endl;
		cout << "服务客户人数：" << served << endl;
		cout << "拒绝客户人数：" << turnaways << endl;
		cout << "平均每分钟队列长度：";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / mins << endl;
		cout << "客户平均等待时间：" << (double)line_wait / served << "分钟" << endl;
	}
	else
		cout << "没有客户！" << endl;
	cout << "模拟完成！" << endl;

	return 0;
}

bool newcustomer(double x)
{
	return (rand()*x / RAND_MAX < 1);
}
