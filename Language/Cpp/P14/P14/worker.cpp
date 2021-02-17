#include "pch.h"
#include "queuetp.h"

Worker::~Worker() {}

void Worker::show() const
{
	cout << "Name:" << fullname << endl;
	cout << "Employee ID:" << id << endl;
}

void Worker::set()
{
	cout << "Enter worker's name:";
	getline(cin, fullname);
	cout << "Enter worker's ID:";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}