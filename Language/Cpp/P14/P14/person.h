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
	virtual void Data() const;	//��ʾ����
	virtual void Get();	//��������
public:
	//Ĭ�ϳ�ʼ��
	Person() :firstname("no one"), lastname("no one") {}		
	//���캯��1
	Person(const string &f, const string &l) :firstname(f), lastname(l) {}
	//���ƹ��캯��2
	Person(const Person & p);
	virtual ~Person() = 0;
	virtual void Set() = 0;		//���������ա���
	virtual void Show() const = 0;	//��ʾ�ա���
};

//�̳�����࣬����һ��Person
//���м̳� ������Ա��Ϊ������Ա
class Gunslinger :virtual public Person
{
private:
	int numsk;		//ǹ�Ŀ̺���
protected:
	void Data() const;	//��ʾ�̺������ǹʱ��
	void Get();			//����̺���
public:
	//Ĭ�Ϲ���
	Gunslinger() :numsk(0), Person() {}
	//���캯��1
	Gunslinger(int nk, const string &f, const string &l) :numsk(nk), Person(f, l) {}
	//���캯��2 ����Person�����
	Gunslinger(int nk, const Person &p) :numsk(nk), Person(p) {}
	void Show() const;	//��ʾ���֡��̺�������ǹʱ��
	void Set();			//����ǹ�����֡��̺���
	double Draw() const { return rand() % 3 + 1; } //������ɰ�ǹʱ��
};

//���м̳� ������Ա��Ϊ������Ա
class PokerPlayer :virtual public Person
{
protected:
	void Data() const;	//��ʾ�˿�������1-52
public:
	PokerPlayer() :Person() {}
	PokerPlayer(const string &f, const string & l) :Person(f, l) {}
	PokerPlayer(const Person &p) :Person(p) {}
	int Draw() const { return rand() % 52 + 1; }	//�����˿���
	void Show() const;		//��ʾ�������˿���
	void Set() { Person::Set(); }	//��������
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
	double Gdraw() const;	//���ذ�ǹʱ��
	int Cdraw() const;		//�����˿���
	void Set();				//��������
	void Show() const;		//��ʾ������Ϣ
};

#endif // ! PERSON_H_
#pragma once
