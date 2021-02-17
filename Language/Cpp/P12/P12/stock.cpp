#include "pch.h"
#include "stock.h"
#include <iostream>

using std::cin;
using std::cout;
using std::ios_base;

stock::stock()
{
	company = new char[strlen("No name")];
	len = strlen("No name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

stock::stock(const char* s, long n, double pr)
{
	len = strlen(s);
	company = new char[len + 1];
	strcpy_s(company, len + 1, s);
	if (n < 0)
	{
		cout << "number of shares can't be negative: "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

stock::~stock()
{
	delete[] company;
}

void stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "购买数不可为负。"
			<< "交易终止。\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "出售数不可为负。"
			<< "交易终止。\n";
	}
	else if (num > shares)
	{
		cout << "没那么多货。"
			<< "交易终止。\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void stock::update(double price)
{
	share_val = price;
	set_tot();
}

const stock& stock::topval(const stock& s)const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

ostream& operator<<(ostream& os, const stock& s)
{
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = os.precision(3);
	os << "company: " << s.company << "  shares: " << s.shares << endl;
	os << "share price: $" << s.share_val;
	os.precision(2);
	os << "total worth: $" << s.total_val << endl;
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);

	return os;
}