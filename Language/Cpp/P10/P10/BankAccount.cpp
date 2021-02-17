#include "pch.h"
#include "iostream"
#include "BankAccount.h"

BankAccount::BankAccount(const string& client, const string& num, 
	double bal)
{
	name = client;
	acctnum = num;
	balance = bal;
}

BankAccount::~BankAccount()
{}

void BankAccount::show() const
{
	using std::endl;
	using std::cout;
	cout.setf(ios::fixed, ios::floatfield);	//设置显示非科学记数法
	cout << "client : " << name << endl;
	cout << "account number : " << acctnum << endl;
	cout << "Balance : " << balance << endl;
}

void BankAccount::deposit(double cash)	//存钱
{
	using std::endl;
	using std::cout;
	if (cash >= 0)
	{
		balance += cash;
	}
	else
		cout << "非法操作！" << endl;
}

void BankAccount::withdraw(double cash)	//取钱
{
	using std::cout;
	using std::endl;
	if (cash < 0)
	{
		cout << "非法操作！" << endl;
	}
	else if (cash <= balance)
		balance -= cash;
	else
		cout << "储存不够，请贷款！" << endl;
}