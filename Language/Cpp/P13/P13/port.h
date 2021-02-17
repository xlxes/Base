#ifndef _PORT_H_
#define _PORT_H

#include <iostream>
#include <cstring>

using namespace std;

class port
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	explicit port(const char* br = "none", const char* st = "none", int b = 0);
	port(const port& p);
	virtual ~port() { delete[] brand; }
	port& operator=(const port& p);
	virtual void show() const;
	port& operator+=(int b);
	port& operator-=(int b);
	int BottleCount() const { return bottles; }
	friend ostream& operator<<(ostream& os, const port& p);
};

class vintageport :public port
{
private:
	char* nickname;
	int year;
public:
	vintageport();
	vintageport(const char* br, int b, const char* nn, int y);
	vintageport(const vintageport& vp);
	~vintageport() { delete[] nickname; }
	vintageport& operator=(const vintageport& vp);
	void show() const;
	friend ostream& operator<<(ostream& os, const vintageport& vp);
};

#endif // !_PORT_H_

