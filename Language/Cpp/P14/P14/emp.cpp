#include "pch.h"
#include "emp.h"
#include <iostream>

using namespace std;

void abstr_emp::ShowAll() const
{
	cout << "firstname :" << firstname << endl;
	cout << "lastname :" << lastname << endl;
	cout << "job is :" << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "enter fn:";
	getline(cin, firstname);
	cout << "enter ln:";
	getline(cin, lastname);
	cout << "enter job:";
	getline(cin, job);
}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << e.firstname << " " << e.lastname << " " << e.job << endl;
	return os;
}

abstr_emp::~abstr_emp()
{}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "inchargeof is :" << charge() << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "enter incharge :";
	cin >> inchargeof;
	cin.ignore();
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "reportsto :" << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "enter reportsto :";
	cin >> reportsto;
	cin.ignore();
}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "inchargeof :" << manager::charge() << endl;
	cout << "reportsto :" << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	manager::getinchargeof();
	fink::getReportTo();
}