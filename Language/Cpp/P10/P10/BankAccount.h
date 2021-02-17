#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_


#include "pch.h"
#include <string>

using namespace std;

class BankAccount
{
private:
	string name;
	string acctnum;
	double balance;
public:
	BankAccount(const string& client, const string& num, double bal = 0.0);	//构造函数 
	~BankAccount();	//析构函数
	void show(void) const;
	void deposit(double cash);
	void withdraw(double cash);
};



#endif 
