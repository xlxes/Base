#include "pch.h"
#include "mytime.h"


Time::Time()
{
	hours = minutes = 0;
}

Time::~Time()
{
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::addhr(int h)
{
	hours += h;
}

void Time::addmin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::operator*(double mult)const
{
	Time result;
	long allmin = hours * mult * 60 + minutes * mult;
	result.hours = allmin / 60;
	result.minutes = allmin % 60;
	return result;
}

Time operator+(const Time& t1, const Time& t2)
{
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time& t1, const Time& t2)
{
	Time diff;
	int m1, m2;
	m1 = t1.hours * 60 + t1.minutes;
	m2 = t2.hours * 60 + t2.minutes;
	diff.minutes = (m1 - m2) % 60;
	diff.hours = (m1 - m2) / 60;
	return diff;
}

ostream& operator<<(ostream& os, const Time& t)
{
	os << t.hours << " hours " << t.minutes << " minutes.";
	return os;
}