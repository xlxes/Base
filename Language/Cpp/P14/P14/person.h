#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class Person
{
private:
	string firstname;
	string lastname;
protected:
	virtual void Data() const;	//显示姓名
	virtual void Get();	//输入姓名
public:
	//默认初始化
	Person() :firstname("no one"), lastname("no one") {}		
	//构造函数1
	Person(const string &f, const string &l) :firstname(f), lastname(l) {}
	//复制构造函数2
	Person(const Person & p);
	virtual ~Person() = 0;
	virtual void Set() = 0;		//设置输入姓、名
	virtual void Show() const = 0;	//显示姓、名
};

//继承虚基类，共享一个Person
//公有继承 保护成员仍为保护成员
class Gunslinger :virtual public Person
{
private:
	int numsk;		//枪的刻痕数
protected:
	void Data() const;	//显示刻痕数与拔枪时间
	void Get();			//输入刻痕数
public:
	//默认构造
	Gunslinger() :numsk(0), Person() {}
	//构造函数1
	Gunslinger(int nk, const string &f, const string &l) :numsk(nk), Person(f, l) {}
	//构造函数2 根据Person虚基类
	Gunslinger(int nk, const Person &p) :numsk(nk), Person(p) {}
	void Show() const;	//显示名字、刻痕数、拔枪时间
	void Set();			//设置枪手名字、刻痕数
	double Draw() const { return rand() % 3 + 1; } //随机生成拔枪时间
};

//公有继承 保护成员仍为保护成员
class PokerPlayer :virtual public Person
{
protected:
	void Data() const;	//显示扑克牌数字1-52
public:
	PokerPlayer() :Person() {}
	PokerPlayer(const string &f, const string & l) :Person(f, l) {}
	PokerPlayer(const Person &p) :Person(p) {}
	int Draw() const { return rand() % 52 + 1; }	//返回扑克数
	void Show() const;		//显示姓名、扑克数
	void Set() { Person::Set(); }	//设置姓名
};


class BadDude :public Gunslinger, public PokerPlayer
{
protected:
	void Data() const;
	void Get();
public:
	BadDude() {}
	BadDude(int nk, const string & f, const string & l) :Person(f, l), Gunslinger(nk, f, l), PokerPlayer(f, l) {}
	BadDude(int nk, const Person & p) :Person(p), Gunslinger(nk, p), PokerPlayer(p) {}
	BadDude(const Gunslinger & g) :Person(g), Gunslinger(g), PokerPlayer(g) {}
	BadDude(int nk,const PokerPlayer & po):Person(po), Gunslinger(nk, po), PokerPlayer(po) {}
	double Gdraw() const;	//返回拔枪时间
	int Cdraw() const;		//返回扑克牌
	void Set();				//输入名字
	void Show() const;		//显示所有信息
};

#endif // ! PERSON_H_
#pragma once
