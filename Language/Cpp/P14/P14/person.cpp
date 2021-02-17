#include "pch.h"
#include "person.h"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//Person基虚类
Person::Person(const Person & p)
{
	firstname = p.firstname;
	lastname = p.lastname;
}

Person::~Person() {}

void Person::Data() const
{
	cout << "first name is :" << firstname << endl;
	cout << "last name is :" << lastname << endl;
}

void Person::Get()
{
	cout << "enter firstname :\n";
	getline(cin, firstname);
	cout << "enter lastname :\n";
	getline(cin, lastname);
}

void Person::Show() const
{
	Data();
}

void Person::Set()
{
	Get();
}

//Gunslinger类
void Gunslinger::Data() const
{
	cout << "Nick is :" << numsk << endl;
	cout << "Time of get the gun :" << Gunslinger::Draw() << endl;
}

void Gunslinger::Get()
{
	cout << "enter nick:\n";
	cin >> numsk;
}

void Gunslinger::Set()
{
	cout << "enter Guns name : \n";
	Person::Get();
	Get();
}

void Gunslinger::Show() const
{
	cout << "Gunslinger : \n";
	Person::Data();
	Data();
}


//PokerPlayer类
void PokerPlayer::Data() const
{
	cout << "The cards : " << Draw() << endl;
}

void PokerPlayer::Show() const
{
	cout << "PokerPlayer :\n";
	Person::Data();
	Data();
}

//BadDude类
double BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
	cout << "the next cards:" << Cdraw() << endl;
	cout << "the time of baddude get the gun: " << Gdraw() << endl;
}

void BadDude::Get()
{
	Gunslinger::Get();
}

void BadDude::Set()
{
	cout << "enter baddude name: \n";
	Person::Get();
	Get();
}

void BadDude::Show() const
{
	cout << "BadDude :\n";
	Person::Data();
	Data();
}


