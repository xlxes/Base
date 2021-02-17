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
	cout.setf(ios::fixed, ios::floatfield);	//������ʾ�ǿ�ѧ������
	cout << "client : " << name << endl;
	cout << "account number : " << acctnum << endl;
	cout << "Balance : " << balance << endl;
}

void BankAccount::deposit(double cash)	//��Ǯ
{
	using std::endl;
	using std::cout;
	if (cash >= 0)
	{
		balance += cash;
	}
	else
		cout << "�Ƿ�������" << endl;
}

void BankAccount::withdraw(double cash)	//ȡǮ
{
	using std::cout;
	using std::endl;
	if (cash < 0)
	{
		cout << "�Ƿ�������" << endl;
	}
	else if (cash <= balance)
		balance -= cash;
	else
		cout << "���治��������" << endl;
}