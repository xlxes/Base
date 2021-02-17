#ifndef MYTIME_H_
#define MYTIME_H_

#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;

public:
	Time();
	Time(int h, int m = 0);
	~Time();
	void addmin(int m);
	void addhr(int h);
	void reset(int h = 0, int m = 0);

	Time operator*(double n)const;
	friend Time operator-(const Time& t1,const Time& t2);
	friend Time operator+(const Time& t1,const Time& t2);
	friend Time operator*(double n, const Time& t) { return t * n; }
	friend ostream& operator<<(ostream& os, const Time& t);
};

#endif // !MYTIME_H_

